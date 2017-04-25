class XD_AIRecruitDialog {
	idd = -1;
	movingEnable = true;
	onLoad = "uiNamespace setVariable ['D_RECRUIT_DIALOG', _this select 0];call d_fnc_fillRecruit;d_airecruit_dialog_open = true;d_do_ma_update_n = true";
	onUnLoad = "uiNamespace setVariable ['D_RECRUIT_DIALOG', nil];d_airecruit_dialog_open = false;d_do_ma_update_n = false";
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
		class XD_MainCaption : XC_RscText {
			x = 0.12; y = 0.01;
			w = 0.25; h = 0.1;
			sizeEx = 0.035;
			colorBackground[] = {1, 1, 1, 0};
			XCTextBI;
			text = "$STR_DOM_MISSIONSTRING_1235";
		};
		class XD_CancelButton: XD_ButtonBase {
			idc = -1;
			text = "$STR_DOM_MISSIONSTRING_1236"; 
			action = "closeDialog 0";
			default = true;
			x = 0.68; y = 0.91;
		};
		class Dom4 : XC_RscText {
			x = 0.12; y = 0.91;
			w = 0.25; h = 0.1;
			sizeEx = 0.035;
			colorBackground[] = {1, 1, 1, 0};
			XCMainCapt;
			text = __DOM_NVER_STR__;
		};
		
		class UnitsListBoxCaption: XC_RscText {
			x = 0.08; y = 0.11;
			w = 0.2; h = 0.1;
			sizeEx = 0.029;
			colorBackground[] = {1, 1, 1, 0};
			XCTextBlack;
			text = "$STR_DOM_MISSIONSTRING_1237";
		};
		class UnitsListbox: SXRscListBox {
			idc = 1000;
			x = 0.08; y = 0.2;
			w = 0.4; h = 0.5;
			style = ST_LEFT;
			onMouseButtonDblClick = "call d_fnc_recruitbuttonaction";
		};
		class XD_RecruitButton: XD_ButtonBase {
			idc = 1010;
			text = "$STR_DOM_MISSIONSTRING_1238"; 
			action = "call d_fnc_recruitbuttonaction";
			x = 0.17; y = 0.7;
		};
		
		class CurUnitsListBoxCaption: XC_RscText {
			idc = 1030;
			x = 0.5; y = 0.11;
			w = 0.3; h = 0.1;
			sizeEx = 0.029;
			colorBackground[] = {1, 1, 1, 0};
			XCTextBlack;
			text = "$STR_DOM_MISSIONSTRING_1239";
		};
		class CurUnitsListbox: SXRscListBox {
			idc = 1001;
			x = 0.5; y = 0.2;
			w = 0.4; h = 0.5;
			style = ST_LEFT;
			onMouseButtonDblClick = "call d_fnc_dismissbuttonaction";
		};
		
		class XD_DismissButton: XD_ButtonBase {
			idc = 1011;
			text = "$STR_DOM_MISSIONSTRING_1240";
			action = "call d_fnc_dismissbuttonaction";
			x = 0.59; y = 0.7;
		};
		
		class XD_DismissAllButton: XD_ButtonBase {
			idc = 1012;
			text = "$STR_DOM_MISSIONSTRING_1241"; 
			action = "call d_fnc_dismissallbuttonaction";
			x = 0.37; y = 0.79;
		};
	};
};
