#include "script_component.hpp"

PREP(fired);
PREP(shrapnel);
PREP(gunInit);
PREP(firedEh);
PREP(dispersion);

GVAR(sc) = 1;

GVAR(seeds) = [];
ace_sys_arty_prngSum = 0;
ace_sys_arty_prngStr = "";
FUNC(randomSequence) = {
	_key = count GVAR(seeds);
	GVAR(seeds) set [_key, _this];
	_key;
};

FUNC(prng) = {
	private ["_r1", "_r2", "_oxi", "_a", "_c", "_m", "_xi", "_r", "_key"];
	_key = _this select 0;
	_r1 = _this select 1;
	_r2 = _this select 2;
	_a = 1277;
	_c = 0;
	_m = 21402;
	_oxi = GVAR(seeds) select _key;
	_xi = (_a*_oxi + _c)%_m;
	_r = _r1 + ((_r2 - _r1)/_m)*_xi;
	GVAR(seeds) set [_key, _xi];
	ace_sys_arty_prngStr = ace_sys_arty_prngStr + 
		format["(%1*%2 + %3) mod %4 = %5 + ((%6 - %7)/%8)*%9 = %10%11", 
				_a,_oxi,_c,_m,_r1,_r2,_r1,_m,_xi,_r, toString[10]];
	ace_sys_arty_prngSum = ace_sys_arty_prngSum + _r;
	_r
};