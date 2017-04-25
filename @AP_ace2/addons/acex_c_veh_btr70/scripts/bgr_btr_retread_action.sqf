/*
Created by Vadim Shchemelinin aka badger
2010 St.Petersburg

Script for BTR-70 by RHS
*/

private ["_btr","_btr2","_btrpos","_upos","_udeg0","_udeg","_man","_selection","_selectionsArray","_freepos"];
_btr = _this select 0;
_man = _this select 1;
_anim = (_this select 3) select 0;
_selection = (_this select 3) select 1;
_selectionsArray = ["wheel_1_1_steering","wheel_2_1_steering","wheel_1_2_steering","wheel_2_2_steering","wheel_1_3_steering","wheel_2_3_steering","wheel_1_4_steering","wheel_2_4_steering"];
_btrpos = getPosATL _btr;
_freepos = "";
_btr2 = _btr;

if (_anim == "delimsa") then {
	//delimsa
	_btr2 = (nearestObjects [_btr, ["ace_btr70_base"], 20]) select 1;
	//hintC format ["%1 // %2  ++  %3",nearestObjects [_btr, ["ace_btr70_base"], 20],_btr2 animationPhase 'wheel_1_1_unhide',_btr2 animationPhase 'wheel_2_1_unhide'];
	if (_btr2 animationPhase 'wheel_2_1_unhide' > 0.5) then {
		_freepos = 'wheel_2_1_unhide';
		hint "2";
	} else {
		if ((_btr2 animationPhase 'wheel_1_1_unhide' > 0.5)and(_btr2 animationPhase 'engineHatches' == 0)) then {
			_freepos = 'wheel_1_1_unhide';
			hint "1";
		} else {
			hint localize "STR_BTR70_retread_delimsa_not";
			_freepos = 'not';
		};
	};
	if (_freepos == 'not') exitWith{};
	hint localize "STR_BTR70_retread_delimsa_start";
	moveOut _man;
	_upos = getPosATL _btr2;
	sleep 0.2;
	waitUntil {_man == vehicle _man};
	if (_btr distance _btrpos > 5) exitwith {hint localize "STR_BTR70_retread_fail";};
	if (_btr2 distance _upos > 5) exitwith {hint localize "STR_BTR70_retread_fail";};
};
if (_freepos == 'not') exitWith{};
if (_btr animationPhase 'wheel_1_1_unhide' < 0.5) then {
	_btr animate ["wheel_1_1_unhide",1];
} else {
	if (_btr animationPhase 'wheel_2_1_unhide' < 0.5) then {
		_btr animate ["wheel_2_1_unhide",1];
	} else {
		hint localize "STR_BTR70_retread_not";
		if (true) exitWith{};
	};
};

if (_anim == "delimsa") then {
	//delimsa
	sleep 2;
	if (_btr distance _btrpos > 5) exitwith {hint localize "STR_BTR70_retread_fail";};
	if (_btr2 distance _upos > 5) exitwith {hint localize "STR_BTR70_retread_fail";};
	_btr2 animate [_freepos,0];
	hint localize "STR_BTR70_retread_delimsa_ok";

} else {
	//remontiruem

	switch (_selectionsArray find _selection) do {
		case 0: {
			_upos = [-1.8,2.3,-2];
			_udeg = 90;
			_udeg0 = 180;
		};
		case 1: {
			_upos = [1.8,1.5,-2];
			_udeg = -90;
			_udeg0 = 0;
		};
		case 2: {
			_upos = [-1.8,1.5,-2];
			_udeg = 90;
			_udeg0 = 180;
		};
		case 3: {
			_upos = [1.8,0.5,-2];
			_udeg = -90;
			_udeg0 = 0;
		};
		case 4: {
			_upos = [-1.8,0.5,-2];
			_udeg = 90;
			_udeg0 = 180;
		};
		case 5: {
			_upos = [1.8,-1.5,-2];
			_udeg = -90;
			_udeg0 = 0;
		};
		case 6: {
			_upos = [-1.8,-1.5,-2];
			_udeg = 90;
			_udeg0 = 180;
		};
		case 7: {
			_upos = [1.8,-3,-2];
			_udeg = -90;
			_udeg0 = 0;
		};
	};

	hint localize "STR_BTR70_retread_start";
	_btr animate ["_anim",0.89];
	if (_man != vehicle _man) then {
		moveOut _man;
		sleep 0.2;
		waitUntil {_man == vehicle _man};
	};


//	_man setVariable ['bgr_rhs_btr70_retread_mans_btr', [_btr,_upos,_udeg,_udeg0], true];
	_man attachTo [_btr,_upos];
	_man SetDir (_udeg0);
	_man playMove  'AmovPercMstpSnonWnonDnon_carCheckWheel';
	sleep 8;
	if (_btr distance _btrpos > 5) exitwith {hint localize "STR_BTR70_retread_fail"; detach _man;};
	_man SetDir (_udeg);
	_man playMove  'AinvPknlMstpSlayWrflDnon_medic';
	sleep 6;
	if (_btr distance _btrpos > 5) exitwith {hint localize "STR_BTR70_retread_fail"; detach _man;};
	_man playMove  'AinvPknlMstpSlayWrflDnon_medic';
	sleep 6;
	if (_btr distance _btrpos > 5) exitwith {hint localize "STR_BTR70_retread_fail"; detach _man;};
	_man playMove  'AinvPknlMstpSlayWrflDnon_medic';
	sleep 6;
	if (_btr distance _btrpos > 5) exitwith {hint localize "STR_BTR70_retread_fail"; detach _man;};
	detach _man;

/*	_man setVariable ['bgr_rhs_btr70_retread_mans_btr', [_btr,_upos,_udeg,_udeg0], true];
	_man setVehicleInit "
		this attachTo [(this getVariable 'bgr_rhs_btr70_retread_mans_btr') select 0,(this getVariable 'bgr_rhs_btr70_retread_mans_btr') select 1];
		this playMove  'AmovPercMstpSnonWnonDnon_carCheckWheel';
		this SetDir ((this getVariable 'bgr_rhs_btr70_retread_mans_btr') select 3);
					";
	processInitCommands;
	sleep 8;
	if (_btr distance _btrpos > 5) exitwith {hint localize "STR_BTR70_retread_fail";};
	_man setVehicleInit "
		this playMove  'AinvPknlMstpSlayWrflDnon_medic';
		this SetDir ((this getVariable 'bgr_rhs_btr70_retread_mans_btr') select 2);
					";
	processInitCommands;
	sleep 6;
	if (_btr distance _btrpos > 5) exitwith {hint localize "STR_BTR70_retread_fail";};
	_man setVehicleInit "
		this playMove  'AinvPknlMstpSlayWrflDnon_medic';
	";
	processInitCommands;
	sleep 6;
	if (_btr distance _btrpos > 5) exitwith {hint localize "STR_BTR70_retread_fail";};
	_man setVehicleInit "
		this playMove  'AinvPknlMstpSlayWrflDnon_medic';
	";
	processInitCommands;
	sleep 6;
	if (_btr distance _btrpos > 5) exitwith {hint localize "STR_BTR70_retread_fail";};
	_man setVehicleInit "
		this SetDir ((this getVariable 'bgr_rhs_btr70_retread_mans_btr') select 3);
		detach this;
	";
	processInitCommands;
	clearVehicleInit (_man);*/

	_btr setHit [_selection, 0];
	hint localize "STR_BTR70_retread_finish";


};