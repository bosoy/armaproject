#include "script_component.hpp"

PREP(startSpectator);
PREP(spectate_events);
PREP(menucamslbchange);

GVAR(unitswithside) = [];

FUNC(missilcamrun) = {
	private "_oldcam";
	_oldcam = GVAR(cameraIdx);
	while {!isNull _this && {speed _this > 1} && {_oldcam == GVAR(cameraIdx)} && {dialog}} do {
		GVAR(cam_missile) camSetTarget _this;
		GVAR(cam_missile) camSetRelPos [0, -0.5, 0.30];
		GVAR(cam_missile) camCommit 0;
		sleep 0.01;
	};
	if (_oldcam == GVAR(cameraIdx) && {dialog}) then {
		sleep 3;
	};
	GVAR(MissileCamActive) = false;
	GVAR(MissileCamOver) = true;
};

FUNC(markerdel) = {
	sleep 2; deleteMarkerLocal _this
};

FUNC(markerupdateev) = {
	PARAMS_2(_m,_o);
	while {!isNull _o } do {
		_m setMarkerPosLocal getPosASL _o;
		_m setMarkerDirLocal getdir _o;
		sleep 0.02;
	};
	_m setMarkerColorLocal "ColorBlack";
	sleep 3;
	deleteMarkerLocal _m;
};

FUNC(markerdel2) = {
	sleep 1.0;(_this select 1) setMarkerColorLocal "ColorYellow";sleep 1;deleteMarkerLocal (_this select 1);deleteMarkerLocal (_this select 0)
};

FUNC(barsremove) = {
	sleep 1.5; {deleteVehicle _x} foreach _this
};

FUNC(togmapf) = {
	sleep 0.25; ["ToggleMap", 0] call FUNC(spectate_events); ["ToggleMap", 0] call FUNC(spectate_events);
};

FUNC(vdsliderchanged) = {
	disableSerialization;
	((uiNamespace getVariable QGVAR(rscSpectate)) displayCtrl 50026) ctrlSetText format [localize "STR_ACE_SPECT_VDSTR", round (_this select 1)];
};

FUNC(vdsavebuttonclick) = {
	setViewDistance (sliderPosition 50025);
};

FUNC(GetMCol) = {
	switch (_this) do {
		case west: {"ColorBlue"};
		case east: {"ColorRed"};
		case resistance: {"ColorGreen"};
		case civilian: {"ColorWhite"};
		default {"ColorWhite"};
	}
};

FUNC(CheckOriginalSide) =  {
	private ["_s", "_r", "_rd"];
	_s = _this getVariable QGVAR(oside);
	if (isNil "_s") then {
		// side group unit always returns the correct side, even if the unit is death and side unit returns civ
		_s = side (group _this);
		_this setVariable [QGVAR(oside), _s];
	};
	_s
};

FUNC(updatemarkers) = {
	if (GVAR(NoMarkersUpdates)) exitWith {};
	GVAR(markersrun) = true;
	private ["_markers", "_disp", "_cMapFull", "_mapFull", "_mappos", "_markedVehicles", "_i", "_m", "_u", "_OriginalSide", "_type", "_icon"];
	PARAMS_1(_markers);
	disableSerialization;
	_disp = uiNamespace getVariable QGVAR(rscSpectate);
	_cMapFull = 55014;
	if (ctrlVisible _cMapFull) then {
		// Position camera in the middle of full map, for sound and
		// smoother marker motion (distant objects appear less smooth)
		_mapFull = _disp displayctrl _cMapFull;
		_mappos = _mapFull posScreenToWorld[0.5, 0.5];
		GVAR(cam_fullmap) camSetTarget _mappos;
		GVAR(cam_fullmap) camSetRelPos [0, -1, 150];
		GVAR(cam_fullmap) camCommit 0;
	};

	_markedVehicles = []; // Keep track of vehicles with markers to avoid multiple markers for one vehicle
	for "_i" from 0 to (count _markers - 1) do {
		if (GVAR(exitspect)) exitWith {};
		if (_i >= count _markers) exitWith {};
		_mo = _markers select _i;
		_m = _mo select 0;
		_u = _mo select 1;
		// show only markers from units that are in the target list!
		if (_u in GVAR(units)) then {
			if (speed vehicle _u > 0) then {
				_m setMarkerPosLocal (getPosASL (vehicle _u));
			} else {
				if (alive _u) then {
					_hpos = getPosASL (vehicle _u); _mpos = markerPos _m;
					if (_hpos select 0 != _mpos select 0 || {_hpos select 1 != _mpos select 1}) then {
						_m setMarkerPosLocal (getPosASL (vehicle _u));
					};
				};
			};

			_OriginalSide = _u call FUNC(CheckOriginalSide);
			if (!(_OriginalSide in GVAR(ShownSides))) then {
				// We arent' supposed to show this side unit - hide marker
				if (markerType _m != "empty") then {_m setMarkerTypeLocal "empty"};
			} else {
				if (GVAR(MarkerNames) || {GVAR(MinimapZoom) < 0.15}) then {
					// Set full screen map marker types - Also zoomed minimap
					if (ctrlVisible _cMapFull) then {
						switch(GVAR(MarkerType)) do {
							case 0: {	// No text
								if (markerText _m != "") then {
									_m setMarkerTextLocal "";
								};
							};
							case 1: {	// Names
								if (alive (vehicle _u)) then {
									if (markerText _m != (_mo select 2)) then {_m setMarkerTextLocal (_mo select 2)};
								};
							};
							case 2: {	// Types
								_na = getText (configFile >> "CfgVehicles" >> typeOf (vehicle _u) >> "DisplayName");
								if (markerText _m != _na) then {_m setMarkerTextLocal _na};
							};
						};
					} else {
						// Minimap with detailed icons but no text
						if (markerText _m != "") then {_m setMarkerTextLocal ""};
					};

					_icon = (vehicle _u) getVariable QGVAR(icon);
					if (isNil "_icon") then {
						_icon = switch (getText(configFile >> "CfgVehicles" >> typeOf (vehicle _u) >> "simulation")) do {
							case "tank": {"n_armor"};
							case "car": {"n_motor_inf"};
							case "soldier": {"n_inf"};
							case "airplane": {"n_plane"};
							case "helicopter": {"n_air"};
							case "motorcycle": {"n_motor_inf"};
							default {"Arrow"};
						};
						(vehicle _u) setVariable [QGVAR(icon), _icon];
					};
					if (markerType _m != _icon) then {_m setMarkerTypeLocal _icon};
					_siz = markerSize _m;
					_nnsiz = 0.42 * GVAR(MarkerSize);
					if (_siz select 0 != _nnsiz || {_siz select 1 != _nnsiz}) then {_m setMarkerSizeLocal [_nnsiz, _nnsiz]};
					_ddir = direction vehicle _u;
					if (markerDir _m != _ddir) then {_m setMarkerDirLocal _ddir};
				} else {
					if (markerText _m != "") then {_m setMarkerTextLocal ""};
					if (markerType _m != "Dot") then {_m setMarkerTypeLocal "Dot"};
					_siz = markerSize _m;
					if (_siz select 0 != 0.4 || {_siz select 1 != 0.4}) then {_m setMarkerSizeLocal [0.4, 0.4]};
				};
			};

			if (!alive _u) then {_m setMarkerColorLocal "ColorBlack"};

			if (vehicle _u in _markedVehicles) then {
				// This vehicle was already marked, hide marker
				if (markerType _m != "Empty") then {_m setMarkerTypeLocal "Empty"};
			} else {
				_markedVehicles set [count _markedVehicles, vehicle _u];
			};
		} else {
			if (markerType _m != "Empty") then {_m setMarkerTypeLocal "Empty"};
		};
	};
	GVAR(markersrun) = false;
};

