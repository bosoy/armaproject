#include "script_component.hpp"

private["_deg"];
PARAMS_2(_el,_table);
_deg = 0;
{
	if (_el == _x select 0) exitwith {
		_deg = (_x select 1)*180/(1000*pi);		//deg = 180*mil/1000pi
	};

} foreach _table;

_deg