#include "script_component.hpp"
#include "Script_SightAdjustmentConfig.hpp"
#define __dsp (uiNameSpace getVariable "ACE_SYS_SA_RIFLE_RSC")
#define __ctrl __dsp displayCtrl 2
#define __dspnil isNil {uiNameSpace getVariable "ACE_SYS_SA_RIFLE_RSC"}

private ["_exit","_range","_table","_el","_wnd","_key","_v","_step","_max","_min","_cnt","_new"];
_key = _this select 1;
_exit = false;
if !(isNull (findDisplay 30830) && {isNull (findDisplay 30831)} && {isNull (findDisplay 30832)}) exitwith {};

if (_key in [0,1]) then { //elev or range
	if (ACE_SYS_SA_RFL_WCFG_ADJMODE == "range") then { //range settings
		_el = ACE_SYS_SA_RFL_CURELEVATION;
		_table = ACE_SYS_SA_RFL_WCFG_TABLE;
		_range = 0;
		_cnt = count _table;
		_new = [];
		for "_i" from 0 to (_cnt - 1) do {
			_cur = _table select _i;
			if ((_cur select 1) == _el) exitwith {
				_range = _cur select 0;
				if (_key == 0) then	{ //range up
					_max = ACE_SYS_SA_RFL_WCFG_MAXELEVATION;
					if (_i < _cnt-1) then {
						if ((_table select (_i+1)) select 0 <= _max) then {
							_new = _table select (_i+1); //[next range,next elev]
						};
					};
				} else { //range down
					_min = ACE_SYS_SA_RFL_WCFG_MINELEVATION;
					if (_i > 0) then {
						if ((_table select (_i-1)) select 0 >= _min) then {
							_new = _table select (_i-1); //[prev rng,prev elev]
						};
					};
				};
			};
		};
		if (count _new == 2) then {
			if (cameraview != "GUNNER") then {
				switch (true) do {
					case (__dspnil): {
						13533 cutRsc ["ACE_SYS_SA_RIFLE_RSC","PLAIN",0];
						__ctrl ctrlSetText format["%1 %2",_range,(call FUNC(findunittext)) select 2];
						_exit = true;
					};
					case (isNull __dsp): {
						13533 cutRsc ["ACE_SYS_SA_RIFLE_RSC","PLAIN",0];
						__ctrl ctrlSetText format["%1 %2",_range,(call FUNC(findunittext)) select 2];
						_exit = true;
					};
					default {
						13533 cutRsc ["ACE_SYS_SA_RIFLE_RSC","PLAIN",0];
						__ctrl ctrlSetText format["%1 %2",_new select 0,(call FUNC(findunittext)) select 2];
					};
				};
			} else {
				13533 cutRsc ["Default", "PLAIN",0];
			};
			if (_exit) exitwith {};
			playsound "ace_sadj_click";
			_new = _new select 1;
			ACE_SYS_SA_RFL_SET_CURELEVATION(_new);
			call FUNC(setDegrees_local);
			{
				if (ACE_SYS_SA_RFL_CURWEAPON == _x select 0) exitwith {
					_x set [1,ACE_SYS_SA_RFL_CURELEVATION];
				};
			} foreach ACE_SYS_SA_RFL_WPN_LIST;
			call FUNC(syncbuffer);
		};
	} else { //elev settings
			_el = ACE_SYS_SA_RFL_CURELEVATION;
			_step = ACE_SYS_SA_RFL_WCFG_ADJELEVATION;
			_el = [_el,_step] call FUNC(roundNumber);
			_new = _el;
			switch (_key) do {
				case 0:	{ //up
					_max = ACE_SYS_SA_RFL_WCFG_MAXELEVATION;
					if (_el+_step <= _max) then {
						_new = _el + _step;
					};
				};
				case 1:	{ //down
					_min = ACE_SYS_SA_RFL_WCFG_MINELEVATION;
					if (_el-_step >= _min) then {
						_new = _el-_step;
					};
				};
			};
			if (_new != _el) then {
				if (cameraview != "GUNNER") then {
					switch (true) do {
						case (__dspnil): {
							13533 cutRsc ["ACE_SYS_SA_RIFLE_RSC","PLAIN",0];
							__ctrl ctrlSetText format["%1 %2",_el,(call FUNC(findunittext)) select 0];
							_exit = true;
						};
						case (isNull __dsp): {
							13533 cutRsc ["ACE_SYS_SA_RIFLE_RSC","PLAIN",0];
							__ctrl ctrlSetText format["%1 %2",_el,(call FUNC(findunittext)) select 0];
							_exit = true;
						};
						default {
							13533 cutRsc ["ACE_SYS_SA_RIFLE_RSC","PLAIN",0];
							__ctrl ctrlSetText format["%1 %2",_new,(call FUNC(findunittext)) select 0];
						};
					};
				} else {
					13533 cutRsc ["Default", "PLAIN",0];
				};
				if (_exit) exitwith {};
				playsound "ace_sadj_click";
				ACE_SYS_SA_RFL_SET_CURELEVATION(_new);
				call FUNC(setDegrees_local);
				{
					if (ACE_SYS_SA_RFL_CURWEAPON == _x select 0) exitwith {
						_x set [1,ACE_SYS_SA_RFL_CURELEVATION];
					};
				} foreach ACE_SYS_SA_RFL_WPN_LIST;
				call FUNC(syncbuffer);
			};
	};
} else { //windage
	_wnd = ACE_SYS_SA_RFL_CURWINDAGE;
	_max = ACE_SYS_SA_RFL_WCFG_MAXWINDAGE;
	_step = ACE_SYS_SA_RFL_WCFG_ADJWINDAGE;
	_wnd = [_wnd,_step] call FUNC(roundNumber);
	_new = _wnd;
	switch (_key) do {
		case 2:	{ //left
			if (_wnd-_step >= - _max) then {
				_new = _wnd - _step;
			};
		};
		case 3:	{ //right
			if (_wnd+_step <= _max) then {
				_new = _wnd + _step;
			};
		};
	};
	if (_new != _wnd) then {
		if (cameraview != "GUNNER") then {
			switch (true) do {
				case (__dspnil): {
					13533 cutRsc ["ACE_SYS_SA_RIFLE_RSC","PLAIN",0];
					__ctrl ctrlSetText format["%1 %2",_wnd,(call FUNC(findunittext)) select 1];
					_exit = true;
				};
				case (isNull __dsp): {
					13533 cutRsc ["ACE_SYS_SA_RIFLE_RSC","PLAIN",0];
					__ctrl ctrlSetText format["%1 %2",_wnd,(call FUNC(findunittext)) select 1];
					_exit = true;
				};
				default {
					13533 cutRsc ["ACE_SYS_SA_RIFLE_RSC","PLAIN",0];
					__ctrl ctrlSetText format["%1 %2",_new,(call FUNC(findunittext)) select 1];
				};
			};
		} else {
			//	13533 cutRsc ["Default", "PLAIN",0];
		};
		if (_exit) exitwith {};
		playsound "ace_sadj_click";
		ACE_SYS_SA_RFL_SET_CURWINDAGE(_new);
		call FUNC(setDegrees_local);
		{
			if (ACE_SYS_SA_RFL_CURWEAPON == _x select 0) exitwith {
				_x set [2,ACE_SYS_SA_RFL_CURWINDAGE];
			};
		} foreach ACE_SYS_SA_RFL_WPN_LIST;
		call FUNC(syncbuffer);
	};
};