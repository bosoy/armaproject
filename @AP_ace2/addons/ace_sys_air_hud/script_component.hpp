#define COMPONENT sys_air_hud
#include "\x\ace\addons\main\script_mod.hpp"

#ifdef DEBUG_ENABLED_SYS_AIR_HUD
	#define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_SYS_AIR_HUD
	#define DEBUG_SETTINGS DEBUG_SETTINGS_SYS_AIR_HUD
#endif

#include "\x\ace\addons\main\script_macros.hpp"

#define EJECTOR_SPEED -10
#define HUDCOLOR [0,0.95,0,0.85]
#define CCIP_FLASHTIME 0.18
#define MAGIC_SIZE	0.323545