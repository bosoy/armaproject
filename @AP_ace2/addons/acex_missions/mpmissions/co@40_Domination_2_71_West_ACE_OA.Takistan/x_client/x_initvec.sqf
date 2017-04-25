// by Xeno
#define THIS_FILE "x_initvec.sqf"
#include "x_setup.sqf"
#define __vecmarker _mxname = _car select 2; \
if (str(markerPos _mxname) == "[0,0,0]") then { \
[_mxname, getPosASL _vec,"ICON",_car select 4,[1,1],_mt,0,_car select 3] call FUNC(CreateMarkerLocal);\
} else { \
_mxname setMarkerPosLocal (getPosASL _vec); \
}; \
_vec setVariable [QGVAR(marker), _mxname];\
GVAR(marker_vecs) set [count GVAR(marker_vecs), _vec];

#define __chopmarker _mxname = _car select 2; \
if (str(markerPos _mxname) == "[0,0,0]") then { \
[_mxname, getPosASL _vec,"ICON",_car select 5,[1,1],_car select 6,0,_car select 4] call FUNC(CreateMarkerLocal);\
} else { \
_mxname setMarkerPosLocal (getPosASL _vec); \
}; \
_vec setVariable [QGVAR(marker), _mxname];\
GVAR(marker_vecs) set [count GVAR(marker_vecs), _vec];\
if (count _car > 8) then {_vec setVariable [QGVAR(lift_types), _car select 8]}

#define __chopset _index = _car select 1;\
_vec setVariable [QGVAR(choppertype), _index];\
_vec setVariable [QGVAR(vec_type), "chopper"];\
switch (_index) do {\
	case 0: {_vec addEventHandler ["getin", {[_this,0] call FUNC(checkhelipilot)}]};\
	case 1: {_vec addEventHandler ["getin", FUNC(checkhelipilot_wreck)]};\
	case 2: {_vec addEventHandler ["getin", {[_this,1] call FUNC(checkhelipilot)}]};\
};\
_vec addEventHandler ["getout", FUNC(checkhelipilotout)]

#define __sidew _vec setVariable [QGVAR(side), west]
#define __sidee _vec setVariable [QGVAR(side), east]
#define __vecname _vec setVariable [QGVAR(vec_name), _car select 6]
#define __chopname _vec setVariable [QGVAR(vec_name), _car select 7]
#define __checkenterer _vec addEventHandler ["getin", FUNC(checkenterer)]
#define __pvecs {if ((_x select 1) == _d_vec) exitWith {_car = _x}} forEach GVAR(p_vecs)
#define __pvecss(sname) {if ((_x select 1) == _d_vec) exitWith {_car = _x}} forEach d_p_vecs_##sname

#define __staticl \
_vec addAction[(localize "STR_DOM_MISSIONSTRING_256") call FUNC(GreyText),"scripts\load_static.sqf",_d_vec,-1,false];\
_vec addAction[(localize "STR_DOM_MISSIONSTRING_257") call FUNC(RedText),"scripts\unload_static.sqf",_d_vec,-1,false]

#define __addchopm _vec addAction [(localize "STR_DOM_MISSIONSTRING_258") call FUNC(GreyText),"x_client\x_vecdialog.sqf",[],-1,false]
#define __halo _vec addAction [(localize "STR_DOM_MISSIONSTRING_259") call FUNC(GreyText),"x_client\x_halo.sqf",[],-1,false,true,"","vehicle player != player && ((vehicle player) call d_fnc_GetHeight) > 50"]

private "_vec";

_vec = _this;

private "_desm";
_desm = GV(_vec,GVAR(deserted_marker));
if (!isNil "_desm") then {
	if (_desm != "") then {
		[_desm, getPosASL _vec,"ICON","ColorBlack",[1,1], format [(localize "STR_DOM_MISSIONSTRING_260"), [typeOf _vec, 0] call FUNC(GetDisplayName)],0,"Dot"] call FUNC(CreateMarkerLocal);
	};
};

_d_vec = GV(_vec,GVAR(vec));
if (isNil "_d_vec") exitWith {};

if (!isNil {GV(_vec,GVAR(vcheck))}) exitWith {};
_vec setVariable [QGVAR(vcheck), true];

