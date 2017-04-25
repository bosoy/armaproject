
_general = "Welcome to Six Battle Center by Sickboy<br />\
		<br />\
		The mission auto-starts within 45 seconds.<br /> \
		At this time there is no default mission setup.<br /> \
		Each mission must be manually setup by going in to the Battle Center menu, and enabling modification mode before auto-start occurs<br /> \
		You can build the mission with multiple people on the same side, or on different sides<br /> \
		<br /> \
		<br /> \
		Six Menu Features:<br /> \
		* Weapons/Attachments options<br /> \
		<br /> \
		<b>The Commander Can:</b> <br /> \
		* Enable/Disable TrainingMode (For Fun/Training rounds)<br /> \
		* Control Environment (Weather, Time)<br /> \
		* Configure the Mission: <br /> \
		* TODO: Start Default Mission (auto in 45sec) <br /> \
		* Create a custom Mission. (Each CfgGroups->Side is available)<br /> \
		* Submit the mission (queue) to the server for building and missionstart<br /> \
		<br /> \
		<b>After Submission:</b> <br /> \
		* Call in Artillery, requires LaserMarker (If friendly camp with Arty)<br /> \
		* Call in Airstrikes, requires LaserMarker<br />";

_credits = "by Sickboy sb_at_dev-heaven.net<br /> \
		<br /> \
		* DAC by Silola (Mapfact.net)<br /> \
		* UPS by Kronzky<br /> \
		* TODO";


waitUntil {!(isNull player)};

player createDiaryRecord ["Diary", ["General", _general]];
player createDiaryRecord ["Diary", ["Credits", _credits]];


/*
_goalString  = format ["%1 must take the %2 Main Base.<br/>To do so, %1 will try to capture the bases until they reach %2 Main Base and capture it.", attackingSide, defendingSide];
_capString = format ["Only neutral bases are capturable.<br/>\
	To take them, the attacking side must bring as much soldiers (from Soldier class in spawn screen) out of vehicles inside the base radius (black circle on map)/<br/>\
	The base will switch after a while if the attacking side has more soldiers in zone than defending side.<br/>\
	The capture advance is visible by checking the flag height on the pole at the base bunker.<br\>\
	Once the attackers have been on zoen long enough with number advantage, the zone changes to the attacker's side, while the adjacent ennemy zone becomes neutral.", flagCaptureTime, flagMaxDistance];
_classString = "The game is class-based. You will be able to do actions corresponding to your current class.<br/>\
	The classes are the following : Soldier, Medic, Engineer, Recon, Spec Ops and Crewman. Each class has one or more possible roles dictating abilities and gear.<br/>\
	Soldier class counts toward base capture or defense. The roles are : Grenadier, Light AntiTank, Heavy AntiTank, AntiAir and Automatic Rifleman.<br/>\
	Medic class can heal. The only role is Medic. Medic are responsible for handling the respawn vehicle driving and deployement. See Respawn in Notes.<br/>\
	Engineer class is handling most of the support and supply for the army. The only role is Engineer. Engineer are the ones driving support vehicles for rearm and repair, and for building facilities (with supply truck) in friendly bases for faster vehicle deployement.<br/>\
	Recon class is the long range specialists. It includes sniper and heavy sniper. They're ability is to wear the Ghillie suit, they don't count toward base capture.<br/>\
	Spec Ops class is the sneaky sneaky. It includes demolition specialist who act in ennemy yard to destroy ennemy assets. He can destroy deploy facilities using his timed satchel charge (beware, satchel can only be timed at 30s in CTB, not remotely detonated).<br/>\
	Crewman is the vehicle class. Roles are Crew and Pilot. Crew can drive, gun and command armored vehicles, Pilot can pilot and gun air vehicles.";
_respawnString = "When dead, the respawn screen appears. It lists the classes for player to chose from, and the available spawn points.<br/>\
	The available spawn points are : the side Back Spawn (area only enterable by this side's units), all friendly bases, and the nearest deployed friendly MHQ.<br/>\
	MHQ are handled by Medics. They spawn at the Back Spawn area and can be driven by Medics anywhere. They can then be deployed to act as spawn point.";
_vehicleString = "Each side starts with a fixed set of vehicles, present in the BackSpawn area of each side.<br/>\
	To get in these vehicles as pilot, driver, gunner, commander, you must be of the correct class, otherwise you'll be booted out when entering.<br/>\
	In some other places on the map, near bases, you can find Factories (marked on map). They give you the possibility to take an available vehicle from the BackSpawn area to the factory place.<br/>\
	To use a Factory, use the 'get vehicle' action on it. A list of vehicles suitable for your class as driver, and available in the BackSpawn area, will be presented, select the desired vehicle and click OK.\
	You'll be placed in driver position of vehicle and the vehicle will be positioned at your current Factory.<br/>\
	Aircraft can't be taken through Factories, you have to take them in the BackSpawn area.<br/>\
	Engineer can use the Supply Truck to go deploy a factory in a friendly base, to help his team with vehicle deployement.<br/><br/>\
	Each Base bunker also always give access to a Humvee or UAZ, independantly of the vehicles available in BackSpawn area and indepandantly of your class.<br/>\
	Only Factory of friendly bases are active for you.";
player createDiaryRecord ["Diary", ["Vehicles", _vehicleString]];
player createDiaryRecord ["Diary", ["Respawn", _respawnString]];
player createDiaryRecord ["Diary", ["Classes", _classString]];
player createDiaryRecord ["Diary", ["Capturing bases", _capString]];
player createDiaryRecord ["Diary", ["Goal", _goalString]];
taskList = [];
_d = 10000;
_curTask = objNull;
waitUntil {!(isNull player)};
{
	_marker = _x getVariable "flagMarker";
	_owner = _x getVariable "flagOwner";
diag_log format ["creating tasks for flag %1, owned by %2, marker is %3", _x, _owner, _marker];
	_name = markerText _marker;
	_taskCreateText = "";
	_taskDescrText = "";
	if (truePlayerSide == attackingSide) then {
		_taskCreateText = format ["Take %1", _name];
		_taskDescrText = format ["Bring soldiers in %1, within %3 meters of %1 bunker. You need more soldiers than defenders to take the base. Check the flag height on the pole at base's bunker for capture status indication", _name, flagCaptureTime, flagMaxDistance];
	} else {
		_taskCreateText = format ["Defend base at %1", _name];
		_taskDescrText = format ["Bring soldiers in %1, within %3 meters of %1 bunker. You need more soldiers than attackers to prevent capture of the base. Check the flag height on the pole at base's bunker for capture status indication", _name, flagCaptureTime, flagMaxDistance];
	};
	_obj = player createSimpleTask [_taskCreateText];
	_obj setSimpleTaskDescription [_taskDescrText, \
		_taskCreateText, \
		_taskCreateText];
	_obj setSimpleTaskDestination (getMarkerPos _marker);
	if (_owner == "none") then {
		_obj setTaskState "CREATED";
		if ((player distance _x) < _d) then {_curTask = _obj; _d = player distance _x};
	} else {
		_obj setTaskState "CANCELED";
	};
	taskList = taskList + [_obj];

} forEach flagList;
diag_log format ["task list = %1", taskList];
if !(isNull _curTask) then {player setCurrentTask _curTask};
*/