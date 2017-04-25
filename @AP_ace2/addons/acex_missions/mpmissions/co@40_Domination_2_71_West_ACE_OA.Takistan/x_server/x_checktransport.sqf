// by Xeno
#define THIS_FILE "x_checktransport.sqf"
#include "x_setup.sqf"
private ["_chopper","_nr","_in_air_var","_kbvar"];
PARAMS_2(_chopper,_nr);

_in_air_var = format ["mr%1_in_air", _nr];
_kbvar = format ["Dmr%1_available", _nr];

while {(X_JIPH getVariable _in_air_var) && !isNull (driver _chopper)} do {sleep 2.453};
if ((X_JIPH getVariable _in_air_var) && isNull (driver _chopper)) then {
	[_in_air_var,false] call FUNC(NetSetJIP);
	#ifndef __TT__
	GVAR(kb_logic1) kbTell [GVAR(kb_logic2),GVAR(kb_topic_side),_kbvar,true];
	#else
	GVAR(hq_logic_en1) kbTell [GVAR(hq_logic_en2),"HQ_W",_kbvar,true];
	#endif
};
