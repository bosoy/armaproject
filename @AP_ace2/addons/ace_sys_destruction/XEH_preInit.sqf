// #define DEBUG_MODE_FULL
#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

PREP(killed);
PREP(destruction);
PREP(airdestruction);
PREP(airdestructionstage2);
PREP(fuelexpbig);
PREP(fuelexpsmall);
PREP(fuelexpspark);
PREP(fuelexpmain);
PREP(burn);
PREP(secondaries);
PREP(rocket);
PREP(smokelauncher);
PREP(smokeshellparticles);
PREP(smokeshell);
PREP(cannon);
PREP(heavycaliber);
PREP(heavysniper);
PREP(rifle);
PREP(playsound_electricspark);

FUNC(destr) = FUNC(killed);

FUNC(engineBurn) = {
	PARAMS_1(_unit);
	_unit setVariable ["ace_is_burning", true];
	// TODO: Better
	if (isServer) then {
		// diag_log text format["sys_destruct engine burn: %1", [_unit, 5]];
		[_unit, 2] call FUNC(cookOff);
	};
	_fuelCapable = getNumber(configFile >> "CfgVehicles" >> typeOf _unit >> "fuelCapacity") > 0;
	_delay = if (_fuelCapable) then { 35 } else { 15 };
	_wait = time + _delay;
	while {!isNull _unit && {time < _wait}} do {
		if (_fuelCapable && {fuel _unit <= 0}) exitWith {}; // No fuel no fire
		[_unit] call FUNC(propagateFire);
		sleep 3;
	};

	TRACE_1("Turning burn off",_unit);
	_unit setVariable ["ace_is_burning", false];
};

[QGVAR(engineBurn), {if (!isNull (_this select 0)) then {_this spawn FUNC(engineBurn)}}] call CBA_fnc_addEventhandler;

#define COOLDOWN 10
#define INF_LIMIT 2
#define CIV_LIMIT 1

