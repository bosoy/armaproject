#include "\x\acex\addons\c_veh_m1\script_component.hpp"
PARAMS_1(_stuff);
_Vehicle = typeOf _stuff;

_stuff_00 = {
	_stuff animate ["t_stuff_hide",0];

	_stuff animate ["t_stuff_ammo1_hide",1];
	_stuff animate ["t_stuff_ammo2_hide",1];
	_stuff animate ["t_stuff_ammo3_hide",0];

	_stuff animate ["t_stuff_bag1_hide",0];
	_stuff animate ["t_stuff_bag2_hide",0];
	_stuff animate ["t_stuff_bag3_hide",1];
	_stuff animate ["t_stuff_bag4_hide",0];

	_stuff animate ["t_stuff_kolo1_hide",0];
	_stuff animate ["t_stuff_kolo2_hide",1];
	_stuff animate ["t_stuff_kolo3_hide",1];

	_stuff animate ["t_stuff_wor1_hide",0];
	_stuff animate ["t_stuff_wor2_hide",0];
};

_stuff_01 = {
	_stuff animate ["t_stuff_hide",0];

	_stuff animate ["t_stuff_ammo1_hide",0];
	_stuff animate ["t_stuff_ammo2_hide",1];
	_stuff animate ["t_stuff_ammo3_hide",1];

	_stuff animate ["t_stuff_bag1_hide",0];
	_stuff animate ["t_stuff_bag2_hide",1];
	_stuff animate ["t_stuff_bag3_hide",0];
	_stuff animate ["t_stuff_bag4_hide",0];

	_stuff animate ["t_stuff_kolo1_hide",1];
	_stuff animate ["t_stuff_kolo2_hide",0];
	_stuff animate ["t_stuff_kolo3_hide",1];

	_stuff animate ["t_stuff_wor1_hide",0];
	_stuff animate ["t_stuff_wor2_hide",0];
};

_stuff_02 = {
	_stuff animate ["t_stuff_hide",0];

	_stuff animate ["t_stuff_ammo1_hide",1];
	_stuff animate ["t_stuff_ammo2_hide",0];
	_stuff animate ["t_stuff_ammo3_hide",1];

	_stuff animate ["t_stuff_bag1_hide",1];
	_stuff animate ["t_stuff_bag2_hide",1];
	_stuff animate ["t_stuff_bag3_hide",0];
	_stuff animate ["t_stuff_bag4_hide",0];

	_stuff animate ["t_stuff_kolo1_hide",0];
	_stuff animate ["t_stuff_kolo2_hide",0];
	_stuff animate ["t_stuff_kolo3_hide",1];

	_stuff animate ["t_stuff_wor1_hide",1];
	_stuff animate ["t_stuff_wor2_hide",0];
};

_stuff_03 = {
	_stuff animate ["t_stuff_hide",0];

	_stuff animate ["t_stuff_ammo1_hide",0];
	_stuff animate ["t_stuff_ammo2_hide",1];
	_stuff animate ["t_stuff_ammo3_hide",0];

	_stuff animate ["t_stuff_bag1_hide",1];
	_stuff animate ["t_stuff_bag2_hide",0];
	_stuff animate ["t_stuff_bag3_hide",0];
	_stuff animate ["t_stuff_bag4_hide",0];

	_stuff animate ["t_stuff_kolo1_hide",1];
	_stuff animate ["t_stuff_kolo2_hide",1];
	_stuff animate ["t_stuff_kolo3_hide",0];

	_stuff animate ["t_stuff_wor1_hide",1];
	_stuff animate ["t_stuff_wor2_hide",1];
};

_stuff_04 = {
	_stuff animate ["t_stuff_hide",0];

	_stuff animate ["t_stuff_ammo1_hide",0];
	_stuff animate ["t_stuff_ammo2_hide",0];
	_stuff animate ["t_stuff_ammo3_hide",1];

	_stuff animate ["t_stuff_bag1_hide",1];
	_stuff animate ["t_stuff_bag2_hide",1];
	_stuff animate ["t_stuff_bag3_hide",0];
	_stuff animate ["t_stuff_bag4_hide",0];

	_stuff animate ["t_stuff_kolo1_hide",0];
	_stuff animate ["t_stuff_kolo2_hide",1];
	_stuff animate ["t_stuff_kolo3_hide",1];

	_stuff animate ["t_stuff_wor1_hide",0];
	_stuff animate ["t_stuff_wor2_hide",0];
};

_stuff_05 = {
	_stuff animate ["t_stuff_hide",0];

	_stuff animate ["t_stuff_ammo1_hide",1];
	_stuff animate ["t_stuff_ammo2_hide",0];
	_stuff animate ["t_stuff_ammo3_hide",0];

	_stuff animate ["t_stuff_bag1_hide",0];
	_stuff animate ["t_stuff_bag2_hide",1];
	_stuff animate ["t_stuff_bag3_hide",0];
	_stuff animate ["t_stuff_bag4_hide",0];

	_stuff animate ["t_stuff_kolo1_hide",1];
	_stuff animate ["t_stuff_kolo2_hide",1];
	_stuff animate ["t_stuff_kolo3_hide",1];

	_stuff animate ["t_stuff_wor1_hide",1];
	_stuff animate ["t_stuff_wor2_hide",0];
};

_stuff_empty = {
	_stuff animate ["t_stuff_hide",1];

	_stuff animate ["t_stuff_ammo1_hide",1];
	_stuff animate ["t_stuff_ammo2_hide",1];
	_stuff animate ["t_stuff_ammo3_hide",1];

	_stuff animate ["t_stuff_bag1_hide",1];
	_stuff animate ["t_stuff_bag2_hide",1];
	_stuff animate ["t_stuff_bag3_hide",1];
	_stuff animate ["t_stuff_bag4_hide",1];

	_stuff animate ["t_stuff_kolo1_hide",1];
	_stuff animate ["t_stuff_kolo2_hide",1];
	_stuff animate ["t_stuff_kolo3_hide",1];

	_stuff animate ["t_stuff_wor1_hide",1];
	_stuff animate ["t_stuff_wor2_hide",1];
};

switch (_this select 1) do {
	case "00" : {
		[] call _stuff_00;
	};

	case "01" : {
		[] call _stuff_01;
	};

	case "02" : {
		[] call _stuff_02;
	};

	case "03" : {
		[] call _stuff_03;
	};

	case "04" : {
		[] call _stuff_04;
	};

	case "05" : {
		[] call _stuff_05;
	};

	case "empty" : {
		[] call _stuff_empty;
	};

	case "random" : {
		_nr = (((getpos _stuff select 0) + (getpos _stuff select 1)*3)Mod 1000)-1;
		_nr = _nr - (_nr Mod 1);
		_i = _nr Mod 10;

		switch (true) do {
			case (_i == 0): {[] call _stuff_00;};
			case (_i == 1 or _i == 6): {[] call _stuff_01};
			case (_i == 2 or _i == 7): {[] call _stuff_02};
			case (_i == 3 or _i == 8): {[] call _stuff_03};
			case (_i == 4 or _i == 9): {[] call _stuff_04};
			case (_i == 5): {[] call _stuff_05};
		};

		_i = ((_nr - _i)/10) Mod 10;

		switch (true) do {
			case (_i == 0): {[] call _stuff_00;};
			case (_i == 1 or _i == 6): {[] call _stuff_01};
			case (_i == 2 or _i == 7): {[] call _stuff_02};
			case (_i == 3 or _i == 8): {[] call _stuff_03};
			case (_i == 4 or _i == 9): {[] call _stuff_04};
			case (_i == 5): {[] call _stuff_05};
		};
	};
};