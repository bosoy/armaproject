//Script simple de revive usando el A.C.E. Wounding module
//Version 1.6.1

_handle = [] execVM 'revive\Configuracion.sqf';
waitUntil {scriptDone _handle};//Wait for config read


/*******************************************************Config Check*******************************************************/
/*******************************************************============*******************************************************/
if (isnil 'ace_sys_wounds_noai') then {ace_sys_wounds_noai= true};
if (isnil 'ace_wounds_prevtime') then {ace_wounds_prevtime=400};
if (isnil 'ace_sys_wounds_withSpect') then {ace_sys_wounds_withSpect=true};
if (isnil 'Colum_revive_TKcheck') then {Colum_revive_TKcheck=true};
if (isnil 'Colum_revive_VerEnemigos') then {Colum_revive_VerEnemigos=true};
if (isnil 'Colum_revive_PvP') then {Colum_revive_PvP=false};
if (isnil 'Colum_revive_MochilaMedico') then {Colum_revive_MochilaMedico="ACE_VTAC_RUSH72_TT_MEDIC";};
if (isnil 'Colum_revive_MochilaMedico_Contenido') then {Colum_revive_MochilaMedico_Contenido=[20,20,20,2]};
if (isnil 'Colum_revive_JIPTelep') then {Colum_revive_JIPTelep=true};
if (isnil 'Colum_revive_Respawn') then {Colum_revive_Respawn=false};

if (isnil 'Colum_revive_Respawn_Side') then {Colum_revive_Respawn_Side=false};
if (isnil 'Colum_revive_Vidas_Side') then {Colum_revive_Vidas_Side=false};
if (isnil 'Colum_revive_Death_Markers') then {Colum_revive_Death_Markers=true};
if (isnil 'Colum_revive_Death_Messages') then {Colum_revive_Death_Messages=true};
if (isnil 'Colum_revive_Death_LeaveGroup') then {Colum_revive_Death_LeaveGroup=true};
if (isnil 'Colum_revive_Levanta_Heal') then {Colum_revive_Levanta_Heal=false};
if (isnil 'Colum_revive_New_LastLife_metod') then {Colum_revive_New_LastLife_metod=true};
if (isnil 'Colum_revive_KillOnConnectfail') then {Colum_revive_KillOnConnectfail=true};
if (isnil 'Colum_revive_RespawnButtonPunish') then {Colum_revive_RespawnButtonPunish=true};


if (isnil 'Colum_revive_Logic') then {Colum_revive_Logic= "logic" createVehicleLocal [0,0,0]};
_posbothil=getMarkerPos "Boot_hill";
if (((_posbothil select 0) == 0)&&((_posbothil select 1) == 0)) then // si no existe lo creamos
{	
	_Posbothil = switch toLower(worldName) do
	{
	  case 'chernarus': {[-6032.46,19052.2,0]};
	  case 'utes': {[1901.67,4361.25,0]};
	  case 'fallujah': {[9207.25,-1499.34,0]};
	  case 'sbrodj': {[1082.36,630.029,0]};
	  case 'spritzisland': {[7069.92,9650.15,0]};
	  case 'namalsk': {[8263.72,7723.37,0]};
	  case 'kolgujev2010': {[6902.75,16710.5,0]};
	  case 'isladuala': {[1562.01,9274.87,0]};
	  case 'lingor': {[11675.51,4783.38,0]};
	  case 'tropica': {[13383.4,2598.89,0]};
	  default {[0,0,0]};
	};
	createMarkerLocal ["Boot_hill", _Posbothil];
};
_posrespawn=getMarkerPos "respawn_west";
if (((_posrespawn select 0) == 0)&&((_posrespawn select 1) == 0)) then // si no existe lo creamos
{
	createMarkerLocal ["respawn_west", getMarkerPos "Boot_hill"];
};
if (!ace_sys_wounds_withSpect) then {ace_sys_wounds_withSpect=nil};
//Todo: check for  ace_sys_wounds_enabled ?
/***********************************************************************************************/


//Init number of lifes
Colum_revive_VidasLocal=nil;

