//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_unit", "_body", "_wepvnam", "_bodRuck", "_havRuck", "_ruckDn", "_actNam", "_actID", "_gotRuck", "_cont", "_def"];

PARAMS_3(_near,_wephld,_ruckNam);

if (!isDedicated) then {
	_this spawn {
		PARAMS_3(_near,_wephld,_ruckNam);
		_body = _near select 0;
		if ( alive _body || {isNull _body} || {isNull _wephld} ) exitWith {};
		{
			_unit = _x;
			if ( local _unit && {alive _unit} ) then {
				_wepvnam = _wephld getVariable [name _unit, nil];
				if ( isNil "_wepvnam" && {(_unit in _near)} ) then {
					TRACE_1("dRuck once",_wepvnam);
					_wephld setVariable [name _unit, true];
					_bodRuck = _body hasWeapon _ruckNam;
					while {((_unit distance _body) < 50) && {_bodRuck} && {!isNull _body} && {!isNull _wephld}}  do {
						waitUntil{sleep 5; ( ((_unit distance _body) < 5) || {!(_body hasWeapon _ruckNam)} )};
						_havRuck = _unit call FUNC(HasRuck);
						TRACE_1("dRuck addAct",_havRuck);
						_ruckDn = getText(configfile >> "cfgWeapons" >> _ruckNam >> "displayName");
						_actNam = format[localize "STR_ACE_SYS_RUCK_OPEN",_ruckDn];
						_actID = _unit addAction [_actNam, QPATHTO_F(act_opnRuck), [_wephld,_body,_ruckNam], 1, false, true, "", ""];
						waitUntil{sleep 5; _gotRuck = (!_havRuck && (_unit call FUNC(HasRuck))); ( ((_unit distance _body) > 5) || {_gotRuck} || {isNull _wephld} )};
						_unit removeAction _actID;
						_gotRuck = (!_havRuck && (_unit call FUNC(HasRuck)));
						_bodRuck = (_body hasWeapon _ruckNam);
						TRACE_3("dRuck remAct",_actID,_gotRuck,_bodRuck);
						if( _gotRuck && {!_bodRuck} ) then {
							_cont = _wephld getVariable ["ACE_RuckContents",[[],[]]];
							deleteVehicle _wephld;
							_unit setVariable ["ACE_RuckMagContents",(_cont select 0)];
							_unit setVariable ["ACE_RuckWepContents",(_cont select 1)];
							TRACE_1("dRuck taken",_cont);
						};
					};
					_wephld setVariable [(name _unit),nil];
				};
			};
		} forEach _near;
	};
};