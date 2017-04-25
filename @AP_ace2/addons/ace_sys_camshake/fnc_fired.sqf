/* ace_fx_explosions | (c) 2013 by rocko */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __cfgW configFile >> "CfgWeapons" >> _weapon
#define __cfgA configFile >> "CfgAmmo" >> _ammo

private["_weapon", "_ammo", "_astr", "_m", "_projectile", "_ihr"];
_weapon = _this select 1;
_ammo = _this select 4;
_projectile = _this select 6; // uses BIS Fired EH
TRACE_3("",_weapon,_ammo,_projectile);
if !(alive _projectile) exitWith {}; // It seems rifle grenades are objNull in non local fired EH!

if !(_gun getVariable ["ARTY_CURRENT_FIRED_EH", false]) exitWith {}; // Shells will be replaced by the arty module - track function would think it explodes while leaving the barrel.

if (getNumber(__cfgW >> "type") in [2,5]) exitWith {}; // DISABLE for Pistol & MG

if (getNumber(__cfgA >> "ACE_FX_EXPLOSIONS_OVR") == 1) exitWith {};
if (getText(__cfgA >> "simulation") in ["shotTimeBomb","shotPipeBomb","shotMine","shotIlluminating","shotSmoke"]) exitWith {};
if (getText(__cfgA >> "ACE_simulation") in ["shotWP","shotCS","shotFlashbang","shotCBU","shotBunkerBuster"]) exitWith {};
_astr = getNumber(__cfgA >> "indirectHit");
if (_astr < 2) exitWith {}; // DISABLE for low indirect hit ammunition

_m = switch (true) do {
	case (_astr > 500): {5.5};
	case (_astr > 250): {4.5};
	case (_astr > 100): {3};
	default {2};
};

_ihr = getNumber(__cfgA >> "indirectHitRange");
if (_ihr < 4.9) exitWith { TRACE_1("low IHR","") }; // DISABLE for low indirecthitrange ammunition
// delay of tracking, to prevent fx on remote clients with yet unarmed ammo
[_projectile,(_ihr * _m),_ammo,_m, getNumber(__cfgA >> "ACE_FX_EXPLOSIONS_d")] call FUNC(track);
