/* ace_sys_explosives (.pbo)| M49 TripFlare | (c) 2008, 2009 by rocko */
#include "script_component.hpp"

private ["_fx_flare","_fx_smoke","_factor","_li","_t","_mine"];

PARAMS_1(_trigger);
_mine = [_trigger] call FUNC(get_mine);
_pos_offset = _mine selectionPosition "ace_flare_pos";

#define __y [[1, 1, 0, 1], [1, 1, 0, 0.8], [1, 1, 0, 1], [1, 1, 0, 1]]
#define __vel [0,0,0]
#define __i 0.01
#define __s ((player distance _mine) / 400)
#define __flareParticle "\ca\Data\sunHalo.p3d"
#define __smokeParticle "\ca\Data\ParticleEffects\Universal\Universal"

#define __fx_flare _fx_flare setParticleParams [[__flareParticle, 1, 1, 1], "", "Billboard", \
10, 0.5, _pos_offset, \
__vel, \
1, 1.275, 1, 0, \
[_factor*2,_factor,_factor/2], \
__y, \
[0.08], 1, 0, "", "", _mine]

#define __fx_smoke _fx_smoke setParticleParams [[__smokeParticle, 16, 7, 48], "", "Billboard", \
1, 2, _pos_offset, \
[0, 0, 0], \
1, 0.05, 0.04, 0, \
[1,0.6,0.3], \
[[0.4,0.4,0.4,0],[0.8,0.8,0.8,0.5],[0.4,0.4,0.4,0.3],[0.6,0.6,0.6,0.2],[1,1,1,0]], \
[1.5,0.5], 0.2, 0.25, "", "", _mine]

// TimerPeriod, Lifetime, Position
// MoveVelocity
// RotationVelocity, Weight, Volume, Rubbing
// Size
// Color
// Animphase, RandomDirPeriod, RandomDirIntensity, OnTimer, BeforeDestroy, Object

_li = "#lightpoint" createVehicleLocal getpos _mine;
_li setLightBrightness 0;
_li setLightAmbient[1, 1, 0.0];
_li setLightColor[1, 1, 0];
_li lightAttachObject [_mine, [0,0,0]];

_factor = __s;
if (_factor > 12.5) then { _factor = 12.5; }; if (_factor < 1) then { _factor = 1; };

_fx_flare = "#particleSource" createVehicleLocal (getPos _mine);
_fx_flare setParticleRandom [0.5, [0.1, 0.1, 0.1], [0, 0, 0], 0, 0.1, [0.1, 0.1, 0.1, 0.05], 0, 0];
_fx_flare setDropInterval __i;
_fx_smoke = "#particleSource" createVehicleLocal (getPos _mine);
_fx_smoke setParticleRandom [0.5, [0.1, 0.1, 0.1], [0, 0, 0], 0, 0.1, [0.1, 0.1, 0.1, 0.05], 0, 0];
_fx_smoke setDropInterval __i;

_t = 0;
_mine say "ACE_M49_Explosion";
while { _t < 60 } do {
	__fx_flare; __fx_smoke;
	_li setLightBrightness (_factor/10);
	sleep 1;
	INC(_t);
};
deleteVehicle _li; deleteVehicle _fx_smoke; deleteVehicle _fx_flare;
_mine setdamage 1;
//[_mine, 300] call ACE_fnc_add2clean;
_mine spawn { sleep 300; deleteVehicle _this; };