//Old param read, only left here for retrocompatibility.
if (! isNil "_this" ) then {
	if (count _this > 0) then { Colum_revive_VidasMax= _this select 0 } else {Colum_revive_VidasMax=0};
	if (count _this > 1) then { ace_wounds_prevtime= _this select 1 };
	if (count _this > 2) then { ace_sys_wounds_noai= _this select 2 };
	if (count _this > 3) then { ace_sys_wounds_withSpect= _this select 3 };
};


if (Colum_revive_VidasMax <= 0) then { Colum_revive_VidasMax=1 }; // At least one life
 
//Asignacion de vidas
//Esperamos a que se sincronice el jugador
T_INIT 	= false;
T_Server 	= false; 
T_Client 	= false; 
T_JIP 	= false;

T_MP = (if (playersNumber east + playersNumber west + playersNumber resistance + playersNumber civilian > 0) then {true} else {false});

if (isServer) then 
{
	T_Server = true;
	if (!isNull player) then {T_Client = true};
	T_INIT = true;
} else {
	T_Client = true;
	if (isNull player) then 
	{
		T_JIP = true;
		[] spawn {waitUntil {!isNull player};T_INIT = true};
	} else {
		T_INIT = true;
	};
};
waitUntil {T_INIT};

if (T_Server) then { 
	[] spawn {Colum_revive_Iniciado = false; PublicVariable 'Colum_revive_Iniciado';
	sleep 60; Colum_revive_Iniciado = true; PublicVariable 'Colum_revive_Iniciado'}
};


Revive_Consulta_Vidas = {
	private ["_UserID","_Vidas"];

	_UserID= _this select 0;
	
	if (isNil ("Vidas"+ _UserID) ) then	{ _Vidas= -10} else { call compile format ["_Vidas=Vidas%1;",_UserID]};
		
	[-1,{ _this spawn Revive_FijarVidas}, [_UserID,_Vidas]] call CBA_fnc_globalExecute;
};

Revive_Update_vidas = {
	private ["_UserID","_Vidas"];

	_UserID= _this select 0;
	_Vidas= _this select 1;
	
	call compile format ["Vidas%1=%2;",_UserID,_Vidas];
};


Revive_FijarVidas = {
	private ["_UserIDJugador","_UserID","_Vidas"];
	_UserID= _this select 0;
	_Vidas= _this select 1;
	
	_UserIDJugador= (getPlayerUID player);
	
	If (_UserID == _UserIDJugador) then { if(_Vidas!=-10) then {Colum_revive_VidasLocal=_Vidas} else {Colum_revive_VidasLocal=Colum_revive_VidasMax}};
};

Colum_revive_LLamada_Medica = {
	private ["_Paciente","_Medico","_Pacientes"];
	_Medico= _this select 0;
	_Paciente= _this select 1;
	
	while {!isnil {_Medico getVariable "Colum_Revive_Paciente"}} do { sleep 2}; //Si esta atendiendo a alguien esperamos en vez de a±adirlo al array
	_Medico setVariable ["Colum_Revive_Paciente",_Paciente]; // Cambiado array por 1 solo, asi evitamos bucle continuo en el server mientras no hay pacientes
	[_Medico,_Paciente] spawn Colum_revive_AtencionMedica;
};


if (!T_Client) exitwith {}; // Nothing more to do for the server.

Colum_revive_LLamar_Medico = {
	private ["_Medico"];
	_Medico= _this;
	if (((player getVariable "ace_w_bleed") > 0)||((player getVariable "ace_w_pain") > 0) ||
	((player getVariable "ace_w_epi") != 0)) then {
		if ((player getVariable "ace_w_revive") > 0) then {player setVariable ["ace_w_revive",9999]};
		10 cutText ["You have entered a medic zone. Wait to be healed...","PLAIN",2];
		[0,{ _this spawn Colum_revive_LLamada_Medica}, [_Medico,player]] call CBA_fnc_globalExecute;
		sleep 60;//Espera al medico, evita multiples llamadas
	};
};


