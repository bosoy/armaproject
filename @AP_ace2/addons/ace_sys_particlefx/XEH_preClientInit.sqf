#include "script_component.hpp"

// XEH_preInit
scriptName "XEH_Init";

// compile functions for ammofx particle effects meta and theta and kreta scripts

// cannon effects (reduced muzzle smoke)
ACE_Effects_Cannon = COMPILE_FILE2(PATHTOF(cannon.sqf));
ACE_Effects_Cannon_Missile = COMPILE_FILE2(PATHTOF(cannon_missile.sqf));

// shotFromTurret workaround - particle FX
PREP(fired_turret);
