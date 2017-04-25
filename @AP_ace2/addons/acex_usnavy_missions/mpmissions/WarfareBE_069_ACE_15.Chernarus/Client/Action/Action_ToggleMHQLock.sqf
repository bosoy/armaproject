Private ["_lock","_MHQ"];

_MHQ = _this select 0;

_lock = if (_MHQ call CBA_fnc_locked) then {false} else {true};

WFBE_RequestVehicleLock = ['SRVFNCREQUESTVEHICLELOCK',[_MHQ,_lock]];
publicVariable 'WFBE_RequestVehicleLock';
if (isHostedServer) then {['SRVFNCREQUESTVEHICLELOCK',[_MHQ,_lock]] Spawn HandleSPVF};
