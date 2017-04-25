/*
Created by Vadim Shchemelinin aka badger
2010 St.Petersburg

Script for BTR-70 by RHS
*/
//if !(rhs_btr70_EnableRetread) exitWith {};
if (!isnil "rhs_btr70_EnableRetread" && {!rhs_btr70_EnableRetread}) exitWith {};//исправлено

private ["_btr","_selectionsArray","_animsArray","_countrefr","_btract"];
_btr = _this select 0;

_selectionsArray = ["wheel_1_1_steering","wheel_2_1_steering","wheel_1_2_steering","wheel_2_2_steering","wheel_1_3_steering","wheel_2_3_steering","wheel_1_4_steering","wheel_2_4_steering"];

_animsArray = ["wheel_1_1_destruct","wheel_2_1_destruct","wheel_1_2_destruct","wheel_2_2_destruct","wheel_1_3_destruct","wheel_2_3_destruct","wheel_1_4_destruct","wheel_2_4_destruct"];

_btract = _btr addAction [localize "STR_BTR70_retread_L1", "\x\acex\addons\c_veh_btr70\scripts\bgr_btr_retread_action.sqf", [(_animsArray select 0),(_selectionsArray select 0)], 1, true, true, "",
	"(_target animationPhase 'wheel_1_1_destruct' > 0.9)&&(getDammage _target < 1)&&(speed _target < 1)&&((_target animationPhase 'wheel_1_unhide' < 0.5) || (_target animationPhase 'wheel_2_unhide' < 0.5))"];
_btract = _btr addAction [localize "STR_BTR70_retread_P1", "\x\acex\addons\c_veh_btr70\scripts\bgr_btr_retread_action.sqf", [(_animsArray select 1),(_selectionsArray select 1)], 1, true, true, "",
	"(_target animationPhase 'wheel_2_1_destruct' > 0.9)&&(getDammage _target < 1)&&(speed _target < 1)&&((_target animationPhase 'wheel_1_unhide' < 0.5) || (_target animationPhase 'wheel_2_unhide' < 0.5))"];
_btract = _btr addAction [localize "STR_BTR70_retread_L2", "\x\acex\addons\c_veh_btr70\scripts\bgr_btr_retread_action.sqf", [(_animsArray select 2),(_selectionsArray select 2)], 1, true, true, "",
	"(_target animationPhase 'wheel_1_2_destruct' > 0.9)&&(getDammage _target < 1)&&(speed _target < 1)&&((_target animationPhase 'wheel_1_unhide' < 0.5) || (_target animationPhase 'wheel_2_unhide' < 0.5))"];
_btract = _btr addAction [localize "STR_BTR70_retread_P2", "\x\acex\addons\c_veh_btr70\scripts\bgr_btr_retread_action.sqf", [(_animsArray select 3),(_selectionsArray select 3)], 1, true, true, "",
	"(_target animationPhase 'wheel_2_2_destruct' > 0.9)&&(getDammage _target < 1)&&(speed _target < 1)&&((_target animationPhase 'wheel_1_unhide' < 0.5) || (_target animationPhase 'wheel_2_unhide' < 0.5))"];
_btract = _btr addAction [localize "STR_BTR70_retread_L3", "\x\acex\addons\c_veh_btr70\scripts\bgr_btr_retread_action.sqf", [(_animsArray select 4),(_selectionsArray select 4)], 1, true, true, "",
	"(_target animationPhase 'wheel_1_3_destruct' > 0.9)&&(getDammage _target < 1)&&(speed _target < 1)&&((_target animationPhase 'wheel_1_unhide' < 0.5) || (_target animationPhase 'wheel_2_unhide' < 0.5))"];
_btract = _btr addAction [localize "STR_BTR70_retread_P3", "\x\acex\addons\c_veh_btr70\scripts\bgr_btr_retread_action.sqf", [(_animsArray select 5),(_selectionsArray select 5)], 1, true, true, "",
	"(_target animationPhase 'wheel_2_3_destruct' > 0.9)&&(getDammage _target < 1)&&(speed _target < 1)&&((_target animationPhase 'wheel_1_unhide' < 0.5) || (_target animationPhase 'wheel_2_unhide' < 0.5))"];
_btract = _btr addAction [localize "STR_BTR70_retread_L4", "\x\acex\addons\c_veh_btr70\scripts\bgr_btr_retread_action.sqf", [(_animsArray select 6),(_selectionsArray select 6)], 1, true, true, "",
	"(_target animationPhase 'wheel_1_4_destruct' > 0.9)&&(getDammage _target < 1)&&(speed _target < 1)&&((_target animationPhase 'wheel_1_unhide' < 0.5) || (_target animationPhase 'wheel_2_unhide' < 0.5))"];
_btract = _btr addAction [localize "STR_BTR70_retread_P4", "\x\acex\addons\c_veh_btr70\scripts\bgr_btr_retread_action.sqf", [(_animsArray select 7),(_selectionsArray select 7)], 1, true, true, "",
	"(_target animationPhase 'wheel_2_4_destruct' > 0.9)&&(getDammage _target < 1)&&(speed _target < 1)&&((_target animationPhase 'wheel_1_unhide' < 0.5) || (_target animationPhase 'wheel_2_unhide' < 0.5))"];

