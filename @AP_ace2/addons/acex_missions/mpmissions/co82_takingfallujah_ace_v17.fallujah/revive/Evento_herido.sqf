//Bucle de control de vidas :)
private ["_Asesino","_parametros","_idJugador"];

	
if (Colum_revive_VidasLocal !=1000) then {
	//One live less
	Colum_revive_VidasLocal=Colum_revive_VidasLocal-1;
	_idJugador = getPlayerUID player;
	[0,{ _this spawn Revive_Update_vidas}, [_idJugador,Colum_revive_VidasLocal]] call CBA_fnc_globalExecute;
};

if (Colum_revive_VidasLocal <= 0) exitwith {};

//Count down while uncons
ace_sys_spectator_can_exit_spectator=false;
//[] spawn { sleep ace_sys_spectator_RevShowButtonTime; BotonesRevive=true; call CambiarBotones };

_parametros=[player,playerside];
if (Colum_revive_TKcheck) then {
	_Asesino = [] call JugadorComprobarTK;	if (!isnil "_Asesino") then { _parametros=_parametros +[_Asesino]};
};

[-1,{ _this spawn Revive_Muerte_PJ}, _parametros] call CBA_fnc_globalExecute;

While { ((player getVariable "ace_w_revive") > 0) && (alive player)} do {sleep 9; call Revive_NuevoLider; call Revive_CheckRespawn};

//Restore mapclick event(spectator removes it)
if (!isnil"EventoMapClick") then {
	[] spawn 
	{
		if (!isNil 'ace_sys_spectator_SPECTATINGON') then 
		{ waitUntil {isNil 'ace_sys_spectator_SPECTATINGON'}};
		sleep 2; waitUntil {!isNull player}; onMapSingleClick EventoMapClick;
	};
};
if (!alive player) then {waitUntil {alive player}};
call Revive_RenombraLider;
if (Colum_revive_Levanta_Heal) then {-1 spawn AccionesRevive};
hint format["Lifes: %1 de %2",Colum_revive_VidasLocal-1,Colum_revive_VidasMax-1];

if (Colum_revive_VidasLocal <= 1) then{
	if (Colum_revive_New_LastLife_metod) then{
		ace_wounds_prevtime = nil;
	}else{
		ace_wounds_prevtime = 1;
	};	
}; // ToDo: check if this new method for last life can cause conflicts with ACE wounds.