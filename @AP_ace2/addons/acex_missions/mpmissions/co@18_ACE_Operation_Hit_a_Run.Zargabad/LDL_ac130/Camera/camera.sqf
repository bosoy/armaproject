/*	camera.sqf by LurchiDerLurch for AC130-Script
*	@author: LurchiDerLurch
*	@param: nothing
*	@return: nothing
*	@description: 
*/

//local variables
private["_xM", "_yM", "_angles", "_cam_set_dirh", "_cam_set_dirv", "_difh", "_difv"];

disableSerialization;

_xM = LDL_mousePosition select 0;
_yM = LDL_mousePosition select 1;

if(LDL_fixCam) then
{
	if (typeName LDL_fixPos == "ARRAY") then
	{
		_logic setPos LDL_fixPos;
	}
	else
	{
		_logic setPos (getPos LDL_fixPos);
	};

	_angles = [LDL_ac130_cam, _logic]call LDL_getObjectAngles;
	_cam_set_dirh = [_angles select 0]call LDL_normalizeAngle;
	_cam_set_dirv = [_angles select 1]call LDL_normalizeAngle;
}
else
{
	_cam_set_dirh = LDL_cam_dirh + _xM*1.5;
	_cam_set_dirv = LDL_cam_dirv + _yM*1.5;
};

_difh = [(_cam_set_dirh - LDL_cam_orientation_angle)]call LDL_normalizeAngle;
_difv = [_cam_set_dirv - 180]call LDL_normalizeAngle;

//horizontal
if((!(_difh < LDL_min_difh) && !(_difh > LDL_max_difh)) || LDL_view360 || LDL_viewMode == 1) then
{
	LDL_cam_dirh = _cam_set_dirh;
}
else
{
	if(_difh < LDL_min_difh) then
	{
		LDL_cam_dirh = [LDL_cam_orientation_angle + 90]call LDL_normalizeAngle;
	}
	else
	{
		LDL_cam_dirh = [LDL_cam_orientation_angle - 90]call LDL_normalizeAngle;
	};
};

//vertical
if(!(_difv < LDL_min_difv) && !(_difv > LDL_max_difv)) then
{
	LDL_cam_dirv = _cam_set_dirv;
}
else
{
	if(_difv > LDL_min_difv) then
	{
		LDL_cam_dirv = LDL_set_min_dirv;
	}
	else
	{
		LDL_cam_dirv = LDL_set_max_dirv;
	};
};

LDL_cam_dirv = [LDL_cam_dirv]call LDL_normalizeAngle;
LDL_cam_dirh = [LDL_cam_dirh]call LDL_normalizeAngle;

//Guns
if(LDL_view360 || LDL_viewMode == 0) then
{
	LDL_guns_enabled = true;
	(_display displayctrl 1007) ctrlSetTextColor [1,1,1,1];
}
else
{
	if(_difh < 90 || _difh > 270 || _difv < 100 || _difv > 190) then
	{
		(_display displayctrl 1007) ctrlSetTextColor [1,1,1,0];
		LDL_guns_enabled = false;
	}
	else
	{
		(_display displayctrl 1007) ctrlSetTextColor [1,1,1,1];
		LDL_guns_enabled = true;	
	};
};