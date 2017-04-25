waitUntil {!isNull player};
waitUntil { player == player };

player createDiaryRecord ["Diary", ["About", "Reaper v1.2 by AnimalMother92<br />Please report any feedback @<br />http://dev-heaven.net/projects/anm-missions [Bug tracker]<br />http://tinyurl.com/AnimalMother92 [BI Forums]<br />@R92B [Twitter]<br /><img image='AM92.paa'/><br />Made for Advanced Combat Environment"]];
player createDiaryRecord ["Diary", ["Support", "An MQ-9 Reaper UAV is on station for fire support. It is equipped with 2x GBU-12 Paveway II laser-guided bombs, and 4x AGM-114 Hellfire air-to-surface missiles. To call support: paint your target with the SOFLAM, select the preferred ordnance, and keep the target marked until the splash."]];
player createDiaryRecord ["Diary", ["Mission", "The primary goal of this mission is to clear the Takiban forces from <marker name=""hideout"">Nur</marker>. The secondary goal is to locate the high value target, who is likely to be in the area. The UAV fire support is key to this mission, as it's quite possible that the enemy has light vehicles and defensive emplacements, so caution is advised."]];
player createDiaryRecord ["Diary", ["Situation", "HUMINT has indicated that Takiban forces are gathering in the village of <marker name=""hideout"">Nur</marker>. In addition, there are rumors that a high ranking Takiban officer may be hiding there. Wiping the insurgent presence from Nur is critical, especially as they may be using the village for training and resupply."]];
tsk3 = player createSimpleTask ["Extract"];
tsk3 setSimpleTaskDescription ["Exfiltrate to the pick-up point and await Chinook transport.", "Extract", ""];
tsk3 setSimpleTaskDestination (getMarkerPos "extract");
tsk2 = player createSimpleTask ["Locate Achmed"];
tsk2 setSimpleTaskDescription ["If possible, attempt to identify the high value target 'Achmed bin Durka', either dead or alive.", "Locate Achmed", ""];
tsk1 = player createSimpleTask ["Secure stronghold"];
tsk1 setSimpleTaskDescription ["Clear the suspected Takiban camp of resistance, using the UAV for fire support.", "Secure stronghold", ""];
tsk1 setSimpleTaskDestination (getMarkerPos "hideout");
player setCurrentTask tsk1;

//Group Respawn & teamSwitch fix
if (!isNil "tsk1done") then {tsk1 setTaskState "SUCCEEDED"; player setCurrentTask tsk3;};
if (!isNil "tsk2done") then {tsk2 setTaskState "SUCCEEDED";};
if (!isNil "tsk3done") then {tsk3 setTaskState "SUCCEEDED";};