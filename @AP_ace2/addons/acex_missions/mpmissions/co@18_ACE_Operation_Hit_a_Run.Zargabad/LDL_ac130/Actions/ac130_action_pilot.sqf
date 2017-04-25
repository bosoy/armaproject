/*	ac130_action_pilot.sqf for AC130-Script
*	@author: LurchiDerLurch
*	@param: nothing
*	@return: nothing
*	@description: 
*/

if(LDL_ac130_plane getVariable "LDL_planeInUse" || LDL_ac130_active) then
{
	hint "AC-130 is unavailable!";
}
else
{
	if((getPos LDL_ac130_plane select 2) < 400) then
	{
		hint format ["Altitude must be over 400m. (Currently: %1)",floor(getPos LDL_ac130_plane select 2)];
	}
	else
	{
		//[OBJECT, RADIUS, HEIGHT, SEQUENCE]
		[LDL_ac130_plane,LDL_options select 0,LDL_options select 1,LDL_options select 21]call LDL_ac130_rot_setup;
	};	
};

	