Private["_camp","_camps","_count","_notifyAllSides","_objects","_previousSide","_side","_sideID","_startingSV","_texture","_town"];

_town = _this Select 0;
_side = _this Select 1;
_previousSide = _this Select 2;

_sideID = _side Call GetSideID;
_camps = _town getVariable "camps";
_startingSV = _town getVariable "supplyValue";

for [{_count = Count _camps - 1},{_count >= 0},{_count = _count - 1}] do {
	_camp = _camps Select _count;
	_camp setVariable ["sideID",_sideID,true];
	_camp setVariable ["supplyValue",_startingSV,true];

	_texture = Format["WFBE_%1FLAG",str _side] Call GetNamespace;

	_objects = _camp nearEntities[[WFFLAG],20];
	if (count _objects > 0) then {(_objects Select 0) setFlagTexture _texture};
};

sleep 0.5;

_notifyAllSides = (_previousSide == East || _previousSide == West);

WFBE_AllCampsCaptured = [nil,'CLTFNCALLCAMPSCAPTURED',[_town,_sideID,_notifyAllSides]];
publicVariable 'WFBE_AllCampsCaptured';
if (isHostedServer) then {[nil,'CLTFNCALLCAMPSCAPTURED',[_town,_sideID,_notifyAllSides]] Spawn HandlePVF};

diag_log Format["[WFBE (INFORMATION)][frameno:%3 | ticktime:%4] Server_SetCampsToSide: '%1' Camps have been set to %2",_town,str _side,diag_frameno,diag_tickTime];
