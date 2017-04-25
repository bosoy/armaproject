// =========================================================================================================
//  Urban Patrol Script
//  Version: 2.0.3
//  Author: Kronzky (www.kronzky.info / kronzky@gmail.com)
// ---------------------------------------------------------------------------------------------------------
//  Required parameters:
//    unit        = Unit to patrol area (1st argument)
//    markername  = Name of marker that covers the active area. (2nd argument)
//    (e.g. nul=[this,"town"] execVM "ups.sqf")
//
//  Optional parameters:
//    random      = Place unit at random start position.
//    randomdn    = Only use random positions on ground level.
//    randomup    = Only use random positions at top building positions.
//    min:n/max:n = Create a random number (between min and max) of 'clones'.
//    init:string = Custom init string for created clones.
//    nomove      = Unit will stay at start position until enemy is spotted.
//    nofollow    = Unit will only follow an enemy within the marker area.
//    delete:n    = Delete dead units after 'n' seconds.
//    nowait      = Do not wait at patrol end points.
//    noslow      = Keep default behaviour of unit (don't change to "safe" and "limited").
//    noai        = Don't use enhanced AI for evasive and flanking maneuvers.
//    showmarker  = Display the area marker.
//    trigger     = Display a message when no more units are left in sector.
//    empty:n     = Consider area empty, even if 'n' units are left.
//    track       = Display a position and destination marker for each unit.
//    reinforcement  = Define la unidad como refuerzo, cuando se de la alarma KRON_UPS_reinforcement==true acudará en ayuda.
// ---------------------------------------------------------------------------------------------------------
//  Modified: Monsada (SMM) 02.02.2010
//		 (smirall@hotmail.com)
//		http://www.simulacion-esp.com/
//		Comunidad Hispana de Simulación
// ---------------------------------------------------------------------------------------------------------
//Version: 4.2.2
//    	Added
//		Se ha añadido ataque frontal
//		Formaciones de combate en función de la situación
//		La IA puede entrar en los edificios a tomar posiciones de defensa y en ataque puede patrullarlos en busca de enemigos o posiciones de fuego.
// 	Modificaciones:
//		Mejorado el sistema para localizar, asignar y entrar en vehiculos,.
//		Optimizado el rendimiento. Se ha mejorado para que se pueda ejecutar cada 20s.
//		Modificada la parametrización, sharedist incrementado, react reducido, cycle aumentado.
//		Modificada la actitud e la IA en combate, se ha dado más especialización en función de la situación.
//		Corregido bug que al enviar refuerzos hacía que dejaran de patrullar si no tenian ningún target
//		Posiciones de flanqueo más dinámicas.
//		Las escuadras con rol "NOMOVE" tienden a asegurar la posición y a hacer mayor uso de los edificios del entorno.
//-------------------------------------------------------------------------------------------------------------
// if (!isServer) exitWith {};

// ---------------------------------------------------------------------------------------------------------

if (isNil("KRON_UPS_INIT")) then {
	KRON_UPS_INIT=0;
};

waitUntil {KRON_UPS_INIT==1};

// convert argument list to uppercase
_UCthis = [];
for [{_i=0},{_i<count _this},{_i=_i+1}] do {_e=_this select _i; if (typeName _e=="STRING") then {_e=toUpper(_e)};_UCthis set [_i,_e]};

if ((count _this)<2) exitWith {
	if (format["%1",_this]!="INIT") then {hint "UPS: Unit and marker name have to be defined!"};
};

// Postioning
private["_targetX","_targetY","_relTX","_relTY","_relUX","_relUY","_waiting","_pursue","_react","_newpos","_currPos","_orgPos","_targetPos","_attackPos","_flankPos","_avoidPos", "_speedmode"];
private["_dist","_lastdist","_lastmove1","_lastmove2","_gothit", "_cover", "_enemigosoldier", "_supressed" , "_currwp", "_flankdist","_nBuilding","_nBuildingt","_distnbuid","_distnbuidt"];
private["_objsflankPos1","_cntobjs1","_objsflankPos2","_cntobjs2","_targettext","_dir1","_dir2","_dir3","_dd","_timeontarget","_newdamage","_dirf1","_dirf2","_fightmode",
		"_flankPos2","_cosU","_sinU","_cosT","_sinT","_reinforcement","_reinforcementsent","_target","_targets","_flankdir","_prov","_lastpos","_newtarget","_planta","_nomove",
		"_newflankAngle","_sharedist" ,"_targetPosOld","_fldest","_grpidx","_grpid","_i","_cont","_unitpos","_Behaviour", "_incar", "_inheli" , "_inboat","_gunner","_driver"
		,"_vehicle","_minreact","_lastreact","_CombatMode","_rnd","_GetOutDist","_GetOut","_GetIn_NearestVehicles","_makenewtarget","_index","_wp","_grp","_wptype","_wpformation","_i"
		,"_targetdead","_frontPos","_GetIn","_dist1","_dist2","_dist3","_fldestfront","_fldest2","_blds","_bld","_blddist","_bldunitin"];

_grpid =0;
_exit = false;
_fldest = 0;
_unitpos = "AUTO";
_vehicle = objnull;
_minreact = 30;
_lastreact = 30;
_rnd = 0;
_GetOutDist = 0;
_GetOut=false;
_index = 0;
_wp=[];
_wptype="MOVE";
_wpformation = "WEDGE";
_targetdead = false;
_GetIn=false;
_dist3 = 0;
_fldestfront = 0;
_fldest2=0;
_blds = [];
_bld = objnull;

KRON_UPS_Instances =	KRON_UPS_Instances + 1;
// give this group a unique index
_grpid = KRON_UPS_Instances;
_grpidx = format["%1",_grpid];
_grpname = format["%1_%2",(side _npc),_grpidx];

//Para que no se ejecuten todas al mismo tiempo esperamos tantos segundos como id tenga
_rnd = _grpid * 2;
sleep _rnd ;//*0.5;

/*{
	_x setVariable ["UPSMON_grpid", _grpid, false];
}foreach units _npc;*/

if (KRON_UPS_Debug>0) then {player sidechat format["%1: Iniciando instancia ",_grpidx]};

// get name of area marker
_areamarker = _this select 1;
if (isNil ("_areamarker")) exitWith {
	hint "UPS: Area marker not defined.\n(Typo, or name not enclosed in quotation marks?)";
};
// remember center position of area marker
_centerpos = getMarkerPos _areamarker;
_centerX = abs(_centerpos select 0);
_centerY = abs(_centerpos select 1);

// show area marker
_showmarker = if ("SHOWMARKER" in _UCthis) then {"SHOWMARKER"} else {"HIDEMARKER"};
if (_showmarker=="HIDEMARKER") then {
	//_areamarker setMarkerCondition "false"; // VBS2
	_areamarker setMarkerPos [-abs(_centerX),-abs(_centerY)];
};

// unit that's moving
_obj = _this select 0;
_npc = _obj;
// is anybody alive in the group?
_exit = true;
if (typename _obj=="OBJECT") then {
	if (alive _npc) then {_exit = false;}
} else {
	if (count _obj>0) then {
		{if (alive _x) then {_npc = _x; _exit = false;}} forEach _obj;
	};
};

// remember the original group members, so we can later find a new leader, in case he dies
_members = units _npc;
KRON_UPS_Total = KRON_UPS_Total + (count _members);

