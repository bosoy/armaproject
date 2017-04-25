class XDomLabel {
	idd=-1;
	movingEnable=0;
	duration=9;
	fadein = 1;
	fadeout = 1;
	name="XDomLabel";
	sizeEx = 256;
	onLoad = "uiNamespace setVariable ['XDomLabel', _this select 0]";
	onUnLoad = "uiNamespace setVariable ['XDomLabel', nil]";
	class controls {
		class DPicture : XD_RscPicture {
			idc = 50;
			x=0.26; y=0.4; w=0.5; h=0.07;
			text="pics\domination.paa";
			sizeEx = 256;
		};
	};
};
class XDomTwo {
	idd=-1;
	movingEnable=0;
	duration=9.5;
	fadeout = 1;
	name="XDomTwo";
	sizeEx = 256;
	onLoad = "uiNamespace setVariable ['XDomTwo', _this select 0]";
	onUnLoad = "uiNamespace setVariable ['XDomTwo', nil]";
	class controls {
		class Picture : XD_RscPicture {
			idc=50;
			x=2; y=0.35; w=0.15; h=0.15;
			text="pics\dtwo.paa";
			sizeEx = 256;
		};
	};
};
class dXlabel {
	idd=-1;
	movingEnable=0;
	fadein = 2;
	fadeout = 2;
	duration=14;
	name="dXlabel";
	sizeEx = 256;
	class controls {
		class Picture : XD_RscPicture {
			x = "SafeZoneX + SafeZoneW - 0.153";
			y = "SafeZoneY + SafeZoneH - 0.15";
			w = 0.16; h = 0.16;
			text="pics\Xlabel.paa";
			sizeEx = 256;
		};
	};
};
class GVAR(Lightning1) {
	idd = -1;
	movingEnable = 0;
	duration = 0.6;
	fadein = 0.2;
	fadeout = 1.3;
	name = QGVAR(Lightning1);
	class controls {
		class Lightning_BG {
			idc=-1;
			type = 0;
			style = 48;
			colorBackground[] = {0, 0, 0, 0};
			colorText[] = {1, 1, 1, 1};
			font = "Bitstream";
			sizeEx = 0.023;
			x = 0.6;y = 0.3;w = 0.3;h = 0.3;
			text = "ca\Data\data\blesk_b_ca.paa";
		};
	};
};
class GVAR(Eyeflare) {
	idd = -1;
	movingEnable = 0;
	duration = 0.4;
	fadein = 0.1;
	fadeout = 1.1;
	name = QGVAR(Eyeflare);
	class controls {
		class Eyeflare_BG {
			idc=-1;
			type = 0;
			style = 48;
			colorBackground[] = {0, 0, 0, 0};
			colorText[] = {1, 1, 1, 0.8};
			font = "Bitstream";
			sizeEx = 0.023;
			x = 0.74;y = 0.3;w = 0.15;h = 0.15;
			text = "ca\Data\data\eyeflare_ca.paa";
		};
	};
};
class XDomAward {
	idd=-1;
	movingEnable=0;
	duration=9;
	fadein = 1;
	fadeout = 1;
	name="XDomAward";
	sizeEx = 256;
	class controls {
		class Picture : XD_RscPicture {
			idc=50;
			x = "SafeZoneX + 0.01";
			y = "SafeZoneY + SafeZoneH - 0.21";
			w=0.15; h=0.2;
			text="pics\award.paa";
			sizeEx = 256;
		};
	};
};
class XA2Logo {
	idd=-1;
	movingEnable=0;
	duration=9;
	name="XA2Logo";
	fadein = 1;
	fadeout = 1;
	sizeEx = 256;
	class controls {
		class Picture : XD_RscPicture {
			idc=50;
#ifndef __GLOGO
			x=0.35;y=0.1;w=0.3;h=0.2;
			text=__UI_Path(ui_logo_main_ca.paa);
#else
			x=0.3;y=0.1;w=0.4;h=0.35;
			text=__GLOGO;
#endif
			sizeEx = 48;
		};
	};
};
class GVAR(SayHello) {
	idd=-1;
	movingEnable=0;
	duration=10;
	fadein = 2;
	fadeout = 2;
	name=QGVAR(SayHello);
	onLoad = "uiNamespace setVariable ['D_SayHello', _this select 0]";
	onUnLoad = "uiNamespace setVariable ['D_SayHello', nil]";
	class controls {
		class thetext: XC_RscText {
			idc=50;
			style="16+2+512";
			lineSpacing=0.95;
			text="";
			x=0.39;y=0.91;w=0.9;h=0.7;
			colorBackground[]={0,0,0,0};
			colorText[]={0.8,0.9,0.9,0.7};
			size=0.57;
			sizeEx = 0.026;
		};
	};
};
#ifdef __CARRIER__
class XCarrierTitel {
	idd=-1;
	movingEnable=0;
	duration=9;
	name="XCarrierTitel";
	fadein = 1;
	fadeout = 1;
	class controls {
		class carrierTitel : XC_RscText {
			lineSpacing=0.95;
			style="16+2+512";
			x=0.35; y=0.335; w=0.3; h=0.2;
			text="Carrier";
			size=0.57;
			sizeEx = 0.04;
			colorBackground[]={0,0,0,0};
			colorText[]={0.8,0.9,0.9,0.7};
		};
	};
};
#endif

