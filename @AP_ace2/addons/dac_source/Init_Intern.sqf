DAC_Basic_Value = 0;

DAC_Zone 		= compile preprocessFile "\DAC_Source\Scripts\DAC_Init_Zone.sqf";
DAC_Objects		= compile preprocessFile "\DAC_Source\Scripts\DAC_Create_Objects.sqf";
DAC_Activate 	= compile preprocessFile "\DAC_Source\Scripts\DAC_Activate_Zone.sqf";
DAC_Deactivate 	= compile preprocessFile "\DAC_Source\Scripts\DAC_Deactivate_Zone.sqf";
DAC_Weapons 	= compile preprocessFile "\DAC_Source\Scripts\DAC_Change_Weapons.sqf";

[] execVM "\DAC_Source\Configs\DAC_Config_Creator.sqf";
DAC_Path = "\DAC_Source\Configs\";