// what type of "vehicle" is unit ?
_isman = "Man" countType [_npc]>0;
_iscar = "LandVehicle" countType [_npc]>0;
_isboat = "Ship" countType [_npc]>0;
_isplane = "Air" countType [_npc]>0;

// check to see whether group is an enemy of the player (for attack and avoidance maneuvers)
// since countenemy doesn't count vehicles, and also only counts enemies if they're known,
// we just have to brute-force it for now, and declare *everyone* an enemy who isn't a civilian
_issoldier = side _npc != civilian;

_friends=[];
_enemies=[];
_sharedenemy=0;

if (_issoldier) then {
	switch (side _npc) do {
		case west:
			{ _friends=_friends+KRON_AllWest; _enemies=_enemies+KRON_AllEast+KRON_AllRes; _sharedenemy=0; };
		case east:
			{ _friends=_friends+KRON_AllEast; _enemies=_enemies+KRON_AllWest+KRON_AllRes; _sharedenemy=1; };
		case resistance:
			{ if (east in KRON_UPS_Res_enemy ) then {_enemies=_enemies+KRON_AllEast;_friends=_friends+KRON_AllWest;};
		if (west in KRON_UPS_Res_enemy ) then {_enemies=_enemies+KRON_AllWest;_friends=_friends+KRON_AllEast;};
			if (west in KRON_UPS_Res_enemy and east in KRON_UPS_Res_enemy) then {_friends=[];};
			_sharedenemy=2;
			};
	};
	{_friends=_friends-[_x]} forEach _members;
};
sleep .05;

// global unit variable to externally influence script
_named = false;
_npcname = str(side _npc);

// create global variable for this group
call compile format ["KRON_UPS_%1=1",_npcname];

// X/Y range of target area
_areasize = getMarkerSize _areamarker;
_rangeX = _areasize select 0;
_rangeY = _areasize select 1;
// marker orientation (needed as negative value!)
_areadir = (markerDir _areamarker) * -1;


// store some trig calculations
_cosdir=cos(_areadir);
_sindir=sin(_areadir);

// minimum distance of new target position
_mindist=(_rangeX^2+_rangeY^2)/4;
if (_rangeX==0) exitWith {
	hint format["UPS: Cannot patrol Sector: %1\nArea Marker doesn't exist",_areamarker];
};
//hint format["%1,%2,%3,%4",_areamarker,isNil ("_areamarker"),_rangeX,_rangeY];

// remember the original mode & speed
_orgMode = behaviour _npc;
_orgSpeed = speedmode _npc;

// set first target to current position (so we'll generate a new one right away)
_currPos = getpos _npc;
_orgPos = _currPos;
_orgDir = getDir _npc;
_orgWatch=[_currPos,50,_orgDir] call KRON_relPos;
_lastpos = _currPos;

_avoidPos = [0,0];
_flankPos = [0,0];
_attackPos = [0,0];
_frontPos = [0,0];
_dirf1 = 0;_dirf2=0;_flankPos2=[0,0];
_dist = 0;
_lastdist = 0;
_lastmove1 = 0;
_lastmove2 = 0;
_maxmove=0;
_moved=0;

_damm=0;
_dammchg=0;
_lastdamm = 0;
_timeontarget = 0;

_fightmode = "walk";
_fm=0;
_gothit = false;
_pursue=false;
_hitPos=[0,0,0];
_react = 0;
_lastdamage = 0;
_lastknown = 0;
_opfknowval = 0;

_sin0=1;
_sin90=1; _cos90=0;
_sin270=-1; _cos270=0;
_targetX =0; _targetY=0;
_relTX=0;_relTY=0;
_relUX=0;_relUY=0;
_cover = [0,0];
_enemigosoldier = nil;
_supressed = false;
_currwp = 0;
_flankdist=0;
_nBuilding=nil;
_nBuildingt =nil;
_speedmode="Limited";
_distnbuid = 0;
_distnbuidt = 0;
_objsflankPos1 =  [];
_cntobjs1 = 0;
_objsflankPos2 =  [];
_cntobjs2 = 0;
_targettext ="";
_dir1 =0;_dir2=0;_dir3=0;_dd=0;
_timeontarget=0;
_newdamage =0;
_reinforcement ="";
_reinforcementsent = false;
_target = objnull;
_newtarget=objnull;
_flankdir=0; //1 tendencia a flankpos1, 2 tendencia a flankpos2
_prov=0;
_targets=[];
_planta=0; //Indice de plantas en edificios
_newflankAngle = 0;
_cont = 0;
_closeenough = KRON_UPS_closeenough;
_gunner = objnull;
_driver = objnull;


// set target tolerance high for choppers & planes
if (_isplane) then {_closeenough=5000};


// ***************************************** optional arguments *****************************************

// wait at patrol end points
_pause = if ("NOWAIT" in _UCthis) then {"NOWAIT"} else {"WAIT"};
// don't move until an enemy is spotted
_nomove  = if ("NOMOVE" in _UCthis) then {"NOMOVE"} else {"MOVE"};
// don't follow outside of marker area
_nofollow = if ("NOFOLLOW" in _UCthis) then {"NOFOLLOW"} else {"FOLLOW"};
// share enemy info
_shareinfo = if ("NOSHARE" in _UCthis) then {"NOSHARE"} else {"SHARE"};
// "area cleared" trigger activator
_areatrigger = if ("TRIGGER" in _UCthis) then {"TRIGGER"} else {if ("NOTRIGGER" in _UCthis) then {"NOTRIGGER"} else {"SILENTTRIGGER"}};
// suppress fight behaviour
if ("NOAI" in _UCthis) then {_issoldier=false};
// adjust cycle delay
_cycle = ["CYCLE:",KRON_UPS_Cycle,_UCthis] call KRON_UPSgetArg;
// drop units at random positions
_initpos = "ORIGINAL";
if ("RANDOM" in _UCthis) then {_initpos = "RANDOM"};
if ("RANDOMUP" in _UCthis) then {_initpos = "RANDOMUP"};
if ("RANDOMDN" in _UCthis) then {_initpos = "RANDOMDN"};
// don't position groups or vehicles on rooftops
if ((_initpos!="ORIGINAL") && {(!_isman) || {(count _members)>1}}) then {_initpos="RANDOMDN"};
// set behaviour modes (or not)
_noslow = if ("NOSLOW" in _UCthis) then {"NOSLOW"} else {"SLOW"};
if (_noslow!="NOSLOW") then {
	_Behaviour = "safe";
	_npc setbehaviour _Behaviour;
	_orgMode = "safe";
	_npc setspeedmode "limited";
	_orgSpeed = "limited";
};

// If enemy detected reinforcements will be sent
_reinforcement= if ("REINFORCEMENT" in _UCthis) then {"REINFORCEMENT"} else {"NOREINFORCEMENT"};

// make start position random
if (_initpos!="ORIGINAL") then {
	// find a random position (try a max of 20 positions)
	_try=0;
	_bld=0;
	_bldpos=0;
	while {_try<20} do {
		_currPos=[_centerX,_centerY,_rangeX,_rangeY,_cosdir,_sindir,_areadir] call KRON_randomPos;
		_posinfo=[_currPos] call KRON_PosInfo3;
		// _posinfo: [0,0]=no house near, [obj,-1]=house near, but no roof positions, [obj,pos]=house near, with roof pos
		_bld=_posinfo select 0;
		_bldpos=_posinfo select 1;
		if (_isplane || {_isboat} || {!(surfaceiswater _currPos)}) then {
			if (((_initpos=="RANDOM") || {(_initpos=="RANDOMUP")}) && {(_bldpos>0)}) then {_try=99};
			if (((_initpos=="RANDOM") || {(_initpos=="RANDOMDN")}) && {(_bldpos==0)}) then {_try=99};
		};
		_try=_try+1;
		//sleep .05;
	};
	if (_bldpos==0) then {
		if (_isman) then {
			{_x setpos _currPos} foreach units _npc;
		} else {
			_npc setpos _currPos;
		};
	} else {
	// put the unit on top of a building
		_npc setPos (_bld buildingPos _bldpos);
		_currPos = getPos _npc;
		_exit=true; // don't move if on roof
	};
};
sleep .05;

