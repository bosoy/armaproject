/* 
	Author: Benny
	Name: uav_spotter.sqf
	Parameters:
	  0 - UAV
	Description:
	  This file handle the UAV 'spotting' ability. If the UAV knows about an hostile unit, it'll reveal it's average location on the map.
*/

Private ['_delay','_range','_sensitivity','_uav'];
_uav = _this select 0;
_delay = 'WFBE_UAVSPOTTINGDELAY' Call GetNamespace;
_range = 'WFBE_UAVSPOTTINGRANGE' Call GetNamespace;
_sensitivity = 'WFBE_UAVSPOTTINGDETECTION' Call GetNamespace;

while {true} do {
	sleep _delay;
	if (!alive _uav || isNull _uav) exitWith {};
	
	{
		if (_uav knowsAbout _x > _sensitivity && side _x != sideJoined && side _x != civilian) then {
			sleep (0.05 + random 0.05);
			WFBE_UAV_Reveal = [sideJoined,'CLTFNCUAV_REVEAL',[_uav,_x]];
			publicVariable 'WFBE_UAV_Reveal';
			if (isHostedServer) then {[sideJoined,'CLTFNCUAV_REVEAL',[_uav,_x]] Spawn HandlePVF};
		};
	} forEach (_uav nearEntities _range);
};
