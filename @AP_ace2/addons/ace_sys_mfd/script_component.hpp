#define COMPONENT sys_mfd

#include "\x\ace\addons\main\script_mod.hpp"

#define DEBUG_ENABLED_SYS_MFD

#ifdef DEBUG_ENABLED_SYS_MFD
	#define DEBUG_MODE_MFD
#endif

#ifdef DEBUG_ENABLED_SYS_MFD
	#define DEBUG_SETTINGS DEBUG_SETTINGS_SYS_MFD
#endif

#define DISPLAY_ID 3342126

#define GET_DIALOG (uiNamespace getVariable QGVAR(currentDialog))

#define CHANGE_STATE(x)  GVAR(lastKeyPressed) = ""; _state = x;

#include "\x\ace\addons\main\script_macros.hpp"
#include "\x\ace\addons\main\script_dialog_defines.hpp"
