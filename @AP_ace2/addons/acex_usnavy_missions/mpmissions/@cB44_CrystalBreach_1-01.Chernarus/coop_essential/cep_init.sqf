// _________________________________________________________________________________________________________________
// | Coop Essential Pack by -eutf-Myke                                                                             |
// |_______________________________________________________________________________________________________________|
// | Do not change this scrip!                                                                                     |
// |_______________________________________________________________________________________________________________|
// | cep initialization script                                                                                     |
// | nul =[WEST, [EAST], [Resistance, Civilian], [units, objects], editor mode] exec "coop_essential\cep_init.sqf" |
// | Friendsarray and remover array are optional                                                                   |
// |_______________________________________________________________________________________________________________|

if (! isServer) exitwith {};
cep_init_done = false;
cep_friendarray = [];

cep_playerside = _this select 0;
cep_enemyarray = _this select 1;
cep_fcache = compile preprocessfile "coop_essential\cep_cache_units.sqf";
cep_cached_grps = [];
cep_init_done = true;