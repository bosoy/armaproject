//#define DEBUG_MODE_FULL
#include "script_component.hpp"

ADDON = false;
LOG(MSG_INIT);

PREP(init_eject);
PREP(init_jumpout);
PREP(getin_eject);
PREP(getin_jumpout);
PREP(getout_eh);
PREP(remove_eject);
PREP(remove_jumpout);
FUNC(eject) = COMPILE_FILE(eject);
PREP(nopilots_uav);
// HALO keys
PREP(keypressed_halo);
PREP(keyreleased_halo);

// Kamov
PREP(kamov);

// Sound
PREP(sound);

// Seat Rocket Flame
PREP(seat_flame);

// Parachutes
//PREP(parachute);
PREP(parachute_round);
PREP(parachute_steer);
PREP(repack);

PREP(water_survival);

[QGVAR(snd), { _this call FUNC(sound) }] call CBA_fnc_addEventHandler;
[QGVAR(ooc), { _this lock true; _this setVariable [QGVAR(seatlock),true]}] call CBA_fnc_addEventHandler;
[QGVAR(ooo), { _this lock false; _this setVariable [QGVAR(seatlock),nil]; _this setVariable [QGVAR(engaged),false] }] call CBA_fnc_addEventHandler;
[QGVAR(sejt), { _this spawn COMPILE_FILE(eject) }] call CBA_fnc_addEventHandler;
[QGVAR(jbld), { _this call FUNC(kamov) }] call CBA_fnc_addEventHandler;
[QGVAR(anim), { _this switchMove 'HaloFreeFall_non' }] call CBA_fnc_addEventhandler; // FreeFall animation needs to be added for NO Chute
[QGVAR(dieanim), { _this switchMove 'aidlppnemstpsraswrfldnon0s' }] call CBA_fnc_addEventhandler;

FUNC(weaponCheckEnabled) = {
	#define CFG configFile >> "CfgVehicles" >> typeOf _vehicle >> "ace_sys_eject_weaponCheck"
	private ["_enabled"];
	PARAMS_1(_vehicle);
	_enabled = _vehicle getVariable QGVAR(weaponCheck);
	if !(isNil "_enabled") exitWith { _enabled };
	_enabled = getNumber(CFG) == 1;
	_vehicle setVariable [QGVAR(weaponCheck), _enabled];
	_enabled;
};

