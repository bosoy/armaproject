#include "\x\acex\addons\c_veh_m1\script_component.hpp"

private "_path";
PARAMS_9(_text,_s1,_s2,_s3,_s4,_s5,_s6,_s7,_s8);
_path = "\x\acex\addons\t_veh_m1\markings";

switch (_this select 1) do {
	case "00" : {_text setObjectTexture [6,_path + "\00.paa"];};
	case "01" : {_text setObjectTexture [6,_path + "\01.paa"];};
	case "02" : {_text setObjectTexture [6,_path + "\02.paa"];};
	case "03" : {_text setObjectTexture [6,_path + "\03.paa"];};
	case "04" : {_text setObjectTexture [6,_path + "\04.paa"];};
	case "05" : {_text setObjectTexture [6,_path + "\05.paa"];};
	case "06" : {_text setObjectTexture [6,_path + "\06.paa"];};
	case "07" : {_text setObjectTexture [6,_path + "\07.paa"];};
	case "08" : {_text setObjectTexture [6,_path + "\08.paa"];};
	case "09" : {_text setObjectTexture [6,_path + "\09.paa"];};
	case "empty" : {_text setObjectTexture [6,_path + "\empty.paa"];};

	case "random" : {
		_nr = (((getpos _text select 0) + (getpos _text select 1)*3)Mod 1000)-1;
		_nr = _nr - (_nr Mod 1);
		_i = _nr Mod 10;
		_text setobjecttexture [6, format [_path + "\0%1.paa", abs _i]];
		_i = ((_nr - _i)/10) Mod 10;
		_text setobjecttexture [6, format [_path + "\0%1.paa", abs _i]];
	};
};

switch (_this select 2) do {

	case "00" : {_text setObjectTexture [7,_path + "\00.paa"];};
	case "01" : {_text setObjectTexture [7,_path + "\01.paa"];};
	case "02" : {_text setObjectTexture [7,_path + "\02.paa"];};
	case "03" : {_text setObjectTexture [7,_path + "\03.paa"];};
	case "04" : {_text setObjectTexture [7,_path + "\04.paa"];};
	case "05" : {_text setObjectTexture [7,_path + "\05.paa"];};
	case "06" : {_text setObjectTexture [7,_path + "\06.paa"];};
	case "07" : {_text setObjectTexture [7,_path + "\07.paa"];};
	case "08" : {_text setObjectTexture [7,_path + "\08.paa"];};
	case "09" : {_text setObjectTexture [7,_path + "\09.paa"];};
	case "empty" : {_text setObjectTexture [7,_path + "\empty.paa"];};

	case "random" : {
		_nr = (((getpos _text select 0) + (getpos _text select 1)*2)Mod 1000)-1;
		_nr = _nr - (_nr Mod 1);
		_i = _nr Mod 10;
		_text setobjecttexture [7, format [_path + "\0%1.paa", _i]];
		_i = ((_nr - _i)/10) Mod 10;
		_text setobjecttexture [7, format [_path + "\0%1.paa", _i]];
	};
};

switch (_this select 3) do {

	case "00" : {_text setObjectTexture [8,_path + "\t1_00.paa"];};
	case "01" : {_text setObjectTexture [8,_path + "\t1_01.paa"];};
	case "02" : {_text setObjectTexture [8,_path + "\t1_02.paa"];};
	case "03" : {_text setObjectTexture [8,_path + "\t1_03.paa"];};
	case "04" : {_text setObjectTexture [8,_path + "\t1_04.paa"];};
	case "05" : {_text setObjectTexture [8,_path + "\t1_05.paa"];};
	case "06" : {_text setObjectTexture [8,_path + "\t1_06.paa"];};
	case "07" : {_text setObjectTexture [8,_path + "\t1_07.paa"];};
	case "08" : {_text setObjectTexture [8,_path + "\t1_08.paa"];};
	case "09" : {_text setObjectTexture [8,_path + "\t1_09.paa"];};
	case "empty" : {_text setObjectTexture [8,_path + "\empty.paa"];};

	case "random" : {
		_nr = (((getpos _text select 0) + (getpos _text select 1)*3)Mod 1000)-1;
		_nr = _nr - (_nr Mod 1);
		_i = _nr Mod 10;
		_text setobjecttexture [8, format [_path + "\t1_0%1.paa", _i]];
		_i = ((_nr - _i)/10) Mod 10;
		_text setobjecttexture [8, format [_path + "\t1_0%1.paa", _i]];
	};
};

