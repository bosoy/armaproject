waitUntil {!(isNull player)};
waitUntil {player==player};
switch (side player) do
{
case WEST:
{
player createDiaryRecord ["Diary",["About","- [co08] OP Streetsweeper - Version 1.52(ACE) - made by Moerderhoschi ( Moerderhoschi@gmx.de) in 2010"]];

player createDiaryRecord ["Diary",["Used Scripts","Norrin's Revieve v0.5"]];

player createDiaryRecord ["Diary",["Revive","Infantry units can heal themself 3 times and revive 5 times, medics can revive 50 times."]];

player createDiaryRecord ["Diary",["Weapons and Equipment","You can choose your Weapons and Equipment at the Missionstartpoint there is a Ammobox."]];

tskObj7=player createSimpleTask ["Clear Area"];
tskObj7 setSimpleTaskDescription ["Clear the <marker name='t8m'>Area</marker>.","Clear Area","Clear Area"];

tskObj6=player createSimpleTask ["Kill Warlord"];
tskObj6 setSimpleTaskDescription ["Kill the enemy <marker name='t7m'>Warlord</marker>.","Kill Warlord","Kill Warlord"];

tskObj5=player createSimpleTask ["Destroy Trucks"];
tskObj5 setSimpleTaskDescription ["Destroy the enemy <marker name='t6m'>Trucks</marker>.","Destroy Trucks","Destroy Trucks"];

tskObj4=player createSimpleTask ["Destroy Radar"];
tskObj4 setSimpleTaskDescription ["Destroy the enemy <marker name='t5m'>Radar</marker>.","Destroy Radar","Destroy Radar"];

tskObj3=player createSimpleTask ["Destroy Mortars"];
tskObj3 setSimpleTaskDescription ["Destroy the enemy <marker name='t4m'>Mortars</marker>.","Destroy Mortars","Destroy Mortars"];

tskObj2=player createSimpleTask ["Destroy Cars"];
tskObj2 setSimpleTaskDescription ["Destroy the enemy <marker name='t3m'>Cars</marker>.","Destroy Cars","Destroy Cars"];

tskObj1=player createSimpleTask ["Destroy Weaponsdepot"];
tskObj1 setSimpleTaskDescription ["Destroy the enemy <marker name='t2m'>Weaponsdepot</marker>.","Destroy Weaponsdepot","Destroy Weaponsdepot"];

tskObj0=player createSimpleTask ["Clear Landay"];
tskObj0 setSimpleTaskDescription ["Clear <marker name='t1m'>Landay</marker> from enemys.","Clear Landay","Clear Landay"];
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