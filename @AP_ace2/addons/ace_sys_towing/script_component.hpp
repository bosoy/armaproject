#define COMPONENT sys_towing
#include "\x\ace\addons\main\script_mod.hpp"

#ifdef DEBUG_ENABLED_SYS_TOWING
	#define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_SYS_TOWING
	#define DEBUG_SETTINGS DEBUG_SETTINGS_SYS_TOWING
#endif

#include "\x\ace\addons\main\script_macros.hpp"

// PLACEHOLDERS - Need new models / classes for horizontal rope ;-)
#define ROPE_M ACE_Rope_TOW_M_5
#define ROPE_V ACE_TowingRope_5
#define ROPE_DIST 15
