/* ----------------------------------------------------------------------------
Function: ACE_fnc_particle

Description:
	Creates particlesource and attaches on unit

Parameters:
	_unit - Unit or Vehicle to attach to [Object]
	_color - RGB color [Array]

Returns:
	created particle source [Object]

Examples:
	(begin example)
	(end)

Author:
	(c) Sickboy 2010
---------------------------------------------------------------------------- */
#include "script_component.hpp"
#define __defSize 1.33
#define __defTime 0.5
#define __defPeriod 0.05
#define __defParticle "\ca\data\cl_water.p3d"

private ["_colorB", "_attach", "_s", "_particle"];
PARAMS_2(_u,_color);

_attach = vehicle _u;
_s = _u getVariable "ACE_PS";
if (isNil "_s") then {
	_s = "#particlesource" createVehiclelocal (getpos _u);
	_u setVariable ["ACE_PS", _s];
};

// Leaving this open for possible changes
_particle = __defParticle;
_size = __defSize;

if (alive _u) then {
	_colorB = [_color select 0, _color select 1, _color select 2, 0];
	_s setParticleParams[_particle, "", "billboard", 1, __defTime, [0, 0, 2], [0,0,0], 1, 1, 0.784, 0.1, [_size, _size*0.66], [_color, _color, _color, _color, _colorB], [1], 10.0, 0.0, "", "", _attach];
	_s setDropInterval __defPeriod;
} else {
	_s setDropInterval 0;
};

_s;

/*
// RGBA -  1:255
#define __colorGreen [0, 0.5, 0, 1]
#define __colorBlue [0, 0, 1, 1]
#define __colorOrange [0.5, 0.5, 0, 1]
#define __colorRed [1, 0, 0, 1]
#define __colorYellow [1, 1, 0, 1]
#define __colorWhite [1, 1, 1, 1]
#define __colorGray [0.5, 0.5, 0.5, 1]
#define __colorBlack [0, 0, 0, 1]
#define __colorMaroon [0.5, 0, 0, 1]
#define __colorOlive [0.5, 0.5, 0, 1]
#define __colorNavy [0, 0, 0.5, 1]
#define __colorPurple [0.5, 0, 0.5, 1]
#define __colorFuchsia [1, 0, 1, 1]
#define __colorAqua [0, 1, 1, 1]

#define __colorTeal [0, 0.5, 0.5, 1]
#define __colorLime [0, 1, 0, 1]
#define __colorSilver [0.75, 0.75, 0.75, 1]
*/