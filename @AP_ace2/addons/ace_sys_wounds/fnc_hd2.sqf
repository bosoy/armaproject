//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __unitcfg configFile >> "cfgVehicles" >> _to
#define __ammocfg configFile >> "cfgAmmo" >> _ammo

/*

0: injured [Object]
1: part hit [String]
2: new overall part damage [Number]
3: injurer [Object]
4: class of ammo causing the damage [String]

For each hit this EH triggers 5 times within a frame, always in this sequence of parts:
1. "" - info on overall damage
2. "head_hit"
3. "body"
4. "hands"
5. "legs"

Multiple hits within one frame are handled one by one, not causing mixups
(1-2-3-4-5 - 1-2-3-4-5  - etc)

All 5 will trigger if at least 1 of the parts receives non-zero damage.
Damage values causing the triggering may be as low as 0.0001, so filtering might be advised.

Triggered by falling or collisions returns the unit itself as the injurer, ammo class is an empty string.
Example: [unit1,"head_hit",0.000253947,unit1,""]

Damage in destroyed vehicles only triggers the 1st type (""), then unit ejects.

using BIS configs:
head_hit:
armor = 0.6;  ==  no helmet
armor = 0.7; == for example pilot helmet
armor = 0.85; == normal helmet

body:
armor = 1;
passThrough = 0.8; == bulletproof west

armor = 0.8;
passThrough = 1; == NO bulletproof west


by q1184


Supplemental, by Sickboy:

The following hit-parts accumulate their damage instead of each time only show the damage made by the current hit.
* ""
* "head_hit"
* "body"

Returning 1 or above to the following parts, will kill the unit
* "head_hit"
* "body"
* ""

setDamage will override the visual wounds on the units.
setHit properly sets the visual wounds on the units.
*/


private ["_to", "_ammo", "_unit", "_part", "_partDamage", "_injurer", "_rv", "_newPartDamage", "_s", "_tp",
	"_prevDamage", "_headbody", "_leg", "_ha", "_vel", "_mass", "_energy", "_dir", "_cal", "_partarmor",
	"_passt", "_nd", "_state", "_isbb", "_anim", "_isu", "_vehicle", "_ee", "_pd", "_bloss", "_inVehicle",
	"_isp", "_velocityLoss", "_bloodLossComponent", "_coef",
	"_energyComponent", "_withpmr", "_force", "_extraBl", "_bd", "_dead", "_startStateHandler", "_vdEnabled", "_penetrated", "_force_fall", "_distance",
	"_randomCoef1","_randomCoef2"];

private "_arterial";
	
PARAMS_5(_unit,_part,_partDamage,_injurer,_ammo);

if (!alive _unit) exitwith {
	_hdh = _unit getVariable QGVAR(hdeh);
	if (!isNil "_hdh") then {
		_unit removeEventHandler ["handleDamage", _hdh];
		_unit setVariable [QGVAR(hdeh), nil];
	};
	_partDamage;
};

if (!isNil {_unit getVariable "ace_w_allow_dam"}) exitWith {0};

_newPartDamage = 0; _rv = 0; _bloss = 0;
_isp = isPlayer _unit; _dead = false; _force = false; _startStateHandler = false;
// added to avoid gazillion lines of doubled code
// only one check instead of many
_withpmr = false;
if (_isp && {!isNil "ace_wounds_prevtime"} && {ace_wounds_prevtime > 0}) then {
	_withpmr = true;
};

// TODO: Should this also be active for AI, so it can be extinguished by 50cal to head or RPG without them "bandaging" themselves?
// TODO: Also this part located in this section is using unfiltered damage, it should be moved to the section where part damage is computed
// Determines if the head/body threshold is active
//_withPMRHeadBodyThreshold = false;
//if (_isp) then {
//	if (!isNil "ace_wounds_prev_headbody_threshold") then {
//		if (ace_wounds_prev_headbody_threshold > 0) then {
//			_withPMRHeadBodyThreshold = true;
//		};
//	};
//};

// Determines if the 'all' threshold is active.
//_withPMRAllThreshold = false;
//if (_isp) then {
//	if (!isNil "ace_wounds_prev_all_threshold") then {
//		if (ace_wounds_prev_all_threshold > 0) then {
//			_withPMRAllThreshold = true;
//		};
//	};
//};

