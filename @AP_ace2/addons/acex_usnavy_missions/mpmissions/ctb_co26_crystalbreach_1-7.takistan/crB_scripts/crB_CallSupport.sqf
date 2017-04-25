//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [CTB]
// Created: 20100815
// Contact: http://creobellum.org
// Purpose: Call in AI Support vehicles
///////////////////////////////////////////////////////////////////

// CLIENT TRIGGER actions
//- trigger action
//- check if enroute/notify
//- hint to map pos

private["_unit", "_args", "_veh", "_name"];
_unit = _this select 1;
_args = _this select 3;
_veh = _args select 0;
_name = _args select 1;

hint format["%1 - click on the map to call in %2", name _unit, _name];
[_unit, _veh, _name] onMapSingleClick {
	private["_unit", "_veh", "_name"];
	_unit = _this select 0;
	_veh = _this select 1;
	_name = _this select 2;

	callSupport = [_unit, _veh, _pos, _name];
	publicVariable "callSupport";
	callSupport spawn fc_callSupport;
	callSupport spawn fs_callSupport;

	hint "";
	onMapSingleClick {};
};

