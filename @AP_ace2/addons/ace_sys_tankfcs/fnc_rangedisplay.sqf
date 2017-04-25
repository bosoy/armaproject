#include "script_component.hpp"
#define __dsp (uiNamespace getVariable "ACE_M1A1GPS_DISPLAY")
#define __thousandscontrol  (__dsp displayCtrl 432112)
#define __hundredscontrol  (__dsp displayCtrl 432113)
#define __tenscontrol  (__dsp displayCtrl 432114)
#define __onescontrol  (__dsp displayCtrl 432115)

#define __vehcfg configFile >> "cfgVehicles" >> typeof _veh
#define __dcolor getArray(__vehcfg >> "ace_tankfcs_digitscolor")
#define __dstyle getNumber(__vehcfg >> "ace_tankfcs_digitsstyle")
#define __rdystyle getNumber(__vehcfg >> "ace_tankfcs_rdystyle")
#define __rdycontrol  (__dsp displayCtrl (432141 + __rdystyle))

#define __cooltime getNumber(__vehcfg >> "ace_tankfcs_lrfcooldowntime")

private ["_rdystyle","_clr","_stl","_veh","_accuracy","_thousandsplace","_hundredsplace","_tensplace","_onesplace"];

PARAMS_3(_range,_maxrange,_minrange);

//if (isNull __dsp) then
//{
//	135443 cutRsc ["ACE_M1A1GPS_DISPLAY", "PLAIN",0];
//};
_veh = vehicle player;

_accuracy = 10;

_thousandsplace = floor(_range/1000);
_hundredsplace = floor(_range/100) - 10*_thousandsplace;
_tensplace = floor(_range/10) - 100*_thousandsplace - 10*_hundredsplace;
_onesplace = floor(_range/_accuracy)*_accuracy - 1000*_thousandsplace - 100*_hundredsplace - 10*_tensplace;

_stl = __dstyle;
_clr = __dcolor;

__thousandscontrol ctrlSetText format[QUOTE(PATHTO_T(data\white%1_%2.paa)),_stl,_thousandsplace];
__hundredscontrol ctrlSetText format[QUOTE(PATHTO_T(data\white%1_%2.paa)),_stl,_hundredsplace];
__tenscontrol ctrlSetText format[QUOTE(PATHTO_T(data\white%1_%2.paa)),_stl,_tensplace];
__onescontrol ctrlSetText format[QUOTE(PATHTO_T(data\white%1_%2.paa)),_stl,_onesplace];

__thousandscontrol ctrlSetTextColor _clr;
__hundredscontrol ctrlSetTextColor _clr;
__tenscontrol ctrlSetTextColor _clr;
__onescontrol ctrlSetTextColor _clr;

_veh setvariable ["ace_tankfcs_range",_range];

if (time - (_veh getvariable ["ace_tankfcs_lastlasetime", 0]) < __cooltime) then {
	if( __rdystyle == 0) then {_rdystyle = 432141} else {_rdystyle = 432142};
	__rdycontrol ctrlshow false;
	[_veh,__cooltime] spawn {
		PARAMS_1(_veh);
		waituntil {time - ((_this select 0) getvariable ["ace_tankfcs_lastlasetime", 0]) >= (_this select 1)};
		if !(isNull __dsp) then {
			__rdycontrol ctrlshow true;
			__rdycontrol ctrlSetText format[QUOTE(PATHTO_T(data\white_rdy%1.paa)),__rdystyle];
			__rdycontrol ctrlSetTextColor __dcolor;
		};
	};
};

if (_range < _minrange || {_range > _maxrange}) then {
	if !(_veh getVariable "ace_tankfcs_flash") then {
		_veh setVariable ["ace_tankfcs_flash", true];

		[_veh] spawn { // flashing range digits .... ???? Why pass a parameter ?
			private "_veh";
			_veh = vehicle player;
			if (player == _veh) exitwith {};
			while { !isNil {_veh getVariable "ace_tankfcs_flash"} && {_veh getVariable "ace_tankfcs_flash"} && {!isNull __dsp} } do {
				__thousandscontrol ctrlShow false;
				__hundredscontrol ctrlShow false;
				__tenscontrol ctrlShow false;
				__onescontrol ctrlShow false;
				sleep 0.4;
				__thousandscontrol ctrlShow true;
				__hundredscontrol ctrlShow true;
				__tenscontrol ctrlShow true;
				__onescontrol ctrlShow true;
				sleep 0.4;
			};
			_veh setVariable ["ace_tankfcs_flash", false];
		};
	};
} else {
	_veh setVariable ["ace_tankfcs_flash", false];
};

