////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Jul 04 15:01:14 2009 : Created on Sat Jul 04 15:01:14 2009
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class map_eu : config.bin{
class CfgPatches
{
	class MAP_EU
	{
		units[] = {};
		weapons[] = {};
		requiredAddons[] = {"CAData","CAMisc","CAMisc2","CAMisc3","CABuildings","CABuildings2","CAStructures","CASigns2","CARoads2","CARocks2","CAA10","CAAir","CAAir2","CAAir3","CAWheeled","CAWheeled2","CAWater2","CATracked","CACharacters2"};
		requiredVersion = 1.02;
	};
};
class CfgVehicleClasses
{
	class MAP_EUPlants
	{
		displayName = "MAP: EU-Plants";
	};
	class MAP_EURocks
	{
		displayName = "MAP: EU-Rocks";
	};
	class MAP_EURoads
	{
		displayName = "MAP: EU-Roads";
	};
	class MAP_EUSWalk
	{
		displayName = "MAP: EU-SWalks";
	};
	class MAP_EUHouses
	{
		displayName = "MAP: EU-Houses";
	};
	class MAP_EUIndus
	{
		displayName = "MAP: EU-Industry";
	};
	class MAP_EURail
	{
		displayName = "MAP: EU-Rails";
	};
	class MAP_EUMilitary
	{
		displayName = "MAP: EU-Military";
	};
	class MAP_EURuins
	{
		displayName = "MAP: EU-Ruins";
	};
	class MAP_EUWalls
	{
		displayName = "MAP: EU-Walls";
	};
	class MAP_EUMisc
	{
		displayName = "MAP: EU-Misc";
	};
	class MAP_EUSigns
	{
		displayName = "MAP: EU-Signs";
	};
	class MAP_EUInter
	{
		displayName = "MAP: EU-Interieur";
	};
	class MAP_EUWater
	{
		displayName = "MAP: EU-Water";
	};
};
class CfgVehicles
{
	class Static;
	class MAP_Plants_Base: Static
	{
		displayName = "";
		accuracy = 0.1;
		vehicleClass = "MAP_EUPlants";
		model = "";
		nameSound = "";
		animated = 0;
		simulation = "house";
		cost = 0;
		armor = 300;
		ladders[] = {};
		placement = "slope";
	};
	class MAP_Plants_DTr: MAP_Plants_Base
	{
		destrType = "DestructTree";
		accuracy = 1000;
		placement = "vertical";
	};
	class MAP_Plants_DNo: MAP_Plants_Base
	{
		destrType = "DestructNo";
		accuracy = 1000;
	};
	class MAP_Plants_DTe: MAP_Plants_Base
	{
		destrType = "DestructTent";
		accuracy = 1000;
	};
	class MAP_Plants_DBu: MAP_Plants_Base
	{
		destrType = "DestructBuilding";
		accuracy = 1000;
		class DestructionEffects
		{
			class HouseDestr
			{
				simulation = "destroy";
				type = "DelayedDestruction";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class MAP_c_autumn_flowers: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G c_autumn_flowers";
		icon = "\MAP_EU\icon\PG.paa";
		model = "\ca\plants2\clutter\c_autumn_flowers.p3d";
	};
	class MAP_c_blueBerry: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G c_blueBerry";
		icon = "\MAP_EU\icon\PG.paa";
		model = "\ca\plants2\clutter\c_blueBerry.p3d";
	};
	class MAP_c_caluna: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G c_caluna";
		icon = "\MAP_EU\icon\PG.paa";
		model = "\ca\plants2\clutter\c_caluna.p3d";
	};
	class MAP_c_deadGrassBunch: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G c_deadGrassBunch";
		icon = "\MAP_EU\icon\PG.paa";
		model = "\ca\plants2\clutter\c_deadGrassBunch.p3d";
	};
	class MAP_c_fern: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G c_fern";
		icon = "\MAP_EU\icon\PG.paa";
		model = "\ca\plants2\clutter\c_fern.p3d";
	};
	class MAP_c_fernTall: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G c_fernTall";
		icon = "\MAP_EU\icon\PG.paa";
		model = "\ca\plants2\clutter\c_fernTall.p3d";
	};
	class MAP_c_GrassAutumn: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G c_GrassAutumn";
		icon = "\MAP_EU\icon\PG.paa";
		model = "\ca\plants2\clutter\c_GrassAutumn.p3d";
	};
	class MAP_c_GrassAutumn_t: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G c_GrassAutumn_t";
		icon = "\MAP_EU\icon\PG.paa";
		model = "\ca\plants2\clutter\c_GrassAutumn_t.p3d";
	};
	class MAP_c_GrassAutumnBrown: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G c_GrassAutumnBrown";
		icon = "\MAP_EU\icon\PG.paa";
		model = "\ca\plants2\clutter\c_GrassAutumnBrown.p3d";
	};
	class MAP_c_grassBunch: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G c_grassBunch";
		icon = "\MAP_EU\icon\PG.paa";
		model = "\ca\plants2\clutter\c_grassBunch.p3d";
	};
	class MAP_c_GrassCrooked: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G c_GrassCrooked";
		icon = "\MAP_EU\icon\PG.paa";
		model = "\ca\plants2\clutter\c_GrassCrooked.p3d";
	};
	class MAP_c_GrassCrookedForest: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G c_GrassCrookedForest";
		icon = "\MAP_EU\icon\PG.paa";
		model = "\ca\plants2\clutter\c_GrassCrookedForest.p3d";
	};
	class MAP_c_GrassCrookedGreen: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G c_GrassCrookedGreen";
		icon = "\MAP_EU\icon\PG.paa";
		model = "\ca\plants2\clutter\c_GrassCrookedGreen.p3d";
	};
	class MAP_c_GrassDryLong: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G c_GrassDryLong";
		icon = "\MAP_EU\icon\PG.paa";
		model = "\ca\plants2\clutter\c_GrassDryLong.p3d";
	};
	class MAP_c_GrassTall: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G c_GrassTall";
		icon = "\MAP_EU\icon\PG.paa";
		model = "\ca\plants2\clutter\c_GrassTall.p3d";
	};
	class MAP_c_leaves: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G c_leaves";
		icon = "\MAP_EU\icon\PG.paa";
		model = "\ca\plants2\clutter\c_leaves.p3d";
	};
	class MAP_c_picea: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G c_picea";
		icon = "\MAP_EU\icon\PG.paa";
		model = "\ca\plants2\clutter\c_picea.p3d";
	};
	class MAP_c_PlantsAutumnForest: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G c_PlantsAutumnForest";
		icon = "\MAP_EU\icon\PG.paa";
		model = "\ca\plants2\clutter\c_PlantsAutumnForest.p3d";
	};
	class MAP_c_raspBerry: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G c_raspBerry";
		icon = "\MAP_EU\icon\PG.paa";
		model = "\ca\plants2\clutter\c_raspBerry.p3d";
	};
	class MAP_C_SmallLeafPlant: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G C_SmallLeafPlant";
		icon = "\MAP_EU\icon\PG.paa";
		model = "\ca\plants2\clutter\C_SmallLeafPlant.p3d";
	};
	class MAP_c_stubble: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G c_stubble";
		icon = "\MAP_EU\icon\PG.paa";
		model = "\ca\plants2\clutter\c_stubble.p3d";
	};
	class MAP_c_TreeSmallForest: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G c_TreeSmallForest";
		icon = "\MAP_EU\icon\PG.paa";
		model = "\ca\plants2\clutter\c_TreeSmallForest.p3d";
	};
	class MAP_c_weed2: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G c_weed2";
		icon = "\MAP_EU\icon\PG.paa";
		model = "\ca\plants2\clutter\c_weed2.p3d";
	};
	class MAP_c_weed3: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G c_weed3";
		icon = "\MAP_EU\icon\PG.paa";
		model = "\ca\plants2\clutter\c_weed3.p3d";
	};
	class MAP_c_WeedDead: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G c_WeedDead";
		icon = "\MAP_EU\icon\PG.paa";
		model = "\ca\plants2\clutter\c_WeedDead.p3d";
	};
	class MAP_c_WeedDead2: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G c_WeedDead2";
		icon = "\MAP_EU\icon\PG.paa";
		model = "\ca\plants2\clutter\c_WeedDead2.p3d";
	};
	class MAP_c_wideLeafPlant: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G c_wideLeafPlant";
		icon = "\MAP_EU\icon\PG.paa";
		model = "\ca\plants2\clutter\c_wideLeafPlant.p3d";
	};
	class MAP_cr_leaf: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G cr_leaf";
		icon = "\MAP_EU\icon\PG.paa";
		model = "\ca\plants2\clutter\cr_leaf.p3d";
	};
	class MAP_cr_leaf2: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G cr_leaf2";
		icon = "\MAP_EU\icon\PG.paa";
		model = "\ca\plants2\clutter\cr_leaf2.p3d";
	};
	class MAP_cr_leaf3: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G cr_leaf3";
		icon = "\MAP_EU\icon\PG.paa";
		model = "\ca\plants2\clutter\cr_leaf3.p3d";
	};
	class MAP_c_MushroomBabka: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G c_MushroomBabka";
		icon = "\MAP_EU\icon\PP.paa";
		model = "\ca\plants2\clutter\c_MushroomBabka.p3d";
	};
	class MAP_c_MushroomHorcak: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G c_MushroomHorcak";
		icon = "\MAP_EU\icon\PP.paa";
		model = "\ca\plants2\clutter\c_MushroomHorcak.p3d";
	};
	class MAP_c_MushroomMuchomurka: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G c_MushroomMuchomurka";
		icon = "\MAP_EU\icon\PP.paa";
		model = "\ca\plants2\clutter\c_MushroomMuchomurka.p3d";
	};
	class MAP_c_MushroomPrasivky: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "G c_MushroomPrasivky";
		icon = "\MAP_EU\icon\PP.paa";
		model = "\ca\plants2\clutter\c_MushroomPrasivky.p3d";
	};
	class MAP_p_articum: MAP_Plants_DTe
	{
		scope = 2;
		displayName = "G p_articum";
		icon = "\MAP_EU\icon\PM.paa";
		model = "\ca\plants2\plant\p_articum.p3d";
	};
	class MAP_p_carduus: MAP_Plants_DTe
	{
		scope = 2;
		displayName = "G p_carduus";
		icon = "\MAP_EU\icon\PM.paa";
		model = "\ca\plants2\plant\p_carduus.p3d";
	};
	class MAP_p_Helianthus: MAP_Plants_DTe
	{
		scope = 2;
		displayName = "G p_Helianthus";
		icon = "\MAP_EU\icon\PM.paa";
		model = "\ca\plants2\plant\p_Helianthus.p3d";
	};
	class MAP_p_heracleum: MAP_Plants_DTe
	{
		scope = 2;
		displayName = "G p_heracleum";
		icon = "\MAP_EU\icon\PM.paa";
		model = "\ca\plants2\plant\p_heracleum.p3d";
	};
	class MAP_p_Phragmites: MAP_Plants_DTe
	{
		scope = 2;
		displayName = "G p_Phragmites";
		icon = "\MAP_EU\icon\PM.paa";
		model = "\ca\plants2\plant\p_Phragmites.p3d";
	};
	class MAP_p_urtica: MAP_Plants_DTe
	{
		scope = 2;
		displayName = "G p_urtica";
		icon = "\MAP_EU\icon\PM.paa";
		model = "\ca\plants2\plant\p_urtica.p3d";
	};
	class MAP_pumpkin: MAP_Plants_DTe
	{
		scope = 2;
		displayName = "G pumpkin";
		icon = "\MAP_EU\icon\PM.paa";
		model = "\ca\plants2\plant\pumpkin.p3d";
	};
	class MAP_pumpkin2: MAP_Plants_DTe
	{
		scope = 2;
		displayName = "G pumpkin2";
		icon = "\MAP_EU\icon\PM.paa";
		model = "\ca\plants2\plant\pumpkin2.p3d";
	};
	class MAP_flower_01: MAP_Plants_DTe
	{
		scope = 2;
		displayName = "G flower_01";
		icon = "\MAP_EU\icon\PM.paa";
		model = "\CA\Structures\Furniture\Decoration\Flowers\flower_01.p3d";
	};
	class MAP_flower_02: MAP_Plants_DTe
	{
		scope = 2;
		displayName = "G flower_02";
		icon = "\MAP_EU\icon\PM.paa";
		model = "\CA\Structures\Furniture\Decoration\Flowers\flower_02.p3d";
	};
	class MAP_b_betulaHumilis: MAP_Plants_DTe
	{
		scope = 2;
		displayName = "B b_betulaHumilis";
		icon = "\MAP_EU\icon\PB.paa";
		model = "\ca\plants2\bush\b_betulaHumilis.p3d";
	};
	class MAP_b_canina2s: MAP_Plants_DTe
	{
		scope = 2;
		displayName = "B b_canina2s";
		icon = "\MAP_EU\icon\PB.paa";
		model = "\ca\plants2\bush\b_canina2s.p3d";
	};
	class MAP_b_corylus: MAP_Plants_DTe
	{
		scope = 2;
		displayName = "B b_corylus";
		icon = "\MAP_EU\icon\PB.paa";
		model = "\ca\plants2\bush\b_corylus.p3d";
	};
	class MAP_b_corylus2s: MAP_Plants_DTe
	{
		scope = 2;
		displayName = "B b_corylus2s";
		icon = "\MAP_EU\icon\PB.paa";
		model = "\ca\plants2\bush\b_corylus2s.p3d";
	};
	class MAP_b_craet1: MAP_Plants_DTe
	{
		scope = 2;
		displayName = "B b_craet1";
		icon = "\MAP_EU\icon\PB.paa";
		model = "\ca\plants2\bush\b_craet1.p3d";
	};
	class MAP_b_craet2: MAP_Plants_DTe
	{
		scope = 2;
		displayName = "B b_craet2";
		icon = "\MAP_EU\icon\PB.paa";
		model = "\ca\plants2\bush\b_craet2.p3d";
	};
	class MAP_b_pmugo: MAP_Plants_DTe
	{
		scope = 2;
		displayName = "B b_pmugo";
		icon = "\MAP_EU\icon\PB.paa";
		model = "\ca\plants2\bush\b_pmugo.p3d";
	};
	class MAP_b_prunus: MAP_Plants_DTe
	{
		scope = 2;
		displayName = "B b_prunus";
		icon = "\MAP_EU\icon\PB.paa";
		model = "\ca\plants2\bush\b_prunus.p3d";
	};
	class MAP_b_salix2s: MAP_Plants_DTe
	{
		scope = 2;
		displayName = "B b_salix2s";
		icon = "\MAP_EU\icon\PB.paa";
		model = "\ca\plants2\bush\b_salix2s.p3d";
	};
	class MAP_b_sambucus: MAP_Plants_DTe
	{
		scope = 2;
		displayName = "B b_sambucus";
		icon = "\MAP_EU\icon\PB.paa";
		model = "\ca\plants2\bush\b_sambucus.p3d";
	};
	class MAP_t_acer2s: MAP_Plants_DTr
	{
		scope = 2;
		displayName = "T t_acer2s";
		icon = "\MAP_EU\icon\PT.paa";
		model = "\ca\plants2\tree\t_acer2s.p3d";
	};
	class MAP_t_alnus2s: MAP_Plants_DTr
	{
		scope = 2;
		displayName = "T t_alnus2s";
		icon = "\MAP_EU\icon\PT.paa";
		model = "\ca\plants2\tree\t_alnus2s.p3d";
	};
	class MAP_t_betula1f: MAP_Plants_DTr
	{
		scope = 2;
		displayName = "T t_betula1f";
		icon = "\MAP_EU\icon\PT.paa";
		model = "\ca\plants2\tree\t_betula1f.p3d";
	};
	class MAP_t_betula2f: MAP_Plants_DTr
	{
		scope = 2;
		displayName = "T t_betula2f";
		icon = "\MAP_EU\icon\PT.paa";
		model = "\ca\plants2\tree\t_betula2f.p3d";
	};
	class MAP_t_betula2s: MAP_Plants_DTr
	{
		scope = 2;
		displayName = "T t_betula2s";
		icon = "\MAP_EU\icon\PT.paa";
		model = "\ca\plants2\tree\t_betula2s.p3d";
	};
	class MAP_t_betula2w: MAP_Plants_DTr
	{
		scope = 2;
		displayName = "T t_betula2w";
		icon = "\MAP_EU\icon\PT.paa";
		model = "\ca\plants2\tree\t_betula2w.p3d";
	};
	class MAP_t_carpinus2s: MAP_Plants_DTr
	{
		scope = 2;
		displayName = "T t_carpinus2s";
		icon = "\MAP_EU\icon\PT.paa";
		model = "\ca\plants2\tree\t_carpinus2s.p3d";
	};
	class MAP_t_fagus2f: MAP_Plants_DTr
	{
		scope = 2;
		displayName = "T t_fagus2f";
		icon = "\MAP_EU\icon\PT.paa";
		model = "\ca\plants2\tree\t_fagus2f.p3d";
	};
	class MAP_t_fagus2s: MAP_Plants_DTr
	{
		scope = 2;
		displayName = "T t_fagus2s";
		icon = "\MAP_EU\icon\PT.paa";
		model = "\ca\plants2\tree\t_fagus2s.p3d";
	};
	class MAP_t_fagus2W: MAP_Plants_DTr
	{
		scope = 2;
		displayName = "T t_fagus2W";
		icon = "\MAP_EU\icon\PT.paa";
		model = "\ca\plants2\tree\t_fagus2W.p3d";
	};
	class MAP_t_fraxinus2s: MAP_Plants_DTr
	{
		scope = 2;
		displayName = "T t_fraxinus2s";
		icon = "\MAP_EU\icon\PT.paa";
		model = "\ca\plants2\tree\t_fraxinus2s.p3d";
	};
	class MAP_t_fraxinus2W: MAP_Plants_DTr
	{
		scope = 2;
		displayName = "T t_fraxinus2W";
		icon = "\MAP_EU\icon\PT.paa";
		model = "\ca\plants2\tree\t_fraxinus2W.p3d";
	};
	class MAP_t_larix3f: MAP_Plants_DTr
	{
		scope = 2;
		displayName = "T t_larix3f";
		icon = "\MAP_EU\icon\PT.paa";
		model = "\ca\plants2\tree\t_larix3f.p3d";
	};
	class MAP_t_larix3s: MAP_Plants_DTr
	{
		scope = 2;
		displayName = "T t_larix3s";
		icon = "\MAP_EU\icon\PT.paa";
		model = "\ca\plants2\tree\t_larix3s.p3d";
	};
	class MAP_t_malus1s: MAP_Plants_DTr
	{
		scope = 2;
		displayName = "T t_malus1s";
		icon = "\MAP_EU\icon\PT.paa";
		model = "\ca\plants2\tree\t_malus1s.p3d";
	};
	class MAP_t_picea1s: MAP_Plants_DTr
	{
		scope = 2;
		displayName = "T t_picea1s";
		icon = "\MAP_EU\icon\PT.paa";
		model = "\ca\plants2\tree\t_picea1s.p3d";
	};
	class MAP_t_picea2s: MAP_Plants_DTr
	{
		scope = 2;
		displayName = "T t_picea2s";
		icon = "\MAP_EU\icon\PT.paa";
		model = "\ca\plants2\tree\t_picea2s.p3d";
	};
	class MAP_t_picea3f: MAP_Plants_DTr
	{
		scope = 2;
		displayName = "T t_picea3f";
		icon = "\MAP_EU\icon\PT.paa";
		model = "\ca\plants2\tree\t_picea3f.p3d";
	};
	class MAP_t_pinusN1s: MAP_Plants_DTr
	{
		scope = 2;
		displayName = "T t_pinusN1s";
		icon = "\MAP_EU\icon\PT.paa";
		model = "\ca\plants2\tree\t_pinusN1s.p3d";
	};
	class MAP_t_pinusN2s: MAP_Plants_DTr
	{
		scope = 2;
		displayName = "T t_pinusN2s";
		icon = "\MAP_EU\icon\PT.paa";
		model = "\ca\plants2\tree\t_pinusN2s.p3d";
	};
	class MAP_t_pinusS2f: MAP_Plants_DTr
	{
		scope = 2;
		displayName = "T t_pinusS2f";
		icon = "\MAP_EU\icon\PT.paa";
		model = "\ca\plants2\tree\t_pinusS2f.p3d";
	};
	class MAP_t_populus3s: MAP_Plants_DTr
	{
		scope = 2;
		displayName = "T t_populus3s";
		icon = "\MAP_EU\icon\PT.paa";
		model = "\ca\plants2\tree\t_populus3s.p3d";
	};
	class MAP_t_pyrus2s: MAP_Plants_DTr
	{
		scope = 2;
		displayName = "T t_pyrus2s";
		icon = "\MAP_EU\icon\PT.paa";
		model = "\ca\plants2\tree\t_pyrus2s.p3d";
	};
	class MAP_t_quercus2f: MAP_Plants_DTr
	{
		scope = 2;
		displayName = "T t_quercus2f";
		icon = "\MAP_EU\icon\PT.paa";
		model = "\ca\plants2\tree\t_quercus2f.p3d";
	};
	class MAP_t_quercus3s: MAP_Plants_DTr
	{
		scope = 2;
		displayName = "T t_quercus3s";
		icon = "\MAP_EU\icon\PT.paa";
		model = "\ca\plants2\tree\t_quercus3s.p3d";
	};
	class MAP_t_salix2s: MAP_Plants_DTr
	{
		scope = 2;
		displayName = "T t_salix2s";
		icon = "\MAP_EU\icon\PT.paa";
		model = "\ca\plants2\tree\t_salix2s.p3d";
	};
	class MAP_t_sorbus2s: MAP_Plants_DTr
	{
		scope = 2;
		displayName = "T t_sorbus2s";
		icon = "\MAP_EU\icon\PT.paa";
		model = "\ca\plants2\tree\t_sorbus2s.p3d";
	};
	class MAP_misc_FallenSpruce: MAP_Plants_DBu
	{
		scope = 2;
		displayName = "M misc_FallenSpruce";
		icon = "\MAP_EU\icon\PM.paa";
		model = "\ca\plants2\misc\misc_FallenSpruce.p3d";
	};
	class MAP_misc_FallenTree1: MAP_Plants_DBu
	{
		scope = 2;
		displayName = "M misc_FallenTree1";
		icon = "\MAP_EU\icon\PM.paa";
		model = "\ca\plants2\misc\misc_FallenTree1.p3d";
	};
	class MAP_misc_FallenTree2: MAP_Plants_DBu
	{
		scope = 2;
		displayName = "M misc_FallenTree2";
		icon = "\MAP_EU\icon\PM.paa";
		model = "\ca\plants2\misc\misc_FallenTree2.p3d";
	};
	class MAP_t_stub_picea: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "M t_stub_picea";
		icon = "\MAP_EU\icon\PM.paa";
		model = "\ca\plants2\tree\t_stub_picea.p3d";
	};
	class MAP_misc_stub1: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "M misc_stub1";
		icon = "\MAP_EU\icon\PM.paa";
		model = "\ca\plants2\misc\misc_stub1.p3d";
	};
	class MAP_misc_stub2: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "M misc_stub2";
		icon = "\MAP_EU\icon\PM.paa";
		model = "\ca\plants2\misc\misc_stub2.p3d";
	};
	class MAP_Misc_trunk_torzo: MAP_Plants_DNo
	{
		scope = 2;
		displayName = "M Misc_trunk_torzo";
		icon = "\MAP_EU\icon\PM.paa";
		model = "\ca\plants2\misc\Misc_trunk_torzo.p3d";
	};
	class MAP_Misc_trunk_water: MAP_Plants_DTr
	{
		scope = 2;
		displayName = "M Misc_trunk_water";
		icon = "\MAP_EU\icon\PM.paa";
		model = "\ca\plants2\misc\Misc_trunk_water.p3d";
	};
	class MAP_Rocks_Base: Static
	{
		displayName = "";
		accuracy = 0.1;
		vehicleClass = "MAP_EURocks";
		model = "";
		nameSound = "";
		animated = 0;
		simulation = "house";
		cost = 0;
		armor = 1000;
		ladders[] = {};
		placement = "vertical";
	};
	class MAP_Rocks_DNo: MAP_Rocks_Base
	{
		destrType = "DestructNo";
		accuracy = 1000;
	};
	class MAP_Rocks_DTe: MAP_Rocks_Base
	{
		destrType = "DestructTent";
		accuracy = 1000;
	};
	class MAP_Rocks_DTr: MAP_Rocks_Base
	{
		destrType = "DestructTree";
		accuracy = 1000;
	};
	class MAP_Rocks_DBu: MAP_Rocks_Base
	{
		destrType = "DestructBuilding";
		accuracy = 1000;
		class DestructionEffects
		{
			class HouseDestr
			{
				simulation = "destroy";
				type = "DelayedDestruction";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class MAP_R2_Stone: MAP_Rocks_DNo
	{
		scope = 2;
		displayName = "R R2_Stone";
		icon = "\MAP_EU\icon\R.paa";
		model = "\ca\rocks2\R2_Stone.p3d";
	};
	class MAP_R2_Boulder1: MAP_Rocks_DNo
	{
		scope = 2;
		displayName = "R R2_Boulder1";
		icon = "\MAP_EU\icon\R.paa";
		model = "\ca\rocks2\R2_Boulder1.p3d";
	};
	class MAP_R2_Boulder2: MAP_Rocks_DNo
	{
		scope = 2;
		displayName = "R R2_Boulder2";
		icon = "\MAP_EU\icon\R.paa";
		model = "\ca\rocks2\R2_Boulder2.p3d";
	};
	class MAP_R2_Rock1: MAP_Rocks_DNo
	{
		scope = 2;
		displayName = "R R2_Rock1";
		icon = "\MAP_EU\icon\R.paa";
		model = "\ca\rocks2\R2_Rock1.p3d";
	};
	class MAP_R2_RockTower: MAP_Rocks_DNo
	{
		scope = 2;
		displayName = "R R2_RockTower";
		icon = "\MAP_EU\icon\R.paa";
		model = "\ca\rocks2\R2_RockTower.p3d";
	};
	class MAP_R2_RockWall: MAP_Rocks_DNo
	{
		scope = 2;
		displayName = "R R2_RockWall";
		icon = "\MAP_EU\icon\R.paa";
		model = "\ca\rocks2\R2_RockWall.p3d";
	};
	class MAP_Roads_Base: Static
	{
		displayName = "";
		accuracy = 0.1;
		vehicleClass = "MAP_EURoads";
		model = "";
		nameSound = "";
		animated = 0;
		simulation = "house";
		cost = 0;
		armor = 1000;
		ladders[] = {};
	};
	class MAP_Roads_DNo: MAP_Roads_Base
	{
		destrType = "DestructNo";
		accuracy = 1000;
	};
	class MAP_Roads_DTe: MAP_Roads_Base
	{
		destrType = "DestructTent";
		accuracy = 1000;
	};
	class MAP_Roads_DTr: MAP_Roads_Base
	{
		destrType = "DestructTree";
		accuracy = 1000;
	};
	class MAP_Roads_DBu: MAP_Roads_Base
	{
		destrType = "DestructBuilding";
		accuracy = 1000;
		class DestructionEffects
		{
			class HouseDestr
			{
				simulation = "destroy";
				type = "DelayedDestruction";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class MAP_Bridge_stone_asf2_25: MAP_Roads_DBu
	{
		scope = 2;
		displayName = "B Bridge_stone_asf2_25";
		icon = "\MAP_EU\icon\B.paa";
		model = "\CA\Roads2\Bridge\Bridge_stone_asf2_25.p3d";
	};
	class MAP_bridge_asf1_25: MAP_Roads_DBu
	{
		scope = 2;
		displayName = "B bridge_asf1_25";
		icon = "\MAP_EU\icon\B.paa";
		model = "\CA\Roads2\Bridge\bridge_asf1_25.p3d";
	};
	class MAP_Bridge_wood_25: MAP_Roads_DBu
	{
		scope = 2;
		displayName = "B Bridge_wood_25";
		icon = "\MAP_EU\icon\B.paa";
		model = "\CA\Roads2\Bridge\Bridge_wood_25.p3d";
	};
	class Land_Dam_Conc_20;
	class MAP_Dam_Conc_20: Land_Dam_Conc_20
	{
		scope = 2;
		displayName = "B Dam_Conc_20";
		icon = "\MAP_EU\icon\B.paa";
		vehicleClass = "MAP_EURoads";
		accuracy = 1000;
	};
	class Land_Dam_ConcP_20;
	class MAP_Dam_ConcP_20: Land_Dam_ConcP_20
	{
		scope = 2;
		displayName = "B Dam_ConcP_20";
		icon = "\MAP_EU\icon\B.paa";
		vehicleClass = "MAP_EURoads";
		accuracy = 1000;
	};
	class Land_Dam_Barrier_40;
	class MAP_Dam_Barrier_40: Land_Dam_Barrier_40
	{
		scope = 2;
		displayName = "B Dam_Barrier_40";
		icon = "\MAP_EU\icon\B.paa";
		vehicleClass = "MAP_EURoads";
		accuracy = 1000;
	};
	class MAP_Misc_Drainage: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "B Misc_Drainage";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Misc\Misc_Drainage1\Misc_Drainage.p3d";
	};
	class MAP_asf1_0_2000: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf1_0 2000";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\asf1_0 2000.p3d";
	};
	class MAP_asf1_1_1000: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf1_1 1000";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\asf1_1 1000.p3d";
	};
	class MAP_asf1_25: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf1_25";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\asf1_25.p3d";
	};
	class MAP_asf1_12: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf1_12";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\asf1_12.p3d";
	};
	class MAP_asf1_6: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf1_6";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\asf1_6.p3d";
	};
	class MAP_asf1_6_crosswalk: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf1_6_crosswalk";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\asf1_6_crosswalk.p3d";
	};
	class MAP_asf1_6konec: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf1_6konec";
		icon = "\MAP_EU\icon\RE.paa";
		model = "\CA\Roads2\asf1_6konec.p3d";
	};
	class MAP_asf1_10_25: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf1_10 25";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\asf1_10 25.p3d";
	};
	class MAP_asf1_10_50: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf1_10 50";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\asf1_10 50.p3d";
	};
	class MAP_asf1_10_75: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf1_10 75";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\asf1_10 75.p3d";
	};
	class MAP_asf1_10_100: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf1_10 100";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\asf1_10 100.p3d";
	};
	class MAP_asf1_7_100: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf1_7 100";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\asf1_7 100.p3d";
	};
	class MAP_asf1_15_75: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf1_15 75";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\asf1_15 75.p3d";
	};
	class MAP_asf1_22_50: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf1_22 50";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\asf1_22 50.p3d";
	};
	class MAP_asf1_30_25: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf1_30 25";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\asf1_30 25.p3d";
	};
	class MAP_asf1_60_10: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf1_60 10";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\asf1_60 10.p3d";
	};
	class MAP_asf2_0_2000: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf2_0 2000";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\asf2_0 2000.p3d";
	};
	class MAP_asf2_1_1000: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf2_1 1000";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\asf2_1 1000.p3d";
	};
	class MAP_asf2_25: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf2_25";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\asf2_25.p3d";
	};
	class MAP_asf2_12: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf2_12";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\asf2_12.p3d";
	};
	class MAP_asf2_6: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf2_6";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\asf2_6.p3d";
	};
	class MAP_asf2_6_crosswalk: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf2_6_crosswalk";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\asf2_6_crosswalk.p3d";
	};
	class MAP_asf2_6konec: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf2_6konec";
		icon = "\MAP_EU\icon\RE.paa";
		model = "\CA\Roads2\asf2_6konec.p3d";
	};
	class MAP_asf2_10_25: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf2_10 25";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\asf2_10 25.p3d";
	};
	class MAP_asf2_10_50: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf2_10 50";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\asf2_10 50.p3d";
	};
	class MAP_asf2_10_75: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf2_10 75";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\asf2_10 75.p3d";
	};
	class MAP_asf2_10_100: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf2_10 100";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\asf2_10 100.p3d";
	};
	class MAP_asf2_7_100: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf2_7 100";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\asf2_7 100.p3d";
	};
	class MAP_asf2_15_75: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf2_15 75";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\asf2_15 75.p3d";
	};
	class MAP_asf2_22_50: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf2_22 50";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\asf2_22 50.p3d";
	};
	class MAP_asf2_30_25: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf2_30 25";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\asf2_30 25.p3d";
	};
	class MAP_asf2_60_10: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf2_60 10";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\asf2_60 10.p3d";
	};
	class MAP_asf3_0_2000: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf3_0 2000";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\asf3_0 2000.p3d";
	};
	class MAP_asf3_1_1000: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf3_1 1000";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\asf3_1 1000.p3d";
	};
	class MAP_asf3_25: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf3_25";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\asf3_25.p3d";
	};
	class MAP_asf3_12: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf3_12";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\asf3_12.p3d";
	};
	class MAP_asf3_6: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf3_6";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\asf3_6.p3d";
	};
	class MAP_asf3_6konec: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf3_6konec";
		icon = "\MAP_EU\icon\RE.paa";
		model = "\CA\Roads2\asf3_6konec.p3d";
	};
	class MAP_asf3_10_25: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf3_10 25";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\asf3_10 25.p3d";
	};
	class MAP_asf3_10_50: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf3_10 50";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\asf3_10 50.p3d";
	};
	class MAP_asf3_10_75: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf3_10 75";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\asf3_10 75.p3d";
	};
	class MAP_asf3_10_100: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf3_10 100";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\asf3_10 100.p3d";
	};
	class MAP_asf3_7_100: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf3_7 100";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\asf3_7 100.p3d";
	};
	class MAP_asf3_15_75: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf3_15 75";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\asf3_15 75.p3d";
	};
	class MAP_asf3_22_50: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf3_22 50";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\asf3_22 50.p3d";
	};
	class MAP_asf3_30_25: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf3_30 25";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\asf3_30 25.p3d";
	};
	class MAP_asf3_60_10: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S asf3_60 10";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\asf3_60 10.p3d";
	};
	class MAP_city_0_2000: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S city_0 2000";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\city_0 2000.p3d";
	};
	class MAP_city_1_1000: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S city_1 1000";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\city_1 1000.p3d";
	};
	class MAP_city_25: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S city_25";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\city_25.p3d";
	};
	class MAP_city_12: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S city_12";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\city_12.p3d";
	};
	class MAP_city_6: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S city_6";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\city_6.p3d";
	};
	class MAP_city_6_crosswalk: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S city_6_crosswalk";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\city_6_crosswalk.p3d";
	};
	class MAP_city_6konec: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S city_6konec";
		icon = "\MAP_EU\icon\RE.paa";
		model = "\CA\Roads2\city_6konec.p3d";
	};
	class MAP_city_10_25: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S city_10 25";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\city_10 25.p3d";
	};
	class MAP_city_10_50: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S city_10 50";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\city_10 50.p3d";
	};
	class MAP_city_10_75: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S city_10 75";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\city_10 75.p3d";
	};
	class MAP_city_10_100: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S city_10 100";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\city_10 100.p3d";
	};
	class MAP_city_7_100: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S city_7 100";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\city_7 100.p3d";
	};
	class MAP_city_15_75: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S city_15 75";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\city_15 75.p3d";
	};
	class MAP_city_22_50: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S city_22 50";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\city_22 50.p3d";
	};
	class MAP_city_30_25: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S city_30 25";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\city_30 25.p3d";
	};
	class MAP_city_60_10: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S city_60 10";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\city_60 10.p3d";
	};
	class MAP_grav_0_2000: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "W grav_0 2000";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\grav_0 2000.p3d";
	};
	class MAP_grav_1_1000: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "W grav_1 1000";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\grav_1 1000.p3d";
	};
	class MAP_grav_25: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "W grav_25";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\grav_25.p3d";
	};
	class MAP_grav_12: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "W grav_12";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\grav_12.p3d";
	};
	class MAP_grav_6: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "W grav_6";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\grav_6.p3d";
	};
	class MAP_grav_6konec: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "W grav_6konec";
		icon = "\MAP_EU\icon\RE.paa";
		model = "\CA\Roads2\grav_6konec.p3d";
	};
	class MAP_grav_10_25: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "W grav_10 25";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\grav_10 25.p3d";
	};
	class MAP_grav_10_50: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "W grav_10 50";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\grav_10 50.p3d";
	};
	class MAP_grav_10_75: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "W grav_10 75";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\grav_10 75.p3d";
	};
	class MAP_grav_10_100: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "W grav_10 100";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\grav_10 100.p3d";
	};
	class MAP_grav_7_100: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "W grav_7 100";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\grav_7 100.p3d";
	};
	class MAP_grav_15_75: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "W grav_15 75";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\grav_15 75.p3d";
	};
	class MAP_grav_22_50: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "W grav_22 50";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\grav_22 50.p3d";
	};
	class MAP_grav_30_25: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "W grav_30 25";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\grav_30 25.p3d";
	};
	class MAP_grav_60_10: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "W grav_60 10";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\grav_60 10.p3d";
	};
	class MAP_mud_0_2000: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "W mud_0 2000";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\mud_0 2000.p3d";
	};
	class MAP_mud_1_1000: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "W mud_1 1000";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\mud_1 1000.p3d";
	};
	class MAP_mud_25: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "W mud_25";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\mud_25.p3d";
	};
	class MAP_mud_12: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "W mud_12";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\mud_12.p3d";
	};
	class MAP_mud_6: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "W mud_6";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\mud_6.p3d";
	};
	class MAP_mud_6konec: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "W mud_6konec";
		icon = "\MAP_EU\icon\RE.paa";
		model = "\CA\Roads2\mud_6konec.p3d";
	};
	class MAP_mud_10_25: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "W mud_10 25";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\mud_10 25.p3d";
	};
	class MAP_mud_10_50: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "W mud_10 50";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\mud_10 50.p3d";
	};
	class MAP_mud_10_75: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "W mud_10 75";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\mud_10 75.p3d";
	};
	class MAP_mud_10_100: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "W mud_10 100";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\mud_10 100.p3d";
	};
	class MAP_mud_7_100: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "W mud_7 100";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\mud_7 100.p3d";
	};
	class MAP_mud_15_75: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "W mud_15 75";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\mud_15 75.p3d";
	};
	class MAP_mud_22_50: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "W mud_22 50";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\mud_22 50.p3d";
	};
	class MAP_mud_30_25: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "W mud_30 25";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\mud_30 25.p3d";
	};
	class MAP_mud_60_10: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "W mud_60 10";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\mud_60 10.p3d";
	};
	class MAP_kr_t_asf1_asf2: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S kr_t_asf1_asf2";
		icon = "\MAP_EU\icon\RCTL.paa";
		model = "\CA\Roads2\kr_t_asf1_asf2.p3d";
	};
	class MAP_kr_t_asf1_asf3: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S kr_t_asf1_asf3";
		icon = "\MAP_EU\icon\RCTL.paa";
		model = "\CA\Roads2\kr_t_asf1_asf3.p3d";
	};
	class MAP_kr_t_asf1_city: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S kr_t_asf1_city";
		icon = "\MAP_EU\icon\RCTL.paa";
		model = "\CA\Roads2\kr_t_asf1_city.p3d";
	};
	class MAP_kr_t_asf2_asf2: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S kr_t_asf2_asf2";
		icon = "\MAP_EU\icon\RCTL.paa";
		model = "\CA\Roads2\kr_t_asf2_asf2.p3d";
	};
	class MAP_kr_t_asf2_asf3: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S kr_t_asf2_asf3";
		icon = "\MAP_EU\icon\RCTL.paa";
		model = "\CA\Roads2\kr_t_asf2_asf3.p3d";
	};
	class MAP_kr_t_asf3_asf2: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S kr_t_asf3_asf2";
		icon = "\MAP_EU\icon\RCTL.paa";
		model = "\CA\Roads2\kr_t_asf3_asf2.p3d";
	};
	class MAP_kr_t_asf3_asf3: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S kr_t_asf3_asf3";
		icon = "\MAP_EU\icon\RCTL.paa";
		model = "\CA\Roads2\kr_t_asf3_asf3.p3d";
	};
	class MAP_kr_t_asf3_grav: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S kr_t_asf3_grav";
		icon = "\MAP_EU\icon\RCTL.paa";
		model = "\CA\Roads2\kr_t_asf3_grav.p3d";
	};
	class MAP_kr_t_asf3_mud: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S kr_t_asf3_mud";
		icon = "\MAP_EU\icon\RCTL.paa";
		model = "\CA\Roads2\kr_t_asf3_mud.p3d";
	};
	class MAP_kr_t_city_asf3: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S kr_t_city_asf3";
		icon = "\MAP_EU\icon\RCTL.paa";
		model = "\CA\Roads2\kr_t_city_asf3.p3d";
	};
	class MAP_kr_t_city_city: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S kr_t_city_city";
		icon = "\MAP_EU\icon\RCTL.paa";
		model = "\CA\Roads2\kr_t_city_city.p3d";
	};
	class MAP_kr_t_mud_mud: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S kr_t_mud_mud";
		icon = "\MAP_EU\icon\RCTL.paa";
		model = "\CA\Roads2\kr_t_mud_mud.p3d";
	};
	class MAP_kr_x_asf1_asf3: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S kr_x_asf1_asf3";
		icon = "\MAP_EU\icon\RCX.paa";
		model = "\CA\Roads2\kr_x_asf1_asf3.p3d";
	};
	class MAP_kr_x_asf1_city: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S kr_x_asf1_city";
		icon = "\MAP_EU\icon\RCX.paa";
		model = "\CA\Roads2\kr_x_asf1_city.p3d";
	};
	class MAP_kr_x_asf2_asf3: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S kr_x_asf2_asf3";
		icon = "\MAP_EU\icon\RCX.paa";
		model = "\CA\Roads2\kr_x_asf2_asf3.p3d";
	};
	class MAP_kr_x_asf2_city: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S kr_x_asf2_city";
		icon = "\MAP_EU\icon\RCX.paa";
		model = "\CA\Roads2\kr_x_asf2_city.p3d";
	};
	class MAP_kr_x_city_asf3: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S kr_x_city_asf3";
		icon = "\MAP_EU\icon\RCX.paa";
		model = "\CA\Roads2\kr_x_city_asf3.p3d";
	};
	class MAP_kr_x_city_city: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S kr_x_city_city";
		icon = "\MAP_EU\icon\RCX.paa";
		model = "\CA\Roads2\kr_x_city_city.p3d";
	};
	class MAP_kr_x_city_city_asf3: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "S kr_x_city_city_asf3";
		icon = "\MAP_EU\icon\RCX.paa";
		model = "\CA\Roads2\kr_x_city_city_asf3.p3d";
	};
	class MAP_runway_beton: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "A runway_beton";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\runway_beton.p3d";
	};
	class MAP_runway_beton_end1: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "A runway_beton_end1";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\runway_beton_end1.p3d";
	};
	class MAP_runway_beton_end2: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "A runway_beton_end2";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\runway_beton_end2.p3d";
	};
	class MAP_runway_dirt_1: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "A runway_dirt_1";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\runway_dirt_1.p3d";
	};
	class MAP_runway_dirt_2: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "A runway_dirt_2";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\runway_dirt_2.p3d";
	};
	class MAP_runway_dirt_3: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "A runway_dirt_3";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\runway_dirt_3.p3d";
	};
	class MAP_runway_end15: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "A runway_end15";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\runway_end15.p3d";
	};
	class MAP_runway_end33: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "A runway_end33";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\runway_end33.p3d";
	};
	class MAP_runway_main: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "A runway_main";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\runway_main.p3d";
	};
	class MAP_runway_main_40: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "A runway_main_40";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\runway_main_40.p3d";
	};
	class MAP_runway_poj_draha: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "A runway_poj_draha";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\runway_poj_draha.p3d";
	};
	class MAP_runway_poj_L_1: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "A runway_poj_L_1";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\runway_poj_L_1.p3d";
	};
	class MAP_runway_poj_L_1_end: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "A runway_poj_L_1_end";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\runway_poj_L_1_end.p3d";
	};
	class MAP_runway_poj_L_2: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "A runway_poj_L_2";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\runway_poj_L_2.p3d";
	};
	class MAP_runway_poj_L_2_end: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "A runway_poj_L_2_end";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\runway_poj_L_2_end.p3d";
	};
	class MAP_runway_poj_spoj: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "A runway_poj_spoj";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\runway_poj_spoj.p3d";
	};
	class MAP_runway_poj_spoj_2: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "A runway_poj_spoj_2";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\runway_poj_spoj_2.p3d";
	};
	class MAP_runway_poj_T_1: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "A runway_poj_T_1";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\runway_poj_T_1.p3d";
	};
	class MAP_runway_poj_T_2: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "A runway_poj_T_2";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\runway_poj_T_2.p3d";
	};
	class MAP_runwayold_40_main: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "A runwayold_40_main";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\runwayold_40_main.p3d";
	};
	class MAP_runwayold_80_dirt: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "A runwayold_80_dirt";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\runwayold_80_dirt.p3d";
	};
	class MAP_road_invisible: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "M road_invisible";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\road_invisible.p3d";
	};
	class MAP_road_invisible_t: MAP_Roads_DNo
	{
		scope = 2;
		displayName = "M road_invisible_t";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\road_invisible_t.p3d";
	};
	class MAP_Swalk_Base: Static
	{
		displayName = "";
		accuracy = 0.1;
		vehicleClass = "MAP_EUSWalk";
		model = "";
		nameSound = "";
		animated = 0;
		simulation = "house";
		cost = 0;
		armor = 1000;
		ladders[] = {};
		placement = "slope";
	};
	class MAP_Swalk_DNo: MAP_Swalk_Base
	{
		destrType = "DestructNo";
		accuracy = 1000;
	};
	class MAP_Swalk_DTe: MAP_Swalk_Base
	{
		destrType = "DestructTent";
		accuracy = 1000;
	};
	class MAP_Swalk_DTr: MAP_Swalk_Base
	{
		destrType = "DestructTree";
		accuracy = 1000;
	};
	class MAP_Swalk_DBu: MAP_Swalk_Base
	{
		destrType = "DestructBuilding";
		accuracy = 1000;
		class DestructionEffects
		{
			class HouseDestr
			{
				simulation = "destroy";
				type = "DelayedDestruction";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class MAP_SidewalkClearLong: MAP_Swalk_DNo
	{
		scope = 2;
		displayName = "S SidewalkClearLong";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\ca\misc\sidewalks\SidewalkClearLong.p3d";
	};
	class MAP_SidewalkClearMiddle: MAP_Swalk_DNo
	{
		scope = 2;
		displayName = "S SidewalkClearMiddle";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\ca\misc\sidewalks\SidewalkClearMiddle.p3d";
	};
	class MAP_SidewalkClearShort: MAP_Swalk_DNo
	{
		scope = 2;
		displayName = "S SidewalkClearShort";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\ca\misc\sidewalks\SidewalkClearShort.p3d";
	};
	class MAP_SidewalkShortEnd: MAP_Swalk_DNo
	{
		scope = 2;
		displayName = "S SidewalkShortEnd";
		icon = "\MAP_EU\icon\RE.paa";
		model = "\ca\misc\sidewalks\SidewalkShortEnd.p3d";
	};
	class MAP_SidewalkCorner: MAP_Swalk_DNo
	{
		scope = 2;
		displayName = "S SidewalkCorner";
		icon = "\MAP_EU\icon\RBL.paa";
		model = "\ca\misc\sidewalks\SidewalkCorner.p3d";
	};
	class MAP_SidewalkTurn5deg: MAP_Swalk_DNo
	{
		scope = 2;
		displayName = "S SidewalkTurn5deg";
		icon = "\MAP_EU\icon\T.paa";
		model = "\ca\misc\sidewalks\SidewalkTurn5deg.p3d";
	};
	class MAP_SidewalkTurn10deg: MAP_Swalk_DNo
	{
		scope = 2;
		displayName = "S SidewalkTurn10deg";
		icon = "\MAP_EU\icon\T.paa";
		model = "\ca\misc\sidewalks\SidewalkTurn10deg.p3d";
	};
	class MAP_SidewalkTurn20deg: MAP_Swalk_DNo
	{
		scope = 2;
		displayName = "S SidewalkTurn20deg";
		icon = "\MAP_EU\icon\T.paa";
		model = "\ca\misc\sidewalks\SidewalkTurn20deg.p3d";
	};
	class MAP_SidewalkTurn30deg: MAP_Swalk_DNo
	{
		scope = 2;
		displayName = "S SidewalkTurn30deg";
		icon = "\MAP_EU\icon\T.paa";
		model = "\ca\misc\sidewalks\SidewalkTurn30deg.p3d";
	};
	class MAP_SidewalkCrossing: MAP_Swalk_DNo
	{
		scope = 2;
		displayName = "S SidewalkCrossing";
		icon = "\MAP_EU\icon\RCX.paa";
		model = "\ca\misc\sidewalks\SidewalkCrossing.p3d";
	};
	class MAP_SidewalkCrossingT: MAP_Swalk_DNo
	{
		scope = 2;
		displayName = "S SidewalkCrossingT";
		icon = "\MAP_EU\icon\RCTB.paa";
		model = "\ca\misc\sidewalks\SidewalkCrossingT.p3d";
	};
	class MAP_path_0_2000: MAP_Swalk_DNo
	{
		scope = 2;
		displayName = "P path_0 2000";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\path_0 2000.p3d";
	};
	class MAP_path_1_1000: MAP_Swalk_DNo
	{
		scope = 2;
		displayName = "P path_1 1000";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\path_1 1000.p3d";
	};
	class MAP_path_25: MAP_Swalk_DNo
	{
		scope = 2;
		displayName = "P path_25";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\path_25.p3d";
	};
	class MAP_path_12: MAP_Swalk_DNo
	{
		scope = 2;
		displayName = "P path_12";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\path_12.p3d";
	};
	class MAP_path_6: MAP_Swalk_DNo
	{
		scope = 2;
		displayName = "P path_6";
		icon = "\MAP_EU\icon\RL.paa";
		model = "\CA\Roads2\path_6.p3d";
	};
	class MAP_path_6konec: MAP_Swalk_DNo
	{
		scope = 2;
		displayName = "P path_6konec";
		icon = "\MAP_EU\icon\RE.paa";
		model = "\CA\Roads2\path_6konec.p3d";
	};
	class MAP_path_10_25: MAP_Swalk_DNo
	{
		scope = 2;
		displayName = "P path_10 25";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\path_10 25.p3d";
	};
	class MAP_path_10_50: MAP_Swalk_DNo
	{
		scope = 2;
		displayName = "P path_10 50";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\path_10 50.p3d";
	};
	class MAP_path_10_75: MAP_Swalk_DNo
	{
		scope = 2;
		displayName = "P path_10 75";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\path_10 75.p3d";
	};
	class MAP_path_10_100: MAP_Swalk_DNo
	{
		scope = 2;
		displayName = "P path_10 100";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\path_10 100.p3d";
	};
	class MAP_path_7_100: MAP_Swalk_DNo
	{
		scope = 2;
		displayName = "P path_7 100";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\path_7 100.p3d";
	};
	class MAP_path_15_75: MAP_Swalk_DNo
	{
		scope = 2;
		displayName = "P path_15 75";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\path_15 75.p3d";
	};
	class MAP_path_22_50: MAP_Swalk_DNo
	{
		scope = 2;
		displayName = "P path_22 50";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\path_22 50.p3d";
	};
	class MAP_path_30_25: MAP_Swalk_DNo
	{
		scope = 2;
		displayName = "P path_30 25";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\path_30 25.p3d";
	};
	class MAP_path_60_10: MAP_Swalk_DNo
	{
		scope = 2;
		displayName = "P path_60 10";
		icon = "\MAP_EU\icon\RBC.paa";
		model = "\CA\Roads2\path_60 10.p3d";
	};
	class MAP_Houses_Base: Static
	{
		displayName = "";
		accuracy = 0.1;
		vehicleClass = "MAP_EUHouses";
		model = "";
		nameSound = "";
		animated = 0;
		simulation = "house";
		cost = 0;
		armor = 1000;
		ladders[] = {};
		placement = "vertical";
	};
	class MAP_House_DNo: MAP_Houses_Base
	{
		accuracy = 1000;
	};
	class MAP_House_DTe: MAP_Houses_Base
	{
		destrType = "DestructTent";
		accuracy = 1000;
	};
	class MAP_House_DTr: MAP_Houses_Base
	{
		destrType = "DestructTree";
		accuracy = 1000;
	};
	class MAP_House_DBu: MAP_Houses_Base
	{
		destrType = "DestructBuilding";
		accuracy = 1000;
		class DestructionEffects
		{
			class HouseDestr
			{
				simulation = "destroy";
				type = "DelayedDestruction";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class Land_bouda1;
	class MAP_bouda1: Land_bouda1
	{
		scope = 2;
		displayName = "B bouda1";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_bouda2_vnitrek;
	class MAP_bouda2_vnitrek: Land_bouda2_vnitrek
	{
		scope = 2;
		displayName = "B bouda2_vnitrek";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_cihlovej_dum;
	class MAP_cihlovej_dum: Land_cihlovej_dum
	{
		scope = 2;
		displayName = "B cihlovej_dum";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_cihlovej_dum_in;
	class MAP_cihlovej_dum_in: Land_cihlovej_dum_in
	{
		scope = 2;
		displayName = "B cihlovej_dum_in";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_deutshe;
	class MAP_deutshe: Land_deutshe
	{
		scope = 2;
		displayName = "B deutshe";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_deutshe_mini;
	class MAP_deutshe_mini: Land_deutshe_mini
	{
		scope = 2;
		displayName = "B deutshe_mini";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_domek_rosa;
	class MAP_domek_rosa: Land_domek_rosa
	{
		scope = 2;
		displayName = "B domek_rosa";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_dum_istan3_hromada2;
	class MAP_dum_istan3_hromada2: Land_dum_istan3_hromada2
	{
		scope = 2;
		displayName = "B dum_istan3_hromada2";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_dum_istan3_pumpa;
	class MAP_dum_istan3_pumpa: Land_dum_istan3_pumpa
	{
		scope = 2;
		displayName = "B dum_istan3_pumpa";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class MAP_dum_istan4_zidka: MAP_House_DBu
	{
		scope = 2;
		displayName = "B dum_istan4_zidka";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\buildings\dum_istan4_zidka.p3d";
	};
	class Land_dum_m2;
	class MAP_dum_m2: Land_dum_m2
	{
		scope = 2;
		displayName = "B dum_m2";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_dum_mesto;
	class MAP_dum_mesto: Land_dum_mesto
	{
		scope = 2;
		displayName = "B dum_mesto";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_dum_mesto_in;
	class MAP_dum_mesto_in: Land_dum_mesto_in
	{
		scope = 2;
		displayName = "B dum_mesto_in";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_dum_mesto2;
	class MAP_dum_mesto2: Land_dum_mesto2
	{
		scope = 2;
		displayName = "B dum_mesto2";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_dum_mesto2l;
	class MAP_dum_mesto2l: Land_dum_mesto2l
	{
		scope = 2;
		displayName = "B dum_mesto2l";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class MAP_Dum_mesto3test: MAP_House_DBu
	{
		scope = 2;
		displayName = "B Dum_mesto3test";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\buildings\Dum_mesto3test.p3d";
	};
	class Land_dum_olez_istan1;
	class dum_olez_istan1: Land_dum_olez_istan1
	{
		scope = 2;
		displayName = "B dum_olez_istan1";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_dum_olez_istan2;
	class dum_olez_istan2: Land_dum_olez_istan2
	{
		scope = 2;
		displayName = "B dum_olez_istan2";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_dum_olez_istan2_maly;
	class dum_olez_istan2_maly: Land_dum_olez_istan2_maly
	{
		scope = 2;
		displayName = "B dum_olez_istan2_maly";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_dum_olez_istan2_maly2;
	class dum_olez_istan2_maly2: Land_dum_olez_istan2_maly2
	{
		scope = 2;
		displayName = "B dum_olez_istan2_maly2";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_dum_olezlina;
	class dum_olezlina: Land_dum_olezlina
	{
		scope = 2;
		displayName = "B dum_olezlina";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_dum_rasovna;
	class dum_rasovna: Land_dum_rasovna
	{
		scope = 2;
		displayName = "B dum_rasovna";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_dumruina_mini;
	class dumruina_mini: Land_dumruina_mini
	{
		scope = 2;
		displayName = "B dumruina_mini";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_hruzdum;
	class hruzdum: Land_hruzdum
	{
		scope = 2;
		displayName = "B hruzdum";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_Panelak;
	class MAP_Panelak: Land_Panelak
	{
		scope = 2;
		displayName = "B Panelak";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_Panelak2;
	class MAP_Panelak2: Land_Panelak2
	{
		scope = 2;
		displayName = "B Panelak2";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_Panelak3;
	class MAP_Panelak3: Land_Panelak3
	{
		scope = 2;
		displayName = "B Panelak3";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_sara_domek_kovarna;
	class MAP_sara_domek_kovarna: Land_sara_domek_kovarna
	{
		scope = 2;
		displayName = "B sara_domek_kovarna";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_sara_domek_podhradi_1;
	class MAP_sara_domek_podhradi_1: Land_sara_domek_podhradi_1
	{
		scope = 2;
		displayName = "B sara_domek_podhradi_1";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_sara_domek_ruina;
	class MAP_sara_domek_ruina: Land_sara_domek_ruina
	{
		scope = 2;
		displayName = "B sara_domek_ruina";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_sara_Domek_sedy;
	class MAP_sara_Domek_sedy: Land_sara_Domek_sedy
	{
		scope = 2;
		displayName = "B sara_Domek_sedy";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_sara_domek_vilka;
	class MAP_sara_domek_vilka: Land_sara_domek_vilka
	{
		scope = 2;
		displayName = "B sara_domek_vilka";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_sara_domek_zluty;
	class MAP_sara_domek_zluty: Land_sara_domek_zluty
	{
		scope = 2;
		displayName = "B sara_domek_zluty";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_stanice;
	class MAP_stanice: Land_stanice
	{
		scope = 2;
		displayName = "B stanice";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_statek_hl_bud;
	class MAP_statek_hl_bud: Land_statek_hl_bud
	{
		scope = 2;
		displayName = "B statek_hl_bud";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_Statek_kulna;
	class MAP_Statek_kulna: Land_Statek_kulna
	{
		scope = 2;
		displayName = "B Statek_kulna";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseV_1I1;
	class MAP_HouseV_1I1: Land_HouseV_1I1
	{
		scope = 2;
		displayName = "B HouseV_1I1";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseV_1I1_dam;
	class MAP_HouseV_1I1_dam: Land_HouseV_1I1_dam
	{
		scope = 2;
		displayName = "B HouseV_1I1_dam";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseV_1I2;
	class MAP_HouseV_1I2: Land_HouseV_1I2
	{
		scope = 2;
		displayName = "B HouseV_1I2";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseV_1I3;
	class MAP_HouseV_1I3: Land_HouseV_1I3
	{
		scope = 2;
		displayName = "B HouseV_1I3";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseV_1I4;
	class MAP_HouseV_1I4: Land_HouseV_1I4
	{
		scope = 2;
		displayName = "B HouseV_1I4";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseV_1L1;
	class MAP_HouseV_1L1: Land_HouseV_1L1
	{
		scope = 2;
		displayName = "B HouseV_1L1";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseV_1L2;
	class MAP_HouseV_1L2: Land_HouseV_1L2
	{
		scope = 2;
		displayName = "B HouseV_1L2";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseV_1T;
	class MAP_HouseV_1T: Land_HouseV_1T
	{
		scope = 2;
		displayName = "B HouseV_1T";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseV_2I;
	class MAP_HouseV_2I: Land_HouseV_2I
	{
		scope = 2;
		displayName = "B HouseV_2I";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseV_2L;
	class MAP_HouseV_2L: Land_HouseV_2L
	{
		scope = 2;
		displayName = "B HouseV_2L";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseV_2L_dam;
	class MAP_HouseV_2L_dam: Land_HouseV_2L_dam
	{
		scope = 2;
		displayName = "B HouseV_2L_dam";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_houseV_2T1;
	class MAP_HouseV_2T1: Land_houseV_2T1
	{
		scope = 2;
		displayName = "B HouseV_2T1";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_houseV_2T2;
	class MAP_HouseV_2T2: Land_houseV_2T2
	{
		scope = 2;
		displayName = "B HouseV_2T2";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseV_3I1;
	class MAP_HouseV_3I1: Land_HouseV_3I1
	{
		scope = 2;
		displayName = "B HouseV_3I1";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseV_3I2;
	class MAP_HouseV_3I2: Land_HouseV_3I2
	{
		scope = 2;
		displayName = "B HouseV_3I2";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseV_3I3;
	class MAP_HouseV_3I3: Land_HouseV_3I3
	{
		scope = 2;
		displayName = "B HouseV_3I3";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseV_3I4;
	class MAP_HouseV_3I4: Land_HouseV_3I4
	{
		scope = 2;
		displayName = "B HouseV_3I4";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseV2_01A;
	class MAP_HouseV2_01A: Land_HouseV2_01A
	{
		scope = 2;
		displayName = "B HouseV2_01A";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseV2_01A_dam;
	class MAP_HouseV2_01A_dam: Land_HouseV2_01A_dam
	{
		scope = 2;
		displayName = "B HouseV2_01A_dam";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseV2_01B;
	class MAP_HouseV2_01B: Land_HouseV2_01B
	{
		scope = 2;
		displayName = "B HouseV2_01B";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseV2_01B_dam;
	class MAP_HouseV2_01B_dam: Land_HouseV2_01B_dam
	{
		scope = 2;
		displayName = "B HouseV2_01B_dam";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseV2_02;
	class MAP_HouseV2_02: Land_HouseV2_02
	{
		scope = 2;
		displayName = "B HouseV2_02";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseV2_02_Interier;
	class MAP_HouseV2_02_Interier: Land_HouseV2_02_Interier
	{
		scope = 2;
		displayName = "B HouseV2_02_Interier";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseV2_02_Interier_dam;
	class MAP_HouseV2_02_Interier_dam: Land_HouseV2_02_Interier_dam
	{
		scope = 2;
		displayName = "B HouseV2_02_Interier";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseV2_03;
	class MAP_HouseV2_03: Land_HouseV2_03
	{
		scope = 2;
		displayName = "B HouseV2_03";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseV2_03_dam;
	class MAP_HouseV2_03_dam: Land_HouseV2_03_dam
	{
		scope = 2;
		displayName = "B HouseV2_03_dam";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseV2_03B;
	class MAP_HouseV2_03B: Land_HouseV2_03B
	{
		scope = 2;
		displayName = "B HouseV2_03B";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseV2_03B_dam;
	class MAP_HouseV2_03B_dam: Land_HouseV2_03B_dam
	{
		scope = 2;
		displayName = "B HouseV2_03B_dam";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseV2_04;
	class MAP_HouseV2_04: Land_HouseV2_04
	{
		scope = 2;
		displayName = "B HouseV2_04";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseV2_04_interier;
	class MAP_HouseV2_04_interier: Land_HouseV2_04_interier
	{
		scope = 2;
		displayName = "B HouseV2_04_interier";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseV2_04_interier_dam;
	class MAP_HouseV2_04_interier_dam: Land_HouseV2_04_interier_dam
	{
		scope = 2;
		displayName = "B HouseV2_04_interier_dam";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseV2_05;
	class MAP_HouseV2_05: Land_HouseV2_05
	{
		scope = 2;
		displayName = "B HouseV2_05";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseBlock_A1;
	class MAP_HouseBlock_A1: Land_HouseBlock_A1
	{
		scope = 2;
		displayName = "B HouseBlock_A1";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseBlock_A1_1;
	class MAP_HouseBlock_A1_1: Land_HouseBlock_A1_1
	{
		scope = 2;
		displayName = "B HouseBlock_A1_1";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseBlock_A1_2;
	class MAP_HouseBlock_A1_2: Land_HouseBlock_A1_2
	{
		scope = 2;
		displayName = "B HouseBlock_A1_2";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseBlock_A2;
	class MAP_HouseBlock_A2: Land_HouseBlock_A2
	{
		scope = 2;
		displayName = "B HouseBlock_A2";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseBlock_A2_1;
	class MAP_HouseBlock_A2_1: Land_HouseBlock_A2_1
	{
		scope = 2;
		displayName = "B HouseBlock_A2_1";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseBlock_A3;
	class MAP_HouseBlock_A3: Land_HouseBlock_A3
	{
		scope = 2;
		displayName = "B HouseBlock_A3";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseBlock_B1;
	class MAP_HouseBlock_B1: Land_HouseBlock_B1
	{
		scope = 2;
		displayName = "B HouseBlock_B1";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseBlock_B2;
	class MAP_HouseBlock_B2: Land_HouseBlock_B2
	{
		scope = 2;
		displayName = "B HouseBlock_B2";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseBlock_B3;
	class MAP_HouseBlock_B3: Land_HouseBlock_B3
	{
		scope = 2;
		displayName = "B HouseBlock_B3";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseBlock_B4;
	class MAP_HouseBlock_B4: Land_HouseBlock_B4
	{
		scope = 2;
		displayName = "B HouseBlock_B4";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseBlock_B5;
	class MAP_HouseBlock_B5: Land_HouseBlock_B5
	{
		scope = 2;
		displayName = "B HouseBlock_B5";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseBlock_B6;
	class MAP_HouseBlock_B6: Land_HouseBlock_B6
	{
		scope = 2;
		displayName = "B HouseBlock_B6";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseBlock_C1;
	class MAP_HouseBlock_C1: Land_HouseBlock_C1
	{
		scope = 2;
		displayName = "B HouseBlock_C1";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseBlock_C2;
	class MAP_HouseBlock_C2: Land_HouseBlock_C2
	{
		scope = 2;
		displayName = "B HouseBlock_C2";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseBlock_C3;
	class MAP_HouseBlock_C3: Land_HouseBlock_C3
	{
		scope = 2;
		displayName = "B HouseBlock_C3";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseBlock_C4;
	class MAP_HouseBlock_C4: Land_HouseBlock_C4
	{
		scope = 2;
		displayName = "B HouseBlock_C4";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseBlock_C5;
	class MAP_HouseBlock_C5: Land_HouseBlock_C5
	{
		scope = 2;
		displayName = "B HouseBlock_C5";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseBlock_D1;
	class MAP_HouseBlock_D1: Land_HouseBlock_D1
	{
		scope = 2;
		displayName = "B HouseBlock_D1";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class Land_HouseBlock_D2;
	class MAP_HouseBlock_D2: Land_HouseBlock_D2
	{
		scope = 2;
		displayName = "B HouseBlock_D2";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUHouses";
		accuracy = 1000;
	};
	class MAP_Indus_Base: Static
	{
		displayName = "";
		accuracy = 0.1;
		vehicleClass = "MAP_EUIndus";
		model = "";
		nameSound = "";
		animated = 0;
		simulation = "house";
		cost = 0;
		armor = 1000;
		ladders[] = {};
		placement = "vertical";
	};
	class MAP_Indus_DNo: MAP_Indus_Base
	{
		destrType = "DestructNo";
		accuracy = 1000;
	};
	class MAP_Indus_DTe: MAP_Indus_Base
	{
		destrType = "DestructTent";
		accuracy = 1000;
	};
	class MAP_Indus_DTr: MAP_Indus_Base
	{
		destrType = "DestructTree";
		accuracy = 1000;
	};
	class MAP_Indus_DBu: MAP_Indus_Base
	{
		destrType = "DestructBuilding";
		accuracy = 1000;
		class DestructionEffects
		{
			class HouseDestr
			{
				simulation = "destroy";
				type = "DelayedDestruction";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class Land_hut06;
	class MAP_hut06: Land_hut06
	{
		scope = 2;
		displayName = "S hut06";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Shed_wooden;
	class MAP_Shed_wooden: Land_Shed_wooden
	{
		scope = 2;
		displayName = "S Shed_wooden";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Shed_M01;
	class MAP_Shed_M01: Land_Shed_M01
	{
		scope = 2;
		displayName = "S Shed_M01";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Shed_M02;
	class MAP_Shed_M02: Land_Shed_M02
	{
		scope = 2;
		displayName = "S Shed_M02";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Shed_M03;
	class MAP_Shed_M03: Land_Shed_M03
	{
		scope = 2;
		displayName = "S Shed_M03";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Shed_W01;
	class MAP_Shed_W01: Land_Shed_W01
	{
		scope = 2;
		displayName = "S Shed_W01";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Shed_W02;
	class MAP_Shed_W02: Land_Shed_W02
	{
		scope = 2;
		displayName = "S Shed_W02";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Shed_W03;
	class MAP_Shed_W03: Land_Shed_W03
	{
		scope = 2;
		displayName = "S Shed_W03";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Shed_W4;
	class MAP_Shed_W4: Land_Shed_W4
	{
		scope = 2;
		displayName = "R Shed_W4";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class MAP_Ind_SideRoof: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "C Ind_SideRoof";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\Ca\Structures\Shed_Ind\Ind_SideRoof.p3d";
	};
	class Land_bouda3;
	class MAP_bouda3: Land_bouda3
	{
		scope = 2;
		displayName = "S bouda3";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_hut_old02;
	class MAP_hut_old02: Land_hut_old02
	{
		scope = 2;
		displayName = "S hut_old02";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Shed_Ind02;
	class MAP_Shed_Ind02: Land_Shed_Ind02
	{
		scope = 2;
		displayName = "C Shed_Ind02";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Shed_Ind02_dam;
	class MAP_Shed_Ind02_dam: Land_Shed_Ind02_dam
	{
		scope = 2;
		displayName = "C Shed_Ind02_dam";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Hangar_2;
	class MAP_Hangar_2: Land_Hangar_2
	{
		scope = 2;
		displayName = "S Hangar_2";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Barn_W_02;
	class MAP_Barn_W_02: Land_Barn_W_02
	{
		scope = 2;
		displayName = "S Barn_W_02";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Barn_W_01;
	class MAP_Barn_W_01: Land_Barn_W_01
	{
		scope = 2;
		displayName = "S Barn_W_01";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Barn_W_01_dam;
	class MAP_Barn_W_01_dam: Land_Barn_W_01_dam
	{
		scope = 2;
		displayName = "S Barn_W_01_dam";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Barn_Metal;
	class MAP_Barn_Metal: Land_Barn_Metal
	{
		scope = 2;
		displayName = "S Barn_Metal";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Barn_Metal_dam;
	class MAP_Barn_Metal_dam: Land_Barn_Metal_dam
	{
		scope = 2;
		displayName = "S Barn_Metal_ruins";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Ind_Shed_01_main;
	class MAP_Ind_Shed_01_main: Land_Ind_Shed_01_main
	{
		scope = 2;
		displayName = "S Ind_Shed_01_main";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Ind_Shed_01_end;
	class MAP_Ind_Shed_01_end: Land_Ind_Shed_01_end
	{
		scope = 2;
		displayName = "S Ind_Shed_01_end";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Ind_Shed_02_main;
	class MAP_Ind_Shed_02_main: Land_Ind_Shed_02_main
	{
		scope = 2;
		displayName = "S Ind_Shed_02_main";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Ind_Shed_02_end;
	class MAP_Ind_Shed_02_end: Land_Ind_Shed_02_end
	{
		scope = 2;
		displayName = "S Ind_Shed_02_end";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class MAP_BusStop: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "S BusStop";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\Structures\Misc\misc_BusStop\BusStop.p3d";
	};
	class MAP_busStop_village: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "S busStop_village";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\Structures\Misc\misc_BusStop\busStop_village.p3d";
	};
	class Land_sara_hasic_zbroj;
	class MAP_sara_hasic_zbroj: Land_sara_hasic_zbroj
	{
		scope = 2;
		displayName = "S sara_hasic_zbroj";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_garaz;
	class MAP_garaz: Land_garaz
	{
		scope = 2;
		displayName = "S garaz";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_garaz_mala;
	class MAP_garaz_mala: Land_garaz_mala
	{
		scope = 2;
		displayName = "S garaz_mala";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Ind_Garage01;
	class MAP_Ind_Garage01: Land_Ind_Garage01
	{
		scope = 2;
		displayName = "S Ind_Garage01";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_dum01;
	class MAP_dum01: Land_dum01
	{
		scope = 2;
		displayName = "C dum01";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_A_Office01;
	class MAP_A_Office01: Land_A_Office01
	{
		scope = 2;
		displayName = "C A_Office01";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_A_Office02;
	class MAP_A_Office02: Land_A_Office02
	{
		scope = 2;
		displayName = "C A_Office02";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_A_Office02_dam;
	class MAP_A_Office02_dam: Land_A_Office02_dam
	{
		scope = 2;
		displayName = "C A_Office02_dam";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_a_stationhouse;
	class MAP_a_stationhouse: Land_a_stationhouse
	{
		scope = 2;
		displayName = "C a_stationhouse";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_A_GeneralStore_01;
	class MAP_A_GeneralStore_01: Land_A_GeneralStore_01
	{
		scope = 2;
		displayName = "C A_GeneralStore_01";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_A_GeneralStore_01a;
	class MAP_A_GeneralStore_01a: Land_A_GeneralStore_01a
	{
		scope = 2;
		displayName = "C A_GeneralStore_01a";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_A_GeneralStore_01_dam;
	class MAP_A_GeneralStore_01_dam: Land_A_GeneralStore_01_dam
	{
		scope = 2;
		displayName = "C A_GeneralStore_01_dam";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_A_GeneralStore_01a_dam;
	class MAP_A_GeneralStore_01a_dam: Land_A_GeneralStore_01a_dam
	{
		scope = 2;
		displayName = "C A_GeneralStore_01a_dam";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_A_Pub_01;
	class MAP_A_Pub_01: Land_A_Pub_01
	{
		scope = 2;
		displayName = "C A_Pub_01";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Farm_Cowshed_a;
	class MAP_Farm_Cowshed_a: Land_Farm_Cowshed_a
	{
		scope = 2;
		displayName = "F Farm_Cowshed_a";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Farm_Cowshed_a_dam;
	class MAP_Farm_Cowshed_a_dam: Land_Farm_Cowshed_a_dam
	{
		scope = 2;
		displayName = "F Farm_Cowshed_a_dam";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Farm_Cowshed_b;
	class MAP_Farm_Cowshed_b: Land_Farm_Cowshed_b
	{
		scope = 2;
		displayName = "F Farm_Cowshed_b";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Farm_Cowshed_b_dam;
	class MAP_Farm_Cowshed_b_dam: Land_Farm_Cowshed_b_dam
	{
		scope = 2;
		displayName = "F Farm_Cowshed_b_dam";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Farm_Cowshed_c;
	class MAP_Farm_Cowshed_c: Land_Farm_Cowshed_c
	{
		scope = 2;
		displayName = "F Farm_Cowshed_c";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Farm_Cowshed_c_dam;
	class MAP_Farm_Cowshed_c_dam: Land_Farm_Cowshed_c_dam
	{
		scope = 2;
		displayName = "F Farm_Cowshed_c_dam";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Farm_WTower;
	class MAP_Farm_WTower: Land_Farm_WTower
	{
		scope = 2;
		displayName = "F Farm_WTower";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_stodola_old_open;
	class MAP_stodola_old_open: Land_stodola_old_open
	{
		scope = 2;
		displayName = "F stodola_old_open";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_stodola_open;
	class MAP_stodola_open: Land_stodola_open
	{
		scope = 2;
		displayName = "F stodola_open";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_sara_stodola;
	class MAP_sara_stodola: Land_sara_stodola
	{
		scope = 2;
		displayName = "F sara_stodola";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_sara_stodola3;
	class MAP_sara_stodola3: Land_sara_stodola3
	{
		scope = 2;
		displayName = "F sara_stodola3";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class MAP_water_tank: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "W water_tank";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\misc\water_tank.p3d";
	};
	class Land_Nasypka;
	class MAP_Nasypka: Land_Nasypka
	{
		scope = 2;
		displayName = "F Nasypka";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_A_BuildingWIP;
	class MAP_A_BuildingWIP: Land_A_BuildingWIP
	{
		scope = 2;
		displayName = "I A_BuildingWIP";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_A_CraneCon;
	class MAP_A_CraneCon: Land_A_CraneCon
	{
		scope = 2;
		displayName = "I A_CraneCon";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_A_Crane_02a;
	class MAP_A_Crane_02a: Land_A_Crane_02a
	{
		scope = 2;
		displayName = "I A_Crane_02a";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_A_Crane_02b;
	class MAP_A_Crane_02b: Land_A_Crane_02b
	{
		scope = 2;
		displayName = "I A_Crane_02b";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class MAP_crane_rails: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "I crane_rails";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\buildings2\A_Crane_02\crane_rails.p3d";
	};
	class MAP_crane_rails_end: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "I crane_rails_end";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\buildings2\A_Crane_02\crane_rails_end.p3d";
	};
	class MAP_Misc_Cargo1A: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "I Misc_Cargo1A";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\buildings2\Misc_Cargo\Misc_Cargo1A.p3d";
	};
	class Land_Misc_Cargo1Ao;
	class MAP_Misc_Cargo1Ao: Land_Misc_Cargo1Ao
	{
		scope = 2;
		displayName = "I Misc_Cargo1Ao";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Misc_Cargo1B;
	class MAP_Misc_Cargo1B: Land_Misc_Cargo1B
	{
		scope = 2;
		displayName = "I Misc_Cargo1B";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Misc_Cargo1Bo;
	class MAP_Misc_Cargo1Bo: Land_Misc_Cargo1Bo
	{
		scope = 2;
		displayName = "I Misc_Cargo1Bo";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Misc_Cargo1C;
	class MAP_Misc_Cargo1C: Land_Misc_Cargo1C
	{
		scope = 2;
		displayName = "I Misc_Cargo1C";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Misc_Cargo1D;
	class MAP_Misc_Cargo1D: Land_Misc_Cargo1D
	{
		scope = 2;
		displayName = "I Misc_Cargo1D";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Misc_Cargo1E;
	class MAP_Misc_Cargo1E: Land_Misc_Cargo1E
	{
		scope = 2;
		displayName = "I Misc_Cargo1E";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Misc_Cargo1F;
	class MAP_Misc_Cargo1F: Land_Misc_Cargo1F
	{
		scope = 2;
		displayName = "I Misc_Cargo1F";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Misc_Cargo1G;
	class MAP_Misc_Cargo1G: Land_Misc_Cargo1G
	{
		scope = 2;
		displayName = "I Misc_Cargo1G";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class MAP_Misc_Cargo2A: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "I Misc_Cargo2A";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\buildings2\Misc_Cargo\Misc_Cargo2A.p3d";
	};
	class Land_Misc_Cargo2B;
	class MAP_Misc_Cargo2B: Land_Misc_Cargo2B
	{
		scope = 2;
		displayName = "I Misc_Cargo2B";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Misc_Cargo2C;
	class MAP_Misc_Cargo2C: Land_Misc_Cargo2C
	{
		scope = 2;
		displayName = "I Misc_Cargo2C";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Misc_Cargo2D;
	class MAP_Misc_Cargo2D: Land_Misc_Cargo2D
	{
		scope = 2;
		displayName = "I Misc_Cargo2D";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Misc_Cargo2E;
	class MAP_Misc_Cargo2E: Land_Misc_Cargo2E
	{
		scope = 2;
		displayName = "I Misc_Cargo2E";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class MAP_SeaCrate: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "I SeaCrate";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\buildings2\Misc_Cargo\SeaCrate.p3d";
	};
	class MAP_Ind_Conveyer: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "I Ind_Conveyer";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Ind_Quarry\Ind_Conveyer.p3d";
		placement = "slope";
	};
	class MAP_Ind_ConveyerLong: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "I Ind_ConveyerLong";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Ind_Quarry\Ind_ConveyerLong.p3d";
		placement = "slope";
	};
	class MAP_Ind_HammerMill: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "I Ind_HammerMill";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Ind_Quarry\Ind_HammerMill.p3d";
	};
	class Land_Ind_Quarry;
	class MAP_Ind_Quarry: Land_Ind_Quarry
	{
		scope = 2;
		displayName = "I Ind_Quarry";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Ind_SawMill;
	class MAP_Ind_SawMill: Land_Ind_SawMill
	{
		scope = 2;
		displayName = "I Ind_SawMill";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Ind_SawMillPen;
	class MAP_Ind_SawMillPen: Land_Ind_SawMillPen
	{
		scope = 2;
		displayName = "I Ind_SawMillPen";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Ind_Workshop01_01;
	class MAP_Ind_Workshop01_01: Land_Ind_Workshop01_01
	{
		scope = 2;
		displayName = "I Ind_Workshop01_01";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Ind_Workshop01_02;
	class MAP_Ind_Workshop01_02: Land_Ind_Workshop01_02
	{
		scope = 2;
		displayName = "I Ind_Workshop01_02";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Ind_Workshop01_03;
	class MAP_Ind_Workshop01_03: Land_Ind_Workshop01_03
	{
		scope = 2;
		displayName = "I Ind_Workshop01_03";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Ind_Workshop01_04;
	class MAP_Ind_Workshop01_04: Land_Ind_Workshop01_04
	{
		scope = 2;
		displayName = "I Ind_Workshop01_04";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Ind_Workshop01_box;
	class MAP_Ind_Workshop01_box: Land_Ind_Workshop01_box
	{
		scope = 2;
		displayName = "I Ind_Workshop01_box";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Ind_Workshop01_L;
	class MAP_Ind_Workshop01_L: Land_Ind_Workshop01_L
	{
		scope = 2;
		displayName = "I Ind_Workshop01_L";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_repair_center;
	class MAP_repair_center: Land_repair_center
	{
		scope = 2;
		displayName = "I repair_center";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Tovarna2;
	class MAP_Tovarna2: Land_Tovarna2
	{
		scope = 2;
		displayName = "I Tovarna2";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Ind_Pec_01;
	class MAP_Ind_Pec_01: Land_Ind_Pec_01
	{
		scope = 2;
		displayName = "I Ind_Pec_01";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Ind_Pec_02;
	class MAP_Ind_Pec_02: Land_Ind_Pec_02
	{
		scope = 2;
		displayName = "I Ind_Pec_02";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Ind_Pec_03a;
	class MAP_Ind_Pec_03a: Land_Ind_Pec_03a
	{
		scope = 2;
		displayName = "I Ind_Pec_03a";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Ind_Pec_03b;
	class MAP_Ind_Pec_03b: Land_Ind_Pec_03b
	{
		scope = 2;
		displayName = "I Ind_Pec_03b";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Ind_Expedice_1;
	class MAP_Ind_Expedice_1: Land_Ind_Expedice_1
	{
		scope = 2;
		displayName = "I Ind_Expedice_1";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_ind_silomale;
	class MAP_ind_silomale: Land_ind_silomale
	{
		scope = 2;
		displayName = "I ind_silomale";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Ind_SiloVelke_01;
	class MAP_Ind_SiloVelke_01: Land_Ind_SiloVelke_01
	{
		scope = 2;
		displayName = "I Ind_SiloVelke_01";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Ind_SiloVelke_02;
	class MAP_Ind_SiloVelke_02: Land_Ind_SiloVelke_02
	{
		scope = 2;
		displayName = "I Ind_SiloVelke_02";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Ind_SiloVelke_most;
	class MAP_Ind_SiloVelke_most: Land_Ind_SiloVelke_most
	{
		scope = 2;
		displayName = "I Ind_SiloVelke_most";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Vez_Silo;
	class MAP_Vez_Silo: Land_Vez_Silo
	{
		scope = 2;
		displayName = "I Vez_Silo";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Ind_Vysypka;
	class MAP_Ind_Vysypka: Land_Ind_Vysypka
	{
		scope = 2;
		displayName = "I Ind_Vysypka";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_D_Mlyn_Vys;
	class MAP_D_Mlyn_Vys: Land_D_Mlyn_Vys
	{
		scope = 2;
		displayName = "I D_Mlyn_Vys";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_D_Pec_Vez1;
	class MAP_D_Pec_Vez1: Land_D_Pec_Vez1
	{
		scope = 2;
		displayName = "I D_Pec_Vez1";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_D_Pec_Vez2;
	class MAP_D_Pec_Vez2: Land_D_Pec_Vez2
	{
		scope = 2;
		displayName = "I D_Pec_Vez2";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_D_Vez_Mlyn;
	class MAP_D_Vez_Mlyn: Land_D_Vez_Mlyn
	{
		scope = 2;
		displayName = "I D_Vez_Mlyn";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_D_VSilo_Pec;
	class MAP_D_VSilo_Pec: Land_D_VSilo_Pec
	{
		scope = 2;
		displayName = "I D_VSilo_Pec";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Vez_Pec;
	class MAP_Vez_Pec: Land_Vez_Pec
	{
		scope = 2;
		displayName = "I Vez_Pec";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Ind_Mlyn_01;
	class MAP_Ind_Mlyn_01: Land_Ind_Mlyn_01
	{
		scope = 2;
		displayName = "I Ind_Mlyn_01";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Ind_Mlyn_02;
	class MAP_Ind_Mlyn_02: Land_Ind_Mlyn_02
	{
		scope = 2;
		displayName = "I Ind_Mlyn_02";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Ind_Mlyn_03;
	class MAP_Ind_Mlyn_03: Land_Ind_Mlyn_03
	{
		scope = 2;
		displayName = "I Ind_Mlyn_03";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Ind_Mlyn_04;
	class MAP_Ind_Mlyn_04: Land_Ind_Mlyn_04
	{
		scope = 2;
		displayName = "I Ind_Mlyn_04";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Ind_Mlyn_D1;
	class MAP_Ind_Mlyn_D1: Land_Ind_Mlyn_D1
	{
		scope = 2;
		displayName = "I Ind_Mlyn_D1";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Ind_Mlyn_D2;
	class MAP_Ind_Mlyn_D2: Land_Ind_Mlyn_D2
	{
		scope = 2;
		displayName = "I Ind_Mlyn_D2";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Ind_Stack_Big;
	class MAP_Ind_Stack_Big: Land_Ind_Stack_Big
	{
		scope = 2;
		displayName = "I Ind_Stack_Big";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Ind_MalyKomin;
	class MAP_Ind_MalyKomin: Land_Ind_MalyKomin
	{
		scope = 2;
		displayName = "I Ind_MalyKomin";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_komin;
	class MAP_komin: Land_komin
	{
		scope = 2;
		displayName = "I komin";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Misc_WaterStation;
	class MAP_Misc_WaterStation: Land_Misc_WaterStation
	{
		scope = 2;
		displayName = "R Misc_WaterStation";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Misc_PowerStation;
	class MAP_Misc_PowerStation: Land_Misc_PowerStation
	{
		scope = 2;
		displayName = "R Misc_PowerStation";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_trafostanica_mala;
	class MAP_trafostanica_mala: Land_trafostanica_mala
	{
		scope = 2;
		displayName = "R trafostanica_mala";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_trafostanica_velka;
	class MAP_trafostanica_velka: Land_trafostanica_velka
	{
		scope = 2;
		displayName = "R trafostanica_velka";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class MAP_PowLines_Transformer1: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "R PowLines_Transformer1";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\Structures\Misc_Powerlines\PowLines_Transformer1.p3d";
	};
	class MAP_PowLines_Transformer2: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "R PowLines_Transformer2";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\Structures\Misc_Powerlines\PowLines_Transformer2.p3d";
	};
	class MAP_PowLines_Conc1: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "R PowLines_Conc1";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\Structures\Misc_Powerlines\PowLines_Conc1.p3d";
	};
	class MAP_PowLines_Conc2: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "R PowLines_Conc2";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\Structures\Misc_Powerlines\PowLines_Conc2.p3d";
	};
	class MAP_PowLines_Conc3: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "R PowLines_Conc3";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\Structures\Misc_Powerlines\PowLines_Conc3.p3d";
	};
	class MAP_PowLines_ConcA: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "R PowLines_ConcA";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\Structures\Misc_Powerlines\PowLines_ConcA.p3d";
	};
	class MAP_PowLines_ConcL: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "R PowLines_ConcL";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\Structures\Misc_Powerlines\PowLines_ConcL.p3d";
	};
	class MAP_PowLines_Wood1: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "R PowLines_Wood1";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\Structures\Misc_Powerlines\PowLines_Wood1.p3d";
	};
	class MAP_PowLines_Wood2: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "R PowLines_Wood2";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\Structures\Misc_Powerlines\PowLines_Wood2.p3d";
	};
	class MAP_PowLines_WoodA: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "R PowLines_WoodA";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\Structures\Misc_Powerlines\PowLines_WoodA.p3d";
	};
	class MAP_PowLines_WoodL: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "R PowLines_WoodL";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\Structures\Misc_Powerlines\PowLines_WoodL.p3d";
	};
	class MAP_sloup_vn: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "W sloup_vn";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\misc\sloup_vn.p3d";
	};
	class MAP_sloupyelA: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "W sloupyelA";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\misc\sloupyelA.p3d";
	};
	class MAP_sloupyelE: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "W sloupyelE";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\misc\sloupyelE.p3d";
	};
	class MAP_sloupyelI: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "W sloupyelI";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\misc\sloupyelI.p3d";
	};
	class MAP_misc_amplion_conc: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "R misc_amplion_conc";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\Structures\Misc\Misc_Amplion\misc_amplion_conc.p3d";
	};
	class MAP_misc_amplion_wood: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "R misc_amplion_wood";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\Structures\Misc\Misc_Amplion\misc_amplion_wood.p3d";
	};
	class Land_A_FuelStation_Build;
	class MAP_A_FuelStation_Build: Land_A_FuelStation_Build
	{
		scope = 2;
		displayName = "R A_FuelStation_Build";
		icon = "\MAP_EU\icon\HF.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class MAP_A_FuelStation_Feed: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "R A_FuelStation_Feed";
		icon = "\MAP_EU\icon\HF.paa";
		model = "\CA\Structures\House\A_FuelStation\A_FuelStation_Feed.p3d";
	};
	class Land_A_FuelStation_Shed;
	class MAP_A_FuelStation_Shed: Land_A_FuelStation_Shed
	{
		scope = 2;
		displayName = "R A_FuelStation_Shed";
		icon = "\MAP_EU\icon\HF.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class MAP_A_FuelStation_Sign: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "R A_FuelStation_Sign";
		icon = "\MAP_EU\icon\HF.paa";
		model = "\CA\Structures\House\A_FuelStation\A_FuelStation_Sign.p3d";
	};
	class Land_Ind_TankSmall;
	class MAP_Ind_TankSmall: Land_Ind_TankSmall
	{
		scope = 2;
		displayName = "R Ind_TankSmall";
		icon = "\MAP_EU\icon\HF.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Ind_TankSmall2;
	class MAP_Ind_TankSmall2: Land_Ind_TankSmall2
	{
		scope = 2;
		displayName = "R Ind_TankSmall2";
		icon = "\MAP_EU\icon\HF.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Ind_TankBig;
	class MAP_Ind_TankBig: Land_Ind_TankBig
	{
		scope = 2;
		displayName = "R Ind_TankBig";
		icon = "\MAP_EU\icon\HF.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_IndPipe2_big_18;
	class MAP_IndPipe2_big_18: Land_IndPipe2_big_18
	{
		scope = 2;
		displayName = "R Ind_Garage01";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_IndPipe2_big_18ladder;
	class MAP_IndPipe2_big_18ladder: Land_IndPipe2_big_18ladder
	{
		scope = 2;
		displayName = "R IndPipe2_big_18ladder";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_IndPipe2_big_9;
	class MAP_IndPipe2_big_9: Land_IndPipe2_big_9
	{
		scope = 2;
		displayName = "R IndPipe2_big_9";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_IndPipe2_big_ground1;
	class MAP_IndPipe2_big_ground1: Land_IndPipe2_big_ground1
	{
		scope = 2;
		displayName = "R IndPipe2_big_ground1";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_IndPipe2_big_ground2;
	class MAP_IndPipe2_big_ground2: Land_IndPipe2_big_ground2
	{
		scope = 2;
		displayName = "R IndPipe2_big_ground2";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_IndPipe2_big_support;
	class MAP_IndPipe2_big_support: Land_IndPipe2_big_support
	{
		scope = 2;
		displayName = "R IndPipe2_big_support";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_IndPipe2_bigBuild1_L;
	class MAP_IndPipe2_bigBuild1_L: Land_IndPipe2_bigBuild1_L
	{
		scope = 2;
		displayName = "R IndPipe2_bigBuild1_L";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_IndPipe2_bigBuild1_R;
	class MAP_IndPipe2_bigBuild1_R: Land_IndPipe2_bigBuild1_R
	{
		scope = 2;
		displayName = "R IndPipe2_bigBuild1_R";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_IndPipe2_bigBuild2_L;
	class MAP_IndPipe2_bigBuild2_L: Land_IndPipe2_bigBuild2_L
	{
		scope = 2;
		displayName = "R IndPipe2_bigBuild2_L";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_IndPipe2_bigBuild2_R;
	class MAP_IndPipe2_bigBuild2_R: Land_IndPipe2_bigBuild2_R
	{
		scope = 2;
		displayName = "R IndPipe2_bigBuild2_R";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_IndPipe2_bigL_L;
	class MAP_IndPipe2_bigL_L: Land_IndPipe2_bigL_L
	{
		scope = 2;
		displayName = "R IndPipe2_bigL_L";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_IndPipe2_bigL_R;
	class MAP_IndPipe2_bigL_R: Land_IndPipe2_bigL_R
	{
		scope = 2;
		displayName = "R IndPipe2_bigL_R";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_IndPipe2_Small_9;
	class MAP_IndPipe2_Small_9: Land_IndPipe2_Small_9
	{
		scope = 2;
		displayName = "R IndPipe2_Small_9";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_IndPipe2_Small_ground1;
	class MAP_IndPipe2_Small_ground1: Land_IndPipe2_Small_ground1
	{
		scope = 2;
		displayName = "R IndPipe2_Small_ground1";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_IndPipe2_Small_ground2;
	class MAP_IndPipe2_Small_ground2: Land_IndPipe2_Small_ground2
	{
		scope = 2;
		displayName = "R IndPipe2_Small_ground2";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_IndPipe2_SmallBuild1_L;
	class MAP_IndPipe2_SmallBuild1_L: Land_IndPipe2_SmallBuild1_L
	{
		scope = 2;
		displayName = "R IndPipe2_SmallBuild1_L";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_IndPipe2_SmallBuild1_R;
	class MAP_IndPipe2_SmallBuild1_R: Land_IndPipe2_SmallBuild1_R
	{
		scope = 2;
		displayName = "R IndPipe2_SmallBuild1_R";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_IndPipe2_SmallBuild2_L;
	class MAP_IndPipe2_SmallBuild2_L: Land_IndPipe2_SmallBuild2_L
	{
		scope = 2;
		displayName = "R IndPipe2_SmallBuild2_L";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_IndPipe2_SmallBuild2_R;
	class MAP_IndPipe2_SmallBuild2_R: Land_IndPipe2_SmallBuild2_R
	{
		scope = 2;
		displayName = "R IndPipe2_SmallBuild2_R";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_IndPipe2_SmallL_L;
	class MAP_IndPipe2_SmallL_L: Land_IndPipe2_SmallL_L
	{
		scope = 2;
		displayName = "R IndPipe2_SmallL_L";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_IndPipe2_SmallL_R;
	class MAP_IndPipe2_SmallL_R: Land_IndPipe2_SmallL_R
	{
		scope = 2;
		displayName = "R IndPipe2_SmallL_R";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_IndPipe2_T_L;
	class MAP_IndPipe2_T_L: Land_IndPipe2_T_L
	{
		scope = 2;
		displayName = "R IndPipe2_T_L";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_IndPipe2_T_R;
	class MAP_IndPipe2_T_R: Land_IndPipe2_T_R
	{
		scope = 2;
		displayName = "R IndPipe2_T_R";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class MAP_IndPipe1_20m: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "R IndPipe1_20m";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\Structures\Ind_Pipeline\IndPipe1\IndPipe1_20m.p3d";
	};
	class MAP_IndPipe1_45degL: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "R IndPipe1_45degL";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\Structures\Ind_Pipeline\IndPipe1\IndPipe1_45degL.p3d";
	};
	class MAP_IndPipe1_45degR: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "R IndPipe1_45degR";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\Structures\Ind_Pipeline\IndPipe1\IndPipe1_45degR.p3d";
	};
	class MAP_IndPipe1_90degL: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "R IndPipe1_90degL";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\Structures\Ind_Pipeline\IndPipe1\IndPipe1_90degL.p3d";
	};
	class MAP_IndPipe1_90degR: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "R IndPipe1_90degR";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\Structures\Ind_Pipeline\IndPipe1\IndPipe1_90degR.p3d";
	};
	class MAP_IndPipe1_broken: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "R IndPipe1_broken";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\Structures\Ind_Pipeline\IndPipe1\IndPipe1_broken.p3d";
	};
	class MAP_IndPipe1_ground: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "R IndPipe1_ground";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\Structures\Ind_Pipeline\IndPipe1\IndPipe1_ground.p3d";
	};
	class MAP_IndPipe1_ground2: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "R IndPipe1_ground2";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\Structures\Ind_Pipeline\IndPipe1\IndPipe1_ground2.p3d";
	};
	class Land_IndPipe1_stair;
	class MAP_IndPipe1_stair: Land_IndPipe1_stair
	{
		scope = 2;
		displayName = "R IndPipe1_stair";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class MAP_IndPipe1_UL: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "R IndPipe1_UL";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\Structures\Ind_Pipeline\IndPipe1\IndPipe1_UL.p3d";
	};
	class MAP_IndPipe1_UR: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "R IndPipe1_UR";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\Structures\Ind_Pipeline\IndPipe1\IndPipe1_UR.p3d";
	};
	class MAP_IndPipe1_Uup: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "R IndPipe1_Uup";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\Structures\Ind_Pipeline\IndPipe1\IndPipe1_Uup.p3d";
	};
	class MAP_IndPipe1_valve: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "R IndPipe1_valve";
		icon = "\MAP_EU\icon\HQ.paa";
		model = "\CA\Structures\Ind_Pipeline\IndPipe1\IndPipe1_valve.p3d";
	};
	class MAP_church_cross_1: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "P church_cross_1";
		icon = "\MAP_EU\icon\EG.paa";
		model = "\CA\Structures\House\Church_Cross\church_cross_1.p3d";
	};
	class MAP_church_cross_1a: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "P church_cross_1a";
		icon = "\MAP_EU\icon\EG.paa";
		model = "\CA\Structures\House\Church_Cross\church_cross_1a.p3d";
	};
	class MAP_hrobecek: MAP_Indus_DTr
	{
		scope = 2;
		displayName = "P hrobecek";
		icon = "\MAP_EU\icon\EG.paa";
		model = "\CA\buildings\misc\hrobecek.p3d";
	};
	class MAP_hrobecek_krizek1: MAP_Indus_DTr
	{
		scope = 2;
		displayName = "P hrobecek_krizek1";
		icon = "\MAP_EU\icon\EG.paa";
		model = "\CA\buildings\misc\hrobecek_krizek1.p3d";
	};
	class MAP_hrobecek_krizek2: MAP_Indus_DTr
	{
		scope = 2;
		displayName = "P hrobecek_krizek2";
		icon = "\MAP_EU\icon\EG.paa";
		model = "\CA\buildings\misc\hrobecek_krizek2.p3d";
	};
	class MAP_hrobecek_krizekhelma: MAP_Indus_DTr
	{
		scope = 2;
		displayName = "P hrobecek_krizekhelma";
		icon = "\MAP_EU\icon\EG.paa";
		model = "\CA\buildings\misc\hrobecek_krizekhelma.p3d";
	};
	class MAP_Church_tomb_1: MAP_Indus_DTr
	{
		scope = 2;
		displayName = "P Church_tomb_1";
		icon = "\MAP_EU\icon\EG.paa";
		model = "\CA\Structures\Misc\Church\Church_tomb_1.p3d";
	};
	class MAP_Church_tomb_2: MAP_Indus_DTr
	{
		scope = 2;
		displayName = "P Church_tomb_2";
		icon = "\MAP_EU\icon\EG.paa";
		model = "\CA\Structures\Misc\Church\Church_tomb_2.p3d";
	};
	class MAP_Church_tomb_3: MAP_Indus_DTr
	{
		scope = 2;
		displayName = "P Church_tomb_3";
		icon = "\MAP_EU\icon\EG.paa";
		model = "\CA\Structures\Misc\Church\Church_tomb_3.p3d";
	};
	class MAP_sarcophagus: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "P sarcophagus";
		icon = "\MAP_EU\icon\EG.paa";
		model = "\CA\Structures\Furniture\Cases\sarcophagus\sarcophagus.p3d";
	};
	class Land_kostel;
	class MAP_kostel: Land_kostel
	{
		scope = 2;
		displayName = "P kostel";
		icon = "\MAP_EU\icon\HC.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_kostel3;
	class MAP_kostel3: Land_kostel3
	{
		scope = 2;
		displayName = "P kostel3";
		icon = "\MAP_EU\icon\HC.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Church_01;
	class MAP_Church_01: Land_Church_01
	{
		scope = 2;
		displayName = "P Church_01";
		icon = "\MAP_EU\icon\HC.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Church_02;
	class MAP_Church_02: Land_Church_02
	{
		scope = 2;
		displayName = "P Church_02";
		icon = "\MAP_EU\icon\HC.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Church_02a;
	class MAP_Church_02a: Land_Church_02a
	{
		scope = 2;
		displayName = "P Church_02a";
		icon = "\MAP_EU\icon\HC.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Church_03;
	class MAP_Church_03: Land_Church_03
	{
		scope = 2;
		displayName = "P Church_03";
		icon = "\MAP_EU\icon\HC.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Church_03_dam;
	class MAP_Church_03_dam: Land_Church_03_dam
	{
		scope = 2;
		displayName = "P Church_03_dam";
		icon = "\MAP_EU\icon\HC.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class MAP_antenna: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "P antenna";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\antenna.p3d";
	};
	class Land_vysilac_FM2;
	class MAP_vysilac_FM2: Land_vysilac_FM2
	{
		scope = 2;
		displayName = "P vysilac_FM2";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_Vysilac_FM;
	class MAP_Vysilac_FM: Land_Vysilac_FM
	{
		scope = 2;
		displayName = "P Vysilac_FM";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_telek1;
	class MAP_telek1: Land_telek1
	{
		scope = 2;
		displayName = "P telek1";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_A_TVTower_Base;
	class MAP_A_TVTower_Base: Land_A_TVTower_Base
	{
		scope = 2;
		displayName = "P A_TVTower_Base";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_A_TVTower_Mid;
	class MAP_A_TVTower_Mid: Land_A_TVTower_Mid
	{
		scope = 2;
		displayName = "P A_TVTower_Mid";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_A_TVTower_Top;
	class MAP_A_TVTower_Top: Land_A_TVTower_Top
	{
		scope = 2;
		displayName = "P A_TVTower_Top";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class MAP_A_AdvertisingColumn: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "P A_AdvertisingColumn";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings2\A_AdvertisingColumn\A_AdvertColumn.p3d";
	};
	class Land_A_MunicipalOffice;
	class MAP_A_MunicipalOffice: Land_A_MunicipalOffice
	{
		scope = 2;
		displayName = "P A_MunicipalOffice";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_A_statue01;
	class MAP_A_statue01: Land_A_statue01
	{
		scope = 2;
		displayName = "P A_statue01";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_A_statue02;
	class MAP_A_statue02: Land_A_statue02
	{
		scope = 2;
		displayName = "P A_statue02";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class MAP_T34: MAP_Indus_DBu
	{
		scope = 2;
		displayName = "P T34";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings2\A_Statue\T34.p3d";
	};
	class Land_A_Hospital;
	class MAP_A_Hospital: Land_A_Hospital
	{
		scope = 2;
		displayName = "H A_Hospital";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_A_Hospital_dam;
	class MAP_A_Hospital_dam: Land_A_Hospital_dam
	{
		scope = 2;
		displayName = "H A_Hospital_dam";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_ZalChata;
	class MAP_ZalChata: Land_ZalChata
	{
		scope = 2;
		displayName = "H ZalChata";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_sara_domek_hospoda;
	class MAP_sara_domek_hospoda: Land_sara_domek_hospoda
	{
		scope = 2;
		displayName = "H sara_domek_hospoda";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class Land_HouseB_Tenement;
	class MAP_HouseB_Tenement: Land_HouseB_Tenement
	{
		scope = 2;
		displayName = "H HouseB_Tenement";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EUIndus";
		accuracy = 1000;
	};
	class MAP_Rails_Base: Static
	{
		displayName = "";
		accuracy = 0.1;
		vehicleClass = "MAP_EURail";
		model = "";
		nameSound = "";
		animated = 0;
		simulation = "house";
		cost = 0;
		armor = 1000;
		ladders[] = {};
		placement = "vertical";
	};
	class MAP_Rails_DNo: MAP_Rails_Base
	{
		destrType = "DestructNo";
		accuracy = 1000;
	};
	class MAP_Rails_DTe: MAP_Rails_Base
	{
		destrType = "DestructTent";
		accuracy = 1000;
	};
	class MAP_Rails_DTr: MAP_Rails_Base
	{
		destrType = "DestructTree";
		accuracy = 1000;
	};
	class MAP_Rails_DBu: MAP_Rails_Base
	{
		destrType = "DestructBuilding";
		accuracy = 1000;
		class DestructionEffects
		{
			class HouseDestr
			{
				simulation = "destroy";
				type = "DelayedDestruction";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class MAP_rails_25: MAP_Rails_DNo
	{
		scope = 2;
		displayName = "T rails_25";
		icon = "\MAP_EU\icon\TL.paa";
		model = "\CA\Structures\Rail\Railway\rails_25.p3d";
	};
	class MAP_rails_v_LB_RE: MAP_Rails_DNo
	{
		scope = 2;
		displayName = "T rails_v_LB_RE";
		icon = "\MAP_EU\icon\TLx.paa";
		model = "\CA\Structures\Rail\Railway\rails_v_LB_RE.p3d";
	};
	class MAP_rails_v_LE_RB: MAP_Rails_DNo
	{
		scope = 2;
		displayName = "T rails_v_LE_RB";
		icon = "\MAP_EU\icon\TLx.paa";
		model = "\CA\Structures\Rail\Railway\rails_v_LE_RB.p3d";
	};
	class MAP_rails_v_SP: MAP_Rails_DNo
	{
		scope = 2;
		displayName = "T rails_v_SP";
		icon = "\MAP_EU\icon\TLx.paa";
		model = "\CA\Structures\Rail\Railway\rails_v_SP.p3d";
	};
	class MAP_rails_v1_LB_RE: MAP_Rails_DNo
	{
		scope = 2;
		displayName = "T rails_v1_LB_RE";
		icon = "\MAP_EU\icon\TLx.paa";
		model = "\CA\Structures\Rail\Railway\rails_v1_LB_RE.p3d";
	};
	class MAP_rails_v1_LE_RB: MAP_Rails_DNo
	{
		scope = 2;
		displayName = "T rails_v1_LE_RB";
		icon = "\MAP_EU\icon\TLx.paa";
		model = "\CA\Structures\Rail\Railway\rails_v1_LE_RB.p3d";
	};
	class MAP_rails_up_25: MAP_Rails_DNo
	{
		scope = 2;
		displayName = "T rails_up_25";
		icon = "\MAP_EU\icon\TL.paa";
		model = "\CA\Structures\Rail\Railway\rails_up_25.p3d";
	};
	class MAP_rails_up_40: MAP_Rails_DNo
	{
		scope = 2;
		displayName = "T rails_up_40";
		icon = "\MAP_EU\icon\TL.paa";
		model = "\CA\Structures\Rail\Railway\rails_up_40.p3d";
	};
	class MAP_rails_down_25: MAP_Rails_DNo
	{
		scope = 2;
		displayName = "T rails_down_25";
		icon = "\MAP_EU\icon\TL.paa";
		model = "\CA\Structures\Rail\Railway\rails_down_25.p3d";
	};
	class MAP_rails_down_40: MAP_Rails_DNo
	{
		scope = 2;
		displayName = "T rails_down_40";
		icon = "\MAP_EU\icon\TL.paa";
		model = "\CA\Structures\Rail\Railway\rails_down_40.p3d";
	};
	class MAP_rails_curve_L25_10: MAP_Rails_DNo
	{
		scope = 2;
		displayName = "T rails_curve_L25_10";
		icon = "\MAP_EU\icon\TC.paa";
		model = "\CA\Structures\Rail\Railway\rails_curve_L25_10.p3d";
	};
	class MAP_rails_curve_R25_10: MAP_Rails_DNo
	{
		scope = 2;
		displayName = "T rails_curve_R25_10";
		icon = "\MAP_EU\icon\TC.paa";
		model = "\CA\Structures\Rail\Railway\rails_curve_R25_10.p3d";
	};
	class MAP_rails_linebreak_concrete: MAP_Rails_DNo
	{
		scope = 2;
		displayName = "T rails_linebreak_concrete";
		icon = "\MAP_EU\icon\TE.paa";
		model = "\CA\Structures\Rail\Railway\rails_linebreak_concrete.p3d";
	};
	class MAP_rails_linebreak_iron: MAP_Rails_DNo
	{
		scope = 2;
		displayName = "T rails_linebreak_iron";
		icon = "\MAP_EU\icon\TE.paa";
		model = "\CA\Structures\Rail\Railway\rails_linebreak_iron.p3d";
	};
	class MAP_rails_passing_10: MAP_Rails_DNo
	{
		scope = 2;
		displayName = "T rails_passing_10";
		icon = "\MAP_EU\icon\TL.paa";
		model = "\CA\Structures\Rail\Railway\rails_passing_10.p3d";
	};
	class MAP_rails_passing_25: MAP_Rails_DNo
	{
		scope = 2;
		displayName = "T rails_passing_25";
		icon = "\MAP_EU\icon\TL.paa";
		model = "\CA\Structures\Rail\Railway\rails_passing_25.p3d";
	};
	class MAP_rails_turnout_L: MAP_Rails_DNo
	{
		scope = 2;
		displayName = "T rails_turnout_L";
		icon = "\MAP_EU\icon\TCTL.paa";
		model = "\CA\Structures\Rail\Railway\rails_turnout_L.p3d";
	};
	class MAP_rails_turnout_R: MAP_Rails_DNo
	{
		scope = 2;
		displayName = "T rails_turnout_R";
		icon = "\MAP_EU\icon\TCTR.paa";
		model = "\CA\Structures\Rail\Railway\rails_turnout_R.p3d";
	};
	class MAP_railsN_25: MAP_Rails_DNo
	{
		scope = 2;
		displayName = "T railsN_25";
		icon = "\MAP_EU\icon\TL.paa";
		model = "\CA\Structures\Rail\Railway\railsN_25.p3d";
	};
	class MAP_railsN_40: MAP_Rails_DNo
	{
		scope = 2;
		displayName = "T railsN_40";
		icon = "\MAP_EU\icon\TL.paa";
		model = "\CA\Structures\Rail\Railway\railsN_40.p3d";
	};
	class MAP_railsN_curve_L25_5: MAP_Rails_DNo
	{
		scope = 2;
		displayName = "T railsN_curve_L25_5";
		icon = "\MAP_EU\icon\TC.paa";
		model = "\CA\Structures\Rail\Railway\railsN_curve_L25_5.p3d";
	};
	class MAP_railsN_curve_L25_10: MAP_Rails_DNo
	{
		scope = 2;
		displayName = "T railsN_curve_L25_10";
		icon = "\MAP_EU\icon\TC.paa";
		model = "\CA\Structures\Rail\Railway\railsN_curve_L25_10.p3d";
	};
	class MAP_railsN_curve_L30_20: MAP_Rails_DNo
	{
		scope = 2;
		displayName = "T railsN_curve_L30_20";
		icon = "\MAP_EU\icon\TC.paa";
		model = "\CA\Structures\Rail\Railway\railsN_curve_L30_20.p3d";
	};
	class MAP_railsN_curve_R25_5: MAP_Rails_DNo
	{
		scope = 2;
		displayName = "T railsN_curve_R25_5";
		icon = "\MAP_EU\icon\TC.paa";
		model = "\CA\Structures\Rail\Railway\railsN_curve_R25_5.p3d";
	};
	class MAP_railsN_curve_R25_10: MAP_Rails_DNo
	{
		scope = 2;
		displayName = "T railsN_curve_R25_10";
		icon = "\MAP_EU\icon\TC.paa";
		model = "\CA\Structures\Rail\Railway\railsN_curve_R25_10.p3d";
	};
	class MAP_railsN_curve_R30_20: MAP_Rails_DNo
	{
		scope = 2;
		displayName = "T railsN_curve_R30_20";
		icon = "\MAP_EU\icon\TC.paa";
		model = "\CA\Structures\Rail\Railway\railsN_curve_R30_20.p3d";
	};
	class MAP_railsN_turnout_L: MAP_Rails_DNo
	{
		scope = 2;
		displayName = "T railsN_turnout_L";
		icon = "\MAP_EU\icon\TCTL.paa";
		model = "\CA\Structures\Rail\Railway\railsN_turnout_L.p3d";
	};
	class MAP_railsN_turnout_R: MAP_Rails_DNo
	{
		scope = 2;
		displayName = "T railsN_turnout_R";
		icon = "\MAP_EU\icon\TCTR.paa";
		model = "\CA\Structures\Rail\Railway\railsN_turnout_R.p3d";
	};
	class Land_rails_bridge_40;
	class MAP_rails_bridge_40: Land_rails_bridge_40
	{
		scope = 2;
		displayName = "T rails_bridge_40";
		icon = "\MAP_EU\icon\B.paa";
		vehicleClass = "MAP_EURail";
		accuracy = 1000;
	};
	class Land_Rail_House_01;
	class MAP_Rail_House_01: Land_Rail_House_01
	{
		scope = 2;
		displayName = "B Rail_House_01";
		icon = "\MAP_EU\icon\HQ.paa";
		vehicleClass = "MAP_EURail";
		accuracy = 1000;
	};
	class Land_rail_station_big;
	class MAP_rail_station_big: Land_rail_station_big
	{
		scope = 2;
		displayName = "B rail_station_big";
		icon = "\MAP_EU\icon\HH.paa";
		vehicleClass = "MAP_EURail";
		accuracy = 1000;
	};
	class MAP_Rail_Platform_Cross: MAP_Rails_DNo
	{
		scope = 2;
		displayName = "B Rail_Platform_Cross";
		icon = "\MAP_EU\icon\L.paa";
		model = "\CA\Structures\Rail\Rail_Platform\Rail_Platform_Cross.p3d";
	};
	class MAP_Rail_Platform_Segment: MAP_Rails_DNo
	{
		scope = 2;
		displayName = "B Rail_Platform_Segment";
		icon = "\MAP_EU\icon\L.paa";
		model = "\CA\Structures\Rail\Rail_Platform\Rail_Platform_Segment.p3d";
	};
	class MAP_Rail_Platform_Start: MAP_Rails_DNo
	{
		scope = 2;
		displayName = "B Rail_Platform_Start";
		icon = "\MAP_EU\icon\L.paa";
		model = "\CA\Structures\Rail\Rail_Platform\Rail_Platform_Start.p3d";
	};
	class MAP_rail_najazdovarampa: MAP_Rails_DNo
	{
		scope = 2;
		displayName = "B rail_najazdovarampa";
		icon = "\MAP_EU\icon\L.paa";
		model = "\CA\Structures\Rail\Rail_Misc\rail_najazdovarampa.p3d";
	};
	class Land_loco_742_blue;
	class MAP_loco_742_blue: Land_loco_742_blue
	{
		scope = 2;
		displayName = "W loco_742_blue";
		icon = "\MAP_EU\icon\TW.paa";
		vehicleClass = "MAP_EURail";
		accuracy = 1000;
	};
	class Land_loco_742_red;
	class MAP_loco_742_red: Land_loco_742_red
	{
		scope = 2;
		displayName = "W loco_742_red";
		icon = "\MAP_EU\icon\TW.paa";
		vehicleClass = "MAP_EURail";
		accuracy = 1000;
	};
	class Land_wagon_box;
	class MAP_wagon_box: Land_wagon_box
	{
		scope = 2;
		displayName = "W wagon_box";
		icon = "\MAP_EU\icon\TW.paa";
		vehicleClass = "MAP_EURail";
		accuracy = 1000;
	};
	class Land_wagon_flat;
	class MAP_wagon_flat: Land_wagon_flat
	{
		scope = 2;
		displayName = "W wagon_flat";
		icon = "\MAP_EU\icon\TW.paa";
		vehicleClass = "MAP_EURail";
		accuracy = 1000;
	};
	class Land_wagon_tanker;
	class MAP_wagon_tanker: Land_wagon_tanker
	{
		scope = 2;
		displayName = "W wagon_tanker";
		icon = "\MAP_EU\icon\TW.paa";
		vehicleClass = "MAP_EURail";
		accuracy = 1000;
	};
	class Land_Rail_Semafor;
	class MAP_Rail_Semafor: Land_Rail_Semafor
	{
		scope = 2;
		displayName = "S Rail_Semafor";
		icon = "\MAP_EU\icon\ESA.paa";
		vehicleClass = "MAP_EURail";
		accuracy = 1000;
	};
	class Land_Rail_Zavora;
	class MAP_Rail_Zavora: Land_Rail_Zavora
	{
		scope = 2;
		displayName = "S Rail_Zavora";
		icon = "\MAP_EU\icon\SBG.paa";
		vehicleClass = "MAP_EURail";
		accuracy = 1000;
	};
	class MAP_rail_50km: MAP_Rails_DTr
	{
		scope = 2;
		displayName = "S rail_50km";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\Structures\Rail\Rail_Misc\rail_50km.p3d";
	};
	class MAP_rail_o25m_Priecestie: MAP_Rails_DTr
	{
		scope = 2;
		displayName = "S rail_o25m_Priecestie";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\Structures\Rail\Rail_Misc\rail_o25m_Priecestie.p3d";
	};
	class MAP_rail_Priecestie: MAP_Rails_DTr
	{
		scope = 2;
		displayName = "S rail_Priecestie";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\Structures\Rail\Rail_Misc\rail_Priecestie.p3d";
	};
	class MAP_rail_KoniecNastupista: MAP_Rails_DTr
	{
		scope = 2;
		displayName = "S rail_KoniecNastupista";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\Structures\Rail\Rail_Misc\rail_KoniecNastupista.p3d";
	};
	class MAP_sign_balota: MAP_Rails_DBu
	{
		scope = 2;
		displayName = "P sign_balota";
		icon = "\MAP_EU\icon\BBu.paa";
		model = "\CA\Structures\Rail\Rail_Station_big\sign_balota.p3d";
	};
	class MAP_sign_berezino: MAP_Rails_DBu
	{
		scope = 2;
		displayName = "P sign_berezino";
		icon = "\MAP_EU\icon\BBu.paa";
		model = "\CA\Structures\Rail\Rail_Station_big\sign_berezino.p3d";
	};
	class MAP_sign_chernogorsk: MAP_Rails_DBu
	{
		scope = 2;
		displayName = "P sign_chernogorsk";
		icon = "\MAP_EU\icon\BBu.paa";
		model = "\CA\Structures\Rail\Rail_Station_big\sign_chernogorsk.p3d";
	};
	class MAP_sign_elektrozavodsk: MAP_Rails_DBu
	{
		scope = 2;
		displayName = "P sign_elektrozavodsk";
		icon = "\MAP_EU\icon\BBu.paa";
		model = "\CA\Structures\Rail\Rail_Station_big\sign_elektrozavodsk.p3d";
	};
	class MAP_sign_kamenka: MAP_Rails_DBu
	{
		scope = 2;
		displayName = "P sign_kamenka";
		icon = "\MAP_EU\icon\BBu.paa";
		model = "\CA\Structures\Rail\Rail_Station_big\sign_kamenka.p3d";
	};
	class MAP_sign_kamyshovo: MAP_Rails_DBu
	{
		scope = 2;
		displayName = "P sign_kamyshovo";
		icon = "\MAP_EU\icon\BBu.paa";
		model = "\CA\Structures\Rail\Rail_Station_big\sign_kamyshovo.p3d";
	};
	class MAP_sign_komarovo: MAP_Rails_DBu
	{
		scope = 2;
		displayName = "P sign_komarovo";
		icon = "\MAP_EU\icon\BBu.paa";
		model = "\CA\Structures\Rail\Rail_Station_big\sign_komarovo.p3d";
	};
	class MAP_sign_prigorodki: MAP_Rails_DBu
	{
		scope = 2;
		displayName = "P sign_prigorodki";
		icon = "\MAP_EU\icon\BBu.paa";
		model = "\CA\Structures\Rail\Rail_Station_big\sign_prigorodki.p3d";
	};
	class MAP_sign_solnichnyi: MAP_Rails_DBu
	{
		scope = 2;
		displayName = "P sign_solnichnyi";
		icon = "\MAP_EU\icon\BBu.paa";
		model = "\CA\Structures\Rail\Rail_Station_big\sign_solnichnyi.p3d";
	};
	class MAP_Military_Base: Static
	{
		displayName = "";
		accuracy = 0.1;
		vehicleClass = "MAP_EUMilitary";
		model = "";
		nameSound = "";
		animated = 0;
		simulation = "house";
		cost = 0;
		armor = 1000;
		ladders[] = {};
		placement = "vertical";
	};
	class MAP_Military_DNo: MAP_Military_Base
	{
		accuracy = 1000;
	};
	class MAP_Military_DTe: MAP_Military_Base
	{
		destrType = "DestructTent";
		accuracy = 1000;
	};
	class MAP_Military_DTr: MAP_Military_Base
	{
		destrType = "DestructTree";
		accuracy = 1000;
	};
	class MAP_Military_DBu: MAP_Military_Base
	{
		destrType = "DestructBuilding";
		accuracy = 1000;
		class DestructionEffects
		{
			class HouseDestr
			{
				simulation = "destroy";
				type = "DelayedDestruction";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class MAP_shooting_range: MAP_Military_DBu
	{
		scope = 2;
		displayName = "L shooting_range";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\shooting_range\shooting_range.p3d";
	};
	class MAP_obihacka: MAP_Military_DBu
	{
		scope = 2;
		displayName = "L obihacka";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\obihacka.p3d";
	};
	class MAP_podlejzacka: MAP_Military_DBu
	{
		scope = 2;
		displayName = "L podlejzacka";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\podlejzacka.p3d";
	};
	class MAP_climbing_obstacle: MAP_Military_DBu
	{
		scope = 2;
		displayName = "L climbing_obstacle";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Misc\Armory\climbing_obstacle\climbing_obstacle.p3d";
	};
	class MAP_prebehlavka: MAP_Military_DBu
	{
		scope = 2;
		displayName = "L prebehlavka";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\prebehlavka.p3d";
	};
	class MAP_prolejzacka: MAP_Military_DBu
	{
		scope = 2;
		displayName = "L prolejzacka";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\prolejzacka.p3d";
	};
	class MAP_plot_provizorni: MAP_Military_DTr
	{
		scope = 2;
		displayName = "W plot_provizorni";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plot_provizorni.p3d";
	};
	class MAP_Fort_Razorwire: MAP_Military_DBu
	{
		scope = 2;
		displayName = "W Fort_Razorwire";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\Fort_Razorwire.p3d";
	};
	class MAP_Barbedwire: MAP_Military_DBu
	{
		scope = 2;
		displayName = "W Barbedwire";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\Barbedwire.p3d";
	};
	class MAP_BarbGate: MAP_Military_DTr
	{
		scope = 2;
		displayName = "W BarbGate";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc2\BarbGate.p3d";
	};
	class MAP_dragonTeeth: MAP_Military_DBu
	{
		scope = 2;
		displayName = "W dragonTeeth";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\dragonTeeth\dragonTeeth.p3d";
	};
	class MAP_dragonTeethBig: MAP_Military_DBu
	{
		scope = 2;
		displayName = "W dragonTeethBig";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\dragonTeeth\dragonTeethBig.p3d";
	};
	class MAP_Fort_Barricade: MAP_Military_DBu
	{
		scope = 2;
		displayName = "W Fort_Barricade";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\Fort_Barricade.p3d";
	};
	class MAP_A_tent: MAP_Military_DBu
	{
		scope = 2;
		displayName = "T A_tent";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\A_tent.p3d";
	};
	class MAP_Astan: MAP_Military_DTe
	{
		scope = 2;
		displayName = "T Astan";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\tents\Astan.p3d";
	};
	class MAP_tent_small_west: MAP_Military_DBu
	{
		scope = 2;
		displayName = "T tent_small_west";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\tent_small_west.p3d";
	};
	class MAP_Stan: MAP_Military_DTe
	{
		scope = 2;
		displayName = "T Stan";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\tents\Stan.p3d";
	};
	class MAP_MASH: MAP_Military_DTe
	{
		scope = 2;
		displayName = "T MASH";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\tents\MASH.p3d";
	};
	class MAP_Stan_east: MAP_Military_DTe
	{
		scope = 2;
		displayName = "T Stan_east";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\tents\Stan_east.p3d";
	};
	class MAP_tent_east: MAP_Military_DBu
	{
		scope = 2;
		displayName = "T tent_east";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\tent_east.p3d";
	};
	class MAP_tent_west: MAP_Military_DBu
	{
		scope = 2;
		displayName = "T tent_west";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\tent_west.p3d";
	};
	class MAP_tent2_west: MAP_Military_DBu
	{
		scope = 2;
		displayName = "T tent2_west";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\tent2_west.p3d";
	};
	class MAP_Camo_Box: MAP_Military_DTe
	{
		scope = 2;
		displayName = "C Camo_Box";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\tents\Camo_Box.p3d";
	};
	class MAP_Pristresek: MAP_Military_DTe
	{
		scope = 2;
		displayName = "C Pristresek";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\tents\Pristresek.p3d";
	};
	class MAP_CamoNet_EAST: MAP_Military_DBu
	{
		scope = 2;
		displayName = "C CamoNet_EAST";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\CamoNet_EAST.p3d";
	};
	class MAP_CamoNet_EAST_var1: MAP_Military_DBu
	{
		scope = 2;
		displayName = "C CamoNet_EAST_var1";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\CamoNet_EAST_var1.p3d";
	};
	class MAP_CamoNet_NATO: MAP_Military_DBu
	{
		scope = 2;
		displayName = "C CamoNet_NATO";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\CamoNet_NATO.p3d";
	};
	class MAP_CamoNet_NATO_var1: MAP_Military_DBu
	{
		scope = 2;
		displayName = "C CamoNet_NATO_var1";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\CamoNet_NATO_var1.p3d";
	};
	class MAP_CamoNet_Support: MAP_Military_DBu
	{
		scope = 2;
		displayName = "C CamoNet_Support";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\CamoNet_Support.p3d";
	};
	class MAP_CamoNetB_EAST: MAP_Military_DBu
	{
		scope = 2;
		displayName = "C CamoNetB_EAST";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\CamoNetB_EAST.p3d";
	};
	class MAP_CamoNetB_NATO: MAP_Military_DBu
	{
		scope = 2;
		displayName = "C CamoNetB_NATO";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\CamoNetB_NATO.p3d";
	};
	class MAP_Fort_EnvelopeSmall: MAP_Military_DBu
	{
		scope = 2;
		displayName = "S Fort_EnvelopeSmall";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\Fort_EnvelopeSmall.p3d";
	};
	class MAP_Fort_EnvelopeBig: MAP_Military_DBu
	{
		scope = 2;
		displayName = "S Fort_EnvelopeBig";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\Fort_EnvelopeBig.p3d";
	};
	class MAP_GuardShed: MAP_Military_DBu
	{
		scope = 2;
		displayName = "S GuardShed";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc2\GuardShed.p3d";
	};
	class MAP_Pristresek_mensi: MAP_Military_DTe
	{
		scope = 2;
		displayName = "S Pristresek_mensi";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\tents\Pristresek_mensi.p3d";
	};
	class MAP_Fortress_01: MAP_Military_DTe
	{
		scope = 2;
		displayName = "S Fortress_01";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\tents\Fortress_01.p3d";
	};
	class MAP_Fortress_02: MAP_Military_DTe
	{
		scope = 2;
		displayName = "S Fortress_02";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\tents\Fortress_02.p3d";
	};
	class MAP_fortified_nest_small: MAP_Military_DBu
	{
		scope = 2;
		displayName = "S fortified_nest_small";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\fortified_nest_small.p3d";
	};
	class MAP_fortified_nest_big: MAP_Military_DBu
	{
		scope = 2;
		displayName = "S fortified_nest_big";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\fortified_nest_big.p3d";
	};
	class MAP_fort_watchtower: MAP_Military_DBu
	{
		scope = 2;
		displayName = "S fort_watchtower";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\fort_watchtower.p3d";
	};
	class MAP_BagFenceCorner: MAP_Military_DBu
	{
		scope = 2;
		displayName = "S BagFenceCorner";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc2\BagFenceCorner.p3d";
	};
	class MAP_BagFenceEnd: MAP_Military_DBu
	{
		scope = 2;
		displayName = "S BagFenceEnd";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc2\BagFenceEnd.p3d";
	};
	class MAP_BagFenceLong: MAP_Military_DBu
	{
		scope = 2;
		displayName = "S BagFenceLong";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc2\BagFenceLong.p3d";
	};
	class MAP_BagFenceRound: MAP_Military_DBu
	{
		scope = 2;
		displayName = "S BagFenceRound";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc2\BagFenceRound.p3d";
	};
	class MAP_BagFenceShort: MAP_Military_DBu
	{
		scope = 2;
		displayName = "S BagFenceShort";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc2\BagFenceShort.p3d";
	};
	class MAP_fort_bagfence_corner: MAP_Military_DBu
	{
		scope = 2;
		displayName = "S fort_bagfence_corner";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\fort_bagfence_corner.p3d";
	};
	class MAP_fort_bagfence_long: MAP_Military_DBu
	{
		scope = 2;
		displayName = "S fort_bagfence_long";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\fort_bagfence_long.p3d";
	};
	class MAP_fort_bagfence_round: MAP_Military_DBu
	{
		scope = 2;
		displayName = "S fort_bagfence_round";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\fort_bagfence_round.p3d";
	};
	class MAP_fort_rampart: MAP_Military_DBu
	{
		scope = 2;
		displayName = "S fort_rampart";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\fort_rampart.p3d";
	};
	class MAP_fort_artillery_nest: MAP_Military_DBu
	{
		scope = 2;
		displayName = "S fort_artillery_nest";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\fort_artillery_nest.p3d";
	};
	class MAP_HBarrier1: MAP_Military_DBu
	{
		scope = 2;
		displayName = "S HBarrier1";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc2\HBarrier1.p3d";
	};
	class MAP_HBarrier3: MAP_Military_DBu
	{
		scope = 2;
		displayName = "S HBarrier3";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc2\HBarrier3.p3d";
	};
	class MAP_HBarrier5: MAP_Military_DBu
	{
		scope = 2;
		displayName = "S HBarrier5";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc2\HBarrier5.p3d";
	};
	class MAP_HBarrier5_round15: MAP_Military_DBu
	{
		scope = 2;
		displayName = "S HBarrier5_round15";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc2\HBarrier5_round15.p3d";
	};
	class MAP_BigHBarrier: MAP_Military_DBu
	{
		scope = 2;
		displayName = "S BigHBarrier";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc2\BigHBarrier.p3d";
	};
	class Land_budova5;
	class MAP_budova5: Land_budova5
	{
		scope = 2;
		displayName = "B budova5";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUMilitary";
		accuracy = 1000;
	};
	class Land_budova1;
	class MAP_budova1: Land_budova1
	{
		scope = 2;
		displayName = "B budova1";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUMilitary";
		accuracy = 1000;
	};
	class Land_budova2;
	class MAP_budova2: Land_budova2
	{
		scope = 2;
		displayName = "B budova2";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUMilitary";
		accuracy = 1000;
	};
	class Land_budova4;
	class MAP_budova4: Land_budova4
	{
		scope = 2;
		displayName = "B budova4";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUMilitary";
		accuracy = 1000;
	};
	class Land_budova4_in;
	class MAP_budova4_in: Land_budova4_in
	{
		scope = 2;
		displayName = "B budova4_in";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUMilitary";
		accuracy = 1000;
	};
	class Land_hospital;
	class MAP_hospital: Land_hospital
	{
		scope = 2;
		displayName = "B hospital";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUMilitary";
		accuracy = 1000;
	};
	class MAP_posed: MAP_Military_DBu
	{
		scope = 2;
		displayName = "B posed";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\posed.p3d";
	};
	class MAP_Ind_IlluminantTower: MAP_Military_DBu
	{
		scope = 2;
		displayName = "B Ind_IlluminantTower";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Ind_SawMill\Ind_IlluminantTower.p3d";
	};
	class Land_vez;
	class MAP_vez: Land_vez
	{
		scope = 2;
		displayName = "B vez";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUMilitary";
		accuracy = 1000;
	};
	class Land_Hlidac_budka;
	class MAP_Hlidac_budka: Land_Hlidac_budka
	{
		scope = 2;
		displayName = "B Hlidac_budka";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUMilitary";
		accuracy = 1000;
	};
	class Land_Mil_Guardhouse;
	class MAP_Mil_Mil_Guardhouse: Land_Mil_Guardhouse
	{
		scope = 2;
		displayName = "B Mil_Guardhouse";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUMilitary";
		accuracy = 1000;
	};
	class MAP_Barrack2: MAP_Military_DBu
	{
		scope = 2;
		displayName = "B Barrack2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc2\Barrack2\Barrack2.p3d";
	};
	class Land_Mil_Barracks;
	class MAP_Mil_Barracks: Land_Mil_Barracks
	{
		scope = 2;
		displayName = "B Mil_Barracks";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUMilitary";
		accuracy = 1000;
	};
	class Land_Mil_Barracks_i;
	class MAP_Mil_Barracks_i: Land_Mil_Barracks_i
	{
		scope = 2;
		displayName = "B Mil_Barracks_i";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUMilitary";
		accuracy = 1000;
	};
	class Land_Mil_Barracks_L;
	class MAP_Mil_Barracks_L: Land_Mil_Barracks_L
	{
		scope = 2;
		displayName = "B Mil_Barracks_L";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUMilitary";
		accuracy = 1000;
	};
	class Land_Mil_House;
	class MAP_Mil_House: Land_Mil_House
	{
		scope = 2;
		displayName = "B Mil_House";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUMilitary";
		accuracy = 1000;
	};
	class Land_Mil_House_dam;
	class MAP_Mil_House_dam: Land_Mil_House_dam
	{
		scope = 2;
		displayName = "B Mil_House_dam";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUMilitary";
		accuracy = 1000;
	};
	class Land_Mil_ControlTower;
	class MAP_Mil_ControlTower: Land_Mil_ControlTower
	{
		scope = 2;
		displayName = "B Mil_ControlTower";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUMilitary";
		accuracy = 1000;
	};
	class Land_Mil_ControlTower_dam;
	class MAP_Mil_ControlTower_dam: Land_Mil_ControlTower_dam
	{
		scope = 2;
		displayName = "B Mil_ControlTower_dam";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUMilitary";
		accuracy = 1000;
	};
	class Land_SS_hangar;
	class MAP_SS_hangar: Land_SS_hangar
	{
		scope = 2;
		displayName = "B SS_hangar";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUMilitary";
		accuracy = 1000;
	};
	class MAP_Gunrack_Empty: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R Gunrack_Empty";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc2\Gunrack_Empty.p3d";
	};
	class MAP_Gunrack1: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R Gunrack1";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc2\Gunrack1.p3d";
	};
	class MAP_Gunrack2: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R Gunrack2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc2\Gunrack2.p3d";
	};
	class MAP_ammobednaX: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R ammobednaX";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\furniture\ammobednaX.p3d";
	};
	class MAP_bedna_ammo2X: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R bedna_ammo2X";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\furniture\bedna_ammo2X.p3d";
	};
	class MAP_hromada_beden_dekorativniX: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R hromada_beden_dekorativniX";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\furniture\hromada_beden_dekorativniX.p3d";
	};
	class MAP_USVehicleAmmo: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R USVehicleAmmo";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\weapons\AmmoBoxes\USVehicleAmmo.p3d";
	};
	class MAP_USSpecialWeapons: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R USSpecialWeapons";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\weapons\AmmoBoxes\USSpecialWeapons.p3d";
	};
	class MAP_USOrdnance: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R USOrdnance";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\weapons\AmmoBoxes\USOrdnance.p3d";
	};
	class MAP_USLaunchers: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R USLaunchers";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\weapons\AmmoBoxes\USLaunchers.p3d";
	};
	class MAP_USBasicWeapons: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R USBasicWeapons";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\weapons\AmmoBoxes\USBasicWeapons.p3d";
	};
	class MAP_USBasicAmmo: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R USBasicAmmo";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\weapons\AmmoBoxes\USBasicAmmo.p3d";
	};
	class MAP_SpecialWeapons: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R SpecialWeapons";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\weapons\AmmoBoxes\SpecialWeapons.p3d";
	};
	class MAP_RUVehicleAmmo: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R RUVehicleAmmo";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\weapons\AmmoBoxes\RUVehicleAmmo.p3d";
	};
	class MAP_RUSpecialWeapons: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R RUSpecialWeapons";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\weapons\AmmoBoxes\RUSpecialWeapons.p3d";
	};
	class MAP_RUOrdnance: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R RUOrdnance";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\weapons\AmmoBoxes\RUOrdnance.p3d";
	};
	class MAP_RULaunchers: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R RULaunchers";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\weapons\AmmoBoxes\RULaunchers.p3d";
	};
	class MAP_RUBasicWeapons: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R RUBasicWeapons";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\weapons\AmmoBoxes\RUBasicWeapons.p3d";
	};
	class MAP_RUBasicAmmo: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R RUBasicAmmo";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\weapons\AmmoBoxes\RUBasicAmmo.p3d";
	};
	class MAP_Proxy_UsLouncherBox: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R Proxy_UsLouncherBox";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\weapons\AmmoBoxes\Proxy_UsLouncherBox.p3d";
	};
	class MAP_Proxy_UsBasicWeaponBox: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R Proxy_UsBasicWeaponBox";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\weapons\AmmoBoxes\Proxy_UsBasicWeaponBox.p3d";
	};
	class MAP_Proxy_UsBasicExplosives: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R Proxy_UsBasicExplosives";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\weapons\AmmoBoxes\Proxy_UsBasicExplosives.p3d";
	};
	class MAP_Proxy_UsBasicAmmoBoxSmall: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R Proxy_UsBasicAmmoBoxSmall";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\weapons\AmmoBoxes\Proxy_UsBasicAmmoBoxSmall.p3d";
	};
	class MAP_Proxy_UsBasicAmmoBoxBig: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R Proxy_UsBasicAmmoBoxBig";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\weapons\AmmoBoxes\Proxy_UsBasicAmmoBoxBig.p3d";
	};
	class MAP_Proxy_UsBasicAmmoBox: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R Proxy_UsBasicAmmoBox";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\weapons\AmmoBoxes\Proxy_UsBasicAmmoBox.p3d";
	};
	class MAP_Proxy_RUWeaponBoxlow: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R Proxy_RUWeaponBoxlow";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\weapons\AmmoBoxes\Proxy_RUWeaponBoxlow.p3d";
	};
	class MAP_Proxy_RUWeaponBox: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R Proxy_RUWeaponBox";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\weapons\AmmoBoxes\Proxy_RUWeaponBox.p3d";
	};
	class MAP_Proxy_RULouncherBox: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R Proxy_RULouncherBox";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\weapons\AmmoBoxes\Proxy_RULouncherBox.p3d";
	};
	class MAP_Proxy_RUExplosives: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R Proxy_RUExplosives";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\weapons\AmmoBoxes\Proxy_RUExplosives.p3d";
	};
	class MAP_Proxy_RUBasicAmmoBox: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R Proxy_RUBasicAmmoBox";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\weapons\AmmoBoxes\Proxy_RUBasicAmmoBox.p3d";
	};
	class MAP_Proxy_RUAmmosmall: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R Proxy_RUAmmosmall";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\weapons\AmmoBoxes\Proxy_RUAmmosmall.p3d";
	};
	class MAP_LocalBasicWeapons: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R LocalBasicWeapons";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\weapons\AmmoBoxes\LocalBasicWeapons.p3d";
	};
	class MAP_LocalBasicAmmo: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R LocalBasicAmmo";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\weapons\AmmoBoxes\LocalBasicAmmo.p3d";
	};
	class MAP_GuerillaCache: MAP_Military_DBu
	{
		scope = 2;
		displayName = "R GuerillaCache";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\weapons\AmmoBoxes\GuerillaCache.p3d";
	};
	class MAP_P_ciws: MAP_Military_DBu
	{
		scope = 2;
		displayName = "N ciws";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\water2\LHD\data\ciws.p3d";
	};
	class MAP_P_raketomet_1: MAP_Military_DBu
	{
		scope = 2;
		displayName = "N raketomet_1";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\water2\LHD\data\raketomet_1.p3d";
	};
	class MAP_P_raketomet_2: MAP_Military_DBu
	{
		scope = 2;
		displayName = "N raketomet_2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\water2\LHD\data\raketomet_2.p3d";
	};
	class MAP_P_torp_tubes: MAP_Military_DBu
	{
		scope = 2;
		displayName = "N torp_tubes";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\Ca\water2\Fregata\torp_tubes.p3d";
	};
	class MAP_P_rhib: MAP_Military_DBu
	{
		scope = 2;
		displayName = "N rhib";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\Ca\water2\Fregata\rhib.p3d";
	};
	class MAP_P_radar: MAP_Military_DBu
	{
		scope = 2;
		displayName = "N radar";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\Ca\water2\Fregata\radar.p3d";
	};
	class MAP_P_radar_2: MAP_Military_DBu
	{
		scope = 2;
		displayName = "N radar_2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\Ca\water2\Fregata\radar_2.p3d";
	};
	class MAP_P_crane: MAP_Military_DBu
	{
		scope = 2;
		displayName = "N crane";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\Ca\water2\Fregata\crane.p3d";
	};
	class MAP_P_amg_84_harpoon_launcher: MAP_Military_DBu
	{
		scope = 2;
		displayName = "N amg_84_harpoon_launcher";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\Ca\water2\Fregata\amg_84_harpoon_launcher.p3d";
	};
	class MAP_PowGen_Big: MAP_Military_DBu
	{
		scope = 2;
		displayName = "B PowGen_Big";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc2\Samsite\PowGen_Big.p3d";
	};
	class MAP_76n6_ClamShell: MAP_Military_DBu
	{
		scope = 2;
		displayName = "B 76n6_ClamShell";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc2\Samsite\76n6_ClamShell.p3d";
	};
	class MAP_76n6_ClamShell_Lower: MAP_Military_DBu
	{
		scope = 2;
		displayName = "B 76n6_ClamShell_Lower";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc2\Samsite\76n6_ClamShell_Lower.p3d";
	};
	class MAP_Ruins_Base: Static
	{
		displayName = "";
		accuracy = 0.1;
		vehicleClass = "MAP_EURuins";
		model = "";
		nameSound = "";
		animated = 0;
		simulation = "house";
		cost = 0;
		armor = 1000;
		ladders[] = {};
		placement = "vertical";
	};
	class MAP_Ruins_DNo: MAP_Ruins_Base
	{
		accuracy = 1000;
	};
	class MAP_Ruins_DTe: MAP_Ruins_Base
	{
		destrType = "DestructTent";
		accuracy = 1000;
	};
	class MAP_Ruins_DTr: MAP_Ruins_Base
	{
		destrType = "DestructTree";
		accuracy = 1000;
	};
	class MAP_Ruins_DBu: MAP_Ruins_Base
	{
		destrType = "DestructBuilding";
		accuracy = 1000;
		class DestructionEffects
		{
			class HouseDestr
			{
				simulation = "destroy";
				type = "DelayedDestruction";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class MAP_Mrtvola_Army1: MAP_Ruins_DBu
	{
		scope = 2;
		displayName = "M Mrtvola_Army1";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\Mrtvola_Army1.p3d";
	};
	class MAP_massgrave: MAP_Ruins_DBu
	{
		scope = 2;
		displayName = "M massgrave";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\characters2\other\massgrave.p3d";
	};
	class MAP_Wreck_Ship_1: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "W Wreck_Ship_1";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\Ca\Structures\Wreck\Wreck_Ship_1.p3d";
	};
	class MAP_Wreck_Ship_2: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "W Wreck_Ship_2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\Ca\Structures\Wreck\Wreck_Ship_2.p3d";
	};
	class MAP_Drevtank_ruin: MAP_Ruins_DBu
	{
		scope = 2;
		displayName = "W Drevtank_ruin";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\Drevtank_ruin.p3d";
	};
	class MAP_Lada_wrecked: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "W Lada_wrecked";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\wheeled2\Lada\Lada_wrecked.p3d";
	};
	class MAP_Skodovka_wrecked: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "W Skodovka_wrecked";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\wheeled\Skodovka_wrecked.p3d";
	};
	class MAP_uaz_wrecked: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "W uaz_wrecked";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\uaz_wrecked.p3d";
	};
	class MAP_datsun01T: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "W datsun01T";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\datsun01T.p3d";
	};
	class MAP_datsun02T: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "W datsun02T";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\datsun02T.p3d";
	};
	class MAP_hiluxT: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "W hiluxT";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\hiluxT.p3d";
	};
	class MAP_HMMWV_wrecked: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "W HMMWV_wrecked";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\wheeled\HMMWV_wrecked.p3d";
	};
	class MAP_HMMWV_wreck: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "W HMMWV_wreck";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\wheeled\HMMWV_wreck.p3d";
	};
	class MAP_PowGen_Big_ruins: MAP_Ruins_DBu
	{
		scope = 2;
		displayName = "W PowGen_Big_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc2\Samsite\PowGen_Big_ruins.p3d";
	};
	class MAP_ural_wrecked: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "W ural_wrecked";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\ural_wrecked.p3d";
	};
	class MAP_BRDM2_wrecked: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "W BRDM2_wrecked";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\BRDM2_wrecked.p3d";
	};
	class MAP_bmp2_wrecked: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "W bmp2_wrecked";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\bmp2_wrecked.p3d";
	};
	class MAP_T72_Wrecked: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "W T72_Wrecked";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\T72_Wrecked.p3d";
	};
	class MAP_t72_wrecked_turret: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "W T72_wrecked_turret";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\t72_wrecked_turret.p3d";
	};
	class MAP_M1A2_TUSK_wreck: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "W M1A2_TUSK_wreck";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\tracked\M1A2_TUSK_wreck.p3d";
	};
	class MAP_AH1ZWreck: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "W AH1ZWreck";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\air\AH1ZWreck.p3d";
	};
	class MAP_UH1YWreck: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "W UH1YWreck";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\air2\UH1Y\UH1YWreck.p3d";
	};
	class MAP_MH_60Wreck: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "W MH_60Wreck";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\air\MH_60Wreck.p3d";
	};
	class MAP_MQ9PredatorWreck: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "W MQ9PredatorWreck";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\air2\MQ9PredatorB\MQ9PredatorWreck.p3d";
	};
	class MAP_AV8BWreck: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "W AV8BWreck";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\air\AV8BWreck.p3d";
	};
	class MAP_A10Wreck: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "W A10Wreck";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\A10\A10Wreck.p3d";
	};
	class MAP_F35bWreck: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "W F35bWreck";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\air2\F35b\F35bWreck.p3d";
	};
	class MAP_C130JWreck: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "W C130JWreck";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\air2\C130J\C130JWreck.p3d";
	};
	class MAP_MV22Wreck: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "W MV22Wreck";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\air2\MV22\MV22Wreck.p3d";
	};
	class MAP_Ka52Wreck: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "W Ka52Wreck";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\air2\Ka52\Ka52Wreck.p3d";
	};
	class MAP_MI8Wreck: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "W MI8Wreck";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\air\MI8Wreck.p3d";
	};
	class MAP_Mi24Wreck: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "W Mi24Wreck";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\air2\Mi35\Mi24Wreck.p3d";
	};
	class MAP_Su25Wreck: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "W Su25Wreck";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\air2\Su25\Su25Wreck.p3d";
	};
	class MAP_su34Wreck: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "W su34Wreck";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\air3\su34\su34Wreck.p3d";
	};
	class Land_A_Castle_Bastion;
	class MAP_A_Castle_Bastion: Land_A_Castle_Bastion
	{
		scope = 2;
		displayName = "C A_Castle_Bastion";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_Bergfrit;
	class MAP_A_Castle_Bergfrit: Land_A_Castle_Bergfrit
	{
		scope = 2;
		displayName = "C A_Castle_Bergfrit";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_Bergfrit_ruins;
	class MAP_A_Castle_Bergfrit_ruins: Land_A_Castle_Bergfrit_ruins
	{
		scope = 2;
		displayName = "C A_Castle_Bergfrit_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_Bergfrit_dam;
	class MAP_A_Castle_Bergfrit_dam: Land_A_Castle_Bergfrit_dam
	{
		scope = 2;
		displayName = "C A_Castle_Bergfrit_dam";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_Donjon;
	class MAP_A_Castle_Donjon: Land_A_Castle_Donjon
	{
		scope = 2;
		displayName = "C A_Castle_Donjon";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_Donjon_dam;
	class MAP_A_Castle_Donjon_dam: Land_A_Castle_Donjon_dam
	{
		scope = 2;
		displayName = "C A_Castle_Donjon_dam";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_Gate;
	class MAP_A_Castle_Gate: Land_A_Castle_Gate
	{
		scope = 2;
		displayName = "C A_Castle_Gate";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_Stairs_A;
	class MAP_A_Castle_Stairs_A: Land_A_Castle_Stairs_A
	{
		scope = 2;
		displayName = "C A_Castle_Stairs_A";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_Wall1_20;
	class MAP_A_Castle_Wall1_20: Land_A_Castle_Wall1_20
	{
		scope = 2;
		displayName = "C A_Castle_Wall1_20";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_Wall1_20_Turn;
	class MAP_A_Castle_Wall1_20_Turn: Land_A_Castle_Wall1_20_Turn
	{
		scope = 2;
		displayName = "C A_Castle_Wall1_20_Turn";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_Wall1_Corner;
	class MAP_A_Castle_Wall1_Corner: Land_A_Castle_Wall1_Corner
	{
		scope = 2;
		displayName = "C A_Castle_Wall1_Corner";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_Wall1_Corner_2;
	class MAP_A_Castle_Wall1_Corner_2: Land_A_Castle_Wall1_Corner_2
	{
		scope = 2;
		displayName = "C A_Castle_Wall1_Corner_2";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_Wall1_End;
	class MAP_A_Castle_Wall1_End: Land_A_Castle_Wall1_End
	{
		scope = 2;
		displayName = "C A_Castle_Wall1_End";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_Wall1_End_2;
	class MAP_A_Castle_Wall1_End_2: Land_A_Castle_Wall1_End_2
	{
		scope = 2;
		displayName = "C A_Castle_Wall1_End_2";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_Wall2_30;
	class MAP_A_Castle_Wall2_30: Land_A_Castle_Wall2_30
	{
		scope = 2;
		displayName = "C A_Castle_Wall2_30";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_Wall2_Corner;
	class MAP_A_Castle_Wall2_Corner: Land_A_Castle_Wall2_Corner
	{
		scope = 2;
		displayName = "C A_Castle_Wall2_Corner";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_Wall2_Corner_2;
	class MAP_A_Castle_Wall2_Corner_2: Land_A_Castle_Wall2_Corner_2
	{
		scope = 2;
		displayName = "C A_Castle_Wall2_Corner_2";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_Wall2_End;
	class MAP_A_Castle_Wall2_End: Land_A_Castle_Wall2_End
	{
		scope = 2;
		displayName = "C A_Castle_Wall2_End";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_Wall2_End_2;
	class MAP_A_Castle_Wall2_End_2: Land_A_Castle_Wall2_End_2
	{
		scope = 2;
		displayName = "C A_Castle_Wall2_End_2";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_WallS_10;
	class MAP_A_Castle_WallS_10: Land_A_Castle_WallS_10
	{
		scope = 2;
		displayName = "C A_Castle_WallS_10";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_WallS_5_D;
	class MAP_A_Castle_WallS_5_D: Land_A_Castle_WallS_5_D
	{
		scope = 2;
		displayName = "C A_Castle_WallS_5_D";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_WallS_End;
	class MAP_A_Castle_WallS_End: Land_A_Castle_WallS_End
	{
		scope = 2;
		displayName = "C A_Castle_WallS_End";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_Bastion_ruins;
	class MAP_A_Castle_Bastion_ruins: Land_A_Castle_Bastion_ruins
	{
		scope = 2;
		displayName = "C A_Castle_Bastion_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_Donjon_ruins;
	class MAP_A_Castle_Donjon_ruins: Land_A_Castle_Donjon_ruins
	{
		scope = 2;
		displayName = "C A_Castle_Donjon_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_Gate_ruins;
	class MAP_A_Castle_Gate_ruins: Land_A_Castle_Gate_ruins
	{
		scope = 2;
		displayName = "C A_Castle_Gate_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_Stairs_A_ruins;
	class MAP_A_Castle_Stairs_A_ruins: Land_A_Castle_Stairs_A_ruins
	{
		scope = 2;
		displayName = "C A_Castle_Stairs_A_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_Wall1_20_ruins;
	class MAP_A_Castle_Wall1_20_ruins: Land_A_Castle_Wall1_20_ruins
	{
		scope = 2;
		displayName = "C A_Castle_Wall1_20_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_Wall1_20_Turn_ruins;
	class MAP_A_Castle_Wall1_20_Turn_ruins: Land_A_Castle_Wall1_20_Turn_ruins
	{
		scope = 2;
		displayName = "C A_Castle_Wall1_20_Turn_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_Wall1_Corner_ruins;
	class MAP_A_Castle_Wall1_Corner_ruins: Land_A_Castle_Wall1_Corner_ruins
	{
		scope = 2;
		displayName = "C A_Castle_Wall1_Corner_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_Wall1_Corner_2_ruins;
	class MAP_A_Castle_Wall1_Corner_2_ruins: Land_A_Castle_Wall1_Corner_2_ruins
	{
		scope = 2;
		displayName = "C A_Castle_Wall1_Corner_2_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_Wall1_End_ruins;
	class MAP_A_Castle_Wall1_End_ruins: Land_A_Castle_Wall1_End_ruins
	{
		scope = 2;
		displayName = "C A_Castle_Wall1_End_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_Wall1_End_2_ruins;
	class MAP_A_Castle_Wall1_End_2_ruins: Land_A_Castle_Wall1_End_2_ruins
	{
		scope = 2;
		displayName = "C A_Castle_Wall1_End_2_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_Wall2_30_ruins;
	class MAP_A_Castle_Wall2_30_ruins: Land_A_Castle_Wall2_30_ruins
	{
		scope = 2;
		displayName = "C A_Castle_Wall2_30_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_Wall2_Corner_ruins;
	class MAP_A_Castle_Wall2_Corner_ruins: Land_A_Castle_Wall2_Corner_ruins
	{
		scope = 2;
		displayName = "C A_Castle_Wall2_Corner_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_Wall2_Corner_2_ruins;
	class MAP_A_Castle_Wall2_Corner_2_ruins: Land_A_Castle_Wall2_Corner_2_ruins
	{
		scope = 2;
		displayName = "C A_Castle_Wall2_Corner_2_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_Wall2_End_ruins;
	class MAP_A_Castle_Wall2_End_ruins: Land_A_Castle_Wall2_End_ruins
	{
		scope = 2;
		displayName = "C A_Castle_Wall2_End_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_Wall2_End_2_ruins;
	class MAP_A_Castle_Wall2_End_2_ruins: Land_A_Castle_Wall2_End_2_ruins
	{
		scope = 2;
		displayName = "C A_Castle_Wall2_End_2_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_WallS_10_ruins;
	class MAP_A_Castle_WallS_10_ruins: Land_A_Castle_WallS_10_ruins
	{
		scope = 2;
		displayName = "C A_Castle_WallS_10_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_WallS_5_D_ruins;
	class MAP_A_Castle_WallS_5_D_ruins: Land_A_Castle_WallS_5_D_ruins
	{
		scope = 2;
		displayName = "C A_Castle_WallS_5_D_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Castle_WallS_End_ruins;
	class MAP_A_Castle_WallS_End_ruins: Land_A_Castle_WallS_End_ruins
	{
		scope = 2;
		displayName = "C A_Castle_WallS_End_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_ruin_corner_1;
	class MAP_ruin_corner_1: Land_ruin_corner_1
	{
		scope = 2;
		displayName = "P ruin_corner_1";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_ruin_corner_2;
	class MAP_ruin_corner_2: Land_ruin_corner_2
	{
		scope = 2;
		displayName = "P ruin_corner_2";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_ruin_wall;
	class MAP_ruin_wall: Land_ruin_wall
	{
		scope = 2;
		displayName = "P ruin_wall";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_ruin_walldoor;
	class MAP_ruin_walldoor: Land_ruin_walldoor
	{
		scope = 2;
		displayName = "P ruin_walldoor";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_ruin_chimney;
	class MAP_ruin_chimney: Land_ruin_chimney
	{
		scope = 2;
		displayName = "P ruin_chimney";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class MAP_ruiny_3_dvere: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "P ruiny_3_dvere";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Rubble\ruiny_3_dvere.p3d";
	};
	class MAP_ruiny_3_prasklina: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "P ruiny_3_prasklina";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Rubble\ruiny_3_prasklina.p3d";
	};
	class MAP_ruiny_3_roh: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "P ruiny_3_roh";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Rubble\ruiny_3_roh.p3d";
	};
	class MAP_ruiny_3_stena: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "P ruiny_3_stena";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Rubble\ruiny_3_stena.p3d";
	};
	class MAP_ruiny_3_stenazbor: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "P ruiny_3_stenazbor";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Rubble\ruiny_3_stenazbor.p3d";
	};
	class MAP_Glass_Cullet_01: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "P Glass_Cullet_01";
		model = "\Ca\Structures\Ruins\Glass_Cullet_01.p3d";
	};
	class MAP_rubble_concrete_03: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "P rubble_concrete_03";
		model = "\Ca\Structures\Ruins\rubble_concrete_03.p3d";
	};
	class MAP_rubble_rocks_02: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "P rubble_rocks_02";
		model = "\Ca\Structures\Ruins\rubble_rocks_02.p3d";
	};
	class MAP_rubble_rocks_03: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "P rubble_rocks_03";
		model = "\Ca\Structures\Ruins\rubble_rocks_03.p3d";
	};
	class MAP_rubble_wood_girder: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "P rubble_wood_girder";
		model = "\Ca\Structures\Ruins\rubble_wood_girder.p3d";
	};
	class MAP_P_R_g1: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "P P_R_g1";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Walls\g1.p3d";
	};
	class MAP_P_R_g2: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "P P_R_g2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Walls\g2.p3d";
	};
	class MAP_P_R_g3: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "P P_R_g3";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Walls\g3.p3d";
	};
	class MAP_P_R_L1: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "P P_R_L1";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Walls\L1.p3d";
	};
	class MAP_P_R_L2: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "P P_R_L2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Walls\L2.p3d";
	};
	class MAP_P_R_L3: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "P P_R_L3";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Walls\L3.p3d";
	};
	class MAP_P_R_m1: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "P P_R_m1";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Walls\m1.p3d";
	};
	class MAP_P_R_m2: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "P P_R_m2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Walls\m2.p3d";
	};
	class MAP_P_R_m3: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "P P_R_m3";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Walls\m3.p3d";
	};
	class MAP_P_R_m4: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "P P_R_m4";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Walls\m4.p3d";
	};
	class MAP_P_R_s1: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "P P_R_s1";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Walls\s1.p3d";
	};
	class MAP_P_R_s2: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "P P_R_s2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Walls\s2.p3d";
	};
	class MAP_P_R_s3: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "P P_R_s3";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Walls\s3.p3d";
	};
	class MAP_P_R_s4: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "P P_R_s4";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Walls\s4.p3d";
	};
	class MAP_P_R_s5: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "P P_R_s5";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Walls\s5.p3d";
	};
	class MAP_P_R_s6: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "P P_R_s6";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Walls\s6.p3d";
	};
	class MAP_P_R_s7: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "P P_R_s7";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Walls\s7.p3d";
	};
	class MAP_P_R_Wall_Top: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "P P_R_Wall_Top";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Walls\Wall_Top.p3d";
	};
	class Land_vez_ruins;
	class MAP_vez_ruins: Land_vez_ruins
	{
		scope = 2;
		displayName = "H t04x03 vez_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_telek1_ruins;
	class MAP_telek1_ruins: Land_telek1_ruins
	{
		scope = 2;
		displayName = "H t06x07 telek1_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_leseni2x_ruins;
	class MAP_leseni2x_ruins: Land_leseni2x_ruins
	{
		scope = 2;
		displayName = "H t07x03 leseni2x_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class MAP_rubble_wood_02: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "H t08x07 rubble_wood_02";
		model = "\Ca\Structures\Ruins\rubble_wood_02.p3d";
	};
	class MAP_HouseV2_04_Part5: MAP_Ruins_DBu
	{
		scope = 2;
		displayName = "H t13x13 HouseV2_04_Part5";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Rooms\HouseV2_04_Part5.p3d";
	};
	class MAP_Ruiny_kov: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "H t16x11 Ruiny_kov";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Rubble\Ruiny_kov.p3d";
	};
	class MAP_HouseV2_02_Part5: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "H t17x13 HouseV2_02_Part5";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Rooms\HouseV2_02_Part5.p3d";
	};
	class Land_Nav_Boathouse_Pier_ruins;
	class MAP_Nav_Boathouse_Pier_ruins: Land_Nav_Boathouse_Pier_ruins
	{
		scope = 2;
		displayName = "H t41x43 Nav_Boathouse_Pier_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Ind_TankSmall_ruins;
	class MAP_Ind_TankSmall_ruins: Land_Ind_TankSmall_ruins
	{
		scope = 2;
		displayName = "H s07x03 Ind_TankSmall_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_NAV_Lighthouse_ruins;
	class MAP_NAV_Lighthouse_ruins: Land_NAV_Lighthouse_ruins
	{
		scope = 2;
		displayName = "H s11x10 NAV_Lighthouse_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Ind_MalyKomin_ruins;
	class MAP_Ind_MalyKomin_ruins: Land_Ind_MalyKomin_ruins
	{
		scope = 2;
		displayName = "H s11x11 Ind_MalyKomin_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_statue01_ruins;
	class MAP_A_statue01_ruins: Land_A_statue01_ruins
	{
		scope = 2;
		displayName = "H s13x11 A_statue01_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Shed_W4_ruins;
	class MAP_Shed_W4_ruins: Land_Shed_W4_ruins
	{
		scope = 2;
		displayName = "H s13x17 Shed_W4_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Nav_Boathouse_ruins;
	class MAP_Nav_Boathouse_ruins: Land_Nav_Boathouse_ruins
	{
		scope = 2;
		displayName = "H s17x17 Nav_Boathouse_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Church_01_ruins;
	class MAP_Church_01_ruins: Land_Church_01_ruins
	{
		scope = 2;
		displayName = "H s21x15 Church_01_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Barn_W_02_ruins;
	class MAP_Barn_W_02_ruins: Land_Barn_W_02_ruins
	{
		scope = 2;
		displayName = "H s21x26 Barn_W_02_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Shed_Ind02_ruins;
	class MAP_Shed_Ind02_ruins: Land_Shed_Ind02_ruins
	{
		scope = 2;
		displayName = "H s22x36 Shed_Ind02_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Barn_W_01_ruins;
	class MAP_Barn_W_01_ruins: Land_Barn_W_01_ruins
	{
		scope = 2;
		displayName = "H s24x52 Barn_W_01_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Farm_WTower_ruins;
	class MAP_Farm_WTower_ruins: Land_Farm_WTower_ruins
	{
		scope = 2;
		displayName = "H s26x24 Farm_WTower_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class MAP_A_FuelStation_Shed_ruins: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "H s27x17 A_FuelStation_Shed_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\House\A_FuelStation\A_FuelStation_Shed_ruins";
	};
	class Land_Ind_Mlyn_04_ruins;
	class MAP_Ind_Mlyn_04_ruins: Land_Ind_Mlyn_04_ruins
	{
		scope = 2;
		displayName = "H s28x42 Ind_Mlyn_04_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Ind_SiloMale_ruins;
	class Ind_SiloMale_ruins: Land_Ind_SiloMale_ruins
	{
		scope = 2;
		displayName = "H s29x42 Ind_SiloMale_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Ind_Pec_01_ruins;
	class MAP_Ind_Pec_01_ruins: Land_Ind_Pec_01_ruins
	{
		scope = 2;
		displayName = "H s30x47 Ind_Pec_01_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Mil_ControlTower_ruins;
	class MAP_Mil_ControlTower_ruins: Land_Mil_ControlTower_ruins
	{
		scope = 2;
		displayName = "H s31x20 Mil_ControlTower_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Ind_Mlyn_03_ruins;
	class MAP_Ind_Mlyn_03_ruins: Land_Ind_Mlyn_03_ruins
	{
		scope = 2;
		displayName = "H s33x45 Ind_Mlyn_03_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_rail_station_big_ruins;
	class MAP_rail_station_big_ruins: Land_rail_station_big_ruins
	{
		scope = 2;
		displayName = "T s35x24 rail_station_big_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Ind_Mlyn_01_ruins;
	class MAP_Ind_Mlyn_01_ruins: Land_Ind_Mlyn_01_ruins
	{
		scope = 2;
		displayName = "H s39x32 Ind_Mlyn_01_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Ind_SiloVelke_02_ruins;
	class Ind_SiloVelke_02_ruins: Land_Ind_SiloVelke_02_ruins
	{
		scope = 2;
		displayName = "H s45x28 Ind_SiloVelke_02_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Nasypka_ruins;
	class MAP_Nasypka_ruins: Land_Nasypka_ruins
	{
		scope = 2;
		displayName = "H m05x08 Nasypka_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_R_HouseV_2L;
	class MAP_R_HouseV_2L: Land_R_HouseV_2L
	{
		scope = 2;
		displayName = "H m12x12 R_HouseV_2L";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_HouseBlock_B3_ruins;
	class MAP_HouseBlock_B3_ruins: Land_HouseBlock_B3_ruins
	{
		scope = 2;
		displayName = "H m15x20 HouseBlock_B3_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_HouseBlock_C5_ruins;
	class MAP_HouseBlock_C5_ruins: Land_HouseBlock_C5_ruins
	{
		scope = 2;
		displayName = "H m18x29 HouseBlock_C5_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_ruin_01;
	class MAP_ruin_01: Land_ruin_01
	{
		scope = 2;
		displayName = "H m22x17 ruin_01";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_HouseBlock_B2_ruins;
	class MAP_HouseBlock_B2_ruins: Land_HouseBlock_B2_ruins
	{
		scope = 2;
		displayName = "H m22x20 HouseBlock_B2_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_R_Farm_Cowshed_a;
	class MAP_R_Farm_Cowshed_a: Land_R_Farm_Cowshed_a
	{
		scope = 2;
		displayName = "H m31x24 R_Farm_Cowshed_a";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_R_A_GeneralStore_01a;
	class MAP_R_A_GeneralStore_01a: Land_R_A_GeneralStore_01a
	{
		scope = 2;
		displayName = "H m32x21 R_A_GeneralStore_01a";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Ind_Mlyn_02_ruins;
	class MAP_Ind_Mlyn_02_ruins: Land_Ind_Mlyn_02_ruins
	{
		scope = 2;
		displayName = "H m32x25 Ind_Mlyn_02_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_HouseBlock_D1_ruins;
	class MAP_HouseBlock_D1_ruins: Land_HouseBlock_D1_ruins
	{
		scope = 2;
		displayName = "H m32x28 HouseBlock_D1_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class MAP_Ind_SawMill_ruins: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "H m34x29 Ind_SawMill_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Ind_SawMill\Ind_SawMill_ruins.p3d";
		placement = "slope";
	};
	class Land_Church_02_ruins;
	class MAP_Church_02_ruins: Land_Church_02_ruins
	{
		scope = 2;
		displayName = "H m36x30 Church_02_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_SS_hangar_ruins;
	class MAP_SS_hangar_ruins: Land_SS_hangar_ruins
	{
		scope = 2;
		displayName = "H m36x55 SS_hangar_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Ind_Expedice_1_ruins;
	class MAP_Ind_Expedice_1_ruins: Land_Ind_Expedice_1_ruins
	{
		scope = 2;
		displayName = "H m39x51 Ind_Expedice_1_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Barn_Metal_ruins;
	class MAP_Barn_Metal_ruins: Land_Barn_Metal_ruins
	{
		scope = 2;
		displayName = "H m40x70 Barn_Metal_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Ind_Vysypka_ruins;
	class Ind_Vysypka_ruins: Land_Ind_Vysypka_ruins
	{
		scope = 2;
		displayName = "H m42x68 Ind_Vysypka_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Church_03_ruins;
	class MAP_Church_03_ruins: Land_Church_03_ruins
	{
		scope = 2;
		displayName = "H m50x40 Church_03_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_a_stationhouse_ruins;
	class MAP_a_stationhouse_ruins: Land_a_stationhouse_ruins
	{
		scope = 2;
		displayName = "H m54x32 a_stationhouse_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_R_Shed_Ind02;
	class MAP_R_Shed_Ind02: Land_R_Shed_Ind02
	{
		scope = 2;
		displayName = "H l13x30 R_Shed_Ind02";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_dum_zboreny_total;
	class dum_zboreny_total: Land_dum_zboreny_total
	{
		scope = 2;
		displayName = "H l19x14 dum_zboreny_total";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_R_HouseV_1I1;
	class MAP_R_HouseV_1I1: Land_R_HouseV_1I1
	{
		scope = 2;
		displayName = "H l19x22 R_HouseV_1I1";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_R_Barn_W_01;
	class MAP_R_Barn_W_01: Land_R_Barn_W_01
	{
		scope = 2;
		displayName = "H l19x55 R_Barn_W_01";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_R_HouseV2_02;
	class MAP_R_HouseV2_02: Land_R_HouseV2_02
	{
		scope = 2;
		displayName = "H l21x13 R_HouseV2_02";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_R_HouseV2_04;
	class MAP_R_HouseV2_04: Land_R_HouseV2_04
	{
		scope = 2;
		displayName = "H l22x24 R_HouseV2_04";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_R_HouseV2_03B;
	class MAP_R_HouseV2_03B: Land_R_HouseV2_03B
	{
		scope = 2;
		displayName = "H l25x21 R_HouseV2_03B";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_HouseBlock_A2_1_ruins;
	class MAP_HouseBlock_A2_1_ruins: Land_HouseBlock_A2_1_ruins
	{
		scope = 2;
		displayName = "H l26x29 HouseBlock_A2_1_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_HouseBlock_A2_ruins;
	class MAP_HouseBlock_A2_ruins: Land_HouseBlock_A2_ruins
	{
		scope = 2;
		displayName = "H l26x25 HouseBlock_A2_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_HouseBlock_C1_ruins;
	class MAP_HouseBlock_C1_ruins: Land_HouseBlock_C1_ruins
	{
		scope = 2;
		displayName = "H l28x24 HouseBlock_C1_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_HouseBlock_A3_ruins;
	class MAP_HouseBlock_A3_ruins: Land_HouseBlock_A3_ruins
	{
		scope = 2;
		displayName = "H l28x31 HouseBlock_A3_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Ind_Quarry_ruins;
	class MAP_Ind_Quarry_ruins: Land_Ind_Quarry_ruins
	{
		scope = 2;
		displayName = "H l29x42 Ind_Quarry_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_MunicipalOffice_ruins;
	class MAP_A_MunicipalOffice_ruins: Land_A_MunicipalOffice_ruins
	{
		scope = 2;
		displayName = "H l41x44 A_MunicipalOffice_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Ind_Stack_Big_ruins;
	class MAP_Ind_Stack_Big_ruins: Land_Ind_Stack_Big_ruins
	{
		scope = 2;
		displayName = "H l47x46 Ind_Stack_Big";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Hospital_ruins;
	class MAP_A_Hospital_ruins: Land_A_Hospital_ruins
	{
		scope = 2;
		displayName = "H l57x30 A_Hospital_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_BuildingWIP_ruins;
	class MAP_A_BuildingWIP_ruins: Land_A_BuildingWIP_ruins
	{
		scope = 2;
		displayName = "H l58x46 A_BuildingWIP_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_HouseB_Tenement_ruins;
	class MAP_HouseB_Tenement_ruins: Land_HouseB_Tenement_ruins
	{
		scope = 2;
		displayName = "H l61x45 HouseB_Tenement_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_dulni_bs;
	class MAP_dulni_bs: Land_dulni_bs
	{
		scope = 2;
		displayName = "H x08x08 dulni_bs";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_afdum_mesto2;
	class MAP_afdum_mesto2: Land_afdum_mesto2
	{
		scope = 2;
		displayName = "H x09x18 afdum_mesto2";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_afdum_mesto2L;
	class MAP_afdum_mesto2L: Land_afdum_mesto2L
	{
		scope = 2;
		displayName = "H x14x14 afdum_mesto2L";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_afdum_mesto3;
	class MAP_afdum_mesto3: Land_afdum_mesto3
	{
		scope = 2;
		displayName = "H x15x19 afdum_mesto3";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Ind_TankBig_ruins;
	class MAP_Ind_TankBig_ruins: Land_Ind_TankBig_ruins
	{
		scope = 2;
		displayName = "H x15x15 Ind_TankBig_ruins";
		vicon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_afhospoda_mesto;
	class MAP_afhospoda_mesto: Land_afhospoda_mesto
	{
		scope = 2;
		displayName = "H x17x16 afhospoda_mesto";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_AFbarabizna;
	class MAP_AFbarabizna: Land_AFbarabizna
	{
		scope = 2;
		displayName = "H x18x15 AFbarabizna";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_dum_zboreny;
	class dum_zboreny: Land_dum_zboreny
	{
		scope = 2;
		displayName = "H x19x14 dum_zboreny";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class MAP_HouseBlock_A1_half_ruin: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "H x19x19 HouseBlock_A1_half_ruin";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\Ca\Buildings2\HouseBlocks\HouseBlock_A\HouseBlock_A1_half_ruin.p3d";
	};
	class Land_kostel_trosky;
	class MAP_kostel_trosky: Land_kostel_trosky
	{
		scope = 2;
		displayName = "H x13x33 kostel_trosky";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_HouseBlock_B1_ruins;
	class MAP_HouseBlock_B1_ruins: Land_HouseBlock_B1_ruins
	{
		scope = 2;
		displayName = "H x32x26 HouseBlock_B1_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_HouseBlock_B6_ruins;
	class MAP_HouseBlock_B6_ruins: Land_HouseBlock_B6_ruins
	{
		scope = 2;
		displayName = "H x32x24 HouseBlock_B6_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Church_05R;
	class MAP_Land_Church_05R: Land_Church_05R
	{
		scope = 2;
		displayName = "H x40x25 Land_Church_05R";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class MAP_a_office02_int: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "H x44x13 a_office02_int";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Rooms\a_office02_int.p3d";
	};
	class Land_R_Barn_Metal;
	class MAP_R_Barn_Metal: Land_R_Barn_Metal
	{
		scope = 2;
		displayName = "H x48x60 R_Barn_Metal";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_bouda3_ruins;
	class MAP_bouda3_ruins: Land_bouda3_ruins
	{
		scope = 2;
		displayName = "R -13x14 bouda3_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class MAP_rubble9: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R t02x02 rubble-9";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Rubble\rubble-9.p3d";
	};
	class MAP_rubble8: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R t03x03 rubble-8";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Rubble\rubble-8.p3d";
	};
	class MAP_ruiny_kopa_1m: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R t03x03 ruiny_kopa_1m";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Rubble\ruiny_kopa_1m.p3d";
	};
	class MAP_rubble_metal_plates_03: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R t03x04 rubble_metal_plates_03";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\Ca\Structures\Ruins\rubble_metal_plates_03.p3d";
	};
	class MAP_kopa_1: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R t03x05 kopa_1";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\kopa_1.p3d";
	};
	class MAP_rubble7: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R t04x02 rubble-7";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Rubble\rubble-7.p3d";
	};
	class MAP_kopa_4r: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R t04x04 kopa_4r";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\kopa_4r.p3d";
	};
	class MAP_rubble6: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R t04x08 rubble-6";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Rubble\rubble-6.p3d";
	};
	class Land_Shed_M02_ruins;
	class MAP_Shed_M02_ruins: Land_Shed_M02_ruins
	{
		scope = 2;
		displayName = "R t05x06 Shed_M02_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class MAP_rubble_metal_plates_01: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R t05x06 rubble_metal_plates_01";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\Ca\Structures\Ruins\rubble_metal_plates_01.p3d";
	};
	class MAP_rubble_bricks_01: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R t05x06 rubble_bricks_01";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\Ca\Structures\Ruins\rubble_bricks_01.p3d";
	};
	class MAP_rubble_wood_01: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R t05x06 rubble_wood_01";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\Ca\Structures\Ruins\rubble_wood_01.p3d";
	};
	class MAP_rubble5: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R t06x06 rubble-5";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Rubble\rubble-5.p3d";
	};
	class MAP_Ruiny_02: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R t06x06 Ruiny_02";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Rubble\Ruiny_02.p3d";
	};
	class MAP_Ruiny_03: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R t06x06 Ruiny_03";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Rubble\Ruiny_03.p3d";
	};
	class MAP_ruiny_kopa_1p: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R t06x06 ruiny_kopa_1p";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Rubble\ruiny_kopa_1p.p3d";
	};
	class MAP_ruiny_kopa_1Tm: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R t06x07 ruiny_kopa_1Tm";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Rubble\ruiny_kopa_1Tm.p3d";
	};
	class MAP_rubble_metal_plates_04: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R t06x08 rubble_metal_plates_04";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\Ca\Structures\Ruins\rubble_metal_plates_04.p3d";
	};
	class Land_Ind_Workshop01_box_ruins;
	class MAP_Ind_Workshop01_box_ruins: Land_Ind_Workshop01_box_ruins
	{
		scope = 2;
		displayName = "R t06x10 Ind_Workshop01_box_ruins";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class MAP_rubble3: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R t06x11 rubble-3";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Rubble\rubble-3.p3d";
	};
	class Land_Shed_M03_ruins;
	class MAP_Shed_M03_ruins: Land_Shed_M03_ruins
	{
		scope = 2;
		displayName = "R t07x10 Shed_M03_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class MAP_rubble4: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R t07x11 rubble-4";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Rubble\rubble-4.p3d";
	};
	class MAP_rubble_concrete_02: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R t08x08 rubble_concrete_02";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\Ca\Structures\Ruins\rubble_concrete_02.p3d";
	};
	class Land_hut06_ruins;
	class MAP_hut06_ruins: Land_hut06_ruins
	{
		scope = 2;
		displayName = "R t08x11 hut06_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class MAP_ruiny_kopa_2: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R t08x15 ruiny_kopa_2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Rubble\ruiny_kopa_2.p3d";
	};
	class Land_Ind_Workshop01_03_ruins;
	class MAP_Ind_Workshop01_03_ruins: Land_Ind_Workshop01_03_ruins
	{
		scope = 2;
		displayName = "R t08x15 Ind_Workshop01_03_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class MAP_Ruiny_01: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R t09x06 Ruiny_01";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Rubble\Ruiny_01.p3d";
	};
	class MAP_A_FuelStation_Build_ruins: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R t09x08 A_FuelStation_Build_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\House\A_FuelStation\A_FuelStation_Build_ruins";
	};
	class Land_Ind_Workshop01_02_ruins;
	class MAP_Ind_Workshop01_02_ruins: Land_Ind_Workshop01_02_ruins
	{
		scope = 2;
		displayName = "R t09x14 Ind_Workshop01_02_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Ind_Shed_02_main_ruins;
	class MAP_Ind_Shed_02_main_ruins: Land_Ind_Shed_02_main_ruins
	{
		scope = 2;
		displayName = "R t10x06 Ind_Shed_02_main_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Shed_M01_ruins;
	class MAP_Shed_M01_ruins: Land_Shed_M01_ruins
	{
		scope = 2;
		displayName = "R t10x07 Shed_M01_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Shed_W03_ruins;
	class MAP_Shed_W03_ruins: Land_Shed_W03_ruins
	{
		scope = 2;
		displayName = "R t10x07 Shed_W03_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Misc_WaterStation_ruins;
	class MAP_Misc_WaterStation_ruins: Land_Misc_WaterStation_ruins
	{
		scope = 2;
		displayName = "R t10x07 Misc_WaterStation_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_HouseV_1I3_ruins;
	class MAP_HouseV_1I3_ruins: Land_HouseV_1I3_ruins
	{
		scope = 2;
		displayName = "R t10x21 HouseV_1I3_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_garaz_mala_ruins;
	class MAP_garaz_mala_ruins: Land_garaz_mala_ruins
	{
		scope = 2;
		displayName = "R t11x11 garaz_mala_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_ruin_rubble;
	class MAP_ruin_rubble: Land_ruin_rubble
	{
		scope = 2;
		displayName = "R t11x11 ruin_rubble";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Majak_ruins;
	class MAP_Majak_ruins: Land_Majak_ruins
	{
		scope = 2;
		displayName = "R t11x11 Majak_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class MAP_rubble1: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R t11x11 rubble-1";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Rubble\rubble-1.p3d";
	};
	class MAP_rubble2: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R t11x11 rubble-2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Rubble\rubble-2.p3d";
	};
	class Land_Dulni_bs_ruins;
	class MAP_Dulni_bs_ruins: Land_Dulni_bs_ruins
	{
		scope = 2;
		displayName = "R t11x12 Dulni_bs_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_repair_center_ruins;
	class MAP_repair_center_ruins: Land_repair_center_ruins
	{
		scope = 2;
		displayName = "R t11x13 repair_center_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Dum_m2_ruins;
	class MAP_Dum_m2_ruins: Land_Dum_m2_ruins
	{
		scope = 2;
		displayName = "R t11x13 Dum_m2_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_HouseV_1I4_ruins;
	class MAP_HouseV_1I4_ruins: Land_HouseV_1I4_ruins
	{
		scope = 2;
		displayName = "R t11x22 HouseV_1I4_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class MAP_ruiny_kopa_big: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R t12x12 ruiny_kopa_big";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Rubble\ruiny_kopa_big.p3d";
	};
	class MAP_ruiny_kopa_big_1: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R t12x12 ruiny_kopa_big_1";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Rubble\ruiny_kopa_big_1.p3d";
	};
	class Land_Hlidac_budka_ruins;
	class MAP_Hlidac_budka_ruins: Land_Hlidac_budka_ruins
	{
		scope = 2;
		displayName = "R t13x11 Hlidac_budka_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Cihlovej_dum_in_ruins;
	class MAP_Cihlovej_dum_in_ruins: Land_Cihlovej_dum_in_ruins
	{
		scope = 2;
		displayName = "R t13x12 Cihlovej_dum_in_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Cihlovej_dum_ruins;
	class MAP_Cihlovej_dum_ruins: Land_Cihlovej_dum_ruins
	{
		scope = 2;
		displayName = "R t13x12 Cihlovej_dum_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_HouseV_1I2_ruins;
	class MAP_HouseV_1I2_ruins: Land_HouseV_1I2_ruins
	{
		scope = 2;
		displayName = "R t13x13 HouseV_1I2_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_dum_rasovna_ruins;
	class MAP_dum_rasovna_ruins: Land_dum_rasovna_ruins
	{
		scope = 2;
		displayName = "R t13x16 dum_rasovna_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_zalchata_ruins;
	class MAP_zalchata_ruins: Land_zalchata_ruins
	{
		scope = 2;
		displayName = "R t13x21 zalchata_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_domek_rosa_ruins;
	class MAP_domek_rosa_ruins: Land_domek_rosa_ruins
	{
		scope = 2;
		displayName = "R t14x10 domek_rosa_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Statek_kulna_old_ruins;
	class MAP_Statek_kulna_old_ruins: Land_Statek_kulna_old_ruins
	{
		scope = 2;
		displayName = "R t14x11 Statek_kulna_old_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Komin_ruins;
	class MAP_Komin_ruins: Land_Komin_ruins
	{
		scope = 2;
		displayName = "R t14x12 Komin_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Hruzdum_ruins;
	class MAP_Hruzdum_ruins: Land_Hruzdum_ruins
	{
		scope = 2;
		displayName = "R t14x13 Hruzdum_ruins";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Ind_Garage01_ruins;
	class MAP_Ind_Garage01_ruins: Land_Ind_Garage01_ruins
	{
		scope = 2;
		displayName = "R t14x14 Ind_Garage01_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Ind_Workshop01_01_ruins;
	class MAP_Ind_Workshop01_01_ruins: Land_Ind_Workshop01_01_ruins
	{
		scope = 2;
		displayName = "R t14x14 Ind_Workshop01_01_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_dum_olez_istan2_maly_ruins;
	class MAP_dum_olez_istan2_maly_ruins: Land_dum_olez_istan2_maly_ruins
	{
		scope = 2;
		displayName = "R t14x14 dum_olez_istan2_maly_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_HouseV_3I2_ruins;
	class MAP_HouseV_3I2_ruins: Land_HouseV_3I2_ruins
	{
		scope = 2;
		displayName = "R t14x14 HouseV_3I2_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Dumruina_mini_ruins;
	class MAP_Dumruina_mini_ruins: Land_Dumruina_mini_ruins
	{
		scope = 2;
		displayName = "R t14x15 Dumruina_mini_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Dum_mesto2_ruins;
	class MAP_Dum_mesto2_ruins: Land_Dum_mesto2_ruins
	{
		scope = 2;
		displayName = "R t14x23 Dum_mesto2_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_brana02nodoor_ruins;
	class MAP_brana02nodoor_ruins: Land_brana02nodoor_ruins
	{
		scope = 2;
		displayName = "R t15x12 brana02nodoor_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_HouseV_3I4_ruins;
	class MAP_HouseV_3I4_ruins: Land_HouseV_3I4_ruins
	{
		scope = 2;
		displayName = "R t15x13 HouseV_3I4_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_trafostanica_velka_ruins;
	class MAP_trafostanica_velka_ruins: Land_trafostanica_velka_ruins
	{
		scope = 2;
		displayName = "R t15x21 trafostanica_velka_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Ind_Shed_01_end_ruins;
	class MAP_Ind_Shed_01_end_ruins: Land_Ind_Shed_01_end_ruins
	{
		scope = 2;
		displayName = "R t16x02 Ind_Shed_01_end_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Deutshe_mini_ruins;
	class MAP_Deutshe_mini_ruins: Land_Deutshe_mini_ruins
	{
		scope = 2;
		displayName = "R t16x13 Deutshe_mini_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_bouda1_ruins;
	class MAP_bouda1_ruins: Land_bouda1_ruins
	{
		scope = 2;
		displayName = "R t16x14 bouda1_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Rail_House_01_ruins;
	class MAP_Rail_House_01_ruins: Land_Rail_House_01_ruins
	{
		scope = 2;
		displayName = "R t16x15 Rail_House_01_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_budova5_ruins;
	class MAP_budova5_ruins: Land_budova5_ruins
	{
		scope = 2;
		displayName = "R t16x15 budova5_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_dum_istan3_pumpa_ruins;
	class MAP_dum_istan3_pumpa_ruins: Land_dum_istan3_pumpa_ruins
	{
		scope = 2;
		displayName = "R t16x15 dum_istan3_pumpa_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_dum_olez_istan2_ruins;
	class MAP_dum_olez_istan2_ruins: Land_dum_olez_istan2_ruins
	{
		scope = 2;
		displayName = "R t16x18 dum_olez_istan2_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_AFDum_mesto3_ruins;
	class MAP_AFDum_mesto3_ruins: Land_AFDum_mesto3_ruins
	{
		scope = 2;
		displayName = "R t16x23 AFDum_mesto3_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_HouseV_2I_ruins;
	class MAP_HouseV_2I_ruins: Land_HouseV_2I_ruins
	{
		scope = 2;
		displayName = "R t16x23 HouseV_2I_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_AFDum_mesto2_ruins;
	class MAP_AFDum_mesto2_ruins: Land_AFDum_mesto2_ruins
	{
		scope = 2;
		displayName = "R t16x24 AFDum_mesto2_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Dum_mesto3_ruins;
	class MAP_Dum_mesto3_ruins: Land_Dum_mesto3_ruins
	{
		scope = 2;
		displayName = "R t16x24 Dum_mesto3_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_HouseV_3I1_ruins;
	class MAP_HouseV_3I1_ruins: Land_HouseV_3I1_ruins
	{
		scope = 2;
		displayName = "R t17x11 HouseV_3I1_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_HouseV_3I3_ruins;
	class MAP_HouseV_3I3_ruins: Land_HouseV_3I3_ruins
	{
		scope = 2;
		displayName = "R t17x11 HouseV_3I3_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_HouseV_2T2_ruins;
	class MAP_HouseV_2T2_ruins: Land_HouseV_2T2_ruins
	{
		scope = 2;
		displayName = "R t17x13 HouseV_2T2_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_stanice_ruins;
	class MAP_stanice_ruins: Land_stanice_ruins
	{
		scope = 2;
		displayName = "R t17x16 stanice_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Ind_Workshop01_L_ruins;
	class MAP_Ind_Workshop01_L_ruins: Land_Ind_Workshop01_L_ruins
	{
		scope = 2;
		displayName = "R t17x18 Ind_Workshop01_L_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Dum_mesto_ruins;
	class MAP_Dum_mesto_ruins: Land_Dum_mesto_ruins
	{
		scope = 2;
		displayName = "R t17x18 Dum_mesto_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Statek_hl_bud_ruins;
	class MAP_Statek_hl_bud_ruins: Land_Statek_hl_bud_ruins
	{
		scope = 2;
		displayName = "R t17x20 Statek_hl_bud_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Sara_domek_ruina_ruins;
	class MAP_Sara_domek_ruina_ruins: Land_Sara_domek_ruina_ruins
	{
		scope = 2;
		displayName = "R t18x13 Sara_domek_ruina_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_HouseV_1T_ruins;
	class MAP_HouseV_1T_ruins: Land_HouseV_1T_ruins
	{
		scope = 2;
		displayName = "R t18x15 HouseV_1T_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Farm_Cowshed_c_ruins;
	class MAP_Farm_Cowshed_c_ruins: Land_Farm_Cowshed_c_ruins
	{
		scope = 2;
		displayName = "R t18x16 Farm_Cowshed_c_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_dum01_ruins;
	class MAP_dum01_ruins: Land_dum01_ruins
	{
		scope = 2;
		displayName = "R t18x23 dum01_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_stodola_open_ruins;
	class MAP_stodola_open_ruins: Land_stodola_open_ruins
	{
		scope = 2;
		displayName = "R t18x24 stodola_open_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Ind_Shed_01_main_ruins;
	class MAP_Ind_Shed_01_main_ruins: Land_Ind_Shed_01_main_ruins
	{
		scope = 2;
		displayName = "R t19x06 Ind_Shed_01_main_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_HouseV_2T1_ruins;
	class MAP_HouseV_2T1_ruins: Land_HouseV_2T1_ruins
	{
		scope = 2;
		displayName = "R t19x13 HouseV_2T1_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Sara_Hasic_zbroj_ruins;
	class MAP_Sara_Hasic_zbroj_ruins: Land_Sara_Hasic_zbroj_ruins
	{
		scope = 2;
		displayName = "R t19x15 Sara_Hasic_zbroj_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_HouseV_1I1_ruins;
	class MAP_HouseV_1I1_ruins: Land_HouseV_1I1_ruins
	{
		scope = 2;
		displayName = "R t19x15 HouseV_1I1_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_AFDum_mesto2L_ruins;
	class MAP_AFDum_mesto2L_ruins: Land_AFDum_mesto2L_ruins
	{
		scope = 2;
		displayName = "R t19x19 AFDum_mesto2L_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_kostel_ruins;
	class MAP_kostel_ruins: Land_kostel_ruins
	{
		scope = 2;
		displayName = "R t19x26 kostel_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_kostel3_ruins;
	class MAP_kostel3_ruins: Land_kostel3_ruins
	{
		scope = 2;
		displayName = "R t19x31 kostel3_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_trafostanica_mala_ruins;
	class MAP_trafostanica_mala_ruins: Land_trafostanica_mala_ruins
	{
		scope = 2;
		displayName = "R t20x11 trafostanica_mala_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_garaz_ruins;
	class MAP_garaz_ruins: Land_garaz_ruins
	{
		scope = 2;
		displayName = "R t20x13 garaz_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Sara_stodola_ruins;
	class MAP_Sara_stodola_ruins: Land_Sara_stodola_ruins
	{
		scope = 2;
		displayName = "R t20x16 Sara_stodola_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Dum_mesto2L_ruins;
	class MAP_Dum_mesto2L_ruins: Land_Dum_mesto2L_ruins
	{
		scope = 2;
		displayName = "R t20x19 Dum_mesto2L_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_sara_domek_vilka_ruins;
	class MAP_sara_domek_vilka_ruins: Land_sara_domek_vilka_ruins
	{
		scope = 2;
		displayName = "R t20x22 sara_domek_vilka_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_dum_mesto_in_ruins;
	class MAP_dum_mesto_in_ruins: Land_dum_mesto_in_ruins
	{
		scope = 2;
		displayName = "R t20x15 dum_mesto_in_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_AFbarabizna_ruins;
	class MAP_AFbarabizna_ruins: Land_AFbarabizna_ruins
	{
		scope = 2;
		displayName = "R t20x20 AFbarabizna_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_budova4_ruins;
	class MAP_budova4_ruins: Land_budova4_ruins
	{
		scope = 2;
		displayName = "R t21x14 budova4_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Deutshe_ruins;
	class MAP_Deutshe_ruins: Land_Deutshe_ruins
	{
		scope = 2;
		displayName = "R t21x14 Deutshe_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class MAP_temp_garaz_bez_tanku_ruins: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R t21x14 temp_garaz_bez_tanku_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Rubble\temp_garaz_bez_tanku_ruins.p3d";
	};
	class Land_AFHospoda_mesto_ruins;
	class MAP_AFHospoda_mesto_ruins: Land_AFHospoda_mesto_ruins
	{
		scope = 2;
		displayName = "R t21x21 AFHospoda_mesto_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_dum_istan3_hromada2_ruins;
	class MAP_dum_istan3_hromada2_ruins: Land_dum_istan3_hromada2_ruins
	{
		scope = 2;
		displayName = "R t21x22 dum_istan3_hromada2_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Sara_domek_sedy_ruins;
	class MAP_Sara_domek_sedy_ruins: Land_Sara_domek_sedy_ruins
	{
		scope = 2;
		displayName = "R t22x14 Sara_domek_sedy_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Sara_domek_podhradi_1_ruins;
	class MAP_Sara_domek_podhradi_1_ruins: Land_Sara_domek_podhradi_1_ruins
	{
		scope = 2;
		displayName = "R t22x17 Sara_domek_podhradi_1_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_dum_olezlina_ruins;
	class MAP_dum_olezlina_ruins: Land_dum_olezlina_ruins
	{
		scope = 2;
		displayName = "R t23x14 dum_olezlina_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_budova1_ruins;
	class MAP_budova1_ruins: Land_budova1_ruins
	{
		scope = 2;
		displayName = "R t23x15 budova1_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_dum_olez_istan1_ruins;
	class MAP_dum_olez_istan1_ruins: Land_dum_olez_istan1_ruins
	{
		scope = 2;
		displayName = "R t23x16 dum_olez_istan1_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Panelak_ruins;
	class MAP_Panelak_ruins: Land_Panelak_ruins
	{
		scope = 2;
		displayName = "R t23x18 Panelak_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Sara_domek_kovarna_ruins;
	class MAP_Sara_domek_kovarna_ruins: Land_Sara_domek_kovarna_ruins
	{
		scope = 2;
		displayName = "R t23x20 Sara_domek_kovarna_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Sara_domek_hospoda_ruins;
	class MAP_Sara_domek_hospoda_ruins: Land_Sara_domek_hospoda_ruins
	{
		scope = 2;
		displayName = "R t23x21 Sara_domek_hospoda_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_budova4_in_ruins;
	class MAP_budova4_in_ruins: Land_budova4_in_ruins
	{
		scope = 2;
		displayName = "R t24x13 budova4_in_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Panelak2_ruins;
	class MAP_Panelak2_ruins: Land_Panelak2_ruins
	{
		scope = 2;
		displayName = "R t24x18 Panelak2_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Sara_domek_zluty_ruins;
	class MAP_Sara_domek_zluty_ruins: Land_Sara_domek_zluty_ruins
	{
		scope = 2;
		displayName = "R t24x18 Sara_domek_zluty_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Panelak3_ruins;
	class MAP_Panelak3_ruins: Land_Panelak3_ruins
	{
		scope = 2;
		displayName = "R t24x20 Panelak3_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_stodola_old_open_ruins;
	class MAP_stodola_old_open_ruins: Land_stodola_old_open_ruins
	{
		scope = 2;
		displayName = "R t24x31 stodola_old_open_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Sara_stodola3_ruins;
	class MAP_Sara_stodola3_ruins: Land_Sara_stodola3_ruins
	{
		scope = 2;
		displayName = "R t25x15 Sara_stodola3_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_budova2_ruins;
	class MAP_budova2_ruins: Land_budova2_ruins
	{
		scope = 2;
		displayName = "R t25x19 budova2_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_kostel_trosky_ruins;
	class MAP_kostel_trosky_ruins: Land_kostel_trosky_ruins
	{
		scope = 2;
		displayName = "R t25x37 kostel_trosky_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_hospital_ruins;
	class MAP_hospital_ruins: Land_hospital_ruins
	{
		scope = 2;
		displayName = "R t26x34 hospital_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Misc_PowerStation_ruins;
	class MAP_Misc_PowerStation_ruins: Land_Misc_PowerStation_ruins
	{
		scope = 2;
		displayName = "R t27x33 Misc_PowerStation_ruin";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Farm_Cowshed_b_ruins;
	class MAP_Farm_Cowshed_b_ruins: Land_Farm_Cowshed_b_ruins
	{
		scope = 2;
		displayName = "R t30x18 Farm_Cowshed_b_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Ind_SiloVelke_01_ruins;
	class Ind_SiloVelke_01_ruins: Land_Ind_SiloVelke_01_ruins
	{
		scope = 2;
		displayName = "R t30x23 Ind_SiloVelke_01_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_tovarna2_ruins;
	class MAP_tovarna2_ruins: Land_tovarna2_ruins
	{
		scope = 2;
		displayName = "R t31x34 tovarna2_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Ind_Pec_03_ruins;
	class MAP_Ind_Pec_03_ruins: Land_Ind_Pec_03_ruins
	{
		scope = 2;
		displayName = "R t31x52 Ind_Pec_03_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Farm_Cowshed_a_ruins;
	class MAP_Farm_Cowshed_a_ruins: Land_Farm_Cowshed_a_ruins
	{
		scope = 2;
		displayName = "R t32x24 Farm_Cowshed_a_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Ind_Pec_02_ruins;
	class MAP_Ind_Pec_02_ruins: Land_Ind_Pec_02_ruins
	{
		scope = 2;
		displayName = "R t32x56 Ind_Pec_02_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_GeneralStore_01_ruins;
	class MAP_A_GeneralStore_01_ruins: Land_A_GeneralStore_01_ruins
	{
		scope = 2;
		displayName = "R t34x32 A_GeneralStore_01_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_hangar_2_ruins;
	class MAP_hangar_2_ruins: Land_hangar_2_ruins
	{
		scope = 2;
		displayName = "R t35x25 hangar_2_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Office01_ruins;
	class MAP_A_Office01_ruins: Land_A_Office01_ruins
	{
		scope = 2;
		displayName = "R t41x26 A_Office01_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_A_Office02_ruins;
	class MAP_A_Office02_ruins: Land_A_Office02_ruins
	{
		scope = 2;
		displayName = "R t55x21 A_Office02_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class MAP_temp_nabrezi_ruins: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R t57x15 temp_nabrezi_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Rubble\temp_nabrezi_ruins.p3d";
	};
	class MAP_temp_nabrezi_najezd_ruins: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R t74x15 temp_nabrezi_najezd_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_Ruins\Rubble\temp_nabrezi_najezd_ruins.p3d";
	};
	class MAP_kopa_2: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R s05x07 kopa_2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\kopa_2.p3d";
	};
	class MAP_kopa_3: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R s05x07 kopa_3";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\kopa_3.p3d";
	};
	class Land_Shed_W01_ruins;
	class MAP_Shed_W01_ruins: Land_Shed_W01_ruins
	{
		scope = 2;
		displayName = "R s10x07 Shed_W01_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_HouseV_1L2_ruins;
	class MAP_HouseV_1L2_ruins: Land_HouseV_1L2_ruins
	{
		scope = 2;
		displayName = "R s12x13 HouseV_1L2_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_HouseV_1L1_ruins;
	class MAP_HouseV_1L1_ruins: Land_HouseV_1L1_ruins
	{
		scope = 2;
		displayName = "R s12x17 HouseV_1L1_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class MAP_rubble_bricks_02: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R s12x10 rubble_bricks_02";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\Ca\Structures\Ruins\rubble_bricks_02.p3d";
	};
	class MAP_rubble_concrete_01: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R s12x10 rubble_concrete_01";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\Ca\Structures\Ruins\rubble_concrete_01.p3d";
	};
	class MAP_rubble_bricks_03: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R s13x08 rubble_bricks_03";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\Ca\Structures\Ruins\rubble_bricks_03.p3d";
	};
	class MAP_rubble_bricks_04: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R s14x12 rubble_bricks_04";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\Ca\Structures\Ruins\rubble_bricks_04.p3d";
	};
	class Land_HouseV_2L_ruins;
	class MAP_HouseV_2L_ruins: Land_HouseV_2L_ruins
	{
		scope = 2;
		displayName = "R s14x15 HouseV_2L_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class MAP_rubble_metal_plates_02: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R s15x12 rubble_metal_plates_02";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\Ca\Structures\Ruins\rubble_metal_plates_02.p3d";
	};
	class MAP_rubble_wood_03: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R s15x12 rubble_wood_03";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\Ca\Structures\Ruins\rubble_wood_03.p3d";
	};
	class Land_HouseV2_05_ruins;
	class MAP_HouseV2_05_ruins: Land_HouseV2_05_ruins
	{
		scope = 2;
		displayName = "R s15x18 HouseV2_05_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_dum_zboreny_ruins;
	class MAP_dum_zboreny_ruins: Land_dum_zboreny_ruins
	{
		scope = 2;
		displayName = "R s16x10 dum_zboreny_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_hut_old02_ruins;
	class MAP_hut_old02_ruins: Land_hut_old02_ruins
	{
		scope = 2;
		displayName = "R s18x20 hut_old02_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_HouseV2_04_ruins;
	class MAP_HouseV2_04_ruins: Land_HouseV2_04_ruins
	{
		scope = 2;
		displayName = "R s23x23 HouseV2_04_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_HouseV2_03B_ruins;
	class MAP_HouseV2_03B_ruins: Land_HouseV2_03B_ruins
	{
		scope = 2;
		displayName = "R s24x27 HouseV2_03B_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_HouseBlock_B5_ruins;
	class MAP_HouseBlock_B5_ruins: Land_HouseBlock_B5_ruins
	{
		scope = 2;
		displayName = "R s25x24 HouseBlock_B5_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_HouseV2_01A_ruins;
	class MAP_HouseV2_01A_ruins: Land_HouseV2_01A_ruins
	{
		scope = 2;
		displayName = "R s27x17 HouseV2_01A_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_HouseV2_01B_ruins;
	class MAP_HouseV2_01B_ruins: Land_HouseV2_01B_ruins
	{
		scope = 2;
		displayName = "R s29x16 HouseV2_01B_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_HouseV2_02_ruins;
	class MAP_HouseV2_02_ruins: Land_HouseV2_02_ruins
	{
		scope = 2;
		displayName = "R s29x24 HouseV2_02_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Mil_House_ruins;
	class MAP_Mil_House_ruins: Land_Mil_House_ruins
	{
		scope = 2;
		displayName = "R s42x27 Mil_House_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_HouseV2_03_ruins;
	class MAP_HouseV2_03_ruins: Land_HouseV2_03_ruins
	{
		scope = 2;
		displayName = "R s44x27 HouseV2_03_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class MAP_rubble_rocks_01: MAP_Ruins_DNo
	{
		scope = 2;
		displayName = "R m20x20 rubble_rocks_01";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\Ca\Structures\Ruins\rubble_rocks_01.p3d";
	};
	class Land_HouseBlock_A1_1_ruins;
	class MAP_HouseBlock_A1_1_ruins: Land_HouseBlock_A1_1_ruins
	{
		scope = 2;
		displayName = "R m21x20 HouseBlock_A1_1_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class Land_Shed_wooden_ruins;
	class MAP_Shed_wooden_ruins: Land_Shed_wooden_ruins
	{
		scope = 2;
		displayName = "R l12x11 Shed_wooden_ruins";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EURuins";
		accuracy = 1000;
	};
	class MAP_Walls_Base: Static
	{
		displayName = "";
		accuracy = 0.1;
		vehicleClass = "MAP_EUWalls";
		model = "";
		nameSound = "fence";
		animated = 0;
		simulation = "house";
		cost = 0;
		armor = 1000;
		ladders[] = {};
		placement = "slope";
	};
	class MAP_Walls_DNo: MAP_Walls_Base
	{
		destrType = "DestructNo";
		accuracy = 1000;
	};
	class MAP_Walls_DTe: MAP_Walls_Base
	{
		destrType = "DestructTent";
		accuracy = 1000;
	};
	class MAP_Walls_DTr: MAP_Walls_Base
	{
		destrType = "DestructTree";
		accuracy = 1000;
	};
	class MAP_Walls_DBu: MAP_Walls_Base
	{
		destrType = "DestructBuilding";
		accuracy = 1000;
		class DestructionEffects
		{
			class HouseDestr
			{
				simulation = "destroy";
				type = "DelayedDestruction";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class Land_brana02nodoor;
	class MAP_brana02nodoor: Land_brana02nodoor
	{
		scope = 2;
		displayName = "G brana02nodoor";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUWalls";
		accuracy = 1000;
	};
	class Land_statek_brana;
	class MAP_statek_brana: Land_statek_brana
	{
		scope = 2;
		displayName = "G statek_brana";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUWalls";
		accuracy = 1000;
	};
	class Land_statek_brana_open;
	class MAP_statek_brana_open: Land_statek_brana_open
	{
		scope = 2;
		displayName = "G statek_brana_open";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUWalls";
		accuracy = 1000;
	};
	class Land_Wall_Gate_Kolchoz;
	class MAP_Wall_Gate_Kolchoz: Land_Wall_Gate_Kolchoz
	{
		scope = 2;
		displayName = "G Wall_Gate_Kolchoz";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUWalls";
		accuracy = 1000;
	};
	class Land_Wall_Gate_Ind1_L;
	class MAP_Wall_Gate_Ind1_L: Land_Wall_Gate_Ind1_L
	{
		scope = 2;
		displayName = "G Wall_Gate_Ind1_L";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUWalls";
		accuracy = 1000;
	};
	class Land_Wall_Gate_Ind1_R;
	class MAP_Wall_Gate_Ind1_R: Land_Wall_Gate_Ind1_R
	{
		scope = 2;
		displayName = "G Wall_Gate_Ind1_R";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUWalls";
		accuracy = 1000;
	};
	class Land_Wall_Gate_Ind2A_L;
	class MAP_Wall_Gate_Ind2A_L: Land_Wall_Gate_Ind2A_L
	{
		scope = 2;
		displayName = "G Wall_Gate_Ind2A_L";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUWalls";
		accuracy = 1000;
	};
	class Land_Wall_Gate_Ind2A_R;
	class MAP_Wall_Gate_Ind2A_R: Land_Wall_Gate_Ind2A_R
	{
		scope = 2;
		displayName = "G Wall_Gate_Ind2A_R";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUWalls";
		accuracy = 1000;
	};
	class Land_Wall_Gate_Ind2B_L;
	class MAP_Wall_Gate_Ind2B_L: Land_Wall_Gate_Ind2B_L
	{
		scope = 2;
		displayName = "G Wall_Gate_Ind2B_L";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUWalls";
		accuracy = 1000;
	};
	class Land_Wall_Gate_Ind2B_R;
	class MAP_Wall_Gate_Ind2B_R: Land_Wall_Gate_Ind2B_R
	{
		scope = 2;
		displayName = "G Wall_Gate_Ind2B_R";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUWalls";
		accuracy = 1000;
	};
	class Land_Wall_Gate_Ind2Rail_L;
	class MAP_Wall_Gate_Ind2Rail_L: Land_Wall_Gate_Ind2Rail_L
	{
		scope = 2;
		displayName = "G Wall_Gate_Ind2Rail_L";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUWalls";
		accuracy = 1000;
	};
	class Land_Wall_Gate_Ind2Rail_R;
	class MAP_Wall_Gate_Ind2Rail_R: Land_Wall_Gate_Ind2Rail_R
	{
		scope = 2;
		displayName = "G Wall_Gate_Ind2Rail_R";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUWalls";
		accuracy = 1000;
	};
	class Land_Wall_Gate_Village;
	class MAP_Wall_Gate_Village: Land_Wall_Gate_Village
	{
		scope = 2;
		displayName = "G Wall_Gate_Village";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUWalls";
		accuracy = 1000;
	};
	class MAP_plutek: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F plutek";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plutek.p3d";
	};
	class MAP_Plot_Wood: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Plot_Wood";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\Plot_Wood.p3d";
	};
	class MAP_Plot_Woodb: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Plot_Woodb";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\Plot_Woodb.p3d";
	};
	class MAP_Plot_Wood_door: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Plot_Wood_door";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\Plot_Wood_door.p3d";
	};
	class MAP_Plot_Wood_sloupek: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Plot_Wood_sloupek";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\Plot_Wood_sloupek.p3d";
	};
	class MAP_Plot_Wood1: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Plot_Wood1";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\Plot_Wood1.p3d";
	};
	class MAP_Plot_Wood1b: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Plot_Wood1b";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\Plot_Wood1b.p3d";
	};
	class MAP_Plot_Wood1_door: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Plot_Wood1_door";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\Plot_Wood1_door.p3d";
	};
	class MAP_plot_zed_drevo1: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F plot_zed-drevo1";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plot_zed-drevo1.p3d";
	};
	class MAP_plot_zed_drevo2: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F plot_zed-drevo2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plot_zed-drevo2.p3d";
	};
	class MAP_plot_zed_drevo3: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F plot_zed-drevo3";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plot_zed-drevo3.p3d";
	};
	class MAP_plot_zed_drevo_sloupek: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F plot_zed-drevo_sloupek";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plot_zed-drevo_sloupek.p3d";
	};
	class Land_plot_zed_drevo1_branka;
	class MAP_plot_zed_drevo1_branka: Land_plot_zed_drevo1_branka
	{
		scope = 2;
		displayName = "F plot_zed_drevo1_branka";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUWalls";
		accuracy = 1000;
	};
	class Land_plot_zboreny;
	class MAP_plot_zboreny: Land_plot_zboreny
	{
		scope = 2;
		displayName = "F plot_zboreny";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUWalls";
		accuracy = 1000;
	};
	class MAP_Wall_Wood1_5: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_Wood1_5";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_Wood1_5.p3d";
	};
	class MAP_Wall_Wood1_5_2: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_Wood1_5_2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_Wood1_5_2.p3d";
	};
	class MAP_Wall_Wood1_5_pole: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_Wood1_5_pole";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_Wood1_5_pole.p3d";
	};
	class Land_Gate_Wood1_5;
	class MAP_Gate_Wood1_5: Land_Gate_Wood1_5
	{
		scope = 2;
		displayName = "F Gate_Wood1_5";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUWalls";
		accuracy = 1000;
	};
	class Land_Wall_Gate_Wood1;
	class MAP_Wall_Gate_Wood1: Land_Wall_Gate_Wood1
	{
		scope = 2;
		displayName = "F Wall_Gate_Wood1";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUWalls";
		accuracy = 1000;
	};
	class MAP_Wall_Wood1D_5: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_Wood1D_5";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_Wood1D_5.p3d";
	};
	class MAP_Wall_Wood1D_5_2: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_Wood1D_5_2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_Wood1D_5_2.p3d";
	};
	class MAP_Wall_Wood1D_5_pole: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_Wood1D_5_pole";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_Wood1D_5_pole.p3d";
	};
	class MAP_Wall_Wood2_5: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_Wood2_5";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_Wood2_5.p3d";
	};
	class MAP_Wall_Wood2_5_D: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_Wood2_5_D";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_Wood2_5_D.p3d";
	};
	class MAP_Wall_Wood2_5_END: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_Wood2_5_END";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_Wood2_5_END.p3d";
	};
	class MAP_Wall_Wood2_5_END_2: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_Wood2_5_END_2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_Wood2_5_END_2.p3d";
	};
	class Land_Gate_wood2_5;
	class MAP_Gate_wood2_5: Land_Gate_wood2_5
	{
		scope = 2;
		displayName = "F Gate_wood2_5";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUWalls";
		accuracy = 1000;
	};
	class MAP_Wall_Wood2_5_pole: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_Wood2_5_pole";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_Wood2_5_pole.p3d";
	};
	class MAP_Wall_WoodVil_4: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_WoodVil_4";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_WoodVil_4.p3d";
	};
	class MAP_Wall_WoodVil_4_2: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_WoodVil_4_2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_WoodVil_4_2.p3d";
	};
	class MAP_Wall_WoodVil_4_pole: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_WoodVil_4_pole";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_WoodVil_4_pole.p3d";
	};
	class MAP_Wall_WoodVil_pole: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_WoodVil_pole";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_WoodVil_pole.p3d";
	};
	class MAP_Wall_VilVar1_6: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_VilVar1_6";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_VilVar1_6.p3d";
	};
	class MAP_Wall_VilVar1_Pole: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_VilVar1_Pole";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_VilVar1_Pole.p3d";
	};
	class MAP_Wall_VilVar2_4: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_VilVar2_4";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_VilVar2_4.p3d";
	};
	class MAP_Wall_VilVar2_4_2: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_VilVar2_4_2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_VilVar2_4_2.p3d";
	};
	class MAP_Wall_VilVar2_4_D: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_VilVar2_4_D";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_VilVar2_4_D.p3d";
	};
	class MAP_Wall_VilVar2_4_END: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_VilVar2_4_END";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_VilVar2_4_END.p3d";
	};
	class MAP_Wall_VilVar2_4_END_2: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_VilVar2_4_END_2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_VilVar2_4_END_2.p3d";
	};
	class MAP_Wall_VilVar2_Pole: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_VilVar2_Pole";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_VilVar2_Pole.p3d";
	};
	class MAP_Wall_FenW_7: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_FenW_7";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_FenW_7.p3d";
	};
	class MAP_Wall_FenW_7_D: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_FenW_7_D";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_FenW_7_D.p3d";
	};
	class MAP_Wall_FenW_7_S: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_FenW_7_S";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_FenW_7_S.p3d";
	};
	class MAP_DD_pletivo: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F DD_pletivo";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\DD_pletivo.p3d";
	};
	class MAP_DD_pletivo_dira: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F DD_pletivo_dira";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\DD_pletivo_dira.p3d";
	};
	class MAP_DD_pletivo_sl: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F DD_pletivo_sl";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\DD_pletivo_sl.p3d";
	};
	class MAP_Wall_Fen1_5: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_Fen1_5";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_Fen1_5.p3d";
	};
	class MAP_Wall_Fen1_5_2: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_Fen1_5_2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_Fen1_5_2.p3d";
	};
	class MAP_Wall_Fen1_5_Hole: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_Fen1_5_Hole";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_Fen1_5_Hole.p3d";
	};
	class MAP_Wall_Fen1_5_Pole: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_Fen1_5_Pole";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_Fen1_5_Pole.p3d";
	};
	class MAP_pletivo_wired: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F pletivo_wired";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\pletivo_wired.p3d";
	};
	class MAP_pletivo_wired_hole: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F pletivo_wired_hole";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\pletivo_wired_hole.p3d";
	};
	class MAP_pletivo_wired_branaL_civil: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F pletivo_wired_branaL_civil";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\pletivo_wired_branaL_civil.p3d";
	};
	class MAP_pletivo_wired_branaP: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F pletivo_wired_branaP";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\pletivo_wired_branaP.p3d";
	};
	class MAP_pletivo_wired_slope: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F pletivo_wired_slope";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\pletivo_wired_slope.p3d";
	};
	class MAP_Wall_IndFnc_3: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_IndFnc_3";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_IndFnc_3.p3d";
	};
	class MAP_Wall_IndFnc_3_D: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_IndFnc_3_D";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_IndFnc_3_D.p3d";
	};
	class MAP_Wall_IndFnc_3_Hole: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_IndFnc_3_Hole";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_IndFnc_3_Hole.p3d";
	};
	class MAP_Wall_IndFnc_9: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_IndFnc_9";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_IndFnc_9.p3d";
	};
	class MAP_Wall_IndFnc_Corner: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_IndFnc_Corner";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_IndFnc_Corner.p3d";
	};
	class MAP_Wall_IndFnc_Pole: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_IndFnc_Pole";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_IndFnc_Pole.p3d";
	};
	class MAP_plot_vlnplech1: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F plot_vlnplech1";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plot_vlnplech1.p3d";
	};
	class MAP_plot_vlnplech2: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F plot_vlnplech2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plot_vlnplech2.p3d";
	};
	class MAP_Wall_Tin_4: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_Tin_4";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_Tin_4.p3d";
	};
	class MAP_Wall_Tin_4_2: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_Tin_4_2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_Tin_4_2.p3d";
	};
	class MAP_Wall_Tin_Pole: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_Tin_Pole";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_Tin_Pole.p3d";
	};
	class MAP_Wall_TinCom_3: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_TinCom_3";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_TinCom_3.p3d";
	};
	class MAP_Wall_TinCom_9: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_TinCom_9";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_TinCom_9.p3d";
	};
	class MAP_Wall_TinCom_9_2: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_TinCom_9_2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_TinCom_9_2.p3d";
	};
	class MAP_Wall_TinCom_Pole: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_TinCom_Pole";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_TinCom_Pole.p3d";
	};
	class MAP_plot_green_draty: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F plot_green_draty";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plot_green_draty.p3d";
	};
	class MAP_plot_green_vrata: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F plot_green_vrata";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plot_green_vrata.p3d";
	};
	class MAP_plot_green_vrat_o: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F plot_green_vrat_o";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plot_green_vrat_o.p3d";
	};
	class MAP_plot_green_vrat_l: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F plot_green_vrat_l";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plot_green_vrat_l.p3d";
	};
	class MAP_plot_green_vrat_r: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F plot_green_vrat_r";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plot_green_vrat_r.p3d";
	};
	class MAP_plot_green_branka: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F plot_green_branka";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plot_green_branka.p3d";
	};
	class MAP_plot_green_brank_o: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F plot_green_brank_o";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plot_green_brank_o.p3d";
	};
	class MAP_plot_green_cihlsloup: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F plot_green_cihlsloup";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plot_green_cihlsloup.p3d";
	};
	class MAP_plot_rust_vrata: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F plot_rust_vrata";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plot_rust_vrata.p3d";
	};
	class MAP_plot_rust_draty: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F plot_rust_draty";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plot_rust_draty.p3d";
	};
	class MAP_plot_rust_vrat_o: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F plot_rust_vrat_o";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plot_rust_vrat_o.p3d";
	};
	class MAP_plot_rust_vrat_l: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F plot_rust_vrat_l";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plot_rust_vrat_l.p3d";
	};
	class MAP_plot_rust_vrat_r: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F plot_rust_vrat_r";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plot_rust_vrat_r.p3d";
	};
	class MAP_plot_rust_brank_o: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F plot_rust_brank_o";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plot_rust_brank_o.p3d";
	};
	class MAP_plot_rust_branka: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F plot_rust_branka";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plot_rust_branka.p3d";
	};
	class MAP_plot_rust_cihlsloup: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F plot_rust_cihlsloup";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plot_rust_cihlsloup.p3d";
	};
	class MAP_Wall_WoodF_5: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_WoodF_5";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_WoodF_5.p3d";
	};
	class MAP_Wall_WoodF_5_2: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_WoodF_5_2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_WoodF_5_2.p3d";
	};
	class MAP_Wall_WoodF_5_END: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Wall_WoodF_5_END";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_WoodF_5_END.p3d";
	};
	class MAP_Plot_Ohrada: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Plot_Ohrada";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\Plot_Ohrada.p3d";
	};
	class MAP_Plot_Ohrada_Zlomena: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F Plot_Ohrada_Zlomena";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\Plot_Ohrada_Zlomena.p3d";
	};
	class Land_Plot_Ohrada_Pruchozi;
	class MAP_Plot_Ohrada_Pruchozi: Land_Plot_Ohrada_Pruchozi
	{
		scope = 2;
		displayName = "F Plot_Ohrada_Pruchozi";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUWalls";
		accuracy = 1000;
	};
	class MAP_plot_vinice: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "F plot_vinice";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plot_vinice.p3d";
	};
	class MAP_Newplot: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Newplot";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\Newplot.p3d";
	};
	class MAP_Newplot2: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Newplot2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\Newplot2.p3d";
	};
	class MAP_plot_istan1_rovny_short: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W plot_istan1_rovny_short";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plot_istan1_rovny_short.p3d";
	};
	class MAP_plot_istan1_rovny_bezs: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W plot_istan1_rovny_bezs";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plot_istan1_rovny_bezs.p3d";
	};
	class MAP_plot_istan1_rovny: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W plot_istan1_rovny";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plot_istan1_rovny.p3d";
	};
	class MAP_plot_istan1_rovny_ohlod: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W plot_istan1_rovny_ohlod";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plot_istan1_rovny_ohlod.p3d";
	};
	class Land_plot_istan1_rovny_gate;
	class MAP_plot_istan1_rovny_gate: Land_plot_istan1_rovny_gate
	{
		scope = 2;
		displayName = "B plot_istan1_rovny_gate";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUWalls";
		accuracy = 1000;
	};
	class MAP_plot_istan1_rovny_end1: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W plot_istan1_rovny_end1";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plot_istan1_rovny_end1.p3d";
	};
	class MAP_plot_istan1_sloupek: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W plot_istan1_sloupek";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plot_istan1_sloupek.p3d";
	};
	class MAP_zidka01: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W zidka01";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\zidka01.p3d";
	};
	class MAP_zidka02: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W zidka02";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\zidka02.p3d";
	};
	class MAP_zidka03: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W zidka03";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\zidka03.p3d";
	};
	class MAP_zidka04: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W zidka04";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\zidka04.p3d";
	};
	class MAP_zidka_branka: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W zidka_branka";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\zidka_branka.p3d";
	};
	class MAP_Wall_CGry_5: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Wall_CGry_5";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_CGry_5.p3d";
	};
	class Land_Wall_CGry_5_D;
	class Wall_CGry_5_D: Land_Wall_CGry_5_D
	{
		scope = 2;
		displayName = "B Wall_CGry_5_D";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUWalls";
		accuracy = 1000;
	};
	class MAP_Wall_CGry_Corner: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Wall_CGry_Corner";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_CGry_Corner.p3d";
	};
	class MAP_Wall_CGry_Corner_2: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Wall_CGry_Corner_2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_CGry_Corner_2.p3d";
	};
	class MAP_Wall_CGry_End: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Wall_CGry_End";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_CGry_End.p3d";
	};
	class MAP_Wall_CGryLow_5: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Wall_CGryLow_5";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_CGryLow_5.p3d";
	};
	class MAP_Wall_CGryLow_End1: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Wall_CGryLow_End1";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_CGryLow_End1.p3d";
	};
	class MAP_Wall_CGryLow_End2: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Wall_CGryLow_End2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_CGryLow_End2.p3d";
	};
	class MAP_Wall_CYel_5: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Wall_CYel_5";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_CYel_5.p3d";
	};
	class MAP_Wall_CYel_Corner: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Wall_CYel_Corner";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_CYel_Corner.p3d";
	};
	class MAP_Wall_CYel_End: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Wall_CYel_End";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_CYel_End.p3d";
	};
	class MAP_Wall_CYel_End2: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Wall_CYel_End2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_CYel_End2.p3d";
	};
	class MAP_plot_istan3_short: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W plot_istan3_short";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plot_istan3_short.p3d";
	};
	class MAP_plot_istan3: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W plot_istan3";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plot_istan3.p3d";
	};
	class MAP_plot_istan3_sloupek: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W plot_istan3_sloupek";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\plot_istan3_sloupek.p3d";
	};
	class MAP_Wall_IndVar2_5: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Wall_IndVar2_5";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_IndVar2_5.p3d";
	};
	class MAP_Wall_IndVar2_5_D: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Wall_IndVar2_5_D";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_IndVar2_5_D.p3d";
	};
	class Land_Gate_IndVar2_5;
	class MAP_Gate_IndVar2_5: Land_Gate_IndVar2_5
	{
		scope = 2;
		displayName = "W Gate_IndVar2_5";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUWalls";
		accuracy = 1000;
	};
	class MAP_Wall_IndVar2_Pole: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Wall_IndVar2_Pole";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_IndVar2_Pole.p3d";
	};
	class MAP_Wall_CBrk_5: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Wall_CBrk_5";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_CBrk_5.p3d";
	};
	class Land_Wall_CBrk_5_D;
	class MAP_Wall_CBrk_5_D: Land_Wall_CBrk_5_D
	{
		scope = 2;
		displayName = "B Wall_CBrk_5_D";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUWalls";
		accuracy = 1000;
	};
	class MAP_Wall_CBrk_Corner: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Wall_CBrk_Corner";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_CBrk_Corner.p3d";
	};
	class MAP_Wall_CBrk_End: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Wall_CBrk_End";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_CBrk_End.p3d";
	};
	class MAP_Wall_Stone: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Wall_Stone";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_Stone.p3d";
	};
	class MAP_Wall_StoneD: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Wall_StoneD";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_StoneD.p3d";
	};
	class MAP_Walls_End: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Walls_End";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Walls_End.p3d";
	};
	class MAP_Walls_End_2: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Walls_End_2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Walls_End_2.p3d";
	};
	class MAP_Walls_End_Half: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Walls_End_Half";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Walls_End_Half.p3d";
	};
	class MAP_zed_civil: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W zed_civil";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\zed_civil.p3d";
	};
	class Land_zed_dira_civil;
	class MAP_zed_dira_civil: Land_zed_dira_civil
	{
		scope = 2;
		displayName = "B zed_dira_civil";
		icon = "\MAP_EU\icon\Icon.paa";
		vehicleClass = "MAP_EUWalls";
		accuracy = 1000;
	};
	class MAP_zed2_civil: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W zed2_civil";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\zed2_civil.p3d";
	};
	class MAP_zed_podplaz_civil: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W zed_podplaz_civil";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\zed_podplaz_civil.p3d";
	};
	class MAP_Wall_IndCnc_4: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Wall_IndCnc_4";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_IndCnc_4.p3d";
	};
	class MAP_Wall_IndCnc_4_D: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Wall_IndCnc_4_D";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_IndCnc_4_D.p3d";
	};
	class MAP_Wall_IndCnc_End_2: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Wall_IndCnc_End_2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_IndCnc_End_2.p3d";
	};
	class MAP_Wall_IndCnc_End_3: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Wall_IndCnc_End_3";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_IndCnc_End_3.p3d";
	};
	class MAP_Wall_IndCnc_Pole: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Wall_IndCnc_Pole";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_IndCnc_Pole.p3d";
	};
	class MAP_Wall_IndCnc2_3: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Wall_IndCnc2_3";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_IndCnc2_3.p3d";
	};
	class MAP_Ohrada_popelnice: MAP_Walls_DBu
	{
		scope = 2;
		displayName = "W Ohrada_popelnice";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\Ohrada_popelnice.p3d";
	};
	class MAP_Ohrada_popelnice_roh: MAP_Walls_DBu
	{
		scope = 2;
		displayName = "W Ohrada_popelnice_roh";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\Ohrada_popelnice_roh.p3d";
	};
	class MAP_Wall_IndVar1_5: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Wall_IndVar1_5";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_IndVar1_5.p3d";
	};
	class MAP_Wall_IndVar1_5_2: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Wall_IndVar1_5_2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_IndVar1_5_2.p3d";
	};
	class MAP_Wall_IndVar1_5_D: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Wall_IndVar1_5_D";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_IndVar1_5_D.p3d";
	};
	class MAP_Wall_IndVar1_5_D_2: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Wall_IndVar1_5_D_2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_IndVar1_5_D_2.p3d";
	};
	class MAP_Wall_IndVar1_Pole: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "W Wall_IndVar1_Pole";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\structures\wall\Wall_IndVar1_Pole.p3d";
	};
	class MAP_Plastovy_patnik: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "S Plastovy_patnik";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\Plastovy_patnik.p3d";
	};
	class MAP_SpurStone: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "S SpurStone";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\signs2\SpurStone.p3d";
	};
	class MAP_road_cone: MAP_Walls_DBu
	{
		scope = 2;
		displayName = "S road_cone";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\Data\Library\road_cone.p3d";
	};
	class MAP_tape_redwhite: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "S tape_redwhite";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\tape_redwhite.p3d";
	};
	class MAP_Patnik: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "S Patnik";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\Patnik.p3d";
	};
	class MAP_Patniky: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "S Patniky";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\Patniky.p3d";
	};
	class MAP_Obstacle_saddle: MAP_Walls_DBu
	{
		scope = 2;
		displayName = "S Obstacle_saddle";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\Data\Library\Obstacle_saddle.p3d";
	};
	class MAP_MSvodidla_5m: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "S Svodidla_5m";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\Svodidla_5m.p3d";
	};
	class MAP_Svodidla_5m: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "S Svodidla_5m";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Misc\Armory\redWhiteBarrier\Svodidla_5m.p3d";
	};
	class MAP_Betonovy_blok: MAP_Walls_DBu
	{
		scope = 2;
		displayName = "S Betonovy_blok";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\Betonovy_blok.p3d";
	};
	class MAP_Betonovy_blok_zacatek: MAP_Walls_DBu
	{
		scope = 2;
		displayName = "S Betonovy_blok_zacatek";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\Betonovy_blok_zacatek.p3d";
	};
	class MAP_CncBlock: MAP_Walls_DBu
	{
		scope = 2;
		displayName = "S CncBlock";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\CncBlock.p3d";
	};
	class MAP_CncBlock_D: MAP_Walls_DBu
	{
		scope = 2;
		displayName = "S CncBlock_D";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\CncBlock_D.p3d";
	};
	class MAP_CncBlock_stripes: MAP_Walls_DBu
	{
		scope = 2;
		displayName = "S CncBlock_stripes";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\CncBlock_stripes.p3d";
	};
	class MAP_Zabradli_pruhovane_levykonec: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "S Zabradli_pruhovane_levykonec";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\Zabradli_pruhovane_levykonec.p3d";
	};
	class MAP_Zabradli_pruhovane_pravykonec: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "S Zabradli_pruhovane_pravykonec";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\Zabradli_pruhovane_pravykonec.p3d";
	};
	class MAP_Zabradli_pruhovane_stred: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "S Zabradli_pruhovane_stred";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\Zabradli_pruhovane_stred.p3d";
	};
	class MAP_zavora_2: MAP_Walls_DTr
	{
		scope = 2;
		displayName = "S zavora_2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\zavora_2.p3d";
	};
	class MAP_Misc_WindBreak: MAP_Walls_DBu
	{
		scope = 2;
		displayName = "S Misc_WindBreak";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Misc\Misc_WindBreak\Misc_WindBreak.p3d";
	};
	class MAP_Misc_Base: Static
	{
		displayName = "";
		accuracy = 0.1;
		vehicleClass = "MAP_EUMisc";
		model = "";
		nameSound = "";
		animated = 0;
		simulation = "house";
		cost = 0;
		armor = 1000;
		ladders[] = {};
		placement = "vertical";
	};
	class MAP_Misc_DNo: MAP_Misc_Base
	{
		destrType = "DestructNo";
		accuracy = 1000;
	};
	class MAP_Misc_DTe: MAP_Misc_Base
	{
		destrType = "DestructTent";
		accuracy = 1000;
	};
	class MAP_Misc_DTr: MAP_Misc_Base
	{
		destrType = "DestructTree";
		accuracy = 1000;
	};
	class MAP_Misc_DBu: MAP_Misc_Base
	{
		destrType = "DestructBuilding";
		accuracy = 1000;
		class DestructionEffects
		{
			class HouseDestr
			{
				simulation = "destroy";
				type = "DelayedDestruction";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class MAP_Misc_HayStack: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "M Misc_HayStack";
		icon = "\MAP_EU\icon\EM.paa";
		model = "\CA\Structures\Misc\Misc_HayStack\Misc_HayStack.p3d";
	};
	class MAP_seno_balik: MAP_Misc_DTr
	{
		scope = 2;
		displayName = "M seno_balik";
		icon = "\MAP_EU\icon\EM.paa";
		model = "\CA\misc\seno_balik.p3d";
	};
	class MAP_Stoh: MAP_Misc_DTe
	{
		scope = 2;
		displayName = "M Stoh";
		icon = "\MAP_EU\icon\EM.paa";
		model = "\CA\buildings\misc\Stoh.p3d";
	};
	class MAP_pneu: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "M pneu";
		icon = "\MAP_EU\icon\EM.paa";
		model = "\CA\Structures\Misc\Armory\pneu\pneu.p3d";
	};
	class MAP_Misc_TyreHeap: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "M Misc_TyreHeap";
		icon = "\MAP_EU\icon\EM.paa";
		model = "\CA\misc\Misc_TyreHeap.p3d";
	};
	class MAP_sekyraspalek: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "M sekyraspalek";
		icon = "\MAP_EU\icon\EM.paa";
		model = "\CA\misc\sekyraspalek.p3d";
	};
	class MAP_Misc_WoodPile: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "M Misc_WoodPile";
		icon = "\MAP_EU\icon\EM.paa";
		model = "\CA\Structures\Misc\Misc_WoodPile\Misc_WoodPile.p3d";
	};
	class MAP_drevo_hromada: MAP_Misc_DTr
	{
		scope = 2;
		displayName = "M drevo_hromada";
		icon = "\MAP_EU\icon\EM.paa";
		model = "\CA\buildings\misc\drevo_hromada.p3d";
	};
	class MAP_Ind_BoardsPack1: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "M Ind_BoardsPack1";
		icon = "\MAP_EU\icon\EM.paa";
		model = "\CA\Structures\Ind_SawMill\Ind_BoardsPack1.p3d";
	};
	class MAP_Ind_BoardsPack2: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "M Ind_BoardsPack2";
		icon = "\MAP_EU\icon\EM.paa";
		model = "\CA\Structures\Ind_SawMill\Ind_BoardsPack2.p3d";
	};
	class MAP_Ind_Timbers: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "M Ind_Timbers";
		icon = "\MAP_EU\icon\EM.paa";
		model = "\CA\Structures\Ind_SawMill\Ind_Timbers.p3d";
		placement = "slope";
	};
	class MAP_ground_garbage_long: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "M ground_garbage_long";
		icon = "\MAP_EU\icon\EM.paa";
		model = "\CA\misc\ground_garbage_long.p3d";
	};
	class MAP_ground_garbage_square3: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "M ground_garbage_square3";
		icon = "\MAP_EU\icon\EM.paa";
		model = "\CA\misc\ground_garbage_square3.p3d";
	};
	class MAP_ground_garbage_square5: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "M ground_garbage_square5";
		icon = "\MAP_EU\icon\EM.paa";
		model = "\CA\misc\ground_garbage_square5.p3d";
	};
	class MAP_garbage_misc: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "M garbage_misc";
		icon = "\MAP_EU\icon\EM.paa";
		model = "\CA\misc\garbage_misc.p3d";
	};
	class MAP_garbage_paleta: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "M garbage_paleta";
		icon = "\MAP_EU\icon\EM.paa";
		model = "\CA\misc\garbage_paleta.p3d";
	};
	class MAP_popelnice: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "M popelnice";
		icon = "\MAP_EU\icon\EM.paa";
		model = "\CA\misc\popelnice.p3d";
	};
	class MAP_Kontejner: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "M Kontejner";
		icon = "\MAP_EU\icon\EM.paa";
		model = "\CA\misc\Kontejner.p3d";
	};
	class MAP_Misc_GContainer_Big: MAP_Misc_DNo
	{
		scope = 2;
		displayName = "M Misc_GContainer_Big";
		icon = "\MAP_EU\icon\EM.paa";
		model = "\CA\Structures\Misc\Misc_GContainer_Big\Misc_GContainer_Big.p3d";
	};
	class MAP_dirthump01: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "M dirthump01";
		icon = "\MAP_EU\icon\EM.paa";
		model = "\CA\Structures\Misc\Armory\dirthump\dirthump01.p3d";
	};
	class MAP_dirthump02: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "M dirthump02";
		icon = "\MAP_EU\icon\EM.paa";
		model = "\CA\Structures\Misc\Armory\dirthump\dirthump02.p3d";
	};
	class MAP_dirthump03: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "M dirthump03";
		icon = "\MAP_EU\icon\EM.paa";
		model = "\CA\Structures\Misc\Armory\dirthump\dirthump03.p3d";
	};
	class MAP_humps_dirt: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "M humps_dirt";
		icon = "\MAP_EU\icon\EM.paa";
		model = "\ca\Data\Library\humps_dirt.p3d";
	};
	class MAP_ruiny_kopa_1Tv: MAP_Misc_DNo
	{
		scope = 2;
		displayName = "M ruiny_kopa_1Tv";
		icon = "\MAP_EU\icon\EM.paa";
		model = "\CA\Structures\Proxy_Ruins\Rubble\ruiny_kopa_1Tv.p3d";
	};
	class MAP_ruiny_kopa_1v: MAP_Misc_DNo
	{
		scope = 2;
		displayName = "M ruiny_kopa_1v";
		icon = "\MAP_EU\icon\EM.paa";
		model = "\CA\Structures\Proxy_Ruins\Rubble\ruiny_kopa_1v.p3d";
	};
	class MAP_Barel1: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T Barel1";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\misc\Barel1.p3d";
	};
	class MAP_Barel3: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T Barel3";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\misc\Barel3.p3d";
	};
	class MAP_Barel4: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T Barel4";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\misc\Barel4.p3d";
	};
	class MAP_Barel5: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T Barel5";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\misc\Barel5.p3d";
	};
	class MAP_Barel6: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T Barel6";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\misc\Barel6.p3d";
	};
	class MAP_Barel7: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T Barel7";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\misc\Barel7.p3d";
	};
	class MAP_Barel8: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T Barel8";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\misc\Barel8.p3d";
	};
	class MAP_barrel_empty: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T barrel_empty";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\Structures\Misc\Armory\Barels\barrel_empty.p3d";
	};
	class MAP_barrel_sand: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T barrel_sand";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\Structures\Misc\Armory\Barels\barrel_sand.p3d";
	};
	class MAP_barrel_water: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T barrel_water";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\Structures\Misc\Armory\Barels\barrel_water.p3d";
	};
	class MAP_Barels: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T Barels";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\misc\Barels.p3d";
	};
	class MAP_Barels2: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T Barels2";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\misc\Barels2.p3d";
	};
	class MAP_Barels3: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T Barels3";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\misc\Barels3.p3d";
	};
	class MAP_paletaA: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T paletaA";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\misc\paletaA.p3d";
	};
	class MAP_paletyC: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T paletyC";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\misc\paletyC.p3d";
	};
	class MAP_paletyD: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T paletyD";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\misc\paletyD.p3d";
	};
	class MAP_Pallets_Column: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T Pallets_Column";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\misc\Pallets_Column.p3d";
	};
	class MAP_Misc_palletsfoiled: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T Misc_palletsfoiled";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\misc\Misc_palletsfoiled.p3d";
	};
	class MAP_Misc_palletsfoiled_heap: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T Misc_palletsfoiled_heap";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\misc\Misc_palletsfoiled_heap.p3d";
	};
	class MAP_obstacle_get_over: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T obstacle_get_over";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\misc\obstacle_get_over.p3d";
	};
	class MAP_obstacle_prone: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T obstacle_prone";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\misc\obstacle_prone.p3d";
	};
	class MAP_obstacle_run_duck: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T obstacle_run_duck";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\misc\obstacle_run_duck.p3d";
	};
	class MAP_Misc_cargo_cont_net1: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T Misc_cargo_cont_net1";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\misc\Misc_cargo_cont_net1.p3d";
	};
	class MAP_Misc_cargo_cont_net2: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T Misc_cargo_cont_net2";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\misc\Misc_cargo_cont_net2.p3d";
	};
	class MAP_Misc_cargo_cont_net3: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T Misc_cargo_cont_net3";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\misc\Misc_cargo_cont_net3.p3d";
	};
	class MAP_P_cihly1: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T cihly1";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\Ca\Structures\A_BuildingWIP\data\cihly1\cihly1.p3d";
	};
	class MAP_P_cihly2: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T cihly2";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\Ca\Structures\A_BuildingWIP\data\cihly2\cihly2.p3d";
	};
	class MAP_P_cihly3: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T cihly3";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\Ca\Structures\A_BuildingWIP\data\cihly3\cihly3.p3d";
	};
	class MAP_P_cihly4: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T cihly4";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\Ca\Structures\A_BuildingWIP\data\cihly4\cihly4.p3d";
	};
	class MAP_P_ytong: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T ytong";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\Ca\Structures\A_BuildingWIP\data\ytong\ytong.p3d";
	};
	class MAP_box_c: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T box_c";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\Structures\Furniture\Decoration\box_c\box_c.p3d";
	};
	class MAP_metalcrate: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T metalcrate";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\Structures\Furniture\Cases\metalcrate\metalcrate.p3d";
	};
	class MAP_metalcrate_02: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T metalcrate_02";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\Structures\Furniture\Cases\metalcrate_02\metalcrate_02.p3d";
	};
	class MAP_P_bedna: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T bedna";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\Ca\Structures\A_BuildingWIP\data\bedna\bedna.p3d";
	};
	class MAP_drevena_bedna: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T drevena_bedna";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\misc\drevena_bedna.p3d";
	};
	class MAP_Misc_cargo_cont_tiny: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T Misc_cargo_cont_tiny";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\misc\Misc_cargo_cont_tiny.p3d";
	};
	class MAP_Misc_cargo_cont_small2: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T Misc_cargo_cont_small2";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\misc\Misc_cargo_cont_small2.p3d";
	};
	class MAP_Misc_cargo_cont_small: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T Misc_cargo_cont_small";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\misc\Misc_cargo_cont_small.p3d";
	};
	class MAP_P_pipe_small: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T pipe-small";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\Ca\Structures\A_BuildingWIP\data\pipe-small\pipe-small.p3d";
	};
	class MAP_P_pipe_big: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T pipe-big";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\Ca\Structures\A_BuildingWIP\data\pipe-big\pipe-big.p3d";
	};
	class MAP_Misc_G_Pipes: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T Misc_G_Pipes";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\Structures\Misc\Misc_G_Pipes\Misc_G_Pipes.p3d";
	};
	class Misc_concrete: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "T Misc_concrete";
		icon = "\MAP_EU\icon\EC.paa";
		model = "\CA\buildings2\Misc_concrete\Misc_Concrete_High.p3d";
	};
	class MAP_brana: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "P brana";
		icon = "\MAP_EU\icon\EP.paa";
		model = "\CA\misc\brana.p3d";
	};
	class MAP_Piskoviste: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "P Piskoviste";
		icon = "\MAP_EU\icon\EP.paa";
		model = "\CA\misc\Piskoviste.p3d";
	};
	class MAP_Houpacka: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "P Houpacka";
		icon = "\MAP_EU\icon\EP.paa";
		model = "\CA\misc\Houpacka.p3d";
	};
	class MAP_nastenkaX: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "P nastenkaX";
		icon = "\MAP_EU\icon\EP.paa";
		model = "\CA\misc\nastenkaX.p3d";
	};
	class MAP_woodenRamp: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "O woodenRamp";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Misc\Armory\woodenRamp\woodenRamp.p3d";
	};
	class MAP_concrete_block: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "O concrete_block";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Misc\Armory\concrete_block\concrete_block.p3d";
	};
	class MAP_ramp_concrete: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "O ramp_concrete";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\Data\Library\ramp_concrete.p3d";
	};
	class MAP_Concrete_Ramp: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "O Concrete_Ramp";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Misc\Armory\Concrete_Ramp\Concrete_Ramp.p3d";
	};
	class MAP_Heli_H_army: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "G Heli_H_army";
		icon = "\MAP_EU\icon\EH.paa";
		model = "\CA\misc\Heli_H_army.p3d";
	};
	class MAP_Heli_H_civil: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "G Heli_H_civil";
		icon = "\MAP_EU\icon\EH.paa";
		model = "\CA\misc\Heli_H_civil.p3d";
	};
	class MAP_Heli_H_cross: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "G Heli_H_cross";
		icon = "\MAP_EU\icon\EH.paa";
		model = "\CA\misc\Heli_H_cross.p3d";
	};
	class MAP_Heli_H_rescue: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "G Heli_H_rescue";
		icon = "\MAP_EU\icon\EH.paa";
		model = "\CA\misc\Heli_H_rescue.p3d";
	};
	class MAP_Sr_border: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "G Sr_border";
		icon = "\MAP_EU\icon\EH.paa";
		model = "\CA\misc2\Sr_border.p3d";
	};
	class MAP_snow: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "S snow";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\snow.p3d";
	};
	class MAP_snowman: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "S snowman";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\snowman.p3d";
	};
	class MAP_stanek_3: MAP_Misc_DTe
	{
		scope = 2;
		displayName = "D stanek_3";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\stanek_3.p3d";
	};
	class MAP_stanek_3_d: MAP_Misc_DTe
	{
		scope = 2;
		displayName = "D stanek_3_d";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\stanek_3_d.p3d";
	};
	class MAP_stanek_3B: MAP_Misc_DTe
	{
		scope = 2;
		displayName = "D stanek_3B";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\stanek_3B.p3d";
	};
	class MAP_psi_bouda: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "D psi_bouda";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\psi_bouda.p3d";
	};
	class MAP_ChickenCoop: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "D Misc_ChickenCoop";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Misc\ChickenCoop\Misc_ChickenCoop.p3d";
	};
	class MAP_Misc_Hutch: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "D Misc_Hutch";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Misc\Hutch\Misc_Hutch.p3d";
	};
	class Land_kulna;
	class MAP_kulna: Land_kulna
	{
		scope = 2;
		displayName = "D kulna";
		vehicleClass = "MAP_EUMisc";
		accuracy = 1000;
	};
	class Land_bouda_plech;
	class MAP_bouda_plech: Land_bouda_plech
	{
		scope = 2;
		displayName = "D bouda_plech";
		vehicleClass = "MAP_EUMisc";
		accuracy = 1000;
	};
	class MAP_kasna_new: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "D kasna_new";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\kasna_new.p3d";
	};
	class MAP_Misc_Boogieman: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "D Misc_Boogieman";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Misc\Misc_Small\Misc_Boogieman.p3d";
	};
	class MAP_Misc_Greenhouse: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "D Misc_Greenhouse";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Misc\Misc_Greenhouse\Misc_Greenhouse.p3d";
	};
	class MAP_phone_box: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "D phone_box";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\phone_box.p3d";
	};
	class Land_KBud;
	class MAP_KBud: Land_KBud
	{
		scope = 2;
		displayName = "D KBud";
		vehicleClass = "MAP_EUMisc";
		accuracy = 1000;
	};
	class MAP_Toilet: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "D Toilet";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\Toilet.p3d";
	};
	class MAP_misc_deerstand: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "D misc_deerstand";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Misc\misc_deerstand\misc_deerstand.p3d";
	};
	class MAP_fire: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "D fire";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\fire.p3d";
	};
	class MAP_campfire: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "D campfire";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\campfire.p3d";
	};
	class MAP_Misc_Well: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "D Misc_Well";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Misc\Misc_Well\Misc_Well.p3d";
	};
	class MAP_Misc_WellPump: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "D Misc_WellPump";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Misc\Misc_WellPump\Misc_WellPump.p3d";
	};
	class Land_pumpa;
	class MAP_pumpa: Land_pumpa
	{
		scope = 2;
		displayName = "D pumpa";
		vehicleClass = "MAP_EUMisc";
		accuracy = 1000;
	};
	class MAP_Misc_PostBox: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "D Misc_PostBox";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Misc\Misc_PostBox\Misc_PostBox.p3d";
	};
	class MAP_PowerGenerator: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "D PowerGenerator";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\PowerGenerator\PowerGenerator.p3d";
	};
	class MAP_Ladder: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "E Ladder";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\Ladder.p3d";
	};
	class MAP_LadderHalf: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "E LadderHalf";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\LadderHalf.p3d";
	};
	class Ladder;
	class MAP_P_Ladder: Ladder
	{
		scope = 2;
		displayName = "E Ladder";
		vehicleClass = "MAP_EUMisc";
		accuracy = 1000;
	};
	class LadderLong;
	class MAP_P_LadderLong: LadderLong
	{
		scope = 2;
		displayName = "E LadderLong";
		vehicleClass = "MAP_EUMisc";
		accuracy = 1000;
	};
	class MAP_P_Stavebni_kozy: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "E Stavebni_kozy";
		model = "\Ca\Structures\A_BuildingWIP\data\Stavebni_kozy\koz.p3d";
	};
	class Land_leseni2x;
	class MAP_leseni2x: Land_leseni2x
	{
		scope = 2;
		displayName = "E leseni2x";
		vehicleClass = "MAP_EUMisc";
		accuracy = 1000;
	};
	class Land_leseni4x;
	class MAP_leseni4x: Land_leseni4x
	{
		scope = 2;
		displayName = "E leseni4x";
		vehicleClass = "MAP_EUMisc";
		accuracy = 1000;
	};
	class MAP_Misc_Scaffolding: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "E Misc_Scaffolding";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Misc\Misc_Scaffolding\Misc_Scaffolding.p3d";
	};
	class MAP_GasMeterExt: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "E GasMeterExt";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_BuildingParts\GasMeterExt\GasMeterExt.p3d";
	};
	class MAP_AirCond_small: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "E AirCond_small";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_BuildingParts\Aircondition\AirCond_small.p3d";
	};
	class MAP_AirCond_big: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "E AirCond_big";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_BuildingParts\Aircondition\AirCond_big.p3d";
	};
	class MAP_AirCondition_A: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "E AirCondition_A";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_BuildingParts\Roof\Aircondition\AirCondition_A.p3d";
	};
	class MAP_AirCondition_B: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "E AirCondition_B";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_BuildingParts\Roof\Aircondition\AirCondition_B.p3d";
	};
	class MAP_FlagHolder: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "E FlagHolder";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings2\BuildingParts\FlagHolder\FlagHolder.p3d";
	};
	class MAP_FuseBox: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "E FuseBox";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings2\BuildingParts\FuseBox\FuseBox.p3d";
	};
	class MAP_antenna_big_roof: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "E antenna_big_roof";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_BuildingParts\Roof\antennabigroof\antenna_big_roof.p3d";
	};
	class MAP_antenna_small_roof: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "E antenna_small_roof";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_BuildingParts\Roof\antennasmallroof\antenna_small_roof.p3d";
	};
	class MAP_antenna_small_roof_1: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "E antenna_small_roof_1";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_BuildingParts\Roof\antennasmallroof\antenna_small_roof_1.p3d";
	};
	class MAP_Misc_loudspeakers: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "E Misc_loudspeakers";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\Misc_loudspeakers.p3d";
	};
	class MAP_parabola_big: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "E parabola_big";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\parabola_big\parabola_big.p3d";
	};
	class MAP_LightningConductorBottom: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "E LightningConductorBottom";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_BuildingParts\LightningCond\LightningConductorBottom\LightningConductorBottom.p3d";
	};
	class MAP_LightningConductorConnection: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "E LightningConductorConnection";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_BuildingParts\LightningCond\LightningConductorConnection\LightningConductorConnection.p3d";
	};
	class MAP_LightningConductorCorner: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "E LightningConductorCorner";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_BuildingParts\LightningCond\LightningConductorCorner\LightningConductorCorner.p3d";
	};
	class MAP_LightningConductorMiddle: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "E LightningConductorMiddle";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_BuildingParts\LightningCond\LightningConductorMiddle\LightningConductorMiddle.p3d";
	};
	class MAP_LightningConductorMiddleShort: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "E LightningConductorMiddleShort";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_BuildingParts\LightningCond\LightningConductorMiddle\LightningConductorMiddleShort.p3d";
	};
	class MAP_LightningConductorTop: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "E LightningConductorTop";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_BuildingParts\LightningCond\LightningConductorTop\LightningConductorTop.p3d";
	};
	class MAP_P_doors: MAP_Misc_DNo
	{
		scope = 2;
		displayName = "E doors";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\water2\LHD\data\doors.p3d";
	};
	class MAP_P_interier: MAP_Misc_DNo
	{
		scope = 2;
		displayName = "E interier";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\water2\LHD\data\interier.p3d";
	};
	class MAP_P_interier_tma: MAP_Misc_DNo
	{
		scope = 2;
		displayName = "E interier_tma";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\water2\LHD\data\interier_tma.p3d";
	};
	class MAP_P_podpaluba_3: MAP_Misc_DNo
	{
		scope = 2;
		displayName = "E podpaluba_3";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\water2\LHD\data\podpaluba_3.p3d";
	};
	class MAP_P_podpaluba_4: MAP_Misc_DNo
	{
		scope = 2;
		displayName = "E podpaluba_4";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\water2\LHD\data\podpaluba_4.p3d";
	};
	class MAP_drapes: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "E drapes";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings2\BuildingParts\drapes\drapes.p3d";
	};
	class MAP_drapes_long: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "E drapes_long";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings2\BuildingParts\drapes\drapes_long.p3d";
	};
	class MAP_P_DoorGlass: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "E DoorGlass";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\House\A_Office01\Data\Proxy\DoorGlass.p3d";
	};
	class MAP_P_DoorInterier: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "E DoorInterier";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\House\A_Office01\Data\Proxy\DoorInterier.p3d";
	};
	class MAP_P_DoorInterier_Closed: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "E DoorInterier_Closed";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\House\A_Office01\Data\Proxy\DoorInterier_Closed.p3d";
	};
	class MAP_P_DoorSmallGlass: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "E DoorSmallGlass";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\House\A_Office01\Data\Proxy\DoorSmallGlass.p3d";
	};
	class MAP_P_WindowHall: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "E WindowHall";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\House\A_Office01\Data\Proxy\WindowHall.p3d";
	};
	class MAP_P_WindowLarge: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "E WindowLarge";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\House\A_Office01\Data\Proxy\WindowLarge.p3d";
	};
	class MAP_P_WindowSmall: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "E WindowSmall";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\House\A_Office01\Data\Proxy\WindowSmall.p3d";
	};
	class MAP_P_Zarivky: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "E Zarivky";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\House\A_Office01\Data\Proxy\Zarivky.p3d";
	};
	class MAP_HouseV2_02_window: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "E HouseV2_02_window";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_BuildingParts\House\HouseV2_02_window.p3d";
	};
	class MAP_InvisibleBarrier: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "X InvisibleBarrier";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\InvisibleBarrier.p3d";
	};
	class MAP_InvisibleBarrier2: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "X InvisibleBarrier2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\InvisibleBarrier2.p3d";
	};
	class MAP_InvisibleBarrier3: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "X InvisibleBarrier3";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\InvisibleBarrier3.p3d";
	};
	class MAP_transparentWall: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "X transparentWall";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\transparentWall.p3d";
	};
	class MAP_Sphere: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "X Sphere";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\Sphere.p3d";
	};
	class MAP_Sphere2: MAP_Misc_DBu
	{
		scope = 2;
		displayName = "X Sphere2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\Sphere2.p3d";
	};
	class MAP_Signs_Base: Static
	{
		displayName = "";
		accuracy = 0.1;
		vehicleClass = "MAP_EUSigns";
		model = "";
		nameSound = "";
		animated = 0;
		simulation = "house";
		cost = 0;
		armor = 300;
		ladders[] = {};
		placement = "slope";
	};
	class MAP_Signs_DNo: MAP_Signs_Base
	{
		destrType = "DestructNo";
		accuracy = 1000;
	};
	class MAP_Signs_DTe: MAP_Signs_Base
	{
		destrType = "DestructTent";
		accuracy = 1000;
	};
	class MAP_Signs_DTr: MAP_Signs_Base
	{
		destrType = "DestructTree";
		accuracy = 1000;
		placement = "vertical";
	};
	class MAP_Signs_DBu: MAP_Signs_Base
	{
		destrType = "DestructBuilding";
		accuracy = 1000;
		class DestructionEffects
		{
			class HouseDestr
			{
				simulation = "destroy";
				type = "DelayedDestruction";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class MAP_sign_crossRoad: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "A sign_crossRoad.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_crossRoad.p3d";
	};
	class MAP_sign_crossRoad_new: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "A sign_crossRoad_new.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_crossRoad_new.p3d";
	};
	class MAP_sign_crossRoadMain: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "A sign_crossRoadMain.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_crossRoadMain.p3d";
	};
	class MAP_sign_crossRoadMain_new: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "A sign_crossRoadMain_new.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_crossRoadMain_new.p3d";
	};
	class MAP_sign_upHill: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "A sign_upHill.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_upHill.p3d";
	};
	class MAP_sign_upHil_new: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "A sign_upHil_new.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_upHil_new.p3d";
	};
	class MAP_sign_downHill: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "A sign_downHill.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_downHill.p3d";
	};
	class MAP_sign_downHill_new: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "A sign_downHill_new.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_downHill_new.p3d";
	};
	class MAP_sign_left: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "A sign_left.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_left.p3d";
	};
	class MAP_sign_left_new: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "A sign_left_new.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_left_new.p3d";
	};
	class MAP_sign_right: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "A sign_right.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_right.p3d";
	};
	class MAP_sign_right_new: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "A sign_right_new.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_right_new.p3d";
	};
	class MAP_sign_serpentine_left: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "A sign_serpentine_left.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_serpentine_left.p3d";
	};
	class MAP_sign_serpentine_left_new: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "A sign_serpentine_left_new.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_serpentine_left_new.p3d";
	};
	class MAP_sign_serpentine_right: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "A sign_serpentine_right.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_serpentine_right.p3d";
	};
	class MAP_sign_serpentine_right_new: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "A sign_serpentine_right_new.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_serpentine_right_new.p3d";
	};
	class MAP_sign_attention: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "A sign_attention.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_attention.p3d";
	};
	class MAP_sign_fallingStones: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "A sign_fallingStones.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_fallingStones.p3d";
	};
	class MAP_sign_fallingStones_new: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "A sign_fallingStones_new.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_fallingStones_new.p3d";
	};
	class MAP_sign_roadworks_new: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "A sign_roadworks_new.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_roadworks_new.p3d";
	};
	class MAP_sign_flyAWayGrit: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "A sign_flyAWayGrit.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_flyAWayGrit.p3d";
	};
	class MAP_sign_badRoadside: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "A sign_badRoadside.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_badRoadside.p3d";
	};
	class MAP_sign_children_new: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "A sign_children_new.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_children_new.p3d";
	};
	class MAP_sign_pass_new: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "A sign_pass_new.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_pass_new.p3d";
	};
	class MAP_sign_cow: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "A sign_cow.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_cow.p3d";
	};
	class MAP_sign_cow_new: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "A sign_cow_new.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_cow_new.p3d";
	};
	class MAP_sign_deer: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "A sign_deer.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_deer.p3d";
	};
	class MAP_sign_deer_new: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "A sign_deer_new.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_deer_new.p3d";
	};
	class MAP_sign_airport: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "A sign_airport.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_airport.p3d";
	};
	class MAP_sign_airport_new: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "A sign_airport_new.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_airport_new.p3d";
	};
	class MAP_sign_train: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "A sign_train.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_train.p3d";
	};
	class MAP_sign_crosstrain: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "A sign_crosstrain.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_crosstrain.p3d";
	};
	class MAP_sign_danger: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "A sign_danger.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_danger.p3d";
	};
	class MAP_sign_leftDirection: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_leftDirection.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_leftDirection.p3d";
	};
	class MAP_sign_leftDirection_new: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_leftDirection_new.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_leftDirection_new.p3d";
	};
	class MAP_sign_rightDirection: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_rightDirection.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_rightDirection.p3d";
	};
	class MAP_sign_rightDirection_new: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_rightDirection_new.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_rightDirection_new.p3d";
	};
	class MAP_arrows_desk_L: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T arrows_desk_L";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\Structures\Misc\Armory\Arrow_sign2\arrows_desk_L.p3d";
	};
	class MAP_arrows_desk_R: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T arrows_desk_R";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\Structures\Misc\Armory\Arrow_sign2\arrows_desk_R.p3d";
	};
	class MAP_arrows_yellow_L: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T arrows_yellow_L";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\Structures\Misc\Armory\Arrow_sign2\arrows_yellow_L.p3d";
	};
	class MAP_arrows_yellow_R: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T arrows_yellow_R";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\Structures\Misc\Armory\Arrow_sign2\arrows_yellow_R.p3d";
	};
	class MAP_sign_main: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_main.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_main.p3d";
	};
	class MAP_sign_main_new: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_main_new.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_main_new.p3d";
	};
	class MAP_sign_main_end: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_main_end.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_main_end.p3d";
	};
	class MAP_sign_main_end_new: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_main_end_new.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_main_end_new.p3d";
	};
	class MAP_sign_priority: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_priority.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_priority.p3d";
	};
	class MAP_sign_priority_new: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_priority_new.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_priority_new.p3d";
	};
	class MAP_sign_stop: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_stop.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_stop.p3d";
	};
	class MAP_sign_stop_new: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_stop_new.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_stop_new.p3d";
	};
	class MAP_sign_noDriving: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_noDriving.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_noDriving.p3d";
	};
	class MAP_sign_noDriving_new: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_noDriving_new.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_noDriving_new.p3d";
	};
	class MAP_sign_noDrivingWronWay: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_noDrivingWronWay.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_noDrivingWronWay.p3d";
	};
	class MAP_sign_noDrivingWronWay_new: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_noDrivingWronWay_new.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_noDrivingWronWay_new.p3d";
	};
	class MAP_sign_noOverTaking: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_noOverTaking.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_noOverTaking.p3d";
	};
	class MAP_sign_oneWay: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_oneWay.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_oneWay.p3d";
	};
	class MAP_sign_speed20: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_speed20.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_speed20.p3d";
	};
	class MAP_sign_speed50: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_speed50.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_speed50.p3d";
	};
	class MAP_sign_stopProhibited: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_stopProhibited.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_stopProhibited.p3d";
	};
	class MAP_sign_stopProhibited_new: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_stopProhibited_new.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_stopProhibited_new.p3d";
	};
	class MAP_sign_tractorProhibited: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_tractorProhibited.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_tractorProhibited.p3d";
	};
	class MAP_sign_wiatingProhibited: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_wiatingProhibited.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_wiatingProhibited.p3d";
	};
	class MAP_sign_wiatingProhibited_new: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_wiatingProhibited_new.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_wiatingProhibited_new.p3d";
	};
	class MAP_sign_blindWay: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_blindWay.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_blindWay.p3d";
	};
	class MAP_sign_blindWay_left: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_blindWay_left.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_blindWay_left.p3d";
	};
	class MAP_sign_blindWay_left_new: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_blindWay_left_new.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_blindWay_left_new.p3d";
	};
	class MAP_sign_blindWay_new: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_blindWay_new.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_blindWay_new.p3d";
	};
	class MAP_sign_blindWay_right: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_blindWay_right.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_blindWay_right.p3d";
	};
	class MAP_sign_blindWay_right_new: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_blindWay_right_new.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_blindWay_right_new.p3d";
	};
	class MAP_sign_heightLimit: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_heightLimit.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_heightLimit.p3d";
	};
	class MAP_sign_widthLimit: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_widthLimit.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_widthLimit.p3d";
	};
	class MAP_sign_prejezd: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_prejezd.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_prejezd.p3d";
	};
	class MAP_sign_prejezd2: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_prejezd2.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_prejezd2.p3d";
	};
	class MAP_sign_prejezd3: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_prejezd3.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_prejezd3.p3d";
	};
	class MAP_sign_krizeni_s_trati: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "T sign_krizeni_s_trati.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_krizeni_s_trati.p3d";
	};
	class MAP_small_flag: MAP_Signs_DBu
	{
		scope = 2;
		displayName = "T small_flag";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\Structures\Misc\Armory\small_flag\small_flag.p3d";
	};
	class MAP_sign_pedCrossing: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "H sign_pedCrossing.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_pedCrossing.p3d";
	};
	class MAP_sign_parking: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "H sign_parking.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_parking.p3d";
	};
	class MAP_sign_parking_new: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "H sign_parking_new.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_parking_new.p3d";
	};
	class MAP_sign_accomodation: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "H sign_accomodation.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_accomodation.p3d";
	};
	class MAP_sign_food: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "H sign_food.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_food.p3d";
	};
	class MAP_sign_fuel: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "H sign_fuel.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_fuel.p3d";
	};
	class MAP_sign_fuel_new: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "H sign_fuel_new.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_fuel_new.p3d";
	};
	class MAP_sign_service: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "H sign_service.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_service.p3d";
	};
	class MAP_sign_service_new: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "H sign_service_new.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_service_new.p3d";
	};
	class MAP_sign_hospital: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "H sign_hospital.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_hospital.p3d";
	};
	class MAP_sign_hospital_new: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "H sign_hospital_new.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_hospital_new.p3d";
	};
	class MAP_sign_snow_new: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "H sign_snow_new.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_snow_new.p3d";
	};
	class MAP_sign_snowChains: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "H sign_snowChains.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_snowChains.p3d";
	};
	class MAP_sign_snowChains_end: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "H sign_snowChains_end.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_snowChains_end.p3d";
	};
	class MAP_sign_port: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "H sign_port.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_port.p3d";
	};
	class MAP_sign_bus: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "H sign_bus.p3d";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\signs2\SignT\sign_bus.p3d";
	};
	class MAP_Zastavka_cedule: MAP_Signs_DBu
	{
		scope = 2;
		displayName = "H Zastavka_cedule";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\Structures\Misc\misc_BusStop\Zastavka_cedule.p3d";
	};
	class MAP_Zastavka_stojan: MAP_Signs_DBu
	{
		scope = 2;
		displayName = "H Zastavka_stojan";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\Structures\Misc\misc_BusStop\Zastavka_stojan.p3d";
	};
	class MAP_nastenka2: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "H nastenka2";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\buildings\misc\nastenka2.p3d";
	};
	class MAP_nastenka3: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "H nastenka3";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\buildings\misc\nastenka3.p3d";
	};
	class MAP_vlajkstozar: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "H vlajkstozar";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\misc\vlajkstozar.p3d";
	};
	class MAP_flag_stozar: MAP_Signs_DBu
	{
		scope = 1;
		displayName = "H flag_stozar";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\flag_stozar.p3d";
	};
	class MAP_Flag_Chernarus: MAP_Signs_DBu
	{
		scope = 1;
		displayName = "H Flag_Chernarus";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings2\BuildingParts\Flag_Chernarus\flag.p3d";
	};
	class MAP_Checkered_flag_holder: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "H Checkered_flag_holder";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\Structures\Misc\Armory\Checkered_flag\Checkered_flag_holder.p3d";
	};
	class MAP_Checkered_flag: MAP_Signs_DBu
	{
		scope = 1;
		displayName = "H Checkered_flag";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\Structures\Misc\Armory\Checkered_flag\Checkered_flag.p3d";
	};
	class MAP_Misc_wall_lamp: MAP_Signs_DBu
	{
		scope = 2;
		displayName = "L Misc_wall_lamp";
		icon = "\MAP_EU\icon\Light.paa";
		model = "\CA\water2\LHD\Misc_wall_lamp.p3d";
	};
	class MAP_NavigLight: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "L NavigLight";
		icon = "\MAP_EU\icon\Light.paa";
		model = "\CA\buildings\misc\NavigLight.p3d";
	};
	class MAP_lampa_ind: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "L lampa_ind";
		icon = "\MAP_EU\icon\Light.paa";
		model = "\CA\buildings\misc\lampa_ind.p3d";
	};
	class MAP_lampa_ind_zebr: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "L lampa_ind_zebr";
		icon = "\MAP_EU\icon\Light.paa";
		model = "\CA\buildings\misc\lampa_ind_zebr.p3d";
	};
	class MAP_lampa_sidl: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "L lampa_sidl";
		icon = "\MAP_EU\icon\Light.paa";
		model = "\CA\buildings\misc\lampa_sidl.p3d";
	};
	class MAP_lampa_sidl_2: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "L lampa_sidl_2";
		icon = "\MAP_EU\icon\Light.paa";
		model = "\CA\buildings\misc\lampa_sidl_2.p3d";
	};
	class MAP_lampa_sidl_3: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "L lampa_sidl_3";
		icon = "\MAP_EU\icon\Light.paa";
		model = "\CA\buildings\misc\lampa_sidl_3.p3d";
	};
	class Land_Stoplight01;
	class MAP_Stoplight01: Land_Stoplight01
	{
		scope = 2;
		displayName = "L Stoplight01";
		icon = "\MAP_EU\icon\Light.paa";
		vehicleClass = "MAP_EUSigns";
		accuracy = 1000;
	};
	class Land_Stoplight02;
	class MAP_Stoplight02: Land_Stoplight02
	{
		scope = 2;
		displayName = "L Stoplight02";
		icon = "\MAP_EU\icon\Light.paa";
		vehicleClass = "MAP_EUSigns";
		accuracy = 1000;
	};
	class MAP_coneLight: MAP_Signs_DBu
	{
		scope = 2;
		displayName = "L coneLight";
		icon = "\MAP_EU\icon\Light.paa";
		model = "\CA\Structures\Misc\Armory\coneLight\coneLight.p3d";
	};
	class MAP_RoadBarrier_light: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "L RoadBarrier_light";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\Data\Library\RoadBarrier_light.p3d";
	};
	class MAP_RoadBarrier_long: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "W RoadBarrier_long";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\Data\Library\RoadBarrier_long.p3d";
	};
	class MAP_sign_board: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "W sign_board";
		icon = "\MAP_EU\icon\SL.paa";
		model = "\CA\misc\sign_board.p3d";
	};
	class MAP_sign_danger1: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "W sign_danger";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\sign_danger.p3d";
	};
	class MAP_sign_danger_mines: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "W sign_danger_mines";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\misc\sign_danger_mines.p3d";
	};
	class MAP_sign_one_leg_h: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "W sign_one_leg_h";
		icon = "\MAP_EU\icon\S.paa";
		model = "\CA\misc\sign_one_leg_h.p3d";
	};
	class MAP_sign_one_leg_v_nodumping: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "W sign_one_leg_v_nodumping";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\sign_one_leg_v_nodumping.p3d";
	};
	class MAP_sign_one_leg_v_quarry: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "W sign_one_leg_v_quarry";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\sign_one_leg_v_quarry.p3d";
	};
	class MAP_sign_wooden_relic_building: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "W sign_wooden_relic_building";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\sign_wooden_relic_building.p3d";
	};
	class MAP_sign_wooden_relic_tree: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "W sign_wooden_relic_tree";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\sign_wooden_relic_tree.p3d";
	};
	class MAP_sign_wooden_relic_zagorie: MAP_Signs_DTr
	{
		scope = 2;
		displayName = "W sign_wooden_relic_zagorie";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\sign_wooden_relic_zagorie.p3d";
	};
	class MAP_Bilboard_alkohol: MAP_Signs_DBu
	{
		scope = 2;
		displayName = "P Bilboard_alkohol";
		icon = "\MAP_EU\icon\BBl.paa";
		model = "\CA\misc\Bilboard_alkohol.p3d";
	};
	class MAP_Bilboard_Beach: MAP_Signs_DBu
	{
		scope = 2;
		displayName = "P Bilboard_Beach";
		icon = "\MAP_EU\icon\BBl.paa";
		model = "\CA\misc\Bilboard_Beach.p3d";
	};
	class MAP_Bilboard_Bienvenudo: MAP_Signs_DBu
	{
		scope = 2;
		displayName = "P Bilboard_Bienvenudo";
		icon = "\MAP_EU\icon\BBl.paa";
		model = "\CA\misc\Bilboard_Bienvenudo.p3d";
	};
	class MAP_Bilboard_cibulka: MAP_Signs_DBu
	{
		scope = 2;
		displayName = "P Bilboard_cibulka";
		icon = "\MAP_EU\icon\BBl.paa";
		model = "\CA\misc\Bilboard_cibulka.p3d";
	};
	class MAP_Bilboard_cigara_chernomorky: MAP_Signs_DBu
	{
		scope = 2;
		displayName = "P Bilboard_cigara_chernomorky";
		icon = "\MAP_EU\icon\BBl.paa";
		model = "\CA\misc\Bilboard_cigara_chernomorky.p3d";
	};
	class MAP_Bilboard_Escape: MAP_Signs_DBu
	{
		scope = 2;
		displayName = "P Bilboard_Escape";
		icon = "\MAP_EU\icon\BBl.paa";
		model = "\CA\misc\Bilboard_Escape.p3d";
	};
	class MAP_Bilboard_Everon: MAP_Signs_DBu
	{
		scope = 2;
		displayName = "P Bilboard_Everon";
		icon = "\MAP_EU\icon\BBl.paa";
		model = "\CA\misc\Bilboard_Everon.p3d";
	};
	class MAP_Bilboard_hlinik: MAP_Signs_DBu
	{
		scope = 2;
		displayName = "P Bilboard_hlinik";
		icon = "\MAP_EU\icon\BBl.paa";
		model = "\CA\misc\Bilboard_hlinik.p3d";
	};
	class MAP_Bilboard_likery_bardak: MAP_Signs_DBu
	{
		scope = 2;
		displayName = "P Bilboard_likery_bardak";
		icon = "\MAP_EU\icon\BBl.paa";
		model = "\CA\misc\Bilboard_likery_bardak.p3d";
	};
	class MAP_Bilboard_Nogova: MAP_Signs_DBu
	{
		scope = 2;
		displayName = "P Bilboard_Nogova";
		icon = "\MAP_EU\icon\BBl.paa";
		model = "\CA\misc\Bilboard_Nogova.p3d";
	};
	class MAP_Bilboard_pizza_presto: MAP_Signs_DBu
	{
		scope = 2;
		displayName = "P Bilboard_pizza_presto";
		icon = "\MAP_EU\icon\BBl.paa";
		model = "\CA\misc\Bilboard_pizza_presto.p3d";
	};
	class MAP_Bilboard_Riviera: MAP_Signs_DBu
	{
		scope = 2;
		displayName = "P Bilboard_Riviera";
		icon = "\MAP_EU\icon\BBl.paa";
		model = "\CA\misc\Bilboard_Riviera.p3d";
	};
	class MAP_Bilboard_seci_stroje: MAP_Signs_DBu
	{
		scope = 2;
		displayName = "P Bilboard_seci_stroje";
		icon = "\MAP_EU\icon\BBl.paa";
		model = "\CA\misc\Bilboard_seci_stroje.p3d";
	};
	class MAP_Bilboard_smadny_maskrnik: MAP_Signs_DBu
	{
		scope = 2;
		displayName = "P Bilboard_smadny_maskrnik";
		icon = "\MAP_EU\icon\BBl.paa";
		model = "\CA\misc\Bilboard_smadny_maskrnik.p3d";
	};
	class MAP_Bilboard_strana_noveho_radu: MAP_Signs_DBu
	{
		scope = 2;
		displayName = "P Bilboard_strana_noveho_radu";
		icon = "\MAP_EU\icon\BBl.paa";
		model = "\CA\misc\Bilboard_strana_noveho_radu.p3d";
	};
	class MAP_Bilboard_toaletak_armasan: MAP_Signs_DBu
	{
		scope = 2;
		displayName = "P Bilboard_toaletak_armasan";
		icon = "\MAP_EU\icon\BBl.paa";
		model = "\CA\misc\Bilboard_toaletak_armasan.p3d";
	};
	class MAP_Bilboard_veterans_choice: MAP_Signs_DBu
	{
		scope = 2;
		displayName = "P Bilboard_veterans_choice";
		icon = "\MAP_EU\icon\BBl.paa";
		model = "\CA\misc\Bilboard_veterans_choice.p3d";
	};
	class MAP_Bilboard_volte_cernaruske_hnuti: MAP_Signs_DBu
	{
		scope = 2;
		displayName = "P Bilboard_volte_cernaruske_hnuti";
		icon = "\MAP_EU\icon\BBl.paa";
		model = "\CA\misc\Bilboard_volte_cernaruske_hnuti.p3d";
	};
	class MAP_Bilboard_vstup_do_CDF: MAP_Signs_DBu
	{
		scope = 2;
		displayName = "P Bilboard_vstup_do_CDF";
		icon = "\MAP_EU\icon\BBl.paa";
		model = "\CA\misc\Bilboard_vstup_do_CDF.p3d";
	};
	class MAP_Bilboard_zlute_zgrynda: MAP_Signs_DBu
	{
		scope = 2;
		displayName = "P Bilboard_zlute_zgrynda";
		icon = "\MAP_EU\icon\BBl.paa";
		model = "\CA\misc\Bilboard_zlute_zgrynda.p3d";
	};
	class MAP_A_CitySignE: MAP_Signs_DBu
	{
		scope = 2;
		displayName = "B A_CitySignE";
		icon = "\MAP_EU\icon\BBu.paa";
		model = "\CA\signs2\A_CitySignE.p3d";
	};
	class Land_Company3_2;
	class MAP_Company3_2: Land_Company3_2
	{
		scope = 2;
		displayName = "B Company3_2";
		icon = "\MAP_EU\icon\BBu.paa";
		vehicleClass = "MAP_EUSigns";
		accuracy = 1000;
	};
	class MAP_EmbeddedTire: MAP_Signs_DBu
	{
		scope = 2;
		displayName = "W EmbeddedTire";
		icon = "\MAP_EU\icon\BBu.paa";
		model = "\CA\signs2\EmbeddedTire.p3d";
	};
	class Land_sign_altar;
	class MAP_sign_altar: Land_sign_altar
	{
		scope = 2;
		displayName = "B sign_altar";
		icon = "\MAP_EU\icon\BBu.paa";
		vehicleClass = "MAP_EUSigns";
		accuracy = 1000;
	};
	class Land_Sign_Bar_RU;
	class MAP_Sign_Bar_RU: Land_Sign_Bar_RU
	{
		scope = 2;
		displayName = "B Sign_Bar_RU";
		icon = "\MAP_EU\icon\BBu.paa";
		vehicleClass = "MAP_EUSigns";
		accuracy = 1000;
	};
	class Land_Sign_BES;
	class MAP_Sign_BES: Land_Sign_BES
	{
		scope = 2;
		displayName = "B Sign_BES";
		icon = "\MAP_EU\icon\BBu.paa";
		vehicleClass = "MAP_EUSigns";
		accuracy = 1000;
	};
	class MAP_Sign_InterHotel: MAP_Signs_DBu
	{
		scope = 2;
		displayName = "B Sign_InterHotel";
		icon = "\MAP_EU\icon\BBu.paa";
		model = "\CA\signs2\Sign_InterHotel.p3d";
	};
	class Land_sign_TEC;
	class MAP_sign_TEC: Land_sign_TEC
	{
		scope = 2;
		displayName = "B sign_TEC";
		icon = "\MAP_EU\icon\BBu.paa";
		vehicleClass = "MAP_EUSigns";
		accuracy = 1000;
	};
	class Land_sign_ulgano;
	class MAP_sign_ulgano: Land_sign_ulgano
	{
		scope = 2;
		displayName = "B sign_ulgano";
		icon = "\MAP_EU\icon\BBu.paa";
		vehicleClass = "MAP_EUSigns";
		accuracy = 1000;
	};
	class Land_SignB_Gov;
	class MAP_SignB_Gov: Land_SignB_Gov
	{
		scope = 2;
		displayName = "B SignB_Gov";
		icon = "\MAP_EU\icon\BBu.paa";
		vehicleClass = "MAP_EUSigns";
		accuracy = 1000;
	};
	class Land_SignB_GovPolice;
	class MAP_SignB_GovPolice: Land_SignB_GovPolice
	{
		scope = 2;
		displayName = "B SignB_GovPolice";
		icon = "\MAP_EU\icon\BBu.paa";
		vehicleClass = "MAP_EUSigns";
		accuracy = 1000;
	};
	class Land_SignB_GovSchool;
	class MAP_SignB_GovSchool: Land_SignB_GovSchool
	{
		scope = 2;
		displayName = "B SignB_GovSchool";
		icon = "\MAP_EU\icon\BBu.paa";
		vehicleClass = "MAP_EUSigns";
		accuracy = 1000;
	};
	class Land_SignB_GovSign;
	class MAP_SignB_GovSign: Land_SignB_GovSign
	{
		scope = 2;
		displayName = "B SignB_GovSign";
		icon = "\MAP_EU\icon\BBu.paa";
		vehicleClass = "MAP_EUSigns";
		accuracy = 1000;
	};
	class Land_SignB_Hotel_CZ;
	class MAP_SignB_Hotel_CZ: Land_SignB_Hotel_CZ
	{
		scope = 2;
		displayName = "B SignB_Hotel_CZ";
		icon = "\MAP_EU\icon\BBu.paa";
		vehicleClass = "MAP_EUSigns";
		accuracy = 1000;
	};
	class Land_SignB_Hotel_CZ2;
	class MAP_SignB_Hotel_CZ2: Land_SignB_Hotel_CZ2
	{
		scope = 2;
		displayName = "B SignB_Hotel_CZ2";
		icon = "\MAP_EU\icon\BBu.paa";
		vehicleClass = "MAP_EUSigns";
		accuracy = 1000;
	};
	class Land_SignB_Hotel_CZ3;
	class MAP_SignB_Hotel_CZ3: Land_SignB_Hotel_CZ3
	{
		scope = 2;
		displayName = "B SignB_Hotel_CZ3";
		icon = "\MAP_EU\icon\BBu.paa";
		vehicleClass = "MAP_EUSigns";
		accuracy = 1000;
	};
	class Land_SignB_Pharmacy;
	class MAP_SignB_Pharmacy: Land_SignB_Pharmacy
	{
		scope = 2;
		displayName = "B SignB_Pharmacy";
		icon = "\MAP_EU\icon\BBu.paa";
		vehicleClass = "MAP_EUSigns";
		accuracy = 1000;
	};
	class Land_SignB_PostOffice;
	class MAP_SignB_PostOffice: Land_SignB_PostOffice
	{
		scope = 2;
		displayName = "B SignB_PostOffice";
		icon = "\MAP_EU\icon\BBu.paa";
		vehicleClass = "MAP_EUSigns";
		accuracy = 1000;
	};
	class Land_SignB_Pub_CZ1;
	class MAP_SignB_Pub_CZ1: Land_SignB_Pub_CZ1
	{
		scope = 2;
		displayName = "B SignB_Pub_CZ1";
		icon = "\MAP_EU\icon\BBu.paa";
		vehicleClass = "MAP_EUSigns";
		accuracy = 1000;
	};
	class Land_SignB_Pub_CZ2;
	class MAP_SignB_Pub_CZ2: Land_SignB_Pub_CZ2
	{
		scope = 2;
		displayName = "B SignB_Pub_CZ2";
		icon = "\MAP_EU\icon\BBu.paa";
		vehicleClass = "MAP_EUSigns";
		accuracy = 1000;
	};
	class Land_SignB_Pub_CZ3;
	class MAP_SignB_Pub_CZ3: Land_SignB_Pub_CZ3
	{
		scope = 2;
		displayName = "B SignB_Pub_CZ3";
		icon = "\MAP_EU\icon\BBu.paa";
		vehicleClass = "MAP_EUSigns";
		accuracy = 1000;
	};
	class Land_SignB_Pub_RU1;
	class MAP_SignB_Pub_RU1: Land_SignB_Pub_RU1
	{
		scope = 2;
		displayName = "B SignB_Pub_RU1";
		icon = "\MAP_EU\icon\BBu.paa";
		vehicleClass = "MAP_EUSigns";
		accuracy = 1000;
	};
	class Land_SignB_Pub_RU2;
	class MAP_SignB_Pub_RU2: Land_SignB_Pub_RU2
	{
		scope = 2;
		displayName = "B SignB_Pub_RU2";
		icon = "\MAP_EU\icon\BBu.paa";
		vehicleClass = "MAP_EUSigns";
		accuracy = 1000;
	};
	class Land_SignB_Pub_RU3;
	class MAP_SignB_Pub_RU3: Land_SignB_Pub_RU3
	{
		scope = 2;
		displayName = "B SignB_Pub_RU3";
		icon = "\MAP_EU\icon\BBu.paa";
		vehicleClass = "MAP_EUSigns";
		accuracy = 1000;
	};
	class MAP_BuildingSign_plate: MAP_Signs_DBu
	{
		scope = 2;
		displayName = "B BuildingSign_plate";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_BuildingParts\Signs\Sign_plate.p3d";
	};
	class MAP_PoliclinicCross: MAP_Signs_DBu
	{
		scope = 2;
		displayName = "B PoliclinicCross";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_BuildingParts\Signs\Policlinic\Cross.p3d";
	};
	class MAP_PoliclinicSign: MAP_Signs_DBu
	{
		scope = 2;
		displayName = "B PoliclinicSign";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Proxy_BuildingParts\Signs\Policlinic\Sign.p3d";
	};
	class MAP_A_CitySign: MAP_Signs_DBu
	{
		scope = 2;
		displayName = "B A_CitySign";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings2\A_CitySign\A_CitySign.p3d";
	};
	class MAP_Signtec: MAP_Signs_DBu
	{
		scope = 2;
		displayName = "B Signtec";
		icon = "\MAP_EU\icon\BBu.paa";
		model = "\CA\buildings2\BuildingParts\Signs\TEC\tec.p3d";
	};
	class MAP_Inter_Base: Static
	{
		displayName = "";
		accuracy = 0.1;
		vehicleClass = "MAP_EUInter";
		model = "";
		nameSound = "";
		animated = 0;
		simulation = "house";
		cost = 0;
		armor = 1000;
		ladders[] = {};
		placement = "vertical";
	};
	class MAP_Inter_DNo: MAP_Inter_Base
	{
		destrType = "DestructNo";
		accuracy = 1000;
	};
	class MAP_Inter_DTe: MAP_Inter_Base
	{
		destrType = "DestructTent";
		accuracy = 1000;
	};
	class MAP_Inter_DTr: MAP_Inter_Base
	{
		destrType = "DestructTree";
		accuracy = 1000;
	};
	class MAP_Inter_DBu: MAP_Inter_Base
	{
		destrType = "DestructBuilding";
		accuracy = 1000;
		class DestructionEffects
		{
			class HouseDestr
			{
				simulation = "destroy";
				type = "DelayedDestruction";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class MAP_chair: MAP_Inter_DTe
	{
		scope = 2;
		displayName = "S chair";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\misc2\Table\chair.p3d";
	};
	class MAP_chair_2: MAP_Inter_DTe
	{
		scope = 2;
		displayName = "S chair_2";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\misc2\Table\chair_2.p3d";
	};
	class MAP_ch_mod_c: MAP_Inter_DTe
	{
		scope = 2;
		displayName = "S ch_mod_c";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Chairs\ch_mod_c\ch_mod_c.p3d";
	};
	class MAP_kitchen_chair_a: MAP_Inter_DTe
	{
		scope = 2;
		displayName = "S kitchen_chair_a";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Chairs\kitchen_chair_a\kitchen_chair_a.p3d";
	};
	class MAP_office_chair: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "S office_chair";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Chairs\office_chair\office_chair.p3d";
	};
	class MAP_ch_mod_h: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "S ch_mod_h";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Chairs\ch_mod_h\ch_mod_h.p3d";
	};
	class MAP_ch_office_B: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "S ch_office_B";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Chairs\ch_office_B\ch_office_B.p3d";
	};
	class MAP_lobby_chair: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "S lobby_chair";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Chairs\lobby_chair\lobby_chair.p3d";
	};
	class MAP_armchair: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "S armchair";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\buildings\furniture\armchair.p3d";
	};
	class MAP_Church_chair: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "S Church_chair";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Chairs\Church_chair\Church_chair.p3d";
	};
	class MAP_hospital_bench: MAP_Inter_DTe
	{
		scope = 2;
		displayName = "S hospital_bench";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Chairs\hospital_bench\hospital_bench.p3d";
	};
	class MAP_F_ch_mod_c: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "S ch_mod_c";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\furniture\ch_mod_c.p3d";
	};
	class MAP_lavicka_1: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "S lavicka_1";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\lavicka_1.p3d";
	};
	class MAP_lavicka_2: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "S lavicka_2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\lavicka_2.p3d";
	};
	class MAP_lavicka_3: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "S lavicka_3";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\lavicka_3.p3d";
	};
	class MAP_lavicka_4: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "S lavicka_4";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\buildings\misc\lavicka_4.p3d";
	};
	class MAP_stul_hospoda: MAP_Inter_DTe
	{
		scope = 2;
		displayName = "T stul_hospoda";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\buildings\furniture\stul_hospoda.p3d";
	};
	class MAP_kitchen_table_a: MAP_Inter_DTe
	{
		scope = 2;
		displayName = "T kitchen_table_a";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Tables\kitchen_table_a\kitchen_table_a.p3d";
	};
	class MAP_stul_kuch1: MAP_Inter_DTe
	{
		scope = 2;
		displayName = "T stul_kuch1";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Tables\stul_kuch1\stul_kuch1.p3d";
	};
	class MAP_SmallTable: MAP_Inter_DTe
	{
		scope = 2;
		displayName = "T SmallTable";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\misc2\SmallTable\SmallTable.p3d";
	};
	class MAP_Table: MAP_Inter_DTe
	{
		scope = 2;
		displayName = "T Table";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\misc2\Table\Table.p3d";
	};
	class MAP_lobby_table: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "T lobby_table";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Tables\lobby_table\lobby_table.p3d";
	};
	class MAP_table_drawer: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "T table_drawer";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Tables\table_drawer\table_drawer.p3d";
	};
	class MAP_office_table_a: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "T office_table_a";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Tables\office_table_a\office_table_a.p3d";
	};
	class MAP_F_conference_table_a: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "T F_conference_table_a";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\buildings\furniture\conference_table_a.p3d";
	};
	class MAP_conference_table_a: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "T conference_table_a";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Tables\conference_table_a\conference_table_a.p3d";
	};
	class MAP_Dhangar_psacistul: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "T Dhangar_psacistul";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\buildings\furniture\Dhangar_psacistul.p3d";
	};
	class MAP_desk: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "T desk";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\misc2\desk\desk.p3d";
	};
	class MAP_lobby_counter: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "T lobby_counter";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Tables\lobby_counter\lobby_counter.p3d";
	};
	class MAP_pultskasou: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "T pultskasou";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\generalstore\pultskasou.p3d";
	};
	class MAP_almara: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "C almara";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Cases\almara\almara.p3d";
	};
	class MAP_case_a: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "C case_a";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Cases\case_a\case_a.p3d";
	};
	class MAP_case_bedroom_a: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "C case_bedroom_a";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Cases\case_bedroom_a\case_bedroom_a.p3d";
	};
	class MAP_case_cans_b: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "C case_cans_b";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Cases\case_cans_b\case_cans_b.p3d";
	};
	class MAP_case_d: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "C case_d";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Cases\case_d\case_d.p3d";
	};
	class MAP_Dhangar_borwnskrin: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "C Dhangar_borwnskrin";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Cases\Dhangar_borwnskrin\Dhangar_brownskrin.p3d";
	};
	class MAP_library_a: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "C library_a";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Cases\library_a\library_a.p3d";
	};
	class MAP_Skrin_bar: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "C Skrin_bar";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Cases\Skrin_bar\Skrin_bar.p3d";
	};
	class MAP_case_bedroom_b: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "C case_bedroom_b";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\buildings\furniture\case_bedroom_b.p3d";
	};
	class MAP_case_wall_unit_part_c: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "C case_wall_unit_part_c";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\buildings\furniture\case_wall_unit_part_c.p3d";
	};
	class MAP_case_wall_unit_part_d: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "C case_wall_unit_part_d";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\buildings\furniture\case_wall_unit_part_d.p3d";
	};
	class MAP_case_wooden_b: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "C case_wooden_b";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\buildings\furniture\case_wooden_b.p3d";
	};
	class MAP_Dhangar_brownskrin: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "C Dhangar_brownskrin";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\buildings\furniture\Dhangar_brownskrin.p3d";
	};
	class MAP_Dhangar_knihovna: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "C Dhangar_knihovna";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\buildings\furniture\Dhangar_knihovna.p3d";
	};
	class MAP_Dhangar_whiteskrin: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "C Dhangar_whiteskrin";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\buildings\furniture\Dhangar_whiteskrin.p3d";
	};
	class MAP_F_skrin_bar: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "C skrin_bar";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\buildings\furniture\skrin_bar.p3d";
	};
	class MAP_Skrin_opalena: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "C Skrin_opalena";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\buildings\furniture\Skrin_opalena.p3d";
	};
	class MAP_Truhla_stara: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "C Truhla_stara";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\buildings\furniture\Truhla_stara.p3d";
	};
	class MAP_shelf: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "C shelf";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\generalstore\shelf.p3d";
	};
	class MAP_postel_manz_kov: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "B postel_manz_kov";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Chairs\postel_manz_kov\postel_manz_kov.p3d";
	};
	class MAP_F_postel_manz_kov: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "B F_postel_manz_kov";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\buildings\furniture\postel_manz_kov.p3d";
	};
	class MAP_postel_panelak1: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "B postel_panelak1";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Chairs\postel_panelak1\postel_panelak1.p3d";
	};
	class MAP_F_postel_panelak1: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "B F_postel_panelak1";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\buildings\furniture\postel_panelak1.p3d";
	};
	class MAP_F_postel_panelak2: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "B F_postel_panelak2";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\buildings\furniture\postel_panelak2.p3d";
	};
	class MAP_vojenska_palanda: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "B vojenska_palanda";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Chairs\vojenska_palanda\vojenska_palanda.p3d";
	};
	class MAP_F_Vojenska_palanda: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "B F_Vojenska_palanda";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\buildings\furniture\Vojenska_palanda.p3d";
	};
	class MAP_bed_husbands: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "B bed_husbands";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\buildings\furniture\bed_husbands.p3d";
	};
	class MAP_P_sink: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "M sink";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Bathroom\sink\sink.p3d";
	};
	class MAP_P_Basin_A: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "M Basin_A";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Bathroom\Basin_A\Basin_A.p3d";
	};
	class MAP_P_bath: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "M bath";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Bathroom\bath\bath.p3d";
	};
	class MAP_F_bath: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "M F_bath";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\buildings\furniture\bath.p3d";
	};
	class MAP_toilet_b: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "M toilet_b";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\buildings\furniture\toilet_b.p3d";
	};
	class MAP_P_toilet_b_02: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "M toilet_b_02";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Bathroom\toilet_b_02\toilet_b_02.p3d";
	};
	class MAP_lekarnicka: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "M lekarnicka";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Decoration\lekarnicka\lekarnicka.p3d";
	};
	class MAP_radio: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "E radio";
		icon = "\MAP_EU\icon\IED.paa";
		model = "\CA\misc\radio.p3d";
	};
	class MAP_radio_b: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "E radio_b";
		icon = "\MAP_EU\icon\IED.paa";
		model = "\CA\Structures\Furniture\Eletrical_appliances\radio_b\radio_b.p3d";
	};
	class MAP_mutt_vysilacka: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "E mutt_vysilacka";
		icon = "\MAP_EU\icon\IED.paa";
		model = "\CA\misc\mutt_vysilacka.p3d";
	};
	class MAP_smallTV: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "E smallTV";
		icon = "\MAP_EU\icon\IED.paa";
		model = "\CA\misc2\smallTV\smallTV.p3d";
	};
	class MAP_tv_a: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "E tv_a";
		icon = "\MAP_EU\icon\IED.paa";
		model = "\CA\Structures\Furniture\Eletrical_appliances\tv_a\tv_a.p3d";
	};
	class MAP_satelitePhone: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "E satelitePhone";
		icon = "\MAP_EU\icon\IED.paa";
		model = "\CA\misc3\satelitePhone\satellitePhone.p3d";
	};
	class MAP_phonebox: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "E phonebox";
		icon = "\MAP_EU\icon\IED.paa";
		model = "\CA\Structures\Furniture\Eletrical_appliances\phonebox\phonebox.p3d";
	};
	class MAP_notebook: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "E notebook";
		icon = "\MAP_EU\icon\IED.paa";
		model = "\CA\misc2\notebook\notebook.p3d";
	};
	class MAP_pc: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "E pc";
		icon = "\MAP_EU\icon\IED.paa";
		model = "\CA\Structures\Furniture\Eletrical_appliances\pc\pc.p3d";
	};
	class MAP_misc_videoprojector: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "E misc_videoprojector";
		icon = "\MAP_EU\icon\IED.paa";
		model = "\CA\misc\misc_videoprojector.p3d";
	};
	class MAP_misc_videoprojector_platno: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "E misc_videoprojector_platno";
		icon = "\MAP_EU\icon\IED.paa";
		model = "\CA\misc\misc_videoprojector_platno.p3d";
	};
	class MAP_fridge: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "E fridge";
		icon = "\MAP_EU\icon\IED.paa";
		model = "\CA\Structures\Furniture\kitchen\fridge\fridge.p3d";
	};
	class MAP_icebox: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "E icebox";
		icon = "\MAP_EU\icon\IED.paa";
		model = "\CA\Structures\Furniture\generalstore\icebox.p3d";
	};
	class MAP_vending_machine: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "E vending_machine";
		icon = "\MAP_EU\icon\IED.paa";
		model = "\CA\Structures\Furniture\Eletrical_appliances\vending_machine\vending_machine.p3d";
	};
	class MAP_washing_machine: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "E washing_machine";
		icon = "\MAP_EU\icon\IED.paa";
		model = "\CA\Structures\Furniture\Eletrical_appliances\washing_machine\washing_machine.p3d";
	};
	class MAP_Kitchenstove_Elec: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "E Kitchenstove_Elec";
		icon = "\MAP_EU\icon\IED.paa";
		model = "\CA\Structures\Furniture\kitchen\Kitchenstove_Elec\Kitchenstove_Elec.p3d";
	};
	class MAP_Dkamna_uhli: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "E Dkamna_uhli";
		icon = "\MAP_EU\icon\IED.paa";
		model = "\CA\Structures\Furniture\kitchen\Dkamna_uhli\Dkamna_uhli.p3d";
	};
	class MAP_F_Dkamna_uhli: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "E F_Dkamna_uhli";
		icon = "\MAP_EU\icon\IED.paa";
		model = "\CA\buildings\furniture\Dkamna_uhli.p3d";
	};
	class MAP_Dkamna_bila: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "E Dkamna_bila";
		icon = "\MAP_EU\icon\IED.paa";
		model = "\CA\buildings\furniture\Dkamna_bila.p3d";
	};
	class MAP_fluor_lamp: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "L fluor_lamp";
		icon = "\MAP_EU\icon\Light.paa";
		model = "\CA\Structures\Furniture\Lighting\fluor_lamp\fluor_lamp.p3d";
	};
	class MAP_lantern: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "L lantern";
		icon = "\MAP_EU\icon\Light.paa";
		model = "\CA\Structures\Furniture\Lighting\lantern\lantern.p3d";
	};
	class MAP_Light_BathRoom: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "L Light_BathRoom";
		icon = "\MAP_EU\icon\Light.paa";
		model = "\CA\Structures\Furniture\Lighting\Light_BathRoom\Light_BathRoom.p3d";
	};
	class MAP_light_kitchen_03: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "L light_kitchen_03";
		icon = "\MAP_EU\icon\Light.paa";
		model = "\CA\Structures\Furniture\Lighting\light_kitchen_03\light_kitchen_03.p3d";
	};
	class MAP_SmallObj_dog_tags: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "O SmallObj_dog_tags";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\SmallObj_dog_tags.p3d";
	};
	class MAP_SmallObj_dog_tags_WPN: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "O SmallObj_dog_tags_WPN";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\SmallObj_dog_tags_WPN";
	};
	class MAP_SmallObj_file_map: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "O SmallObj_file_map";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\SmallObj_file_map.p3d";
	};
	class MAP_SmallObj_file_map_WPN: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "O SmallObj_file_map_WPN";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\SmallObj_file_map_WPN.p3d";
	};
	class MAP_SmallObj_File_photos: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "O SmallObj_File_photos";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\SmallObj_File_photos.p3d";
	};
	class MAP_SmallObj_File_photos_WPN: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "O SmallObj_File_photos_WPN";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\SmallObj_File_photos_WPN.p3d";
	};
	class MAP_SmallObj_money: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "O SmallObj_money";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\SmallObj_money.p3d";
	};
	class MAP_SmallObj_money_WPN: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "O SmallObj_money_WPN";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\SmallObj_money_WPN.p3d";
	};
	class MAP_SmallObj_moscow_docs: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "O SmallObj_moscow_docs";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\SmallObj_moscow_docs.p3d";
	};
	class MAP_SmallObj_moscow_docs_WPN: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "O SmallObj_moscow_docs_WPN";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\SmallObj_moscow_docs_WPN.p3d";
	};
	class MAP_SmallObj_spukayev_docs: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "O SmallObj_spukayev_docs";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\SmallObj_spukayev_docs.p3d";
	};
	class MAP_SmallObj_spukayev_docs_WPN: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "O SmallObj_spukayev_docs_WPN";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\SmallObj_spukayev_docs_WPN.p3d";
	};
	class MAP_explosive: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "O explosive";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc2\explosive\explosive.p3d";
	};
	class MAP_plechovka_1: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "O plechovka_1";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\plechovka_1.p3d";
	};
	class MAP_floormop: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "O floormop";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc2\floormop\floormop.p3d";
	};
	class MAP_bucket: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "O bucket";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\Furniture\Decoration\bucket\bucket.p3d";
	};
	class MAP_MetalBucket: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "O MetalBucket";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc2\MetalBucket\MetalBucket.p3d";
	};
	class MAP_FuelCan: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "O FuelCan";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc\FuelCan.p3d";
	};
	class MAP_briefcase: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "W briefcase";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\briefcase.p3d";
	};
	class MAP_Baseball: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "B Baseball";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc2\Baseball\Baseball.p3d";
	};
	class MAP_wall_board: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "P wall_board";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Decoration\Wallboards\wall_board\wall_board.p3d";
	};
	class MAP_wall_board_02: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "P wall_board_02";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Decoration\Wallboards\wall_board_02\wall_board_02.p3d";
	};
	class MAP_wall_board_03: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "P wall_board_03";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Decoration\Wallboards\wall_board_03\wall_board_03.p3d";
	};
	class MAP_picture_a: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "P picture_a";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Decoration\Wallboards\picture_a\picture_a.p3d";
	};
	class MAP_picture_a_02: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "P picture_a_02";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Decoration\Wallboards\picture_a_02\picture_a_02.p3d";
	};
	class MAP_picture_a_03: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "P picture_a_03";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Decoration\Wallboards\picture_a_03\picture_a_03.p3d";
	};
	class MAP_picture_a_04: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "P picture_a_04";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Decoration\Wallboards\picture_a_04\picture_a_04.p3d";
	};
	class MAP_picture_a_05: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "P picture_a_05";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Decoration\Wallboards\picture_a_05\picture_a_05.p3d";
	};
	class MAP_picture_b: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "P picture_b";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Decoration\Wallboards\picture_b\picture_b.p3d";
	};
	class MAP_picture_b_02: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "P picture_b_02";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Decoration\Wallboards\picture_b_02\picture_b_02.p3d";
	};
	class MAP_picture_c: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "P picture_c";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Decoration\Wallboards\picture_c\picture_c.p3d";
	};
	class MAP_picture_c_02: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "P picture_c_02";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Decoration\Wallboards\picture_c_02\picture_c_02.p3d";
	};
	class MAP_picture_d: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "P picture_d";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Decoration\Wallboards\picture_d\picture_d.p3d";
	};
	class MAP_picture_e: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "P picture_e";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Decoration\Wallboards\picture_e\picture_e.p3d";
	};
	class MAP_picture_f: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "P picture_f";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Decoration\Wallboards\picture_f\picture_f.p3d";
	};
	class MAP_picture_f_02: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "P picture_f_02";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Decoration\Wallboards\picture_f_02\picture_f_02.p3d";
	};
	class MAP_picture_g: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "P picture_g";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\Structures\Furniture\Decoration\Wallboards\picture_g\picture_g.p3d";
	};
	class MAP_obraz_kancl4: MAP_Inter_DBu
	{
		scope = 2;
		displayName = "P obraz_kancl4";
		icon = "\MAP_EU\icon\IF.paa";
		model = "\CA\buildings\furniture\obraz_kancl4.p3d";
	};
	class MAP_Water_Base: Static
	{
		displayName = "";
		accuracy = 0.1;
		vehicleClass = "MAP_EUWater";
		model = "";
		nameSound = "";
		animated = 0;
		simulation = "house";
		cost = 0;
		armor = 1000;
		ladders[] = {};
		placement = "vertical";
	};
	class MAP_Water_DNo: MAP_Water_Base
	{
		destrType = "DestructNo";
		accuracy = 1000;
	};
	class MAP_Water_DTe: MAP_Water_Base
	{
		destrType = "DestructTent";
		accuracy = 1000;
	};
	class MAP_Water_DTr: MAP_Water_Base
	{
		destrType = "DestructTree";
		accuracy = 1000;
	};
	class MAP_Water_DBu: MAP_Water_Base
	{
		destrType = "DestructBuilding";
		accuracy = 1000;
		class DestructionEffects
		{
			class HouseDestr
			{
				simulation = "destroy";
				type = "DelayedDestruction";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class MAP_buoy: MAP_Water_DBu
	{
		scope = 2;
		displayName = "B buoy";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\Data\Library\buoy.p3d";
	};
	class MAP_buoy_small: MAP_Water_DBu
	{
		scope = 2;
		displayName = "B buoy_small";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\ca\Data\Library\buoy_small.p3d";
	};
	class MAP_BoatSmall_1: MAP_Water_DBu
	{
		scope = 2;
		displayName = "B BoatSmall_1";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\BoatSmall_1.p3d";
	};
	class MAP_BoatSmall_2A: MAP_Water_DBu
	{
		scope = 2;
		displayName = "B BoatSmall_2A";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\BoatSmall_2A.p3d";
	};
	class MAP_BoatSmall_2B: MAP_Water_DBu
	{
		scope = 2;
		displayName = "B BoatSmall_2B";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\misc3\BoatSmall_2B.p3d";
	};
	class Land_NAV_Lighthouse;
	class MAP_NAV_Lighthouse: Land_NAV_Lighthouse
	{
		scope = 2;
		displayName = "H NAV_Lighthouse";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class Land_NAV_Lighthouse2;
	class MAP_NAV_Lighthouse2: Land_NAV_Lighthouse2
	{
		scope = 2;
		displayName = "H NAV_Lighthouse2";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class Land_majak;
	class MAP_majak: Land_majak
	{
		scope = 2;
		displayName = "H majak";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class Land_majak_podesta;
	class MAP_majak_podesta: Land_majak_podesta
	{
		scope = 2;
		displayName = "H majak_podesta";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class Land_majak2;
	class MAP_majak2: Land_majak2
	{
		scope = 2;
		displayName = "H majak2";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class Land_Nav_Boathouse;
	class MAP_Nav_Boathouse: Land_Nav_Boathouse
	{
		scope = 2;
		displayName = "H Nav_Boathouse";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class Land_Nav_Boathouse_Pier;
	class MAP_Nav_Boathouse_Pier: Land_Nav_Boathouse_Pier
	{
		scope = 2;
		displayName = "P Nav_Boathouse_Pier";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class Land_Nav_Boathouse_PierL;
	class MAP_Nav_Boathouse_PierL: Land_Nav_Boathouse_PierL
	{
		scope = 2;
		displayName = "P Nav_Boathouse_PierL";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class Land_Nav_Boathouse_PierR;
	class MAP_Nav_Boathouse_PierR: Land_Nav_Boathouse_PierR
	{
		scope = 2;
		displayName = "P Nav_Boathouse_PierR";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class Land_Nav_Boathouse_PierT;
	class MAP_Nav_Boathouse_PierT: Land_Nav_Boathouse_PierT
	{
		scope = 2;
		displayName = "P Nav_Boathouse_PierT";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class Land_molo_drevo_bs;
	class MAP_molo_drevo_bs: Land_molo_drevo_bs
	{
		scope = 2;
		displayName = "P molo_drevo_bs";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class Land_molo_drevo_end;
	class MAP_molo_drevo_end: Land_molo_drevo_end
	{
		scope = 2;
		displayName = "P molo_drevo_end";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class land_nav_pier_c;
	class MAP_nav_pier_c: land_nav_pier_c
	{
		scope = 2;
		displayName = "P nav_pier_c";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class land_nav_pier_c_270;
	class MAP_nav_pier_c_270: land_nav_pier_c_270
	{
		scope = 2;
		displayName = "P nav_pier_c_270";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class land_nav_pier_c_90;
	class MAP_nav_pier_c_90: land_nav_pier_c_90
	{
		scope = 2;
		displayName = "P nav_pier_c_90";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class land_nav_pier_c_big;
	class MAP_nav_pier_c_big: land_nav_pier_c_big
	{
		scope = 2;
		displayName = "P nav_pier_c_big";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class land_nav_pier_C_L;
	class MAP_nav_pier_C_L: land_nav_pier_C_L
	{
		scope = 2;
		displayName = "P nav_pier_C_L";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class land_nav_pier_C_L10;
	class MAP_nav_pier_C_L10: land_nav_pier_C_L10
	{
		scope = 2;
		displayName = "P nav_pier_C_L10";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class land_nav_pier_C_L30;
	class MAP_nav_pier_C_L30: land_nav_pier_C_L30
	{
		scope = 2;
		displayName = "P nav_pier_C_L30";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class land_nav_pier_C_R;
	class MAP_nav_pier_C_R: land_nav_pier_C_R
	{
		scope = 2;
		displayName = "P nav_pier_C_R";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class land_nav_pier_C_R10;
	class MAP_nav_pier_C_R10: land_nav_pier_C_R10
	{
		scope = 2;
		displayName = "P nav_pier_C_R10";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class land_nav_pier_C_R30;
	class MAP_nav_pier_C_R30: land_nav_pier_C_R30
	{
		scope = 2;
		displayName = "P nav_pier_C_R30";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class land_nav_pier_c_t15;
	class MAP_nav_pier_c_t15: land_nav_pier_c_t15
	{
		scope = 2;
		displayName = "P nav_pier_c_t15";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class land_nav_pier_c_t20;
	class MAP_nav_pier_c_t20: land_nav_pier_c_t20
	{
		scope = 2;
		displayName = "P nav_pier_c_t20";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class land_nav_pier_c2;
	class MAP_nav_pier_c2: land_nav_pier_c2
	{
		scope = 2;
		displayName = "P nav_pier_c2";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class land_nav_pier_c2_end;
	class MAP_nav_pier_c2_end: land_nav_pier_c2_end
	{
		scope = 2;
		displayName = "P nav_pier_c2_end";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class land_nav_pier_F_17;
	class MAP_nav_pier_F_17: land_nav_pier_F_17
	{
		scope = 2;
		displayName = "P nav_pier_F_17";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class land_nav_pier_F_23;
	class MAP_nav_pier_F_23: land_nav_pier_F_23
	{
		scope = 2;
		displayName = "P nav_pier_F_23";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class land_nav_pier_m;
	class MAP_nav_pier_m: land_nav_pier_m
	{
		scope = 2;
		displayName = "P nav_pier_m";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class land_nav_pier_m_1;
	class MAP_nav_pier_m_1: land_nav_pier_m_1
	{
		scope = 2;
		displayName = "P nav_pier_m_1";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class Land_nav_pier_m_2;
	class MAP_nav_pier_m_2: Land_nav_pier_m_2
	{
		scope = 2;
		displayName = "P nav_pier_m_2";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class land_nav_pier_m_end;
	class MAP_nav_pier_m_end: land_nav_pier_m_end
	{
		scope = 2;
		displayName = "P nav_pier_m_end";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class land_nav_pier_M_fuel;
	class MAP_nav_pier_M_fuel: land_nav_pier_M_fuel
	{
		scope = 2;
		displayName = "P nav_pier_M_fuel";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class land_nav_pier_pneu;
	class MAP_nav_pier_pneu: land_nav_pier_pneu
	{
		scope = 2;
		displayName = "P nav_pier_pneu";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class land_nav_pier_uvaz;
	class MAP_nav_pier_uvaz: land_nav_pier_uvaz
	{
		scope = 2;
		displayName = "P nav_pier_uvaz";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class Land_molo_beton;
	class MAP_molo_beton: Land_molo_beton
	{
		scope = 2;
		displayName = "P molo_beton";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class Land_molo_krychle;
	class MAP_molo_krychle: Land_molo_krychle
	{
		scope = 2;
		displayName = "P molo_krychle";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class MAP_nav_wave_breaker: MAP_Water_DNo
	{
		scope = 2;
		displayName = "O nav_wave_breaker";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\nav_pier\nav_wave_breaker.p3d";
	};
	class MAP_p_wave_breaker_1: MAP_Water_DNo
	{
		scope = 2;
		displayName = "O p_wave_breaker_1";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\nav_pier\proxy\wave_breaker_1.p3d";
	};
	class MAP_p_wave_breaker_2: MAP_Water_DNo
	{
		scope = 2;
		displayName = "O p_wave_breaker_2";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\nav_pier\proxy\wave_breaker_2.p3d";
	};
	class MAP_p_wave_breaker_3: MAP_Water_DNo
	{
		scope = 2;
		displayName = "O p_wave_breaker_3";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\nav_pier\proxy\wave_breaker_3.p3d";
	};
	class MAP_pond_small_01: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_small_01";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_small_01.p3d";
	};
	class MAP_pond_small_02: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_small_02";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_small_02.p3d";
	};
	class MAP_pond_small_03: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_small_03";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_small_03.p3d";
	};
	class MAP_pond_small_04: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_small_04";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_small_04.p3d";
	};
	class MAP_pond_small_05: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_small_05";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_small_05.p3d";
	};
	class MAP_pond_small_06: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_small_06";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_small_06.p3d";
	};
	class MAP_pond_small_07: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_small_07";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_small_07.p3d";
	};
	class MAP_pond_small_08: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_small_08";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_small_08.p3d";
	};
	class MAP_pond_small_09: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_small_09";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_small_09.p3d";
	};
	class MAP_pond_small_10: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_small_10";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_small_10.p3d";
	};
	class MAP_pond_small_11: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_small_11";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_small_11.p3d";
	};
	class MAP_pond_small_12: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_small_12";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_small_12.p3d";
	};
	class MAP_pond_small_13: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_small_13";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_small_13.p3d";
	};
	class MAP_pond_small_14: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_small_14";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_small_14.p3d";
	};
	class MAP_pond_small_15: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_small_15";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_small_15.p3d";
	};
	class MAP_pond_small_16: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_small_16";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_small_16.p3d";
	};
	class MAP_pond_small_17: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_small_17";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_small_17.p3d";
	};
	class MAP_pond_small_18: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_small_18";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_small_18.p3d";
	};
	class MAP_pond_small_19: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_small_19";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_small_19.p3d";
	};
	class MAP_pond_small_20: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_small_20";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_small_20.p3d";
	};
	class MAP_pond_small_21: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_small_21";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_small_21.p3d";
	};
	class MAP_pond_small_22: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_small_22";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_small_22.p3d";
	};
	class MAP_pond_small_23: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_small_23";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_small_23.p3d";
	};
	class MAP_pond_small_24: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_small_24";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_small_24.p3d";
	};
	class MAP_pond_small_25: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_small_25";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_small_25.p3d";
	};
	class MAP_pond_small_26: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_small_26";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_small_26.p3d";
	};
	class MAP_pond_small_27: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_small_27";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_small_27.p3d";
	};
	class MAP_pond_big_01: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_01";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_01.p3d";
	};
	class MAP_pond_big_02: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_02";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_02.p3d";
	};
	class MAP_pond_big_28_01: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_28_01";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_28_01.p3d";
	};
	class MAP_pond_big_28_02: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_28_02";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_28_02.p3d";
	};
	class MAP_pond_big_28_03: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_28_03";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_28_03.p3d";
	};
	class MAP_pond_big_28_04: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_28_04";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_28_04.p3d";
	};
	class MAP_pond_big_29_01: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_29_01";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_29_01.p3d";
	};
	class MAP_pond_big_29_02: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_29_02";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_29_02.p3d";
	};
	class MAP_pond_big_29_03: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_29_03";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_29_03.p3d";
	};
	class MAP_pond_big_29_04: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_29_04";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_29_04.p3d";
	};
	class MAP_pond_big_30_01: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_30_01";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_30_01.p3d";
	};
	class MAP_pond_big_30_02: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_30_02";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_30_02.p3d";
	};
	class MAP_pond_big_30_03: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_30_03";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_30_03.p3d";
	};
	class MAP_pond_big_30_04: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_30_04";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_30_04.p3d";
	};
	class MAP_pond_big_31_01: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_31_01";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_31_01.p3d";
	};
	class MAP_pond_big_31_02: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_31_02";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_31_02.p3d";
	};
	class MAP_pond_big_31_03: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_31_03";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_31_03.p3d";
	};
	class MAP_pond_big_31_04: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_31_04";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_31_04.p3d";
	};
	class MAP_pond_big_32_01: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_32_01";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_32_01.p3d";
	};
	class MAP_pond_big_32_02: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_32_02";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_32_02.p3d";
	};
	class MAP_pond_big_32_03: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_32_03";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_32_03.p3d";
	};
	class MAP_pond_big_33_01: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_33_01";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_33_01.p3d";
	};
	class MAP_pond_big_33_02: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_33_02";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_33_02.p3d";
	};
	class MAP_pond_big_33_03: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_33_03";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_33_03.p3d";
	};
	class MAP_pond_big_34_01: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_34_01";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_34_01.p3d";
	};
	class MAP_pond_big_34_02: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_34_02";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_34_02.p3d";
	};
	class MAP_pond_big_34_03: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_34_03";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_34_03.p3d";
	};
	class MAP_pond_big_34_04: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_34_04";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_34_04.p3d";
	};
	class MAP_pond_big_35_01: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_35_01";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_35_01.p3d";
	};
	class MAP_pond_big_35_02: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_35_02";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_35_02.p3d";
	};
	class MAP_pond_big_36_01: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_36_01";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_35_01.p3d";
	};
	class MAP_pond_big_36_02: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_36_02";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_36_02.p3d";
	};
	class MAP_pond_big_36_03: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_36_03";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_36_03.p3d";
	};
	class MAP_pond_big_36_04: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_36_04";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_36_04.p3d";
	};
	class MAP_pond_big_37_01: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_37_01";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_37_01.p3d";
	};
	class MAP_pond_big_37_02: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_37_02";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_37_02.p3d";
	};
	class MAP_pond_big_37_03: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_37_03";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_37_03.p3d";
	};
	class MAP_pond_big_37_04: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_37_04";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_37_04.p3d";
	};
	class MAP_pond_big_38_01: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_38_01";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_38_01.p3d";
	};
	class MAP_pond_big_38_02: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_38_02";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_38_02.p3d";
	};
	class MAP_pond_big_38_03: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_38_03";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_38_03.p3d";
	};
	class MAP_pond_big_38_04: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_38_04";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_38_04.p3d";
	};
	class MAP_pond_big_39_01: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_39_01";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_39_01.p3d";
	};
	class MAP_pond_big_39_02: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_39_02";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_39_02.p3d";
	};
	class MAP_pond_big_39_03: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_39_03";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_39_03.p3d";
	};
	class MAP_pond_big_39_04: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_39_04";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_39_04.p3d";
	};
	class MAP_pond_big_40_01: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_40_01";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_40_01.p3d";
	};
	class MAP_pond_big_40_02: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_40_02";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_40_02.p3d";
	};
	class MAP_pond_big_40_03: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_40_03";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_40_03.p3d";
	};
	class MAP_pond_big_40_04: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_40_04";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_40_04.p3d";
	};
	class MAP_pond_big_41_01: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_41_01";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_41_01.p3d";
	};
	class MAP_pond_big_41_02: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_41_02";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_41_02.p3d";
	};
	class MAP_pond_big_41_03: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_41_03";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_41_03.p3d";
	};
	class MAP_pond_big_41_04: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_41_04";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_41_04.p3d";
	};
	class MAP_pond_big_41_05: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_41_05";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_41_05.p3d";
	};
	class MAP_pond_big_42_01: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_42_01";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_42_01.p3d";
	};
	class MAP_pond_big_42_02: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_42_02";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_42_02.p3d";
	};
	class MAP_pond_big_42_03: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_42_03";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_42_03.p3d";
	};
	class MAP_pond_big_42_04: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_42_04";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_42_04.p3d";
	};
	class MAP_pond_big_42_05: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_42_05";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_42_05.p3d";
	};
	class MAP_pond_big_42_06: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_42_06";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_42_06.p3d";
	};
	class MAP_pond_big_42_07: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_42_07";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_42_07.p3d";
	};
	class MAP_pond_big_42_08: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_42_08";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_42_08.p3d";
	};
	class MAP_pond_big_42_09: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_42_09";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_42_09.p3d";
	};
	class MAP_pond_big_42_10: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_42_10";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_42_10.p3d";
	};
	class MAP_pond_big_42_11: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_42_11";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_42_11.p3d";
	};
	class MAP_pond_big_42_12: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_42_12";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_42_12.p3d";
	};
	class MAP_pond_big_42_13: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_42_13";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_42_13.p3d";
	};
	class MAP_pond_big_42_14: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_42_14";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_42_14.p3d";
	};
	class MAP_pond_big_42_15: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_42_15";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_42_15.p3d";
	};
	class MAP_pond_big_42_16: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_42_16";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_42_16.p3d";
	};
	class MAP_pond_big_42_17: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_42_17";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_42_17.p3d";
	};
	class MAP_pond_big_42_18: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_42_18";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_42_18.p3d";
	};
	class MAP_pond_big_42_19: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_42_19";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_42_19.p3d";
	};
	class MAP_pond_big_42_20: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_42_20";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_42_20.p3d";
	};
	class MAP_pond_big_43_01: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_01";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_01.p3d";
	};
	class MAP_pond_big_43_02: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_02";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_02.p3d";
	};
	class MAP_pond_big_43_03: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_03";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_03.p3d";
	};
	class MAP_pond_big_43_04: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_04";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_04.p3d";
	};
	class MAP_pond_big_43_05: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_05";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_05.p3d";
	};
	class MAP_pond_big_43_06: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_06";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_06.p3d";
	};
	class MAP_pond_big_43_07: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_07";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_07.p3d";
	};
	class MAP_pond_big_43_08: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_08";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_08.p3d";
	};
	class MAP_pond_big_43_09: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_09";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_09.p3d";
	};
	class MAP_pond_big_43_10: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_10";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_10.p3d";
	};
	class MAP_pond_big_43_11: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_11";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_11.p3d";
	};
	class MAP_pond_big_43_12: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_12";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_12.p3d";
	};
	class MAP_pond_big_43_13: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_13";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_13.p3d";
	};
	class MAP_pond_big_43_14: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_14";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_14.p3d";
	};
	class MAP_pond_big_43_15: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_15";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_15.p3d";
	};
	class MAP_pond_big_43_16: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_16";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_16.p3d";
	};
	class MAP_pond_big_43_17: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_17";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_17.p3d";
	};
	class MAP_pond_big_43_18: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_18";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_18.p3d";
	};
	class MAP_pond_big_43_19: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_19";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_19.p3d";
	};
	class MAP_pond_big_43_20: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_20";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_20.p3d";
	};
	class MAP_pond_big_43_21: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_21";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_21.p3d";
	};
	class MAP_pond_big_43_22: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_22";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_22.p3d";
	};
	class MAP_pond_big_43_23: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_23";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_23.p3d";
	};
	class MAP_pond_big_43_24: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_24";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_24.p3d";
	};
	class MAP_pond_big_43_25: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_25";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_25.p3d";
	};
	class MAP_pond_big_43_26: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_26";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_26.p3d";
	};
	class MAP_pond_big_43_27: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_27";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_27.p3d";
	};
	class MAP_pond_big_43_28: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_28";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_28.p3d";
	};
	class MAP_pond_big_43_29: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_29";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_29.p3d";
	};
	class MAP_pond_big_43_30: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_30";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_30.p3d";
	};
	class MAP_pond_big_43_31: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_31";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_31.p3d";
	};
	class MAP_pond_big_43_32: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_32";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_32.p3d";
	};
	class MAP_pond_big_43_33: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_33";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_33.p3d";
	};
	class MAP_pond_big_43_34: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_34";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_34.p3d";
	};
	class MAP_pond_big_43_35: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_35";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_35.p3d";
	};
	class MAP_pond_big_43_36: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_43_36";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_43_36.p3d";
	};
	class MAP_pond_big_44: MAP_Water_DNo
	{
		scope = 2;
		displayName = "S pond_big_44";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\Structures\pond\pond_big_44.p3d";
	};
	class Land_LHD_1;
	class MAP_LHD_1: Land_LHD_1
	{
		scope = 2;
		displayName = "N LHD_1";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class Land_LHD_2;
	class MAP_LHD_2: Land_LHD_2
	{
		scope = 2;
		displayName = "N LHD_2";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class Land_LHD_3;
	class MAP_LHD_3: Land_LHD_3
	{
		scope = 2;
		displayName = "N LHD_3";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class Land_LHD_4;
	class MAP_LHD_4: Land_LHD_4
	{
		scope = 2;
		displayName = "N LHD_4";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class Land_LHD_5;
	class MAP_LHD_5: Land_LHD_5
	{
		scope = 2;
		displayName = "N LHD_5";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class Land_LHD_6;
	class MAP_LHD_6: Land_LHD_6
	{
		scope = 2;
		displayName = "N LHD_6";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class MAP_LHD_house_1: MAP_Water_DNo
	{
		scope = 2;
		displayName = "N LHD_house_1";
		icon = "\MAP_EU\icon\Icon.paa";
		model = "\CA\water2\LHD\LHD_house_1.p3d";
		accuracy = 1000;
	};
	class Land_LHD_house_2;
	class MAP_LHD_house_2: Land_LHD_house_2
	{
		scope = 2;
		displayName = "N LHD_house_2";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
	class Land_LHD_elev_R;
	class MAP_LHD_elev_R: Land_LHD_elev_R
	{
		scope = 2;
		displayName = "N LHD_elev_R";
		vehicleClass = "MAP_EUWater";
		accuracy = 1000;
	};
};
//};
