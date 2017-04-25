// by Xeno
#define THIS_FILE "x_checktransport2.sqf"
#include "x_setup.sqf"
private ["_chopper","_nr","_in_air_var","_kbvar"];
PARAMS_2(_chopper,_nr);

_in_air_var = format ["mrr%1_in_air", _nr];
_kbvar = format ["Dmr%1_available", _nr];

while {(X_JIPH getVariable _in_air_var) && !isNull (driver _chopper)} do {sleep 2.453};
if ((X_JIPH getVariable _in_air_var) && isNull (driver _chopper)) then {
	[_in_air_var,false] call FUNC(NetSetJIP);
	GVAR(hq_logic_ru1) kbTell [GVAR(hq_logic_ru2),"HQ_E",_kbvar,true];
};