// track unit
_track = 	if (("TRACK" in _UCthis) || {KRON_UPS_Debug>0}) then {"TRACK"} else {"NOTRACK"};
_trackername = "";
_destname = "";
if (_track=="TRACK") then {
	_track = "TRACK";
	_trackername=format["trk_%1",_grpidx];
	_markerobj = createMarker[_trackername,[0,0]];
	_markerobj setMarkerShape "ICON";
	_markertype = if (isClass(configFile >> "cfgMarkers" >> "WTF_Dot")) then {"WTF_DOT"} else {"DOT"};
	_trackername setMarkerType _markertype;
	_markercolor = switch (side _npc) do {
		case west: {"ColorGreen"};
		case east: {"ColorRed"};
		case resistance: {"ColorBlue"};
		default {"ColorBlack"};
	};
	_trackername setMarkerColor _markercolor;
	_trackername setMarkerText format["%1",_grpidx];
	_trackername setmarkerpos _currPos;

	_destname=format["dest_%1",_grpidx];
	_markerobj = createMarker[_destname,[0,0]];
	_markerobj setMarkerShape "ICON";
	_markertype = if (isClass(configFile >> "cfgMarkers" >> "WTF_Flag")) then {"WTF_FLAG"} else {"FLAG"};
	_destname setMarkerType _markertype;
	_destname setMarkerColor _markercolor;
	_destname setMarkerText format["%1",_grpidx];
	_destname setMarkerSize [.5,.5];
};


// delete dead units
_deletedead = ["DELETE:",0,_UCthis] call KRON_UPSgetArg;
if (_deletedead>0) then {
	{_x addEventHandler['killed',format["[_this select 0,%1] spawn KRON_deleteDead",_deletedead]];
	}forEach _members;
};

// how many group clones?
// TBD: add to global side arrays?
_mincopies = ["MIN:",0,_UCthis] call KRON_UPSgetArg;
_maxcopies = ["MAX:",0,_UCthis] call KRON_UPSgetArg;
if (_mincopies>_maxcopies) then {_maxcopies=_mincopies};
if (_maxcopies>140) exitWith {hint "Cannot create more than 140 groups!"};
if (_maxcopies>0) then {
	_copies=_mincopies+random (_maxcopies-_mincopies);
	// any init strings?
	_initstr = ["INIT:","",_UCthis] call KRON_UPSgetArg;

// create the clones
	for "_grpcnt" from 1 to _copies do {
		// copy groups
		if (isNil ("KRON_grpindex")) then {KRON_grpindex = 0};
		KRON_grpindex = KRON_grpindex+1;
		// copy group leader
		_unittype=typeof _npc;
		// make the clones civilians
		// use random Civilian models for single unit groups
		if (_unittype == "Civilian" && {count _members == 1}) then {_rnd=1+round(random 20); if (_rnd>1) then {_unittype=format["Civilian%1",_rnd]}};

		_grp=createGroup side _npc;
		_lead = _grp createUnit [_unittype, getpos _npc, [], 0, "form"];
		_lead setVehicleVarName format["l%1",KRON_grpindex];
		call compile format["l%1=_lead",KRON_grpindex];
		_lead setBehaviour _orgMode;
		_lead setSpeedmode _orgSpeed;
		_lead setSkill skill _npc;
		_lead setVehicleInit _initstr;
		[_lead] join _grp;
		_grp selectLeader _lead;
		// copy team members (skip the leader)
		_c=0; {
			_c=_c+1;
			if (_c>1) then {
				_newunit = _grp createUnit [typeof _x, getpos _x, [],0,"form"];
				_newunit setBehaviour _orgMode;
				_newunit setSpeedMode _orgSpeed;
				_newunit setSkill skill _x;
				_newunit setVehicleInit _initstr;
				[_newunit] join _grp;
			};
		} foreach _members;
		_nul=[_lead,_areamarker,_pause,_noslow,_nomove,_nofollow,_initpos,_track,_showmarker,_shareinfo,"DELETE:",_deletedead] spawn ace_sys_bc_fnc_UPSMON;
		//sleep .05;
	};
	processInitCommands;
};
sleep .05;


// units that can be left for area to be "cleared"
_zoneempty = ["EMPTY:",0,_UCthis] call KRON_UPSgetArg;

// create area trigger
if (_areatrigger!="NOTRIGGER") then {
	_trgside = switch (side _npc) do { case west: {"WEST"}; case east: {"EAST"}; case resistance: {"GUER"}; case civilian: {"CIV"};};
	//_trgside = switch (side _npc) do { case west: {"EAST"}; case east: {"WEST"}; case resistance: {"ANY"}; case civilian: {"ANY"};};
	_trgname="KRON_Trig_"+_trgside+"_"+_areamarker;
	_flgname="KRON_Cleared_"+_areamarker;
	// has the trigger been created already?
	KRON_TRGFlag=-1;
	call compile format["%1=false",_flgname];
	call compile format["KRON_TRGFlag=%1",_trgname];
	if (isNil ("KRON_TRGFlag")) then {
		// trigger doesn't exist yet, so create one (make it a bit bigger than the marker, to catch path finding 'excursions' and flanking moves)
		call compile format["%1=createTrigger['EmptyDetector',_centerpos]",_trgname];
		call compile format["%1 setTriggerArea[_rangeX*1.5,_rangeY*1.5,markerDir _areamarker,true]",_trgname];
		call compile format["%1 setTriggerActivation[_trgside,'PRESENT',true]",_trgname];
		call compile format["%1 setEffectCondition 'true'",_trgname];
		call compile format["%1 setTriggerTimeout [5,7,10,true]",_trgname];
		if (_areatrigger!="SILENTTRIGGER") then {
			call compile format["%1 setTriggerStatements['count thislist<=%6', 'titletext [''SECTOR <%2> LIMPIO'',''PLAIN''];''%2'' setmarkerpos [-%4,-%5];%3=true;', 'titletext [''SECTOR <%2> HA SIDO REOCUPADO'',''PLAIN''];''%2'' setmarkerpos [%4,%5];%3=false;']", _trgname,_areamarker,_flgname,_centerX,_centerY,_zoneempty];

		} else {
			call compile format["%1 setTriggerStatements['count thislist<=%3', '%2=true;', '%2=false;']", _trgname,_flgname,_zoneempty];
		};

		//Si quieres que ejecute tu script descomenta estas lineas
		//message = format["_trgside=%1, _npc=%2",_trgside, _npc];
		//call compile format["%1 setTriggerStatements['this', 'nul = [%1,%3,thisList] execvm ''mon\enemydetected.sqF'';', '%2=false;'];", _trgname,_flgname,_trgside];
		//setTriggerStatements['this', 'nul = [thislist,_trgside] execvm "mon\enemydetectedd.sqF"';, 'ok = false']
	};
	sleep .05;
};

