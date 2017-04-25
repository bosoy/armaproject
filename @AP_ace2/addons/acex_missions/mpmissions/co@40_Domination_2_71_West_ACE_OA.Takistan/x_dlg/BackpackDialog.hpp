#include "x_setup.sqf"
class GVAR(BackpackDialog) {
	idd = -1;
	movingEnable = 1;
	onLoad = "uiNamespace setVariable ['D_BACKPACK_DIALOG', _this select 0];d_backpack_dialog_open = true;d_do_ma_update_n = true;call d_fnc_fillbackpacks";
	onUnLoad = "uiNamespace setVariable ['D_BACKPACK_DIALOG', nil];d_backpack_dialog_open = false;d_do_ma_update_n = false";
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
		class XD_TakeButton: XD_ButtonBase {
			text = "$STR_DOM_MISSIONSTRING_1247";
			action = "CloseDialog 0;call d_fnc_take_backpack";
			x = 0.61; y = 0.43;
		};
		class XD_CloseButton: XD_ButtonBase {
			idc = -1;
			text = "$STR_DOM_MISSIONSTRING_1229"; 
			action = "closeDialog 0";
			default = true;
			x = 0.68; y = 0.91;
		};
		class XD_MainCaption: XC_RscText {
			x = 0.12; y = 0.01;
			w = 0.25; h = 0.1;
			sizeEx = 0.035;
			colorBackground[] = {1, 1, 1, 0};
			colorText[] = {0.643, 0.5742, 0.4102, 1};
			text = "$STR_DOM_MISSIONSTRING_1248";
		};
		class Dom2: XC_RscText {
			x = 0.12; y = 0.91;
			w = 0.25; h = 0.1;
			sizeEx = 0.035;
			colorBackground[] = {1, 1, 1, 0};
			XCMainCapt;
			text = __DOM_NVER_STR__;
		};
		class ListBoxCaption: XC_RscText {
			x = 0.1; y = 0.11;
			w = 0.2; h = 0.1;
			sizeEx = 0.029;
			colorBackground[] = {1, 1, 1, 0};
			XCTextBlack;
			text = "$STR_DOM_MISSIONSTRING_1249";
		};
		class BackpackListbox: SXRscListBox {
			idc = 1000;
			x = 0.1; y = 0.2;
			w = 0.4; h = 0.6;
			style = ST_LEFT;
			onLBSelChanged = "[_this] call d_fnc_blselchanged";
		};
		class BackpackCaption: XC_RscText {
			idc = 1003;
			x = 0.55; y = 0.11;
			w = 0.4; h = 0.1;
			sizeEx = 0.029;
			colorBackground[] = {1, 1, 1, 0};
			XCTextBlack;
			text = "";
		};
		class BackpackPic: XD_RscPicture {
			idc = 1001;
			x = 0.6; y = 0.18;
			w = 0.25; h = 0.25;
		};
		class CurBackpackCaption: XC_RscText {
			idc = 1004;
			x = 0.55; y = 0.51;
			w = 0.4; h = 0.1;
			sizeEx = 0.029;
			colorBackground[] = {1, 1, 1, 0};
			XCTextBlack;
			text = "";
		};
		class CurBackpackPic: XD_RscPicture {
			idc = 1002;
			x = 0.6; y = 0.58;
			w = 0.25; h = 0.25;
		};
	};
};
