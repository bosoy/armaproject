waitUntil {!isNull player};

_subject1 = player createDiarySubject ["About","About"];
_subject1Tab1 = player createDiaryRecord ["About",["Author", "Made by Iron Eddie"]];

_subject2 = player createDiarySubject ["Briefing","Mission Information"];
_subject2Tab1 = player createDiaryRecord ["Briefing",["Situation","Our airport base at Rasman is under sporadic artillery attack. A sniper team of the US Army guys managed to find and eliminate the enemy Forward Observer. Since then they just keep firing at the SW part of the runway... The enemy artillery site is somewhere 3 to 4 kilometers south of the airport. We also have intel about <marker name=""town"">enemy infiltrating Bastam and the villages north of the town.</marker>	Our Forces are still bound in Operation Arrowhead. So we have to deal with the enemy with what we have here at the base."]];
_subject2Tab1 = player createDiaryRecord ["Briefing", ["Task","Your KSK Teams have to find the enemy artillery site somewhere near <marker name=""bastam"">Bastam.</marker> and destroy it. It may be heavily guarded, so we organized a combined operation with the remaining forces at the airbase (1 Mechanizes Squad, 1 Motorized Squad, and 2 M1A2). If you have found the arty site you can call them in to distract the guards at the arty site. Hopefully it works... If possible capture the commanding officer or members of his staff. If you can`t take POW just call HQ via radio to report mission done after main objectives are done."]];
_subject2Tab1 = player createDiaryRecord ["Briefing", ["Rules of Engagement","Avoid collateral damage. We can't afford to risk the civilian support."]];


// Mission progress
task3 = player createSimpleTask ["Sec Obj: "];
task3 setSimpleTaskDescription ["If possible capture the commanding officer or members of his staff. Bring them to your base. If you can`t take POW just call HQ via radio to report mission done after main objectives are done.", "Take POW at artillerie site.", "Take POW"];
task3 settaskstate "Created";

task2 = player createSimpleTask ["OBJ2: Kick the enemy out of this <marker name=""town"">town</marker>, make sure it is clear."];
task2 setSimpleTaskDescription ["<marker name=""town"">Clear the town</marker>.", "Clear town", "Clear"];
task2 settaskstate "Created";

task1 = player createSimpleTask ["OBJ1: Find the enemy artillery site around <marker name=""bastam"">Bastam</marker> and destroy it."];
task1 setSimpleTaskDescription ["<marker name=""bastam"">Find the enemy artillery site</marker> and destroy all guns. Try to take POW", "Destroy the artillery site", "Destroy"];
task1 settaskstate "Created";
player setCurrentTask task1;

[] spawn {
	waitUntil {(artyDestroyed)};
		task1 settaskstate "Succeeded";
};

[] spawn {
	waitUntil {(townClear)};
		task2 settaskstate "Succeeded";
};

[] spawn {
	waitUntil {(tookPrisoners)};
		task3 settaskstate "Succeeded";
};