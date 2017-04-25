/*
Created by Vadim Shchemelinin aka badger
2010 St.Petersburg

Init:
HANDLE = this addeventhandler ["HandleDamage",{[_this,_time,_delta,_maxdemag,_mindemag] execVM "bgr_podkachka.sqf"; _this select 2;} ];

example fot ural:
HANDLE2 = this addeventhandler ["HandleDamage",{[_this,0.5,0.025,0.8,0.2] execVM "bgr_podkachka.sqf"; _this select 2;} ];

example for btr-90:
HANDLE = this addeventhandler ["HandleDamage",{[_this,0.5,0.002,0.9,0.2] execVM "bgr_podkachka.sqf"; _this select 2;} ];

_unit: Object - Object the event handler is assigned to.
_selectionName: String - Name of the selection where the unit was damaged. "" for over-all structural damage, "?" for unknown selections.
_damage: Number - Resulting level of damage for the selection.
_source: Object - The source unit that caused the damage.
_projectile: String - Classname of the projectile that caused inflicted the damage. ("" for unknown, such as falling damage.)
*/

if !(rhs_activeTirePressure) exitWith {};

_mas = _this select 0;
_unit = _mas select 0;
_selectionName = _mas select 1;
//hint format ["%1",_selectionName];
_damage = _mas select 2;
_source = _mas select 3;
_projectile = _mas select 4;
_time = _this select 1;
_delta = _this select 2;
_maxdemag = _this select 3;
_mindemag = _this select 4;

//for BIS vehicle:
_selectionsArray = ["wheel_1_1_steering","wheel_2_1_steering","wheel_1_2_steering","wheel_2_2_steering","wheel_1_3_steering","wheel_2_3_steering","wheel_1_4_steering","wheel_2_4_steering"];
_animsArray = ["wheel_1_1_destruct","wheel_2_1_destruct","wheel_1_2_destruct","wheel_2_2_destruct","wheel_1_3_destruct","wheel_2_3_destruct","wheel_1_4_destruct","wheel_2_4_destruct"];
//for RHS BTR70:
if (_unit isKindOf "ace_btr70_base") then {
_selectionsArray = ["wheel_1_1_steering","wheel_2_1_steering","wheel_1_2_steering","wheel_2_2_steering","wheel_1_3_steering","wheel_2_3_steering","wheel_1_4_steering","wheel_2_4_steering"];
_animsArray = ["wheel_1_1_destruct","wheel_2_1_destruct","wheel_1_2_destruct","wheel_2_2_destruct","wheel_1_3_destruct","wheel_2_3_destruct","wheel_1_4_destruct","wheel_2_4_destruct"];
};

_Nkolesa = _selectionsArray find _selectionName;
_caliber = 0;

if (rhs_TypeTirePressure == 1) then {
	if (_projectile == "") then {
		_caliber = 0.5;
	} else {	//if falling damage
		if (_projectile isKindOf "BulletBase") then {
			_caliber = getNumber (configFile >> "CfgAmmo" >> _projectile >> "caliber");
			//hintC format ["b2 %1",_caliber];
		} else { //if not bullet
			_caliber = 100;
		};
	};
} else {
	sleep _time;
};

if ((_Nkolesa > -1) and (_caliber < 2)) then {
	_kolesoproverkadam = _unit animationPhase (_animsArray select _Nkolesa);
	while {(_kolesoproverkadam > _mindemag) and  (_kolesoproverkadam < _maxdemag) and  (damage _unit < 1)} do {
			waitUntil {isEngineOn _unit};
			_kolesoproverkadam = _unit animationPhase (_animsArray select _Nkolesa);
			_Ddammage = _kolesoproverkadam;
			if (_kolesoproverkadam < _maxdemag) then {_Ddammage = _kolesoproverkadam - _delta};
			if (_Ddammage < _mindemag) then {_Ddammage = _mindemag};
			_unit setHit [_selectionName, _Ddammage];
			sleep _time;
    };
};

