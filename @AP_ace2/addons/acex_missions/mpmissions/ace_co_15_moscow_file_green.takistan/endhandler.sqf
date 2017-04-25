if (!isServer) then
{
	"end1" addPublicVariableEventHandler
	{
		if (dialog) then
		{
			closeDialog 0;
		};
		endMission "END1";
	};
	
	"end2" addPublicVariableEventHandler
	{
		if (dialog) then
		{
			closeDialog 0;
		};
		endMission "END2";
	};
	
	"end3" addPublicVariableEventHandler
	{
		if (dialog) then
		{
			closeDialog 0;
		};
		endMission "END3";
	};
}
else
{
	minIndCount = indCount/2;
	[] spawn
	{
		waitUntil
		{
			_end1=false;
			if (bExtracted) then
			{
				{
					if (_x hasWeapon "Moscow_Bombing_File") then
					{
						_end1=true;
					};
				} forEach indUnits;
			};
			(_end1 && {alive _x && !(captive _x)} count indUnits >= minIndCount)
		};
		end1=true;
		publicVariable "end1";
		if (dialog) then
		{
			closeDialog 0;
		};
		sleep 5;
		endMission "END1";
	};
	[] spawn
	{
		waitUntil {{alive _x} count indUnits < minIndCount};
		end2=true;
		publicVariable "end2";
		if (dialog) then
		{
			closeDialog 0;
		};
		sleep 5;
		endMission "END2";
	};
	[] spawn
	{
		_endTime = time + 45 * 60;
		waitUntil {time>_endTime};
		end3=true;
		publicVariable "end3";
		if (dialog) then
		{
			closeDialog 0;
		};
		sleep 5;
		endMission "END3";
	};
};