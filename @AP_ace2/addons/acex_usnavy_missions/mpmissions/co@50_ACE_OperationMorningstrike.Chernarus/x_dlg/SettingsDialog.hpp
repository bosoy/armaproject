#define UILEFT 0
#define UICOMBO 4
#define DEFAULTFONT "Bitstream"
#define CT_BUTTON 1
#define ST_CENTER 0x02
#define FontM "Zeppelin32"

class UIList
{
	w = 0.275;
	h = 0.04;
	colorSelect[] = {0.023529,0,0.0313725,1};
	colorText[] = {0.023529,0,0.0313725,1};
	colorBackground[] = {0.95,0.95,0.95,1};
	colorSelectBackground[] = {0.543,0.5742,0.4102,1};
	colorScrollbar[] = {0.023529,0,0.0313725,1};
	arrowEmpty = "\ca\ui\data\ui_arrow_combo_ca.paa";
	arrowFull = "\ca\ui\data\ui_arrow_combo_active_ca.paa";
	wholeHeight = 0.45;
	color[] = {0,0,0,0.6};
	colorActive[] = {0,0,0,1};
	colorDisabled[] = {0,0,0,0.3};
	font = "Zeppelin32";
	sizeEx = 0.029;
	soundSelect[] = {"",0.1,1};
	soundExpand[] = {"",0.1,1};
	soundCollapse[] = {"",0.1,1};
	maxHistoryDelay = 1;
	class ScrollBar
	{
		color[] = {1, 1, 1, 0.6};
		colorActive[] = {1, 1, 1, 1};
		colorDisabled[] = {1, 1, 1, 0.3};
		thumb = "\ca\ui\data\ui_scrollbar_thumb_ca.paa";
		arrowFull = "\ca\ui\data\ui_arrow_top_active_ca.paa";
		arrowEmpty = "\ca\ui\data\ui_arrow_top_ca.paa";
		border = "\ca\ui\data\ui_border_scroll_ca.paa";
	};
};

class UIComboBox:UIList
{
	type = UICOMBO;
	style = 0;
	idc = -1;
	sizeEx = 0.025;
	wholeHeight = 0.3;
};

// ####
class XD_StatusDialog
{
  idd = 11001;

	movingEnable = 1;
	controlsBackground[] = {XD_BackGround};

	// ####
	objects[] = {};

	controls[] =
	{
		x_miscXD_CloseButton,
		x_miscXD_FixHeadBugButton,
		x_miscXD_SettingsCaption,
		x_miscXD_ViewDistanceHint,
		x_miscXD_VDistanceCombo,
		x_miscXD_GraslayerCaption,
		x_miscXD_GraslayerHint,
		x_miscXD_GraslayerCombo,
		x_miscXD_ViewDistanceCaption,
		x_miscXD_PlayernamesCaption,
		x_miscXD_PlayernamesHint,
		x_miscXD_PlayernamesCombo,
		x_miscXD_MessageCaption,
		x_miscXD_MessageHint,
		x_miscXD_MessageCombo,
		x_miscXD_MessageNameSel,
		x_miscXD_MessageLine,
		x_miscXD_MessageMainCaption,
		x_miscXD_MessageEditbox,
		x_miscXD_MessageEditCap,
		x_miscXD_MessageSendBut,
		x_miscXD_MessageClearBut,
		x_miscXD_MessageRecCaption,
		x_miscXD_MessageRecHint,
		x_miscXD_MessageRecCombo,
		x_miscXD_MessageSendCaption,
		x_miscXD_MessageSendHint,
		x_miscXD_MessageSendCombo
	};

	class XD_BackGround : RscText
	{
		idc = -1;
		type = 0;
		style = 48;
		x = 0;
		y = 0;
		w = 1.93;
		h = 1.3;
		colorText[] = {1, 1, 1, 1};
		colorBackground[] = {0,0,0,0};
		text = "\ca\ui\data\ui_mainmenu_background_ca.paa";
		font = "Zeppelin32";
		sizeEx = 0.032;
	};

	class x_miscXD_SettingsCaption : XC_RscText
	{
		x = 0.12;
		y = 0.04;
		w = 0.25;
		h = 0.1;
		sizeEx = 0.035;
		colorBackground[] = {1, 1, 1, 0.0};
		colorText[] = {0.543, 0.5742, 0.4102, 1.0};
		text = "SETTINGS MENU";
	};

