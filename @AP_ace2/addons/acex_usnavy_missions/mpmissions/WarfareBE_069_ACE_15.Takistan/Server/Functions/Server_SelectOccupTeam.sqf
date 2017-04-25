private ["_difficulty","_probaOccupation","_oc1","_oc2","_oc3","_oc4","_oc5","_oc6","_ran1","_ran2","_supplyValue","_teams","_type","_x"];
_supplyValue = _this select 0;
_type = [];
_teams = [];

_oc1 = 'WFBE_OCCUPATIONTEAM1' Call GetNamespace;
_oc2 = 'WFBE_OCCUPATIONTEAM2' Call GetNamespace;
_oc3 = 'WFBE_OCCUPATIONTEAM3' Call GetNamespace;
_oc4 = 'WFBE_OCCUPATIONTEAM4' Call GetNamespace;
_oc5 = 'WFBE_OCCUPATIONTEAM5' Call GetNamespace;
_oc6 = 'WFBE_OCCUPATIONTEAM6' Call GetNamespace;

_probaOccupation = 75;
if ((_supplyValue >= _oc1)&&(_supplyValue < _oc2)) then {_type = ["SmallTeam"];_probaOccupation = 95};
if ((_supplyValue >= _oc2)&&(_supplyValue < _oc3)) then {_type = ["SmallTeam","SmallVehTeam"];_probaOccupation = 85};
if ((_supplyValue >= _oc3)&&(_supplyValue < _oc4)) then {_type = ["SmallTeam","MediumTeam","MediumVehTeam"];_probaOccupation = 80};
if ((_supplyValue >= _oc4)&&(_supplyValue < _oc5)) then {_type = ["SmallTeam","MediumTeam","LargeTeam","MediumVehTeam"];_probaOccupation = 75};
if ((_supplyValue >= _oc5)&&(_supplyValue < _oc6)) then {_type = ["SmallTeam","MediumTeam","LargeTeam","MediumVehTeam","LargeVehTeam"];_probaOccupation = 65};
if (_supplyValue >= _oc6) then {_type = ["SmallTeam","MediumTeam","LargeTeam","SmallVehTeam","MediumVehTeam","LargeVehTeam"];_probaOccupation = 60};

_difficulty = 'WFBE_TOWNOCCUPATIONDIFFICULTY' Call GetNamespace;
if (_difficulty == 5) then {
	if (diag_fps >= 35) then {_difficulty = 4};
	if (diag_fps >= 25 && diag_fps < 30) then {_difficulty = 3};
	if (diag_fps >= 15 && diag_fps < 25) then {_difficulty = 2};
	if (diag_fps < 15) then {_difficulty = 1};
};

for [{_z = 0},{_z <= _difficulty},{_z = _z + 1}] do {
	_ran1 = random 100;
	if (_ran1 < _probaOccupation) then {
		{_ran2 = round(1 + random 2);_teams = _teams + [Format ["%1%2",_x,_ran2]]} forEach _type;
	};
};

if (count _teams < 1) then {_teams = ["SmallTeam1"]};

_teams