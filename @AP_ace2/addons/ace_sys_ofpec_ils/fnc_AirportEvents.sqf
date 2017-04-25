
#include "script_component.hpp"
/*
 ofpec_AirportEvents.sqf v1.0
 August 2007 Hoz
*/

#define __display (uiNameSpace getVariable "OFPEC_AirPortSelector")

private ["_lb_index"];

PARAMS_2(_event,_params);

_lb_index = 0;

switch (toUpper _event) do {
	case "ONLOAD": {
		
		GVAR(AirportArray) = [];
		playSound "ofpec_clear";

		_cfgILSP = [];
		_cfgILSD = [];
		_cfgAirP = (configFile >> "cfgWorlds" >> worldName );
		_cfgILSP = getArray (_cfgAirP  >> "ilsPosition");
		_cfgILSD = getArray (_cfgAirP  >> "ilsDirection");
		_cfgName = [_cfgILSP, 2000] call FUNC(ClosestTown);
		if (_cfgName select 0 == "") then {
			_cfgName = [format["%1Airstrip0", worldname],_cfgILSP, _cfgILSD];
	};
		GVAR(AirportArray) set [0, [str(_cfgName select 0), _cfgILSP, _cfgILSD]];
		_cfgAirP = (configFile >> "cfgWorlds" >> WorldName >> "SecondaryAirports");

		for "_i" from 0 to ((Count _cfgAirP)-1) do {
			_k = _i + 1;
			_cfgILSP = getArray (_cfgAirP Select _i >> "ilsPosition");
			_cfgILSD = getArray (_cfgAirP Select _i >> "ilsDirection");
			_cfgName = [_cfgILSP, 2000] call FUNC(ClosestTown);
			if (_cfgName select 0 == "") then {
				_cfgname = [format["%1Airstrip%2", worldname, _k],_cfgILSP, _cfgILSD];
			};
			GVAR(AirportArray) set [_k, [format["%1", (_cfgName select 0)], _cfgILSP, _cfgILSD]];
		};
		for "_i" from 0 to (count GVAR(AirportArray)) - 1 do {
			_lb_index = (__display displayCtrl 108) lbAdd format["%1 - %2km", ((GVAR(AirportArray) select _i) select 0), (player distance ((GVAR(AirportArray) select _i) select 1)) call GVAR(m_to_km)];
		};

		(__display displayCtrl 108) lbSetCurSel 0;
		(__display displayCtrl 108) ctrlSetEventHandler ["LBSelChanged", "[""OFPEC_ASLstChnge"", _this] call ace_ofpec_ils_fnc_airportevents"]; //FUNC(AirportEvents)"];
		(__display displayCtrl 109) ctrlMapAnimAdd [0.01, 1, ((GVAR(AirportArray) select 0) select 1)];
		ctrlMapAnimCommit (__display displayCtrl 109);
	};
	case "OFPEC_ASLSTCHNGE": {
		_itemSelected = (_params select 1);
		(__display displayCtrl 109) ctrlMapAnimAdd [0.01, 1, ((GVAR(AirportArray) select _itemSelected) select 1)];
		ctrlMapAnimCommit (__display displayCtrl 109);
	};
	case "OFPEC_ACTIVATEILS": {
		_itemSelected = lbCurSel (__display displayCtrl 108);
		if (_itemSelected >= 0) then {
			closeDialog 0;
			//GVAR(vehicle) removeAction GVAR(action);
			[GVAR(vehicle), ((GVAR(AirportArray) select _itemSelected) select 0), ((GVAR(AirportArray) select _itemSelected) select 1),((GVAR(AirportArray) select _itemSelected) select 2)] spawn COMPILE_FILE(ofpec_ils);
		};
	};
	case "OFPEC_CLOSESELECTOR": {
		closeDialog 0;
		GVAR(airportevents) = false;
	};
};
