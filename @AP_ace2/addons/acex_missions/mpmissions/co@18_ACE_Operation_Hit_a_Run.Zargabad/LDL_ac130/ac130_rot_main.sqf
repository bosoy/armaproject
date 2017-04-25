/*	ac130_rot_main.sqf by LurchiDerLurch for AC130-Script
*	@author: LurchiDerLurch
*	@param: nothing
*	@return: nothing
*	@description: 
*/

//local variables
private["_display", "_logic_plane", "_function_hud", "_ang", "_dif", "_pos", "_cam", "_screen", "_secTotal"];

disableSerialization;

waitUntil {sleep 0.1; (LDL_ac130_active)};

_display = (finddisplay 1000);
_logic_plane = (createGroup (createCenter sideLogic)) createUnit ["LOGIC", [0, 0, 0], [], 0, ""];

while {dialog && alive LDL_ac130_plane && alive player && !LDL_ac130_abort} do
{
	sleep 0.005;
	
	//Plane Axis
	[]call LDL_ac130_correctAxis;
	
	//Set new position
	if (LDL_mouseButtons select 1) then 
	{
		LDL_destination setPos screenToWorld [0.5,0.5];
		
		[_logic_plane, LDL_destination, LDL_cam_rotating_radius, LDL_cam_rotating_angle, LDL_cam_rotating_height]call LDL_setCirclePosition;

		_ang = [LDL_ac130_plane, _logic_plane] call LDL_mando_angles;
		_dif = _ang select 1;

		if (!(_dif < 1 && _dif > -1)) then
		{
			LDL_flyMode = 2; //waiting to float
		};
	};
	
	//Prepare to change position
	if(LDL_flyMode == 2) then
	{
		//waiting to float
		[_logic_plane, LDL_destination, LDL_cam_rotating_radius, LDL_cam_rotating_angle, LDL_cam_rotating_height]call LDL_setCirclePosition;
		
		_ang = [LDL_ac130_plane, _logic_plane] call LDL_mando_angles;
		_dif = _ang select 1;
		
		_pos = (worldToScreen getPos LDL_destination);
		if (count _pos != 2) then
     		{                              
      		_pos = [-1,-1];
     		};
		(_display displayCtrl 1006) ctrlSetPosition [(_pos select 0)-SafeZoneW/64,(_pos select 1)-SafeZoneH/64];
		(_display displayCtrl 1006) ctrlSetTextColor [1,1,1,0.5];
		(_display displayCtrl 1006) ctrlCommit 0;
		
		if (_dif < 1 && _dif > -1) exitWith
		{
			LDL_flyMode = 3; //float
			
			LDL_cam_rotating_center setPosASL [getPos LDL_cam_rotating_center select 0,getPos LDL_cam_rotating_center select 1,getPosASL LDL_destination select 2];
			
			[LDL_cam_rotating_center,LDL_destination,1,1,false,false]spawn LDL_ac130_rot_float;
			
			(_display displayCtrl 1006) ctrlSetTextColor [1,1,1,0];
		};
	};
	
	//Countdown
	if(LDL_endTime > 0) then
	{
		_secTotal = LDL_endTime-(time-LDL_startTime);
		
		if(_secTotal <= 0) then
		{
			LDL_ac130_abort = true;
		};
	};
	
	//Center
	_screen = worldToScreen (getPos LDL_cam_rotating_center);

	if (count _screen != 2) then
	{                              
		_screen = [-1,-1];
	};
	     
	(_display displayCtrl 1005) ctrlSetPosition [(_screen select 0)-SafeZoneW/32,(_screen select 1)-SafeZoneH/32];
	(_display displayCtrl 1005) ctrlCommit 0;
	
	//HUD
	#include "AC130\ac130_HUD.sqf"
	
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
};

camDestroy LDL_ac130_cam;
setAperture -1;
LDL_ac130_cam cameraeffect ["terminate", "back"];

ppEffectDestroy LDL_ppccor;
ppEffectDestroy LDL_ppcinv;
ppEffectDestroy LDL_ppfilm;
ppEffectDestroy LDL_ppdyblur;
setAperture -1; 

//Remove DEH again on exit
(findDisplay 46) displayRemoveEventHandler ["keyDown",LDL_KeyDownDEH];
(findDisplay 46) displayRemoveEventHandler ["keyUp",LDL_KeyUpDEH];

while{dialog} do
{
	closeDialog 0;	
};

if(!alive LDL_ac130_plane) then
{
	_cam = "camera" camcreate (LDL_ac130_plane modelToWorld [20,0,50]);
	_cam cameraeffect ["internal", "back"];
	showCinemaBorder false;
	camUseNVG false;

	_cam camSetTarget LDL_ac130_plane;
	_cam camCommit 3;
	
	sleep 3;
	
	titleText ["", "BLACK OUT",0.5];
	
	sleep 0.5;
	
	camDestroy _cam;
	_cam cameraeffect ["terminate", "back"];
	
	titleText ["", "BLACK IN",1];
};

LDL_ac130_plane setVariable ["LDL_Ammo25", (LDL_weaponSlots select 0)select 2, true];
LDL_ac130_plane setVariable ["LDL_Ammo40", (LDL_weaponSlots select 1)select 2, true];
LDL_ac130_plane setVariable ["LDL_Ammo105",(LDL_weaponSlots select 2)select 2, true];

LDL_ac130_abort = true;

waitUntil{(LDL_scriptTerminated >= 4)};

LDL_ac130_active = false;