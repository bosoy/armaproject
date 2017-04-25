// =========================================================================================================
//  Biblioteca de funciones comunes
//  Version: 3.0.0
//  Author: Monsada (smirall@hotmail.com)
//		http://www.simulacion-esp.com/
//		Comunidad Hispana de Simulación
// =========================================================================================================

// ---------------------------------------------------------------------------------------------------------
//Función que permite posicionar objetos a la altura definida
//param1: objeto
//param2: altura
MON_subir = {
private ["_object","_altura","_pos","_x","_y","_z","_bld","_bldpos"];

_object = _this select 0;
_altura = _this select 1;

_x = 0;
_y = 0;
_z = 0;
_pos =0;
_bld = objnull;
_bldpos =0;

_pos = getposasl _object;

_x = _pos select 0;
_y = ( _pos select 1 );
_z = ( _pos select 2 ) + _altura;
_object setposasl [_x,_y ,_z];
};

// ---------------------------------------------------------------------------------------------------------
//Función de borra unidades que han sido matadas
//param1: objeto a borrar cuando muera
//param2: tiempo a esperar antes de borrar el objeto
MON_deleteDead = {private["_u","_s"];_u=_this select 0; _s= _this select 1; _u removeAllEventHandlers "killed"; sleep _s; deletevehicle _u};
MON_deleteDeadDist = {private["_u","_s","_dist","_OCercanos","_cicle","_deleted","_isplayer"];
	_i = 0;
	_cicle = 10;
	_deleted = false;
	_isplayer = false;
	_u = _this select 0; _s = _this select 1; _dist = _this select 2;
	_u removeAllEventHandlers "killed";
	sleep _s;

	while {!_deleted} do {
		_isplayer = false;
		//Buscamos objetos cercanos
		_OCercanos = nearestObjects [_u, ["Man"] , _dist];

		//Validamos si alguno de los soldados cerca es un jugador y está vivo
		{if (isplayer _x && alive _x) exitwith {_isplayer = true;}}foreach _OCercanos;

		if (!_isplayer) then {
			deletevehicle _u;
			_deleted = true;
		};
		sleep _cicle;
	};
};
// ---------------------------------------------------------------------------------------------------------
//Función tomada de UPS, busca el comando en la lista y devuelve el siguiente elemento
//param1: comando a buscar
//param2: valor por defecto del comando
//param3: array con los comandos
//Retorna valor del comando encontrado o valor por defecto
MON_getArg = {private["_cmd","_arg","_list","_a","_v"]; _cmd=_this select 0; _arg=_this select 1; _list=_this select 2; _a=-1; {_a=_a+1; _v=format["%1",_list select _a];
if (_v==_cmd) then {_arg=(_list select _a+1)}} foreach _list; _arg};

// ---------------------------------------------------------------------------------------------------------
//Función que devuelve una posición en 3D a partir de otra, una dirección y una distancia
//param1: posición
//param2: dirección
//param3: distancia
//Retorna vector de posicion en 3D [0,0,0]
MON_GetPos = {
	private ["_pos","_dir","_dist","_cosU","_cosT","_relTX","_sinU","_sinT","_relTY","_newPos","_newPosX","_newPosY", "_targetZ" ];
	_pos = _this select 0;
	_dir = _this select 1;
	_dist = _this select 2;

			_targetX = _pos select 0; _targetY = _pos select 1; _targetZ = _pos select 2;

			//Calculamos posición
			_cosU = [_dir] call MON_GetCOS;		_sinU = [_dir] call MON_GetSIN;
			_cosT = abs cos(_dir);				_sinT = abs sin(_dir);
			_relTX = _sinT * _dist * _cosU;  	_relTY = _cosT * _dist * _sinU;
			_newPosX = _targetX + _relTX;		_newPosY = _targetY + _relTY;
			_newPos = [_newPosX,_newPosY,_targetZ];
			_newPos;
};

