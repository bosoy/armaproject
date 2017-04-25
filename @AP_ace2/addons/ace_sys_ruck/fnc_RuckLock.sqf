//#define DEBUG_MODE_FULL
#include "script_component.hpp"

scopeName "script_out";
private ["_scopes", "_target", "_lock", "_found", "_scope", "_disp", "_ctrl_txt", "_ctrl_pic", "_scope_let", "_scope_name", "_inpro"];
PARAMS_1(_target);
DEFAULT_PARAM(1,_index,nil);

_scopes = ["", "Squad", "Team"];

if (! isNil "_index") then {
    if (_index < 0) then {
		breakOut "script_out";
	} else {
		if (_index >= (count _scopes)) then { breakOut "script_out"; };
	};
};

_lock = _target getVariable ["ACE_Ruck_Lock","Team"];

_found = _scopes find _lock;

_inpro =  _found == -1; //ruck is in busy state

if (isNil "_index") then {
    _found = _found + 1;
    if ( _found >= (count _scopes) ) then {
        _found = 0;
    } else {
        if ( _found < 0 ) then { _found = (count _scopes) - 1 };
    };

    _scope = _scopes select _found;
} else {
    _scope = _scopes select _index;
};

_target setVariable ["ACE_Ruck_Lock_Scope", _scope];
if (! _inpro) then { _target setVariable ["ACE_Ruck_Lock", _scope, true]; };
