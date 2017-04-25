#include "script_component.hpp"

ADDON = false;
LOG(MSG_INIT);

PREP(DAGR_MENU_INIT);
//PREP(DAGR_OUTPUT_INIT);
PREP(DAGR_OUTPUT_DATA);
PREP(DAGR_OUTPUT_VECTOR);
PREP(DAGR_OUTPUT_WP);
PREP(DAGR_OUTPUT_GPS);
PREP(DAGR_START);
PREP(DAGR_VECTOR);
PREP(DAGR_MAP_INIT);


DAGR_RUN = false;
DAGR_STP = false;
DAGR_MENU_RUN = false;
DAGR_MENU_FIRST = true; //work around due to init glitch
Dagr_Map_Info = "default";
DAGR_DIRECTION = true; //true is degrees
DAGR_GRID_VECTOR = "00000000"; //default

DAGR_WP_NUM = 0;  //number of WP entered into DAGR
DAGR_WP0_String = "";  //Presets all WPs to empty
DAGR_WP1_String = "";
DAGR_WP2_String = "";
DAGR_WP3_String = "";
DAGR_WP4_String = "";
DAGR_WP0 = 0;
DAGR_WP1 = 0;
DAGR_WP2 = 0;
DAGR_WP3 = 0;
DAGR_WP4 = 0;
DAGRSLEEP = 0.5;   //Update timer on DAGR, set for 0.5secs
DAGR_EMPTYVECTOR = true;  //Keeps DAGR Vector display from filling up before use

DAGR_DISPLAY_SELECTION = "DATA"; //sets dagr for data display

[QUOTE(ADDON), "Toggle_dagr", {_this call FUNC(DAGR_START)}] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "Toggle_dagr_mode", {_this call FUNC(DAGR_OUTPUT_GPS)}]  call CBA_fnc_addKeyHandlerFromConfig; 
[QUOTE(ADDON), "Dagr_Menu", {_this call FUNC(DAGR_MENU_INIT)}] call CBA_fnc_addKeyHandlerFromConfig;

[] spawn FUNC(DAGR_VECTOR);
[] spawn FUNC(DAGR_MAP_INIT);

ADDON = true;
