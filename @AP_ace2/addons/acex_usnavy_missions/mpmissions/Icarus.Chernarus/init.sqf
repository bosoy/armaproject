execVM "briefing.sqf"

////////////////////////////////////////////////////////////////////////////////
// Environment
////////////////////////////////////////////////////////////////////////////////
//enableenvironment false;
if (viewdistance < 3500) then {setviewdistance 3500};
setwind [0.201112,0.204166,true];
0 setovercast 0.7;

"colorCorrections" ppEffectAdjust [2, 30, 0, [0.0, 0.0, 0.0, 0.0], [0.8*2, 0.5*2, 0.0, 0.7], [0.9, 0.9, 0.9, 0.0]];
"colorCorrections" ppEffectCommit 0;
//"colorCorrections" ppEffectAdjust [1, 1, 0, [0.0, 0.0, 0.0, 0.0], [0.8*2, 0.5*2, 0.0, 0.7], [0.9, 0.9, 0.9, 0.0]];
"colorCorrections" ppEffectAdjust [1, 0.8, -0.001, [0.0, 0.0, 0.0, 0.0], [0.8*2, 0.5*2, 0.0, 0.7], [0.9, 0.9, 0.9, 0.0]];
"colorCorrections" ppEffectCommit 3;
"colorCorrections" ppEffectEnable true;
"filmGrain" ppEffectEnable true;
"filmGrain" ppEffectAdjust [0.02, 1, 1, 0.1, 1, false];
"filmGrain" ppEffectCommit 5;

//--- Jukebox
jukebox = {
   20 fademusic 0;
   sleep 20;
   if (brown distance rah1 < 200) then {savegame};

   _tracklist = ["Fallout","Defcon","Wasteland","SkyNet"];
   _tracklistduration = [207,193,194,233];
   _song = "";
   while {alive brown} do {
      jukebox_reset = false;
      waituntil {!cutscene};
      _tracklistTemp = _tracklist - [_song];
      _song = _tracklistTemp call bis_fnc_selectrandom;
      _delay = _tracklistduration select (_tracklist find _song);
      playmusic _song;
      5 fademusic 0.2;
         debuglog ["Log:::::::::::::::::MUSIC",_song,_delay];
      //sleep _delay;
      _cutscene = cutscene;
      _timeNow = time;
      waituntil {
         sleep 1;
         (time - _timeNow) > _delay || str _cutscene != str cutscene || jukebox_reset
      };
   };
};

//--- Ash
[] spawn {
   waituntil {isplayer brown};
   _pos = position player;
   _parray = [
   /* 00 */      ["\Ca\Data\ParticleEffects\Universal\Universal", 16, 12, 8, 1],//"\Ca\Data\cl_water",
   /* 01 */      "",
   /* 02 */      "Billboard",
   /* 03 */      1,
   /* 04 */      4,
   /* 05 */      [0,0,0],
   /* 06 */      [0,0,0],
   /* 07 */      1,
   /* 08 */      0.000001,
   /* 09 */      0,
   /* 10 */      1.4,
   /* 11 */      [0.05,0.05],
   /* 12 */      [[0.1,0.1,0.1,1]],
   /* 13 */      [0,1],
   /* 14 */      0.2,
   /* 15 */      1.2,
   /* 16 */      "",
   /* 17 */      "",
   /* 18 */      vehicle player
   ];
   _snow = "#particlesource" createVehicleLocal _pos;
   _snow setParticleParams _parray;
   _snow setParticleRandom [0, [10, 10, 7], [0, 0, 0], 0, 0.01, [0, 0, 0, 0.1], 0, 0];
   _snow setParticleCircle [0.0, [0, 0, 0]];
   _snow setDropInterval 0.01;

   _oldPlayer = vehicle player;
   while {true} do {
      waituntil {vehicle player != _oldPlayer};
      _parray set [18,vehicle player];
      _snow setParticleParams _parray;
      _oldPlayer = vehicle player;
   };
};