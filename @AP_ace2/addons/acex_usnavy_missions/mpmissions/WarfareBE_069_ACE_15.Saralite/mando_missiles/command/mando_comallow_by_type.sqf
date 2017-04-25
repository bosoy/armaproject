/* mando_comallow_by_type.sqf
By Mandoble June 2007

Purpose:
   Waits until a player is in a vehicle which type is in the provided array, and then gives that vehicle MCC capability. 

Arguments: 
   Array of vehicle types
   position of the player to activate this mcc: 0 - driver, 1 - gunner, 2 - commander
   Array of commanded vehicles   
   

Examples:

*/

private ["_planetypes", "_position", "_plane", "_inplane", "_driver", "_gunner", "_commander", "_class", "_actionidx", "_range"];

_planetypes  = _this select 0;
_position    = _this select 1;
_commanded   = _this select 2;
_range       = _this select 3;

while {true} do
{
   waitUntil {!isNull player};

   _inplane = false;

   while {!_inplane} do
   {
      Sleep 1;

      if ((vehicle player) != player) then
      {
         _plane = vehicle player;
         _class = typeOf _plane;

         if (_class in _planetypes) then
         {
            _driver = driver _plane;
            _gunner = gunner _plane;
            _commander = commander _plane;

            if (((_position == 0) && (_driver == player)) || 
                ((_position == 1) && (_gunner == player)) ||
                ((_position == 2) && (_commander == player))) then
            {
               _inplane = true;
               _plane = vehicle player;
            };
         };
      };
   };

   _actionidx =  _plane addAction ["Activate Command Center", mando_missile_path+"command\mando_com_control.sqf", [_commanded, _range]];

   if (_position == 0) then
   {
      while {driver _plane == player} do
      {
         Sleep 1;
      };
   }
   else
   {
      if (_position == 1) then
      {
         while {gunner _plane == player} do
         {
            Sleep 1;
         };
      }
      else
      {
         while {commander _plane == player} do
         {
            Sleep 1;
         };
      };
   };
   _plane removeAction _actionidx;

   _inplane = false;

   Sleep 2;
};