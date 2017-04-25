waitUntil {!isNull player};
waitUntil { player == player };

player createDiaryRecord ["Diary", ["About", "Steamroller v1.2 by AnimalMother92<br />Please report any feedback @<br />https://dev-heaven.net/projects/anm-missions [Bug tracker]<br />http://tinyurl.com/AnimalMother92 [BI Forums]<br />@R92B [Twitter]<br /><img image='AM92.paa'/><br />Made for Advanced Combat Environment"]];
player createDiaryRecord ["Diary", ["Mission", "Now that the mortar fire has ceased, infantry from Alpha Squad will dismount and advance into Karachinar to clean up the remaining insurgent forces. Apprehension of the village elder is of great importance. Due to the IED threat, vehicles are to remain outside the village."]];
player createDiaryRecord ["Diary", ["Situation", "Earlier this afternoon, Alpha Squad was tasked with entering <marker name=""village"">Karachinar</marker>, with the intention of making contact with the village elder. However, the Marines were ambushed upon their arrival and it appears that Karachinar is pro-Takiban. Alpha's M1A1 Abrams was disabled by a large IED and the convoy received small arms fire from the village. USMC batteries quickly responded with mortar fire, quelling the insurgent assault."]];
tsk2 = player createSimpleTask ["Arrest elder"];
tsk2 setSimpleTaskDescription ["Locate the elder and take him captive.", "Arrest elder", ""];
tsk2 setSimpleTaskDestination (getMarkerPos "elder");
tsk1 = player createSimpleTask ["Clear town"];
tsk1 setSimpleTaskDescription ["Advance into Karachinar and eliminate any hostile units.", "Clear town", ""];
tsk1 setSimpleTaskDestination (getMarkerPos "village");
player setCurrentTask tsk1;

//Group Respawn & teamSwitch fix
if (!isNil "tsk1done") then {tsk1 setTaskState "SUCCEEDED"; player setCurrentTask tsk2;};
if (!isNil "tsk2done") then {tsk2 setTaskState "SUCCEEDED";};