//waitUntil {!(isNull player)};
//waitUntil {player==player};

switch (side player) do
{
  case WEST:
  {
    player createDiaryRecord ["Diary", ["Credits", "<br />Created by Reezo of SR5 Tactical<br /><br />March 8th, 2011<br /><br /><br /><br />Visit us at: www.sr5tactical.net"]];
    player createDiaryRecord ["Diary", ["Support", "<br />No support available."]];
    player createDiaryRecord ["Diary", ["Mission", "<br />Allied forces are pushing to gain control of some towns in Southern Takistan. The civilian population is probably going to flee using the <marker name='helper_00'>Sar-e Sang Pass</marker>.<br /><br />Your job is to prevent insurgent forces and other enemy personnel leave the area and infiltrate the settlements North of your position."]];

    OBJ_REEZO_ROADBLOCKDUTY = player createSimpleTask ["Guard the roadblock"];
    OBJ_REEZO_ROADBLOCKDUTY setSimpleTaskDescription ["<br />Your fire team is assigned to watch a <marker name='loc_checkpoint'>remote checkpoint</marker> in order to keep insurgents from leaving town.","Guard the roadblock","Guard the roadblock"];
    player setCurrentTask OBJ_REEZO_ROADBLOCKDUTY;
  };
  
  case EAST:
  {
  };
};

if (true) exitWith {};