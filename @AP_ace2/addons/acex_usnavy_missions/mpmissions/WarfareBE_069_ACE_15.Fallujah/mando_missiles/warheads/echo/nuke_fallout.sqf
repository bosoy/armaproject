#include "nuke.h"

// This is not a version of DELFIC, we don't need/want that level of detail.
// Locations are used to check geometry of fallout pattern, do not assume a circle!
// Adjust value of SIM_SPEEDUP to speed up simulation time.

// For vehicles, if significantly above ground level ( 10m ) the hazard from fallout is largely
// negated, so air vehicles can safely travel over a zone, just don't land and kick up dust.

// Using Iodine-131 as principal fallout hazard to model. Intensity drops over time according
// the half-life formula. Once levels reach 1% of original level we stop inflicting damage. This
// takes about 7 half-life intervals.

// The global variable echo_fallout_decay_rate is used to alter decay rate, used for mission makers.
// Use a rate of 1440 (minutes in a day) to make a fallout zone disappear in about 1 hour.

// Use parentheses around any DEFINES to ensure calculations are correct.





// Time constants. DO NOT CHANGE!!
#define MINUTE 60
#define HOUR (60*MINUTE)
#define DAY (24*HOUR)
#define YEAR (365.25*DAY)

// Standardized exposure interval
#define DOSAGE_WINDOW 10

#define AVOGADRO (6.02214179*10^23)

#define CURIES_PER_KILOTON (3*10^10)
#define GRAMS_PER_KILOTON 56.7

// Enable local marker display. Comment out to disable
// #define SHOW_NOW

// Use value of 60 to make minutes like seconds. Set to 1 to run at normal speed.
#define SIM_SPEEDUP 1
// Enable logging
//#define DIAGNOSTICS

private [
	"_pos",
	"_yield",
	"_C1",
	"_airburst_threshold",
	"_fireball_life",
	"_fallrate_this",
	"_falldrag_this",
	"_halflife_this",
	"_fraction_this",
	"_color_this",
	"_delay",
	"_wind",
	"_mean",
	"_mean_mag",
	"_mean_dir",
	"_drift",
	"_dist",
	"_a_axis",
	"_b_axis",
	"_my_fallout_number",
	"_fallout_center",
	"_fallout_name",
	"_fallout_marker",
	"_fallout_zone",
	"_area",
	"_zone_name",
	"_zone_data",
	"_to_wait",
	"_fallout_start",
	"_check_radius",
	"_hasNBC",
	"_obj_position",
	"_radiation_intensity",
	"_rad_damage",
	"_objects",
	"_object_damage",
	"_dispersion_this",
	"_atomicWeight_this",
	"_energy_this",
	"_grams",
	"_decay_constant",
	"_activity",
	"_gray10",
	"_intensity0",
	"_fallout_type"];

if (!isServer) exitWith {};

_pos  = _this select 0;
_yield  = _this select 1;
_fallout_type  = _this select 2;

_C1 = _yield^(1/5);

_airburst_threshold = 33.528*_C1^2;

