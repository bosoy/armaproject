#include "script_component.hpp"
#include "Script_SightAdjustmentConfig.hpp"

private ["_el","_wnd","_rng"];

_el = switch (toLower ACE_SYS_SA_RFL_WCFG_ELEVATION_UNITS) do {
	case "mil": {"mil"};
	case "mil_e": {"mil"};
	case "moa": {"moa"};
	case "deg": {"deg"};
	default {"deg"};
};
_wnd = switch (toLower ACE_SYS_SA_RFL_WCFG_WINDAGE_UNITS) do {
	case "mil": {"mil"};
	case "mil_e": {"mil"};
	case "moa": {"moa"};
	case "deg": {"deg"};
	default {"deg"};
};
_rng = switch (toLower ACE_SYS_SA_RFL_WCFG_RANGE_UNITS) do {
	case "meters": {"m"};
	case "yards": {"yds"};
	default {"m"};
};
//player groupchat format["%1, %2, %3", _el,_wnd,_rng];
[_el,_wnd,_rng]
