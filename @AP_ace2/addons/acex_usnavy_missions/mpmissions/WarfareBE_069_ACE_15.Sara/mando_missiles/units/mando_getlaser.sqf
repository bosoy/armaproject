/* mando_getlaser.sqf
By Mandoble June 2007


*/
private["_dirini", "_lasers", "_firstlaser", "_ltype", "_mindistabs", "_posm", "_dir", "_i", "_laser", "_post", "_ang", "_dif", "_difabs", "_targets", "_target", "_classtarget", "_crewt", "_cost", "_launcher", "_side", "_score", "_rating"];

_dirini = 0.0;
_lasers = [];
_firstlaser = objNull;

(_this select 0) removeAction (_this select 2);

_ltype = "";
if (side player == west) then
{
   _ltype = "LaserTargetW";
}
else 
{
   if (side player == east) then
   {
      _ltype = "LaserTargetE";
   }
   else 
   {
      if (side player == resistance) then
      {
         _ltype = "LaserTargetC";
      }
      else 
      {
         _ltype = "LaserTargetC";
      };   
   };   
};   

_mindifabs = 9999;
//_posm   = getPos vehicle player;
_posm = screenToWorld [0.5,0.5];

_lasers = _posm nearObjects[_ltype,1000];
_dir    = getDir player;
if (count _lasers > 0) then
{
   for [{_i = 0},{_i < count _lasers}, {_i=_i+1}] do
   {
      _laser = _lasers select _i;
      _post = getPos _laser;
      
      _ang = ((_post select 0)-(_posm select 0)) atan2 ((_post select 1)-(_posm select 1));
      _dif = (_ang - _dir);
      if (_dif < 0) then {_dif = 360 + _dif;};
      if (_dif > 180) then {_dif = _dif - 360;};
      _difabs = abs(_dif);
      if (_difabs < _mindifabs) then
      {
         _firstlaser = _laser;
         _mindifabs = _difabs;
      };
   };

//   hint format["%1 %2", side _firstlaser, _mindifabs];

   if (!isNull _firstlaser) then
   {
      switch (side player) do
      {
         case west:
         {
            mando_remote_w = _firstlaser;
            publicVariable "mando_remote_w";
            titleText["Laser target transmitted", "PLAIN DOWN"];
         };
     
         case east:
         {
            mando_remote_e = _firstlaser;
            publicVariable "mando_remote_e";
            titleText["Laser target transmitted", "PLAIN DOWN"];
         };

         case resistance:
         {
            mando_remote_r = _firstlaser;
            publicVariable "mando_remote_r";
            titleText["Laser target transmitted", "PLAIN DOWN"];
         };
      };

      _score = 0;
      _target = objNull; 
      _post = getPos _firstlaser;


      _score = 0;
      _target = objNull; 
      while {!isNull _firstlaser} do
      {
         _post = getPos _firstlaser;
         if ((!isNull _target) && ((_target distance _post) < 10)) then
         {
            if (damage _target > 0.9) then
            { 
               call mando_scorefunc;
               _target = objNull;
            };
         }
         else
         {
            _targets = nearestObjects [_post, ["LandVehicle","Air", "Ship"], 10];
            if (count _targets > 0) then
            {
               _target = _targets select 0;
               if (damage _target <= 0.9) then
               {
                  _classtarget = typeOf _target;
                  _crewt = crew _target;
                  _launcher = player;
                  _side = sideEnemy;
                  _cost = getNumber (configFile >> "CfgVehicles" >> _classtarget >> "cost");
               } 
               else
               {
                  _target = objNull;
               };            
            }
            else
            {
               _target = objNull;  
            };
         };

         Sleep 0.1;
      };
   };
}
else
{
   titleText["No laser target present", "PLAIN DOWN"];
};

if (((currentWeapon vehicle player) in mando_lasers) && (alive vehicle player)) then
{
   (_this select 0) addAction ["<t color=""#ffffff"">MMA Transmit target", mando_missile_path+"units\mando_getlaser.sqf","",94];
};