if ( (_pos select 2) < _airburst_threshold ) then {
	switch (_fallout_type) do {

// I-131
		case 1: {
			_fraction_this = 0.028336;
			_atomicWeight_this = 131;
			_halflife_this = 8.0197*DAY;
			_fallrate_this =  0.27845;
			_falldrag_this = 0.5;
			_dispersion_this = 13.24;
			_energy_this = 8.7474883*10^(-14);
			_color_this = "ColorOrange";
		};

// Sr-90
		case 2: {
			_fraction_this = 0.057518;
			_atomicWeight_this = 90;
			_halflife_this = 28.8*YEAR;
			_fallrate_this =  0.04641;
			_falldrag_this = 0.0333;
			_dispersion_this = 34.59;
			_energy_this = 5.831922*10^(-14);
			_color_this = "ColorYellow";
		};

// Si-31
		case 3: {
			_fraction_this = 0.00001;
			_atomicWeight_this = 31;
			_halflife_this = 2.62*HOUR;
			_fallrate_this =  0.001;
			_falldrag_this = 0.001;
			_dispersion_this = 600;
			_energy_this = 2.387243*10^(-13);
			_color_this = "ColorBlack";
		};

		default {
			diag_log "Unknown case";
		};
	};

	_grams = _fraction_this*_yield*GRAMS_PER_KILOTON;
	_decay_constant = 1/(_halflife_this/(ln 2));
	_activity = AVOGADRO*_grams*_decay_constant/_atomicWeight_this;

	_fireball_life = 1.75*_airburst_threshold;
	_delay = _fireball_life*_fallrate_this;
	_area = (_delay*_dispersion_this*_C1)^2;
	_gray10 = DOSAGE_WINDOW*MINUTE*_energy_this*_activity/_area;
	_intensity0 = _gray10/6;

	_mean = [0, 0, 0];
	_mean_mag = 0;

	for "_i" from 1 to _delay do {
		_wind = wind;

		for "_j" from 0 to 2 do {
			_mean set[_j, (_mean select _j) + (_wind select _j)];
		};

		sleep ((MINUTE)/SIM_SPEEDUP); 
	};

	for "_j" from 0 to 2 do {
		_mean set[_j, (_mean select _j)/_delay];
	};

	_mean_mag = sqrt ( (_mean select 0)^2 + (_mean select 1)^2 + (_mean select 2)^2 );

	if ( _mean_mag == 0 ) then {
		_mean_dir = 0;
	} else {
		_mean_dir = (_mean select 0) atan2 (_mean select 1);

		if ( _mean_dir < 0 ) then {
			_mean_dir = _mean_dir + 360;
		};
	};

	_drift = _falldrag_this*60*_delay;

	_a_axis = (sqrt _area) + 0.25*_drift*_mean_mag;
	_b_axis = _area/_a_axis;

	_dist = 0.95*_a_axis;
	_fallout_center = [(_pos select 0) + _dist*sin(_mean_dir), (_pos select 1) + _dist*cos(_mean_dir), _pos select 2];

// Define my local ID number, global will change over time.
	_my_fallout_number = echo_fallout_number + 1;
	echo_fallout_number = _my_fallout_number;
	publicVariable "echo_fallout_number";

	_fallout_name = format["ECHO_FalloutMarker%1", _my_fallout_number];
	_fallout_marker = createMarker[_fallout_name, [_fallout_center select 0, (_fallout_center select 1)]];
#ifdef SHOW_NOW
	_fallout_name setMarkerShape "ELLIPSE";
	_fallout_name setMarkerColor _color_this;
#else
	_fallout_name setMarkerShape "ICON";
	_fallout_name setMarkerType "Empty";
#endif
	_fallout_name setMarkerSize [_b_axis, _a_axis];
	_fallout_name setMarkerDir _mean_dir;

	_fallout_zone = createLocation["Name", [_fallout_center select 0, _fallout_center select 1], _b_axis, _a_axis];
	_fallout_zone setDirection _mean_dir;

	_zone_name = format["%1", _my_fallout_number];
	_zone_data = [1.0, _fallout_marker, _fallout_zone, _fallout_center, _a_axis, _b_axis, _mean_dir];
	ECHO_FalloutGL setVariable[_zone_name, _zone_data, true];

	_check_radius = _a_axis max _b_axis;
	_fallout_start = time;

	while {
		_radiation_intensity = _intensity0*2^((SIM_SPEEDUP)*(_fallout_start - time)*echo_fallout_decay_rate/_halflife_this);
#ifdef DIAGNOSTICS
		diag_log format["%1 # Zone %2, Intensity %3", time, _my_fallout_number, _radiation_intensity];
#endif
		(_radiation_intensity/_intensity0 >= 0.01) 
	} do {
		_fallout_zone setVariable["Intensity", _radiation_intensity];
		_zone_data set[0, _radiation_intensity];
		ECHO_FalloutGL setVariable[_zone_name, _zone_data, true];

#ifdef SHOW_NOW
		_fallout_name setMarkerAlpha (_radiation_intensity/_intensity0);;
#endif

		_to_wait = 0;
		_objects = nearestObjects[_fallout_center, ["Car", "Motorcycle", "Tank", "Air", "Ship"], _check_radius];
		_to_wait = (count _objects)*0.1;
		{
			_obj_position = getPosATL _x;
			if ( (alive _x)  && (_obj_position in _fallout_zone) && ((_obj_position select 2) < 10) ) then {
				if ((count crew _x) > 0) then {
					{
						if (alive _x) then {
							_hasNBC = _x getVariable "ECHO_HasNBC";

							if (isNil "_hasNBC") then {
								_object_damage = damage _x;
								_rad_damage = _radiation_intensity/DOSAGE_WINDOW;
								_x setDamage (_object_damage + _rad_damage);
							} else {
								// Depends on value of _hasNBC
							};
						};

					} forEach crew _x;
				};
			};
			sleep 0.1;
		} forEach _objects;

		_objects = nearestObjects[_fallout_center, ["Man"], _check_radius];
		_to_wait = _to_wait + (count _objects)*0.1;
		{
			if ((local _x) && (alive _x)  && (_obj_position in _fallout_zone) ) then {
				_hasNBC = _x getVariable "ECHO_HasNBC";

				if (isNil "_hasNBC") then {
					_object_damage = damage _x;
					_rad_damage = _radiation_intensity/DOSAGE_WINDOW;
					_x setDamage (_object_damage + _rad_damage);
				} else {
					// Depends on value of _hasNBC
				};

			};

			sleep 0.1;
		} forEach _objects;
		
#ifdef DIAGNOSTICS
		diag_log format["%1 # Zone %2, Diagnostic %3", time, _my_fallout_number, ECHO_FalloutGL getVariable _zone_name];
#endif
		sleep (((MINUTE - _to_wait) max 1)/SIM_SPEEDUP);
	};

#ifdef DIAGNOSTICS
	diag_log format["%1 # Zone %2 Done", time, _my_fallout_number];
#endif
	_fallout_zone setVariable["Intensity", 0];
	_zone_data set[0, 0];
	_zone_data set[1, objNull];
	ECHO_FalloutGL setVariable[_zone_name, _zone_data, true];
	deleteMarker _fallout_name;
};