class xvehicle_hud {
	idd=-1;
	movingEnable = true;
	fadein = 0;
	fadeout = 1;
	duration = 1e+011;
	name="xvehicle_hud";
	onLoad = "uiNamespace setVariable ['DVEC_HUD', _this select 0]";
	onUnLoad = "uiNamespace setVariable ['DVEC_HUD', nil]";
	class controls {
		class vehicle_hud_name {
			type = 0;
			idc = 64432;
			style = 0;
			x = "SafeZoneX + SafeZoneW - 0.163";
			y = "SafeZoneY + SafeZoneH - 0.3";
			w = 0.2;h = 0.2;
			font = "Zeppelin32";
			sizeEx = 0.019;
			colorBackground[]={0,0,0,0};
			colorText[] = {1.0, 1.0, 1.0, 0.9};
			text = "";
			shadow = 2;
		};
		class vehicle_hud_speed: vehicle_hud_name {
			idc = 64433;
			y = "SafeZoneY + SafeZoneH - 0.27";
		};
		class vehicle_hud_fuel: vehicle_hud_name {
			idc = 64434;
			y = "SafeZoneY + SafeZoneH - 0.24";
		};
		class vehicle_hud_damage: vehicle_hud_name {
			idc = 64435;
			y = "SafeZoneY + SafeZoneH - 0.21";
		};
		class vehicle_hud_direction: vehicle_hud_name {
			idc = 64436;
			y = "SafeZoneY + SafeZoneH - 0.18";
		};
	};
};
class chopper_hud {
	idd=-1;
	movingEnable = true;
	fadein = 0;
	fadeout = 1;
	duration = 1e+011;
	name="chopper_hud";
	onLoad="uiNamespace setVariable ['DCHOP_HUD', _this select 0]";
	onUnLoad="uiNamespace setVariable ['DCHOP_HUD', nil]";
	class controls {
		class vehicle_hud_start {
			type = 0;
			idc = 64438;
			style = 0;
			x = 0.3;y = 0.3;w = 0.6;h = 0.4;
			font = "Zeppelin32";
			sizeEx = 0.04;
			colorText[] = {1.0, 1.0, 1.0, 0.9};
			colorBackground[]={0,0,0,0};
			text = "";
			shadow = 2;
		};
		class vehicle_hud_start2: vehicle_hud_start {
			idc = 64439;
			y = 0.37;w = 0.4;
			sizeEx = 0.03;
		};
		class vehicle_hud_start3: vehicle_hud_start {
			idc = 64440;
			y = 0.43;w = 0.5;
			sizeEx = 0.03;
		};
		class vehicle_hud_start4: vehicle_hud_start {
			idc = 64441;
			y = 0.49;w = 0.5;
			sizeEx = 0.03;
		};
	};
};
class chopper_lift_hud {
	idd=-1;
	movingEnable = true;
	fadein = 0;
	fadeout = 0;
	duration = 1e+011;
	name="chopper_lift_hud";
	onLoad="uiNamespace setVariable ['DCHOP_LIFT_HUD', _this select 0]";
	onUnLoad="uiNamespace setVariable ['DCHOP_LIFT_HUD', nil]";
	class controls {
		class chopper_hud_background {
			idc = 64437;
			type = 0;
			XCTextBlack;
			font = "Bitstream";
			colorBackground[] = {0, 0.3, 0, 0.1};
			text = "";
			style = 128;
			sizeEx = 0.015;
			x = 0.3;y = 0.4;w = 0.42;h = 0.4;
		};
		class chopper_hud_type {
			type = 0;
			idc = 64438;
			style = 0;
			x = 0.31;y = 0.73;w = 0.42;h = 0.1;
			font = "Zeppelin32";
			sizeEx = 0.02;
			XCTextHud;
			colorBackground[]={0,0,0,0};
			text = "";
			shadow = 2;
		};
		class chopper_hud_icon: chopper_hud_type {
			idc = 64439;
			style = 48;
			x = 0.62;y = 0.723;w = 0.083;h = 0.07;
		};
		class chopper_hud_edge: chopper_hud_type {
			idc = 64440;
			x = 0.1;
			y = "SafeZoneY + 0.02";
			w = 0.42;h = 0.1;
		};
		class chopper_hud_dist: chopper_hud_type {
			idc = 64441;
			x = 0.31;y = 0.37;w = 0.25;h = 0.1;
		};
		class chopper_hud_height: chopper_hud_type {
			idc = 64442;
			x = 0.6;y = 0.37;w = 0.2;h = 0.1;
		};
		class chopper_hud_back: chopper_hud_type {
			idc = 64443;
			style = 48;
			x = 0.45;y = 0.6;w = 0.1;h = 0.1;
		};
		class chopper_hud_forward: chopper_hud_type {
			idc = 64444;
			style = 48;
			x = 0.45;y = 0.5;w = 0.1;h = 0.1;
		};
		class chopper_hud_left: chopper_hud_type {
			idc = 64445;
			style = 48;
			x = 0.4;y = 0.55;w = 0.1;h = 0.1;
		};
		class chopper_hud_right: chopper_hud_type {
			idc = 64446;
			style = 48;
			x = 0.5;y = 0.55;w = 0.1;h = 0.1;
		};
		class chopper_hud_middle: chopper_hud_type {
			idc = 64447;
			style = 48;
			x = 0.45;y = 0.55;w = 0.1;h = 0.1;
		};
		class chopper_hud_icon2: chopper_hud_type {
			idc = 64448;
			style = 48;
			x = 0.458;y = 0.56;w = 0.083;h = 0.07;
		};
	};
};
class chopper_lift_hud2 {
	idd=-1;
	movingEnable = true;
	fadein = 0;
	fadeout = 0;
	duration = 1e+011;
	name="chopper_hud2";
	onLoad="uiNamespace setVariable ['DCHOP_HUD2', _this select 0]";
	onUnLoad="uiNamespace setVariable ['DCHOP_HUD2', nil]";
	class controls {
		class chopper_hud_type {
			type = 0;
			idc = 61422;
			style = 0;
			x = 0.1;
			y = "SafeZoneY + 0.02";
			w = 0.42;h = 0.1;
			font = "Zeppelin32";
			sizeEx = 0.02;
			XCTextHud;
			colorBackground[]={0,0,0,0};
			text = "";
			shadow = 2;
		};
	};
};
#define IDCPLAYER 5200
#define IDCUNDEFINED -1
#define SECONDARY_FONT "Bitstream"
#define ST_LEFT 0x00
class PlayerNameHud {
	idd = -1;
	duration = 1e+011;
	name="PlayerNameHud";
	onLoad = "uiNamespace setVariable ['X_PHUD', _this select 0]";
	onUnLoad = "uiNamespace setVariable ['X_PHUD', nil]";
	objects[] = {};
	class controls {
		class PlayerNameDisp {
			type = 0;
			idc = IDCUNDEFINED;
			style = ST_LEFT;
			colorText[] = {0.75,0.75,0.75,1};
			colorBackground[] = {0,0,0,0};
			font = SECONDARY_FONT;
			text = "";
			sizeEx = 0.018;
			w = 0.165;h = 0.018;x = 0.5;y = 0.5;
			//shadow = 2;
		};
		
