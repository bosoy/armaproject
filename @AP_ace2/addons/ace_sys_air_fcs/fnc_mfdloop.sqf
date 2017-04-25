#include "script_component.hpp"

#define __MainTurret configFile >> "CfgVehicles" >> _vType >> "Turrets" >> "MainTurret"

disableSerialization;

private "_vehicle";

PARAMS_1(_MFD_Display);

_MFD_HeadingText =		_MFD_Display displayCtrl 693001;
_MFD_TimeText = 		_MFD_Display displayCtrl 693002;
_MFD_WeaponIndicator =	_MFD_Display displayCtrl 693003;
_MFD_DesignatorStatus =	_MFD_Display displayCtrl 693004;
_MFD_RangeText = 		_MFD_Display displayCtrl 693005;
_MFD_DesignatorCircle =	_MFD_Display displayCtrl 693006;
_MFD_ATTKIndicator =	_MFD_Display displayCtrl 693008;
_MFD_TOFText =			_MFD_Display displayCtrl 693009;
_MFD_HeadingText ctrlShow false;
_MFD_TimeText ctrlShow false;
_MFD_WeaponIndicator ctrlShow false;
_MFD_DesignatorStatus ctrlShow false;
_MFD_RangeText ctrlShow false;
_MFD_DesignatorCircle ctrlShow false;
_MFD_ATTKIndicator ctrlShow false;
_MFD_TOFText ctrlShow false;

_MFD_TargettingCircle = false;

// Pilot's stuff
_MFD_Cross =			_MFD_Display displayCtrl 693010;
_MFD_Cross ctrlShow false;

_w = 0.08*safezoneH*0.749351;
_h = 0.08*safezoneH;
_xoff = _w/2;
_yoff = _h/2;
_MFD_Cross ctrlsetposition [-10,-10,_w,_h];
_MFD_Cross ctrlsettextcolor [0,1,0,0.5];
_MFD_Cross ctrlcommit 0;

sleep 0.001;

_vehicle = player getVariable "MY_LITTLE_COBRA";

_vType = typeOf _vehicle;
_tracker = getText (configFile >> "CfgVehicles" >> _vType >> "Turrets" >> "MainTurret" >>"ace_sys_missileguidance_tracker");

_lastTime = time;
_sleepTime = 0.1;
_hudSize = if (_vehicle isKindOf "ACE_AH1W") then {10} else {180};	// Half angular size
_hudArea = 0.2;	// Maximum screen offset when FoV = 0.7

_vehicle setVariable ["AH_DESINDICATORS_ACTIVATED", nil];// Controls the DES circle & text
_vehicle setVariable ["AH_ATTKINDICATOR_ACTIVATED", nil];// Controls ATTK indicator

_MFD_WeaponIndicator ctrlSetText "GUN";

_vehicle setVariable ["AH_SYSTEMS_LOADED", true];
_vehicle setVariable ["AH_DISTANCE_TO_TARGET", 250];

