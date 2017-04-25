#include "script_component.hpp"
class CfgPatches {
	class ADDON {
		units[] = {};
		requiredVersion = REQUIRED_VERSION;
		requiredAddons[] = { QUOTE(MAIN_ADDON), "ace_sys_bc" };
		version = VERSION;
	};
};
#include "CfgMissions.hpp"

