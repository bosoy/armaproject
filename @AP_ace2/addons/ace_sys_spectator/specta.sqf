#include "script_component.hpp"
//
// Spectating Script for Armed Assault
// by Kegetys <kegetys [ät] dnainternet.net>
//
if (GVAR(SPECTATINGON)) exitWith {};
GVAR(SPECTATINGON) = true;

waitUntil {time > 0};

disableSerialization;

private ["_player", "_killer", "_seagull", "_factor", "_i", "_name", "_disp", "_cLBCameras", "_cLBTargets", "_pos", "_cameras", "_cLbSeparator", "_ctrloverlay", "_fh", "_doexitx", "_bpos", "_bird", "_ret"];
PARAMS_3(_player,_killer,_seagull);

if ( isNil "_seagull" )  then  {_seagull = "noWait"};

// safety check to wait for a still running spectator script
if (!isNil QGVAR(exit_spectator)) then {waitUntil {isNil QGVAR(exit_spectator)}};

// ace_sys_spectator_can_exit_spectator = true, the player can exit spectating with the X key
if (isNil QGVAR(can_exit_spectator)) then {GVAR(can_exit_spectator) = false};
// ace_sys_spectator_playable_only = true, only playable (MP) or switchableUnits (SP) units will be shown in the target listbox
if (isNil QGVAR(playable_only)) then {GVAR(playable_only) = false};
// ace_sys_spectator_no_butterfly_mode = true, if a player presses Esc he won't switch to butterfly mode but the spectating dialog gets restarted after a second
if (isNil QGVAR(no_butterfly_mode)) then {GVAR(no_seagull_mode) = false; GVAR(no_butterfly_mode) = false};
// markers are enabled as default, set ace_sys_spectator_NoMarkersUpdates to true to completely disable marker updates
if (isNil QGVAR(NoMarkersUpdates)) then {GVAR(NoMarkersUpdates) = false};
// if GVAR(UseLog) is set to true, spctator messages are written to group chat and RPT
// in Singleplayer killed messages are logged too
if (isNil QGVAR(UseLog)) then {GVAR(UseLog) = false};
// do also check if a unit is unconscious and don't add it to the target list, ace_sys_spectator_CheckUncon = true
if (isNil QGVAR(CheckUncon)) then {GVAR(CheckUncon) = false};
// display only units in the target list that are max ace_sys_spectator_CheckDist meters away, -1 = no check
if (isNil QGVAR(CheckDist)) then {GVAR(CheckDist) = -1};
// if ace_sys_spectator_RemoveDeadFilter = true dead units will allways get removed from the target listbox, doesn't matter if you change it during spectating
if (isNil QGVAR(RemoveDeadFilter)) then {GVAR(RemoveDeadFilter) = false};
// do also check if a unit is captive
if (isNil QGVAR(CheckCaptive)) then {GVAR(CheckCaptive) = false};

// if ace_sys_spectator_dropped_check is set to false no nearby target gets acquired
if (isNil QGVAR(dropped_check)) then {GVAR(dropped_check) = false};

 // ace_sys_spectator_RevShowButtonTime = 300 will show some buttons that you can assign actions to after 5 minutes (300 seconds)
 if (isNil QGVAR(showbuttonattime)) then {
	_factor = if (isNil QGVAR(RevShowButtonTime)) then {99999999999} else {GVAR(RevShowButtonTime)};
	GVAR(showbuttonattime) = time + _factor;
};

// if you add text to the array it will show the corresponding button
// for example, ace_sys_spectator_RevButtons = ["Respawn 1", "Respawn 2", "", ""];
// will only show button 1 and 2 with
// You don't have to make an array with four elements, it will get filled automatically
// default no buttons visible
if (isNil QGVAR(RevButtons)) then {GVAR(RevButtons) = ["","","",""]};
if (count GVAR(RevButtons) < 4) then {
	for "_i" from (count GVAR(RevButtons) - 1) to 3 do {GVAR(RevButtons) set [count GVAR(RevButtons), ""]};
};

// ace_sys_spectator_no_one_alive = distance for alive unit check, -1 = disabled
// shows buttons when PMR is enabled and no other players in distance ace_sys_spectator_no_one_alive are alive
if (isNil QGVAR(no_one_alive)) then {GVAR(no_one_alive) = -1};