// ---------------------------------------------------------------------------------------------------------
//Función que devuelve una posición en 2D a partir de otra, una dirección y una distancia
//param1: posición
//param2: dirección
//param3: distancia
//Retorna vector de posicion en 2D [0,0]
MON_GetPos2D = {
	private ["_pos","_dir","_dist","_cosU","_cosT","_relTX","_sinU","_sinT","_relTY","_newPos","_newPosX","_newPosY" ];
	_pos = _this select 0;
	_dir = _this select 1;
	_dist = _this select 2;

			_targetX = _pos select 0; _targetY = _pos select 1;

			//Calculamos posición
			_cosU = [_dir] call MON_GetCOS;		_sinU = [_dir] call MON_GetSIN;
			_cosT = abs cos(_dir);				_sinT = abs sin(_dir);
			_relTX = _sinT * _dist * _cosU;  	_relTY = _cosT * _dist * _sinU;
			_newPosX = _targetX + _relTX;		_newPosY = _targetY + _relTY;
			_newPos = [_newPosX,_newPosY];
			_newPos;
};

// ---------------------------------------------------------------------------------------------------------
//Función que devuelve las posiciones que se pueden ocupar dentro de un edificio
//param1: objeto location
//Retorna numero de posiciones que tiene el edificio
MON_BldPos = {private ["_bld","_bldpos"];
					_bld=_this; _bldpos = 1;
					while {format ["%1", _bld buildingPos _bldpos] != "[0,0,0]"}  do {_bldpos = _bldpos + 1;};
				_bldpos = _bldpos - 1; _bldpos;};

// ---------------------------------------------------------------------------------------------------------
//Función que devuelve la casa que hay más cerca del objeto param1 y las posiciones que se pueden ocupar dentro de ella.
//param1: objeto
//Retorna vector con [objeto location, posiciones que tiene]
MON_PosInfo = {
	private["_obj","_bld","_bldpos"];
	_obj=_this;
	_bld = nearestbuilding _obj;
	_bldpos= _bld call MON_BldPos;
	[_bld,_bldpos];
	};

// ---------------------------------------------------------------------------------------------------------
//Función que devuelve el valor negativo o positivo del seno en base a un angulo
MON_GetSIN = {
	private["_dir","_sin","_cos"];
	_dir=_this select 0;
		if (_dir<90)  then {
			_sin=1;
		} else {
			if (_dir<180) then {
				_sin=-1;
			} else {
				if (_dir<270) then {
					_sin=-1;
				}
				else {
					_sin=1;
				};
			};
		};
	_sin
};

// ---------------------------------------------------------------------------------------------------------
//Función que devuelve el valor negativo o positivo del coseno en base a un angulo
MON_GetCOS = {
	private["_dir","_cos"];
	_dir=_this select 0;
		if (_dir<90)  then {
			_cos=1;
		} else {
			if (_dir<180) then {
				_cos=1;
			} else {
				if (_dir<270) then {
					_cos=-1;
				}
				else {
					_cos=-1;
				};
			};
		};
	_cos
};