switch (_this select 4) do {
	case "00" : {_text setObjectTexture [9,_path + "\t2_00.paa"];};
	case "01" : {_text setObjectTexture [9,_path + "\t2_01.paa"];};
	case "02" : {_text setObjectTexture [9,_path + "\t2_02.paa"];};
	case "03" : {_text setObjectTexture [9,_path + "\t2_03.paa"];};
	case "04" : {_text setObjectTexture [9,_path + "\t2_04.paa"];};
	case "05" : {_text setObjectTexture [9,_path + "\t2_05.paa"];};
	case "06" : {_text setObjectTexture [9,_path + "\t2_06.paa"];};
	case "07" : {_text setObjectTexture [9,_path + "\t2_07.paa"];};
	case "08" : {_text setObjectTexture [9,_path + "\t2_08.paa"];};
	case "09" : {_text setObjectTexture [9,_path + "\t2_09.paa"];};
	case "10" : {_text setObjectTexture [9,_path + "\t2_10.paa"];};
	case "empty" : {_text setObjectTexture [9,_path + "\empty.paa"];};

	case "random" : {
		_nr = (((getpos _text select 0) + (getpos _text select 1)*4)Mod 1000)-1;
		_nr = _nr - (_nr Mod 1);
		_i = _nr Mod 10;
		_text setobjecttexture [9, format [_path + "\t2_0%1.paa", _i]];
		_i = ((_nr - _i)/10) Mod 10;
		_text setobjecttexture [9, format [_path + "\t2_0%1.paa", _i]];
	};
};

switch (_this select 5) do {
	case "00" : {_text setObjectTexture [10,_path + "\t3_00.paa"];};
	case "empty" : {_text setObjectTexture [10,_path + "\empty.paa"];};
};

switch (_this select 6) do {
	case "00" : {_text setObjectTexture [11,_path + "\t3_00.paa"];};
	case "empty" : {_text setObjectTexture [11,_path + "\empty.paa"];};
};

switch (_this select 7) do {
	case "00" : {_text setObjectTexture [12,_path + "\t4_00.paa"];};
	case "01" : {_text setObjectTexture [12,_path + "\t4_01.paa"];};
	case "02" : {_text setObjectTexture [12,_path + "\t4_02.paa"];};
	case "03" : {_text setObjectTexture [12,_path + "\t4_03.paa"];};
	case "04" : {_text setObjectTexture [12,_path + "\t4_04.paa"];};
	case "05" : {_text setObjectTexture [12,_path + "\t4_05.paa"];};
	case "06" : {_text setObjectTexture [12,_path + "\t4_06.paa"];};
	case "07" : {_text setObjectTexture [12,_path + "\t4_07.paa"];};
	case "08" : {_text setObjectTexture [12,_path + "\t4_08.paa"];};
	case "09" : {_text setObjectTexture [12,_path + "\t4_09.paa"];};
	case "10" : {_text setObjectTexture [12,_path + "\t4_10.paa"];};
	case "11" : {_text setObjectTexture [12,_path + "\t4_11.paa"];};
	case "empty" : {_text setObjectTexture [12,_path + "\empty.paa"];};
};

switch (_this select 8) do {
	case "00" : {_text setObjectTexture [13,_path + "\t5_00.paa"];};
	case "01" : {_text setObjectTexture [13,_path + "\t5_01.paa"];};
	case "empty" : {_text setObjectTexture [13,_path + "\empty.paa"];};
};


//the following code is here to fix a bug with setObjectTexture command in singleplayer games
//sleep 0.1;

//waitUntil {time >= 0};

//ACE_Markings = [_text, _s1, _s2, _s3, _s4, _s5, _s6, _s7, _s8] execVM "\x\acex\addons\c_veh_m1\scripts\markings.sqf";