if (Colum_revive_Respawn_Side) then
{
	if (!isnil format["Colum_revive_RevButtons_%1",playerside]) then {
		ace_sys_spectator_RevButtons= call compile format["Colum_revive_RevButtons_%1",playerside];
		Colum_revive_RespawnMarkers= call compile format["Colum_revive_RespawnMarkers_%1",playerside];
		Colum_revive_RespawnOffset= call compile format["Colum_revive_RespawnOffset_%1",playerside];
	} else {
		Colum_revive_Respawn= false; // este bando no tiene respawns definidos
		ace_sys_spectator_RevShowButtonTime = nil;
	};
};

if (Colum_revive_Vidas_Side) then { Colum_revive_VidasMax= call compile format["Colum_revive_VidasMax_%1",playerside]};

/**********************************************FUNCIONES CLIENTES ***********************************************************************/
CambiarBotones = {
	//TODO: permitir mas de 4 respawns
	Disableserialization;
	private["_disp"];
	
	_disp = (findDisplay 55001);
};

AccionesRevive = {
	private["_posicion"];
	
	//Heal and reset all wound status
	player call ace_sys_wounds_fnc_unitInit;
	
	[player,0] call ace_sys_wounds_fnc_heal;
	
	if (_this >= 0) then {
		_posicion = getmarkerpos (Colum_revive_RespawnMarkers select _this);
		_posicion set [2, Colum_revive_RespawnOffset select _this];
		player setpos _posicion;
	};
};

Revive_CheckRespawn= {

	if (!Colum_revive_Respawn) exitwith{};
	if (((player getVariable "ace_w_revive") -time) < 13) then
	{
		//He is going to die!, avoid death to not lose equip
		[] spawn {
			player setVariable ["ace_w_revive",999999];
			sleep 15; // extra time, maybe he was been healed
			if (player call ace_sys_wounds_fnc_isUncon) then {0 spawn AccionesRevive};
		};
		
	};

};

Revive_Boton_Respawn_pulsado= 
{
	private["_unit","_corpose"];
	_unit = _this select 0;
	_corpose = _this select 1;
	
	if (!Colum_revive_Respawn || Colum_revive_RespawnButtonPunish) exitwith {[] spawn Colum_revive_evento_Muerte};

	if (Colum_revive_VidasLocal > 1) then {
		if ((player getVariable "ace_w_revive") <= 0) then {
			Colum_revive_VidasLocal=Colum_revive_VidasLocal-1;
			_idJugador = getPlayerUID player;
			[0,{ _this spawn Revive_Update_vidas}, [_idJugador,Colum_revive_VidasLocal]] call CBA_fnc_globalExecute;
		};
		cutText [" ", "black out", 1];
		sleep 5;
		
		_armas= weapons _corpose;
		_municion= magazines _corpose;
		deletevehicle _corpose;
		removeallweapons _unit;
		removeBackpack _unit;
		sleep 1;
		
		{_unit addweapon _x} foreach _armas;
		{_unit addmagazine _x} foreach _municion;
		
		titleText ["Please, ONLY use respawn button in needed situations","PLAIN DOWN"];
		sleep 10;
		titleText ["Reappearing...","PLAIN DOWN"];
		0 spawn AccionesRevive;
		sleep 3;
		titleText [" ","PLAIN DOWN"];
		cutText [" ", "black in", 0];
	} else {[] spawn Colum_revive_evento_Muerte};

};

Revive_Muerte_PJ = {
	private ["_Muerto","_MuertoSide","_Asesino","_NuevoMarcador","_TmpNombre","_Salir"];
	_Muerto= _this select 0;
	_MuertoSide= _this select 1;
	if (count _this  > 2) then {_Asesino= _this select 2} else {_Asesino=nil};
	_Salir=if (Colum_revive_PvP) then {if (_MuertoSide != playerside)then {true} else{false}}else{false};
	if (_Salir) exitwith{};
	
	if (Colum_revive_Death_Markers) then {
		_NuevoMarcador = createMarkerlocal [format["muer%1", name _Muerto],getPos _Muerto];
		_NuevoMarcador setMarkerShapelocal "ICON";
		_NuevoMarcador setMarkerTypelocal "hd_destroy";
		_NuevoMarcador setMarkerTextlocal format["%1 wounded",(name _Muerto)];
		_NuevoMarcador setMarkerColorlocal "ColorBlue";
	};
	
	if (Colum_revive_Death_Messages) then {
		Colum_revive_Logic globalchat format["%1 is heavily wounded", name _Muerto];
	};
	
	if (!isnil "_Asesino") then {
		[_Muerto,_Asesino] call Revive_TK_Mensaje; 
	};
	
	 //Wait for uncons, maybe lag can mess arround :P
	waituntil {(_Muerto call ace_sys_wounds_fnc_isUncon)};
	
	if (Colum_revive_Death_Markers) then {
		while {(!isnull _Muerto) && (alive _Muerto) && (_Muerto call ace_sys_wounds_fnc_isUncon)} do
		{
			_NuevoMarcador SetMarkerPoslocal (getPos _Muerto);sleep 7;
		};
		deleteMarkerlocal _NuevoMarcador;
	};
};

