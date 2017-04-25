player createDiaryRecord ["Diary", ["Second Objective", "Tell us with your radio when you're regrouped! The way to call us is: 0-0-1"]];

obj4 = player createSimpleTask["Take Grishino"];
obj4 setSimpleTaskDescription["Take Grishino<br/><br/>Take <marker name='grish'>Grishino</marker>! It's the last step to control the area.", "Take Grishino", "Take Grishino"];
obj4 setSimpleTaskDestination (getMarkerPos "grish");

obj3 = player createSimpleTask["Capture Novy Sobor and Stary Sobor"];
obj3 setSimpleTaskDescription["Capture Novy Sobor and Stary Sobor<br/><br/>Move to <marker name='novy'>Novy Sobor</marker> and capture it. Then, move to <marker name='stary'>Stary Sobor</marker> and take it!", "Capture Novy Sobor and Stary Sobor", "Capture Novy Sobor and Stary Sobor"];
obj3 setSimpleTaskDestination (getMarkerPos "zone_s");

obj2 = player createSimpleTask["Regroup"];
obj2 setSimpleTaskDescription["Regroup<br/><br/>Regroup at <marker name='regroup'>120063</marker>, North of Tchernogosk and prepare for the next objectives!", "Regroup", "Regroup"];
obj2 setSimpleTaskDestination (getMarkerPos "regroup");

obj1 = player createSimpleTask["Capture Tchernogosk"];
obj1 setSimpleTaskDescription["Capture Tchernogosk <br/><br/> You have to take <marker name='cherno'>Tchernogosk</marker>. Then, you'll be allowed to move to the North and attack remaining Russian forces in the area.", "Capture Tchernogosk", "Capture Tcherkogosk"];
obj1 setSimpleTaskDestination (getMarkerPos "cherno");

player setCurrentTask obj1