		#define __ADP(varnum) \
		class Player##varnum:PlayerNameDisp {idc = IDCPLAYER +  varnum;};
		
		__ADP(0)
		__ADP(1)
		__ADP(2)
		__ADP(3)
		__ADP(4)
		__ADP(5)
		__ADP(6)
		__ADP(7)
		__ADP(8)
		__ADP(9)
		__ADP(10)
		__ADP(11)
		__ADP(12)
		__ADP(13)
		__ADP(14)
		__ADP(15)
		__ADP(16)
		__ADP(17)
		__ADP(18)
		__ADP(19)
		__ADP(20)
		__ADP(21)
		__ADP(22)
		__ADP(23)
		__ADP(24)
		__ADP(25)
		__ADP(26)
		__ADP(27)
		__ADP(28)
		__ADP(29)
		__ADP(30)
		__ADP(31)
		__ADP(32)
		__ADP(33)
		__ADP(34)
		__ADP(35)
		__ADP(36)
		__ADP(37)
		__ADP(38)
		__ADP(39)
		__ADP(40)
		__ADP(41)
		__ADP(42)
		__ADP(43)
		__ADP(44)
		__ADP(45)
		__ADP(46)
		__ADP(47)
		__ADP(48)
		__ADP(49)
	};
};
class XProgressBar {
	idd = -1;
	movingEnable = 0;
	objects[] = {};
	duration = 1e+011;
	name = "XProgressBar";
	onLoad="uiNamespace setVariable ['DPROGBAR', _this select 0]";
	onUnLoad="uiNamespace setVariable ['DPROGBAR', nil]";
	controlsBackground[] = {};
	class controls {
		class XProgressBarBackground : XC_RscText {
			style = 128;
			idc = 3600;
			x = 0.3;y = "((SafeZoneH + SafeZoneY) - (1 + 0.165))*-1";w = 0.4;h = 0.06;
			colorBackground[] = {0,0,0,0.5};
		};
		class XProgressBarX : XC_RscText {
			style = 128;
			idc = 3800;
			x = 0.31;y = "((SafeZoneH + SafeZoneY) - (1 + 0.175))*-1";w = 0.02;h = 0.04;
			colorBackground[] = {0.543, 0.5742, 0.4102, 0.8};
		};
		class XProgress_Label: XC_RscText {
			idc = 3900;
			text = "$STR_DOM_MISSIONSTRING_1272";
			x = 0.405;w = 0.2;y = "((SafeZoneH + SafeZoneY) - (1 + 0.1))*-1";
			sizeEx = 0.035;
			colorBackground[] = {1,1,1,0};
			XCMainCapt;
		};
	};
};

