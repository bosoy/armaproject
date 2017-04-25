#define V_OFFSET		0.725
#define H_OFFSET		0.045
#define CODE_SPACING	0.0245

class FlashLightDialog
{
	idd = 173;
	MovingEnable = false;
	controlsbackground[] = {SignalBackground,CodesPic};
	onLoad = "uiNamespace setVariable [""FlashLightDialog"", _this select 0];";

	class SignalBackground : RscBackground
	{
		idc = 174;
		moving = true;
		x = H_OFFSET + 0.685;
		y = V_OFFSET + 0;
		w = 0.27;
		h = 0.215;
		text = ;
	};

	class CodesPic : RscPicture
	{
		idc = 175;
		x = H_OFFSET + 0.82;
		y = V_OFFSET + 0.0145;
		w = 0.12;
		h = 0.16;
		text = "Images\codeSMOn2.paa";
	};

	controls[] = {Hail,Receive,Resend,Go,Ready,Danger,SoS,CLOSE, HELP, FilterHRule, SelectText, SelectWhite,SelectRed,SelectYellow,SelectGreen,SelectBlue};

	class FlashButton : RscButton
	{
		style = ST_RIGHT;
		sizeEx = 0.016;
		x = H_OFFSET + 0.692;
		w = 0.119;
		h = 0.022;
	};

	class Hail : FlashButton
	{
		idc = 176;
		y = V_OFFSET + 0.008;
		text = "HAIL / REQ. ATTENTION";
		action = "execVM ""Flashlight\CloseAndSave.sqf"";[player,[0,0]] execVM ""Flashlight\DoFlash.sqf""";
	};

	class Receive : FlashButton
	{
		idc = 177;
		y = V_OFFSET + 0.008 + 1*CODE_SPACING;
		text = "RECEIVED / LISTENING";
		action = "execVM ""Flashlight\CloseAndSave.sqf"";[player,[1,1]] execVM ""Flashlight\DoFlash.sqf""";
	};

	class Resend : FlashButton
	{
		idc = 178;
		y = V_OFFSET + 0.008 + 2*CODE_SPACING;
		text = "RESEND THAT";
		action = "execVM ""Flashlight\CloseAndSave.sqf"";[player,[2,2,2,2,2,2]] execVM ""Flashlight\DoFlash.sqf""";
	};

	class Go : FlashButton
	{
		idc = 179;
		y = V_OFFSET + 0.008 + 3*CODE_SPACING;
		text = "GO GO GO";
		action = "execVM ""Flashlight\CloseAndSave.sqf"";[player,[0,1,1,0,0,0]] execVM ""Flashlight\DoFlash.sqf""";
	};

	class Ready : FlashButton
	{
		idc = 180;
		y = V_OFFSET + 0.008 + 4*CODE_SPACING;
		text = "READY / SAFE";
		action = "execVM ""Flashlight\CloseAndSave.sqf"";[player,[0,0,0,1,1,0]] execVM ""Flashlight\DoFlash.sqf""";
	};

	class Danger : FlashButton
	{
		idc = 181;
		y = V_OFFSET + 0.008 + 5*CODE_SPACING;
		text = "NOT READY / DANGER";
		action = "execVM ""Flashlight\CloseAndSave.sqf"";[player,[0,1,0,1,0,1,0,1]] execVM ""Flashlight\DoFlash.sqf""";
	};

	class SoS : FlashButton
	{
		idc = 182;
		y = V_OFFSET + 0.008 + 6*CODE_SPACING;
		text = "S.O.S. (HELP)";
		action = "execVM ""Flashlight\CloseAndSave.sqf"";[player,[0,0,0,1,1,1,0,0,0]] execVM ""Flashlight\DoFlash.sqf""";
	};

	class HELP : RscButton
	{
		idc = 191;
		x = H_OFFSET + 0.89;
		y = V_OFFSET + 0.015;
		w = 0.02;
		h = 0.0267;
		style = ST_CENTER;
		sizeEx = 0.03;
		text = "?";
		action = "hint format [""FLASHLIGHT INSTRUCTIONS:\n\nClick the '?' button to repeat this message.\n\nSend a signal by clicking on the signal's words. Change your signal's color by clicking on the color's text.\n\nYou may relocate the dialog on your screen. If you close the dialog with your 'Esc' key, it will not leave an overlay on-screen.\n\nOpen the dialog with either your action menu, or the %1 key."",actionKeysImages [""TeamSwitch"", 1]];";
	};

	class CLOSE : RscButton
	{
		idc = 183;
		x = H_OFFSET + 0.92;
		y = V_OFFSET + 0.015;
		w = 0.02;
		h = 0.0267;
		style = ST_CENTER;
		sizeEx = 0.03;
		text = "X";
		action = "execVM ""Flashlight\CloseAndSave.sqf""";
	};

	class FilterHRule : RscText
	{
		idc = 190;
		x = H_OFFSET + 0.69;
		y = V_OFFSET + 0.18;
		w = 0.26;
		h = 0.001;
		text = "";
		colorBackground[] = {1,1,1,0.2};
	};

	class SelectText : RscText
	{
		idc = 189;
		x = H_OFFSET + 0.69;
		y = V_OFFSET + 0.1805;
		style = ST_CENTER;
		w = 0.05;
		h = 0.03;
		text = "Filter:";
		sizeEx = 0.018;
		Colortext[] = {1,1,1,1};
	};

	class FlashColorButton : RscButton
	{
		style = ST_CENTER;
		sizeEx = 0.016;
		y = V_OFFSET + 0.1835;
		w = 0.04;
		h = 0.025;
	};

	class SelectWhite : FlashColorButton
	{
		idc = 184;
		x = H_OFFSET + 0.75;
		text = "White";
		action = "[""White""] execVM ""Flashlight\ChangeColor.sqf""";
	};

	class SelectRed : FlashColorButton
	{
		idc = 185;
		x = H_OFFSET + 0.79;
		text = "Red";
		action = "[""Red""] execVM ""Flashlight\ChangeColor.sqf""";
	};

	class SelectYellow : FlashColorButton
	{
		idc = 186;
		x = H_OFFSET + 0.83;
		text = "Yellow";
		action = "[""Yellow""] execVM ""Flashlight\ChangeColor.sqf""";
	};

	class SelectGreen : FlashColorButton
	{
		idc = 187;
		x = H_OFFSET + 0.87;
		text = "Green";
		action = "[""Green""] execVM ""Flashlight\ChangeColor.sqf""";
	};

	class SelectBlue : FlashColorButton
	{
		idc = 188;
		x = H_OFFSET + 0.91;
		text = "Blue";
		action = "[""Blue""] execVM ""Flashlight\ChangeColor.sqf""";
	};
};