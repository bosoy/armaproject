#define COLUMN_PERCENT 0.55
#define RISETIME 0.5

#define TICK_RATE 0.05
#define OVERLAP 1.8

#define GROW_RATE 1.002

#define RED_DECAY 0.99
#define GREEN_DECAY 0.98
#define BLUE_DECAY 0.96

#define ALPHA_INITIAL 20
#define ALPHA_DECAY 0.700
#define ALPHA_THRESHOLD 0.02

#define GLARE_INITIAL 100
#define GLARE_DECAY .955

#define FLASH_DURATION 0.2
#define FLASH_DARKTIME 0.1

#define LIGHT1_INITIAL 50
#define LIGHT1_DECAY .950
#define LIGHT2_THRESHOLD 6
#define LIGHT2_DECAY .94

#define RISE_SPEED TICK_RATE*2495/112

private [
	"_pos",
	"_yield",
	"_Glare",
	"_Fireball",
	"_fireball_size",
	"_fireball_life",
	"_column_life",
	"_column_size",
	"_cloud_base1",
	"_Base_PA",
	"_Base_PA_WA",
	"_C1",
	"_light",
	"_airburst_threshold_2"];

_pos = _this select 0;
_yield = _this select 1;

_Glare = {
	private ["_pos","_light","_glare","_cooltime","_cooltick","_i"];

	_pos = _this select 0;
	_cooltime = _this select 1;

	_glare = GLARE_INITIAL*100;
	_light = "#lightpoint" createvehicleLocal [0,0,0];
	_light setpos _pos;
	_light setLightBrightness _glare;
	_light setLightAmbient[0.8*_glare, 0.9*_glare, 1.0*_glare];
	_light setLightColor[1, 1, 1];

	sleep FLASH_DURATION;

	_light setLightBrightness 0;
	_light setLightAmbient[0, 0, 0];
	_light setLightColor[0, 0, 0];

	sleep FLASH_DARKTIME;

	_cooltick = _cooltime/100;

	for [{_i = 0}, {_i < 100}, {_i = _i + 1}] do {
		_glare = GLARE_INITIAL*(GLARE_DECAY^_i);
		_light setLightBrightness _glare;
		_light setLightAmbient[0.8*_glare, 0.9*_glare, 1.0*_glare];
		sleep _cooltick;
	};

	deleteVehicle _light;
};

_Fireball = {
	private[
		"_pos",
		"_radius",
		"_glare",
		"_radius2",
		"_growtime",
		"_cooltime",
		"_glare_handle"];

	_pos = _this select 0;
	_radius = _this select 1;
	_glare = _this select 2;

	_radius2 = _radius*4.5;
	_growtime = _radius/1000;
	_cooltime = 0.04*(_radius2^(4/5));

	_glare_handle = [_pos, _cooltime] spawn _Glare;

	drop [
		"\Ca\Data\kouleSvetlo.p3d",
		"",
		"Billboard",
		1,
		_growtime,
		_pos,
		[0, 0, 0],
		1,
		1.3,
		1.0,
		0.0,
		[0, _radius],
		[[1.0, 1.0, 1.0, -10.0], [1.0, 0.7, 0.4, -1.0]],
		[0],
		0.0,
		0.0,
		"",
		"",
		""
	];

	sleep (_growtime - 0.05);

	drop [
		"\Ca\Data\kouleSvetlo.p3d",
		"",
		"Billboard",
		1,
		_cooltime,
		_pos,
		[0, 0, 0],
		1,
		1.3,
		1.0,
		0.0,
		[_radius2],
		[[1.0, 0.7, 0.4, 1.0], [1.0, 0.6, 0.3, 0.0]],
		[0],
		0.0,
		0.0,
		"",
		"",
		""
	];

	waitUntil {scriptDone _glare_handle};
};

_C1 = _yield^(1/5);

_airburst_threshold_2 = 68.58*_C1^2;

