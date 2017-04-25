/* ace_sys_gas (.pbo) | (c) 2008, 2009 by rocko */

#include "script_component.hpp"

private["_gas_time"];

#define __teargas (_this select 6)
#define __vel ((velocity __teargas) call ACE_fnc_magnitude)

_pos = getPosATL __teargas;
_range = getNumber(configFile >> "CfgAmmo" >> (_this select 4) >> "ACE" >> "ACE_GAS" >> "range");
_ttl = getNumber(configFile >> "CfgAmmo" >> (_this select 4) >> "timeToLive");
_sleep_build = getNumber(configFile >> "CfgAmmo" >> (_this select 4) >> "ACE" >> "ACE_GAS" >> "buildtime");
_sleep_ingest = getNumber(configFile >> "CfgAmmo" >> (_this select 4) >> "ACE" >> "ACE_GAS" >> "ingestiontime");
while { alive __teargas && {!isNull __teargas} } do {
	_pos = getPos __teargas;
	sleep .05;
	if (__vel < 0.2) exitWith {};
};

sleep (_sleep_build max 1);

_trigger = createTrigger ["EmptyDetector", [0, 0]];
if (alive __teargas) then { _pos = getPos __teargas };
_trigger setPos _pos;
_trigger setTriggerArea [_range, _range, 0, false]; // round trigger, dont care for gas spreadism
_trigger setTriggerActivation ["ANY", "PRESENT", true];
_trigger setTriggerStatements ["this", "", ""];

sleep 2;

_t = time;
_gas_time = 1;

while { time < (_t + _ttl) } do {
	{
		TRACE_1("First instance","");
		if ((_x isKindOf "Man") && {(local _x)} && {alive _x}) then {
			_x setVariable ["ace_gassed",false,false];
			TRACE_1("Unit in trigger",_x);
			_hasMask = _x getVariable ["ACE_Identity", ""];
			TRACE_1("Identity", _hasMask);
			if (_hasMask in ["ACE_GlassesGasMask_US","ACE_GlassesGasMask_RU","ACE_GlassesGasMask2_US","ACE_GlassesGasMask_S10"]) then { _hasMask = true; } else { _hasMask = false; };
			if (player == _x) then {if (ace_sys_spectator_SPECTATINGON) then {_hasMask = true}};
			if (!_hasMask) then {
				TRACE_1("Unit received damage","");
				TRACE_1("Running FX on unit","");
				if (_x == player) then { [_x,2] spawn FUNC(fx); } else { [_x,1] spawn FUNC(fx_server); };
				_gas_time = _gas_time + 1;					// Attempt: If player is inside gas cloud for more than 3 seconds and then puts on his gasmask, he is also affected by gas
				_x setVariable ["ace_gas_time", _gas_time, false];
			};
			sleep 1;
			if ( !(isPlayer _x) && {isServer} ) then { _x doMove [((getpos _x) select 0) + ((sin (random 360))*45),((getpos _x) select 1) + ((cos (random 360))*45),0]; }; // AI run away from gas
			TRACE_1("Gas time set and counted", (_x getVariable "ace_gas_time"));
		};
	} foreach list _trigger;

	sleep (_sleep_ingest + random 3);
};
deleteVehicle _trigger;
