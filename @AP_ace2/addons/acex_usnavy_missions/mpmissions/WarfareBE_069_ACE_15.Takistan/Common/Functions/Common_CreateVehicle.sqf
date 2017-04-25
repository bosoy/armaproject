Private ["_lock","_position","_side","_type","_vehicle"];
_type = _this select 0;
_position = _this select 1;
_side = _this select 2;
_lock = _this select 3;

_vehicle = _type createVehicle _position;
if (_side != resistance) then {
	_vehicle SetVehicleInit Format["[this,%1] ExecVM 'Common\Common_InitUnit.sqf';",_side];
	ProcessInitCommands;
	Call Compile Format ["_vehicle addEventHandler ['Killed',{[_this select 0,_this select 1,%1] Spawn UnitKilled}]",_side];
} else {
	//--- Note To be optimized, 1.03 BIS BUG, cannot add resistance side via call compile format.
	_vehicle addEventHandler ["Killed",{[_this select 0,_this select 1,resistance] Spawn UnitKilled}];
};
_vehicle lock _lock;

diag_log Format["[WFBE (INFORMATION)][frameno:%4 | ticktime:%5] Common_CreateVehicle: A %1 '%2' vehicle has been created (position: %3)",str _side,_type,_position,diag_frameno,diag_tickTime];

_vehicle