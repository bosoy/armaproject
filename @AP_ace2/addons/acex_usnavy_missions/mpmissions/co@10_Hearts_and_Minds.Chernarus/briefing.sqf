waitUntil { !isNull player };
waitUntil { player == player };

if (isNil "Alpha") then {
	Alpha = grpNull;
};
if (isNil "NAPA") then {
	NAPA = grpNull;
};
switch ((group player)) do {
  case Alpha: {
	player createDiaryRecord ["Diary", ["About", "Hearts & Minds v2.1 by AnimalMother92<br />Please report any feedback @<br />http://dev-heaven.net/projects/anm-missions [Bug tracker]<br />http://tinyurl.com/AnimalMother92 [BI Forums]<br />@R92B [Twitter]<br /><img image='AM92.paa'/><br />Made for Advanced Combat Environment"]];
	player createDiaryRecord ["Diary", ["Mission", "Your four-man SF team will <marker name=""lz"">insert</marker> via Little Bird at dawn. You will then proceed to <marker name=""rally"">rendezvous</marker> with indigenous forces for an assault on <marker name=""secure"">Vyshnoye</marker>. The objective is to eliminate a known insurgent leader in the area. Air support will be available to you once you have cleared the <marker name=""aa"">anti-air location</marker>. Vyshnoye is completely under ChDKZ control. They'll be expecting small skirmishes with NAPA fighters, not steel rain from some Apaches. However, the Apaches cannot be called until the anti-air site is cleared. Expect scattered patrols in the hills and heavier enemy forces closer to town."]];
	player createDiaryRecord ["Diary", ["Situation", "Civil war has been raging in Chernarus for the past several months. The pro-Communist ChDKZ and the pro-West NAPA factions have been slaughtering eachother without much of a clear winner so far. We need to change that. Before the Marines hit the beaches, it is of great importance that America has a connection with the locals. The Army's Green Berets are being sent to contact a NAPA group and take out a ChDKZ leader who is known to be a war criminal. Do this, and we win the good Chernarussian's hearts and minds..."]];
	tsk4 = player createSimpleTask ["Eliminate HVT"];
	tsk4 setSimpleTaskDescription ["Locate and execute the high value target, a known insurgent leader.", "Eliminate HVT", ""];
	tsk4 setSimpleTaskDestination (getMarkerPos "hvt");
	tsk3 = player createSimpleTask ["Secure Vyshnoye"];
	tsk3 setSimpleTaskDescription ["Call Apache air support and clear Vyshnoye of insurgent forces.", "Secure Vyshnoye", ""];
	tsk3 setSimpleTaskDestination (getMarkerPos "secure");
	tsk2 = player createSimpleTask ["Secure AA threat"];
	tsk2 setSimpleTaskDescription ["Secure the anti-air site so that close air support can be called.", "Secure AA threat", ""];
	tsk2 setSimpleTaskDestination (getMarkerPos "aa");
	tsk1 = player createSimpleTask ["Link-up with local forces"];
	tsk1 setSimpleTaskDescription ["Meet the indigenous forces at the RV point and prepare to assault Vyshnoye.", "Link-up with local forces", ""];
	tsk1 setSimpleTaskDestination (getMarkerPos "rally");
	player setCurrentTask tsk1;
  };
  case NAPA: {
    player createDiaryRecord ["Diary", ["About", "Hearts & Minds v2.1 by AnimalMother92<br />Please report any feedback @<br />http://dev-heaven.net/projects/anm-missions [Bug tracker]<br />http://tinyurl.com/AnimalMother92 [BI Forums]<br />@R92B [Twitter]<br /><img image='AM92.paa'/><br />Made for Advanced Combat Environment"]];
	player createDiaryRecord ["Diary", ["Mission", "We have made contact with the American forces and they are sending a special forces team to meet with us. Our goal is to annihilate the local Chedaki warlord that has plagued Chernarus for years."]];
    player createDiaryRecord ["Diary", ["Situation", "Civil war has been raging in Chernarus for the past several months. While NAPA seeks to bring peace to the region, the ChDKZ seek to ruin our great nation. It is time to put an end to this brothers."]];
	tsk1napa = player createSimpleTask ["Wait for SF Team"];
    tsk1napa setSimpleTaskDescription ["Hold position at the rally point until the US special forces team arrives.", "Wait for SF Team", ""];
	tsk1napa setSimpleTaskDestination (getMarkerPos "rally");
    player setCurrentTask tsk1napa;
  };
};

//Group Respawn & teamSwitch fix
if (!isNil "tsk1done") then {tsk1 setTaskState "SUCCEEDED"; player setCurrentTask tsk2;};
if (!isNil "tsk2done") then {tsk2 setTaskState "SUCCEEDED"; player setCurrentTask tsk3;};
if (!isNil "tsk3done") then {tsk3 setTaskState "SUCCEEDED"; player setCurrentTask tsk4;};
if (!isNil "tsk4done") then {tsk4 setTaskState "SUCCEEDED";};