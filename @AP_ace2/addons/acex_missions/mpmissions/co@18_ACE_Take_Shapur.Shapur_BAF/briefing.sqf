waitUntil {!isNull player};
waitUntil {player==player};
switch (side player) do
{
case WEST:
{
player createDiaryRecord ["Diary",["About","- [co18] Take Shapur - Version 1.2 (ACE) - made by Moerderhoschi ( Moerderhoschi@gmx.de) in 2010"]];

player createDiaryRecord ["Diary",["Used Scripts","Norrin's Revieve v0.5"]];

player createDiaryRecord ["Diary",["Revive","Infantry units can heal themself 3 times and revive 5 times, medics can revive 50 times."]];

player createDiaryRecord ["Diary",["Weapons and Equipment","You can choose your Weapons and Equipment at the Missionstartpoint, there are a Ammobox."]];

tskObj5=player createSimpleTask ["Clear Areas"];
tskObj5 setSimpleTaskDescription ["Clear those Areas <marker name='oel1'>Area1</marker> <marker name='oel2'>Area2</marker> <marker name='oel3'>Area3</marker> <marker name='oel4'>Area4</marker> <marker name='oel5'>Area5</marker> <marker name='oel6'>Area6</marker> .","Clear Areas","Clear Areas"];

tskObj4=player createSimpleTask ["Destroy Planes"];
tskObj4 setSimpleTaskDescription ["Destroy the enemy <marker name='t5m'>Planes</marker>.","Destroy Planes","Destroy Planes"];

tskObj3=player createSimpleTask ["Destroy Helis"];
tskObj3 setSimpleTaskDescription ["Destroy the enemy <marker name='t4m'>Helis</marker>.","Destroy Helis","Destroy Helis"];

tskObj2=player createSimpleTask ["Kill Colonel"];
tskObj2 setSimpleTaskDescription ["Kill the enemy <marker name='t3m'>Colonel</marker>.","Kill Colonel","Kill Colonel"];

tskObj1=player createSimpleTask ["Destroy Radar"];
tskObj1 setSimpleTaskDescription ["Destroy the enemy <marker name='t2m'>Radar</marker>.","Destroy Radar","Destroy Radar"];

tskObj0=player createSimpleTask ["Destroy Mortars"];
tskObj0 setSimpleTaskDescription ["Destroy the enemy <marker name='t1m'>Mortars</marker>.","Destroy Mortars","Destroy Mortars"];

player setCurrentTask tskObj0;
};
case EAST:
{
};
case RESISTANCE:
{
};
case CIVILIAN:
{
};
};