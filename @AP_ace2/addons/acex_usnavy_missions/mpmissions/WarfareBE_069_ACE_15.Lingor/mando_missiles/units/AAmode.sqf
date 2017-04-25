/* AAmode.sqf
By Mandoble March 2007


*/
_unit = vehicle player;
mando_missileidx = (mando_missileidxbase select 0) select 0;
_unit setVariable ["target_types", ["Air"]];
_unit setVariable ["current_target", objNull];
if (!isNull (uiNameSpace getVariable "mandotarget_disp")) then
{
   ((uiNameSpace getVariable "mandotarget_disp") displayCtrl 108) ctrlSetText "Air units";
}
else
{
   titleText["Switching to Air Mode", "PLAIN DOWN"];
};