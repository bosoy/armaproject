Private ["_get","_position","_side","_skill","_team","_type","_unit"];
_type = _this select 0;
_team = _this select 1;
_position = _this select 2;
_side = _this select 3;

_get = _type Call GetNamespace;
_skill = if !(isNil '_get') then {_get select QUERYUNITSKILL} else {'WFBE_AISKILL' Call GetNamespace};
_unit = _team createUnit [_type,_position,[],0,"FORM"];
_unit setSkill _skill;
if (_side != resistance) then {
	if (paramTrackAI) then {
		_unit setVehicleInit Format["[this,%1] ExecVM 'Common\Common_InitUnit.sqf';",_side];
		processInitCommands;
	} else {
		if (isPlayer leader _team) then {[_unit,_side] ExecVM 'Common\Common_InitUnit.sqf'};
	};
	Call Compile Format ["_unit addEventHandler ['Killed',{[_this select 0,_this select 1,%1] Spawn UnitKilled}];",_side];
} else {
	//--- Note To be optimized, 1.03 BIS BUG, cannot add resistance side via call compile format.
	_unit addEventHandler ['Killed',{[_this select 0,_this select 1,resistance] Spawn UnitKilled}];
};

if (('WFBE_ISIS' Call GetNamespace) == 2) then {_unit addEventHandler['handleDamage',{_this Call ISIS_Wound}]};

diag_log Format["[WFBE (INFORMATION)][frameno:%5 | ticktime:%6] Common_CreateUnit: A '%1' unit was created (position: %2) and has joined the %3 %4 Team",_type,_position,str _side,_team,diag_frameno,diag_tickTime];

_unit