class GVAR(FrameHandlerRsc) {
	idd = -1;
	movingEnable = 1;
	enableSimulation = 1;
	enableDisplay = 1;
	duration = 1e+011;
	fadein  = 0;
	fadeout = 0;
	name = QGVAR(FrameHandlerRsc);
	class controlsBackground {
		class dummy_map : GVAR(Dummy_Map) {
			x = -1;y = -1;w = 0;h = 0;
			onDraw = "call d_fnc_perFrame";
		};
	};
	class objects {};
	class controls {};
};

class GVAR(ScreenDirt) {
	idd = -1;
	movingEnable = 0;
	duration = 5;
	fadein = 0.1;
	fadeout = 5;
	name = QGVAR(ScreenDirt);
	class controls {
		class ScreenDirt_BG {
			idc=-1;
			type = 0;
			style = 48;
			colorBackground[] = {0, 0, 0, 0};
			colorText[] = {0.9, 0.9, 0.9, 0.8};
			font = "Bitstream";
			sizeEx = 0.023;
			x = "SafeZoneXAbs";
			y = "SafeZoneY";
			w = "SafeZoneWAbs + 0.05";
			h = "SafeZoneH + 0.05";
			text = "pics\screen_dirt_ca.paa";
		};
	};
};

class GVAR(ScreenBlood1) {
	idd = -1;
	movingEnable = 0;
	duration = 2;
	fadein = 0.1;
	fadeout = 5;
	name = QGVAR(ScreenBlood1);
	class controls {
		class ScreenBlood_BG {
			idc=-1;
			type = 0;
			style = 48;
			colorBackground[] = {0, 0, 0, 0};
			colorText[] = {0.9, 0.9, 0.9, 0.8};
			font = "Bitstream";
			sizeEx = 0.023;
			x = "SafeZoneXAbs";
			y = "SafeZoneY";
			w = "SafeZoneWAbs + 0.05";
			h = "SafeZoneH + 0.05";
			text = "pics\screen_blood_1_ca.paa";
		};
	};
};

