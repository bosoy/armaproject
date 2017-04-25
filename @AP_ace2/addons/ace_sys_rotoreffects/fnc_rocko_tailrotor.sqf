/* rocko_tailrotor.sqf | (c) 2008 by rocko

 # Chops your head off or dismembers you when you are stupid enough to run into a spinning tailrotor #

 Mathematics, especially trigonometry, is somewhat gay in ArmA, so we cheat a little here and there to get this script roughly working.
 Feel free to improve the script, but the credits are mine, heck I got the friggin' idea for that !

 I had some nice cake while I did this.

*/

#include "script_component.hpp"

#define __tail_rotor_pos_model _tail_rotor_pos_model
#define __tail_rotor_pos_world_3D _v modelToWorld __tail_rotor_pos_model
#define __tail_rotor_diameter (((boundingbox _v) select 1 select 2) / 2) - 0.175
#define __tail_rotor_pos_world_Z (__tail_rotor_pos_world_3D select 2) - __tail_rotor_diameter
#define __set _v setVariable ["rocko_tailrotor_set", 1]
#define __unset _v setVariable ["rocko_tailrotor_set", 0]
#define __setspin _v setVariable ["rocko_tailrotor_spin", 1]
#define __unspin _v setVariable ["rocko_tailrotor_spin", 0]

private ["_v", "_msg", "_timeNow", "_trigger", "_pos", "_c"];

PARAMS_1(_v);

if !(_v getVariable QGVAR(enginestate)) exitWith { false };

// Re-ordered, always do your exit checks first
_tail_rotor_pos_model = _v selectionposition "mala osa";
if ( (__tail_rotor_pos_model) select 2 == 0) then { _tail_rotor_pos_model = _v selectionposition "tailRotor_axis";};
if ( (__tail_rotor_pos_model) select 2 == 0) then { _tail_rotor_pos_model = _v selectionposition "axis_mala_vrtule";};
if ( (__tail_rotor_pos_model) select 2 == 0) exitWith {
	#ifdef DEBUG_MODE_FULL
	_msg = format["Warning Message: %1 has not properly set tailrotor in model space (or script is missing)",(typeOf _v)];
	LOG(_msg);
	#endif
};
TRACE_1("",_tail_rotor_pos_model);

sleep 2;

__unset;
__unspin;
private "_timeNow";
_timeNow = time; // Rotor powerdown fix (a rotor spun for one second would kill anyone for 30 seconds after)

_trigger = objNull;

while {true} do {
	if !(_v getVariable QGVAR(enginestate)) exitWith { false };

	while { (getpos _v) select 2 > 2 } do {
		if (!isNull _trigger) then {
			detach _trigger;
			_trigger setPos [0,0,1000];
			deleteVehicle _trigger;
			TRACE_1("Trigger deleted, position vehicle > 2",_trigger);
		};
		__unset;
		sleep .8;
		#ifdef DEBUG_MODE_FULL
		if !(isNull _trigger) then { LOG(str(_v) + " flying too high for trigger"); };
		#endif
	};
	if (__tail_rotor_pos_world_Z  > 1.9) then {
		if (!isNull _trigger) then {
			detach _trigger;
			_trigger setPos [0,0,1000];
			deleteVehicle _trigger;
			TRACE_1("Trigger deleted, pos world tail rotor > 1.9",_trigger);
		};
		__unset;
		sleep .3;
		#ifdef DEBUG_MODE_FULL
		if !(isNull _trigger) then { LOG(str(_v) + " flying too high for trigger"); };
		#endif
	} else {
		if (_v getVariable "rocko_tailrotor_set" == 0) then  {
			if (canMove _v) then {
				_pos = __tail_rotor_pos_world_Z;
				TRACE_1("",_pos);
				_trigger = createTrigger ["EmptyDetector", [0, 0]];
				_trigger attachTo [_v,_tail_rotor_pos_model,""];
				_trigger setTriggerArea [2, 1, getDir _v, true];
				_trigger setTriggerActivation ["ANY", "PRESENT", true];
				_trigger setTriggerStatements
				[
					"({ _x isKindOf 'Man' } count thisList) > 0",
					format ["{[_x, %1, thisTrigger] call ace_sys_rotoreffects_fnc_rocko_manshred} foreach thisList", _pos],
					""
				];
				TRACE_1("Trigger created",_trigger);
				__set;
			} else {
				LOG(str(_v) + " Tailrotor dammaged - No trigger created");
				if (!isNull _trigger) then {
					detach _trigger;
					_trigger setPos [0,0,1000];
					deleteVehicle _trigger;
					TRACE_1("Trigger deleted, tailrotor dammaged",_trigger);
				};
				__unset;
			};
		};
	};
	if (canMove _v) then {
		if !(isNull _trigger) then {
			_trigger setDir (getDir _v);
			LOG("Trigger position updated");
			TRACE_1("Trigger position",(getDir _v));
		};
	} else {
		LOG(str(_v) + " Tailrotor dammaged - No trigger created");
		if (!isNull _trigger) then {
			detach _trigger;
			_trigger setPos [0,0,1000];
			deleteVehicle _trigger;
			TRACE_1("Trigger deleted, tailrotor dammaged",_trigger);
		};
		__unset;
	};
	sleep .3;
};

#ifdef DEBUG_MODE_FULL
if (isNull _trigger) then { LOG("Tailrotor harmless"); } else { LOG("Commencing spindown"); };
#endif

__setspin;

_c = (time - _timeNow) min 30; // Full power down is 30seconds, but if diff is only 5 seconds, then it will take 5 seconds until not dangerous
while { _c > 0 && {alive _v} } do {
	if (!isNull _trigger) then {
		_trigger setDir (getDir _v);
	};
	//if !(isNull _trigger) then { LOG("Spindown Phase"); };
	sleep 1;
	_c = _c - 1;
	if ( (_v getVariable "rocko_tailrotor_spin")== 0 ) exitWith { false };
};
__unset;
__unspin;

if (!isNull _trigger) then {
	detach _trigger;
	_trigger setPos [0,0,1000];
	deleteVehicle _trigger;
	TRACE_1("Trigger deleted, end of script",_trigger);
};
LOG("Variables UNSET");
LOG("Script TERMINATED");
