waitUntil {!isNull player};
waitUntil { player == player };

player createDiaryRecord ["Diary", ["About", "Guerrilla Radio v2.1 by AnimalMother92<br />Please report any feedback @<br />http://dev-heaven.net/projects/anm-missions [Bug tracker]<br />http://tinyurl.com/AnimalMother92 [BI Forums]<br />@R92B [Twitter]<br /><img image='AM92.paa'/><br />Made for Advanced Combat Environment"]];
player createDiaryRecord ["Diary", ["Mission", "Your task is to regain control of the <marker name=""Guerrilla Camp"">Green Mountain radio tower</marker> and eliminate the guerrilla force without destroying the compound. For this reason no air support or artillery can be used as it risks the facility. The people of Chernarus rely on this radio tower. Alpha and Charlie squads will insert via helicopter and assault the site. After the compound is secure, Charlie squad will remain at the tower and secure it until relieved. Alpha squad, with the support of a motorized infantry team, will proceed to sweep the <marker name=""supply"">supply site</marker>."]];
player createDiaryRecord ["Diary", ["Situation", "Guerrilla forces have taken control of a <marker name=""Guerrilla Camp"">Chernarussian radio tower</marker> and are using it as a base camp and to broadcast propaganda. The guerrillas have reportedly been striking from their camp on Green Mountain, at the old radio facility. HUMINT has indicated that there is a fairly significant enemy force at the site, mostly consisting of infantry and some light vehicles."]];
tsk2 = player createSimpleTask ["Clear supply site"];
tsk2 setSimpleTaskDescription ["Sweep the guerrilla supply site and eliminate any hostiles. The enemy has been using this site to refuel and rearm their vehicles as well as train new soldiers in the area.", "Clear supply site", ""];
tsk2 setSimpleTaskDestination (getMarkerPos "supply");
tsk1 = player createSimpleTask ["Secure compound"];
tsk1 setSimpleTaskDescription ["Storm Green Mountain and retake the radio tower.", "Secure compound", ""];
tsk1 setSimpleTaskDestination (getMarkerPos "Guerrilla Camp");
player setCurrentTask tsk1;

//Group Respawn & teamSwitch fix
if (!isNil "tsk1done") then {tsk1 setTaskState "SUCCEEDED"; player setCurrentTask tsk2;};
if (!isNil "tsk2done") then {tsk2 setTaskState "SUCCEEDED"; player setCurrentTask tsk3;};
if (!isNil "tsk3done") then {tsk3 setTaskState "SUCCEEDED"; player setCurrentTask tsk4;};
if (!isNil "tsk4done") then {tsk4 setTaskState "SUCCEEDED";};