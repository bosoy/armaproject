#include "script_component.hpp"
#include "Script_SightAdjustmentConfig.hpp"
private["_defaultwindage","_veh","_rng","_elevunit","_windunit","_c","_adjmode","_tableelev","_tablerange","_weaparray","_sa_enabled","_defaultelevation","_minelevation","_maxelevation","_windage","_stepelevation","_stepwindage","_mode","_table"];

PARAMS_2(_turretpath,_weapon);

#define __wcfg (configfile >> "CfgWeapons" >> _weapon)

_weaparray = [];

_defaultelevation = [__wcfg,_turretpath,"ace_sa_defaultelevation",0] call FUNC(GetValue);
_defaultwindage = [__wcfg,_turretpath,"ace_sa_defaultwindage",0] call FUNC(GetValue);
_minelevation = [__wcfg,_turretpath,"ace_sa_minelevation",0] call FUNC(GetValue);
_maxelevation = [__wcfg,_turretpath,"ace_sa_maxelevation",0] call FUNC(GetValue);
_stepelevation = [__wcfg,_turretpath,"ace_sa_stepelevation",0] call FUNC(GetValue);
_windage = [__wcfg,_turretpath,"ace_sa_windage",0] call FUNC(GetValue);
_stepwindage = [__wcfg,_turretpath,"ace_sa_stepwindage",0] call FUNC(GetValue);
_adjmode = [__wcfg,_turretpath,"ace_sa_adj_mode",""] call FUNC(GetValue);
_elevunit = [__wcfg,_turretpath,"ace_sa_elev_unit",""] call FUNC(GetValue);
_windunit = [__wcfg,_turretpath,"ace_sa_wind_unit",""] call FUNC(GetValue);
_rng = [__wcfg,_turretpath,"ace_sa_range_unit",""] call FUNC(GetValue);
_table = [__wcfg,_turretpath,"ace_sa_table_elev",[]] call FUNC(GetValue);

ACE_SYS_SA_WCFG = ACE_SYS_SA_WCFG_NEW;	//creating a new array containig current weapon sight properties
ACE_SYS_SA_WCFG_SET_WEAPON(_weapon);
ACE_SYS_SA_WCFG_SET_DEFAULTELEVATION(_defaultelevation);
ACE_SYS_SA_WCFG_SET_DEFAULTWINDAGE(_defaultwindage);
ACE_SYS_SA_WCFG_SET_MINELEVATION(_minelevation);
ACE_SYS_SA_WCFG_SET_MAXELEVATION(_maxelevation);
ACE_SYS_SA_WCFG_SET_MAXWINDAGE(_windage);
ACE_SYS_SA_WCFG_SET_ADJELEVATION(_stepelevation);
ACE_SYS_SA_WCFG_SET_ADJWINDAGE(_stepwindage);
ACE_SYS_SA_WCFG_SET_ELEVATION_UNITS(_elevunit);
ACE_SYS_SA_WCFG_SET_WINDAGE_UNITS(_windunit);
ACE_SYS_SA_WCFG_SET_TABLE(_table);
ACE_SYS_SA_WCFG_SET_ADJMODE(_adjmode);
ACE_SYS_SA_WCFG_SET_RANGE_UNITS(_rng);