FUNC(CheckU) = {
	private ["_r", "_isloc", "_isalive", "_unc"];
	_r = true;_unc = false;_isalive = alive _this;
	if (GVAR(playable_only) && {!((_this in playableUnits) || {(_this in switchableUnits)})}) then {_r = false};
	if (_r) then {
		if (!isPlayer _this && {GVAR(AIfilter) == 1}) exitWith {_r = false};
		_isloc = (_this == player);
		if (!_isloc && {!_isalive} && {GVAR(DeadFilter) == 1}) exitWith {_r = false};
		if (!_isloc && {GVAR(gfleader)} && {(_this != formationLeader _this || {_this != leader _this})}) exitWith {_r = false};
		if (!_isloc && {GVAR(CheckDist) != -1} && {_this distance player > GVAR(CheckDist)}) exitWith {_r = false};
		if (GVAR(CheckUncon)) then {
			if (_isalive && {!_isloc}) then {_unc = _this call ace_sys_wounds_fnc_isUncon;if (_unc) then {_r = false}};
		} else {
			if (_isalive) then {_unc = _this call ace_sys_wounds_fnc_isUncon};
		};
	};
	[_r, _unc, _isalive]
};

FUNC(HMouseButtons) = {
	GVAR(mousecheckon) = true;
	while {(GVAR(MouseButtons) select 0) || {(GVAR(MouseButtons) select 1)}} do {
		// Process mouse movement
		switch (true) do {
			case (!(GVAR(MouseButtons) select 0) && {(GVAR(MouseButtons) select 1)}): {
				// Right mouse button - Adjust position
				GVAR(fangle) = GVAR(fangle) - ((GVAR(mouseDeltaPos) select 0) * 360);
				GVAR(fangleY) = GVAR(fangleY) + ((GVAR(mouseDeltaPos) select 1) * 180);
				switch (true) do {
					case (GVAR(fangleY) > 89): {GVAR(fangleY) = 89};
					case (GVAR(fangleY) < -89): {GVAR(fangleY) = -89};
				};
			};
			case ((GVAR(MouseButtons) select 0) && {!(GVAR(MouseButtons) select 1)}): {
				// Left mouse button - Adjust distance
				GVAR(sdistance) = GVAR(sdistance) - ((GVAR(mouseDeltaPos) select 1) * 10);
				switch (true) do {
					case (GVAR(sdistance) > GVAR(maxDistance)): {GVAR(sdistance) = GVAR(maxDistance)};
					case (GVAR(sdistance) < -GVAR(maxDistance)): {GVAR(sdistance) = -GVAR(maxDistance)};
				};
				if (GVAR(sdistance) < -0.6) then {GVAR(sdistance) = -0.6};
			};
			case ((GVAR(MouseButtons) select 0) && {(GVAR(MouseButtons) select 1)}): {
				// Both mousebuttons - Adjust zoom
				GVAR(szoom) = GVAR(szoom) - ((GVAR(mouseDeltaPos) select 1) * 3);
				switch (true) do {
					case (GVAR(szoom) > 2): {GVAR(szoom) = 2};
					case (GVAR(szoom) < 0.05): {GVAR(szoom) = 0.05};
				};
			};
		};
		if (GVAR(exitspect)) exitWith {};
		sleep 0.0034;
	};
	GVAR(mousecheckon) = false;
};

FUNC(onmapdraw) = {
	if (GVAR(DoFirstUnitCheck)) then {
		call FUNC(FirstUnitCheck);
		GVAR(DoFirstUnitCheck) = false;
	};
	if (count GVAR(TogTagsParams) > 0) then {
		["ToggleTags", GVAR(TogTagsParams)] call FUNC(spectate_events);
		GVAR(TogTagsParams) = [];
	};
	if (!GVAR(exit_the_frame)) then {call FUNC(MainLoop)};
};

FUNC(UpdateLB) = {
	GVAR(updating_lb) = true;
	private ["_cLBTargets", "_deadstr", "_clbcols", "_idx", "_oside", "_rr", "_name", "_i", "_colidx", "_prest", "_excluded"];
	PARAMS_3(_cLBTargets,_deadstr,_clbcols);
	_uns = []; _rest = []; _idx = 0; _prest = [];
	{
		_oside = _x call FUNC(CheckOriginalSide);
		if (_oside in GVAR(ShownSides)) then {
			if (GVAR(CheckCaptive) && {captive _x}) exitWith {}; // Exit's only the if scope
			_excluded = _x getVariable QGVAR(exclude);
			if !(isNil "_excluded") exitWith{}; // Exit's only the if scope.
			_rr = _x call FUNC(CheckU);
			if (_rr select 0) then {
				_uns set [count _uns, _x];
				_name = _x getVariable QGVAR(nameu);
				if !(_rr select 2) then {_name = _deadstr + _name} else {if (_rr select 1) then {_name = "(Unc) " + _name}};
				_colidx =  if (_idx == GVAR(tgtIdx)) then {0} else {if (_rr select 2) then {switch (_oside) do {case west: {1};case east: {2};case resistance: {3};case civilian: {4};}} else {5}};
				if (isNil "ace_sys_wounds_withSpect") then {
					_rest set [count _rest, [_name, _idx, _colidx]];
				} else {
					if (_x != player) then {
						_rest set [count _rest, [_name, _idx, _colidx]];
					} else {
						_prest = [_name, _idx, _colidx];
					};
				};
			};
		};
		_idx = _idx + 1;
		if (GVAR(exitspect)) exitWith {};
	} forEach GVAR(deathCam);
	if (GVAR(exitspect)) exitWith {};
	if (count _prest > 0) then { // make sure, player is the first listbox entry when with Spect is enabled in wounds
		// BIS array UnShift doesn't work, returns totally broken arrays, make own function ?
		_rest resize (count _rest + 1);
		for "_v" from (count _rest - 1) to 1 step - 1 do {
			_rest set [_v, _rest select (_v - 1)];
		};
		_rest set [0, _prest];
		_uns = _uns - [player];
		_uns resize (count _uns + 1);
		for "_v" from (count _uns - 1) to 1 step - 1 do {
			_uns set [_v, _uns select (_v - 1)];
		};
		_uns set [0, player];
	};
	// Clear and re-fill targets listbox
	GVAR(units) = _uns;
	lbClear _cLBTargets;
	{
		_i = lbAdd [_cLBTargets, _x select 0];
		lbSetValue [_cLBTargets, _i, _x select 1]; // Value used to id unit
		lbSetColor [_cLBTargets, _i, _clbcols select (_x select 2)];
		if (GVAR(exitspect)) exitWith {};
	} forEach _rest;
	GVAR(lastAutoUpdateLB) = time;
	GVAR(NeedUpdateLB) = false;
	GVAR(updating_lb) = false;
};

