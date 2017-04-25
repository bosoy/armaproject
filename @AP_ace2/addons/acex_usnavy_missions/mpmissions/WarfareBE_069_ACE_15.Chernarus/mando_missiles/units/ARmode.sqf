/* ARmode.sqf
By Mandoble March 2007


*/
_unit = vehicle player;
mando_missileidx = (mando_missileidxbase select 1) select 0;
_unit setVariable ["target_types", ["REMOTE"]];
_unit setVariable ["current_target", objNull];
if (!isNull (uiNameSpace getVariable "mandotarget_disp")) then
{
   ((uiNameSpace getVariable "mandotarget_disp") displayCtrl 108) ctrlSetText "Remote";
}
else
{
   titleText["Switching to Remote Mode", "PLAIN DOWN"];
};
