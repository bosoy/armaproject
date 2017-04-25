private["_params", "_cmd_script", "_next_params"];
_params = _this select 3;
_cmd_script = _params select 0;
_next_params = _params select 1;

mando_mcc_custom_script = "";
[_this select 0, _this select 1, _this select 2, _next_params] exec _cmd_script;
Sleep 1;
if (mando_mcc_custom_script != "") then
{
   if (!dialog) then
   {
      Sleep 1; 
   };
   if (dialog) then
   {
      []execVM mando_mcc_custom_script;
   };
};