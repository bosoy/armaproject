Private ["_buildings","_closest","_defense","_direction","_distance","_index","_position","_side","_soldier","_team","_type","_unit"];
_defense = _this select 0;
_side = _this select 1;
_team = _this select 2;
_closest = _this select 3;

while {alive _defense} do {
	if (isNull(gunner _defense) || !alive gunner _defense) then {
	
		sleep 7;
		
		if (alive _closest && !(isNull _closest )) then {
			_type = typeOf _closest;
			_index = (Format["WFBE_%1STRUCTURENAMES",str _side] Call GetNamespace) find _type;
			_distance = (Format["WFBE_%1STRUCTUREDISTANCES",str _side] Call GetNamespace) select _index;
			_direction = (Format["WFBE_%1STRUCTUREDIRECTIONS",str _side] Call GetNamespace) select _index;
			_position = [getPos _closest,_distance,getDir (_closest) + _direction] Call GetPositionFrom;
			
			_type = Format ["WFBE_%1SOLDIER",str _side] Call GetNamespace;
			_soldier = [_type,_team,_position,_side] Call CreateMan;
			[_soldier] allowGetIn true;
			_soldier assignAsGunner _defense;
			[_soldier] orderGetIn true;
			
			[str _side,'UnitsCreated',1] Call UpdateStatistics;
			
			diag_log Format["[WFBE (INFORMATION)][frameno:%3 | ticktime:%4] Server_HandleDefense: A Soldier has been dispatched to the %1 defense %2",str _side,_type,diag_frameno,diag_tickTime];
			
			//--- Calculate the average time in function of the distance and the speed.
			sleep ((((_soldier distance _defense)/(14*1000))*3600)+20);
			
			if ((vehicle _soldier != _defense)&& alive _soldier &&(!isNull _soldier)) then {
				if ((_defense EmptyPositions "gunner" > 0) && alive _defense && (!isNull _defense)) then {_soldier MoveInGunner _defense} else {deleteVehicle _soldier};
			};
		} else {
			diag_log Format["[WFBE (INFORMATION)][frameno:%1 | ticktime:%2] Server_HandleDefense.sqf: Canceled auto manning, the barracks is destroyed.",diag_frameno,diag_tickTime];
		};
	};
	sleep 420;
};