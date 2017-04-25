class XD_MsgDialog {
	idd = -1;
	movingEnable = 1;
	objects[] = {};
	onLoad="uiNamespace setVariable ['XD_MsgDialog', _this select 0];d_message_dialog_open = true;d_do_ma_update_n = true";
	onUnLoad="uiNamespace setVariable ['XD_MsgDialog', nil];d_message_dialog_open = false;d_do_ma_update_n = false";
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
		class SettingsCaption : XC_RscText {
			x = 0.12;
			y = 0.01;
			w = 0.25;
			h = 0.1;
			sizeEx = 0.035;
			colorBackground[] = {1, 1, 1, 0};
			XCTextBI;
			text = "$STR_DOM_MISSIONSTRING_1256";
		};
		class MessageLine : XC_RscText {
			idc = -1;
			x = 0.12;
			y = 0.26;
			w = 0.776;
			h = 0.002;
			sizeEx = 0.001;
			colorBackground[] = {0, 0, 0, 0.8};
			XCTextBlack;
			text = "";
		};
		class MessageCaption : XC_RscText {
			idc = 1505;
			x = 0.12;
			y = 0.11;
			w = 0.25;
			h = 0.1;
			sizeEx = 0.035;
			colorBackground[] = {1, 1, 1, 0};
			XCTextBlack;
			text = "$STR_DOM_MISSIONSTRING_1257";
		};
		class MessageHint : XC_RscText {
			idc = 1506;
			x = 0.12;
			y = 0.135;
			w = 0.25;
			h = 0.1;
			sizeEx = 0.017;
			colorBackground[] = {1, 1, 1, 0};
			colorText[] = {0.5, 0.5, 0.5, 0.8};
			text = "$STR_DOM_MISSIONSTRING_1258";
		};
		class MessageCombo:XD_UIComboBox {
			idc = 1005;
			x = 0.128;
			y = 0.2;
			w = 0.23;
			h = 0.03;
			onLBSelChanged = "[_this] call d_fnc_pmmsgselchanged";
		};
		class MessageEditCap : XC_RscText {
			idc = -1;
			x = 0.12;
			y = 0.25;
			w = 0.25;
			h = 0.1;
			sizeEx = 0.035;
			colorBackground[] = {1, 1, 1, 0};
			XCTextBI;
			text = "$STR_DOM_MISSIONSTRING_1259";
		};
		class MessageEditbox {
			idc = 1201;
			type = 2;
			style = ST_LEFT + ST_MULTI;
			x = 0.13;
			y = 0.34;
			w = 0.758;
			h = 0.44;
			sizeEx = 0.035;
			font = "Zeppelin32";
			text = "";
			colorBackground[] = {0.95,0.95,0.95,1};
			colorText[] = {1, 1, 1, 0.8};
			autocomplete = false;
			colorSelection[] = {0.543, 0.5742, 0.4102, 1};
		};
		class MessageNameSel : XC_RscText {
			idc = 1010;
			x = 0.365;
			y = 0.77;
			w = 0.4;
			h = 0.1;
			sizeEx = 0.03;
			colorBackground[] = {1, 1, 1, 0};
			XCTextBI;
			text = "";
		};
		class MessageSendBut: XD_ButtonBase {
			idc = -1;
			text = "$STR_DOM_MISSIONSTRING_1260"; 
			action = "call d_fnc_XSendMsgSysMsg";
			x = 0.125;
			y = 0.77;
		};
		class MessageClearBut: XD_ButtonBase {
			idc = -1;
			text = "$STR_DOM_MISSIONSTRING_1261"; 
			action = "_ctrl = (uiNamespace getVariable 'XD_MsgDialog') displayCtrl 1201;_ctrl ctrlsettext ''";
			x = 0.665;
			y = 0.77;
		};
		class MessageRecCaption : XC_RscText {
			idc = -1;
			x = 0.65;
			y = 0.11;
			w = 0.25;
			h = 0.1;
			sizeEx = 0.035;
			colorBackground[] = {1, 1, 1, 0};
			XCTextBlack;
			text = "$STR_DOM_MISSIONSTRING_1262";
		};
		class MessageRecHint : XC_RscText {
			idc = -1;
			x = 0.65;
			y = 0.135;
			w = 0.25;
			h = 0.1;
			sizeEx = 0.017;
			colorBackground[] = {1, 1, 1, 0};
			colorText[] = {0.5, 0.5, 0.5, 0.8};
			text = "$STR_DOM_MISSIONSTRING_1263";
		};
		class MessageRecCombo:XD_UIComboBox {
			idc = 1030;
			x = 0.658;
			y = 0.2;
			w = 0.23;
			h = 0.03;
			onLBSelChanged = "[_this] call d_fnc_pmrecchanged";
		};
		class MessageSendCaption : XC_RscText {
			idc = -1;
			x = 0.385;
			y = 0.11;
			w = 0.25;
			h = 0.1;
			sizeEx = 0.035;
			colorBackground[] = {1, 1, 1, 0};
			XCTextBlack;
			text = "$STR_DOM_MISSIONSTRING_1264";
		};
		class MessageSendHint : XC_RscText {
			idc = -1;
			x = 0.385;
			y = 0.135;
			w = 0.25;
			h = 0.1;
			sizeEx = 0.017;
			colorBackground[] = {1, 1, 1, 0};
			colorText[] = {0.5, 0.5, 0.5, 0.8};
			text = "$STR_DOM_MISSIONSTRING_1265";
		};
		class MessageSendCombo:XD_UIComboBox {
			idc = 1031;
			x = 0.393;
			y = 0.2;
			w = 0.23;
			h = 0.03;
			onLBSelChanged = "[_this] call d_fnc_pmrsendchanged";
		};
		class CloseButton: XD_ButtonBase {
			idc = -1;
			text = "$STR_DOM_MISSIONSTRING_1218"; 
			action = "closeDialog 0";
			default = true;
			x = 0.68;
			y = 0.91;
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