//fnc_shrapnel.sqf
#include "script_component.hpp"
//setAccTime 0.01;
PARAMS_3(_lastPos,_lastVel,_explosive);

//player sideChat format["this: %1", _this];
if ((count _lastPos) > 0 && {(count _lastVel) > 0}) then {
	_polar = _lastVel call CBA_fnc_vect2polar;
	_dirRange = ((((abs (_polar select 2))/90)*360)+160) min 360;
	
	_dir = (_polar select 1) - (_dirRange/2);
	if (_dir < 0) then {
		_dir = _dir + 360;
	};
	if (_dir < 0) then {
		_dir = _dir + 360;
	};
	_elrangeTop = 0.35;
	_elrangeBot = -0.25;
	if ((_lastPos select 2) > 2) then {
		_elrangeTop = 40;
		_elrangeBot = -40;
	};
	_ccc = 0;
	_scount = 500;
	_scount = round (_scount*(_dirRange/360));
	
	if (isNil "_explosive") then {
		_explosive = 0.5;
	};
	_scount = _scount*_explosive;
	//player sideChat format["c: %1", _scount];
	_types = ["ace_sys_arty_shrapnel"];
	for "_shrap" from 0 to _scount do {
		_ccc = _ccc + 1;
		
		_b = (_types select (floor (random (count _types)))) createVehicleLocal [((_lastPos select 0) + random (0.25)), ((_lastPos select 1) + random (0.25)), ((_lastPos select 2) + random (0.25) + 0.1)];
		_sdir = (_dir + ((_shrap+(random _dirRange)) mod _dirRange)) mod 360;
		_e = (_elrangeBot + ((_shrap + (random _elrangeTop)) mod _elrangeTop));
		_newVel = [100 + (random 300), _sdir, _e] call CBA_fnc_polar2vect;
		_b setVelocity _newVel;
		_b setVectorDir _newVel;
		
		// [_b, _marker] spawn {
			// private ["_bbb"];
			// _bbb = _this select 0;
			// _marker = _this select 1;
			
			// waitUntil {
				// if(alive _bbb) then {
					// drop ["\Ca\Data\Cl_basic","","Billboard",1,5,(getPos _bbb),[0,0,0],1,1.275,1.0,0.0,[1],[[1,0,0,1]],[0],0.0,2.0,"","",""];
					// _marker = createMarkerLocal [format["m%1", random(1000)+time], (getPos _bbb)];
					// _marker setMarkerTypeLocal "Dot";
					// _marker setMarkerColorLocal "ColorRed";
					// _marker setMarkerSizeLocal [0.1, 0.1];
				// };
				// (!alive _bbb)
			// };
		// };
	};
};