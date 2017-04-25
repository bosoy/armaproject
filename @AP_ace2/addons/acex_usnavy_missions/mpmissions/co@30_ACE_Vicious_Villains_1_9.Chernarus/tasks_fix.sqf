private ["_diary3", "_diary2", "_diary1", "_str"];


_diary3 = player createDiaryRecord ["Diary", ["Situation", "The war in South zagoria is coming to an end. The ChDKZ forces are continuously losing ground. Last night their retreat came to an end near the coast. All loyal soldiers have regrouped there and are ready for a last stand. NATO forces immediately surrounded them. Now it's time to end this conflict!"]];
_diary2 = player createDiaryRecord ["Diary", ["Enemy", "The insurgents are defending their last positions. They have regrouped in the forest near the coast and are now awaiting an attack."]];
_diary1 = player createDiaryRecord ["Diary", ["Tasks", "Your tasks are clear. Move into the hostile area and clear key points in the area in order to destabilize the enemy and to end this war!"]];



//task4 = player createSimpleTask ["Main Target: Clear The Camp"];
task4 = player createSimpleTask ["obj4"];
task4 setSimpleTaskDescription ["The last big insurgent camp in South Zagoria is located in the small village <marker name=""rebels"">Tulga</marker>. Once it is cleared of any hostiles together with the other objectives the war will be over!","Main Target: Clear The Camp","Main Target: Clear The Camp"];
task4 setSimpleTaskDestination markerpos "rebels";
if (isNil "camp_clear") then {
	task4 settaskstate "Created";
} else {
	task4 settaskstate "Succeeded";
};

//task3 = player createSimpleTask ["Main Target: Eleminate The General!"];
task3 = player createSimpleTask ["obj3"];
task3 setSimpleTaskDescription ["Our informant reports that General Ivan Wodkavic, the leader of the local insurgents, is caught in the surrounded area. The informant gave us several locations where he could be - <marker name=""pos1"">here</marker>, <marker name=""pos2"">here</marker> and <marker name=""pos3"">here</marker>. With the General dead there should be no more thread to the NATO forces in the future.","Main Target: Eleminate The General!","Main Target: Eleminate The General!"];
task3 setSimpleTaskDestination markerpos "area";
if (isNil "officer_clear") then {
	task3 settaskstate "Created";
} else {
	task3 settaskstate "Succeeded";
};

//task2 = player createSimpleTask ["Main target: Clear Msta!"];
task2 = player createSimpleTask ["obj2"];
task2 setSimpleTaskDescription ["Once Staroye is in our hands try to advance quickly towards <marker name=""msta"">Msta</marker>. Be warned: Once you enter Msta the enemy might answer in sporadic counter attacks.","Main target: Clear Msta!","Main target: Clear Msta!"];
task2 setSimpleTaskDestination markerpos "msta";
if (isNil "msta_clear") then {
	task2 settaskstate "Created";
} else {
	task2 settaskstate "Succeeded";
};

//task1 = player createSimpleTask ["Main target: Clear Staroye!"];
task1 = player createSimpleTask ["obj1"];
task1 setSimpleTaskDescription ["5 hours ago the enemy moved into <marker name=""staroye"">Staroye</marker>. Our informant reports that all civilians fled. Keep in mind that they had enough time to fortify their positions. It's essential to capture this village first in order to make it impossible for the insurgents to expand their territory once more!","Main target: Clear Staroye!","Main target: Clear Staroye!"];
task1 setSimpleTaskDestination markerpos "staroye";
if (isNil "staroye_clear") then {
	task1 settaskstate "Created";
} else {
	task1 settaskstate "Succeeded";
};


tasks_done = true;