//Función que busca vehiculos cercanos y hace entrar a las unidades del lider
MON_GetIn_NearestVehicles = {
	private["_vehicles","_npc","_units","_unitsIn","_grpid","_getin"];
	_grpid = _this select 0;
	_npc = _this select 1;

	_vehicles=[[]];
	_units = [];
	_unitsIn = [];
	_getin=false;

	if (leader _npc == _npc) then {
		_units = units _npc;
	} else {
		_units = _units + [_npc];
	};
 {
		if ( _x!= vehicle _x || !alive _x) then {_units = _units-[_x];};
	}foreach _units;

	_unitsIn = _units;

	if ( (count _units) > 0) then {
		_vehicles = [_npc,200] call MON_NearestsLandTransports;
		_units = [_grpid, _units, _vehicles, false] call MON_selectvehicles;
	};

	if ( (count _units) > 0 && {(count _vehicles) > 0}) then {
		sleep 1;
		_units = [_grpid, _units, _vehicles, true] call MON_selectvehicles;
	};

	if ( (count _units) < count _unitsin) then {_getin = true;} else {_getin = false;};
	_getin;
};


 MON_selectvehicles = {
	private["_vehicles","_emptypositions","_units","_unitsIn","_i","_grpid","_vehgrpid","_unit","_wp","_any","_index","_cargo"];
	_grpid = _this select 0;
	_units = _this select 1;
	_vehicles = _this select 2;
	_any = _this select 3;	//meter en cualquier vehiculo

	_wp = [];
	_vehicle = [];
	_unitsIn = [];
	_emptypositions = 0;
	_i = 0;
	_vehgrpid = 0;
	_unit = objnull;
	_index = 0;
	_cargo = [];

	//if (KRON_UPS_Debug>0) then {player sidechat format["%1 buscando transporte %2 units%3 any%4",_grpid, _vehicles, _units , _any]}; {
		if ((count _units) == 0 )  exitwith {};

		_vehicle = _x select 0 ;
		_emptypositions = _x select 1;
		_unitsIn = [];
		_i = 0;
		_vehgrpid = _vehicle getvariable ("UPSMON_grpid");
		_cargo = _vehicle getvariable ("UPSMON_cargo");
		if ( isNil("_vehgrpid") ) then {_vehgrpid = 0;};
		if ( isNil("_cargo") ) then {_cargo = [];};

		_emptypositions = _emptypositions - (count _cargo - count ( crew _vehicle) );

		//Asignamos el vehiculo a a la escuadra si contiene las posiciones justas
		if (_vehgrpid == 0 && _emptypositions > 0) then {
			_vehicle setVariable ["UPSMON_grpid", _grpid, false];
			_vehgrpid = _grpid;
		};

		//ahora buscamos en cualquier vehiculo
		if ( _vehgrpid == _grpid || (_emptypositions > 0 && _any)) then {

			while {_i < _emptypositions && _i < count _units} do {
				_unit = _units select _i;
				if ( _unit == vehicle _unit) then {
					_unitsIn = _unitsIn + [_unit];
				};
				_i = _i + 1;
			};
			_units = _units - _unitsIn;

			if ( (count _unitsIn) > 0) then {
				//Metemos las unidades en el vehiculo
				//if (KRON_UPS_Debug>0) then {player sidechat format["%1 entrando %2 unidades en %3 id %4, capacidad %5 cargo %6 crew %7" ,_grpid, count _unitsIn, typeof _vehicle,_vehgrpid, _emptypositions, count _cargo, count crew _vehicle ]};
				[_grpid,_unitsIn,_vehicle] spawn MON_UnitsGetIn;
			};
		};
		_index 	= _index  + 1;
	} foreach _vehicles;

	_units;
 };


//Funcion que mete la tropa en el vehiculo
MON_UnitsGetIn = {
		private["_grpid","_vehicle","_npc","_driver","_gunner", "_unitsin", "_units" , "_Commandercount","_Drivercount","_Gunnercount","_cargo",
				"_Cargocount","_emptypositions","_Commander","_vehgrpid","_cargo"];

		_grpid = _this select 0;
		_unitsin = _this select 1;
		_vehicle = _this select 2;

		_units = _unitsin;
		_driver = objnull;
		_gunner = objnull;
		_Commander	= objnull;
		_Cargocount = 0;
		_Gunnercount = 0;
		_Commandercount = 0;
		_Drivercount = 0;
		_cargo = [];

		_Cargocount = (_vehicle) emptyPositions "Cargo";
		_Gunnercount = (_vehicle) emptyPositions "Gunner";
		_Commandercount = (_vehicle) emptyPositions "Commander";
		_Drivercount = (_vehicle) emptyPositions "Driver";

		_emptypositions = _Cargocount + _Gunnercount + _Commandercount + _Drivercount;

		//Obtenemos el identificador del vehiculo
		_vehgrpid = _vehicle getvariable ("UPSMON_grpid");
		_cargo = _vehicle getvariable ("UPSMON_cargo");
		if ( isNil("_vehgrpid") ) then {_vehgrpid = 0;};
		if ( isNil("_cargo") ) then {_cargo = [];};


		{ //Hablitamos a la IA para entrar en el vehiculo
			unassignVehicle _x;
			_x spawn MON_Allowgetin;
		}foreach _units;
 {
			if ( _x == leader _x && _Cargocount > 0 ) then {
				_x assignAsCargo _vehicle;
				_units = _units - [_x];
				[_x] orderGetIn true;
			};
		}foreach _units;

		//Si el vehiculo pertenece al grupo asignamos posiciones de piloto, sinó solo de carga
		if ( _vehgrpid == _grpid ) then {
			//Asignamos el conductor
			if ( _Drivercount > 0 && count (_units) > 0 ) then {
				_driver =  _units  select 0;
				[_driver,_vehicle,20] spawn MON_assignasdriver;
				_units = _units - [_driver];
			};

			//Asignamos el artillero
			if ( _Gunnercount > 0 && count (_units) > 0 ) then {
				_gunner =  _units select 0;
				_gunner assignAsGunner _vehicle;
				_units = _units - [_gunner];
			};

			//Asignamos el comandante
			if ( _Commandercount > 0 && count (_units) > 0 ) then {
				_Commander =  _units select 0;
				_Commander assignAsCommander _vehicle;
				_units = _units - [_Commander];
			};

		};

		{ //Movemos el resto como carga
			_x assignAsCargo _vehicle;
			_units = _units - [_x];
		} forEach _units;

 {
			[_x,0] spawn MON_dostop;
			[_x] orderGetIn true;
		} forEach _unitsin - [_driver];

		_cargo = _cargo - _unitsin; //Para evitar duplicados
		_cargo = _cargo + _unitsin; //Añadimos a la carga
		_vehicle setVariable ["UPSMON_cargo", _cargo, false];
	};


