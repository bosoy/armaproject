//#define DEBUG_MODE_FULL
#include "script_component.hpp"

ADDON = false;
LOG(MSG_INIT);

GVAR(enableRain) = false;

ace_wind_initial_dir = (random 360);

ace_wind_initial_speed = (overcast*15)+(random (overcast*5)) max 1;

ace_wind_overcast_multiplier = 1;

ace_wind_mean_speed = ace_wind_initial_speed;

ace_wind_mean_dir = ace_wind_initial_dir;

ace_wind_current_speed = ace_wind_initial_speed;

ace_wind_current_dir = ace_wind_initial_dir;

ace_wind_current_range_speed = -1+(random 2);

ace_wind_current_range_dir = -1+(random 2);

ace_wind_next_period = -1; //ceil((2+random(5))/(ace_wind_overcast_multiplier/10));

ace_wind_next_major_period = -1;

ace_wind_period_count = 0;

ace_wind_major_period_count = 0;

ace_wind_total_time = 0;

ace_wind_period_start_time = time;

ace_wind_rain_next_period = -1;

ace_wind_rain_period_count = 0;

ace_wind_rain_initial_rain = 0;
if(overcast >= 0.7) then {
	ace_wind_rain_initial_rain = (random ((overcast-0.7)/0.3));
};

ace_wind_current_rain = ace_wind_rain_initial_rain;

ace_wind_rain_current_range = -1+(random 2);



ace_wind_fnc_serverController = {
	//player sideChat format["overcast: %1", overcast];
	if(ace_wind_rain_period_count > ace_wind_rain_next_period) then {
		if(overcast >= 0.7) then {
			_lastRain = ace_wind_current_rain;
			_rainOverCast = ((overcast-0.7)/0.3);
			ace_wind_rain_next_period = ceil((1+random(10))/(ace_wind_overcast_multiplier));
			ace_wind_current_rain = (ace_wind_current_rain+(((ace_wind_current_rain))*((_rainOverCast*(ace_wind_overcast_multiplier))/8)*ace_wind_rain_current_range));
			ace_wind_current_rain = (ace_wind_current_rain max 0.01) min 1;
			_transitionTime = (_rainOverCast*5)+(random (_rainOverCast*20));
			ace_wind_rain_current_range = -1+(random 2);
			
			
			// player sideChat format["lastRain: %1 currentRain: %2", _lastRain, ace_wind_current_rain];
			// player sideChat format["_transitionTime: %1", _transitionTime];
			
			
			
			ACE_RAIN_PARAMS = [_lastRain, ace_wind_current_rain, _transitionTime];
		} else {
			ace_wind_current_rain = 0;
			_lastRain = ace_wind_current_rain;
			_rainOverCast = 1;
			_transitionTime = (_rainOverCast*5)+(random (_rainOverCast*20));
			ACE_RAIN_PARAMS = [_lastRain, ace_wind_current_rain, _transitionTime];
			TRACE_4("",_lastRain,_rainOverCast,_transitionTime, overcast);
		};
		ace_wind_rain_period_start_time = time;
		publicVariable "ACE_RAIN_PARAMS";
	};

	if(ace_wind_period_count > ace_wind_next_period) then {
		_startDir = ace_wind_current_dir;
		_startSpeed = ace_wind_current_speed;
		ace_wind_current_dir = (ace_wind_current_dir+(((ace_wind_current_dir))*((overcast*(ace_wind_overcast_multiplier))/8)*ace_wind_current_range_dir));
		ace_wind_current_speed = (ace_wind_current_speed+(((ace_wind_current_speed))*(overcast*(ace_wind_overcast_multiplier)/12)*ace_wind_current_range_speed));
		
		ace_wind_current_speed = ace_wind_current_speed max 0.01;
		
		if(ace_wind_current_dir < 0) then {
			ace_wind_current_dir = ace_wind_current_dir+360;
		};
		ace_wind_current_dir = ace_wind_current_dir % 360;
		
		ace_wind_current_range_speed = (-1)+(random 2);

		ace_wind_current_range_dir = (-1)+(random 2);
		
		ace_wind_next_period = ceil((2+random(5))/(ace_wind_overcast_multiplier));
		ace_wind_period_count = 0;
		
		_gustCount = floor(random(ace_wind_next_period*(overcast*((ace_wind_overcast_multiplier^3)))));
		
		_time = ace_wind_next_period*60;
		_gusts = [];
		if(_gustCount > 0) then {
			_maxInterval = _time/_gustCount;
			for "_i" from 0 to _gustCount-1 do {
				_gustTime = (random (3 min _maxInterval));
				_timeTillGust = (_maxInterval*_i)+(random (_maxInterval - _gustTime));
				_gustSpeed = (random 1);
				_gustDir = (ace_wind_current_dir+(ace_wind_current_dir*(-1+(random 2))))*(overcast*(ace_wind_overcast_multiplier));
				_gusts set[(count _gusts), [_timeTillGust, _gustTime, _gustSpeed, _gustDir]];
			};
		};
		// diag_log text "-------";
		// diag_log text format["startDir: %1 endDir: %2", _startDir, ace_wind_current_dir];
		// diag_log text format["startSpeed: %1 endSpeed: %2", _startSpeed, ace_wind_current_speed];
		// diag_log text format["ace_wind_current_range_speed: %1", ace_wind_current_range_speed];
		// diag_log text format["ace_wind_current_range_dir: %1", ace_wind_current_range_dir];
		// diag_log text format["gusts: %1", _gusts];
		// diag_log text format["next period: %1", ace_wind_next_period];
		ace_wind_total_time = ace_wind_total_time + ace_wind_next_period;
		// diag_log text format["%1,%2,%3,%4", ace_wind_total_time, ace_wind_current_dir, ace_wind_current_speed, _gustCount];
		
		ACE_WIND_PARAMS = [_startDir, ace_wind_current_dir, _startSpeed, ace_wind_current_speed, _time, _gusts];
		ace_wind_period_start_time = time;
		publicVariable "ACE_WIND_PARAMS";
	};
	ace_wind_rain_period_count = ace_wind_rain_period_count + 1;
	ace_wind_period_count = ace_wind_period_count + 1;
};




ace_wind_fnc_getWind = {
	_return = [0,0,0];
	if(!isNil "ACE_WIND_PARAMS") then {
		_dir		= ACE_WIND_PARAMS select 0;
		_dirRange	= (ACE_WIND_PARAMS select 1)-(ACE_WIND_PARAMS select 0);
		_spd		= ACE_WIND_PARAMS select 2;
		_spdRange	= (ACE_WIND_PARAMS select 3)-(ACE_WIND_PARAMS select 2);
		_period		= ACE_WIND_PARAMS select 4;
		
		_periodPosition = (time - ace_wind_period_start_time) min _period;
		_periodPercent = _periodPosition/_period;
		_spdInc = _spdRange*_periodPercent;
		_dirInc = _dirRange*_periodPercent;
		_spd = (_spd + _spdInc);
		_dir = _dir + _dirInc;
		if (_dir > 360) then {_dir = _dir - 360};
		if (_dir < 0) then {_dir = _dir + 360};

		_return = [_spd*sin _dir, _spd*cos _dir, 0];
	};
	_return;
};

FUNC(wind) = ace_wind_fnc_getWind;

ADDON = true;
