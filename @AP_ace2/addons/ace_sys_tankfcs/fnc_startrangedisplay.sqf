#include "script_component.hpp"

#define __dsp (uiNamespace getVariable "ACE_M1A1GPS_DISPLAY")
#define __thousandscontrol  (__dsp displayCtrl 432112)
#define __hundredscontrol  (__dsp displayCtrl 432113)
#define __tenscontrol  (__dsp displayCtrl 432114)
#define __onescontrol  (__dsp displayCtrl 432115)
#define __blackbgcontrol  (__dsp displayCtrl 432144)

#define __vehcfg configFile >> "cfgVehicles" >> typeof _veh
#define __maxrng getNumber(__vehcfg >> "ace_tankfcs_maxlrfrange")
#define __minrng getNumber(__vehcfg >> "ace_tankfcs_minlrfrange")

#define __dcolor getArray(__vehcfg >> "ace_tankfcs_digitscolor")
#define __dstyle getNumber(__vehcfg >> "ace_tankfcs_digitsstyle")
#define __rdystyle getNumber(__vehcfg >> "ace_tankfcs_rdystyle")
#define __blackbar getNumber(__vehcfg >> "ace_tankfcs_background")
#define __rdycontrol  (__dsp displayCtrl (432141 + __rdystyle))


#define __cooltime getNumber(__vehcfg >> "ace_tankfcs_lrfcooldowntime")

PARAMS_1(_range);
private ["_rdytext","_rdystyle","_veh","_stl","_clr","_accuracy","_thousandsplace","_hundredsplace","_tensplace","_onesplace","_dsp","_c4","_c3","_c2","_c1"];
_veh = vehicle player;

//if (isNull __dsp) then
//{
	135443 cutRsc ["ACE_M1A1GPS_DISPLAY", "PLAIN"];
//};
_stl = __dstyle;
_clr = __dcolor;

_accuracy = 10;

__thousandscontrol ctrlSetTextColor _clr;
__hundredscontrol ctrlSetTextColor _clr;
__tenscontrol ctrlSetTextColor _clr;
__onescontrol ctrlSetTextColor _clr;

if (_range == 0) then {
	__thousandscontrol ctrlSetText format[QUOTE(PATHTO_T(data\white%1_1.paa)),_stl];
	__hundredscontrol ctrlSetText format[QUOTE(PATHTO_T(data\white%1_2.paa)),_stl];
	__tenscontrol ctrlSetText format[QUOTE(PATHTO_T(data\white%1_3.paa)),_stl];
	__onescontrol ctrlSetText format[QUOTE(PATHTO_T(data\white%1_4.paa)),_stl];
	sleep 0.3;

	__thousandscontrol ctrlSetText format[QUOTE(PATHTO_T(data\white%1_5.paa)),_stl];
	__hundredscontrol ctrlSetText format[QUOTE(PATHTO_T(data\white%1_6.paa)),_stl];
	__tenscontrol ctrlSetText format[QUOTE(PATHTO_T(data\white%1_7.paa)),_stl];
	__onescontrol ctrlSetText format[QUOTE(PATHTO_T(data\white%1_9.paa)),_stl];
	sleep 0.3;
};
_thousandsplace = floor(_range/1000);
_hundredsplace = floor(_range/100) - 10*_thousandsplace;
_tensplace = floor(_range/10) - 100*_thousandsplace - 10*_hundredsplace;
_onesplace = floor(_range/_accuracy)*_accuracy - 1000*_thousandsplace - 100*_hundredsplace - 10*_tensplace;

__thousandscontrol ctrlSetText format[QUOTE(PATHTO_T(data\white%1_%2.paa)),_stl,_thousandsplace];
__hundredscontrol ctrlSetText format[QUOTE(PATHTO_T(data\white%1_%2.paa)),_stl,_hundredsplace];
__tenscontrol ctrlSetText format[QUOTE(PATHTO_T(data\white%1_%2.paa)),_stl,_tensplace];
__onescontrol ctrlSetText format[QUOTE(PATHTO_T(data\white%1_%2.paa)),_stl,_onesplace];

//if (__blackbar == 0) then {__blackbgcontrol ctrlShow false};

if (time - (_veh getvariable ["ace_tankfcs_lastlasetime", 0]) < __cooltime) then {
	__rdycontrol ctrlShow false;
} else {
	__rdycontrol ctrlShow true;
	__rdycontrol ctrlSetText format[QUOTE(PATHTO_T(data\white_rdy%1.paa)),__rdystyle];
	__rdycontrol ctrlSetTextColor _clr;
};
