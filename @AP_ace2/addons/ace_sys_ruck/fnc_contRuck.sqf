//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_body", "_magAry", "_wepAry", "_ruckNam", "_bodypos", "_wephld", "_time", "_near", "_count"];

PARAMS_1(_body);
DEFAULT_PARAM(1,_magAry,[]);
DEFAULT_PARAM(2,_wepAry,[]);

if ( _body call FUNC(HasRuck) ) then {
	_this spawn {
		PARAMS_1(_body);
		DEFAULT_PARAM(1,_magAry,[]);
		DEFAULT_PARAM(2,_wepAry,[]);
		TRACE_2("dRuck passed",_magAry,_wepAry);
		_ruckNam = _body call FUNC(FindRuck);
		if ( _ruckNam == "" || {(count _magAry == 0 && {count _wepAry == 0})} ) exitWith {TRACE_1("Empty",_ruckNam);};
		_bodypos = getPosATL _body;
		_wephld = "WEAPONHOLDER" createVehicle _bodypos;
		_wephld setVariable ["ACE_RuckContents", [_magAry,_wepAry], true];
		_time = time + 1800;
		while { !isNull _body && {(_body hasWeapon _ruckNam)} && {(time < _time)} } do {
			//if(isPlayer _body) then {waitUntil{alive player};}; //debug only
			_near = (position _body) nearEntities ["CaManBase", 50];
			_count = {alive _x} count _near;
			TRACE_1("dRuck loop",_count);
			if (_count > 0) then {
				[QGVAR(acsRuck), [_near,_wephld,_ruckNam]] call CBA_fnc_globalEvent;
				TRACE_1("dRuck global",_near);
			};
			sleep 60;
		};
		if (!isNull _wephld) then {deleteVehicle _wephld};
		TRACE_1("Ruck End",_wephld);
	};
};