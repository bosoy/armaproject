class LDL_RscText
{
	type = CT_STATIC;
	idc = -1;
	style = ST_LEFT;
	colorBackground[] = {0,0,0,0};
	colorText[] = {1,1,1,1};
	font = FontM;
	sizeEx = 0.02;
	text = "";
	x = 0; 
	y = 0; 
	w = 0.2; 
	h = 0.4; 
};

class LDL_RscPicture
{
	type = CT_STATIC;
	idc = -1;
	style = ST_PICTURE;
	colorBackground[] = {0,0,0,0};
	colorText[] = {1,1,1,1};
	font = FontM;
	sizeEx = 0.02;
	text = "";
	x = 0; 
	y = 0; 
	w = 0.2; 
	h = 0.4; 
};

class LDL_RscEdit
{
	idc = -1; 
	type = CT_EDIT; 
	style = ST_LEFT; 
	x = 0; 
	y = 0; 
	w = 0.2; 
	h = 0.4; 
	sizeEx = 0.02; 
	font = BitStream; 
	text = ""; 
	colorText[] = {1,1,1,1}; 
	autocomplete = false; 
	colorSelection[] = {0,0,0,1}; 
};

class LDL_RscButton
{ 
	idc = -1; 
	type = CT_BUTTON; 
	style = ST_LEFT; 
	default = false; 
	font = FontM; 
	sizeEx = 0.03; 
	colorText[] = { 0, 0, 0, 1 }; 
	colorFocused[] = { 1, 1, 1, 1 }; // border color for focused state 
	colorDisabled[] = { 0, 0, 1, 0 }; // text color for disabled state 
	colorBackground[] = { 1, 1, 1, 1 }; 
	colorBackgroundDisabled[] = { 1, 1, 1, 0 }; // background color for disabled state 
	colorBackgroundActive[] = { 1, 1, 1, 1 }; // background color for active state 
	offsetX = 0; 
	offsetY = 0; 
	offsetPressedX = 0; 
	offsetPressedY = 0.002; 
	colorShadow[] = { 0, 0, 0, 0 }; 
	colorBorder[] = { 0, 0, 0, 0 }; 
	borderSize = 0; 
	soundEnter[] = { "", 0, 1 }; // no sound 
	soundPush[] = { "buttonpushed.ogg", 0.1, 1 }; 
	soundClick[] = { "", 0, 1 }; // no sound 
	soundEscape[] = { "", 0, 1 }; // no sound 
	x = 0.4; 
	y = 0.475; 
	w = 0.2; 
	h = 0.05; 
	text = ""; 
	action = ""; 
};