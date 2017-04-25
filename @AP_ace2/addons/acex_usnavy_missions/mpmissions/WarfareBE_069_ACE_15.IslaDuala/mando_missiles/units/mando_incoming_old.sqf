/* 
 mando ArmA missile defense system
 mando_incoming.sqf v1.1
 Apr 2007 Mandoble

 This is automatically executed by mando_missileecm.sqf
*/
private ["_target", "_type", "_firer", "_missile", "_vel", "_dir", "_up"];
_target = _this select 0;
_type = _this select 1;
_firer = _this select 2;

//mando_message = format["%1, Incomming event handler, firing unit %2",name player, _firer];

if (local _firer) then
{
   _missile = nearestObject [_firer, _type];

   if (!isNull _missile) then
   {
//      mando_message = format["%1, %2 incomming to %3",name player, _missile, _target];

      mando_missileincomming = _missile;
      mando_missiletarget = _target;
      mando_missilerequest = true;
      {publicVariable _x} forEach ["mando_missileincomming","mando_missiletarget","mando_missilerequest"];

      while {!isNull _missile} do
      {
         if ((mando_missilechafflauncher == _target) && (!isNull mando_missilechaff)) then
         {
            _dir = vectorDir _missile;
            _up = vectorUp _missile;
            _vel = [(_dir select 0)*400, (_dir select 1)*400, (_dir select 2)*400];
            while {(!isNull _missile)&&(!isNull mando_missilechaff)} do
            {
               _missile setvectorDir _dir;
               _missile setvectorUp _up;
               _missile setVelocity _vel;
               Sleep 0.005;
            };

         };
         Sleep 0.005;
      };
   };
};