// init done
_makenewtarget=true;
_newpos=false;
_targetPos = _currPos; _targettext ="_currPos";
_swimming = false;
_waiting = if (_nomove=="NOMOVE") then {9999} else {0};
_sharedist = if (_nomove=="NOMOVE") then {KRON_UPS_sharedist} else {KRON_UPS_sharedist*1.5};
_grp = grpnull;

// exit if something went wrong during initialization (or if unit is on roof)
if (_exit) exitWith {
	if (KRON_UPS_DEBUG>0) then {hint "Initialization aborted"};
};




// ***********************************************************************************************************
// ************************************************ MAIN LOOP ************************************************
// ***********************************************************************************************************
_loop=true;
_currcycle=_cycle;
while {_loop} do {
//if (KRON_UPS_Debug>0) then {player sidechat format["%1: _cycle=%2 _currcycle=%3 _react=%4 _waiting=%5",_grpidx,_cycle,_currcycle,_react,_waiting]}; //SMM
	; //SMM  no hace falta que se recalcule cada segundo se hace sleep al final
	_timeontarget=_timeontarget+_currcycle;
	_react=_react+_currcycle;
	_waiting = _waiting - _currcycle;
	_lastreact = _lastreact+_currcycle;
	_targets = call (compile format ["KRON_targets%1",_sharedenemy]);
	_newpos = false;


	//echo format["[K] time on target: %1",_timeontarget];

	// did anybody in the group got hit?
	_newdamage=0; {
		if((damage _x)>0.2) then {
			_newdamage=_newdamage+(damage _x);
			// damage has increased since last round
			if (_newdamage>_lastdamage) then {
				_lastdamage=_newdamage;
				_gothit=true;
			};
			_hitPos=getpos _x;
			if (!alive _x) then {
				_members=_members-[_x];
				_friends=_friends-[_x];
				KRON_AllTroops=KRON_AllTroops-[_x];
			};
		};
	} foreach _members;

	//if (KRON_UPS_Debug>10) then {player sidechat format["%1: _lastdamage=%2 _newdamage=%3 _gothit=%4",_grpidx,_lastdamage,_newdamage,_gothit]}; //SMM
	//if (KRON_UPS_Debug>0) then {player sidechat format["%1 init loop",_grpidx]};
	//sleep .05;

	// nobody left alive, exit routine
	if (count _members==0) then {
		_exit=true;
	} else {
		// did the leader die?
		if (!alive _npc) then {
			_npc = _members select 0;
			group _npc selectLeader _npc;
			if (isPlayer _npc) then {
										_exit=true;
									};
		};
	};


	//Asignamos el lider actual del grupo en el array de lideres de grupos
	KRON_NPCs set [_grpid,_npc];
	_grp = group _npc;

	// current position
	_currPos = getpos _npc; _currX = _currPos select 0; _currY = _currPos select 1;
	if (_track=="TRACK" || {KRON_UPS_Debug>0}) then { _trackername setmarkerpos _currPos; };

	// if the AI is a civilian we don't have to bother checking for enemy encounters
	if ((_issoldier) && {((count _enemies)>0) && !(_exit)}) then {
		_pursue=false;
		_accuracy=100;

		//Variables para saber si estamos en un vehiculo
		_incar = "LandVehicle" countType [vehicle (_npc)]>0;
		_inheli = "Air" countType [vehicle (_npc)]>0;
		_inboat = "Ship" countType [vehicle (_npc)]>0;

		//Si el grupo es un refuerzo y se han detectado los enemigos se envian al objetivo
		if ( KRON_UPS_reinforcement && {(_reinforcement=="REINFORCEMENT")} && {(!_reinforcementsent)}) then {
			if (KRON_UPS_Debug>0) then {player sidechat format["%1 Refuezos enviados",_grpidx,_dir2,KRON_UPS_safedist]};
			_reinforcementsent=true;
			_react = _react + 100;
		};

		//Borramos los targets detectados que han muerto
		call (compile format ["{IF (isnull(_x) || !alive _x ) THEN {KRON_targets%1 = KRON_targets%1-[_x];};}foreach KRON_targets%1;",_sharedenemy]);
		_targets = call (compile format ["KRON_targets%1",_sharedenemy]);

		// if the leader comes across another unit that's either injured or dead, go into combat mode as well.
		// If the other person is still alive, share enemy information.
		if ((_shareinfo=="SHARE")) then {
			//Se comunicac visualmente con las unidades aliadas por si han sido heridas
			if (KRON_UPS_comradio == 1) then {
				_others=_friends-_members; {
					if (!(isNull _x) && {(_npc distance _x<(_sharedist))) && {(damage _x>.2)}) exitWith {
						_pursue=true;
						if (_fightmode != "fight") then {
							_react = KRON_UPS_react;
						};

						if (_npc knowsabout _x>0.5) then {
							if (alive _x) then {_npc reveal (_target)};
						};
					};
				} forEach _others;
			};
			//Solicita por radio la posición del enemigo, si está dentro del radio de acción actua
			if ((KRON_UPS_comradio == 2)) then {
				{
					//Si el objetivo conocido está al alcance de la radio y no lo conocía ya, aumentará su conocimiento del mismo
					IF (_npc distance (_x) <= _sharedist || {_reinforcementsent}) THEN {
						_npc reveal (_x);
					};
				} foreach _targets;
			};
			//sleep .05;


			//Si el enemigo se ha alejado de la covertura de rádio y no es un refuerzo enviado habremos perdido la pista
			if ( _fightmode != "walk" && {!isnull(_target)} && {(_npc distance (_target) > (_sharedist * 1.10))} && {(_npc knowsabout _target <= 0.5)} && {!_reinforcementsent}) then {
				if (KRON_UPS_Debug>0) then {player sidechat format["%1: Se ha perdido al objetivo",_grpidx,_targets]};
				_fightmode="walk";
				_speedmode = _orgSpeed;
				_target = objnull;
				_Behaviour = _orgMode;
				_npc setBehaviour _Behaviour;
				_targetPos = _currPos;_targettext ="_currPos";
				_makenewtarget = true; //Volvemos a la posición original
				_unitpos = "AUTO";
			};
		};


		// did the group spot an enemy?
		//_lastknown=_opfknowval; //smm se comenta y se pone más abajo cuando se hace pursuit
		//Si el objetivo actual está muerto o no existe se limpia el conocimiento anterior
		if (isNull (_target) || {!alive _target} ) then {
			_lastknown = 0;
		};

		_opfknowval=0;
		_maxknowledge=0;
		_newtarget = _target; {
			_knows=_npc knowsabout _x;

			if ((alive _x) && {(_knows>0.2)}) then {
				call (compile format ["KRON_targets%1 = KRON_targets%1 - [_x]",_sharedenemy]);
				call (compile format ["KRON_targets%1 = KRON_targets%1 + [_x]",_sharedenemy]);
				if ((_npc distance (_x) < _npc distance (_newtarget)) || !(alive (_newtarget))) then {
					_newtarget = _x
				};
				if (_maxknowledge==4 && {_newtarget == _x}) exitWith {};
				_opfknowval=_opfknowval+_knows;
				_maxknowledge=_knows;
			};
		} forEach _enemies;
		//sleep .05;



		//Si cambia el target cambiamos inicializamos la dirección de flanqueo
		if ( !isNull (_newtarget) && {alive _newtarget} && {_newtarget != _target} ) then {
			_timeontarget = 0;
			_flankdir= if (random 1 <=.25) then {0} else {_flankdir};
			_target = _newtarget;
			_targetdead = false;
			if (_fightmode != "fight") then {
				_fightmode = "fight";
				_react = KRON_UPS_react;
				if (KRON_UPS_Debug>0) then {player sidechat format["%1: Enemigo detectado, todos a cubierto",_grpidx,_target]};
			};
		};

		//Si aumenta el conocimiento del target aceleramos la reacción
		if (_opfknowval>_lastknown ) then {
			_react = _react + 20;
		};


		// opfor spotted an enemy or got shot, so start pursuit, if in combat and exceed time to react y el tiempo de la última acción
		//es superior al mínimo fijado
		if ((_fightmode != "walk" && {_react >= KRON_UPS_react} && {_lastreact >=_minreact}) || {moveToCompleted _npc} ) then {
			_pursue=true;
			// make the exactness of the target dependent on the knowledge about the shooter
			_accuracy=21-(_maxknowledge*5);
		};


		//Si bajo ataque o aumenta el conocimiento se acelera la respuesta
		if (_gothit ) then {
			_react = if (_supressed) then {_react + 30} else {_react + 60};

			if (_fightmode == "walk") then {
				//Puede tratarse de un sniper, se debe buscar nueva posición Alerta
				_Behaviour =  "AWARE";
				if (KRON_UPS_Debug>0) then {player sidechat format["%1: Todos a cubierto, nos disparan %2",_grpidx,_makenewtarget]};
			};
		};

		//Si no hay objetivo se anula la orden de persecución
		if (isNull (_target) || {!alive _target}) then {
			_pursue=false;
			if (_gothit && {_react >= KRON_UPS_react} && {_lastreact >=_minreact}) then {
				//Nos disparan y no tenemos target, nos movemos de posición
				if (KRON_UPS_Debug>0) then {player sidechat format["%1: Nos disparan y no tenemos objetivo, nos movemos %2 %3 %4 %5",_grpidx,_newpos,_waiting,_lastreact,_minreact]};
				_makenewtarget = true;
				_waiting = -1;
				_pause="NOWAIT";
				_speedmode = "FULL";
				_unitpos = "middle";
			}else{

				if (_fightmode == "fight" && {_lastreact >=_minreact} && {!_targetdead}) then {
					_targetdead = true;
					//Nos hemos qdado sin objetivos continuamos la búsqueda
					if (KRON_UPS_Debug>0) then {player sidechat format["%1: El target ha muerto,continuamos buscando",_grpidx]};
						_pursue = true;
				};

			};

		} else {
			//hechamos un ojo miramos hacia el target;
			[_npc,_target] spawn MON_dowatch;
			//Si es unidad de refuerzo siempre acosará al enemigo
		};

		if (_pursue && {_reinforcementsent}) then {
			_makenewtarget = false;
		};
		sleep .05;

		//if (KRON_UPS_Debug>0) then {player sidechat format["%1 before pursue",_grpidx]};



//**********************************************************************************************************************
//   								PURSUE:	SE 	INICIA	LA	PERSECUCIÓN	DEL	OBJETIVO
//**********************************************************************************************************************
		if (_pursue) then{
			_pursue = false;
			_newpos = true;
			_react = 0;
			_lastreact = 0;
			_timeontarget = 0;
			_fightmode = "fight";
			_makenewtarget = false;
			_fm = 1;
			//Cancel supress effect when reaction time
			_supressed = false;

			//if (KRON_UPS_Debug>0) then {player sidechat format["%1 pursuing",_grpidx]};


			//if (KRON_UPS_Debug>0) then {player sidechat format["(%1) Pursuing",_grpidx]};
			// get position of spotted unit in player group, and watch that spot
			_offsx=_accuracy/2-random _accuracy; _offsY=_accuracy/2-random _accuracy;
			_targetPos = getpos (_target);
			_targetPos = [(_targetPos select 0) + _offsX, (_targetPos select 1) + _offsY];
			_attackPos = _targetPos;
			_targetX = _targetPos select 0; _targetY = _targetPos select 1;
			_currPos = getpos _npc;

			//if (KRON_UPS_Debug>0) then {player sidechat format[" _targetX:%1 _targetY=%2 _targetPos %3",_targetX,_targetY,_targetPos]};

			// also go into "combat mode"
			_pause="NOWAIT";
			_waiting=0;

			// distance to target
			_dist = [_currPos,_targetPos] call KRON_distancePosSqr;

			// angle from unit to target
			_dir1 = [_currPos,_targetPos] call KRON_getDirPos;
			// angle from target to unit (reverse direction)
			_dir2 = (_dir1+180) mod 360;

			//Establecemos una distancia de flanqueo
			_flankdist = ((random 0.5)+0.7)*KRON_UPS_safedist;

			//La distancia de flanqueo no puede ser superior a la distancia del objetivo o nos pordría pillar por la espalda
			_flankdist = if ((_flankdist*1.40) >= _dist) then {_dist*.6} else {_flankdist};


			// avoidance position (right or left of unit)
			_avoidPos = [_currPos,_dir2, _flankdist/3] call MON_GetPos2D;

			//Calculamos posición de avance frontal
			_frontPos = [_targetPos,_dir2, _flankdist] call MON_GetPos2D;


			//Adaptamos el ángulo de flanqueo a la distancia
			_newflankAngle = (random(KRON_UPS_flankAngle) * 2 * (_flankdist / KRON_UPS_safedist )) + (KRON_UPS_flankAngle/2) ;
			if (_newflankAngle > KRON_UPS_flankAngle) then {_newflankAngle = KRON_UPS_flankAngle};
			//if (KRON_UPS_Debug>0) then {player sidechat format["%1 KRON_UPS_flankAngle=%2 newflankAngle=%3 safedist=%4  flankdist=%5 ",_grpidx,KRON_UPS_flankAngle,_newflankAngle,KRON_UPS_safedist,_flankdist]};

			//Calculamos posición de flanqueo 1 45º
			_dirf1 = (_dir2+_newflankAngle) mod 360;
			_flankPos = [_targetPos,_dirf1, _flankdist] call MON_GetPos2D;


			//Calculamos posición de flanqueo 2 -45º
			_dirf2 = (_dir2-_newflankAngle+360) mod 360;
			_flankPos2 = [_targetPos,_dirf2, _flankdist] call MON_GetPos2D;

			if (KRON_UPS_Debug>0) then {
				"flank1" setmarkerpos _flankPos; "flank2" setmarkerpos _flankPos2;
			};


			//Decidir por el mejor punto de flanqueo
			//Contamos las posiciones de destino de otros grupos más alejadas
			_fldest = 0;
			_fldest2 = 0;
			_fldestfront = 0;
			_i = 0;
 {
				if (_i != _grpid && {format ["%1", _x] != "[0,0]")}) then {
					_dist1 = [_x,_flankPos] call KRON_distancePosSqr;
					_dist2 = [_x,_flankPos2] call KRON_distancePosSqr;
					_dist3 = [_x,_frontPos] call KRON_distancePosSqr;
					if (_dist1 <= _flankdist/1.5 || {_dist2 <= _flankdist/1.5} || {_dist3 <= _flankdist/1.5}) then {
						if (_dist1 < _dist2 && {_dist1 < _dist3}) then {_fldest = _fldest + 1;};
						if (_dist2 < _dist1 && {_dist2 < _dist3}) then {_fldest2 = _fldest2 + 1;};
						if (_dist3 < _dist1 && {_dist3 < _dist2}) then {_fldestfront = _fldestfront + 1;};
					//if (KRON_UPS_Debug>0) then {player sidechat format["%1 _dist1=%2 _dist2=%3 _dist3=%4",_grpidx, _dist1, _dist2, _dist3]};
					};
				};
				_i = _i + 1;
			}foreach KRON_targetsPos;


//if (KRON_UPS_Debug>0) then {player sidechat format["%1 _fldest=%2 _fldest2=%3 _fldestfront=%4",_grpidx, _fldest, _fldest2, _fldestfront]};

			//Contamos las posiciones de otros grupos más alejadas
			_i = 0; {
				if (_i != _grpid && {!isnull(_x)}) then {
					_dist1 = [getpos(_x),_flankPos] call KRON_distancePosSqr;
					_dist2 = [getpos(_x),_flankPos2] call KRON_distancePosSqr;
					_dist3 = [getpos(_x),_frontPos] call KRON_distancePosSqr;
					if (_dist1 <= _flankdist/1.5 || {_dist2 <= _flankdist/1.5} || {_dist3 <= _flankdist/1.5}) then {
						if (_dist1 < _dist2 && {_dist1 < _dist3}) then {_fldest = _fldest + 1;};
						if (_dist2 < _dist1 && {_dist2 < _dist3}) then {_fldest2 = _fldest2 + 1;};
						if (_dist3 < _dist1 && {_dist3 < _dist2}) then {_fldestfront = _fldestfront + 1;};
					};
				};
				_i = _i + 1;
			}foreach KRON_NPCs;


			//La preferencia es la elección inicial de dirección
			switch (_flankdir) do {
				case 1:
					{_prov = 125};
				case 2:
					{_prov = -25};
				default
					{_prov = 50};
			};


			//Si es positivo significa que hay más destinos existentes lejanos a la posicion de flanqueo1, tomamos primariamente este
			if (_fldest<_fldest2) then {_prov = _prov + 60;};
			if (_fldest2<_fldest) then {_prov = _prov - 60;};

			//Si la provablilidad es negativa indica que tomará el flank2 por lo tanto la provabilidad de coger 1 es 0
			if (_prov<0) then {_prov = 0;};


			//if (KRON_UPS_Debug>0) then {player sidechat format["%1 _fldest=%2 _flankdir=%3 _prov=%4",_grpidx, _fldest, _flankdir, _prov]};

			//Evaluamos la dirección en base a la provablilidad calculada
			if ((random 100)<=_prov) then {
				_flankdir =1;
				_flankPos = _flankPos; _targettext = "_flankPos";
			} else {
				_flankdir =2;
				_flankPos = _flankPos2; _targettext = "_flankPos2";
			};
			//sleep .05;

			//Posición de ataque por defecto el flanco
			_targetPos = _flankPos;//_targettext = "_flankPos";


			if ((isNull (_target) || {!alive _target})) then {
				_targetPos = _frontPos;_targettext ="_attackPos";
				_flankdir =0;
			} else {
				_prov = 15 * ((_fldest + _fldest2)-_fldestfront);
				//if (KRON_UPS_Debug>0) then {player sidechat format["%1 _fldest=%2 _fldest2=%3 _fldestfront=%4 _prov=%5",_grpidx, _fldest, _fldest2, _fldestfront,_prov]};
				if ((random 100)< _prov ) then {
					_targetPos = _frontPos;_targettext ="_frontPos";
					_flankdir =0;
				};
			};

			//Establecemos el target
			KRON_targetsPos set [_grpid,_targetPos];

			//Establecemos tipo de waypoint
			//con DESTROY tiene peor comportamiento y a veces no se mueven
			_wptype = "MOVE";


			//Establecer velocidad y modo de combate
			if (_dist <= _closeenough ) then {
				//Si estamos muy cerca damos prioridad a fuego a discrección
				if (_dist <= _closeenough/2 ) then {
					//Modo combate cerrado
					_Behaviour =  "COMBAT";
					_speedmode = "LIMITED";
					_wpformation = "COMPACT COLUMN";
					_wptype = "MOVE";
					_unitpos = "Middle";
				}else{
					//Si la tropa tiene el rol de no moverse tenderá a mantener la posición
					_speedmode = "NORMAL";
					_wpformation = "COMPACT COLUMN";

					if ((_nomove == "NOMOVE") && {((random 1)<.20)} && {!_reinforcementsent}) then {
						//Combate defensivo
						_Behaviour =  "STEALTH";
						_wptype = "HOLD";
					} else {
						_Behaviour =  "AWARE";
						_wptype = "MOVE";
					};
					_unitpos = "Middle";
				};
			} else	{
				if (( _dist <= (_closeenough + KRON_UPS_safedist))) then {
					_speedmode = "FULL";
					_wpformation = "COMPACT COLUMN";

					if ((_nomove=="NOMOVE") && {((random 1)<.40)}  && {!_reinforcementsent}) then {
						//Combate defensivo
						_Behaviour =  "COMBAT";
						_wptype = "HOLD";
						_wpformation = "LINE";
					}else{
						//Movimiento con precaución (más rápido)
						_Behaviour =  "AWARE";
						_wptype = "MOVE";
					};
					_unitpos = if ((random 1)<.90) then {"Middle"}else{"AUTO"};

				} else {
					//Pelotón lejos del objetivo hay que desplazarse rápido y directo al punto
					_Behaviour =  "AWARE";
					_speedmode = "FULL";

					if ((_nomove=="NOMOVE") && {((random 1)<.60)}  && {!_reinforcementsent}) then {
						_wptype = "HOLD";
						_wpformation = "WEDGE";
					}else{
						_wptype = "MOVE";
						_wpformation = "COLUMN";
					};
					_unitpos = if ((random 1)<.80) then {"Middle"}else{"AUTO"};
				};
			};

			if (_wptype == "HOLD") then {
				_targetPos = _currPos;	_targettext ="_currPos";
			};

			//Si hay algun miembro del grupo en un vehiculo lo sacamos si está en distancia
			_GetOutDist = (_closeenough + KRON_UPS_safedist ) * (0.4 + random (0.5));
			if ( !_GetIn_NearestVehicles ) then { {
					if (vehicle _x != _x ) then {
						_GetOut = [_x,_target,_GetOutDist] call MON_GetOutDist;

						_pursue = if (_pursue || {_GetOut}) then {true} else {false};


					};
				}foreach (units _npc);

				if (_pursue && {_GetOut}) then {
					if (KRON_UPS_Debug>0) then {player sidechat format["%1: Saliendo del vehiculo",_grpidx]};
					_wpformation = "LINE";
					_Behaviour =  "AWARE";
				};
			};


			//Si estamos lejos buscamos un vehiculo cercano
			_GetIn_NearestVehicles = false;
			if ( _dist >= ( _closeenough + KRON_UPS_safedist )*1.2) then {

				if (!_incar) then {
					_Behaviour = "CARELESS";
					_speedmode = "FULL";
					_unitpos = "AUTO";
					_GetIn_NearestVehicles = [_grpid,_npc] call MON_GetIn_NearestVehicles;

					if (_GetIn_NearestVehicles) then {
						if (KRON_UPS_Debug>0 ) then {player sidechat format["%1: Escuadra entrando en vehiculo",_grpidx]};
					};
				};
			};

			//Si es unidad de refuerzo siempre acosará al enemigo
			if (_reinforcementsent) then {
				_newpos=true;
				_makenewtarget = false;
			};

			if (_nofollow=="NOFOLLOW") then {
				_avoidPos = [_avoidPos,_centerpos,_rangeX,_rangeY,_areadir] call KRON_stayInside;
				_flankPos = [_flankPos,_centerpos,_rangeX,_rangeY,_areadir] call KRON_stayInside;
				_attackPos = [_attackPos,_centerpos,_rangeX,_rangeY,_areadir] call KRON_stayInside;
				_targetPos = [_targetPos,_centerpos,_rangeX,_rangeY,_areadir] call KRON_stayInside;
			};

			_lastknown=_opfknowval; //Se actualiza con el último valor, por si cambia el target


			//Si por el motivo que sea se cancela la nueva posición se deben limpiar los parámetros que hacen entrar en pursuit
			if  (!_newpos) then {
				//Si la unidad ha decidio mantener posición pero está siendo atacada está siendo suprimida, debe tener la oportunidad de reaccionar
				_newpos = _gothit;
				if  (!_newpos) then {
					_targetPos=_lastpos;
					if (!_newpos && {KRON_UPS_Debug>0}) then {player sidechat format["%1 manteniendo ordenes %2",_grpidx,_nomove]};
				};
			};
			if (KRON_UPS_Debug>=1) then {
				"dead" setmarkerpos _hitPos; "avoid" setmarkerpos _avoidPos; "flank" setmarkerpos _flankPos; "target" setmarkerpos _attackPos;
			};
		};	//END PURSUE
	}; //((_issoldier) && {(count _enemies)>0})
	sleep .05;



