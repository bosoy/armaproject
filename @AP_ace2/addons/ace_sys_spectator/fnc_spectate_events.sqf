//#define DEBUG_MODE_FULL
#include "script_component.hpp"

// for Spectating Script;
// Handles events such as keyboard keypresses;
// by Kegetys <kegetys [ät] dnainternet.net>;

private ["_type", "_param", "_dummy", "_closest", "_id", "_i", "_d", "_key", "_y", "_button", "_lifeTime", "_dropPeriod", "_size", "_cam", "_u", "_s", "_color", "_colorB", "_txt", "_killed", "_killer", "_w", "_a", "_o", "_bar", "_bars", "_pos", "_b", "_len", "_dir", "_m2", "_name", "_m"];

PARAMS_2(_type,_param);

#define KCCAMERA 55002
#define KCTARGET 55003
#define KCNAME 55004
#define KCLBCAMERAS 55005
#define KCLBTARGETS 55006
#define KCCAMERAsBG 55007
#define KCTARGETsBG 55008
#define KCBG1 55009
#define KCBG2 55010
#define KCTITLE 55011
#define KCHELP 55012
#define KCMAP 55013
#define KCMAPFULL 55014
#define KCMAPFULLBG 55015
#define KCRBUTTON1 50018
#define KCRBUTTON2 50019
#define KCRBUTTON3 50020
#define KCRBUTTON4 50021
switch (_type) do {
	// User clicked map, find nearest unit;
	case "MapClick": {
		_dummy = "ACE_LogicDummy" createVehicleLocal [_param select 0, _param select 1, 0];
		_closest = 5000;
		_id = -1;
		_idxx = 0;
		{
			if ((side _x) in GVAR(ShownSides) && {(_x in GVAR(units))}) then {
				_d = _dummy distance _x;
				if (_d < _closest) then {_id = _idxx; _closest = _d};
			};
			_idxx = _idxx + 1;
		} forEach GVAR(deathCam);
		if (_id != -1) then {
			GVAR(tgtIdx) = _id;
			GVAR(DroppedCamera) = false;
			if (ctrlVisible KCMAPFULL) then {
				// Full map -> Small map;
				[] spawn FUNC(togmapf);
			}
		};
		deleteVehicle _dummy;
	};

	case "KeyDown": {
		_key = _param select 1;
		// WSAD keys: camera movement in dropped mode;
		switch(_key) do {
			case 1: {GVAR(exit_the_frame) = true};
			case 32: {GVAR(CamRight) = true};
			case 30: {GVAR(CamLeft) = true};
			case 17: {GVAR(CamForward) = true};
			case 31: {GVAR(CamBack) = true};
			case 35: {
				if (GVAR(NoMarkersUpdates)) then {
					GVAR(NoMarkersUpdates) = false;
					titleCut ["\n\n\n\n\n\n\n\n\n" + (localize "STR_ACE_SPECT_MARKERENABLED"),"PLAIN", 0.2];
				} else {
					GVAR(NoMarkersUpdates) = true;
					titleCut ["\n\n\n\n\n\n\n\n\n" + (localize "STR_ACE_SPECT_MARKERDISABLED"),"PLAIN", 0.2];
				};
			};
		};
	};

	// Key up - process keypress;
	case "KeyUp": {
		_key = _param select 1;
		switch(_key) do {
			case 32: {
				// D = Next target;
				if (!GVAR(DroppedCamera)) then {
					_cur = (lbCurSel KCLBTARGETS) + 1;
					if (_cur > (lbSize KCLBTARGETS) - 1) then {_cur = 0};
					lbSetCurSel [KCLBTARGETS, _cur];
					if (!GVAR(SHOWSEUI)) then {
						GVAR(SEUICHANGED) = GVAR(SEUICHANGED) + 1;
						ctrlShow [KCNAME, true];
						[] spawn {
							sleep 5;
							GVAR(SEUICHANGED) = GVAR(SEUICHANGED) - 1;
							if (!GVAR(SHOWSEUI) && {GVAR(SEUICHANGED) == 0}) then {
								ctrlShow [KCNAME, false];
							};
						};
					};
				};
				GVAR(CamRight) = false;
			};
			case 30: {
				// A = Previous target;
				if (!GVAR(DroppedCamera)) then {
					_cur = (lbCurSel KCLBTARGETS) - 1;
					if (_cur < 0) then {_cur = (lbSize KCLBTARGETS) - 1};
					lbSetCurSel [KCLBTARGETS, _cur];
					if (!GVAR(SHOWSEUI)) then {
						GVAR(SEUICHANGED) = GVAR(SEUICHANGED) + 1;
						ctrlShow [KCNAME, true];
						[] spawn {
							sleep 5;
							GVAR(SEUICHANGED) = GVAR(SEUICHANGED) - 1;
							if (!GVAR(SHOWSEUI) && {GVAR(SEUICHANGED) == 0}) then {
								ctrlShow [KCNAME, false];
							};
						};
					};
				};
				GVAR(CamLeft) = false;
			};
			case 17: {
				// W = Previous camera;
				if (!GVAR(DroppedCamera)) then {
					GVAR(cameraIdx) = GVAR(cameraIdx) - 1;
					if (GVAR(cameraIdx) < 0) then {GVAR(cameraIdx) = 4};
					lbSetCurSel [KCLBCAMERAS, GVAR(cameraIdx)];
				};
				GVAR(CamForward) = false;
			};
			case 31: {
				// S = Next camera;
				if (!GVAR(DroppedCamera)) then {
					GVAR(cameraIdx) = GVAR(cameraIdx) + 1;
					if (GVAR(cameraIdx) > 4) then {GVAR(cameraIdx) = 0};
					lbSetCurSel [KCLBCAMERAS, GVAR(cameraIdx)];
				};
				GVAR(CamBack) = false;
			};

			case 20: {
				// T = Toggle tags;
				GVAR(Tags) = abs (GVAR(Tags) - 1);
				if (GVAR(Tags) == 0) then {
					["ToggleTags", [false, objNull]] call FUNC(spectate_events);
				};
			};

			case 33: {
				// F = Toggle filter;
				GVAR(AIfilter) = abs (GVAR(AIfilter) - 1);
				GVAR(NeedUpdateLB) = true;
			};

			case 34: {
				// G = Toggle Group/Formation Leader filter;
				GVAR(gfleader) = !GVAR(gfleader);
				GVAR(NeedUpdateLB) = true;
			};

			case 22: {
				// U = Toggle Dead Player filter;
				if (!GVAR(RemoveDeadFilter)) then {
					GVAR(DeadFilter) = abs (GVAR(DeadFilter) - 1);
					GVAR(NeedUpdateLB) = true;
				};
			};

			case 57: {
				// Space - drop camera or toggle 1stperson/gunner;
				if (GVAR(cameras) select GVAR(cameraIdx) == GVAR(cam_1stperson)) then {
					GVAR(1stGunner) = !GVAR(1stGunner);
				} else {
					GVAR(DroppedCamera) = !GVAR(DroppedCamera);
					if (GVAR(DroppedCamera)) then {GVAR(cameraIdx) = 0};
				};
			};

			// Direct camera change with number keys;
			case 2: {GVAR(cameraIdx) = 0;lbSetCurSel [KCLBCAMERAS, GVAR(cameraIdx)];};
			case 3: {GVAR(cameraIdx) = 1;lbSetCurSel [KCLBCAMERAS, GVAR(cameraIdx)];};
			case 4: {GVAR(cameraIdx) = 2;lbSetCurSel [KCLBCAMERAS, GVAR(cameraIdx)];};
			case 5: {GVAR(cameraIdx) = 3;lbSetCurSel [KCLBCAMERAS, GVAR(cameraIdx)];};
			case 6: {GVAR(cameraIdx) = 4;lbSetCurSel [KCLBCAMERAS, GVAR(cameraIdx)];};

			// Toggle NVG or map text type;
			case 49: {
				if (ctrlVisible KCMAPFULL) then {
					GVAR(MarkerType) = GVAR(MarkerType) + 1;
					if (GVAR(MarkerType) > 2) then {GVAR(MarkerType) = 0};
				} else {
					//GVAR(UseNVG) = abs (GVAR(UseNVG) - 1);
					INC(GVAR(NVGMode));
					if (GVAR(NVGMode) > 2) then {
						GVAR(UseNVG) = 0;
						GVAR(NVGMode) = -1
					} else {
						GVAR(UseNVG) = 1;
					};
				};
			};

			case 50: {["ToggleMap", 0] call FUNC(spectate_events)};
			case 15: {["ToggleUI", 0] call FUNC(spectate_events)};
			case 59: {["ToggleHelp", 0] call FUNC(spectate_events)};

			// Numpad + / -;
			case 78: {if (GVAR(MarkerSize) < 1.7) then { GVAR(MarkerSize) = GVAR(MarkerSize) * 1.15 }};
			case 74: {if (GVAR(MarkerSize) > 0.7) then { GVAR(MarkerSize) = GVAR(MarkerSize) * (1/1.15)}};

			// exit spectating with X key, must be enabled
			case 45: {if (GVAR(can_exit_spectator)) then {GVAR(exit_spectator) = true}};
			
			// switch map size, K key
			case 37: {
				_ctrlm = (uiNamespace getVariable QGVAR(rscSpectate)) displayCtrl 55013;
				_ctrlm2 = (uiNamespace getVariable QGVAR(rscSpectate)) displayCtrl 50023;
				_c2pos = ctrlPosition _ctrlm2;
				if ((ctrlPosition _ctrlm) select 2 < 0.31) then {
					GVAR(minimi) = false;
					_ctrlm ctrlSetPosition [SafeZoneX + SafeZoneW - 0.6, SafeZoneY + SafeZoneH - 0.6, 0.6, 0.6];
					_ctrlm2 ctrlSetPosition [SafeZoneX + SafeZoneW - 0.6  - 0.1, _c2pos select 1, _c2pos select 2, _c2pos select 3];
				} else {
					GVAR(minimi) = true;
					_ctrlm ctrlSetPosition [SafeZoneX + SafeZoneW - 0.3, SafeZoneY + SafeZoneH - 0.3, 0.3, 0.3];
					_ctrlm2 ctrlSetPosition [SafeZoneX + SafeZoneW - 0.3  - 0.1, _c2pos select 1, _c2pos select 2, _c2pos select 3];
				};
				_ctrlm ctrlCommit 0;
				_ctrlm2 ctrlCommit 0;
				if (!isNull GVAR(target)) then {
					ctrlMapAnimClear _ctrlm;
					if (GVAR(minimi)) then {
						_ctrlm ctrlMapAnimAdd [0.1, GVAR(MinimapZoom), getPosASL (vehicle GVAR(target))];
					} else {
						_mmpo = getPosASL (vehicle GVAR(target));
						_mmratio = getResolution select 4;
						_mmscale = (ctrlMapScale _ctrlm) * 2;
						_mmoffset = if (_mmratio > 1) then {400} else {1224};
						_mmpo set [0, (_mmpo select 0) - (_mmoffset * _mmscale)];
						_mmpo set [1, (_mmpo select 1) + (_mmoffset * _mmscale)];
						_ctrlm ctrlMapAnimAdd [0.1, GVAR(MinimapZoom), _mmpo];
					};
					ctrlMapAnimCommit _ctrlm;
				};
			};
			
			// change viewdistance, V key
			case 47: {
				_ctrl = (uiNamespace getVariable QGVAR(rscSpectate)) displayCtrl 50024;
				if !(ctrlShown _ctrl) then {
					_ctrl ctrlShow true;
					((uiNamespace getVariable QGVAR(rscSpectate)) displayCtrl 50026) ctrlSetText format [localize "STR_ACE_SPECT_VDSTR", round viewDistance];
					sliderSetRange [50025, 200, 10000];
					sliderSetPosition [50025, round viewDistance];
				} else {
					_ctrl ctrlShow false;
				};
			};
		};
	};

	// Mouse events;
	case "MouseMoving": {
		_x = (_param select 1);
		_y = (_param select 2);
		GVAR(MouseCoord) = [_x, _y];
	};

	case "MouseButtonDown": {
		_x = _param select 2;
		_y = _param select 3;
		_button = _param select 1;
		GVAR(MouseButtons) set[_button, true];
		if (!GVAR(mousecheckon)) then {
			[] spawn FUNC(HMouseButtons);
		};
	};
	case "MouseButtonUp": {
		_x = _param select 2;
		_y = _param select 3;
		_button = _param select 1;
		GVAR(MouseButtons) set[_button, false];
	};

	case "MouseZChanged": {
		GVAR(MouseScroll) = GVAR(MouseScroll) + (_param select 1);
	};

	case "MouseZChangedminimap": {
		GVAR(MinimapZoom) = GVAR(MinimapZoom) + ((_param select 1) * 0.066);
		switch (true) do {
			case (GVAR(MinimapZoom) > 0.5): {GVAR(MinimapZoom) = 0.5};
			case (GVAR(MinimapZoom) < 0.05): {GVAR(MinimapZoom) = 0.05};
		};
	};
	
	case "MouseButtonDownminimap": {
		_button = _param select 1;
		GVAR(minimi_follow) = _button == 0;
	};

	case "ToggleCameraMenu": {
		// Hide/unhide camera menu;
		if (ctrlVisible KCLBCAMERAS) then {
			ctrlShow [KCLBCAMERAS, false];
			ctrlShow [KCCAMERAsBG, false];
		} else {
			ctrlShow [KCLBCAMERAS, true];
			ctrlShow [KCCAMERAsBG, true];
		};
	};

	case "ToggleTargetMenu": {
		// Hide/unhide targets menu;
		if (ctrlVisible KCLBTARGETS) then {
			ctrlShow [KCLBTARGETS, false];
			ctrlShow [KCTARGETsBG, false];
		} else {
			ctrlShow [KCLBTARGETS, true];
			ctrlShow [KCTARGETsBG, true];
		};
	};

	case "ToggleUI": {
		// Hide/unhide UI;
		if (GVAR(SHOWSEUI)) then {
			GVAR(SHOWSEUI) = false;
			GVAR(SEUICHANGED) = 0;
			{ctrlShow [_x, false]} foreach GVAR(SEUI);
			GVAR(SEUICHANGED) = GVAR(SEUICHANGED) + 1;
			0 spawn {
				sleep 5;
				GVAR(SEUICHANGED) = GVAR(SEUICHANGED) - 1;
				if (!GVAR(SHOWSEUI) && {GVAR(SEUICHANGED) == 0}) then {
					ctrlShow [KCNAME, false];
				};
			};
		} else {
			GVAR(SHOWSEUI) = true;
			{ctrlShow [_x, true]} foreach GVAR(SEUI);
			ctrlShow [KCHELP, false];
			ctrlShow [KCLBTARGETS, false];
			ctrlShow [KCTARGETsBG, false];
			ctrlShow [KCLBCAMERAS, false];
			ctrlShow [KCCAMERAsBG, false];
			ctrlShow [KCNAME, true];
		};
	};

	case "ToggleHelp": {
		// Hide/unhide Help text;
		if (ctrlVisible KCHELP) then {ctrlShow [KCHELP, false]} else {ctrlShow [KCHELP, true]};
	};

	case "ToggleMap": {
		// Hide/unhide Map;
		if (ctrlVisible KCMAP && {ctrlVisible KCMAPFULL}) then {
			// Beginning, hide both;
			ctrlShow [KCMAP, false];
			ctrlShow [KCMAPFULL, false];
			ctrlShow [KCMAPFULLBG, false];
		};

		if (ctrlVisible KCMAP) then {
			ctrlShow [KCMAP, false];
			ctrlShow [KCMAPFULL, true];
			ctrlShow [KCMAPFULLBG, true];
			if (ctrlVisible KCLBTARGETS) then {
				ctrlShow [KCLBTARGETS, false];
				ctrlShow [KCTARGETsBG, false];
			};
			if (ctrlVisible KCLBCAMERAS) then {
				ctrlShow [KCLBCAMERAS, false];
				ctrlShow [KCCAMERAsBG, false];
			};
			ctrlShow [KCRBUTTON1, false];
			ctrlShow [KCRBUTTON2, false];
			ctrlShow [KCRBUTTON3, false];
			ctrlShow [KCRBUTTON4, false];
			GVAR(MarkerNames) = true;
			GVAR(SoundVolume) = soundVolume;
			0.5 fadeSound 0.2;
		} else {
			GVAR(MarkerNames) = false;
			if (ctrlVisible KCMAPFULL) then {
				ctrlShow [KCMAPFULL, false];
				ctrlShow [KCMAPFULLBG, false];
				ctrlShow [KCRBUTTON1, true];
				ctrlShow [KCRBUTTON2, true];
				ctrlShow [KCRBUTTON3, true];
				ctrlShow [KCRBUTTON4, true];
				0.5 fadeSound GVAR(SoundVolume);
				GVAR(MissileCamOver) = true;
			} else {
				ctrlShow [KCMAP, true];
			};
		};
	};

	case "ToggleMapBird": {
		if (!dialog) then {createDialog "ACE_rscSpectateBirdMap"} else {closeDialog 0};
	};

	// Toggle particlesource tags;
	case "ToggleTags": {
		if (_param select 0) then {
			// turn on;
			_lifeTime = 0.5;
			_dropPeriod = 0.05;
			_size = 0.5;
			_cam = _param select 1;
			{
				_u = _x select 0;
				_s = _x select 1;
				if (alive _u) then {
					_size = 1.33 min (((vehicle _u) distance _cam) / 100);
					_color = switch (side _u) do {
						case east: {[1, 0, 0, 1]};
						case west: {[0, 0, 1, 1]};
						case resistance: {[0, 1, 0, 1]};
						default {[1, 1, 1, 1]};
					};
					_colorB = [_color select 0, _color select 1, _color select 2, 0];
					_s setParticleParams [QUOTE(PATHTOF(tag.p3d)), "", "billboard", 1, _lifeTime, [0, 0, 2], [0, 0, 0], 1, 1, 0.784, 0.1, [_size, _size*0.66], [_color, _color, _color, _color, _colorB], [1], 10.0, 0.0, "", "", vehicle _u];
					_s setDropInterval _dropPeriod;
				} else {
					_s setDropInterval 0;
				};
			} foreach GVAR(Tagsources);
		} else {
			// turn off;
			{(_x select 1) setDropInterval 0} foreach GVAR(Tagsources);
		};
	};

	/*// Add string to event log;
	case "EventLogAdd": {
		_txt = _param select 0;
		diag_log _txt;
	};*/

	// Killed eventhandler, add to log, only available in SP
	case "UnitKilled": {
		_killed = _param select 0;
		_killer = _param select 1;
		_txt = format["%1 (%2) was killed by %3 (%4) (%5m)", _killed, _killed call FUNC(CheckOriginalSide), _killer, side _killer, _killed distance _killer];
		player groupChat _txt;
		diag_log _txt;
	};

	// Fired eventhandler, display as marker in map;
	// Also missile camera is handled here;
	case "UnitFired": {
		if (GVAR(MissileCamActive)) exitWith {};
		_u = _param select 0;
		_w = _param select 1;
		_a = _param select 4;
		_o = _param select 6; // Uses BIS Fired EH
		_type = getText(configFile >> "CfgAmmo" >> typeOf _o >> "simulation");
		if (GVAR(Tags) == 1 && {_type == "shotBullet"}) then {
			// Bullet path bar;
			_bar = switch (side _u) do {
				case west: {"ACE_KEGspect_bar_red"};
				case east: {"ACE_KEGspect_bar_green"};
				default {"ACE_KEGspect_bar_yellow"};
			};

			_bars = [];
			for "_i" from 0 to 300 step 5 do {
				_pos = _o modelToWorld [0, _i + 2.5, 0];
				_b = _bar createVehicleLocal _pos;
				_b setVectorDir (vectorDir _o);
				_b setVectorUp (vectorUp _o);
				_bars set [count _bars, _b];
			};
			_bars spawn FUNC(barsremove);
		};
		if (ctrlVisible KCMAPFULL) then {
			_len = (speed _o) / 15;
			_dir = getdir _o;
			// Marker for shot effect (stationary circle);
			_m2 = createMarkerLocal ["DOT", getPosASL _o];
			// _m2 = createMarkerLocal[format["KEGsMarkerFired%1", random 10000], getpos _o];
			_m2 setMarkerColorLocal "ColorYellow";
			_m2 setMarkerSizeLocal [0.45, 0.45];
			_m2 setMarkerTypeLocal "Select";

			// Marker for round itself, for bullet display line, everything else a named marker
			if (_type in ["shotMissile", "shotRocket", "shotShell", "shotTimeBomb", "shotPipeBomb", "shotMine", "shotSmoke"]) then {
				_opos = getPosASL _o;
				_m = createMarkerLocal ["DOT", [(_opos select 0) + (sin _dir) * _len, (_opos select 1) + (cos _dir) * _len, 0]];
				// _m = createMarkerLocal[format["KEGsMarkerFired%1", random 10000], [(getpos _o select 0)+(sin _dir)*_len, (getpos _o select 1)+(cos _dir)*_len, 0]];
				_m setMarkerTypeLocal "Dot";
				_m setMarkerColorLocal "ColorWhite";
				_m setMarkerSizeLocal [0.25, 0.5];
				_name = getText(configFile >> "CfgWeapons" >> _w >> "displayName");
				_m setMarkerTextLocal _name;
				_m2 spawn FUNC(markerdel);
				[_m, _o] spawn FUNC(markerupdateev);
			} else {
				//_m = createMarkerLocal[format["KEGsMarkerFired%1", random 10000], [(getpos _o select 0)+(sin _dir)*_len, (getpos _o select 1)+(cos _dir)*_len, 0]];
				_opos = getPosASL _o;
				_m = createMarkerLocal ["DOT", [(_opos select 0) + (sin _dir) * _len, (_opos select 1) + (cos _dir) * _len, 0]];
				_m setMarkerShapeLocal "RECTANGLE";
				_m setMarkerSizeLocal [0.25, _len];
				_m setMarkerDirLocal (getdir _o);
				//_m setMarkerColorLocal "KEGsDarkYellow";
				_m setMarkerColorLocal "ColorYellow";
				// KEGsYellowAlpha
				[_m2, _m] spawn FUNC(markerdel2);
			}
		} else {
			// Missile camera;
			if (GVAR(UseMissileCam) == 1 && {!GVAR(DroppedCamera)} && {_u == vehicle GVAR(target)} && {(_type in ["shotMissile", "shotRocket", "shotShell"])} && {!GVAR(MissileCamActive)}) then {
				_name = getText(configFile >> "CfgWeapons" >> _w >> "displayName");
				GVAR(MissileCamActive) = true;
				cutText [_name, "PLAIN DOWN", 0.10];
				GVAR(cam_missile) switchCamera "INTERNAL";
				GVAR(cam_missile) cameraEffect ["internal", "BACK"];
				GVAR(cam_missile) camSetTarget _o;
				GVAR(cam_missile) camSetRelPos [0, 0, 0];
				GVAR(cam_missile) camSetFov 0.5;
				GVAR(cam_missile) camCommit 0;
				GVAR(cam_missile) camSetFov 1.25;
				GVAR(cam_missile) camCommit 2;
				_o spawn FUNC(missilcamrun);
			};
		};
	};

	default {
		hint "Unknown event";
	};
};

false