// Unit sides shown - Show all if sides not set
// example: ace_sys_spectator_ShownSides = [west];
if (isNil QGVAR(ShownSides)) then {
	GVAR(ShownSides) = [west, east, resistance, civilian];
} else {
	if (count GVAR(ShownSides) == 0 || {count GVAR(ShownSides) > 4}) then {
		GVAR(ShownSides) = [west, east, resistance, civilian];
	};
};

// Maximum distance for camera
// 10 ~ 100 m, 50 ~ 500 m, default = 50, example ace_sys_spectatorGVAR(maxDistance) = 20;
if (isNil QGVAR(maxDistance)) then {GVAR(maxDistance) = 50};

#define KCCAMERA 55002
#define KCTARGET 55003
#define KCLBCAMERAS 55005
#define KCLBTARGETS 55006
#define KCCAMERAsBG 55007
#define KCTARGETsBG 55008
#define KCBG1 55009
#define KCBG2 55010
#define KCTITLE 55011
#define KCHELP 55012
#define KCLIFETIME 50022
#define KCCOMPASS 50023

GVAR(SEUI) = [KCCAMERA, KCTARGET, KCLBCAMERAS, KCLBTARGETS, KCCAMERAsBG, KCTARGETsBG, KCBG1, KCBG2, KCTITLE, KCHELP, KCLIFETIME,KCCOMPASS];
GVAR(SHOWSEUI) = true;
GVAR(SEUICHANGED) = 0;

GVAR(TogTagsParams) = [];
GVAR(DoFirstUnitCheck) = false;

GVAR(oldViewDistance) = viewDistance;

// If seagull is valid we came from the respawn scene
if (typeName _seagull == "OBJECT") then {
	_seagull setPos [-1000, -1000, 1000];
	sleep 5;
	titleCut["", "BLACK OUT", 2]; // death simulating the lights going out.
	sleep 3; // holding back the startLoadingScreen spectator screen while viewing the death simulation (1 second longer than the Black Out Fade)
};

// Globals etc.
if (isNil QGVAR(OldNVGMethod)) then {GVAR(OldNVGMethod) = false};
GVAR(Spect_Init) = false;
GVAR(target) = objNull;
GVAR(MouseButtons) = [false, false];
GVAR(MouseScroll) = 0;
GVAR(MouseCoord) = [0.5, 0.5];
GVAR(UseNVG) = 0;
GVAR(OldNVGMode) = -2;
GVAR(NVGMode) = -1;
GVAR(oldUseNVG) = 0;
GVAR(MissileCamActive) = false;
GVAR(UseMissileCam) = 1;
GVAR(olduseMCam) = 1;
GVAR(MarkerNames) = false; // True = display marker names and arrows
GVAR(MarkerType) = 1; // 0 = disabled, 1 = names, 2 = types
GVAR(Tags) = 0; // Particlesource tags
GVAR(oldTags) = 0;
GVAR(AIfilter) = 0; // Filter AI units (only players displayed)
GVAR(oldAIfilter) = 0;
GVAR(DeadFilter) = if (GVAR(RemoveDeadFilter)) then {1} else {0}; // Filter Unknown Dead units (only Alive players displayed)
GVAR(oldDeadFilter) = 0;
GVAR(MarkerSize) = 1.0; // Full map marker size
GVAR(MinimapZoom) = 0.5; // Minimap zoom
GVAR(1stGunner) = false; // Gunner view on 1st person camera?
GVAR(DroppedCamera) = false; // Free camera dropped (non-targeted with free motion)?
GVAR(CamForward) = false;
GVAR(CamBack) = false;
GVAR(CamLeft) = false;
GVAR(CamRight) = false;
GVAR(NeedUpdateLB) = false;
GVAR(exitspect) = false;
GVAR(gfleader) = false;
GVAR(units) = [];
GVAR(MissileCamOver) = false;
GVAR(markersrun) = false;
GVAR(sdistance) = 1; // camera distance
GVAR(fangle)  = 0; // Free camera angle
GVAR(fangleY) = 15;
GVAR(flybydst) = 35; // Distance of flyby camera (adjusted based on target speed)
GVAR(szoom) = 0.976;
GVAR(markers) = []; // Map markers showing positions of all units
GVAR(Tagsources) = []; // Particle sources for tags
GVAR(lastTgt) = -1;
GVAR(exit_the_frame) = true;
GVAR(minimi) = true;
GVAR(minimi_follow) = true;

