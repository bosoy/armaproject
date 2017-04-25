// Air 5, Car 2, Tank 3, Boat 3, Static 3

// Code that is executed by missile warhead scripts to add score to players firing missiles.
Sleep 4;
_var = false;
// hint format["%1-%2-%3",damage _target, typeOf _target, _side];

if ((damage _target > 0.9) || (isNull _target)) then
{
   if (!isNull _target) then
   {
      _var = _target getVariable "mando_kill_scored";
   };
	  
   if ((isNil "_var") || (isNull _target)) then
   {

      if ((!isNull _target) && (isServer)) then
      {
         [_target] spawn
         {
            Sleep 5;
            (_this select 0) setVariable ["mando_kill_scored", true, true];
         };
      };


      if (typeName _cost == "SCALAR") then
      {
         _rating = 100 + _cost / 1000;
      }
      else
      {
         _rating = 100;
      };

	  
	  _planes = 0;
	  _choppers = 0;
	  _tanks = 0;
	  _cars = 0;
	  _ships = 0;
	  _bships = 0;
	  _static = 0;
	  _crews = 0;
	  _missiles = 0;
      if (_classtarget isKindOf "Air") then
      {
         _score = 5;
		 if (_classtarget isKindOf "Plane") then
		 {
            _planes = _planes + 1;
		 }
		 else
		 {
		    _choppers = _choppers + 1;
		 };
      }
      else
      {
         if ((_classtarget isKindOf "Car") || (_classtarget isKindOf "Motorcycle")) then
         {
            _score = 2;
			_cars = _cars + 1;
         }
         else
         {
            if (_classtarget isKindOf "Tank") then
            {
               _score = 3;
			   _tanks = _tanks + 1;
            }
            else
            {
               if (_classtarget isKindOf "Boat") then
               {
                  _score = 3;
				  _ships = _ships + 1;
               }
               else
               {
                  if (_classtarget isKindOf "BigShip") then
                  {
                     _score = 25;
					 _ships = _ships + 1;
                  }
                  else
                  {
                     if (_classtarget isKindOf "SmallShip") then
                     {
                        _score = 15;
						_ships = _ships + 1;
                     }
                     else
                     {         
                        if (_classtarget isKindOf "Ship") then
                        {
                           _score = 10;
						   _ships = _ships + 1;
                        }
                        else
                        {
                           if (_classtarget isKindOf "StaticWeapon") then
                           {
                              _score = 3;
							  _static = _static + 1;
                           }
                           else
                           {
								if (!(_classtarget in ["LaserTargetW", "LaserTargetE", "LaserTargetC", "Logic"])) then
								{
									_score = 25;
									_missiles = _missiles + 1;
								};
                           };
                        };
                     };
                  };
               };
            };
         };
      };

      if (({!alive _x} count _crewt) > 0) then
      {
         _score = _score + ({!alive _x} count _crewt);
		 _crews = _crews + ({!alive _x} count _crewt);
      };
  
      if (_side == (side _launcher)) then
      {
         _rating = -_rating;
         _score = -_score;
      };	  
	  
      _crew = crew _launcher;
	  //--- Benny: Kill Script.
	  _unit = _crew select 0;
	  if (local _target) then {
		if !(_target in [('WFBE_WESTMHQNAME' Call GetNamespace),('WFBE_EASTMHQNAME' Call GetNamespace)]) then {
			[_target, _unit, _side] Spawn UnitKilled;
		};
	  };


      for [{_i=0},{_i < (count _crew)},{_i=_i+1}] do
      {
         _unit = _crew select _i;
         if (alive _unit) then
         {
            if (isPlayer _unit) then 
            {
               if (isServer) then
               {
                  _unit addScore _score;
               };
            };
  
            if ((local _unit) && (isPlayer _unit)) then
            {
              _unit addRating _rating;
			  
			  mando_score_cars = mando_score_cars + _cars;
			  mando_score_planes = mando_score_planes + _planes;
			  mando_score_choppers = mando_score_choppers + _choppers;
			  mando_score_tanks = mando_score_tanks + _tanks;
			  mando_score_ships = mando_score_ships + _ships;
			  mando_score_bships = mando_score_bships + _bships;
			  mando_score_static = mando_score_static + _static;
			  mando_score_crews = mando_score_crews + _crews;
			  mando_score_missiles = mando_score_missiles + _missiles;			  
            };
         };
      };
   };
};