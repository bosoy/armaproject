/* Header */

//--- Respawn options.
respawn = 3;
respawnDelay = WF_RESPAWNDELAY;
respawnDialog = false;

//--- Require briefing.html to show up.
onLoadMission = WF_MISSIONNAME;
onLoadMissionTime = false;

//--- ArrowHead loadscreen.
#ifndef VANILLA
	loadScreen = WF_LOADSCREEN;
#endif

//--- Properties.
class Header {
	gameType = CTI;
	minPlayers = 1;
	maxPlayers = WF_MAXPLAYERS;
};