/*
Created by Vadim Shchemelinin aka badger
2010 St.Petersburg

Script for BMD-2 by RHS

_habarScr = [this,type,setting,config] execVM "bgr_bmd_habar.sqf";
type = 0  -  all off
type = 1  -  all on
type = 2  -  random
type = 3  -  castom

setting = [#,#,#,#,#,#,"left"] //ONLY IF type = 3 !!!
[1,0,0,0,1,0,"back"]
1 - ящик ЕСТЬ
0 - ящика НЕТ
(сначала левый борт, потом правый)
"back" - бревно сзади
"left" - бревно слева
"none" - бревна нет

config = true - running from config

Example for config init:
_habarScr = [_this,2,true] execVM "bgr_bmd_habar.sqf";

Example for mission init or mission script:
_habarScr = [this] execVM "bgr_bmd_habar.sqf";	//random
or:
_habarScr = [this,1] execVM "bgr_bmd_habar.sqf";	//all ON
or:
_habarScr = [this,3,[1,0,0,0,1,0,"back"]] execVM "bgr_bmd_habar.sqf";
*/

private ["_bmd","_type","_setting","_config","_str"];

if (!isServer) exitWith {};
//_tochka animate ["USSR_SS21_luk_levy",1];
//_tochka setVariable ["lanchStatus", 3, true];
_bmd = _this select 0;
_type = if (count _this > 1) then {_this select 1} else {2};
_setting = if ((count _this > 2)and(_type == 3)) then {_this select 2} else {[]};
_config = if (((count _this > 3)and(_type == 3))or((count _this > 2)and(_type != 3))) then {_this select 3} else {false};

if (_config) then { //перед установкой дефолта нужно проверить не выставил ли пользователь свои установки
	if (!isnil (_bmd getVariable "habar_set")) exitWith{}; //выходим если пользователь уже установил чтото своё
};

switch (_type) do {
	case 0: {	//всё выкл
		_setting = [1,1,1,1,1,1,"none"];
	};
	case 1: {	//всё вкл
		if ((random 10) > 5) then {
			_str = "left";
		} else {
			_str = "back";
		};
		_setting = [0,0,0,0,0,0,_str];
	};
	case 3: {	//пользовательская настройка
		if (count _setting < 7) then {	//проверка на "малоли забыли"
			_setting = [1,1,1,1,1,1,"none"];
		};
		_setting = [(1-(_setting select 0)),
					(1-(_setting select 1)),
					(1-(_setting select 2)),
					(1-(_setting select 3)),
					(1-(_setting select 4)),
					(1-(_setting select 5)),
					_setting select 6];
	};
	default {	//рандом
		if ((random 10) > 6.66) then {
			_str = "back";
		} else {
			if ((random 10) > 5) then {
				_str = "left";
			} else {
				_str = "none";
			};
		};
		_setting = [(floor (random 2)),
					(floor (random 2)),
					(floor (random 2)),
					(floor (random 2)),
					(floor (random 2)),
					(floor (random 2)),
					_str];
	};
};
_bmd setVariable ["habar_set", _setting, true];
_bmd animate ["crate_l1_unhide",(_setting select 0)];
_bmd animate ["crate_l2_unhide",(_setting select 1)];
_bmd animate ["crate_l3_unhide",(_setting select 2)];
_bmd animate ["crate_r1_unhide",(_setting select 3)];
_bmd animate ["crate_r2_unhide",(_setting select 4)];
_bmd animate ["crate_r3_unhide",(_setting select 5)];
switch (_setting select 6) do {
	case "back": {
		_bmd animate ["wood_1_unhide",0];
		_bmd animate ["wood_2_unhide",1];
	};
	case "left": {
		_bmd animate ["wood_1_unhide",1];
		_bmd animate ["wood_2_unhide",0];
	};
	default {
		_bmd animate ["wood_1_unhide",1];
		_bmd animate ["wood_2_unhide",1];
	};
};