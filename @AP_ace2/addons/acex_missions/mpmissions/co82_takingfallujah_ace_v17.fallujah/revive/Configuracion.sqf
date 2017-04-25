/***********************************************************************************************************************************/
/*************************************************Seccion de configuracion***********************************************************/
/***********************************************************************************************************************************/
//Disable IA wounding system for IA, seems to cause more desync.
ace_sys_wounds_noai= true;

//Total time that units remains uncon before die, in seconds
ace_wounds_prevtime = 400;

//If true, spectator will be activated wile uncons, if false you will see a black screen while uncons.
ace_sys_wounds_withSpect  = false;

//Show team kill mesages
Colum_revive_TKcheck= true;

//Show enemy units when you are totally death, true= show all, false = only your side.
Colum_revive_VerEnemigos= true;

//Pvp enabled, markers and uncons mesages only will be seen by your teammates
Colum_revive_PvP=true;

//Medic rucksack. "" for disabled any other rucksack classname to enable
Colum_revive_MochilaMedico="ACE_VTAC_RUSH72_TT_MEDIC";

//Contents for the rucksack
// the contents are: [nº vandages, nº morphine, nº ephinifrine, nº green smoke grenades]
Colum_revive_MochilaMedico_Contenido=[20,20,20,2];

//Jip players wil have an option to teleport to his squadmates when conected. True = allow, False = not allow
Colum_revive_JIPTelep=false;

//allow respawn . false= if you get out of uncons time you will die even if you had lives left. true= if you get out of time you will respawn on the designated respawn if you had lives left
Colum_revive_Respawn=true;

//Side respawns . false= everybody has the same respawn. true= each side has his own respawn points
Colum_revive_Respawn_Side=false;

//Side lifes . false=everybody has the same number of lifes. true= each side has his own number of lifes
Colum_revive_Vidas_Side= false;

//Death map Markers, false= no markers, true= wounded units would be shown on the map.
Colum_revive_Death_Markers= false;

//Death Messages . false=no mesages. true= a mesage will be shown when someone falls uncons.
Colum_revive_Death_Messages= false;

//death people leave group . Recomended true, only false if you use a stupid script that uses the leader unit to get the group in the middle of the game.
Colum_revive_Death_LeaveGroup= true;

//Minimun damage left after been healed with the medkit.  0 disabled. Values recomended 0.01-0.08
ace_sys_wounds_leftdam=0;

//On medic revive make full heal( so you don't need to use medkit after revive, only for normal healing). True enabled, false (Default) disabled
Colum_revive_Levanta_Heal=false;

//Penalice Respawn button with Death. If true, if you press the respawn button you are out of the game, if false, you will only lose a life
Colum_revive_RespawnButtonPunish=false;

//New metod is faster, but right now produces problems with CPR
Colum_revive_New_LastLife_metod=true;

//If server fails to send the number of lifes,  set it to 0. If set to false, if fails, you will get all the lifes
Colum_revive_KillOnConnectFail=true;



if (Colum_revive_Respawn) then {
//Text of the respawn buttons
	ace_sys_spectator_RevButtons = ["respawn1", "respawn2", "respawn3", "respawn4"];
	//other example : ace_sys_spectator_RevButtons = ["respawn1", "respawn2"]; 
//Name of the markers for the respawn( could be diferent from the text)
	Colum_revive_RespawnMarkers= ["respawn1", "respawn2", "respawn3", "respawn4"];
//offset for the respawn point. Usefull for example to define respawn inside buildings or in the carrier.
	Colum_revive_RespawnOffset= [0,0,0,0];
	
//Time to appear the respawn buttons
	ace_sys_spectator_RevShowButtonTime = 80;
	
	if (Colum_revive_Respawn_Side) then {
		// Side respawns
		//Bluefor
		Colum_revive_RevButtons_WEST = ["respawn1_WEST", "respawn2_WEST", "respawn3_WEST", "respawn4_WEST"];
		Colum_revive_RespawnMarkers_WEST= ["respawn1_WEST", "respawn2_WEST", "respawn3_WEST", "respawn4_WEST"];
		Colum_revive_RespawnOffset_WEST=[0,0,0,0];
		
		//oppfor
		Colum_revive_RevButtons_EAST = ["respawn1_EAST", "respawn2_EAST", "respawn3_EAST", "respawn4_EAST"];
		Colum_revive_RespawnMarkers_EAST= ["respawn1_EAST", "respawn2_EAST", "respawn3_EAST", "respawn4_EAST"];
		Colum_revive_RespawnOffset_EAST=[0,0,0,0];
		
		//Independ
		Colum_revive_RevButtons_GUER = ["respawn1_GUER", "respawn2_GUER", "respawn3_GUER", "respawn4_GUER"];
		Colum_revive_RespawnMarkers_GUER= ["respawn1_GUER", "respawn2_GUER", "respawn3_GUER", "respawn4_GUER"];
		Colum_revive_RespawnOffset_GUER=[0,0,0,0];
			
		//Civil
		Colum_revive_RevButtons_CIV = ["respawn1_CIV", "respawn2_CIV", "respawn3_CIV", "respawn4_CIV"];
		Colum_revive_RespawnMarkers_CIV= ["respawn1_CIV", "respawn2_CIV", "respawn3_CIV", "respawn4_CIV"];
		Colum_revive_RespawnOffset_CIV=[0,0,0,0];
		
	};

	ace_sys_spectator_fnc_rbutton1={0 spawn AccionesRevive};
	ace_sys_spectator_fnc_rbutton2={1 spawn AccionesRevive};
	ace_sys_spectator_fnc_rbutton3={2 spawn AccionesRevive};
	ace_sys_spectator_fnc_rbutton4={3 spawn AccionesRevive};
	
};

if (Colum_revive_Vidas_Side) then {
	//Vidas para el bando bluefor
	Colum_revive_VidasMax_WEST=2;
	
	//Vidas para el bando Opfor
	Colum_revive_VidasMax_EAST=3;
	
	//Vidas para el bando indepen
	Colum_revive_VidasMax_GUER=4;
	
	//Vidas para el bando civil
	Colum_revive_VidasMax_CIV=10;
};



/***********************************************************************************************************************************/
/****************************************************FIN configuracion**************************************************************/
/***********************************************************************************************************************************/