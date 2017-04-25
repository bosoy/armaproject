waitUntil {!isNull player};
waitUntil { player == player };

player createDiaryRecord ["Diary", ["About", "Hind in Sight v1.2 by AnimalMother92<br />Please report any feedback @<br />http://dev-heaven.net/projects/anm-missions [Bug tracker]<br />http://tinyurl.com/AnimalMother92 [BI Forums]<br />@R92B [Twitter]<br /><img image='AM92.paa'/><br />Made for Advanced Combat Environment"]];
player createDiaryRecord ["Diary", ["Mission", "After insertion via Osprey, make your way to the <marker name=""farp"">Russian helicopter FARP</marker> near Staroye. The objective is to knock out the attack helo (Mi-24 Hind) that is stationed there. After disabling the chopper, make your way to the <marker name=""gtfo"">pick up zone</marker>, where a Venom will extract your team."]];
player createDiaryRecord ["Diary", ["Situation", "Before the main forces move into Chernarus, several MARSOC raiding parties are being sent in to deal with key tactical sites. One such site is a forward arming and refueling point for a Hind helicopter. This bird poses a huge threat to any invading forces and so it is imperative that it is disabled ASAP. Intel on troop numbers in the vicinity is scarce, but no armor is expected. The FARP is in a relatively remote location and the enemy are unlikely to be expecting Marines on their doorstep."]];
tsk2 = player createSimpleTask ["Exfiltrate"];
tsk2 setSimpleTaskDescription ["Exfil from the FARP and get to the extraction helo.", "Exfiltrate", ""];
tsk2 setSimpleTaskDestination (getMarkerPos "gtfo");
tsk1 = player createSimpleTask ["Raid FARP"];
tsk1 setSimpleTaskDescription ["Destroy the Mi-24 Hind helicopter at the FARP.", "Raid FARP", ""];
tsk1 setSimpleTaskDestination (getMarkerPos "farp");
player setCurrentTask tsk1;

//Group Respawn & teamSwitch fix
if (!isNil "tsk1done") then {tsk1 setTaskState "SUCCEEDED"; player setCurrentTask tsk2;};
if (!isNil "tsk2done") then {tsk2 setTaskState "SUCCEEDED";};