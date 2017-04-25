//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_3(_itm,_txt,_pic);
private ["_isClsWep", "_isClsMag", "_isWep", "_isNamWep", "_isNamMag"];
//isClass
_isClsWep = isClass(__CONF_WEAPONS >> _itm);
_isClsMag = isClass(__CONF_MAGAZINES >> _itm);
if ( !(_isClsWep && _isClsMag) ) then {_isWep = _isClsWep;};
//displayName
if (isNil "_isWep" && {!isNil "_txt"}) then {
	if (typeName _txt == "STRING" && {_txt != ""}) then {
		_isNamWep = (_txt == getText(__CONF_WEAPONS >> _itm >> "displayName"));
		_isNamMag = (_txt == getText(__CONF_MAGAZINES >> _itm >> "displayName"));
		if !(_isNamWep && _isNamMag) then {_isWep = _isNamWep;};
	};
};
//scope
if (isNil "_isWep") then {
	if ( getNumber(__CONF_WEAPONS >> _itm >> "scope") == 0 ) then {_isWep = false;};
	if ( getNumber(__CONF_MAGAZINES >> _itm >> "scope") == 0 ) then {_isWep = true;};
	TRACE_1("scp",_isWep);
};
//picture
if (isNil "_isWep" && {!isNil "_pic"}) then {
	if ( typeName _pic == "STRING" && {_pic != ""}) then {
		_isNamWep = (_pic == getText(__CONF_WEAPONS >> _itm >> "picture"));
		_isNamMag = (_pic == getText(__CONF_MAGAZINES >> _itm >> "picture"));
		if !(_isNamWep && _isNamMag) then {_isWep = _isNamWep;};
	};
};
//fallback
if (isNil "_isWep") then {TRACE_1("fbFin",_itm); _isWep = false;};
//return
_isWep;