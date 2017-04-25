private ["_diary6", "_diary5", "_diary4", "_diary3", "_diary2", "_diary1", "_str"];
//Briefingeintraege

_diary6 = player createDiaryRecord ["Diary", ["Technical details", "respawn"]];
_diary5 = player createDiaryRecord ["Diary", ["History", "The russian got many new planes. We start a offensive to destroy them to get the air supremacy"]];
//_diary4 = player createDiaryRecord ["Diary", ["Wetter", "Es ist frueh am Morgen und das Wetter sollte gut bleiben"]];
//_diary3 = player createDiaryRecord ["Diary", ["Aufklaerung", "Es ist mit massiver Luftabwehr zu rechnen."]];
_diary2 = player createDiaryRecord ["Diary", ["Credits", "Made by Thom0001 in 2009  -  special thanks to the Germany-Fun Community and Xeno"]];
_diary1 = player createDiaryRecord ["Diary", ["Mission", "Destroy the AA-Unit and then capture the russian air base. Destroy all planes!"]];


//Missionsziele


//task2 = player createSimpleTask ["Main Target: Airfield"];
task2 = player createSimpleTask ["obj1"];
task2 setSimpleTaskDescription ["Capture the russian air base. Destroy all planes <marker name=""Target_1"">Airfield</marker>.","Main target: Airfield","Main target: Airfield"];
task2 setSimpleTaskDestination markerpos "Target_1";
if (isNil "Target_1_clear") then {
	task2 settaskstate "Created";
} else {
	task2 settaskstate "Succeeded";
};

//task1 = player createSimpleTask ["Main Target: AA-Unit"];
task1 = player createSimpleTask ["obj2"];
task1 setSimpleTaskDescription ["Destroy the AA-Unit <marker name=""AA"">AA-Unit</marker>.","Main target: AA-Unit","Main target: AA-Unit"];
task1 setSimpleTaskDestination markerpos "AA";
if (isNil "AA_1_clear") then {
	task1 settaskstate "Created";
} else {
	task1 settaskstate "Succeeded";
};



tasks_done = true;