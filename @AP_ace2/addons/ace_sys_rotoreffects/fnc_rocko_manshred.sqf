/* rocko_manshred.sqf | (c) 2008 by rocko

 # Chops your head off or dismembers you when you are stupid enough to run into a spinning tailrotor #

 Mathematics, especially trigonometry, is somewhat gay in ArmA, so we cheat a little here and there to get this script roughly working.
 Feel free to improve the script, but the credits are mine, heck I got the friggin' idea for that !

 I had some nice cake while I did this.

*/

#include "script_component.hpp"

PARAMS_3(_unit,_pos,_trig);

if (_unit distance _trig > 3) exitWith {};

#ifdef DEBUG_MODE_FULL
_msg = format[" unit %1  rotor_pos %2  unit position %3",_unit,_pos,((_unit call CBA_fnc_getUnitAnim) select 0) ];
LOG(_msg);
#endif

switch toLower ((_unit call CBA_fnc_getUnitAnim) select 0) do {
	case "stand": {
		[QGVAR(dodam), [_unit, 1]] call ACE_fnc_receiverOnlyEvent;
	};
	case "kneel": {
		if (_pos < 1.3) then {
			[QGVAR(dodam), [_unit, 0.7]] call ACE_fnc_receiverOnlyEvent;
		};
	};
	case "prone": {
		if (_pos < 0.9) then {
			[QGVAR(dodam), [_unit, 0.5]] call ACE_fnc_receiverOnlyEvent;
		};
	};
	case "unknown": {
		[QGVAR(dodam), [_unit, 1]] call ACE_fnc_receiverOnlyEvent;
	};
};
