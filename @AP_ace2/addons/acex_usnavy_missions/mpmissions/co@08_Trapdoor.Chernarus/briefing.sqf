waitUntil {!isNull player};
waitUntil { player == player };

player createDiaryRecord ["Diary", ["About", "Trapdoor v2.1 by AnimalMother92<br />Please report any feedback @<br />https://dev-heaven.net/projects/anm-missions [Bug tracker]<br />http://tinyurl.com/AnimalMother92 [BI Forums]<br />@R92B [Twitter]<br /><img image='AM92.paa'/><br />Made for Advanced Combat Environment"]];
player createDiaryRecord ["Diary", ["Mission", "A USMC <marker name=""convoy"">convoy</marker> was ambushed in <marker name=""vybor"">Vybor</marker> 10 minutes ago. We received distress calls from the survivors stating that they had been hit by RPGs and received heavy fire from the town. They were investigating a suspected <marker name=""cache"">ChDKZ depot</marker> in the town. Your team will assist Bravo's mechanized infantry in assaulting the town and securing the depot. Intelligence now suggests that the ChDKZ may be stronger in this region than was originally anticipated."]];
player createDiaryRecord ["Diary", ["Situation", "The majority of Chernarus is still considered hostile. Though the main Chedaki forces have been defeated, there is still some resistance in certain towns, even from civilians. Regular USMC patrols are being sent out to probe for enemy locations."]];
tsk2 = player createSimpleTask ["Assault depot"];
tsk2 setSimpleTaskDescription ["Assault the insurgent depot site.", "Assault depot", ""];
tsk2 setSimpleTaskDestination (getMarkerPos "cache");
tsk1 = player createSimpleTask ["Secure Vybor"];
tsk1 setSimpleTaskDescription ["Check the Marine convoy for survivors. Sweep Vybor and eliminate all enemy forces.", "Secure Vybor", ""];
tsk1 setSimpleTaskDestination (getMarkerPos "vybor");
player setCurrentTask tsk1;

//Group Respawn & teamSwitch fix
if (!isNil "tsk1done") then {tsk1 setTaskState "SUCCEEDED"; player setCurrentTask tsk2;};
if (!isNil "tsk2done") then {tsk2 setTaskState "SUCCEEDED";};