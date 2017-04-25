//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: Reezo of SR5 Tactical - www.sr5tactical.net
// This script clears a crate and fills it with all possible ACRE radios available.
// Thanks Hornet for finding out about these.
//////////////////////////////////////////////////////////////////

private ["_crate","_amount"];
//if (!isServer) exitWith{};

if (count _this < 2) exitWith {hint "insufficient parameters in init_ACREradios.sqf"};

_crate = _this select 0;
_amount = _this select 1;

clearWeaponCargo _crate;
clearMagazineCargo _crate;

_crate addWeaponCargo ["ACRE_PRC148",_amount];
_crate addWeaponCargo ["ACRE_PRC148_UHF",_amount];
_crate addWeaponCargo ["ACRE_PRC343",_amount];
_crate addWeaponCargo ["ACRE_PRC119",_amount];
_crate addWeaponCargo ["ACRE_PRC117F",_amount];

if (true) exitWith{};