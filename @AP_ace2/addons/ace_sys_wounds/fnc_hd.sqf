// #define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __unitcfg configFile >> "cfgVehicles" >> _to
#define __ammocfg configFile >> "cfgAmmo" >> _ammo

/*

0: injured [Object]
1: part hit [String]
2: new overall part damage [Number]
3: injurer [Object]
4: class of ammo causing the damage [String]

For each hit this EH triggers 5 times within a frame, always in this sequence of parts:
1. "" - info on overall damage
2. "head_hit"
3. "body"
4. "hands"
5. "legs"

Multiple hits within one frame are handled one by one, not causing mixups
(1-2-3-4-5 - 1-2-3-4-5  - etc)

All 5 will trigger if at least 1 of the parts receives non-zero damage.
Damage values causing the triggering may be as low as 0.0001, so filtering might be advised.

Triggered by falling or collisions returns the unit itself as the injurer, ammo class is an empty string.
Example: [unit1,"head_hit",0.000253947,unit1,""]

Damage in destroyed vehicles only triggers the 1st type (""), then unit ejects.

using BIS configs:
head_hit:
armor = 0.6;  ==  no helmet
armor = 0.7; == for example pilot helmet
armor = 0.85; == normal helmet

body:
armor = 1;
passThrough = 0.8; == bulletproof west

armor = 0.8;
passThrough = 1; == NO bulletproof west


by q1184
*/
private "_isp";
PARAMS_1(_u);
_isp = isPlayer _u;

if (isNil "ace_sys_wounds_enabled" || {(!_isp && !isNil "ace_sys_wounds_noai")}) then {
	if (!alive _u) then {
		_hdh = _u getVariable QGVAR(hdeh);
		if (!isNil "_hdh") then {
			_u removeEventHandler ["handleDamage", _hdh];
			_u setVariable [QGVAR(hdeh), nil];
		};
	};
	if (_isp) then {if (vehicle _u == _u) then {[_u, _this select 4, ""] call FUNC(effect)}};
	if (!isNil {_unit getVariable "ace_w_allow_dam"}) then { 0 } else { _this select 2 };
} else { _this call FUNC(hd2) };