class GVAR(ScreenBlood2) {
	idd = -1;
	movingEnable = 0;
	duration = 2;
	fadein = 0.1;
	fadeout = 5;
	name = QGVAR(ScreenBlood2);
	class controls {
		class ScreenBlood_BG {
			idc=-1;
			type = 0;
			style = 48;
			colorBackground[] = {0, 0, 0, 0};
			colorText[] = {0.9, 0.9, 0.9, 0.8};
			font = "Bitstream";
			sizeEx = 0.023;
			x = "SafeZoneXAbs";
			y = "SafeZoneY";
			w = "SafeZoneWAbs + 0.05";
			h = "SafeZoneH + 0.05";
			text = "pics\screen_blood_2_ca.paa";
		};
	};
};

class GVAR(ScreenBlood3) {
	idd = -1;
	movingEnable = 0;
	duration = 2;
	fadein = 0.1;
	fadeout = 5;
	name = QGVAR(ScreenBlood3);
	class controls {
		class ScreenBlood_BG {
			idc=-1;
			type = 0;
			style = 48;
			colorBackground[] = {0, 0, 0, 0};
			colorText[] = {0.9, 0.9, 0.9, 0.8};
			font = "Bitstream";
			sizeEx = 0.023;
			x = "SafeZoneXAbs";
			y = "SafeZoneY";
			w = "SafeZoneWAbs + 0.05";
			h = "SafeZoneH + 0.05";
			text = "pics\screen_blood_3_ca.paa";
		};
	};
};

class GVAR(message_hud) {
	idd=-1;
	movingEnable = true;
	fadein = 3;
	fadeout = 3;
	duration = 15;
	name=QGVAR(message_hud);
	onLoad = "uiNamespace setVariable ['DMESSAGE_HUD', _this select 0]";
	onUnLoad = "uiNamespace setVariable ['DMESSAGE_HUD', nil]";
	class controls {
		class BackGround : XD_RscPicture {
			idc = 1000;
			x = "SafeZoneX + SafeZoneW - 0.412";
			y = "SafeZoneY + SafeZoneH + 0.01";
			w = "0.3137255*1.5";h = 0.068;
			colorBackground[] = {0,0,0,0};
			text = __UI_Path(igui_gradient_background.paa);
		};
		class MsgTxt : XC_RscText {
			idc = 1001;
			style = ST_MULTI;
			sizeEx = 0.02;
			lineSpacing = 1;
			colorbackground[] = {0, 0, 0, 0};
			colorText[] = {0.8784,0.8471,0.651,1};
			x = "SafeZoneX + SafeZoneW - 0.4115";
			y = "SafeZoneY + SafeZoneH + 0.008";
			w = 0.4110;h = 0.068;
			text = "";
			shadow = 2;
		};
	};
};

