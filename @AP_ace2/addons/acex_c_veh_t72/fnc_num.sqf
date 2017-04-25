#include "script_component.hpp"
#define TEX(A) QUOTE(PATHTO_T(numbers\A))

PARAMS_1(_unit);

if (true) then {
	_nrand = random(100);
	if (_nrand > 80) exitWith { _unit setObjectTexture [0, TEX(n4.paa)] };
	if (_nrand > 60) exitWith { _unit setObjectTexture [0, TEX(n3.paa)] };
	if (_nrand > 40) exitWith { _unit setObjectTexture [0, TEX(n2.paa)] };
	if (_nrand > 20) exitWith { _unit setObjectTexture [0, TEX(n1.paa)] };
	_unit setObjectTexture [0, TEX(n0.paa)];
};

if (true) then {
	_nrand = random(100);
	if (_nrand > 75) exitWith { _unit setObjectTexture [1, TEX(n3.paa)] };
	if (_nrand > 50) exitWith { _unit setObjectTexture [1, TEX(n2.paa)] };
	if (_nrand > 25) exitWith { _unit setObjectTexture [1, TEX(n1.paa)] };
	_unit setObjectTexture [1, TEX(n0.paa)];
};

if (true) then {
	_nrand = random(100);
	if (_nrand > 90) exitWith { _unit setObjectTexture [2, TEX(n9.paa)] };
	if (_nrand > 80) exitWith { _unit setObjectTexture [2, TEX(n8.paa)] };
	if (_nrand > 70) exitWith { _unit setObjectTexture [2, TEX(n7.paa)] };
	if (_nrand > 60) exitWith { _unit setObjectTexture [2, TEX(n6.paa)] };
	if (_nrand > 50) exitWith { _unit setObjectTexture [2, TEX(n5.paa)] };
	if (_nrand > 40) exitWith { _unit setObjectTexture [2, TEX(n4.paa)] };
	if (_nrand > 30) exitWith { _unit setObjectTexture [2, TEX(n3.paa)] };
	if (_nrand > 20) exitWith { _unit setObjectTexture [2, TEX(n2.paa)] };
	if (_nrand > 10) exitWith { _unit setObjectTexture [2, TEX(n1.paa)] };
	_unit setObjectTexture [2, TEX(n0.paa)];
};