GVAR(mouseDeltaPos) = [0, 0];

GVAR(mousecheckon) = false;
GVAR(newCheckUn) = false;
GVAR(updating_lb) = false;

GVAR(oldtarget) = objNull;
GVAR(hasdropped) = true;

GVAR(oldnname) = "";
GVAR(oldnrole) = "";
GVAR(oldcamselidx) = -1000;
GVAR(oldCameraIdx) = -123;

GVAR(specstrings) = [(localize "STR_ACE_SPECT_DEAD") + " ","ace_sys_spect_Marker%1",localize "STR_ACE_SPECT_UNKNOWN",localize "STR_ACE_SPECT_PILOT",localize "STR_ACE_SPECT_DRIVER",localize "STR_ACE_SPECT_GUNNER",localize "STR_ACE_SPECT_COMMANDER",localize "STR_ACE_SPECT_SELCAM","Life time: %1"];
_name = localize "STR_ACE_SPECT_UNKNOWN";

GVAR(deathCam) = [];
GVAR(ehVehicles) = []; // Used to keep track of added eventhandlers

if (typeName _seagull != "string") then {
	sleep 1;
	titleCut ["", "BLACK IN", 8];
} else {
	titleText["", "BLACK IN", 0];
};

_seagull = "noWait";

// Create dialog & assign keyboard handler
createDialog "ACE_rscSpectate";
TRACE_1("Creating ACE_rscSpectate","");
_disp = uiNamespace getVariable QGVAR(rscSpectate);
_disp displaySetEventHandler ["KeyDown", "[""KeyDown"", _this] call ace_sys_spectator_fnc_spectate_events"];
_disp displaySetEventHandler ["KeyUp", "[""KeyUp"", _this] call ace_sys_spectator_fnc_spectate_events"];

(_disp displayCtrl 55012) ctrlSetStructuredText parseText ("Spectating Script v1.03 by Kegetys<br/><br/>" +
	(localize "STR_ACE_SPECT_HELPN1") + "<br/>" + (localize "STR_ACE_SPECT_HELPN2") + "<br/><br/>" +
	(localize "STR_ACE_SPECT_HELPN3") + "<br/>" + (localize "STR_ACE_SPECT_HELPN4") + "<br/>" +
	(localize "STR_ACE_SPECT_HELPN5") + "<br/>" + (localize "STR_ACE_SPECT_HELPN6") + "<br/>" +
	(localize "STR_ACE_SPECT_HELPN7") + "<br/>" + (localize "STR_ACE_SPECT_HELPN8") + "<br/>" +
	(localize "STR_ACE_SPECT_HELPN9") + "<br/>" + (localize "STR_ACE_SPECT_HELPN10") + "<br/>" +
	(localize "STR_ACE_SPECT_HELPN11") + "<br/>" + (localize "STR_ACE_SPECT_HELPN12") + "<br/>" +
	(localize "STR_ACE_SPECT_HELPN13") + "<br/>" + (localize "STR_ACE_SPECT_HELPN14") + "<br/>" +
	(localize "STR_ACE_SPECT_HELPN14a") + "<br/>" + (localize "STR_ACE_SPECT_HELPN14b") + "<br/>" +
	(localize "STR_ACE_SPECT_HELPN15") + "<br/>" + (localize "STR_ACE_SPECT_HELPN16") + "<br/>" +
	(localize "STR_ACE_SPECT_HELPN17") + "<br/>" + (localize "STR_ACE_SPECT_HELPN18") + "<br/>" +
	(localize "STR_ACE_SPECT_HELPN19") + "<br/><br/>" + (localize "STR_ACE_SPECT_HELPN20") + "<br/>" +
	(localize "STR_ACE_SPECT_HELPN21") + "<br/>" + (localize "STR_ACE_SPECT_HELPN22") + "<br/>" +
	(localize "STR_ACE_SPECT_HELPN23") + "<br/><br/>Improvement modifications by Dwarden, Vipermaul and norrin<br/>Complete rewrite for ACE by Xeno<br/>");

