private ["_diary6", "_diary5", "_diary4", "_diary3", "_diary2", "_diary1", "_str"];

//Briefingeinträge
_diary6 = player createDiaryRecord ["Diary", ["Technical Details", "None"]];
_diary5 = player createDiaryRecord ["Diary", ["Historic", "No Information available"]];
_diary4 = player createDiaryRecord ["Diary", ["Weather", "No weather information available"]];
_diary3 = player createDiaryRecord ["Diary", ["Intelligence report", "No intelligence report avaialbe"]];
_diary2 = player createDiaryRecord ["Diary", ["Motor pool", "Not available"]];
_diary1 = player createDiaryRecord ["Diary", ["Briefing", "
This is it!<br/>
After we have lost east Podagorsk to the Russian troops we are now trying to get back in.<br/>
Your first task is to clear an old <marker name=""target1"">US base</marker> that Russian forces seized during their attack.
"]];

//Missionsziele

if (!isNil "main_clear") then {
	task4 = player createSimpleTask ["obj4"];
	task4 setSimpleTaskDescription ["Free <marker name=""zz3"">Berezniki</marker> from all enemy troops. There might be a lot of resistance on the way there.","Main target: Free Berezniki","Main target: Free Berezniki"];
	task4 setSimpleTaskDestination markerpos "zz3";
	if (isNil "officer_down") then {
		task4 settaskstate "Created";
	} else {
		task4 settaskstate "Succeeded";
	};
};

if (!isNil "factory_down") then {
	task3 = player createSimpleTask ["obj3"];
	task3 setSimpleTaskDescription ["Free <marker name=""target2"">Protvino</marker> from all enemy troops.","Main target: Clear Protvino","Main target: Clear Protvino"];
	task3 setSimpleTaskDestination markerpos "target2";
	if (isNil "main_clear") then {
		task3 settaskstate "Created";
	} else {
		task3 settaskstate "Succeeded";
	};
};

if (!isNil "base_clear") then {
	task2 = player createSimpleTask ["obj2"];
	task2 setSimpleTaskDescription ["Destroy four weapon containers in the enemy <marker name=""factory"">weapon factory</marker> near Tobolsk (two large factory buildings). Be warned, there are a lot of enemy patrols in the area.","Main target: Destroy factory","Main target: Destroy factory"];
	task2 setSimpleTaskDestination markerpos "factory";
	if (isNil "factory_down") then {
		task2 settaskstate "Created";
	} else {
		task2 settaskstate "Succeeded";
	};
};

task1 = player createSimpleTask ["obj1"];
task1 setSimpleTaskDescription ["Your first object is to clear the <marker name=""target1"">military base</marker> in the east. There you will find additional equipment","Main target: Seize base","Main target: Seize base"];
task1 setSimpleTaskDestination markerpos "target1";
//Created, Succeeded, Failed
if (isNil "base_clear") then {
	task1 settaskstate "Created";
} else {
	task1 settaskstate "Succeeded";
};

tasks_done = true;
