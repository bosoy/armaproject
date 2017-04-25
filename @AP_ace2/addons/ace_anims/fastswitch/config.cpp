////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Jun 08 13:05:08 2013 : Created on Sat Jun 08 13:05:08 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_anims : fastswitch\config.bin{
class CfgPatches
{
	class ace_anims_fastswitch
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
	class Default;
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class TransAnimBase;
		class amovpercmstpslowwlnrdnon;
		class AmovPercMstpSlowWpstDnon;
		class AmovPercMstpSlowWrflDnon;
		class AmovPercMstpSnonWnonDnon;
		class amovpercmstpsraswlnrdnon;
		class AmovPercMstpSrasWpstDnon;
		class AmovPercMstpSrasWrflDnon;
		class AovrPercMstpSlowWlnrDf: amovpercmstpslowwlnrdnon
		{
			speed = 0.7;
		};
		class AovrPercMstpSlowWpstDf: AmovPercMstpSlowWpstDnon
		{
			speed = 0.724137;
		};
		class AovrPercMstpSlowWrflDf: AmovPercMstpSlowWrflDnon
		{
			speed = 0.617646;
		};
		class AovrPercMstpSnonWnonDf: AmovPercMstpSnonWnonDnon
		{
			speed = 0.80769;
		};
		class AovrPercMstpSrasWlnrDf: amovpercmstpsraswlnrdnon
		{
			speed = 0.7;
		};
		class AovrPercMstpSrasWpstDf: AmovPercMstpSrasWpstDnon
		{
			speed = 0.724137;
		};
		class AovrPercMstpSrasWrflDf: AmovPercMstpSrasWrflDnon
		{
			speed = 0.617646;
		};
		class AmovPercMstpSrasWrflDnon_AmovPercMstpSrasWpstDnon: TransAnimBase
		{
			speed = 1.4;
		};
		class AmovPercMstpSrasWrflDnon_AmovPercMstpSrasWpstDnon_end: AmovPercMstpSrasWrflDnon_AmovPercMstpSrasWpstDnon
		{
			speed = 2.7;
		};
		class AmovPknlMstpSrasWrflDnon_AmovPknlMstpSrasWpstDnon: TransAnimBase
		{
			speed = 0.975;
		};
		class AmovPknlMstpSrasWrflDnon_AmovPknlMstpSrasWpstDnon_end: AmovPknlMstpSrasWrflDnon_AmovPknlMstpSrasWpstDnon
		{
			speed = 2;
		};
		class AmovPpneMstpSrasWrflDnon_AmovPpneMstpSrasWpstDnon: TransAnimBase
		{
			speed = 0.715;
		};
		class AmovPpneMstpSrasWrflDnon_AmovPpneMstpSrasWpstDnon_end: AmovPpneMstpSrasWrflDnon_AmovPpneMstpSrasWpstDnon
		{
			speed = 1.43;
		};
		class AmovPercMstpSrasWpstDnon_AmovPercMstpSrasWrflDnon: TransAnimBase
		{
			speed = 2.7;
		};
		class AmovPercMstpSrasWpstDnon_AmovPercMstpSrasWrflDnon_end: AmovPercMstpSrasWpstDnon_AmovPercMstpSrasWrflDnon
		{
			speed = 1.17;
		};
		class AmovPknlMstpSrasWpstDnon_AmovPknlMstpSrasWrflDnon: TransAnimBase
		{
			speed = 1.955;
		};
		class AmovPknlMstpSrasWpstDnon_AmovPknlMstpSrasWrflDnon_end: AmovPknlMstpSrasWpstDnon_AmovPknlMstpSrasWrflDnon
		{
			speed = 0.828;
		};
		class AmovPknlMstpSrasWlnrDnon_AmovPknlMstpSrasWrflDnon: TransAnimBase
		{
			speed = 0.6;
		};
		class AmovPknlMstpSrasWlnrDnon_AmovPpneMstpSnonWnonDnon: TransAnimBase
		{
			speed = 1.0;
		};
		class AmovPpneMstpSnonWnonDnon_AmovPpneMstpSrasWrflDnon: TransAnimBase
		{
			speed = 0.6;
		};
		class AwopPercMstpSgthWrflDnon_Start1: Default{};
		class AwopPercMstpSgthWrflDnon_Throw1: AwopPercMstpSgthWrflDnon_Start1{};
		class AwopPercMstpSgthWrflDnon_End1: AwopPercMstpSgthWrflDnon_Start1{};
		class AwopPercMstpSgthWrflDnon_Start2: AwopPercMstpSgthWrflDnon_Start1{};
		class AwopPercMstpSgthWrflDnon_Throw2: AwopPercMstpSgthWrflDnon_Throw1{};
		class AwopPercMstpSgthWrflDnon_End2: AwopPercMstpSgthWrflDnon_End1
		{
			speed = 1.0;
		};
		class AwopPknlMstpSgthWrflDnon_Start;
		class AwopPknlMstpSgthWrflDnon_End: AwopPknlMstpSgthWrflDnon_Start
		{
			speed = 1.2;
		};
		class AwopPpneMstpSgthWrflDnon_Start;
		class AwopPpneMstpSgthWrflDnon_End: AwopPpneMstpSgthWrflDnon_Start
		{
			speed = 1.7;
		};
	};
};
//};
