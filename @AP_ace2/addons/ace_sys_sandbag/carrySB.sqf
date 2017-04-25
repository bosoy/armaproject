/* ace_sys_sandbag (.pbo) | (c) 2009 by rocko */

#include "script_component.hpp"

#define __fConfirmed _unit getVariable QGVAR(confirmed)
#define __fCancelled _unit getVariable QGVAR(cancelled)
#define ACE_TEXT_RED(Text) ("<t color='#FF0000'>" + ##Text + "</t>")
#define ACE_TEXT_SILVER(Text) ("<t color='#C0C0C0'>" + ##Text + "</t>")

//closeDialog 0;

private ["_SB", "_unit", "_busy", "_ACE_confirmDeploySB", "_confirmSB", "_ACE_cancelDeploySB", "_worldPos", "_dir", "_pb", "_car"];

_SB = _this;
_unit = player;

_busy = _unit getVariable [QGVAR(busy), false];

if(!_busy) then {
	_confirmSB = "ACE_Sandbag_NoGeo" createVehicleLocal [0, 0, 0];

	// Default placement script
	GVAR(OffsetZ) = (getPos player) select 2; // Always on player height - to be changed
	GVAR(DiffZ) = (getPos player) select 2; // not to be changed and used as reference
	GVAR(dir) = 0;

	_unit setVariable [QGVAR(busy), true];
	_unit setVariable [QGVAR(prebusy), true];
	_unit setVariable [QGVAR(confirmed), false];
	_unit setVariable [QGVAR(cancelled), false];

	_ACE_confirmDeploySB = _unit addAction [ACE_TEXT_SILVER(localize "STR_ACE_AC_DROP"), QPATHTO_F(confirmSBdeploy), [_confirmSB], -8]; // Erneut ablegen
	_ACE_cancelDeploySB = _unit addAction [ACE_TEXT_RED(localize "STR_ACE_AC_ENDCARRYSB"), QPATHTO_F(cancelSBdeploy), [], -9]; // Tragen beenden

	call GVAR(key_add);
	deleteVehicle _SB;

	while { !(__fConfirmed) && {!(__fCancelled)} && {alive _unit}} do {
		if (!(alive _confirmSB) && {_unit getVariable QGVAR(exploit)} ) then {
			_confirmSB = "ACE_Sandbag_NoGeo" createVehicleLocal [0, 0, 0];
			_unit removeAction _ACE_confirmDeploySB;
			_ACE_confirmDeploySB = _unit addAction [ACE_TEXT_SILVER(localize "STR_ACE_AC_DROP"), QPATHTO_F(confirmSBdeploy), [_confirmSB], -8];
		};
		_worldPos = _unit modelToWorld ([0, 1 + (_unit weaponDirection primaryWeapon _unit select 2) * 0.4,GVAR(OffsetZ)]);
		_confirmSB setPos [_worldPos select 0,_worldPos select 1,(_worldpos select 2)];
		_confirmSB setDir GVAR(dir);
		sleep .25;
	};

	call GVAR(key_rem);

	deleteVehicle _confirmSB;
	_unit removeAction _ACE_confirmDeploySB;
	_unit removeAction _ACE_cancelDeploySB;
	if (__fCancelled || !(alive _unit)) exitWith {
		_unit setVariable [QGVAR(confirmed), nil];
		_unit setVariable [QGVAR(cancelled), nil];
		_unit setVariable [QGVAR(busy), false];
		_unit setVariable [QGVAR(prebusy), false];

		// Aborted Carrying:
		_SB = "ACE_Sandbag_Build" createVehicle [0, 0, 0];
		_SB setPos (_unit modelToWorld [0,0,0]);
		_SB setDir (getDir player);
		player reveal _SB;
	};
	_unit setVariable [QGVAR(confirmed), nil];
	_unit setVariable [QGVAR(cancelled), nil];
	_dir = getDir _unit;

	[1,[],true,true] spawn ace_progressbar;

	waitUntil { (player getVariable "ACE_PB_Result" != 0) };

	if (player getVariable "ACE_PB_Result" == 1) then {
		_SB = "ACE_Sandbag_Build" createVehicle [0, 0, 0];
		_place_pos = player getVariable QGVAR(place_pos);
		_worldPos = [(_place_pos select 0), (_place_pos select 1), GVAR(OffsetZ)];
		_SB setPos [(_worldPos select 0),(_worldPos select 1),(_worldPos select 2)];
		_SB setDir GVAR(dir);
		_unit reveal _SB;
		_unit setVariable [QGVAR(busy), false];
		_unit setVariable [QGVAR(prebusy), false];
		GVAR(OffsetZ) = 0;

		_SB spawn {
			private["_SB","_car","_dir"];
			sleep 1;
			_SB = _this;
			_dir = getDir _SB;
			if ( ((getPos _SB) select 2 < 0.5) ) exitWith {};
			_car = nearestObject [_SB, "LandVehicle"];
			if (isNull _car) exitWith {};
			if ((_SB distance _car) > 7)  exitWith { _SB setpos (getPos player); };
			_SB attachTo [_car,[(_car worldToModel (getPos _SB)) select 0,(_car worldToModel (getPos _SB)) select 1,((_car worldToModel (getPos _SB)) select 2) + 0.05],""];
			_SB setDir GVAR(dir);
			player reveal _SB;
		};
	};
	if (player getVariable "ACE_PB_Result" != 1) then {
		_unit setVariable [QGVAR(confirmed), nil];
		_unit setVariable [QGVAR(cancelled), nil];
		_unit setVariable [QGVAR(busy), false];
		_unit setVariable [QGVAR(prebusy), false];
		GVAR(OffsetZ) = 0;
		// Start over
		objNull spawn COMPILE_FILE(carrySB);
	};
};