	class x_miscXD_ViewDistanceCaption : XC_RscText
	{
		idc = 1999;
		x = 0.12;
		y = 0.15;
		w = 0.25;
		h = 0.1;
		sizeEx = 0.035;
		colorBackground[] = {1, 1, 1, 0.0};
		colorText[] = { 1, 1, 1, 1 };
		text = "Select Viewdistance";
	};

	class x_miscXD_ViewDistanceHint : XC_RscText
	{
		idc = 1997;
		x = 0.12;
		y = 0.175;
		w = 0.25;
		h = 0.1;
		sizeEx = 0.017;
		colorBackground[] = {1, 1, 1, 0.0};
		colorText[] = {0.5, 0.5, 0.5, 0.8};
		text = "Click on the number to change the VD";
	};

	class x_miscXD_VDistanceCombo:UIComboBox
	{
		idc = 1000;
		x = 0.128;
		y = 0.24;
		w = 0.23;
		h = 0.03;
		onLBSelChanged = "_handle = [_this] execVM ""x_scripts\x_vdselchanged.sqf""";
	};

	class x_miscXD_GraslayerCaption : XC_RscText
	{
		idc = 1998;
		x = 0.385;
		y = 0.15;
		w = 0.25;
		h = 0.1;
		sizeEx = 0.035;
		colorBackground[] = {1, 1, 1, 0.0};
		colorText[] = { 1, 1, 1, 1 };
		text = "Select Gras Layer";
	};

	class x_miscXD_GraslayerHint : XC_RscText
	{
		idc = 1996;
		x = 0.385;
		y = 0.175;
		w = 0.25;
		h = 0.1;
		sizeEx = 0.017;
		colorBackground[] = {1, 1, 1, 0.0};
		colorText[] = {0.5, 0.5, 0.5, 0.8};
		text = "Click on the number to change the layer";
	};

	class x_miscXD_GraslayerCombo:UIComboBox
	{
		idc = 1001;
		x = 0.393;
		y = 0.24;
		w = 0.23;
		h = 0.03;
		onLBSelChanged = "_handle = [_this] execVM ""x_scripts\x_glselchanged.sqf""";
	};

	class x_miscXD_PlayernamesCaption : XC_RscText
	{
		idc = 1501;
		x = 0.65;
		y = 0.15;
		w = 0.25;
		h = 0.1;
		sizeEx = 0.035;
		colorBackground[] = {1, 1, 1, 0.0};
		colorText[] = { 1, 1, 1, 1 };
		text = "Show Player Names";
	};

	class x_miscXD_PlayernamesHint : XC_RscText
	{
		idc = 1500;
		x = 0.65;
		y = 0.175;
		w = 0.25;
		h = 0.1;
		sizeEx = 0.017;
		colorBackground[] = {1, 1, 1, 0.0};
		colorText[] = {0.5, 0.5, 0.5, 0.8};
		text = "Click to turn on/off";
	};

	class x_miscXD_PlayernamesCombo:UIComboBox
	{
		idc = 1002;
		x = 0.658;
		y = 0.24;
		w = 0.23;
		h = 0.03;
		onLBSelChanged = "_handle = [_this] execVM ""x_scripts\x_pnselchanged.sqf""";
	};

	//######################################################
	class x_miscXD_MessageLine : XC_RscText
	{
		idc = -1;
		x = 0.12;
		y = 0.3;
		w = 0.776;
		h = 0.002;
		sizeEx = 0.001;
		colorBackground[] = {0, 0, 0, 0.8};
		colorText[] = { 1, 1, 1, 1 };
		text = "";
	};

	class x_miscXD_MessageMainCaption : XC_RscText
	{
		x = 0.12;
		y = 0.3;
		w = 0.25;
		h = 0.1;
		sizeEx = 0.035;
		colorBackground[] = {1, 1, 1, 0.0};
		colorText[] = {0.543, 0.5742, 0.4102, 1.0};
		text = "MESSAGE SYSTEM";
	};

	class x_miscXD_MessageCaption : XC_RscText
	{
		idc = 1505;
		x = 0.12;
		y = 0.35;
		w = 0.25;
		h = 0.1;
		sizeEx = 0.035;
		colorBackground[] = {1, 1, 1, 0.0};
		colorText[] = { 1, 1, 1, 1 };
		text = "Select Player";
	};

	class x_miscXD_MessageHint : XC_RscText
	{
		idc = 1506;
		x = 0.12;
		y = 0.375;
		w = 0.25;
		h = 0.1;
		sizeEx = 0.017;
		colorBackground[] = {1, 1, 1, 0.0};
		colorText[] = {0.5, 0.5, 0.5, 0.8};
		text = "Select player to send message to";
	};

