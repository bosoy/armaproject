// #define DEBUG_MODE_FULL
#include "script_component.hpp"
#include "Script_SightAdjustmentConfig.hpp"

#define ACE_TEXT_SILVER(Text) ("<t color='#C0C0C0'>" + ##Text + "</t>")
#define __wcfg (configfile >> "CfgWeapons" >> _weapon)

#define HAS_RETICLES(VEH) (getNumber(configfile>>"cfgvehicles">>(typeof VEH)>>"ace_sys_reticles_gunneroptics")==1)

private ["_te","_sa","_p","_poschanged","_pos","_curturret","_turretpath","_turcfg","_turret","_action_dlg","_action_TE","_veh_in_the_list","_wd","_x1","_y","_z","_el","_veh","_weapon","_sa_enabled","_s"];
_turret = _this;
_veh = vehicle player;
_veh_in_the_list = false;
_turcfg = [typeOf _veh, _turret] call FUNC(GetTurretCfg);
_sa = _turcfg select 3;
_te = _turcfg select 4;
if (!_sa && !_te) exitwith {};	//weapon does not have SA or TE
_weapon = _turcfg select 1;
_turretpath = _turcfg select 0;

_turcfg call FUNC(getWeaponCfg);

ACE_SYS_SA = ACE_SYS_SA_NEW;
ACE_SYS_SA_SET_ENABLED(true);
ACE_SYS_SA_SET_CURUNIT(player);
ACE_SYS_SA_SET_CURWEAPON(_weapon);
ACE_SYS_SA_SET_CURVEHICLE(typeOf _veh);
ACE_SYS_SA_SET_CURTURRET(_turret);
ACE_SYS_SA_SET_CURELEVATION(ACE_SYS_SA_WCFG_DEFAULTELEVATION);
ACE_SYS_SA_SET_CURWINDAGE(0);
call FUNC(SetDegrees);

ace_te_enabled = false;

if (!isNil {_veh getVariable QGVAR(params)}) then {
	_p = _veh getVariable "ace_sys_sight_adjustment_params";
	ACE_SYS_SA_SET_CURELEVATION(_p select 5);
	ACE_SYS_SA_SET_CURWINDAGE(_p select 6);
	call FUNC(SetDegrees);
} else {
	_p = [ACE_SYS_SA_CURELEVATION_DEG,ACE_SYS_SA_CURWINDAGE_DEG,ACE_SYS_SA_CURWEAPON,ACE_SYS_SA_CURTURRET,false,ACE_SYS_SA_CURELEVATION,ACE_SYS_SA_CURWINDAGE, _sa];
	//[QGVAR(setadj), [_veh,_p]] call CBA_fnc_globalEvent;
	_veh setVariable ["ace_sys_sight_adjustment_params", _p, true]; //global
};

if (_sa) then { _action_dlg = _veh addaction [ACE_TEXT_SILVER(localize "STR_ACE_SA_SA"), "\x\ace\addons\sys_sight_adjustment\startdialog.sqf",[],0.11,false,true,"","!(ace_te_enabled)"]; };

//_s = [__wcfg,_turretpath,"ace_sa_TE_enabled",0] call FUNC(GetValue);
if (_te) then { _action_TE = _veh addaction [ACE_TEXT_SILVER(localize "STR_ACE_SA_TandE"), "\x\ace\addons\sys_sight_adjustment\TE.sqf",[],0.1] };

_poschanged = false;
while { !_poschanged && {vehicle player == _veh} } do {
	_pos = assignedVehicleRole player;
	if (_pos select 0 == "Turret") then { //plr in gunner pos, checking if it's the same or another turret
		_curturret = _pos select 1;
		if !([_turret, _curturret] call FUNC(EqualArrays)) then { _poschanged = true } else
		{
			if (HAS_RETICLES(_veh) && (!ace_sys_reticles_sightup_veh)) then
			{
				player spawn ace_sys_reticles_fnc_veh_reticle;
			};
		};
	} else { // not in gunner pos anymore, exit
		_poschanged = true;
	};
	if (_poschanged) exitwith {};
	sleep 1.5;
};
if (_sa) then { _veh removeaction _action_dlg; };
if (_te && !(ACE_SYS_SA_TEACTIVE)) then { _veh removeaction _action_TE };
