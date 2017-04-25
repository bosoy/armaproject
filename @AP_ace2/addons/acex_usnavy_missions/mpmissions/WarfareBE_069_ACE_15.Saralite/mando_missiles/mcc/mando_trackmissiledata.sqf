/* mando Missile track missile data
mando_trackmissiledata.sqf
July 2007 mandoble

Missile Control Center low/center panel showing current missile data
*/

private["_mode", "_follow1", "_follow2", "_follow3", "_velocity", "_speed", "_engine1", "_engine2"];

MCC_MCC_FRAME		=21901;
MCC_MODE 		=21926;
MCC_FOLLOW1		=21927;
MCC_FOLLOW2		=21928;
MCC_FOLLOW3		=21929;
MCC_DISTANCEM		=21930;
MCC_SPEEDM		=21931;
MCC_ALTITUDEM		=21932;
MCC_ENGINEON		=21933;
MCC_ENGINEOFF		=21934;
MCC_ENDURANCEM		=21935;
MCC_GROUNDNO		=21936;
MCC_GROUNDYES		=21937;



while {ctrlVisible MCC_MCC_FRAME} do
{
   waitUntil {!(isNull mando_missile) || !(ctrlVisible MCC_MCC_FRAME)};
   
   Sleep 0.25;

   while {(!isNull mando_missile) && (ctrlVisible MCC_MCC_FRAME)} do
   {
      switch (mando_missile_mode) do
      {
         case 0:
         {
            _mode = "Inertial mode 0";

         };
         
         case 1:
         {
            _mode = "Inertial mode 1";
         };

         case 2:
         {
            _mode = "Active";

         };
      };


      _follow1 = "Radar OFF";
      _follow2 = "";
      _follow3 = "";

      if ((mando_missile_mode == 2) && mando_missile_follow) then
      {
         _follow1 = "";
         _follow2 = "Tracking target";
         _follow3 = "";
      };


      if ((mando_missile_mode == 2) && !mando_missile_follow) then 
      {
         _follow1 = "";
         _follow2 = "";
         _follow3 = "Track lost";
      };

      ctrlSetText [MCC_MODE, format["Mode: %1", _mode]];
      ctrlSetText [MCC_FOLLOW1, format["%1", _follow1]];
      ctrlSetText [MCC_FOLLOW2, format["%1", _follow2]];
      ctrlSetText [MCC_FOLLOW3, format["%1", _follow3]];


      ctrlSetText [MCC_DISTANCEM, format["Distance: %1 m", mando_missile_distance]];

      _velocity = velocity mando_missile;
      _speed = sqrt((_velocity select 0)^2 + (_velocity select 1)^2 + (_velocity select 2)^2);
      ctrlSetText [MCC_SPEEDM, format["Speed: %1 m/s", _speed]];


      ctrlSetText [MCC_ALTITUDEM, format["Altitude ASL: %1 m", getPosASL mando_missile select 2]];
      _engine1 = "Engine ON";
      _engine2 = "";

      if ((damage mando_missile > 0) || (isNull mando_missile)) then
      {
         _engine1 = "";
         _engine2 = "Engine OFF";
      };
      ctrlSetText [MCC_ENGINEON, _engine1];
      ctrlSetText [MCC_ENGINEOFF, _engine2];
      ctrlSetText [MCC_ENDURANCEM, format["Time left: %1 secs", mando_missile_endurance]];

      if (!mando_missile_emergency) then
      {
         ctrlSetText [MCC_GROUNDYES, ""];
         ctrlSetText [MCC_GROUNDNO, "Ground avoidance: No"];
      }
      else
      {  
         ctrlSetText [MCC_GROUNDNO, ""];
         ctrlSetText [MCC_GROUNDYES, "Ground avoidance: Yes"]
      };
      Sleep 0.25;
   };

   if (ctrlVisible MCC_MCC_FRAME) then
   {
      ctrlSetText [MCC_MODE, "Mode: ----"];
      ctrlSetText [MCC_FOLLOW1, ""];
      ctrlSetText [MCC_FOLLOW2, ""];
      ctrlSetText [MCC_FOLLOW3, ""];
      ctrlSetText [MCC_DISTANCEM, "Distance: ---- m"];
      ctrlSetText [MCC_SPEEDM, "Speed: ---- m/s"];
      ctrlSetText [MCC_ALTITUDEM, "Altitude ASL: ---- m"];
      ctrlSetText [MCC_ENGINEON, "Engine ----"];
      ctrlSetText [MCC_ENGINEOFF, ""];
      ctrlSetText [MCC_ENDURANCEM, "Time left: ---- secs"];
      ctrlSetText [MCC_GROUNDNO, "Ground avoidance: No"];
      ctrlSetText [MCC_GROUNDYES, ""];
   };
};