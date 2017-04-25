#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

PREP(fired);
if (isNil "ACE_WTAB") then {
	ACE_WTAB = CBA_WTAB;
	ACE_KTAB = CBA_KTAB;
	ACE_YTAB = CBA_YTAB;
	ACE_PARAM_R = CBA_PARAM_R;
};

ADDON = true;