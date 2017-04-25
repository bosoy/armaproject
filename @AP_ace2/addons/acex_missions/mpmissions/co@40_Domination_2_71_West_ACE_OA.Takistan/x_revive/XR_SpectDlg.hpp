#include "xr_macros.sqf"
class GVARXR(SpectDlg) {
	idd = -1;
	movingEnable = 1;
	onLoad = "uiNamespace setVariable ['XR_SpectDlg', _this select 0];d_do_ma_update_n = true";
	//onUnload = "uiNamespace setVariable ['XR_SpectDlg', nil];d_do_ma_update_n = false";
	objects[] = {};
	class controls {
		class MouseMovement: GVARXR(mouseHandler) {};
		class BorderTop {
			idc = -1;
			x = SafeZoneXAbs; y = SafeZoneY;
			w = SafeZoneWAbs; h = 0.06;
			type = CT_STATIC;
			style = ST_CENTER;
			font = "TahomaB";
			sizeEx = 0.04;
			colorText[] = { 1, 1, 1, 1 };
			colorBackground[] = {0,0,0,1};
			text = "";
		};
		class BorderBot: BorderTop {
			y = SafeZoneY + SafeZoneH - 0.06;
		};
		class FollowingCaption: GVARXR(SXRscText) {
			idc = -1;
			x = "SafeZoneX + 0.05";
			y = "SafeZoneY + 0.01";
			w = 0.5;
			h = 0.04;
			sizeEx = 0.032;
			colorText[] = {1, 1, 1, 1};
			text = "$STR_DOM_MISSIONSTRING_1330";
		};
		class FollowingText: FollowingCaption {
			idc = 1010;
			x = "SafeZoneX + 0.15";
			text = "";
		};
		class SpectatingCaption: GVARXR(SXRscText) {
			idc = -1;
			x = "SafeZoneX + (SafeZoneW / 2) - 0.05";
			y = "SafeZoneY + 0.01";
			w = 0.5;
			h = 0.04;
			sizeEx = 0.032;
			colorText[] = {1, 0, 0, 1};
			text = "$STR_DOM_MISSIONSTRING_1331";
		};
		class TimerTextCap: GVARXR(SXRscText) {
			idc = 1020;
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
			idc = 1021;
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
			y = "SafeZoneY + 0.08";
			w = "(SafeZoneW / 2) - 0.06";
			h = "SafeZoneH - 0.08 - 0.08";
			sizeEx = 0.04;
			text = "";
			colorText[] = {1,1,1,1};
			colorSelect[] = {1,1,1,0.9};
			onLBSelChanged = "_this call xr_fnc_targetsslbchange";
		};
		class maprespawn: GVARXR(XD_RscMapControl) {
			idc = 1001;
			x = 0.52;
			y = "SafeZoneY + 0.08";
			w = "(SafeZoneW / 2) - 0.06";
			h = "SafeZoneH - 0.08 - 0.08";
			colorBackground[] = {1, 1, 1, 1};
			onMouseButtonClick = "if (xr_followcam) then {_pp = (_this select 0) ctrlMapScreenToWorld [_this select 2, _this select 3];_pp call xr_fnc_OnMapSingleClickResp}";
		};
		class MapButton: GVARXR(XD_ButtonBase) {
			idc = 1002;
			text = "$STR_DOM_MISSIONSTRING_1333"; 
			action = "_ctrl = (uiNamespace getVariable 'XR_SpectDlg') displayCtrl 1001;if (ctrlShown _ctrl) then {ctrlShow [1001, false];((uiNamespace getVariable 'XR_SpectDlg') displayCtrl 1002) ctrlSetText 'Show Map'} else {ctrlShow [1001, true];((uiNamespace getVariable 'XR_SpectDlg') displayCtrl 1002) ctrlSetText 'Hide Map'}";
			x = "SafeZoneX + SafeZoneW - 0.263";
			y = "SafeZoneY + SafeZoneH - 0.08";
		};
		class ShowPlayersButton: GVARXR(XD_ButtonBase) {
			idc = 1003;
			text = "$STR_DOM_MISSIONSTRING_1334"; 
			action = "_ctrl = (uiNamespace getVariable 'XR_SpectDlg') displayCtrl 1000;if (ctrlShown _ctrl) then {ctrlShow [1000, false];((uiNamespace getVariable 'XR_SpectDlg') displayCtrl 1003) ctrlSetText 'Show Players'} else {ctrlShow [1000, true];((uiNamespace getVariable 'XR_SpectDlg') displayCtrl 1003) ctrlSetText 'Hide Players'}";
			x = "SafeZoneX + 0.05";
			y = "SafeZoneY + SafeZoneH - 0.08";
		};
		class NVGButton: GVARXR(XD_ButtonBase) {
			idc = 1004;
			text = "$STR_DOM_MISSIONSTRING_1335"; 
			action = "if (!xr_camnvgon) then {camUseNVG true; xr_camnvgon = true;((uiNamespace getVariable 'XR_SpectDlg') displayCtrl 1004) ctrlSetText 'Nightvision Off'} else {camUseNVG false; xr_camnvgon = false;((uiNamespace getVariable 'XR_SpectDlg') displayCtrl 1004) ctrlSetText 'Nightvision On'}";
			x = "SafeZoneX + 0.3";
			y = "SafeZoneY + SafeZoneH - 0.08";
		};
	};
};