// Hide menus by default
["ToggleCameraMenu", 0] call FUNC(spectate_events);
["ToggleTargetMenu", 0] call FUNC(spectate_events);
["ToggleHelp", 0] call FUNC(spectate_events);
["ToggleMap", 1] call FUNC(spectate_events);

// IDC's from rsc
_cLBCameras = 55005;
_cLBTargets = 55006;

GVAR(the_nearest) = objNull;
GVAR(rbuttonsvisible) = false;

// Create cameras
_pos = [(player modelToWorld [0, 0, 0] select 0) - 1 + random 2, (player modelToWorld [0, 0, 0] select 1) - 1 + random 2, 2];
GVAR(cam_static) = "camera" camCreate _pos;
GVAR(cam_target) = "camera" camCreate _pos; // "Dummy" target camera for smooth transitions
GVAR(cam_free) = "camera" camCreate _pos;
GVAR(cam_flyby) = "camera" camCreate _pos;
GVAR(cam_topdown) = "camera" camCreate _pos;
GVAR(cam_1stperson) = "camera" camCreate _pos; // Dummy camera
GVAR(cam_missile) = "camera" camCreate _pos; // Missile camera
GVAR(cam_fullmap) = "camera" camCreate _pos; // Full map view camera
_cameras = [GVAR(cam_free), GVAR(cam_static), GVAR(cam_flyby), GVAR(cam_topdown), GVAR(cam_1stperson)];
GVAR(cameraNames) = [localize "STR_ACE_SPECT_CAMFREE", localize "STR_ACE_SPECT_CAMCHASE", localize "STR_ACE_SPECT_CAMFLYBY", localize "STR_ACE_SPECT_CAMFTOPDOWN", localize "STR_ACE_SPECT_CAMFIRST"];
GVAR(dummy_o) = "ACE_LogicDummy" createVehicleLocal [0, 0, 0]; // Dummy object for distance command
GVAR(cameras) = _cameras; // Hack to allow access from events.sqf

// Add cameras to listbox
lbClear _cLBCameras;
{lbAdd [_cLBCameras, _x]} foreach GVAR(cameraNames);

// Add separator & toggles
_cLbSeparator = lbAdd [_cLBCameras, "---"];
lbSetColor [_cLBCameras, _cLbSeparator, [0.5, 0.5, 0.5, 0.5]];
GVAR(cLbMissileCam) = lbAdd [_cLBCameras, localize "STR_ACE_SPECT_CAMMISSILE"];
GVAR(cLbToggleNVG) = lbAdd [_cLBCameras, localize "STR_ACE_SPECT_CAMNIGHTV"];
GVAR(cLbToggleTags) = lbAdd [_cLBCameras, localize "STR_ACE_SPECT_CAMUNITTAGS"];
GVAR(cLbToggleAiFilter) = lbAdd [_cLBCameras, localize "STR_ACE_SPECT_CAMFILTERAI"];
GVAR(cLbToggleDeadFilter) = lbAdd [_cLBCameras, localize "STR_ACE_SPECT_CAMFILTERDEAD"];

lbSetColor [_cLBCameras, GVAR(cLbMissileCam), [1, 0.5, 0, 1]];
lbSetColor [_cLBCameras, GVAR(cLbToggleNVG), [1, 1, 1, 0.33]];
lbSetColor [_cLBCameras, GVAR(cLbToggleTags), [1, 1, 1, 0.33]];
lbSetColor [_cLBCameras, GVAR(cLbToggleAiFilter), [1, 1, 1, 0.33]];
lbSetColor [_cLBCameras, GVAR(cLbToggleDeadFilter), [1, 1, 1, 0.33]];

GVAR(tgtIdx) = 0;
GVAR(cameraIdx) = 0;
GVAR(NewCameraIdx) = 0;
showcinemaborder false;
lbClear _cLBTargets;
onMapSingleClick {["MapClick", _pos] call ace_sys_spectator_fnc_spectate_events};

if (GVAR(UseLog)) then {["EventLogAdd", ["Initialize", [1, 1, 1, 1]]] call FUNC(spectate_events)};

