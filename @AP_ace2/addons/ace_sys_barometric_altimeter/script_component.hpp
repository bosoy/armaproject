#define COMPONENT sys_barometric_altimeter
#include "\x\ace\addons\main\script_mod.hpp"
/*
#ifndef DEBUG_ENABLED_SYS_BAROMETRIC_ALTIMETER
#define DEBUG_ENABLED_SYS_BAROMETRIC_ALTIMETER
#endif
*/
#ifdef DEBUG_ENABLED_SYS_BAROMETRIC_ALTIMETER
	#define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_BAROMETRIC_ALTIMETER
	#define DEBUG_SETTINGS DEBUG_SETTINGS_SYS_BAROMETRIC_ALTIMETER
#endif

#include "\x\ace\addons\main\script_macros.hpp"
