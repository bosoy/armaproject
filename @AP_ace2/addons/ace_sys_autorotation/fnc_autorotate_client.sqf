#include "script_component.hpp"

PARAMS_1(_heli);

if (_heli getVariable QGVAR(autorotating)) exitWith {};
_heli setVariable [QGVAR(autorotating), true];

#define __dsp (uiNameSpace getVariable "ACE_RscGeneric")
#define __ctrl_mstr (__dsp displayCtrl 135136)
#define __ctrl_airf (__dsp displayCtrl 135137)

#define __verticalGain getNumber (configFile >> "CfgVehicles" >> _typeOf >> QGVAR(vertical_gain))
#define __horizontalGain getNumber (configFile >> "CfgVehicles" >> _typeOf >> QGVAR(horizontal_gain))

#define __step 0.05
#define __f (_verticalGain * _timeDiff)		//factor of how much gain does vertical movement of air provide for lift force
#define __h (_horizontalGain * _timeDiff)	//6th_gar factor scalling for how much gain in lift is provided by horizontal movement of air trough rotor, around whings etc. (allows for some gain from "gliding" at high speed)
						//these two values are hard to set to satisfy every chopper type (allow any chopper to land with little dammage) and make it not hard to die in the manouver at the same time. Choppers also act different when hitting the ground - MAP_ Apache for example is very fragile... AH-6 is another problem since by default it has quite high drag and tends to loose speed fast
						//perhabs needs different values for each helicopter to ballance the difficulty? For now it is set so any chopper can be landed, some easier than others.

						// TODO: various values for various helicopters, read config setting (mass vs wing lift + rotor lift)
							// It shouldn't be so easy to autorotate Merlin as Littlebird

#define __vx (_v select 0)
#define __vy (_v select 1)
#define __vz (_v select 2)
#define __ux (_u select 0)
#define __uy (_u select 1)
#define __uz (_u select 2)

#define __alphaCos ((__vx*__ux + __vy*__uy + __vz*__uz)/(sqrt(__vx^2+__vy^2+__vz^2)+sqrt(__ux^2+__uy^2+__uz^2)))
#define __alphaSin (sin(acos __alphaCos))
#define __airflow (sqrt (__vx^2+__vy^2+__vz^2))
#define __vNew ([__vx + __ux*(((-__alphaCos)*__f + (abs __alphaSin)*__h)*__airflow),__vy + __uy*(((-__alphaCos)*__f + (abs __alphaSin)*__h)*__airflow),__vz + __uz*(((-__alphaCos)*__f + (abs __alphaSin)*__h)*__airflow)])


_handle = [
	{
		_v = velocity _vehicle;
		_u = vectorUp _vehicle;
		_vehicle setVelocity __vNew;
		_timeDiff = time - _timePrev;
		_timePrev = time;
		if (driver _vehicle == player) then {
			cutRsc ["ACE_RscGeneric","PLAIN"];
			_text = format ["Airflow Speed %1 m/s", (-__alphaCos * __airflow) - (-__alphaCos * __airflow) mod 1];	//6th_gar normally pilot would get this information watching a pice of string mounted outside of cabin or simmilar primitive instrument, it is making the manouver much easier
			__ctrl_mstr ctrlSetText "MSTR WRNG";
			__ctrl_airf ctrlSetText _text;
			__ctrl_mstr ctrlSetTextColor [1,0,0,1];
			__ctrl_airf ctrlSetTextColor [1,0,0,1];
		};
	},
	_heli, /* parameters */
	0, // delay
	{ /* init code */
		_vehicle = _this;
		_typeOf = typeOf _vehicle;
		_verticalGain = __verticalGain;
		_horizontalGain = __horizontalGain;
		_timeDiff = __step;
		_timePrev = time;
	},
	{ /* exit code */
		_vehicle setVariable [QGVAR(autorotating), false];
	},
	{ /* Run condition - default true */
		_r = false;
		_r = time > _timePrev;
		_r;
	},
	{!((alive driver _vehicle) && {(alive _vehicle)} && {(local driver _vehicle)}) || {(isEngineOn _vehicle)} || {(((getPos _vehicle) select 2 < 1) && {(velocity _vehicle call ACE_fnc_magnitude < 1)})}}, /* exit condition */
	[ /* Private variables, available throughout all states and conditions */
		"_v","_u","_timePrev","_timeDiff","_vehicle","_typeOf","_verticalGain","_horizontalGain"
	]
] call cba_common_fnc_addPerFrameHandlerLogic;
