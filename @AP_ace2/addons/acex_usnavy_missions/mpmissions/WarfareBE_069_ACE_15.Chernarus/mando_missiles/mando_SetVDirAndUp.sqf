/* mando_SetVDirAndUp.sqf 1.0
   August 2009, by Mandoble

   Sets the vectorDir and vectorUp of indicated object passing the object and one of these:

   Horizontal direction and vertical inclination
   or
   a direction vector

   Compile it in your init.sqf in order to use it as function this way:
   mando_setVectorDirAndUp = compile (preprocessFileLineNumbers "mando_SetVectorDirAndUp.sqf");


   Usage example:

   // Plane heading South and noseup 45 degree (passing direction and vert inclination as parameters)
   [myplane, 180, 45] call mando_setVectorDirAndUp;

   // Plane heading West and 45 degree nose down (passing dir vector as parameter)
   [myplane, [0.5,0,0.5]] call mando_setVectorDirAndUp;
*/

private["_obj", "_angh", "_angv", "_vdir", "_angvu", "_anghu", "_upc"];

_obj  = _this select 0;
if (count _this == 2) then
{
   _vdir = _this select 1;
   _angv = asin(_vdir select 2);
}
else
{
   _angh = _this select 1;
   _angv = _this select 2;
   _vdir = [sin(_angh)*cos(_angv),cos(_angh)*cos(_angv), sin(_angv)];
};

_angvu = _angv + 90;
if (_angvu > 90) then
{
   _angvu = 90 - _angv;
   _anghu = _angh + 180;
}
else
{
   _anghu = _angh;
};

_upc = [sin(_anghu)*cos(_angvu),cos(_anghu)*cos(_angvu),sin(_angvu)];
_obj setVectorDirAndUp [_vdir, _upc];
true
