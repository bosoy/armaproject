#include "script_component.hpp"
#include "Script_SightAdjustmentConfig.hpp"

ADDON = false;

PREP(keypressed);
PREP(newWeap);
PREP(fired);
PREP(setDegrees);
PREP(findUnitText);
PREP(showDialog);
PREP(roundNumber);
PREP(zeroTable);
PREP(windTable);
PREP(mWheel);
PREP(dlgkeypressed);
PREP(ApplyRngChanges);
PREP(prevRng);
PREP(nextRng);
PREP(prevWnd);
PREP(nextWnd);
PREP(ApplyElevChanges);
PREP(prevElev);
PREP(nextElev);
PREP(prevRng_Elev);
PREP(nextRng_Elev);
PREP(prevElev_Elev);
PREP(nextElev_Elev);
PREP(ApplyRange_ElevChanges);

PREP(click);
PREP(setdegrees_local);
PREP(syncbuffer);
PREP(keypressed_ar);

GVAR(shiftdown) = false;
GVAR(clicktime) = 0;
GVAR(listening) = false;
GVAR(presstime) = 0;

ACE_SYS_SA_RFL_WCFG = ACE_SYS_SA_RFL_WCFG_NEW;		//current weapon's sight properties/range table
ACE_SYS_SA_RFL = ACE_SYS_SA_RFL_NEW;			//current unit/weapon/elevation/windage
ACE_SYS_SA_RFL_WPN_LIST = [];					//list of weapons used by player and sight settings for them

ADDON = true;

[QUOTE(ADDON), "Open_Adjustment_Dialog", { _this call FUNC(keyPressed) }] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "Elevation_Up", { [_this, 0] call FUNC(keypressed_ar) }] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "Elevation_Down", { [_this, 1] call FUNC(keypressed_ar) }] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "Windage_Left", { [_this, 2] call FUNC(keypressed_ar) }] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "Windage_Right", { [_this, 3] call FUNC(keypressed_ar) }] call CBA_fnc_addKeyHandlerFromConfig;
