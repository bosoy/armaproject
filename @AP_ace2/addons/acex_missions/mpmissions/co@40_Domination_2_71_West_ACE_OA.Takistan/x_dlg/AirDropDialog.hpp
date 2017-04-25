class x_x_RscText {
	type = CT_STATIC;
	idc = -1;
	style = ST_LEFT;
	x = 0.0;y = 0.0;w = 0.3;h = 0.03;
	sizeEx = 0.023;
	colorBackground[] = {0.5, 0.5, 0.5, 0.75};
	colorText[] = {0, 0, 0, 1};
	font = FontM;
	text = "";
	shadow = 2;
};
class XD_AirDropDialog {
	idd = -1;
	movingEnable = true;
	onLoad = "uiNamespace setVariable ['D_DROP_DIALOG', _this select 0];d_airdrop_dialog_open = true;d_do_ma_update_n = true";
	onUnLoad = "uiNamespace setVariable ['D_DROP_DIALOG', nil];d_airdrop_dialog_open = false;d_do_ma_update_n = false";
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
			text = "$STR_DOM_MISSIONSTRING_1228";
		};
		class XD_CancelButton: XD_ButtonBase {
			idc = -1;
			text = "$STR_DOM_MISSIONSTRING_1229"; 
			action = "closeDialog 0";
			default = true;
			x = 0.68; y = 0.91;
		};
		class XD_Drop3: XD_ButtonBase {
			idc = 11004;
			text = "$STR_DOM_MISSIONSTRING_1230";
			action = "d_x_drop_type = (d_X_Drop_Array select 2) select 1;closeDialog 0";
			x = 0.68; y = 0.32;
		};
		class XD_Drop2: XD_Drop3 {
			idc = 11003;
			text = "$STR_DOM_MISSIONSTRING_1231";
			action = "d_x_drop_type = (d_X_Drop_Array select 1) select 1;closeDialog 0";
			y = 0.26;
		};
		class XD_Drop1: XD_Drop3 {
			idc = 11002;
			text = "$STR_DOM_MISSIONSTRING_1232";
			action = "d_x_drop_type = (d_X_Drop_Array select 0) select 1;closeDialog 0";
			y = 0.20;
		};
		class XD_DropText : XC_RscText {
			x = 0.68; y = 0.16;
			w = 0.3; h = 0.1;
			colorBackground[] = {1, 1, 1, 0};
			XCTextBI;
			sizeEx = 0.03;
			text = "$STR_DOM_MISSIONSTRING_1233";
		};
		class XD_DropMapText : x_x_RscText {
			x = 0.12; y = 0.12;
			w = 0.3; h = 0.1;
			colorBackground[] = {1, 1, 1, 0};
			XCTextBlack;
			text = "$STR_DOM_MISSIONSTRING_1234";
		};
		class XD_Map : XD_RscMapControl {
			idc = 11111;
			colorBackground[] = {0.9, 0.9, 0.9, 0.9};
			x = 0.12; y = 0.2;
			w = 0.52; h = 0.64;
			showCountourInterval = false;
			onMouseButtonClick = "if (ctrlShown ((uiNamespace getVariable 'D_DROP_DIALOG') displayCtrl 11111)) then {_pp = (_this select 0) ctrlMapScreenToWorld [_this select 2, _this select 3];d_X_DropZone setpos _pp;'d_drop_zone' setMarkerPos _pp}";
		};
		class Dom2 : XC_RscText {
			x = 0.12; y = 0.91;
			w = 0.25; h = 0.1;
			sizeEx = 0.035;
			colorBackground[] = {1, 1, 1, 0};
			XCMainCapt;
			text = __DOM_NVER_STR__;
		};
	};
};
