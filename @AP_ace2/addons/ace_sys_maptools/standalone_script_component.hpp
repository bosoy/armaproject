#define COMPONENT maptools
#define PREFIX nou
#define BUILD 1
#define VERSION 2.0.BUILD
// MINIMAL required version for the Mod. Components can specify others..
#define REQUIRED_VERSION 1.01

#ifdef DEBUG_ENABLED_MAPTOOLS
	#define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_MAPTOOLS
	#define DEBUG_SETTINGS DEBUG_SETTINGS_MAPTOOLS
#endif

#include "\x\cba\addons\main\script_macros_common.hpp"
