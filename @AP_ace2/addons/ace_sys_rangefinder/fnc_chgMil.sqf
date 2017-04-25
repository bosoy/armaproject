/* ace_sys_rangefinder (.pbo) (c) 2010 by tcp */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_1(_optr);

if(_optr == player) then {
	if(EMP_RF_RUN) then {
		if(!EMP_RF_CML) then {
			EMP_RF_CML = true;
		};
	};
};
