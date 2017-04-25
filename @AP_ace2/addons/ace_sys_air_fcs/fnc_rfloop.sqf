#include "script_component.hpp"

#define __MainTurret configFile >> "CfgVehicles" >> _vType >> "Turrets" >> "MainTurret"

disableSerialization;

private ["_vehicle","_vType", "_Display_HeadingText", "_Display_RangeText", "_Display_LaunchAuthorization","_lastTime","_sleepTime"];

PARAMS_1(_Generic_Display);

// Gunner's
_Display_HeadingText =			_Generic_Display displayCtrl 694001;
_Display_RangeText =			_Generic_Display displayCtrl 694002;
_Display_LaunchAuthorization =	_Generic_Display displayCtrl 694003;

// Pilot's
_Display_Cross =	_Generic_Display displayCtrl 694004;
_Display_Range =	_Generic_Display displayCtrl 694005;
_Display_LaunchAuthorization2 =	_Generic_Display displayCtrl 694006;

_Display_HeadingText ctrlShow false;
_Display_RangeText ctrlShow false;
_Display_LaunchAuthorization ctrlShow false;


// Pilot's stuff
_Display_Cross ctrlShow false;
_Display_Range ctrlShow false;
_Display_LaunchAuthorization2 ctrlShow false;

_w = 0.08*safezoneH*0.749351;
_h = 0.08*safezoneH;
_xoff = _w/2;
_yoff = _h/2;
_Display_Cross ctrlsetposition [-10,-10,_w,_h];
_Display_Cross ctrlcommit 0;

_p = ctrlposition _Display_Cross;
_k = 1.5*0.55/(getresolution select 5);
_Display_Range ctrlsetposition [(_p select 0),(_p select 1)-0.04*SafezoneH,(_p select 2)/_k,0.03*SafezoneH/_k];
_Display_Range ctrlsetscale _k;
_Display_Range ctrlcommit 0;

_Display_LaunchAuthorization2 ctrlsetposition [(_p select 0),(_p select 1)-0.04*SafezoneH,(_p select 2)/_k,0.03*SafezoneH/_k];
_Display_LaunchAuthorization2 ctrlsetscale _k;
_Display_LaunchAuthorization2 ctrlcommit 0;

sleep 0.001;

_vehicle = player getVariable "MY_LITTLE_RU";

_vType = typeOf _vehicle;
_tracker = getText (configFile >> "CfgVehicles" >> _vType >> "Turrets" >> "MainTurret" >>"ace_sys_missileguidance_tracker");
_lastTime = time;
_sleepTime = 0.1;

_hudSize = if (_vehicle isKindOf "Mi24_Base") then {4} else {8};	// Half angular size
_hudArea = 0.4;	// Maximum screen offset when FoV = 0.7
_gunnerHudArea = if (_vehicle isKindOf "Mi24_Base") then {0.1} else {0};	// Maximum screen offset when FoV = 0.7

_color = [0,1,0,0.6];
_color2 = [1,0.75,0,0.8];

_Display_Cross ctrlsettextcolor _color;
_Display_Range ctrlsettextcolor _color;
_Display_LaunchAuthorization2 ctrlsettextcolor _color;

_vehicle setVariable ["RU_SYSTEMS_LOADED", true];
_vehicle setVariable ["RU_DISTANCE_TO_TARGET", 200];

