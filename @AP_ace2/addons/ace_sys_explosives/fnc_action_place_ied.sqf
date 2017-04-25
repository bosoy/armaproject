/* ace_sys_explosives | IED | (c) 2008, 2009, 2010, 2011 by rocko */
#include "script_component.hpp"

if ({["BAF_ied_v1","BAF_ied_v2","BAF_ied_v3","BAF_ied_v4","PMC_ied_v1","PMC_ied_v2","PMC_ied_v3","PMC_ied_v4"]  find _x != - 1} count (magazines player) > 0) then {
	if ("BAF_ied_v1" in magazines player) exitWith { player removeMagazine "BAF_ied_v1"; };
	if ("BAF_ied_v2" in magazines player) exitWith { player removeMagazine "BAF_ied_v2"; };
	if ("BAF_ied_v3" in magazines player) exitWith { player removeMagazine "BAF_ied_v3"; };
	if ("BAF_ied_v4" in magazines player) exitWith { player removeMagazine "BAF_ied_v4"; };
	if ("PMC_ied_v1" in magazines player) exitWith { player removeMagazine "PMC_ied_v1"; };
	if ("PMC_ied_v2" in magazines player) exitWith { player removeMagazine "PMC_ied_v2"; };
	if ("PMC_ied_v3" in magazines player) exitWith { player removeMagazine "PMC_ied_v3"; };
	if ("PMC_ied_v4" in magazines player) exitWith { player removeMagazine "PMC_ied_v4"; };
};

call FUNC(anim);

_minetype = if (isOnRoad player) then { ["ACE_Land_IED_v3_PMC", "ACE_Land_IED_v4_PMC"] select (abs random 1) } else { ["ACE_Land_IED_v1_PMC", "ACE_Land_IED_v2_PMC"] select (abs random 1) };

_pos = player modelToWorld [0,0,0];
_pos set [0, (_pos select 0) + (sin (direction player) * 0.5)];
_pos set [1, (_pos select 1) + (cos (direction player) * 0.5)];
_z = [player] call CBA_fnc_realHeight;
_p set [2,_z];

_mine = _minetype createVehicle _pos;
player reveal _mine;
_mine setDir (direction player);
_mine setPos _pos;

_mine call FUNC(set_id);
[_mine,true] call FUNC(set_ready);
