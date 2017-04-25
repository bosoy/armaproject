sideWeapons = 2;
weaponTypes = 5;
explosives = 5;
launchers = 3;
sfweapons = 2;
nightVision=2;
nightSights = 2;
futureWeapons = 1;
scopes=1;
caliber=7;
csw=2;
hiCapMags=2;
lessThanLethal=1;
huntIR=1;

nightOrDay=0;
loadouts = 0;
maxScore=7;
setupTime=60;
timeLimit = 120;
lastPlayersCountdown=30;

if (!isNil "paramsArray") then
{
	for [{_i = 0}, {_i < count(paramsArray)}, {_i = _i + 1 }] do
	{
		switch (configName ((missionConfigFile >> "Params") select _i)) do
		{
			case "SideWeapons":
			{
				sideWeapons = (paramsArray select _i);
			};
			case "WeaponTypes":
			{
				weaponTypes = (paramsArray select _i);
			};
			case "Explosives":
			{
				explosives = (paramsArray select _i);
			};
			case "Launchers":
			{
				launchers = (paramsArray select _i);
			};
			case "SFweapons":
			{
				sfweapons = (paramsArray select _i);
			};
			case "NightVision":
			{
				nightVision = (paramsArray select _i);
			};
			case "NightSights":
			{
				nightSights = (paramsArray select _i);
			};
			case "FutureWeapons":
			{
				futureWeapons = (paramsArray select _i);
			};
			case "Scopes":
			{
				scopes = (paramsArray select _i);
			};
			case "Caliber":
			{
				caliber = (paramsArray select _i);
			};
			case "CSW":
			{
				csw = (paramsArray select _i);
			};
			case "HiCapMags":
			{
				hiCapMags = (paramsArray select _i);
			};
			case "Nightorday":
			{
				nightOrDay = (paramsArray select _i);
			};
			case "NightVision":
			{
				nightVision = (paramsArray select _i);
			};	
			case "Loadouts":
			{
				loadouts = (paramsArray select _i);
			};
			case "MaxScore":
			{
				maxScore = (paramsArray select _i);
			};
			case "SetupTime":
			{
				setupTime = (paramsArray select _i);
			};
			case "TimeLimit":
			{
				timeLimit = 60 * (paramsArray select _i);
			};
			case "LastPlayersCountdown":
			{
				lastPlayersCountdown = (paramsArray select _i);
			};
			case "LessThanLethal":
			{
				lessThanLethal = (paramsArray select _i);
			};
			case "HuntIR":
			{
				huntIR = (paramsArray select _i);
			};
		};
	};
};