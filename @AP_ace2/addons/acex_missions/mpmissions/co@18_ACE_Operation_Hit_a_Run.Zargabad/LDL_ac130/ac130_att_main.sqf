/*	ac130_att_main.sqf by LurchiDerLurch for AC130-Script
*	@author: LurchiDerLurch
*	@param: nothing
*	@return: nothing
*	@description: 
*/

//local variables
private["_display", "_logic_center", "_logic_plane", "_secTotal"];

disableSerialization;

waitUntil {sleep 0.1; (LDL_ac130_active)};

_display = (finddisplay 1000);

_logic_center = (createGroup (createCenter sideLogic)) createUnit ["LOGIC", [0, 0, 0], [], 0, ""];
_logic_plane = (createGroup (createCenter sideLogic)) createUnit ["LOGIC", [0, 0, 0], [], 0, ""];

while {dialog && alive LDL_ac130_plane && alive player && !LDL_ac130_abort} do
{
	sleep 0.005;
	
	//Countdown
	if(LDL_endTime > 0) then
	{
		_secTotal = LDL_endTime-(time-LDL_startTime);
		
		if(_secTotal <= 0) then
		{
			LDL_ac130_abort = true;
		};
	};

	//Shooting
	if (LDL_mouseButtons select 0 && !(LDL_mouseButtons select 4)) then 
	{
		if((LDL_guns_enabled && LDL_viewMode == 1) || LDL_viewMode == 0) then
		{
			if(LDL_viewMode == 0) then
			{
				[getPos LDL_gunPosition,LDL_cam_dirh,LDL_cam_dirv]spawn LDL_ac130_guns;
			}
			else
			{
				[getPos LDL_gunPosition,LDL_guns_dirh,LDL_guns_dirv]spawn LDL_ac130_guns;
			};
		};
	};
		
	//HUD
	#include "AC130\ac130_HUD.sqf"
};

//abort all scripts
camDestroy LDL_ac130_cam;
setAperture -1; //TODO: reset to current GDT value
LDL_ac130_cam cameraeffect ["terminate", "back"];
LDL_ac130_plane enableSimulation true;

ppEffectDestroy LDL_ppccor;
ppEffectDestroy LDL_ppcinv;
ppEffectDestroy LDL_ppfilm;
ppEffectDestroy LDL_ppdyblur;
setAperture -1; //TODO: reset to current GDT value

deleteWaypoint LDL_waypoint;

while{dialog} do
{
	closeDialog 0;	
};

//Remove DEH again on exit
(findDisplay 46) displayRemoveEventHandler ["keyDown",LDL_KeyDownDEH];
(findDisplay 46) displayRemoveEventHandler ["keyUp",LDL_KeyUpDEH];

//Update ammo count of the AC130 for all clients
LDL_ac130_plane setVariable ["LDL_Ammo25", (LDL_weaponSlots select 0)select 2, true];
LDL_ac130_plane setVariable ["LDL_Ammo40", (LDL_weaponSlots select 1)select 2, true];
LDL_ac130_plane setVariable ["LDL_Ammo105",(LDL_weaponSlots select 2)select 2, true];

LDL_ac130_abort = true;

waitUntil{(LDL_scriptTerminated >= 3)};

LDL_ac130_active = false;