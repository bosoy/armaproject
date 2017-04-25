// Admiral Kuznetsov mando missile and mando gun setup
// Put a mando missile kuznetsov init gamelogic near the center of the kutz you want to have all these systems

private ["_log", "_ship", "_loca1", "_loca2", "_loca3", "_pos", "_gun1", "_gun2"];
_log = _this select 0;

_ship = nearestObject [_log, "TAKR_F0"];

if (isServer && (!isNull _ship)) then
{
   [_ship]spawn
   {
      private["_ship", "_res", "_gun1", "_gun2"];
      _ship = _this select 0;

      if (IsClass (ConfigFile >> "CfgVehicles" >> "bos_ak630")) then
      {
         _gun1 = "bos_ak630" createVehicle [0,0,100];
         _gun1 attachTo [_ship, [21,58,15]];
         _gun2 = "bos_ak630" createVehicle [0,0,100];
         _gun2 attachTo [_ship, [-21,58,15]];
      }
      else
      {

         _gun1 = "mandoturret" createVehicle [0,0,100];
         _gun1 attachTo [_ship, [21,58,17]];
         _gun2 = "mandoturret" createVehicle [0,0,100];
         _gun2 attachTo [_ship, [-21,58,17]];

      };

      // Wait for Mando Missile initialization 
      waitUntil {!isNil "mando_missile_init_done"};
      waitUntil {mando_missile_init_done};

      _animcode = 
      {
         (_this select 0) animate ["turret", -rad(_this select 1)];
         (_this select 0) animate ["gun", rad(_this select 2)];
      };

      // Simulated Kashtan gun (Antiair - antimissile)
      [_gun1, 3, ["Air"], 200, 100, 1500, 1000, 17, 20, [0.6,0.6], 4, true, "", "B_23mm_AA", [0,0,-0.20], "Usti hlavne", [170, 90], 0,[west, east, resistance]-[side _ship], true, true, true, "","", "mando_gun", _animcode]execVM"mando_missiles\mando_gun\mando_gunattacker.sqf";
      Sleep 1;
      [_gun2, 3, ["Air"], 200, 100, 1500, 1000, 17, 20, [0.6,0.6], 4, true, "", "B_23mm_AA", [0,0,-0.20], "Usti hlavne", [170, 270], 0,[west, east, resistance]-[side _ship], true, true, true, "","", "mando_gun", _animcode]execVM"mando_missiles\mando_gun\mando_gunattacker.sqf";
      Sleep 1;

      // 4 SA-N-9 launchers with 192 missiles (Antiair/antimissile)
      _res = [_ship, 0, ["Air"], 48, 500, 6000, 12, [20,40,17], [180, 90], 0, [west, east, resistance]-[side _ship], true, false, true, true, 55]exec"mando_missiles\units\attackers\mando_seasparrow.sqs";
      Sleep 1;

      _res = [_ship, 0, ["Air"], 48, 500, 6000, 12, [-18,40,17], [180, -90], 0, [west, east, resistance]-[side _ship], true, false, true, true, 55]exec"mando_missiles\units\attackers\mando_seasparrow.sqs";
      Sleep 1;

      _res = [_ship, 0, ["Air"], 48, 500, 6000, 12, [22,-140,17], [180, 90], 0, [west, east, resistance]-[side _ship], true, false, true, true, 55]exec"mando_missiles\units\attackers\mando_seasparrow.sqs";
      Sleep 1;

      _res = [_ship, 0, ["Air"], 48, 500, 6000, 12, [-24,-140,17], [180, -90], 0, [west, east, resistance]-[side _ship], true, false, true, true, 55]exec"mando_missiles\units\attackers\mando_seasparrow.sqs";


      // Automatic AG misiles for AI driver (12 SS-N-19)
      _res =  [_ship, 0, ["LandVehicle", "Ship"], 12, 500, 8000, 6, [0, 90, 17], 360, 0, [west, east, resistance]-[side _ship], false, false, true, true, 85]exec"mando_missiles\units\attackers\mando_harpoon.sqs";

   };
};

if (!isNull _ship) then
{
   while {!alive player} do
   {
      Sleep 1;
   };


   if (side player == east) then
   {
      _loca1 = createLocation ["NameCity", getPos _ship, 100, 100];
      _loca1 setSide east;
      _loca1 setText "_";
      _loca1 setVariable ["mando_nav_info", "3"];

      _loca2 = createLocation ["NameCity", getPos _ship, 100, 100];
      _loca2 setSide east;
      _loca2 setText "___";
      _loca2 setVariable ["mando_nav_info", "2"];

      _loca3 = createLocation ["NameCity", getPos _ship, 100, 100];
      _loca3 setSide east;
      _loca3 setText "_____";
      _loca3 setVariable ["mando_nav_info", "1"];

      while {alive _ship} do
      {
         _pos = getPos _ship;
         _pos = [(_pos select 0)+sin(180 + getDir _ship)*140,(_pos select 1)+cos(180 + getDir _ship)*140, 17];
         _loca1 setPosition _pos;
         _pos = getPos _ship;
         _pos = [(_pos select 0)+sin(180 + getDir _ship)*1140,(_pos select 1)+cos(180 + getDir _ship)*1140, 100];
         _loca2 setPosition _pos;
         _pos = getPos _ship;
         _pos = [(_pos select 0)+sin(180 + getDir _ship)*2140,(_pos select 1)+cos(180 + getDir _ship)*2140, 200];
         _loca3 setPosition _pos;
         Sleep 3;
      };
   };
};