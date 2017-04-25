/*	ac130_action_copilot.sqf for AC130-Script
*	@author: LurchiDerLurch
*	@param: nothing
*	@return: nothing
*	@description: 
*/

if(!(LDL_ac130_plane getVariable "LDL_planeInUse") && !LDL_ac130_active) then
{
	//[OBJECT, RADIUS]
	[LDL_ac130_plane,LDL_options select 0]call LDL_ac130_att_setup;
}
else
{
	hint "AC-130 is unavailable!";	
};