// Propagate Fire to other objects - Only TO men atm.
FUNC(propagateFire) = {
	// Fire scripts are supposed to run on every machine, so this function only handles units local to this machine.
	private ["_objects", "_b", "_bt", "_bc"];
	PARAMS_1(_unit);
	// TODO: Instead, base this on the size of the object etc?
	_isMan = _unit isKindOf "Man";
	DEFAULT_PARAM(2,_range,if (_isMan) then { 1.5 } else { if (_unit isKindOf "AllVehicles") then { 3.75 } else { 3 } });

	if (isNull _unit) exitWith {}; // But why?
	_objects = (nearestObjects [_unit, ["CAManBase", "ACE_JerryCan", "ReammoBox"], _range]) - [_unit];

	// Don't forget the Crew :D
	// TODO: Perhaps no need to do stuff to the crew incase of vehicledamage enabled vehicle??
	if !(_isMan) then {
		ADD(_objects,(crew _unit));
	};
	// Propagation to Objects (Reammo+Jerry and AI Men only). Player men is handled already locally by that player.
	{
		if (local _x && {alive _x} && {!(isPlayer _x)}) then {
			if !([_x] call ACE_fnc_isBurning) then {
				if (_x isKindOf "CAManBase") then {
					// Apply damage
					TRACE_1("Applying damage",_x);
					[_x, 0.06] call ace_sys_wounds_fnc_addDamage;
					if ([_x] call ace_fnc_hasCrewProtection && {damage _x < 0.33}) exitWith {};

					_bt = _x getVariable [QGVAR(burn_time), time];
					if (_bt < time - COOLDOWN) then {
						// Past Cooldown
						_b = 0;
					} else {
						_b = _x getVariable [QGVAR(burn_count), 0];
					};
					_x setVariable [QGVAR(burn_time), time];

					_bc = if (_x isKindOf "Civilian") then { CIV_LIMIT } else { INF_LIMIT };
					if (_b > _bc) then {
						// Set _x on fire!
						TRACE_1("Checking to put on fire", _x);

						// NOTE: checkburn is only for Infantry - If we add propagation to other objects, need to handle this..
						["ace_sys_wounds_checkburn", [_x]] call ACE_fnc_receiverOnlyEvent; // LocalEvent; Burning runs everywhere, so we only process local units
						_x setVariable [QGVAR(burn_count), 0];
					} else {
						_x setVariable [QGVAR(burn_count), _b + 1]
					};
				} else {
					// Apply damage
					TRACE_1("Damaging", _x);
					_x setDamage (damage _x + 0.34);
				};
			};
		};
	} forEach _objects; // TODO: What about Buildings/Foliage/Trees etc?

/*
	// Also propagate to other objects
	// TODO: Improve, cleanup, stop crashing when trees near :D
	_objects = (nearestObjects [_unit, [], _range]) - [_unit]; // "CAManBase", "ACE_JerryCan", "ReammoBox"
	{
		if (local _x && {alive _x} && {!(isPlayer _x)}) then {
			if !([_x] call ACE_fnc_isBurning) then {
				if (_x isKindOf "CAManBase") then {
					// Apply damage
					[_x, 0.01] call ace_sys_wounds_fnc_addDamage;

					if (_x in _near) then {
						// Set _x on fire!
						TRACE_1("Putting on fire", _x);

						// NOTE: checkburn is only for Infantry - If we add propagation to other objects, need to handle this..
						["ace_sys_wounds_checkburn", [_x]] call ACE_fnc_receiverOnlyEvent; // LocalEvent; Burning runs everywhere, so we only process local units
						_near = _near - [_x];
					} else {
						PUSH(_near,_x);
					};
				} else {
					if (_x isKindOf "All") then {
						// Object from CfgVehicles
						if (_x isKindOf "ACE_jerryCan" || {_x isKindOf "ReammoBox"}) then {
							// Apply damage
							TRACE_1("Damaging", _x);
							_x setDamage (damage _x + 0.34);
						};
					} else {
						// Object without class
						// TODO: Optimize
						_str = str(_x);
						_strAr = toArray _str;
						_i = 0;
						{
							if (toString [_x] == " ") exitWith {};
							INC(_i);
						} forEach _strAr;
						if (_i > 0) then {
							if (count _strAr >= (_i + 3)) then {
								_b = toString [_strAr select (_i + 1), _strAr select (_i + 2)];
								if (_b == "b_") then {
									["ace_sys_wounds_burnmen", [_x, 15, time, true]] call CBA_fnc_globalEvent;
								};
							};
						};
					};
				};
			};
		};
	} forEach _objects;
*/
};
ace_sys_destruction_fnc_cookOffCount = 0;
ace_sys_destruction_enable_cookoff = false;
ace_sys_destruction_fnc_cookOff = {
	if(ace_sys_destruction_fnc_cookOffCount > 10 || {!ace_sys_destruction_enable_cookoff}) exitWith {};
	_v = _this select 0;
	_intensity = _this select 1;
	_isCooking = _v getVariable ["ace_is_cooking", false];
	if(_isCooking) exitWith {};
	ace_sys_destruction_fnc_cookOffCount = ace_sys_destruction_fnc_cookOffCount + 1;
	_v setVariable ["ace_is_cooking", true];
	_magazines = magazines _v;
	_cargoMags = getMagazineCargo _v;
	// TODO: Include loaded ammoboxes via sys_cargo
	
	_startTime = 5-(5*((_intensity/4)));
	_totalMagazines = [];
	if(!alive _v) then {
		_transportMagazines = configFile >> "CfgVehicles" >> (typeOf _v) >> "TransportMagazines";
		_magNames = [];
		_counts = [];
		for "_i" from 0 to (count _transportMagazines)-1 do {
			_mag = _transportMagazines select _i;
			if(isClass _mag) then {
				_magName = getText(_mag >> "magazine");
				_count = getNumber(_mag >> "count");
				if(_magName != "" && {_count > 0}) then {
					_magNames set[(count _magNames), _magName];
					_counts set[(count _counts), _count];
				};
			};
		};
		_cargoMags = [_magNames, _counts];
	};
	{
		_addCount = ((random ((_cargoMags select 1) select _forEachIndex)) max 0);
		for "_i" from 1 to _addCount do {
			_magazines set[(count _magazines), _x];
		};
	} forEach (_cargoMags select 0);
	{
		_ammoCount = getNumber (configFile >> "CfgMagazines" >> _x >> "count");
		_initSpeed = getNumber (configFile >> "CfgMagazines" >> _x >> "initSpeed");
		_totalMagazines set[(count _totalMagazines), [_x, _ammoCount, _initSpeed]];
	} forEach _magazines;
	
	_burnOutSelections = ["osa_poklop_commander", "hatch_commander_axis"];
	{
		_pos = _v selectionPosition _x;
		if(_pos distance [0,0,0] != 0) exitWith {
			_v setVariable ["ace_burnout_selection", _x];
		};
	} forEach _burnOutSelections;
	
	_cookOff = {
		private ["_params", "_startTime", "_magazines", "_vehicle", "_finale", "_finaleDone", "_cookCount"];
		_params = _this select 0;
		_startTime = _params select 0;
		_magazines = _params select 1;
		
		_vehicle = _params select 2;
		_finale = _params select 3;
		_finaleDone = _params select 4;
		if(time > _startTime) then {
			_cookCount = 1;
			if(_finale && {!_finaleDone}) then {
				"ace_fuelexpbig" createvehicle (_vehicle modelToWorld [0,0,0]);
				_cookCount = 3+(floor (random 3));
				_vehicle setVariable ["ace_cookoffinalied", true];
				_finale = true;
			};
			for "_i" from 1 to _cookCount do {
				_mag = _magazines select (floor (random (count _magazines)));
				_count = (_mag select 1);
				if(_count > 0) then {
					_handled = false;
					_ammo = getText(configFile >> "CfgMagazines" >> (_mag select 0) >> "ammo");
					_simType = getText(configFile >> "CfgAmmo" >> _ammo >> "simulation");
					if(toLower(_simType) == "shotbullet") then {
						_handled = true;
						_rippleCount = floor(random _count) min 40;
						if(_finale) then {
							_rippleCount = floor(random _count) min 10;
						};
						_mag set[1, 0];
						[_vehicle, _ammo, _rippleCount, (_mag select 2)] spawn {
							_vehicle = _this select 0;
							_ammo = _this select 1;
							_count = _this select 2;
							_speed = _this select 3;
							_spacing = (random 0.25) max 0.05;
							_caliber = getNumber(configFile >> "CfgAmmo" >> _ammo >> "caliber");
							_reportType = "small";
							_maxTypes = 4;
							if(_caliber > 1.1) then {
								_reportType = "large";
								_maxTypes = 3;
							};
						
							_burnSelection = _vehicle getVariable ["ace_burnout_selection", ""];
							_burnObj = nil;
							_burnOutCount = _vehicle getVariable ["ace_burnOutCount", 0];
							_didBurn = false;
							if(_burnOutCount < 0) then {
								_vehicle setVariable ["ace_burnOutCount", 0];
								_burnOutCount = 0;
							};
							if ((random 1) > 0.8) then {
								_crewScreaming = _vehicle getVariable ["ace_flameout_crewscream", false];
								if (!_crewScreaming && {({alive _x} count (crew _vehicle)) > 0}) then {
									_vehicle setVariable ["ace_flameout_crewscream", true];
									[_vehicle] spawn {
										_screamCount = floor((random (count (crew (_this select 0)))) min 4) max 1;
										_crewArray = (crew (_this select 0));
										for "_m" from 1 to _screamCount*2 do {
											_soundidx = floor (random 15) + 1;
											_sound = "ACE_VDBrutalScream" + (_soundidx call CBA_fnc_intToString);
											_crewPosIndex = (floor (random (count _crewArray)));
											_guy = _crewArray select _crewPosIndex;
											if (_guy in (_this select 0)) then {
												[[_crewArray select _crewPosIndex], _sound] call CBA_fnc_globalSay;
											};
											sleep 0.25+(random 1);
										};
									};
								};
							};
							
							if (_burnSelection != "" && {alive _vehicle} && {_spacing <= 0.18} && {_burnOutCount == 0} && {_count > 3}) then {
								_alwaysTop = _vehicle getVariable ["ace_flameout_alwaystop", false];
								_flameType = "ace_flameout_2";
								if (_alwaysTop || {(random 10) >= 7.5}) then {
									_flameType = "ace_flameout_1";
									_vehicle setVariable ["ace_flameout_alwaystop", true];
								};
								
								
								_burnObj = _flameType createVehicle [0,0,10000];
								_burnObj attachTo [_vehicle, [0,0,-0.2], _burnSelection];
								_sound = createSoundSource ["ace_flameout", [0,0,10000], [], 0];
								_sound attachTo [_burnObj, [0,0,-0.2], _burnSelection];
								_vehicle setVariable ["ace_burnOutCount", 1];
								_vehicle setVariable ["ace_burnOutStart", diag_tickTime];
								_burnOutCountCum = _vehicle getVariable ["ace_burnOutCountCum", 0];
								_vehicle setVariable ["ace_burnOutCountCum", _burnOutCountCum + 1];
								_vehicle setVariable ["ace_burnObj", [_burnObj, _sound]];
								[_burnObj] call ace_sys_destruction_fnc_flameOut;
								_didBurn = true;
							} else {
								if (_burnOutCount > 0) then {
									_burnOutCountCum = _vehicle getVariable ["ace_burnOutCountCum", 0];
									_vehicle setVariable ["ace_burnOutCountCum", _burnOutCountCum + 1];
									_didBurn = true;
									_vehicle setVariable ["ace_burnOutCount", _burnOutCount + 1];
									_burnOutCountCum = _vehicle getVariable ["ace_burnOutCountCum", 0];
									if(_burnOutCountCum > 2) then {
										_vehicle setDamage 1;
									} else {
										_startTime = _vehicle getVariable "ace_burnOutStart";
										_time = diag_tickTime - _startTime;
										if(_time > 3.5) then {
											_vehicle setDamage 1;
										};
									};
								};
							};
							for "_i" from 1 to _count do {
								_spawnPos = _vehicle modelToWorld [(-0.2+(random 0.4)),(-0.2+(random 0.4)),(random 0.2)];//[_randX, _randY, _randZ];
								if(_spawnPos select 2 < 0) then {
									_spawnPos set[2, 0];
								};
								_vec = [(-1 + (random 2)), (-1 + (random 2)), -0.2+(random 1)];
								_filter = "filtered";
								if(!alive _vehicle) then {
									_filter = "normal";
								};
								_reportClass = format["ACE_cookoff_%1_%2_%3", _reportType, ceil(random _maxTypes), _filter];
								_report = _reportClass createVehicleLocal _spawnPos;
								if(_i == 12) then {
									{
										if(alive _x) then {
											_x setDamage 1;
										};
									} forEach (crew _vehicle);
								};
								if((random 1) > 0.75) then {
									_report setPos _spawnPos;
									_speed = (((_speed*0.5)+(random (_speed/2))) min _speed);
									_velVec = [
												(_vec select 0)*_speed,
												(_vec select 1)*_speed,
												(_vec select 2)*_speed
											];
									_bullet = _ammo createVehicleLocal _spawnPos;
									_bullet setPos _spawnPos;
									_bullet setVectorDir _velVec;
									_bullet setVelocity _velVec;
									// [ace_sys_frag_fnc_frag_trace, 0.05, [_bullet]] call cba_fnc_addPerFrameHandler;
								};
								if(alive _vehicle) then {
									_startTime = _vehicle getVariable "ace_burnOutStart";
									_time = diag_tickTime - _startTime;
									if(_time > 3.5) then {
										_vehicle setDamage 1;
									};
								};
								_finalied = _vehicle getVariable ["ace_cookoffinalied", false];
								_burnOutCount = _vehicle getVariable ["ace_burnOutCount", 0];
								if(_finalied && {_burnOutCount > 0}) then { 
									_objs = (_vehicle getVariable "ace_burnObj");
									_vehicle setVariable ["ace_burnOutCount", 0];
									deleteVehicle (_objs select 1);
									deleteVehicle (_objs select 0);
								};
								sleep _spacing+(-0.02+(random 0.04));
							};
							if(_didBurn) then {
								_burnOutCount = _vehicle getVariable ["ace_burnOutCount", 0];
								_burnOutCount = _burnOutCount - 1;
								if(_burnOutCount <= 0) then {
									_objs = (_vehicle getVariable "ace_burnObj");
									deleteVehicle (_objs select 1);
									deleteVehicle (_objs select 0);
									if(alive _vehicle) then {
										_burnOutCountCum = _vehicle getVariable ["ace_burnOutCountCum", 0];
										if(_burnOutCountCum > 2) then {
											_vehicle setDamage 1;
										} else {
											_startTime = _vehicle getVariable "ace_burnOutStart";
											_time = diag_tickTime - _startTime;
											if(_time > 3.5) then {
												_vehicle setDamage 1;
											};
										};
									};
								};
								_vehicle setVariable ["ace_burnOutCount", _burnOutCount];
							};
						};
					};
					if(toLower(_simType) == "shotshell" || {toLower(_simType) == "shotgrenade"}) then {
						_handled = true;
						_rippleCount = floor(random _count) min 3;
						_mag set[1, 0];
						[_vehicle, _ammo, _rippleCount, (_mag select 2)] spawn {
							_vehicle = _this select 0;
							_ammo = _this select 1;
							_count = _this select 2;
							_speed = _this select 3;
							_spacing = (random 0.5) max 0.1;
							_caliber = getNumber(configFile >> "CfgAmmo" >> _ammo >> "caliber");
							_fuseDistance = getNumber(configFile >> "CfgAmmo" >> _ammo >> "fuseDistance");
							_reportType = "small";
							_maxTypes = 4;
							if(_caliber > 2) then {
								_reportType = "large";
								_maxTypes = 3;
							};
							_bb = boundingBox _vehicle;
							for "_i" from 1 to _count do {
								_randX = ((_bb select 0) select 0)+(random (((_bb select 1) select 0)*2));
								_randY = ((_bb select 0) select 1)+(random (((_bb select 1) select 1)*2));
								_randZ = ((_bb select 0) select 2)+(random (((_bb select 1) select 2)*2));
								
								_spawnPos = _vehicle modelToWorld [0,0,_fuseDistance];//[_randX, _randY, _fuseDistance];
								if(_spawnPos select 2 < 0) then {
									_spawnPos set[2, 0];
								};
								_bullet = _ammo createVehicleLocal _spawnPos;
								_bullet setPos _spawnPos;
								_bullet setVectorDir [0,0,0];
								_bullet setVelocity [0,0,-300];
								sleep _spacing+(-0.02+(random 0.04));
							};
						};
					};
					if(toLower(_simType) == "shotrocket" || {toLower(_simType) == "shotmissile"}) then {
						_handled = true;
						_rippleCount = (floor(random _count) min 6) max 1;
						_mag set[1, 0];
						[_vehicle, _ammo, _rippleCount, (_mag select 2)] spawn {
							_vehicle = _this select 0;
							_ammo = _this select 1;
							_count = _this select 2;
							_speed = _this select 3;
							_spacing = (random 0.5) max 0.05;
							_caliber = getNumber(configFile >> "CfgAmmo" >> _ammo >> "caliber");
							_reportType = "small";
							_maxTypes = 4;
							if(_caliber > 1.1) then {
								_reportType = "large";
								_maxTypes = 3;
							};
							_bb = boundingBox _vehicle;
							for "_i" from 1 to _count do {
								_randX = ((_bb select 0) select 0)+(random (((_bb select 1) select 0)*2));
								_randY = ((_bb select 0) select 1)+(random (((_bb select 1) select 1)*2));
								_randZ = (random (((_bb select 1) select 2)))/2;
								_spawnPos = _vehicle modelToWorld [_randX, _randY, _randZ];
								if(_spawnPos select 2 < 0) then {
									_spawnPos set[2, 0];
								};
								_vec = [(-1 + (random 2)), (-1 + (random 2)), -0.2+(random 0.8)];
								_vertin = (random 1);
								if(_vertin < 0.9) then {
									_spawnPos = _vehicle modelToWorld [0,0,0];//[_randX, _randY, _randZ];
									_vec set[2, -0.999999];
								};
								_reportClass = format["ACE_cookoff_%1_%2", _reportType, ceil(random _maxTypes)];
								_report = _reportClass createVehicleLocal _spawnPos;
								_report setPos _spawnPos;
								_speed = ((_speed*0.5)+(random _speed) min _speed)*0.6;
								_velVec = [
											(_vec select 0)*_speed,
											(_vec select 1)*_speed,
											(_vec select 2)*_speed
										];
								_bullet = _ammo createVehicleLocal _spawnPos;
								_bullet setPos _spawnPos;
								_bullet setVectorDir _velVec;
								_bullet setVelocity _velVec;
								// [ace_sys_frag_fnc_frag_trace, 0.05, [_bullet]] call cba_fnc_addPerFrameHandler;
								
								sleep _spacing+(-0.02+(random 0.04));
							};
						};
					};
					if(!_handled) then {
						_mag set[1, 0];
					};
				};
				
				_newMags = [];
				{
					if(_x select 1 != 0) then {
						_newMags set[(count _newMags), _x];
					};
				} forEach _magazines;
				_magazines = _newMags;
				_params set[1, _newMags];
			};
			if(_finale && {!_finaleDone}) then {
				_params set[4, true];
				_newMags = [];
				
				_c = floor((count _magazines)/_cookCount);
				for "_i" from 0 to _c do {
					_newMags set[(count _newMags), (_magazines select _i)];
				};
				_magazines = _newMags;
				_params set[1, _newMags];
			};
			
			_params set[0, time+(random 5)*(random 3)];
		};
		
		_isBurning = _vehicle getVariable ["ace_is_burning", false];
		if(!_finale && {!(alive _vehicle)}) then {
			_params set[3, true];
			_params set[0, time-1];
		} else {
			if(!_isBurning || {(count _magazines) == 0}) then {
				_v setVariable ["ace_is_cooking", false];
				[(_this select 1)] call CBA_fnc_removePerFrameHandler;
				ace_sys_destruction_fnc_cookOffCount = ace_sys_destruction_fnc_cookOffCount - 1;
			};
		};
	};
	if((count _totalMagazines) > 0) then {
		[_cookOff, 0.25, [time+_startTime, _totalMagazines, _v, false, false]] call cba_fnc_addPerFrameHandler;
	} else {
		ace_sys_destruction_fnc_cookOffCount = ace_sys_destruction_fnc_cookOffCount - 1;
	};
};
ace_sys_destruction_fnc_flameOut = {
	private ["_obj", "_li"];
	_obj = _this select 0;
	if(!isDedicated) then {
		_li = "#lightpoint" createVehicleLocal [0,0,100000];
		_li setLightBrightness 0.35;
		_li setLightAmbient[0.8, 0.6, 0.2];
		_li setLightColor[1, 0.5, 0.2];
		_li lightAttachObject [_obj, [0,0,0]];
	};

	_flame = {
		_params = _this select 0;
		_obj = _params select 0;
		_startTime = _params select 1;
		_light = _params select 2;
		_factor = 1+((time-_startTime)/2) min 2;
		
		if(alive _obj) then {
			_nearObjects = (getPos _obj) nearEntities ["CAManBase", 2.4+_factor];
			//_nearObjects = nearestObjects [(getPos _obj), ["CAManBase"], 2.4+_factor];
			{
				if(local _x) then {
					_isBurning = _x getVariable ["ace_is_burning", false];
					if(!_isBurning) then {
						["ace_sys_wounds_checkburn", [_x, 30]] call ACE_fnc_receiverOnlyEvent;
						[_x] spawn {
							sleep 5+(random 8);
							(_this select 0) setDamage 1;
						};
					};
				};
			} forEach _nearObjects;
			if(!isDedicated) then {
				_light setLightBrightness 0.35*(_factor/5);
				if((typeOf _obj) == "ace_flameout_1") then {
					drop [["\ca\Data\ParticleEffects\Universal\Universal",16,2,32],
						"", "Billboard", 1,(0.1 + (random 0.2))*_factor, 
						[-0.1 + random 0.2, -0.1 + random 0.2, 0],
						[0,0,15*(_factor/2)], 
						0, 10, 7.9, 0.075, 
						[1.25*_factor, 2.5*_factor], 
						[[1, 1, 1, -2],[1, 1, 1, -2], [1, 1, 1, -1], [1, 1, 1, -0]], 
						[2 + random 1], 1, 0, "", "", _obj];
				};
				_flameSize = 2;
				_factor = _factor / 2;
				drop [["\ca\Data\ParticleEffects\Universal\Universal",16,2,32],
					"", "Billboard", 1,(0.1 + (random 0.2))*_factor, 
					[-0.1 + random 0.2, -0.1 + random 0.2, -1],
					[0,20*(_factor/2),0], 
					0, 10, 7.9, 0.075, 
					[1.25*_factor, _flameSize*_factor], 
					[[1, 1, 1, -2],[1, 1, 1, -2], [1, 1, 1, -1], [1, 1, 1, -0]], 
					[2 + random 1], 1, 0, "", "", _obj];
				drop [["\ca\Data\ParticleEffects\Universal\Universal",16,2,32],
					"", "Billboard", 1,(0.1 + (random 0.2))*_factor, 
					[-0.1 + random 0.2, -0.1 + random 0.2, -1],
					[0,-20*(_factor/2),0], 
					0, 10, 7.9, 0.075, 
					[1.25*_factor, _flameSize*_factor], 
					[[1, 1, 1, -2],[1, 1, 1, -2], [1, 1, 1, -1], [1, 1, 1, -0]], 
					[2 + random 1], 1, 0, "", "", _obj];
				drop [["\ca\Data\ParticleEffects\Universal\Universal",16,2,32],
					"", "Billboard", 1,(0.1 + (random 0.2))*_factor, 
					[-0.1 + random 0.2, -0.1 + random 0.2, -1],
					[20*(_factor/2),0,0], 
					0, 10, 7.9, 0.075, 
					[1.25*_factor, _flameSize*_factor], 
					[[1, 1, 1, -2],[1, 1, 1, -2], [1, 1, 1, -1], [1, 1, 1, -0]], 
					[2 + random 1], 1, 0, "", "", _obj];
				drop [["\ca\Data\ParticleEffects\Universal\Universal",16,2,32],
					"", "Billboard", 1,(0.1 + (random 0.2))*_factor, 
					[-0.1 + random 0.2, -0.1 + random 0.2, -1],
					[-20*(_factor/2),0,0], 
					0, 10, 7.9, 0.075, 
					[1.25*_factor, _flameSize*_factor], 
					[[1, 1, 1, -2],[1, 1, 1, -2], [1, 1, 1, -1], [1, 1, 1, -0]], 
					[2 + random 1], 1, 0, "", "", _obj];
				
				_dir = 20*(_factor/2);
				drop [["\ca\Data\ParticleEffects\Universal\Universal",16,2,32],
					"", "Billboard", 1,(0.1 + (random 0.2))*_factor, 
					[-0.1 + random 0.2, -0.1 + random 0.2, -1],
					[_dir,_dir,0], 
					0, 10, 7.9, 0.075, 
					[1.25*_factor, _flameSize*_factor], 
					[[1, 1, 1, -2],[1, 1, 1, -2], [1, 1, 1, -1], [1, 1, 1, -0]], 
					[2 + random 1], 1, 0, "", "", _obj];
				_dir = -20*(_factor/2);
				drop [["\ca\Data\ParticleEffects\Universal\Universal",16,2,32],
					"", "Billboard", 1,(0.1 + (random 0.2))*_factor, 
					[-0.1 + random 0.2, -0.1 + random 0.2, -1],
					[_dir,_dir,0], 
					0, 10, 7.9, 0.075, 
					[1.25*_factor, _flameSize*_factor], 
					[[1, 1, 1, -2],[1, 1, 1, -2], [1, 1, 1, -1], [1, 1, 1, -0]], 
					[2 + random 1], 1, 0, "", "", _obj];
				_dir = 20*(_factor/2);
				drop [["\ca\Data\ParticleEffects\Universal\Universal",16,2,32],
					"", "Billboard", 1,(0.1 + (random 0.2))*_factor, 
					[-0.1 + random 0.2, -0.1 + random 0.2, -1],
					[_dir,-(_dir),0], 
					0, 10, 7.9, 0.075, 
					[1.25*_factor, _flameSize*_factor], 
					[[1, 1, 1, -2],[1, 1, 1, -2], [1, 1, 1, -1], [1, 1, 1, -0]], 
					[2 + random 1], 1, 0, "", "", _obj];
				_dir = 20*(_factor/2);
				drop [["\ca\Data\ParticleEffects\Universal\Universal",16,2,32],
					"", "Billboard", 1,(0.1 + (random 0.2))*_factor, 
					[-0.1 + random 0.2, -0.1 + random 0.2, -1],
					[-(_dir),_dir,0], 
					0, 10, 7.9, 0.075, 
					[1.25*_factor, _flameSize*_factor], 
					[[1, 1, 1, -2],[1, 1, 1, -2], [1, 1, 1, -1], [1, 1, 1, -0]], 
					[2 + random 1], 1, 0, "", "", _obj];
			};
		} else {
			[(_this select 1)] call cba_fnc_removePerFrameHandler;
			if(!isDedicated) then {
				deleteVehicle _light;
			};
		};
	};
	[_flame, 0, [_obj, time, _li]] call cba_fnc_addPerFrameHandler;
};

