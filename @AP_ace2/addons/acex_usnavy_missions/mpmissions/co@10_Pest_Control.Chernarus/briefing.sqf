waitUntil { !isNull player };
waitUntil { player == player };

if (isNil "Alpha") then {
	Alpha = grpNull;
};
if (isNil "Buzzard1") then {
	Buzzard1 = grpNull;
};
if (isNil "Buzzard2") then {
	Buzzard2 = grpNull;
};
switch ((group player)) do {
  case Alpha: {
    player createDiaryRecord ["Diary", ["About", "Pest Control v2.2 by AnimalMother92<br />Please report any feedback @<br />http://dev-heaven.net/projects/anm-missions [Bug tracker]<br />http://tinyurl.com/AnimalMother92 [BI Forums]<br />@R92B [Twitter]<br /><img image='AM92.paa'/><br />Made for Advanced Combat Environment"]];
	player createDiaryRecord ["Diary", ["Mission", "UAV footage has indicated that there is guerrilla activity in the village of <marker name=""infantry"">Gorka</marker>. An Airborne team will be deployed via Blackhawk to the village and will conduct a complete sweep to eliminate any enemy fighters and destroy caches or other threats. Close air support will be provided by 2 AH-6J Little Birds. WP marker grenades are quite effective for designating targets for the helos. Enemy forces are expected to be poorly equipped and rather unorganized. However, even though we have the technological advantage, we're playing on their field."]];
    player createDiaryRecord ["Diary", ["Situation", "Over the past few months the insurgency in Chernarus has been all but eliminated. However, recent reports and surveillance footage have indicated that guerrilla forces are stockpiling weapons in the mountain regions of Chernarus and may seek to destabilize the area again. We must not let them spread and get a chance to strike. The blow must be dealt now in order to control these pests."]];
    tsk3 = player createSimpleTask ["Extract"];
    tsk3 setSimpleTaskDescription ["Once Gorka is clear of resistance and the weapon caches are destroyed, move to the extraction point and board the helo.", "Extract", ""];
    tsk3 setSimpleTaskDestination (getMarkerPos "Extract");
	tsk2 = player createSimpleTask ["Destory caches"];
    tsk2 setSimpleTaskDescription ["Locate the ammunition caches in Gorka and destroy them using satchel charges or incendiary grenades. The engineer, Alpha 7, is carrying extra demolition equipment if needed.", "Destroy caches", ""];
	tsk1 = player createSimpleTask ["Sweep Gorka"];
    tsk1 setSimpleTaskDescription ["Advance through Gorka and elimate any threats. Light enemy movement has been observed throughout the village, and it is likely that the guerrillas have stockpiled weapons in the town.", "Sweep Gorka", ""];
    tsk1 setSimpleTaskDestination (getMarkerPos "infantry");
    player setCurrentTask tsk1;
  };
  case Buzzard1: {
    player createDiaryRecord ["Diary", ["About", "Pest Control v2.2 by AnimalMother92<br />Please report any feedback @<br />http://dev-heaven.net/projects/anm-missions [Bug tracker]<br />http://tinyurl.com/AnimalMother92 [BI Forums]<br />@R92B [Twitter]<br /><img image='AM92.paa'/><br />Made for Advanced Combat Environment"]];
	player createDiaryRecord ["Diary", ["Mission", "UAV footage has indicated that there is guerrilla activity in the village of <marker name=""infantry"">Gorka</marker>. An Airborne team will be deployed via Blackhawk to the village and will conduct a complete sweep to eliminate any enemy fighters and destroy caches or other threats. Close air support will be provided by 2 AH-6J Little Birds. Enemy forces are expected to be poorly equipped and rather unorganized. However, even though we have the technological advantage, we're playing on their field."]];
    player createDiaryRecord ["Diary", ["Situation", "Over the past few months the insurgency in Chernarus has been all but eliminated. However, recent reports and surveillance footage have indicated that guerrilla forces are stockpiling weapons in the mountain regions of Chernarus and may seek to destabilize the area again. We must not let them spread and get a chance to strike. The blow must be dealt now in order to control these pests."]];
	tsk2cas = player createSimpleTask ["RTB"];
    tsk2cas setSimpleTaskDescription ["After ammunition is expended or Alpha's tasks are completed, return to base for resupply.", "RTB", ""];
	tsk2cas setSimpleTaskDestination (getMarkerPos "farp");
	tsk1cas = player createSimpleTask ["Provide CAS"];
    tsk1cas setSimpleTaskDescription ["Give Alpha squad close air support as they sweep the village of Gorka.", "Provide CAS", ""];
	tsk1cas setSimpleTaskDestination (getMarkerPos "infantry");
    player setCurrentTask tsk1cas;
  };
  case Buzzard2: {
    player createDiaryRecord ["Diary", ["About", "Pest Control v2.2 by AnimalMother92<br />Please report any feedback @<br />http://dev-heaven.net/projects/anm-missions [Bug tracker]<br />http://tinyurl.com/AnimalMother92 [BI Forums]<br />@R92B [Twitter]<br /><img image='AM92.paa'/><br />Made for Advanced Combat Environment"]];
	player createDiaryRecord ["Diary", ["Mission", "UAV footage has indicated that there is guerrilla activity in the village of <marker name=""infantry"">Gorka</marker>. An Airborne team will be deployed via Blackhawk to the village and will conduct a complete sweep to eliminate any enemy fighters and destroy caches or other threats. Close air support will be provided by 2 AH-6J Little Birds. Enemy forces are expected to be poorly equipped and rather unorganized. However, even though we have the technological advantage, we're playing on their field."]];
    player createDiaryRecord ["Diary", ["Situation", "Over the past few months the insurgency in Chernarus has been all but eliminated. However, recent reports and surveillance footage have indicated that guerrilla forces are stockpiling weapons in the mountain regions of Chernarus and may seek to destabilize the area again. We must not let them spread and get a chance to strike. The blow must be dealt now in order to control these pests."]];
	tsk2cas = player createSimpleTask ["RTB"];
    tsk2cas setSimpleTaskDescription ["After ammunition is expended or Alpha's tasks are completed, return to base for resupply.", "RTB", ""];
	tsk2cas setSimpleTaskDestination (getMarkerPos "farp");
	tsk1cas = player createSimpleTask ["Provide CAS"];
    tsk1cas setSimpleTaskDescription ["Give Alpha squad close air support as they sweep the village of Gorka.", "Provide CAS", ""];
	tsk1cas setSimpleTaskDestination (getMarkerPos "infantry");
    player setCurrentTask tsk1cas;
  };
};

//Group Respawn & teamSwitch fix
if (!isNil "tsk1done") then {tsk1 setTaskState "SUCCEEDED"; player setCurrentTask tsk2;};
if (!isNil "tsk2done") then {tsk2 setTaskState "SUCCEEDED"; player setCurrentTask tsk3;};
if (!isNil "tsk3done") then {tsk3 setTaskState "SUCCEEDED";};