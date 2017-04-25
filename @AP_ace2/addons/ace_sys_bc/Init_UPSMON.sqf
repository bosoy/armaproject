// =========================================================================================================
//  Urban Patrol Script  by Monsada
//  Version: 4.2.2
//  Author: Monsada (smirall@hotmail.com)
//		http://www.simulacion-esp.com/
//		Comunidad Hispana de Simulación
// =========================================================================================================
//  Basado en el script Urban Patrol Script  de Kronzky
//  Version: 2.0.3
//  Author: Kronzky (www.kronzky.info / kronzky@gmail.com)
// ---------------------------------------------------------------------------------------------------------

//Habilita el estado de debug, el cual permite ver la posición de los grupos así como a donde se dirigen,
//en modo local tambien muestra mensajes del comportamiento de la IA
KRON_UPS_Debug = 0;

//Tiempo que tarda en calcular un nuevo movimiento (en combate), no le des poco tiempo o no hará más que moverse
KRON_UPS_react = 60;

//Parámetro para patrullas (MOVE) Tiempo de espera máxima cerca del objetivo, transcurrido este tiempo  las patrullas se moveran a otro punto
KRON_UPS_maxwaiting = 120;

// how long AI units should be in alert mode after initially spotting an enemy
//Tiempo que las unidades permanecen alerta, este parámetro debe ser siempre superior a KRON_UPS_maxwaiting
KRON_UPS_alerttime= 180;

// how far opfors should move away if they're under attack
// Distancia de seguridad, se usa para calcular la distancia de flanqueo al objetivo
KRON_UPS_safedist = 300;

// how close unit has to be to target to generate a new one target or to enter stealth mode
// Se usa para determinar cuando es suficientemente cerca del objetivo, influye en la actitud de la IA
KRON_UPS_closeenough = 250;

// how close units have to be to each other to share information, over this, will lose target
//Distancia a la que tiene que estar el grupo de un enemigo conocido para que se les comunique la posición del enemigo.
//Fuera de este radio la IA puede perder el rastro
//Las patrullas con rol "MOVE" tendrán un 1.5 de este valor
KRON_UPS_sharedist = 500;

//If enabled IA comunicating between them with radio defined sharedist distance,
//1 check if visible friends in range (sharedist) are injured,  //Detecta cuando han herido a un compañero, menos óptimo
//2 check if enemy position is in range to atackt (sharedist) //Simula la comunicacion por radio entre la IA
KRON_UPS_comradio = 2;

//Distancia que debe haber de las unidades a los edificios para  cosiderarlo una ciudad y poder entrar en modo combate urbano
//KRON_UPS_intowndist = 60;  //deshabilitado por comportamientos extraños con algunos objetos builiding

//Habilita el envio de refuerzos cuando el enemigo es detectado, lo normal es que esté siempre a false
// y se use un trigger para activar/desactivar esta opcción
KRON_UPS_reinforcement = false;

//Establece los bandos de enemigos que debe considerar la IAs de la resistencia
KRON_UPS_Res_enemy = [east];

//Tiempo en segundos que tarda en volver a ejecutarse
KRON_UPS_Cycle = 20;


//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//		Private Variables
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	KRON_UPS_flankAngle = 45; //Angulo de flanqueo
	KRON_UPS_INIT = 0;        //Variable que indica que ha sido inicializado
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Init library function

// ***************************************** SERVER INITIALIZATION *****************************************
//sleep 1;

	// global functions
