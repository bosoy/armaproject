Private["_position","_radius","_direction","_maxRadius","_minRadius"];

_position = _this select 0;
_minRadius = _this select 1;
_maxRadius = _this select 2;
_direction = random 360;

_radius = (random (_maxRadius - _minRadius)) + _minRadius;
_position = [(_position select 0)+((sin _direction)*_radius),(_position select 1)+((cos _direction)*_radius),(_position select 2)];
while {surfaceIsWater _position}do {_direction = random 360;_radius = (random (_maxRadius - _minRadius)) + _minRadius;_position = [(_position select 0)+((sin _direction)*_radius),(_position select 1)+((cos _direction)*_radius),(_position select 2)]};

_position