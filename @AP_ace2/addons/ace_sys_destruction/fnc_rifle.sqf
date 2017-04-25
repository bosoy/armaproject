if (isDedicated) exitWith {};

private ["_type","_cnv","_cal","_mass","_cv","_sh","_p","_tr1","_tr2","_vec","_i","_int"];

_type = _this select 4;
_sh = _this select 6; // Uses Extended_FiredBIS
_p = getpos _sh;
_vec = vectordir _sh;

// zGuba: Decrease visible smoke on own weapon, especially in NV mode.

switch (currentVisionMode player) do {
	case 1: {
		if (cameraOn == _this select 0) then {
			switch (cameraView) do {
				case "GUNNER": {_cnv = 0.25};
				default {_cnv = 0.5};
			};
		} else {
			_cnv = 0.5
		};
	};
	default {_cnv = 1};
};

// zGuba: corelation between round size and amount of smoke. B_762x51_Ball as ref.
_cal = getNumber (configFile >> "CfgAmmo" >> _type >> "ace_caliber") / 7.62;
_mass = getNumber (configFile >> "CfgAmmo" >> _type >> "ace_mass") / 0.972;

// zGuba: Apply only if sys_wounds is present.
_cv = if (_cal > 0 && {_mass > 0}) then { _cnv * sqrt(sqrt(_cal) * sqrt(_mass)) } else { _cnv };

_int = ((speed _sh)/3240) * (0.7 + random 0.6) * _cv;
_life = _int * (0.5 + random 0.2);

if (_life == 0) exitWith {};
if (getNumber(configfile>>"cfgweapons">>(_this select 1)>>"ace_suppressed")==1) then {
	_int = (0.7 * _int) min 0.2;
	_life = _int * (0.5 + random 0.2);
	drop [["\ca\Data\ParticleEffects\Universal\Universal",16,12,8],
	"", "Billboard", 1, _life, [0,-0.05,0], [(1 + random 0.3),0,0], 0, 0.104, 0.08,
	0.2,[0.1*_cv,0.2*_cv,0.3*_cv,0.4*_cv], [[0.9, 0.9, 0.9, (0.1 + random 0.07)*_cv],[1, 1, 1, 0]],
	[1/_life], 1, 0, "", "", _sh,random 360];
};

drop [["\ca\Data\ParticleEffects\Universal\Universal",16,12,8],
	"", "Billboard", 1, _life, [0,0.4,0], [0, (2 + random 1.5)*_int, 0], 0, 0.104, 0.08,
	0.2,[0.1*_cv, 1*_int,1.6*_int,_int*2], [[0.9, 0.9, 0.9, (0.1 + random 0.07)*_cv],[1, 1, 1, 0]],
	[1/_life], 1, 0, "", "", _sh,random 360];

if (_int > 1) then {_int = 1};
if ((abs(_p select 2) < _int) && {!(surfaceiswater _p)}) then {
	_tr1 = (_int - abs(_p select 2)) / 1.3;

	drop [["\ca\Data\ParticleEffects\Universal\Universal.p3d", 16, 12, 13, 0], "", "Billboard", 1, 0.9 + random 0.3,
	[(_p select 0)+0.5*(_vec select 0), (_p select 1)+0.5*(_vec select 1), 0.07], [((_vec select 0) -0.4 +(random 0.8))*1.3, ((_vec select 1) -0.4 +(random 0.8))*1.3, 0], 0,
	0.104, 0.08, 0.2, [(0.2 + random 0.2)*_int,(1.3 +random 0.6)*_int],[[0.6, 0.5, 0.4, _tr1],[0.6, 0.5, 0.4, 0]],
	[1000], 1, 0, "", "", ""];
}