class BBRscStructuredText {
	access = 0;
	type = 13;
	idc = -1;
	style = 0;
	colorText[] = {0.8784,0.8471,0.651,1};
	class Attributes {
		font = "Zeppelin32";
		color = "#e0d8a6";
		align = "center";
		shadow = 1;
	};
	x = 0;
	y = 0;
	h = 0.035;
	w = 0.1;
	text = "";
	size = 0.03921;
	shadow = 2;
};

class GVAR(rscDynamicText) {
	idd = -1;
	movingEnable = 1;
	duration = 1e+011;
	fadein = 0;
	fadeout = 0;
	name = "d_BIS_dynamicText";
	onload = "uinamespace setvariable ['d_BIS_dynamicText',_this select 0];";
	onUnload = "uinamespace setvariable ['d_BIS_dynamicText',nil];";
	class controls {
		class Text: BBRscStructuredText {
			idc = 9999;
			style = "1 + 16";
			text = "";
			x = 0;
			y = 0.45;
			w = 1;
			h = 10000;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0};
			size = "(0.05 / 1.17647) * safezoneH";
			sizeEx = 0.4;
			class Attributes {
				font = "TahomaB";
				color = "#ffffff";
				align = "center";
				shadow = 0;
				valign = "top";
			};
		};
	};
};

#ifndef __ACE__
class GVAR(rscCrewText) {
	idd = -1;
	movingEnable = 1;
	duration = 1e+011;
	fadein = 0;
	fadeout = 0;
	name = "d_rscCrewText";
	onload = "uinamespace setvariable ['d_rscCrewText',_this select 0]";
	onUnload = "uinamespace setvariable ['d_rscCrewText',nil]";
	class controls {
		class Text: BBRscStructuredText {
			idc = 9999;
			style = "1 + 16";
			text = "";
			x = SafeZoneX + SafeZoneW - 0.21;
			y = 0.73;
			w = 0.2;
			h = 0.45;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0.2,0.15,0.1,0.5};
			size = 0.03;
			sizeEx = 0.032;
			class Attributes {
				font = "Zeppelin32";
				color = "#ffffff";
				align = "center";
				shadow = 0;
			};
		};
	};
};
#endif

class GVAR(RscText) {
	access = 0;
	type = 0;
	idc = -1;
	colorBackground[] = {0,0,0,0};
	colorText[] = {0.8784,0.8471,0.651,1};
	text = "";
	fixedWidth = 0;
	x = 0;
	y = 0;
	h = 0.037;
	w = 0.3;
	style = 0;
	shadow = 2;
	font = "Zeppelin32";
	SizeEx = 0.03921;
};

class GVAR(rscInfoText) {
	idd = 123100;
	fadein = 0;
	fadeout = 0;
	duration = 1e+011;
	onLoad = "uinamespace setvariable ['d_BIS_InfoText',_this select 0]";
	onUnLoad = "uinamespace setvariable ['d_BIS_InfoText',nil]";
	class Controls {
		class InfoText: GVAR(RscText) {
			idc = 3101;
			style = "0x01 + 0x10 + 0x200 + 0x100";
			font = "EtelkaMonospaceProBold";
			x = "safezoneX + safezoneW - 0.7";
			y = "safezoneY + safezoneH - 0.33";
			w = 0.6;
			h = 0.15;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0};
			text = "";
			lineSpacing = 1;
			sizeEx = 0.045;
			fixedWidth = 1;
		};
	};
};

