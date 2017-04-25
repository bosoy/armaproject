/* ace_sys_groundmarker | (c) 2010,2011,2012 by rocko */

#include "script_component.hpp"

PARAMS_2(_panel,_panel_magazine);

if ((_unit call CBA_fnc_getUnitAnim) select 0 == "stand") then {
	_unit playMove "AmovPercMstpSrasWrflDnon_diary";
};
deleteVehicle _panel;
player addMagazine _panel_magazine;
