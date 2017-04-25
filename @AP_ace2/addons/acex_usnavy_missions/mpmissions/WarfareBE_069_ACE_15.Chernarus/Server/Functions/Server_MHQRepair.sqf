Private ["_commanderTeam","_direction","_hq","_HQName","_MHQ","_position","_side","_sideText","_text"];
_side = _this select 0;
_sideText = str _side;

_hq = (_sideText) Call GetSideHQ;
_position = getPos _hq;
_direction = getDir _hq;

_commanderTeam = (_side) Call GetCommanderTeam;
if !(isNull _commanderTeam) then {
	WFBE_SetHQStatus = [vehicleVarName (leader _commanderTeam),'CLTFNCSETHQSTATUS',false];
	publicVariable 'WFBE_SetHQStatus';
	if (isHostedServer) then {[vehicleVarName (leader _commanderTeam),'CLTFNCSETHQSTATUS',false] Spawn HandlePVF};
};

sleep 15;

_HQName = Format["WFBE_%1MHQNAME",_sideText] Call GetNamespace;
_MHQ = _HQName createVehicle _position;

Call Compile Format ["%1MHQ = _MHQ; publicVariable '%1MHQ';",_sideText];

_MHQ setDir _direction;
_MHQ setVelocity [0,0,-1];

Call Compile Format ["_MHQ AddEventHandler ['killed',{[_this select 0,_this select 1,%1,'%2'] Spawn HQKilled}];",_side,typeOf _MHQ];

_text = "";
if (('WFBE_INCOMINGMISSILEMAXRANGE' Call GetNamespace) != 0) then {_text = "this addEventHandler ['IncomingMissile', {_this Spawn HandleIncomingMissile}];"};
_MHQ setVehicleInit Format["['Headquarters','ColorGreen',[1,1],'','HQUndeployed',this,0.2,false,'','',false,%1] ExecVM 'Common\Common_MarkerUpdate.sqf';%2",_side,_text];
processInitCommands;
	
deleteVehicle _hq;

Call Compile Format ["%1MHQDeployed = false; publicVariable '%1MHQDeployed';",_sideText];
WF_Logic setVariable [Format ["%1MHQRepair",_sideText],false,true];

diag_log Format["[WFBE (INFORMATION)][frameno:%2 | ticktime:%3] Server_MHQRepair: The %1 MHQ was repaired.",_sideText,diag_frameno,diag_tickTime];