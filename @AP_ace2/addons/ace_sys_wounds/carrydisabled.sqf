// #define DEBUG_MODE_FULL
#include "script_component.hpp"

#define ACE_TEXT_RED(Text) ("<t color='#FF0000'>" + ##Text + "</t>")
#define __DROP 	ACE_TEXT_RED(localize "STR_ACE_UA_DROP")
#define __MASS 80


private ["_dragee", "_unit", "_nos", "_vec", "_cargocrew", "_vecrole", "_tps","_gearweight","_mass"];
_dragee	= _this select 3;
private ["_name_dragee"];
_name_dragee = localize "STR_ACE_NO_UNIT";
if (alive _dragee) then {if (name _dragee != "Error: No unit") then {_name_dragee = name _dragee}};
_unit = player;

// Check lifestate
if (!alive _dragee) exitWith {};

// Check before if player is already dragging/carrying someone
if (player getVariable [QGVAR(is_dragging), false]) exitWith { TRACE_1("Already dragging, if not -> ERROR",""); };

// Send request, if _dragee is a player
_action = "carry";
ace_sys_interaction_confirmed = nil;
if (ace_sys_interaction_inProgress) exitWith {};
ace_sys_interaction_inProgress = true;
private "_endtime";
if (isPlayer _dragee) then {
	TRACE_1("Reqesting Carry action","");
	[QUOTE(ace_sys_interaction_confirmation), [_dragee, player, -1, _action]] call ACE_fnc_receiverOnlyEvent;
	_endtime = time + 20;
} else {
	TRACE_1("Requesting Carry action from AI","");
	ace_sys_interaction_confirmed = true;
	_endtime = time + MAX_UNC_TIME;
};
sleep 0.5;
waitUntil { !isNil QUOTE(ace_sys_interaction_confirmed) || {time > _endtime} };
sleep 0.5;

if (!isNil QUOTE(ace_sys_interaction_confirmed)) then {
	switch (ace_sys_interaction_confirmed) do {
		case true: {
			GVAR(carrydisabled) = true;
		};
		case false: {
			GVAR(carrydisabled) = false;
		};
	};
};

ace_sys_interaction_inProgress = false;

if !(GVAR(carrydisabled)) exitWith {};

// Prevent player dragging a second player/AI via Interaction menu
GVAR(carry) = true;
GVAR(drag) = true;

// Requesting done. Carry the disabled player / AI
if (isNull _dragee) exitWith {};
detach _dragee;
[QGVAR(a1), _dragee] call CBA_fnc_globalEvent;

if (primaryWeapon _unit == "") then {
	[QGVAR(a21), _unit] call CBA_fnc_globalEvent;
} else {
	[QGVAR(a2), _unit] call CBA_fnc_globalEvent;
};
sleep 10;
_dragee attachTo [_unit,  [-0,-0.1,-1.2], "RightShoulder"];
[QGVAR(dir), _dragee] call CBA_fnc_globalEvent;

_found_anim = false;
_draganims = ["acinpercmstpsraswrfldnon","acinpercmrunsraswrfldf"];

_gearweight = [_dragee] call ACE_SYS_RUCK_FNC_GEARWEIGHT;
_mass = (__MASS + _gearweight) * sin 45;
[_unit, _mass] call ace_sys_stamina_fnc_inc_mass; // Stamina Boost while carrying wounded 

// Add "C" key down eventhandler
GVAR(drag_keyDownEHId) = (findDisplay 46) displayAddEventHandler ["KeyDown", "_this call ace_sys_wounds_fnc_dragkeydown"];

if (GVAR(dropAction) != -3333) then {
	player removeAction GVAR(dropAction);
	GVAR(dropAction) = -3333;
};
GVAR(dropAction) = player addAction [format[__DROP, _name_dragee], QPATHTO_C(drop_body.sqf), [_dragee, 0, true], 0, false, true];

while {GVAR(carrydisabled)} do {
	if (!_found_anim) then {
		if (animationState player in _draganims) then {
			_found_anim = true;
		};
	};

	_pisuncon = _unit call FUNC(isUncon); 	// check if dragger is uncon
	_disuncon = _dragee call FUNC(isUncon); // check if dragee is uncon
	
	// Check that dragged unit still exists
	// Not sure what happens if wounded player falls uncon while carrying
	// Assuming he does not know what happens with the guy on his back, only check if unit suddenly dies
	if (isNull _dragee || {!alive _unit} || {_pisuncon} || {_found_anim && {!((animationState _unit) in _draganims)}}) exitWith {
		player removeAction GVAR(dropAction);
		GVAR(dropAction) = -3333;
		if (!isNull _dragee) then {
			detach _dragee;
			sleep 0.5;
			if ((alive _dragee && {_disuncon}) || {!alive _dragee}) then {
				[_dragee, 101] call FUNC(animator);
			} else {
				[_dragee, 105] call FUNC(animator);
			};
		};
		if (!_pisuncon) then {
			[QGVAR(aswmnon), _unit] call CBA_fnc_globalEvent;
		};
		GVAR(carrydisabled) = false;
	};
	sleep 0.1;
};

// Reset
GVAR(carry) = false;
GVAR(drag) = false;

// Remove "C" key down eventhandler
(findDisplay 46) displayRemoveEventHandler ["KeyDown", GVAR(drag_keyDownEHId)];

// Reset Stamina Boost while carrying wounded
[player, 0] call ace_sys_stamina_fnc_inc_mass;
