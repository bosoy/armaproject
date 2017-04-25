_mine = _this select 0;
_vehicle = _this select 1;

_mine attachTo [_vehicle,[0,0,0],""];
_vehicle setVariable ["ace_sys_explosives_VBIED", true, true]; // Helper variable to indicate vbieds
