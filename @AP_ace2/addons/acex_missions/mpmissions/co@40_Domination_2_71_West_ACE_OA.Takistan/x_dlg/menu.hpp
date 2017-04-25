class d_TeleportModule {
	idd = -1;
	movingEnable = false;
	objects[] = {};
	onLoad="uiNamespace setVariable ['X_TELE_DIALOG', _this select 0];d_teleport_dialog_open = true;d_do_ma_update_n = true;0 spawn d_fnc_x_teleupdate_dlg";
	onUnLoad="uiNamespace setVariable ['X_TELE_DIALOG', nil];d_teleport_dialog_open = false;d_do_ma_update_n = false";
	class controlsBackground {
		class bg1 : RscBG {
			x = SafeZoneXAbs;
			y = SafeZoneY;
			w = SafeZoneWAbs;
			h = SafeZoneH;
			idc = 100101;
			colorBackground[] = {0.106, 0.133, 0.102, 1};
		};
	};
	class controls {
		class respawn: XD_ButtonBase {
			idc = 100102;
			text = "$STR_DOM_MISSIONSTRING_1250"; 
			action = "call d_fnc_x_beam_tele";
			x = "SafeZoneX + SafeZoneW - 0.37";
			y = 0.67;
			w = 0.3;
			default = true;
		};
		class cancelb: XD_ButtonBase {
			idc = 100103;
			text = "$STR_DOM_MISSIONSTRING_1229"; 
			action = "CloseDialog 0";
			x = "SafeZoneX + 0.04";
			y = "SafeZoneY + SafeZoneH - 0.09";
			w = 0.3;
		};
		class BaseButton: XD_ButtonBase {
			idc = 100107;
			text = "$STR_DOM_MISSIONSTRING_1251"; 
			action = "[0] call d_fnc_x_update_target";
			x = "SafeZoneX + SafeZoneW - 0.37";
			y = 0.34;
			w = 0.3;
		};
		class Mr1Button: XD_ButtonBase {
			idc = 100108;
			text = "$STR_DOM_MISSIONSTRING_1252";
			action = "[1] call d_fnc_x_update_target";
			x = "SafeZoneX + SafeZoneW - 0.37";
			y = 0.41;
			w = 0.3;
		};
		class Mr2Button: XD_ButtonBase {
			idc = 100109;
			text = "$STR_DOM_MISSIONSTRING_1253";
			action = "[2] call d_fnc_x_update_target";
			x = "SafeZoneX + SafeZoneW - 0.37";
			y = 0.48;
			w = 0.3;
		};
		class Tdestination : SXRscText {
			idc = 100110;
			x = "SafeZoneX + SafeZoneW - 0.37";
			y = 0.55;
			w = 0.3;
			h = 0.1;
			sizeEx = 0.025;
			text = "";
		};
		class dtext : SXRscText {
			x = "SafeZoneX + SafeZoneW - 0.2";
			y = "SafeZoneY + SafeZoneH - 0.09";
			w = 0.3;
			h = 0.1;
			font = "Zeppelin32";
			sizeEx = 0.03921;
			XCTextBI;
			text = __DOM_NVER_STR__;
		};
		class maprespawn : XD_RscMapControl {
			idc = 100104;
			x = "SafeZoneX + 0.3";
			y = "SafeZoneY + 0.3";
			w = "(SafeZoneX + SafeZoneW - 0.52) - (SafeZoneX + 0.3)";
			h = "(SafeZoneY + SafeZoneH) - 0.3 - (SafeZoneY + 0.4)";
			colorBackground[] = {1, 1, 1, 1};
		};
		class mr1inair : SXRscText {
			idc = 100105;
			x = "SafeZoneX + SafeZoneW - 0.37";
			y = 0.75;
			w = 0.4;
			h = 0.1;
			sizeEx = 0.02;
			text = "";
		};
		class mr2inair : SXRscText {
			idc = 100106;
			x = "SafeZoneX + SafeZoneW - 0.37";
			y = 0.772;
			w = 0.4;
			h = 0.1;
			sizeEx = 0.02;
			text = "";
		};
		class respawncaption : SXRscText {
			idc = 100111;
			x = 0.35;
			y = "SafeZoneY + 0.02";
			w = 0.6;
			h = 0.2;
			font = "Zeppelin32";
			sizeEx = 0.03921;
			XCTextBI;
			text = "$STR_DOM_MISSIONSTRING_1254";
		};
		class changepos : SXRscText {
			idc = 100112;
			x = "(((SafeZoneX + SafeZoneW - 0.42) - (SafeZoneX + 0.1)) / 2) - 0.2 + (SafeZoneX + 0.1)";
			y = "SafeZoneY + 0.2 + (SafeZoneY + SafeZoneH) - 0.2";
			w = 0.6;
			h = 0.2;
			font = "Zeppelin32";
			sizeEx = 0.03921;
			XCTextBI;
			text = "$STR_DOM_MISSIONSTRING_1255";
		};
	};
};
