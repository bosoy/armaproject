class XD_ArtilleryDialog {
	idd = -1;
	movingEnable = true;
	onLoad = "uiNamespace setVariable ['D_ARTI_DISP', _this select 0];call d_fnc_initArtyDlg;d_arti_dialog_open = true;d_do_ma_update_n = true";
	onUnLoad = "uiNamespace setVariable ['D_ARTI_DISP', nil];d_arti_dialog_open = false;d_do_ma_update_n = false";
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
			XCMainCapt;
			text = "$STR_DOM_MISSIONSTRING_1242";
		};
		class XD_SalvosText : XC_RscText {
			idc = 11009;
			x = 0.68; y = 0.3;
			w = 0.3; h = 0.1;
			colorBackground[] = {1, 1, 1, 0};
			XCTextBI;
			sizeEx = 0.03;
			text = "$STR_DOM_MISSIONSTRING_1243";
		};
		class FireSeriesCombo:XD_UIComboBox {
			idc = 889;
			x = 0.685; y = 0.375;
			w = 0.218; h = 0.035;
		};		
		class ArtyTypeCombo:XD_UIComboBox {
			idc = 888;
			x = 0.685; y = 0.235;
			w = 0.218; h = 0.035;
		};
		class ArtyFireButton: XD_ButtonBase {
			idc = 890;
			text = "$STR_DOM_MISSIONSTRING_1244"; 
			action = "call d_fnc_FireArty; closeDialog 0";
			x = 0.68; y = 0.5;
		};
		class XD_ArtiText : XC_RscText {
			x = 0.68; y = 0.16;
			w = 0.3; h = 0.1;
			colorBackground[] = {1, 1, 1, 0};
			XCTextBI;
			sizeEx = 0.03;
			text = "$STR_DOM_MISSIONSTRING_1245";
		};
		class XD_ArtiMapText : XC_RscText {
			x = 0.12; y = 0.12;
			w = 0.3; h = 0.1;
			colorBackground[] = {1, 1, 1, 0};
			XCTextBlack;
			text = "$STR_DOM_MISSIONSTRING_1246";
		};
		class XD_Map : XD_RscMapControl {
			idc = 11111;
			colorBackground[] = {0.9, 0.9, 0.9, 0.9};
			x = 0.12; y = 0.2;
			w = 0.52; h = 0.64;
			showCountourInterval = false;
			onMouseButtonClick = "if (ctrlShown ((uiNamespace getVariable 'D_ARTI_DISP') displayCtrl 11111)) then {_pp = (_this select 0) ctrlMapScreenToWorld [_this select 2, _this select 3];D_ARTI_HELPER setpos _pp;D_ARTI_MARKER_HELPER setMarkerPos _pp}";
		};
		class Dom2 : XC_RscText {
			x = 0.12; y = 0.91;
			w = 0.25; h = 0.1;
			sizeEx = 0.035;
			colorBackground[] = {1, 1, 1, 0};
			XCMainCapt;
			text = __DOM_NVER_STR__;
		};
		class XD_CancelButton: XD_ButtonBase {
			idc = -1;
			text = "$STR_DOM_MISSIONSTRING_1229";
			action = "closeDialog 0";
			default = true;
			x = 0.68; y = 0.91;
		};
	};
};