if ( (_pos select 2) < _airburst_threshold_2 ) then {
	_fireball_size = 80*_C1^(3/2);
	_fireball_life = 121.41*_C1;
	_column_size = _fireball_size/((1.25*_C1)^(4/5));
	_column_life = COLUMN_PERCENT*_fireball_life;

	_cloud_base1 = "#particlesource" createVehicleLocal _pos;

	// Cloud base - debris rushing inward.
	_Base_PA = [
		["\Ca\Data\ParticleEffects\Universal\Universal.p3d", 16, 7, 48, 1],
		"",
		"Billboard",
		1,
		35.0,
		[0, 0, 0],
		[0, 0, 0],
		1.0,
		1.275,
		1,
		0.001,
		[30, 60],
		[
			[0.40, 0.26, 0.13, 0.04],
			[0.40, 0.26, 0.13, 0.6],
			[0.40, 0.26, 0.13, 0.8],
			[0.40, 0.26, 0.13, 0.7],
			[0.40, 0.26, 0.13, 0]
		],
		[0.5],
		1,
		0,
		"",
		"",
		""
	];

	// Cloud base WATER - debris rushing inward.
	_Base_PA_WA = [
		["\Ca\Data\ParticleEffects\Universal\Universal.p3d", 16, 12, 8, 1],
		"",
		"Billboard",
		1,
		35.0,
		[0, 0, 0],
		[0, 0, 0],
		1.0,
		1.275,
		1,
		0.001,
		[30, 60],
		[
			[1, 1, 1, 0.04],
			[1, 1, 1, 0.6],
			[1, 1, 1, 0.8],
			[1, 1, 1, 0.7],
			[1, 1, 1, 0]
		],
		[0.5],
		1,
		0,
		"",
		"",
		""
	];

	[_pos, _fireball_size, _Glare] spawn _Fireball;

	sleep 1;

// Light
	_light = "logic" createvehicleLocal [0, 0, 0];
	_light setpos _pos;

	[_light, _fireball_life] spawn {
		// 112 seconds - 2495m
		private [
			"_light_logic",
			"_life",
			"_vel",
			"_pos",
			"_elapsed",
			"_time_ini"];

		_light_logic = _this select 0;
		_life = _this select 1;

		_vel = 2495/112;
		_pos = getPos _light_logic;
		_elapsed = 0;
		_time_ini = dayTime*3600;

		// 50 secs before no hat light is gone
		while {_elapsed < (_life - 50)} do {
			_pos = [
				(_pos select 0) + (wind select 0)*_elapsed*0.02,
				(_pos select 1) + (wind select 1)*_elapsed*0.02,
				(_pos select 2) + _vel*0.5
			];
			_light_logic setPos _pos;
			sleep 0.5;
			_elapsed = (dayTime*3600) - _time_ini;
		};

		deleteVehicle _light_logic;
	};


	[_light, _fireball_life] spawn {
		// 112 seconds - 2495m
		private [
			"_light_logic",
			"_life",
			"_light",
			"_elapsed",
			"_tick",
			"_intensity",
			"_time_ini",
			"_red",
			"_green",
			"_blue",
			"_rate"];

		_light_logic = _this select 0;
		_life = _this select 1;

		_intensity = LIGHT1_INITIAL;

		_light = "#lightpoint" createvehicleLocal [0,0,0];
		_light setLightBrightness _intensity;
		_light setLightAmbient[1.0, 0.8, 0.5];
		_light setLightColor[1.0, 0.8, 0.5];

		_elapsed = 0;
		_time_ini = dayTime*3600;

		// 50 secs before no hat light is gone
		while {_elapsed < (_life - 60)} do {
			if ( _intensity > LIGHT2_THRESHOLD ) then {
				_intensity = LIGHT1_INITIAL*(LIGHT1_DECAY^_elapsed);
			} else {
				_intensity = LIGHT1_INITIAL*(LIGHT2_DECAY^_elapsed);
			};

			_red = RED_DECAY^_elapsed;
			_green = GREEN_DECAY^_elapsed;
			_blue = BLUE_DECAY^_elapsed;

			if (_intensity > 5) then {
				_light setLightBrightness _intensity;
				_light setLightAmbient[_red, _green, _blue];
				_light setLightColor[_red, _green, _blue];
			};

			if (!isNull _light_logic) then {
				_light setPos getPos _light_logic;
			};

			sleep 0.1;
			_elapsed = (dayTime*3600) - _time_ini;
		};

		_intensity = 5;
		_tick = 0.05;
		_rate = _intensity / (2/_tick);

		while {_intensity > 0} do {
			_intensity = _intensity - _rate;
			_light setLightBrightness _intensity;
			sleep _tick;
		};

		deleteVehicle _light;
	};



// Cap ascending
	[_pos, _fireball_size, _fireball_life, _light] spawn {
		private [
			"_pos_ini",
			"_size",
			"_life",
			"_light",
			"_cap_size",
			"_particle_size",
			"_pos",
			"_elapsed",
			"_vel",
			"_ang",
			"_rpos",
			"_rdir",
			"_time_ini",
			"_alt",
			"_max_alt",
			"_radius_inc",
			"_radius_delta",
			"_max_radius",
			"_min_radius",
			"_water",
			"_water_old",
			"_shape",
			"_colors",
			"_sizes",
			"_phaseTimings",
			"_randomIntensity",
			"_particle_life",
			"_angv",
			"_angs",
			"_lifes",
			"_branches",
			"_delta",
			"_num_steps",
			"_radius"];
			

		_pos_ini = _this select 0;
		_size = _this select 1;
		_life = _this select 2;
		_light = _this select 3;

		_cap_size = 4.0*_size;
		_ang = 0;
		_time_ini = dayTime*3600;
		_elapsed = 0;
		_radius = 0.01*_cap_size;
		_radius_inc = 1.2*_radius;
		_radius_delta = _cap_size/6;
		_max_radius = 1.1*_cap_size;
		_min_radius = 0.1*_cap_size;

		_num_steps = ceil(0.253*(_cap_size^(7/8)));
		_max_alt = 1.667*_num_steps;
		_alt = _num_steps/12;

		_water_old = false;

		for "_i" from _num_steps to 1 step -1 do {
			if ( _i > (_num_steps/4) ) then {
				_radius = (_radius + _radius_inc) min _max_radius;
			} else {
				_radius = (_radius - _radius_inc) max _min_radius;
			};
			
			_alt = _alt - 1*(((60 - _i)/10) min _max_alt);

			for "_angle" from 0 to 360 step 12 do {
				_rpos = _radius + random _radius_delta;
				_rdir = _angle + random 12;
				_pos = [
					(_pos_ini select 0) + _rpos*(sin _rdir),
					(_pos_ini select 1) + _rpos*(cos _rdir),
					_alt
				];

				_water = surfaceIsWater _pos;

				if ( (_i > (_num_steps/3)) || ((_i % 3) != 0) ) then {
				// Mostly dust
					if (!_water) then {
						_shape = ["\Ca\Data\ParticleEffects\Universal\Universal.p3d", 16, 7, 48, 1];

						if (_water_old) then {
							if (random 2 < 1) then {
								_shape = ["\Ca\Data\ParticleEffects\Universal\Universal.p3d", 16, 12, 8, 1];
							};
						};
						
						_colors = [
							[1, 0.5, 0., 0.9],
							[0.9, 0.4, 0, 0.9],
							[0.5, 0.3, 0.2, 0.9],
							[0.55, 0.40, 0.35, 0.8],
							[0.60, 0.48, 0.44, 0.8],
							[0.65, 0.56, 0.53, 0.8],
							[0.70, 0.64, 0.62, 0.8],
							[0.75, 0.72, 0.71, 0.8],
							[0.80, 0.80, 0.80, 0.8],
							[0.80, 0.80, 0.80, 0.8],
							[0.80, 0.80, 0.80, 0.8],
							[0.80, 0.80, 0.80, 0.7],
							[0.90, 0.90, 0.90, 0.6],
							[0.90, 0.90, 0.90, 0.5],
							[0.90, 0.90, 0.90, 0.4],
							[0.90, 0.90, 0.90, 0.3],
							[0.90, 0.90, 0.90, 0.2],
							[0.90, 0.90, 0.90, 0.1],
							[1, 1, 1, 0.0],
							[1, 1, 1, 0.0],
							[1, 1, 1, 0.0]
						];
					} else {
						_shape = ["\Ca\Data\ParticleEffects\Universal\Universal.p3d", 16, 12, 8, 1];

						if (!_water_old) then {
							if (random 2 < 1) then {
								_shape = ["\Ca\Data\ParticleEffects\Universal\Universal.p3d", 16, 7, 48, 1];
							};
						};

						_colors = [
							[1, 1, 1, 1],
							[1, 1, 1, 0.8],
							[1, 1, 1, 0.8],
							[1, 1, 1, 0.8],
							[1, 1, 1, 0.8],
							[1, 1, 1, 0.8],
							[1, 1, 1, 0.8],
							[1, 1, 1, 0.8],
							[0.80, 0.80, 0.80, 0.8],
							[0.80, 0.80, 0.80, 0.8],
							[0.80, 0.80, 0.80, 0.8],
							[0.80, 0.80, 0.80, 0.7],
							[0.90, 0.90, 0.90, 0.6],
							[0.90, 0.90, 0.90, 0.5],
							[0.90, 0.90, 0.90, 0.4],
							[0.90, 0.90, 0.90, 0.3],
							[0.90, 0.90, 0.90, 0.2],
							[0.90, 0.90, 0.90, 0.1],
							[1, 1, 1, 0.0],
							[1, 1, 1, 0.0],
							[1, 1, 1, 0.0]
						];
					};

					_particle_size = 0.25*_cap_size + random(0.15*_cap_size);
					_sizes = [
						_particle_size,
						_particle_size,
						1.05*_particle_size,
						1.07*_particle_size,
						1.09*_particle_size,
						1.11*_particle_size,
						0,
						0
					];
					_phaseTimings = [0.2 + random 0.05];
					_randomIntensity = 0.5;

				} else {
				// Some fire
					_shape = ["\Ca\Data\ParticleEffects\Universal\Universal.p3d", 16, 5, 32, 1];
					_particle_size = random(_cap_size/8);
					_sizes = [
						_cap_size/7 + _particle_size,
						_cap_size/9 + _particle_size,
						_cap_size/12 + _particle_size,
						_cap_size/18 + _particle_size,
						0,
						0
					];
					_colors = [
						[1, 1, 1, 0.2],
						[1, 1, 1, 0.2],
						[1, 1, 1, 0.2],
						[0.90, 0.90, 0.90, 0.0],
						[0.90, 0.90, 0.90, 0.0],
						[0.90, 0.90, 0.90, 0.0]
					];
					_phaseTimings = [
						0.1 + random 0.9,
						0.1 + random 0.9,
						0.1 + random 0.9
					];
					_randomIntensity = 0.2;
				};

				_particle_life = _life - _elapsed;

				drop [
					_shape,
					"",
					"Billboard",
					1,
					_particle_life,
					_pos,
					[0, 0, 50 + (10 - random 20)],
					0.25,
					0.90 + 0.30 - 0.20,
					1,
					0.010,
					_sizes,
					_colors,
					_phaseTimings,
					1,
					_randomIntensity,
					"",
					"",
					""
				];

				_water_old = _water;
				_elapsed = dayTime*3600 - _time_ini;
			};
		};

		_angs = [];
		_lifes = [];
		_branches = 8;
		_delta = 360 / _branches;
		for [{_i = 0}, {_i < _branches}, {_i=_i + 1}] do {
			_angs = _angs + [(_delta*_i) + random 15];
			_lifes = _lifes + [0.05*_life*(1 + (random 0.1))];
		};

		_branch_alt = (random 1)-0.4;
		while {!isNull _light} do {
			_pos_ini = getPos _light;

			if (_pos_ini select 2 < (7*_life)) then {

				for [{_i = 0}, {_i < _branches}, {_i=_i + 1}] do {
					_ang = _angs select _i;
					_rpos = 10 + random 5;
					_rdir = _ang + random 2;
/*					
					_pos = [
						(_pos_ini select 0) + _rpos*(sin _rdir),
						(_pos_ini select 1) + _rpos*(cos _rdir),
						(_pos_ini select 2) + 0.70*_max_alt];
*/						
					_pos = [
						(_pos_ini select 0) + _rpos*(sin _rdir),
						(_pos_ini select 1) + _rpos*(cos _rdir),
						(_pos_ini select 2) + _branch_alt*_max_alt];

					_angv = ((_pos select 0) - (_pos_ini select 0)) atan2 ((_pos select 1) - (_pos_ini select 1));
					_rdir = _angv + 2 - random 4;
					
					_vel = [(sin(_rdir)*35 + (2 - random 4)) + (wind select 0)*0.3*0.02,
					(cos(_rdir)*35 + (2 - random 4)) + (wind select 1)*0.3*0.02,
					 -65 - random 5];
					
/*					
					_vel = [
						50*(sin _rdir) + (wind select 0)*0.3*0.02,
						50*(cos _rdir) + (wind select 1)*0.3*0.02,
						-55 - random 5];
*/
					if (_pos_ini select 2 < (3*_life)) then {
						_shape = ["\Ca\Data\ParticleEffects\Universal\Universal.p3d", 16, 5, 16, 1];
						_colors = [
							[1, 1, 1, 0.75],
							[1, 1, 1, 0.5],
							[1, 1, 0.75, 0.4],
							[0.5, 0.5, 0.5, 0.3],
							[0, 0, 0, 0.2],
							[0, 0, 0, 0.1],
							[0, 0, 0, 0.0]
						];
					} else {
						_shape = ["\Ca\Data\ParticleEffects\Universal\Universal.p3d", 16, 7, 16, 1];
						_colors = [
							[0.5, 0.5, 0.5, 0.3],
							[0.5, 0.5, 0.5, 0.2],
							[0, 0, 0, 0.0]
						];
					};

					drop [
						_shape,
						"",
						"Billboard",
						1,
						_lifes select _i,
						_pos,
						_vel,
						0.25,
						0.90 + 0.30 - 0.20 + 0.1,
						1,
						0.015,
						[40 + random 10, 70 + random(30), 100 + random(30), 120 + random(40)],
						_colors,
						[random 1, random 1, random 1],
						1,
						1,
						"",
						"",
						""
					];
				};
				sleep 0.25;
			} else {
				sleep 1;
			};
		};
	};

	// base clouds
	_cloud_base1 setParticleCircle [
		4*_fireball_size,
		[0, -20, -0.5]];

	if (!surfaceIsWater getPos _cloud_base1) then {
		_cloud_base1 setParticleParams _Base_PA;
	} else {
		_cloud_base1 setParticleParams _Base_PA_WA;
	};

	_cloud_base1 setDropInterval 0.01;

	// Ascending column

	[_pos, _column_size, _column_life] spawn {
		private[
			"_pos_ini",
			"_size",
			"_life",
			"_vel",
			"_radius",
			"_ang",
			"_rpos",
			"_rdir",
			"_time_ini",
			"_time_left",
			"_pos",
			"_shape",
			"_colors",
			"_angv"];

		_pos_ini = _this select 0;
		_size = _this select 1;
		_life = _this select 2;

		_radius = 1.0*_size;
		_ang = 0;
		_time_ini = dayTime*3600;
		_time_left = 0.45*_life;

		while {_time_left > 0} do {
			for [{_ang = 0}, {_ang < 360}, {_ang = _ang + 40}] do {
                _rpos = _radius + random (_radius/20);
				_rdir = _ang + random 4;
				_pos = [
					(_pos_ini select 0) + _rpos*(sin _rdir),
					(_pos_ini select 1) + _rpos*(cos _rdir),
					0
				];
				_angv = ((_pos_ini select 0) - (_pos select 0)) atan2 ((_pos_ini select 1) - (_pos select 1));
				_vel = [
					4*(sin _angv) + (4 - random 8),
					4*(cos _angv) + (4 - random 8),
					20 + (10 - random 20)
				];

				if (!surfaceIsWater _pos) then {
					_shape = ["\Ca\Data\ParticleEffects\Universal\Universal.p3d", 16, 7, 48, 1];
					_colors = [
						[0.40, 0.26, 0.13, 0.1*_time_left/_life],
						[0.40, 0.26, 0.13, 0.5*_time_left/_life],
						[0.40, 0.26, 0.13, 0.7*_time_left/_life],
						[0.40, 0.26, 0.13, 0.8*_time_left/_life],
						[0.40, 0.26, 0.13, 1*_time_left/_life],
						[0.45, 0.29, 0.20, 1*_time_left/_life],
						[0.50, 0.32, 0.26, 1*_time_left/_life],
						[0.55, 0.40, 0.35, 1*_time_left/_life],
						[0.60, 0.48, 0.44, 1*_time_left/_life],
						[0.65, 0.56, 0.53, 1*_time_left/_life],
						[0.70, 0.64, 0.62, 1*_time_left/_life],
						[0.75, 0.72, 0.71, 1*_time_left/_life],
						[0.80, 0.80, 0.80, 1*_time_left/_life],
						[0.80, 0.80, 0.80, 0.8*_time_left/_life],
						[0.90, 0.90, 0.90, 0.6*_time_left/_life],
						[0.90, 0.90, 0.90, 0.004*_time_left/_life],
						[0.90, 0.90, 0.90, 0.002*_time_left/_life],
						[0.90, 0.90, 0.90, 0.00*_time_left/_life],
						[0.90, 0.90, 0.90, 0.00*_time_left/_life]

					];
				} else {
					_shape = ["\Ca\Data\ParticleEffects\Universal\Universal.p3d", 16, 12, 8, 1];
					_colors = [
						[1, 1, 1, 0.1*_time_left/_life],
						[1, 1, 1, 0.5*_time_left/_life],
						[1, 1, 1, 0.7*_time_left/_life],
						[1, 1, 1, 0.7*_time_left/_life],
						[1, 1, 1, 0.8*_time_left/_life],
						[1, 1, 1, 0.8*_time_left/_life],
						[1, 1, 1, 0.8*_time_left/_life],
						[1, 1, 1, 0.8*_time_left/_life],
						[1, 1, 1, 0.8*_time_left/_life],
						[1, 1, 1, 0.8*_time_left/_life],
						[1, 1, 1, 0.8*_time_left/_life],
						[1, 1, 1, 0.8*_time_left/_life],
						[1, 1, 1, 0.8*_time_left/_life],
						[1, 1, 1, 0.7*_time_left/_life],
						[0.90, 0.90, 0.90, 0.6*_time_left/_life],
						[0.90, 0.90, 0.90, 0.004*_time_left/_life],
						[0.90, 0.90, 0.90, 0.002*_time_left/_life],
						[0.90, 0.90, 0.90, 0.00*_time_left/_life],
						[0.90, 0.90, 0.90, 0.00*_time_left/_life]

					];
				};

				drop [
					_shape,
					"",
					"Billboard",
					1,
					_time_left,
					_pos,
					_vel,
					0.25,
					0.90 + 0.30 - 0.20,
					1,
					0.01,
					[_radius*(0.33 + random 1), 1.11*_radius*(0.33 + random 1)],
					_colors,
					[0.2 + random 0.4],
					1,
					0,
					"",
					"",
					""
				];

			};
			sleep 0.2;
			_time_left = _life - ((dayTime*3600) - _time_ini);
		};
	};

	sleep (0.8*_column_life);
	deleteVehicle _cloud_base1;
} else {
// Air burst
// Cap ascending

	_fireball_size = 1.15*_airburst_threshold_2;
	_fireball_life = 0.80*_airburst_threshold_2;

	[_pos, _fireball_size, _Glare] spawn _Fireball;

	sleep 1;

	[_pos, _fireball_size, _fireball_life] spawn {
		private [
			"_pos_ini",
			"_size",
			"_life",
			"_pos",
			"_elapsed",
			"_rpos",
			"_rdir",
			"_time_ini",
			"_alt",
			"_shape",
			"_i",
			"_radius",
			"_colors",
			"_particle_size",
			"_sizes",
			"_phaseTimings",
			"_randomIntensity",
			"_particle_life",
			"_cap_size",
			"_eccentricity"];

		_pos_ini = _this select 0;
		_size = _this select 1;
		_life = _this select 2;

		_cap_size = 4.0*_size;
		_ang = 0;
		_time_ini = dayTime*3600;
		_elapsed = 0;
		_radius = 0.01*_cap_size;
		_radius_inc = 1.2*_radius;
		_radius_delta = _cap_size/6;
		_max_radius = 1.1*_cap_size;
		_min_radius = 0.1*_cap_size;

		_num_steps = ceil(2.636*(sqrt _cap_size));
		_max_alt = 1.667*_num_steps;
		_alt = _num_steps/12;

		for "_i" from _num_steps to 1 step -1 do {
			if ( _i > (_num_steps/4) ) then {
				_radius = (_radius + _radius_inc) min _max_radius;
			} else {
				_radius = (_radius - _radius_inc) max _min_radius;
			};
			
			_alt = _alt - 1*(((60 - _i)/10) min _max_alt);

			for "_angle" from 0 to 360 step 12 do {
				_rpos = _radius + random _radius_delta;
				_rdir = _angle + random 12;
				_pos = [
					(_pos_ini select 0) + _rpos*(sin _rdir),
					(_pos_ini select 1) + _rpos*(cos _rdir),
					(_pos_ini select 2) + _alt
				];


				_shape = ["\Ca\Data\ParticleEffects\Universal\Universal.p3d", 16, 12, 13, 0];

				if (random 1 > 0.75) then {
					_shape = ["\Ca\Data\ParticleEffects\Universal\Universal.p3d", 16, 12, 1, 8];
				};

				_colors = [
					[1, 1, 1, 0],
					[1, 1, 1, 0],
					[1, 1, 1, 0.1*(0.35 + random 0.1)],
					[1, 1, 1, 0.2*(0.35 + random 0.1)],
					[1, 1, 1, 0.3*(0.35 + random 0.1)],
					[1, 1, 1, 0.4*(0.35 + random 0.1)],
					[1, 1, 1, 0.5*(0.35 + random 0.1)],
					[1, 1, 1, 0.6*(0.35 + random 0.1)],
					[1, 1, 1, 0.7*(0.35 + random 0.1)],
					[1, 1, 1, 0.8*(0.35 + random 0.1)],
					[1, 1, 1, 1*(0.35 + random 0.1)],							
					[1, 1, 1, 1*(0.35 + random 0.1)],
					[1, 1, 1, 1*(0.35 + random 0.1)],
					[1, 1, 1, 1*(0.35 + random 0.1)],
					[1, 1, 1, 1*(0.35 + random 0.1)],
					[1, 1, 1, 1*(0.35 + random 0.1)],
					[1, 1, 1, 1*(0.35 + random 0.1)],
					[1, 1, 1, 1*(0.35 + random 0.1)],
					[1, 1, 1, 0.5*(0.35 + random 0.1)],
					[1, 1, 1, 0.01*(0.35 + random 0.1)],
					[1, 1, 1, 0.0]
				];

				_particle_size = 90 + random _size;
				_sizes = [
					_particle_size,
					_particle_size,
					_particle_size,
					_particle_size,
					_particle_size,
					_particle_size,
					_particle_size,
					_particle_size
				];
				_phaseTimings = [random 1.0];
				_randomIntensity = 0.5;

				_particle_life = _life - _elapsed;

				drop [
					_shape,
					"",
					"Billboard",
					1,
					_particle_life,
					_pos,
					[0, 0, 50 + (10 - random 20)],
					0.25,
					0.90 + 0.30 - 0.20,
					1,
					0.010,
					_sizes,
					_colors,
					_phaseTimings,
					1,
					_randomIntensity,
					"",
					"",
					""
				];

				_elapsed = dayTime*3600 - _time_ini;
			};
		};
	};
};
