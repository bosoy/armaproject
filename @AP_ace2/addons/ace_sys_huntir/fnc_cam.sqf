#include "script_component.hpp"

private ["_object", "_pos", "_destroy", "_logic", "_height", "_cam_dir", "_cam_no", "_cam_time", "_cam_times"];
13521 cutText["","PLAIN"];
PARAMS_1(_object);
_pos = getPosATL _object;
_destroy = false;
_cam_time_remain = time + 420;

GVAR(ZOOM) = 0;
GVAR(NV) = 0;
GVAR(TI) = 0;
GVAR(SELECT) = 0;
GVAR(ROTATE) = 0;
GVAR(ELEVAT) = 0.01;

closedialog 0;
createDialog "ace_huntir_cam_dialog";
uiNameSpace setVariable ["ace_huntir_monitor", findDisplay 18880];
(uiNameSpace getVariable "ace_huntir_monitor") displaySetEventHandler ["Keydown", "_this call ace_sys_huntir_fnc_keypressed"];

ctrlSetText [4, "0X"];

GVAR(cam) = "camera" CamCreate _pos;
_logic = "ACE_LogicDummy" createVehicleLocal [_pos select 0,_pos select 1,(_pos select 2) - 5];
_logic setVectorUp [0.001, 0.001, 1];
GVAR(cam) CamSetTarget _logic;
GVAR(cam) CameraEffect ["internal", "BACK"];
GVAR(cam) camsetrelpos [0, 0, 2];
GVAR(cam) camCommit 0;
showCinemaBorder false;
camUseNVG false;

_pphandle = ppEffectCreate ["colorCorrections", 135522];
_pphandle ppEffectAdjust [1, 1, 0, [0.01, 0.02, 0.04, 0.01], [0.87, 1.08, 1.196, 0.3], [0.399, 0.287, 0.014, 0.0]];
_pphandle ppEffectCommit 0;
_pphandle ppEffectEnable true;

GVAR(stop) = false;
[] spawn COMPILE_FILE(ace_sys_huntir_compass);

while { dialog && {(_pos select 2 > 20)}} do  {
	GVAR(no_cams) = (position player) nearEntities ["ACE_HuntIR", 2000];
	while { GVAR(SELECT) >= (count GVAR(no_cams))}do {
		GVAR(SELECT) = GVAR(SELECT) - 1;
	};
	_object = GVAR(no_cams) select GVAR(SELECT);
	_pos = if (!surfaceIsWater (getPosASL _object)) then {
		ASLToATL (visiblePositionASL _object)
	} else {
		visiblePosition _object
	};

	switch (GVAR(ZOOM)) do {
		case 0: {
			GVAR(cam) camsetFOV 0.7;
			GVAR(cam) camSetFocus [_pos select 2, 1];
		};
		case 1: {
			GVAR(cam) camsetFOV 0.35;
			GVAR(cam) camSetFocus [(_pos select 2)/2, 1];
		};
		case 2: {
			GVAR(cam) camsetFOV 0.17;
			GVAR(cam) camSetFocus [(_pos select 2)/4, 1];
		};
		case 3: {
			GVAR(cam) camsetFOV 0.1;
			GVAR(cam) camSetFocus [(_pos select 2)/8, 1];
		};
	};

	_logic setPos [_pos select 0,_pos select 1,(_pos select 2) - 5];
	_logic setDir GVAR(ROTATE);
	_logic setVectorUp [0.0001, 0.0001, 1];
	GVAR(cam) CameraEffect ["internal", "BACK"];
	_cam_coord_y = (GVAR(ELEVAT) * cos (GVAR(ROTATE)));
	_cam_coord_x = (GVAR(ELEVAT) * sin (GVAR(ROTATE)));
	GVAR(cam) camsetrelpos [_cam_coord_x, _cam_coord_y, 2];
	GVAR(cam) camCommit 0;

	_height = format ["%1 m", round (_pos select 2)];
	ctrlSetText [1, _height];
	_cam_no = (GVAR(SELECT) + 1) call CBA_fnc_intToString;
	ctrlSetText [2, _cam_no];
	_speed = 15; //abs(speed _object);
	_cam_time = round (round (_pos select 2) / _speed);
	_cam_times = (_cam_time call CBA_fnc_intToString) + " s";
	ctrlSetText [3, _cam_times];
	_cam_pos = getPosATL _object;
	_cam_pos = format ["X = %1, Y = %2", round (_cam_pos select 0), round (_cam_pos select 1)];
	ctrlSetText [5, _cam_pos];
	//_cam_dir = getDir GVAR(cam);
	//_cam_dir_index = (round(_cam_dir * 8 / 360) * (32 / 8)) mod 32;
	//_cam_dir_name =[ "N", "NbE", "NNE", "NEbN", "NE", "NEbE", "ENE", "EbN", "E", "EbS", "ESE", "SEbE", "SE", "SEbS", "SSE", "SbE", "S", "SbW", "SSW", "SWbS", "SW", "SWbW", "WSW", "WbS", "W", "WbN", "WNW", "NWbW", "NW", "NWbN", "NNW", "NbW"];
	//_cam_dir = format ["%1", (_cam_dir_name select _cam_dir_index)];
	ctrlSetText [6, ""];
	sleep 0.01;
};

GVAR(stop) = true;

_pphandle ppEffectEnable true;
ppEffectDestroy _pphandle;

GVAR(NV) = 0;
setAperture -1;
closedialog 0;
titletext [" ", "BLACK IN", 4];
player switchCamera "INTERNAL";
GVAR(cam) CameraEffect ["Terminate", "Back"];
CamDestroy GVAR(cam);
deleteVehicle _logic;
