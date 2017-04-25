waitUntil {!isNull player};

{
	_x createDiaryRecord ["Diary", ["Credits", "Mission by GalZohar"]];
	_x createDiaryRecord ["Diary", ["Enemy forces", format ["About %1 Takistani soldiers.", enemyCount]]];
	_x createDiaryRecord ["Diary", ["Friendly forces", format ["%1 US infantrymen.", count blueforUnits]]];
	_x createDiaryRecord ["Diary", ["Mission", "Start <marker name='mrkStart'>here</marker> and head out to take the Moscow Bombing File from <marker name='mrkObj'>Colonel Aziz</marker>. Then, extract to safety without losing more than 1/2 of your rebel team. You have 45 minutes (until 02:45)."]];
	_x createDiaryRecord ["Diary", ["Situation", "It seems the Takistanis have discovered information about bombins in Moscow. We have reasons to believe that a relevant file is being held by Takistani Colonel Aziz, who should be hiding in <marker name='mrkObj'>this building</marker>. The area is held by Takistani soldiers. Our force will start <marker name='mrkStart'>here</marker>."]];
} forEach blueforUnits;