private ["_diary6", "_diary5", "_diary4", "_diary3", "_diary2", "_diary1", "_str"];

//Briefingeinträge
_diary6 = player createDiaryRecord ["Diary", ["Technical Details", "No NVGoggles available!<br/>Uses flashlight dialogs from Homer Johnston."]];
_diary4 = player createDiaryRecord ["Diary", ["Weather", "Clear, full moon"]];
_diary3 = player createDiaryRecord ["Diary", ["Intelligence report", "Expect enemy patrols"]];
_diary2 = player createDiaryRecord ["Diary", ["Motor pool", "No vehicles available"]];
_diary1 = player createDiaryRecord ["Diary", ["Briefing", "Three russian regiments are pushing to the coasts of Chernarus.<br/>
Currently it seems the Russian attack came to a halt. Main reason should be that they have to resupply their troops first.<br/>
This is a good chance for us to break through a weak area in their lines and gain back some lost territory.<br/>
Maybe we are able to cut off some of their troops in the eastern territory of Chernarus.<br/>
Your platoon will start near <marker name=""start_us"">Msta</marker>, near <marker name=""start_us_1"">Solnichniy</marker> and near <marker name=""start_us_2"">Orlovets</marker>, good luck."]];

//Missionsziele

if (!isNil "berezino_clear") then {
	task5 = player createSimpleTask ["obj5"];
	task5 setSimpleTaskDescription ["Now try to reach your <marker name=""extraction"">extraction point</marker>.","Main target: Reach extraction point","Main target: Reach extraction point"];
	task5 setSimpleTaskDestination markerpos "extraction";
	task5 settaskstate "Created";
};

if (!isNil "next_phase") then {
	task4 = player createSimpleTask ["obj4"];
	task4 setSimpleTaskDescription ["As the last task tonight try to make your way back through <marker name=""berezino"">Berezino</marker>.<br/>Clear the city from all enemy presence so that we can take it back.","Main target: Clear Berezino","Main target: Clear Berezino"];
	task4 setSimpleTaskDestination markerpos "berezino";
	if (isNil "berezino_clear") then {
		task4 settaskstate "Created";
	} else {
		task4 settaskstate "Succeeded";
	};
};

if (!isNil "ammo_clear") then {
	task3 = player createSimpleTask ["obj3"];
	task3 setSimpleTaskDescription ["Beside the tank platoon in Polana intel also found an AA Tunguska unit in <marker name=""aaunit"">Gorka</marker>.<br/>Destroy all Tungis (we don't know the exact number) so that our air units survive a little bit longer.","Main target: Destroy AA unit","Main target: Destroy AA unit"];
	task3 setSimpleTaskDestination markerpos "aaunit";
	if (isNil "tungi_clear") then {
		task3 settaskstate "Created";
	} else {
		task3 settaskstate "Succeeded";
	};

	task2 = player createSimpleTask ["obj2"];
	task2 setSimpleTaskDescription ["Intel reports that there is an enemy T90 platoon in <marker name=""tanks"">Polana</marker>.<br/>The tank crews are currently resting in a tent camp somewhere in Polana. Sneak in and try to kill the tank crews first before the enemy takes any notice of you.<br/>Otherwise it will get a bloody attack.<br/>Destroy all T90s!","Main target: Destroy tanks","Main target: Destroy tanks"];
	task2 setSimpleTaskDestination markerpos "tanks";
	if (isNil "t90_clear") then {
		task2 settaskstate "Created";
	} else {
		task2 settaskstate "Succeeded";
	};
};

task1 = player createSimpleTask ["obj1"];
task1 setSimpleTaskDescription ["Our first target is a former <marker name=""ammo"">US ammo depot</marker> near Dolina. Try to seize it, there should be still enough US ammunition.<br/>We don't expect too much enemy resistance in the depot.","Main target: Seize ammo depot","Seize ammo depot"];
task1 setSimpleTaskDestination markerpos "ammo";
//Created, Succeeded, Failed
if (isNil "fuel_dump_down") then {
	task1 settaskstate "Created";
} else {
	task1 settaskstate "Succeeded";
};

tasks_done = true;