class GVAR(GDF_RscActiveText) {
	access = 0;
	type = 11;
	style = 2;
	color[] = {0,0,0,1};
	colorActive[] = {0.3,0.4,0,1};
	soundEnter[] = {"",0.1,1};
	soundPush[] = {"",0.1,1};
	soundClick[] = {"",0.1,1};
	soundEscape[] = {"",0.1,1};
	text = "";
	default = 0;
	idc = -1;
	x = 0;
	y = 0;
	h = 0.035;
	w = 0.035;
	font = "Zeppelin32";
	shadow = 2;
	sizeEx = 0.03921;
	colortext[] = {0,0,0,1};
};

class GVAR(GDF_RscControlsGroup) {
	class VScrollbar {
		color[] = {1,1,1,1};
		width = 0.001;
		autoScrollSpeed = -1;
		autoScrollDelay = 5;
		autoScrollRewind = 0;
		shadow = 0;
	};
	class HScrollbar {
		color[] = {1,1,1,1};
		height = 0.001;
		shadow = 0;
	};
	class ScrollBar {
		color[] = {1,1,1,0.6};
		colorActive[] = {1,1,1,1};
		colorDisabled[] = {1,1,1,0.3};
		shadow = 0;
		thumb = __UI_Path(ui_scrollbar_thumb_ca.paa);
		arrowFull = __UI_Path(ui_arrow_top_active_ca.paa);
		arrowEmpty = __UI_Path(ui_arrow_top_ca.paa);
		border = __UI_Path(ui_border_scroll_ca.paa);
	};
	class Controls { };
	type = 15;
	idc = -1;
	x = 0;
	y = 0;
	w = 1;
	h = 1;
	shadow = 0;
	style = 16;
};

class GVAR(RscGearFast) {
	idd = -1;
	movingEnable = 1;
	duration = 20;
	fadein = 0;
	fadeout = 0;
	name = "d_RscGearFast";
	onLoad = "uiNamespace setVariable ['d_RscGearFast', _this select 0];call d_fnc_fillgdfdialog";
	onUnLoad = "uiNamespace setVariable ['d_RscGearFast', nil]";
	class controls {
		class G_GearItems : GVAR(GDF_RscControlsGroup) {
			idc = 1000;
			x = "SafeZoneX + SafeZoneW + 0.01";
			y = 0.3;
			w = 0.228;
			h = 0.55;

			class Controls {
				class CA_Gear_slot_item1 : GVAR(GDF_RscActiveText) {
					idc = 109;
					__EXEC(xpos = 0);
					x = __EVAL(xpos);
					__EXEC(ypos = 0);
					y = __EVAL(ypos);
					w = 0.055;
					h = 0.074;
					style = ST_PICTURE + ST_KEEP_ASPECT_RATIO;
					color[] = {1, 1, 1, 0.5};
					colorBackground[] = {0.6, 0.8392, 0.4706, 1.0};
					colorBackgroundSelected[] = {0.6, 0.8392, 0.4706, 1.0};
					colorFocused[] = {0.0, 0.0, 0.0, 0};
				};

				class CA_Gear_slot_item2 : CA_Gear_slot_item1 {
					idc = 110;
					__EXEC(xpos = xpos + 0.057);
					x = __EVAL(xpos);
					y = __EVAL(ypos);
				};

				class CA_Gear_slot_item3 : CA_Gear_slot_item1 {
					idc = 111;
					__EXEC(xpos = xpos + 0.057);
					x = __EVAL(xpos);
					y = __EVAL(ypos);
				};

				class CA_Gear_slot_item4 : CA_Gear_slot_item1 {
					idc = 112;
					__EXEC(xpos = xpos + 0.057);
					x = __EVAL(xpos);
					y = __EVAL(ypos);
				};

