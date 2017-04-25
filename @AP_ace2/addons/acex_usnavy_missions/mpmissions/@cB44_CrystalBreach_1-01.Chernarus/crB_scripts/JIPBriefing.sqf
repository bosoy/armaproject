//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [2CAV]
// Created: 20090619
// Version: 20090620 - Initial release
// Contact: http://creobellum.org
// Purpose: Control briefing and tasks incl JIP
///////////////////////////////////////////////////////////////////
STR_CLEARMSR1 = "Clear Main Supply Route (1)";
STR_CLEARMSR2 = "Clear Main Supply Route (2)";
STR_CLEARMSR3 = "Clear Main Supply Route (3)";
STR_CLEARMSR4 = "Clear Main Supply Route (4)";
STR_ASSAULTMORTAR = "Capture Mortar Site";

taskSetup = {
	// Creating notes
	if(isNil "tskCredits") then {
		player createDiaryRecord ["Diary",["Credits", "Defenses, squads sizes, motor patrols and weather are randomised in this mission to play out differently everytime. Enjoy!<br/><br/>Mission concept by Williepete &amp; Delta 51<br/>Mission design by Wolffy.au<br/>Thanks to:<br/>    Briefing text by Delta 51<br/>    The ever willing mission testers from cB and AEF<br/>    Random Group Spawn code by Odin<br/>    Medical/Revive by Norrin<br/>        Team Status Dialog by Dr Eyeball<br/>    CEP Unit Caching and Move by Myke<br/>    CreateComposition by ArmaTec<br/>    ACE Weapons Box by Xeno<br/>    Improved AI Driving by Sakura Chan<br/>    Improved taskDefend and taskPatrol by Binesi<br/>    On-the-fly GFX Changer by Deadfast<br/>    Missions Conditions Selector - F2 MP Framework<br/><br/>Visit us a http://creoBellum.org"]];
		player createDiaryRecord ["Diary",["Current Intel", "Enemy forces are highly trained and are under orders to hold the route at all costs. The Company size troop is reinforced by another Company from the south and west of the Area of Operation (AO). Land and air troop carriers have been sighted and will engage if provoked.<br/><br/>A number of seek-and-destroy aerial patrols of varying configurations have been sighted and on occasion, have engaged the F.O.B. so beware.<br/><br/>The heavily fortfied Mortar emplacement on Mt Klen contains 3 x Podnos 2B14 mortars, which if captured can be used by friendly forces to secure the route.<br/><br/>Players can be revived in three ways; by medics, the HMMWV Ambulance and the MASH tent at base.<br/><br/>Unarmed HMMWV's will regularly respawn at base."]];
		player createDiaryRecord ["Diary",["Background", "Around 24hrs ago, SASR Reconnaissance patrols successfully secured data from a UAV providing enough evidence for the UN to grant us occupation of Chernarus on the grounds of genocide and warcrimes.<br/><br/>A small Forward Operating Base (FOB) has been established near the village Olsha. Our objectives for today, are to scout and secure a Main Supply Route (MSR) leading from the FOB, south along the main road, cutting off through the valley east to finish east of Khelm, just north of Berenzino Harbour. Khelm will be used as a FOB during the assault to take the deep water harbour which is critical to future operations; we need a suitable harbour to offload supplies from our Canberra class sitting off the shore.<br/><br/>The Australian Government have deployed troops in the area with the task of securing the docks of Berenzino Harbour to receive supplies and further establish U.N. forces.<br/><br/>The MSR is to be used to transport troops and supplies to Khelm for the forthcoming assault. The enemy know we want that harbour and so expect some heavy defences along the proposed MSR."]];
		tskCredits = true;
	};

	// Creating tasks
	if(isNil "tskObj5") then {
		tskObj5 = player createSimpleTask [STR_ASSAULTMORTAR];
		tskObj5 setSimpleTaskDescription ["Secondary Objective: Locate and secure the <marker name='MORTARS'>enemy Mortar Emplacement</marker> in the area.", STR_ASSAULTMORTAR, STR_ASSAULTMORTAR];
		tskObj5 setSimpleTaskDestination (getMarkerPos "MORTARS");
	};
	if(isNil "tskObj4") then {
		tskObj4 = player createSimpleTask [STR_CLEARMSR4];
		tskObj4 setSimpleTaskDescription ["Primary Objective 4: Clear <marker name='MSR4'>Main Supply Route (4)</marker> to the loading docks in the Bay of Khelm.", STR_CLEARMSR4, STR_CLEARMSR4];
		tskObj4 setSimpleTaskDestination (getMarkerPos "MSR4");
	};
	if(isNil "tskObj3") then {
		tskObj3 = player createSimpleTask [STR_CLEARMSR3];
		tskObj3 setSimpleTaskDescription ["Primary Objective 3: Clear <marker name='MSR3'>Main Supply Route (3)</marker> to the loading docks in the Bay of Khelm.", STR_CLEARMSR3, STR_CLEARMSR3];
		tskObj3 setSimpleTaskDestination (getMarkerPos "MSR3");
	};
	if(isNil "tskObj2") then {
		tskObj2 = player createSimpleTask [STR_CLEARMSR2];
		tskObj2 setSimpleTaskDescription ["Primary Objective 2: Clear <marker name='MSR2'>Main Supply Route (2)</marker> to the loading docks in the Bay of Khelm.", STR_CLEARMSR2, STR_CLEARMSR2];
		tskObj2 setSimpleTaskDestination (getMarkerPos "MSR2");
	};
	if(isNil "tskObj1") then {
		tskObj1 = player createSimpleTask [STR_CLEARMSR1];
		tskObj1 setSimpleTaskDescription ["Primary Objective 1: Clear <marker name='MSR1'>Main Supply Route (1)</marker> to the loading docks in the Bay of Khelm.", STR_CLEARMSR1, STR_CLEARMSR1];
		tskObj1 setSimpleTaskDestination (getMarkerPos "MSR1");
	};

};

