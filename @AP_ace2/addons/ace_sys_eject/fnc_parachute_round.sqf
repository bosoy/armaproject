// #define DEBUG_MODE_FULL
#include "script_component.hpp"
#define ACE_TEXT_RED(Text) ("<t color='#FF0000'>" + ##Text + "</t>")

/* Script called for every round parachute at init */

private ["_jumper", "_run", "_pos", "_dead_chute", "_holder", "_fallTime", "_spd", "_local"];

PARAMS_1(_chute);

if (!local _chute) exitWith {};	// More common
if (_chute isKindOf "ACE_HuntIR") exitWith { TRACE_1("HuntIR",_chute); };
if !(_chute isKindOf "ParachuteBase") exitWith { TRACE_1("Not parachute",_chute); };

if (!isNil {_chute getVariable QGVAR(chute_loop)}) exitWith {};	// AI parachutes on eject
_chute setVariable [QGVAR(chute_loop), true];

// Cut-chute for round-parachute may be added in future
//_chute addAction ["Cut chute",QPATHTO_F(fnc_cutchute),[],100,false,false,"Eject"]; //ACE_TEXT_RED(localize "STR_ACE_CUTCHUTE") TODO: localize this

sleep 1;
_pos = [0,0,0];
_spd = 0;
_run = true;
_local = true;
while {_run} do {
	if !(isNull _chute) then {
		_pos = getPosATL _chute;
		_local = local _chute;
		_spd = velocity _chute call ACE_fnc_magnitude;

		if (!isNull driver _chute) then {
			_jumper = driver _chute;
		};
	};
	//player sidechat format ["_chute = %1 -- _jumper = %2",_chute, _jumper];
	if ((getPos _chute select 2 < 2.5) || {!(alive _chute)} || {(isNull _chute)}) then {
	#ifdef DEBUG_MODE_FULL
	_debugMsg = format["Checking Chute for player %1 at ATL:%2 at tickTime:%3",name _jumper, getPosATL _chute, diag_tickTime];
	LOG(_debugMsg);
	#endif
		if !(isNull _jumper) then {
			if (assignedVehicle _jumper == _chute) then {
				unassignVehicle _jumper;
			};
			moveOut _jumper;
			_jumper removeWeapon "ACE_ParachuteRoundPack";
			waitUntil {
				sleep 0.1;
				_spd = (velocity _jumper call ACE_fnc_magnitude) max _spd;
				((getPos _jumper) select 2 < 3) || {(vehicle _jumper != _jumper)}
			};

			if (vehicle _jumper == _jumper) then {
				// carrier landing
				_posASL = getPosASL _jumper;
				_altitudeARL = (getPos _jumper) select 2;
				_altitudeATL = (getPosATL _jumper) select 2;

				_jumper setPosASL [_posASL select 0, _posASL select 1, (_posASL select 2) - _altitudeARL];
				_jumper setVelocity [0,0,0.1];
				#ifdef DEBUG_MODE_FULL
				_debugMsg = format["Carrier Landing Check Chute for player %1 at ATL:%2 at tickTime:%3",name _jumper, getPosATL _jumper, diag_tickTime];
				LOG(_debugMsg);
				#endif
				if (!(surfaceIsWater (position _jumper)) || {((_altitudeARL + 2)  < ((_posASL select 2) min _altitudeATL))}) then {
					_jumper say3D ["ParaLand", 50, 1];
					if (alive _jumper) then {
						_jumper switchMove "AmovPercMsprSnonWnonDf_AmovPpneMstpSnonWnonDnon";
						_jumper setBehaviour "COMBAT";
						if (_spd < (-9.5-random 1)) then {
							if (isNil "ace_sys_wounds_enabled") then {
								_jumper setDamage (damage _jumper + 0.3);
							} else {
								[_jumper,"",0.3,objNull,""] call ace_sys_wounds_fnc_hd;
							};
						} else {
							if (_spd < (-6 - random 1)) then {
								if (isNil "ace_sys_wounds_enabled") then {
									_jumper setDamage (damage _jumper + 0.25);
								} else {
									[_jumper,"",0.25,objNull,""] call ace_sys_wounds_fnc_hd;
								};
							};
						};
					};
				} else {
					_jumper say3D ["ParaLandinWater", 50, 1];
				};
			};
		};

		sleep 1;
		if (_local) then {
			if !(isNull _chute) then {
				_fallTime = (_pos select 2) min ((getPos _chute) select 2)/ 5;
				sleep 1;
				#ifdef DEBUG_MODE_FULL
				_debugMsg = format["Deleting chute %1 for _jumper %2 at ATL:%3 at tickTime:%4",_chute, name _jumper, getPosATL (vehicle _jumper), diag_tickTime];
				LOG(_debugMsg);
				#endif
				deleteVehicle _chute;
			};
		};
		// Script ended. Place used parachute model.
		if (isPlayer _jumper) then {
			_dead_chute = "ACE_UsedParachute_Round" createVehicle [0,0,0];
			_dead_chute setDir (((direction _jumper) + 180) % 360);
			_dead_chute setPosASL [_pos select 0,_pos select 1,(getPosASL _jumper select 2) - (getPos _jumper select 2) - 0.25];
			[_dead_chute, 50] call ACE_fnc_add2Fifo;
			_jumper reveal _dead_chute;
			#ifdef DEBUG_MODE_FULL
			_debugMsg = format["Dead chute %1 for _jumper %2 at ATL:%3 at tickTime:%4",_dead_chute, name _jumper, getPosATL _jumper, diag_tickTime];
			LOG(_debugMsg);
			#endif
		};
		_run = false;
	};
	sleep 0.25;
};
TRACE_1("Exiting Script",_jumper);