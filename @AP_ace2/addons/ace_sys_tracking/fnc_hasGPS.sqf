// gives true if unit has GPS or is in a vehicle with GPS
//#define DEBUG_MODE_FULL
#include "script_component.hpp"
private "_ret";
_ret = _this hasWeapon "ACE_DAGR" || {getNumber (configFile >> "CfgVehicles" >> typeOf (vehicle _this) >> "enableGPS") == 1};
_ret