FUNC(weaponcheck) = {
	// (c) this by rocko
	#define ASV (assignedVehicleRole player) select 0
	
	private ["_bag","_vehicle","_forbidden_stuff","_personal_weapons","_personal_weapons_OB","_fnc_drop_shit"];
	_fnc_drop_shit = {
		// Remove backpack
		private ["_magAry", "_wepAry", "_ruck", "_orgRuck", "_cratyp", "_crate", "_unitdir", "_unitpos"];
		private ["_unit","_vehicle"];
		_unit = _this;
		_vehicle = vehicle _unit;

		_magAry = _unit getVariable ["ACE_RuckMagContents",[]];
		_wepAry = _unit getVariable ["ACE_RuckWepContents",[]];
		_ruck = _unit call ACE_SYS_RUCK_FNC_FINDRUCK;
		
		_orgRuck = "";
		_cratyp = _ruck + "_crate";
		if !(isClass(configFile >> "CfgVehicles" >> _cratyp)) then { // If CrateType does not exist, like ACRE rucks or CSW packs, drop beackpack into weaponholder 
			_orgRuck = _ruck;
			_cratyp = "Weaponholder";
		};
		if (alive _unit && {_cratyp != ""} && {_unit call ACE_SYS_RUCK_FNC_HASRUCK}) then {
			if (_unit hasWeapon _ruck) then {_unit removeWeapon _ruck} else {_unit setVariable ["ACE_weapononback", "", true];};
			_unit setvariable ["ACE_RUCKMAGCONTENTS", []];
			_unit setvariable ["ACE_RUCKWEPCONTENTS", []];
			

			_crate = _cratyp createVehicle [0,0,0];
			if (_cratyp == "Weaponholder") then {
				_crate addWeaponCargo [_ruck,1];
			};
			_unitdir = (getDir _vehicle) + 90;
			_unitpos = getPosATL _vehicle;
			_unitpos = [(_unitpos select 0) + (sin _unitdir * 3),(_unitpos select 1) + (cos _unitdir * 3),_unitpos select 2];
			_crate setPosATL _unitpos;
			// TODO: Put Radio Rucks into Cargo - Attach non-Radio Rucks to the vehicle
			_crate setVectorDirAndUp [[-0.0204803,-0.585819,0.810183],[0.00794978,-0.810423,-0.585792]];
			_unit reveal _crate;
			_crate setVariable ["ACE_RUCKOWNER",format[localize "STR_ACE_SYS_RUCK_OWNRUCK",name _unit],true];
			_crate setVariable ["ACE_SYS_CARGO_NAME",format[localize "STR_ACE_SYS_RUCK_OWNRUCK",name _unit],true];
			_crate setVariable ["ACE_SYS_CARGO_OWNER",name _unit];
			_crate setVariable ["ACE_SYS_CARGO_ATPLAYER",true,true];
			{_crate addMagazineCargoGlobal [_x select 0, _x select 1]} forEach _magAry;
			{_crate addWeaponCargoGlobal _x} forEach _wepAry;			
			["ACE_SYS_RUCK_GLBRUCKACT", [_crate,_orgRuck]] call CBA_fnc_globalEvent;
			[[_crate],_vehicle] call ACE_SYS_CARGO_FNC_LOADCARGO;
		} else {
			// Drop it
			//hint "Non ACE backpack";
			
			//_bisPack = unitBackpack _unit; 	//Check if BIS backpack
			//if (!isNull _bisPack) then {	// If BIS backpack, then drop it
			//	_bisPack = unitBackpack _unit; diag_log _bisPack;
			//	_unit action ["putbag", _unit]; diag_log (getPos _bisPack);
			//	_bisPack setVariable ["ACE_RUCKOWNER",format[localize "STR_ACE_SYS_RUCK_OWNRUCK",name _unit],true];
			//	_bisPack setVariable ["ACE_SYS_CARGO_NAME",format[localize "STR_ACE_SYS_RUCK_OWNRUCK",name _unit],true];
			//	_bisPack setVariable ["ACE_SYS_CARGO_OWNER",name _unit];
			//	_bisPack setVariable ["ACE_SYS_CARGO_ATPLAYER",true,true];
			//	[[_bisPack],_vehicle] call ACE_SYS_CARGO_FNC_LOADCARGO;
			//	diag_log (unitBackPack _unit);
			//};
		};
	};
	PARAMS_1(_vehicle);
	if !(player in _vehicle) exitWith {}; // For init EH
	if (count crew _vehicle == 0) exitWith {}; // For init EH

	if !(_vehicle call FUNC(weaponCheckEnabled)) exitWith {}; //piss fuck shit
	
	// Workaround for stupid people that get in a vehicle via a crew seat
	// It gives the idiot, 5 seconds to change the seat before stuff is removed
	// New: Progressbar to help the dumb guy 
	if (ASV != "Cargo") then {
		TRACE_1("Idiotcheck started","");
		player setVariable ["ACE_PB_Result", 0];
		_wait = 3;
		[_wait,[localize "STR_ACE_EJECT_STORGEAR"],false,false,player,false] spawn ACE_PROGRESSBAR;
		_time = time;
		while { time < _time + _wait } do {
			sleep 0.25;
			if (ASV == "Cargo") exitWith { 
				player setVariable ["ACE_PB_Abort",true]; 
				TRACE_1("--> Cargo Seat","");
				[localize "STR_ACE_LADEBALKEN_CANCELLED",[1,0,0,1],0,2] spawn ACE_FNC_VISUAL;		
			};
		};
		player setVariable ["ACE_PB_Result", 0];
	};

	// Now the check wether player is in a cargo seat or not and not remove stuff
	if (player in (assignedCargo _vehicle)) exitWith {};
	if !(player in _vehicle) exitWith {};
	
	// Check if a doorgunner seat has been chosen
	_doorgunner = false;
	// TODO: perhaps check wether lademeister feature is enabled for this turret?
	//_turretWeapon = _vehicle weaponsTurret ((assignedVehicleRole player) select 1);
	//if (getNumber(configFile >> "CfgWeapons" >> _turretweapon >> "isDoorgunner") == 1) then {
	//	_doorgunner = true;
	//};
	
	player setVariable [QGVAR(jumpedout),false];
	
	_isHelicopter = (_vehicle isKindOf "Helicopter");
	_forbidden_stuff = if (_isHelicopter) then { [3,4,5,6] } else { [1,3,4,5,6] }; // Helicopter Crew have rifle, Jet Crew does not have
	if (_vehicle isKindOf "LandVehicle") then {	_forbidden_stuff = []; };
	
	_personal_weapons = weapons player;
	_personal_weapons_OB = player getVariable ["ACE_WEAPONONBACK", ""];
	if (_personal_weapons_OB != "") then {
		_personal_weapons set [count _personal_weapons, _personal_weapons_OB];
	};
	_stuff_to_store = []; // Check if forbidden weapon already carried
	{
		_type = getNumber (configFile >> "CfgWeapons" >> _x >> "ace_sys_weapons_type"); 	// Retrieve original weapons type, since we made vanilla types different
		if ([_x] call ACE_SYS_RUCK_FNC_ISRUCK) then { _type = 0 }; 							// Exclude rucksacks for now, process them later
		if (_type in _forbidden_stuff) then {
			_stuff_to_store set [count _stuff_to_store, _x];
		};
	} foreach _personal_weapons;
	if (count _stuff_to_store > 0) then {
		_bag = "ACE_Bag" createVehicleLocal [0,0,0]; //Create bag // Create local, so no others can steal it // TODO: consider remove after time
		_dir = (getDir _vehicle) + 90;
		_pos = getPosATL _vehicle;
		_pos = [(_pos select 0) + (sin _dir * (random 7 max 4)),(_pos select 1) + (cos _dir * (random 7 max 4)),0];
		_bag setPosATL _pos;
		player reveal _bag;
		_bag setVariable ["ACE_SYS_CARGO_NAME",format[localize "STR_ACE_SYS_RUCK_OWNBAG",name player],true];
	};
	if (!_doorgunner) then {
		{
			if (player hasWeapon _x) then {
				player removeWeapon _x;
				_bag addWeaponCargo [_x,1];
			};
			if (_x == _personal_weapons_OB) then {
				player setVariable ["ACE_weapononback","",true];
				_bag addWeaponCargo [_x,1];
			};
			_magazines = getArray(configFile >> "CfgWeapons" >> _x >> "magazines");
			_personal_magazines = magazines player;
			{
				if (_x in _magazines) then {
					player removeMagazine _x;
					_bag addMagazineCargo[_x,1];
				};
			} foreach _personal_magazines;
		} foreach _stuff_to_store;
	};
	// Check if carrying a rucksack
	// Duffle bags cannot be loaded, due to being local and therefore would mess up sys_cargo
	if (player call ACE_FNC_HASRUCK) then {
		player call _fnc_drop_shit;
		0 spawn {
			sleep 1;
			if (player call ACE_FNC_HASRUCK) then {
				player call _fnc_drop_shit;
			};
		};
	};
	
	// Safety check, store main weapon in helicopter cargo space
	if (_isHelicopter) then {
		_weapons = weapons player;
		{
			_type = getNumber (configFile >> "CfgWeapons" >> _x >> "ace_sys_weapons_type");
			if (_type == 1) then {
				player removeWeapon _x;
				_vehicle addWeaponCargoGlobal [_x,1]; // Global, deal with real gangstas that grab ur weapon, yourself :)
				TRACE_1("WC: Weapon stored in Weaponmount",_x);
				player setVariable ["SAFETY_STORAGE",[_vehicle,_x]];
			};
		} foreach _weapons;
		TRACE_1("WC: SAFETY_STORAGE-Value",(player getVariable "SAFETY_STORAGE"));
	};
};

