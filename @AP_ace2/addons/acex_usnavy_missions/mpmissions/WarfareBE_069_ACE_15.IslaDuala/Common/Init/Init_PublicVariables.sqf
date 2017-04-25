Private ['_clientCommandPV','_count','_l','_serverCommandPV'];

_l		= ["RequestVehicleLock"];
_l = _l + ["RequestChangeScore"];
_l = _l + ["RequestCommanderVote"];
_l = _l + ["RequestStructure"];
_l = _l + ["RequestDefense"];
_l = _l + ["RequestJoin"];
_l = _l + ["RequestMHQRepair"];
_l = _l + ["RequestSpecial"];
_l = _l + ["RequestTeamUpdate"];
_l = _l + ["RequestUpgrade"];
if (paramUseWorkers) then {_l = _l + ["RequestWorker"]};

_serverCommandPV = _l;

_l =      ["AllCampsCaptured"];
_l = _l + ["AwardBounty"];
_l = _l + ["CampCaptured"];
_l = _l + ["CanJoin"];
_l = _l + ["ChangeScore"];
_l = _l + ["CommanderVote"];
_l = _l + ["DisplayICBM"];
_l = _l + ["EndGame"];
_l = _l + ["ISIS_AddAction"];
_l = _l + ["LocalizeMessage"];
_l = _l + ["Penalty"];
_l = _l + ["PerformAction"];
_l = _l + ["SetHQStatus"];
_l = _l + ["SetTask"];
_l = _l + ["SetVehicleLock"];
_l = _l + ["TownCaptured"];
_l = _l + ["TownCapturedPublic"];
_l = _l + ["UAV_Reveal"];
_l = _l + ["VoteForCommander"];

/* Add missions Clients PVF here */
if (paramSecondaryMissions) then {
	_l = _l + ['M_BASE_Attack'];
	_l = _l + ['M_PLAYERS_Attack_Air'];
	_l = _l + ['M_TOWN_Attack'];
	_l = _l + ['M_UAV_RetrieveModule'];
};

_clientCommandPV = _l;

for [{_count = Count _clientCommandPV - 1},{_count >= 0},{_count = _count - 1}] do {Call Compile Format["CLTFNC%1 = Compile PreprocessFile 'Client\PVFunctions\%1.sqf'",_clientCommandPV Select _count,_count]};
for [{_count = Count _serverCommandPV - 1},{_count >= 0},{_count = _count - 1}] do {Call Compile Format["SRVFNC%1 = Compile PreprocessFile 'Server\PVFunctions\%1.sqf'",_serverCommandPV Select _count,_count]};

//--- Handle the client side publicVariable.
if (local player) then {
	{Format['WFBE_%1',_x] addPublicVariableEventHandler {(_this select 1) Spawn HandlePVF}} forEach _clientCommandPV;
};
//--- Handle the server side publicVariable.
if (isServer) then {
	{Format['WFBE_%1',_x] addPublicVariableEventHandler {(_this select 1) Spawn HandleSPVF}} forEach _serverCommandPV;
};

diag_log Format["[WFBE (INIT)][frameno:%3 | ticktime:%4] Init_PublicVariables: Public Variable Initialization (SRV: %1 CLT: %2) - [Done]",count _serverCommandPV, count _clientCommandPV,diag_frameno,diag_tickTime];