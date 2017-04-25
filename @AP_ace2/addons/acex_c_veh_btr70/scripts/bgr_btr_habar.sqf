/*
Created by Vadim Shchemelinin aka badger
2010 St.Petersburg

Script for BTR-70 by RHS

_habarScr = [this,type,setting,config] execVM "bgr_btr_habar.sqf";
type = 0  -  all off
type = 1  -  all on
type = 2  -  random
type = 3  -  castom
*/

private ["_btr","_type","_setting","_config","_str"];

if (!isServer) exitWith {};
//_tochka animate ["USSR_SS21_luk_levy",1];
//_tochka setVariable ["lanchStatus", 3, true];
_btr = _this select 0;
_type = if (count _this > 1) then {_this select 1} else {2};
_setting = if ((count _this > 2)and(_type == 3)) then {_this select 2} else {[]};
_config = if (((count _this > 3)and(_type == 3))or((count _this > 2)and(_type != 3))) then {_this select 3} else {false};

if (_config) then { //????? ?????????? ??????? ????? ????????? ?? ???????? ?? ???????????? ???? ?????????
   if (!isnil (_btr getVariable "habar_set")) exitWith{}; //??????? ???? ???????????? ??? ????????? ????? ????
};

switch (_type) do {
   case 0: {   //??? ????
      _setting = [1,1,1,1,1,1,1,1,1,1,"none"];
   };
   case 1: {   //??? ???
/*      if ((random 10) > 5) then { both
         _str = "front";
      } else {
         if ((random 10) > 5) then {
            _str = "back";
         }else{
            _str = "both";
         };
      };
      */
      _setting = [0,0,0,0,0,0,0,0,0,0,"both"];
   };
   case 3: {   //???????????????? ?????????
      if (count _setting < 11) then {   //???????? ?? "?????? ??????"
         _setting = [1,1,1,1,1,1,1,1,1,1,"none"];
      };
      _setting = [(1-(_setting select 0)),
               (1-(_setting select 1)),
               (1-(_setting select 2)),
               (1-(_setting select 3)),
               (1-(_setting select 4)),
               (1-(_setting select 5)),
               (1-(_setting select 6)),
               (1-(_setting select 7)),
               (1-(_setting select 8)),
               (1-(_setting select 9)),
               _setting select 10];
   };
   default {   //??????
      _r = (random 10);
      _str = "both";
      if (_r < 7.5) then {_str = "back";};
      if (_r < 5) then {_str = "front";};
      if (_r < 2.5) then {_str = "none";};
      _setting = [(floor (random 2)),
               (floor (random 2)),
               (floor (random 2)),
               (floor (random 2)),
               (floor (random 2)),
               (floor (random 2)),
               (floor (random 2)),
               (floor (random 2)),
               (floor (random 2)),
               (floor (random 2)),
               _str];
   };
};
_btr setVariable ["habar_set", _setting, true];
_btr animate ["crate_l1_unhide",(_setting select 0)];
_btr animate ["crate_l2_unhide",(_setting select 1)];
_btr animate ["crate_l3_unhide",(_setting select 2)];
_btr animate ["crate_l4_unhide",(_setting select 3)];
_btr animate ["crate_r1_unhide",(_setting select 4)];
_btr animate ["crate_r2_unhide",(_setting select 5)];
_btr animate ["crate_r3_unhide",(_setting select 6)];
_btr animate ["crate_r4_unhide",(_setting select 7)];
_btr animate ["water_1_unhide",(_setting select 8)];
_btr animate ["water_2_unhide",(_setting select 9)];
switch (_setting select 10) do {
   case "front": {
      _btr animate ["wheel_1_unhide",0];
      _btr animate ["wheel_2_unhide",1];
   };
   case "back": {
      _btr animate ["wheel_1_unhide",1];
      _btr animate ["wheel_2_unhide",0];
   };
   case "both": {
      _btr animate ["wheel_1_unhide",0];
      _btr animate ["wheel_2_unhide",0];
   };
   default {
      _btr animate ["wheel_1_unhide",1];
      _btr animate ["wheel_2_unhide",1];
   };
};