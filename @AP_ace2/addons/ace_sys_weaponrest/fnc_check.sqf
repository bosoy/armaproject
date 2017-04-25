#include "script_component.hpp"

#define __amount 			12
#define __dy 			0.02
#define __dz 			0.26
#define __y0 			1.1

#define __stand ["amovpercmstpsraswrfldnon", "aidlpercmstpsraswrfldnon_aiming01", "aidlpercmstpsraswrfldnon_idlesteady01", "aidlpercmstpsraswrfldnon_idlesteady02", "aidlpercmstpsraswrfldnon_idlesteady03", "aidlpercmstpsraswrfldnon_idlesteady04", "aidlpercmstpsraswrfldnon_aiming02"]
#define __kneel ["amovpknlmstpsraswrfldnon", "aidlpknlmstpsraswrfldnon_player_idlesteady01", "aidlpknlmstpsraswrfldnon_player_idlesteady02", "aidlpknlmstpsraswrfldnon_player_idlesteady03", "aidlpknlmstpsraswrfldnon_player_idlesteady04"]
#define __prone ["amovppnemstpsraswrfldnon"]

#define __animsteadystanding 	"AmovPercMstpSrasWrflDnon_Steady"
#define __animstanding	__stand	//"AmovPercMstpSrasWrflDnon"
#define __animsteadykneeling 	"AmovPknlMstpSrasWrflDnon_Steady"
#define __animkneeling 	__kneel	//"AmovPknlMstpSrasWrflDnon"
#define __animprone_bipod	"AmovPpneMstpSrasWrflDnon_Bipod"
#define __animprone	__prone	//"AmovPpneMstpSrasWrflDnon"

#define __check getNumber(configFile >> "CfgWeapons" >> primaryWeapon player >> "ace_bipod")
#define __weight getNumber(configFile >> "CfgWeapons" >> primaryWeapon player >> "ACE_Weight")

TRACE_1("",_this);
private["_snd", "_vec", "_men", "_zcoords", "_deleted", "_detectors", "_wd", "_dir0", "_wdx", "_wdy", "_wdz", "_res", "_dir", "_minheight", "_t1", "_offset1", "_z1", "_zinit", "_dy", "_dz", "_cfg", "_n", "_x", "_anim", "_obj", "_t", "_pos", "_z", "_pos1", "_do", "_offset", "_oldanim", "_OnT"];

PARAMS_1(_currentAnim);

if (_currentAnim in __animprone) exitwith {
	// Bipods
	if (__check == 1) then { [__animprone_bipod,__animprone, localize "STR_ACE_BIPOD", false] call ace_sys_weaponrest_fnc_bipod; };

	// Rest weapon on sandbag or rucksack crate (if installed)
	if ([player,1.5] call ace_sys_weaponrest_fnc_sB) then { [__animprone_bipod,__animprone, localize "STR_ACE_DEPLOYED", true] call ace_sys_weaponrest_fnc_bipod; };
};

// Rest weapon standing or kneeling
_OnT = ([player,2.5] call ace_sys_weaponrest_fnc_Tp && {__weight > 9.9});
if (_currentAnim in __animkneeling) then {
	_offset = [0.1,__y0, 0.9];
	_anim = __animsteadykneeling;
	_oldanim = _currentAnim; //__animkneeling;
} else {
	_offset = [0.1,__y0, 1.3];
	_anim = __animsteadystanding;
	_oldanim = _currentAnim; //__animstanding;
};
_zinit = _offset select 2;
_minheight = _zinit - __dz;
_detectors = [];
_zcoords = [];
_deleted = 0;
_do  = false;
_offset1 = +_offset;
_wd = player weapondirection (primaryweapon player);

// *** creating an array of detectors with _dy m between them

