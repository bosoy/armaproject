private["_sam", "_owners", "_side", "_enemysides", "_animcode", "_var"];
_sam= _this select 0;

if (isServer) then
{   
   Sleep (2+(random 3));
   
   _side = _sam getVariable "mando_sam_side";

   if (!isNil "_side") then
   {
      _enemysides = [];
      {
         if ((_side getFriend _x) < 0.2) then
         {
            _enemysides = _enemysides + [_x];
         }; 
      } forEach [west, east, civilian, resistance, sideEnemy];
      
      // Simulated sea sparrow SAM (Antiair - antimissile)
      [_sam, 0, ["Air"], 8, 500, 6000, 12, [-24,-140,17], 360, 0, _enemysides, true, false, true, true, 55]exec"mando_missiles\units\attackers\mando_bo_seasparrow_auto.sqs";

      while {alive _sam} do
      {
         _var = _sam getVariable "mando_gunattacker_on";
         if (!isNil "_var") then
         {
            if (!_var) then
            {
               _sam animate ["gun", rad (-20)];
               while {!_var && alive _sam} do
               {
                  _var = _sam getVariable "mando_gunattacker_on";
                   Sleep 1;
               };
            }
            else
            {
               _sam animate ["gun", 0];
               while {_var && alive _sam} do
               {
                  _var = _sam getVariable "mando_gunattacker_on";
                  Sleep 1;
               };
            };
         };
         Sleep 1;
      };

   }; 
};