/* ACE_Stretcher | (c) 2010 by rocko */

// Stretcher handling
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private "_stretcher_monitoring";

PARAMS_4(_stretcher,_caller,_id,_ar);
// TODO: Taking a knee, requires to stand up again, by script, or looks ugly
//if (((_caller call CBA_fnc_getUnitAnim) select 0) == "stand") then { _caller playMove "AmovPercMstpSrasWrflDnon_diary"; };

_position = _ar select 0;
_action = _ar select 1;
_var = _ar select 2;
_animation_code = _ar select 3;
_stretcher_object = _ar select 4;
if (isNil "_stretcher_object") then { _stretcher_object = _stretcher; };

if (isNil QUOTE(FUNC(sdrop))) then {
	FUNC(sdrop) = {
		_carrier_front = _stretcher_object getVariable "ace_stretcher_carrier_front";
		_carrier_back = _stretcher_object getVariable "ace_stretcher_carrier_back";
		detach _carrier_back;
		detach _stretcher_object;
		_carrier_front setVariable ["ace_stretcher_monitoring", false, true];
		_carrier_back setVariable ["ace_stretcher_monitoring", false, true];
		_stretcher_object animate ["rotate_driver1",0]; 
		_stretcher_object animate ["rotate_driver2",0];
		_stretcher_object setVariable ["ace_stretcher_front_grab", false, true]; 
		_stretcher_object setVariable ["ace_stretcher_back_grab", false, true];
		_carrier_front setVariable ["ace_stretcher_monitoring", false, true]; 
		_stretcher_monitoring = false;
		TRACE_1("Dropping stretcher","");
		_stretcher_object setVelocity [0,0,0];

		// No stamina boost after releasing stretcher
		{ 
			_x setVariable ["ace_sys_stamina_mass",-40,false]; // The function is bullshit
		} foreach [_carrier_front,_carrier_back]; 
		_carrier_front forceWalk false;
		_carrier_back forceWalk false;
	};
};
if (isNil QUOTE(FUNC(sease))) then {
	FUNC(ease) = {
		_this action ["WeaponOnBack", _this];
	};
};

switch (toLower _action) do {
	// GRAB ACTION
	case "grab": {
		switch (toLower _position) do {
			case "front": {
				_caller setDir direction _stretcher; // Front position is "driver"
				_stretcher attachTo [_caller, [0,-1.2,0], ""];
				_stretcher setVariable ["ace_stretcher_carrier_front", _caller, true];
				// Add "drop" action, GLOBAL, since we handle player only
				GVAR(drop_action) = _caller addAction [
					localize "STR_ACE_UA_DROP_STRETCHER",
					"\x\ace\addons\sys_wounds\ua_grab_stretcher.sqf",
					["", "drop", "", "", _stretcher],
					-1,false,true,"",""
				];
				_caller setVariable ["ace_stretcher_monitoring", true, true]; // Run a monitoring script for the carrying player
				_caller setVariable ["ace_stretcher_carrier_back_available",nil,true];
				if (local _caller) then { _stretcher_monitoring = _caller getVariable "ace_stretcher_monitoring"; };
				_caller call FUNC(ease);

				// Stamina Boost on taking knee + pushing loaded stretcher up
				if (count (crew _stretcher) > 0) then {
					// TODO: Get weight of person IN stretcher
					// _stretcher_weight = ...;
					//[_caller, 40] call ace_sys_stamina_fnc_inc_mass;
					_caller setVariable ["ace_sys_stamina_mass",40,false];
				};
			};
			case "back": { // Back position is following
				_caller attachTo [_stretcher, [0,-1,0], ""];
				_stretcher setVariable ["ace_stretcher_carrier_back", _caller, true];
				_caller call FUNC(ease);

				// Stamina Boost on taking knee + pushing loaded stretcher up
				if (count (crew _stretcher) > 0) then {
					// TODO: Get weight of person IN stretcher
					// _stretcher_weight = ...;
					_caller setVariable ["ace_sys_stamina_mass",40,false];
				};
			};
		};
		// TODO: Switch animation for _caller unit
		_stretcher animate _animation_code; // Animate stretcher upon drag
		_stretcher setVariable [_var, true, true]; // SetVariable to enable/disable actions
	};
	case "drop": {
		// DROP ACTION
		call FUNC(sdrop);
		(_this select 1) removeAction (_this select 2);
	};
	case "pickup": {
		// PICKUP ACTION
		if !(isPlayer _caller) exitWith { _caller groupChat "Negativ"; }; // AI cannot carry stretchers
		deleteVehicle _stretcher;
		if (secondaryWeapon _caller == "") then {
			_caller addWeapon "ACE_Stretcher";
		} else {
			_wh = "WeaponHolder" createVehicle getPosATL _caller;
			_wh addWeaponCargoGlobal ["ACE_Stretcher",1];
			player reveal _wh;
		};
		_stretcher_monitoring = false;
	};
};

