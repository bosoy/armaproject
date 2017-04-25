private ["_diary6", "_diary5", "_diary4", "_diary3", "_diary2", "_diary1", "_str"];

//Briefingeinträge
_diary6 = player createDiaryRecord ["Diary", ["Technical Details", "None"]];
_diary5 = player createDiaryRecord ["Diary", ["Historic", "No Information available"]];
_diary4 = player createDiaryRecord ["Diary", ["Weather", "No weather information available"]];
_diary3 = player createDiaryRecord ["Diary", ["Intelligence report", "No intelligence report avaialbe"]];
_diary2 = player createDiaryRecord ["Diary", ["Motor pool", "Not available"]];
_diary1 = player createDiaryRecord ["Diary", ["Briefing", "Russian troops captured Chernarus a few weeks ago. The brave Chernarus army had no chance against the overwhelming Russian forces. US government decided to send a small task force lead by the U.S.S. Bon Homme Richard to attack several key targets to force russian troops to withdraw. You will start on the <marker name=""bonhomme"">U.S.S. Bon Homme Richard</marker>, good luck."]];

//Missionsziele

if (!isNil "second_round_done") then {
	task8 = player createSimpleTask ["obj8"];
	task8 setSimpleTaskDescription ["Free the main <marker name=""airbase"">airfield</marker> and destroy all SU fighters there.","Main target: Clear Airfield","Main target: Clear Airfield"];
	task8 setSimpleTaskDestination markerpos "airbase";
	if (isNil "airbase_clear") then {
		task8 settaskstate "Created";
	} else {
		task8 settaskstate "Succeeded";
	};
};

if (!isNil "first_round_done") then {
	task6 = player createSimpleTask ["obj6"];
	task6 setSimpleTaskDescription ["Charlie and Delta, there is a T90 platoon in  <marker name=""t90"">Pogorevka</marker>. The platoon is waiting for fuel and ammunition, a good chance to destroy those tanks.","Main target: Destroy T90s","Main target: Destroy T90s"];
	task6 setSimpleTaskDestination markerpos "t90";
	if (isNil "t90s_destroyed") then {
		task6 settaskstate "Created";
	} else {
		task6 settaskstate "Succeeded";
	};

	task5 = player createSimpleTask ["obj5"];
	task5 setSimpleTaskDescription ["Alpha and Bravo, destroy some com towers in <marker name=""dishes"">Dubrovka</marker>. The enemy uses them for data transmissions to russia.","Main target: Destroy Com Towers","Main target: Destroy Com Towers"];
	task5 setSimpleTaskDestination markerpos "dishes";
	if (isNil "sat_down") then {
		task5 settaskstate "Created";
	} else {
		task5 settaskstate "Succeeded";
	};

	task4 = player createSimpleTask ["obj4"];
	task4 setSimpleTaskDescription ["Team Razor, eliminate the collaborator at the <marker name=""opforhq"">enemy HQ Rog</marker>. He helped the russian troops to invade Chernarus.","Main target: Eliminate collaborator","Main target: Eliminate collaborator"];
	task4 setSimpleTaskDestination markerpos "opforhq";
	if (isNil "officer_down") then {
		task4 settaskstate "Created";
	} else {
		task4 settaskstate "Succeeded";
	};
};

task3 = player createSimpleTask ["obj3"];
task3 setSimpleTaskDescription ["Team Charlie and Team Delta, your first task is to destroy the SU 25 on <marker name=""destroy_sus"">Balota airfield</marker>. You should start when the radar station is down!","Main target: Destroy SU 25","Main target: Destroy SU 25"];
task3 setSimpleTaskDestination markerpos "destroy_sus";
if (isNil "su_destroyed") then {
	task3 settaskstate "Created";
} else {
	task3 settaskstate "Succeeded";
};

task2 = player createSimpleTask ["obj2"];
task2 setSimpleTaskDescription ["Team Alpha and Team Bravo, your first task is to blow up an ammunition train in the <marker name=""factory"">ammuniton factory</marker> near Solnichniy. You should start when the radar station is down!","Main target: Destroy ammunition train","Main target: Destroy ammunition train"];
task2 setSimpleTaskDestination markerpos "factory";
if (isNil "factory_down") then {
	task2 settaskstate "Created";
} else {
	task2 settaskstate "Succeeded";
};

//task1 = player createSimpleTask ["Hauptziel: Konvoi zerstören"];
task1 = player createSimpleTask ["obj1"];
task1 setSimpleTaskDescription ["Team Razors first job is to destroy a radar station on <marker name=""radar"">Isle Skalisty</marker>. All other teams have to wait until this task is finished. Otherwise the other teams will have trouble to set their feet on the main land.","Main target: Destroy radar","Destroy radar"];
task1 setSimpleTaskDestination markerpos "radar";
//Created, Succeeded, Failed
if (isNil "radar_down") then {
	task1 settaskstate "Created";
} else {
	task1 settaskstate "Succeeded";
};

tasks_done = true;
