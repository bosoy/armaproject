if IsFlashing exitwith {player Groupchat "I'm already sending a signal!"};

IsFlashing = true;

FlashSender = [_this select 0, _this select 1,HOMJ_FlashColor select 1];

//player sidechat format ["debug - signal code array sent: %1",FlashSender];

publicvariable "FlashSender";

//Rest of script does a LOCALIZED flash, on the sender's PC.
private ["_Src","_Rpt","_Int","_Int1","_Int2","_sl"];

_intR = 0.15;//_intR is the RESEND pulse life-time
_Int0 = 0.15;//_int0 is the short pulse life-time
_Int1 = 3*_Int0;//_int1 is the long pulse life-time
_Int2 = 3*_Int0;//_int2 is the space between pulses
_Code = _this select 1;

_Src = Player;

_x = 0;
while {_x < (count _Code)} do	//for each of the members of the Code array, do...
{
	switch (_Code select _x) do
	{
		case (0):
		{
			_int = _int0;
			_sl = _int2;
		};
		case (1):
		{
			_int = _int1;
			_sl = _int2;
		};
		case (2):
		{
			_int = _intR;
			_sl = _intR;
		};
	};

	_light = "#lightpoint" createVehicleLocal [0,0,0];
	_light setLightBrightness 0.02;
	_light setLightAmbient[0.2, 0.2, 0.2];
	_light setLightColor[0.01, 0.01, 0.01];
	_light lightAttachObject [_Src, [0,10,0.5]];

	sleep _Int;
	deletevehicle _light;
	sleep _sl;
	_x = _x + 1;
};

sleep 0.5;

IsFlashing = false;