	class x_miscXD_MessageCombo:UIComboBox
	{
		idc = 1005;
		x = 0.128;
		y = 0.44;
		w = 0.23;
		h = 0.03;
		onLBSelChanged = "_handle = [_this] execVM ""x_scripts\x_pmselchanged.sqf""";
	};

	class x_miscXD_MessageEditCap : XC_RscText
	{
		idc = -1;
		x = 0.12;
		y = 0.49;
		w = 0.25;
		h = 0.1;
		sizeEx = 0.035;
		colorBackground[] = {1, 1, 1, 0.0};
		colorText[] = {0.543, 0.5742, 0.4102, 1.0};
		text = "Message Text:";
	};

	class x_miscXD_MessageEditbox {
		idc = 1201;
		type = 2;
		style = ST_LEFT + ST_MULTI;
		x = 0.13;
		y = 0.58;
		w = 0.758;
		h = 0.24;
		sizeEx = 0.035;
		font = "Zeppelin32";
		text = "";
		//colorBackground[] = {1, 1, 1, 1};
		//colorBackground[] = {1, 1, 1, 0.8};
		colorBackground[] = {0.95,0.95,0.95,1};
		colorText[] = { 1, 1, 1, 0.8 };
		autocomplete = false;
		colorSelection[] = {0.543, 0.5742, 0.4102, 1.0};
	};

	class x_miscXD_MessageNameSel : XC_RscText
	{
		idc = 1010;
		x = 0.365;
		y = 0.81;
		w = 0.4;
		h = 0.1;
		sizeEx = 0.03;
		colorBackground[] = {1, 1, 1, 0.0};
		colorText[] = {0.543, 0.5742, 0.4102, 1.0};
		text = "";
	};

	class x_miscXD_MessageSendBut
	{
		idc = -1;
		type = 16;
		style = 0;

		text = "Send Msg To:";
		action = "call XSendMsgSysMsg";

		x = 0.125;
		y = 0.81;
		w = 0.23;
		h = 0.104575;

		size = 0.03921;
		sizeEx = 0.03921;

		color[] = {0.543, 0.5742, 0.4102, 1.0};
		color2[] = {0.95, 0.95, 0.95, 1};
		colorBackground[] = {1, 1, 1, 1};
		colorbackground2[] = {1, 1, 1, 0.4};
		colorDisabled[] = {1, 1, 1, 0.25};
		periodFocus = 1.2;
		periodOver = 0.8;

		class HitZone
		{
			left = 0.004;
			top = 0.029;
			right = 0.004;
			bottom = 0.029;
		};

		class ShortcutPos
		{
			left = 0.0145;
			top = 0.026;
			w = 0.0392157;
			h = 0.0522876;
		};

		class TextPos
		{
			left = 0.05;
			top = 0.034;
			right = 0.005;
			bottom = 0.005;
		};


		textureNoShortcut = "";
		animTextureNormal = "\ca\ui\data\ui_button_normal_ca.paa";
		animTextureDisabled = "\ca\ui\data\ui_button_disabled_ca.paa";
		animTextureOver = "\ca\ui\data\ui_button_over_ca.paa";
		animTextureFocused = "\ca\ui\data\ui_button_focus_ca.paa";
		animTexturePressed = "\ca\ui\data\ui_button_down_ca.paa";
		animTextureDefault = "\ca\ui\data\ui_button_default_ca.paa";
		period = 0.4;
		font = "Zeppelin32";


		soundEnter[] = {"\ca\ui\data\sound\mouse2", 0.09, 1};
		soundPush[] = {"\ca\ui\data\sound\new1", 0.09, 1};
		soundClick[] = {"\ca\ui\data\sound\mouse3", 0.07, 1};
		soundEscape[] = {"\ca\ui\data\sound\mouse1", 0.09, 1};

		class Attributes
		{
			font = "Zeppelin32";
			color = "#E5E5E5";
			align = "left";
			shadow = "true";
		};

		class AttributesImage
		{
			font = "Zeppelin32";
			color = "#E5E5E5";
			align = "left";
			shadow = "true";
		};
	};

	class x_miscXD_MessageClearBut
	{
		idc = -1;
		type = 16;
		style = 0;

		text = "Clear Text Box";
		action = "_x_display = findDisplay 11001;_ctrl = _x_display displayCtrl 1201;_ctrl ctrlsettext ''";

		x = 0.665;
		y = 0.81;
		w = 0.23;
		h = 0.104575;

