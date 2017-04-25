class XD_GrasLayerDialog
{
	idd = 75335;

	movingEnable = 1;
	onLoad="_test = [] execVM ""x_scripts\x_fillgl.sqf""";
	controlsBackground[] = {XD_BackGround};

	// ####
	objects[] = {};

	controls[] =
	{
		XD_SelectButton,
		XD_CancelButton,
		XD_GLlistbox,
		XD_GLCaption
	};

	class XD_BackGround : RscText
	{
		x = 0.2;
		y = 0.2;
		w = 0.6;
		h = 0.6;
		colorBackground[] = {0.5, 0.5, 0.5, 0.3};
	};

  // ####
  class XD_SelectButton
  {
	idc = -1;
	type = CT_BUTTON;
	style = ST_CENTER;
	default = false;
	font = FontM;
	sizeEx = 0.03;
	colorText[] = { 0, 0, 0, 1 };
	colorFocused[] = { 1, 0, 0, 1 }; // border color for focused state
	colorDisabled[] = { 0, 0, 1, 0.7 }; // text color for disabled state
	colorBackground[] = { 1, 1, 1, 0.5 };
	colorBackgroundDisabled[] = { 1, 1, 1, 0.5 }; // background color for disabled state
	colorBackgroundActive[] = { 1, 1, 1, 0.7 }; // background color for active state
	offsetX = 0.003;
	offsetY = 0.003;
	offsetPressedX = 0.002;
	offsetPressedY = 0.002;
	colorShadow[] = { 0, 0, 0, 0.5 };
	colorBorder[] = { 0, 0, 0, 1 };
	borderSize = 0;
	soundEnter[] = { "", 0, 1 }; // no sound
	soundPush[] = { "\ca\ui\data\sound\new1", 0.1, 1 };
	soundClick[] = { "", 0, 1 }; // no sound
	soundEscape[] = { "", 0, 1 }; // no sound
	x = 0.27;
	y = 0.725;
	w = 0.2;
	h = 0.05;
	text = "Select";
	action = "_kk = 0 execVM ""x_scripts\x_setgraslayer.sqf""";
	};
	class XD_CancelButton
  {
	idc = -1;
	type = CT_BUTTON;
	style = ST_CENTER;
	default = false;
	font = FontM;
	sizeEx = 0.03;
	colorText[] = { 0, 0, 0, 1 };
	colorFocused[] = { 1, 0, 0, 1 }; // border color for focused state
	colorDisabled[] = { 0, 0, 1, 0.7 }; // text color for disabled state
	colorBackground[] = { 1, 1, 1, 0.5 };
	colorBackgroundDisabled[] = { 1, 1, 1, 0.5 }; // background color for disabled state
	colorBackgroundActive[] = { 1, 1, 1, 0.7 }; // background color for active state
	offsetX = 0.003;
	offsetY = 0.003;
	offsetPressedX = 0.002;
	offsetPressedY = 0.002;
	colorShadow[] = { 0, 0, 0, 0.5 };
	colorBorder[] = { 0, 0, 0, 1 };
	borderSize = 0;
	soundEnter[] = { "", 0, 1 }; // no sound
	soundPush[] = { "\ca\ui\data\sound\new1", 0.1, 1 };
	soundClick[] = { "", 0, 1 }; // no sound
	soundEscape[] = { "", 0, 1 }; // no sound
	x = 0.57;
	y = 0.725;
	w = 0.2;
	h = 0.05;
	text = "Cancel";
	action = "closeDialog 0;";
	};
	class XD_GLlistbox : RscListBox
	{
		x = 0.32;
		y = 0.3;
		w = 0.4;
		h = 0.35;
		idc = 101117;
		soundselect[]={};
		sizeEx = 0.02;
		rowHeight = 0.023;
		SoundExpand[]={"\ca\ui\data\sound\new1", 0.15, 1};
		SoundCollapse[]={"\ca\ui\data\sound\new1", 0.15, 1};
		maxHistoryDelay = 1;
		autoScrollSpeed = -1;
		autoScrollDelay = 5;
		autoScrollRewind = 0;
		class ScrollBar
		{
			color[] = {1,1,1,0.6};
			colorActive[] = {1,1,1,1};
			colorDisabled[] = {1,1,1,0.3};
			thumb = "\ca\ui\data\ui_scrollbar_thumb_ca.paa";
			arrowFull = "\ca\ui\data\ui_arrow_top_active_ca.paa";
			arrowEmpty = "\ca\ui\data\ui_arrow_top_ca.paa";
			border = "\ca\ui\data\ui_border_scroll_ca.paa";
		};

	};
	class XD_GLCaption : RscText
	{
		x = 0.27;
		y = 0.22;
		w = 0.2;
		h = 0.1;
		sizeEx = 0.03;
		colorBackground[] = {1, 1, 1, 0.0};
		colorText[] = { 1, 1, 1, 1 };
		text = "Select Gras Layer:";
	};
};
