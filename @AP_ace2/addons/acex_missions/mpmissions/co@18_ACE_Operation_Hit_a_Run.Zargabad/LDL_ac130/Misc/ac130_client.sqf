/*	ac130_client.sqf for AC130-Script
*	@author: LurchiDerLurch
*	@param: nothing
*	@return: nothing
*	@description: 
*/

//local variables
private["_plane", "_var", "_copilot","_action"];

/*
[]spawn
{
	while {true} do
	{
		sleep 0.5;
		titleText[format ["Scripts: %1\nActive: %2\nAbort: %3\nMap: %4",LDL_scriptTerminated, LDL_ac130_active, LDL_ac130_abort, LDL_MapShown], "PLAIN"];	
	};	
};
*/

while {true} do
{
	sleep 1;
	
	_plane = vehicle player;
	_var = (_plane getVariable "LDL_planeInUse");
	
	//Copilot
	if(player != driver _plane && !isNil "_var") then
	{
		if(!LDL_ac130_active) then
		{
			LDL_ac130_plane = _plane;
			
			_copilot = ((_plane worldToModel (positionCameraToWorld [0,0,0]) distance [0.5, 12.33, -2.06])<5);
			
			if(_copilot) then
			{
				_action = _plane addAction ["<t color=""#FA1845"">"+"AC130 Camera", "LDL_ac130\Actions\ac130_action_copilot.sqf",[2], 99, false, true];
				
				while{(((_plane worldToModel (positionCameraToWorld [0,0,0]) distance [0.5, 12.33, -2.06])<5) && (player != driver _plane) && (player in _plane))} do
				{
					sleep 0.5;
					if(LDL_ac130_active) then
					{
						LDL_ac130_plane setVariable ["LDL_planeInUse", true, true];	
						waitUntil{(!LDL_ac130_active)};
						LDL_ac130_plane setVariable ["LDL_planeInUse", false, true];	
					};
				};
				
				_copilot = false;
				_plane removeAction _action;
			};
		};
	};
	
	//Pilot
	if(player == driver _plane && !isNil "_var") then
	{
		if(!LDL_ac130_active) then
		{
			LDL_ac130_plane = _plane;

			_action = _plane addAction ["<t color=""#FA1845"">"+"AC130 Autopilot", "LDL_ac130\Actions\ac130_action_pilot.sqf",[1], 99, false, true];
			
			while{((player == driver _plane) && (player in _plane))} do
			{
				sleep 0.5;
				if(LDL_ac130_active) then
				{
					LDL_ac130_plane setVariable ["LDL_planeInUse", true, true];	
					waitUntil{(!LDL_ac130_active)};
					LDL_ac130_plane setVariable ["LDL_planeInUse", false, true];	
				};
			};
			
			_plane removeAction _action;
		};
	};
	
	//Lasermarker
};
