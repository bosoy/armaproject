#include "script_component.hpp"
#include "Script_SightAdjustmentConfig.hpp"

// Text magic
#define ACE_TEXT_RED(Text) ("<t color='#FF0000'>" + ##Text + "</t>")
#define ACE_TEXT_GRAY(Text) ("<t color='#808080'>" + ##Text + "</t>")
#define ACE_TEXT_SILVER(Text) ("<t color='#C0C0C0'>" + ##Text + "</t>")
#define ACE_TEXT_TEAL(Text) ("<t color='#008080'>" + ##Text + "</t>")
#define ACE_TEXT_OLIVE(Text) ("<t color='#808000'>" + ##Text + "</t>")
#define ACE_TEXT_MAROON(Text) ("<t color='#800000'>" + ##Text + "</t>")

#define __dsp (uiNameSpace getVariable "ACE_RscGenericNF")
#define __ctrl_elev (__dsp displayCtrl 1358009)
#define __ctrl_azim (__dsp displayCtrl 1358010)
#define __ctrl_bg (__dsp displayCtrl 1358012)

private ["_pos","_azim1","_p","_ctrl_elev","_ctrl_azim","_azim","_txt","_wd","_x1","_y","_z","_el","_veh","_weapon", "_s", "_s1"];
_veh = vehicle player;
_veh removeaction (_this select 2);
_s = _veh addaction [ACE_TEXT_RED(localize "STR_ACE_SA_TandE_END"), "\x\ace\addons\sys_sight_adjustment\TEclose.sqf",[],0.1];
if (count ACE_SYS_SA_WCFG_TABLE > 0) then {
  _s1 = _veh addaction [ACE_TEXT_SILVER(localize "STR_ACE_SA_RANGETABLE"), "\x\ace\addons\sys_sight_adjustment\openRangeCard.sqf",[],0];
};

_azim1 = 0;

ace_te_enabled = true;
ACE_SYS_SA_SET_TEACTIVE(true);
_p = _veh getVariable "ace_sys_sight_adjustment_params";
_p set [4,true];
//[-1, { (_this select 0) setVariable ["ace_sys_sight_adjustment_params", _this select 1] }, [_veh, _p] ] call ace_sys_network_fSend;
_veh setVariable ["ace_sys_sight_adjustment_params",_p,true];

cutRsc ["ACE_RscGenericNF","PLAIN"];
_pos = ctrlposition __ctrl_bg;
__ctrl_bg ctrlsetposition [_pos select 0,_pos select 1,_pos select 2,2*(_pos select 3)];
__ctrl_bg ctrlcommit 0;

while { vehicle player == _veh && {ACE_SYS_SA_TEACTIVE} } do {
	_wd = _veh weapondirection ACE_SYS_SA_CURWEAPON;
	_x1 = _wd select 0;
	_y = _wd select 1;
	_z = _wd select 2;
	_el = _z atan2 sqrt(_x1^2 + _y^2);
	_azim = _x1 atan2 _y;
	if (_azim < 0) then { _azim = 360 + _azim };
	switch (toLower ACE_SYS_SA_WCFG_ELEVATION_UNITS) do {
		/*case "mil": { _el = round (1000*pi*_el/180); _txt = "mil"; _azim1 = round (_azim*6400/360) };*/
		case "mil": { _el = round ((_el/360)*6400); _txt = "mil"; _azim1 = round (_azim*6400/360) };
		case "mil_e": { _el = round (_el/0.06); _txt = "mil"; _azim1 = round(_azim*6000/360) };
		case "moa": { _el = round(_el/60); _txt = "MOA" };
		case "deg": { _el = round _el; _txt = localize "STR_ACE_SA_deg"; _azim1 = round _azim };
		default { _el = round _el; _txt = localize "STR_ACE_SA_deg"; _azim1 = round _azim };
	};
	__ctrl_elev ctrlSetText format["Elev: %1 %2", _el, _txt];
	__ctrl_azim ctrlSetText format["Azim: %1 %2 (%3 °)", _azim1, _txt,0.1*round (_azim*10)];
	sleep 0.1;
};
_veh removeaction _s;
_veh removeaction _s1;

__ctrl_elev ctrlShow false;
__ctrl_azim ctrlShow false;
__ctrl_bg ctrlsetposition [_pos select 0,_pos select 1,_pos select 2,_pos select 3];
__ctrl_bg ctrlcommit 0;

//1358008 closeDisplay IDC_OK;
cutText["","PLAIN"];

ACE_SYS_SA_SET_TEACTIVE(false);
_p = _veh getVariable "ace_sys_sight_adjustment_params";
_p set [4,false];
_veh setVariable ["ace_sys_sight_adjustment_params",_p,true];
//[-2, { (_this select 0) setVariable ["ace_sys_sight_adjustment_params",(_this select 1)] }, [_veh, _p] ] call ace_sys_network_fSend;