//Función que devuelve un vehiculo de transporte cercano
MON_NearestLandTransport = {
		private["_vehicle","_npc","_transportSoldier","_OCercanos","_driver", "_Commandercount","_Drivercount","_Gunnercount","_Cargocount"];

		_npc = _this;

		_OCercanos = [];
		_transportSoldier = 0;
		_vehicle = objnull;
		_Cargocount = 0;
		_Gunnercount = 0;
		_Commandercount = 0;
		_Drivercount = 0;


		//Buscamos objetos cercanos
		_OCercanos = nearestObjects [_npc, ["Car","TANK","Truck","Motorcycle"] , 150];

		if (count _OCercanos == 0) exitwith {};
 {
			_Cargocount = (_x) emptyPositions "Cargo";
			_Gunnercount = (_x) emptyPositions "Gunner";
			_Commandercount = (_x) emptyPositions "Commander";
			_Drivercount = (_x) emptyPositions "Driver";

			_transportSoldier = _Cargocount + _Gunnercount + _Commandercount + _Drivercount;

			if (_transportSoldier >= count (units _npc)) exitwith {	_vehicle = _x;};
		}foreach _OCercanos;

		_vehicle;
	};

//Función que devuelve un array con los vehiculos más cercanos
MON_NearestsLandTransports = {
		private["_vehicles","_npc","_emptypositions","_OCercanos","_driver", "_Commandercount","_Drivercount","_Gunnercount","_Cargocount","_distance"];

	_npc = _this select 0;
	_distance = _this select 1;


		_OCercanos = [];
		_emptypositions = 0;
		_vehicles = [];
		_Cargocount = 0;
		_Gunnercount = 0;
		_Commandercount = 0;
		_Drivercount = 0;

		//Buscamos objetos cercanos
		_OCercanos = nearestObjects [_npc, ["Car","TANK","Truck","Motorcycle"] , _distance];

		if (count _OCercanos == 0) exitwith {};
 {
			_Cargocount = (_x) emptyPositions "Cargo";
			_Gunnercount = (_x) emptyPositions "Gunner";
			_Commandercount = (_x) emptyPositions "Commander";
			_Drivercount = (_x) emptyPositions "Driver";

			_emptypositions = _Cargocount + _Gunnercount + _Commandercount + _Drivercount;

			if (_emptypositions > 0) then { _vehicles = _vehicles + [[_x,_emptypositions]];};
		}foreach _OCercanos;

		_vehicles;
	};



//Función para retardar la toma del volante, así no se va el vehiculo y da tiempo a subir
MON_assignasdriver = {
	_driver =  _this  select 0;
	_vehicle = _this select 1;
	_wait = _this select 2;
	[_driver,_wait] spawn MON_dostop;
	_driver assignasdriver _vehicle;
	[_driver] orderGetIn true;
};

//Allow getin
MON_Allowgetin = {
	_unit =  _this;

	//Hablitamos a la IA para entrar en el vehiculo
	[_unit] allowGetIn true;
};



