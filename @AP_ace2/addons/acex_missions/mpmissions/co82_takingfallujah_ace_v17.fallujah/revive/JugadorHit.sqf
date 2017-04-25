JugadorHit=
{
	Private['_jugador','_causante','_dano'];
	_jugador=_this select 0;
	_causante=_this select 1;
	_dano=_this select 2;
	if ((!isplayer _causante)||(!local _jugador)) exitwith{};
	_jugador setvariable ['UltAtack', [time,_causante]];
};


JugadorComprobarTK=
{
	Private['_datos','_causante','_tiempo'];
	
	_datos= player getVariable 'UltAtack';
	if (!isnil "_datos") then {
		_tiempo=_datos select 0;
		_causante=_datos select 1;
		if ((time -_tiempo ) < 10) then
		{
			//Fue hace poco asique se supone que el lo mato , cabronazo xD.
			if (_causante != player) then
			{
				if ((side _causante ) == playerSide) then {
					10 cutText [format["You where killed by %1. FRIENDLY FIRE",name _causante],"PLAIN",2];
					_causante;
				};
			}else {
				10 cutText ["You committed suicide","PLAIN",2];
			};
		};
	};
};

Player addEventHandler ['Hit', {_this spawn JugadorHit}];