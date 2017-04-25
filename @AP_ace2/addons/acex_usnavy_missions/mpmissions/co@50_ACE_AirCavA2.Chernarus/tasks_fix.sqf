private ["_diary6", "_diary5", "_diary4", "_diary3", "_diary2", "_diary1", "_str"];

//Briefingeinträge
_diary6 = player createDiaryRecord ["Diary", ["Technical Details", "None"]];
_diary5 = player createDiaryRecord ["Diary", ["Historic", "No Information available"]];
_diary4 = player createDiaryRecord ["Diary", ["Weather", "No weather information available"]];
_diary3 = player createDiaryRecord ["Diary", ["Intelligence report", "No intelligence report avaialbe"]];
_diary2 = player createDiaryRecord ["Diary", ["Motor pool", "Not available"]];
_diary1 = player createDiaryRecord ["Diary", ["Briefing", "Your main task is to recapture <marker name=""elektro"">Elektrozavodsk</marker>, <marker name=""zeleno"">Zelenogorsk</marker> and <marker name=""krasnostav"">Krasnostav</marker> from enemy forces. Watch out for enemy AntiAir guns. We have spotted them around <marker name=""shilka1"">here</marker> and <marker name=""shilka2"">here</marker>here</marker>. In case of this danger, we only get a go for the armed choppers, when the AAs are eliminated. A convoy is underway to support the enemy forces. Destroy the convoy before it reaches Elektrozavodsk."]];

//Missionsziele
task5 = player createSimpleTask ["obj5"];
task5 setSimpleTaskDescription ["Attention: Don't waste our choppers <marker name=""start"">own</marker> helicopters.","Main target: Do not waist choppers","Main target: Do not waist choppers"];
task5 setSimpleTaskDestination markerpos "start";
task5 settaskstate "Created";

task4 = player createSimpleTask ["obj4"];
task4 setSimpleTaskDescription ["Clear <marker name=""krasnostav"">Krasnostav</marker> from all enemy forces.","Main target: Clear Krasnostav","Main target: Clear Krasnostav"];
task4 setSimpleTaskDestination markerpos "krasnostav";
if (isNil "krasno_clear") then {
	task4 settaskstate "Created";
} else {
	task4 settaskstate "Succeeded";
};

task3 = player createSimpleTask ["obj3"];
task3 setSimpleTaskDescription ["Clear <marker name=""elektro"">Elektrozavodsk</marker> from all enemy forces.","Main target: Clear Elektrozavodsk","Main target: Clear Elektrozavodsk"];
task3 setSimpleTaskDestination markerpos "elektro";
if (isNil "elektro_clear") then {
	task3 settaskstate "Created";
} else {
	task3 settaskstate "Succeeded";
};

task2 = player createSimpleTask ["obj2"];
task2 setSimpleTaskDescription ["Destroy the Tanks in <marker name=""zeleno"">Zelenogorsk</marker> and clear the town of all enemy presence","Hauptziel: Destroy Tanks","Hauptziel: Destroy Tanks"];
task2 setSimpleTaskDestination markerpos "zeleno";
if (isNil "zele_clear") then {
	task2 settaskstate "Created";
} else {
	task2 settaskstate "Succeeded";
};

//task1 = player createSimpleTask ["Hauptziel: Konvoi zerstören"];
task1 = player createSimpleTask ["obj1"];
task1 setSimpleTaskDescription ["Destroy the convoy that is coming from <marker name=""krasnostav"">Krasnostav</marker>. Its destination is <marker name=""elektro"">Elektrozavodsk</marker>. The SF Team starts in <marker name=""sf_team"">Dubrovka</marker> and must stop the convoy. If the convoy reaches <marker name=""elektro"">Elektrozavodsk</marker> the complete mission failed.","Main target: Destroy convoy","Destroy convoy"];
task1 setSimpleTaskDestination markerpos "Hinterhalt";
//Created, Succeeded, Failed
if (isNil "convoy_down") then {
	task1 settaskstate "Created";
} else {
	task1 settaskstate "Succeeded";
};

tasks_done = true;