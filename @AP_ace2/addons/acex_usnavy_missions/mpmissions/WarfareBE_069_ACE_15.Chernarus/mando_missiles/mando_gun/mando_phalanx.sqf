private["_phalanx", "_owners", "_side", "_enemysides", "_animcode", "_var"];
_phalanx= _this select 0;

if (isServer) then
{   
   Sleep (2+(random 3));
   
   _side = _phalanx getVariable "mando_gun_side";

   if (!isNil "_side") then
   {
      _enemysides = [];
      {
         if ((_side getFriend _x) < 0.2) then
         {
            _enemysides = _enemysides + [_x];
         }; 
      } forEach [west, east, civilian, resistance, sideEnemy];
      
      // Simulated phalanx gun (Antiair - antimissile)
      _animcode = 
      {
       //  maingun (x) and mainturret (y)
       // "gun" "turret"
/*
         (_this select 0) animate ["x_base", (_this select 1)/180];
         (_this select 0) animate ["y_base", (_this select 2)/180];
*/

         (_this select 0) animate ["turret", -rad(_this select 1)];
         (_this select 0) animate ["gun", rad(_this select 2)];
      };

      [_phalanx, 3, ["Air"], 200, 100, 1500, 1000, 17, 20, [0.6,0.6], 4, true, "", "B_23mm_AA", [0,0,-0.20], "Usti hlavne", 360, 0,_enemysides, true, true, false, "","", "mando_gun", _animcode]execVM"mando_missiles\mando_gun\mando_gunattacker.sqf";

      while {alive _phalanx} do
      {
         _var = _phalanx getVariable "mando_gunattacker_on";
         if (!isNil "_var") then
         {
            if (!_var) then
            {
               _phalanx animate ["gun", rad (-20)];
               while {!_var && alive _phalanx} do
               {
                  _var = _phalanx getVariable "mando_gunattacker_on";
                   Sleep 1;
               };
            }
            else
            {
               _phalanx animate ["gun", 0];
               while {_var && alive _phalanx} do
               {
                  _var = _phalanx getVariable "mando_gunattacker_on";
                  Sleep 1;
               };
            };
         };
         Sleep 1;
      };

   }; 
};