#include "script_component.hpp"
#include "Script_SightAdjustmentConfig.hpp"

private ["_el","_wnd","_rng"];

_el = switch (toLower ACE_SYS_SA_WCFG_ELEVATION_UNITS) do {
	case "mil": {"mil"};
	case "mil_e": {"mil"};
	case "moa": {"MOA"};
	case "deg": {localize "STR_ACE_SA_deg"};
	default {localize "STR_ACE_SA_deg"};
};
_wnd = switch (toLower ACE_SYS_SA_WCFG_WINDAGE_UNITS) do {
	case "mil": {"mil"};
	case "mil_e": {"mil"};
	case "moa": {"MOA"};
	case "deg": {localize "STR_ACE_SA_deg"};
	default {localize "STR_ACE_SA_deg"};
};
_rng = switch (toLower ACE_SYS_SA_WCFG_RANGE_UNITS) do {
	case "meters": {"m"};
	case "yards": {"yds"};
	default {"m"};
};
[_el,_wnd,_rng]