Revive_TK_Mensaje = {
	private ["_Muerto","_Asesino"];
	_Muerto=_this select 0;
	_Asesino= _this select 1;
	[playerSide, "HQ"] sideChat format["%1 Friendly Fire!!, you have wounded %2",name _Asesino,name _Muerto];
};

Revive_Keypressedcode={
	Private["_target","_Escuadra","_Lider","_tmpos","_tmposALT","_tmposX","_tmposY","_tmposZ"];
	if ((_this select 1) == 88) then{
		_Lider =(leader player);
		_target= objnull; // Not valid leader
		if ((_Lider == player)||( _Lider call ace_sys_wounds_fnc_isUncon)) then
		{
			_Escuadra = units (group player);
			{
				if (alive _x) then {
					if (!(_x call ace_sys_wounds_fnc_isUncon)) exitwith { _target= _x };
				};
			} foreach _Escuadra;
			if (isnull _target) then
			{
				_Escuadra = allunits;
				{
					if ((alive _x) && (isplayer _x)) then {
						if ((side _x) == playerside) then {
							if (!(_x call ace_sys_wounds_fnc_isUncon)) exitwith { _target= _x };
						};
					};
				} foreach _Escuadra;
			};
		} else { _target= _Lider};
		if (!isnull _target) then
		{
			_tmpos= getPosATL _target;
			_tmposX=_tmpos select 0; _tmposY=_tmpos select 1; _tmposZ=_tmpos select 2;
			_tmpos set[0,(_tmposX+ (random 2) -1)];
			_tmpos set[1,(_tmposY+ (random 2) -1)];
			
			if (_tmposZ > 1) then {
			
				//Detect buildings
				_tmposALT=_tmpos findEmptyPosition [1,30, typeof player];
				if ((count _tmposALT) > 1) then {_tmpos=_tmposALT};
			};
			player setPosATL _tmpos;
			Revive_Keypressedcode={true};
		};
	};
	true;
};
	
Revive_TelepSquad= { 
	Private["_revive_Keypressed"];
	sleep 5;
	waitUntil {!isNil "Colum_revive_VidasLocal"}; 
	if (Colum_revive_VidasLocal > 0) then
	{
		_revive_Keypressed = (findDisplay 46) displayAddEventHandler ["KeyUp","_this call Revive_Keypressedcode"];
		10 cutText ["Press F12 within the next 5 minutes to teleport with your squad/allies","PLAIN",2];
		Sleep 400; // en realidad algo mas de 5 mins pero para que se den prisa :P
		(findDisplay 46) displayRemoveEventHandler ["KeyUp",_revive_Keypressed]
	};
};

Revive_NuevoLider = {
	private ["_Escuadra"];
	if ((leader player) == player) then 
	{
		_Escuadra = units (group player);
		{
			if (alive _x && (!(_x call ace_sys_wounds_fnc_isUncon))) exitwith {
				(group player) selectleader _x;
			};
		} foreach _Escuadra;
	};
};

Revive_RenombraLider = {
	private ["_Escuadra","_lider","_liderORG"];
	 _lider=(leader player);
	 _liderORG=_lider;
	if (_lider != player) then 
	{
		_Escuadra = units (group player);
		{ if (!(_x call ace_sys_wounds_fnc_isUncon)&& alive _x) then {if ((rankId _x) > (rankId _lider)) then { _lider= _x }}} foreach _Escuadra;
		if( _liderORG != _lider) then { (group player) selectleader _lider};
	};
};

