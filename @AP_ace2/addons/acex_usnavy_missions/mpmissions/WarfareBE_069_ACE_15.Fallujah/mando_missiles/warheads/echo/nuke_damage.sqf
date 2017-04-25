#define BLAST_SCALE 368.4
#define RANGE_BIAS 0.25
#define TO_BI_HITS 75
#define PRESSURE_CONSTANT 10^8.569
#define THERMAL_RADIANCE 10^8/(4*pi)
#define GAMMA_RADIANCE 2.174*10^7/(4*pi)
#define NEUTRON_RADIANCE 0.758*10^6/(4*pi)

// Attenuation factor for 0.5 MeV converted to inverse meters.
// Attenuation factor for 1.0 MeV converted to inverse meters.
#define MU_GAMMA_AIR -0.00111
#define MU_NEUTRON_AIR -0.000001

#define MIN_PRESSURE 1.0
#define KICK_BOOST 5.5

private [
	"_pos",
	"_yield",
	"_burst",
	"_Sectional",
	"_Fire",
	"_blast_radius",
	"_objects",
	"_yd2",
	"_yd3",
	"_damage_radius",
	"_damage_type",
	"_distance",
	"_velocity",
	"_location",
	"_magnitude",
	"_j",
	"_impulse",
	"_thermal_fraction",
	"_rad_crew",
	"_kpascals",
	"_cal_cm",
	"_gray_gamma",
	"_gray_neutron",
	"_blast",
	"_thermal",
	"_rad",
	"_object_damage",
	"_damage"
];

_pos = _this select 0;
_yield = _this select 1;
_burst = _this select 2;
_Sectional = _this select 3;
_Fire = _this select 4;

_blast_radius = BLAST_SCALE*_yield^(1/3);
_damage_radius = (_yield*PRESSURE_CONSTANT/MIN_PRESSURE)^(1/3);

