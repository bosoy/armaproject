_particles = [];
if (_this == "mist") then {

	_pos = position player;
	_mist = "#particlesource" createVehicleLocal _pos;
	_mist setParticleRandom [0, [50, 50, 0], [0, 0, 0], 0, 0, [0, 0, 0, 0], 0, 0];
	_mist setParticleCircle [0.1, [1, 1, 0]];
	_mist setDropInterval 0.01;

	while {true} do {
		_mist setParticleParams [["\Ca\Data\Cl_basic.p3d", 1, 0, 1], "", "Billboard", 1, 30, [0, 0, 0], [0, 0, 0], 1, 1.275, 1, 0.1, [6, 15], [[0.8, 0.8, 0.8 ,0], [0.8, 0.8, 0.8, 0.1], [0.8, 0.8, 0.8, 0]], [0, 1], 1, 0, "", "", player];
		sleep 1;
	};

} else {
	_pos = position player;
	_dust = "#particlesource" createVehicleLocal _pos;
	_dust setParticleRandom [0, [30, 30, 0], [0, 0, 0], 0, 0, [0, 0, 0, 0], 0, 0];
	_dust setParticleCircle [0.1, [1, 1, 0]];
	_dust setDropInterval 0.1;

	while {true} do {
		_dust setParticleParams [["\Ca\Data\Cl_basic.p3d", 1, 0, 1], "", "Billboard", 1, 10, [1, 0, 0], [0,0,0], 5, 0.2, 0.1568, 0.0, [4, 13], [[0.7,0.6,0.5,0.0],[0.7,0.6,0.5,0.2],[0.7,0.6,0.5,0.0]], [0, 1], 1, 0, "", "", player];
		sleep 1;
	};
};