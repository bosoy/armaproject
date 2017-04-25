// by Xeno
#define THIS_FILE "x_markercheck.sqf"
#include "x_setup.sqf"
private ["_val", "_pvar_name", "_body"];
if (!isServer) exitWith {};

_pvar_name = _this;

_val = GV2(GVAR(placed_objs_store),_pvar_name);
if (!isNil "_val") then {
	{
		[QGVAR(r_delm), _x select 1] call FUNC(NetCallEvent);
		if (!isNull (_x select 0)) then {
			_farpsar = __XJIPGetVar(GVAR(farps)); 
			_cof = count _farpsar;
			_farpsar = _farpsar - [_x];
			if (_cof != count _farpsar) then {
				__XJIPSetVar [QGVAR(farps), _farpsar, true];
			};
			deleteVehicle (_x select 0);
		};
	} forEach _val;
	GVAR(placed_objs_store) setVariable [_pvar_name, nil];
};

_val = GV2(GVAR(placed_objs_store2),_pvar_name);
if (!isNil "_val") then {
	{if (!isNull _x) then {deleteVehicle _x}} forEach _val;
	GVAR(placed_objs_store2) setVariable [_pvar_name, nil];
};

_body = __getMNsVar2(_pvar_name);
if (!isNil "_body") then {
	// cleanup later
	if (!isNull _body) then {__addDeadAI(_unit)};
};