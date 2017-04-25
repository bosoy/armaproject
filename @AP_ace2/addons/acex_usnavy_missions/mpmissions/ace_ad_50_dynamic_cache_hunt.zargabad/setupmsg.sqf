private ["_roundStartTime"];
_roundStartTime = _this select 0;
{
	if (_roundStartTime-time>_x) then
	{
		waitUntil {_roundStartTime-time<_x};
		titleText [format ["%1 seconds until round starts", _x], "PLAIN"];
		sleep 2.5;
		titleFadeOut 1.5;
	};
} forEach [45, 30, 20, 15, 10, 5];