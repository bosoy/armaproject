//fnc_fired.sqf
#include "script_component.hpp"
// player sideChat format["this: %1", _this];
PARAMS_7(_vehicle,_weapon,_muzzle,_mode,_ammo,_magazine,_bomb);
if(local _bomb) then {
	_proxy = getText(configFile >> "CfgAmmo" >> _ammo >> "ACE_ccip_proxy");
	// player sideChat format["proxy: %1", _proxy];
	if(_proxy != "") then {
		_positionCamera = positionCameraToWorld [0, 0, 0];
		_positionVehicle = _vehicle modelToWorld [0, 0, 0];
		if ((_positionCamera distance _positionVehicle) < 150) then {
			_vehicle say "ace_bombrelease";
		};

		_pos = getPos _bomb;
		_velocity = velocity _bomb;
		_vDir = vectorDir _bomb;
		_vup = vectorUp _bomb;
		deleteVehicle _bomb;
		_velocity set[2, (_velocity select 2)+EJECTOR_SPEED];
		_newBomb = _proxy createVehicle _pos;
		_newBomb setPos _pos;
		_newBomb setVelocity _velocity;
		_newBomb setVectorDir _velocity;
		[QGVAR(syncBomb), [player, _proxy, _pos, _velocity]] call CBA_fnc_globalEvent;
		
		// CBUs
		_isCBU = (getText(configFile >> "CfgAmmo" >> _ammo >> "ACE" >> "ACE_CLUSTERBOMBS" >> "simulation") in ["ACE_CEM","ACE_SFW","ACE_RUNWAY"]);
		if (_isCBU) then {
			[_vehicle,_weapon,_muzzle,_mode,_ammo,_magazine,_newBomb] call ace_sys_clusterbombs_fnc_fired;
		};
		//[_vehicle, _newBomb] spawn ACE_fnc_bulletCam;
		
		[_newBomb] call ace_sys_frag_fnc_addManualTrack;
		// [_newBomb] spawn {
			// _bomb = _this select 0;
			// _dropPos = +GVAR(lastDropPos);
			// _pipperPos = +GVAR(CONSENT_TARGETPOS);
			// if((count _pipperPos) == 0) then {
				// _pipperPos = _dropPos;
			// };
			// while {alive _bomb} do {
				// drop ["\Ca\Data\Cl_basic","","Billboard",1,0.1,_dropPos,[0,0,0],1,1.275,1.0,0.0,[20],[[0,1,0,1]],[0],0.0,2.0,"","",""];
				// drop ["\Ca\Data\Cl_basic","","Billboard",1,0.1,_pipperPos,[0,0,0],1,1.275,1.0,0.0,[20],[[1,0,0,1]],[0],0.0,2.0,"","",""];
				
				// drop ["\Ca\Data\Cl_basic","","Billboard",1,20,(getPos _bomb),[0,0,0],1,1.275,1.0,0.0,[5],[[0,0,1,1]],[0],0.0,2.0,"","",""];
				// player sideChat format["dis: %1 p: %2", _dropPos distance (getPos _bomb), _pipperPos distance (getPos _bomb)];
				// sleep 0.1;
			// };
		// };
	} else {
		_gravity = getNumber(configFile >> "CfgAmmo" >> _type >> "ACE_CCIP_GRAVITY");
		if(_gravity != 0) then {
			_positionCamera = positionCameraToWorld [0, 0, 0];
			_positionVehicle = _vehicle modelToWorld [0, 0, 0];
			if ((_positionCamera distance _positionVehicle) < 150) then {
				_vehicle say "ace_bombrelease";
			};			
			
		};
	};
};