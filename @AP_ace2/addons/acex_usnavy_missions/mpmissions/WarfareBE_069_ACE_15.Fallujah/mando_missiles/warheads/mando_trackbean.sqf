// mando missile warhead type 1
// mando_missilehead1a.sqf v1.0
// Jan 2007 Mandoble
// 
// General explosion script for mando missiles
// This script may be used as explosion script argument for mando_missile.sqf
// 
// Big smoke and falling smoke debris
// Medium power explosion (equivalent to M_Ch29_AT missile).

private ["_pos", "_target", "_targets", "_classtarget", "_rating", "_crewt", "_launcher", "_drop1", "_drop2", "_debris", "_maxspd", "_mass", "_vol", "_rubb", "_size", "_numdrops", "_i", "_angh", "_angv", "_rad", "_radv", "_radh", "_vel", "_size1", "_size2", "_pos2", "_b2", "_b1", "_dmgtarget", "_score", "_cost", "_side", "_unit", "_crew"];

_pos = _this select 0;
_target = _this select 1;
_side = _this select 2;
_launcher = _this select 3;

if ((_pos distance _target) < 80) then
{
   drop ["\ca\data\koulesvetlo","","Billboard",100,1,[0,0,0],[0,0,0],0,1.27,1,0.05,[0.9,20,30,20,0.9],[[1,0,1,0],[1,0,1,0.7],[1,0,1,0]],[0],0,0,"","",_target];
};

if ((local _launcher) && ((_pos distance _target) < 80)) then
{
   if (alive _launcher) then
   {
      _vup = vectorUp _target;
      _pos = _launcher worldToModel (getPos _target);
      _target setFuel 0;
            
      _target attachTo [_launcher,_pos]; 
//      _target setVectorUp _vup;

      _pos_ini = _launcher worldToModel (getPos _target);
      _centered = false;
      _target setVehicleInit "(driver this) action ['eject', this]";
      processInitCommands ;
      
      while {(alive _target) && (alive _launcher) && !_centered} do
      {
         _pos = _launcher worldToModel (getPos _target);
         _ok = 0;
         if (abs(_pos select 0) > 2) then
         {
            _sign = -(_pos select 0)/abs(_pos select 0);
            _delta = ((abs(_pos select 0)*.05) max 1)*_sign;
            _pos set[0, (_pos select 0) + _delta];
         }
         else
         {
            _ok = _ok + 1;
         };       

         if (abs(_pos select 1) > 100) then
         {
            _sign = -(_pos select 1)/abs(_pos select 1);
            _delta = ((abs(_pos select 1)*.05) max 1)*_sign;
            _pos set[1, (_pos select 1) + _delta];
         }
         else
         {
            _ok = _ok + 1;
         };       

         if (abs(_pos select 2) > 2) then
         {
            _sign = -(_pos select 2)/abs(_pos select 2);
            _delta = ((abs(_pos select 2)*.05) max 1)*_sign;
            _pos set[2, (_pos select 2) + _delta];
         }
         else
         {
            _ok = _ok + 1;
         };       

         if (_ok == 3) then
         {
            _centered = true;
         };
         _target attachTo [_launcher,_pos];
//         _target setVectorUp _vup;
         sleep 0.1;
      };

      while {(alive _target) && (alive _launcher) && ((getPos _target select 2) > 2)} do
      {
         sleep 1;
      };
      detach _target;
   };
};