/* ace_sys_clusterbombs (.pbo) | (c) 2008, 2009, 2010, 2011 by rocko */

#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

PREP(fired);
PREP(CEM);
PREP(SFW);
PREP(durandal);


FUNC(trash) = {
	//diag_log "Trashing";
	{ [_x, 600] call ACE_fnc_add2clean; } foreach _this;
};

FUNC(popfx) = {
	drop [ ["\ca\Ca_E\data\ParticleEffects\Universal\Universal.p3d",16,12,8,0], "", "Billboard", 1, 0.1, [0.3,0.3,0.3], [0,0,0], 1, 1, 0.08, 0.5, [1.5,0], [[1,1,1,-4],[1,1,1,-4],[1,1,1,-2],[1,1,1,0]], [1], 0.1, 0.1, "", "", _this ];
	drop [ ["\ca\Ca_E\data\ParticleEffects\Universal\Universal.p3d",16,12,8,0], "", "Billboard", 1, 3, [0,0,0], [0,0,0], 1, 1, 0.08, 0.5, [1.3,4], [[0.9,0.9,0.9,0.6],[1,1,1,0.3],[1,1,1,0]], [1000], 0.1, 0.1, "", "", _this ];
	drop [ ["\ca\Ca_E\data\ParticleEffects\Universal\Universal.p3d",16,12,8,0], "", "Billboard", 1, 0.1, [0.3,0.3,0.3], [0,0,0], 1, 1, 0.08, 0.5, [1.5,0], [[1,1,1,-4],[1,1,1,-4],[1,1,1,-2],[1,1,1,0]], [1], 0.1, 0.1, "", "", _this ];
	drop [ ["\ca\Ca_E\data\ParticleEffects\Universal\Universal.p3d",16,12,8,0], "", "Billboard", 1, 3, [0,0,0], [0,0,0], 1, 1, 0.08, 0.5, [1.3,4], [[0.9,0.9,0.9,0.6],[1,1,1,0.3],[1,1,1,0]], [1000], 0.1, 0.1, "", "", _this ];
};

if (isServer) then {
	[QGVAR(trash), {_this call FUNC(trash)}] call ACE_fnc_addClientToServerEventhandler;
};
if (!isDedicated) then {
	[QGVAR(popfx), {_this call FUNC(popfx)}] call CBA_fnc_addEventHandler;
};

ADDON = true;