_btract = _btr addAction [localize "STR_BTR70_retread_delimsa", "\x\acex\addons\c_veh_btr70\scripts\bgr_btr_retread_action.sqf", ["delimsa",""], 1, false, true, "",
	"(vehicle _this == _target)&&(1 < count nearestObjects [_target, ['ace_btr70_base'], 20])&&(getDammage _target < 1)&&(speed _target < 1)&&((_target animationPhase 'wheel_1_1_unhide' < 0.5) || (_target animationPhase 'wheel_2_1_unhide' < 0.5))"];

/*

_btract = _btr addAction [localize "STR_BTR70_retread_L1", "\x\acex\addons\c_veh_btr70\scripts\bgr_btr_retread_action.sqf", [(_animsArray select 0),(_selectionsArray select 0)], 1, true, true, "",
	"(_target animationPhase 'wheel_1_1_destruct' > 0.9)&&(getDammage _target < 1)&&(speed _target < 1)&&((_target animationPhase 'wheel_1_unhide' < 0.5) || (_target animationPhase 'wheel_2_unhide' < 0.5))"];
_btract = _btr addAction [localize "STR_BTR70_retread_P1", "\x\acex\addons\c_veh_btr70\scripts\bgr_btr_retread_action.sqf", [(_animsArray select 1),(_selectionsArray select 1)], 1, true, true, "",
	"(_target animationPhase 'wheel_2_1_destruct' > 0.9)&&(getDammage _target < 1)&&(speed _target < 1)&&((_target animationPhase 'wheel_1_unhide' < 0.5) || (_target animationPhase 'wheel_2_unhide' < 0.5))"];
_btract = _btr addAction [localize "STR_BTR70_retread_L2", "\x\acex\addons\c_veh_btr70\scripts\bgr_btr_retread_action.sqf", [(_animsArray select 2),(_selectionsArray select 2)], 1, true, true, "",
	"(_target animationPhase 'wheel_1_2_destruct' > 0.9)&&(getDammage _target < 1)&&(speed _target < 1)&&((_target animationPhase 'wheel_1_unhide' < 0.5) || (_target animationPhase 'wheel_2_unhide' < 0.5))"];
_btract = _btr addAction [localize "STR_BTR70_retread_P2", "\x\acex\addons\c_veh_btr70\scripts\bgr_btr_retread_action.sqf", [(_animsArray select 3),(_selectionsArray select 3)], 1, true, true, "",
	"(_target animationPhase 'wheel_2_2_destruct' > 0.9)&&(getDammage _target < 1)&&(speed _target < 1)&&((_target animationPhase 'wheel_1_unhide' < 0.5) || (_target animationPhase 'wheel_2_unhide' < 0.5))"];
_btract = _btr addAction [localize "STR_BTR70_retread_L3", "\x\acex\addons\c_veh_btr70\scripts\bgr_btr_retread_action.sqf", [(_animsArray select 4),(_selectionsArray select 4)], 1, true, true, "",
	"(_target animationPhase 'wheel_1_3_destruct' > 0.9)&&(getDammage _target < 1)&&(speed _target < 1)&&((_target animationPhase 'wheel_1_unhide' < 0.5) || (_target animationPhase 'wheel_2_unhide' < 0.5))"];
_btract = _btr addAction [localize "STR_BTR70_retread_P4", "\x\acex\addons\c_veh_btr70\scripts\bgr_btr_retread_action.sqf", [(_animsArray select 5),(_selectionsArray select 5)], 1, true, true, "",
	"(_target animationPhase 'wheel_2_3_destruct' > 0.9)&&(getDammage _target < 1)&&(speed _target < 1)&&((_target animationPhase 'wheel_1_unhide' < 0.5) || (_target animationPhase 'wheel_2_unhide' < 0.5))"];
_btract = _btr addAction [localize "STR_BTR70_retread_L4", "\x\acex\addons\c_veh_btr70\scripts\bgr_btr_retread_action.sqf", [(_animsArray select 6),(_selectionsArray select 6)], 1, true, true, "",
	"(_target animationPhase 'wheel_1_4_destruct' > 0.9)&&(getDammage _target < 1)&&(speed _target < 1)&&((_target animationPhase 'wheel_1_unhide' < 0.5) || (_target animationPhase 'wheel_2_unhide' < 0.5))"];
_btract = _btr addAction [localize "STR_BTR70_retread_P4", "\x\acex\addons\c_veh_btr70\scripts\bgr_btr_retread_action.sqf", [(_animsArray select 7),(_selectionsArray select 7)], 1, true, true, "",
	"(_target animationPhase 'wheel_2_4_destruct' > 0.9)&&(getDammage _target < 1)&&(speed _target < 1)&&((_target animationPhase 'wheel_1_unhide' < 0.5) || (_target animationPhase 'wheel_2_unhide' < 0.5))"];

*/