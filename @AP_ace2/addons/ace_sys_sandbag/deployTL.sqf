//#define DEBUG_MODE_FULL
#include "script_component.hpp"

player removeWeapon "ACE_TacticalLadder_Pack";

_pos = player modelToWorld [0,0,0];
_offset = if ((player call CBA_fnc_getUnitAnim select 0) == "prone") then { 1 } else {0.8};
_pos set [0, (_pos select 0) + (sin (direction player) * _offset)];
_pos set [1, (_pos select 1) + (cos (direction player) * _offset)];
_z = [player] call CBA_fnc_realHeight;
_pos set [2,_z];

_ladder = "ACE_Tactical_Ladder" createVehicle _pos;
_ladder setPos _pos;
_ladder setDir (direction player);
player reveal _ladder;
