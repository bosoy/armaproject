/*	ac130_action_map.sqf for AC130-Script
*	@author: LurchiDerLurch
*	@param: nothing
*	@return: nothing
*	@description: 
*/

//local variables
private["_pos", "_mapclicks", "_var"];

_mapclicks = player getVariable "LDL_Mapclicks";

if (isNil "_mapclicks") then
{
	player setVariable ["LDL_Mapclicks", 0, true];
	_mapclicks = 0;
};

if(!LDL_ac130_active && _mapclicks < LDL_options select 22) then
{
	titleText ["Open your map and single click.", "PLAIN"];

	onMapSingleClick 
	{
		titleText ["", "PLAIN"];
		[_pos]spawn
		{
			private["_pos"];
			_pos = _this select 0;
			
			player setVariable ["LDL_Mapclicks", ((player getVariable "LDL_Mapclicks") + 1), true];
			
			hint format ["%1 AC-130 left.", (LDL_options select 22) - (player getVariable "LDL_Mapclicks")];
			
			sleep 1;
			
			//[POSITION/OBJECT, RADIUS, HEIGHT, SEQUENCE, DELAY]
			[_pos,LDL_options select 0,LDL_options select 1,LDL_options select 21, LDL_options select 20]call LDL_ac130_rot_setup;
		};
		onMapSingleClick {};
	};
}
else
{
	hint "AC-130 is unavailable!";	
};