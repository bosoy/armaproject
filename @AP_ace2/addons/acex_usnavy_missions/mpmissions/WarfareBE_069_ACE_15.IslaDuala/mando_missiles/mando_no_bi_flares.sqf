   []spawn
   {
      while {true} do
      {  
         {
            if ("CMFlareLauncher" in (_x weaponsTurret [-1])) then
            {
               _x removeMagazinesTurret["60Rnd_CMFlareMagazine", [-1]];
               _x removeMagazinesTurret["120Rnd_CMFlareMagazine", [-1]];
               _x removeMagazinesTurret["120Rnd_CMFlare_Chaff_Magazine", [-1]];
			   _x removeMagazinesTurret["60Rnd_CMFlare_Chaff_Magazine", [-1]];
            }
            else
            {
               if ("CMFlareLauncher" in (_x weaponsTurret [0])) then
               {
                  _x removeMagazinesTurret["60Rnd_CMFlareMagazine", [0]];
                  _x removeMagazinesTurret["120Rnd_CMFlareMagazine", [0]];
                  _x removeMagazinesTurret["120Rnd_CMFlare_Chaff_Magazine", [0]];
				  _x removeMagazinesTurret["60Rnd_CMFlare_Chaff_Magazine", [0]];
               };
            };
            Sleep 0.01;
         } forEach vehicles;
         Sleep 5;
      };
   };