[QGVAR(AirDestruction), {[_this] spawn FUNC(airdestruction)}] call CBA_fnc_addEventHandler;
[QGVAR(AirDestructionStage2), {_this spawn FUNC(airdestructionstage2)}] call CBA_fnc_addEventHandler;
[QGVAR(Burn), {_this spawn FUNC(burn)}] call CBA_fnc_addEventHandler;

// BIS Effects scripts - ca\data\particleffects\scripts is overwritten by ace_sys_ca_scripts, so they can't be overriden by BIS default scripts anymore.
BIS_Effects_Init = true;

// Only available in BIS
BIS_Effects_EH_Fired = COMPILE_FILE2(\ca\Data\ParticleEffects\SCRIPTS\fired.sqf);
BIS_Effects_Flares = COMPILE_FILE2(\ca\Data\ParticleEffects\SCRIPTS\muzzle\flares.sqf);
BIS_Effects_AircraftVapour = COMPILE_FILE2(\ca\Data\ParticleEffects\SCRIPTS\misc\aircraftvapour.sqf);
//BIS_Effects_RocketTrail = COMPILE_FILE2(\ca\Data\ParticleEffects\SCRIPTS\muzzle\rockettrail.sqf);

// ACE Replacements
BIS_Effects_EH_Killed = FUNC(killed);
BIS_Effects_AirDestruction = FUNC(airdestruction);
BIS_Effects_AirDestructionStage2 = FUNC(airdestructionstage2);
BIS_Effects_Burn = FUNC(burn);
BIS_Effects_Secondaries = FUNC(secondaries);
BIS_Effects_Rocket = FUNC(rocket);
BIS_Effects_SmokeLauncher = FUNC(smokelauncher);
BIS_Effects_SmokeShell = FUNC(smokeshell);
BIS_Effects_Cannon = FUNC(cannon);
BIS_Effects_HeavyCaliber = FUNC(heavycaliber);
BIS_Effects_HeavySniper = FUNC(heavysniper);
BIS_Effects_Rifle = FUNC(rifle);


// Workaround to get rid of WarFX BIS functions recompile
// It may otherwise overwrite our own NON SVI BIS scripts again because WarFX doesn't use call compile preprocess in the preinit EH but execVM
WARFX_Effects_Init=true;

if !(isDedicated) then {
	[QGVAR(handle_playsound_electricspark), {
		if ((cameraOn == (_this select 0)) && {(cameraView in ["GUNNER","INTERNAL"])}) then {playSound (_this select 1)};
	}] call CBA_fnc_addEventHandler;
};


ADDON = true;