for "_i" from 0 to __amount do {
	//_offset set [0,(_offset1 select 0) + (_i mod 2)/10];
	_offset set [1,(_offset select 1) + __dy + (random _i / 10)]; /* reduces FPS lag due to mass collision in small space enormously! */
	_pos = player ModelToWorld _offset;
	_t = "ACE_B_Detector" createvehicleLocal [0, 0, 0];
	_t setvectordir _wd;
	_t setpos _pos; //TODO: ASL/ATL conversion
	_detectors set [_i,_t];
};

// *** waiting until all of them reach an obstacle and get deleted, tracking their last z coord

while { true } do {
	_deleted = 0;
	for "_i" from 0 to __amount do {
		_t = _detectors select _i;
		if (alive _t) then {
			_z = (player worldToModel (getpos _t)) select 2; //TODO: ASL/ATL conversion
			_zcoords set [_i,_z];
			if (_z < 0) then { deletevehicle _t };
		} else {
			INC(_deleted);
		};
	};
	//hint format ["z: %1 deleted: %2", _zcoords,_deleted];
	if (_deleted == (__amount + 1)) exitwith {};
	sleep 0.001;
};

{
	if (_x >= _minheight) exitWith { _do = true };
} foreach _zcoords;

if (! _do) exitwith { /*player sidechat "Can't rest the weapon here"*/ };

// *** don't rest the weapon on people
_men = (player modeltoworld [_offset1 select 0,_offset1 select 1, 0]) nearEntities ["CaManBase", 1];
_t = count _men;
if (player in _men) then { _t = _t - 1 };
_dir0 = (_wd select 0) atan2 (_wd select 1);
if (_dir0 < 0) then { _dir0 = _dir0 + 360 };

if (_t > 0) then {
	{
		if (_x != player) then {
			_t = getpos _x;
			_vec = [(_t select 0)-(getpos player select 0),(_t select 1)-(getpos player select 1)];  //TODO: ASL/ATL conversion
			_dir = (_vec select 0) atan2 (_vec select 1);
			if (_dir < 0) then { _dir = _dir + 360 };
			_res = _dir0 - _dir;
			switch (true) do {
				case (_res < -180): { _res = 360 + _res };
				case (_res > 180): { _res = _res - 360 };
			};
			//player sidechat format ["difference: %1", _res];
			if (abs _res <= 10) exitwith { _do = false };
		};
		if (!_do) exitWith {};
	} foreach _men;
};
if (!_do) exitwith { /* player sidechat "Can't rest the weapon on people" */ };

// *** resting the weapon

_snd = format ["ace_deployweapon_%1", round (1 + random 2)];
_t = "ACE_LogicDummy" createVehicleLocal (player ModelToWorld _offset1);
_t say _snd;

// *** Visual feedback
(localize "STR_ACE_DEPLOYED") spawn ace_fnc_visual;

player switchmove _anim;
if (_OnT) exitWith {
	_SB = nearestObjects [player, ["ACE_SniperTripod"], 2.5] select 0;
	if (!isNull _SB) then {
		_n = _SB animationPhase "slide_down_tripod";
		if (_n == 0) then {
			{ _SB animate [_x,1] } foreach ["slide_down_tripod","retract_leg_1","retract_leg_2","retract_leg_3"];
			player switchmove _oldanim;
		} else {
			(localize "STR_ACE_DEPLOYED_HEAVY") spawn ace_fnc_visual;
			player switchmove _oldanim;
		};
	};
};
//turn limitation, exit if weapon is turned too much from the initial heading
while {(animationstate player) == _anim } do {
	_wd = player weapondirection (primaryweapon player);
	_dir = (_wd select 0) atan2 (_wd select 1);
	if (_dir < 0) then { _dir = _dir + 360 };
	_res = _dir0 - _dir;
	switch (true) do {
		case (_res < -180): { _res = 360 + _res };
		case (_res > 180): { _res = _res - 360 };
	};
	if (abs _res > 25) exitwith { player switchmove _oldanim;};
	sleep 0.5;
};
deletevehicle _t;