//**********************************************************************************************************************
//   								SIN		NOVEDADES
//**********************************************************************************************************************
	if !(_newpos) then {
		// calculate new distance
		// if we're waiting at a waypoint, no calculating necessary
		if (_waiting<0) then {
			// distance to target
			_dist = [_currPos,_targetPos] call KRON_distancePosSqr;

			if (_lastdist==0) then {_lastdist=_dist};
			_moved = abs(_dist-_lastdist);
			// adjust the target tolerance for fast moving vehicles
			if (_moved>_maxmove) then {_maxmove=_moved; if ((_maxmove/40) > _closeenough) then {_closeenough=_maxmove/40}};
			// how much did we move in the last three cycles?
			_totmove=_moved+_lastmove1+_lastmove2;
			_damm = damage _npc;
			// is our damage changing (increasing)?
			_dammchg = abs(_damm - _lastdamm);


			//Se evalua si se ha excedido el tiempo máximo de espera y el objetivo ya está abatido para retornar a la posición inicial.
			//if (KRON_UPS_Debug>0) then {player sidechat format["%1 waiting=%5 _fightmode=%2 _time=%3 _enemy %4",_grpidx,_fightmode,_timeontarget,_target, _waiting]};
			if (_fightmode!="walk") then {
				if (_timeontarget>KRON_UPS_alerttime && { isNull (_target) || {!alive (_target)}}) then {
					_pursue=false;
					_reinforcementsent = false;
					KRON_UPS_reinforcement = false; //ya no hay amenaza
					_fightmode="walk";
					_npc setBehaviour _orgMode;
					if (KRON_UPS_Debug>0) then {player sidechat format["%1 Sin objetivos, saliendo de modo combate",_grpidx]};
				};
			};
			//sleep .05;

			// if not in combat and we're either close enough, seem to be stuck, or are getting damaged, so find a new target
			if ((!_gothit) && {(!_swimming)} && {_fightmode == "walk"} && {(_dist<=(_closeenough/2)) && {_timeontarget>KRON_UPS_maxwaiting}}) then {_makenewtarget=true; _timeontarget = 0;};

			// make new target
			if (_makenewtarget) then {
				_react = 0;
				_lastreact = 0;
				_makenewtarget = false;
				_gothit=false;
				_timeontarget = 0;

				if (KRON_UPS_Debug>0) then {player sidechat format["%1 Calculando nuevo target %2 %3",_grpidx,_nomove, _fightmode]};
				if ((_nomove=="NOMOVE") && {(_timeontarget>KRON_UPS_alerttime)}) then {
					if (([_currPos,_orgPos] call KRON_distancePosSqr)<_closeenough) then {
						_newpos = false;
					} else {
						_targetPos=_orgPos; _targettext ="_orgPos";
					};
				} else {
					// re-read marker position/size
					_centerpos = getMarkerPos _areamarker; _centerX = abs(_centerpos select 0); _centerY = abs(_centerpos select 1);
					_areasize = getMarkerSize _areamarker; _rangeX = _areasize select 0; _rangeY = _areasize select 1;
					_areadir = (markerDir _areamarker) * -1;
					// find a new target that's not too close to the current position
					_targetPos=_currPos; _targettext ="newTarget";
					_tries=0;
					while {((([_currPos,_targetPos] call KRON_distancePosSqr) < _mindist)) && (_tries<20)} do {
						_tries=_tries+1;
						// generate new target position (on the road)
						_road=0;
						while {_road<20} do {
							_targetPos=[_centerX,_centerY,_rangeX,_rangeY,_cosdir,_sindir,_areadir] call KRON_randomPos;
							_road=[_targetPos,(_isplane || {_isboat}),_road] call KRON_OnRoad;
						};
					};
				};
				sleep 0.05;
				_avoidPos = [0,0]; _flankPos = [0,0]; _attackPos = [0,0];	_frontPos = [0,0];
				_hitPos=[0,0,0];
				_fm=0;
				_newpos=true;
				_lastpos=_targetPos;
				_timeontarget=0;

			};
		};

		//Si se ha ordenado entrar en un vehiculo seguimos refrendando la orden
		if (_GetIn_NearestVehicles) then {
			units _npc orderGetIn true;
			//_npc setBehaviour "CARELESS";
		};
	};
	//sleep .05;

	// if in water, get right back out of it again
	if (surfaceIsWater _currPos) then {
		if (_isman && {!_swimming}) then {
			_drydist=999;
			// look around, to find a dry spot
			for [{_a=0}, {_a<=270}, {_a=_a+90}] do {
				_dp=[_currPos,30,_a] call KRON_relPos;
				if !(surfaceIsWater _dp) then {_targetPos=_dp};
			};
			_newpos=true;
			_swimming=true;
		};
	} else {
		_swimming=false;
	};

	sleep 0.05;


