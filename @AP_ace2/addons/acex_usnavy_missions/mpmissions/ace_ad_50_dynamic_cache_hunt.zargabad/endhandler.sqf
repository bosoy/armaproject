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
}
else
{
	[] spawn
	{
		waitUntil {!isNil "scoreW"};
		waitUntil {scoreW==maxScore};
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
		waitUntil {!isNil "scoreE"};
		waitUntil {scoreE==maxScore};
		end2=true;
		publicVariable "end2";
		if (dialog) then
		{
			closeDialog 0;
		};
		sleep 5;
		endMission "END2";
	};
};