class CfgPatches
{
	class ace_sys_interaction
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","CBA_UI","ace_main","ace_c_weapon","ace_anims"};
		version = "1.14.0.597";
		author[] = {"Xeno","Rocko","Dr. Eyeball"};
		class ACE_Options
		{
			group = "INTERACTION";
			title = " ";
			class TapShoulder
			{
				title = "$STR_ACE_MENU_TAPSHOULDER";
			};
			class Knockdown
			{
				title = "$STR_ACE_MENU_KNOCKDOWN";
			};
		};
	};
};
class CfgVehicles
{
	class ACE_Logic;
	class ACE_NoCivilianInteraction: ACE_Logic
	{
		displayName = "$STR_ACE_IA_NOCIVILIANINTERACTION";
		vehicleClass = "Modules";
		class Eventhandlers
		{
			init = "ACE_NoCivilianInteraction = true; publicVariable 'ACE_NoCivilianInteraction'";
		};
	};
	class ACE_NoKnockDown: ACE_Logic
	{
		displayName = "$STR_ACE_IA_MODDISABLEKNOCKDOWN";
		vehicleClass = "Modules";
		class Eventhandlers
		{
			init = "ACE_DisableKnockdown = true; publicVariable 'ACE_DisableKnockdown'";
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_interaction
	{
		init = "call ('\x\ace\addons\sys_interaction\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
		clientInit = "call ('\x\ace\addons\sys_interaction\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_Killed_EventHandlers
{
	class CAManBase
	{
		class ace_sys_interaction
		{
			killedPlayer = "call ace_sys_interaction_fnc_checkTeamSwitch";
		};
	};
};
class RscText;
class RscShortcutButton;
class _flexiMenu_RscShortcutButtoni: RscShortcutButton
{
	class HitZone
	{
		left = 0.002;
		top = 0.003;
		right = 0.002;
		bottom = 0.003;
	};
	class ShortcutPos
	{
		left = -0.006;
		top = -0.007;
		w = 0.0392157;
		h = "2*(safeZoneH/36)";
	};
	class TextPos
	{
		left = 0.01;
		top = 0.002;
		right = 0.01;
		bottom = 0.002;
	};
};
class ACE_Interaction_Menu
{
	idd = 91483;
	movingEnable = 0;
	onload = "_this spawn ace_sys_interaction_fnc_onload";
	class controlsBackground{};
	class objects{};
	flexiMenu_subMenuControlWidth = "0.15*safeZoneW";
	flexiMenu_subMenuCaptionWidth = 0.4;
	class listButton: _flexiMenu_RscShortcutButtoni
	{
		x = 0.5;
		y = 0.5;
		w = 0;
		h = "0.033*safeZoneH";
		sizeEx = "0.033*safeZoneH";
		size = "0.033*safeZoneH*0.75";
		color[] = {"138/256","146/256","105/256",1};
		color2[] = {1,1,1,0.8};
		colorBackground[] = {1,1,1,1};
		colorbackground2[] = {1,1,1,1};
		colorDisabled[] = {1,1,1,0.25};
		class TextPos
		{
			left = 0.02;
			top = 0.005;
			right = 0.02;
			bottom = 0.005;
		};
		class Attributes
		{
			font = "Zeppelin32";
			color = "#E5E5E5";
			align = "left";
			shadow = "true";
		};
		animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\buttonList\normal.paa";
		animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\buttonList\disabled.paa";
		animTextureOver = "\x\cba\addons\ui\flexiMenu\data\buttonList\over.paa";
		animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\buttonList\focused.paa";
		animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\buttonList\down.paa";
		animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\buttonList\default.paa";
		animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\buttonList\normal.paa";
	};
	class button: _flexiMenu_RscShortcutButtoni
	{
		w = "0.18*safeZoneW";
		h = "(0.15*safeZoneH/5.5)";
		sizeEx = "(0.15*safeZoneH/5.5)";
		size = "(0.15*safeZoneH/5.5)*0.85";
		color[] = {"138/256","146/256","105/256",1};
		color2[] = {1,1,1,0.8};
		colorBackground[] = {1,1,1,1};
		colorbackground2[] = {1,1,1,1};
		colorDisabled[] = {1,1,1,0.25};
		class Attributes
		{
			font = "Zeppelin32";
			color = "#E5E5E5";
			align = "center";
			shadow = "true";
		};
	};
	class controls
	{
		class caption: rscText
		{
			idc = 230;
			x = "((safeZoneX+safeZoneW/2)-(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(-0.025*safeZoneW))-0.18*safeZoneW-(-0.00*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)-(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))-(0.15*safeZoneH/5.5)-((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)-(0.15*safeZoneH/5.5)*0.85";
			w = 0.4;
			h = "(0.15*safeZoneH/5.5)*0.85";
			sizeEx = "(0.15*safeZoneH/5.5)*0.85";
			color[] = {"138/256","146/256","105/256",1};
			text = "";
		};
		class button01: button
		{
			idc = 240;
			x = "(safeZoneX+safeZoneW/2)-0.15*safeZoneW*3/4/2+0.011*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)-0.15*safeZoneH/2";
			w = "0.15*safeZoneW*3/4";
			h = "0.15*safeZoneH";
			sizeEx = "0.15*safeZoneH";
			text = "";
			action = "";
			class TextPos
			{
				left = "-0.011*safeZoneW*2";
				top = "0.15*safeZoneH/2-(0.15*safeZoneH/5.5)/2";
				right = 0;
				bottom = 0.0;
			};
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\rose\normal_circle.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\rose\disabled_circle.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\rose\over_circle.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\rose\over_circle.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\rose\down_circle.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\rose\normal_circle.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\rose\normal_circle.paa";
		};
		class button02: button
		{
			idc = 241;
			x = "(safeZoneX+safeZoneW/2)-0.18*safeZoneW/2";
			y = "(safeZoneY+safeZoneH/2)-(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))-(0.15*safeZoneH/5.5)";
			text = "";
			action = "";
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\rose\normal_top.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\rose\disabled_top.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\rose\over_top.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\rose\over_top.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\rose\down_top.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\rose\normal_top.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\rose\normal_top.paa";
		};
		class button03: button
		{
			idc = 242;
			x = "(safeZoneX+safeZoneW/2)-0.18*safeZoneW/2";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))";
			text = "";
			action = "";
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\rose\normal_bottom.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\rose\disabled_bottom.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\rose\over_bottom.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\rose\over_bottom.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\rose\down_bottom.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\rose\normal_bottom.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\rose\normal_bottom.paa";
		};
		class button04: button
		{
			idc = 243;
			x = "((safeZoneX+safeZoneW/2)-(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(-0.025*safeZoneW))-0.18*safeZoneW-(-0.00*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)-((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)/2-(0.15*safeZoneH/5.5)-((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)-(0.15*safeZoneH/5.5)";
			text = "";
			action = "";
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L01.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\rose\disabled_L01.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\rose\over_L01.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\rose\over_L01.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\rose\down_L01.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L01.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L01.paa";
		};
		class button05: button
		{
			idc = 244;
			x = "((safeZoneX+safeZoneW/2)-(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(-0.015*safeZoneW))-0.18*safeZoneW-(-0.00*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)-((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)/2-(0.15*safeZoneH/5.5)";
			text = "";
			action = "";
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L02.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\rose\disabled_L02.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\rose\over_L02.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\rose\over_L02.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\rose\down_L02.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L02.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L02.paa";
		};
		class button06: button
		{
			idc = 245;
			x = "((safeZoneX+safeZoneW/2)-(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(-0.015*safeZoneW))-0.18*safeZoneW-(-0.00*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)/2";
			text = "";
			action = "";
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L03.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\rose\disabled_L03.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\rose\over_L03.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\rose\over_L03.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\rose\down_L03.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L03.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L03.paa";
		};
		class button07: button
		{
			idc = 246;
			x = "((safeZoneX+safeZoneW/2)-(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(-0.025*safeZoneW))-0.18*safeZoneW-(-0.00*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)/2+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)";
			text = "";
			action = "";
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L04.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\rose\disabled_L04.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\rose\over_L04.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\rose\over_L04.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\rose\down_L04.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L04.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L04.paa";
		};
		class button08: button
		{
			idc = 247;
			x = "((safeZoneX+safeZoneW/2)+(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(-0.025*safeZoneW))+(-0.00*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)-((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)/2-(0.15*safeZoneH/5.5)-((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)-(0.15*safeZoneH/5.5)";
			text = "";
			action = "";
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R01.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\rose\disabled_R01.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\rose\over_R01.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\rose\over_R01.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\rose\down_R01.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R01.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R01.paa";
		};
		class button09: button
		{
			idc = 248;
			x = "((safeZoneX+safeZoneW/2)+(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(-0.015*safeZoneW))+(-0.00*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)-((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)/2-(0.15*safeZoneH/5.5)";
			text = "";
			action = "";
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R02.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\rose\disabled_R02.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\rose\over_R02.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\rose\over_R02.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\rose\down_R02.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R02.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R02.paa";
		};
		class button10: button
		{
			idc = 249;
			x = "((safeZoneX+safeZoneW/2)+(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(-0.015*safeZoneW))+(-0.00*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)/2";
			text = "";
			action = "";
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R03.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\rose\disabled_R03.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\rose\over_R03.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\rose\over_R03.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\rose\down_R03.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R03.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R03.paa";
		};
		class button11: button
		{
			idc = 250;
			x = "((safeZoneX+safeZoneW/2)+(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(-0.025*safeZoneW))+(-0.00*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)/2+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)";
			text = "";
			action = "";
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R04.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\rose\disabled_R04.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\rose\over_R04.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\rose\over_R04.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\rose\down_R04.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R04.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R04.paa";
		};
		class caption2: caption
		{
			idc = 231;
			x = "(safeZoneX+safeZoneW/2)-(0.15*safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+0*0.033*safeZoneH";
			w = 0;
		};
		class listButton00: listButton
		{
			idc = 340;
			x = "(safeZoneX+safeZoneW/2)-(0.15*safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+00)*0.033*safeZoneH";
		};
		class listButton01: listButton
		{
			idc = 341;
			x = "(safeZoneX+safeZoneW/2)-(0.15*safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+01)*0.033*safeZoneH";
		};
		class listButton02: listButton
		{
			idc = 342;
			x = "(safeZoneX+safeZoneW/2)-(0.15*safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+02)*0.033*safeZoneH";
		};
		class listButton03: listButton
		{
			idc = 343;
			x = "(safeZoneX+safeZoneW/2)-(0.15*safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+03)*0.033*safeZoneH";
		};
		class listButton04: listButton
		{
			idc = 344;
			x = "(safeZoneX+safeZoneW/2)-(0.15*safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+04)*0.033*safeZoneH";
		};
		class listButton05: listButton
		{
			idc = 345;
			x = "(safeZoneX+safeZoneW/2)-(0.15*safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+05)*0.033*safeZoneH";
		};
		class listButton06: listButton
		{
			idc = 346;
			x = "(safeZoneX+safeZoneW/2)-(0.15*safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+06)*0.033*safeZoneH";
		};
		class listButton07: listButton
		{
			idc = 347;
			x = "(safeZoneX+safeZoneW/2)-(0.15*safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+07)*0.033*safeZoneH";
		};
		class listButton08: listButton
		{
			idc = 348;
			x = "(safeZoneX+safeZoneW/2)-(0.15*safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+08)*0.033*safeZoneH";
		};
		class listButton09: listButton
		{
			idc = 349;
			x = "(safeZoneX+safeZoneW/2)-(0.15*safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+09)*0.033*safeZoneH";
		};
		class listButton10: listButton
		{
			idc = 350;
			x = "(safeZoneX+safeZoneW/2)-(0.15*safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+10)*0.033*safeZoneH";
		};
	};
};
class _flexiMenu_RscShortcutButton: RscShortcutButton
{
	class HitZone
	{
		left = 0.002;
		top = 0.003;
		right = 0.002;
		bottom = 0.003;
	};
	class ShortcutPos
	{
		left = -0.006;
		top = -0.007;
		w = 0.0392157;
		h = "2*(safeZoneH/36)";
	};
	class TextPos
	{
		left = 0.01;
		top = 0.002;
		right = 0.01;
		bottom = 0.002;
	};
};
class ACE_Interaction_Menu2
{
	idd = 91484;
	movingEnable = 0;
	onload = "_this spawn ace_sys_wounds_fnc_onload2";
	class controlsBackground{};
	class objects{};
	flexiMenu_subMenuControlWidth = "0.15*safeZoneW";
	flexiMenu_subMenuCaptionWidth = 0.4;
	class listButton: _flexiMenu_RscShortcutButton
	{
		x = 0.5;
		y = 0.5;
		w = 0;
		h = "0.033*safeZoneH";
		sizeEx = "0.033*safeZoneH";
		size = "0.033*safeZoneH*0.75";
		color[] = {"138/256","146/256","105/256",1};
		color2[] = {1,1,1,0.8};
		colorBackground[] = {1,1,1,1};
		colorbackground2[] = {1,1,1,1};
		colorDisabled[] = {1,1,1,0.25};
		class TextPos
		{
			left = 0.02;
			top = 0.005;
			right = 0.02;
			bottom = 0.005;
		};
		class Attributes
		{
			font = "Zeppelin32";
			color = "#E5E5E5";
			align = "left";
			shadow = "true";
		};
		animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\buttonList\normal.paa";
		animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\buttonList\disabled.paa";
		animTextureOver = "\x\cba\addons\ui\flexiMenu\data\buttonList\over.paa";
		animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\buttonList\focused.paa";
		animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\buttonList\down.paa";
		animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\buttonList\default.paa";
		animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\buttonList\normal.paa";
	};
	class button: _flexiMenu_RscShortcutButton
	{
		w = "0.18*safeZoneW";
		h = "(0.15*safeZoneH/5.5)";
		sizeEx = "(0.15*safeZoneH/5.5)";
		size = "(0.15*safeZoneH/5.5)*0.85";
		color[] = {"138/256","146/256","105/256",1};
		color2[] = {1,1,1,0.8};
		colorBackground[] = {1,1,1,1};
		colorbackground2[] = {1,1,1,1};
		colorDisabled[] = {1,1,1,0.25};
		class Attributes
		{
			font = "Zeppelin32";
			color = "#E5E5E5";
			align = "center";
			shadow = "true";
		};
	};
	class controls
	{
		class caption: rscText
		{
			idc = 1230;
			x = "((safeZoneX+safeZoneW/2)-(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(-0.025*safeZoneW))-0.18*safeZoneW-(-0.00*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)-(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))-(0.15*safeZoneH/5.5)-((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)-(0.15*safeZoneH/5.5)*0.85";
			w = 0.4;
			h = "(0.15*safeZoneH/5.5)*0.85";
			sizeEx = "(0.15*safeZoneH/5.5)*0.85";
			color[] = {"138/256","146/256","105/256",1};
			text = "";
		};
		class button01: button
		{
			idc = 1240;
			x = "(safeZoneX+safeZoneW/2)-0.15*safeZoneW*3/4/2+0.011*safeZoneW";
			y = "(safeZoneY+safeZoneH/2)-0.15*safeZoneH/2";
			w = "0.15*safeZoneW*3/4";
			h = "0.15*safeZoneH";
			sizeEx = "0.15*safeZoneH";
			text = "";
			action = "";
			class TextPos
			{
				left = "-0.011*safeZoneW*2";
				top = "0.15*safeZoneH/2-(0.15*safeZoneH/5.5)/2";
				right = 0;
				bottom = 0.0;
			};
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\rose\normal_circle.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\rose\disabled_circle.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\rose\over_circle.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\rose\over_circle.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\rose\down_circle.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\rose\normal_circle.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\rose\normal_circle.paa";
		};
		class button02: button
		{
			idc = 1241;
			x = "(safeZoneX+safeZoneW/2)-0.18*safeZoneW/2";
			y = "(safeZoneY+safeZoneH/2)-(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))-(0.15*safeZoneH/5.5)";
			text = "";
			action = "";
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\rose\normal_top.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\rose\disabled_top.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\rose\over_top.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\rose\over_top.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\rose\down_top.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\rose\normal_top.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\rose\normal_top.paa";
		};
		class button03: button
		{
			idc = 1242;
			x = "(safeZoneX+safeZoneW/2)-0.18*safeZoneW/2";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))";
			text = "";
			action = "";
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\rose\normal_bottom.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\rose\disabled_bottom.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\rose\over_bottom.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\rose\over_bottom.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\rose\down_bottom.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\rose\normal_bottom.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\rose\normal_bottom.paa";
		};
		class button04: button
		{
			idc = 1243;
			x = "((safeZoneX+safeZoneW/2)-(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(-0.025*safeZoneW))-0.18*safeZoneW-(-0.00*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)-((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)/2-(0.15*safeZoneH/5.5)-((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)-(0.15*safeZoneH/5.5)";
			text = "";
			action = "";
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L01.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\rose\disabled_L01.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\rose\over_L01.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\rose\over_L01.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\rose\down_L01.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L01.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L01.paa";
		};
		class button05: button
		{
			idc = 1244;
			x = "((safeZoneX+safeZoneW/2)-(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(-0.015*safeZoneW))-0.18*safeZoneW-(-0.00*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)-((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)/2-(0.15*safeZoneH/5.5)";
			text = "";
			action = "";
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L02.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\rose\disabled_L02.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\rose\over_L02.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\rose\over_L02.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\rose\down_L02.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L02.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L02.paa";
		};
		class button06: button
		{
			idc = 1245;
			x = "((safeZoneX+safeZoneW/2)-(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(-0.015*safeZoneW))-0.18*safeZoneW-(-0.00*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)/2";
			text = "";
			action = "";
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L03.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\rose\disabled_L03.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\rose\over_L03.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\rose\over_L03.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\rose\down_L03.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L03.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L03.paa";
		};
		class button07: button
		{
			idc = 1246;
			x = "((safeZoneX+safeZoneW/2)-(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(-0.025*safeZoneW))-0.18*safeZoneW-(-0.00*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)/2+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)";
			text = "";
			action = "";
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L04.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\rose\disabled_L04.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\rose\over_L04.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\rose\over_L04.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\rose\down_L04.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L04.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\rose\normal_L04.paa";
		};
		class button08: button
		{
			idc = 1247;
			x = "((safeZoneX+safeZoneW/2)+(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(-0.025*safeZoneW))+(-0.00*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)-((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)/2-(0.15*safeZoneH/5.5)-((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)-(0.15*safeZoneH/5.5)";
			text = "";
			action = "";
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R01.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\rose\disabled_R01.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\rose\over_R01.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\rose\over_R01.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\rose\down_R01.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R01.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R01.paa";
		};
		class button09: button
		{
			idc = 1248;
			x = "((safeZoneX+safeZoneW/2)+(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(-0.015*safeZoneW))+(-0.00*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)-((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)/2-(0.15*safeZoneH/5.5)";
			text = "";
			action = "";
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R02.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\rose\disabled_R02.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\rose\over_R02.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\rose\over_R02.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\rose\down_R02.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R02.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R02.paa";
		};
		class button10: button
		{
			idc = 1249;
			x = "((safeZoneX+safeZoneW/2)+(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(-0.015*safeZoneW))+(-0.00*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)/2";
			text = "";
			action = "";
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R03.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\rose\disabled_R03.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\rose\over_R03.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\rose\over_R03.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\rose\down_R03.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R03.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R03.paa";
		};
		class button11: button
		{
			idc = 1250;
			x = "((safeZoneX+safeZoneW/2)+(0.15*safeZoneW*3/4/2+0.01*safeZoneW+(-0.025*safeZoneW))+(-0.00*safeZoneW))";
			y = "(safeZoneY+safeZoneH/2)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)/2+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)";
			text = "";
			action = "";
			animTextureNormal = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R04.paa";
			animTextureDisabled = "\x\cba\addons\ui\flexiMenu\data\rose\disabled_R04.paa";
			animTextureOver = "\x\cba\addons\ui\flexiMenu\data\rose\over_R04.paa";
			animTextureFocused = "\x\cba\addons\ui\flexiMenu\data\rose\over_R04.paa";
			animTexturePressed = "\x\cba\addons\ui\flexiMenu\data\rose\down_R04.paa";
			animTextureDefault = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R04.paa";
			animTextureNoShortcut = "\x\cba\addons\ui\flexiMenu\data\rose\normal_R04.paa";
		};
		class caption2: caption
		{
			idc = 1231;
			x = "(safeZoneX+safeZoneW/2)-(0.15*safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+0*0.033*safeZoneH";
			w = 0;
		};
		class listButton00: listButton
		{
			idc = 1340;
			x = "(safeZoneX+safeZoneW/2)-(0.15*safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+00)*0.033*safeZoneH";
		};
		class listButton01: listButton
		{
			idc = 1341;
			x = "(safeZoneX+safeZoneW/2)-(0.15*safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+01)*0.033*safeZoneH";
		};
		class listButton02: listButton
		{
			idc = 1342;
			x = "(safeZoneX+safeZoneW/2)-(0.15*safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+02)*0.033*safeZoneH";
		};
		class listButton03: listButton
		{
			idc = 1343;
			x = "(safeZoneX+safeZoneW/2)-(0.15*safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+03)*0.033*safeZoneH";
		};
		class listButton04: listButton
		{
			idc = 1344;
			x = "(safeZoneX+safeZoneW/2)-(0.15*safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+04)*0.033*safeZoneH";
		};
		class listButton05: listButton
		{
			idc = 1345;
			x = "(safeZoneX+safeZoneW/2)-(0.15*safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+05)*0.033*safeZoneH";
		};
		class listButton06: listButton
		{
			idc = 1346;
			x = "(safeZoneX+safeZoneW/2)-(0.15*safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+06)*0.033*safeZoneH";
		};
		class listButton07: listButton
		{
			idc = 1347;
			x = "(safeZoneX+safeZoneW/2)-(0.15*safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+07)*0.033*safeZoneH";
		};
		class listButton08: listButton
		{
			idc = 1348;
			x = "(safeZoneX+safeZoneW/2)-(0.15*safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+08)*0.033*safeZoneH";
		};
		class listButton09: listButton
		{
			idc = 1349;
			x = "(safeZoneX+safeZoneW/2)-(0.15*safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+09)*0.033*safeZoneH";
		};
		class listButton10: listButton
		{
			idc = 1350;
			x = "(safeZoneX+safeZoneW/2)-(0.15*safeZoneW/2)";
			y = "(safeZoneY+safeZoneH/2)+(0.15*safeZoneH/2+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3))+(0.15*safeZoneH/5.5)+((0.15*safeZoneH/2-2*(0.15*safeZoneH/5.5))*2/3)+(1+10)*0.033*safeZoneH";
		};
	};
};
class CfgSounds
{
	class ACE_Melee1
	{
		name = "ACE_Melee1";
		sound[] = {"\x\ace\addons\sys_interaction\sound\melee1.ogg","db-10",1};
		titles[] = {};
	};
	class ACE_Melee2
	{
		name = "ACE_Melee2";
		sound[] = {"\x\ace\addons\sys_interaction\sound\melee2.ogg","db-10",1};
		titles[] = {};
	};
};