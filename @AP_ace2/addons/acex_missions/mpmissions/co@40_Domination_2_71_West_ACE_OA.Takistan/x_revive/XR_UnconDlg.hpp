#include "xr_macros.sqf"
class GVARXR(UnconDlg) {
	idd = -1;
	movingEnable = 1;
	onLoad = "uiNamespace setVariable ['XR_UnconDlg', _this select 0];xr_lb_u_updater = true;d_do_ma_update_n = true;0 spawn xr_fnc_pllbupdater";
	onUnLoad = "uiNamespace setVariable ['XR_UnconDlg', nil];xr_lb_u_updater = false;d_do_ma_update_n = false";
	objects[] = {};
	class controlsBackground {
		class bg1 : GVARXR(XD_RscPicture) {
			x = SafeZoneXAbs;
			y = "SafeZoneY";
			w = SafeZoneWAbs;
			h = "SafeZoneH";
			idc = -1;
			colorBackground[] = {1, 0, 0, 0.5};
			text = "pics\screen_dirt_ca.paa";
		};
	};
	class controls {
		class FirstText: GVARXR(SXRscText) {
			idc = -1;
			x = 0.5 - 0.185;
			y = "SafeZoneY + 0.3";
			w = 0.5;
			h = 0.1;
			sizeEx = 0.05;
			colorText[] = {1, 1, 1, 1};
			text = "$STR_DOM_MISSIONSTRING_1336";
		};
		class SecondText: FirstText {
			idc = -1;
			x = 0.5 - 0.28;
			y = "SafeZoneY + 0.4";
			w = 0.7;
			sizeEx = 0.023;
			text = "$STR_DOM_MISSIONSTRING_1337";
		};
		class TimerTextCap: GVARXR(SXRscText) {
			idc = -1;
			x = 0.4;
			y = "SafeZoneY + SafeZoneH - 0.05";
			w = 0.1;
			h = 0.04;
			sizeEx = 0.023;
			colorText[] = {1, 1, 1, 1};
			text = "$STR_DOM_MISSIONSTRING_1011";
		};
		class TimerText: TimerTextCap {
			idc = 1005;
			x = 0.485;
			text = "";
		};
		class RespawnTextCap: GVARXR(SXRscText) {
			idc = -1;
			x = 0.55;
			y = "SafeZoneY + SafeZoneH - 0.05";
			w = 0.25;
			h = 0.04;
			sizeEx = 0.023;
			colorText[] = {1, 1, 1, 1};
			text = "$STR_DOM_MISSIONSTRING_1332";
		};
		class RespawnText: RespawnTextCap {
			idc = 1006;
			x = 0.77;
			text = "$STR_DOM_MISSIONSTRING_1007";
		};
		class NoRespawnTextCap: GVARXR(SXRscText) {
			idc = 1022;
			x = 0.55;
			y = "SafeZoneY + SafeZoneH - 0.17";
			w = 0.3;
			h = 0.1;
			sizeEx = 0.023;
			colorText[] = {1, 1, 1, 1};
			text = "";
		};
		class LeftPanel: GVARXR(SXRscListBox) {
			idc = 1000;
			x = "SafeZoneX + 0.05";
			y = "SafeZoneY + 0.1";
			w = "(SafeZoneW / 2) - 0.06";
			h = "SafeZoneH - 0.2";
			sizeEx = 0.04;
			text = "";
			colorText[] = {1,1,1,0.9};
			colorSelect[] = {1,1,1,0.9};
		};
		class maprespawn: GVARXR(XD_RscMapControl) {
			idc = 1001;
			x = 0.52;
			y = "SafeZoneY + 0.1";
			w = "(SafeZoneW / 2) - 0.06";
			h = "SafeZoneH - 0.2";
			colorBackground[] = {1, 1, 1, 1};
			onMouseButtonClick = "_pp = (_this select 0) ctrlMapScreenToWorld [_this select 2, _this select 3];_pp call xr_fnc_OnMapSingleClickResp";
		};
		class MapButton: GVARXR(XD_ButtonBase) {
			idc = 1002;
			text = "$STR_DOM_MISSIONSTRING_1333"; 
			action = "_ctrl = (uiNamespace getVariable 'XR_UnconDlg') displayCtrl 1001;if (ctrlShown _ctrl) then {ctrlShow [1001, false];((uiNamespace getVariable 'XR_UnconDlg') displayCtrl 1002) ctrlSetText 'Show Map'} else {ctrlShow [1001, true];((uiNamespace getVariable 'XR_UnconDlg') displayCtrl 1002) ctrlSetText 'Hide Map'}";
			x = "SafeZoneX + SafeZoneW - 0.263";
			y = "SafeZoneY + SafeZoneH - 0.08";
		};
		class NearPlayersButton: GVARXR(XD_ButtonBase) {
			idc = 1003;
			text = "$STR_DOM_MISSIONSTRING_1338"; 
			action = "_ctrl = (uiNamespace getVariable 'XR_UnconDlg') displayCtrl 1000;if (ctrlShown _ctrl) then {ctrlShow [1000, false];((uiNamespace getVariable 'XR_UnconDlg') displayCtrl 1003) ctrlSetText 'Near Players'} else {ctrlShow [1000, true];((uiNamespace getVariable 'XR_UnconDlg') displayCtrl 1003) ctrlSetText 'Hide NPlayers'}";
			x = "SafeZoneX + 0.05";
			y = "SafeZoneY + SafeZoneH - 0.08";
		};
	};
};
