waitUntil {!isNull player};

{
	_x createDiaryRecord ["Diary", ["Credits", "Mission by GalZohar"]];
	_x createDiaryRecord ["Diary", ["Enemy forces", format ["About %1 Takistani insurgents and 2 suicide carbombs, as well as about %2 insurgents on standby with Land Rovers that may come to assist.", briefingEnemycount, briefingReinfCount]]];
	_x createDiaryRecord ["Diary", ["Friendly forces", format ["%1 US army infantrymen on humvees.", blueforCount]]];
	_x createDiaryRecord ["Diary", ["Mission", "Start <marker name='mrkStart'>here</marker> and head out destroy the <marker name='mrkObj'>2 caches</marker>. You have 45 minutes (until 12:45). Killing civilians is forbidden (though if you kill only 1 we'll let it slip)."]];
	_x createDiaryRecord ["Diary", ["Situation", "Takistani insurgents have been collecting weapons and ammunition and storing them in Zargabad. We just discovered the <marker name='mrkObj'>estimated location</marker> of the site used to store their supplies. We know you've already destroyed an incredible number of ammo caches around Takistan, but this time it's special. Beware, as they are  known to have 2 suicide carbombs driving around along with regular civilians - when in doubt, fire warning shots first."]];
} forEach blueforUnits;