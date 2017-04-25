/*	uav_createDialog.sqf by LurchiDerLurch for AC130-Script
*	@author: LurchiDerLurch
*	@param: nothing
*	@return: nothing
*	@description: 
*/

//local variables
private["_dialog","_display"];

_dialog = createDialog "LDL_UAVDialog";

waitUntil{(dialog)};

disableSerialization;
_display = (findDisplay 1000);

if(LDL_disableMonitor) then
{
	(_display displayctrl 1000) ctrlShow false;
}
else
{
	(_display displayctrl 1000) ctrlShow true;
};