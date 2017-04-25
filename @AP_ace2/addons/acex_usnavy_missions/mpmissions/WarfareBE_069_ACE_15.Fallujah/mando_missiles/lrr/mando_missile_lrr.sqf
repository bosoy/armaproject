/*********************************************************************************
   mando_missile_lrr.sqf v1.0
   by Mandoble, Jan 2011

   Example activation action scripts for several systems can be found into mando_missiles\lrr\lrr_types folder. These scripts are used as sixth parameter for mando_mccallow_by_name.sqf or mando_mccallow_by_type.sqf.

   Globals required (set them from the corresponding activation action script)

*********************************************************************************/



disableSerialization;

private ["_event", "_params", "_display", "_i", "_first","_marker", "_missparam", "_target", "_target1", "_target2", "_continue", "_mis", "_firing_dir", "_rects", "_texts"];



_first = false;
if (count _this == 0) then
{
   _first = true;
}
else
{
   if (typeName (_this select 0) != "STRING") then
   {
      _first = true;
   }
   else
   {      
      _event = _this select 0;
      _params = _this select 1;
   };
};


if (_first) exitWith
{
   disableSerialization;

   if (isNil "mandotarget_disp_on") then
   {
      mandotarget_disp_on = false;
   };
   mandotarget_disp_on_old = mandotarget_disp_on;
   mandotarget_disp_on = false;
   3 cutText["", "PLAIN"];
   mando_rec_flir = false;

   if (isNil "mando_missile_lrr") then
   {
      mando_missile_lrr = compile (preprocessFileLineNumbers (mando_missile_path+"lrr\mando_missile_lrr.sqf"));
   };


      // HELP, MAP, TGT, MODE, FLIR, FIRE, XMIT, UP, DOWN
      mando_tv_backcolor = [mando_missile_path+"mfds\raptor6_mfd1.paa", [
/*	  
[-0.086, 0.155,0.076, 0.075*4/3],
[-0.084, 0.31,0.076,0.075*4/3],
[1.005, 0.61,0.0765,0.075*4/3],
[-0.082, 0.61,0.076,0.075*4/3],
[1.005,0.755,0.076,0.075*4/3],
[1.005, 0.155, 0.075, 0.075*4/3],
[1.005, 0.31, 0.075, 0.075*4/3],
[1.005, 0.46, 0.075,0.075*4/3],
[-0.082, 0.755, 0.075,0.075*4/3]]];
*/

[1.005, 0.155,0.075, 0.075*4/3],
[1.005, 0.31,0.075,0.075*4/3],
[-0.082, 0.61,0.075,0.075*4/3],
[1.005, 0.46,0.075,0.075*4/3],
[-0.082,0.755,0.075,0.075*4/3],
[-0.082, 0.155, 0.075, 0.075*4/3],
[-0.082, 0.31, 0.075, 0.075*4/3],
[-0.082, 0.46, 0.075,0.075*4/3],
[1.005, 0.755, 0.075,0.075*4/3]]];

	mando_lrr_state = false;
	mando_lrr_max_range	= 20000;
	mando_lrr_range = mando_lrr_max_range;
	mando_lrr_camera = 0;
	mando_lrr_sam = 0;
	mando_lrr_fov = 1;

   if (isNil "mando_lrr_cam_pos") then
   {
      mando_lrr_cam_pos = [0,3,-2];
   };

	{
		_x setVariable ["mando_auto_allowed", false, true];
	} forEach (mando_lrr_unit getVariable "mando_lrr_units");
   
   _ok = createDialog "MandoMissileLRRDlg";
};



