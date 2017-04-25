#define COMPONENT sys_nvg
#include "\x\ace\addons\main\script_mod.hpp"

// #define DEBUG_ENABLED_SYS_NVG

#ifdef DEBUG_ENABLED_SYS_NVG
	#define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_SYS_NVG
	#define DEBUG_SETTINGS DEBUG_SETTINGS_SYS_NVG
#endif

#include "\x\ace\addons\main\script_macros.hpp"

#define __MAX_APERTURE 25 //  Maximum Sensitivity (Aperture)
#define __MIN_APERTURE 1 // Minimum Sensitivity (Aperture)
#define __INIT_APERTURE 5 // Start NV sensitivity setting (inverse relationship with brightness)
