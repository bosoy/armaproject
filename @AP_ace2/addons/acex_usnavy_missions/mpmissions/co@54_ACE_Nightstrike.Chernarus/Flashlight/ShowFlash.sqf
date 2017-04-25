/*
Src = Source (unit who shines light)
Rcv = Receiver (unit who sees light -- Player)

_Int0	= length of short "light on" period. long is 4x this value.
_Int1	= length of "light off" period.
*/

if ((player distance _Src) > 800) exitWith {};

private ["_Src","_Code","_SrcD","_dirSrcRcv","_ViewL","_ViewR","_Int","_Int1","_Int2","_sl","_col1","_size1","_Hgt","_UnitPos","_wht"];

_Src = _this select 0;
_Code = _this select 1;
_Col = _this select 2;

_IntR = 0.15;//_intR is the RESEND pulse life-time
_Int0 = 0.15;//_int0 is the short pulse life-time
_Int1 = 4*_Int0;//_int1 is the long pulse life-time
_Int2 = 3*_Int0;//_int2 is the space between pulses

_x = 0;
while {_x < (count _Code)} do
{
	if !alive (_Src) exitwith {};

	switch (_Code select _x) do
	{
		case 0:
		{
			_int = _int0;
			_sl = _int2;
		};
		case 1:
		{
			_int = _int1;
			_sl = _int2;
		};
		case 2:
		{
			_int = _intR;
			_sl = _intR;
		};
	};

	//create a real light source
	_light = "#lightpoint" createVehicleLocal [0,0,0];
	_light setLightBrightness 0.02;
	_light setLightAmbient[0.6*(_Col select 0), 0.6*(_Col select 1), 0.6*(_Col select 2)];
	_light setLightColor[0.01*(_Col select 0), 0.01*(_Col select 1), 0.01*(_Col select 2)];
	_light lightAttachObject [_Src, [0,15,0.5]];

	_SrcD = getDir _Src;
	_dirSrcRcv = [_Src, Player] call DirToObj;

	_OffAng = _SrcD - _dirSrcRcv;
	if (_OffAng > 180) then {_OffAng = 360 - _OffAng};
	if (_OffAng < -180) then {_OffAng = 360 + _OffAng};
	//if ((_OffAng < 0) AND (_OffAng > -180)) then {_OffAng = 360 + _OffAng};

	_OffAng = abs(_OffAng);

	if (_OffAng < 90) then  // IF PLAYER IS IN THE ARC, AND WITHIN 1000m, then draw the bright dot
	{
		//_OffAng = abs(_dirSrcRcv - _SrcD);
		//player sidechat format ["Angle: %1",_OffAng];
		if (_OffAng > 15) then {_OffAng = _OffAng - 15} else {_OffAng = 0}; //make a 30 degree "full bright" zone
		_W = (1 - (_OffAng/75))^3;

		if (_int == _int0) then
		{
			_col1 = [_Col+[0.75*_W],_Col+[_W],_Col+[0.25*_W],_Col+[0]];
			_size1 = [0.59,0.6,0.5,0.4];
		}
		else
		{
			_col1 = [_Col+[0.75*_M],_Col+[_W],_Col+[_W],_Col+[_W],_Col+[_W],_Col+[_W],_Col+[_W],_Col+[_W],_Col+[_W],_Col+[_W],_Col+[_W],_Col+[_W],_Col+[_W],_Col+[_W],_Col+[_W],_Col+[_W],_Col+[0.25*_M],_Col+[0]];
			_size1 = [0.59,0.6,0.6,0.6,0.6,0.6,0.6,0.6,0.6,0.6,0.6,0.6,0.6,0.6,0.6,0.6,0.5,0.4];
		};

		_MandoR = ([_Src] call mando_getpos);
		_UnitPos = _MandoR select 0;
		_UnitHgt = _MandoR select 1;

		switch (_UnitPos) do {case (-1): {_Hgt = 1}; case(0): {_Hgt = 1.35}; case(1): {_Hgt = 1}; case(2): {_Hgt = 0.25};}; //unknown, standing, crouching, prone .. height offsets

		_pos = [(position _Src select 0) + 0.75*sin(_SrcD),(position _Src select 1) + 0.75*cos(_SrcD),_UnitHgt+_Hgt];

		drop ["\Ca\Data\sun.p3d","","billboard",1,_Int+0.1,_pos,velocity _Src,0,1.275,1,0,_size1,_col1,[0],0,0,"","",""]; // create 'bright' light object!

	};

	sleep _int;
	deletevehicle _light;
	sleep _sl;
	_x = _x + 1;
};