switch (_event) do
{

   case "onLoad":
   {

	  camUseNVG false;

      _display = _params select 0;

// Back color has no effect, use only pic if exist

      (_display displayCtrl 23901) ctrlSetText mando_missile_path+"mfds\raptor6_mfd1.paa";


      (_display displayCtrl 23903) ctrlSetText (mando_missile_path+"mcc\aimcircle.paa");
      (_display displayCtrl 23904) ctrlSetText (mando_missile_path+"mandocamera_circle.paa");
      (_display displayCtrl 23905) ctrlSetText (mando_missile_path+"mandocamera_rect.paa");
      (_display displayCtrl 23929) ctrlSetText (mando_missile_path+"mandocamera_rombe.paa");
      (_display displayCtrl 23930) ctrlSetText (mando_missile_path+"mandocamera_rect.paa");
      (_display displayCtrl 23931) ctrlSetText (mando_missile_path+"mandocamera_rect.paa");
      (_display displayCtrl 23932) ctrlSetText (mando_missile_path+"mandocamera_rect.paa");
      (_display displayCtrl 23933) ctrlSetText (mando_missile_path+"mandocamera_rect.paa");
      (_display displayCtrl 23934) ctrlSetText (mando_missile_path+"mandocamera_rect.paa");
      (_display displayCtrl 23935) ctrlSetText (mando_missile_path+"mandocamera_rect.paa");
      (_display displayCtrl 23936) ctrlSetText (mando_missile_path+"mandocamera_rect.paa");
      (_display displayCtrl 23937) ctrlSetText (mando_missile_path+"mandocamera_rect.paa");
      (_display displayCtrl 23938) ctrlSetText (mando_missile_path+"mandocamera_rect.paa");
      (_display displayCtrl 23939) ctrlSetText (mando_missile_path+"mandocamera_rect.paa");

	  {
		(_display displayCtrl (22100 + _x)) ctrlSetText (mando_missile_path+"mandocamera_circle.paa");
	  } forEach [0,1,2,3,4,5];
	  
/*
      (_display displayCtrl 23950) ctrlSetText (mando_missile_path+"mandocamera_left.paa");
      (_display displayCtrl 23951) ctrlSetText (mando_missile_path+"mandocamera_right.paa");
*/
      (_display displayCtrl 23923) ctrlSetText "";

	  [_display] spawn
	  {
		  disableSerialization;
		  _display = _this select 0;
		  _rects = [];
		  _rects = _rects + [_display displayCtrl 23930];
		  _rects = _rects + [_display displayCtrl 23931];
		  _rects = _rects + [_display displayCtrl 23932];
		  _rects = _rects + [_display displayCtrl 23933];
		  _rects = _rects + [_display displayCtrl 23934];
		  _rects = _rects + [_display displayCtrl 23935];
	      _rects = _rects + [_display displayCtrl 23936];
	      _rects = _rects + [_display displayCtrl 23937];
	      _rects = _rects + [_display displayCtrl 23938];
	      _rects = _rects + [_display displayCtrl 23939];		  

		  _texts = [];
		  _texts = _texts + [_display displayCtrl 23940];
		  _texts = _texts + [_display displayCtrl 23941];
		  _texts = _texts + [_display displayCtrl 23942];
		  _texts = _texts + [_display displayCtrl 23943];
		  _texts = _texts + [_display displayCtrl 23944];
		  _texts = _texts + [_display displayCtrl 23945];
		  _texts = _texts + [_display displayCtrl 23946];		  
		  _texts = _texts + [_display displayCtrl 23947];
		  _texts = _texts + [_display displayCtrl 23948];
		  _texts = _texts + [_display displayCtrl 23949];

		  for [{_i=0},{_i<10},{_i=_i+1}] do
		  { 
			 (_rects select _i) ctrlSetTextColor [1,0,0,0];
			 (_texts select _i) ctrlSetTextColor [1,0,0,0];
			 (_texts select _i) ctrlSetText "";
		  };
		  

		  []spawn
		  {
			 sleep 0.2;
			 ((findDisplay 23900) displayCtrl 23924) ctrlShow false;

			 _i = 0;
			 {
				((findDisplay 23900) displayCtrl _x) ctrlSetPosition ((mando_tv_backcolor select 1) select _i);
				((findDisplay 23900) displayCtrl _x) ctrlCommit 0;
				_i = _i + 1;
			 } forEach [23925,23926,23922,23921,23919,23918,23927,23960,23961];
		  };

		  _trigger = createTrigger ["EmptyDetector", getPos mando_lrr_unit];
		  _trigger setTriggerActivation ["ANY", "PRESENT", false];
		  _trigger setTriggerArea [mando_lrr_max_range, mando_lrr_max_range, 0, false];
		  _trigger setTriggerType "NONE";
		  _trigger setTriggerStatements ["this", "", ""];
		  _trigger setTriggerTimeout [0, 0, 0, false ];
		  
		  mando_tv_targets = [];
          _min_targets_alt = 20;
		  _max_targets_alt = 30000;

		  [_display] spawn
		  {
			disableSerialization;
			_display = _this select 0;
			_missiles = [];
			while {!isNull _display} do
			{
				{
					_missile = _x getVariable "mando_auto_fired";
					if (!isNull _missile) then
					{
						if (!(_missile in _missiles)) then
						{
							_missiles = _missiles + [_missile];
						};
					};
				} forEach (mando_lrr_unit getVariable "mando_lrr_units");
				
				for [{_i=0}, {_i < 6}, {_i = _i + 1}] do
				{
					_poss = [-2, -2];
					if (_i < (count _missiles)) then
					{						
						_target = _missiles select _i;
						if (!isNull _target) then
						{
							_pos = mando_lrr_unit worldToModel (getPos _target);
							_dist = sqrt ((_pos select 0)^2 + (_pos select 1)^2);

							if (_dist < mando_lrr_range) then
							{
								_ang = ((getPos _target select 0)-(getPos mando_lrr_unit select 0)) atan2 ((getPos _target select 1)-(getPos mando_lrr_unit select 1));
								_rads = (_dist * 0.968/2)/mando_lrr_range;
								_poss = [0.5 - 0.01*3/4 + sin(_ang)*_rads*3/4, 0.5 - 0.01 - cos(_ang)*_rads, 0.02*3/4, 0.02];
							};
						};						
					};

					 (_display displayCtrl (22100 + _i)) ctrlSetPosition _poss;
					 (_display displayCtrl (22100 + _i)) ctrlCommit 0;										
				};
				Sleep 0.1;
				_missiles = _missiles - [objNull];
			};
		  };
		  
		  [_display] spawn
		  {
			disableSerialization;
			_display = _this select 0;
			_old_target = objNull;
			_old_fov = mando_lrr_fov;
			showCinemaBorder false;
			_cam = "camera" camcreate [0, 0, 0];
			_cam cameraeffect ["internal", "back"];
			_cam camSetFov 1;
			_cam attachTo [mando_lrr_unit, mando_lrr_cam_pos];
			_target = (mando_lrr_unit getVariable "mando_lrr_units") select 0;
			while {!isNull _display} do
			{
				if (mando_lrr_camera == 2) then
				{					
					if (!isNull(mando_lrr_target)) then
					{
						_target = mando_lrr_target;
					}
					else
					{
						_target = (mando_lrr_unit getVariable "mando_lrr_units") select mando_lrr_sam;
					};
				}
				else
				{
					_target = (mando_lrr_unit getVariable "mando_lrr_units") select mando_lrr_sam;
				};
				
				if ((_old_target != _target) || (_old_fov != mando_lrr_fov)) then
				{
					_old_target = _target;
					_cam camSetTarget _target;
					_cam camSetFov mando_lrr_fov;
					if (_old_fov != mando_lrr_fov) then
					{
						_old_fov = mando_lrr_fov;
						_cam camCommit 0;
					}
					else
					{					
						_cam camCommit 1;
					};
				};
				Sleep 0.5;
				_radar = "";
				if (mando_lrr_state) then
				{
					if (!isNull mando_lrr_target) then
					{
						_radar = "STT";
					}
					else
					{
						_radar = "RWS";
					};
				}
				else
				{
					_radar = "OFF";
				};
				_range = mando_lrr_range;
				if (_target == (mando_lrr_unit getVariable "mando_lrr_units") select 0) then
				{
					_target = "L1";
				}
				else
				{
					if (_target == (mando_lrr_unit getVariable "mando_lrr_units") select 1) then
					{
						_target = "L2";
					}
					else
					{
						if (_target == (mando_lrr_unit getVariable "mando_lrr_units") select 2) then
						{
							_target = "L3";
						}
						else
						{
							if (_target == mando_lrr_target) then
							{
								_target = "TGT";
							}
							else
							{
								_target = "None";							
							};						
						};					
					};
				};
//				_zoom = floor (1/((atan(mando_lrr_fov)*2) / (atan(1)*2)));
				_zoom = floor (1/((atan(mando_lrr_fov)*2) / 90));
				(_display displayCtrl 23950) ctrlSetStructuredText parseText 
					format ["Radar: %1<br />Current Range: %2 Km<br />Max Range: %3 Km<br />Launcher: L%4<br />Cam: %5<br />Zoom: %6x", 
							_radar, floor (mando_lrr_range/1000), floor (mando_lrr_max_range/1000), mando_lrr_sam + 1, _target, _zoom];
				_txt = "";
				for [{_i=0},{_i<3},{_i=_i+1}] do
				{
					_unit = (mando_lrr_unit getVariable "mando_lrr_units") select _i;
					if (!isNull _unit) then
					{
						if (alive _unit) then
						{
							if (_unit getVariable "mando_auto_allowed") then
							{
								_txt = _txt + format["L%1 Engage", _i + 1];
							}
							else
							{
								_txt = _txt + format["L%1 Do not engage", _i + 1];
							};
							
							// Miss left
							_left = 0;
							for [{_j=0},{_j<8},{_j=_j+1}] do
							{
								_var = _unit getVariable format["mando_maxmissiles%1", _j];
								if (!isNil "_var") then
								{
									_left = _left + _var;
								};
							};
							_txt = _txt + format[" - %1",_left];
						}
						else
						{
							_txt = _txt + format["L%1 destroyed", _i + 1];						
						};
					}
					else
					{
						_txt = _txt + format["L%1 not present", _i + 1];
					};
					_txt = _txt + "<br />";
				};
				(_display displayCtrl 23952) ctrlSetStructuredText parseText _txt;				
			};
			_cam cameraeffect ["terminate", "back"];
			camDestroy _cam;			
		  };

			_deltaz = ((mando_lrr_unit modelToWorld mando_lrr_cam_pos) select 2) - (getPos mando_lrr_unit select 2);
		  
		  [_display, _trigger, _min_targets_alt, _max_targets_alt, _deltaz] spawn 
		  {
			 disableSerialization;
				  
			 private ["_commdisplay", "_trigger", "_radar_targets", "_min_targets_alt", "_max_targets_alt", "_loglos", "_deltaz", "_list", "_elapsed", "_org", "_deltat", "_target"];
			 _commdisplay = _this select 0;
			 _trigger = _this select 1;
			 _min_targets_alt = _this select 2;
			 _max_targets_alt = _this select 3;
			 _deltaz = _this select 4;
			 
			 _loglos = "logic" createVehicleLocal [0,0,0];
			 _deltat = 2;
			 mando_lrr_target = objNull;
			 _org = mando_lrr_unit;			 
			 Sleep 1;
			 _elapsed = (dayTime * 3600);				 
			 while {!isNull _commdisplay} do
			 {				
				if (!isNull mando_lrr_target) then
				{
				   _deltat = 0;
				
					(_commdisplay displayCtrl 23951) ctrlSetStructuredText parseText 
						format ["Target Locked On<br />Speed: %1 Km/h<br />Dist: %2 m<br />Alt AGL: %3 m<br />Alt Rel: %4 m<br />Climb: %5 m/s", 
							floor (speed mando_lrr_target), floor(mando_lrr_target distance mando_lrr_unit), 
							floor((getPos mando_lrr_target) select 2), floor(((getPosASL mando_lrr_target) select 2)-((getPosASL mando_lrr_unit) select 2)), 
							floor(velocity mando_lrr_target select 2)
							];

				}
				else
				{
					(_commdisplay displayCtrl 23951) ctrlSetStructuredText parseText "";
				   _deltat = 2;
				};
				
				if ((dayTime * 3600) > (_elapsed + _deltat)) then
				{
					_elapsed = (dayTime * 3600);					 
					_list = [];

					// Add current target here, if exist
					if (!isNull mando_lrr_target) then
					{
						if (((getPos mando_lrr_target select 2) > _min_targets_alt) &&
						    ((getPos mando_lrr_target select 2) < _max_targets_alt) &&
							(alive mando_lrr_target)) then
						{
							if ([_loglos, _org, mando_lrr_target, 20, _deltaz] call mando_check_los) then
							{
							   _list = [mando_lrr_target]; 
							}
							else
							{
								mando_lrr_target = objNull;
								{
									_x setVariable ["mando_target_auto", objNull, true];
								} forEach (mando_lrr_unit getVariable "mando_lrr_units");
							   
							};
						}
						else
						{
							mando_lrr_target = objNull;
							{
								_x setVariable ["mando_target_auto", objNull, true];
							} forEach (mando_lrr_unit getVariable "mando_lrr_units");							
						};
					}
					else
					{
					// Add all missiles missiles here <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
					// Que esten en rango
						{
							if ((_x distance _org) < mando_lrr_max_range) then 
							{
								if ([_loglos, _org, _x, 20, _deltaz] call mando_check_los) then
								{
									_list = _list + [_x]
								};
							};
						} forEach mando_detmissiles;
					
						{
						   if ((count _list) < 10) then
						   {
							  if (fuel _x < 1) then
							  {
								 if (isEngineOn _x) then
								 {
									   if (((getPos _x select 2) > _min_targets_alt) &&
										   ((getPos _x select 2) < _max_targets_alt)) then
									   {
										  if ([_loglos, _org, _x, 20, _deltaz] call mando_check_los) then
										  {
											 _list = _list + [_x];
										  };
									   };
								 };
							  };
						   };
						} forEach list _trigger;

					};
					mando_tv_targets = [];
					mando_tv_targets = mando_tv_targets + _list;
				};				   
				Sleep 1;
			};	
			deleteVehicle _loglos;
		  };

		  _deltat = 1;
		  while {!isNull _display} do
		  {
				_trigger setPos getPos mando_lrr_unit;
				_trigger setTriggerArea [mando_lrr_max_range, mando_lrr_max_range, 0, false];

				_list = [];
				if (mando_lrr_state) then
				{
				   _list = _list + mando_tv_targets;
				};

				_poss = [-2, -2, 0, 0];
				_posl = [-2, -2, 0, 0];
				_posd = [-2, -2, 0, 0];
				_colorl = [0,0,0,0];
				if (count _list > 0) then
				{
				  for [{_i=0},{_i<10},{_i=_i+1}] do
				  { 
					 _poss = [-2, -2, 0, 0];
					 _colorl = [0,0,0,0];
					 if (_i < count _list) then
					 {
						_target = _list select _i;
						if (!isNull _target) then
						{
// Max Rad Y = 0.968/2 -> mando_lrr_range
// Max Rad X = 0.968/2 * 3/4

						   _pos = mando_lrr_unit worldToModel (getPos _target);
						   _dist = sqrt ((_pos select 0)^2 + (_pos select 1)^2);

							_ang = ((getPos _target select 0)-(getPos mando_lrr_unit select 0)) atan2 ((getPos _target select 1)-(getPos mando_lrr_unit select 1));
						   
						   if (_dist < mando_lrr_range) then
						   {
						   		_rads = (_dist * 0.968/2)/mando_lrr_range;
								_poss = [0.5 - 0.01*3/4 + sin(_ang)*_rads*3/4, 0.5 - 0.01 - cos(_ang)*_rads, 0.02*3/4, 0.02];
								_colorl = [0,1,0,1];								
						   };

						   if (_target == mando_lrr_target) then
						   {
							_rads = ((_dist * 0.968/2)/mando_lrr_range) min (0.968/2);
							_posl = [0.5+ sin(_ang)*_rads*3/4, 0.5 - cos(_ang)*_rads, 0,0];
							_posl = [0.5, 0.5, (_posl select 0)-0.5, (_posl select 1)-0.5];
							
								if (_dist < mando_lrr_range) then
								{
									_posd = [0.5+(_posl select 2), 0.5+(_posl select 3), sin(getDir _target)*0.03, -cos(getDir _target)*0.03*3/4];
								};
						   };						   
						};
					 };
					 (_rects select _i) ctrlSetTextColor _colorl;
					 (_rects select _i) ctrlSetPosition _poss;
					 (_rects select _i) ctrlCommit 0;
				  };
				}
				else
				{
					{
						_x ctrlSetPosition _poss;
						_x ctrlCommit 0;
						_x ctrlSetTextColor [0,0,0,0];
					} forEach _rects;
				};
				
				(_display displayCtrl 22120) ctrlSetPosition _posl;
				(_display displayCtrl 22120) ctrlCommit 0;
				(_display displayCtrl 22119) ctrlSetPosition _posd;
				(_display displayCtrl 22119) ctrlCommit 0;

				if (mando_lrr_state && (isNull mando_lrr_target)) then
				{
					playSound "mando_radar2";
				};

				
				sleep _deltat;
				// List ready
				if (!isNull mando_lrr_target) then
				{
				   _deltat = 0.1;
				}
				else
				{
				   _deltat = 1;
				};
				
		  };
		  
		  deleteVehicle _trigger;
		  mandotarget_disp_on = mandotarget_disp_on_old;
		  mandotarget_disp_on = true;
		  
		  	mando_radar_off = mando_lrr_unit;
			publicVariable "mando_radar_off";
			if (mando_lrr_state) then
			{
				mando_lrr_unit say3D "mando_radaroff";
			};
		};
   };


   case "onMouseZChanged":
   {
      if (((_this select 1) select 1) > 0) then
      {
		mando_lrr_range = (mando_lrr_range*2) min mando_lrr_max_range;
	  }
      else
      {
		mando_lrr_range = (mando_lrr_range/2) max 1000;
      };
   };

   case "onCameraClick":
   {
   // 2 y 3
      if (((_this select 1) select 1) == 0) then
      {
		_display = findDisplay 23900;
		_mindist = 999999;
		_target = objNull;
		for [{_i=0},{_i<10},{_i=_i+1}] do
		{ 
			_pos = ctrlPosition (_display displayCtrl (_i + 23930));
			_dist = sqrt(
				(((_this select 1) select 2)-((_pos select 0)+0.01))^2+
				(((_this select 1) select 3)-((_pos select 1)+0.01))^2);
			if (_dist < _mindist) then
			{
				if (_dist < 0.02) then
				{
					_target = mando_tv_targets select _i;
					_mindist = _dist;
				};
			};
		};
		mando_lrr_target = _target;
		{
			_x setVariable ["mando_target_auto", mando_lrr_target, true];
		} forEach (mando_lrr_unit getVariable "mando_lrr_units");
		
		if (!isNull mando_lrr_target) then
		{
		    mando_lockedon= mando_lrr_target;
			publicVariable "mando_lockedon";
			
			playSound "mando_target1";
		};
      };
   };


   case "ZOOM_IN":
   {

      if (mando_cam_scale > 0.2) then
      {
         mando_cam_scale = mando_cam_scale - 0.1;
      };

      if (mando_tvcam_scale > 0.05) then
      {
         mando_tvcam_scale = mando_tvcam_scale - 0.05;
      };
   };


   case "ZOOM_OUT":
   {
      if (mando_cam_scale < 1) then
      {
         mando_cam_scale = mando_cam_scale + 0.1;
      };

      if (mando_tvcam_scale < 1) then
      {
         mando_tvcam_scale = mando_tvcam_scale + 0.05;
      };
   };

	case "CALL_LRR_ONOFF":
	{
		if (!mando_lrr_state) then
		{
			if (ctrlEnabled ((findDisplay 23900) displayCtrl 23925)) then
			{		
				[]spawn
				{
					((findDisplay 23900) displayCtrl 23925) ctrlEnable false;
					mando_lrr_unit say3D "mando_radaron";
					Sleep 5;
					mando_lrr_state = true;
					mando_radar_on = mando_lrr_unit;
					publicVariable "mando_radar_on";
					((findDisplay 23900) displayCtrl 23925) ctrlEnable true;
				};
			};
		}
		else
		{
			if (ctrlEnabled ((findDisplay 23900) displayCtrl 23925)) then
			{
				[]spawn
				{
					((findDisplay 23900) displayCtrl 23925) ctrlEnable false;
					mando_lrr_unit say3D "mando_radaroff";
					mando_lrr_state = false;
					{
						_x setVariable ["mando_target_auto", objNull, true];
					} forEach (mando_lrr_unit getVariable "mando_lrr_units");
					mando_lrr_target = objNull;
					mando_radar_off = mando_lrr_unit;
					publicVariable "mando_radar_off";
					sleep 4;
					((findDisplay 23900) displayCtrl 23925) ctrlEnable true;				
				};
			};
		};
	};

	case "CALL_LRR_SAM":
	{
		mando_lrr_sam = _this select 1;
	};

	case "CALL_LRR_ZOOM":
	{
		if (mando_lrr_fov == 1) then
		{
			mando_lrr_fov = 0.09;
		}
		else
		{
			mando_lrr_fov = 1;
		};
	};

	
	case "CALL_LRR_ENG":
	{	
		if (((mando_lrr_unit getVariable "mando_lrr_units") select mando_lrr_sam) getVariable "mando_auto_allowed") then
		{
			((mando_lrr_unit getVariable "mando_lrr_units") select mando_lrr_sam) setVariable ["mando_auto_allowed", false, true];		
		}
		else
		{
			((mando_lrr_unit getVariable "mando_lrr_units") select mando_lrr_sam) setVariable ["mando_auto_allowed", true, true];
		};
	};

	case "CALL_LRR_IFF":
	{
		if (side mando_lrr_target == side player) then
		{
			playSound "mando_target1";
		}
		else
		{
			playSound "mando_denied"
		};
	};

	
	case "CALL_LRR_CAM":
	{
		if (mando_lrr_camera < 2) then
		{
		   mando_lrr_camera = mando_lrr_camera + 1;
		}
		else
		{
		   mando_lrr_camera = 0;
		};
		
		if (mando_lrr_camera > 0) then
		{
			((findDisplay 23900) displayCtrl 23902) ctrlSetBackgroundColor [0,0,0,0]; 
		}
		else
		{
			((findDisplay 23900) displayCtrl 23902) ctrlSetBackgroundColor [0,0,0,1]; 		
		};
	};

	case "CALL_LRR_HELP":
	{	
      if (ctrlVisible 23924) then
      {
         ((findDisplay 23900) displayCtrl 23924) ctrlShow false;
         []spawn
         { 
            setMousePosition [0.5, 0.5];
         };
      }
      else
      {
         ((findDisplay 23900) displayCtrl 23924) ctrlShow true;
         ((findDisplay 23900) displayCtrl 23924) htmlLoad "mando_missiles\lrr\lrr_help.html";
      };
	};
	
   case "onKeyDown":
   {      
      switch ((_this select 1) select 1) do
      {
         case 59: // F1 Select Launcher 1
         {
			["CALL_LRR_SAM", 0] call mando_missile_lrr;
         };

         case 60: // F2 Select Launcher 2
         {
			["CALL_LRR_SAM", 1] call mando_missile_lrr;
         };

         case 61: // F3 Select Launcher 3
         {
			["CALL_LRR_SAM", 2] call mando_missile_lrr;
         };
		 
         case 62: // F4 ENGAGEMENT ALLOWED YES/NO
         {
			["CALL_LRR_ENG", []] call mando_missile_lrr;
         };

         case 63: // F5 IFF
         {
			["CALL_LRR_IFF", []] call mando_missile_lrr;
         };
		 		 
         case 64: // F6 ON/OFF
         {
            ["CALL_LRR_ONOFF", []] call mando_missile_lrr;
         };

         case 65: // F7 CAMERA
         {
            ["CALL_LRR_CAM", []] call mando_missile_lrr;
         };

         case 66: // F8 Zoom toggle
         {
            ["CALL_LRR_ZOOM", []] call mando_missile_lrr;
         };

         case 67: // F9 HELP
         {
            ["CALL_LRR_HELP", []] call mando_missile_lrr;
         };
		 
         default 
         {
// Down 80
// Up   72
// Left 75
// Right 77
// UR 73
// UL 71
// DR 81
// DL 79
// LOCK 76 
//            titleText [format["\n%1", _this], "PLAIN DOWN"];
         };
      };
   };   


   default {};
};

if (_event == "onKeyDown") then
{
   false
}
else
{
   true
};