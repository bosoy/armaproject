#include "script_component.hpp"

private["_handle"];
PARAMS_3(_vehicle,_projectile,_target);

_handle = [
			ace_sys_missileguidance_fnc_missile_kh29_track,
			[_projectile,_target], /* parameters */
			0.02, // delay
			{
				//init
				_bomb = _this select 0;
				_currentTarget = _this select 1;
				_lastTime = time;
				_prevdirx = nil;
				_prevdiry = nil;
				_curVelocity = velocity _bomb;
			},
			{ /* exit code */
			},
			{ /* Run condition - default true */
				true
			},
			{(! alive _bomb) || {isNull _currentTarget}}, /* exit condition */
			[ /* Private variables, available throughout all states and conditions */
				"_bomb", "_lastTime", "_currentTarget","_prevdirx","_prevdiry","_curPitch", "_newDir", "_totalVelocity", "_vec","_maxdelta",
				"_coefx","_coefy","_curVelocity", "_tdif", "_totalVelocity", "_headingPitch", "_marker", "_vectorTo", "_polarTo", "_dir","_diry",
				 "_angdif","_offset", "_elevationOffset", "_orientation", "_laserCode", "_targetCode",
				"_newdirV","_vUpX","_vUpY","_vUpZ","_pitchcomponent"
			]
		] call cba_common_fnc_addPerFrameHandlerLogic;

_handle