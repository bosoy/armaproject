#include "x_setup.sqf"
class XD_PlayerStatsDialog {
	idd = -1;
	movingEnable = 1;
	onLoad = "uiNamespace setVariable ['D_PSTATS_DLG', _this select 0];d_pstats_dialog_open = true;d_do_ma_update_n = true";
	onUnLoad = "uiNamespace setVariable ['D_PSTATS_DLG', nil];d_pstats_dialog_open = false;d_do_ma_update_n = false";
	objects[] = {};
	class controlsBackground {
		class XD_BackGround : XD_RscPicture {
			x = 0; y = 0;
			w = 1.2549; h = 1.03;
			colorBackground[] = {0,0,0,0};
			text = __UI_Path(ui_background_controls_ca.paa);
		};
	};
	class controls {
		class XD_CloseButton: XD_ButtonBase {
			idc = -1;
			text = "$STR_DOM_MISSIONSTRING_1218"; 
			action = "closeDialog 0";
			default = true;
			x = 0.68; y = 0.91;
		};
		class XD_MainCaption : XC_RscText {
			x = 0.12; y = 0.01;
			w = 0.25; h = 0.1;
			sizeEx = 0.035;
			colorBackground[] = {1, 1, 1, 0};
			colorText[] = {0.643, 0.5742, 0.4102, 1};
			text = "PLAYER STATS";
		};
		class Dom2 : XD_MainCaption {
			y = 0.91;
			XCMainCapt;
			text = __DOM_NVER_STR__;
		};
		class NamePlayerCaption : XC_RscText {
			x = 0.12; y = 0.1;
			w = 0.2; h = 0.1;
			sizeEx = 0.032;
			colorBackground[] = {1, 1, 1, 0};
			XCTextBlack;
			text = "Name player:";
		};
		class NamePlayerValue : NamePlayerCaption {
			idc = 1200;
			x = 0.4;
			text = "";
		};
		class UIDCaption : NamePlayerCaption {
			y = 0.14;
			text = "UID player:";
		};
		class UIDValue : NamePlayerValue {
			idc = 1201;
			y = 0.14;
			text = "";
		};
		class ServerCaption : NamePlayerCaption {
			idc = 2200;
			y = 0.18;
			text = "Server name:";
		};
		class ServerValue : NamePlayerValue {
			idc = 1202;
			y = 0.18;
			text = "";
		};
		class TimesPlayedCaption : NamePlayerCaption {
			y = 0.22;
			text = "Times played:";
		};
		class TimesPlayedValue : NamePlayerValue {
			idc = 1215;
			y = 0.22;
			text = "";
		};
		class TotalScoreCaption : NamePlayerCaption {
			y = 0.26;
			text = "Total score:";
		};
		class TotalScoreValue : NamePlayerValue {
			idc = 1203;
			y = 0.26;
			text = "";
		};
		class TimePlayedCaption : NamePlayerCaption {
			y = 0.3;
			text = "Time played:";
		};
		class TimePlayedValue : NamePlayerValue {
			idc = 1204;
			y = 0.3;
			text = "";
		};
		class AIKillsCaption : NamePlayerCaption {
			y = 0.34;
			text = "AI unit kills:";
		};
		class AIKillsValue : NamePlayerValue {
			idc = 1205;
			y = 0.34;
			text = "";
		};
		class HumanKillsCaption : NamePlayerCaption {
			y = 0.38;
			text = "Player kills (TT only):";
		};
		class HumanKillsValue : NamePlayerValue {
			idc = 1206;
			y = 0.38;
			text = "";
		};
		class CarKillsCaption : NamePlayerCaption {
			y = 0.42;
			text = "Cars destroyed:";
		};
		class CarKillsValue : NamePlayerValue {
			idc = 1207;
			y = 0.42;
			text = "";
		};
		class APCKillsCaption : NamePlayerCaption {
			y = 0.46;
			text = "APCs destroyed:";
		};
		class APCKillsValue : NamePlayerValue {
			idc = 1208;
			y = 0.46;
			text = "";
		};
		class TankKillsCaption : NamePlayerCaption {
			y = 0.5;
			text = "Tanks destroyed:";
		};
		class TankKillsValue : NamePlayerValue {
			idc = 1209;
			y = 0.5;
			text = "";
		};
		class PlaneKillsCaption : NamePlayerCaption {
			y = 0.54;
			text = "Planes destroyed:";
		};
		class PlaneKillsValue : NamePlayerValue {
			idc = 1210;
			y = 0.54;
			text = "";
		};
		class ChopperKillsCaption : NamePlayerCaption {
			y = 0.58;
			text = "Choppers destroyed:";
		};
		class ChopperKillsValue : NamePlayerValue {
			idc = 1211;
			y = 0.58;
			text = "";
		};
		class RadioTowerKillsCaption : NamePlayerCaption {
			y = 0.62;
			text = "Radio Towers destroyed:";
		};
		class RadioTowerKillsValue : NamePlayerValue {
			idc = 1212;
			y = 0.62;
			text = "";
		};
		class MainTargetObjectKillsCaption : NamePlayerCaption {
			y = 0.66;
			text = "MT objects destroyed:";
		};
		class MainTargetObjectKillsValue : NamePlayerValue {
			idc = 1213;
			y = 0.66;
			text = "";
		};
		class DeathsUnconsCaption : NamePlayerCaption {
			y = 0.7;
			text = "Deaths/Uncons:";
		};
		class DeathsUnconsValue : NamePlayerValue {
			idc = 1214;
			y = 0.7;
			text = "";
		};
	};
};