FUNC(retrieveWeapon) = {
	PARAMS_1(_vehicle);
	_data = player getVariable ["SAFETY_STORAGE",[]];
	TRACE_1("RTW: Safety Storage",_data);
	if (count _data < 1) exitWith { TRACE_1("Missing data","") };
	_vehicle_store = _data select 0;
	_weapon_store = _data select 1;
	if (_vehicle != _vehicle_store) exitwith { TRACE_1("RTW: No storage",""); };
	[_vehicle,_weapon_store] call ACE_fnc_removeweaponcargo;
	player addWeapon _weapon_store;
	if !(player hasweapon "ace_safe") then {player addweapon "ace_safe"};
	player selectweapon "ace_safe";
};

// Player lands successfully!
FUNC(ChuteDelete) = {
	private ["_V1", "_V2", "_V3", "_worldPos", "_altitudeARL", "_altitudeASL", "_altitudeATL", "_spd"];
	PARAMS_2(_chute,_jumper);
	["KeyDown", GVAR(HALO_KEYSDN)] call CBA_fnc_removeDisplayHandler;
	["KeyUp", GVAR(HALO_KEYSUP)] call CBA_fnc_removeDisplayHandler;
	hintSilent "";
	_jumper removeWeapon "ACE_ParachutePack";
	_jumper setVariable [QGVAR(ChuteOpen), 0];
	_spd = (velocity _chute select 2);
	_V1 = VectorDir _chute;
	_V2 = VectorUp _chute;
	_V3 = getPosATL _chute;
	moveOut _jumper;
	waitUntil {vehicle _jumper == _jumper};
	_jumper setVelocity [0,0,0];
	if (surfaceIsWater (position vehicle _jumper)) then {
		_jumper setPosASL (_chute modelToWorld [0,0,0]);
	} else {
		_jumper setPosATL (_chute modelToWorld [0,0,0]);
	};

	sleep 0.001;
	deleteVehicle _chute;
	//detach _jumper;

	_worldPos = getPosATL _jumper;
	_altitudeARL = (getPos _jumper) select 2;
	_altitudeASL = (getPosASL _jumper) select 2;
	_altitudeATL = _worldPos select 2;
	TRACE_5("Altitude Check", _jumper, _altitudeARL,_altitudeASL,_altitudeATL, _worldPos);
	_jumper setPosATL [_worldPos select 0, _worldPos select 1, (_worldPos select 2) - 4.2];
	//_jumper setVectorDir _V1;
	if (!(surfaceIsWater (position vehicle _jumper)) || ((_altitudeARL + 2) < (_altitudeASL min _altitudeATL))) then {
		_jumper switchmove "SprintCivilBaseDf";
		_jumper say ["ParaLand", 50, 1];
		if (_spd < (-9.5-random 1)) then {
			_jumper switchmove "AmovPercMsprSnonWnonDf_AmovPpneMstpSnonWnonDnon";
			[_jumper, 0.1] call FUNC(hd);
		} else {
			if (_spd < (-6 - random 1)) then {
				_jumper switchmove "AmovPercMsprSnonWnonDf_AmovPpneMstpSnonWnonDnon";
				[_jumper, 0.05] call FUNC(hd);
			} else {
				if (_spd < -2.5) then {
					_jumper switchmove "AmovPercMsprSnonWnonDf_AmovPpneMstpSnonWnonDnon";
				} else {
					_jumper switchmove "SprintCivilBaseDf";
					sleep 2;
					_jumper switchmove "AmovPercMevaSnonWnonDfl";
				};
			};
		};
	} else {
		_jumper say ["ParaLandinWater", 50, 1];
	};
	// Script ended. Place used parachute model.
	_dead_chute = "ACE_UsedParachute_MC5" createVehicle _worldPos;
	_dead_chute setDir (((direction _jumper) + 180) % 360);
	_dead_chute setPosASL [(_worldPos select 0),(_worldPos select 1),((getPosASL _jumper select 2) - (getPos _jumper select 2) - 0.25)];
	[_dead_chute, 100] call ACE_fnc_add2sfifo;
	_jumper reveal _dead_chute;
	TRACE_2("Exiting FUNC(ChuteDelete)",_jumper,_chute);
};