while {player in [gunner _vehicle, driver _vehicle] && {alive _vehicle}} do {
	// *** Optics/Overlay ***
	if (cameraView == "GUNNER" && {!visibleMap}) then {
		// *** Perform MFD Updates ***

		// Show overlay if it's not being shown already
		if (isNil "RU_DISPLAYING_OPTICS") then {
			_Display_HeadingText ctrlShow true;		// Heading
			_Display_RangeText ctrlShow true;		// Laser range

			RU_DISPLAYING_OPTICS = true;
		};
		// * Update Heading *
	//	_hdng = getDir _vehicle;
		_wdir = ([_vehicle modelToWorld (_vehicle selectionPosition (getText (__MainTurret >> "gunEnd"))),_vehicle modelToWorld (_vehicle selectionPosition (getText (__MainTurret >> "gunBeg")))] call BIS_fnc_vectorDiff) call FUNC(mat_normalize3d);
		_hdng = -(_wdir select 0) atan2 -(_wdir select 1) + 180;
		_hhd = floor(_hdng / 100);
		_thd = floor((_hdng - (_hhd*100)) / 10);
		_ohd = floor(_hdng - (_hhd*100 + _thd*10));
		_Display_HeadingText ctrlSetText format ["%1%2%3", _hhd, _thd, _ohd];

		// Format Range Text
		_range = _vehicle getVariable "RU_DISTANCE_TO_TARGET";
		_range = if (_range < 200) then {0} else {_range min 10000};
		_thousands = floor(_range/1000);
		_hundreds = floor(_range/100) - (_thousands * 10);
		_Display_RangeText ctrlSetText format ["%1.%2", _thousands, _hundreds];

		// Launch authorization
		if (player == gunner _vehicle) then {
			if ((([configFile >> "CfgWeapons" >> (currentWeapon _vehicle) , configFile >> "CfgWeapons" >> "MissileLauncher"] call CBA_fnc_inheritsFrom) && {(isNil {_vehicle getVariable "ace_sys_missileguidance_exceeded"})}) && {(isNil {_vehicle getVariable "RU_LAUNCH_AUTHORIZED"})}) then {
				_Display_LaunchAuthorization ctrlShow true;
				_vehicle setVariable ["RU_LAUNCH_AUTHORIZED", true];
			} else {
				if !((([configFile >> "CfgWeapons" >> (currentWeapon _vehicle) , configFile >> "CfgWeapons" >> "MissileLauncher"] call CBA_fnc_inheritsFrom) && {(isNil {_vehicle getVariable "ace_sys_missileguidance_exceeded"})}) || {(isNil {_vehicle getVariable "RU_LAUNCH_AUTHORIZED"})}) then {
					_Display_LaunchAuthorization ctrlShow false;
					_vehicle setVariable ["RU_LAUNCH_AUTHORIZED", nil];
				};
			};
		};
		_sleepTime = 0.1;
	} else {
		// Disable overlay if it's being shown
		if !(isNil "RU_DISPLAYING_OPTICS") then {
			_Display_HeadingText ctrlShow false;			// Heading
			_Display_RangeText ctrlShow false;				// Laser range
			_Display_LaunchAuthorization ctrlShow false;	// Launch authorization

			RU_DISPLAYING_OPTICS = nil;
		};
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
		_range = if (_range < 200) then {0} else {_range min 10000};
		_vehicle setVariable ["RU_DISTANCE_TO_TARGET", _range];
		if (time - _lastTime > 2) then {
			_vehicle setVariable ["RU_DISTANCE_TO_TARGET",_range,true];

			_lastTime = time;
		};
	};

	[_vehicle,_vehicle getVariable "RU_DISTANCE_TO_TARGET",magazines _vehicle,weapons _vehicle,true] call FUNC(setsolution);
	
	// Pilot's HUD, Mi-24 gunner's colimator sight KS-53
	if (cameraView == "INTERNAL" && {!visibleMap} && {isEngineOn _vehicle} && {player in [driver _vehicle,gunner _vehicle]}) then {
		if (player == driver _vehicle) then {
			if (isNil "RU_DISPLAYING_HUD") then {
				_Display_Cross ctrlShow true;
				_Display_Range ctrlShow true;
				_Display_LaunchAuthorization2 ctrlShow true;
				_Display_Cross ctrlsettext "x\ace\addons\sys_air_fcs\data\crossdot_ca.paa";
				_Display_Cross ctrlSetTextColor _color;
				RU_DISPLAYING_HUD = true;
			};

			_vpos = getPosASL _vehicle;
			_vdir = vectorDir _vehicle;
			_distance = _vehicle getVariable "RU_DISTANCE_TO_TARGET";

			_wdir = _vehicle weaponDirection _tracker;

			_avec = [_wdir,2000] call ACE_fnc_vectorMultiply;
			_apos = [_vpos,_avec] call ACE_fnc_vectorAdd;
			_terrainHeight = getTerrainHeightASL [_apos select 0, _apos select 1];
			if (_terrainHeight > 0) then {
				_apos set [2, (_apos select 2) - _terrainHeight];
			};

			_apos = worldtoscreen _apos;
			if (count _apos < 2) then {
				_apos = [-10,-10];
			};
			if (count _apos == 2 && {(abs(acos([_vdir,_wdir] call ACE_fnc_dotProduct)) < _hudSize)}) then {
				_fov = (call cba_fnc_getfov) select 0;
				if (sqrt((0.5-(_apos select 0))^2+(0.5-(_apos select 1))^2) < _hudArea*(0.7/_fov)) then {
					_scale = 0.2*round(1.8/_fov);

					_Display_Cross ctrlsetposition [(_apos select 0)-_xoff*_scale,(_apos select 1)-_yoff*_scale];
					_Display_Cross ctrlsetscale _scale;
					_Display_Cross ctrlcommit 0;

					_Display_Range ctrlsetposition [(_apos select 0)-_xoff*_scale,(_apos select 1)-_yoff*_scale-0.02*SafezoneH*_scale];
					_txt = (0.1*round((_distance)/100));
					_txt = if (_txt mod 1 == 0) then {(str _txt) + ".0"} else {str _txt};
					_Display_Range ctrlsettext _txt;
					_Display_Range ctrlsetscale _scale*_k;
					_Display_Range ctrlcommit 0;


					if ([configFile >> "CfgWeapons" >> (currentWeapon _vehicle) , configFile >> "CfgWeapons" >> "MissileLauncher"] call CBA_fnc_inheritsFrom) then {
						if (isNil {_vehicle getVariable "ace_sys_missileguidance_exceeded"}) then {
							_Display_LaunchAuthorization2 ctrlsetposition [(_apos select 0)-_xoff*_scale,(_apos select 1)+ _yoff*_scale -0.01*SafezoneH*_scale ];
							_Display_LaunchAuthorization2 ctrlsetscale _scale*_k;
							_Display_LaunchAuthorization2 ctrlcommit 0;
						} else {
							_Display_LaunchAuthorization2 ctrlsetposition [-10,-10];
							_Display_LaunchAuthorization2 ctrlcommit 0;
						};
						_Display_Cross ctrlsettext "\ca\UI\Data\cursor_w_grenade_gs.paa";
					} else {
						_Display_Cross ctrlsettext "x\ace\addons\sys_air_fcs\data\crossdot_ca.paa";
						_Display_LaunchAuthorization2 ctrlsetposition [-10,-10];
						_Display_LaunchAuthorization2 ctrlcommit 0;
					};
				} else {
					_Display_Cross ctrlsetposition [-10,-10];
					_Display_Cross ctrlcommit 0;
					_Display_Range ctrlsetposition [-10,-10];
					_Display_Range ctrlcommit 0;
					_Display_LaunchAuthorization2 ctrlsetposition [-10,-10];
					_Display_LaunchAuthorization2 ctrlcommit 0;
				};
			} else {
				_Display_Cross ctrlsetposition [-10,-10];
				_Display_Cross ctrlcommit 0;
				_Display_Range ctrlsetposition [-10,-10];
				_Display_Range ctrlcommit 0;
				_Display_LaunchAuthorization2 ctrlsetposition [-10,-10];
				_Display_LaunchAuthorization2 ctrlcommit 0;
			};
		} else {
			if (isNil "RU_DISPLAYING_HUD") then {
				_Display_Cross ctrlShow true;
				_Display_Cross ctrlsettext "x\ace\addons\sys_air_fcs\data\ks53_ca.paa";
				_Display_Cross ctrlSetTextColor _color2;
				RU_DISPLAYING_HUD = true;
			};

			_vpos = getPosASL _vehicle;
			_vdir = vectorDir _vehicle;
			_distance = _vehicle getVariable "RU_DISTANCE_TO_TARGET";

			_wdir = _vehicle weaponDirection _tracker;
			
			_avec = [_wdir,2000] call ACE_fnc_vectorMultiply;
			_apos = [_vpos,_avec] call ACE_fnc_vectorAdd;
			_terrainHeight = getTerrainHeightASL [_apos select 0, _apos select 1];
			if (_terrainHeight > 0) then {
				_apos set [2, (_apos select 2) - _terrainHeight];
			};

			_apos = worldtoscreen _apos;
			if (count _apos == 2) then {
				_fov = (call cba_fnc_getfov) select 0;
				if (sqrt((0.5-(_apos select 0))^2+(0.5-(_apos select 1))^2) < _gunnerHudArea*(0.7/_fov)) then {
					_scale = 0.1*round(1.8/_fov);

					_Display_Cross ctrlsetposition [(_apos select 0)-_xoff*_scale,(_apos select 1)-_yoff*_scale];
					_Display_Cross ctrlsetscale _scale;
					_Display_Cross ctrlcommit 0;
				} else {
					_Display_Cross ctrlsetposition [-10,-10];
					_Display_Cross ctrlcommit 0;
				};
			} else {
				_Display_Cross ctrlsetposition [-10,-10];
				_Display_Cross ctrlcommit 0;
			};
		};
		_sleepTime = 0.01;
	} else {
		if !(isNil "RU_DISPLAYING_HUD") then {
			_Display_Cross ctrlShow false;			// Cross
			_Display_Range ctrlShow false;				// Range
			_Display_LaunchAuthorization2 ctrlShow false;	// Launch authorization

			RU_DISPLAYING_HUD = nil;
		};
		_sleepTime = 0.1;
	};
	sleep _sleepTime;
};

if (_vehicle getVariable "RU_SYSTEMS_LOADED") then {
	// Deactivate dialogs
	// * Teardown display *
	_Display_HeadingText ctrlShow false;			// Deactivate heading indicator.
	_Display_RangeText ctrlShow false;				// Deactivate range text.
	_Display_LaunchAuthorization ctrlShow false;	// Deactivate launch authorization.


	_Display_Cross ctrlShow false;
	_Display_Range ctrlShow false;
	_Display_LaunchAuthorization2 ctrlShow false;
	
	RU_DISPLAYING_HUD = nil;
	
	// * Set Unloaded *
	_vehicle setVariable ["RU_SYSTEMS_LOADED", nil];
	cutText [" ", "plain"];
};

ACE_RU_GUNNERFCS_INITIALIZED = nil;
