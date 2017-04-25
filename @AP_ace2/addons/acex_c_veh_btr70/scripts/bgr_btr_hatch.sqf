#include "\x\acex\addons\c_veh_btr70\script_component.hpp"
/*
Created by Vadim Shchemelinin aka badger
2010 St.Petersburg

Script for BTR-70 by RHS
*/
private ["_btr","_InWater","_Tpitch","_pos0","_weapon"];

_btr = _this select 0;

if (isServer) then {
	[_btr] spawn {
		while {(alive (_this select 0))} do {
			waitUntil{surfaceIsWater [(getposASL (_this select 0) select 0), (getposASL (_this select 0) select 1)]};
			(_this select 0) animate["propDoor",1];
			waitUntil{not surfaceIsWater [(getposASL (_this select 0) select 0), (getposASL (_this select 0) select 1)]};
			(_this select 0) animate["propDoor",0];
			sleep 1;
		};
	};
	[_btr] spawn {
		while {(alive (_this select 0))} do {
			if ((speed (_this select 0) > 10)and(((_this select 0) animationPhase "l_door" == 1)or((_this select 0) animationPhase "r_door" == 1))) then {
				if ((_this select 0) animationPhase "l_door" == 1) then {(_this select 0) animate["l_door",0];};
				if ((_this select 0) animationPhase "r_door" == 1) then {(_this select 0) animate["r_door",0];};
			};
		};
	};
};

if (isMultiplayer) exitWith {rhs_activeAutoHatches = false;};

//if !(rhs_activeAutoHatches) exitWith {};
waitUntil {rhs_activeAutoHatches};

_btr setVariable ["bgr_btr_hatch_driver", [0,0,0], false];	//state unit hatch
_btr setVariable ["bgr_btr_hatch_gunner", [0,0,0], false];
_btr setVariable ["bgr_btr_hatch_commander", [0,0,0], false];
_btr setVariable ["bgr_btr_hatch_cargo", [0,0,0,0,0,""], false];	//state unit top left right type

_bgr_btr_in = _btr addEventHandler ["GetIn", {
	//hintC "1";
	switch (_this select 1) do {
		case "driver": {
			_this select 0 setVariable ["bgr_btr_hatch_driver", [0.5,_this select 2,(_this select 0 getVariable "bgr_btr_hatch_driver") select 2], false];
//			hintC format ["%1", _this select 0 getVariable "bgr_btr_hatch_driver"];
		};
		case "gunner": {
			if (abs((((_this select 0) worldToModel getPos (_this select 2)) select 1)-(((_this select 0) selectionPosition getText(configFile >> "CfgVehicles" >> typeOf (_this select 0) >> "memoryPointsGetInGunner")) select 1)) < 1) then {
				//_this select 0 setVariable ["bgr_btr_hatch_gunner", [0.5,_this select 2,(_this select 0 getVariable "bgr_btr_hatch_gunner") select 2], false];
				_this select 0 setVariable ["bgr_btr_hatch_cargo", [0.5,_this select 2,(_this select 0 getVariable "bgr_btr_hatch_cargo") select 2,(_this select 0 getVariable "bgr_btr_hatch_cargo") select 3,(_this select 0 getVariable "bgr_btr_hatch_cargo") select 4, _this select 1], false];
			} else {
				_this select 0 setVariable ["bgr_btr_hatch_commander", [0.5,_this select 2,(_this select 0 getVariable "bgr_btr_hatch_commander") select 2], false];
			};
		};
		case "commander": {
			_this select 0 setVariable ["bgr_btr_hatch_commander", [0.5,_this select 2,(_this select 0 getVariable "bgr_btr_hatch_commander") select 2], false];
		};
		case "cargo": {
			_this select 0 setVariable ["bgr_btr_hatch_cargo", [0.5,_this select 2,(_this select 0 getVariable "bgr_btr_hatch_cargo") select 2,(_this select 0 getVariable "bgr_btr_hatch_cargo") select 3,(_this select 0 getVariable "bgr_btr_hatch_cargo") select 4, _this select 1], false];
		};
		default {
			_this select 0 setVariable ["bgr_btr_hatch_commander", [0.5,_this select 2,(_this select 0 getVariable "bgr_btr_hatch_commander") select 2], false];
		};
	};
}];
_bgr_btr_out = _btr addEventHandler ["GetOut", {
//	hintC "1"; memoryPointsGetInCargo
//	hintC format ["%1", _this];
	switch (_this select 1) do {
		case "driver": {
			_this select 0 setVariable ["bgr_btr_hatch_driver", [0.4,_this select 2,(_this select 0 getVariable "bgr_btr_hatch_driver") select 2], false];
		};
		case "gunner": {
			//hintC format ["%1 %2",((_this select 0) worldToModel getPos (_this select 2)) select 1, ((_this select 0) selectionPosition getText(configFile >> "CfgVehicles" >> typeOf (_this select 0) >> "memoryPointsGetInGunner")) select 1];
			if (abs((((_this select 0) worldToModel getPos (_this select 2)) select 1)-(((_this select 0) selectionPosition getText(configFile >> "CfgVehicles" >> typeOf (_this select 0) >> "memoryPointsGetInGunner")) select 1)) < 1) then {
				//_this select 0 setVariable ["bgr_btr_hatch_gunner", [0.4,_this select 2,(_this select 0 getVariable "bgr_btr_hatch_gunner") select 2], false];
				_this select 0 setVariable ["bgr_btr_hatch_cargo", [0.4,_this select 2,(_this select 0 getVariable "bgr_btr_hatch_cargo") select 2,(_this select 0 getVariable "bgr_btr_hatch_cargo") select 3,(_this select 0 getVariable "bgr_btr_hatch_cargo") select 4, _this select 1], false];
			} else {
				_this select 0 setVariable ["bgr_btr_hatch_commander", [0.4,_this select 2,(_this select 0 getVariable "bgr_btr_hatch_commander") select 2], false];
			};
		};
		case "commander": {
			_this select 0 setVariable ["bgr_btr_hatch_commander", [0.4,_this select 2,(_this select 0 getVariable "bgr_btr_hatch_commander") select 2], false];
		};
		case "cargo": {
			_this select 0 setVariable ["bgr_btr_hatch_cargo", [0.4,_this select 2,(_this select 0 getVariable "bgr_btr_hatch_cargo") select 2,(_this select 0 getVariable "bgr_btr_hatch_cargo") select 3,(_this select 0 getVariable "bgr_btr_hatch_cargo") select 4, _this select 1], false];
		};
		default {
			_this select 0 setVariable ["bgr_btr_hatch_commander", [0.4,_this select 2,(_this select 0 getVariable "bgr_btr_hatch_commander") select 2], false];
		};
	};
}];