// Player cuts his chute!
FUNC(CutChute) = {
	private ["_dir", "_vel"];
	PARAMS_2(_chute,_jumper);
	_dir = vectorDir _chute;
	moveOut _jumper;
	waitUntil {vehicle _jumper == _jumper};
	_jumper attachTo [_chute, [0,0,-1]];
	sleep 0.001;
	deleteVehicle _chute;
	//_jumper setVectorDir _dir;
	//_jumper setVelocity [0,0,0];
	if ((getpos _jumper select 2) > 20) then {
		[_jumper] spawn COMPILE_FILE(jumpout_cord);
		waitUntil {_jumper getVariable QGVAR(ChuteOpen) == 0};
		_jumper setVariable [QGVAR(ChuteOpen), 4]; // "reserve" status
	} else {
		waitUntil {(getPos _jumper select 2) < 2};
		LOG("Close to the ground - cutting chute");
		_vel = Velocity _jumper;
		_jumper setVelocity [(_vel select 0),(_vel select 1),(_vel select 2)/1.5];
	};
	TRACE_2("Exiting FUNC(CutChute)",_jumper,_chute);
};

FUNC(hd) = {
	PARAMS_2(_unit,_damage);
	if (!isNil "ace_sys_wounds_enabled") then {
		[_unit,"",_damage,objNull,""] call ace_sys_wounds_fnc_hd;
	} else {
		_unit setDamage (getDammage _unit + _damage);
	};
	TRACE_2("Exiting FUNC(hd)",_unit,_damage);
};