//Función que ordena al soldado salir si se encuentra en un vehiculo y a la distancia indicada
MON_GetOutDist = {
	private["_vehicle","_npc","_target","_atdist","_getout","_dogetout","_driver","_commander"];

	_npc = _this select 0;
	_target = _this select 1;
	_atdist = _this select 2;
	_getout = false;
	_dogetout = [];

	_vehicle = vehicle _npc;
	_gunner = gunner _vehicle;
	_driver = driver _vehicle;
	_commander = commander _vehicle;
	_dogetout = crew _vehicle;

	if ( _vehicle != _npc ) then {
		if ( (_vehicle distance _target) <= _atdist ) then {
			//Si hay artillero no sacarenos ni al piloto ni al artillero ni al comandante
			if ( !isnull _gunner && alive _gunner ) then {
				_dogetout = _dogetout - [_gunner] - [_driver] - [_commander];
			};

			if ( count _dogetout > 0 ) then {

				_getout	= true;
				//Paramos el vehiculo y esperamos 5 segundos
				[_vehicle,10] spawn MON_doStop;

				//Esperamos a que esté parado
				sleep 4;
 {
					_x spawn MON_GetOut;
				}foreach _dogetout;

				//Quitamos el id al vehiculo para que pueda ser reutilizado
				_vehicle setVariable ["UPSMON_grpid", 0, false];
				_vehicle setVariable ["UPSMON_cargo", [], false];

			};
		} else {
			//Chequeamos si el piloto está vivo
			if (isnull(driver _vehicle) || !alive(driver _vehicle)) then {
				_npc call MON_movetoDriver;
			};
		};
	};

	_getout;
};

//Función que ordena salir al soldado
MON_GetOut = {
		private["_vehicle","_npc","_getout" ,"_gunner"];

		_npc = _this;
		_vehicle = vehicle (_npc);
		_gunner = objnull;
		_gunner = gunner _vehicle;

		if (!alive _npc) exitwith{};

		//Si no hay artillero abandonamos el vehiculo
		if ( isnull _gunner || !alive _gunner || (_gunner != _npc && driver _vehicle != _npc && commander _vehicle != _npc) ) then {

			unassignVehicle _npc;
			_npc action ["getOut", _vehicle];
			doGetOut _npc;

			WaitUntil {vehicle _npc==_npc || !alive _npc};

			[_npc] allowGetIn false;
			unassignVehicle _npc;

		};
	};

//Función que detiene al soldado y lo hace esperar x segundos
MON_doStop = {
	private["_sleep","_npc"];

	_npc = _this select 0;
	_sleep = _this select 1;

	if (!alive _npc) exitwith{};

	//Restauramos valores por defecto de movimiento
	_npc disableAI "TARGET";
	_npc disableAI "MOVE";
	sleep 0.1;
	_npc enableAI "TARGET";
	sleep 0.1;
	_npc enableAI "AUTOTARGET";
	sleep _sleep;
	_npc enableAI "MOVE";
	sleep 2;
};

//Realiza la animación de esquivar granada
MON_evadeGrenade = {
	if (!alive _this || (vehicle _this) != _this) exitwith{};

	_this playmovenow "AmovPercMstpSlowWrflDnon_ActsPpneMstpSlowWrflDr_GrenadeEscape";
	sleep 8;
	_this switchmove "AmovPpneMstpSrasWrflDnon_AmovPpneMevaSlowWrflDr"; //croqueta
	_this playmovenow "AmovPpneMstpSrasWrflDnon"; //prone
};

//Realiza la animación de la croqueta
MON_animCroqueta = {
	if (!alive _this || (vehicle _this) != _this) exitwith{};

	if ((random 1)<=.50) then {
		_x switchmove "AmovPpneMstpSrasWrflDnon_AmovPpneMevaSlowWrflDl"; //croqueta
	} else {
		_x switchmove "AmovPpneMstpSrasWrflDnon_AmovPpneMevaSlowWrflDr"; //croqueta
	};
};

//Lanza una granada
MON_throw_grenade = {
	private["_target","_npc"];
	_npc = _this select 0;
	_target = _this select 1;

	if (!alive _npc || (vehicle _npc) != _npc) exitwith{};
	_npc addMagazine "SmokeShell";
	[_npc,_target] spawn MON_dowatch;

	_npc selectWeapon "throw";
	sleep .1;
	_npc fire ["SmokeShellMuzzle","SmokeShellMuzzle","SmokeShell"];
	sleep 4;
};