if (_stretcher_monitoring) then {
	_count = 0;
	// CALLED WHEN USING GRAB ONLY !
	while {(_caller getVariable "ace_stretcher_monitoring")} do {
		_carrier_front = _stretcher getVariable "ace_stretcher_carrier_front";
		_carrier_back = _stretcher getVariable "ace_stretcher_carrier_back";

		// ForceWalk
		_carrier_front forceWalk true;
		_carrier_back forceWalk true;		
		
		// Check for front carrier, when there is no back carrier within 10 seconds, front carrier drops stretcher again
		if (_count > 8 && {isNil "_carrier_back"}) then {
			call FUNC(sdrop);
			_carrier_front removeAction GVAR(drop_action);
			if (local _carrier_front) then { "You need someone helping you." call ace_fnc_visual; };
		};

		// While none of the carriers is dead or unconscious nothing happens
		if !(alive _carrier_front) then {
			call FUNC(sdrop);
			_carrier_front removeAction GVAR(drop_action);
		};
		if !(alive _carrier_back) then {
			call FUNC(sdrop);
			_carrier_front removeAction GVAR(drop_action);
		};

		// Too fast
		if ((velocity _carrier_front call ACE_fnc_magnitude) > 5.51) then {
			if (random 10 > 8) then {
				// Guy falls down ...
				//call FUNC(sfall);
				call FUNC(sdrop); // ... once in place
			} else {
				call FUNC(sdrop);
				_carrier_front removeAction GVAR(drop_action); // TODO: Change, make guy on stretcher fall down! Maybe random...
			};
			if (local _carrier_front) then { "You have to walk slowly" call ace_fnc_visual; };
		};

		// TODO: Carrier front and back are unconsciousnes (i.e back carriers is unconscious and would be dragged in stretcher)
		// TODO: Wrong animation: Taking out Binocular, Raising weapon (combat ready), taking a knee, going prone
		if (((_carrier_front call CBA_fnc_getUnitAnim) select 0) != "stand") then {
			call FUNC(sdrop);
			_carrier_front removeAction GVAR(drop_action);
			if (local _carrier_front) then { "Get up stand up ..." call ace_fnc_visual; };
		};
		if (((_carrier_back call CBA_fnc_getUnitAnim) select 0) != "stand") then {
			call FUNC(sdrop);
			_carrier_front removeAction GVAR(drop_action);
			if (local _carrier_back) then { "Get up stand up ..." call ace_fnc_visual; };
		};

		// TODO: Anything else not allowed, firing, entering vehicles, climbing up ladders
		// Ladders
		if ((animationState _carrier_front) in ["ladderrifleon","laddercivilon"]) then {
			call FUNC(sdrop);
			_carrier_front removeAction GVAR(drop_action);
			if (local _carrier_front) then { "No ladders dude, no ladders" call ace_fnc_visual; };
		};
		// Knockoutanim for later
		//ActsPercMrunSlowWrflDf_TumbleOver

		sleep 1;
		INC(_count);
		TRACE_2("",(_carrier_front getVariable "ace_stretcher_carrier_back_available"),_count);
	};
	TRACE_1("Carrying stretcher aborted","");
};
