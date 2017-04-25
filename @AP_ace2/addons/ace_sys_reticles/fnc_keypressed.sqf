#include "script_component.hpp"
#define __wcfg configFile >> "CfgWeapons" >> _wpn
#define __scfg configfile>>"ace_config">>"cfgOpticsReticles">>_type
#define __vcfg configfile>>"cfgvehicles">>typeof (vehicle player)
#define __scfg_veh configfile>>"ace_config">>"cfgVehicleOpticsReticles">>_type

#define __dsp (uiNamespace getVariable "ACE_RscOpticsReticle")
#define __ctrl (__dsp displayCtrl 1)
#define __ctrl2 (__dsp displayCtrl 2)

private["_wpn","_type","_handled","_clr"];
_handled = false;
if (GVAR(sightup_veh) && {(currentvisionmode player) == 0}) then
{
	_type = getText(__vcfg>>"ace_sys_reticles_gunnersight");
	if (getNumber(__scfg_veh>>"ace_sys_reticles_illum")==1) then
	{
		if (GVAR(illum_veh)) then {__ctrl ctrlSetTextColor [0,0,0,1];__ctrl2 ctrlSetTextColor [0,0,0,1];GVAR(illum_veh) = false} else
		{
			_clr = getArray(__scfg_veh>>"ace_sys_reticles_illumcolor");
			__ctrl ctrlsetTextColor _clr;
			__ctrl2 ctrlSetTextColor _clr;
			GVAR(illum_veh) = true;
		};
		_handled = true;
	};
};
if !(GVAR(sightup)) exitwith {_handled};
_wpn = currentweapon player;
_type = getText(__wcfg>>"ace_sys_reticles_scope");
if (getNumber(__scfg>>"ace_sys_reticles_illum")==1) then
{
	if (GVAR(illum)) then {__ctrl ctrlSetTextColor [0,0,0,1];GVAR(illum) = false} else
	{__ctrl ctrlsetTextColor (getArray(__scfg>>"ace_sys_reticles_illumcolor"));GVAR(illum) = true};
	__ctrl ctrlcommit 0;
	_handled = true;
};
_handled