//Establece el tipo de posición
MON_setUnitPos = {
	private["_pos","_npc"];
	_npc = _this select 0;
	_pos = _this select 1;

	if (!alive _npc) exitwith{};
	_npc setUnitPos _pos;
	sleep 1;
};
//Establece el tipo de posición
MON_setUnitPosTime = {
	private["_pos","_npc"];
	_npc = _this select 0;
	_pos = _this select 1;
	_time = _this select 2;

	if (!alive _npc) exitwith{};
	_npc setUnitPos _pos;
	sleep _time;
	_npc setUnitPos "AUTO";
	sleep 1;
};

// Función para  mirar en una dirección
MON_dowatch = {
	private["_target","_npc"];
	_npc = _this select 0;
	_target = _this select 1;

	if (!alive _npc) exitwith{};
	_npc dotarget _target;
	_npc dowatch _target;
	sleep 1;
};

//Función que mueve al soldado a la posición de conductor
MON_movetoDriver = {
	private["_vehicle","_npc"];
	_npc = _this ;
	_vehicle = vehicle _npc;

	if (!alive _npc || _vehicle == _npc ) exitwith{};

	if (isnull(driver _vehicle) || !alive(driver _vehicle)) then {
		//if (KRON_UPS_Debug>0) then {player sidechat format["%1: Tomando el volante de %2 ",_npc,typeof _vehicle]};
		_npc action ["getOut", _vehicle];
		doGetOut _npc;
		WaitUntil {vehicle _npc==_npc || !alive _npc};
		unassignVehicle _npc;
		_npc assignasdriver _vehicle;
		_npc moveindriver _vehicle;
	};
};

//Función que retorna array de arrays con edificios y sus plantas
//Parámeters: [_object,(_distance,_minfloors)]
//	<-	_object: soldier to get near buildings
//	<-	_distance: distance to search buildings (optional, 25 by default)
//	<- 	_minfloors:  min floors of building (optional) if not especified  min floors is 2
// 	->	 [_bld,_bldpos]

MON_GetNearestBuildings = {
	private ["_object","_altura","_pos","_bld","_bldpos","_posinfo","_minfloors","_OCercanos","_distance","_blds"];
	_distance = 25;
	_minfloors = 2;
	_altura = 0;
	_blds = [];

	_object = _this select 0;
	if ((count _this) > 1) then {_distance = _this select 1;};
	if ((count _this) > 2) then {_minfloors = _this select 2;};

	_pos =0;
	_bld = objnull;
	_bldpos =0;
	_posinfo=[];

	//La altura mínima es 2 porque hay muchos edificios q devuelven 2 de altura pero no se puede entrar en ellos.
	if ( minfloors == 0  ) then {
		minfloors = 2;
	};

	// _posinfo: [0,0]=no house near, [obj,0]=house near, but no roof positions, [obj,pos]=house near, with roof pos
	//_posinfo= _object call MON_PosInfo;
	_OCercanos = nearestObjects [_object, ["house","building"] , _distance];
 {
		_bldpos = _x call MON_BldPos;
		if ( _bldpos >= _minfloors ) then { _blds = _blds + [[_x,_bldpos]];};
		//player sidechat format["%1 cerca de edificio con %2 plantas %5",typeof _object,_bldpos];
	}foreach _OCercanos;

	_blds;
};

//Función para mover a una unidad al edificio más cercano
//Parámeters: [_object,(_patrol,_minfloors)]
//	<-	 _object: soldier to move
// 	<- 	_patrol: true if want to patrol entire building
//	<-	 _distance: distance to search buildings (optional, 25 by default)
MON_moveNearestBuilding = {
	private ["_object","_altura","_pos","_bld","_bldpos","_posinfo","_minfloors","_OCercanos","_distance","_patrol"];
	_distance = 25;
	_minfloors = 2;
	_altura = 0;
	_patrol = false;

	_object = _this select 0;
	if ((count _this) > 1) then {_patrol = _this select 1;};
	if ((count _this) > 2) then {_distance = _this select 2;};
	if ((count _this) > 3) then {_minfloors = _this select 3;};

	_pos =0;
	_bld = objnull;
	_bldpos =0;
	_posinfo=[];

	//La altura mínima es 2 porque hay muchos edificios q devuelven 2 de altura pero no se puede entrar en ellos.
	if ( minfloors == 0  ) then {
		minfloors = 2;
	};

	// _posinfo: [0,0]=no house near, [obj,0]=house near, but no roof positions, [obj,pos]=house near, with roof pos
	//_posinfo= _object call MON_PosInfo;
	_OCercanos = nearestObjects [_object, ["house","building"] , _distance];
 {
		_bldpos = _x call MON_BldPos;
		if ( _bldpos >= _minfloors ) exitwith { _bld = _x;};
	}foreach _OCercanos;


	if (isnull(_bld)) exitwith {};

	if (!isnull(_bld) && _bldpos >= _minfloors ) then {
		// move the unit on top of a building
		if ( _patrol ) then {
			[_object,_bld,_bldpos] spawn MON_patrolBuilding;
		} else {
			_altura = if ( _altura > _bldpos ) then {_bldpos} else {_altura};

			if ( _altura == 0  ) then {
				_altura = random(_bldpos);
			};

			_object domove (_bld buildingPos _altura);
			player sidechat format["%1 entrando en %2 posiciones=%3",typeof _object, typeof _bld, _bldpos];
		};

	};
};