FUNC(CheckNew) = {
	private ["_newUnits", "_newVehicles", "_nn", "_fh", "_nunits", "_iswu", "_gg", "_m", "_markstr", "_unknownstr", "_OriginalSide", "_s", "_cameras", "_allUnits"];
	PARAMS_3(_markstr,_unknownstr,_cameras);
	// Avoid game logics
	_allUnits = if (GVAR(playable_only)) then {if (isMultiplayer) then {playableUnits} else {switchableUnits}} else {allUnits};
	_newUnits = _allUnits - GVAR(deathCam);
	_newVehicles = vehicles - GVAR(ehVehicles);
	if (count _newVehicles > 0) then {
		// Add event handlers to new vehicles
		GVAR(ehVehicles) = [GVAR(ehVehicles), _newVehicles] call BIS_fnc_arrayPushStack;
		{
			// Add fired eventhandler for map indication
			_nn = _x getVariable QGVAR(EHFired);
			if (isNil "_nn") then {
				_fh = _x addEventHandler ["fired", {["UnitFired",_this] call FUNC(spectate_events)}];
				_x setVariable [QGVAR(EHFired), _fh];
				_x setVariable [QGVAR(mapmove), false];
			};
		} foreach _newVehicles;
	};
	if (count _newUnits > 0) then {
		_nunits = [];
		{
			_iswu = false;
			_gg = _x getVariable [QGVAR(SPECT), false];
			if (!_gg) then {
				// If variable not found, set it, thus unit is tagged for next update cycle
				// This way, (re)spawned units have some time to fully initialize. Name arma.rpt Error fix.
				_x setVariable [QGVAR(SPECT), true];
				_x setVariable [QGVAR(mapmove), false];
				_iswu = true;
			};
			if (!isMultiplayer && {GVAR(UseLog)}) then {
				_nn = _x getVariable QGVAR(EHKilled);
				if (isNil "_nn") then {
					_fh = _x addEventHandler ["killed", {["UnitKilled",_this] call FUNC(spectate_events)}];
					_x setVariable [QGVAR(EHKilled), _fh];
				};
			};
			if (!_iswu) then {
				_nunits set [count _nunits, _x];
				_m = createMarkerLocal [format[_markstr, count GVAR(markers)], [0, 0, 0]];
				_m setMarkerTypeLocal "Dot";
				_m setMarkerSizeLocal [0.4, 0.4];
				_nn = if (alive _x) then {name _x} else {_unknownstr};
				GVAR(markers) set [count GVAR(markers), [_m, _x, _nn]];

				_OriginalSide = _x call FUNC(CheckOriginalSide);

				// Set marker color
				_m setMarkerColorLocal (_OriginalSide call FUNC(GetMCol));
				_m setMarkerPosLocal (getPosASL (vehicle _x));

				// Create particle source
				_s = "#particlesource" createVehicleLocal getPosASL _x;
				GVAR(Tagsources) set [count GVAR(Tagsources), [_x, _s]];

				// If tags are on, turn them off and back again to include new units
				if (GVAR(Tags) == 1) then {
					["ToggleTags", [false, _cameras select GVAR(cameraIdx)]] call FUNC(spectate_events);
					["ToggleTags", [true, _cameras select GVAR(cameraIdx)]] call FUNC(spectate_events);
				};
				_x setVariable [QGVAR(nameu), _nn];
			};
		} forEach _newUnits;
		// Add new units to end of list
		GVAR(deathCam) = [GVAR(deathCam), _nunits] call BIS_fnc_arrayPushStack;
		// Request listbox update
		GVAR(NeedUpdateLB) = true;
	};
	GVAR(lastCheckNewUnits) = time;
	GVAR(newCheckUn) = false;
};

