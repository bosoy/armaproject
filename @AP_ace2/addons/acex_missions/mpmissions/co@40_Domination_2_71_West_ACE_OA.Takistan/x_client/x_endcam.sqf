// by Xeno
#define THIS_FILE "x_endcam.sqf"
#include "x_setup.sqf"
private ["_line", "_camera", "_posp", "_str", "_str2"];

GVAR(end_cam_running) = true;

showCinemaBorder false;
disableSerialization;
createDialog "X_RscAnimatedLetters";
(__uiGetVar(X_ANIM_LETTERS) displayCtrl 66666) ctrlShow false;

_line = 0;
i = 0;
#ifdef __CO__
playMusic "Track19_Debriefing";
#endif
#ifdef __OA__
playMusic "EP1_Track03D";
#endif

_camera = "camera" camCreate position player;
_camera cameraEffect ["External","back"];

_camera camSetTarget position player;
_camera camSetRelPos [2.71,19.55,3.94];
_camera camSetFOV 1;
_camera camCommit 0.0;
waitUntil {camCommitted _camera};
0 spawn {
	if (vehicle player != player) then {
		_vec = vehicle player;
		if (_vec isKindOf "Air") then {
			_posp = position player;
			_is_driver = (driver _vec == player);
			player action ["EJECT", _vec];
			waitUntil {vehicle player == player};
			player setPos [_posp select 0, _posp select 1, 0];
			player setVelocity [0,0,0];
			if (_is_driver) then {
				_vec spawn {
					private "_vec";
					_vec = _this;
					waitUntil {count crew _vec == 0};
					deleteVehicle _vec;
				};
			};
		};
	};
};

_camera camSetRelPos [80.80,120.29,633.07];
_camera camCommit 20;
GVAR(intro_color) = [0,0,0,1];
#ifndef __TT__
[5, (localize "STR_DOM_MISSIONSTRING_231"), 2] execVM "IntroAnim\animateLettersX.sqf";__INC(_line); waitUntil {i == _line};
sleep 5;
if (GVAR(MissionType) != 2) then {
	[0, (localize "STR_DOM_MISSIONSTRING_232"), 4] execVM "IntroAnim\animateLettersX.sqf";__INC(_line); waitUntil {i == _line};
} else {
	[0, (localize "STR_DOM_MISSIONSTRING_233"), 4] execVM "IntroAnim\animateLettersX.sqf";__INC(_line); waitUntil {i == _line};
};
#else
_str = "";
_str2 = "";
_points_array = __XJIPGetVar(points_array);
_points_west = _points_array select 0;
_points_east = _points_array select 1;
if (_points_west > _points_east) then {
	_str = (localize "STR_DOM_MISSIONSTRING_234");
	_str2 = format [(localize "STR_DOM_MISSIONSTRING_235"), _points_west, _points_east];
} else {
	if (_points_east > _points_west) then {
		_str = (localize "STR_DOM_MISSIONSTRING_236");
		_str2 = format [(localize "STR_DOM_MISSIONSTRING_237"), _points_east, _points_west];
	} else {
		if (_points_east == _points_west) then {
			_str = (localize "STR_DOM_MISSIONSTRING_238");
			_str2 = format [(localize "STR_DOM_MISSIONSTRING_239"), _points_west, _points_east];
		};
	};
};
[4, _str, 2] execVM "IntroAnim\animateLettersX.sqf";__INC(_line); waitUntil {i == _line};
sleep 5;
[6, _str2, 4] execVM "IntroAnim\animateLettersX.sqf";__INC(_line); waitUntil {i == _line};
#endif
waitUntil {camCommitted _camera};

_camera camSetFOV 2;

_camera camCommit 20;
[2, (localize "STR_DOM_MISSIONSTRING_240"), 6] execVM "IntroAnim\animateLettersX.sqf";__INC(_line); waitUntil {i == _line};
waitUntil {camCommitted _camera};

_camera cameraEffect ["terminate","front"];
camDestroy _camera;

3 FADEMUSIC 0;
