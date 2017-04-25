#include "script_component.hpp"

#define ACE_TEXT_ORANGE(Text) ("<t color='#ffa500'>" + ##Text + "</t>")

if (player == driver _this) then {
	GVAR(action_abort) = _this addAction [ACE_TEXT_ORANGE(localize "STR_ACE_RELEASE_ROPE"), QPATHTO_F(abort), [], -1000, true, true, "", ""];
};