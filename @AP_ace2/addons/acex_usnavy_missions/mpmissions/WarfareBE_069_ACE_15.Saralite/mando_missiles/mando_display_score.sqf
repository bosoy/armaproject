_scoret = "<t color='#ffffff' size='2.2' shadow='1'shadowColor='#999999'>MMA SCORE</t><br />";
_scoret = _scoret + format["<t size='2.2'><t align='left'><img size='4' color='#88aaaa' image='%1'/> %2</t></t><br />", 
					getText (configFile>>"cfgVehicles">>"AV8B">>"picture"),mando_score_planes];
_scoret = _scoret + format["<t size='2.2'><t align='left'><img size='4' color='#88aaaa' image='%1'/> %2</t></t><br />", 
					getText (configFile>>"cfgVehicles">>"Mi17_Ins">>"picture"),mando_score_choppers];
_scoret = _scoret + format["<t size='2.2'><t align='left'><img size='4' color='#88aaaa' image='%1'/> %2</t></t><br />", 
					getText (configFile>>"cfgVehicles">>"M1A1">>"picture"),mando_score_tanks];
_scoret = _scoret + format["<t size='2.2'><t align='left'><img size='4' color='#88aaaa' image='%1'/> %2</t></t><br />", 
					getText (configFile>>"cfgVehicles">>"Ural_Base">>"picture"),mando_score_cars];
_scoret = _scoret + format["<t size='2.2'><t align='left'><img size='4' color='#88aaaa' image='%1'/> %2</t></t><br />", 
					getText (configFile>>"cfgVehicles">>"RHIB">>"picture"),mando_score_ships];
_scoret = _scoret + format["<t size='2.2'><t align='left'><img size='4' color='#88aaaa' image='%1'/> %2</t></t><br />", 
					getText (configFile>>"cfgVehicles">>"M119">>"picture"),mando_score_static];
_scoret = _scoret + format["<t size='2.2'><t align='left'><img size='4' color='#88aaaa' image='%1'/> %2</t></t><br />", 
					getText (configFile>>"cfgVehicles">>"USMC_Soldier">>"portrait"),mando_score_crews];
_scoret = _scoret + format["<t size='2.2'><t align='left'><img size='4' color='#88aaaa' image='%1'/> %2</t></t><br />", 
					getText (configFile>>"cfgMagazines">>"Javelin">>"picture"),mando_score_missiles];					
if (isMultiplayer) then
{					
   _scoret = _scoret + format["<t color='#ffffaa' size='1.5' shadow='1'shadowColor='#999999'>SC:%1</t><br />", score player];
};
hintSilent parseText _scoret;
