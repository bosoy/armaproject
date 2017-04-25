// Kh-29L guidance thread by q1184
// based on LGB code by Nou & jaynus
// based on proportional navigation method

#define __maxacceleration 70
#define __N 25
#define __positive 1
#define __negative -1


#include "script_component.hpp"

_tdif = time-_lastTime;
_lastTime = time;
//_angdif = acos ([velocity _bomb,_curvelocity] call ace_sys_missileguidance_fnc_mat_cos3dvec);
_curVelocity = velocity _bomb;
_headingPitch = _curVelocity call CBA_fnc_vect2polar;
_totalVelocity = sqrt((_curVelocity select 0)^2 + (_curVelocity select 1)^2 + (_curVelocity select 2)^2);
_maxdelta = 10*_tdif*_totalvelocity/500; //__maxacceleration*_tdif*180/(_totalvelocity*pi);

_vectorTo = ([(getPosASL _bomb), (getPosASL _currentTarget)] call ACE_fnc_vectorFromXToY);
_polarTo = _vectorTo call CBA_fnc_vect2polar;

// get the dir to the target
_dir = _polarTo select 1;

// ... and then make it relative to our current heading
_dir = _dir - (_headingPitch select 1);

if (_dir < 0) then {_dir = _dir + 360};
if (_dir > 360) then {_dir = _dir - 360};

//proportional navigation: dMIS/dt = N*dLOS/dt

//heading
if(_tdif > 0) then
{
	if !(isNil "_prevdirx") then
	{
		_coefX = _dir - _prevdirx;
		if (_coefX <= -180) then {_coefX = -_coefX - 360};
		if (_coefX >= 180) then {_coefX = 360 - _coefX};
	} else
	{
		_coefX = 0;
	};
} else
{
	_coefX = 0;
};
_prevdirx = _dir;

_offset = 0;
if(_dir > 180) then {
	_offset = __negative*(abs(__N*_coefx) min _maxdelta);
} else {
	_offset = __positive*(abs(__N*_coefx) min _maxdelta);
};

// pitch
_diry = _polarTo select 2;
_headingPitch = (_headingPitch select 2) max -89;
_diry = _diry - _headingPitch;
if(_tdif > 0) then
{
	if !(isNil "_prevdiry") then
	{
		_coefY = _diry - _prevdiry;
	} else
	{
		_coefY = 0;
	};
} else
{
	_coefY = 0;
};
_prevdiry = _diry;

_elevationOffset = 0;
if (_diry > 0) then {
	_elevationOffset = __positive*(abs(__N*_coefy) min _maxdelta);
} else {
	if(_diry < 0) then {
		_elevationOffset = __negative*(abs(__N*_coefy) min _maxdelta);
	};
};

//diag_log format ["dirx %8 diry %9 dlosx %1 dlosy %2 dx %3 dy %4 dmax %5 acc %6 realacc %7",_coefx,_coefy,_offset,_elevationoffset,_maxdelta,_totalvelocity*(asin sqrt((sin _offset)^2+(sin _elevationoffset)^2))*pi/(180*_tdif),_totalvelocity*_angdif*pi/(180*_tdif),_dir,_diry];

if(_offset != 0 && {_elevationOffset != 0}) then {

	_newDir = (getDir _bomb) + _offset;
	if(_newDir < 0) then {
		_newDir = 360 + _newDir;
	} else
	{
		if(_newDir >= 360) then {
			_newDir = _newDir mod 360;
		};
	};

	_vec = vectordir _bomb;
	_newdirV = ((_vec select 2) atan2 sqrt((_vec select 0)^2+(_vec select 1)^2)) + _elevationOffset;

	_vec = [sin(_newdir) * cos(_newdirV), cos(_newdir) * cos (_newdirV), sin (_newdirV)];
	_pitchComponent = sin(_newdirV);
	_vUpX = sin(_newdir) * _pitchComponent;
	_vUpY = cos(_newdir) * _pitchComponent;
	_vUpZ = cos(_newdirV);

	_bomb setVectorDirAndUp [_vec,[_vUpX, _vUpY, _vUpZ]];
	//_bomb setvelocity ([_vec,_totalvelocity] call ACE_fnc_vectorMultiply);

	//drop ["\ca\data\koulesvetlo","","Billboard",100,120,(getpos _bomb),[0,0,0],0,1.275,1,0,[1],[[1,0.1,0.1,-10]],[0],0,0,"","",""];
};
