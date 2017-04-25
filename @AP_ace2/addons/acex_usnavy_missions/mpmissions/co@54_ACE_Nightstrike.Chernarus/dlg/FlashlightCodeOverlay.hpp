class XC_RscText
{
	type = 0;
	idc = -1;
	style = 0x00;

	x = 0.0;
	y = 0.0;
	w = 0.3;
	h = 0.03;
	sizeEx = 0.023;

	colorBackground[] = {0.5, 0.5, 0.5, 0.75};
	colorText[] = { 0, 0, 0, 1 };
	font = "Zeppelin32";

	text = "";
};

class RscTitles
	{
	titles[] = {FlashlightCodes,Titel1}; // optional

	class Titel1
	{
		idd=0;
		movingEnable=0;
		duration=10;
		name="titel1";
		controls[]={"titel1"};
		class titel1: XC_RscText
		{
			style="16+2+512";
			lineSpacing=0.950000;
			text="Made 2009 by Xeno";
			//x=0.39000000;
			x=0.40000000;
			y=0.9100000;
			w=0.900000;
			h=0.700000;
			colorBackground[]={0,0,0,0};
			colorText[]={0.8,0.9,0.9,0.7};
			size=0.8;
			sizeEx = 0.026;
		};
	};

	class FlashlightCodes
		{
		idd = 3000;
		onLoad = "uiNamespace setVariable [""FlashlightCodes"", _this select 0];";
		movingEnable = 1;
		duration = 20000; // 5 hours, if the mission goes longer then this, then ... I don't know what to say.
		fadein = 0;
		fadeout = 0;
		name = "FlashlightCodes";
		controls[] = {"Codes","Hail","Receive","Resend","Go","Ready","Danger","SoS"};
		//onLoad = "HOMJ_FlashOverlay = (_this select 0)";
		class Codes: RscPicture
			{
			idc = 1001;
			x = 0.82;
			y = 0.015;
			w = 0.18;
			h = 0.18;
			text = "images\codeSMOff2.paa";
			};

		class CodeTexts : RscText
			{
			style = ST_RIGHT;
			sizeEx = 0.016;
			x = 0.67;
			w = 0.145;
			h = 0.025;
			colorText[] = {1,1,1,0.15};
			};

		class Hail : CodeTexts
			{
			idc = 1002;
			y = 0.009;
			text = "HAIL / REQ. ATTENTION";
			};

		class Receive : CodeTexts
			{
			idc = 1003;
			y = 0.0372;
			text = "RECEIVED / LISTENING";
			};

		class Resend : CodeTexts
			{
			idc = 1004;
			y = 0.0653;
			text = "RESEND THAT";
			};

		class Go : CodeTexts
			{
			idc = 1005;
			y = 0.0935;
			text = "GO GO GO";
			};

		class Ready : CodeTexts
			{
			idc = 1006;
			y = 0.1217;
			text = "READY / SAFE";
			};

		class Danger : CodeTexts
			{
			idc = 1007;
			y = 0.1498;
			text = "NOT READY / DANGER";
			};

		class SoS : CodeTexts
			{
			idc = 1008;
			y = 0.178;
			text = "S.O.S. (HELP)";
			};
		};
	};