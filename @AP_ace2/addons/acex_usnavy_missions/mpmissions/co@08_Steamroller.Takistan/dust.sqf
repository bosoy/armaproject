//By CarlGustaffa
//Dust based on wind and no rain.
[] spawn {
	while {true} do {
		if (rain == 0) then {
			_obj = vehicle player;
			_pos = getPosASL _obj;
			_multiplier = 1 + (_pos select 2) / 1400; //means wind effect is 1.5x at 700 meter altitude.
			_velocity = [_multiplier * (wind select 0), _multiplier * (wind select 1),0];
			_color = [1.0, 0.9, 0.8];
			_wforce = sqrt ((wind select 0)^2+(wind select 1)^2);
			_wforce = 0.1 * ((_wforce - 5.55) max 0); //Dust starts to raise here according to Beaufort scale.
			_wforce = _wforce * (1 - sqrt(rain));
			_range = 0.25 * _wforce * _multiplier;
			_alpha = _range + random _range;
			_ps = "#particlesource" createVehicleLocal _pos;  
			_ps setParticleParams [["\Ca\Data\ParticleEffects\Universal\universal.p3d", 16, 12, 8], "", "Billboard", 1, 3, [0, 0, -6], _velocity, 1, 1.275, 1, 0, [9], [_color + [0], _color + [_alpha], _color + [0]], [1000], 1, 0, "", "", _obj];
			_ps setParticleRandom [3, [30, 30, 0], [0, 0, 0], 1, 0, [0, 0, 0, 0.01], 0, 0];
			_ps setParticleCircle [0.1, [0, 0, 0]];
			_ps setDropInterval 0.01;
			sleep 10;
			deleteVehicle _ps;
			sleep 0.1;
		} else {
			sleep 10;
		};
	};
};