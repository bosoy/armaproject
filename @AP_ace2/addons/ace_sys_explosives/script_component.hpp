#define COMPONENT sys_explosives
#include "\x\ace\addons\main\script_mod.hpp"

// #define DEBUG_ENABLED_SYS_EXPLOSIVES

#ifdef DEBUG_ENABLED_SYS_EXPLOSIVES
	#define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_SYS_EXPLOSIVES
	#define DEBUG_SETTINGS DEBUG_SETTINGS_SYS_EXPLOSIVES
#endif

#include "\x\ace\addons\main\script_macros.hpp"

#define __DIR "x\ace\addons\sys_explosives"
#define __PATH getText(configFile >> "CfgVehicles" >> typeOf _mine >> "ACE" >> "ACE_EXPLOSIVES" >> "mine_type")
#define PATH __DIR+"\"+__PATH+"\"

#define __WIDTH_TRIPWIRE	2.5
#define __WIDTH_SLAM		4
#define __WIDTH_PARM		4
#define __WIDTH_IED			2
#define __WIDTH				3
#define __LENGTH			3
#define __WIDTHPMN			1.6
#define __LENGTHPMN			1.6
