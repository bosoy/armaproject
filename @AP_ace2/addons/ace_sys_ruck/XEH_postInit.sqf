//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private "_stamina";
_stamina = if (isDedicated) then { true } else { if (isNil "ACE_SYS_STAMINA") then { false } else { ACE_SYS_STAMINA } };
if !(isNil "ACE_NoStaminaEffects") then { if (ACE_NoStaminaEffects) then { _stamina = false } };
if !(_stamina) then { GVAR(no_ruck_conversion) = true };
