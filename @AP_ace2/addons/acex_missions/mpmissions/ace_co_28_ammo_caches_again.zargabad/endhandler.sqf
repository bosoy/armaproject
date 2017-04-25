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
	
	"end4" addPublicVariableEventHandler
	{
		if (dialog) then
		{
			closeDialog 0;
		};
		endMission "END4";
	};
}
else
{
	minBlueforCount = blueforCount/2;
	[] spawn
	{
		waitUntil {getDammage obj1 > 0.999 && getDammage obj2 > 0.999};
		sleep 3;
		if ({alive _x} count blueforUnits < minBlueforCount) exitWith {};
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
		waitUntil {{alive _x} count blueforUnits < minBlueforCount};
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
	[] spawn
	{
		waitUntil {deadCivCount>1};
		end4=true;
		publicVariable "end4";
		if (dialog) then
		{
			closeDialog 0;
		};
		sleep 5;
		endMission "END4";
	};
};