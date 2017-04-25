private["_return"];


_return = false;
if (((_this select 0) select 1) in [mando_keyflare, mando_keyfire, mando_keylock, mando_keymode, mando_keyecm,mando_keyspecial]) then
{
   (_this select 0) spawn mando_hud_key_handler;
   if (((_this select 0) select 1) == mando_keylock) then
   {
      _return = true;
   };
};
_return