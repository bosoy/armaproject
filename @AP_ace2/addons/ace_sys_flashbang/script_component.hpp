#define COMPONENT sys_flashbang
#include "\x\ace\addons\main\script_mod.hpp"

#ifdef DEBUG_ENABLED_SYS_FLASHBANG
	#define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_SYS_FLASHBANG
	#define DEBUG_SETTINGS DEBUG_SETTINGS_SYS_FLASHBANG
#endif

#include "\x\ace\addons\main\script_macros.hpp"

// Fucking defines for flashbangs
#define __AOE 20

#define __AOE_FLASH 15
#define __FLASH_DURATION 5

#define __AOE_DEAF 10
#define __DEAF_DURATION 15

#define __AOE_STUN 5
#define __STUN_DURARION 20

#define __DELAY getNumber(configFile >> "CfgAmmo" >> _ammo >> "explosionTime")
#define __SND getText(configFile >> "CfgAmmo" >> _ammo >> "ACE" >> "ACE_FLASHBANG" >> "sound")
#define __NOFX getNumber(configFile >> "CfgAmmo" >> _ammo >> "ACE" >> "ACE_FLASHBANG" >> "nofx")
#define __DBFX getNumber(configFile >> "CfgAmmo" >> _ammo >> "ACE" >> "ACE_FLASHBANG" >> "delay")