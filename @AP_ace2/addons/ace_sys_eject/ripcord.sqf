//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_vel", "_chute_object", "_para_unit", "_vehicle", "_pos", "_vUp", "_vDir", "_vel", "_endtime"];

PARAMS_1(_para_unit);
if (count _this > 2) then { _para_unit removeAction (_this select 2) };
_chute_object = objNull;
_vel = [];

_secs = abs (velocity _para_unit select 2) * 0.05;
player setVariable ["ACE_PB_Result", 0];
[_secs,[localize "STR_ACE_EJECT_HALO_CHUOPEN"],false,false] spawn ace_progressbar;

_endtime = time + _secs;
waitUntil {time >= _endtime};
if (!alive _para_unit) exitWith {};

// Determine which chute to give jumper.
if ("ACE_ParachutePack" in (weapons _para_unit)) then {
	_chute_object = "BIS_Steerable_Parachute";
} else {
	if (("ACE_ParachuteRoundPack" in (weapons _para_unit)) || {player != _para_unit}) then {
		_chute_object = ["ParachuteWest","ParachuteEast","ParachuteG","ParachuteC", "ParachuteC", "ParachuteC", "ParachuteC"] select ([WEST, EAST, RESISTANCE, CIVILIAN, SIDEFRIENDLY, SIDEENEMY, SIDELOGIC] Find (side _para_unit));
	};
};

// GIVE STEERABLE PARACHUTE
_vehicle = createVehicle [_chute_object, [0,0,100],[],0,"FLY"];
waitUntil { !isNil "_vehicle" };

_para_unit say3D "ChuteOpen";

// Avoid colliding with player - setPos after board
_pos = getPosASL _para_unit;
_vUp = vectorUp _para_unit;
_vDir = vectorDir _para_unit;
_vel = velocity _para_unit;

#ifdef DEBUG_MODE_FULL
	_debugMsg = format["RIPCORD: Checking player for _para_unit %1 at ATL:%2 at tickTime:%3",name _para_unit, getPosATL _para_unit, diag_tickTime];
	LOG(_debugMsg);
#endif
if (getPos _para_unit select 2 > 10) then {
	// AI
	if !(isPlayer(_para_unit)) then {
		// SQUARE CHUTE
		if (_chute_object == "BIS_Steerable_Parachute") then {
			_vehicle setPosASL _pos;
			_vehicle setVectorDirAndUp [_vDir, _vUp];
			_para_unit moveInCargo _vehicle;
			_vehicle setVelocity _vel;
			_para_unit setVelocity _vel;
			// BIS control for AI
			[_vehicle, _para_unit] spawn COMPILE_FILE2(ca\air2\halo\data\Scripts\Parachute_AI.sqf);
		};
		// ROUND CHUTE
		if (_chute_object in ["ParachuteWest","ParachuteEast","ParachuteG","ParachuteC"]) then {
			_para_unit moveInDriver _vehicle;
			_vehicle setPosASL _pos;
			_vehicle setVectorDirAndUp [_vDir, _vUp];
			_vehicle setVelocity _vel;
			_para_unit setVelocity _vel;
		};
	} else { // PLAYER
		"DynamicBlur" ppEffectEnable false;
		"RadialBlur" ppEffectEnable false;
		//SQUARE CHUTE
		if (_chute_object == "BIS_Steerable_Parachute") then {
			if (abs(_vel select 2) > (100 + random 15)) then {
				_para_unit setVariable [QGVAR(Chute_Unconc), true];
				_para_unit spawn COMPILE_FILE(ripcord_knockOut);
			} else {
				_para_unit setVariable [QGVAR(Chute_Unconc), false];
			};

			_vehicle setPosASL _pos;
			_vehicle setVectorDirAndUp [_vDir, _vUp];
			_para_unit moveInCargo _vehicle;
			_vehicle setVelocity _vel;
			_para_unit setVelocity _vel;
			#ifdef DEBUG_MODE_FULL
				_debugMsg = format["RIPCORD: _para_unit %1 is now in Square chute: %2 at ATL:%3 at tickTime:%4",name _para_unit,_vehicle, getPosATL _para_unit, diag_tickTime];
				LOG(_debugMsg);
			#endif
		};
		// ROUND CHUTE
		if (_chute_object in ["ParachuteWest","ParachuteEast","ParachuteG","ParachuteC"]) then {
			_para_unit moveInDriver _vehicle;
			_vehicle setPosASL _pos;
			_vehicle setVectorDirAndUp [_vDir, _vUp];
			_vehicle setVelocity _vel;
			_para_unit setVelocity _vel;
			sleep 0.5;
			#ifdef DEBUG_MODE_FULL
				_debugMsg = format["RIPCORD: _para_unit %1 is now in Round chute: %2 at ATL:%3 at tickTime:%4",name _para_unit,_vehicle, getPosATL _para_unit, diag_tickTime];
				LOG(_debugMsg);
			#endif
			//if (abs(_vel select 2) > (65 + random 10)) then { [_para_unit] spawn COMPILE_FILE(ripcord_dropGear); };
			//if (abs(_vel select 2) > (79 + random 10)) then { _para_unit spawn COMPILE_FILE(ripcord_knockOut); };
		};
	};
};
sleep 0.001;
_vehicle lock true;
_vehicle say3D "BIS_Steerable_Parachute_Opening";
TRACE_1("Exiting Script",_para_unit);