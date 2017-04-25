////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Jun 08 13:05:08 2013 : Created on Sat Jun 08 13:05:08 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_anims : turn\config.bin{
class CfgPatches
{
	class ace_anims_turn
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.01;
		requiredAddons[] = {"CA_Anims","CA_Anims_E","CA_Anims_Sdr","CA_Anims_E_Sdr"};
		version = 0;
	};
};
class CfgMovesBasic
{
	class Actions
	{
		class RifleBaseStandActions;
		class RifleProneActions: RifleBaseStandActions
		{
			turnSpeed = 2;
		};
		class RifleProneActionsRunF: RifleProneActions
		{
			Up = "AmovPpneMstpSrasWrflDnon_AmovPercMsprSlowWrflDf";
		};
		class ACE_RifleProneActions_noturn: RifleProneActions
		{
			turnSpeed = 1;
		};
		class PistolStandActions;
		class PistolProneActions: PistolStandActions
		{
			turnSpeed = 2;
		};
		class ACE_PistolProneActions_noturn: PistolProneActions
		{
			turnSpeed = 1;
		};
		class CivilStandActions;
		class CivilProneActions: CivilStandActions
		{
			turnSpeed = 2;
		};
		class ACE_CivilProneActions_noturn: CivilProneActions
		{
			turnSpeed = 1;
		};
		class BinocProneRflActions: RifleProneActions{};
		class BinocPronePstActions: PistolProneActions{};
		class BinocProneCivilActions: CivilProneActions{};
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class AmovPercMstpSrasWrflDnon;
		class AmovPpneMstpSrasWrflDnon: AmovPercMstpSrasWrflDnon
		{
			actions = "ACE_RifleProneActions_noturn";
		};
		class AmovPpneMstpSrasWrflDnon_turnL: AmovPpneMstpSrasWrflDnon
		{
			actions = "RifleProneActions";
		};
		class AmovPpneMstpSrasWrflDnon_turnR: AmovPpneMstpSrasWrflDnon
		{
			actions = "RifleProneActions";
		};
		class AmovPpneMrunSlowWrflDf: AmovPpneMstpSrasWrflDnon
		{
			actions = "RifleProneActions";
		};
		class AmovPercMstpSrasWpstDnon;
		class AmovPpneMstpSrasWpstDnon: AmovPercMstpSrasWpstDnon
		{
			actions = "ACE_PistolProneActions_noturn";
		};
		class AmovPpneMstpSrasWpstDnon_turnL: AmovPpneMstpSrasWpstDnon
		{
			actions = "PistolProneActions";
		};
		class AmovPpneMstpSrasWpstDnon_turnR: AmovPpneMstpSrasWpstDnon
		{
			actions = "PistolProneActions";
		};
		class AmovPpneMrunSlowWpstDf: AmovPpneMstpSrasWpstDnon
		{
			actions = "PistolProneActions";
		};
		class AmovPercMstpSnonWnonDnon;
		class AmovPpneMstpSnonWnonDnon: AmovPercMstpSnonWnonDnon
		{
			actions = "ACE_CivilProneActions_noturn";
		};
		class AmovPpneMstpSnonWnonDnon_turnL: AmovPpneMstpSnonWnonDnon
		{
			actions = "CivilProneActions";
		};
		class AmovPpneMstpSnonWnonDnon_turnR: AmovPpneMstpSnonWnonDnon
		{
			actions = "CivilProneActions";
		};
		class AmovPpneMrunSnonWnonDf: AmovPpneMstpSnonWnonDnon
		{
			actions = "CivilProneActions";
		};
	};
};
//};