				class CA_Gear_slot_item5 : CA_Gear_slot_item1 {
					idc = 113;
					__EXEC(xpos = 0);
					x = __EVAL(xpos);
					__EXEC(ypos = ypos + 0.077);
					y = __EVAL(ypos);
				};

				class CA_Gear_slot_item6 : CA_Gear_slot_item1 {
					idc = 114;
					__EXEC(xpos = xpos + 0.057);
					x = __EVAL(xpos);
					y = __EVAL(ypos);
				};

				class CA_Gear_slot_item7 : CA_Gear_slot_item1 {
					idc = 115;
					__EXEC(xpos = xpos + 0.057);
					x = __EVAL(xpos);
					y = __EVAL(ypos);
				};

				class CA_Gear_slot_item8 : CA_Gear_slot_item7 {
					idc = 116;
					__EXEC(xpos = xpos + 0.057);
					x = __EVAL(xpos);
					y = __EVAL(ypos);
				};

				class CA_Gear_slot_item9 : CA_Gear_slot_item7 {
					idc = 117;
					__EXEC(xpos = 0);
					x = __EVAL(xpos);
					__EXEC(ypos = ypos + 0.077);
					y = __EVAL(ypos);
				};

				class CA_Gear_slot_item10 : CA_Gear_slot_item7 {
					idc = 118;
					__EXEC(xpos = xpos + 0.057);
					x = __EVAL(xpos);
					y = __EVAL(ypos);
				};

				class CA_Gear_slot_item11 : CA_Gear_slot_item7 {
					idc = 119;
					__EXEC(xpos = xpos + 0.057);
					x = __EVAL(xpos);
					y = __EVAL(ypos);
				};

				class CA_Gear_slot_item12 : CA_Gear_slot_item7 {
					idc = 120;
					__EXEC(xpos = xpos + 0.057);
					x = __EVAL(xpos);
					y = __EVAL(ypos);
				};

				class CA_Gear_slot_handgun_item1 : CA_Gear_slot_item1 {
					idc = 122;
					__EXEC(xpos = 0);
					x = __EVAL(xpos);
					__EXEC(ypos = ypos + 0.12);
					y = __EVAL(ypos);
					w = 0.055;
					h = 0.074;
				};

				class CA_Gear_slot_handgun_item2 : CA_Gear_slot_handgun_item1 {
					idc = 123;
					__EXEC(xpos = xpos + 0.057);
					x = __EVAL(xpos);
					y = __EVAL(ypos);
				};

				class CA_Gear_slot_handgun_item3 : CA_Gear_slot_handgun_item1 {
					idc = 124;
					__EXEC(xpos = xpos + 0.057);
					x = __EVAL(xpos);
					y = __EVAL(ypos);
				};

				class CA_Gear_slot_handgun_item4 : CA_Gear_slot_handgun_item1 {
					idc = 125;
					__EXEC(xpos = xpos + 0.057);
					x = __EVAL(xpos);
					y = __EVAL(ypos);
				};

				class CA_Gear_slot_handgun_item5 : CA_Gear_slot_handgun_item1 {
					idc = 126;
					__EXEC(xpos = 0);
					x = __EVAL(xpos);
					__EXEC(ypos = ypos + 0.077);
					y = __EVAL(ypos);
				};

				class CA_Gear_slot_handgun_item6 : CA_Gear_slot_handgun_item5 {
					idc = 127;
					__EXEC(xpos = xpos + 0.057);
					x = __EVAL(xpos);
					y = __EVAL(ypos);
				};

				class CA_Gear_slot_handgun_item7 : CA_Gear_slot_handgun_item5 {
					idc = 128;
					__EXEC(xpos = xpos + 0.057);
					x = __EVAL(xpos);
					y = __EVAL(ypos);
				};

				class CA_Gear_slot_handgun_item8 : CA_Gear_slot_handgun_item5 {
					idc = 129;
					__EXEC(xpos = xpos + 0.057);
					x = __EVAL(xpos);
					y = __EVAL(ypos);
				};
			};
		};
	};
};