		size = 0.03921;
		sizeEx = 0.03921;

		color[] = {0.543, 0.5742, 0.4102, 1.0};
		color2[] = {0.95, 0.95, 0.95, 1};
		colorBackground[] = {1, 1, 1, 1};
		colorbackground2[] = {1, 1, 1, 0.4};
		colorDisabled[] = {1, 1, 1, 0.25};
		periodFocus = 1.2;
		periodOver = 0.8;

		class HitZone
		{
			left = 0.004;
			top = 0.029;
			right = 0.004;
			bottom = 0.029;
		};

		class ShortcutPos
		{
			left = 0.0145;
			top = 0.026;
			w = 0.0392157;
			h = 0.0522876;
		};

		class TextPos
		{
			left = 0.04;
			top = 0.034;
			right = 0.005;
			bottom = 0.005;
		};


		textureNoShortcut = "";
		animTextureNormal = "\ca\ui\data\ui_button_normal_ca.paa";
		animTextureDisabled = "\ca\ui\data\ui_button_disabled_ca.paa";
		animTextureOver = "\ca\ui\data\ui_button_over_ca.paa";
		animTextureFocused = "\ca\ui\data\ui_button_focus_ca.paa";
		animTexturePressed = "\ca\ui\data\ui_button_down_ca.paa";
		animTextureDefault = "\ca\ui\data\ui_button_default_ca.paa";
		period = 0.4;
		font = "Zeppelin32";


		soundEnter[] = {"\ca\ui\data\sound\mouse2", 0.09, 1};
		soundPush[] = {"\ca\ui\data\sound\new1", 0.09, 1};
		soundClick[] = {"\ca\ui\data\sound\mouse3", 0.07, 1};
		soundEscape[] = {"\ca\ui\data\sound\mouse1", 0.09, 1};

		class Attributes
		{
			font = "Zeppelin32";
			color = "#E5E5E5";
			align = "left";
			shadow = "true";
		};

		class AttributesImage
		{
			font = "Zeppelin32";
			color = "#E5E5E5";
			align = "left";
			shadow = "true";
		};
	};

	class x_miscXD_MessageRecCaption : XC_RscText
	{
		idc = -1;
		x = 0.65;
		y = 0.35;
		w = 0.25;
		h = 0.1;
		sizeEx = 0.035;
		colorBackground[] = {1, 1, 1, 0.0};
		colorText[] = { 1, 1, 1, 1 };
		text = "Select Received Msg:";
	};

	class x_miscXD_MessageRecHint : XC_RscText
	{
		idc = -1;
		x = 0.65;
		y = 0.375;
		w = 0.25;
		h = 0.1;
		sizeEx = 0.017;
		colorBackground[] = {1, 1, 1, 0.0};
		colorText[] = {0.5, 0.5, 0.5, 0.8};
		text = "Select received messages";
	};

	class x_miscXD_MessageRecCombo:UIComboBox
	{
		idc = 1030;
		x = 0.658;
		y = 0.44;
		w = 0.23;
		h = 0.03;
		onLBSelChanged = "_handle = [_this] execVM ""x_scripts\x_pmrecchanged.sqf""";
	};

	class x_miscXD_MessageSendCaption : XC_RscText
	{
		idc = -1;
		x = 0.385;
		y = 0.35;
		w = 0.25;
		h = 0.1;
		sizeEx = 0.035;
		colorBackground[] = {1, 1, 1, 0.0};
		colorText[] = { 1, 1, 1, 1 };
		text = "Select Send Msg:";
	};

	class x_miscXD_MessageSendHint : XC_RscText
	{
		idc = -1;
		x = 0.385;
		y = 0.375;
		w = 0.25;
		h = 0.1;
		sizeEx = 0.017;
		colorBackground[] = {1, 1, 1, 0.0};
		colorText[] = {0.5, 0.5, 0.5, 0.8};
		text = "Select send messages";
	};

	class x_miscXD_MessageSendCombo:UIComboBox
	{
		idc = 1031;
		x = 0.393;
		y = 0.44;
		w = 0.23;
		h = 0.03;
		onLBSelChanged = "_handle = [_this] execVM ""x_scripts\x_pmrsendchanged.sqf""";
	};

	// #########################################
	class x_miscXD_CloseButton
	{
		idc = -1;
		type = 16;
		style = 0;

		text = "Close";
		action = "closeDialog 0;";

		x = 0.68;
		y = 0.945;
		w = 0.23;
		h = 0.104575;

