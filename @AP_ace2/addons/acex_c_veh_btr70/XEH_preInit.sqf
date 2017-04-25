#include "script_component.hpp"

ADDON = false;
LOG(MSG_INIT);

FUNC(init) = COMPILE_FILE(scripts\BTRinit);
FUNC(btr_doors) = COMPILE_FILE(scripts\btr_doors);


[QUOTE(GVAR(moveInDriver)), {
	(_this select 0) moveInDriver ((_this select 0) getVariable 'bgr_btr70_passanger');
	((_this select 0) getVariable 'bgr_btr70_passanger') animate[_this select 1,_this select 2];
	diag_log "SVI Cleanup - moveInDriver"; diag_log _this select 1;
}] call CBA_fnc_addEventHandler;

[QUOTE(GVAR(moveInGunner)), {
	(_this select 0) moveInGunner ((_this select 0) getVariable 'bgr_btr70_passanger');
	((_this select 0) getVariable 'bgr_btr70_passanger') animate[_this select 1,_this select 2];
	diag_log "SVI Cleanup - moveInGunner"; diag_log _this select 1;
}] call CBA_fnc_addEventHandler;

[QUOTE(GVAR(moveInGunner_only)), {
	(_this select 0) moveInGunner ((_this select 0) getVariable 'bgr_btr70_passanger');
	diag_log "SVI Cleanup - moveInGunner_o	nly"; diag_log _this select 1;
}] call CBA_fnc_addEventHandler;

[QUOTE(GVAR(moveInCargo)), {
	(_this select 0) moveInCargo ((_this select 0) getVariable 'bgr_btr70_passanger');
	((_this select 0) getVariable 'bgr_btr70_passanger') animate[_this select 1,_this select 2];
	diag_log "SVI Cleanup - moveInCargo"; diag_log _this select 1;
}] call CBA_fnc_addEventHandler;

[QUOTE(GVAR(moveInCargo_only)), {
	(_this select 0) moveInCargo ((_this select 0) getVariable 'bgr_btr70_passanger');
	diag_log "SVI Cleanup - moveInCargo_only"; diag_log _this select 1;
}] call CBA_fnc_addEventHandler;

[QUOTE(GVAR(moveInTurret)), {
	(_this select 0) moveInDriver ((_this select 0) getVariable 'bgr_btr70_passanger');
	((_this select 0) getVariable 'bgr_btr70_passanger') animate[_this select 1,_this select 2];
	diag_log "SVI Cleanup - moveInTurret"; diag_log _this select 1;
}] call CBA_fnc_addEventHandler;

[QUOTE(GVAR(moveOut)), {
    moveOut (_this select 0);
    ((_this select 0) getVariable 'bgr_btr70_passanger') animate [_this select 1, _this select 2];
	diag_log "SVI Cleanup - moveOut"; diag_log _this select 1;
}] call CBA_fnc_addEventHandler;

[QUOTE(GVAR(moveOut_only)), {
    moveOut (_this select 0);
	diag_log "SVI Cleanup - moveOut_only";
}] call CBA_fnc_addEventHandler;


[QUOTE(GVAR(moveOut_getinhigh)), {
    moveOut (_this select 0);
    (_this select 0) setDir 180 + getDir (_this select 0);
    ((_this select 0) getVariable 'bgr_btr70_passanger') animate [_this select 1, _this select 2];
    (_this select 0) playMove 'amovpercmstpsnonwnondnon_acrgpknlmstpsnonwnondnon_getinhigh';
	diag_log "SVI Cleanup - moveOut_getinhigh"; diag_log _this select 1;
}] call CBA_fnc_addEventHandler;


[QUOTE(GVAR(moveOut_getinlow)), {
    moveOut (_this select 0);
    (_this select 0) setDir 180 + getDir (_this select 0);
    ((_this select 0) getVariable 'bgr_btr70_passanger') animate [_this select 1, _this select 2];
    (_this select 0) playMove 'amovpercmstpsnonwnondnon_acrgpknlmstpsnonwnondnon_getinlow';
	diag_log "SVI Cleanup - moveOut_getinlow"; diag_log _this select 1;
}] call CBA_fnc_addEventHandler;

[QUOTE(GVAR(play_getinlow)), {
    (_this select 0) setDir 180 + getDir (_this select 0);
    ((_this select 0) getVariable 'bgr_btr70_passanger') animate [_this select 1, _this select 2];
    (_this select 0) playMove 'amovpercmstpsnonwnondnon_acrgpknlmstpsnonwnondnon_getinlow';
	diag_log "SVI Cleanup - play_getinlow"; diag_log _this select 1;
}] call CBA_fnc_addEventHandler;

[QUOTE(GVAR(play_getinhigh)), {
    (_this select 0) setDir 180 + getDir (_this select 0);
    ((_this select 0) getVariable 'bgr_btr70_passanger') animate [_this select 1, _this select 2];
    (_this select 0) playMove 'amovpercmstpsnonwnondnon_acrgpknlmstpsnonwnondnon_getinhigh';
	diag_log "SVI Cleanup - play_getinlow"; diag_log _this select 1;
}] call CBA_fnc_addEventHandler;

[QUOTE(GVAR(BTR_Animate)), {
	((_this select 0) getVariable 'bgr_btr70_passanger') animate[_this select 1, _this select 2];
	diag_log "SVI Cleanup - BTR_Animate"; diag_log _this select 1;
}] call CBA_fnc_addEventHandler;


ADDON = true;

