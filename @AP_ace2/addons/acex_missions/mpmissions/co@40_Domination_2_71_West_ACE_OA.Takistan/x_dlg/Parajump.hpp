#include "x_setup.sqf"
class XD_ParajumpDialog {
	idd = -1;
	movingEnable = true;
	onLoad = "d_parajump_dialog_open = true;d_do_ma_update_n = true";
	onUnLoad = "d_parajump_dialog_open = false;d_do_ma_update_n = false";
	objects[] = {};
	class controlsBackground {
		class XD_BackGround : XD_RscPicture {
			x = 0;
			y = 0;
			w = 1.2549;
			h = 1.03;
			colorBackground[] = {0,0,0,0};
			text = __UI_Path(ui_background_controls_ca.paa);
		};
	};
	class controls {
		class XD_MainCaption : XC_RscText {
			x = 0.12;
			y = 0.01;
			w = 0.25;
			h = 0.1;
			sizeEx = 0.035;
			colorBackground[] = {1, 1, 1, 0};
			XCTextBI;
			text = "$STR_DOM_MISSIONSTRING_1266";
		};
		class XD_CancelButton: XD_ButtonBase {
			idc = -1;
			text = "$STR_DOM_MISSIONSTRING_1229"; 
			action = "closeDialog 0";
			x = 0.68;
			y = 0.91;
			default = true;
		};
		class XD_ParaMapText : XC_RscText {
			x = 0.12;
			y = 0.12;
			w = 0.7;
			h = 0.1;
			colorBackground[] = {1, 1, 1, 0};
			XCTextBlack;
			text = "$STR_DOM_MISSIONSTRING_1267";
		};
		class XD_ArtiMapText2 : XC_RscText {
			x = 0.12;
			y = 0.77;
			w = 0.7;
			h = 0.1;
			colorBackground[] = {1, 1, 1, 0};
			XCTextBlack;
	#ifndef __ACE__
			text = "$STR_DOM_MISSIONSTRING_1268";
	#else
			text = "$STR_DOM_MISSIONSTRING_1269";
	#endif
		};
		class XD_ArtiMapText3 : XC_RscText {
			x = 0.12;
			y = 0.80;
			w = 0.7;
			h = 0.1;
			colorBackground[] = {1, 1, 1, 0};
			XCTextBlack;
	#ifndef __ACE__
			text = "$STR_DOM_MISSIONSTRING_1270";
	#else
			text = "$STR_DOM_MISSIONSTRING_1271";
	#endif
		};
		class XD_Map : XD_RscMapControl {
			colorBackground[] = {0.9, 0.9, 0.9, 0.9};
			x = 0.12;
			y = 0.2;
			w = 0.76;
			h = 0.58;
			showCountourInterval = false;
			onMouseButtonClick = "closeDialog 0;_pp = (_this select 0) ctrlMapScreenToWorld [_this select 2, _this select 3];d_global_jump_pos = _pp";
		};
		class Dom2 : XC_RscText {
			x = 0.12;
			y = 0.91;
			w = 0.25;
			h = 0.1;
			sizeEx = 0.035;
			colorBackground[] = {1, 1, 1, 0};
			XCMainCapt;
			text = __DOM_NVER_STR__;
		};
	};
};