		size = 0.03921;
		sizeEx = 0.03921;

		color[] = {0.543, 0.5742, 0.4102, 1.0};
		color2[] = {0.95, 0.95, 0.95, 1};
		colorBackground[] = {1, 1, 1, 1};
		colorbackground2[] = {1, 1, 1, 0.4};
		colorDisabled[] = {1, 1, 1, 0.25};
		periodFocus = 1.2;
		periodOver = 0.8;

		class HitZone
		{
			left = 0.004;
			top = 0.029;
			right = 0.004;
			bottom = 0.029;
		};

		class ShortcutPos
		{
			left = 0.0145;
			top = 0.026;
			w = 0.0392157;
			h = 0.0522876;
		};

		class TextPos
		{
			left = 0.05;
			top = 0.034;
			right = 0.005;
			bottom = 0.005;
		};


		textureNoShortcut = "";
		animTextureNormal = "\ca\ui\data\ui_button_normal_ca.paa";
		animTextureDisabled = "\ca\ui\data\ui_button_disabled_ca.paa";
		animTextureOver = "\ca\ui\data\ui_button_over_ca.paa";
		animTextureFocused = "\ca\ui\data\ui_button_focus_ca.paa";
		animTexturePressed = "\ca\ui\data\ui_button_down_ca.paa";
		animTextureDefault = "\ca\ui\data\ui_button_default_ca.paa";
		period = 0.4;
		font = "Zeppelin32";


		soundEnter[] = {"\ca\ui\data\sound\mouse2", 0.09, 1};
		soundPush[] = {"\ca\ui\data\sound\new1", 0.09, 1};
		soundClick[] = {"\ca\ui\data\sound\mouse3", 0.07, 1};
		soundEscape[] = {"\ca\ui\data\sound\mouse1", 0.09, 1};

		class Attributes
		{
			font = "Zeppelin32";
			color = "#E5E5E5";
			align = "left";
			shadow = "true";
		};

		class AttributesImage
		{
			font = "Zeppelin32";
			color = "#E5E5E5";
			align = "left";
			shadow = "true";
		};
	};

	// ####
	class x_miscXD_FixHeadBugButton
	{
		idc = -1;
		type = 16;
		style = 0;

		text = "Fix Headbug";
		action = "closeDialog 0;_bt = 0 execVM ""x_scripts\x_headbug.sqf""";

		x = 0.12;
		y = 0.945;
		w = 0.23;
		h = 0.104575;

		size = 0.03921;
		sizeEx = 0.03921;

		color[] = {0.543, 0.5742, 0.4102, 1.0};
		color2[] = {0.95, 0.95, 0.95, 1};
		colorBackground[] = {1, 1, 1, 1};
		colorbackground2[] = {1, 1, 1, 0.4};
		colorDisabled[] = {1, 1, 1, 0.25};
		periodFocus = 1.2;
		periodOver = 0.8;

		class HitZone
		{
			left = 0.004;
			top = 0.029;
			right = 0.004;
			bottom = 0.029;
		};

		class ShortcutPos
		{
			left = 0.0145;
			top = 0.026;
			w = 0.0392157;
			h = 0.0522876;
		};

		class TextPos
		{
			left = 0.05;
			top = 0.034;
			right = 0.005;
			bottom = 0.005;
		};


		textureNoShortcut = "";
		animTextureNormal = "\ca\ui\data\ui_button_normal_ca.paa";
		animTextureDisabled = "\ca\ui\data\ui_button_disabled_ca.paa";
		animTextureOver = "\ca\ui\data\ui_button_over_ca.paa";
		animTextureFocused = "\ca\ui\data\ui_button_focus_ca.paa";
		animTexturePressed = "\ca\ui\data\ui_button_down_ca.paa";
		animTextureDefault = "\ca\ui\data\ui_button_default_ca.paa";
		period = 0.4;
		font = "Zeppelin32";


		soundEnter[] = {"\ca\ui\data\sound\mouse2", 0.09, 1};
		soundPush[] = {"\ca\ui\data\sound\new1", 0.09, 1};
		soundClick[] = {"\ca\ui\data\sound\mouse3", 0.07, 1};
		soundEscape[] = {"\ca\ui\data\sound\mouse1", 0.09, 1};

		class Attributes
		{
			font = "Zeppelin32";
			color = "#E5E5E5";
			align = "left";
			shadow = "true";
		};

		class AttributesImage
		{
			font = "Zeppelin32";
			color = "#E5E5E5";
			align = "left";
			shadow = "true";
		};
	};
};
