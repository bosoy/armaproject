/*	ac130_createMap.sqf for AC130-Script
*	@author: LurchiDerLurch
*	@param: nothing
*	@return: nothing
*	@description: 
*/

//local variables
private["_dialog","_display"];

_dialog = createDialog "LDL_DialogMap";

waitUntil{(dialog)};

buttonSetAction [2004, "[]spawn LDL_confirmButton"];

disableSerialization;
_display = (findDisplay 2000);

(_display displayctrl 2002) ctrlSetText str(LDL_cam_rotating_radius);
(_display displayctrl 2003) ctrlSetText str(LDL_cam_rotating_height);

if(LDL_disableMonitor) then
{
	(_display displayctrl 2000) ctrlShow false;
}
else
{
	(_display displayctrl 2000) ctrlShow true;
};

onMapSingleClick 
{
	titleText ["", "PLAIN"];
	[_pos]spawn
	{
		private["_pos"];
		_pos = _this select 0;
		
		LDL_destination setPos _pos;
		
		LDL_flyMode = 2;
	};
};

while {LDL_MapShown} do
{
	_ellipse = createMarkerLocal ["Ellipse", LDL_cam_rotating_center];
	_ellipse setMarkerShapeLocal "ELLIPSE";
	_ellipse setMarkerSizeLocal [LDL_cam_rotating_radius, LDL_cam_rotating_radius];
	_ellipse setMarkerBrushLocal "BORDER";	
	_ellipse setMarkerDirLocal 0;
	
	_ac130 = createMarkerLocal ["PlaneMark", LDL_ac130_plane];
	_ac130 setMarkerShapeLocal "ICON";
	_ac130 setMarkerSizeLocal [1, 1];
	_ac130 setMarkerTypeLocal "b_plane";	
	_ac130 setMarkerDirLocal (getDir LDL_ac130_plane);
	
	if(LDL_flyMode > 1) then
	{
		_point = createMarkerLocal ["Destination", LDL_destination];
		_point setMarkerShapeLocal "ICON";
		_point setMarkerSizeLocal [1, 1];
		_point setMarkerTypeLocal "Dot";
		_point setMarkerColorLocal "ColorBlue";
	};

	sleep 0.1;

	deleteMarkerLocal "Ellipse";
	deleteMarkerLocal "PlaneMark";
	deleteMarkerLocal "Destination";
};


deleteMarkerLocal "Ellipse";
deleteMarkerLocal "PlaneMark";
deleteMarkerLocal "Destination";
	
onMapSingleClick {};