DisableSerialization;

mando_mapfallout = 
{
   private["_event", "_params", "_display"];
   _event = _this select 0;
   _params = _this select 1;

   switch (_event) do
   {
      case "onLoad":
      {
         onMapSingleClick "true";

         ECHO_rad_format = "gray";

         _display = _params select 0;
         (_display displayCtrl 100) ctrlSetText (mando_missile_path+"mfds\raptor6_mfd1.paa");

	 []spawn
	 {
		Sleep 0.1;
		while {!isNull (findDisplay 24000)} do
		{
			// Up to 50 Echo fallout markers are made visible (their y-40000)
			_rad = 0;
			for [{_i=0},{_i<50},{_i=_i+1}] do
			{
			       _marker_name = format["ECHO_FalloutMarker%1", _i];
	               		if (getMarkerColor _marker_name != "") then
	               		{
		                	if (getMarkerColor (_marker_name + "X") == "") then
	        	        	{						   
				   		_fallout_name = _marker_name + "X";
				   		_fallout_marker = createMarkerLocal[_fallout_name, getMarkerPos _marker_name];
				   		_fallout_name setMarkerShape "ELLIPSE";
				  	 	_fallout_name setMarkerSize getMarkerSize _marker_name;
		                   		_loc = nearestLocation [getMarkerPos _marker_name, "Name"];
				   		_fallout_name setMarkerDir direction _loc;
		                   		_fallout_name setMarkerColor "ColorOrange";
					};

		                        _loc = nearestLocation [getMarkerPos _marker_name, "Name"];
				        if ((getMarkerPos "mk_mando_maptgt") in _loc) then
				        {
						_rad = _rad + ((ECHO_FalloutGL getVariable format["%1",_i]) select 0);
	       		        	};
		      		}
				else
				{
		                	if (getMarkerColor (_marker_name + "X") != "") then
	        	        	{
					        deleteMarker (_marker_name + "X");
					};
				};
			};
			switch (ECHO_rad_format) do
			{
				case "gray":
				{
					"mk_mando_maptgt" setMarkerTextLocal format["RAD:%1 Gy", (8*(round(100*_rad))/100)];
				};

				default
				{
					"mk_mando_maptgt" setMarkerTextLocal format["RAD:%1%2", (100*(round(10*_rad))/10),"%"];
				};
			};
			Sleep 4;
		};
	 };

         []spawn 
         {
            private["_unit"];
            _unit = vehicle player;

	    Sleep 0.5;

            createMarkerLocal ["mk_mando_maptgt", getPos _unit];
            "mk_mando_maptgt" setMarkerTypeLocal "Attack";
            "mk_mando_maptgt" setMarkerColorLocal "ColorWhite";
            "mk_mando_maptgt" setMarkerSizeLocal [0.55, 0.55];
            "mk_mando_maptgt" setMarkerTextLocal "RAD:?";


            createMarkerLocal ["mk_mando_maptgt_lnk", [0,0]];
            "mk_mando_maptgt_lnk" setMarkerShapeLocal "RECTANGLE";
            "mk_mando_maptgt_lnk" setMarkerColorLocal "ColorWhite";
            "mk_mando_maptgt_lnk" setMarkerSizeLocal [0, 0];
            
            createMarkerLocal ["mk_mando_maptgt_dir", getPos _unit];
            "mk_mando_maptgt_dir" setMarkerTypeLocal "Move";
            "mk_mando_maptgt_dir" setMarkerColorLocal "ColorWhite";
            "mk_mando_maptgt_dir" setMarkerSizeLocal [0.55, 0.55];
            "mk_mando_maptgt_dir" setMarkerDirLocal (getDir _unit)-90;

            Sleep 0.5;           

            while {!isNull (findDisplay 24000)} do
            {
              _ang = ((getMarkerPos "mk_mando_maptgt" select 0)-(getPos _unit select 0)) atan2 ((getMarkerPos "mk_mando_maptgt" select 1)-(getPos _unit select 1));
              _dist = sqrt (((getMarkerPos "mk_mando_maptgt" select 0)-(getPos _unit select 0))^2 + ((getMarkerPos "mk_mando_maptgt" select 1)-(getPos _unit select 1))^2);
              "mk_mando_maptgt_lnk" setMarkerPosLocal [(getPos _unit select 0)+sin(_ang)*_dist/2, (getPos _unit select 1)+cos(_ang)*_dist/2];

              "mk_mando_maptgt_lnk" setMarkerDirLocal _ang;
              "mk_mando_maptgt_lnk" setMarkerSizeLocal [2, _dist/2];
              "mk_mando_maptgt_dir" setMarkerDirLocal (getDir _unit)-90;
              "mk_mando_maptgt_dir" setMarkerPosLocal (getPos _unit);
               Sleep 0.1;
            };            
         };
      };

      case "onUnload":
      {
         deleteMarker "mk_mando_maptgt";
         deleteMarker "mk_mando_maptgt_lnk";
         deleteMarker "mk_mando_maptgt_dir";
         if (!isNil "mando_last_onmapsclick") then
         {
            onMapSingleClick mando_last_onmapsclick;
         }
         else
         {
            onMapSingleClick "";
         };

	    // Up to 50 Echo fallout markers are made invisible (their y+40000)
	   for [{_i=0},{_i<50},{_i=_i+1}] do
	   {
	       _marker_name = format["ECHO_FalloutMarker%1", _i];
               if (getMarkerColor _marker_name != "") then
               {
		   _fallout_name = _marker_name + "X";
		   deleteMarker _fallout_name;
               };
	   };		
      };

      case "onMapClick":
      {
         if (((_this select 1) select 1) == 0) then
         {
            if (!((_this select 1) select 4)) then
            {
               "mk_mando_maptgt" setMarkerPosLocal (((_this select 1) select 0) ctrlMapScreenToWorld [(_this select 1) select 2, (_this select 1) select 3]);

	       _rad = 0;
	       for [{_i=0},{_i<50},{_i=_i+1}] do
	       {
	          _marker_name = format["ECHO_FalloutMarker%1", _i];
                  if (getMarkerColor _marker_name != "") then
                  {  
                      _loc = nearestLocation [getMarkerPos _marker_name, "Name"];
		      if ((getMarkerPos "mk_mando_maptgt") in _loc) then
		      {
			_rad = _rad + ((ECHO_FalloutGL getVariable format["%1",_i]) select 0);
		      };
                  };
	       };
		switch (ECHO_rad_format) do
		{
			case "gray":
			{
				"mk_mando_maptgt" setMarkerTextLocal format["RAD:%1 Gy", 8*((round(100*_rad))/100)];
			};

			default
			{
				"mk_mando_maptgt" setMarkerTextLocal format["RAD:%1%2", 100*((round(10*_rad))/10), "%"];
			};
		};
            };
            playSound "mando_target1";
         };
      };

      case "on_btn1":
      {
         _display = findDisplay 24000;
         (_display displayCtrl 99) ctrlSetText "Dosage in Gray";
         ECHO_rad_format = "gray";
      };

      case "on_btn2":
      {
         _display = findDisplay 24000;
         (_display displayCtrl 99) ctrlSetText "Dosage in %LD-10min";
         ECHO_rad_format = "percent";
      };
   };
};

_ok = createDialog "Mando_mapfallout";
