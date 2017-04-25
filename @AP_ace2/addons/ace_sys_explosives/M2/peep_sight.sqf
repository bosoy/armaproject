#include "\x\ace\addons\sys_explosives\script_component.hpp"

disableSerialization;

if ((player call CBA_fnc_getUnitAnim) select 0 == "stand") then {
	player playMove "AmovPercMstpSrasWrflDnon_diary";
};

_mine = _this;
_pos = getposATL _mine;
_z = [_mine] call CBA_fnc_realHeight;
_pos set [2,_z];

_camera = "camera" camCreate _pos;
_camera cameraEffect ["internal", "back"];
cutrsc ["ACE_SLAM_Sight", "PLAIN DOWN"];

GVAR(sight_right) = false;
GVAR(sight_left) = false;
GVAR(sight_up) = false;
GVAR(sight_dn) = false;

call FUNC(sight_addkey);

GVAR(peep_sight) = true;
GVAR(presstime) = 0;

while { GVAR(peep_sight) } do {
	if (GVAR(sight_right)) then { [_mine, "R",_pos] call FUNC(sight_rotate); };
	if (GVAR(sight_left)) then { [_mine, "L",_pos] call FUNC(sight_rotate); };
	if (GVAR(sight_up)) then { [_mine, "UP",_pos] call FUNC(sight_rotate); };
	if (GVAR(sight_dn)) then { [_mine, "DN",_pos] call FUNC(sight_rotate); };

	_dir = getdir _mine;
	_pitch = _mine getVariable ["pitch",0];
	_camera setDir _dir;
	_camera setPos getPos _mine;
	_camera setVectorUp [((sin _dir)*(sin _pitch)),((cos _dir)*(sin _pitch)),(cos _pitch)];

	camUseNVG ace_sys_nvg_on;
	_camera camCommit 0.1;
	sleep 0.05;
};

_mine call FUNC(sight_add_pitch);

call FUNC(sight_remkey);

_camera cameraEffect ["terminate", "back"];
cutrsc ["default", "PLAIN DOWN"];
camDestroy _camera;
