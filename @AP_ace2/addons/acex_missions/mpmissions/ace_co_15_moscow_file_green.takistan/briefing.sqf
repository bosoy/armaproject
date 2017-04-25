waitUntil {!isNull player};

{
	_x createDiaryRecord ["Diary", ["Credits", "Mission by GalZohar"]];
	_x createDiaryRecord ["Diary", ["Enemy forces", format ["About %1 well-equipped SF infantrymen.", enemyCount]]];
	_x createDiaryRecord ["Diary", ["Friendly forces", format ["%1 of out best Takistani rebels with the best equipment we can afford.", count indUnits]]];
	_x createDiaryRecord ["Diary", ["Mission", "Start <marker name='mrkStart'>here</marker> and head out to steal the Moscow Bombing File from <marker name='mrkObj'>the American officer</marker>. Then, extract to safety without losing more than 1/2 of your rebel team. You have 45 minutes (until 02:45)."]];
	_x createDiaryRecord ["Diary", ["Situation", "Our supporting organizations in Moscow have shown interest in a top secret file related to bombings in Moscow. The file is held by an American officer who should be hiding in <marker name='mrkObj'>this building</marker>. The area is held by American SF soldiers, so we are sending our best rebels to get this job done. Our force will start <marker name='mrkStart'>here</marker>."]];
} forEach indUnits;