#define COMPONENT sys_missileguidance
#include "\x\ace\addons\main\script_mod.hpp"

//#define DEBUG_ENABLED_SYS_MISSILEGUIDANCE

#ifdef DEBUG_ENABLED_SYS_MISSILEGUIDANCE
	#define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_SYS_MISSILEGUIDANCE
	#define DEBUG_SETTINGS DEBUG_SETTINGS_SYS_MISSILEGUIDANCE
#endif

#include "\x\ace\addons\main\script_macros.hpp"
#include "\x\ace\addons\sys_stamina\script_stamina.hpp"

// Javelin IGUI defines
#define __JavelinIGUI (uinamespace getVariable "ACE_RscWeaponInfoJavelin")

// Custom controls
#define __JavelinIGUISeek (__JavelinIGUI displayCtrl 699000)
#define __JavelinIGUITop (__JavelinIGUI displayCtrl 699001)
#define __JavelinIGUIDir (__JavelinIGUI displayCtrl 699002)
#define __JavelinIGUINFOV (__JavelinIGUI displayCtrl 699003)

// Constrains
#define __JavelinIGUITargetingConstrains (__JavelinIGUI displayCtrl 699100)
#define __JavelinIGUITargetingConstrainTop (__JavelinIGUI displayCtrl 699101)
#define __JavelinIGUITargetingConstrainBottom (__JavelinIGUI displayCtrl 699102)
#define __JavelinIGUITargetingConstrainLeft (__JavelinIGUI displayCtrl 699103)
#define __JavelinIGUITargetingConstrainRight (__JavelinIGUI displayCtrl 699104)

// Targeting gate (not present yet)
#define __JavelinIGUITargetingGate (__JavelinIGUI displayCtrl 699200)
#define __JavelinIGUITargetingGateTL (__JavelinIGUI displayCtrl 699201)
#define __JavelinIGUITargetingGateTR (__JavelinIGUI displayCtrl 699202)
#define __JavelinIGUITargetingGateBL (__JavelinIGUI displayCtrl 699203)
#define __JavelinIGUITargetingGateBR (__JavelinIGUI displayCtrl 699204)

// Targeting lines
#define __JavelinIGUITargetingLines (__JavelinIGUI displayCtrl 699300)
#define __JavelinIGUITargetingLineH (__JavelinIGUI displayCtrl 699301)
#define __JavelinIGUITargetingLineV (__JavelinIGUI displayCtrl 699302)

// Rangefinder
#define __JavelinIGUIRangefinder (__JavelinIGUI displayCtrl 151)

// Colors for controls
#define __ColorOrange [0.9255,0.5216,0.1216,1]
#define __ColorGreen [0.2941,0.8745,0.2157,1]
#define __ColorGray [0.2941,0.2941,0.2941,1]
#define __ColorNull [0,0,0,0]

#define HELLFIRE_MODE_LOBL		0
#define HELLFIRE_MODE_LOALDIR	1
#define HELLFIRE_MODE_LOALLOW	2
#define HELLFIRE_MODE_LOALHI	3

#define HELLFIRE_MODE_ALL_STAGE_LAUNCH	0

#define HELLFIRE_MODE_LOBL_STAGE_CLIMB_PREPARE	1
#define HELLFIRE_MODE_LOBL_STAGE_CLIMB			2
#define HELLFIRE_MODE_LOBL_STAGE_COAST			3
#define HELLFIRE_MODE_LOBL_STAGE_DIVE			4
#define HELLFIRE_MODE_LOBL_STAGE_TERMINAL		5


#define HELLFIRE_MODE_LOAL_STAGE_CLIMB_PREPARE	1
#define HELLFIRE_MODE_LOAL_STAGE_CLIMB	2
#define HELLFIRE_MODE_LOAL_STAGE_CLIMB2	3
#define HELLFIRE_MODE_LOAL_STAGE_COAST	4
#define HELLFIRE_MODE_LOAL_STAGE_GLIDE	5

#define LASER_LOS_STAGE_PULSE		0
#define LASER_LOS_STAGE_FINDING		1
#define LASER_LOS_STAGE_END			2

