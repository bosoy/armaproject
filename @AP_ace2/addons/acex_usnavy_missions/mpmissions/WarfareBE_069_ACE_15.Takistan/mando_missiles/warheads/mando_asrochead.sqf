// mando missile ASROC head
// mando_asrochead.sqf
// Oct 2007 Mandoble
// 


private ["_pos", "_target", "_launcher", "_drop1", "_drop2", "_debris", "_maxspd", "_mass", "_vol", "_rubb", "_size", "_numdrops", "_i", "_angh", "_angv", "_rad", "_radv", "_radh", "_vel", "_size1", "_size2", "_pos2", "_b2", "_b1", "_dmgtarget", "_score", "_cost", "_side", "_unit", "_crew"];

_pos = _this select 0;
_target = _this select 1;
_side = _this select 2;
_launcher = _this select 3;


drop ["\Ca\Data\ParticleEffects\RocketSmoke\RocketSmoke", "", "Billboard", 1, 3, _pos, [0,0,0], 0.5, 1.275 + 0.3,  1.0, 0.5, [2,4,6], [[1,1,1,0.2],[1,1,1,1],[1,1,1,1],[0.5,0.5,0.5,0]], [0,1,0], 5, 0.05, "", "", ""];

asroc_target = _target;