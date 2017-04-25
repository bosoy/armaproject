/* MMA HUD customization - Engage Multiple Targets Mandoble - Feb 2011 */


private["_veh"];
_veh = vehicle player;

   [] spawn  
   {
      Sleep 4; 
      while {!mando_exit_hud} do
      {
         if (!isNull (UINameSpace GetVariable "mandotarget_disp")) then
         {
			if (mando_hud_missile > -1) then
			{
				_weapon = (mando_missileidxbase select mando_hud_missile) select 1;
				if (_weapon in ["GLT_AIM120Launcher","GLT_AIM120_Launcher"]) then
				{
				   ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 78) CtrlSetTextColor [1.0, 1.0, 1.0, 0.9];
				   ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 78) CtrlSetStructuredText ParseText Format ["<t size='1.2'>Engage Multi: %1</t>", mando_keyspecialname];
				   ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 78) CtrlSetPosition [SafeZoneX + 0.0125, SafeZoneY + SafeZoneH - 0.1875, 0.2250, 0.2000];
				   ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 78) CtrlCommit 0;
				}
				else
				{
				   ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 78) CtrlSetTextColor [1.0, 1.0, 1.0, 0];
				};
			}
			else
			{
				((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 78) CtrlSetTextColor [1.0, 1.0, 1.0, 0];
			};
         };
         Sleep 1; 
      };
   };


while {!mando_exit_hud} do
{
   if (mando_key_pressed == mando_keyspecial) then
   {	
      _continue = false;
      if (!isNull (UINameSpace GetVariable "mandotarget_disp") && (mando_hud_missile > -1)) then
      {
         _weapon = (mando_missileidxbase select mando_hud_missile) select 1;
         if (_weapon in ["GLT_AIM120Launcher","GLT_AIM120_Launcher"]) then
         {
            _continue = true;
         };
      };

      if (_continue) then
      {
	     mando_key_pressed = -1;
		// Engage Multi
		_targets = [];
		_targets = _targets + mando_hud_targets - ["A"];
         for [{_i=0},{_i<4},{_i=_i+1}] do
		 {
			if (_i < (count _targets)) then
			{
				vehicle player setVariable ["mando_current_target", _targets select _i];
				Sleep 1;
				[displayNull, mando_keyfire] spawn mando_hud_key_handler;
				Sleep 1;
			};
		 };
      };
   };

   Sleep 0.5;
};