//**********************************************************************************************************************
//   								NEWPOS:	SE	EJECUTA		LA	ORDEN 	DE 	MOVIMIENTO
//**********************************************************************************************************************
//	if (KRON_UPS_Debug>0) then {player sidechat format["%1 react=%2 _pursue=%3 _newpos=%4 %5 %6 %7",_grpidx,_react, _pursue,_newpos,_waiting,_timeontarget,_makenewtarget]};
//	if (KRON_UPS_Debug>0 && {_reinforcementsent}) then {player sidechat format["%1 %7 %8 pur=%4 rea=%2 tim=%6 rf=%9 tg=%10",_grpidx,_react,_gothit, _pursue,_waiting,_timeontarget,_fightmode,_nomove,_reinforcementsent,alive _target]};
	if ((_waiting<=0) && {_newpos}) then {

		_currPos = getpos _npc;
		_newpos = false;
		_waiting = -1;


		//if (KRON_UPS_Debug>0) then {player sidechat format["(%1) New Pos true",_grpidx]};
		if (_gothit) then {
			_gothit=false;

			//Nos ponemos en modo sigilo
			_Behaviour = "COMBAT";
			_npc setBehaviour _Behaviour;

			//Unidad suprimida
			if ((random 1)<.50) then {
				if (KRON_UPS_Debug>0) then {player sidechat format["%1 bajo fuego de supresion",_grpidx]};
				_gothit = false;

				//La unidad está suprimida, borramos el waypoint actual
				_supressed = true;
				_targetPos = _currPos;	_targettext ="SUPRIMIDA";

				//Se anula el movimiento
				_x setdir _dir1;
				[_x,10] spawn MON_doStop;

				//Cuerpo a tierra
				{if ((random 1)<.80) then {
					[_x,"DOWN",10] spawn MON_setUnitPosTime;
				}else{[_x,"Middle"] spawn MON_setUnitPos;};} foreach units _npc;


				//Retirada!!
				if ((random 1)<.01) then {
					_targetPos = _avoidPos;_targettext = "_avoidPos";
					_npc move _targetPos;
					_flankdir = 0;
				};
			};
 {
				if ((random 1)<.40) then {

					//Animación Esquivar granada
					if ((random 1)<.10) then {
						_x spawn MON_evadeGrenade;
					}else {
						//Animación croqueta
						if ( (random 1)<.30) then {
							_x spawn MON_animCroqueta;
						};
					};
				};
			} foreach units _npc;

			{ //Responder al ataque
				_x dowatch _target;
				_NearestEnemy = _x findNearestEnemy _x;
				_x dotarget _NearestEnemy;
				_x dofire _NearestEnemy;
			} foreach units _npc;


			//Cubre al grupo con una granada de humo
			if ((random 1)<.30) then {
				[_npc,_target] spawn MON_throw_grenade;
			};
		};

		//Si no ha sido suprimida continuamos el avance
		if (!_supressed) then {
			_index = currentWaypoint _grp;

			//No haq waypoints  o están completados
			//_index = 1 Waypoint por defecto, no usar.
			//if ( _index == 1 || {_index > count waypoints _grp} ) then {
			if ( _index < 3 ) then {
				_wp = _grp addWaypoint [_targetPos, 10];
				_index = _wp select 1;
			} else {
				_wp = [_grp,_index];
			};

			//Establecemos la actitud del grupo
			_npc setBehaviour _Behaviour;
			sleep 0.05;

			//Definimos los parámetros del nuevo waypoint
			_wp  setWaypointFormation _wpformation;
			_wp  setWaypointType _wptype;
			_wp  setWaypointSpeed _speedmode;
			_wp  setWaypointPosition [_targetPos, 10];


			{ //Si tiene más de 2 waypoints borramos los obsoletos
				if ( _x select 1 < _index - 1 ) then {
					deleteWaypoint _x;
				};
			}foreach waypoints _grp;
			//if (KRON_UPS_Debug>0) then {player sidechat format["%1 added waypoint %2 wp=%3 wps=%4",_grpidx,_index,_wp, count waypoints _grp]};

			//Aunque haya predefinido un tipo de movimiento se dejará un pequeño porcentaje para variar a nivel individual
			{if ((random 1)<.90) then {[_x,_unitpos] spawn MON_setUnitPos;}else{[_x,"AUTO"] spawn MON_setUnitPos;};} foreach units _npc;

			//Si estamos  muy cerca es peligroso que se muevan todos, se dejarán aleatoriamente algunos soldados estáticos defenciendo
			if (alive _target && {_npc distance (_target) <= _closeenough/1.5}) then { {
					if ((random 1)<.50) then {
						[_x,10] spawn MON_doStop;
					};
				} foreach units _npc;
			};

			//Si algún soldado tiene un edificio util cerca lo toma
			if ( ( _wptype == "HOLD" && {(random 1)<.60} || {_wptype != "HOLD"} && {(random 1)<.30}  )
				&& {_npc == vehicle _npc} && {_npc distance (_target) <= ( _closeenough + KRON_UPS_safedist ) }) then {
				_bldpos = 0;

				//Obtenemos los edificios cercanos al lider
				_blds = [_npc,60] call MON_GetNearestBuildings;
 {
					_bld 		= _x select 0;
					_bldpos 	= _x select 1;
					_cntobjs1 = 1;

					if (_bldpos > 10) then { _cntobjs1 = 2;};
					//Buscamos una unidad cercana para recorrerlo
					if (_cntobjs1 > 1 || {(random 1) < .50}) then {
						_blddist = 100000;
						_bldunitin = [];
						_i = 0;
 {
							if ( alive _x && {vehicle _x == _x} && {_x distance _bld < 50} && {_i < _cntobjs1}) then{
								_blddist = _x distance _bld;
								_bldunitin = _bldunitin + [_x];
								_i = _i + 1;
							};

						} foreach _members - [_npc];

						if (count _bldunitin > 0) then { {
								if (KRON_UPS_Debug>0) then {player sidechat format["%1 %2 patrullar %3 posiciones %4 %5",_grpidx,_bldunitin,typeof _bld,_bldpos, _cntobjs1];};
								[_x,_bld,_bldpos] spawn MON_patrolBuilding;
							}foreach _bldunitin;
						}else{
							if (KRON_UPS_Debug>0) then {player sidechat format["%1 No hay unidades cerca para patrullar %2",_grpidx,typeof _bld];};
						};
					};

				}foreach _blds;
			};
		};


		if (_track=="TRACK") then {
			switch (_fm) do {
				case 1:
					{_destname setmarkerSize [.4,.4]};
				case 2:
					{_destname setmarkerSize [.6,.6]};
				default
					{_destname setmarkerSize [.5,.5]};
			};
			if (_targettext == "SUPRIMIDA") then {
				_destname setMarkerPos [0,0];
			} else {
				_destname setMarkerPos _targetPos;
			};
		};
		_dist=0; _moved=0; _lastmove1=10;
		_swimming=false;

		//Refrescamos el target por si ha cambiado
		KRON_targetsPos set [_grpid,_targetPos];

		//moving
		if (KRON_UPS_Debug>0) then {player sidechat format["%1 %7 %2 %5 vel=%3 %4 %6 ",_grpidx,_targettext, _speedmode, _unitpos, _Behaviour, _wpformation, _wptype];	};
		//sleep .05;
	};//if ((_waiting<=0) && {_newpos}) then {


	// move on
	_lastdist = _dist; _lastmove2 = _lastmove1; _lastmove1 = _moved; _lastdamm = _damm;

	// check external loop switch
	_cont = (call compile format ["KRON_UPS_%1",_npcname]);
	if (_cont==0) then {_exit=true};


	if ((_exit) || {isNil("_npc")}) then {
		_loop=false;
	} else {
		// slowly increase the cycle duration after an incident
		if (_currcycle<_cycle) then {_currcycle=_currcycle+.5};
		sleep _currcycle;
	};
};//while {_loop}


if (KRON_UPS_Debug>0) then {player sidechat format["%1 exiting mainloop _cont %2 ",_grpidx,_cont]};

//Limpiamos variables globales de este grupo
KRON_targetsPos set [_grpid,[0,0]];
KRON_NPCs set [_grpid,objnull];

if !(isNil("_npc")) then {
	{doStop _x; _x domove getPos _x; _x move getPos _x} forEach _members;
};

KRON_UPS_Exited=KRON_UPS_Exited+1;
if (_track=="TRACK") then {
	//_trackername setMarkerType "Dot";
	_trackername setMarkerType "Empty";
	_destname setMarkerType "Empty";
};
_friends=nil;
_enemies=nil;

if(true) exitWith {}; 