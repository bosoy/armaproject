// by Xeno
//#define __DEBUG__
#define THIS_FILE "x_playerspawn.sqf"
#include "x_setup.sqf"
#define __prma _p removeAction _id
#define __addbp __pSetVar [#d_pbp_id, _p addAction [_s call FUNC(GreyText), "x_client\x_backpack.sqf",[],-1,false]]

private ["_rtype", "_p", "_oabackpackmags", "_oabackpackweaps", "_ubp", "_ubackp", "_hasruck", "_ruckmags", "_ruckweapons", "_backwep", "_ident", "_id", "_types", "_type", "_ar", "_hh", "_primw", "_muzzles", "_bp", "_mags", "_mcount", "_i", "_weaps", "_s", "_action"];
PARAMS_1(_rtype);
__TRACE_1("","_rtype");

if (_rtype == 0) then { // player died
	if !(__WoundsVer) then {
		if (GVAR(WithRevive) == 1) then {
			_timediff = time - __pGetVar(GVAR(alivetimestart));
			_td = _timediff / 400;
			_trime = if (_td >= 1) then {
				GVAR(RespawnTime)
			} else {
				GVAR(RespawnTime) + (((1 - _td) * 10) * GVAR(RespawnTime))
			};
			_trime = _trime max 4;
			__TRACE_1("","_trime");
			setPlayerRespawnTime _trime;
		};
	};
	_p = player;
#ifdef __OA__
	if (GVAR(WithRevive) == 1) then {
		__pSetVar [QGVAR(is_leader), if (player == leader (group player)) then {group player} else {objNull}];
	};
	__TRACE("removing handleDamage eventhandlers");
	player removeAllEventHandlers "handleDamage";
	_oabackpackmags = [[],[]];
	_oabackpackweaps = [[],[]];
	_ubp = unitBackpack _p;
	_ubackp = if (!isNull _ubp) then {typeOf _ubp} else {""};
	if (_ubackp != "") then {
		_oabackpackmags = getMagazineCargo _ubp;
		_oabackpackweaps = getWeaponCargo _ubp;
	};
	__TRACE_3("","_oabackpackmags","_oabackpackweaps","_ubackp");
	__pSetVar [QGVAR(respawn_oabackpackmags), _oabackpackmags];
	__pSetVar [QGVAR(respawn_oabackpackweaps), _oabackpackweaps];
	__pSetVar [QGVAR(respawn_ubackp), _ubackp];
#endif

#ifdef __ACE__
	_hasruck = false;
	_ruckmags = [];
	_ruckweapons = [];
	if (_p call ace_sys_ruck_fnc_hasRuck) then {
		_ruckmags = __pGetVar(ACE_RuckMagContents);
		_hasruck = true;
		_ruckweapons = __pGetVar(ACE_RuckWepContents);
	};
	_backwep = __pGetVar(ACE_weapononback);
	_ident = __pGetVar(ACE_Identity);
	__pSetVar [QGVAR(respawn_hasruck), _hasruck];
	__pSetVar [QGVAR(respawn_ruckmags), _ruckmags];
	__pSetVar [QGVAR(respawn_ruckweapons), _ruckweapons];
	__pSetVar [QGVAR(respawn_backwep), _backwep];
	__pSetVar [QGVAR(respawn_ident), _ident];
#endif
	if (GVAR(weapon_respawn)) then {
		__pSetVar [QGVAR(respawn_weapons), weapons player];
		__pSetVar [QGVAR(respawn_magazines), magazines player];
		__pSetVar [QGVAR(respawn_items), items player];
	};
	if (GVAR(WithBackpack)) then {
		_id = __pGetVar(GVAR(pbp_id));
		if (_id != -9999) then {
			__prma;
			__pSetVar [QGVAR(pbp_id), -9999];
		};
	};
	if (!isNil QGVAR(action_menus_type)) then {
		if (count GVAR(action_menus_type) > 0) then {
			{
				_types = _x select 0;
				if (count _types > 0) then {
					if (_type in _types) then {
						_id = _x select 3;
						__prma;
					};
				} else {
					_id = _x select 3;
					__prma;
				};
			} forEach GVAR(action_menus_type);
		};
	};
	if (!isNil QGVAR(action_menus_unit)) then {
		if (count GVAR(action_menus_unit) > 0) then {
			{
				_types = _x select 0;
				_ar = _x;
				if (count _types > 0) then {
					{
						_hh = __getMNsVar2(_x);
						if (_p ==  _hh) exitWith { 
							_id = _ar select 3;
							__prma;
						};
					} forEach _types
				} else {
					_id = _x select 3;
					__prma;
				};
			} forEach GVAR(action_menus_unit);
		};
	};
	private "_trencho";
	_trencho = __pGetVar(GVAR(trench));
	if (!isNull _trencho) then {
		deleteVehicle _trencho;
		__pSetVar [QGVAR(trench), objNull];
	};
} else { // _rtype = 1, player has respawned
	__pSetVar [QGVAR(alivetimestart), time];
	GVAR(commandingMenuIniting) = false;
	player removeAllEventHandlers "handleDamage";
	if (GVAR(WithRevive) == 1) then {
		player addEventHandler ["handleDamage", {_this call FUNC(playerHD)}];
	} else {
		player addEventHandler ["handleDamage", {_this call xr_fnc_ClientHD}];
	};
	xr_phd_invulnerable = true;
	__pSetVar ["ace_w_allow_dam", false];
#ifdef __OA__
	removeBackpack player;
#endif
	_p = player;
	if (GVAR(weapon_respawn)) then {
		removeAllItems _p;
		removeAllWeapons _p;
		#define __addmx _p addMagazine _x
		#define __addwx _p addWeapon _x
		if (count GVAR(custom_layout) > 0) then {
			{__addmx} forEach (GVAR(custom_layout) select 1);
			{
				if (getNumber (configFile >> "CfgWeapons" >> _x >> "ace_isusedweapon") == 0) then {
					__addwx;
				};
			} forEach (GVAR(custom_layout) select 0);
		} else {
			{__addmx} forEach __pGetVar(GVAR(respawn_magazines));
			{
				if (getNumber (configFile >> "CfgWeapons" >> _x >> "ace_isusedweapon") == 0) then {
					__addwx;
				};
			} forEach __pGetVar(GVAR(respawn_weapons));
			{if !(_p hasWeapon _x) then {__addwx}} forEach __pGetVar(GVAR(respawn_items));			
			if (count GVAR(backpack_helper) > 0) then {
				{__addmx} forEach (GVAR(backpack_helper) select 0);
				{
					if (getNumber (configFile >> "CfgWeapons" >> _x >> "ace_isusedweapon") == 0) then {
						__addwx;
					};
				} forEach (GVAR(backpack_helper) select 1);
				GVAR(backpack_helper) = [];
			};
		};
		if (GVAR(WithBackpack)) then {
			if (count __pGetVar(GVAR(custom_backpack)) > 0) then {
				__pSetVar [QGVAR(player_backpack), [__pGetVar(GVAR(custom_backpack)) select 0, __pGetVar(GVAR(custom_backpack)) select 1]];
			};
		};
#ifdef __ACE__
		if (!isNil QGVAR(custom_ruckbkw)) then {
			if (typeName GVAR(custom_ruckbkw) == "STRING") then {_backwep = GVAR(custom_ruckbkw)};
		};
		if (!isNil QGVAR(custom_ruckmag)) then {
			if (typeName GVAR(custom_ruckmag) == "ARRAY") then {_ruckmags = GVAR(custom_ruckmag)};
		};
		if (!isNil QGVAR(custom_ruckwep)) then {
			if (typeName GVAR(custom_ruckwep) == "ARRAY") then {_ruckweapons = GVAR(custom_ruckwep)};
		};
		if (__pGetVar(GVAR(earwear))) then {
			if !(_p hasWeapon "ACE_Earplugs") then {_p addWeapon "ACE_Earplugs"}
		};
#endif
		_primw = primaryWeapon _p;
		if (_primw != "") then {
			_p selectWeapon _primw;
			_muzzles = getArray(configFile>>"cfgWeapons" >> _primw >> "muzzles");
			_p selectWeapon (_muzzles select 0);
		};
#ifdef __OA__
		_ubackp = __pGetVar(GVAR(respawn_ubackp));
		if (_ubackp != "") then {
			if (!isNull (unitBackpack _p)) then {removeBackpack _p};
			_p addBackpack _ubackp;
			_bp = unitBackpack _p;
			clearMagazineCargo _bp;
			clearWeaponCargo _bp;
			_oabackpackmags = __pGetVar(GVAR(respawn_oabackpackmags));
			_oabackpackweaps = __pGetVar(GVAR(respawn_oabackpackweaps));
			if (count (_oabackpackmags select 0) > 0) then {
				_mags = _oabackpackmags select 0;
				_mcount = _oabackpackmags select 1;
				{_bp addMagazineCargo [_x, _mcount select _forEachIndex]} forEach _mags;
			};
			if (count (_oabackpackweaps select 0) > 0) then {
				_weaps = _oabackpackweaps select 0;
				_mcount = _oabackpackweaps select 1;
				{_bp addWeaponCargo [_x, _mcount select _forEachIndex]} forEach _weaps;
			};
		};
#endif
	};
	"RadialBlur" ppEffectAdjust [0.0, 0.0, 0.0, 0.0];
	"RadialBlur" ppEffectCommit 0;
	"RadialBlur" ppEffectEnable false;
#ifdef __ACE__
	_hasruck = __pGetVar(GVAR(respawn_hasruck));
	if (_hasruck) then {
		_ruckmags = __pGetVar(GVAR(respawn_ruckmags));
		_ruckweapons = __pGetVar(GVAR(respawn_ruckweapons));
		if (!isNil "_ruckmags") then {__pSetVar ["ACE_RuckMagContents", _ruckmags]};
		if (!isNil "_ruckweapons") then {__pSetVar ["ACE_RuckWepContents", _ruckweapons]};
	};
	_backwep = __pGetVar(GVAR(respawn_backwep));
	if (!isNil "_backwep") then {if ((typeName _backwep) == "STRING") then {__pSetVar ["ACE_weapononback", _backwep]}};
	ACE_MvmtFV = 0;ACE_FireFV = 0;ACE_WoundFV = 0;ACE_FV = 0;
	ACE_Heartbeat = [0,20];ACE_Blackout = 0;ACE_Breathing = 0;
#endif

	if (GVAR(with_ai)) then {
		if (rating _p < 20000) then {_p addRating 20000};
	};
	if (GVAR(with_ai) || GVAR(with_ai_features) == 0) then {
		if (rating _p < 20000) then {_p addRating 20000};
	};
	if (GVAR(WithBackpack)) then {
		if (count __pGetVar(GVAR(player_backpack)) == 0) then {
			if (primaryWeapon _p != "" && {primaryWeapon _p != " "}) then {
				_s = format [(localize "STR_DOM_MISSIONSTRING_155"), [primaryWeapon _p,1] call FUNC(GetDisplayName)];
				if (__pGetVar(GVAR(pbp_id)) == -9999) then {__addbp};
			};
		} else {
			_s = format [(localize "STR_DOM_MISSIONSTRING_154"), [__pGetVar(GVAR(player_backpack)) select 0,1] call FUNC(GetDisplayName)];
			if (__pGetVar(GVAR(pbp_id)) == -9999) then {__addbp};
		};
	};
	if (!isNil QGVAR(action_menus_type)) then {
		if (count GVAR(action_menus_type) > 0) then {
			{
				_types = _x select 0;
				if (count _types > 0) then {
					if (_type in _types) then { 
						_action = _p addAction [(_x select 1) call FUNC(GreyText),_x select 2,[],-1,false];
						_x set [3, _action];
					};
				} else {
					_action = _p addAction [(_x select 1) call FUNC(GreyText),_x select 2,[],-1,false];
					_x set [3, _action];
				};
			} forEach GVAR(action_menus_type);
		};
	};
	if (!isNil QGVAR(action_menus_unit)) then {
		if (count GVAR(action_menus_unit) > 0) then {
			{
				_types = _x select 0;
				_ar = _x;
				if (count _types > 0) then {
					{
						_hh = __getMNsVar2(_x);
						if (_p ==  _hh) exitWith { 
							_action = _p addAction [(_ar select 1) call FUNC(GreyText),_ar select 2,[],-1,false];
							_ar set [3, _action];
						};
					} forEach _types
				} else {
					_action = _p addAction [(_x select 1) call FUNC(GreyText),_x select 2,[],-1,false];
					_x set [3, _action];
				};
			} forEach GVAR(action_menus_unit);
		};
	};
	if (!isNil {__pGetVar(GVAR(bike_created))}) then {__pSetVar [QGVAR(bike_created), false]};
	
	if (GVAR(WithRevive) == 1) then {
		deleteVehicle ((_this select 1) select 1);
	};
	
#ifndef __ACE__
	if (_p hasWeapon "NVGoggles") then {if (daytime > 19.75 || daytime < 4.15) then {_p action ["NVGoggles",_p]}};
#endif
	0 spawn {
		private "_ident";
		waitUntil {!dialog};
		sleep 5;
		xr_phd_invulnerable = false;
		__pSetVar ["ace_w_allow_dam", nil];
#ifdef __ACE__
		_ident = __pGetVar(GVAR(respawn_ident));
		if (_ident != "") then {
			if (isClass(configFile >> "CfgWeapons" >> _ident) && !(player hasWeapon _ident)) then {player addWeapon _ident};
			[player, _ident] execFSM '\x\ace\addons\sys_goggles\use_glasses.fsm';
		};
#endif
	};
	if (GVAR(WithRevive) == 1) then {
		if !(isNull __pGetVar(GVAR(is_leader))) then {
			[QGVAR(grpl), [__pGetVar(GVAR(is_leader)), player]] call FUNC(NetCallEventSTO);
		};
	};
};