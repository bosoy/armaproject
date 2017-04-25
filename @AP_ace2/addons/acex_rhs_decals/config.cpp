////////////////////////////////////////////////////////////////////
//Produced from mikero's Dos Tools using dll 3.22
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class rhs_decals : config.bin{
class CfgPatches
{
 class RHS_Decals
 {
  units[] = {"RHSDecalsNeckBanner","RHSDecalsWallFlag90x135"};
  weapons[] = {};
  requiredVersion = 1.0;
  requiredAddons[] = {};
 };
};
class CfgVehicleClasses
{
 class RHSObjectsDecals
 {
  displayName = "$STR_RHS_DECALS_CLASS_NAME";
 };
};
class CfgVehicles
{
 class NonStrategic;
 class Thing;
 class RHSSmallItems: Thing
 {
  vehicleClass = "RHSObjectsDecals";
  destrType = "DestructNo";
  animated = 0;
  mapSize = 2;
 };
 class RHSSmallItems_NoInteractive: NonStrategic
 {
  vehicleClass = "RHSObjectsDecals";
  destrType = "DestructNo";
  animated = 0;
  mapSize = 2;
 };
 class RHSDecalsNeckBanner: RHSSmallItems
 {
  scope = 0;
  animated = 0;
  model = "\RHS_Decals\RHSNeckBanner";
  icon = "\ca\data\data\Unknown_object.paa";
  displayName = "$STR_RHS_DECALS_NECK_BANNER";
  accuracy = 0.2;
  armor = 50;
 };
 class RHSDecalsWallFlag90x135: RHSSmallItems
 {
  scope = 2;
  animated = 0;
  model = "\RHS_Decals\Objects\RHS_Flag";
  icon = "\ca\data\data\Unknown_object.paa";
  displayName = "$STR_RHS_DECALS_WALLFLAG90x135";
  accuracy = 0.2;
  armor = 50;
 };
};
//};

