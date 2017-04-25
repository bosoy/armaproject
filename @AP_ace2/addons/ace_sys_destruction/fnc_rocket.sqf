if (isDedicated) exitWith {};

private ["_sh","_p","_tr1","_tr2","_vec","_col","_i","_no","_u","_pp","_y","_z"];
_u = _this select 0;
_sh = _this select 6; // Uses Extended_FiredBIS
_p = getpos _sh;

_col = [[0.7,0.7,0.7,0],[0.7,0.7,0.7,0.8],[0.7,0.7,0.7,0.6],[0.8,0.8,0.8,0.4],[0.9,0.9,0.9,0.2], [1,1,1,0]];
_no = 6 + random 3;

if (_u isKindOf "CAManBase") then {
	_pp = _u selectionposition "righthand";
	_p = _u modeltoworld _pp;
	_z = (vectordir _sh) select 2;
	_y = sqrt(1-_z^2);
	drop [["\ca\Data\ParticleEffects\Universal\Universal",16,2,32], "", "Billboard", 1,(0.1 + random 0.1),
	[_pp select 0,(_pp select 1)-1.3*_y,(_pp select 2)-1.3*_z],
	[0, -2*_y, -2*_z], 0, 10, 7.9, 0.075, [1,3],
	[[1, 1, 1, -2], [1, 1, 1, -2],
	[1, 1, 1, -1], [1, 0.5, 1, -0]],
	[5], 1, 0, "", "", _u];
	for "_i" from 1 to _no - 1 do {
		drop [["\ca\Data\ParticleEffects\Universal\Universal", 16, 7, 48], "", "Billboard", 1, 2.5, [_pp select 0,(_pp select 1)-1.3,_pp select 2],
			[-0.5+random 1,-1.5*_i + random 1,-0.5+random 1], 1, 1, 0.80, 0.4, [1,(2.3*_i)+random 0.5],_col,[2,0.7,0.5],0.1,0.1,"","",_u];
	};

} else {
	drop [["\ca\Data\ParticleEffects\Universal\Universal",16,2,32], "", "Billboard", 1,(0.1 + random 0.1),
	[0, -1.3,0],
	[0, -2, 0], 0, 10, 7.9, 0.075, [1,3],
	[[1, 1, 1, -2], [1, 1, 1, -2],
	[1, 1, 1, -1], [1, 0.5, 1, -0]],
	[5], 1, 0, "", "", _sh];
	for "_i" from 1 to _no - 1 do {
		drop [["\ca\Data\ParticleEffects\Universal\Universal", 16, 7, 48], "", "Billboard", 1, 2.5, [0, - 1.3, 0],
			[-0.5+random 1,-1.5*_i + random 1,-0.5+random 1], 1, 1, 0.80, 0.4, [1,(2.3*_i)+random 0.5],_col,[2,0.7,0.5],0.1,0.1,"","",_sh];
	};
};

if ((abs(_p select 2) < 2) && {!(surfaceiswater _p)}) then {
	_vec = vectordir _sh;
	_no = 20 + random 7;
	for "_i" from 0 to _no - 1 do {
		drop [["\ca\Data\ParticleEffects\Universal\Universal.p3d", 16, 12, 13, 0], "", "Billboard", 1, 7,
			[_p select 0, _p select 1, 0], [-((_vec select 0) -0.5 +(random 1))*4,
			-((_vec select 1) -0.5 +(random 1))*4, 0.3 + random 0.3],
			0, 0.104, 0.08, 0.04, [2,4], [[0.6, 0.5, 0.4, 0],[0.6, 0.5, 0.4, 0.4], [0.6, 0.5, 0.4, 0.2],
			[0.6, 0.5, 0.4, 0]], [1000], 1, 0, "", "", ""];
	};
};
