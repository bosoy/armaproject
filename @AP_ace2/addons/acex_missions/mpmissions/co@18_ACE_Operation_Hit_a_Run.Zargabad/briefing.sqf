waitUntil {!(isNull player)};
waitUntil {player==player};
switch (side player) do
{
case WEST:
{
player createDiaryRecord ["Diary",["About","- [co18] Operation Hit and Run (ACE) - made by Moerderhoschi ( Moerderhoschi@gmx.de) in 2010"]];

player createDiaryRecord ["Diary",["Thanks to","Thanks to burns, Cyborg11, Vienna and Xeno for their help and support in the Armed-Assault.de Forum.<br/>Thanks to Matula and Ranzavoll for their support at Missiontesting."]];

player createDiaryRecord ["Diary",["Used Scripts","Norrin's Revieve v0.5 / Cyborg11's HALO Jump / Lurchi's AC130 Gunship"]];

player createDiaryRecord ["Diary",["Revive","Infantry units can heal themself 3 times and revive 5 times, medics can revive 50 times."]];

player createDiaryRecord ["Diary",["Weapons and Equipment","You can choose your Weapons and Equipment at the Missionstartpoint, there are a Ammobox."]];

player createDiaryRecord ["Diary",["Intelligence","One of our Drones spotted <marker name='target5marker'>Colonel Aziz</marker> at the Army-Base near Hazar Bagh. Find and liquidate him, but first destroy the <marker name='target1marker'>Radar</marker> on top of the hill and destroy the <marker name='target2marker'>Choppers</marker> in the Army-Base that the Enemy can't encounter our Aircrafts.<br/><br/> Our Drones spotted several Armored Forces in the Area, better you take some AT-Weapons with you."]];

tskObj4=player createSimpleTask ["Liquidate Col.Aziz"];
tskObj4 setSimpleTaskDescription ["Find and liquidate <marker name='target5marker'>Colonel Aziz</marker>.","Liquidate Col.Aziz","Liquidate Col.Aziz"];

tskObj1=player createSimpleTask ["Destroy the Choppers"];
tskObj1 setSimpleTaskDescription ["Destroy the enemy <marker name='target2marker'>Choppers</marker> that the Enemy has no Airsupport anymore.","Destroy the Choppers","Destroy the Choppers"];

tskObj0=player createSimpleTask ["Destroy the Radar"];
tskObj0 setSimpleTaskDescription ["Destroy the Enemy <marker name='target1marker'>Radar</marker> on top of the Hill that the Enemy can't seize our Aircrafts.","Destroy the Radar","Destroy the Radar"];

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