// Spawn thread to display help reminder after a few seconds
0 spawn {
	sleep 3;
	if (dialog) then {
		if (!GVAR(can_exit_spectator)) then {
			cutText[(localize "STR_ACE_SPECT_F1HELP"), "PLAIN DOWN", 0.75];
		} else {
			cutText[(localize "STR_ACE_SPECT_F1HELP2"), "PLAIN DOWN", 0.75];
		};
	};
};

GVAR(camSelLast) = 0;
GVAR(tgtSelLast) = -1;
GVAR(mouseLastX) = 0.5;
GVAR(mouseLastY) = 0.5;
GVAR(lastCheckNewUnits) = -100;
GVAR(nextmarkertime) = time + 3;
GVAR(nextmaptime) = -100;
GVAR(lastUpdateTags) = -100;
GVAR(lastAutoUpdateLB) = time;
GVAR(lasttgtIdx) = 0;
GVAR(CamPos) = [0, 0, 0];
GVAR(cxpos) = 0;
GVAR(cypos) = 0;
GVAR(czpos) = 0;
GVAR(cspeedx) = 0;
GVAR(cspeedy) = 0;
GVAR(tbase) = 0.1;
GVAR(tbasestart) = 0;
GVAR(The_h) = 2;

GVAR(olddropedname) = "";
GVAR(overlay_on) = false;
10009 cutRsc["ACE_SpectRecogOverlay","PLAIN"];
TRACE_1("Creating ACE_SpectRecogOverlay","");
_ctrloverlay = (uiNamespace getVariable "ACE_SpectRecogOverlay") displayCtrl 1;
_ctrloverlay ctrlShow false;
_ctrloverlay ctrlCommit 0;

GVAR(dirmarker) = createMarkerLocal [QGVAR(sdir_marker), [0, 0, 0]];
GVAR(dirmarker) setMarkerTypeLocal "mil_arrow2";
GVAR(dirmarker) setMarkerSizeLocal [0.3, 0.3];
GVAR(dirmarker) setMarkerColorLocal "ColorBlack";
GVAR(dirmarker) setMarkerTextLocal "Camera";

GVAR(lastCheckNewUnits) = time;
GVAR(DoFirstUnitCheck) = true;
waitUntil {GVAR(NeedUpdateLB)};

if (!isNil "ace_sys_wounds_enabled" && {!isNil "ace_wounds_prevtime"} && {ace_wounds_prevtime > 0} && {isNil "ace_wounds_no_prevtime"}) then {ace_wounds_no_prevtime = false};

TRACE_1("Starting per frame handling","");
GVAR(exit_the_frame) = false; // here the magic beginns, GVAR(exit_the_frame) starts the per frame handler for the main loop
waitUntil {GVAR(exit_the_frame)};
TRACE_1("Per frame handling ended","");

setViewDistance GVAR(oldViewDistance);

10009 cutRsc["Default","PLAIN"];

// Dialog closed with esc key
titleText ["", "BLACK IN", 0.5];

// Destroy cameras, markers, particlesources, etc.
{camDestroy _x} foreach _cameras;
camDestroy GVAR(cam_target);
camDestroy GVAR(cam_missile);
camDestroy GVAR(cam_fullmap);
deletevehicle GVAR(cam_target);
deletevehicle GVAR(cam_missile);
deletevehicle GVAR(cam_fullmap);
GVAR(exitspect) = true;
sleep 0.01;
{deleteMarkerLocal (_x select 0)} foreach GVAR(markers);
// camUseNVG false;
if (GVAR(UseNVG) == 1) then {setAperture -1};
onMapSingleClick {};
{deletevehicle (_x select 1)} foreach GVAR(Tagsources);
deleteVehicle GVAR(dummy_o);

{
	if (!isNull _x) then {
		_fh = _x getVariable QGVAR(EHFired);
		if (!isNil "_fh") then {_x removeEventHandler["fired", _fh]};
		_x setVariable [QGVAR(EHFired), nil];
	};
} foreach GVAR(ehVehicles);

{
	if (!isNull _x) then {
		(vehicle _x) setVariable [QGVAR(mapmove), nil];
		if (!isMultiplayer && {GVAR(UseLog)}) then {
			_fh = _x getVariable QGVAR(EHKilled);
			if (!isNil "_fh") then {_x removeEventHandler["killed", _fh]};
		};
	};
} forEach GVAR(deathCam);

