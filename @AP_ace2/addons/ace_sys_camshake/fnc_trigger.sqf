//#define DEBUG_MODE_FULL
#include "script_component.hpp"
PARAMS_2(_pos,_ihr); //[_pos,_ihr,_ammoType,_m]

_o = (vehicle player);
_ihr = _ihr*4;
_expDistance = (getPosASL _o) distance _pos; //diag_log format ["Start :: Exp Distnace: %1",_expDistance];

// Effect dont need to play on dedicated
if (!isDedicated) then {
	_intensity = overcast+(rain)+(random 0.5);
	if (overcast < 0.75) then {
		_intensity = _intensity*(overcast/1);
	};
	//player sideChat format["shock: %1", _intensity];
	_shockWaveDistance = (_ihr)*_intensity; //diag_log format ["Shockwave Distance: %1",_shockWaveDistance];

	drop ["\Ca\Data\missileSmoke","","Billboard",1,(_shockWaveDistance/340.29),(ASLtoATL _pos),[0,0,0],1,1.275,0.0,0.0,[0,_shockWaveDistance*0.75, _shockWaveDistance*0.85, _shockWaveDistance*0.9, _shockWaveDistance],[[1,1,1,2*_intensity], [1,1,1,0]],[0],0.0,2.0,"","",""];
};

if (_expDistance > _ihr) exitWith { TRACE_1("exiting expl distance > ihr","") };
TRACE_1("",_ar);

TRACE_1("",_o);
_params = [_pos,_ihr,_at,_m,_ar,_o];
// switch ...
FUNC(fxFunc) = {
	private "_dist";

	_pos = _this select 0;
	_ihr = _this select 1;
	_at = _this select 2;
	_m = _this select 3;
	_ar = _this select 4;
	_o = _this select 5;
	
	_dist = _pos distance (getPosASL _o); //diag_log format ["fxFunc:: Dist : %1",_dist];
	_disCoef = ((1-(_dist/_ihr)) max 0) min 1; //diag_log format ["Dist Coef: %1",_disCoef];
	_turnedOut = false;
	if (_o != player) then {
		_turnedOut = [player] call ACE_fnc_isTurnedOut;
	};
	
	if (_o == player || {_turnedOut} || {_o isKindOf "StaticWeapon"} || {_o isKindOf "Motorcycle"}) then {
		_testPos = +_pos;
		_testPos set[2, (_testPos select 2)+1];
		_count = (count lineIntersectsWith [_testPos, (eyePos player)]);
		_divisor = 1-((0.25*_count) min 1);
		_ihr = _ihr*_divisor;
		//player sideChat format["d: %1 %2", _divisor, _count];
		//player sideChat format["exposed human: %1", _turnedOut];
		135997 cutText["", "BLACK IN", .5];
		135997 cutFadeOut .5;
		
		[player,1.25*_disCoef,1*_disCoef] call ace_fx_fnc_flash;
		[player,(_ihr/20)*_disCoef,log(((_ihr/60)*_disCoef))] call ace_fx_fnc_dizzy;
		if (_dist < _ihr/3) then {
			if (_dist < _ihr/2) then {
				[player,25*_disCoef] call ace_fx_fnc_deaf;
				[player,false,nil,nil,false] call ace_fx_fnc_ring; // Ring
				if (random 1 > 0.5 && {!_turnedOut}) then {
					if (_o isKindOf "StaticWeapon" || {_o isKindOf "Motorcycle"}) then {
						//player sideChat "EJECT!";
						player action ["eject", _o];
					};
					[player,7*_disCoef,true] spawn ace_fx_fnc_knockout;
				};
			} else {
				[player,1,true] spawn ace_fx_fnc_knockout;
			};
		};
	} else {
		// player sideChat "unexposed human";
		_doEffects = true;
		if (_o isKindOf "Helicopter" || {_o isKindOf "Plane"}) then {
			if (((getPos _o) select 2) > 10 || {speed _o > 50}) then {
				_doEffects = false;
			};
		};
		if(_doEffects) then {			
			if (_o isKindOf "Tank" || {(_o isKindOf "Car")}) exitWith {
				if (_turnedOut) then {
					[player,(_ihr/10)*_disCoef,log(((_ihr/20)*_disCoef))] call ace_fx_fnc_dizzy;
					if(_dist < _ihr/10) then {
						[player,1*_disCoef,1*_disCoef] call ace_fx_fnc_flash;
						[player,false,nil,nil,false] call ace_fx_fnc_ring;
					};
				};
			};
		};
	};
};
_delayTime = time + (_expDistance/340.29);
//player sideChat format["delay: %1", (_expDistance/340.29)];
_delayFunc = {
	private ["_delayTime", "_params"];
	_delayTime = (_this select 0) select 0; //diag_log format ["delaytime %1",_delayTime];
	_params = (_this select 0) select 1; //diag_log format ["params %1",_params];
	//player sidechat "waiting for bang";
	if(time >= _delayTime) then {
		
		//player sideChat format["shock!"];
		_params call FUNC(fxFunc);
		[(_this select 1)] call cba_fnc_removePerFramehandler; //diag_log "pfh removed";
	};
};

[_delayFunc, 0, [_delayTime, _params]] call cba_fnc_addPerFramehandler; //diag_log "pfh started";
//player sideChat "TRIGGGGGER!";
