/*	float.sqf for AC130-Script
*	@author: LurchiDerLurch
*	@param: nothing
*	@return: nothing
*	@description: 
*/

//local variables
private["_object", "_targetInput", "_modelToWorld", "_velocity", "_distance", "_correctAngle", "_setFinalPos", "_target", "_heightStart", "_heightNow", "_objectPos", "_posWtoM", "_xMissing", "_yMissing", "_zMissing", "_distance3D", "_xWalk", "_yWalk", "_zWalk", "_ang"];

_object = _this select 0;
_targetInput = _this select 1;
_modelToWorld = _this select 2;
_velocity = _this select 3;
_distance = _this select 4;
_correctAngle = _this select 5;
_setFinalPos = _this select 6;
_target = objNull;

if (typeName _targetInput == "ARRAY") then
{
	//target is position
	_target = (createGroup (createCenter sideLogic)) createUnit ["LOGIC", [0, 0, 0], [], 0, ""];
	_target setPos [_targetInput select 0,_targetInput select 1,_targetInput select 2];
};

if (typeName _targetInput == "OBJECT") then
{
	//target is object
	_target = _targetInput;
};

//_object setPosASL [getPos _object select 0,getPos _object select 1,getPosASL _object select 2];
_heightStart = (getPosASL _object select 2);
_heightNow = _heightStart;
_objectPos = getPos _object;

while {(_target distance _object) > _distance} do
{
	sleep 0.001;
	//_posWtoM = _object worldToModel (getPos _target);
	_posWtoM = _object worldToModel (_target modelToWorld _modelToWorld);
	_xMissing = _posWtoM select 0;
	_yMissing = _posWtoM select 1;
	_zMissing = _posWtoM select 2;
	
	_distance3D = (_target distance _object);
	
	_xWalk = _xMissing/(_distance3D*_velocity);
	_yWalk = _yMissing/(_distance3D*_velocity);
	_zWalk = _zMissing/(_distance3D*_velocity);
	
	_heightNow = _heightNow + _zWalk;
	
	_object setPosASL [(_object modelToWorld [_xWalk,_yWalk,0]) select 0,(_object modelToWorld [_xWalk,_yWalk,0]) select 1,_heightNow];
	
	if (_correctAngle) then
	{
		_ang = [_object, _target] call LDL_mando_angles;
		_object setDir ((getDir _object) + (_ang select 1));	
	};
};

if (_setFinalPos) then
{
	_object setPos getPos _target;
};
