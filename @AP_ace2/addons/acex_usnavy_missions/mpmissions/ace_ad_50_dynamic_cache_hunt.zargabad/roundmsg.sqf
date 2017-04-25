private ["_str1", "_str2", "_str3", "_nextStartTime"];

_nextStartTime = time+setupTime;

switch (roundEnd) do
{
	case 1:
	{
		_str1 = "Takistanis win, US forces eliminated.";
	};
	
	case 2:
	{
		_str1 = "US wins, Takistanis eliminated.";
	};

	case 3:
	{
		_str1 = "US wins, ammo caches destroyed.";
	};
	
	case 4:
	{
		_str1 = "Takistanis win, US forces ran out of time.";
	};
};

_str2 = format ["Score %1:%2 US:TK.", scoreW, scoreE];

if (scoreW<maxScore && scoreE<maxScore) then
{
	_str3 = format ["Next round starts in %1 seconds", setupTime];
}
else
{
	_str3 = "Game Over!";
};

titleText [format ["%1 %2 %3", _str1, _str2, _str3], "PLAIN"];
sleep 6;
titleFadeOut 2;

[_nextStartTime] execVM "setupmsg.sqf";