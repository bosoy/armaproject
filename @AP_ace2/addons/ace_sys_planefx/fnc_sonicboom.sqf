private ["_emitter", "_lastspeed", "_currentspeed"];

_emitter = "#particlesource" createVehicleLocal position _this;
_emitter setParticleRandom [0.05,[2,2,2],[5,5,5],0,0.5,[0.1,0.1,0.1,0.5],0,0];
_emitter setDropInterval 0;
_lastspeed = 0;

while {alive _this} do {
	if (speed _this > 750 && {((positionCameraToWorld [0,0,0]) distance _this < (viewDistance min 3000))}) then {
		_currentspeed = speed _this;
		if (_currentspeed > 850 && {_currentspeed < 860} && {_lastspeed < _currentspeed}) then {
			_emitter setPosASL (getposASL _this);
			_emitter setDropInterval 0.0005;
			for "_i" from 1 to 100 do {
				_emitter setParticleRandom [0.4,[10*(_i/100),10*(_i/100),10*(_i/100)],[10*(_i/100),10*(_i/100),10*(_i/100)],0,0.3,[0.1,0.15,0.3,0.5],0,0];
				_emitter setParticleParams ["\Ca\data\cl_basic","","Billboard",1,0.1,[0,(-8*(_i/100)+8),-0.5],(velocity _this),1,1.2745,1,0.001,[20*(_i/100)],[[1,1,1,0],[1,1,1,0.1*(_i/100)],[1,1,1,0]],[0],0,0,"","",_this];
				sleep 0.005;
			};
			_emitter setDropInterval 0;
			sleep 1; //faking here :P
			if !(player in _this) then {playSound "ace_fx_sonicboom"};
			sleep ((random 5)+ 5);
		} else {
			_emitter setDropInterval 0
		};
		_lastspeed = speed _this;
		sleep 0.356759;
	} else {
		sleep 2.11;
	};
};
deleteVehicle _emitter;
