// updates flag colors for client
// first parameter: flag to update

private ["_flagNumber", "_currentSide", "_eastControl", "_westControl"];

_flagNumber = _this select 0;
_currentSide = 0;

_eastControl =
{
	[_flagNumber, "East"] execVM "controlMessage.sqf";
	call compile format ["""flag%1"" setMarkerColor ""ColorRed""", _flagNumber+1];
	//call compile format ["objFlag%1 setFlagTexture ""\ca\data\Flag_rus_co.paa""", _flagNumber+1];
	_currentSide=-1;
	playSound "buzzer";
};

_westControl =
{
	[_flagNumber, "West"] execVM "controlMessage.sqf";
	call compile format ["""flag%1"" setMarkerColor ""ColorBlue""", _flagNumber+1];
	//call compile format ["objFlag%1 setFlagTexture ""\ca\data\Flag_usa_co.paa""", _flagNumber+1];
	_currentSide=1;
	playSound "buzzer";
};


// wait until flag control changes and update the flag
while {true} do
{
	waitUntil {_currentSide != (flags select _flagNumber)};
	if ((flags select _flagNumber)==1) then
	{
		call _westControl;
	}
	else
	{
		call _eastControl;
	};
};