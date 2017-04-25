waitUntil {!isNull player};
waitUntil { player == player };

player createDiaryRecord ["Diary", ["About", "Crash & Grab v2.1 by AnimalMother92<br />Please report any feedback @<br />http://dev-heaven.net/projects/anm-missions [Bug tracker]<br />http://tinyurl.com/AnimalMother92 [BI Forums]<br />@R92B [Twitter]<br /><img image='AM92.paa'/><br />Made for Advanced Combat Environment"]];
player createDiaryRecord ["Diary", ["Mission", "A US pilot experienced mechanical issues with his plane and went down while performing a recon mission over Chernarus. Intelligence has confirmed that he has been captured by OPFOR troops and is being held at an artillery camp in <marker name=""camp"">Nadezhdino</marker>. Your task is to infiltrate the camp and secure the <marker name=""hostage"">pilot</marker>, and then proceed to the <marker name=""Extract"">extraction point</marker>. Be advised that there is a <marker name=""qrf"">quick reaction force</marker> located to the south. Once contact has been made, it is likely that an enemy force will arrive to investigate the area. Speed is crucial in getting the pilot to safety."]];
player createDiaryRecord ["Diary", ["Situation", "Conventional American forces are not yet in Chernarus. The enemy is unlikely to be expecting an assault, especially in this poor weather. The pilot that has been captured was flying over Chernarus on reconaissance in order to provide intel for the main invasion forces. His bird has been confirmed as completely destroyed. Enemy forces are known to be in and around <marker name=""camp"">Nadezhdino</marker>."]];
tsk2 = player createSimpleTask ["Extract"];
tsk2 setSimpleTaskDescription ["Escort the pilot to the extraction point and wait for the evac chopper.", "Extract", ""];
tsk2 setSimpleTaskDestination (getMarkerPos "Extract");
tsk1 = player createSimpleTask ["Rescue pilot"];
tsk1 setSimpleTaskDescription ["Infiltrate the artillery camp in Nadezhdino and secure the downed pilot for extraction.", "Rescue pilot", ""];
tsk1 setSimpleTaskDestination (getMarkerPos "Hostage");
player setCurrentTask tsk1;

//Group Respawn & teamSwitch fix
if (!isNil "tsk1done") then {tsk1 setTaskState "SUCCEEDED"; player setCurrentTask tsk2;};
if (!isNil "tsk2done") then {tsk2 setTaskState "SUCCEEDED";};