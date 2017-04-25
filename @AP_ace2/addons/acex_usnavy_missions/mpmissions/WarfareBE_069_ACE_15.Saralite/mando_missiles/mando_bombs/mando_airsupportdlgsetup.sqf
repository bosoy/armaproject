/*********************************************************************************
   mando_airsupportdlgsetup.sqf v1.1
   by Mandoble, September 2008

   Creates and handles the air support console setup/info. From this console you may types of planes, vehicles, etc used in support missions.

*********************************************************************************/


private ["_event", "_params", "_display", "_item", "_opt", "_i", "_j", "_nitems"];

_event = _this select 0;
_params = _this select 1;
_display = _params select 0;

switch (_event) do
{
   case "onLoad":
   {
      (_display displayCtrl 100) ctrlSetText (mando_missile_path+"mando_bombs\laptop.paa");
      (_display displayCtrl 24004) ctrlSetStructuredText (parseText mando_airsupport_info);


      for [{_i=0},{_i < 5},{_i=_i+1}] do
      {
         (_display displayCtrl 24005+_i*2) ctrlSetText (call compile format["mando_airsupport_opt%1_text", _i+1]);
         {
            (_display displayCtrl 24006+_i*2) lbAdd _x;
         } forEach (call compile format["mando_airsupport_opt%1_array", _i+1]);

         _nitems = lbSize (_display displayCtrl 24006+_i*2);
         for [{_j=0},{_j < _nitems},{_j=_j+1}] do
         {
            if (((_display displayCtrl 24006+_i*2) lbText _j) == (call compile format["mando_airsupport_opt%1_selected", _i+1])) then
            {
               (_display displayCtrl 24006+_i*2) lbSetCurSel _j;
            };
         };
      };
   };

   case "onItemChanged1":
   {
      _item = (_params select 0) lbText (_params select 1);
      mando_airsupport_opt1_selected = _item;
      [_item] spawn mando_airsupport_opt1_action;
   };

   case "onItemChanged2":
   {
      _item = (_params select 0) lbText (_params select 1);
      mando_airsupport_opt2_selected = _item;
      [_item] spawn mando_airsupport_opt2_action;
   };

   case "onItemChanged3":
   {
      _item = (_params select 0) lbText (_params select 1);
      mando_airsupport_opt3_selected = _item;
      [_item] spawn mando_airsupport_opt3_action;
   };

   case "onItemChanged4":
   {
      _item = (_params select 0) lbText (_params select 1);
      mando_airsupport_opt4_selected = _item;
      [_item] spawn mando_airsupport_opt4_action;
   };

   case "onItemChanged5":
   {
      _item = (_params select 0) lbText (_params select 1);
      mando_airsupport_opt5_selected = _item;
      [_item] spawn mando_airsupport_opt5_action;
   };

   default {};
};

true