FUNC(FirstUnitCheck) = {
	private ["_allUnits", "_allVehicles", "_nn", "_fh", "_gg", "_m", "_markstr", "_unknownstr", "_OriginalSide", "_s", "_cameras"];
	// Avoid game logics
	_markstr = "ace_sys_spect_Marker%1";
	_allUnits = if (GVAR(playable_only)) then {if (isMultiplayer) then {playableUnits} else {switchableUnits}} else {allUnits};
	_allVehicles = vehicles;
	if (count _allVehicles > 0) then {
		// Add event handlers to new vehicles
		GVAR(ehVehicles) = _allVehicles;
		{
			// Add fired eventhandler for map indication
			_nn = _x getVariable QGVAR(EHFired);
			if (isNil "_nn") then {
				_fh = _x addEventHandler ["fired", {["UnitFired",_this] call FUNC(spectate_events)}];
				_x setVariable [QGVAR(EHFired), _fh];
				_x setVariable [QGVAR(mapmove), false];
			};
		} foreach _allVehicles;
	};
	if (count _allUnits > 0) then {
		{
			_gg = _x getVariable [QGVAR(SPECT), false];
			if (!_gg) then {
				// If variable not found, set it, thus unit is tagged for next update cycle
				// This way, (re)spawned units have some time to fully initialize. Name arma.rpt Error fix.
				_x setVariable [QGVAR(SPECT), true];
				_x setVariable [QGVAR(mapmove), false];
			};

			if (!isMultiplayer && {GVAR(UseLog)}) then {
				_nn = _x getVariable QGVAR(EHKilled);
				if (isNil "_nn") then {
					_fh = _x addEventHandler ["killed", {["UnitKilled",_this] call FUNC(spectate_events)}];
					_x setVariable [QGVAR(EHKilled), _fh];
				};
			};

			_m = createMarkerLocal [format[_markstr, count GVAR(markers)], [0, 0, 0]];
			_m setMarkerTypeLocal "Dot";
			_m setMarkerSizeLocal [0.4, 0.4];
			_nn = if (alive _x) then {name _x} else {_unknownstr};
			GVAR(markers) set [count GVAR(markers), [_m, _x, _nn]];

			_OriginalSide = _x call FUNC(CheckOriginalSide);

			// Set marker color
			_m setMarkerColorLocal (_OriginalSide call FUNC(GetMCol));
			_m setMarkerPosLocal (getPosASL (vehicle _x));

			// Create particle source
			_s = "#particlesource" createVehicleLocal getPosASL _x;
			GVAR(Tagsources) set [count GVAR(Tagsources), [_x, _s]];

			// If tags are on, turn them off and back again to include new units
			if (GVAR(Tags) == 1) then {
				["ToggleTags",[false, (GVAR(cameras) select GVAR(cameraIdx))]] call FUNC(spectate_events);
				["ToggleTags",[true, (GVAR(cameras) select GVAR(cameraIdx))]] call FUNC(spectate_events);
			};
			_x setVariable [QGVAR(nameu), _nn];
		} forEach _allUnits;

		// Add new units to end of list
		GVAR(deathCam) = _allUnits;

		// Request listbox update
		GVAR(NeedUpdateLB) = true;
	};
};

