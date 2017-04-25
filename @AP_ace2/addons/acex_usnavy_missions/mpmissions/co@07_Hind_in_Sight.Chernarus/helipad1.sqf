_target_pos = getPos helipad1;

helipad = "HeliH" createVehicle _target_pos;
helipad setPos _target_pos;

_ang = 0;
_rad = 10; //radius
bcount = 8; //number of lights
_inc = 360/bcount;

for "_x" from 0 to bcount do
{
	_a = (_target_pos select 0)+(sin(_ang)*_rad);
	_b = (_target_pos select 1)+(cos(_ang)*_rad);

	_pos = [_a,_b,_target_pos select 2];
	_ang = _ang + _inc;
	
	_light = "Land_runway_edgelight" createVehicle _pos;
	_light setPos _pos;
};