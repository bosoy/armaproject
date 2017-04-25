for [{_loop=0}, {_loop<1}, {_loop=_loop}] do
{
	if (!x_with_revive) then {
		waitUntil {vehicle player in list rainy or vehicle player in list rainy2 or vehicle player in list rainy3};
	} else {
		_do_loop = true;
		while {_do_loop} do {
			if (!p_uncon) then {
				if (vehicle player in list rainy or vehicle player in list rainy2 or vehicle player in list rainy3) then {
					_do_loop = false;
				};
			} else {
				if (unconscious_body in list rainy or unconscious_body in list rainy2 or unconscious_body in list rainy3) then {
					_do_loop = false;
				};
			};
			sleep 0.321;
		};
	};
	2 setRain 1.0;
	if ((speed vehicle player) > 100) then
	{
		10 setOvercast 1.0;
	}
	else
	{
		if ((speed vehicle player) > 25) then
		{
			20 setOvercast 1.0;
		}
		else
		{
			if ((speed vehicle player) < 25) then
			{
				30 setOvercast 1.0;
			};
		};
	};
	if (!x_with_revive) then {
		waitUntil {not (vehicle player in list rainy or vehicle player in list rainy2 or vehicle player in list rainy3) or not alive player};
	} else {
		_do_loop = true;
		while {_do_loop} do {
			if (!p_uncon) then {
				if (not (vehicle player in list rainy or vehicle player in list rainy2 or vehicle player in list rainy3) or not alive player) then {
					_do_loop = false;
				};
			} else {
				if (not (unconscious_body in list rainy or unconscious_body in list rainy2 or unconscious_body in list rainy3) or isNull unconscious_body) then {
					_do_loop = false;
				};
			};
			sleep 0.221;
		};
	};
	if (not alive player) then
	{
		10 setOvercast 0.0;
	}
	else
	{
		if ((speed vehicle player) > 100 or not alive player) then
		{
			10 setOvercast 0.0;
		}
		else
		{
			if ((speed vehicle player) > 25) then
			{
				20 setOvercast 0.0;
			}
			else
			{
				if ((speed vehicle player) < 25) then
				{
					30 setOvercast 0.0;
				};
			};
		};
	};
	2 setRain 0.0;
	sleep 1.0;
};		