// LOOPED STEERING FUNCTION, 100 times per second
FUNC(ChuteSteer) = {
	#define DELAY 0.01

	_handle = [_this,
	{_exit},
	{ /* Run Code */
		if ((_jumper getVariable QGVAR(ChuteOpen)) != 1) exitWith {_exit = true};

		_dT = (time - _nextTime) + DELAY;

		_dZ = (getPosASL _chute select 2) - _z;
		_dPAct = (position _chute) distance _oldPos;
		_dPTheo = ([_Fwd * _HdgX, _Fwd * _HdgY, _Descent] call ACE_fnc_magnitude) * _dT;
		_diffPos = (_diffPos / 2 + (_dPTheo - _dPAct) / 2);

		_NewDam = Damage _jumper;

		if (_jumper getVariable QGVAR(Chute_Unconc)) then {
			_Bank = (_Bank * 0.99); // Slowly bring the desired bank back to zero, when keys are released
			_Pitch = (_Pitch * 0.99);
		} else {
			if (_jumper == player) then {
				switch (toUpper ACEChute_Steer) do {
					case "CENTER": {
						_Bank = (_Bank * (1 - 0.5*_dT) ); // Slowly bring the desired bank back to zero, when keys are released
					};
					case "LEFT": {
						if ((Abs _Bank) < 1) then {_Bank = _Bank - 0.875*_dT;}; // Slowly move desired bank left. MAX value of -1 or +1
					};
					case "RIGHT": {
						if ((Abs _Bank) < 1) then {_Bank = _Bank + 0.875*_dT;}; // Slowly move desired bank right. MAX value of -1 or +1
					};
				};
				switch (toUpper ACEChute_Pitch) do {
					case "CENTER": {
						_Pitch = (_Pitch - 0.25) * (1 - 0.125* _dT) + 0.25; // Center-pitch is offset to ~20-30% brakes
					};
					case "FORWARD": {
						if (_Pitch > 0) then { // apply less brakes
							_Pitch = _Pitch - 1.25*_dT;
						} else {
							_Pitch = 0;
						};
					};
					case "BACK": {
						if (_Pitch < 1) then { // apply more brakes
							_Pitch = _Pitch + 1.25*_dT;
						} else {
							_Pitch = 1;
						};
					};
				};
			} else {
				// BIS get target code here?
				_bank = 0; _pitch = -0.2;
			};
		};

		// "System damping" - Make sure _Pitch and _Bank max out at 0/1 and -1/+1 ... they can be well outside limits for one frame if _dT is large.
		if (_Pitch < 0) then {_Pitch = 0};
		if (_Pitch > 1) then {_Pitch = 1};
		if (_Bank > 1) then {_Bank = 1};
		if (_Bank < -1) then {_Bank = -1};

		// Convert the index factor into a number of degrees
		_BAngle = 20 * _Bank;
		_NewBank = _NewBank + (1 min (1.5*_dT))*(_BAngle - _NewBank); // "System damping" - make sure added differential is never more than 1 * the difference
		_Hdg = _Hdg + (1 min (2*_dT))*_NewBank;

		_HdgX = sin _Hdg; // WHEN you are heading 0, this is MINIMUM
		_HdgY = cos _Hdg; // when you are heading 0, this is MAXIMUM

		_NY = sin _NewBank;
		_NZ = cos _NewBank;

		_PAngle = -2 + 22 * _Pitch;
		_NewPitch = _NewPitch + (1 min (5*_dT))*((_PAngle - 7) - _NewPitch); // A seven-degree nosedown attitude is induced

		if (_jumper getVariable QGVAR(ChuteHit)) then {
			_Descent = -3; _Fwd = 0.5; // crashed parachute into something - descend player slowly and evenly
		} else {
			_DsdFwd = (13 - _NewPitch) * 12 / 22; // (13 - Pitch) ranges from 0 to 22. Speeds should go from 0 to 12m/s (0 to 40 km/h) .... this is a basic scaling operation
			_DsdDescent = _Drop + 0.25 * _NewPitch - 1.25 * (abs _Bank) - (0.3 * (11 - _Fwd)) / ((_Fwd + 1.75) / 10); // descent speed depends on brakes and forward speed

			if (_DsdFwd > _Fwd) then {
				_Fwd = _Fwd + (1 min (0.25*_dT))*(_DsdFwd - _Fwd);
			} else {
				_Fwd = _Fwd + (1 min (0.15*_dT))*(_DsdFwd - _Fwd);
			};
			_Descent = _Descent + (1 min (0.75*_dT))*(_DsdDescent - _Descent);
		};
		//TRACE_4("Checking Params for ChuteSteer Function",_chute,_jumper,_velcc,_Hdg);
		_sinP = sin _NewPitch;

		//TRACE_5("_Chute setVectorDir [_HdgX, _HdgY, 1];",_HdgX,_HdgY,_NY,_sinP,_NZ);
		//TRACE_3("_Chute setVectorUp [_HdgY * _NY - _HdgX * _sinP, -_HdgX * _NY - _HdgY * _sinP, _NZ];",(_HdgY * _NY - _HdgX * _sinP), (-_HdgX * _NY - _HdgY * _sinP), (_NZ));
		_Chute setVectorUp [_HdgY * _NY - _HdgX * _sinP, -_HdgX * _NY - _HdgY * _sinP, _NZ];
		_Chute setVectorDir [_HdgX, _HdgY, 1];

		// Tree or building impact detection:
		// if player is injured during the last 10m of the fall, slow down descent rate so they don't keep being setVelocity'd into the object and die. Problem: player who is SHOT in this period, will land very weirdly. Still seeking solution to this!
		//if ((_NewDam > _OldDam) AND (true))then {_badLand = true; player globalchat "BADLAND ----------------------------------";};
		//if (_badLand) then {_Descent = -3.01;_Fwd = 3;};


		//TRACE_3("_Chute setVelocity [_Fwd * _HdgX, _Fwd * _HdgY, _Descent];",_Fwd * _HdgX, _Fwd * _HdgY, _Descent);
		_Chute setVelocity [_Fwd * _HdgX, _Fwd * _HdgY, _Descent];

		_spd = (velocity _chute select 2);

		// if player is low, end control and goto chuteDelete
		_chute_posz = position _chute select 2;
		_diffz = _old_c_posz - _chute_posz;

		// Landing conditions
		if (_diffz < 5 && {(((_chute_posz < 10) && {((_dT*_spd) < (_dZ - 0.1))}) || {(_chute_posz < 1)})}) exitWith { _chute setVelocity [0, 0, -1]; _jumper setVariable [QGVAR(ChuteOpen), 3]; _exit = true };
		_OldDam = damage _jumper;
		_z = (getPosASL _chute select 2);
		_oldPos = (position _chute);
		_old_c_posz = _oldPos select 2;
		_nextTime = time + DELAY;
	},
	{ /* Init Code */
		TRACE_1("Init Code",_this);
		_chute = _this select 0;
		_jumper = _this select 1;
		_velcc = _this select 2;
		_Hdg = getDir _chute;

		_chute setVelocity _velcc;

		_weight = _jumper call ACE_SYS_RUCK_FNC_GEARWEIGHT;
		_Bank = 0; // DESIRED bank index factor (keys A,D,Left,Right will change this)
		_NewBank = 0; // ACTUAL bank the chute will be set to. This "follows" _Bank as best it can with a delay, for smoother turns :D

		_Pitch = 0;
		_NewPitch = 0;

		_Speed = 3; // basic velocity magnitude, caused by pitching forwards
		_Drop = -1 - (_weight/25); // basic descent speed, to be modified later -> -3 for ~80 kg? therefore drop = weight / 25
		_badLand = false; // rough landing, i.e. hitting a tree, player will drop to the ground in a gentler manner

		_Fwd = 6; // start parachute with some flight speed
		_Descent = 0.5 * ((velocity vehicle _jumper) select 2); // start parachute with some downwards speed

		_DsdFwd = 12;
		_DsdDescent = -10;

		_dT = DELAY;
		_dZ = -1000;

		ACEChute_Steer = "CENTER";
		ACEChute_Pitch = "CENTER";

		_NewDam = 0;
		_OldDam = 0;

		_diffPos = 0;

		_text_yel = "#ffff00";
		_text_ora = "#ff9900";
		_text_red = "#ff0000";
		_text_grn = "#00ff00";

		// for delta
		_old_c_posz = 10000000;
		_oldPos = (position _chute);
		_z = (getPosASL _chute select 2);
		_HdgX = sin _Hdg; // WHEN you are heading 0, this is MINIMUM
		_HdgY = cos _Hdg; // when you are heading 0, this is MAXIMUM

		// Loop conditions
		_exit = false;
		_nextTime = time + DELAY;
	},
	{ /* Exit code */
		#ifdef DEBUG_MODE_FULL
		_debugMsg = format["Chute is now Closed:  _jumper %1 now in Round chute: %2 at ATL:%3 at tickTime:%4",name _jumper, _chute, getPosATL _jumper, diag_tickTime];
		LOG(_debugMsg);
		#endif
		TRACE_1("Exit","");
	},
	["_exit", "_old_c_posz", "_text_yel", "_text_ora", "_text_red", "_text_grn", "_nextTime", "_chute", "_jumper", "_velcc", "_Hdg", "_Bank", "_NewBank", "_Pitch", "_NewPitch", "_Speed", "_Drop", "_weight", "_badLand", "_Fwd", "_Descent", "_DsdFwd", "_DsdDescent", "_dT", "_dZ", "_NewDam", "_OldDam", "_diffPos", "_p1text", "_BAngle", "_HdgX", "_HdgY", "_NY", "_NZ", "_PAngle", "_sinP", "_spd", "_Col1", "_Col2", "_diffz", "_z", "_oldPos", "_t1", "_dPAct", "_dPTheo"],
	{time > _nextTime}
	] execFSM CBA_common_delayLess_loop;

	waitUntil {completedFSM _handle}; // Wait until done before returning, or the initiater will delete chute as it thinks its done :D
	TRACE_1("Exiting FUNC(ChuteSteer)",_jumper);
};

