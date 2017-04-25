#define ACE_TEXT_SILVER(Text) ("<t color='#C0C0C0'>" + ##Text + "</t>")

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

_wirecoil = _this;
detach _wirecoil;
_wire_nogeo = "ACE_ConcertinaWireNoGeo" createvehicle [0,0,0]; W = _wire_nogeo;

_wireFast = ["wire_2","wire_3","wire_4","wire_5","wire_6","wire_7","wire_8","wire_9","wire_10","wire_11","wire_12","wire_13","wire_14","wire_15","wire_16","wire_17","wire_18"]; // fast
_wireSlow = ["wire_2_1","wire_3_1","wire_4_1","wire_5_1","wire_6_1","wire_7_1","wire_8_1","wire_9_1","wire_10_1","wire_11_1","wire_12_1","wire_13_1","wire_14_1","wire_15_1","wire_16_1","wire_17_1","wire_18_1"]; // slow

{
	_wire_nogeo animate [_x,1];
} foreach _wireFast;

sleep 0.1;
_dir_p = getDir player;
_pos_p = getPos player;
_wire_nogeo setdir _dir_p;
_wire_nogeo_pos = [(_pos_p select 0) + (1.1* sin _dir_p),(_pos_p select 1) + (1.1 * cos _dir_p),0];
_wire_nogeo setpos _wire_nogeo_pos;

deletevehicle _wirecoil;

_action = player addAction [ACE_TEXT_SILVER(localize "STR_ACE_ROLLWIRE"),"\x\ace\addons\sys_sandbag\confirmCWdeploy.sqf",_wire_nogeo];
player setVariable [QGVAR(wireDeployed),false];

private ["_dir_w","_range","_anim"];
_range = 0;
while { alive player && {_range < 12} && {!(player getVariable [QGVAR(wireDeployed),false])} } do {
	_dir_w = ([getpos player, (_wire_nogeo modelToWorld (_wire_nogeo selectionPosition "start"))] call BIS_fnc_dirTo);
	_range = ((_wire_nogeo modelToWorld (_wire_nogeo selectionPosition "start")) distance player) min 12;
	_wire_nogeo setDir _dir_w;
	_anim = (1 - ((1/12)*_range));
	{ _wire_nogeo animate [_x,_anim] } foreach _wireFast;
	sleep 0.05;
};

player removeAction _action;

_wire = "ACE_ConcertinaWire" createvehicle [0,0,0];

{
	_wire animate [_x,_anim];
} foreach _wireFast;

waituntil { _wire animationPhase "wire_2" == _anim };

_wire setdir _dir_w;
deletevehicle _wire_nogeo;
_wire setpos _wire_nogeo_pos;
