#define COMPONENT sys_rangefinder
#include "\x\ace\addons\main\script_mod.hpp"

#ifdef DEBUG_ENABLED_sys_rangefinder
	#define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_sys_rangefinder
	#define DEBUG_SETTINGS DEBUG_SETTINGS_sys_rangefinder
#endif

#include "\x\ace\addons\main\script_macros.hpp"
#include "\x\ace\addons\sys_stamina\script_stamina.hpp"

//also define in sys_ruck
#define __rangefinders ["ACE_Rangefinder_OD","Binocular_Vector","Laserdesignator","ACE_YardAge450"]