// Initialize variables if don't exit yet
if (isNil {_unit getVariable "ace_w_initialized"}) then {_unit call FUNC(unitinit)};

_vehicle = vehicle _unit;
_inVehicle = _vehicle != _unit;

// zGuba: randomization: critical hits, and/or sinus of random hit angle, usually bigger than 45 degrees - no need to know exact value.
// Coefficients in equation are purely empirical - feel free to adjust for better.
_randomCoef1 = random 1;
_randomCoef1 = 3.2*(_randomCoef1^3) - 4.8*(_randomCoef1^2) + 2.4*_randomCoef1 + 0.6;
_randomCoef2 = random 1;
_randomCoef2 = 3.2*(_randomCoef2^3) - 4.8*(_randomCoef2^2) + 2.4*_randomCoef2 + 0.6;
// minimum 60%
// average 100%
// maximum 140%
// small probability of extreme values, almost 50% would be around average

if (_part == "") then {   // ** first triggering of the EH - no part
	_prevDamage = _unit getVariable "ace_w_overall";
	_anim = (_unit call CBA_fnc_getUnitAnim) select 0;
	_diff = _partDamage - _prevDamage;
	_coef = OVERALL_DAM_COEF;
	if (GVAR(armor_difficulty_enabled)) then { _coef = _coef * DIFFICULTY_COMPENSATION_COEF };
	if (_coef != 1) then {
		_diff = _diff * _coef;
		_partDamage = _prevDamage + _diff;
	};

	// Removed for v1.60 - prone damage isn't halved anymore
	//if (_anim == "prone") then {_partdamage = _partdamage + _diff;_diff = 2*_diff}; // Workaround for prone halves overall damage
	_rv = _partDamage;
	
	#ifdef DEBUG_MODE_FULL
	_distance = _unit distance _injurer;
	TRACE_7("DamData",_partDamage,_prevDamage,_diff,_anim,_distance,_coef,GVAR(armor_difficulty_enabled));
	#endif

	// Exit with current damage if it is equal
	if (_prevDamage == _partDamage) exitWith {};

	_startStateHandler = true;

	_state = _unit getVariable "ace_w_state";

	_vdEnabled = false;
	_exit = false;

	_damDone = false;
	// TODO: Verify with vehicle hitting objects etc - might need extra parameter that tells if it really is custom called
	if (_ammo == "" && {isNull _injurer}) then { // helper for functions that call hd directly, for example in backblast, etc, injurer has to be null
		if (!_withpmr) then {
			for "_ee" from 0 to 3 do {
				_pd = _partDamage;  // max 0; // max 0 in case the diff is negative
				[_unit, _ee, _pd] call FUNC(setHit);
			};
			_damDone = true;
			_bd = _unit getVariable (GVAR(parts) select 1);
			if (_bd < 1) then { [_unit, _state, false] call FUNC(NoAmmoCheck) };

			_force = true; // Custom damage should always be forced.

			// Kill the unit if body damage over 1
			if (_bd >= 1) exitWith { _rv = 1; _dead = true };
		} else {
			[_unit, _partDamage] call FUNC(AddPRDam);
			_bd = _unit getVariable (GVAR(parts) select 1);
			switch (true) do {
				case (_bd < STATE_800_HEAD_BODY_DAM_MAX && {_bd > 0}): {
					[_unit, STATE_800_BLOSS_ADD/2, STATE_800_PAIN_ADD, 0] call FUNC(vchange);
					if (_state <= 800) then {
						_unit setVariable ["ace_w_state",800]; // state 800 = bleeding signs, pain
					};
				};
				case (_bd < STATE_801_HEAD_BODY_DAM_MAX && {_bd >= STATE_800_HEAD_BODY_DAM_MAX}): {
					[_unit, STATE_801_BLOSS_ADD/2, STATE_801_PAIN_ADD, 0] call FUNC(vchange);
					if (_state <= 801) then {
						_unit setVariable ["ace_w_nextuncon", time];
						_unit setVariable ["ace_w_state",801]; // state 801 = blackouts every now and then, bleeding signs, pain
					};
				};
				case (_bd >= STATE_801_HEAD_BODY_DAM_MAX): {
					[_unit, STATE_802_BLOSS_ADD/2, STATE_802_PAIN_ADD, 1] call FUNC(vchange);
					[_state,_unit] call FUNC(PRInitU);
					if (_inVehicle) then {
						_vacm = _vehicle getVariable "ace_canmove";
						_alv = if (isNil "_vacm") then {alive _vehicle} else {_vehicle call ace_v_alive};
						if (!_alv || {_vehicle isKindOf "StaticWeapon"}) then {
							_unit action ["eject", _vehicle];
							if !(_unit getVariable [QGVAR(preject), false]) then {
								_unit setVariable [QGVAR(preject), true];
								_unit spawn FUNC(PREject);
							};
						};
					};
				};
			};
			_rv = _bd;
		};
	} else {
		// Grab data for energy calcs etc.
		_isbb = false;
		if (_ammo != "" && {_prevDamage < _partDamage}) then {
			_explosive = getNumber(__ammocfg >> "explosive"); // explosive ammo
			_ace_w_explosive = getNumber(__ammocfg >> "ace_w_explosive"); // forced explosive
			_ace_w_ke = getNumber(__ammocfg >> "ace_w_ke"); // forced KE
			if ((_explosive == 0 && {_ace_w_explosive == 0}) || {_ace_w_ke > 0}) then { // KE ammo - use ace_wounds energy calculations
				_ha = [_unit,_injurer,_ammo,_diff] call FUNC(ha);
				PUSH(_ha,_diff); // save overall damage for later
				_unit setVariable ["ace_w_ha", _ha];
				if (_ammo isKindOf "bulletBase" || {_ammo isKindOf "GrenadeBase"} || {_ammo isKindOf "Grenade"}) then {
					_isbb = true;
					// Test for regulating the overall damage better...
					// TODO: What about when inside vehicles etc?
					_diff2 = _diff / DAMAGE_DIFF_DIV;
					_partDamage = _partDamage - (_diff - _diff2);
					_diff = _partDamage - _prevDamage;
					_rv = _partDamage;
					TRACE_3("UpdDamData",_partDamage,_prevDamage,_diff);
				};
			} else { // explosive - use default damage
				_unit setVariable ["ace_w_ha", [0, 0, 0, 0, 0, false, _diff]]; // set #5 to false to use engine damage calculations
			};
		} else {
			_unit setVariable ["ace_w_ha",  [0, 0, 0, 0, 0, false, _diff]]; // set #5 to false to use engine damage calculations
		};
		
		// In OA, the crew handledamage eh's register hits on the tank, also to the crew units, this wasn't the case in A2, so we have to exit
		if (_inVehicle) then {
			_vdEnabled = ([_vehicle] call ace_sys_vehicledamage_fnc_enabled);
			_exit = _injurer != _vehicle && {_ammo != ""} && {_diff < VEH_CREW_DAM_FLOOR} && {_vdEnabled || {getNumber(configFile >> "CfgAmmo" >> _ammo >> "explosive") < 0.8}}; // _ammo check is so that custom damage (_ammo == "" && isNull _injurer) etc are still working
		};
	};

	if (_exit) exitWith { TRACE_6("Abort in vehicle.",_rv,_partDamage,_prevDamage,_diff,_vdEnabled,_ammo);_rv = _prevDamage }; // But still return the previous damage, otherwise we're actually lowering the damage on the unit.

	//new damage received
	if (!_inVehicle) then { // Outside vehicle
		if (_isp && {!ace_sys_spectator_SPECTATINGON} && {!(_unit call FUNC(isUncon))}) then {
			//_anim = (_unit call CBA_fnc_getUnitAnim) select 0;
			[_unit, _ammo, _anim] call FUNC(effect);
		};
	} else { // Inside a vehicle
		_vacm = _vehicle getVariable "ace_canmove";
		_alv = if (isNil "_vacm") then {alive _vehicle} else {_vehicle call ace_v_alive};
		if (!_alv) then{
			if (_withpmr) then {
				[_unit, STATE_802_BLOSS_ADD/2, STATE_802_PAIN_ADD, 1] call FUNC(vchange);
				_unit call FUNC(MaxPRDam);
				[_state,_unit] call FUNC(PRInitU);
				_unit action ["eject", _vehicle];
				if !(_unit getVariable [QGVAR(preject), false]) then {
					_unit setVariable [QGVAR(preject), true];
					_unit spawn FUNC(PREject);
				};
				_rv = MAX_PMR_DAM;
			} else {
				_rv = 1; _force = true;
			};
		} else {
			if (!_isbb && {!([_vehicle] call ace_sys_vehicledamage_fnc_enabled)}) then {
				if (_partDamage > MIN_PART_DAM) then {
					if (!_withpmr) then {
						if !(_damDone) then {
							for "_ee" from 0 to 3 do {
								_pd = ((_unit getVariable (GVAR(parts) select _ee)) + _diff) max 0;
								[_unit, _ee, _pd] call FUNC(setHit);
							};
							_damDone = true;
						};
						_force = true;
					} else {
						[_unit, _diff] call FUNC(AddPRDam);
						if (_inVehicle) then {
							if (_unit getVariable (GVAR(parts) select 1) >= MAX_PMR_DAM) then {
								[_unit, STATE_802_BLOSS_ADD/2, STATE_802_PAIN_ADD, 1] call FUNC(vchange);
								[_state,_unit] call FUNC(PRInitU);
								if (_vehicle isKindOf "StaticWeapon") then {
									_unit action ["eject", _vehicle];
									if !(_unit getVariable [QGVAR(preject), false]) then {
										_unit setVariable [QGVAR(preject), true];
										_unit spawn FUNC(PREject);
									};
								};
							};
						};
					};
					_bd = _unit getVariable "ace_w_body";
					_rv = _bd;
					if (_bd >= 1) exitWith {};

					_state = _unit getVariable "ace_w_state";
					if (_isp) then {
						[_unit, (_bd * STAMINA_COEF)] call FUNC(addStamina);
					};

					switch (true) do {
						case (_bd < STATE_800_HEAD_BODY_DAM_MAX && {_bd > 0}): {
							[_unit, 0, STATE_800_PAIN_ADD, 0] call FUNC(vchange);
							if (_state <= 800) then {
								_unit setVariable ["ace_w_state",800]; // state 800 = bleeding signs, pain
							};
						};
						case (_bd < STATE_801_HEAD_BODY_DAM_MAX && {_bd >= STATE_800_HEAD_BODY_DAM_MAX}): {
							[_unit, STATE_801_BLOSS_ADD/2, STATE_801_PAIN_ADD, 0] call FUNC(vchange);
							if (_state <= 801) then {
								_unit setVariable ["ace_w_nextuncon", time];
								_unit setVariable ["ace_w_state",801]; // state 801 = blackouts every now and then, bleeding signs, pain
							};
						};
						case (_bd >= STATE_801_HEAD_BODY_DAM_MAX): {
							[_unit, STATE_802_BLOSS_ADD/2, STATE_802_PAIN_ADD, 1] call FUNC(vchange);
							if (_state <= 802) then {
								_unit setVariable ["ace_w_unconlen", time + MAX_UNC_TIME];
								_unit setVariable ["ace_w_state",802]; // state 802 = complete blackout,
							};
							if (_withpmr && {_unit getVariable "ace_w_revive" == -1}) then {
								_unit setVariable ["ace_w_revive", time + ace_wounds_prevtime];
								[QGVAR(rev), [_unit]] call CBA_fnc_localEvent;
							};
						};
					};
				};
			} else {
				if (_partDamage > MIN_PART_DAM) then {
					if (!_withpmr) then {
						if !(_damDone) then {
							for "_ee" from 0 to 3 do {
								_pd = ((_unit getVariable (GVAR(parts) select _ee)) + _diff) max 0;
								[_unit, _ee, _pd] call FUNC(setHit);
							};
							_damDone = true;
						};
						_force = true;
					} else {
						[_unit, _diff] call FUNC(AddPRDam);
						if (_inVehicle) then {
							if (_unit getVariable (GVAR(parts) select 1) >= MAX_PMR_DAM) then {
								[_unit, STATE_802_BLOSS_ADD/2, STATE_802_PAIN_ADD, 1] call FUNC(vchange);
								[_state,_unit] call FUNC(PRInitU);
								_vacm = _vehicle getVariable "ace_canmove";
								_alv = if (isNil "_vacm") then {alive _vehicle} else {_vehicle call ace_v_alive};
								if (!_alv || {_vehicle isKindOf "StaticWeapon"}) then {
									_unit action ["eject", _vehicle];
									if !(_unit getVariable [QGVAR(preject), false]) then {
										_unit setVariable [QGVAR(preject), true];
										_unit spawn FUNC(PREject);
									};
								};
							};
						};
					};
					_rv = _unit getVariable (GVAR(parts) select 1); // body
					if (!ace_sys_spectator_SPECTATINGON && {_isp} && {(_ammo isKindOf "bulletBase")}) then {
						[_unit, _ammo, "a"] call FUNC(effect);
					};
				};
			};
		};
	};

	if !(_force) then { _rv = if (_withPmr) then { _rv min MAX_PMR_DAM } else { _rv min MAX_UNFORCED_DAM } };
	_unit setVariable ["ace_w_overall", _rv];
	if (_rv >= 1) then { _unit setDamage 1; _dead = true }; // Kill the unit, which only happens on custom event calls for add/setDamage etc.

	// Handle AI use medical items
	// TODO: How to handle better??
	if (!_isp && {_rv > 0} && {!_dead} && {!(_unit call FUNC(isUncon))} && {!(_unit getVariable ["ace_w_check", false])}) then {
		_unit setVariable ["ace_w_check", true];
		[_unit] spawn {
			PARAMS_1(_unit);
			sleep (7 + random 8);
			if (_unit call FUNC(isUncon) || {!alive _unit}) exitWith { _unit setVariable ["ace_w_check", false] };
			[_unit, _unit] call FUNC(help);
			_unit setVariable ["ace_w_check", false];
		};
	};
} else {  // Second (etc) triggering of the event; Once for each of the 4 parts.
	_s = 0; _tp = 0; _headBody = false; _leg = false;
	_to = typeOf _unit;

	_coef = 1;
	switch (_part) do {
		case "head_hit": {_headBody = true; _coef = HEAD_DAM_COEF};
		case "body": {_s = 1;_tp = 1;_headBody = true; _coef = BODY_DAM_COEF};
		case "hands": {_s = 2;_tp = 2; _coef = HANDS_DAM_COEF};
		case "legs": {_s = 3;_tp = 3;_leg = true; _coef = LEGS_DAM_COEF};
	};
	
	if (GVAR(armor_difficulty_enabled)) then { _coef = _coef * DIFFICULTY_COMPENSATION_COEF };

	_prevDamage = _unit getvariable (GVAR(parts) select _tp);
	_diff = if (_headBody) then { _partDamage - _prevDamage } else { _partDamage };
	if (_coef != 1) then {
		_partDamage = _partDamage - _diff;
		_diff = _diff * _coef;
		_partDamage = _partDamage + _diff;
	};
	TRACE_4("DamData",_partDamage,_prevDamage,_diff,_coef);

	// Head/Body seems to accumulate every hit, so when equal or smaller do not apply damage
	if (_headBody && {(_prevDamage >= _partDamage)}) exitWith {
		_rv = _partDamage; _unit setVariable [GVAR(parts) select _tp, _rv];
	};
	
	// Chance a bullet hit does not cause bleeding to be added, makes it feel no longer being able to bleed to death from a mosquito stitch
	_arterial = (_ammo != "" && {_part != ""} && {(getNumber(__ammocfg >> "caliber") > 0.85 || {70 > random 100})});
	// TODO: explosives
	
	_ha = _unit getVariable "ace_w_ha"; _vel = 1; _mass = 1; _cal = 1; _penetrationMultiplier = 1; _dir = 0; _ke = false; _damage = 1;
	if (!isNil "_ha" && {count _ha > 0}) then { EXPLODE_7(_ha,_vel,_mass,_cal,_penetrationMultiplier,_dir,_ke,_damage) };
	// EXPLODE_7(_ha,_vel,_mass,_cal,_penetrationMultiplier,_dir,_ke,_damage) // WTH??

	_partArmor = getNumber (__unitcfg >> "hitpoints" >> (GVAR(hitp) select _s) >> "armor");

	_penetrated = true; // Later switched to off if not penetrated
	_penetrationCoefficient = BASE_PENETRATION_COEF * _penetrationMultiplier * _randomCoef1;	// Random angle
	if (_ke) then { // use energy to calculate damage
		TRACE_6("wounds debug 1", _ke, _tp, _vel, _damage,_partArmor,_bloss);
		switch (_tp) do {
			case 0: { // head	// should use eye direction
				if (_partarmor >= 0.85 && {_dir > 70} && {_dir < 290}) then { // unit has helmet -> back
					_velocityLoss = ((240 / _penetrationCoefficient) * (_cal^1.7)) / _mass;
					_vel = (_vel - _velocityLoss) max 0;
				};
			};
			case 1: { // body
				_passt = getNumber (__unitcfg >> "hitpoints" >> (GVAR(hitp) select _s) >> "passThrough");
				// TRACE_1("",_passt);
				if (_passt < 1) then {
					if ((_dir < 80 || {_dir > 280}) || {(_dir > 110 && {_dir < 260})}) then { // front or back
						_velocityLoss = ((240 / _penetrationCoefficient) * (_cal^1.7)) / _mass;
						//_velocityLoss = ((250 / _penetrationCoefficient) * (_cal)) / _mass;
						_vel = (_vel - _velocityLoss) max 0;
					};
				};
			};
		};

		_penetration = ((_vel * _mass) / (_cal^1.7)) * _penetrationCoefficient * _randomCoef2;	// Did the bullet smash something important?
		_penetrated = _penetration > 0;
		_exitVelocity = 0;
		_energy = 0;
		_exitWound = 1;
		_force_fall = false;
		if (_penetration > PENETRATION_CEIL) then {
			_penetration = PENETRATION_CEIL;
			_exitWound = 1.5;
		};
		if (_penetration > 0) then {
			_velocityLoss = ((_penetration / _penetrationCoefficient) * (_cal^1.7)) / _mass;
			_exitVelocity = (_vel - _velocityLoss) max 0;
			_energy = (0.005 * (_mass * (_vel ^ 2))) - (0.005 * (_mass * (_exitVelocity ^ 2)));
		} else {
			_force_fall = true; // All the energy is absorbed by the unit...
		};
		
		_bloodLossComponent = _penetration * _cal  * BLOSS_COEF * _exitWound;
		_energyComponent = _energy * ENERGY_COEF;
		_nd = (_bloodLossComponent + _energyComponent) * (_diff / _damage); // * _diff;

		_div = BLOSS_DIV;
		_newPartDamage = switch (_part) do {
			case "head_hit": { 1 min (_nd + _prevDamage) };
			case "body": { 1 min (_nd + _prevDamage) };
			case "hands": { _div = HANDS_BLOSS_DIV; _nd + _prevDamage };
			case "legs": { _nd + _prevDamage };
		};
		_bloss = _bloodLossComponent / _div;
		TRACE_8("wounds - ke damage", _bloodLossComponent, _energyComponent, _vel,_nd, _penetration, _energy, _mass,_ke);

		// Knockdown
		if (_diff > 0.1 && {!_inVehicle} && {_part != "hands"} && {!(_unit getVariable ["ace_w_falling", false])}) then { [_unit, _energy, _dir, _force_fall] call FUNC(fall) };

	} else { // use default damage

		_nd = _partDamage;

		if (_ammo == "") then {
			_penetrated = false;

			// Normalize the damage - for falling off rooftops etc...
			if (_headBody && {_injurer == _unit} && {!_inVehicle}) then {
				// TODO: Make the unit fall on the ground if damage is over dam threshold??
				if (_nd > FALL_DAM_TRESHOLD) then {
					_nd = _nd / FALL_DAM_DIV;
					if (surfaceIsWater getPos _unit) then {
						_nd = _nd/2;
					};
				} else { 
					_nd = 0;
				};
			}; // Temporary to be able to survive small falls better
		};

		if (_headbody) then {
			_newPartDamage = 1 min _nd;
			_bloss = _nd / HEAD_BODY_DAM_BLOSS_DIV;
		} else {
			_newPartDamage = _nd + _prevDamage;
			_bloss = _nd / ARMS_LEGS_DAM_BLOSS_DIV;
		};

		TRACE_3("Not KE",_nd,_newPartDamage,_bloss);
	};

	// ----------------
	// PMR Threshold Implementation
	/* 	kill the player if:
	 	1. Either PMR Threshold is active.
	 	AND
	 		2.1. The damage (on the body or the head) is greater than the headbody threshold.
	 		OR
	 		2.2. The damage (anywhere)  is greater than the all threshold.
	*/
	//_significantAreaHit = (_part == "head_hit" || {_part == "body"});

	//diag_log "Partdamage";
	//diag_log _nd;

	//_headBodyThresholdExceeded = false;
	//if (_withPMRHeadBodyThreshold && {_headbody}) then {
	//	_headBodyThresholdExceeded = (_nd > ace_wounds_prev_headbody_threshold);
	//};

	//_allThresholdExceeded = false;
	//if (_withPMRAllThreshold) then {
	//	_allThresholdExceeded = (_nd > ace_wounds_prev_all_threshold);
	//};
	//if (_headBodyThresholdExceeded || {_allThresholdExceeded}) exitWith {
	//	diag_log format ["%1 was KILLED!", _unit];
	//	hint format ["%1 was KILLED!", _unit];
	//	_rv = 1;
	//	_dead = true;
	//	_rv; 
	//};
	// ----------------	
	
	if (_withpmr) then {
		if (_headbody) then {
			_newPartDamage = MAX_PMR_DAM min _newPartDamage;
			if ((_unit getVariable "ace_w_revive" == -1) && {(_newPartDamage >= HEAD_BODY_MAX_PMR_DAM)}) then {
				_unit setVariable ["ace_w_revive", time + ace_wounds_prevtime];
				[QGVAR(rev), [_unit]] call CBA_fnc_localEvent;
			};
		} else {
			_newPartDamage = MAX_PMR_DAM2 min _newPartDamage;
			if ((_unit getVariable "ace_w_revive" == -1) && {(_newPartDamage >= ARMS_LEGS_MAX_PMR_DAM)}) then {
				_unit setVariable ["ace_w_revive", time + ace_wounds_prevtime];
				[QGVAR(rev), [_unit]] call CBA_fnc_localEvent;
			};
		};
	};
	
	_rv = _newPartDamage;
	_state = _unit getVariable "ace_w_state";

	_unit setVariable [GVAR(parts) select _tp, _newPartDamage];
	
	if (_headbody) then {
		if (_newPartDamage >= 1) exitWith { _dead = true };
		if (_isp) then {
			[_unit, (_partDamage * STAMINA_COEF)] call FUNC(addStamina);
		};
		switch (true) do {
			case (_newPartDamage < STATE_800_HEAD_BODY_DAM_MAX && {_newPartDamage > 0}): {
				[_unit, if (_penetrated) then { if (_arterial) then { _bloss } else { _bloss/2 } } else { 0 }, (_bloss*0.9), 0] call FUNC(vchange);
				if (_state <= 800) then {
					_unit setVariable ["ace_w_state",800]; // state 800 = bleeding signs, pain
				};
			};
			case (_newPartDamage < STATE_801_HEAD_BODY_DAM_MAX && {_newPartDamage >= STATE_800_HEAD_BODY_DAM_MAX}): {
				_bloss = _bloss * STATE_801_BLOSS_COEF;
				[_unit, if (_penetrated) then { if (_arterial) then { _bloss } else { _bloss/2 } } else { 0 }, (_bloss*0.9), 0] call FUNC(vchange);
				if (_state <= 801) then {
					_unit setVariable ["ace_w_nextuncon", time];
					_unit setVariable ["ace_w_state",801]; // state 801 = blackouts every now and then, bleeding signs, pain
				};
			};
			case (_newPartDamage >= STATE_801_HEAD_BODY_DAM_MAX && {_newPartDamage < 1}): { // _newPartDamage > 1 for body and head = dead
				_bloss = _bloss * STATE_802_BLOSS_COEF;
				[_unit, if (_penetrated) then { if (_arterial) then { _bloss } else { _bloss/2 } } else { 0 }, (_bloss*0.9), 1] call FUNC(vchange);
				if (_state <= 802) then {
					_unit setVariable ["ace_w_unconlen", time + MAX_UNC_TIME];
					_unit setVariable ["ace_w_state",802]; // state 802 = complete blackout,
				};
			};
		};
	} else {
		if (_isp) then {
			[_unit, (_partDamage * STAMINA_COEF)] call FUNC(addStamina);
		};
		switch (true) do {
			case (_newPartDamage < STATE_800_ARMS_LEGS_DAM_MAX && {_newPartDamage > 0}): {
				[_unit, if (_penetrated) then { if (_arterial) then { _bloss } else { _bloss/2 } } else { 0 }, (_bloss*0.9), 0] call FUNC(vchange);
				if (_state <= 800) then {
					_unit setVariable ["ace_w_state",800];
				};
			};
			case (_newPartDamage < STATE_801_ARMS_LEGS_DAM_MAX && {_newPartDamage >= STATE_800_ARMS_LEGS_DAM_MAX}): {
				_bloss = _bloss * STATE_801_BLOSS_COEF;
				[_unit, if (_penetrated) then { if (_arterial) then { _bloss } else { _bloss/2 } } else { 0 }, (_bloss*0.9), 0] call FUNC(vchange);
				if (_state <= 801) then {
					_unit setVariable ["ace_w_nextuncon", time];
					_unit setVariable ["ace_w_state",801];
				};
			};
			case (_newPartDamage >= STATE_801_ARMS_LEGS_DAM_MAX): {
				_bloss = _bloss * STATE_802_BLOSS_COEF;
				[_unit, if (_penetrated) then { if (_arterial) then { _bloss } else { _bloss/2 } } else { 0 }, (_bloss*0.9), 1] call FUNC(vchange);
				if (_state <= 802) then {
					_unit setVariable ["ace_w_unconlen", time + MAX_UNC_TIME];
					_unit setVariable ["ace_w_state",802];
				};
			};
		};
	};

	// Each hit spurt out blood, on top of the increasing of the bloss applied every 0.15 by statehandler
	if (_penetrated && {_ammo != ""} && {!_dead}) then {
		if (_arterial) then {
			_tmpBl = _unit getVariable ["ace_w_bleed", 0];
			_extraBl = _bloss * HIT_BLOSS_COEF;
			_unit setVariable ["ace_w_bleed", _tmpBl + _extraBl];
			TRACE_1("Arterial bleeding added", _extraBl);
		} else {
			// If hit but not arterial, we do net get a bleeding value, therefore set a fake value
			_tmpBl = _unit getVariable ["ace_w_bleed", 0];
			_unit setVariable ["ace_w_bleed", _tmpBl + 0.00001];
			TRACE_1("Non arterial fake bleed added", "");
		};
	};
	TRACE_3("wounds debug 2", _bloss,_newPartDamage,_state);
};

if (_startStateHandler && {!_dead} && {_unit getVariable ["ace_w_fsm", 0] == 0}) then { // Start Statehandler if not already running, and not dead
	_unit setVariable ["ace_w_fsm", 1];
	[_unit] spawn FUNC(statehandler);
};

#ifdef DEBUG_MODE_FULL
	_curDam = [_unit] call FUNC(getDamage);
	_body = _unit getVariable ["ace_w_body", 0];
	_head = _unit getVariable ["ace_w_head_hit", 0];
	_hands = _unit getVariable ["ace_w_hands", 0];
	_legs = _unit getVariable ["ace_w_legs", 0];
	_data = [_body, _head, _hands, _legs, _unit getVariable ["ace_w_ha", []]];
#endif
TRACE_4("Return",_rv,_prevDamage,_data,typeOf _unit);

[QGVAR(hdeh), [_this, _rv]] call CBA_fnc_localEvent;

_rv;
