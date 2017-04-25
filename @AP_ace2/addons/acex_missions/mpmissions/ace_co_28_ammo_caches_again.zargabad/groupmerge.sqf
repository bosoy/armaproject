disableSerialization;

groupMergeMenu=false;
groupMergeGroups = [];
actionArray = [];

// Mike's function to remove the B from group names
groupMerge_fnc_properGroupName = 
{
	private ["_group", "_groupName", "_trimmedGroupName"];

	_group = _this select 0;
	_groupName = toArray(str(_group));
	_trimmedGroupName = [];

	for [ { _i = 2 }, { _i < count(_groupName) }, { _i = _i + 1 }] do
	{
		_trimmedGroupName set [count _trimmedGroupName, _groupName select _i];
	};

	toString(_trimmedGroupName)
};

// Function to create/remove join group action menu items
groupMerge_fnc_menu =
{
	groupMergeMenu = !groupMergeMenu;
	if (groupMergeMenu) then
	{
		groupMergeGroups = [];
		{
			_unit = _x;
			if (isPlayer _unit && (playerSide == side _unit) && (!(_unit in (units (group player))))) then
			{
				_addx = true;
				{
					if (_unit in (units _x)) then
					{
						_addx = false;
					};
				} forEach groupMergeGroups;
				if (_addx) then
				{
					groupMergeGroups set [count groupMergeGroups, group _unit];
				};
			};
		} forEach allUnits;
		{
			_action = player addAction [format ["Join %1", [_x] call groupMerge_fnc_properGroupName], "groupmergeaction.sqf", [_x]];
			actionArray set [count actionArray, _action];
		} forEach groupMergeGroups;
		hint "Choose group to join in action menu or press the teamswitch key again to cancel";
	}
	else
	{
		{player removeAction _x} forEach actionArray;
		actionArray=[];
	};
};

// function to handle key press to detect player hitting the "team switch" button
groupMerge_fnc_key =
{
	private['_handled'];
	_handled = false;
	_key = _this select 1;
	if (_key in (actionKeys 'TeamSwitch')) then
	{
		_handled=true;
		call groupMerge_fnc_menu;
	};
	_handled;
};

// create key eventhandler
waitUntil {!isNull (findDisplay 46)};
(findDisplay 46) displayAddEventHandler ["KeyDown", "call groupMerge_fnc_key"];