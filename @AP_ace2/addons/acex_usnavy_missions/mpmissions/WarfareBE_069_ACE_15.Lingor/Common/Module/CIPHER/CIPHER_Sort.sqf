/* Elements to sort etc ... */

_preformat = {
	Private ["_get","_output","_units"];
	_units = _this;
	_output = [];

	for '_i' from 0 to count(_units)-1 do {
		_get = (_units select _i) Call GetNamespace;
		if !(isNil "_get") then {
			_output set [_i, _get select QUERYUNITLABEL];
		} else {
			_output set [_i, (_units select _i)];
		};
	};
	
	_output
};

_preformat_gear = {
	Private ["_content","_get","_output"];
	_content = _this;
	_output = [];

	for '_i' from 0 to count(_content)-1 do {
		_get = (_content select _i) Call GetNamespace;
		if !(isNil "_get") then {
			_output set [_i, _get select QUERYGEARLABEL];
		} else {
			_output set [_i, (_content select _i)];
		};
	};
	
	_output
};

//--- Sort Factions.
{
	_content = Format["WFBE_%1%2FACTIONS",sideJoinedText,_x] Call GetNamespace;
	_sorted = ([_content, false] Call CIPHER_SortArray) select 0;
	[Format['WFBE_%1%2FACTIONS',sideJoinedText,_x], _sorted, true] Call SetNamespace;
	
	//--- While we're at it we set the default selected faction.
	_content = Format["WFBE_%1%2FACTIONS",sideJoinedText,_x] Call GetNamespace;
	_find = _content find (Format["WFBE_%1DEFAULTFACTION",sideJoinedText] Call GetNamespace);
	if (_find != -1) then {
		[Format["WFBE_%1%2CURRENTFACTIONSELECTED",sideJoinedText,_x], _find] Call SetNamespace;
	};
} forEach ["BARRACKS","LIGHT","HEAVY","AIRCRAFT","AIRPORT","DEPOT"];

//--- Sort Purchases (Default, name - asc).
{
	_content = Format['WFBE_%1%2UNITS',sideJoinedText,_x] Call GetNamespace;
	_sorted = ([(_content) Call _preformat,false,_content] Call CIPHER_SortArray) select 1;
	[Format['WFBE_%1%2UNITS',sideJoinedText,_x], _sorted, true] Call SetNamespace;
} forEach ["BARRACKS","LIGHT","HEAVY","AIRCRAFT","AIRPORT","DEPOT"];

//--- Sort Gear.
{
	_content = WF_Logic getVariable Format ["%1Classes",_x];
	_sorted = ([(_content) Call _preformat_gear,false,_content] Call CIPHER_SortArray) select 1;
	WF_Logic setVariable [Format ["%1Classes",_x], _sorted];
} forEach ["primary","secondary","sidearm","misc"];