if ( _blast_radius > 0 ) then {

// check for ground burst
	if ( (_burst == "air") || ((_pos select 2) > _blast_radius) ) then {
		_thermal_fraction = 0.35*THERMAL_RADIANCE;
	} else {
		_thermal_fraction = 0.19*THERMAL_RADIANCE;
	};

	_objects = _pos nearObjects["All", _damage_radius]; 

	{
	   if (local _x) then {
		_blast = 0;
		_thermal = 0;
		_rad = 0;
		_rad_crew = 0;
		_impulse = 0;

		while {true} do {
			if ( _x isKindOf "Thing" ) exitWith { 
				_damage_type = "skip";
			};

			if ( _x isKindOf "Small_items" ) exitWith { 
				_damage_type = "skip";
			};

			if ( _x isKindOf "Logic" ) exitWith { 
				_damage_type = "skip";
			};

			if ( _x isKindOf "LaserTarget" ) exitWith { 
				_damage_type = "skip";
			};

			if ( _x isKindOf "FireSectorTarget" ) exitWith { 
				_damage_type = "skip";
			};

			_damage_type = "BIS_percent";
			_distance = (_x distance _pos) max 1.0;
				
			_yd2 = _yield/(_distance^2);
			_yd3 = _yield/(_distance^3);
			_kpascals = PRESSURE_CONSTANT*_yd3;
			_cal_cm = _thermal_fraction*_yd2;
			_gray_gamma = GAMMA_RADIANCE*_yd2*exp(MU_GAMMA_AIR*_distance);
			_gray_neutron = NEUTRON_RADIANCE*_yd2*exp(MU_NEUTRON_AIR*_distance);

			if ( (_kpascals + _cal_cm + _gray_gamma + _gray_neutron) < 0 ) exitwith {
				_damage_type = "skip";
			};

			if ( _x isKindOf "Man" ) exitWith { 
				_blast = _kpascals/634;
				_impulse = _kpascals/5.7;
				_thermal = _cal_cm/7;
				_rad = ((1.0*_gray_gamma) + (10*_gray_neutron))/5;
				_rad_crew = 0;
			};

			if ( _x isKindOf "Tank" ) exitWith { 
				_blast = _kpascals/3000;
				_impulse = _kpascals/680;
				_thermal = _cal_cm/45;
				_rad = 0;
				_rad_crew = 0.22*((1.0*_gray_gamma) + (10*_gray_neutron))/5;
			};

			if ( _x isKindOf "Wheeled_APC" ) exitWith { 
				_blast = _kpascals/2000;
				_impulse = _kpascals/226;
				_thermal = _cal_cm/25;
				_rad = 0;
				_rad_crew = 0.55*((1.0*_gray_gamma) + (10*_gray_neutron))/5;
			};

			if ( _x isKindOf "LandVehicle" ) exitWith { 
				_blast = _kpascals/34.47;
				_impulse = _kpascals/55;
				_thermal = _cal_cm/20;
				_rad = 0;
				_rad_crew = ((1.0*_gray_gamma) + (10*_gray_neutron))/5;
			};

			if ( _x isKindOf "Air" ) exitWith { 
				_blast = _kpascals/13.8;
				_thermal = _cal_cm/30;
				_impulse = _kpascals/40;
				_rad = 0;
				_rad_crew = ((1.0*_gray_gamma) + (10*_gray_neutron))/5;
			};

			if ( _x isKindOf "BigShip" ) exitWith { 
				_blast = _kpascals/68.64;
				_thermal = _cal_cm/50;
				_rad = 0;
				_rad_crew = 0.34*((1.0*_gray_gamma) + (10*_gray_neutron))/5;
			};

			if ( _x isKindOf "Ship" ) exitWith { 
				_blast = _kpascals/34.32;
				_thermal = _cal_cm/22;
				_rad = 0;
				_rad_crew = ((1.0*_gray_gamma) + (10*_gray_neutron))/5;
			};

			if ( _x isKindOf "Building" ) exitWith { 
				_blast = _kpascals/41.364;
				_thermal = _cal_cm/25.4;
				_rad = 0;
				_rad_crew = 0;

				if (_x isKindOf "HouseBase") then {
					if ( (random 1) < (0.083*_blast + 0.125*_thermal) ) then {
						[getPos _x, 50 + random 100] spawn _Fire;
					};
				};

				if ( _x isKindOf "Ruins" ) then { 
					_damage_type = "skip";
				} else {
					_damage_type = "buildingsection";
				};
			};

			if ( true ) exitWith { 
				_blast = _kpascals/634;
				_thermal = _cal_cm/7;
				_rad = ((1.0*_gray_gamma) + (10*_gray_neutron))/5;
				_rad_crew = 0;
			};
		};

		_damage = _blast + _thermal + _rad;

		switch (_damage_type) do {
			case "skip": {
			};
			case "buildingsection": {
				_object_damage = damage _x;
				if ( _object_damage < 1.0 ) then {
					_object_damage = _object_damage + _damage;
					[_x, _object_damage] spawn _Sectional;
				};
			};
			default {
				_object_damage = damage _x;

				if ( _object_damage < 1.0 ) then {
					_object_damage = _object_damage + _damage;
					_x setDamage(_object_damage);
				};

				if ( _impulse > 0.1 ) then {
					_location = getPosATL _x;
					_magnitude = 0;
					_velocity = [];

					for "_i" from 0 to 2 do {
						_j = (_location select _i) - (_pos select _i);
						_velocity set[_i, _j];
						_magnitude = _magnitude + _j^2;
					};

					_magnitude = sqrt _magnitude;

					for "_i" from 0 to 2 do {
						_j = KICK_BOOST*_impulse*(_velocity select _i)/_magnitude;

						if ( _i == 2 ) then {
							_j = _j + KICK_BOOST*_impulse/8;
						};

						_velocity set[_i, _j];
					};

					_x setPosATL [_location select 0, _location select 1, (_location select 2) + 2];
					_x setVelocity _velocity;
				};
			};
		};

		if ( _rad_crew > 0 ) then {
			{
				_object_damage = damage _x;

				if ( _object_damage < 1.0 ) then {
					_object_damage = _object_damage + _rad_crew;
					_x setDamage(_object_damage);
				};
			} forEach crew _x;
		};
	   };
	   sleep 0.00005;
	} forEach _objects;
};

false;
