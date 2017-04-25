//////////////////////////////
//    Dynamic-AI-Creator    //
//    Version 3.0 - 2010    //
//--------------------------//
//    DAC_Config_Weapons    //
//--------------------------//
//    Script by Silola      //
//    silola@freenet.de     //
//////////////////////////////

private ["_TypNumber","_TempArray","_Weapon_Pool","_Magazine_Pool"];

_TypNumber = _this select 0;_TempArray = [];

switch (_TypNumber) do
{
//-------------------------------------------------------------------------------------------------
	case 1:
	{
		_Weapon_Pool	= ["AK_107_kobra","Makarov","Binocular","NVGoggles"];
		_Magazine_Pool	= [["30Rnd_545x39_AK",6],["8Rnd_9x18_Makarov",4]];
	};
//-------------------------------------------------------------------------------------------------
	case 2:
	{
		_Weapon_Pool	= ["M16A4_ACG_GL","NVGoggles","Binocular","ItemCompass","ItemMap"];
		_Magazine_Pool	= [["30Rnd_556x45_Stanag",6],["1Rnd_HE_M203",6],["HandGrenade_West",4]];
	};
//-------------------------------------------------------------------------------------------------
	case 3:
	{
		_Weapon_Pool	= [];
		_Magazine_Pool	= [];
	};
//-------------------------------------------------------------------------------------------------
	case 4:
	{
		_Weapon_Pool	= [];
		_Magazine_Pool	= [];
	};
//-------------------------------------------------------------------------------------------------
	Default {
				if(DAC_Basic_Value != 5) then
				{
					DAC_Basic_Value = 5;publicvariable "DAC_Basic_Value";
					hintc "Error: DAC_Config_Weapons > No valid config number";
				};
				if(true) exitwith {};
			};
};

_TempArray = [_Weapon_Pool] + [_Magazine_Pool];
_TempArray