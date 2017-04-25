/*	uav_action_map.sqf by LurchiDerLurch for AC130-Script
*	@author: LurchiDerLurch
*	@param: nothing
*	@return: nothing
*	@description: 
*/

//local variables
private["_pos"];

if(!LDL_ac130_active) then
{
	titleText ["Open your map and single click.", "PLAIN"];

	onMapSingleClick 
	{
		titleText ["", "PLAIN"];
		[_pos]spawn
		{
			private["_pos"];
			_pos = _this select 0;
			//[POSITION/OBJECT, RADIUS, HEIGHT, SEQUENCE, DELAY]
			[_pos,LDL_options select 0,LDL_options select 1,LDL_options select 21, LDL_options select 20]call LDL_uav_rot_setup;
		};
		onMapSingleClick {};
	};
}
else
{
	hint "UAV is unavailable!";	
};