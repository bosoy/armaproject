/*	ac130_logic_C130J.sqf for AC130-Script
*	@author: LurchiDerLurch
*	@param: nothing
*	@return: nothing
*	@description: 
*/

//local variables
private ["_objects", "_object"];

_objects = synchronizedObjects (_this select 0);

for [{_i = 0},{_i < count _objects},{_i = _i + 1}] do 
{
	_object = (_objects select _i);
	_object addAction ["Call AC-130 (AI)", "LDL_ac130\Actions\ac130_action_map_AI.sqf"];
};