FUNC(showAltimeter) = {
	private ["_height","_descent"];
	#define __dsp (uiNamespace getVariable "ACE_Altimeter_HALO")
	#define __ctrl_alt (__dsp displayCtrl 135)
	#define __ctrl_compass (__dsp displayCtrl 136)
	#define __ctrl_descent (__dsp displayCtrl 137)
	13523 cutRsc ["ACE_Altimeter_HALO", "PLAIN"];
	while { ace_sys_wind_deflection_running && {ctrlShown __ctrl_alt} } do {
		_height = round ((getPosASL player) select 2);
		_height = _height - (_height mod 5);
		_descent = -round ((velocity vehicle player) select 2);
		_descent = _descent - (_descent mod 2);
		__ctrl_alt ctrlSetText format["%1 m",ceil _height];
		__ctrl_compass ctrlSetText format ["%1",(round direction vehicle player)];
		__ctrl_descent ctrlSetText format ["%1",_descent];
		__ctrl_alt ctrlcommit 0;__ctrl_descent ctrlCommit 0; __ctrl_compass ctrlCommit 0;
		sleep 1;
	};
	ace_sys_wind_deflection_running = false;
	if (ctrlShown __ctrl_alt) then { 13523 cutRsc ["Default", "PLAIN",3] };
};

ADDON = true;