if (!isServer) exitWith {};


while {(alive _btr)} do {
	if (((_btr getVariable "bgr_btr_hatch_driver") select 0 >0)and((_btr getVariable "bgr_btr_hatch_driver") select 2 == 0)) then {
		if ((_btr getVariable "bgr_btr_hatch_driver") select 0 ==0.5) then {
			//getin
			[_btr,(_btr getVariable "bgr_btr_hatch_driver") select 1] spawn {
				_this select 0 setVariable ["bgr_btr_hatch_driver", [0,0,1], true];
				_this select 1 setVariable ["bgr_btr70_passanger", _this select 0, true];
				
				//svi cleanup - moveout_getinhigh
				[QUOTE(GVAR(moveOut_getinhigh)), [_this select 1, 'driverHatch',1]] call CBA_fnc_globalEvent;
				
				sleep 3.5;
				
				//svi cleanup - moveInDriver
				[QUOTE(GVAR(moveInDriver)), [_this select 1, 'driverHatch',0]] call CBA_fnc_globalEvent;
				
				_this select 0 setVariable ["bgr_btr_hatch_driver", [0,0,0], true];
			};
		} else {
			//getout
			[_btr,(_btr getVariable "bgr_btr_hatch_driver") select 1] spawn {
				_this select 0 setVariable ["bgr_btr_hatch_driver", [0,0,2], true];
				_this select 1 setVariable ["bgr_btr70_passanger", _this select 0, true];
				
				//svi cleanup - moveInDriver
				[QUOTE(GVAR(moveInDriver)), [_this select 1, "driverHatch", 1]] call CBA_fnc_globalEvent;
				
				sleep 2;
				
				//svi cleanup - moveout
				[QUOTE(GVAR(moveOut)), [_this select 1, "driverHatch", 0]] call CBA_fnc_globalEvent;
				
				_this select 0 setVariable ["bgr_btr_hatch_driver", [0,0,0], true];
			};
		};
		_btr setVariable ["bgr_btr_hatch_driver", [0,0,(_btr getVariable "bgr_btr_hatch_driver") select 2], true];
	};
	if (((_btr getVariable "bgr_btr_hatch_gunner") select 0 >0)and((_btr getVariable "bgr_btr_hatch_gunner") select 2 == 0)) then {
		if ((_btr getVariable "bgr_btr_hatch_gunner") select 0 ==0.5) then {
			//getin
			[_btr,(_btr getVariable "bgr_btr_hatch_gunner") select 1] spawn {
				_this select 0 setVariable ["bgr_btr_hatch_gunner", [0,0,1], true];
				_this select 1 setVariable ["bgr_btr70_passanger", _this select 0, true];
				
				//svi cleanup - moveout
				[QUOTE(GVAR(moveOut_getinhigh)), [_this select 1, 't_door_1', 1]] call CBA_fnc_globalEvent;
				
				sleep 3.5;
				
				//svi cleanup - moveInGunner
				[QUOTE(GVAR(moveInGunner)), [_this select 1, "t_door_1", 0]] call CBA_fnc_globalEvent;
				
				_this select 0 setVariable ["bgr_btr_hatch_gunner", [0,0,0], true];
			};
			//(_car modelToWorld (_car selectionPosition getText(_config >> "memoryPointsGetInDriver")));
		} else {
			//getout
			[_btr,(_btr getVariable "bgr_btr_hatch_gunner") select 1] spawn {
				_this select 0 setVariable ["bgr_btr_hatch_gunner", [0,0,2], true];
				_this select 1 setVariable ["bgr_btr70_passanger", _this select 0, true];
				
				//svi cleanup - moveInGunner
				[QUOTE(GVAR(moveInGunner)), [_this select 1, "t_door_1", 1]] call CBA_fnc_globalEvent;
				sleep 2;

				//svi cleanup - moveout
				[QUOTE(GVAR(moveOut)), [_this select 1, 't_door_1', 0]] call CBA_fnc_globalEvent;
				
				_this select 0 setVariable ["bgr_btr_hatch_gunner", [0,0,0], true];
			};
		};
		_btr setVariable ["bgr_btr_hatch_gunner", [0,0,(_btr getVariable "bgr_btr_hatch_gunner") select 2], true];
	};
	if (((_btr getVariable "bgr_btr_hatch_commander") select 0 >0)and((_btr getVariable "bgr_btr_hatch_commander") select 2 == 0)) then {
		if ((_btr getVariable "bgr_btr_hatch_commander") select 0 ==0.5) then {
			//getin
			[_btr,(_btr getVariable "bgr_btr_hatch_commander") select 1] spawn {
				_this select 0 setVariable ["bgr_btr_hatch_commander", [0,0,1], true];
				_this select 1 setVariable ["bgr_btr70_passanger", _this select 0, true];

				//svi cleanup - moveout_getinhigh
				[QUOTE(GVAR(moveOut_getinhigh)), [_this select 1, 'commanderHatch', 1]] call CBA_fnc_globalEvent;
				sleep 3.5;
				
				//svi cleanup - moveInTurret
				[QUOTE(GVAR(moveInTurret)), [_this select 1, 'commanderHatch', 0]] call CBA_fnc_globalEvent;

				_this select 0 setVariable ["bgr_btr_hatch_commander", [0,0,0], true];
			};
			//(_car modelToWorld (_car selectionPosition getText(_config >> "memoryPointsGetInDriver")));
		} else {
			//getout
			[_btr,(_btr getVariable "bgr_btr_hatch_commander") select 1] spawn {
				_this select 0 setVariable ["bgr_btr_hatch_commander", [0,0,2], true];
				_this select 1 setVariable ["bgr_btr70_passanger", _this select 0, true];
				
				//svi cleanup - moveInTurret
				[QUOTE(GVAR(moveInTurret)), [_this select 1, 'commanderHatch', 1]] call CBA_fnc_globalEvent;
				
				sleep 2;

				//svi cleanup - moveout
				[QUOTE(GVAR(moveOut)), [_this select 1, 'commanderHatch', 0]] call CBA_fnc_globalEvent;
				
				_this select 0 setVariable ["bgr_btr_hatch_commander", [0,0,0], true];
			};
		};
		_btr setVariable ["bgr_btr_hatch_commander", [0,0,(_btr getVariable "bgr_btr_hatch_commander") select 2], true];
	};
	if ((_btr getVariable "bgr_btr_hatch_cargo") select 0 >0) then {
		if ((((speed _btr <= 10)or(!surfaceIsWater [(getposASL _btr select 0), (getposASL _btr select 1)]))and(_btr animationPhase "l_door" == 1)and(_btr animationPhase "r_door" == 1))or(((speed _btr > 10)or(surfaceIsWater [(getposASL _btr select 0), (getposASL _btr select 1)]))and(_btr animationPhase "t_door_1" == 1))) then {
			//люки открыты
		} else {
			if ((_btr getVariable "bgr_btr_hatch_cargo") select 0 ==0.5) then {
				//getin
				if ((speed _btr > 10)or(surfaceIsWater [(getposASL _btr select 0), (getposASL _btr select 1)])) then {
					//верхний люк
					if ((_btr getVariable "bgr_btr_hatch_cargo") select 2 == 0) then {
						[_btr,(_btr getVariable "bgr_btr_hatch_cargo") select 1,(_btr getVariable "bgr_btr_hatch_cargo") select 5] spawn {
							_this select 0 setVariable ["bgr_btr_hatch_cargo", [0,0,1,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 3,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 4,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 5], true];
							_this select 1 setVariable ["bgr_btr70_passanger", _this select 0, true];

							//svi cleanup - moveOut_getinlow
							[QUOTE(GVAR(moveOut_getinlow)), [_this select 1, 't_door_1', 1]] call CBA_fnc_globalEvent;
							
							sleep 3.5;
							if (_this select 2 == "gunner") then {
								//svi cleanup - moveInGunner_only
								[QUOTE(GVAR(moveInGunner_only)), [_this select 1]] call CBA_fnc_globalEvent;
							} else {
								//svi cleanup - moveInCargo_only
								[QUOTE(GVAR(moveInCargo_only)), [_this select 1]] call CBA_fnc_globalEvent;
							};
							_this select 0 setVariable ["bgr_btr_hatch_cargo", [0,0,0,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 3,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 4,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 5], true];
						};
					};
				} else {
					//нижние люки
					if (((_btr getVariable "bgr_btr_hatch_cargo") select 3 == 0)or((_btr getVariable "bgr_btr_hatch_cargo") select 4 == 0)) then {
						[_btr,(_btr getVariable "bgr_btr_hatch_cargo") select 1,(_btr getVariable "bgr_btr_hatch_cargo") select 5] spawn {
							//svi cleanup - moveOut_only
							[QUOTE(GVAR(moveOut_only)), [_this select 1]] call CBA_fnc_globalEvent;
							
							if (((_this select 0) worldToModel getPosASL (_this select 1)) select 0 < 0) then {
								//left
								if ((_this select 0 getVariable "bgr_btr_hatch_cargo") select 3 == 0) then {
									_this select 0 setVariable ["bgr_btr_hatch_cargo", [0,0,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 2,1,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 4,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 5], true];
									_this select 1 setVariable ["bgr_btr70_passanger", _this select 0, true];

									//svi cleanup - play_getinhigh
									[QUOTE(GVAR(play_getinhigh)), [_this select 1, 'l_door',1]] call CBA_fnc_globalEvent;
									
									sleep 1.5;
									if (_this select 2 == "gunner") then {
										//svi cleanup - moveInGunner_only
										[QUOTE(GVAR(moveInGunner_only)), [_this select 1]] call CBA_fnc_globalEvent;
										
									}else{
										//svi cleanup - moveInCargo_only
										[QUOTE(GVAR(moveInCargo_only)), [_this select 1]] call CBA_fnc_globalEvent;
										
									};
									_this select 0 setVariable ["bgr_btr_hatch_cargo", [0,0,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 2,0,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 4,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 5], true];
								};
							} else {
								//right
								if ((_this select 0 getVariable "bgr_btr_hatch_cargo") select 4 == 0) then {
									_this select 0 setVariable ["bgr_btr_hatch_cargo", [0,0,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 2,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 3,1,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 5], true];
									_this select 1 setVariable ["bgr_btr70_passanger", _this select 0, true];
									
								//svi cleanup - play_getinhigh
								[QUOTE(GVAR(play_getinhigh)), [_this select 1, 'r_door',1]] call CBA_fnc_globalEvent;
				
									sleep 1.5;
									if (_this select 2 == "gunner") then {
										//svi cleanup - moveInGunner_only
										[QUOTE(GVAR(moveInGunner_only)), [_this select 1]] call CBA_fnc_globalEvent;
										
									}else{
										//svi cleanup - moveInCargo_only
										[QUOTE(GVAR(moveInCargo_only)), [_this select 1]] call CBA_fnc_globalEvent;
										
									};

									_this select 0 setVariable ["bgr_btr_hatch_cargo", [0,0,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 2,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 3,0,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 5], true];
								};
							};
						};	//end spawn
					};
				};
			} else {
				//getout
				if ((speed _btr > 10)or(surfaceIsWater [(getposASL _btr select 0), (getposASL _btr select 1)])) then {
					//верхний люк
					if ((_btr getVariable "bgr_btr_hatch_cargo") select 2 == 0) then {
						[_btr,(_btr getVariable "bgr_btr_hatch_cargo") select 1,(_btr getVariable "bgr_btr_hatch_cargo") select 5] spawn {
							_this select 0 setVariable ["bgr_btr_hatch_cargo", [0,0,2,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 3,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 4,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 5], true];
							_this select 1 setVariable ["bgr_btr70_passanger", _this select 0, true];
							if (_this select 2 == "gunner") then {
								//svi cleanup - moveInGunner
								[QUOTE(GVAR(moveInGunner)), [_this select 1, 't_door_1',1]] call CBA_fnc_globalEvent;
								";
							} else {
								//svi cleanup - moveInCargo
								[QUOTE(GVAR(moveInCargo)), [_this select 1, 't_door_1', 1]] call CBA_fnc_globalEvent;
							};
							sleep 2;
							//svi cleanup - moveOut_only
							[QUOTE(GVAR(moveOut_only)), [_this select 1]] call CBA_fnc_globalEvent;
							
							_this select 0 setVariable ["bgr_btr_hatch_cargo", [0,0,0,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 3,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 4,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 5], true];
						};
					};
				} else {
					//нижние люки
					if (((_btr getVariable "bgr_btr_hatch_cargo") select 3 == 0)or((_btr getVariable "bgr_btr_hatch_cargo") select 4 == 0)) then {
						[_btr,(_btr getVariable "bgr_btr_hatch_cargo") select 1,(_btr getVariable "bgr_btr_hatch_cargo") select 5] spawn {
							if (_this select 2 == "gunner") then {
								//svi cleanup - moveInGunner_only
								[QUOTE(GVAR(moveInGunner_only)), [_this select 1]] call CBA_fnc_globalEvent;
								
							}else{
								//svi cleanup - moveInCargo_only
								[QUOTE(GVAR(moveInCargo_only)), [_this select 1]] call CBA_fnc_globalEvent;
								
							};
							if (((_this select 0) worldToModel getPosASL (_this select 1)) select 0 < 0) then {
								//left
								if ((_this select 0 getVariable "bgr_btr_hatch_cargo") select 3 == 0) then {
									_this select 0 setVariable ["bgr_btr_hatch_cargo", [0,0,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 2,2,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 4,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 5], true];
									_this select 1 setVariable ["bgr_btr70_passanger", _this select 0, true];
									//svi cleanup - BTR_Animate
									[QUOTE(GVAR(BTR_Animate)), [_this select 1, "l_door", 1]] call CBA_fnc_globalEvent;
									
									sleep 1.5;
									//svi cleanup - moveOut_only
									[QUOTE(GVAR(moveOut_only)), [_this select 1]] call CBA_fnc_globalEvent;
									
									_this select 0 setVariable ["bgr_btr_hatch_cargo", [0,0,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 2,0,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 4,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 5], true];
								};
							} else {
								//right
								if ((_this select 0 getVariable "bgr_btr_hatch_cargo") select 4 == 0) then {
									_this select 0 setVariable ["bgr_btr_hatch_cargo", [0,0,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 2,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 3,2,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 5], true];
									_this select 1 setVariable ["bgr_btr70_passanger", _this select 0, true];
									//svi cleanup - BTR_Animate
									[QUOTE(GVAR(BTR_Animate)), [_this select 1, "r_door", 1]] call CBA_fnc_globalEvent;
									
									sleep 1.5;
									//svi cleanup - moveOut_only
									[QUOTE(GVAR(moveOut_only)), [_this select 1]] call CBA_fnc_globalEvent;
									
									_this select 0 setVariable ["bgr_btr_hatch_cargo", [0,0,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 2,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 3,0,((_this select 0) getVariable "bgr_btr_hatch_cargo") select 5], true];
								};
							};
						};	//end spawn
					};
				};
			};
		};
		_btr setVariable ["bgr_btr_hatch_cargo", [0,0,(_btr getVariable "bgr_btr_hatch_cargo") select 2,(_btr getVariable "bgr_btr_hatch_cargo") select 3,(_btr getVariable "bgr_btr_hatch_cargo") select 4,(_btr getVariable "bgr_btr_hatch_cargo") select 5], true];
	};

};