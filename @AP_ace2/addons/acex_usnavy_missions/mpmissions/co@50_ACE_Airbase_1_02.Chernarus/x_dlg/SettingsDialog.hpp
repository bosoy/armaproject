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
		x_miscXD_SetViewdistanceButton,
		x_miscXD_SetGrasLayerButton,
		x_miscXD_SettingsCaption,
		x_miscXD_SetMarkerButton
	};

	class XD_BackGround : RscText
	{
		x = 0.6;
		y = 0.3;
		w = 0.36;
		h = 0.63;
		colorBackground[] = {0.5, 0.5, 0.5, 0.3};
	};

  // ####
  class x_miscXD_CloseButton
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
	x = 0.68;
	y = 0.82;
	w = 0.2;
	h = 0.05;
	text = "Close";
	action = "closeDialog 0;";
	};
	class x_miscXD_FixHeadBugButton
  {
	idc = -1;
	type = CT_BUTTON;
	style = ST_CENTER;
	default = false;
	font = FontM;
	sizeEx = 0.02;
	colorText[] = { 0, 0, 0, 1 };
	colorFocused[] = { 1, 0, 0, 1 }; // border color for focused state
	colorDisabled[] = { 0, 0, 1, 0.7 }; // text color for disabled state
	colorBackground[] = { 1, 1, 1, 0.2 };
	colorBackgroundDisabled[] = { 1, 1, 1, 0.5 }; // background color for disabled state
	colorBackgroundActive[] = { 1, 1, 1, 0.4 }; // background color for active state
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
	x = 0.68;
	y = 0.72;
	w = 0.2;
	h = 0.05;
	text = "Fix Headbug";
	action = "closeDialog 0;_bt = 0 execVM ""x_scripts\x_headbug.sqf""";
	};

	class x_miscXD_SetViewdistanceButton
  {
	idc = 11006;
	type = CT_BUTTON;
	style = ST_CENTER;
	default = false;
	font = FontM;
	sizeEx = 0.02;
	colorText[] = { 0, 0, 0, 1 };
	colorFocused[] = { 1, 0, 0, 1 }; // border color for focused state
	colorDisabled[] = { 0, 0, 1, 0.7 }; // text color for disabled state
	colorBackground[] = { 1, 1, 1, 0.2 };
	colorBackgroundDisabled[] = { 1, 1, 1, 0.5 }; // background color for disabled state
	colorBackgroundActive[] = { 1, 1, 1, 0.4 }; // background color for active state
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
	x = 0.68;
	y = 0.62;
	w = 0.2;
	h = 0.05;
	text = "Set Viewdistance";
	action = "CloseDialog 0;_vd = createDialog ""XD_ViewDistanceDialog""";
	};
	class x_miscXD_SetGrasLayerButton
  {
	idc = 11007;
	type = CT_BUTTON;
	style = ST_CENTER;
	default = false;
	font = FontM;
	sizeEx = 0.02;
	colorText[] = { 0, 0, 0, 1 };
	colorFocused[] = { 1, 0, 0, 1 }; // border color for focused state
	colorDisabled[] = { 0, 0, 1, 0.7 }; // text color for disabled state
	colorBackground[] = { 1, 1, 1, 0.2 };
	colorBackgroundDisabled[] = { 1, 1, 1, 0.5 }; // background color for disabled state
	colorBackgroundActive[] = { 1, 1, 1, 0.4 }; // background color for active state
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
	x = 0.68;
	y = 0.52;
	w = 0.2;
	h = 0.05;
	text = "Set Gras Layer";
	action = "CloseDialog 0;_vd = createDialog ""XD_GrasLayerDialog""";
	};
	class x_miscXD_SetMarkerButton
  {
	idc = 11008;
	type = CT_BUTTON;
	style = ST_CENTER;
	default = false;
	font = FontM;
	sizeEx = 0.02;
	colorText[] = { 0, 0, 0, 1 };
	colorFocused[] = { 1, 0, 0, 1 }; // border color for focused state
	colorDisabled[] = { 0, 0, 1, 0.7 }; // text color for disabled state
	colorBackground[] = { 1, 1, 1, 0.2 };
	colorBackgroundDisabled[] = { 1, 1, 1, 0.5 }; // background color for disabled state
	colorBackgroundActive[] = { 1, 1, 1, 0.4 }; // background color for active state
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
	x = 0.68;
	y = 0.42;
	w = 0.2;
	h = 0.05;
	text = "Show Player Marker";
	action = "CloseDialog 0;xhandle = player execVM ""x_scripts\x_deleteplayermarker.sqf"";";
	};
	class x_miscXD_SettingsCaption : RscText
	{
		x = 0.73;
		y = 0.32;
		w = 0.25;
		h = 0.1;
		sizeEx = 0.03;
		colorText[] = { 1, 1, 1, 1 };
		colorBackground[] = {1, 1, 1, 0.0};
		text = "Settings";
	};
};
