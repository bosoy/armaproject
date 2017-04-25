/* 
	Author: Benny
	Name: Server_TrashObject.sqf
	Parameters:
	  0 - Object
	Description:
	  This function will remove an object after the defined amount of time.
*/

private ["_alive","_group","_isMan","_object","_get"];
_object = _this;

if !(isNull _object) then {
	_group = [];
	_isMan = if (_object isKindOf "Man") then {true} else {false};
	
	if (_isMan) then {_group = group _object};
	
	sleep ('WFBE_UNITREMOVEDLAY' Call GetNamespace);
	trashQueu = trashQueu - [_object];
	
	if (_isMan) then {hideBody _object; sleep 6};
	
	deleteVehicle _object;
	
	if (_isMan) then {
		if !(isNull _group) then {
			_get = _group getVariable 'queue';
			if (isNil '_get') then {
				if (count (units _group) <= 0) then {deleteGroup _group;};
			};
		};
	};
};