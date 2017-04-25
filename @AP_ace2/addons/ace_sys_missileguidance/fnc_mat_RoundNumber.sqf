#include "script_component.hpp"

//rounds the number _n to the nearest number than can be obtained as multiplication of _c and an integer
//[3.7, 0.25] -> 3.75

PARAMS_2(_n,_c);

if (_c == 0) exitWith {_n};
(_c*round(_n / _c))
