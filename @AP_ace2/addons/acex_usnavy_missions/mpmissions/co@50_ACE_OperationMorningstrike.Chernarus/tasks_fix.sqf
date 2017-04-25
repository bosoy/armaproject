private ["_diary6", "_diary5", "_diary4", "_diary3", "_diary2", "_diary1", "_str"];

//Briefingeinträge
_diary6 = player createDiaryRecord ["Diary", ["Technical Details", "None"]];
_diary5 = player createDiaryRecord ["Diary", ["Historic", "No Information available"]];
_diary4 = player createDiaryRecord ["Diary", ["Weather", "No weather information available"]];
_diary3 = player createDiaryRecord ["Diary", ["Intelligence report", "No intelligence report avaialbe"]];
_diary2 = player createDiaryRecord ["Diary", ["Motor pool", "Not available"]];
_diary1 = player createDiaryRecord ["Diary", ["Briefing", "Russian troops drove us back into the sea a week ago.<br/>
Because of the surprising attack of the russian troups we had no time to extract all vehicles and choppers.<br/>
We are still waiting for resuplies from the states, but High Command decided that we should commence our attack alone.<br/>
Your first task will be to take back Balota airfield to get our hands on the choppers we had to leave back.<br/>
Several USMC groups will land at the <marker name=""startpos"">beach</marker> near Komarovo under the lead of a SEAL commander.<br/>
Good luck."]];

//Missionsziele

if (!isNil "balota_clear") then {
	if (!isNil "airfield_clear") then {
		task7 = player createSimpleTask ["obj7"];
		task7 setSimpleTaskDescription ["Eliminate all officers in the enemy <marker name=""hq"">HQ</marker> in Krasnostav.","Main target: Eliminate officers","Main target: Eliminate officers"];
		task7 setSimpleTaskDestination markerpos "hq";
		if (isNil "officers_dead") then {
			task7 settaskstate "Created";
		} else {
			task7 settaskstate "Succeeded";
		};
	};

	if (!isNil "start_phase3") then {
		task6 = player createSimpleTask ["obj6"];
		task6 setSimpleTaskDescription ["Seize the <marker name=""main_airfield"">main airfield</marker>.","Main target: Seize Airfield","Main target: Seize Airfield"];
		task6 setSimpleTaskDestination markerpos "main_airfield";
		if (isNil "airfield_clear") then {
			task6 settaskstate "Created";
		} else {
			task6 settaskstate "Succeeded";
		};
	};

	task5 = player createSimpleTask ["obj5"];
	task5 setSimpleTaskDescription ["Destroy the fuel trucks in the enemy <marker name=""supply_depot"">supply base</marker> near Vyshnoe.","Main target: Destroy Supply Base","Main target: Destroy Supply Base"];
	task5 setSimpleTaskDestination markerpos "supply_depot";
	if (isNil "fuel_dump_down") then {
		task5 settaskstate "Created";
	} else {
		task5 settaskstate "Succeeded";
	};

	task4 = player createSimpleTask ["obj4"];
	task4 setSimpleTaskDescription ["Destroy the <marker name=""artillery"">artillery firebase</marker> near Stary Sobor","Main target: Destroy artillery","Main target: Destroy artillery"];
	task4 setSimpleTaskDestination markerpos "artillery";
	if (isNil "arti_down") then {
		task4 settaskstate "Created";
	} else {
		task4 settaskstate "Succeeded";
	};

	task3 = player createSimpleTask ["obj3"];
	task3 setSimpleTaskDescription ["Destroy the AA units near <marker name=""aa"">Pusta</marker>.","Main target: Destroy AA","Main target: Destroy AA"];
	task3 setSimpleTaskDestination markerpos "aa";
	if (isNil "aa_down") then {
		task3 settaskstate "Created";
	} else {
		task3 settaskstate "Succeeded";
	};

	task2 = player createSimpleTask ["obj2"];
	task2 setSimpleTaskDescription ["Destroy the generators that powert the enemy communication system on mount <marker name=""combase"">Grüner Berg</marker>.","Main target: Destroy generators","Main target: Destroy generators"];
	task2 setSimpleTaskDestination markerpos "combase";
	if (isNil "gen_down") then {
		task2 settaskstate "Created";
	} else {
		task2 settaskstate "Succeeded";
	};
};

task1 = player createSimpleTask ["obj1"];
task1 setSimpleTaskDescription ["Seize <marker name=""balota_airfield"">Balota airfield</marker> to get back our choppers!","Main target: Seize Balota airfield","Seize Balota airfield"];
task1 setSimpleTaskDestination markerpos "balota_airfield";
//Created, Succeeded, Failed
if (isNil "balota_clear") then {
	task1 settaskstate "Created";
} else {
	task1 settaskstate "Succeeded";
};

tasks_done = true;