if (_d_vec < 10) exitWith {
	_car = [];
#ifndef __TT__
	__pvecs;
#else
	__pvecss(west);
#endif
	if (count _car > 0) then {
		__mNsSetVar [_car select 0, _vec];
		if (!alive _vec) exitWith {};
#ifdef __ACE__
		if (!(if (!isNil {GV(_vec,ace_canmove)}) then {_vec call ace_v_alive} else {true})) exitWith {};
#endif
#ifdef __TT__
		if (GVAR(player_side) == west) then {
#endif
		_mt = _car select 5;
		if (!isNil {GV(_vec,GVAR(MHQ_Deployed))}) then {
			if (GV(_vec,GVAR(MHQ_Deployed))) then {
				_mt = format [(localize "STR_DOM_MISSIONSTRING_261"), _mt];
			};
		};
		if (str(markerPos (_car select 2)) != "[0,0,0]") then {
			(_car select 2) setMarkerTextLocal _mt;
		};
		__vecmarker;
		_vec setVariable [QGVAR(marker_text), _car select 5];
#ifdef __TT__
		};
#endif
		__vecname;
	};
	if (!alive _vec) exitWith {};
#ifdef __ACE__
	if (!(if (!isNil {GV(_vec,ace_canmove)}) then {_vec call ace_v_alive} else {true})) exitWith {};
#endif
#ifdef __TT__
	if (GVAR(player_side) == west) then {
#endif
	_vec addAction [(localize "STR_DOM_MISSIONSTRING_262") call FUNC(GreyText),"x_client\x_vecdialog.sqf",_d_vec,-1,false];
#ifdef __TT__
	};
#endif
	_vec setVariable [QGVAR(vec_type), "MHQ"];
#ifdef __TT__
	_vec addEventHandler ["getin", FUNC(checkdriver)];
	__sidew;
#endif
	_vec setAmmoCargo 0;
};

if (_d_vec < 20) exitWith {
	_car = [];
#ifndef __TT__
	__pvecs;
#else
	__pvecss(west);
#endif
	if (count _car > 0) then {
		__mNsSetVar [_car select 0, _vec];
		if (!alive _vec) exitWith {};
#ifdef __TT__
		if (GVAR(player_side) == west) then {
#endif
		_mt = _car select 5;
		__vecmarker;
#ifdef __TT__
		};
#endif
		__vecname;
	};
	if (!alive _vec) exitWith {};
#ifdef __ACE__
	if (!(if (!isNil {GV(_vec,ace_canmove)}) then {_vec call ace_v_alive} else {true})) exitWith {};
#endif
#ifdef __TT__
	__sidew;
	__checkenterer;
#endif
	_vec setAmmoCargo 0;
};

if (_d_vec < 30) exitWith {
	_car = [];
#ifndef __TT__
	__pvecs;
#else
	__pvecss(west);
#endif
	if (count _car > 0) then {
		__mNsSetVar [_car select 0, _vec];
		if (!alive _vec) exitWith {};
#ifdef __ACE__
		if (!(if (!isNil {GV(_vec,ace_canmove)}) then {_vec call ace_v_alive} else {true})) exitWith {};
#endif
#ifdef __TT__
		if (GVAR(player_side) == west) then {
#endif
		_mt = _car select 5;
		__vecmarker;
#ifdef __TT__
		};
#endif
		__vecname;
	};
	if (!alive _vec) exitWith {};
#ifdef __ACE__
	if (!(if (!isNil {GV(_vec,ace_canmove)}) then {_vec call ace_v_alive} else {true})) exitWith {};
#endif
#ifdef __TT__
	__sidew;
	__checkenterer;
#endif
	_vec setAmmoCargo 0;
};