Revive_MochilaMedica = {
	private ["_Secundaria","_cantidad"];
	if (isnil "Colum_revive_MochilaMedico") exitwith{};
	if (Colum_revive_MochilaMedico=='') exitwith{};
	if (!([player] call ace_sys_wounds_fnc_isMedic)) exitwith{};
 
	sleep 8;
	if (!([player] call ACE_fnc_HasRuck)) then {
		_Secundaria= secondaryWeapon player;
		if (_Secundaria != '') then {[player, _Secundaria] call ACE_fnc_PutWeaponOnBack;sleep .5};
		player addweapon Colum_revive_MochilaMedico;
	};
	sleep .5;
	_cantidad= Colum_revive_MochilaMedico_Contenido select 0;
	if (_cantidad > 0) then{ [player, "ACE_Bandage",_cantidad ] call ACE_fnc_PackMagazine};
	_cantidad= Colum_revive_MochilaMedico_Contenido select 1;
	if (_cantidad > 0) then{[player, "ACE_Morphine",_cantidad ] call ACE_fnc_PackMagazine};
	_cantidad= Colum_revive_MochilaMedico_Contenido select 2;
	if (_cantidad > 0) then{[player, "ACE_Epinephrine",_cantidad ] call ACE_fnc_PackMagazine};
	_cantidad= Colum_revive_MochilaMedico_Contenido select 3;
	if (_cantidad > 0) then{[player, "SmokeShellGreen",_cantidad ] call ACE_fnc_PackMagazine};
	_cantidad= Colum_revive_MochilaMedico_Contenido select 4;
	if (_cantidad > 0) then{[player, "ACE_Medkit",_cantidad ] call ACE_fnc_PackMagazine};
};


Colum_revive_evento_Muerte= compile preprocessFileLineNumbers 'revive\muerte.sqf';
/*******************************************FIN FUNCIONES CLIENTES ***********************************************************************/
/***********************************************************************************************************************************************/
Player addMPeventhandler ['MPRespawn',{_this spawn Revive_Boton_Respawn_pulsado}];

[] spawn {
	Private["_idJugador"];
	waitUntil {!isNil "Colum_revive_Iniciado"}; 
	
	if (Colum_revive_Iniciado) then { //If the mission already started and 60 seconds have passed
		_idJugador =getPlayerUID player;
		_W_clycle_count=0;
		while {(isNil "Colum_revive_VidasLocal") && (_W_clycle_count < 10)} do {
			[0,{ _this spawn Revive_Consulta_Vidas}, [_idJugador]] call CBA_fnc_globalExecute;
			sleep (7 + (random 7)); _W_clycle_count = _W_clycle_count +1;
		};
		if (isNil "Colum_revive_VidasLocal") then {
			if (Colum_revive_KillOnConnectFail) then {
				Colum_revive_VidasLocal = 0;
			}else {
				Colum_revive_VidasLocal = Colum_revive_VidasMax;
			};
			Hint 'Error JIP, por favor reporta este error'; 
			sleep 10; 
		}; //If no lives recived, default = death

		if (Colum_revive_JIPTelep) then { [] spawn Revive_TelepSquad};
	}else{ // Server not started or in the first 60 seconds = max lives
		Colum_revive_VidasLocal=Colum_revive_VidasMax;
	};
};

waitUntil {!isNil "Colum_revive_VidasLocal"}; 


if (Colum_revive_VidasLocal <= 0) exitwith{[] spawn Colum_revive_evento_Muerte}; //No lives left => exit && espectator
if (Colum_revive_VidasLocal == 1) then {ace_wounds_prevtime = nil};

//Life loss event script
Colum_revive_evento_HeridoGrave= compile preprocessFileLineNumbers 'revive\Evento_herido.sqf';
["ace_sys_wounds_rev", {player spawn Colum_revive_evento_HeridoGrave}] call CBA_fnc_addEventhandler;


if (Colum_revive_TKcheck) then { ExecVM "revive\JugadorHit.sqf" }; //Detect TK's

[] spawn Revive_MochilaMedica;

hint format["Lifes: %1 de %2",Colum_revive_VidasLocal-1,Colum_revive_VidasMax-1]; ];