// a little helper if you might want to exit spectating during a mission again
// just set ace_sys_spectator_exit_spectator = true and spectating will exit safely
_doexitx = false;
if (!isNil QGVAR(exit_spectator)) then {
	deleteMarkerLocal GVAR(dirmarker);
	player switchCamera "INTERNAL";
	player cameraEffect["terminate", "FRONT"];
	closeDialog 0;
	_doexitx = true;
	GVAR(showbuttonattime) = nil;
};

// cleanup
GVAR(deathCam) = nil;
GVAR(units) = nil;
GVAR(MouseButtons) = nil;
GVAR(MouseCoord) = nil;
GVAR(units) = nil;
GVAR(markers) = nil;
GVAR(Tagsources) = nil;
GVAR(mouseDeltaPos) = nil;
GVAR(ehVehicles) = nil;
GVAR(SEUI) = nil;

GVAR(exit_spectator) = nil;

if (_doexitx) exitWith {GVAR(SPECTATINGON) = false};

if (GVAR(no_butterfly_mode)) exitWith {
	deleteMarkerLocal GVAR(dirmarker);
	// give some time to press Esc to exit the game
	titleText ["", "BLACK OUT", 0.2];
	player switchCamera "INTERNAL";
	player cameraEffect["terminate", "FRONT"];
	sleep 2;
	titleText ["", "BLACK IN", 0.2];
	GVAR(SPECTATINGON) = false;
	0 spawn {
		sleep 0.01; 
		if (!isNil QGVAR(exit_spectator)) exitwith { GVAR(exit_spectator) = nil };
		call ace_sys_spectator_fnc_startSpectator;
	};
};

// Create a butterfly for player to fly with
_bpos = [(((vehicle GVAR(target)) modelToWorld [0, 0, 0]) select 0) - 5 + random 10, (((vehicle GVAR(target)) modelToWorld [0, 0, 0]) select 1) - 5 + random 10, 1];
_bird = "ACE_ButterFlySpectator" createVehiclelocal _bpos;
_bird setVelocity [0, 0, 5];
_bird setPos _bpos;
_bird switchCamera "INTERNAL";
_bird cameraEffect ["terminate", "FRONT"];
_bird camCommand "manual on";

GVAR(Bird) = _bird;
onMapSingleClick {ace_sys_spectator_Bird setpos [_pos select 0, _pos select 1, 2];ace_sys_spectator_Bird setvelocity[0, 0, 5];if (dialog) then {closeDialog 0}};

cutText [localize "STR_ACE_SPECT_LANDGROUND", "PLAIN DOWN", 0.75];

// faking map here as workaround, butterflies don't have a map so we add a dialog with a map
GVAR(birdkeyDownEHId) = (findDisplay 46) displayAddEventHandler ["KeyDown", "
	_ret = false;
	if ((_this select 1) in ([50] + (actionKeys 'ShowMap') + (actionKeys 'HideMap'))) then {
		['ToggleMapBird', 0] call ace_sys_spectator_fnc_spectate_events;
		_ret = true;
	};
	_ret
"];

GVAR(dirmarker) setMarkerTextLocal "Bird Camera";
GVAR(dirmarker) spawn {
	GVAR(dirmarker) = _this;
	while {!isNull GVAR(Bird)} do {
		GVAR(dirmarker) setMarkerPosLocal getPosASL GVAR(Bird);
		GVAR(dirmarker) setMarkerDirLocal direction GVAR(Bird);
		sleep 0.1;
	};
};

// Wait until landed, delete bird & restart script
waitUntil {speed _bird < 1 && {(_bird modelToWorld [0, 0, 0]) select 2 < 0.05}};
onMapSingleClick {};
if (dialog) then {closeDialog 0};
(findDisplay 46) displayRemoveEventHandler ["KeyDown", GVAR(birdkeyDownEHId)];

sleep 0.5;

player switchCamera "INTERNAL";
player cameraEffect["terminate", "FRONT"];
deletevehicle _bird;
deleteMarkerLocal GVAR(dirmarker);
GVAR(SPECTATINGON) = false;
[_player, _killer, "noWait"] spawn COMPILE_FILE(specta);

TRACE_1("Exiting specta.sqf","");
