#define COMPONENT sys_crewserved
#include "\x\ace\addons\main\script_mod.hpp"

// #define DEBUG_ENABLED_sys_crewserved

#ifdef DEBUG_ENABLED_sys_crewserved
	#define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_sys_crewserved
	#define DEBUG_SETTINGS DEBUG_SETTINGS_sys_crewserved
#endif

#define ACE_CSW_ACTIONS "mount","unmount","pickup","left","right","load","unload","deploy"

#include "\x\ace\addons\main\script_macros.hpp"
#include "\x\ace\addons\sys_stamina\script_stamina.hpp"