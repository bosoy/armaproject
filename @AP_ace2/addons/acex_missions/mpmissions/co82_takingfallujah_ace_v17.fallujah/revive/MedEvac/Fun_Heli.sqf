//Funciones de la evacuacion en heli
Colum_revive_AcVueltaHeli= {
	private ["_Heli","_Accion"];
	_Heli= _this;
	_Accion=_Heli addAction ["<t color='#f001DF01'>Everybody in, Go, GO, GO!</t>", "revive\MedEvac\accion.sqf", 1,0];
	_Heli setvariable ["revive_accion_Casa",_Accion];
};

Colum_revive_RMAcVueltaHeli= {
	private ["_Heli","_Accion"];
	_Heli= _this;
	_Accion=_Heli getVariable "revive_accion_Casa";
	_Heli removeaction _Accion;
	4 spawn Colum_revive_HeliMSG; //vuelve a casa( ahorramos broadcast 1 msg)
	_Heli setvariable ["revive_accion_Casa",nil];
};

Colum_revive_HeliMSG= {
	switch(_this) do
	{
	  case 0: { [playerside,"HQ"] sidechat "There is no medevac avaliable at the moment"};
	  case 1: { [playerside,"HQ"] sidechat "Smoke in sight"};
	  case 2: { [playerside,"HQ"] sidechat "We can't locate the smoke, we are low of fuel, returning to base"};
	  case 3: { [playerside,"HQ"] sidechat "HQ understood, sending medevac. Get ready to throw green smoke"};
	  case 4: { [playerside,"HQ"] sidechat "Roger, medevac returnig base"};
	  case 5: { [playerside,"HQ"] sidechat "Medevac aproaching landing zone, mark a safe zone with green smoke"};
	  case 6: { [playerside,"HQ"] sidechat "Negative, you are almost in the base."};
	};
};

Colum_revive_HeliAutoExtracc= {
	private ["_Heli","_Accion"];
	_Heli= _this;
	if (player in _heli) then
	{
		if (player call ace_sys_wounds_fnc_isUncon) then
		{
			{
				if (_x distance player < 200) then {
					_tmppos= getpos _x;
					_tmppos set [0, (((_tmppos select 0) -5) + random 10)];
					_tmppos set [1, (((_tmppos select 1) -5) + random 10)];
					player action ["eject", vehicle player];
					waituntil {(vehicle player == player)};
					sleep 5;
					player setpos _tmppos;
				};
			} foreach Colum_Revive_MedicoList;
		};
	};
};

if (!isServer) exitwith {}; 
/************************************************************************************************************/
/*******************************************Funciones server***************************************************/
/************************************************************************************************************/

Colum_revive_HeliEvac= {
	private ["_Heli","_HeliCount","_posicion","_piloto","_GrupoEvac"];
	_posicion= _this select 0;
	
	{ 
		if (( _x getVariable 'Colum_Revive_HeliOcupado') == 0 )exitwith {
			_Heli = _x;
			_HeliCount= _x getVariable 'Colum_Revive_HeliNum';
		} 
	} foreach Colum_Revive_HeliList;
	
	if (isnil "_Heli") exitwith { [-1,{ 0 spawn Colum_revive_HeliMSG}, []] call CBA_fnc_globalExecute}; // No hay helis
	if ((_Heli distance _posicion)< 400)exitwith {[-1,{ 6 spawn Colum_revive_HeliMSG}, []] call CBA_fnc_globalExecute}; // esta demasiado cerca de la base
	[-1,{ 3 spawn Colum_revive_HeliMSG}, []] call CBA_fnc_globalExecute; // heli en camino
	_Heli setVariable ["Colum_Revive_HeliOcupado",1];
	
	_piloto= driver _Heli;
	_GrupoEvac= group _piloto;
	_Heli engineOn true;
	_Heli flyInHeight 100;
	_GrupoEvac setBehaviour "CARELESS";

	_way_count = waypoints _GrupoEvac;
	{ deleteWaypoint _x } forEach _way_count;

	if(alive _Heli && isEngineOn _Heli) then{
		_wpreinsert = _GrupoEvac addWaypoint [_posicion, 0];
		_wpreinsert setWaypointType "MOVE";
		_wpreinsert setWaypointSpeed "FULL";
		_GrupoEvac setCurrentWaypoint _wpreinsert;
	};
	
	_timeout = time + 120; // _timeout < time
	_lastpos= getpos _heli;
	
	while {((alive _piloto) && ((_heli distance _posicion) > 2000)) || ((getPosATL _Heli) select 2 < 1)} do
	{
		if (((getpos _heli distance _lastpos) < 20) &&( _timeout < time)) exitwith {}; //quieto??? ummm algo fallo
		_lastpos= getpos _heli;
		sleep 10;
	};
	
	
	[-1,{ 5 spawn Colum_revive_HeliMSG}, []] call CBA_fnc_globalExecute;//esperando humo
	 _timeout = time + 120;
	 _EncontradoHumo=false;
	 while {_timeout > time && !(_EncontradoHumo)} do {
		//_list= nearestObjects [_posicion, ["G_40mm_SmokeGreen","SMOKESHELLGREEN"], 200];
		_list=_posicion nearObjects ["SMOKESHELLGREEN",150];
		if (count _list > 0) exitwith{_posicion=getpos (_list select 0); _EncontradoHumo=true};
		sleep 1;
		_list=_posicion nearObjects ["G_40mm_SmokeGreen",150];
		if (count _list > 0) exitwith{_posicion=getpos (_list select 0); _EncontradoHumo=true};
		sleep 10;
	 };

	 if ( _EncontradoHumo) then
	 {
		[-1,{ 1 spawn Colum_revive_HeliMSG}, []] call CBA_fnc_globalExecute;//Humo avistado
		[_Heli,_posicion] call Colum_revive_HeliEvac_Aterri;
		[-1,{ _this spawn Colum_revive_AcVueltaHeli}, _Heli] call CBA_fnc_globalExecute;
	 } else {
		[-1,{ 2 spawn Colum_revive_HeliMSG}, []] call CBA_fnc_globalExecute;//No Humo
		_heli spawn Colum_revive_HeliEvac_VueltaBase;
	 };
};

