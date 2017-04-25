/*mando chaffflaresdraw_chopper.sqf
v1.0
Nov 2009 Mandoble
Flares effects by Maddmatt, already included in ArmA 2 Ca\Data\ParticleEffects\SCRIPTS\muzzle

Generates a chaff or flares "clouds" able to attract mando_missile missiles aproaching in mode 2 (active mode)

DO NOT EXECUTE THIS SCRIPT MANUALLY
*/

private ["_launcher", "_type", "_flare", "_sm", "_sp", "_li", "_to_delete", "_var", "_angs", "_vel", "_pos1", "_pos2"];
_launcher = _this select 0;
_type = _this select 1; 
_launcher say3D "mando_flares";
_to_delete = [];         
_angs = [45, 60, 90, 160, 200, 270, 300, 315];
 

{ 
   _pos1 = _launcher modelToWorld [(sin _x)*5, -10+(cos _x)*5, -2];
   _flare="FlareCountermeasure" createvehiclelocal _pos1;

   _flare setPos _pos1;

   _pos1 = _launcher modelToWorld [(sin _x)*20, (cos _x)*20, 0];
   _pos2 = getPos _launcher;

   _vel = [((_pos1 select 0) - (_pos2 select 0)), ((_pos1 select 1) - (_pos2 select 1)),((_pos1 select 2) - (_pos2 select 2))];


   _flare SetVelocity _Vel; 
  
   _sm = "#particlesource" createVehicleLocal getpos _flare;
   _sm setParticleRandom [0.5, [0, 0, 0], [0, 0, 0], 0, 0.3, [0, 0, 0, 0], 0, 0, 360];
   _sm setParticleParams [["\ca\Data\ParticleEffects\Universal\Universal", 16, 12, 8,0],
		"", "Billboard", 1, 3, [0, 0, 0],
		[0,0,0], 1, 1, 0.80, 0.5, [1.3,4],
		[[0.9,0.9,0.9,0.6], [1,1,1,0.3], [1,1,1,0]],[1],0.1,0.1,"","",_flare];	
   _sm setdropinterval 0.02;

   _sp = "#particlesource" createVehicleLocal getpos _flare;
   _sp setParticleRandom [0.03, [0, 0, 0], [0, 0, 0], 0, 0.2, [0, 0, 0, 0], 0, 0, 360];
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
} forEach _angs;
Sleep 4;
{deleteVehicle _x} forEach _to_delete;
