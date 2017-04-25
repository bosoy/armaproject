/* ACE2 Kestrel 4500 Windmeter */
// (c) 2009 by rocko

#include "script_component.hpp"

TRACE_1("",_this);

with uiNameSpace do { ACE_Kestrel4500 = _this select 0 };

TRACE_1("Kestrel 4500 switched on","");
[] spawn FUNC(windmeter);
GVAR(kestrel_on) = true;

false
