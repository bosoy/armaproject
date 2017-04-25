//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_2(_target,_caller);
private ["_magAry", "_wepAry", "_targetname"];

if !([_target] call FUNC(RuckBusy)) then {
    _target setVariable ["ACE_Ruck_Lock", name _caller, true];
    //TODO: Temporarily disable own ruck usage
	_magAry = _target getVariable ["ACE_RuckMagContents", []];
	
	//temporary bwc, adds warnings to RPT
	private ["_oneentry", "_nammoar", "_nammoc", "_ez", "_ufoundwrong"];
	_ufoundwrong = false;
	{
		_oneentry = _x;
		TRACE_1("before",_oneentry);
		if (count _oneentry < 3) then {
			_ufoundwrong = true;
			WARNING("ACE_RuckMagContents ammocount for magazine missing: " + str(_oneentry)); 
			_nammoar = [];
			_nammoc = getNumber(configFile/"CfgMagazines"/(_oneentry select 0)/"count");
			for "_ez" from 1 to (_oneentry select 1) do {
				_nammoar set [count _nammoar, _nammoc];
			};
			_oneentry set [count _oneentry, _nammoar];
			TRACE_1("after",_oneentry);
		} else {
			// just in case
			if (_oneentry select 1 > count (_oneentry select 2)) then {
				_nammoar = _oneentry select 2;
				_nammoc = getNumber(configFile/"CfgMagazines"/(_oneentry select 0)/"count");
				for "_ez" from (count _nammoar) to (_oneentry select 1) - 1 do {
					_nammoar set [count _nammoar, _nammoc];
				};
			};
		};
	} forEach _magAry;
	if (_ufoundwrong) then {
		WARNING("Please update mission or addon to make use of the ACE_fnc_PackMagazine API function !!!");
	};	
	
	_wepAry = _target getVariable ["ACE_RuckWepContents", []];
    _target setVariable ["ACE_RuckContents_Net", [_magAry, _wepAry], true];
    _target setVariable ["ACE_Ruck_Lock_Unit", _caller];

    playsound "beep";
    _targetname = if (alive _target) then {name _target} else {if (!isNil {_target getVariable "ace_sys_dogtag_name"}) then {_target getVariable "ace_sys_dogtag_name"} else {localize "str_dn_body"}};
    format[localize "STR_DN_ACE_RUCK_ACCESSING", name _caller, _targetname] spawn ace_fnc_visual;

    [_target, _caller] spawn {
        PARAMS_2(_target,_caller);
        if ( isNil QGVAR(ACE_Ruck_Share_Dist) ) then { GVAR(ACE_Ruck_Share_Dist) = 10; };
        while { [_target] call FUNC(RuckBusy) } do {
            sleep 2;
            if ( (_target distance _caller) > GVAR(ACE_Ruck_Share_Dist) ) exitWith { [_target] call FUNC(RuckCancel); };
        };
    };
};