if (_d_vec < 40) exitWith {
	_car = [];
#ifndef __TT__
	__pvecs;
#else
	__pvecss(west);
#endif
	if (count _car > 0) then {
		__mNsSetVar [_car select 0, _vec];
		if (!alive _vec) exitWith {};
#ifdef __ACE__
		if (!(if (!isNil {GV(_vec,ace_canmove)}) then {_vec call ace_v_alive} else {true})) exitWith {};
#endif
#ifdef __TT__
		if (GVAR(player_side) == west) then {
#endif
		_mt = _car select 5;
		__vecmarker;
#ifdef __TT__
		};
#endif
		__vecname;
	};
	if (!alive _vec) exitWith {};
#ifdef __ACE__
	if (!(if (!isNil {GV(_vec,ace_canmove)}) then {_vec call ace_v_alive} else {true})) exitWith {};
#endif
#ifndef __TT__
	if (GVAR(with_ai) || GVAR(with_ai_features) == 0 || GVAR(string_player) in GVAR(is_engineer)) then {
#else
	if (GVAR(string_player) in GVAR(is_engineer) && GVAR(player_side) == west) then {
#endif
		__staticl;
	} else {
		_vec addEventHandler ["getin", FUNC(checktrucktrans)];
	};
	_vec setVariable [QGVAR(vec_type), "Engineer"];
#ifdef __TT__
	__sidew;
#endif
	_vec setAmmoCargo 0;
};

if (_d_vec < 50) exitWith {
	_car = [];
#ifndef __TT__
	__pvecs;
#else
	__pvecss(west);
#endif
	if (count _car > 0) then {
		__mNsSetVar [_car select 0, _vec];
		if (!alive _vec) exitWith {};
#ifdef __ACE__
		if (!(if (!isNil {GV(_vec,ace_canmove)}) then {_vec call ace_v_alive} else {true})) exitWith {};
#endif
#ifdef __TT__
		if (GVAR(player_side) == west) then {
#endif
		_mt = _car select 5;
		__vecmarker;
#ifdef __TT__
		};
#endif
		__vecname;
	};
	if (!alive _vec) exitWith {};
#ifdef __ACE__
	if (!(if (!isNil {GV(_vec,ace_canmove)}) then {_vec call ace_v_alive} else {true})) exitWith {};
#endif
#ifdef __TT__
	__sidew;
	__checkenterer;
#endif
	_vec setAmmoCargo 0;
};

#ifdef __TT__
if (_d_vec < 110) exitWith {
	_car = [];
	__pvecss(east);
	_eeit = false;
	if (count _car > 0) then {
		__mNsSetVar [_car select 0, _vec];
		if (!alive _vec) exitWith {};
		if (__ACEVer) then {
			if (!(if (!isNil {GV(_vec,ace_canmove)}) then {_vec call ace_v_alive} else {true})) then {_eeit = true};
		};
		if (_eeit) exitWith {};
		if (GVAR(player_side) == east) then {
			_mt = _car select 5;
			if (!isNil {GV(_vec,GVAR(MHQ_Deployed))}) then {
				if (GV(_vec,GVAR(MHQ_Deployed))) then {
					_mt = format [(localize "STR_DOM_MISSIONSTRING_261"), _mt];
				};
			};
			if (str(markerPos (_car select 2)) != "[0,0,0]") then {
				(_car select 2) setMarkerTextLocal _mt;
			};
			__vecmarker;
			_vec setVariable [QGVAR(marker_text), _car select 5];
		};
		__vecname;
	};
	if (!alive _vec) exitWith {};
	if (_eeit) exitWith {};
	if (GVAR(player_side) == east) then {
		_vec addAction [(localize "STR_DOM_MISSIONSTRING_262") call FUNC(GreyText),"x_client\x_vecdialog.sqf",_d_vec,-1,false];
	};
	_vec setVariable [QGVAR(vec_type), "MHQ"];
	__sidee;
	_vec addEventHandler ["getin", FUNC(checkdriver)];
	_vec setAmmoCargo 0;
};

if (_d_vec < 120) exitWith {
	_car = [];
	__pvecss(east);
	_eeit = false;
	if (count _car > 0) then {
		__mNsSetVar [_car select 0, _vec];
		if (!alive _vec) exitWith {};
		if (__ACEVer) then {
			if (!(if (!isNil {GV(_vec,ace_canmove)}) then {_vec call ace_v_alive} else {true})) then {_eeit = true};
		};
		if (_eeit) exitWith {};
		if (GVAR(player_side) == east) then {
			_mt = _car select 5;
			__vecmarker;
		};
		__vecname;
	};
	if (!alive _vec) exitWith {};
	if (_eeit) exitWith {};
	__sidee;
	__checkenterer;
	_vec setAmmoCargo 0;
};

if (_d_vec < 130) exitWith {
	_car = [];
	__pvecss(east);
	_eeit = false;
	if (count _car > 0) then {
		__mNsSetVar [_car select 0, _vec];
		if (!alive _vec) exitWith {};
		if (__ACEVer) then {
			if (!(if (!isNil {GV(_vec,ace_canmove)}) then {_vec call ace_v_alive} else {true})) then {_eeit = true};
		};
		if (_eeit) exitWith {};
		if (GVAR(player_side) == east) then {
			_mt = _car select 5;
			__vecmarker;
		};
		__vecname;
	};
	if (!alive _vec) exitWith {};
	if (_eeit) exitWith {};
	__sidee;
	__checkenterer;
	_vec setAmmoCargo 0;
};

if (_d_vec < 140) exitWith {
	_car = [];
	__pvecss(east);
	_eeit = false;
	if (count _car > 0) then {
		__mNsSetVar [_car select 0, _vec];
		if (!alive _vec) exitWith {};
		if (__ACEVer) then {
			if (!(if (!isNil {GV(_vec,ace_canmove)}) then {_vec call ace_v_alive} else {true})) then {_eeit = true};
		};
		if (_eeit) exitWith {};
		if (GVAR(player_side) == east) then {
			_mt = _car select 5;
			__vecmarker;
		};
		__vecname;
	};
	if (!alive _vec) exitWith {};
	if (_eeit) exitWith {};
	if (GVAR(string_player) in GVAR(is_engineer) && GVAR(player_side) == east) then {
		__staticl;
	};
	_vec setVariable [QGVAR(vec_type), "Engineer"];
	__sidee;
	_vec addEventHandler ["getin", FUNC(checktrucktrans)];
	_vec setAmmoCargo 0;
};

if (_d_vec < 150) exitWith {
	_car = [];
	__pvecss(east);
	_eeit = false;
	if (count _car > 0) then {
		__mNsSetVar [_car select 0, _vec];
		if (!alive _vec) exitWith {};
		if (__ACEVer) then {
			if (!(if (!isNil {GV(_vec,ace_canmove)}) then {_vec call ace_v_alive} else {true})) then {_eeit = true};
		};
		if (_eeit) exitWith {};
		if (GVAR(player_side) == east) then {
			_mt = _car select 5;
			__vecmarker;
		};
		__vecname;
	};
	if (_eeit) exitWith {};
	__sidee;
	__checkenterer;
	_vec setAmmoCargo 0;
};
#endif

if (_d_vec < 400) exitWith {
	_car = [];
#ifndef __TT__
	{if ((_x select 3) == _d_vec) exitWith {_car = _x}} forEach GVAR(choppers);
#else
	{if ((_x select 3) == _d_vec) exitWith {_car = _x}} forEach GVAR(choppers_west);
#endif
	if (count _car > 0) then {
		if (!alive _vec) exitWith {};
		__mNsSetVar [_car select 0, _vec];
		__chopname;
#ifdef __TT__
		if (GVAR(player_side) == west) then {
#endif
		__chopmarker;
#ifdef __TT__
		};
#endif
	};
	if (!alive _vec) exitWith {};
#ifdef __TT__
	if (GVAR(player_side) == west) then {
#endif
	__addchopm;
#ifdef __TT__
	};
	__sidew;
#endif
	__chopset;
#ifdef __TT__
	if (GVAR(player_side) == west) then {
#endif
	if !(__ACEVer) then {__halo};
#ifdef __TT__
	};
#endif
};

#ifdef __TT__
if (_d_vec < 500) exitWith {
	_car = [];
	{if ((_x select 3) == _d_vec) exitWith {_car = _x}} forEach GVAR(choppers_east);
	if (count _car > 0) then {
		if (!alive _vec) exitWith {};
		__mNsSetVar [_car select 0, _vec];
		__chopname;
		if (GVAR(player_side) == east) then {__chopmarker};
	};
	if (!alive _vec) exitWith {};
	if (GVAR(player_side) == east) then {__addchopm};
	__chopset;
	if (GVAR(player_side) == east) then {
		if !(__ACEVer) then {__halo};
	};
	__sidee;
};
#endif