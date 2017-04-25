#include "script_component.hpp"

_veh = GET_SELECTED_VEHICLE;
_current_magazines = [];
_index_turret = GET_SELECTED_TURRET;
if ((_veh isKindOf "Plane" || {_veh isKindOf "Helicopter"}) && {_index_turret select 0 < 1} && {2 > lbSize GET_CTRL(66364)}) then {
	_current_magazines = magazines _veh;
}else{
	if ((_index_turret select 0 == -1) && {_veh isKindOf "Car"}) then {
		_current_magazines = [];
	}else{
		_current_magazines = _veh magazinesTurret _index_turret;
	};
};
//diag_log "get_current_magazines end";
_current_magazines