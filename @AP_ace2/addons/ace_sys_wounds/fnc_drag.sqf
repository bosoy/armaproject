/* ace_sys_wounds(.pbo)  */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define ACE_TEXT_RED(Text) ("<t color='#FF0000'>" + ##Text + "</t>")
#define ACE_TEXT_BLUE(Text) ("<t color='#0000FF'>" + ##Text + "</t>")

#define __LOAD 	ACE_TEXT_BLUE(localize "STR_ACE_UA_LOAD")
#define __CARRY ACE_TEXT_BLUE(localize "STR_ACE_UA_CARRYWOUNDED")
#define __DROP 	ACE_TEXT_RED(localize "STR_ACE_UA_DROP")

#define __MASS 80

// _this (c) by Xeno

closeDialog 0;

private ["_unit", "_found_anim"];
PARAMS_1(_dragee);

// Check before if player is already dragging/carrying someone
if (player getVariable [QGVAR(is_dragging), false]) exitWith { TRACE_1("Already dragging, if not -> ERROR",""); };
if (player getVariable [QGVAR(change_drag_to_carry), false]) then {
	player setVariable [QGVAR(change_drag_to_carry),false];
	player setVariable [QGVAR(is_carrying),true];
	TRACE_1("Reset change variable","");
};

if (isNull _dragee) exitWith { TRACE_1("Dragee isnull",""); };
if (!alive player) exitWith { TRACE_1("Dragger is dead",""); };

player setVariable [QGVAR(is_dragging), true]; // TODO: Should be simpliefied, to one VAR name that is easier to check through different components

_resetCarryAction = {
	if (GVAR(carryAction) != -3333) then {
		TRACE_1("Actions removed","");
		player removeAction GVAR(carryAction);
		GVAR(carryAction) = -3333;
	};
};

_resetLoadAction = {
	if (GVAR(loadAction) != -3333) then {
		TRACE_1("Actions removed","");
		player removeAction GVAR(loadAction);
		GVAR(loadAction) = -3333;
	};
};

_crouch = true;
_prone = (((player call CBA_fnc_getUnitAnim) select 0) == "prone");
_carrying = player getVariable [QGVAR(is_carrying),false];
if (_carrying) then { _prone = false };


TRACE_2("Dragging style",_prone,_carrying);
_unit = player;

private "_name_dragee";
_name_dragee = localize "STR_ACE_NO_UNIT";
if (alive _dragee) then {if (name _dragee != "Error: No unit") then {_name_dragee = name _dragee}};

GVAR(drag_keyDownEHId) = (findDisplay 46) displayAddEventHandler ["KeyDown", "_this call ace_sys_wounds_fnc_dragkeydown"]; // Add "C" key down eventhandler

detach _dragee;

if (!_prone) then { 											// Normal drag
	if (!_carrying) then {
		//player assumes dragging posture
		_unit playMove "acinpknlmstpsraswrfldnon";
		sleep 2;
		//unconscious unit assumes dragging posture
		[QGVAR(a3), _dragee] call CBA_fnc_globalEvent;
		
		// Add Weight for Carrying
		_gearweight = [_dragee] call ACE_SYS_RUCK_FNC_GEARWEIGHT;
		_mass = (__MASS + _gearweight) * sin 45;
		[player, _mass] call ace_sys_stamina_fnc_inc_mass; // Stamina Boost while carrying wounded 
	} else { // Carrying
		call _resetCarryAction;
		[QGVAR(a1), _dragee] call CBA_fnc_globalEvent;
		if (primaryWeapon _unit == "") then {
			[QGVAR(a21), _unit] call CBA_fnc_globalEvent;
		} else {
			[QGVAR(a2), _unit] call CBA_fnc_globalEvent;
		};
		sleep 10;
		// Add Weight for Carrying
		_gearweight = [_dragee] call ACE_SYS_RUCK_FNC_GEARWEIGHT;
		_mass = (__MASS + _gearweight);
		[player, _mass] call ace_sys_stamina_fnc_inc_mass; // Stamina Boost while carrying wounded 
	};
} else { 														// Prone drag
	//player no dragging posture needed // TODO: Find a animation for prone dragging (weapon on back etc)
	sleep 0.5;
	//no dragging posture needed
	[QGVAR(a4), _dragee] call CBA_fnc_globalEvent;
};

_dragee setVariable ["ace_w_carry", _unit, true];

//attach unconscious unit
_attach_pos = if (!_prone) then {
	if (!_carrying) then {
		[0.1, 1.01, 0]
	} else {
		[-0,-0.1,-1.2]
	};
} else {
	[0, 2, 0] 
};
_selection = if (!_prone) then {
	if (!_carrying) then {
		""
	} else {
		"RightShoulder"
	};
} else {
	""
};

_dragee attachto [_unit,_attach_pos,_selection];
sleep 0.02;
[QGVAR(dir), _dragee] call CBA_fnc_globalEvent;
GVAR(drag) = true;

[QGVAR(checkdrag), [_dragee, _unit]] call ACE_fnc_receiverOnlyEvent;


// drop body added
if (GVAR(dropAction) != -3333) then { player removeAction GVAR(dropAction); GVAR(dropAction) = -3333 };
if (!_prone) then {
	GVAR(dropAction) = player addAction [format[__DROP,(_name_dragee)], QPATHTO_C(drop_body.sqf), [_dragee, 0], 999, false, true];
	if (!_carrying) then { GVAR(carryAction) = player addAction [format[__CARRY,(_name_dragee)], QPATHTO_C(carry.sqf), _dragee, 900, false, true]; };
} else {
	GVAR(dropAction) = player addAction [format[__DROP,(_name_dragee)], QPATHTO_C(drop_body.sqf), [_dragee, 1], 900, false, true];
};
GVAR(loadAction) = -3333;
sleep 1;

_found_anim = false;
_draganims = if (!_prone) then {
	if (!_carrying) then {
		[
			"acinpknlmstpsraswrfldnon",
			"acinpknlmwlksraswrfldb"
		];
	} else {
		[
			"acinpercmstpsraswrfldnon",
			"acinpercmrunsraswrfldf"
		];
	};
} else {
	[
		"amovppnemstpsraswrfldnon",
		"amovppnemrunslowwrfldf",
		"amovppnemsprslowwrfldfl",
		"amovppnemsprslowwrfldfr",
		"amovppnemrunslowwrfldb",
		"amovppnemsprslowwrfldbl",
		"amovppnemsprslowwrfldr",
		"amovppnemstpsraswrfldnon_turnl",
		"amovppnemstpsraswrfldnon_turnr",
		"amovppnemrunslowwrfldl",
		"amovppnemrunslowwrfldr",
		"amovppnemsprslowwrfldb",
		"amovppnemrunslowwrfldbl",
		"amovppnemsprslowwrfldl",
		"amovppnemsprslowwrfldbr"
	];
};

while {GVAR(drag)} do {
	if (!_found_anim) then {
		if (animationState player in _draganims) then {
			_found_anim = true;
			TRACE_1("Found anim","");
		};
	};
	
	_pisuncon = _unit call FUNC(isUncon); 	// check if dragger is uncon
	_disuncon = _dragee call FUNC(isUncon); // check if dragee is uncon
	
	if (!alive _dragee || {(alive _dragee && !_disuncon)}) exitWith {
		TRACE_1("Dragee dead or NOT unconscious","");
		player removeAction GVAR(dropAction);
		GVAR(dropAction) = -3333;

		call _resetCarryAction;
		
		detach _dragee;
		TRACE_1("Dragee detached","");
		sleep 0.5;
		if ((alive _dragee && {_disuncon}) || {!alive _dragee}) then {
			[_dragee, 101] call FUNC(animator);
			TRACE_1("101 ANIMATOR","");
		} else {
			[_dragee, 102] call FUNC(animator);
			TRACE_1("102 ANIMATOR","");
		};
		if (!_pisuncon) then {
			[QGVAR(aswmnon), _unit] call CBA_fnc_globalEvent;
		};
		_dragee setVariable ["ace_w_carry", objNull, true];
		sleep 1;
		GVAR(drag) = false;
	};

	if (_found_anim && {!((animationState _unit) in _draganims)}) exitWith { // TODO: Would be nice if dragging would dynamically change between prone and crouch until dropped
		// ERROR: In SP/Editor, when player is set unconscious while dragging someone, he magically floats away from the former dragged unit... ??? (with latest beta)
		TRACE_1("Some animations???","");
		player removeAction GVAR(dropAction);
		GVAR(dropAction) = -3333;
		
		call _resetCarryAction;
		
		detach _dragee;
		sleep 0.5;
		if ((alive _dragee && {_disuncon}) || {!alive _dragee}) then {
			[_dragee, 101] call FUNC(animator);
		} else {
			[_dragee, 102] call FUNC(animator);
		};
		if (!_pisuncon) then {
			[QGVAR(aswmnon), _unit] call CBA_fnc_globalEvent;
		};
		_dragee setVariable ["ace_w_carry", objNull, true];
		sleep 1;
		GVAR(drag) = false;
	};

	// Check that dragged unit still exists
	if (_pisuncon || {!alive _unit}) exitWith {
		TRACE_1("Dragger dead or unconscious","");
		player removeAction GVAR(dropAction);
		GVAR(dropAction) = -3333;

		call _resetCarryAction;
		
		detach _dragee;
		if ((alive _dragee && {_disuncon}) || {!alive _dragee}) then {
			[_dragee, 101] call FUNC(animator);
		} else {
			[_dragee, 102] call FUNC(animator);
		};
		if (!_pisuncon) then {
			[QGVAR(aswmnon), _unit] call CBA_fnc_globalEvent;
		};
		_dragee setVariable ["ace_w_carry", objNull, true];
		sleep 1;
		GVAR(drag) = false;
	};

	if (isNull _dragee) then {
		TRACE_1("Draggee isnull","");
		player removeAction GVAR(dropAction);
		GVAR(dropAction) = -3333;
		
		call _resetCarryAction;
		
		detach _dragee;
		if (!_pisuncon) then {
			[QGVAR(aswmnon), _unit] call CBA_fnc_globalEvent;
		};
		sleep 1;
		GVAR(drag) = false;
	};

	if (!_prone) then {
		_nos = (position player) nearEntities [["Car","Tank","Helicopter","Plane","ACE_Stretcher"], 5];
		if (count _nos > 0) then {
			_vec = _nos select 0;
			if (!(_vec isKindOf "ParachuteBase") && {!(_vec isKindOf "BIS_Steerable_Parachute")} && {!(_vec isKindOf "UAV")}) then {
				// check for free cargo slots
				_cargocrew = 0;
				{
					_vecrole = assignedVehicleRole _x;
					if (count _vecrole > 0 && {(_vecrole select 0) == "Cargo"}) then {
						INC(_cargocrew);
					};
				} forEach (crew _vec);
				_tps = getNumber(configFile >> "CfgVehicles" >> typeOf _vec >> "transportSoldier");
				if (_cargocrew < _tps) then {
					if (GVAR(loadAction) == -3333) then {
						GVAR(loadAction) = player addAction [format[__LOAD,(_name_dragee),getText(configFile>>"CFGVEHICLES">>typeOf _vec>>"displayNameShort")], QPATHTO_C(load.sqf), [_dragee, _vec], 0, false, true];
					};
				} else {
					call _resetLoadAction;
				};
			};
		} else {
			call _resetLoadAction;
		};
	};
	sleep 0.1;
	if (_unit getVariable [QGVAR(change_drag_to_carry),false]) exitWith {
		[_dragee] spawn FUNC(drag);
	};
};

player setVariable [QGVAR(is_carrying),false];
player setVariable [QGVAR(is_dragging), false];

// Remove "C" key down eventhandler
(findDisplay 46) displayRemoveEventHandler ["KeyDown", GVAR(drag_keyDownEHId)];

call _resetCarryAction;

call _resetLoadAction;

[player, 0] call ace_sys_stamina_fnc_inc_mass; // Reset Stamina Boost while carrying wounded

false