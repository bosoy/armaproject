#define COMPONENT sys_vehicledamage
#include "\x\ace\addons\main\script_mod.hpp"

// #define DEBUG_ENABLED_SYS_VEHICLEDAMAGE

#define __ADDINFO(value)
#ifdef DEBUG_ENABLED_SYS_VEHICLEDAMAGE
	// ALL 3 Need to be enabled for useful debug tracing
	#define DEBUG_MODE_FULL
	#define DEBUG_MODE_FULL1
	#define DEBUG_MODE_FXONLY
	#define __ADDINFO(value) _desc = _desc + ##value;
#endif

#ifdef DEBUG_SETTINGS_SYS_VEHICLEDAMAGE
	#define DEBUG_SETTINGS DEBUG_SETTINGS_SYS_VEHICLE
#endif

#include "\x\ace\addons\main\script_macros.hpp"
