//returns best throw animation based on current unit stance and weapon
//#define DEBUG_MODE_FULL
#include "script_component.hpp"
PARAMS_1(_unit);
private ["_anim","_posstr","_wpnstr","_ret"];
_anim = toArray(toLower(animationState _unit));
if (count(_anim)<24) exitWith {"AwopPknlMstpSgthWrflDnon_Start"};
_posstr = toString([_anim select 4, _anim select 5, _anim select 6, _anim select 7]);
_wpnstr = toString([_anim select 16, _anim select 17, _anim select 18, _anim select 19]);
switch (_wpnstr) do {
	case "wrfl": {
		_ret = switch (_posstr) do {
			case "perc": {"AwopPercMstpSgthWrflDnon_Start1"};
			case "ppne": {"AwopPpneMstpSgthWrflDnon_Start"};
			default {"AwopPknlMstpSgthWrflDnon_Start"};
		};
	};
	case "wpst": {
		_ret = switch (_posstr) do {
			case "perc": {"AwopPercMstpSgthWpstDnon_Part1"};
			case "ppne": {"AwopPpneMstpSgthWpstDnon_Part1"};
			default {"AwopPknlMstpSgthWpstDnon_Part1"};
		};
	};
	case "wnon": {
		_ret = switch (_posstr) do {
			case "perc": {"AwopPercMstpSgthWnonDnon_start"};
			case "ppne": {"AwopPpneMstpSgthWnonDnon_start"};
			default {"awoppknlmstpsgthwnondnon_start_forgoten"};
		};
	};
	default {_ret = "AwopPknlMstpSgthWrflDnon_Start"};
};
//TRACE_4("",_anim,_posstr,_wpnstr,_ret);
_ret
