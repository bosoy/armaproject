#define COMPONENT sys_ruck
#include "\x\ace\addons\main\script_mod.hpp"

#ifdef DEBUG_ENABLED_SYS_RUCK
	#define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_SYS_RUCK
	#define DEBUG_SETTINGS DEBUG_SETTINGS_SYS_RUCK
#endif

#include "\x\ace\addons\main\script_macros.hpp"

#define __CONF_MAGAZINES configFile >> "CfgMagazines"
#define __CONF_WEAPONS configFile >> "CfgWeapons"
#define __CONF_VEHICLES configFile >> "CfgVehicles"

#define __Type_NoSlot		0	// dummy weapon
#define __Type_SlotPrimary	1	// primary weapon
#define __Type_SlotHandGun	2	// sidearm
#define __Type_SlotSecondary	4	// secondary weapon
#define __Type_SlotHandGunItem	16	// sidearm/GL magazines
#define __Type_SlotPrimaryItem	256	// main magazines, missiles, explosives
#define __Type_SlotBinocular	4096	// binocular, NVG, LD, etc.
#define __Type_HardMounted	65536	// ?
#define __Type_SlotSmallItems	131072	// map, compass, small items

#define __Num_NoSlot		0
#define __Num_SlotPrimary	1
#define __Num_SlotHandGun	1
#define __Num_SlotSecondary	1
#define __Num_SlotHandGunItem	8
#define __Num_SlotPrimaryItem	12
#define __Num_SlotBinocular	2
#define __Num_HardMounted	0
#define __Num_SlotSmallItems	12

#define __IFAK_TYPES_DEFAULT ["ACE_Bandage","ACE_Bandage","ACE_LargeBandage"]
#define __IFAK_NAMES_DEFAULT [(localize "STR_ACE_ITEM_BANDAGE"),(localize "STR_ACE_ITEM_BANDAGE"),(localize "STR_ACE_ITEM_LARGEBANDAGE")]

#define __IFAK_TYPES_CIV ["","",""]
#define __IFAK_NAMES_CIV ["","",""]

#define __IFAK_TYPES_INS ["ACE_Bandage","ACE_Bandage","ACE_Bandage"]
#define __IFAK_NAMES_INS [(localize "STR_ACE_ITEM_BANDAGE"),(localize "STR_ACE_ITEM_BANDAGE"),(localize "STR_ACE_ITEM_BANDAGE")]

#define __IFAK_TYPES_US ["ACE_LargeBandage","ACE_Bandage","ACE_Tourniquet"]
#define __IFAK_NAMES_US [(localize "STR_ACE_ITEM_LARGEBANDAGE"),(localize "STR_ACE_ITEM_BANDAGE"),(localize "STR_ACE_ITEM_TOURNIQUET")]

#define __IFAK_TYPES_RU ["ACE_LargeBandage","ACE_Bandage","ACE_Tourniquet"]
#define __IFAK_NAMES_RU [(localize "STR_ACE_ITEM_LARGEBANDAGE"),(localize "STR_ACE_ITEM_BANDAGE"),(localize "STR_ACE_ITEM_TOURNIQUET")]

#define __IFAK_TYPES_GER ["ACE_LargeBandage","ACE_Morphine","ACE_Tourniquet"]
#define __IFAK_NAMES_GER [(localize "STR_ACE_ITEM_LARGEBANDAGE"),(localize "STR_ACE_ITEM_MORPHINE"),(localize "STR_ACE_ITEM_TOURNIQUET")]

#define __DEF_GETV(VAR,OBJ,OVAR,DEF) \
VAR = OBJ getVariable OVAR; \
if ( isNil #VAR ) then { \
	VAR = DEF; \
	OBJ setVariable [OVAR, VAR]; \
}

//also define in sys_rangefinder
#define __rangefinders ["ACE_Rangefinder_OD","Binocular_Vector","Laserdesignator","ACE_YardAge450"]