//Función para mover a una unidad al edificio más cercano
//Parámeters: [_npc,_bld,(_BldPos)]
//	<-	 _npc: soldier to move
// 	<-	 _bld:building to patrol
//	<-	 _BldPos: positions of builiding (optional)
MON_patrolBuilding = {
	private ["_npc","_bld","_bldpos","_posinfo","_minfloors","_OCercanos","_distance","_timeout","_pos","_inbuilding","_rnd","_NearestEnemy","_patrolto","_time"];
	_bldpos = 0;
	_pos = 0;
	_timeout = 0;
	_i = 1;
	_inbuilding = false;
	_rnd = 0;
	_patrolto = 0;
	_NearestEnemy = objnull;
	_time = 0;

	_npc = _this select 0;
	_bld = _this select 1;
	if ((count _this) > 2) then {_bldpos = _this select 2;} else {_bldpos = _x call MON_BldPos;};

	if (_i > _bldpos) then {_i = _bldpos};
	_patrolto = round ( 10 + random (_bldpos) );

	if (_patrolto > _bldpos) then {_patrolto = _bldpos};

	//Si ya está en un edificio ignoramos la orden
	_inbuilding = _npc getvariable ("UPSMON_inbuilding");
	if ( isNil("_inbuilding") ) then {_inbuilding = false;};

	//Asignamos el vehiculo a a la escuadra si contiene las posiciones justas
	if (!_inbuilding) then {
		_inbuilding	 = true;
		_npc setVariable ["UPSMON_inbuilding", _inbuilding, false];
		[_npc,"Middle"] spawn MON_setUnitPos;
		_timeout = time + 60;

		while { _i <= _patrolto && alive _npc} do{

			_npc domove (_bld buildingPos _i);

			//player sidechat format["%1 patrullando en %2 %3 hasta %4",_npc, typeof _bld,_i, _patrolto];

			_time = time + 30;

			waitUntil {moveToCompleted _npc or moveToFailed _npc or !alive _npc or _time < time};

			if (moveToCompleted _npc) then {
				_timeout = time + 60;
				_i = _i + 1;
			} else {
				if (moveToFailed _npc  || !alive _npc || _timeout < time) then {
					//player sidechat format["%1 Cancelando patrulla en %2",_npc, typeof _bld];
					_i = _patrolto + 1;
				};
			};

			_npc dofire _NearestEnemy;
			sleep 0.05;
		};
		//Volvemos con el lider
		_npc domove	(position leader _npc);

		//Marcamos que ya hemos finalizado
		sleep 120; //Damos tiempo para salir del edificio
		_npc setVariable ["UPSMON_inbuilding", false, false];
	};
};
/*
if(dll_tow_velocity_impl) then {
					//velocity implementation (smoother but elastic)
					_dirdeg_axis = _dx_axis atan2 _dy_axis;	//get the direction of the difference vector
					_speed = _d_axis*8; //control the speed needed to make this distance smaller TWEAK HERE	Higher value means less elasticty, but more choppy.
					_speed = _speed min 50; //set max speed for safety.
					_Pvel = velocity _P;
					_P setVelocity [(sin _dirdeg_axis*_speed),(cos _dirdeg_axis*_speed),(_Pvel select 2)-0.3]; //set the velocity in the correct direction
				}
*/