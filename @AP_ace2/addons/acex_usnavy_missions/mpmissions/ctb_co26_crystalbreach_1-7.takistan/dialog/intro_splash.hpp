// Thanks Xeno for the dialogs

// ####
class XC_RscText
{
	type = CT_STATIC;
	idc = -1;
	style = ST_LEFT;
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

class CTBTitle
{
	idd=123000;
	movingEnable=0;
	duration=10;
	name="CTBTitle";
	controls[]={"titel1"};
	class titel1 : XC_RscText
	{
		idc=66666;
		style="ST_MULTI+ST_CENTER+ST_NO_RECT";
		lineSpacing=0.950000;
		text="http://www.aef-hq.com.au";
		x=0.8400000;
		y=0.5300000;
		w=0.700000;
		h=0.700000;
		colorBackground[]={0,0,0,0};
		colorText[]={0.49,0.4,0.24,1.0};
		size=0.57;
		sizeEx = 0.026;
	};
};

class CTBFlag
{
	idd=-1;
	movingEnable=0;
	duration=10;
	name="CTBFlag";
	sizeEx = 256;
	controls[]={"Picture"};

	class Picture : RscPicture
	{
		x=0.8000000;
		y=0.600000;
		w=0.25;
		h=0.3;
		text="images\ctb_logo.paa";
		sizeEx = 256;
	};
};

