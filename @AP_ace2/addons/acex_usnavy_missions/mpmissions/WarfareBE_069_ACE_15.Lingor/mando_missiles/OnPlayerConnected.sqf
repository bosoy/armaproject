private["_uid", "_varname"];
_uid = _this select 2;
_varname = format["mando_missile_init_%1", _uid];
Sleep 10;
if (isNil _varname) then
{
   hint format["%1 joins without MMA", _varname];
};