task1 = {
	if (taskState tskObj1 != "SUCCEEDED") then {
		"MSR1" setMarkerColor "ColorGreen";
		"MSRAREA1" setMarkerColor "ColorGreen";
		tskObj1 setTaskState "SUCCEEDED";//"FAILED", "CANCELED", "CREATED"

		[west, "Base"] sideChat "Main supply route (1) cleared.";
	};
};

task2 = {
	if (taskState tskObj2 != "SUCCEEDED") then {
		"MSR2" setMarkerColor "ColorGreen";
		"MSRAREA2" setMarkerColor "ColorGreen";
		tskObj2 setTaskState "SUCCEEDED";//"FAILED", "CANCELED", "CREATED"

		[west, "Base"] sideChat "Main supply route (2) cleared.";
	};
};

task3 = {
	if (taskState tskObj3 != "SUCCEEDED") then {
		"MSR3" setMarkerColor "ColorGreen";
		"MSRAREA3" setMarkerColor "ColorGreen";
		tskObj3 setTaskState "SUCCEEDED";//"FAILED", "CANCELED", "CREATED"

		[west, "Base"] sideChat "Main supply route (3) cleared.";
	};
};

task4 = {
	if (taskState tskObj4 != "SUCCEEDED") then {
		"MSR4" setMarkerColor "ColorGreen";
		"MSRAREA4" setMarkerColor "ColorGreen";
		tskObj4 setTaskState "SUCCEEDED";//"FAILED", "CANCELED", "CREATED"

		[west, "Base"] sideChat "Main supply route (4) cleared.";
	};
};

task5 = {
	if (taskState tskObj5 != "SUCCEEDED") then {
		"MORTARS" setMarkerColor "ColorGreen";
		"MORTARAREA" setMarkerColor "ColorGreen";
		tskObj5 setTaskState "SUCCEEDED";//"FAILED", "CANCELED", "CREATED"

		[west, "Base"] sideChat "Enemy mortar emplacement captured and available to provide friendly support.";
	};
};

Briefing = {
	_select = _this select 0;
	if (!isNil "_select") then {
		switch (_select) do {
			case 1: {
				if(!(tasksPublicVariable select 0)) then {
					[] call task1;
					tasksPublicVariable set [0, true];
				};
			};
			case 2: {
				if(!(tasksPublicVariable select 1)) then {
					[] call task2;
					tasksPublicVariable set [1, true];
				};
			};
			case 3: {
				if(!(tasksPublicVariable select 2)) then {
					[] call task3;
					tasksPublicVariable set [2, true];
				};
			};
			case 4: {
				if(!(tasksPublicVariable select 3)) then {
					[] call task4;
					tasksPublicVariable set [3, true];
				};
			};
			case 5: {
				if(!(tasksPublicVariable select 4)) then {
					[] call task5;
					tasksPublicVariable set [4, true];
				};
			};
		};
		PublicVariable "tasksPublicVariable";
	} else {
		if (isNil "tskCredits") then {
			[] call taskSetup;
		};
		if (tasksPublicVariable select 0) then {
			[] call task1;
		};
		if (tasksPublicVariable select 1) then {
			[] call task2;
		};
		if (tasksPublicVariable select 2) then {
			[] call task3;
		};
		if (tasksPublicVariable select 3) then {
			[] call task4;
		};
		if (tasksPublicVariable select 4) then {
			[] call task5;
		};
	};
};

_task = _this select 0;
//hint format["Outside: %1", tasksPublicVariable];
PublicVariable "tasksPublicVariable";
[_task] call Briefing;

"tasksPublicVariable" addPublicVariableEventHandler {
//	hint format["Inside: %1", tasksPublicVariable];
	[] call Briefing;
};
