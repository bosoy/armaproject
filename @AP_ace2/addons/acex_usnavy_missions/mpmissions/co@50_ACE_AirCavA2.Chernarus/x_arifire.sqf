private ["_aritype", "_targetpos", "_center_x", "_center_y", "_radius", "_angle", "_x1", "_y1", "_height", "_type", "_number_shells", "_arix", "_ariy", "_ang", "_posf", "_posb", "_posl", "_posr", "_wp_array", "_strenght", "_i", "_j", "_shell", "_xo", "_pos", "_pod", "_helper_bomb"];
if (!isServer) exitWith {};

ari_available = false; publicVariable "ari_available";

if (({alive _x} count [kan1,kan2,kan3,kan4,kan5,kan6,kan7,kan8]) == 0) exitWith {};

_aritype = _this;

_targetpos = [position AriTarget select 0, position AriTarget select 1, 0];
_center_x = _targetpos select 0;
_center_y = _targetpos select 1;
_radius = 50;

{
	if (!isNull _x && alive _x) then {
		_x DoWatch [_center_x,_center_y,1000];
	};
	sleep 0.3;
} forEach [kan1,kan2,kan3,kan4,kan5,kan6,kan7,kan8];

sleep 1;

{
	if (!isNull _x && alive _x) then {
		_angle = floor random 360;
		_x1 = _center_x - ((random _radius) * sin _angle);
		_y1 = _center_y - ((random _radius) * cos _angle);
		_x DoWatch [_center_x,_center_y,1000];
		sleep 0.5 + random 0.5;
		_x fire "M119";
		_x removeMagazine "30Rnd_105mmHE_M119";
		_x addMagazine "30Rnd_105mmHE_M119";
	};
	sleep 0.1;
} forEach [kan1,kan2,kan3,kan4,kan5,kan6,kan7,kan8];

//sleep traveltime!!!!
sleep 2;

_height = 0;
_type = "";
_radius = 30;
_number_shells = 1;

switch (ari_type) do {
	case "flare": {
		_number_shells = 18;
        _height = 350;
        _type = "F_40mm_White";
        _radius = 300;
        _arix = getPos AriTarget select 0;
        _ariy = getPos AriTarget select 1;
        _ang = floor random 360;
        _posf = [_arix + _radius * sin(_ang), _ariy + _radius * cos(_ang)]; //in front range
        _posb = [_arix - _radius * sin(_ang), _ariy - _radius * cos(_ang)]; //behind range
        _posl = [_arix + _radius * sin(_ang-90), _ariy + _radius * cos(_ang-90)]; //left lateral
        _posr = [_arix + _radius * sin(_ang+90), _ariy + _radius * cos(_ang+90)]; //right lateral
	};
	case "he": {
		_number_shells = 6;
		_height = 150;
		_type = "Sh_120_HE";
	};
	case "smoke": {
		_number_shells = 10;
		_height = 150;
		_type = "Smokeshell";
	};
	case "dpicm": {
		_number_shells = 40;
		_height = 150;
		_type = "G_40mm_HE";
		_radius = 100;
	};
};

_wp_array = [];
while {count _wp_array < _number_shells} do {
	if (ari_type == "flare") then {
		{
			_x1 = (_x select 0) - 20 + random 40; //No need for circular randomness
			_y1 = (_x select 1) - 20 + random 40;
			_wp_array = _wp_array + [[_x1, _y1, _height + random 10]];
			sleep 0.0153;
		} forEach [_posf, _posb, _posl, _posr];
	} else {
		_angle = floor random 360;
		_x1 = _center_x - ((random _radius) * sin _angle);
		_y1 = _center_y - ((random _radius) * cos _angle);
		_wp_array = _wp_array + [[_x1, _y1, (if (ari_type == "he") then {_height + random 50} else {_height})]];
		sleep 0.0153; // 0.2
	};
};

switch (ari_type) do {
		case "flare": {
			sleep 1;
			_strenght = 8; //Use this until we get flares with proper arty brightness. Maybe ACE can provide such flares for this use?
			for "_i" from 0 to (_number_shells-1) do {
				for "_j" from 0 to (_strenght-1) do {
					_type createVehicle [(_wp_array select _i) select 0, (_wp_array select _i) select 1, ((_wp_array select _i) select 2)-_j/100];
					sleep 0.002;
				};
				if (((_i+1) % 4 == 0) && (_i > 1)) then {sleep 18 + (ceil random 5)} else {sleep 0.5 + random 1.5};
			};
		};
		case "he": {
			for "_i" from 0 to (_number_shells - 1) do {
				_type createVehicle (_wp_array select _i);
				sleep 0.923 + (random 2);
			};
		};
		case "smoke": {
			for "_i" from 0 to (_number_shells - 1) do {
				_shell = _type createVehicle (_wp_array select _i);
				_xo = ceil random 10;
				sleep 0.923 + (_xo / 10);
			};
		};
		case "dpicm": {
			// _pos = [(position AriTarget) select 0, (position AriTarget) select 1, _height];
			// _pod = "Bomb" createVehicle _pos;
			// _pod setPos _pos;
			// _helper_bomb = "M_Ch29_AT" createVehicle _pos;
			// _helper_bomb setPos _pos;
			// sleep 0.5;
			// deleteVehicle _helper_bomb;
			for "_i" from 0 to (_number_shells - 1) do {
				_type createVehicle (_wp_array select _i);
				_xo = ceil random 10;
				sleep 0.223 + (_xo / 10);
			};
			// sleep 2.132;
			// deleteVehicle _pod;
		};
	};

sleep 600 + random 60;
ari_available = true;
publicVariable "ari_available";

if (true) exitWith {};