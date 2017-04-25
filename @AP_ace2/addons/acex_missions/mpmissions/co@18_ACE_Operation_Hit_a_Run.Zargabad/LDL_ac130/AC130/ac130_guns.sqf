/*	ac130_guns.sqf for AC130-Script
*	@author: LurchiDerLurch
*	@param: nothing
*	@return: nothing
*	@description: 
*/

//local variables
private["_pos", "_dirh", "_dirv", "_display", "_weapon"];

disableSerialization;

waitUntil {sleep 0.1;(LDL_ac130_active)};

_pos = _this select 0;
_dirh = _this select 1;
_dirv = _this select 2;
_display = (finddisplay  1000);
_weapon = LDL_equippedWeapon;

if ((!((LDL_weaponSlots select _weapon)select 3)) && (((LDL_weaponSlots select _weapon)select 2) > 0)) then
{
	(LDL_weaponSlots select _weapon) set [3, true]; 
	[_dirh,_dirv,_weapon,_pos]spawn LDL_calculateBullet;
	switch (_weapon) do
	{
		//25mm
		case 0:
		{
			sleep 0.1;
		};	
		
		//40mm
		case 1:
		{
			sleep 0.5;
		};
		
		//105mm
		case 2:
		{
			sleep 1.5;
			
			if(((LDL_weaponSlots select 2)select 2) > 0) then 
			{
				playSound "LDL_reload";
				sleep 2;
			};
		};
	};
	
	(LDL_weaponSlots select _weapon) set [3, false]; 
};