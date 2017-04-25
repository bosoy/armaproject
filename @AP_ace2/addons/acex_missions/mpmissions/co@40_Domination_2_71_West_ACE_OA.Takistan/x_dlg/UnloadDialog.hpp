class XD_UnloadDialog {
	idd = -1;
	movingEnable = 1;
	onLoad="uiNamespace setVariable ['D_UNLOAD_DIALOG', _this select 0];d_unload_dialog_open = true;d_do_ma_update_n = true;call d_fnc_fillunload";
	onUnLoad="uiNamespace setVariable ['D_UNLOAD_DIALOG', nil];d_unload_dialog_open = false;d_do_ma_update_n = false";
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
			text = "$STR_DOM_MISSIONSTRING_1319";
		};
		class XD_SelectButton: XD_ButtonBase {
			idc = -1;
			text = "$STR_DOM_MISSIONSTRING_1320"; 
			action = "call d_fnc_unloadsetcargo";
			x = 0.23;
			y = 0.70;
		};
		class XD_CancelButton: XD_ButtonBase {
			idc = -1;
			text = "$STR_DOM_MISSIONSTRING_1229"; 
			action = "closeDialog 0";
			x = 0.56;
			y = 0.70;
			default = true;
		};
		class XD_Unloadlistbox : SXRscListBox {
			idc = 101115;
			x = 0.36;
			y = 0.3;
			w = 0.275;
			h = 0.36;
			sizeEx = 0.023;
			rowHeight = 0.06;
			style = ST_LEFT;
		};
		class XD_UnloadCaption : XC_RscText {
			x = 0.4;
			y = 0.22;
			w = 0.2;
			h = 0.1;
			colorBackground[] = {1, 1, 1, 0};
			XCTextBlack;
			text = "$STR_DOM_MISSIONSTRING_1321";
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
