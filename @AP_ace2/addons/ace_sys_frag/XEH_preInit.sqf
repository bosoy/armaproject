#include "script_component.hpp"

ADDON = false;

PREP(fired);
PREP(frago);
PREP(trackFragRound);

GVAR(trackedObjects) = [];
GVAR(blackList) = [];
GVAR(enabled) = true;
GVAR(traceFrags) = false;

GVAR(replacedBisArtyWrapper) = false;

GVAR(TOTALFRAGS) = 0;

FUNC(frag_trace) = {
	_params = _this select 0;
	_shell = _params select 0;
	if(alive _shell) then {
		drop ["\Ca\Data\Cl_basic","","Billboard",1,30,(getPos _shell),[0,0,0],1,1.275,1.0,0.0,[0.5],[[0,1,0,1]],[0],0.0,2.0,"","",""];
	} else {
		[_this select 1] call cba_fnc_removePerFrameHandler;
	};
};

FUNC(denyFrag) = {
	_ret = [(_this select 0)] call FUNC(removeTrack);
	if(!_ret) then {
		[(_this select 0)] call FUNC(addBlackList);
	};
};

FUNC(removeTrack) = {
	private ["_ret"];
	_ret = true;
	if(IS_ARRAY((_this select 0))) then {
		_ret = false;
	} else {
		if((_this select 0) in GVAR(trackedObjects)) then {
			GVAR(trackedObjects) = GVAR(trackedObjects) - [(_this select 0)];
		} else {
			_ret = false;
		};
	};
	_ret
};

FUNC(addBlackList) = {
	_round = _this select 0;
	GVAR(blackList) set[(count GVAR(blackList)), _round];
};

FUNC(addManualTrack) = {
	PARAMS_1(_round);
	if(alive _round) then {
		GVAR(trackedObjects) set[(count GVAR(trackedObjects)), _round];
		[FUNC(trackFragRound), 0, [_round, (getPosASL _round), (velocity _round), (typeOf _round), time]] call cba_fnc_addPerFrameHandler;
	};
};

FUNC(BIS_ARTY_WRAPPER) = {
	_ret = [(_this select 6)] call FUNC(removeTrack);
	if(!_ret) then {
		[(_this select 6)] call FUNC(addBlackList);
	};
	_this call ACE_WRAPPER_BIS_ARTY_F_ShellFlight;
	_catEntry = BIS_ARTY_SHELLCAT select ((count BIS_ARTY_SHELLCAT) - 1);
	_shell = _catEntry select 0;
	_ARTY_DeployOnImpact = getText (configFile >> "CfgAmmo" >> "ARTY_DeployOnImpact");
	if(_ARTY_DeployOnImpact == "") then {
		_this set[6, _shell];
		_this call FUNC(fired);
	};
};

ADDON = true;
