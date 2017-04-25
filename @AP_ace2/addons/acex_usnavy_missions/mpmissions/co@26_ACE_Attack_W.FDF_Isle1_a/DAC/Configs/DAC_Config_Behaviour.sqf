//////////////////////////////
//    Dynamic-AI-Creator    //
//    Version 3.0 - 2010    //
//--------------------------//
//    DAC_Config_Behaviour  //
//--------------------------//
//    Script by Silola      //
//    silola@freenet.de     //
//////////////////////////////

private [
			"_array","_setSkill","_setCombat","_setBehav","_setSpeed","_setForm","_setPatrol","_setSearch",
			"_setFleeing","_setHeliVal","_setPause","_setBldgBeh","_setSupport","_setJoin","_setEmpVeh","_setSupTime","_setHidTime"
		];

switch (_this select 0) do
{
//-------------------------------------------------------------------------------------------------------------------------
	case 0:
	{
		_setSkill   = [0.2,0.7];
		_setCombat  = ["green","white","yellow"];
		_setBehav   = ["careless","safe","aware"];
		_setSpeed   = ["limited","normal","full"];
		_setForm    = ["line","vee","column","wedge","stag column","ech left","ech right","file","diamond"];
		_setFleeing = [0,100];
		_setHeliVal = [45,100,0.7,1];
		_setPause   = [[5,10],[5,10],[5,10],[20,30,5,5],[1,3],[0,0]];
		_setBldgBeh = [3,50,120,600,1];
		_setPatrol  = ["45 + (20 * (skill _leader))","(60 + (random 60)) + ((skill _leader) * 50)"];
		_setSearch  = ["40 + ((skill _leader) * 150)","50 + ((skill _leader) * 50)"];
		_setSupport = [1,1];
		_setJoin    = 2;
		_setEmpVeh  = [[150,100],[150,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 1:
	{
		_setSkill   = [0.2,0.7];
		_setCombat  = ["green","white","yellow"];
		_setBehav   = ["careless","safe","aware"];
		_setSpeed   = ["limited","normal","full"];
		_setForm    = ["line","vee","column","wedge","stag column","ech left","ech right","file","diamond"];
		_setFleeing = [0,100];
		_setHeliVal = [45,100,0.7,1];
		_setPause   = [[5,10],[5,10],[5,10],[20,30,5,5],[1,3],[0,0]];
		_setBldgBeh = [3,50,120,600,1];
		_setPatrol  = ["45 + (20 * (skill _leader))","(60 + (random 60)) + ((skill _leader) * 50)"];
		_setSearch  = ["40 + ((skill _leader) * 150)","50 + ((skill _leader) * 50)"];
		_setSupport = [1,2];
		_setJoin    = 2;
		_setEmpVeh  = [[150,100],[150,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 2:
	{
		_setSkill   = [0.2,0.7];
		_setCombat  = ["green","white","yellow"];
		_setBehav   = ["careless","safe","aware"];
		_setSpeed   = ["limited","normal","full"];
		_setForm    = ["line","vee","column","wedge","stag column","ech left","ech right","file","diamond"];
		_setFleeing = [0,100];
		_setHeliVal = [45,100,0.7,1];
		_setPause   = [[5,10],[5,10],[5,10],[20,30,5,5],[1,3],[0,0]];
		_setBldgBeh = [3,50,120,600,1];
		_setPatrol  = ["45 + (20 * (skill _leader))","(60 + (random 60)) + ((skill _leader) * 50)"];
		_setSearch  = ["40 + ((skill _leader) * 150)","50 + ((skill _leader) * 50)"];
		_setSupport = [1,3];
		_setJoin    = 2;
		_setEmpVeh  = [[150,100],[150,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 3:
	{
		_setSkill   = [0.2,0.7];
		_setCombat  = ["green","white","yellow"];
		_setBehav   = ["careless","safe","aware"];
		_setSpeed   = ["limited","normal","full"];
		_setForm    = ["line","vee","column","wedge","stag column","ech left","ech right","file","diamond"];
		_setFleeing = [0,100];
		_setHeliVal = [45,100,0.7,1];
		_setPause   = [[5,10],[5,10],[5,10],[20,30,5,5],[1,3],[0,0]];
		_setBldgBeh = [3,50,120,600,1];
		_setPatrol  = ["45 + (20 * (skill _leader))","(60 + (random 60)) + ((skill _leader) * 50)"];
		_setSearch  = ["40 + ((skill _leader) * 150)","50 + ((skill _leader) * 50)"];
		_setSupport = [1,4];
		_setJoin    = 2;
		_setEmpVeh  = [[150,100],[150,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 100:  // save
	{
		_setSkill = [0.3,0.9];
		_setCombat = ["white","yellow"];
		_setBehav = ["safe"];
		_setSpeed = ["limited"];
		_setForm =  ["column","stag column"];
		_setFleeing = [0.3,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[5,50],[5,50],[5,50],[80,180,5,10],[1,3],[0,0]];
		_setBldgBeh = [0,50,180,600];
		_setPatrol = ["35 + (20 * (skill _leader))","(30 + (random 30)) + ((skill _leader) * 50)"];
		_setSearch = ["20 + ((skill _leader) * 150)","30 + ((skill _leader) * 50)"];
		_setSupport = [1,101];
		_setJoin =  1;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 101: // aggressive patrol
	{
		_setSkill = [0.3,0.9];
		_setCombat = ["yellow","red"];
		_setBehav = ["aware","Combat"];
		_setSpeed = ["normal","full"];
		_setForm =  ["line","vee","column","wedge","stag column","ech left","ech right","file","diamond"];
		_setFleeing = [0.1,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[10,30],[10,30],[10,30],[60,130,5,10],[1,3],[0,0]];
		_setBldgBeh = [4,50,100,600];
		_setPatrol = ["5 + (5 * (skill _leader))","(5 + (random 10)) + ((skill _leader) * 5)"];
		_setSearch = ["50 + ((skill _leader) * 150)","50 + ((skill _leader) * 50)"];
		_setSupport = [1,102];
		_setJoin =  1;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 102: // hunter force
	{
		_setSkill = [0.7,0.9];
		_setCombat = ["yellow","red"];
		_setBehav = ["Combat"];
		_setSpeed = ["normal","full"];
		_setForm =  ["vee","line","wedge","ech left","ech right","file","diamond"];
		_setFleeing = [0,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[3,5],[3,5],[5,10],[20,30,5,5],[1,3],[0,0]];
		_setBldgBeh = [2,70,60,100];
		_setPatrol = ["45 + (30 * (skill _leader))","(70 + (random 40)) + ((skill _leader) * 50)"];
		_setSearch = ["100 + ((skill _leader) * 150)","120 + ((skill _leader) * 50)"];
		_setSupport = [1,101];
		_setJoin =  0;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 103: // passive patrol
	{
		_setSkill = [0.3,0.9];
		_setCombat = ["white","yellow"];
		_setBehav = ["safe"];
		_setSpeed = ["limited"];
		_setForm =  ["column","stag column"];
		_setFleeing = [0.3,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[30,50],[30,50],[30,50],[120,180,5,10],[1,3],[0,0]];
		_setBldgBeh = [4,80,300,300];
		_setPatrol = ["85 + (60 * (skill _leader))","(120 + (random 60)) + ((skill _leader) * 50)"];
		_setSearch = ["40 + ((skill _leader) * 150)","40 + ((skill _leader) * 50)"];
		_setSupport = [1,103];
		_setJoin =  1;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	// For base patrol etc
	case 104:
	{
		_setSkill = [0.5,0.8];
		_setCombat = ["yellow"];
		_setBehav = ["safe","aware"];
		_setSpeed = ["limited", "normal"];
		_setForm =  ["line","column","stag column"];
		_setFleeing = [0,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[3,5],[3,5],[5,10],[20,30,5,5],[1,3],[0,0]];
		_setBldgBeh = [2,50,120,600];
		_setPatrol = ["35 + (20 * (skill _leader))","(30 + (random 30)) + ((skill _leader) * 50)"];
		_setSearch = ["20 + ((skill _leader) * 150)","30 + ((skill _leader) * 50)"];
		_setSupport = [1,101];
		_setJoin =  0;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	// Sniper Patrol
	case 105:
	{
	_setSkill = [0.7,0.9];
	_setCombat = ["red"];
	_setBehav = ["stealth"];
	_setSpeed = ["limited"];
	_setForm = ["line","vee","column","wedge","stag column","ech left","ech right","file","diamond"];
	_setFleeing = [0.1,100];
	_setHeliVal = [35,45,0.7,1];
	_setPause = [[300,300],[300,180],[300,180],[200,20,5,5],[120,30],[0,0]];
	_setBldgBeh = [4,100,180,60];
	_setPatrol = ["35 + (20 * (skill _leader))","(30 + (random 30)) + ((skill _leader) * 50)"];
	_setSearch = ["100 + ((skill _leader) * 150)","180 + ((skill _leader) * 50)"];
	_setSupport = [1,103];
	_setJoin = 0;
	_setEmpVeh = [[100,100],[100,100]];
	_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};

//-------------------------------------------------------------------------------------------------------------------------
	// No Support (50+)
	case 150: // save
	{
		_setSkill = [0.3,0.9];
		_setCombat = ["white","yellow"];
		_setBehav = ["safe"];
		_setSpeed = ["limited"];
		_setForm =  ["column","stag column"];
		_setFleeing = [0.3,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[5,50],[5,50],[5,50],[80,180,5,10],[1,3],[0,0]];
		_setBldgBeh = [0,50,180,600];
		_setPatrol = ["35 + (20 * (skill _leader))","(30 + (random 30)) + ((skill _leader) * 50)"];
		_setSearch = ["20 + ((skill _leader) * 150)","30 + ((skill _leader) * 50)"];
		_setSupport = [0,101];
		_setJoin =  1;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 151: // aggressive patrol
	{
		_setSkill = [0.3,0.9];
		_setCombat = ["yellow","red"];
		_setBehav = ["aware","Combat"];
		_setSpeed = ["normal","full"];
		_setForm =  ["line","vee","column","wedge","stag column","ech left","ech right","file","diamond"];
		_setFleeing = [0.1,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[10,30],[10,30],[10,30],[60,130,5,10],[1,3],[0,0]];
		_setBldgBeh = [4,50,100,600];
		_setPatrol = ["5 + (5 * (skill _leader))","(5 + (random 10)) + ((skill _leader) * 5)"];
		_setSearch = ["50 + ((skill _leader) * 150)","50 + ((skill _leader) * 50)"];
		_setSupport = [0,102];
		_setJoin =  1;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 152: // hunter force
	{
		_setSkill = [0.7,0.9];
		_setCombat = ["yellow","red"];
		_setBehav = ["Combat"];
		_setSpeed = ["normal","full"];
		_setForm =  ["vee","line","wedge","ech left","ech right","file","diamond"];
		_setFleeing = [0,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[3,5],[3,5],[5,10],[20,30,5,5],[1,3],[0,0]];
		_setBldgBeh = [2,70,60,100];
		_setPatrol = ["45 + (30 * (skill _leader))","(70 + (random 40)) + ((skill _leader) * 50)"];
		_setSearch = ["100 + ((skill _leader) * 150)","120 + ((skill _leader) * 50)"];
		_setSupport = [0,101];
		_setJoin =  0;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 153: // passive patrol
	{
		_setSkill = [0.3,0.9];
		_setCombat = ["white","yellow"];
		_setBehav = ["safe"];
		_setSpeed = ["limited"];
		_setForm =  ["column","stag column"];
		_setFleeing = [0.3,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[30,50],[30,50],[30,50],[120,180,5,10],[1,3],[0,0]];
		_setBldgBeh = [4,80,300,300];
		_setPatrol = ["85 + (60 * (skill _leader))","(120 + (random 60)) + ((skill _leader) * 50)"];
		_setSearch = ["40 + ((skill _leader) * 150)","40 + ((skill _leader) * 50)"];
		_setSupport = [0,103];
		_setJoin =  1;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	// For base patrol etc
	case 154:
	{
		_setSkill = [0.5,0.8];
		_setCombat = ["yellow"];
		_setBehav = ["safe","aware"];
		_setSpeed = ["limited", "normal"];
		_setForm =  ["line","column","stag column"];
		_setFleeing = [0,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[3,5],[3,5],[5,10],[20,30,5,5],[1,3],[0,0]];
		_setBldgBeh = [2,50,120,600];
		_setPatrol = ["35 + (20 * (skill _leader))","(30 + (random 30)) + ((skill _leader) * 50)"];
		_setSearch = ["20 + ((skill _leader) * 150)","30 + ((skill _leader) * 50)"];
		_setSupport = [0,101];
		_setJoin =  0;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	// Sniper Patrol
	case 155:
	{
	_setSkill = [0.7,0.9];
	_setCombat = ["red"];
	_setBehav = ["stealth"];
	_setSpeed = ["limited"];
	_setForm = ["line","vee","column","wedge","stag column","ech left","ech right","file","diamond"];
	_setFleeing = [0.1,100];
	_setHeliVal = [35,45,0.7,1];
	_setPause = [[300,300],[300,180],[300,180],[200,20,5,5],[120,30],[0,0]];
	_setBldgBeh = [4,100,180,60];
	_setPatrol = ["35 + (20 * (skill _leader))","(30 + (random 30)) + ((skill _leader) * 50)"];
	_setSearch = ["100 + ((skill _leader) * 150)","180 + ((skill _leader) * 50)"];
	_setSupport = [0,1];
	_setJoin = 0;
	_setEmpVeh = [[100,100],[100,100]];
	_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------
	case 200:  // save
	{
		_setSkill = [0.3,0.9];
		_setCombat = ["white","yellow"];
		_setBehav = ["safe"];
		_setSpeed = ["limited"];
		_setForm =  ["column","stag column"];
		_setFleeing = [0.3,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[5,50],[5,50],[5,50],[80,180,5,10],[1,3],[0,0]];
		_setBldgBeh = [0,50,180,600];
		_setPatrol = ["35 + (20 * (skill _leader))","(30 + (random 30)) + ((skill _leader) * 50)"];
		_setSearch = ["20 + ((skill _leader) * 150)","30 + ((skill _leader) * 50)"];
		_setSupport = [1,101];
		_setJoin =  1;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 201: // aggressive patrol
	{
		_setSkill = [0.3,0.9];
		_setCombat = ["yellow","red"];
		_setBehav = ["aware","Combat"];
		_setSpeed = ["normal","full"];
		_setForm =  ["line","vee","column","wedge","stag column","ech left","ech right","file","diamond"];
		_setFleeing = [0.1,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[10,30],[10,30],[10,30],[60,130,5,10],[1,3],[0,0]];
		_setBldgBeh = [4,50,100,600];
		_setPatrol = ["5 + (5 * (skill _leader))","(5 + (random 10)) + ((skill _leader) * 5)"];
		_setSearch = ["50 + ((skill _leader) * 150)","50 + ((skill _leader) * 50)"];
		_setSupport = [1,102];
		_setJoin =  1;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 202: // hunter force
	{
		_setSkill = [0.7,0.9];
		_setCombat = ["yellow","red"];
		_setBehav = ["Combat"];
		_setSpeed = ["normal","full"];
		_setForm =  ["vee","line","wedge","ech left","ech right","file","diamond"];
		_setFleeing = [0,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[3,5],[3,5],[5,10],[20,30,5,5],[1,3],[0,0]];
		_setBldgBeh = [2,70,60,100];
		_setPatrol = ["45 + (30 * (skill _leader))","(70 + (random 40)) + ((skill _leader) * 50)"];
		_setSearch = ["100 + ((skill _leader) * 150)","120 + ((skill _leader) * 50)"];
		_setSupport = [1,101];
		_setJoin =  0;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 203: // passive patrol
	{
		_setSkill = [0.3,0.9];
		_setCombat = ["white","yellow"];
		_setBehav = ["safe"];
		_setSpeed = ["limited"];
		_setForm =  ["column","stag column"];
		_setFleeing = [0.3,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[30,50],[30,50],[30,50],[120,180,5,10],[1,3],[0,0]];
		_setBldgBeh = [4,80,300,300];
		_setPatrol = ["85 + (60 * (skill _leader))","(120 + (random 60)) + ((skill _leader) * 50)"];
		_setSearch = ["40 + ((skill _leader) * 150)","40 + ((skill _leader) * 50)"];
		_setSupport = [1,103];
		_setJoin =  1;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	// For base patrol etc
	case 204:
	{
		_setSkill = [0.5,0.8];
		_setCombat = ["yellow"];
		_setBehav = ["safe","aware"];
		_setSpeed = ["limited", "normal"];
		_setForm =  ["line","column","stag column"];
		_setFleeing = [0,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[3,5],[3,5],[5,10],[20,30,5,5],[1,3],[0,0]];
		_setBldgBeh = [2,50,120,600];
		_setPatrol = ["35 + (20 * (skill _leader))","(30 + (random 30)) + ((skill _leader) * 50)"];
		_setSearch = ["20 + ((skill _leader) * 150)","30 + ((skill _leader) * 50)"];
		_setSupport = [1,101];
		_setJoin =  0;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	// Sniper Patrol
	case 205:
	{
	_setSkill = [0.7,0.9];
	_setCombat = ["red"];
	_setBehav = ["stealth"];
	_setSpeed = ["limited"];
	_setForm = ["line","vee","column","wedge","stag column","ech left","ech right","file","diamond"];
	_setFleeing = [0.1,100];
	_setHeliVal = [35,45,0.7,1];
	_setPause = [[300,300],[300,180],[300,180],[200,20,5,5],[120,30],[0,0]];
	_setBldgBeh = [4,100,180,60];
	_setPatrol = ["35 + (20 * (skill _leader))","(30 + (random 30)) + ((skill _leader) * 50)"];
	_setSearch = ["100 + ((skill _leader) * 150)","180 + ((skill _leader) * 50)"];
	_setSupport = [1,103];
	_setJoin = 0;
	_setEmpVeh = [[100,100],[100,100]];
	_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	// No Support (50+)
	case 250: // save
	{
		_setSkill = [0.3,0.9];
		_setCombat = ["white","yellow"];
		_setBehav = ["safe"];
		_setSpeed = ["limited"];
		_setForm =  ["column","stag column"];
		_setFleeing = [0.3,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[5,50],[5,50],[5,50],[80,180,5,10],[1,3],[0,0]];
		_setBldgBeh = [0,50,180,600];
		_setPatrol = ["35 + (20 * (skill _leader))","(30 + (random 30)) + ((skill _leader) * 50)"];
		_setSearch = ["20 + ((skill _leader) * 150)","30 + ((skill _leader) * 50)"];
		_setSupport = [0,101];
		_setJoin =  1;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 251: // aggressive patrol
	{
		_setSkill = [0.3,0.9];
		_setCombat = ["yellow","red"];
		_setBehav = ["aware","Combat"];
		_setSpeed = ["normal","full"];
		_setForm =  ["line","vee","column","wedge","stag column","ech left","ech right","file","diamond"];
		_setFleeing = [0.1,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[10,30],[10,30],[10,30],[60,130,5,10],[1,3],[0,0]];
		_setBldgBeh = [4,50,100,600];
		_setPatrol = ["5 + (5 * (skill _leader))","(5 + (random 10)) + ((skill _leader) * 5)"];
		_setSearch = ["50 + ((skill _leader) * 150)","50 + ((skill _leader) * 50)"];
		_setSupport = [0,102];
		_setJoin =  1;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 252: // hunter force
	{
		_setSkill = [0.7,0.9];
		_setCombat = ["yellow","red"];
		_setBehav = ["Combat"];
		_setSpeed = ["normal","full"];
		_setForm =  ["vee","line","wedge","ech left","ech right","file","diamond"];
		_setFleeing = [0,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[3,5],[3,5],[5,10],[20,30,5,5],[1,3],[0,0]];
		_setBldgBeh = [2,70,60,100];
		_setPatrol = ["45 + (30 * (skill _leader))","(70 + (random 40)) + ((skill _leader) * 50)"];
		_setSearch = ["100 + ((skill _leader) * 150)","120 + ((skill _leader) * 50)"];
		_setSupport = [0,101];
		_setJoin =  0;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 253: // passive patrol
	{
		_setSkill = [0.3,0.9];
		_setCombat = ["white","yellow"];
		_setBehav = ["safe"];
		_setSpeed = ["limited"];
		_setForm =  ["column","stag column"];
		_setFleeing = [0.3,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[30,50],[30,50],[30,50],[120,180,5,10],[1,3],[0,0]];
		_setBldgBeh = [4,80,300,300];
		_setPatrol = ["85 + (60 * (skill _leader))","(120 + (random 60)) + ((skill _leader) * 50)"];
		_setSearch = ["40 + ((skill _leader) * 150)","40 + ((skill _leader) * 50)"];
		_setSupport = [0,103];
		_setJoin =  1;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	// For base patrol etc
	case 254:
	{
		_setSkill = [0.5,0.8];
		_setCombat = ["yellow"];
		_setBehav = ["safe","aware"];
		_setSpeed = ["limited", "normal"];
		_setForm =  ["line","column","stag column"];
		_setFleeing = [0,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[3,5],[3,5],[5,10],[20,30,5,5],[1,3],[0,0]];
		_setBldgBeh = [2,50,120,600];
		_setPatrol = ["35 + (20 * (skill _leader))","(30 + (random 30)) + ((skill _leader) * 50)"];
		_setSearch = ["20 + ((skill _leader) * 150)","30 + ((skill _leader) * 50)"];
		_setSupport = [0,101];
		_setJoin =  0;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	// Sniper Patrol
	case 255:
	{
	_setSkill = [0.7,0.9];
	_setCombat = ["red"];
	_setBehav = ["stealth"];
	_setSpeed = ["limited"];
	_setForm = ["line","vee","column","wedge","stag column","ech left","ech right","file","diamond"];
	_setFleeing = [0.1,100];
	_setHeliVal = [35,45,0.7,1];
	_setPause = [[300,300],[300,180],[300,180],[200,20,5,5],[120,30],[0,0]];
	_setBldgBeh = [4,100,180,60];
	_setPatrol = ["35 + (20 * (skill _leader))","(30 + (random 30)) + ((skill _leader) * 50)"];
	_setSearch = ["100 + ((skill _leader) * 150)","180 + ((skill _leader) * 50)"];
	_setSupport = [0,1];
	_setJoin = 0;
	_setEmpVeh = [[100,100],[100,100]];
	_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------
	case 300:  // save
	{
		_setSkill = [0.3,0.9];
		_setCombat = ["white","yellow"];
		_setBehav = ["safe"];
		_setSpeed = ["limited"];
		_setForm =  ["column","stag column"];
		_setFleeing = [0.3,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[5,50],[5,50],[5,50],[80,180,5,10],[1,3],[0,0]];
		_setBldgBeh = [4,50,180,600];
		_setPatrol = ["35 + (20 * (skill _leader))","(30 + (random 30)) + ((skill _leader) * 50)"];
		_setSearch = ["20 + ((skill _leader) * 150)","30 + ((skill _leader) * 50)"];
		_setSupport = [1,101];
		_setJoin =  1;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 301: // aggressive patrol
	{
		_setSkill = [0.3,0.9];
		_setCombat = ["yellow","red"];
		_setBehav = ["aware","Combat"];
		_setSpeed = ["normal","full"];
		_setForm =  ["line","vee","column","wedge","stag column","ech left","ech right","file","diamond"];
		_setFleeing = [0.1,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[10,30],[10,30],[10,30],[60,130,5,10],[1,3],[0,0]];
		_setBldgBeh = [4,50,100,600];
		_setPatrol = ["5 + (5 * (skill _leader))","(5 + (random 10)) + ((skill _leader) * 5)"];
		_setSearch = ["50 + ((skill _leader) * 150)","50 + ((skill _leader) * 50)"];
		_setSupport = [1,102];
		_setJoin =  1;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 302: // hunter force
	{
		_setSkill = [0.7,0.9];
		_setCombat = ["yellow","red"];
		_setBehav = ["Combat"];
		_setSpeed = ["normal","full"];
		_setForm =  ["vee","line","wedge","ech left","ech right","file","diamond"];
		_setFleeing = [0,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[3,5],[3,5],[5,10],[20,30,5,5],[1,3],[0,0]];
		_setBldgBeh = [2,70,60,100];
		_setPatrol = ["45 + (30 * (skill _leader))","(70 + (random 40)) + ((skill _leader) * 50)"];
		_setSearch = ["100 + ((skill _leader) * 150)","120 + ((skill _leader) * 50)"];
		_setSupport = [1,101];
		_setJoin =  0;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 303: // passive patrol
	{
		_setSkill = [0.3,0.9];
		_setCombat = ["white","yellow"];
		_setBehav = ["safe"];
		_setSpeed = ["limited"];
		_setForm =  ["column","stag column"];
		_setFleeing = [0.3,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[30,50],[30,50],[30,50],[120,180,5,10],[1,3],[0,0]];
		_setBldgBeh = [4,80,300,300];
		_setPatrol = ["85 + (60 * (skill _leader))","(120 + (random 60)) + ((skill _leader) * 50)"];
		_setSearch = ["40 + ((skill _leader) * 150)","40 + ((skill _leader) * 50)"];
		_setSupport = [1,103];
		_setJoin =  1;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	// For base patrol etc
	case 304:
	{
		_setSkill = [0.5,0.8];
		_setCombat = ["yellow"];
		_setBehav = ["safe","aware"];
		_setSpeed = ["limited", "normal"];
		_setForm =  ["line","column","stag column"];
		_setFleeing = [0,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[3,5],[3,5],[5,10],[20,30,5,5],[1,3],[0,0]];
		_setBldgBeh = [2,50,120,600];
		_setPatrol = ["35 + (20 * (skill _leader))","(30 + (random 30)) + ((skill _leader) * 50)"];
		_setSearch = ["20 + ((skill _leader) * 150)","30 + ((skill _leader) * 50)"];
		_setSupport = [1,101];
		_setJoin =  0;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	// Sniper Patrol
	case 305:
	{
	_setSkill = [0.7,0.9];
	_setCombat = ["red"];
	_setBehav = ["stealth"];
	_setSpeed = ["limited"];
	_setForm = ["line","vee","column","wedge","stag column","ech left","ech right","file","diamond"];
	_setFleeing = [0.1,100];
	_setHeliVal = [35,45,0.7,1];
	_setPause = [[300,300],[300,180],[300,180],[200,20,5,5],[120,30],[0,0]];
	_setBldgBeh = [4,100,180,60];
	_setPatrol = ["35 + (20 * (skill _leader))","(30 + (random 30)) + ((skill _leader) * 50)"];
	_setSearch = ["100 + ((skill _leader) * 150)","180 + ((skill _leader) * 50)"];
	_setSupport = [1,103];
	_setJoin = 0;
	_setEmpVeh = [[100,100],[100,100]];
	_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};

//-------------------------------------------------------------------------------------------------------------------------
	// No Support (50+)
	case 350: // save
	{
		_setSkill = [0.3,0.9];
		_setCombat = ["white","yellow"];
		_setBehav = ["safe"];
		_setSpeed = ["limited"];
		_setForm =  ["column","stag column"];
		_setFleeing = [0.3,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[5,50],[5,50],[5,50],[80,180,5,10],[1,3],[0,0]];
		_setBldgBeh = [0,50,180,600];
		_setPatrol = ["35 + (20 * (skill _leader))","(30 + (random 30)) + ((skill _leader) * 50)"];
		_setSearch = ["20 + ((skill _leader) * 150)","30 + ((skill _leader) * 50)"];
		_setSupport = [0,101];
		_setJoin =  1;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 351: // aggressive patrol
	{
		_setSkill = [0.3,0.9];
		_setCombat = ["yellow","red"];
		_setBehav = ["aware","Combat"];
		_setSpeed = ["normal","full"];
		_setForm =  ["line","vee","column","wedge","stag column","ech left","ech right","file","diamond"];
		_setFleeing = [0.1,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[10,30],[10,30],[10,30],[60,130,5,10],[1,3],[0,0]];
		_setBldgBeh = [4,50,100,600];
		_setPatrol = ["5 + (5 * (skill _leader))","(5 + (random 10)) + ((skill _leader) * 5)"];
		_setSearch = ["50 + ((skill _leader) * 150)","50 + ((skill _leader) * 50)"];
		_setSupport = [0,102];
		_setJoin =  1;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 352: // hunter force
	{
		_setSkill = [0.7,0.9];
		_setCombat = ["yellow","red"];
		_setBehav = ["Combat"];
		_setSpeed = ["normal","full"];
		_setForm =  ["vee","line","wedge","ech left","ech right","file","diamond"];
		_setFleeing = [0,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[3,5],[3,5],[5,10],[20,30,5,5],[1,3],[0,0]];
		_setBldgBeh = [2,70,60,100];
		_setPatrol = ["45 + (30 * (skill _leader))","(70 + (random 40)) + ((skill _leader) * 50)"];
		_setSearch = ["100 + ((skill _leader) * 150)","120 + ((skill _leader) * 50)"];
		_setSupport = [0,101];
		_setJoin =  0;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 353: // passive patrol
	{
		_setSkill = [0.3,0.9];
		_setCombat = ["white","yellow"];
		_setBehav = ["safe"];
		_setSpeed = ["limited"];
		_setForm =  ["column","stag column"];
		_setFleeing = [0.3,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[30,50],[30,50],[30,50],[120,180,5,10],[1,3],[0,0]];
		_setBldgBeh = [4,80,300,300];
		_setPatrol = ["85 + (60 * (skill _leader))","(120 + (random 60)) + ((skill _leader) * 50)"];
		_setSearch = ["40 + ((skill _leader) * 150)","40 + ((skill _leader) * 50)"];
		_setSupport = [0,103];
		_setJoin =  1;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	// For base patrol etc
	case 354:
	{
		_setSkill = [0.5,0.8];
		_setCombat = ["yellow"];
		_setBehav = ["safe","aware"];
		_setSpeed = ["limited", "normal"];
		_setForm =  ["line","column","stag column"];
		_setFleeing = [0,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[3,5],[3,5],[5,10],[20,30,5,5],[1,3],[0,0]];
		_setBldgBeh = [2,50,120,600];
		_setPatrol = ["35 + (20 * (skill _leader))","(30 + (random 30)) + ((skill _leader) * 50)"];
		_setSearch = ["20 + ((skill _leader) * 150)","30 + ((skill _leader) * 50)"];
		_setSupport = [0,101];
		_setJoin =  0;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	// Sniper Patrol
	case 355:
	{
	_setSkill = [0.7,0.9];
	_setCombat = ["red"];
	_setBehav = ["stealth"];
	_setSpeed = ["limited"];
	_setForm = ["line","vee","column","wedge","stag column","ech left","ech right","file","diamond"];
	_setFleeing = [0.1,100];
	_setHeliVal = [35,45,0.7,1];
	_setPause = [[300,300],[300,180],[300,180],[200,20,5,5],[120,30],[0,0]];
	_setBldgBeh = [4,100,180,60];
	_setPatrol = ["35 + (20 * (skill _leader))","(30 + (random 30)) + ((skill _leader) * 50)"];
	_setSearch = ["100 + ((skill _leader) * 150)","180 + ((skill _leader) * 50)"];
	_setSupport = [0,1];
	_setJoin = 0;
	_setEmpVeh = [[100,100],[100,100]];
	_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 400:  // save
	{
		_setSkill = [0.3,0.9];
		_setCombat = ["white","yellow"];
		_setBehav = ["safe"];
		_setSpeed = ["limited"];
		_setForm =  ["column","stag column"];
		_setFleeing = [0.3,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[5,50],[5,50],[5,50],[80,180,5,10],[1,3],[0,0]];
		_setBldgBeh = [0,50,180,600];
		_setPatrol = ["35 + (20 * (skill _leader))","(30 + (random 30)) + ((skill _leader) * 50)"];
		_setSearch = ["20 + ((skill _leader) * 150)","30 + ((skill _leader) * 50)"];
		_setSupport = [1,101];
		_setJoin =  1;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 401: // aggressive patrol
	{
		_setSkill = [0.3,0.9];
		_setCombat = ["yellow","red"];
		_setBehav = ["aware","Combat"];
		_setSpeed = ["normal","full"];
		_setForm =  ["line","vee","column","wedge","stag column","ech left","ech right","file","diamond"];
		_setFleeing = [0.1,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[10,30],[10,30],[10,30],[60,130,5,10],[1,3],[0,0]];
		_setBldgBeh = [4,50,100,600];
		_setPatrol = ["5 + (5 * (skill _leader))","(5 + (random 10)) + ((skill _leader) * 5)"];
		_setSearch = ["50 + ((skill _leader) * 150)","50 + ((skill _leader) * 50)"];
		_setSupport = [1,102];
		_setJoin =  1;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 402: // hunter force
	{
		_setSkill = [0.7,0.9];
		_setCombat = ["yellow","red"];
		_setBehav = ["Combat"];
		_setSpeed = ["normal","full"];
		_setForm =  ["vee","line","wedge","ech left","ech right","file","diamond"];
		_setFleeing = [0,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[3,5],[3,5],[5,10],[20,30,5,5],[1,3],[0,0]];
		_setBldgBeh = [2,70,60,100];
		_setPatrol = ["45 + (30 * (skill _leader))","(70 + (random 40)) + ((skill _leader) * 50)"];
		_setSearch = ["100 + ((skill _leader) * 150)","120 + ((skill _leader) * 50)"];
		_setSupport = [1,101];
		_setJoin =  0;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 403: // passive patrol
	{
		_setSkill = [0.3,0.9];
		_setCombat = ["white","yellow"];
		_setBehav = ["safe"];
		_setSpeed = ["limited"];
		_setForm =  ["column","stag column"];
		_setFleeing = [0.3,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[30,50],[30,50],[30,50],[120,180,5,10],[1,3],[0,0]];
		_setBldgBeh = [4,80,300,300];
		_setPatrol = ["85 + (60 * (skill _leader))","(120 + (random 60)) + ((skill _leader) * 50)"];
		_setSearch = ["40 + ((skill _leader) * 150)","40 + ((skill _leader) * 50)"];
		_setSupport = [1,103];
		_setJoin =  1;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	// For base patrol etc
	case 404:
	{
		_setSkill = [0.5,0.8];
		_setCombat = ["yellow"];
		_setBehav = ["safe","aware"];
		_setSpeed = ["limited", "normal"];
		_setForm =  ["line","column","stag column"];
		_setFleeing = [0,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[3,5],[3,5],[5,10],[20,30,5,5],[1,3],[0,0]];
		_setBldgBeh = [2,50,120,600];
		_setPatrol = ["35 + (20 * (skill _leader))","(30 + (random 30)) + ((skill _leader) * 50)"];
		_setSearch = ["20 + ((skill _leader) * 150)","30 + ((skill _leader) * 50)"];
		_setSupport = [1,101];
		_setJoin =  0;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	// Sniper Patrol
	case 405:
	{
	_setSkill = [0.7,0.9];
	_setCombat = ["red"];
	_setBehav = ["stealth"];
	_setSpeed = ["limited"];
	_setForm = ["line","vee","column","wedge","stag column","ech left","ech right","file","diamond"];
	_setFleeing = [0.1,100];
	_setHeliVal = [35,45,0.7,1];
	_setPause = [[300,300],[300,180],[300,180],[200,20,5,5],[120,30],[0,0]];
	_setBldgBeh = [4,100,180,60];
	_setPatrol = ["35 + (20 * (skill _leader))","(30 + (random 30)) + ((skill _leader) * 50)"];
	_setSearch = ["100 + ((skill _leader) * 150)","180 + ((skill _leader) * 50)"];
	_setSupport = [1,103];
	_setJoin = 0;
	_setEmpVeh = [[100,100],[100,100]];
	_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};

//-------------------------------------------------------------------------------------------------------------------------
	// No Support (50+)
	case 450: // save
	{
		_setSkill = [0.3,0.9];
		_setCombat = ["white","yellow"];
		_setBehav = ["safe"];
		_setSpeed = ["limited"];
		_setForm =  ["column","stag column"];
		_setFleeing = [0.3,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[5,50],[5,50],[5,50],[80,180,5,10],[1,3],[0,0]];
		_setBldgBeh = [0,50,180,600];
		_setPatrol = ["35 + (20 * (skill _leader))","(30 + (random 30)) + ((skill _leader) * 50)"];
		_setSearch = ["20 + ((skill _leader) * 150)","30 + ((skill _leader) * 50)"];
		_setSupport = [0,101];
		_setJoin =  1;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 451: // aggressive patrol
	{
		_setSkill = [0.3,0.9];
		_setCombat = ["yellow","red"];
		_setBehav = ["aware","Combat"];
		_setSpeed = ["normal","full"];
		_setForm =  ["line","vee","column","wedge","stag column","ech left","ech right","file","diamond"];
		_setFleeing = [0.1,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[10,30],[10,30],[10,30],[60,130,5,10],[1,3],[0,0]];
		_setBldgBeh = [4,50,100,600];
		_setPatrol = ["5 + (5 * (skill _leader))","(5 + (random 10)) + ((skill _leader) * 5)"];
		_setSearch = ["50 + ((skill _leader) * 150)","50 + ((skill _leader) * 50)"];
		_setSupport = [0,102];
		_setJoin =  1;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 452: // hunter force
	{
		_setSkill = [0.7,0.9];
		_setCombat = ["yellow","red"];
		_setBehav = ["Combat"];
		_setSpeed = ["normal","full"];
		_setForm =  ["vee","line","wedge","ech left","ech right","file","diamond"];
		_setFleeing = [0,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[3,5],[3,5],[5,10],[20,30,5,5],[1,3],[0,0]];
		_setBldgBeh = [2,70,60,100];
		_setPatrol = ["45 + (30 * (skill _leader))","(70 + (random 40)) + ((skill _leader) * 50)"];
		_setSearch = ["100 + ((skill _leader) * 150)","120 + ((skill _leader) * 50)"];
		_setSupport = [0,101];
		_setJoin =  0;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	case 453: // passive patrol
	{
		_setSkill = [0.3,0.9];
		_setCombat = ["white","yellow"];
		_setBehav = ["safe"];
		_setSpeed = ["limited"];
		_setForm =  ["column","stag column"];
		_setFleeing = [0.3,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[30,50],[30,50],[30,50],[120,180,5,10],[1,3],[0,0]];
		_setBldgBeh = [4,80,300,300];
		_setPatrol = ["85 + (60 * (skill _leader))","(120 + (random 60)) + ((skill _leader) * 50)"];
		_setSearch = ["40 + ((skill _leader) * 150)","40 + ((skill _leader) * 50)"];
		_setSupport = [0,103];
		_setJoin =  1;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	// For base patrol etc
	case 454:
	{
		_setSkill = [0.5,0.8];
		_setCombat = ["yellow"];
		_setBehav = ["safe","aware"];
		_setSpeed = ["limited", "normal"];
		_setForm =  ["line","column","stag column"];
		_setFleeing = [0,50];
		_setHeliVal = [45,100,0.7,1];
		_setPause = [[3,5],[3,5],[5,10],[20,30,5,5],[1,3],[0,0]];
		_setBldgBeh = [2,50,120,600];
		_setPatrol = ["35 + (20 * (skill _leader))","(30 + (random 30)) + ((skill _leader) * 50)"];
		_setSearch = ["20 + ((skill _leader) * 150)","30 + ((skill _leader) * 50)"];
		_setSupport = [0,101];
		_setJoin =  0;
		_setEmpVeh = [[100,100],[100,100]];
		_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	// Sniper Patrol
	case 455:
	{
	_setSkill = [0.7,0.9];
	_setCombat = ["red"];
	_setBehav = ["stealth"];
	_setSpeed = ["limited"];
	_setForm = ["line","vee","column","wedge","stag column","ech left","ech right","file","diamond"];
	_setFleeing = [0.1,100];
	_setHeliVal = [35,45,0.7,1];
	_setPause = [[300,300],[300,180],[300,180],[200,20,5,5],[120,30],[0,0]];
	_setBldgBeh = [4,100,180,60];
	_setPatrol = ["35 + (20 * (skill _leader))","(30 + (random 30)) + ((skill _leader) * 50)"];
	_setSearch = ["100 + ((skill _leader) * 150)","180 + ((skill _leader) * 50)"];
	_setSupport = [0,1];
	_setJoin = 0;
	_setEmpVeh = [[100,100],[100,100]];
	_setSupTime = ["5 + ((skill _unit) * (5 * DAC_AI_Level))",2,5];
		_setHidTime = ["(((10 * DAC_AI_Level) + ((skill _leader) * 50)) / ((count units _group) + 1))"];
	};
//-------------------------------------------------------------------------------------------------------------------------
	Default {
				if(DAC_Basic_Value != 5) then
				{
					DAC_Basic_Value = 5;publicvariable "DAC_Basic_Value";
					hintc "Error: DAC_Config_Behaviour > No valid config number";
				};
			};
};

_array =	[
				_setSkill,_setCombat,_setBehav,_setSpeed,_setForm,_setFleeing,
				_setHeliVal,_setPause,_setBldgBeh,_setPatrol,_setSearch,
				_setSupport,_setJoin,_setEmpVeh,_setSupTime,_setHidTime
			];
_array