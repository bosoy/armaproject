#include "rscA2BasicDefines.hpp"

#define ReadAndWrite		0
#define ReadAndCreate		1
#define ReadOnly			2
#define ReadOnlyVerified	3
#define true	1
#define false	0

class KEGsRscText {
	access = ReadAndWrite;
	type = 0;
	idc = -1;
	style = 0;
	w = 0.1;
	h = 0.05;
	font = "TahomaB";
	sizeEx = 0.04;
	colorBackground[] = {0, 0, 0, 0};
	colorText[] = {1, 1, 1, 1};
	text = "";
	shadow = 2;
};
class KEGsRscListBox : SpectRscListBox {
	access = ReadAndWrite;
	type = 5;
	style = 0;
	w = 0.4;
	h = 0.4;
	font = "TahomaB";
	sizeEx = 0.04;
	rowHeight = 0;
	colorText[] = {1, 1, 1, 1};
	colorScrollbar[] = {1, 1, 1, 1};
	colorSelect[] = {0, 0, 0, 1};
	colorSelect2[] = {1, 0.5, 0, 1};
	colorSelectBackground[] = {0.6, 0.6, 0.6, 1};
	colorSelectBackground2[] = {0.2, 0.2, 0.2, 1};
	colorBackground[] = {0, 0, 0, 1};
	soundSelect[] = {"", 0.1, 1};
	period = 1;
	autoScrollSpeed = -1;
	autoScrollDelay = 5;
	autoScrollRewind = 0;
	class ScrollBar {
		color[] = {1, 1, 1, 0.6};
		colorActive[] = {1, 1, 1, 1};
		colorDisabled[] = {1, 1, 1, 0.3};
		thumb = __UI_Path(ui_scrollbar_thumb_ca.paa);
		arrowFull = __UI_Path(ui_arrow_top_active_ca.paa);
		arrowEmpty = __UI_Path(ui_arrow_top_ca.paa);
		border = __UI_Path(ui_border_scroll_ca.paa);
	};
	shadow = 2;
};
class KEGsRscActiveText {
	access = ReadAndWrite;
	type = 11;
	style = 2;
	h = 0.05;
	w = 0.15;
	font = "TahomaB";
	sizeEx = 0.04;
	color[] = {1, 1, 1, 1};
	colorActive[] = {1, 0.5, 0, 1};
	soundEnter[] = {"", 0.1, 1};
	soundPush[] = {"", 0.1, 1};
	soundClick[] = {"", 0.1, 1};
	soundEscape[] = {"", 0.1, 1};
	text = "";
	default = 0;
	shadow = 2;
};
class KEGsRscMapControl : SpectRscMapControl {
	access = ReadAndWrite;
	type = 101;
	idc = 51;
	style = 48;
	colorBackground[] = {1, 1, 1, 1};
	colorText[] = {0, 0, 0, 1};
	font = "TahomaB";
	sizeEx = 0.04;
	colorSea[] = {0.56, 0.8, 0.98, 0.5};
	colorForest[] = {0.6, 0.8, 0.2, 0.5};
	colorRocks[] = {0.5, 0.5, 0.5, 0.5};
	colorCountlines[] = {0.65, 0.45, 0.27, 0.5};
	colorMainCountlines[] = {0.65, 0.45, 0.27, 1};
	colorCountlinesWater[] = {0, 0.53, 1, 0.5};
	colorMainCountlinesWater[] = {0, 0.53, 1, 1};
	colorForestBorder[] = {0.4, 0.8, 0, 1};
	colorRocksBorder[] = {0.5, 0.5, 0.5, 1};
	colorPowerLines[] = {0, 0, 0, 1};
	colorNames[] = {0, 0, 0, 1};
	colorInactive[] = {1, 1, 1, 0.5};
	colorLevels[] = {0, 0, 0, 1};
	fontLabel = "Zeppelin32";
	sizeExLabel = 0.027;
	fontGrid = "Zeppelin32";
	sizeExGrid = 0.027;
	fontUnits = "Zeppelin32";
	sizeExUnits = 0.027;
	fontNames = "Zeppelin32";
	sizeExNames = 0.027;
	fontInfo = "Zeppelin32";
	sizeExInfo = 0.027;
	fontLevel = "Zeppelin32";
	sizeExLevel = 0.027;
	text = "#(argb,8,8,3)color(1,1,1,1)";
	stickX[] = {0.2, {"Gamma", 1, 1.5}};
	stickY[] = {0.2, {"Gamma", 1, 1.5}};
	ptsPerSquareSea = 6;
	ptsPerSquareTxt = 8;
	ptsPerSquareCLn = 8;
	ptsPerSquareExp = 8;
	ptsPerSquareCost = 8;
	ptsPerSquareFor = "4.0f";
	ptsPerSquareForEdge = "10.0f";
	ptsPerSquareRoad = 2;
	ptsPerSquareObj = 10;
	class Bunker {
		icon = __UI_Path(map_bunker_ca.paa);
		color[] = {0.55, 0.64, 0.43, 1};
		size = 16;
		importance = 1.5 * 14 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	class Bush {
		icon = __UI_Path(map_bush_ca.paa);
		color[] = {0.55, 0.64, 0.43, 1};
		size = 16;
		importance = 0.2 * 14 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	class BusStop {
		icon = __UI_Path(map_busstop_ca.paa);
		color[] = {0, 0, 1, 1};
		size = 10;
		importance = 1 * 10 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	class Cross {
		icon = __UI_Path(map_cross_ca.paa);
		color[] = {0.55, 0.64, 0.43, 1};
		size = 16;
		importance = 0.7 * 16 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	class Fortress {
		icon = __UI_Path(map_bunker_ca.paa);
		color[] = {0.55, 0.64, 0.43, 1};
		size = 16;
		importance = 2 * 16 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	class Fuelstation {
		icon = __UI_Path(map_fuelstation_ca.paa);
		color[] = {0.55, 0.64, 0.43, 1};
		size = 16;
		importance = 2 * 16 * 0.05;
		coefMin = 0.75;
		coefMax = 4;
	};
	class Fountain {
		icon = __UI_Path(map_fountain_ca.paa);
		color[] = {0, 0.35, 0.7, 1};
		size = 12;
		importance = 1 * 12 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	class Hospital {
		icon = __UI_Path(map_hospital_ca.paa);
		color[] = {0.78, 0, 0.05, 1};
		size = 16;
		importance = 2 * 16 * 0.05;
		coefMin = 0.5;
		coefMax = 4;
	};
	class Chapel {
		icon = __UI_Path(map_chapel_ca.paa);
		color[] = {0.55, 0.64, 0.43, 1};
		size = 16;
		importance = 1 * 16 * 0.05;
		coefMin = 0.9;
		coefMax = 4;
	};
	class Church {
		icon = __UI_Path(map_church_ca.paa);
		color[] = {0.55, 0.64, 0.43, 1};
		size = 16;
		importance = 2 * 16 * 0.05;
		coefMin = 0.9;
		coefMax = 4;
	};
	class Lighthouse {
		icon = __UI_Path(map_lighthouse_ca.paa);
		color[] = {0.78, 0, 0.05, 1};
		size = 20;
		importance = 3 * 16 * 0.05;
		coefMin = 0.9;
		coefMax = 4;
	};
	class Quay {
		icon = __UI_Path(map_quay_ca.paa);
		color[] = {0.55, 0.64, 0.43, 1};
		size = 16;
		importance = 2 * 16 * 0.05;
		coefMin = 0.5;
		coefMax = 4;
	};
	class Rock {
		icon = __UI_Path(map_rock_ca.paa);
		color[] = {0.55, 0.64, 0.43, 1};
		size = 12;
		importance = 0.5 * 12 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	class Ruin {
		icon = __UI_Path(map_ruin_ca.paa);
		color[] = {0.78, 0, 0.05, 1};
		size = 16;
		importance = 1.2 * 16 * 0.05;
		coefMin = 1;
		coefMax = 4;
	};
	class SmallTree {
		icon = __UI_Path(map_smalltree_ca.paa);
		color[] = {0.55, 0.64, 0.43, 1};
		size = 16;
		importance = 0.6 * 12 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	class Stack {
		icon = __UI_Path(map_stack_ca.paa);
		color[] = {0.55, 0.64, 0.43, 1};
		size = 20;
		importance = 2 * 16 * 0.05;
		coefMin = 0.9;
		coefMax = 4;
	};
	class Tree {
		icon = __UI_Path(map_tree_ca.paa);
		color[] = {0.55, 0.64, 0.43, 1};
		size = 16;
		importance = 0.9 * 16 * 0.05;
		coefMin = 0.25;
		coefMax = 4;	
	};
	class Tourism {
		icon = __UI_Path(map_tourism_ca.paa);
		color[] = {0.78, 0, 0.05, 1};
		size = 16;
		importance = 1 * 16 * 0.05;
		coefMin = 0.7;
		coefMax = 4;
	};
	class Transmitter {
		icon = __UI_Path(map_transmitter_ca.paa);
		size = 20;
		color[] = {0, 0.35, 0.7, 1};
		importance = 2 * 16 * 0.05;
		coefMin = 0.9;
		coefMax = 4;
	};
	class ViewTower {
		icon = __UI_Path(map_viewtower_ca.paa);
		size = 16;
		color[] = {0, 0.35, 0.7, 1};
		importance = 2.5 * 16 * 0.05;
		coefMin = 0.5;
		coefMax = 4;
	};
	class Watertower {
		icon = __UI_Path(map_watertower_ca.paa);
		color[] = {0, 0.35, 0.7, 1};
		size = 32;
		importance = 1.2 * 16 * 0.05;
		coefMin = 0.9;
		coefMax = 4;
	};
	class Waypoint {
		icon = __UI_Path(map_waypoint_ca.paa);
		size = 16;
		color[] = {0, 0.35, 0.7, 1};
		importance = 2.5 * 16 * 0.05;
		coefMin = 0.5;
		coefMax = 4;
	};
	class WaypointCompleted {
		icon = __UI_Path(map_waypoint_completed_ca.paa);
		size = 16;
		color[] = {0, 0.35, 0.7, 1};
		importance = 2.5 * 16 * 0.05;
		coefMin = 0.5;
		coefMax = 4;
	};	
};

class KEGsRscControlsGroup : SpectRscControlsGroup {
	type = 15;
	idc = -1;
	style = 0;
	x = 0;y = 0;w = 1;h = 1;
	class VScrollbar {
		color[] = {1, 1, 1, 1};
		width = 0.021;
		autoScrollSpeed = -1;
		autoScrollDelay = 5;
		autoScrollRewind = false;	
	};
	class HScrollbar {
		color[] = {1, 1, 1, 1};
		height = 0.028;
		autoScrollSpeed = -1;
		autoScrollDelay = 5;
		autoScrollRewind = false;	
	};
	class Controls {};
};