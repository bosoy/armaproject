#include "script_component.hpp"
private "_code";

_args = _this select 3; // [[_mine,_id], FUNC(xx)]
_code = _args select 1;
_data = _args select 0;

_data call (call compile format ["%1",_code]);