while {player in [gunner _vehicle, driver _vehicle] && {alive _vehicle}} do {
	// *** Optics/Overlay ***
	if (cameraView == "GUNNER" && {!visibleMap}) then {
		// *** Perform MFD Updates ***

		// Show overlay if it's not being shown already
		if (isNil "AH_DISPLAYING_OPTICS") then {
			_MFD_HeadingText ctrlShow true;			// Heading
			_MFD_TimeText ctrlShow true;			// Time
			_MFD_WeaponIndicator ctrlShow true;		// Current Weapon
			_MFD_DesignatorStatus ctrlShow false;	// Laser designator status (on/off)
			_MFD_RangeText ctrlShow true;			// Laser range
			_MFD_DesignatorCircle ctrlShow false;	// Only on when the laser is.
			_MFD_TOFText ctrlShow false;			// Only if Hellfire is on the way

			AH_DISPLAYING_OPTICS = true;
		};

		// * Update Time of Flight status for missiles *
		if ((player == gunner _vehicle) && {(AH_CURRENT_WEAPON in ["HELLFIRELAUNCHER", "ACE_HELLFIRELAUNCHER", "ACE_HELLFIRELAUNCHER_APACHE", "ACE_DAGR_LAUNCHER", "CRV7_PG"])}) then {
			// Pulse - Use the information for our Laser target.
			_range = _vehicle getVariable ["AH_DISTANCE_TO_TARGET", 0];
			_preEta = 0;
			if(_range > 500) then {
				_preEta = 3e-07*(_range^2) + 0.0017*_range + 1.5491;
			};
			_eta = _vehicle getVariable ["ACE_Missile_ETA", 0];
			if(_eta == 0) then {
				_eta = _preEta;
			};
			_ones = floor _eta;
			_tens = floor ((_eta - _ones) * 10);
			_MFD_TOFText ctrlShow true;			// Only if Hellfire is on the way
			_MFD_TOFText ctrlSetText format ["TOF %1.%2",_ones,_tens];
		} else {
			_MFD_TOFText ctrlShow false;			// Only if Hellfire is on the way
			_MFD_TOFText ctrlSetText "";
		};

		// * Update the MFD's Designator Status *
		if (isNil {_vehicle getVariable "ace_sys_missileguidance_laser_designation"}) then {
			if !(isNil {_vehicle getVariable "AH_DESINDICATORS_ACTIVATED"}) then {
				_MFD_DesignatorCircle ctrlShow false;
				_MFD_DesignatorStatus ctrlShow false;
				_vehicle setVariable ["AH_DESINDICATORS_ACTIVATED", nil];
			};
		} else {
			if (isNil {_vehicle getVariable "AH_DESINDICATORS_ACTIVATED"}) then {
				_MFD_DesignatorStatus ctrlSetText "DES";
				_MFD_DesignatorCircle ctrlShow true;
				_MFD_DesignatorStatus ctrlShow true;
				_vehicle setVariable ["AH_DESINDICATORS_ACTIVATED", true];
			};
		};

		// * Update the MFD's ATTK Indicator *
		if (player == gunner _vehicle) then {
			if (((AH_CURRENT_WEAPON in ["TOWLAUNCHER", "ACE_TOWLAUNCHER", "HELLFIRELAUNCHER", "ACE_HELLFIRELAUNCHER", "ACE_HELLFIRELAUNCHER_APACHE", "ACE_DAGR_LAUNCHER", "CRV7_PG"]) && {(isNil {_vehicle getVariable "ace_sys_missileguidance_exceeded"})}) && {(isNil {_vehicle getVariable "AH_ATTKINDICATOR_ACTIVATED"})}) then {
				_MFD_ATTKIndicator ctrlShow true;
				_vehicle setVariable ["AH_ATTKINDICATOR_ACTIVATED", true];
			}
			else {
				if !(((AH_CURRENT_WEAPON in ["TOWLAUNCHER", "ACE_TOWLAUNCHER", "HELLFIRELAUNCHER", "ACE_HELLFIRELAUNCHER", "ACE_HELLFIRELAUNCHER_APACHE", "ACE_DAGR_LAUNCHER", "CRV7_PG"]) && {(isNil {_vehicle getVariable "ace_sys_missileguidance_exceeded"})}) || {(isNil {_vehicle getVariable "AH_ATTKINDICATOR_ACTIVATED"})}) then {
					_MFD_ATTKIndicator ctrlShow false;
					_vehicle setVariable ["AH_ATTKINDICATOR_ACTIVATED", nil];
				};
			};
		};

		// * Update Heading *
		_wdir = _vehicle weaponDirection _tracker;
		_hdng = -(_wdir select 0) atan2 -(_wdir select 1) + 180;
		_hhd = floor(_hdng / 100);
		_thd = floor((_hdng - (_hhd*100)) / 10);
		_ohd = floor(_hdng - (_hhd*100 + _thd*10));
		_MFD_HeadingText ctrlSetText format ["%1%2%3", _hhd, _thd, _ohd];

		// * Update Clock *
		_curTime = daytime;
		_thr = _curTime;
		_tmin = (_thr mod 1) * 60;
		_tsec = (_tmin mod 1) * 60;

		_thrt = (floor _thr) call CBA_fnc_intToString;
		_tmint = (floor _tmin) call CBA_fnc_intToString;
		_tsect = (floor _tsec) call CBA_fnc_intToString;

		if (count (toArray _thrt) == 1) then {_thrt = "0" + _thrt};
		if (count (toArray _tmint) == 1) then {_tmint = "0" + _tmint};
		if (count (toArray _tsect) == 1) then {_tsect = "0" + _tsect};

		_MFD_TimeText ctrlSetText format ["%1:%2:%3", _thrt, _tmint, _tsect];

		// Format Range Text
		_range = _vehicle getVariable "AH_DISTANCE_TO_TARGET";
		_shownRange = if (_range > 0) then {floor((_range/10)+.25)*10} else {0};
		if ((_range - _shownRange) >= 5) then {_shownRange = _shownRange + 5}; // Round to nearest 5 meters
		private "_rangePadding";
		_rangePadding = if (_shownRange > 10 && {_shownRange < 1000}) then {"0"} else {""};
		if (_shownRange == 0) then {_shownRange = "0000"};
		_MFD_RangeText ctrlSetText format ["%1%2  T", _rangePadding, _shownRange];
		
		_sleepTime = 0.1;
	} else {
		// Disable overlay if it's being shown
		if !(isNil "AH_DISPLAYING_OPTICS") then {
			_MFD_HeadingText ctrlShow false;      // Heading
			_MFD_TimeText ctrlShow false;         // Time
			_MFD_WeaponIndicator ctrlShow false;  // Current Weapon
			_MFD_DesignatorStatus ctrlShow false; // Laser designator status (on/off)
			_MFD_RangeText ctrlShow false;        // Laser range
			_MFD_DesignatorCircle ctrlShow false; // Only on when the laser is.
			_MFD_ATTKIndicator ctrlShow false;    // ATTK Indicator
			_MFD_TOFText ctrlShow false;         // HF Time of Flight

			_vehicle setVariable ["AH_ATTKINDICATOR_ACTIVATED", nil];
			_vehicle setVariable ["AH_DESINDICATORS_ACTIVATED", nil];

			AH_DISPLAYING_OPTICS = nil;
		};
		_sleepTime = 0.1;
	};

	// Weapon mode
	if (player == gunner _vehicle) then {
		if (toUpper(currentWeapon _vehicle) != AH_CURRENT_WEAPON) then {
			_MFD_WeaponIndicator = _MFD_Display displayCtrl 693003;
			AH_CURRENT_WEAPON = toUpper(currentWeapon _vehicle);

			_MFD_WeaponIndicator ctrlSetText " ";

			if (AH_CURRENT_WEAPON in ["M197","M230"]) then {
				_MFD_WeaponIndicator ctrlSetText "GUN";
			};
			if (AH_CURRENT_WEAPON in ["HELLFIRELAUNCHER", "ACE_HELLFIRELAUNCHER", "ACE_HELLFIRELAUNCHER_APACHE"]) then {
				_MFD_WeaponIndicator ctrlSetText "HF";
			};
			if (AH_CURRENT_WEAPON in ["TOWLAUNCHER", "ACE_TOWLAUNCHER"]) then {
				_MFD_WeaponIndicator ctrlSetText "TOW";
			};
			if (AH_CURRENT_WEAPON in ["SIDEWINDERLAUCHER", "SIDEWINDERLAUCHER_AH1Z"]) then {
				_MFD_WeaponIndicator ctrlSetText "AAM";
			};
			if (AH_CURRENT_WEAPON in ["ACE_DAGR_LAUNCHER"]) then {
				_MFD_WeaponIndicator ctrlSetText "DGR";
			};
			if (AH_CURRENT_WEAPON in ["CRV7_PG"]) then {
				_MFD_WeaponIndicator ctrlSetText "CRV7";
			};
		};
		
		switch AH_CURRENT_WEAPON do {
			// HELLFIRE-L (114-L Radar!)
			case "ACE_HELLFIRELAUNCHER_APACHE": { // "ACE_HellfireLauncher_Apache"
				if !(_MFD_TargettingCircle) then {
					call FUNC(enableDot);
					_MFD_TargettingCircle = true;
				};
			};
			default {
				if (_MFD_TargettingCircle) then {
					call FUNC(disableDot);
					_MFD_TargettingCircle = false;
				};
			};
		};

		// Hellfire mode
		if ((player == gunner _vehicle) && {(AH_CURRENT_WEAPON in ["HELLFIRELAUNCHER", "ACE_HELLFIRELAUNCHER", "ACE_HELLFIRELAUNCHER_APACHE", "ACE_DAGR_LAUNCHER", "CRV7_PG"])}) then {
			private "_modetext";

			_modetext = "HF LOBL";
			_hellFireMode = _vehicle getVariable ["ace_sys_missileguidance_hellfire_mode", 0];
			_laserCode = _vehicle getVariable "ACE_CURRENT_LASERTARGET_CODE";
			switch (_hellFireMode) do {
				case 1: {_modetext = "HF LOAL-DIR"};
				case 2: {_modetext = "HF LOAL-LO"};
				case 3: {_modetext = "HF LOAL-HI"};
				default { };
			};
			if((_vehicle ammo AH_CURRENT_WEAPON) > 0) then {
				if(_hellFireMode == 0) then {
					[_vehicle, _laserCode] call FUNC(findLD);
					if(GVAR(validLD)) then {
						_modetext = "HF LOBL -LOCK-";
					};
				};
			};
			if (ctrlText _MFD_WeaponIndicator != _modetext) then {
				_MFD_WeaponIndicator ctrlSetText _modetext;
			};
		};
		_sleepTime = 0.1;
	} else {
		_MFD_WeaponIndicator ctrlSetText " ";
		_sleepTime = 0.1;
	};

	// * Update Range *
	if (isNil {_vehicle getVariable "ace_sys_missileguidance_laser_designation"}) then {
		_lastTime = time;
	} else {
		// Pulse - Use the information for our Laser target.
		_pulse = laserTarget _vehicle;
		if (isNull _pulse) then {_pulse = (_vehicle getVariable "ace_sys_missileguidance_opticalTarget")};
		_range = _pulse distance _vehicle;
		_range = if (_range < 250) then {0} else {_range min 9999};
		_vehicle setVariable ["AH_DISTANCE_TO_TARGET", _range];
		if (time - _lastTime > 2) then {
			_vehicle setVariable ["AH_DISTANCE_TO_TARGET",_range,true];
			
			_lastTime = time;
		};
	};

	[_vehicle,_vehicle getVariable "AH_DISTANCE_TO_TARGET",magazines _vehicle,weapons _vehicle,true] call FUNC(setsolution);
	
	
	// Pilot's HUD
	if !(visibleMap) then {
		if (isNil "AH_DISPLAYING_HUD") then {
			_MFD_Cross ctrlShow true;
			AH_DISPLAYING_HUD = true;
		};
		
		_vpos = getPosASL _vehicle;
		_vdir = vectorDir _vehicle;
		_distance = _vehicle getVariable "AH_DISTANCE_TO_TARGET";
		
		_wdir = _vehicle weaponDirection _tracker;
		
		_avec = [_wdir,2000] call ACE_fnc_vectorMultiply;
		_apos = [_vpos,_avec] call ACE_fnc_vectorAdd;
		_terrainHeight = getTerrainHeightASL [_apos select 0, _apos select 1];
		if (_terrainHeight > 0) then {
			_apos set [2, (_apos select 2) - _terrainHeight];
		};
		
		_apos = worldtoscreen _apos;
		if ((count _apos == 2) && {(isEngineOn _vehicle)} && {cameraView == "INTERNAL"} && {((player == gunner _vehicle) || {(abs(acos([_vdir,_wdir] call ACE_fnc_dotProduct)) < _hudSize)})}) then {
			_fov = (call cba_fnc_getfov) select 0;
			if (sqrt((0.5-(_apos select 0))^2+(0.5-(_apos select 1))^2) < _hudArea*(0.7/_fov)) then {
				_scale = 0.2*round(1.8/_fov);
				
				_MFD_Cross ctrlsetposition [(_apos select 0)-_xoff*_scale,(_apos select 1)-_yoff*_scale];
				_MFD_Cross ctrlsetscale _scale;
				_MFD_Cross ctrlcommit 0;
			} else {
				_MFD_Cross ctrlsetposition [-10,-10];
				_MFD_Cross ctrlcommit 0;
			};
		} else {
			_MFD_Cross ctrlsetposition [-10,-10];
			_MFD_Cross ctrlcommit 0;
		};
		_sleepTime = 0.01;
	} else {
		if !(isNil "AH_DISPLAYING_HUD") then {
			_MFD_Cross ctrlShow false;			// Cross

			AH_DISPLAYING_HUD = nil;
		};
		_sleepTime = 0.1;
	};
	
	sleep _sleepTime;
};


// Deactivate dialogs
if (_vehicle getVariable "AH_SYSTEMS_LOADED") then {
	// * Teardown display *
	_MFD_HeadingText ctrlShow false;           // Deactivate heading indicator.
	_MFD_WeaponIndicator ctrlShow false;       // Deactivate weapon indicator.
	_MFD_TimeText ctrlShow false;              // Deactivate time indicator.
	_MFD_DesignatorStatus ctrlShow false;      // Deactivate laser designator status.
	_MFD_RangeText ctrlShow false;             // Deactivate range text.
	_MFD_DesignatorCircle ctrlShow false;      // Deactivate des circle.
	_MFD_TOFText ctrlShow false;              // Deactivate HF TOF indicator
	_MFD_Cross ctrlShow false;				// Deactivate pilot's turret cross

	if (_MFD_TargettingCircle) then {
		call FUNC(disableDot);
		_MFD_TargettingCircle = false;
	};

	// * Set Unloaded *
	_vehicle setVariable ["AH_SYSTEMS_LOADED", nil];
	cutText [" ", "plain"];
};

ACE_AH_GUNNERMFD_SYSTEM_INITIALIZED = nil;
