////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 21 14:00:44 2011 : Created on Fri Oct 21 14:00:44 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_sm_c_sound_veh_helicopters : config.bin{
class CfgPatches
{
	class acex_sm_c_sound_veh_helicopters
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"acex_sm_main","Arma2_Ka52","CA_AH64D","CAAir","CAAir2","CAAir3","CAAir2_UH1Y","CAAir_E","CAAir_E_CH_47F","CAAir_E_AH6J","CAAir_E_Mi8","CAAir_E_Mi24","CAAir_E_UH1H_EP1","CAAir_E_UH60M","acex_sm_s_veh_helicopters"};
		version = "1.12.0.97";
	};
};
class CfgVehicles
{
	class Air;
	class Helicopter: Air
	{
		class Sounds;
	};
	class AH1_Base;
	class AH64_base_EP1;
	class CH_47F_EP1;
	class UH60_Base;
	class Kamov_Base;
	class AH1Z: AH1_Base
	{
		class Sounds
		{
			class Engine
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ah1z_eng_ex.wss",3.16228,1,800};
				frequency = "rotorSpeed";
				volume = "camPos*((rotorSpeed-0.72)*4)";
			};
			class RotorLowOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ah1z_rot_lo.wss",3.16228,1,"1800*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*(0 max (rotorSpeed-0.1))";
				cone[] = {1.8,3.14,2,0.9};
			};
			class RotorHighOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ah1z_rot_hi.wss",3.16228,1,"1500*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*10*(0 max (rotorThrust-0.95))";
				cone[] = {1.8,3.14,2,0.9};
			};
			class EngineIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ah1z_eng_in.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
			};
			class RotorLowIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ah1z_rot_lo.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))*0.75";
			};
			class RotorHighIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ah1z_rot_hi.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*3*(0 max (rotorThrust-0.9))*0.75";
			};
		};
	};
	class UH1_Base: Helicopter
	{
		class Sounds: Sounds
		{
			class Engine;
		};
	};
	class UH1Y: UH1_Base
	{
		class Sounds: Sounds
		{
			class Engine: Engine
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\uh1y_eng_ex.wss",2.51189,1,800};
				frequency = "rotorSpeed";
				volume = "camPos*((rotorSpeed-0.72)*4)";
			};
			class RotorLowOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\uh1y_rot_lo.wss",2.51189,1,"1600*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*(0 max (rotorSpeed-0.1))";
				cone[] = {1.6,3.14,2,0.5};
			};
			class RotorHighOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\uh1y_rot_hi.wss",2.51189,1,"1400*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*10*(0 max (rotorThrust-0.9))";
				cone[] = {1.6,3.14,2,0.5};
			};
			class EngineIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\uh1y_eng_in.wss",1,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
			};
			class RotorLowIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\uh1y_rot_lo.wss",1,1};
				frequency = "rotorSpeed";
				volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))";
			};
			class RotorHighIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\uh1y_rot_hi.wss",1,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*3*(0 max (rotorThrust-0.9))";
			};
		};
	};
	class UH1H_Base: Helicopter
	{
		class Sounds
		{
			class Engine
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\uh1h_eng_ex.wss",2.51189,1,800};
				frequency = "rotorSpeed";
				volume = "camPos*((rotorSpeed-0.72)*4)";
			};
			class RotorLowOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\uh1h_rot_lo.wss",2.51189,1,"1600*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*(0 max (rotorSpeed-0.1))";
				cone[] = {1.6,3.14,2,0.5};
			};
			class RotorHighOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\uh1h_rot_hi.wss",2.51189,1,"1400*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*10*(0 max (rotorThrust-0.9))";
				cone[] = {1.6,3.14,2,0.5};
			};
			class EngineIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\uh1h_eng_in.wss",3.16228,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
			};
			class RotorLowIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\uh1h_rot_lo.wss",3.16228,1};
				frequency = "rotorSpeed";
				volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))";
			};
			class RotorHighIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\uh1h_rot_hi.wss",3.16228,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*3*(rotorThrust-0.9)";
			};
		};
	};
	class MH60S: UH60_Base
	{
		class Sounds
		{
			class Engine
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\mh60_eng_ex.wss",1,1,800};
				frequency = "rotorSpeed";
				volume = "camPos*((rotorSpeed-0.72)*4)";
			};
			class RotorLowOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\mh60_rot_lo.wss",2.51189,1,"1600*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*(0 max (rotorSpeed-0.1))";
				cone[] = {1.6,3.14,2,0.5};
			};
			class RotorHighOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\mh60_rot_hi.wss",2.51189,1,"1400*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*10*(0 max (rotorThrust-0.9))";
				cone[] = {1.6,3.14,2,0.5};
			};
			class EngineIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\mh60_eng_in.wss",1,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
			};
			class RotorLowIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\mh60_rot_lo.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))";
			};
			class RotorHighIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\mh60_rot_hi.wss",3.16228,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*3*(0 max (rotorThrust-0.9))";
			};
		};
	};
	class UH60M_base_EP1: UH60_Base
	{
		class Sounds
		{
			class Engine
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\mh60_eng_ex.wss",1,1,800};
				frequency = "rotorSpeed";
				volume = "camPos*((rotorSpeed-0.72)*4)";
			};
			class RotorLowOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\mh60_rot_lo.wss",2.51189,1,"1600*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*(0 max (rotorSpeed-0.1))";
				cone[] = {1.6,3.14,2,0.5};
			};
			class RotorHighOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\mh60_rot_hi.wss",2.51189,1,"1400*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*10*(0 max (rotorThrust-0.9))";
				cone[] = {1.6,3.14,2,0.5};
			};
			class EngineIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\mh60_eng_in.wss",1,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
			};
			class RotorLowIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\mh60_rot_lo.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))";
			};
			class RotorHighIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\mh60_rot_hi.wss",3.16228,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*3*(0 max (rotorThrust-0.9))";
			};
		};
	};
	class AH64D: AH64_base_EP1
	{
		class Sounds
		{
			class Engine
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ah64_eng_ex.wss",3.16228,1,1000};
				frequency = "rotorSpeed";
				volume = "camPos*((rotorSpeed-0.72)*4)";
			};
			class RotorLowOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ah64_rot_lo.wss",3.16228,1,"1300*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*(0 max (rotorSpeed-0.1))";
				cone[] = {1.8,3.14,2,0.9};
			};
			class RotorHighOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ah64_rot_hi.wss",1.77828,"",1,"1200*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*10*(0 max (rotorThrust-0.9))";
				cone[] = {1.8,3.14,2,0.9};
			};
			class EngineIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ah64_eng_in.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
			};
			class RotorLowIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ah64_rot_lo.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))";
			};
			class RotorHighIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ah64_rot_hi.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*3*(0 max (rotorThrust-0.9))";
			};
		};
	};
	class AH64D_EP1: AH64_base_EP1
	{
		class Sounds
		{
			class Engine
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ah64_eng_ex.wss",3.16228,1,1000};
				frequency = "rotorSpeed";
				volume = "camPos*((rotorSpeed-0.72)*4)";
			};
			class RotorLowOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ah64_rot_lo.wss",3.16228,1,"1300*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*(0 max (rotorSpeed-0.1))";
				cone[] = {1.8,3.14,2,0.9};
			};
			class RotorHighOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ah64_rot_hi.wss",1.77828,"",1,"1200*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*10*(0 max (rotorThrust-0.9))";
				cone[] = {1.8,3.14,2,0.9};
			};
			class EngineIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ah64_eng_in.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
			};
			class RotorLowIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ah64_rot_lo.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))";
			};
			class RotorHighIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ah64_rot_hi.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*3*(0 max (rotorThrust-0.9))";
			};
		};
	};
	class AH64D_Sidewinders: AH64D
	{
		scope = 1;
		class Sounds
		{
			class Engine
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ah64_eng_ex.wss",3.16228,1,1000};
				frequency = "rotorSpeed";
				volume = "camPos*((rotorSpeed-0.72)*4)";
			};
			class RotorLowOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ah64_rot_lo.wss",3.16228,1,"1300*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*(0 max (rotorSpeed-0.1))";
				cone[] = {1.8,3.14,2,0.9};
			};
			class RotorHighOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ah64_rot_hi.wss",1.77828,"",1,"1200*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*10*(0 max (rotorThrust-0.9))";
				cone[] = {1.8,3.14,2,0.9};
			};
			class EngineIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ah64_eng_in.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
			};
			class RotorLowIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ah64_rot_lo.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))";
			};
			class RotorHighIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ah64_rot_hi.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*3*(0 max (rotorThrust-0.9))";
			};
		};
	};
	class CH47_base_EP1: Helicopter
	{
		class Sounds
		{
			class Engine
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ch47_eng_ex.wss",1,1,800};
				frequency = "rotorSpeed";
				volume = "camPos*((rotorSpeed-0.72)*4)";
			};
			class RotorLowOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ch47_rot_lo.wss",3.16228,1,"1800*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*(0 max (rotorSpeed-0.1))";
				cone[] = {1.8,3.14,2,0.9};
			};
			class RotorHighOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ch47_rot_hi.wss",3.16228,1,"1500*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*10*(0 max (rotorThrust-0.95))";
				cone[] = {1.8,3.14,2,0.9};
			};
			class EngineIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ch47_eng_in.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
			};
			class RotorLowIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ch47_rot_lo.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))";
			};
			class RotorHighIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ch47_rot_hi.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*3*(0 max (rotorThrust-0.9))";
			};
		};
	};
	class CH_47F_BAF: CH_47F_EP1
	{
		class Sounds
		{
			class Engine
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ch47_eng_ex.wss",1,1,800};
				frequency = "rotorSpeed";
				volume = "camPos*((rotorSpeed-0.72)*4)";
			};
			class RotorLowOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ch47_rot_lo.wss",3.16228,1,"1800*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*(0 max (rotorSpeed-0.1))";
				cone[] = {1.8,3.14,2,0.9};
			};
			class RotorHighOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ch47_rot_hi.wss",3.16228,1,"1500*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*10*(0 max (rotorThrust-0.95))";
				cone[] = {1.8,3.14,2,0.9};
			};
			class EngineIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ch47_eng_in.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
			};
			class RotorLowIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ch47_rot_lo.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))";
			};
			class RotorHighIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ch47_rot_hi.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*3*(0 max (rotorThrust-0.9))";
			};
		};
	};
	class AH6_Base_EP1: Helicopter
	{
		soundGetIn[] = {"x\acex_sm\addons\s_veh_helicopters\oh6_getin.wss",1.77828,1.0};
		soundGetOut[] = {"x\acex_sm\addons\s_veh_helicopters\oh6_getout.wss",1.77828,1.0,80};
		soundDammage[] = {"x\acex_sm\addons\s_veh_helicopters\oh6_alarm.wss",3.0,1.0,200};
		soundCrash[] = {"x\acex_sm\addons\s_veh_helicopters\oh6_crash.wss",3.0,1.0,1000};
		soundWaterCrash[] = {"x\acex_sm\addons\s_veh_helicopters\oh6_water.wss",2.0,1.0,500};
		soundEngineOnInt[] = {"x\acex_sm\addons\s_veh_helicopters\oh6_eng_start_in.wss",0.794328,1.0,600};
		soundEngineOnExt[] = {"x\acex_sm\addons\s_veh_helicopters\oh6_eng_start_ex.wss",0.794328,1.0,600};
		soundEngineOffInt[] = {"x\acex_sm\addons\s_veh_helicopters\oh6_eng_stop_in.wss",0.794328,1.0,600};
		soundEngineOffExt[] = {"x\acex_sm\addons\s_veh_helicopters\oh6_eng_stop_ex.wss",0.794328,1.0,600};
		class Sounds
		{
			class Engine
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\oh6_eng_ex.wss",3.16228,1,1000};
				frequency = "rotorSpeed";
				volume = "camPos*((rotorSpeed-0.72)*4)";
			};
			class RotorLowOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\oh6_rot_lo.wss",3.16228,1,"1300*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*(0 max (rotorSpeed-0.1))";
				cone[] = {1.8,3.14,2,0.9};
			};
			class RotorHighOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\oh6_rot_hi.wss",1.77828,1,"1200*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*10*(0 max (rotorThrust-0.95))";
				cone[] = {1.8,3.14,2,0.9};
			};
			class EngineIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\oh6_eng_in.wss",1.25893,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
			};
			class RotorLowIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\oh6_rot_lo.wss",1.25893,1};
				frequency = "rotorSpeed";
				volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))";
			};
			class RotorHighIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\oh6_rot_hi.wss",1.99526,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*3*(rotorThrust-0.9)";
			};
			class WindNoiseOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\oh6_wind.wss",6.9,2.2,220};
				frequency = "(0.1+(1.2*(speed factor[1, 150])))";
				volume = "camPos*(speed factor[1, 150])*((rpm*0.105-0.75)*4)";
			};
			class WindNoiseIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\oh6_wind.wss",6.9,2.2};
				frequency = "(0.1+(1.2*(speed factor[1, 150])))";
				volume = "(1-camPos)*(speed factor[1, 150])*((rpm*0.105-0.75)*4)";
			};
		};
	};
	class BAF_Merlin_HC3_D: Helicopter
	{
		class Sounds
		{
			class Engine
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\merlin_eng_ex.wss",5.62341,1,1000};
				frequency = "rotorSpeed";
				volume = "camPos*((rotorSpeed-0.72)*4)";
			};
			class RotorLowOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\merlin_rot_lo.wss",1.77828,1,"1300*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*(0 max (rotorSpeed-0.1))";
				cone[] = {1.8,3.14,2.0,0.9};
			};
			class RotorHighOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\merlin_rot_hi.wss",3.16228,1,"1200*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*10*(0 max (rotorThrust-0.95))";
				cone[] = {1.8,3.14,2.0,0.9};
			};
			class EngineIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\merlin_eng_in.wss",1,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
			};
			class RotorLowIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\merlin_rot_lo.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))";
			};
			class RotorHighIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\merlin_rot_hi.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*3*(rotorThrust-0.9)";
			};
		};
	};
	class AW159_Lynx_BAF: Helicopter
	{
		class Sounds
		{
			class Engine
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\lynx_eng_ex.wss",5.62341,1,1000};
				frequency = "rotorSpeed";
				volume = "camPos*((rotorSpeed-0.72)*4)";
			};
			class RotorLowOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\lynx_rot_lo.wss",1.77828,1,"1300*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*(0 max (rotorSpeed-0.1))";
				cone[] = {1.8,3.14,2.0,0.9};
			};
			class RotorHighOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\lynx_rot_hi.wss",3.16228,1,"1200*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*10*(0 max (rotorThrust-0.95))";
				cone[] = {1.8,3.14,2.0,0.9};
			};
			class EngineIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\lynx_eng_in.wss",1,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
			};
			class RotorLowIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\lynx_rot_lo.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))";
			};
			class RotorHighIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\lynx_rot_hi.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*3*(rotorThrust-0.9)";
			};
		};
	};
	class Ka60_Base_PMC: Helicopter
	{
		class Sounds
		{
			class Engine
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ka60_eng_ex.wss",5.62341,1,800};
				frequency = "rotorSpeed";
				volume = "camPos*((rotorSpeed-0.72)*4)";
			};
			class RotorLowOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ka60_rot_lo.wss",1.77828,1,"1500*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*(0 max (rotorSpeed-0.1))";
				cone[] = {1.8,3.14,2.0,0.9};
			};
			class RotorHighOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ka60_rot_hi.wss",3.16228,1,"1400*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*10*(0 max (rotorThrust-0.95))";
				cone[] = {1.1,3.14,2.0,0.9};
			};
			class EngineIn
			{
				sound[] = {"Ca\Sounds_PMC\Air_PMC\Ka_engi_int_1",3.1622777,1.0};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
			};
			class RotorLowIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ka60_rot_lo.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))";
			};
			class RotorHighIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ka60_rot_hi.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*3*(rotorThrust-0.9)";
			};
		};
	};
	class Mi17_base: Helicopter
	{
		class Sounds
		{
			class Engine
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\mi17_eng_ex.wss",5.62341,1,900};
				frequency = "rotorSpeed";
				volume = "camPos*((rotorSpeed-0.72)*4)";
			};
			class RotorLowOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\mi17_rot_lo_ex.wss",1.77828,1,"1600*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*(0 max (rotorSpeed-0.1))";
				cone[] = {1.6,3.14,2,0.95};
			};
			class RotorHighOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\mi17_rot_hi_ex.wss",3.16228,1,"1400*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*10*(0 max (rotorThrust-0.9))";
				cone[] = {1.6,3.14,2,0.95};
			};
			class EngineIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\mi17_eng_in.wss",1,1};
				frequency = "rpm*0.105";
				volume = "(1-camPos)*((rpm*0.105-0.75)*4)";
			};
			class RotorLowIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\mi17_rot_lo_in.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*(0 max (rotorSpeed-0.1))";
			};
			class RotorHighIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\mi17_rot_hi_in.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*3*(0 max (rotorThrust-0.9))";
			};
		};
	};
	class Mi24_base: Helicopter
	{
		class Sounds
		{
			class Engine
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\mi24_eng_ex.wss",5.62341,1,900};
				frequency = "rotorSpeed";
				volume = "camPos*((rotorSpeed-0.72)*4)";
			};
			class RotorLowOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\mi24_rot_lo_ex.wss",1.77828,1,"1650*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*(0 max (rotorSpeed-0.1))";
				cone[] = {1.6,3.14,2,0.95};
			};
			class RotorHighOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\mi24_rot_hi_ex.wss",3.16228,1,"1400*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*10*(0 max (rotorThrust-0.9))";
				cone[] = {1.6,3.14,2,0.95};
			};
			class EngineIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\mi24_eng_in.wss",1,1};
				frequency = "rpm*0.105";
				volume = "(1-camPos)*((rpm*0.105-0.75)*4)";
			};
			class RotorLowIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\mi24_rot_lo_in.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*(0 max (rotorSpeed-0.1))";
			};
			class RotorHighIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\mi24_rot_hi_in.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*3*(0 max (rotorThrust-0.9))";
			};
		};
	};
	class Ka52: Kamov_Base
	{
		class Sounds
		{
			class Engine
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ka52_eng_ex.wss",2.23872,1,900};
				frequency = "rotorSpeed";
				volume = "camPos*((rotorSpeed-0.72)*4)";
			};
			class RotorLowOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ka52_rot_lo.wss",1.41254,1,"1500*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*(0 max (rotorSpeed-0.1))";
				cone[] = {1.6,3.14,1.6,0.95};
			};
			class RotorHighOut
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ka52_rot_hi.wss",3.16228,1,"1200*1.5"};
				frequency = "rotorSpeed";
				volume = "camPos*10*(0 max (rotorThrust-0.9))";
				cone[] = {1.6,3.14,1.6,0.95};
			};
			class EngineIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ka52_eng_in.wss",1,1};
				frequency = "rpm*0.105";
				volume = "(1-camPos)*((rpm*0.105-0.75)*4)";
			};
			class RotorLowIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ka52_rot_lo.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*(0 max (rotorSpeed-0.1))*0.75";
			};
			class RotorHighIn
			{
				sound[] = {"x\acex_sm\addons\s_veh_helicopters\ka52_rot_hi.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*3*(0 max (rotorThrust-0.9))*0.75";
			};
		};
	};
};
//};