FUNC(MainLoop) = {
	TRACE_1("FUNC(MainLoop) startet","");
	private ["_cCamera", "_cTarget", "_cName", "_cLBTargets", "_cLBCameras", "_cMapFull", "_cMap", "_cRButton1", "_cRButton2", "_cRButton3", "_cRButton4", "_cRCompass", "_clbcols", "_disp", "_acer", "_ctlr", "_llbsize", "_idx", "_ot", "_oside", "_coldidx", "_rate", "_map", "_mm", "_dir", "_bb", "_foo", "_l", "_w", "_hstr", "_role", "_name", "_vectar", "_camdir", "_ctrloverlay", "_spd", "_spdbase", "_bstr", "_tbasebstr", "_objs", "_dist", "_d", "_nixx", "_wpos", "_nname", "_vpmtw", "_gjp", "_lsdist", "_z", "_co", "_comSpeed"];
	_cCamera = 55002;
	_cTarget = 55003;
	_cName = 55004;
	_cLBTargets = 55006;
	_cLBCameras = 55005;
	_cMapFull = 55014;
	_cMap = 55013;
	_cRButton1 = 50018;
	_cRButton2 = 50019;
	_cRButton3 = 50020;
	_cRButton4 = 50021;
	_cRCompass = 50023;
	_clbcols = [[1, 0.5, 0, 1], [0.8, 0.8, 1, 1], [1, 0.8, 0.8, 1], [0.8, 1, 0.8, 1], [1, 1, 1, 1], [0.5, 0.5, 0.5, 1]];
	GVAR(cameraIdx) = GVAR(NewCameraIdx);
	GVAR(mouseDeltaPos) set [0, GVAR(mouseLastX) - (GVAR(MouseCoord) select 0)];
	GVAR(mouseDeltaPos) set [1, GVAR(mouseLastY) - (GVAR(MouseCoord) select 1)];
	GVAR(mouseLastX) = GVAR(MouseCoord) select 0;
	GVAR(mouseLastY) = GVAR(MouseCoord) select 1;
	// don't move MouseScroll to events!
	if (GVAR(MouseScroll) != 0) then {
		// Mouse scroll wheel - Adjust distance
		GVAR(sdistance) = GVAR(sdistance) - (GVAR(MouseScroll) * 0.11);
		GVAR(MouseScroll) = GVAR(MouseScroll) * 0.75;
		switch (true) do {
			case (GVAR(sdistance) > GVAR(maxDistance)): {GVAR(sdistance) = GVAR(maxDistance)};
			case (GVAR(sdistance) < -GVAR(maxDistance)): {GVAR(sdistance) = -GVAR(maxDistance)};
		};
		if (GVAR(sdistance) < -0.6) then {GVAR(sdistance) = -0.6};
	};

	_disp = uiNamespace getVariable QGVAR(rscSpectate);

	if (!isNil "ace_sys_wounds_enabled" && {!isNil "ace_wounds_prevtime"} && {!ace_wounds_no_prevtime}) then {
		_acer = player getVariable ["ace_w_revive", -1];
		if (_acer != -1) then {
			_ctlr = _disp displayCtrl 50022;
			_ctlr ctrlSetText format [GVAR(specstrings) select 8, (round (_acer - time)) max 0];
			_ctlr ctrlCommit 0;
		};
	};

	// CHECK FOR NEW PLAYER TARGET
	_llbsize = lbSize _cLBTargets;
	if (_llbsize > 0 && {!GVAR(updating_lb)}) then {
		if (lbCurSel _cLBTargets > (_llbsize - 1)) then {
			lbSetCurSel [_cLBTargets, _llbsize - 1]; // Selection outside listbox size
		};
		if (GVAR(tgtSelLast) != lbCurSel _cLBTargets) then {
			GVAR(DroppedCamera) = false;

			for "_idx" from 0 to (lbSize _cLBTargets) - 1 do {
				if (_idx == (lbSize _cLBTargets)) exitWith {};
				if (lbValue [_cLBTargets, _idx] == GVAR(lasttgtIdx)) exitWith {
					_ot = GVAR(deathcam) select GVAR(lasttgtIdx);
					_oside = _ot call FUNC(CheckOriginalSide);
					_coldidx = if (alive _ot) then {switch (_oside) do {case west: {1};case east: {2};case resistance: {3};case civilian: {4};}} else {5};
					lbSetColor [_cLBTargets, _idx, _clbcols select _coldidx];
				};
			};

			if (GVAR(cameraIdx) == 4) then {GVAR(target) switchCamera "INTERNAL"};
			GVAR(tgtSelLast) = lbCurSel _cLBTargets; //immediately capture the last selected target index
			GVAR(tgtIdx) = lbValue [_cLBTargets, GVAR(tgtSelLast)]; // Get the new player target
			GVAR(lasttgtIdx) = GVAR(tgtIdx);
			lbSetColor [_cLBTargets, GVAR(tgtSelLast), [1, 0.5, 0, 1]];
		};
	};

	// Check for new units every 4 seconds
	if (time - GVAR(lastCheckNewUnits) > 4 && {!GVAR(MissileCamActive)} && {!GVAR(NeedUpdateLB)} && {!GVAR(newCheckUn)}) then {
		//player setVariable ["BIS_IS_inAgony",false];
		GVAR(newCheckUn) = true;
		[GVAR(specstrings) select 1,GVAR(specstrings) select 2,GVAR(cameras)] call FUNC(CheckNew);
	};
	// If there are no Cameras attached to soldiers yet then then exit the call loop and continue
	if (count GVAR(deathCam) < 1) exitWith {};
	if (!GVAR(Spect_Init) && {count GVAR(deathCam) > 0}) then {player groupChat (localize "STR_ACE_SPECT_INITED"); GVAR(Spect_Init) = true};

	// Request listbox update every 20 seconds to update dead units or jip player names
	// or when NeedUpdateLB is set to true
	if ((GVAR(NeedUpdateLB) || {(time - GVAR(lastAutoUpdateLB) > 20)}) && {!GVAR(MissileCamActive)} && {!GVAR(markersrun)} && {!GVAR(newCheckUn)} && {!GVAR(updating_lb)}) then {
		[_cLBTargets, GVAR(specstrings) select 0, _clbcols] call FUNC(UpdateLB);
	};

	if (!GVAR(updating_lb)) then {
		if (!(GVAR(target) in GVAR(units)) && {lbSize _cLBTargets > 0}) then {
			GVAR(tgtIdx) = lbValue [_cLBTargets, 0];
		};

		// lbSort menuTargets;
		// Check limits
		switch (true) do {
			case (GVAR(tgtIdx) > (count GVAR(deathCam) - 1)): {GVAR(tgtIdx) = (count GVAR(deathCam)) - 1};
			case (GVAR(tgtIdx) < 0): {GVAR(tgtIdx) = 0};
		};
	};

	// Select camera, get target
	if (!GVAR(MissileCamActive)) then {
		// If not in First Person mode rest camera
		GVAR(target) = GVAR(deathCam) select GVAR(tgtIdx);  // reset camera to the new or current player target
		if (GVAR(oldtarget) != GVAR(target) && {!isNull GVAR(oldtarget)}) then {(vehicle GVAR(oldtarget)) setVariable [QGVAR(mapmove), false]};
		GVAR(oldtarget) = GVAR(target);
		if (GVAR(cameraIdx) != 4 && {(GVAR(oldCameraIdx) != GVAR(cameraIdx) || {GVAR(MissileCamOver)})}) then {
			GVAR(MissileCamOver) = false;
			(GVAR(cameras) select GVAR(cameraIdx)) cameraEffect["internal", "BACK"];
			(GVAR(cameras) select GVAR(cameraIdx)) camCommit 0;
			GVAR(oldCameraIdx) = GVAR(cameraIdx);
		};
	};
	if (GVAR(cameraIdx) == 4) then {
		if (GVAR(1stGunner)) then {
			if (cameraView != "GUNNER") then {(vehicle GVAR(target)) switchCamera "GUNNER"};
		} else {
			(vehicle GVAR(target)) switchCamera "INTERNAL";
		};
		GVAR(oldCameraIdx) = GVAR(cameraIdx);
		(vehicle GVAR(target)) cameraEffect ["terminate","BACK"];
		(vehicle GVAR(target)) camCommit 0.01;
	};

	lbSetCurSel [_cLBCameras, GVAR(cameraIdx)];	// reset camera mode selection in the listbox to the new or current camera mode

	if (!GVAR(updating_lb) && {lbValue [_cLBTargets, (lbCurSel _cLBTargets)] != GVAR(tgtIdx)}) then {
		// Find listbox element with matching value
		for "_idx" from 0 to (lbSize _cLBTargets) - 1 do {
			if (_idx == (lbSize _cLBTargets)) exitWith {};
			if (lbValue [_cLBTargets, _idx] == GVAR(tgtIdx)) exitWith {
				lbSetCurSel [_cLBTargets, _idx];
			};
		};
	};

	if (GVAR(OldNVGMethod)) then {
		camUseNVG (GVAR(UseNVG) == 1);
		setAperture (if (GVAR(UseNVG) == 1) then {4} else {-1});
	} else {
		//setAperture (if (GVAR(UseNVG) == 1) then {0.07} else {-1});
		if (GVAR(UseNVG) == 1) then {
			if (GVAR(NVGMode) != GVAR(OldNVGMode)) then {
				switch (GVAR(NVGMode)) do {
					case 0: {
						setAperture -1;
						true setCamUseTi GVAR(NVGMode);
					};
					case 1: {
						setAperture -1;
						true setCamUseTi GVAR(NVGMode);
					};
					case 2: {
						false setCamUseTi 0;
						setAperture 0.07;
					};
				};
				GVAR(OldNVGMode) = GVAR(NVGMode);
			};
		} else {
			false setCamUseTi 0;
			setAperture -1;
		};
	};

	if (ctrlVisible _cMapFull) then {
		GVAR(cam_fullmap) cameraEffect ["internal", "BACK"];
	};

	// Update tag particlesources
	if (GVAR(Tags) == 1 && {!GVAR(MissileCamActive)} && {time - GVAR(lastUpdateTags) > 0.3}) then {
		GVAR(lastUpdateTags) = time;
		if (count GVAR(TogTagsParams) == 0) then {
			GVAR(TogTagsParams) = [true, GVAR(cameras) select GVAR(cameraIdx)];
		};
	};

	if (!GVAR(NoMarkersUpdates) && {!GVAR(NeedUpdateLB)} && {time > GVAR(nextmarkertime)}) then {
		_rate = (round ((count GVAR(markers)) / 99)) max 1;
		GVAR(nextmarkertime) = time + _rate;
		[GVAR(markers)] call FUNC(updatemarkers);
	};

	// Follow target with small map
	if (time >= GVAR(nextmaptime)) then {
		GVAR(nextmaptime) = time + 0.2;
		_map = _disp displayCtrl _cMap;
		if (GVAR(DroppedCamera)) then {
			// Center on dropped camera position
			ctrlMapAnimClear _map;
			_map ctrlMapAnimAdd [0.19, GVAR(MinimapZoom), [GVAR(cxpos), GVAR(cypos), 0]];
			ctrlMapAnimCommit _map;
			if (!isNull GVAR(target)) then {(vehicle GVAR(target)) setVariable [QGVAR(mapmove), false]};
		} else {
			// Center on target
			if (GVAR(minimi_follow)) then {
				_mm = (vehicle GVAR(target)) getVariable [QGVAR(mapmove), false];
				if (!_mm || {speed vehicle GVAR(target) > 0}) then {
					ctrlMapAnimClear _map;
					if (GVAR(minimi)) then {
						_map ctrlMapAnimAdd [(GVAR(nextmaptime) - time - 0.01), GVAR(MinimapZoom), getPosASL (vehicle GVAR(target))];
					} else {
						_mmpo = getPosASL (vehicle GVAR(target));
						_mmratio = getResolution select 4;
						_mmscale = (ctrlMapScale _map) * 2;
						_mmoffset = if (_mmratio > 1) then {400} else {1224};
						_mmpo set [0, (_mmpo select 0) - (_mmoffset * _mmscale)];
						_mmpo set [1, (_mmpo select 1) + (_mmoffset * _mmscale)];
						_map ctrlMapAnimAdd [(GVAR(nextmaptime) - time - 0.01), GVAR(MinimapZoom), _mmpo];
					};
					ctrlMapAnimCommit _map;
					(vehicle GVAR(target)) setVariable [QGVAR(mapmove), true]
				};
			};
		};
	};

	// Check if target changed and center main map
	if (GVAR(tgtIdx) != GVAR(lastTgt)) then {
		_map = _disp displayCtrl _cMapFull;
		ctrlMapAnimClear _map;
		GVAR(lastTgt) = GVAR(tgtIdx);
		_map ctrlMapAnimAdd [0.2, 1.0, getPosASL (GVAR(deathCam) select GVAR(lastTgt))];
		ctrlMapAnimCommit _map;
	};

	_doshowbu = false;
	if (GVAR(no_one_alive) != -1 && {!GVAR(rbuttonsvisible)}) then {
		_enddcheck = false;
		{
			if (_x != player && {_x distance player < GVAR(no_one_alive)}) exitWith {
				_enddcheck = true;
			};
		} forEach (if (isMultiplayer) then {playableUnits} else {switchableUnits});
		if (!_enddcheck) then {
			_doshowbu = true;
		};
	};
	if (!GVAR(rbuttonsvisible) && {(time >= GVAR(showbuttonattime) || {_doshowbu})}) then {
	// if (!GVAR(rbuttonsvisible)) then {
		// GVAR(RevButtons) = ["Respawn 1","Respawn 2","Respawn 3","Respawn 4"];
		if (ctrlVisible _cMapFull) then {
			ctrlShow [_cRButton1, false];
			ctrlShow [_cRButton2, false];
			ctrlShow [_cRButton3, false];
			ctrlShow [_cRButton4, false];
		};
		if ((GVAR(RevButtons) select 0) != "") then {(_disp displayCtrl _cRButton1) ctrlSetText (GVAR(RevButtons) select 0);(_disp displayCtrl _cRButton1) ctrlSetPosition [(safeZoneX + safeZoneW) - 0.25, (safeZoneY + safeZoneH) - 0.6, 0.23, 0.104575];(_disp displayCtrl _cRButton1) ctrlCommit 0};
		if ((GVAR(RevButtons) select 1) != "") then {(_disp displayCtrl _cRButton2) ctrlSetText (GVAR(RevButtons) select 1);(_disp displayCtrl _cRButton2) ctrlSetPosition [(safeZoneX + safeZoneW) - 0.25, (safeZoneY + safeZoneH) - 0.54, 0.23, 0.104575];(_disp displayCtrl _cRButton2) ctrlCommit 0};
		if ((GVAR(RevButtons) select 2) != "") then {(_disp displayCtrl _cRButton3) ctrlSetText (GVAR(RevButtons) select 2);(_disp displayCtrl _cRButton3) ctrlSetPosition [(safeZoneX + safeZoneW) - 0.25, (safeZoneY + safeZoneH) - 0.48, 0.23, 0.104575];(_disp displayCtrl _cRButton3) ctrlCommit 0};
		if ((GVAR(RevButtons) select 3) != "") then {(_disp displayCtrl _cRButton4) ctrlSetText (GVAR(RevButtons) select 3);(_disp displayCtrl _cRButton4) ctrlSetPosition [(safeZoneX + safeZoneW) - 0.25, (safeZoneY + safeZoneH) - 0.42, 0.23, 0.104575];(_disp displayCtrl _cRButton4) ctrlCommit 0};
		GVAR(rbuttonsvisible) = true;
	};

	// Get target properties
	_dir = direction vehicle GVAR(target);
	_bb = boundingBox vehicle GVAR(target);
	//GVAR(The_h) = ((_bb select 1) select 2) - ((_bb select 0) select 2); // Height
	_foo = ((_bb select 1) select 2) - ((_bb select 0) select 2); // Height
	_l = ((_bb select 1) select 1) - ((_bb select 0) select 1); // Length
	_w = ((_bb select 1) select 0) - ((_bb select 0) select 0); // Width

	_hstr = 0.15;
	GVAR(The_h) = (_foo * _hstr) + (GVAR(The_h) * (1 - _hstr));

	// Set UI texts
	_role = "";
	if (GVAR(DroppedCamera) && {isNull GVAR(the_nearest)}) then {
		// Dropped camera mode - no target
		_name = ""; _role = "";
	} else {
		_vectar = vehicle GVAR(target);
		if (_vectar != GVAR(target)) then {
			_role = switch (GVAR(target)) do {
				case (driver _vectar): {if (_vectar isKindOf "Air") then {GVAR(specstrings) select 3} else {GVAR(specstrings) select 4}};
				case (gunner _vectar): {GVAR(specstrings) select 5};
				case (commander _vectar): {GVAR(specstrings) select 6};
				default {""};
			};
		};
		_name = GVAR(target) getVariable QGVAR(namu);
	};
	if (_name != GVAR(oldnname) || {_role != GVAR(oldnrole)}) then {
		ctrlSetText [_cName, format ["%1 %2", _name, _role]];
		GVAR(oldnname) = _name; GVAR(oldnrole) = _role;
	};

	if (GVAR(cameraIdx) != GVAR(oldcamselidx)) then {
		ctrlSetText [_cCamera, format[(GVAR(specstrings) select 7), GVAR(cameraNames) select GVAR(cameraIdx)]];
		GVAR(oldcamselidx) = GVAR(cameraIdx);
	};

	_camdir = round (direction (GVAR(cameras) select GVAR(cameraIdx)));
	ctrlSetText [_cRCompass, "Dir: " + (_camdir call CBA_fnc_intToString)];
	GVAR(dirmarker) setMarkerDirLocal _camdir;
	GVAR(dirmarker) setMarkerPosLocal getPosASL (GVAR(cameras) select GVAR(cameraIdx));

	// Set name color to gray if dropped cam
	if (GVAR(DroppedCamera)) then {
		(_disp displayCtrl _cName) ctrlSetTextColor [0.6, 0.6, 0.6, 1];
		GVAR(hasdropped) = true;
	} else {
		if (GVAR(hasdropped)) then {
			(_disp displayCtrl _cName) ctrlSetTextColor [1, 1, 1, 1];
			GVAR(hasdropped) = false;
		};
	};

	// Set toggle text color for camera menu
	// only change it when it was really changed
	if (GVAR(olduseMCam) != GVAR(UseMissileCam)) then {
		if (GVAR(UseMissileCam) == 1) then {lbSetColor [_cLBCameras, GVAR(cLbMissileCam), [1, 0.5, 0, 1]]}
		else {lbSetColor [_cLBCameras, GVAR(cLbMissileCam), [1, 1, 1, 0.33]]};
		GVAR(olduseMCam) = GVAR(UseMissileCam);
	};

	if (GVAR(oldUseNVG) != GVAR(UseNVG)) then {
		if (GVAR(UseNVG) == 1) then {lbSetColor [_cLBCameras, GVAR(cLbToggleNVG), [1, 0.5, 0, 1]]}
		else {lbSetColor [_cLBCameras, GVAR(cLbToggleNVG), [1, 1, 1, 0.33]]};
		GVAR(oldUseNVG) = GVAR(UseNVG);
	};

	if (GVAR(oldTags) != GVAR(Tags)) then {
		if (GVAR(Tags) == 1) then {lbSetColor [_cLBCameras, GVAR(cLbToggleTags), [1, 0.5, 0, 1]]}
		else {lbSetColor [_cLBCameras, GVAR(cLbToggleTags), [1, 1, 1, 0.33]]};
		GVAR(oldTags) = GVAR(Tags);
	};

	if (GVAR(oldAIfilter) != GVAR(AIfilter)) then {
		if (GVAR(AIfilter) == 1) then {lbSetColor [_cLBCameras, GVAR(cLbToggleAiFilter), [1, 0.5, 0, 1]]}
		else {lbSetColor [_cLBCameras, GVAR(cLbToggleAiFilter), [1, 1, 1, 0.33]]};
		GVAR(oldAIfilter) = GVAR(AIfilter);
	};

	if (GVAR(oldDeadFilter) != GVAR(DeadFilter)) then {
		if (GVAR(DeadFilter) == 1) then {lbSetColor [_cLBCameras, GVAR(cLbToggleDeadFilter), [1, 0.5, 0, 1]]}
		else {lbSetColor [_cLBCameras, GVAR(cLbToggleDeadFilter), [1, 1, 1, 0.33]]};
		GVAR(oldDeadFilter) = GVAR(DeadFilter);
	};

	_ctrloverlay = (uiNamespace getVariable "ACE_SpectRecogOverlay") displayCtrl 1;
	GVAR(tbase) = time - GVAR(tbasestart);
	if (GVAR(DroppedCamera)) then {
		// Dropped free camera, moved with WSAD keys
		if (GVAR(cameraIdx) != 0) then {
			// User changed camera
			GVAR(DroppedCamera) = false;
		};
		
		// Adjust speed from buttons held down
		if (GVAR(CamForward)) then {
			_spd = (GVAR(sdistance) max 1) * 20;
			_spdbase = _spd * GVAR(tbase);
			GVAR(cspeedx) = GVAR(cspeedx) + (_spdbase * sin GVAR(fangle));
			GVAR(cspeedy) = GVAR(cspeedy) + (_spdbase * cos GVAR(fangle));
		};
		if (GVAR(CamBack)) then {
			_spd = (GVAR(sdistance) max 1) * 20;
			_spdbase = -_spd * GVAR(tbase);
			GVAR(cspeedx) = GVAR(cspeedx) + (_spdbase * sin GVAR(fangle));
			GVAR(cspeedy) = GVAR(cspeedy) + (_spdbase * cos GVAR(fangle));
		};
		if (GVAR(CamLeft)) then {
			_spd = (GVAR(sdistance) max 1) * 20;
			_spdbase = _spd * GVAR(tbase);
			GVAR(cspeedx) = GVAR(cspeedx) + (_spdbase * sin (GVAR(fangle) - 90));
			GVAR(cspeedy) = GVAR(cspeedy) + (_spdbase * cos (GVAR(fangle) - 90));
		};
		if (GVAR(CamRight)) then {
			_spd = (GVAR(sdistance) max 1) * 20;
			_spdbase = -_spd * GVAR(tbase);
			GVAR(cspeedx) = GVAR(cspeedx) + (_spdbase * sin (GVAR(fangle) - 90));
			GVAR(cspeedy) = GVAR(cspeedy) + (_spdbase * cos (GVAR(fangle) - 90));
		};
		// Move camera
		GVAR(cxpos) = GVAR(cxpos) + (GVAR(cspeedx) * GVAR(tbase));
		GVAR(cypos) = GVAR(cypos) + (GVAR(cspeedy) * GVAR(tbase));
		GVAR(czpos) = 0;
		GVAR(The_h) = 2; // Static camera height
		_l = 2.2;

		// Slow down
		_bstr = 5;
		_tbasebstr = (1.0 - (GVAR(tbase) * _bstr)) max 0;
		GVAR(cspeedx) = GVAR(cspeedx) * _tbasebstr;
		GVAR(cspeedy) = GVAR(cspeedy) * _tbasebstr;

		// Check for nearby targets
		if (GVAR(dropped_check)) then {
			GVAR(dummy_o) setpos[GVAR(cxpos), GVAR(cypos), 1.5];
			_objs = [GVAR(cxpos), GVAR(cypos), 1.5] nearObjects 10;
			GVAR(the_nearest) = objNull;
			_dist = 10;
			{
				{
					_d = GVAR(dummy_o) distance _x;
					if (_d < _dist && {_x in GVAR(deathCam)} && {alive _x}) then {GVAR(the_nearest) = _x; _dist = _d};
				} foreach crew _x;
			} foreach _objs;
			if (!isNull GVAR(the_nearest)) then {
				_nixx = GVAR(deathCam) find GVAR(the_nearest);
				if (_nixx != -1) then {
					GVAR(tgtIdx) = _nixx;
				};
			};
		} else {
			if (GVAR(mousecheckon)) then {
				if (GVAR(MouseButtons) select 0) then {
					_wpos = screenToWorld GVAR(MouseCoord);
					_objs = _wpos nearObjects 10;
					if (count _objs > 0) then {
						GVAR(the_nearest) = objNull;
						_dist = 10;
						{
							{
								_d = _wpos distance _x;
								if (_d < _dist && {_x in GVAR(deathCam)} && {alive _x}) then {GVAR(the_nearest) = _x; _dist = _d};
							} foreach crew _x;
						} foreach _objs;
						if (!isNull GVAR(the_nearest)) then {
							_nixx = GVAR(deathCam) find GVAR(the_nearest);
							if (_nixx != -1) then {
								GVAR(tgtIdx) = _nixx;
							};
						};
					};
				};
				if (GVAR(overlay_on)) then {
					GVAR(overlay_on) = false;
					_ctrloverlay ctrlShow false;
				};
			} else {
				_wpos = screenToWorld GVAR(MouseCoord);
				_objs = _wpos nearObjects 10;
				if (count _objs > 0) then {
					GVAR(the_nearest) = objNull;
					_dist = 10;
					{
						{
							_d = _wpos distance _x;
							if (_d < _dist && {_x in GVAR(deathCam)} && {alive _x}) then {GVAR(the_nearest) = _x; _dist = _d};
						} foreach crew _x;
					} foreach _objs;
					if (!isNull GVAR(the_nearest)) then {
						_nname = name GVAR(the_nearest);
						if (_nname != GVAR(olddropedname)) then {
							_ctrloverlay ctrlSetText _nname;
							_ctrloverlay ctrlShow true;
							GVAR(olddropedname) = _nname;
							GVAR(overlay_on) = true;
						};
						_ctrloverlay ctrlSetPosition [GVAR(MouseCoord) select 0, GVAR(MouseCoord) select 1, 0.4, 0.15];
						_ctrloverlay ctrlCommit 0;
					} else {
						if (GVAR(overlay_on)) then {
							GVAR(overlay_on) = false;
							_ctrloverlay ctrlShow false;
						};
					};
				} else {
					if (GVAR(overlay_on)) then {
						GVAR(overlay_on) = false;
						_ctrloverlay ctrlShow false;
					};
				};
			};
		};
	} else {
		if (GVAR(overlay_on)) then {
			GVAR(overlay_on) = false;
			_ctrloverlay ctrlShow false;
		};
		// Set targets for all cameras
		_vpmtw = if (!surfaceIsWater (getPosASL (vehicle GVAR(target)))) then {
			ASLToATL (visiblePositionASL (vehicle GVAR(target)))
		} else {
			visiblePosition (vehicle GVAR(target))
		};
		GVAR(cxpos) = _vpmtw select 0;
		GVAR(cypos) = _vpmtw select 1;
		GVAR(czpos) = _vpmtw select 2;
	};
	GVAR(cam_target) camSetPos [GVAR(cxpos), GVAR(cypos), GVAR(czpos) + (GVAR(The_h) * 0.7)];
	GVAR(cam_static) camSetTarget GVAR(cam_target);
	_gjp = [GVAR(cxpos), GVAR(cypos), GVAR(czpos) + (GVAR(The_h) * 0.8)];
	GVAR(cam_free) camSetTarget _gjp;
	GVAR(cam_flyby) camSetTarget GVAR(cam_target);
	GVAR(cam_topdown) camSetTarget _gjp;
	{_x camSetFov GVAR(szoom)} foreach GVAR(cameras);

	// Static camera, follows unit from behind
	_lsdist = -(_l * GVAR(sdistance));
	GVAR(cam_static) camSetRelPos [sin _dir * _lsdist, cos _dir * _lsdist, 0.6 * abs GVAR(sdistance)];

	// Free camera, user rotates camera around target
	_lsdist = _l * (0.3 max GVAR(sdistance));
	_d = -_lsdist;
	_z = sin GVAR(fangleY) * _lsdist;
	_co = cos GVAR(fangleY);
	GVAR(cam_free) camSetRelPos [(sin GVAR(fangle) * _d) * _co, (cos GVAR(fangle) * _d) * _co, _z];
	GVAR(cam_free) camCommit GVAR(tbase);

	// Flyby camera, no user control except zoom
	if (GVAR(target) distance GVAR(cam_flyby) > (GVAR(flybydst) * 1.1)) then {
		GVAR(flybydst) = 20 + (speed vehicle GVAR(target));
		GVAR(cam_flyby) camSetRelPos [sin _dir * GVAR(flybydst), cos _dir * GVAR(flybydst), 1 + ((random GVAR(The_h)) * 1.5)];
		GVAR(cam_flyby) camCommit 0;
		GVAR(cam_target) camCommit 0;
	};

	// Top-down camera
	GVAR(cam_topdown) camSetRelPos [0.0, -0.01, 2 + ((0 max GVAR(sdistance)) * 15)];
	GVAR(cam_topdown) camCommit 0;

	// Commit static and flyby cameras
	// 0 = Jump immediately to distant target
	_comSpeed = if ((vehicle GVAR(target)) distance GVAR(cam_static) > 650) then {0} else {(1.0 - ((speed vehicle GVAR(target)) / 70)) max 0.0};
	GVAR(cam_static) camCommit _comSpeed / 2;
	GVAR(cam_target) camCommit _comSpeed / 3;
	GVAR(cam_flyby) camCommit _comSpeed;
	GVAR(tbasestart) = time;
	// a little helper if you might want to exit spectating during a mission again
	// just set ace_sys_spectator_exit_spectator = true and spectating will exit safely
	if (!isNil QGVAR(exit_spectator)) then {GVAR(exit_the_frame) = true};
	if (!isNil "ace_sys_wounds_enabled" && {!isNil "ace_wounds_prevtime"} && {!alive player}) then {
		if (isMultiplayer) then {
			// only bird and none
			_respawn = getText(missionConfigFile >> "respawn");
			_noresp = false;
			if (_respawn == "") then {
				_respawn = getNumber(missionConfigFile >> "respawn");
				if (_respawn in [0, 1]) then {_noresp = true};
			} else {
				if ((toUpper _respawn) in ["NONE", "BIRD"]) then {_noresp = true};
			};
			if (_noresp) then {
				ace_wounds_prevtime = nil;
			};
		};
		GVAR(exit_spectator) = true;GVAR(exit_the_frame) = true;
	};
	TRACE_1("FUNC(MainLoop) ended","");
};

[] spawn COMPILE_FILE(specta_init);
