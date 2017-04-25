#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

uiNameSpace setVariable ['ACE_RscUnitInfoAir',displayNull];

PREP(altimeter);

// Sea level
GVAR(baseAlt) = getNumber (configFile >> "CfgWorlds" >> worldName >> "elevationOffset");
// ASL altimeter precision
GVAR(aprecision) = 5;
// VSI indicator precision
GVAR(vprecision) = 1;

ADDON = true;