Colum_revive_HeliEvac_Aterri= {
	private ["_Heli","_HeliCount","_posicion","_piloto","_GrupoEvac"];
	_Heli= _this select 0;
	_posicion= _this select 1;
	
	_piloto= driver _Heli;
	_GrupoEvac= group _piloto;
	_HeliCount= _Heli getVariable 'Colum_Revive_HeliNum';
	
	_Heli setVariable ["Colum_Revive_HeliOcupado",2]; // estado heli 2, aterrizando


	_wpreinsert = _GrupoEvac addWaypoint [_posicion, 0];
	_wpreinsert setWaypointType "MOVE";
	_wpreinsert setWaypointSpeed "FULL";
	_wpreinsert setWaypointStatements ["true", format["(Colum_Revive_HeliList select %1) land 'LAND';(Colum_Revive_HeliList select %1) flyInHeight 4; (Colum_Revive_HeliList select %1) setVariable ['Colum_Revive_HeliOcupado',3];",_HeliCount]];
	_GrupoEvac setCurrentWaypoint _wpreinsert;
	
	_timeout = time + 80;
	 while {(_timeout > time) && ((getPosATL _Heli) select 2 > 0.5)&& ((_Heli getVariable "Colum_Revive_HeliOcupado")==2)} do {
		sleep 10;
	 };
	 
	 _timeout = time + 180;
	 while {(_timeout > time) && ((getPosATL _Heli) select 2 > 0.5)} do {
		_Heli land "LAND";
		sleep 10;
	 };

	if ((getPosATL _Heli) select 2 > 0.5) exitwith{ _heli spawn Colum_revive_HeliEvac_VueltaBase };//Si no aterriza que intente volver a base
	
	_Heli engineOn false;
	_way_count = waypoints _GrupoEvac;
	{ deleteWaypoint _x } forEach _way_count;

};

Colum_revive_HeliEvac_VueltaBase= {
	private ["_Heli","_HeliCount","_posicion","_piloto","_GrupoEvac"];
	_Heli= _this;
	_posicion=getpos (_Heli getVariable "Colum_Revive_HeliBase");
	
	
	_piloto= driver _Heli;
	_GrupoEvac= group _piloto;
	_Heli engineOn true;
	_Heli flyInHeight 100;
	_HeliCount= _Heli getVariable 'Colum_Revive_HeliNum';
	_GrupoEvac setBehaviour "CARELESS";

	
	[-1,{ _this call Colum_revive_RMAcVueltaHeli}, _Heli] call CBA_fnc_globalExecute;
	_Heli setVariable ["Colum_Revive_HeliOcupado",4]; // estado heli 4, vuelve a casa vueeelve
	
	_way_count = waypoints _GrupoEvac;
	{ deleteWaypoint _x } forEach _way_count;


	_wpreinsert = _GrupoEvac addWaypoint [_posicion, 0];
	_wpreinsert setWaypointType "MOVE";
	_wpreinsert setWaypointSpeed "FULL";
	_wpreinsert setWaypointStatements ["true", format["(Colum_Revive_HeliList select %1) land 'LAND';(Colum_Revive_HeliList select %1) flyInHeight 4; (Colum_Revive_HeliList select %1) setVariable ['Colum_Revive_HeliOcupado',5];",_HeliCount]];
	_GrupoEvac setCurrentWaypoint _wpreinsert;

	
	_timeout = time + 120;
	_lastpos= getpos _heli;
	//Esperamos a que llegue
	while {(alive _piloto) && ((_heli distance _posicion) > 200)} do
	{
		if (((getpos _heli distance _lastpos) < 20) &&( _timeout < time)) exitwith {}; //quieto??? ummm algo fallo
		_lastpos= getpos _heli;
		sleep 10;
	};
	
	
	_timeout = time + 120;
	//Forzar aterrizaje
	 while {(_timeout > time) && ((getPosATL _Heli) select 2 > 0.5)&& ((_Heli getVariable "Colum_Revive_HeliOcupado")==4)} do {
		sleep 10;
	 };
	 
	 _timeout = time + 50;
	 while {(_timeout > time) && ((getPosATL _Heli) select 2 > 0.5)} do {
		_Heli land "LAND";
		sleep 10;
	 };
	
	if (alive _Heli && (Alive (driver _Heli))) then {
		_Heli setVariable ["Colum_Revive_HeliOcupado",0];
		_Heli engineOn false;
		_Heli setpos _posicion;
		_Heli setdamage 0;
		_Heli setfuel 1;
		[-1,{ _this spawn Colum_revive_HeliAutoExtracc}, _Heli] call CBA_fnc_globalExecute;//autoextraemos los incoscientes
		
	};
	
};

Colum_revive_HeliPilotoMuerto= {
	private ["_Heli"];
	_Heli= vehicle (_this select 0);
	_Heli setfuel 0;//quitamos gasofa si matan al piloto, para evitar cabroncetes xD
};