/* ace_sys_dogtag | (c) 2008 by rocko */

private["_tagspawn"];
_tagspawn = "WeaponHolder" createVehicle (position _this);
_tagspawn addMagazineCargo ["ACE_DogTag",1];
_tagspawn setPos (_this modelToWorld [0,0,0]);
