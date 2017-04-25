_unit = _this select 0;
_caller = _this select 1;
_id = _this select 2;
_ar = _this select 3;

_vehicle = (_ar select 0) select 0;
_mine = _ar select 1;
_helper = _ar select 2;

_mine attachTo [_vehicle,[0,0,0],""];

_unit removeAction _id;
deleteVehicle _helper;