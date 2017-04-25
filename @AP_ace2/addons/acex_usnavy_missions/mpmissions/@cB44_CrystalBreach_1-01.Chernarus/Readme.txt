Operation Crystal Breach

The basic premise of the mission is to secure the Main Supply Route (MSR).

Defenses, squads sizes, motor patrols and weather are randomised in this mission to play out differently everytime. Enjoy!

Mission concept by Williepete & Delta 51
Mission design by Wolffy.au

Thanks to:
    Briefing text by Delta 51
    The ever willing mission testers from cB and AEF
    Random Group Spawn code by Odin
    Medical/Revive by Norrin
    Team Status Dialog by Dr Eyeball
    CEP Unit Caching and Move by Myke
    CreateComposition by ArmaTec
    ACE Weapons Box by Xeno
    Simple Vehicle Respawn Script by Tophe of Östgöta Ops
    Improved AI Driving by Sakura Chan
    Improved taskDefend and taskPatrol by Binesi
    On-the-fly GFX Changer by Deadfast
    Missions Conditions Selector - F2 MP Framework

Visit us a http://creoBellum.org

Developer notes:
Here is a list of nifty components to be found in this mission.

Random Group Spawn code by Odin
- This piece of code has turned out to be the most important piece of my future mission making. Using GameLogic objects, this code will spawn random enemy groups of Infantry, Motorised, Mechanised, Armour and Air. In conjunction with Binesi's taskDefend and taskPatrol code, randomised mission making has never been simpler.

Medical/Revive by Norrin
- Need I say more, code that turned ARMA on its head and continues to enhance ARMA II like no other piece of scripting.

Team Status Dialog by Dr Eyeball
- Allows the customisations of groups while playing the mission. As suggested by the Dr himself, I'm sure other clans will find it very useful.

CEP Unit Caching by Myke
- This code is originally from Myke's ARMA I Coop Essentials Pack. I have heavily modified it and it now supports vehicle units. 

CreateComposition/CreateCompositionLocal by ArmaTec
- If you don't know what compositions are yet, make sure you find out. I modified this code to spawn aesthetic objects locally on the client and mounted objects (MG Nests, etc) on the server so the AI can man them. It cut down the server workload by 90%. Extremely handy code if you use lots of compositions.
- If you want to create your own compositions (this mission has an RU checkpoint), CreateCompositionLocal will use custom composition code.

Improved taskDefend and taskPatrol by Binesi
- Binesi posted these improved BIS functions around the same time I was asking myself the same question. Placing patrols and defensive squads has never been simpler.

ACE Weapons Box by Xeno
- Xeno did all the coding to create these ammo boxes, so I think he deserves a mention for their use.

On-the-fly GFX Changer by Deadfast
- Simple graphical viewdistance and terrain control. Very slick interface, although I've hardcoded the terrain detail in this mission, as I didn't think it was fair on the AI.

Missions Conditions Selector - F2 MP Framework
- Another handy script, I modified it slightly for JIP client time setting, but it works a treat otherwise.

Simple Vehicle Respawn Script by Tophe of Östgöta Ops
- A vehicle respawn script used to provide transport to JIP players.

Improved AI Driving by Sakura Chan
- Improves AI driving skills dramatically, in particularly on roads.

creoBellum scripts:
Here are some of my own scripts, which you are free to use with credits intact.

Random Group Generation (crb_randomGroup.sqf)
- This is a must have for randomising your mission. Will create random squads of Infantry, Motorised, Mechanised, Armoured and Air. Makes the mission different everytime.

Reinforcements (crb_reinforcements.sqf)
- This is great for minimising the number of AI while maintaining a large Area of Operation. When enemy units are reduced to a low level, they will be reinforced and transported by land and air to the specific area.

Aerial Patrol (AerialPatrol.sqf)
- A quick script that spawns an aerial patrol for your Area of Operation, who will happily engage if they spot you. I've had units successfully patrol for over 3 hours into a mission. A new group will respawn if you destroy the current patrol.

JIP Briefing (JIPBriefing.sqf)
- JIP Briefings are a real pain. This is my current model for consecutive objectives which is JIP compatible.

Enemy weapon reload (RUStaticRearm.sqf)
- This script will scan ammo levels across all static enemy DSHKM, AGS, D30, and MG Nests, and re-arm them to keep up the fire fight.

JIP Markers (JIPMarkers.sqf)
- If you create markers dynamically (not in the editor), you'll find that JIP clients will not get them. This is a bit of code to get around that issue.

Player Weapon Loadout (PlayerInit.sqf)
- Sets up weapon loadout based on mission selector and unit model. Works for human and AI playable units.

Minefields (crB_Minefields.sqf)
- Drop a marker and create a minefield. Great for funneling players into kill zones.

Hide Bodies (crB_HideCorpses.sqf)
- Inspired by Mr Murrays code, this one liner will remove dead bodies from the mission with no additional triggers or objects. Just add the script to your Init.sqf - very simple.

WaypointPatrol.sqf
- Uses markers to patrol vehicles randomly from one marker to another. Excellent to ensure all parts of your Area of Operation are patrolled.