if (isNil("KRON_UPS_INIT") || KRON_UPS_INIT == 0) then {
	KRON_UPS_INIT=0;

	// declaración de variables privadas
	private["_obj","_trg","_l","_pos"];

	//Funciones
	KRON_randomPos = {private["_cx","_cy","_rx","_ry","_cd","_sd","_ad","_tx","_ty","_xout","_yout"];_cx=_this select 0; _cy=_this select 1; _rx=_this select 2; _ry=_this select 3; _cd=_this select 4; _sd=_this select 5; _ad=_this select 6; _tx=random (_rx*2)-_rx; _ty=random (_ry*2)-_ry; _xout=if (_ad!=0) then {_cx+ (_cd*_tx - _sd*_ty)} else {_cx+_tx}; _yout=if (_ad!=0) then {_cy+ (_sd*_tx + _cd*_ty)} else {_cy+_ty}; [_xout,_yout]};
	KRON_PosInfo = {private["_pos","_lst","_bld","_bldpos"];_pos=_this select 0; _lst=_pos nearObjects ["House",12]; if (count _lst==0) then {_bld=0;_bldpos=0} else {_bld=_lst select 0; _bldpos=[_bld] call KRON_BldPos}; [_bld,_bldpos]};
	KRON_PosInfo3 = {private["_pos","_lst","_bld","_bldpos"];_pos=_this select 0; _lst= nearestObjects [_pos, [], 3];
		if (count _lst==0) then {_bld=objnull;_bldpos=0} else {_bld = nearestbuilding (_lst select 0);
		//if (KRON_UPS_Debug>0) then {player sidechat format["%1 building %2",_grpidx,_bld]};
		_bldpos=[_bld] call KRON_BldPos2}; [_bld,_bldpos]};
	KRON_BldPos = {private ["_bld","_bldpos","_posZ","_maxZ"];_bld=_this select 0;_maxZ=0;_bi=0;_bldpos=0;while {_bi>=0} do {if (((_bld BuildingPos _bi) select 0)==0) then {_bi=-99} else {_bz=((_bld BuildingPos _bi) select 2); if (((_bz)>4) && {_bz>_maxZ || {(_bz==_maxZ) && {random 1>.8}}}) then {_maxZ=_bz; _bldpos=_bi}};_bi=_bi+1};_bldpos};
	KRON_BldPos2 = {private ["_bld","_bldpos"];
						_bld=_this select 0; _bldpos = 1;
						while {format ["%1", _bld buildingPos _bldpos] != "[0,0,0]"}  do {_bldpos = _bldpos + 1;};
					_bldpos = _bldpos - 1; _bldpos;};
	KRON_OnRoad = {private["_p","_w","_i","_lst"];_p=_this select 0; _w=_this select 1; _i=_this select 2; _lst=_p nearObjects ["House",12]; if ((count _lst==0) && {(_w || !(surfaceIsWater _p))}) then {_i=99}; (_i+1)};
	KRON_getDirPos = {private["_a","_b","_from","_to","_return"]; _from = _this select 0; _to = _this select 1; _return = 0; _a = ((_to select 0) - (_from select 0)); _b = ((_to select 1) - (_from select 1)); if (_a != 0 || _b != 0) then {_return = _a atan2 _b}; if ( _return < 0 ) then { _return = _return + 360 }; _return};
	KRON_distancePosSqr = {((((_this select 0) select 0)-((_this select 1) select 0))^2 + (((_this select 0) select 1)-((_this select 1) select 1))^2)^0.5};
	KRON_relPos = {private["_p","_d","_a","_x","_y","_xout","_yout"];_p=_this select 0; _x=_p select 0; _y=_p select 1; _d=_this select 1; _a=_this select 2; _xout=_x + sin(_a)*_d; _yout=_y + cos(_a)*_d;[_xout,_yout,0]};
	KRON_rotpoint = {private["_cp","_a","_tx","_ty","_cd","_sd","_cx","_cy","_xout","_yout"];_cp=_this select 0; _cx=_cp select 0; _cy=_cp select 1; _a=_this select 1; _cd=cos(_a*-1); _sd=sin(_a*-1); _tx=_this select 2; _ty=_this select 3; _xout=if (_a!=0) then {_cx+ (_cd*_tx - _sd*_ty)} else {_cx+_tx}; _yout=if (_a!=0) then {_cy+ (_sd*_tx + _cd*_ty)} else {_cy+_ty}; [_xout,_yout,0]};
	KRON_stayInside = {
		private["_np","_nx","_ny","_cp","_cx","_cy","_rx","_ry","_d","_tp","_tx","_ty","_fx","_fy"];
		_np=_this select 0;	_nx=_np select 0;	_ny=_np select 1;
		_cp=_this select 1;	_cx=_cp select 0;	_cy=_cp select 1;
		_rx=_this select 2;	_ry=_this select 3;	_d=_this select 4;
		_tp = [_cp,_d,(_nx-_cx),(_ny-_cy)] call KRON_rotpoint;
		_tx = _tp select 0; _fx=_tx;
		_ty = _tp select 1; _fy=_ty;
		if (_tx<(_cx-_rx)) then {_fx=_cx-_rx};
		if (_tx>(_cx+_rx)) then {_fx=_cx+_rx};
		if (_ty<(_cy-_ry)) then {_fy=_cy-_ry};
		if (_ty>(_cy+_ry)) then {_fy=_cy+_ry};
		if ((_fx!=_tx) || (_fy!=_ty)) then {_np = [_cp,_d*-1,(_fx-_cx),(_fy-_cy)] call KRON_rotpoint};
		_np;
	};


	// Misc
	KRON_UPSgetArg = {private["_cmd","_arg","_list","_a","_v"]; _cmd=_this select 0; _arg=_this select 1; _list=_this select 2; _a=-1; {_a=_a+1; _v=format["%1",_list select _a]; if (_v==_cmd) then {_arg=(_list select _a+1)}} foreach _list; _arg};
	KRON_deleteDead = {private["_u","_s"];_u=_this select 0; _s= _this select 1; _u removeAllEventHandlers "killed"; sleep _s; deletevehicle _u};

	KRON_AllTroops=[];
	KRON_AllWest=[];
	KRON_AllEast=[];
	KRON_AllRes=[];
	KRON_targets0 =[];//objetivos west
	KRON_targets1 =[];//objetivos east
	KRON_targets2 =[];//resistence
	KRON_KnownEnemy=[objNull,objNull];
	KRON_targetsPos =[];//Posiciones de destino actuales.
	KRON_NPCs = []; //Lideres de los grupos actuales

	_obj = _this select 0;
	_pos = [5000,5000];
	if (typename _obj=="OBJECT") then {_pos=position _obj};
	_trg=createTrigger ["EmptyDetector", _pos];
	_trg setTriggerArea [20000,20000,0,false];
	_trg setTriggerActivation ["ANY","PRESENT",false];
	_trg setTriggerTimeout [1,1,1,false];
	sleep 1 + (random 1);
	_l=[];
	_l=list _trg;
	deleteVehicle _trg; {
		if (("AllVehicles" countType [_x]>0) && {(side _x != civilian)}) then {
			KRON_AllTroops=KRON_AllTroops+[_x];
			_s = side _x;
			switch (_s) do {
				case west:
					{ KRON_AllWest=KRON_AllWest+[_x]; };
				case east:
					{ KRON_AllEast=KRON_AllEast+[_x]; };
				case resistance:
					{ KRON_AllRes=KRON_AllRes+[_x]; };
			};
		};
		//sleep .05;
	} forEach _l;
	_l = nil;

	if (isNil("KRON_UPS_Debug")) then {KRON_UPS_Debug=0};
	//KRON_HQ="Logic" createVehicle [0,0];
	KRON_UPS_Instances=0;
	KRON_UPS_Total=0;
	KRON_UPS_Exited=0;
	KRON_UPS_INIT=1;
};
