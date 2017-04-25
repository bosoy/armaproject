//waitUntil {!(isNull player)};
//waitUntil {player==player};

switch (side player) do
{
  case WEST:
  {
    player createDiaryRecord ["Diary", ["Credits", "<br />Created by Reezo of SR5 Tactical<br /><br />September 4th, 2010<br /><br />IED script by: James (00DC15)<br />AGM support script by: Venori, with tweaks by Kilania and AnimalMother92.<br />Virtual UAV and Reaper Relay tweaks by Reezo.<br /><br /><br /><br />Visit us at: www.sr5tactical.net"]];
    player createDiaryRecord ["Diary", ["Support", "<br />Two MLRS stationed in FOB Arizona.<br /><br />In addition an UAV drone can provide aerial reconnaisance."]];
    player createDiaryRecord ["Diary", ["Execution", "<br /><marker name='fob_arizona'>FOB Arizona</marker> and <marker name='fob_jester'>FOB Jester</marker> are your reference points. The streets and towns in-between these two bases are relatively safe but this is no excuse to lower your attention. The UN have established a supply depot at <marker name='resource'>Resource</marker> and a medical station at <marker name='hotel'>Hotel</marker>."]];
    player createDiaryRecord ["Diary", ["Situation", "<br />Insurgents presence was reported <marker name='border'>East</marker> and <marker name='border_1'>West</marker> of the AO. US and British troops patrol the area on a regular basis but the situation still has not cooled down yet so keep your eyes open."]];
    player createDiaryRecord ["Diary", ["Mission", "<br />There is much to do here. Check your tasks, gear up and get moving."]];
    player createDiaryRecord ["Diary", ["Briefing", "<br />Takistani Insurgents are still present in the area. This war is far from over. This is just a day in the life."]];

    OBJ_BTR = player createSimpleTask ["Destroy BTRs"];
    OBJ_REPAIRS = player createSimpleTask ["Assist UNO trucks"];
    OBJ_STASHY = player createSimpleTask ["Eliminate Bombmakers"];
    OBJ_STASH = player createSimpleTask ["Destroy Weapons Stash"];
    OBJ_CHOPPERS = player createSimpleTask ["Take Down Choppers"];
    OBJ_URAL = player createSimpleTask ["Relocate Supply Truck"];
    OBJ_SNIPERS = player createSimpleTask ["Enemy Snipers"];
    OBJ_LALEZAR = player createSimpleTask ["Clear Lalezar"];
    OBJ_MINES = player createSimpleTask ["Clear Minefield"];
    OBJ_EUROMAN1 = player createSimpleTask ["Escort Tourist"];
    OBJ_IED1 = player createSimpleTask ["Disarm IED"];
    
    OBJ_URAL setSimpleTaskDescription ["<br />The UN must move an URAL truck from <marker name='resource'>Resource</marker> to <marker name='fob_arizona'>FOB Arizona</marker>. Go there, get on the truck and take it to our FOB.","Relocate Supply Truck","Relocate Supply Truck"];
    OBJ_SNIPERS setSimpleTaskDescription ["<br />An enemy sniper team was recently spotted in the area. Aerial reconnaisance has reasons to believe the team has relocated somewhere in <marker name='snipers_loc'>this area</marker>. Eliminate this threat.","Enemy Snipers","Enemy Snipers"];
    OBJ_LALEZAR setSimpleTaskDescription ["<br />Takistani insurgents are stationing in the <marker name='lalezar'>industrial area of Lalezar</marker>. The proximity with FOB Arizona makes it a dangerous area for potential AA attacks. Clear the area from the opposition.","Clear Lalezars","Clear Lalezar"];
    OBJ_MINES setSimpleTaskDescription ["<br />Two Bradleys directed to FOB Arizona had to halt their course because of a <marker name='minefield_loc'>minefield</marker>. Take an engineer there and clear the road from any mine. When you are done, use the radio to tell the convoy to proceed.","Clear Minefield","Clear Minefield"];
    OBJ_EUROMAN1 setSimpleTaskDescription ["<br />Some people just cannnot believe this is not a place for a vacation. A French tourist has <marker name='euroman1_loc'>lost his way</marker> and is afraid the Takis might kidnap him. Take him to <marker name='fob_arizona'>FOB Arizona</marker>.","Escort Tourist","Escort Tourist"];
    OBJ_IED1 setSimpleTaskDescription ["<br />Locals informed us of a possible Improvised Explosive Device (IED) at <marker name='ied1_loc'>this location</marker>. Win some minds and hearts: take an engineer there and defuse the bomb.<br /><br />Be very careful about these explosive devices: most of them need to be triggered manually and this means the -trigger man- has to be somewhere near the IED to detonate it. Most terrorists would use a house or a cover of some kind with good visual on the bomb location. Taking the triggerman down is usually the safest bet.","Disarm IED","Disarm IED"];
    OBJ_STASH setSimpleTaskDescription ["<br />Intel located a small enemy outpost. We have reason to believe the Takis are building IEDs at <marker name='stash_loc'>this location</marker>. Destroy the stash.","Destroy Weapons Stash","Destroy Weapons Stash"];
    OBJ_CHOPPERS setSimpleTaskDescription ["<br />Takistani Choppers have been moving troops from one side of the AO to the other. With our recent victories they are now crossing our air space. Take them down: they have been following <marker name='chopperspath_loc'>this route</marker> for days. Find a suitable attack point and destroy the choppers.","Take Down Choppers","Take Down Choppers"];
    OBJ_STASHY setSimpleTaskDescription ["<br />Locals informed us of an imminent trade between different cells of the Taki militia: warlords are distributing IEDs and other explosive ordnance to go on with their terrororist actions. Storm <marker name='loc_stashy'>this location</marker>, destroy the explosives stashe and kill the warlords.","Eliminate Bombmakers","Eliminate Bombmakers"];
    OBJ_REPAIRS setSimpleTaskDescription ["<br />UNO trucks have been attacked by insurgents. The enemy has been neutralized but the trucks cannot move. Reach <marker name='loc_repairs'>this location</marker> and repair the trucks so that they can reach their destination.","Assist UNO trucks","Assist UNO trucks"];
    OBJ_BTR setSimpleTaskDescription ["<br />The Takis are conducting combined arms training in the Eastern Region of the AO. Destroy the BTR trucks by taking advantage of their known rally points: <marker name='loc_btr'>here</marker> and <marker name='loc_btr2'>here</marker>.","Destroy BTRs","Destroy BTRs"];
    };
  
  case EAST:
  {
  };
};

if (true) exitWith {};