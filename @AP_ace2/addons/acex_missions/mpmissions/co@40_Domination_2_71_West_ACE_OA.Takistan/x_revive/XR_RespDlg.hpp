#include "xr_macros.sqf"
class GVARXR(RespDlg) {
	idd = -1;
	movingEnable = 1;
	onLoad = "uiNamespace setVariable ['XR_RespDlg', _this select 0];d_do_ma_update_n = true";
	onUnload = "uiNamespace setVariable ['XR_RespDlg', nil];d_do_ma_update_n = false";
	objects[] = {};
	class controlsBackground {
		class bg1 : GVARXR(SXRscText) {
			x = SafeZoneXAbs;
			y = "SafeZoneY";
			w = SafeZoneWAbs;
			h = "SafeZoneH";
			idc = -1;
			colorBackground[] = {0, 0, 0, 1};
			text = "";
		};
	};
	class controls {
		class RespawnText: GVARXR(SXRscText) {
			idc = 1000;
			x = 0.33;
			y = "SafeZoneY + SafeZoneH - 0.2";
			w = 0.5;
			h = 0.1;
			sizeEx = 0.023;
			colorText[] = {1, 1, 1, 1};
			text = "$STR_DOM_MISSIONSTRING_1329";
		};
		class maprespawn: GVARXR(XD_RscMapControl) {
			idc = 1001;
			x = "SafeZoneX + 0.1";
			y = "SafeZoneY + 0.1";
			w = "SafeZoneW - 0.2";
			h = "SafeZoneH - 0.2";
			colorBackground[] = {1, 1, 1, 1};
			onMouseButtonClick = "_pp = (_this select 0) ctrlMapScreenToWorld [_this select 2, _this select 3];_pp call xr_fnc_OnMapSingleClickResp2";
		};
	};
};
