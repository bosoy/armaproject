/*mando chaffflares
mando_chaffflares2.sqf v1.2
August 2009 Mandoble
Flares effects by Maddmatt, already included in ArmA 2 Ca\Data\ParticleEffects\SCRIPTS\muzzle

Generates a chaff or flares "clouds" able to attract mando_missile missiles aproaching in mode 2 (active mode)

DO NOT EXECUTE THIS SCRIPT MANUALLY
*/

private ["_maxspd", "_mass", "_vol", "_rubb", "_launcher", "_type", "_pos", "_drop1", "_script", "_color", "_size", "_i", "_numdrops", "_angv", "_angh", "_rad", "_radv", "_radh", "_vel", "_vell"];

_maxspd = 10;
_mass  = 1.275 + 0.3;
_vol   = 1.0;
_rubb  = 1;
_launcher = objNull;
_type = -1;
_pos = [0,0,0];
_drop1 = "";
_script = "";
_color = [[1,1,1,1]];
_size = [1.5, 3.5];
_i = 0;
_numdrops = 0;
_angv = 0;
_angh = 0;
_rad  = 0;
_radv = 0;
_radh = 0;
_vel = [0,0,0];
_vell = [0,0,0];

while {true} do
{
   waitUntil {mando_missilechaffdraw != -1};
   _launcher = mando_missilechafflauncher;
   _type     = mando_missilechaffdraw;
   mando_missilechaffdraw = -1;


   [_launcher, _type] spawn
   {
      private ["_launcher", "_type", "_flare", "_sm", "_sp", "_li", "_to_delete", "_var"];
      _launcher = _this select 0;
      _type = _this select 1; 
      _launcher say3D "mando_flares";

      _var = _launcher getVariable "mando_flares_script";

      if (isNil "_var") then
      {
         if (_launcher isKindof "Helicopter") then
         {
            [_launcher, _type]execVM mando_missile_path+"mando_chaffflaredraw_chopper.sqf";
         }
         else
         {
            _to_delete = [];
            for [{_i = 0},{_i < ((random 3)+1)},{_i = _i + 1}] do
            {         
               _flare="FlareCountermeasure" createvehiclelocal (_launcher modelToWorld [0, -3, -2]);
               _flare SetVelocity [-(vectorDir _launcher select 0)*30 + (velocity _launcher select 0),-(vectorDir _launcher select 1)*30 + (velocity _launcher select 1),-(vectorDir _launcher select 2)*30 +(velocity _launcher select 2)]; 
  
               _sm = "#particlesource" createVehicleLocal getpos _flare;
               _sm setParticleRandom [0.5, [0.3, 0.3, 0.3], [0.5, 0.5, 0.5], 0, 0.3, [0, 0, 0, 0], 0, 0,360];
               _sm setParticleParams [["\ca\Data\ParticleEffects\Universal\Universal", 16, 12, 8,0],
		"", "Billboard", 1, 3, [0, 0, 0],
		[0,0,0], 1, 1, 0.80, 0.5, [1.3,4],
		[[0.9,0.9,0.9,0.6], [1,1,1,0.3], [1,1,1,0]],[1],0.1,0.1,"","",_flare];	
               _sm setdropinterval 0.02;

               _sp = "#particlesource" createVehicleLocal getpos _flare;
               _sp setParticleRandom [0.03, [0.3, 0.3, 0.3], [1, 1, 1], 0, 0.2, [0, 0, 0, 0], 0, 0,360];
               _sp setParticleParams [["\ca\Data\ParticleEffects\Universal\Universal", 16, 13, 2,0],
		"", "Billboard", 1, 0.1, [0, 0, 0],
		[0,0,0], 1, 1, 0.80, 0.5, [1.5,0],
		[[1,1,1,-4], [1,1,1,-4], [1,1,1,-2],[1,1,1,0]],[1000],0.1,0.1,"","",_flare,360];	
               _sp setdropinterval 0.001;

               _li = "#lightpoint" createVehicleLocal getpos _flare;
               _li setLightBrightness 0.1;
               _li setLightAmbient[0.8, 0.6, 0.2];
               _li setLightColor[1, 0.5, 0.2];
               _li lightAttachObject [_flare, [0,0,0]];
               _to_delete = _to_delete + [_flare, _sm, _sp, _li];
               Sleep (0.1 + (random 0.25));
            };
            Sleep 4;
            {deleteVehicle _x} forEach _to_delete;
         };
      }
      else
      {
         [_launcher, _type] execVM _var;
      };
   };
};