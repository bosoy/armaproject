#include "script_component.hpp"
#define __cfgM (configFile >> "CfgMagazines" >> currentMagazine player)
#define __cfgA (configFile >> "CfgAmmo" >> _ammo)

#define __dspCursor (uiNamespace getVariable "ACE_RscCursorG")
#define __ctrlCursor (__dspCursor displayCtrl 159155)

private["_ammo","_cookie"];

if !(GVAR(holding)) exitwith {false};
if (player != vehicle player) exitwith {false};
if (currentWeapon player != "Throw") exitwith {false};
if ((velocity player) call ACE_fnc_magnitude > 0.1) exitwith {false};

_ammo = getText(__cfgM>>"ammo");
if (_ammo isKindOf "ace_flashbang") exitwith {false};
if (getNumber (__cfgA>>"explosionTime") <= 0.1) exitwith {false};
if (getNumber (__cfgA>>"explosive") == 0) exitwith {false};
if (getNumber (__cfgA>>"indirecthit") <= 0.1) exitwith {false};
if (getNumber (__cfgA>>"indirecthitRange") <= 0.1) exitwith {false};

GVAR(holding) = false;

_cookie = _ammo createvehicle [0,0,100];
_cookie attachto [player, [-0.05,0.05,0],"righthand"];
player setvariable ["ace_sys_grenadethrow_cookie",_cookie];
__ctrlCursor ctrlSetTextColor [1,0,0,1];
[player,"throw",currentmuzzle player,currentWeaponMode player,_ammo,currentmuzzle player,_cookie] call ace_sys_camshake_fnc_fired;



//[QGVAR(remotecookinit), [player,_ammo]] call CBA_fnc_globalEvent;
//player sidechat "Grenade hot";

//right mouse click will switch to optics - with last grenade you'll go into rifle's optics view - no good :)
//if (cameraview != "GUNNER") then {player switchcamera cameraview} else {player switchcamera "INTERNAL"};

true