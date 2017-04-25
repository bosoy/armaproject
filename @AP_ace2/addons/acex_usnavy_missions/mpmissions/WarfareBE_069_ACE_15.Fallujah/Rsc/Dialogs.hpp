/* Dialogs */

#ifndef VANILLA
	#define gearmenu "_this ExecVM 'Client\GUI\GUI_GearBeta.sqf'"
#else
	#define gearmenu "_this ExecVM 'Client\GUI\GUI_GearV.sqf'"
#endif

//--- Vote Menu.
class RscDisplayWFVoting {
	movingEnable = 1;
	idd = 10001;
	onLoad = "ExecVM ""Client\GUI\GUI_UpdateCommanderVoteMenu.sqf""";
	
	class controlsBackground {
		class CA_Background : RscPicture {
			idc = 10002;
			x = 0.273;
			y = 0.134;
			w = 0.627451;
			h = 0.836601;
			text = "\ca\ui\data\igui_wf_vote_background_ca.paa";
			colorText[] = {1, 1, 1, 1};
		};
	};
	
	class controls {
		class VotingTitle : RscText {
			idc = 10003;
			x = 0.283;
			y = 0.133549;
			w = 0.44;
			h = 0.03921;
			text = $STR_WF_VOTE_COMMANDER;
		};
		
		class VotesText : RscText {
			idc = 10004;
			x = 0.283;
			y = 0.174;
			w = 0.135;
			h = 0.03921;
			text = $STR_WF_VOTES;
		};
		
		class PlayersText : RscText {
			idc = 10005;
			x = 0.414;
			y = 0.174;
			w = 0.306;
			h = 0.03921;
			text = $STR_WF_PLAYERS;
		};
		
		class Players : RscListBox {
			columns[] = {0.0, 0.3};
			idc = 10006;
			x = 0.273;
			y = 0.211;
			w = 0.455;
			h = 0.528;
			rows = 10;
			rowHeight = 0.025;
			lineSpacing = 1;
			text = " ";
		};
		
		class MostVotesText : RscText {
			idc = 10007;
			x = 0.283;
			y = 0.785;
			w = 0.434;
			h = 0.03921;
			text = "";
		};
		
		class ButtonClose : RscIGUIShortcutButton {
			idc = 1;
			shortcuts[] = {0x00050000 + 0, 0x00050000 + 1, 28, 57, 156};
			x = 0.545758;
			y = 0.828439;
			text = $STR_DISP_CLOSE;
			onButtonClick = "closeDialog 0;";
		};
	};
};

//--- Main Menu.
class WF_Menu {
	movingEnable = 1;
	idd = 11000;
	onLoad = "ExecVM ""Client\GUI\GUI_Menu.sqf""";
	
	class controlsBackground {
		class Mainback : RscPicture {
			x = 0.015;
			y = 0.17;
			w = 0.627451;
			h = 0.836601;
			moving = 1;
			text = "\ca\ui\data\ui_mainmenu_background_ca.paa";
		};
	};
	class controls {
		class Button_A: RscShortcutButtonMain
		{
			idc = 11001;
			x = 0.02;
			y = 0.255;
			text = $STR_WF_Purchase_Units;
			action = "MenuAction = 1";
		};
		class Button_B: RscShortcutButtonMain
		{
			idc = 11002;
			x = 0.02;
			y = 0.355;
			text = $STR_WF_Purchase_Gear;
			action = "MenuAction = 2";
		};
		class Button_C: RscShortcutButtonMain
		{
			idc = 11003;
			x = 0.02;
			y = 0.455;
			text = $STR_WF_TeamMenu;
			action = "MenuAction = 3";
		};
		class Button_D: RscShortcutButtonMain
		{
			idc = 11004;
			x = 0.02;
			y = 0.555;
			text = $STR_WF_VoteForCommander;
			action = "MenuAction = 4";
		};
		class Button_E: RscShortcutButtonMain
		{
			idc = 11005;
			x = 0.02;
			y = 0.655;
			text = $STR_WF_CommandMenu;
			action = "MenuAction = 5";
		};
		class Label: RscText {
			idc = 11006;
			text = $STR_WF_Options;
			x = 0.04;
			y = 0.205;
		};
		class CA_Diff_B_Back : RscShortcutButton {
			idc = 11007;
			shortcuts[] = {0x00050000 + 1};
			default = 0;
			x = 0.14;
			y = 0.7625;
			text = $STR_DISP_CLOSE;
			action = "closeDialog 0;";
		};
	};
};

//--- Team Menu.
class RscVideo {
	movingEnable = 1;
	idd = 13000;
	onLoad = "_this ExecVM ""Client\GUI\GUI_TeamMenu.sqf""";
	
	class controlsBackground {
		class Mainback : RscPicture {
			x = 0.015;
			y = 0.17;
			w = 0.627451;
			h = 0.836601;
			moving = 1;
			text = "\ca\ui\data\ui_mainmenu_background_ca.paa";
		};
	};
	class controls {
		class Label: RscText {
			idc = 13001;
			text = $STR_WF_TeamMenu;
			x = 0.04;
			y = 0.205;
		};
		class CA_VD_Label: RscText {
			idc = 13002;
			text = "";
			x = 0.04;
			y = 0.25;
			sizeEx = 0.03;
		};
		class CA_VD_Slider : RscXSliderH {
			idc = 13003;
			x = 0.04;
			y = 0.285;
			w = 0.28;
		};
		class CA_TG_Label: RscText {
			idc = 13004;
			text = "";
			x = 0.04;
			y = 0.31;
			sizeEx = 0.03;
		};
		class CA_TG_Slider : RscXSliderH {
			idc = 13005;
			x = 0.04;
			y = 0.345;
			w = 0.28;
		};
		class CA_TM_Label: RscText {
			idc = 13006;
			text = "";
			x = 0.04;
			y = 0.37;
			sizeEx = 0.03;
		};
		class CA_TM_Slider : RscXSliderH {
			idc = 13007;
			x = 0.04;
			y = 0.405;
			w = 0.28;
		};
		class CA_TM_Combo: RscCombo {
			idc = 13008;
			x = 0.04;
			w = 0.28;
			y = 0.445;
		};
		class CA_TM_Button : RscIGUIShortcutButton {
			idc = 13009;
			x = 0.04;
			y = 0.485;
			w = 0.28;
			text = $STR_WF_Transfer;
			action = "MenuAction = 1";
		};
		class CA_IC_Label: RscText {
			idc = 13010;
			text = "";
			x = 0.04;
			y = 0.73;
			sizeEx = 0.03;
		};
		class CA_Diff_B_Back : RscShortcutButton {
			idc = 13011;
			shortcuts[] = {0x00050000 + 1};
			default = 0;
			x = 0.14;
			y = 0.7625;
			text = $STR_DISP_CLOSE;
			action = "closeDialog 0";
		};
		class CA_UN_Button : RscIGUIShortcutButton {
			idc = 13012;
			x = 0.04;
			y = 0.525;
			w = 0.28;
			text = $STR_WF_Unflip;
			action = "MenuAction = 2";
		};
		class CA_DB_Combo: RscCombo {
			idc = 13013;
			x = 0.04;
			w = 0.28;
			y = 0.57;
		};
		class CA_DB_Button : RscIGUIShortcutButton {
			idc = 13014;
			x = 0.04;
			y = 0.615;
			w = 0.28;
			text = $STR_WF_Disband;
			action = "MenuAction = 3";
		};
		class CA_HB_Button : RscIGUIShortcutButton {
			idc = 13015;
			x = 0.04;
			y = 0.655;
			w = 0.28;
			text = $STR_WF_HeadbugFix;
			action = "MenuAction = 4";
		};
		class CA_VPOPON_Button : RscIGUIShortcutButton {
			idc = 13016;
			x = 0.04;
			y = 0.695;
			w = 0.28;
			text = $STR_WF_Vote_PopUp_On;
			action = "MenuAction = 5";
		};
		class CA_VPOPOFF_Button : RscIGUIShortcutButton {
			idc = 13017;
			x = 0.04;
			y = 0.695;
			w = 0.28;
			text = $STR_WF_Vote_PopUp_Off;
			action = "MenuAction = 5";
		};
		class CA_FX_combo : RscCombo {
			idc = 13018;
			x = 0.04;
			y = 0.7975;
			w = 0.1;
			
			onLBSelChanged = "MenuAction = 6";
		};
	};
};

//--- Unit Purchase.
class RscBuyUnits {
	movingEnable = 1;
	idd = 12000;
	onLoad = "_this ExecVM ""Client\GUI\GUI_BuyUnits.sqf""";
	
	class controlsBackground {
		class Mainback : RscPicture {
			x = 0.04;
			y = 0.01;
			w = 1.25;
			h = 1.67;
			moving = 1;
			text = "\ca\ui\data\igui_background_buy_units_ca.paa";
		};
		class background1: RscText {
			x = 0.1975;
			y = 0.662;
			w = 0.2975;
			h = 0.234;
			colorBackground[] = {0, 0, 0, 0.5};
		};
	};
	
	class controls {
		/* Controls */
		class CA_BuyList : RscListBoxA {
			idc = 12001;
			x = 0.043;
			y = 0.167676;
			w = 0.45;
			h = 0.444;
			columns[] = {0.01, 0.19, 0.75};
			drawSideArrows = 0;
			idcRight = -1;
			idcLeft = -1;
			
			onLBSelChanged = "MenuAction = 302";
			onLBDblClick = "MenuAction = 1";
		};
		class CA_OK_Text : RscIGUIShortcutButton {
			idc = 12002;
			shortcuts[] = {0x00050000 + 0, 28, 57, 156};
			action = "MenuAction = 1";
			x = 0.0392 + 0.245 * 2;
			y = 0.897;
			w = 0.185;
			h = 0.052;
			text = $STR_WF_Purchase;
		};
		class CA_Diff_B_Back : CA_OK_Text {
			idc = 12003;
			shortcuts[] = {0x00050000 + 1};
			default = 0;
			x = 0.0392 + 0.245 * 3;
			text = $STR_DISP_CLOSE;
			action = "closeDialog 0";
		};
		class CA_Label: RscText {
			idc = 12004;
			text = $STR_WF_Purchase_Units;
			x = 0.047634;
			y = 0.01;
			colorText[] = subcolor1;
			SizeEx = 0.03;
			shadow = 2;
		};
		class WF_Con1: RscClickableText {
			idc = 12005;
			text = "\CA\warfare2\Images\con_barracks.paa";
			x = 0.515;
			y = 0.05;
			w = 0.072;
			h = 0.072;
			action = "MenuAction = 101";
		};
		class WF_Con2: RscClickableText {
			idc = 12006;
			text = "\CA\warfare2\Images\con_light.paa";
			x = 0.585;
			y = 0.05;
			w = 0.072;
			h = 0.072;
			action = "MenuAction = 102";
		};
		class WF_Con3: RscClickableText {
			idc = 12007;
			text = "\CA\warfare2\Images\con_heavy.paa";
			x = 0.655;
			y = 0.05;
			w = 0.072;
			h = 0.072;
			action = "MenuAction = 103";
		};
		class WF_Con4: RscClickableText {
			idc = 12008;
			text = "\CA\warfare2\Images\con_aircraft.paa";
			x = 0.725;
			y = 0.05;
			w = 0.072;
			h = 0.072;
			action = "MenuAction = 104";
		};
		class WF_Con7: RscClickableText {
			idc = 12021;
			text = "\CA\warfare2\Images\con_airport.paa";
			x = 0.795;
			y = 0.05;
			w = 0.072;
			h = 0.072;
			action = "MenuAction = 106";
		};
		class WF_Con5: RscClickableText {
			idc = 12020;
			text = "Client\Images\con_depot.paa";
			x = 0.865;
			y = 0.05;
			w = 0.072;
			h = 0.072;
			action = "MenuAction = 105";
		};
		class CA_Portrait: RscPicture {
			idc = 12009;
			style = 0x30+0x800;
			text = "";
			x = 0.043;
			y = 0.663641;
			w = 0.15;
			h = 0.15;
		};
		class CA_Price: CA_Label {
			idc = 12010;
			text = "$STR_WF_Price";
			x = 0.2;
			y = 0.69;
			sizeEx = 0.025;
		};
		class WF_Lock: RscClickableText {
			idc = 12023;
			text = "Client\Images\i_lock.paa";
			color[] = {1,1,1,0.75};
			x = 0.34;
			y = 0.125;
			w = 0.04;
			h = 0.04;
			tooltip = $STR_WF_Tooltips_Buy_Locked;
			action = "MenuAction = 401";
		};
		class WF_Driver: RscClickableText {
			idc = 12012;
			text = "\CA\ui\data\i_driver_ca.paa";
			color[] = {1,1,1,0.75};
			x = 0.38;
			y = 0.125;
			w = 0.04;
			h = 0.04;
			action = "MenuAction = 201";
		};
		class WF_Gunner: RscClickableText {
			idc = 12013;
			text = "\CA\ui\data\i_gunner_ca.paa";
			color[] = {1,1,1,0.75};
			x = 0.42;
			y = 0.125;
			w = 0.04;
			h = 0.04;
			action = "MenuAction = 202";
		};
		class WF_Commander: RscClickableText {
			idc = 12014;
			text = "\CA\ui\data\i_commander_ca.paa";
			color[] = {1,1,1,0.75};
			x = 0.46;
			y = 0.125;
			w = 0.04;
			h = 0.04;
			action = "MenuAction = 203";
		};
		class WF_Extra: RscClickableText {
			idc = 12041;
			text = "Client\Images\i_extra.paa";
			color[] = {1,1,1,0.75};
			x = 0.3;
			y = 0.125;
			w = 0.04;
			h = 0.04;
			tooltip = $STR_WF_Tooltips_Buy_Extra;
			action = "MenuAction = 204";
		};
		class WF_MiniMap : RscMapControl {
			IDC = 12015;
			ShowCountourInterval = 1;
			x = 0.5;
			y = 0.165;
			w = 0.454;
			h = 0.452;
		};
		class CA_Label_Factory: CA_Label {
			idc = 12016;
			text = $STR_WF_Factory;
			x = 0.5;
			y = 0.127;
			colorText[] = subcolor1;
			SizeEx = 0.03;
		};
		class CA_Combo_Factory: RscCombo {
			idc = 12018;
			x = 0.65;
			w = 0.3;
			y = 0.127;
			onLBSelChanged = "MenuAction = 301";
		};
		class CA_Cash_Label: CA_Label {
			idc = 12019;
			text = "";
			x = 0.756;
			y = 0.01;
		};
		class CA_Details: RscStructuredText {
			idc = 12022;
			size = 0.0232;
			x = 0.5;
			y = 0.663641;
			h = 0.225;
			w = 0.465;
		};
		class CA_Queu_Label: CA_Label {
			idc = 12024;
			text = '';
			x = 0.5;
			y = 0.01;
		};
		class CA_Faction: CA_Label {
			idc = 12025;
			text = "";
			x = 0.105;
			y = 0.054;
			colorText[] = subcolor1;
			SizeEx = 0.03;
		};
		class CA_Combo_Faction: RscCombo {
			idc = 12026;
			x = 0.234;
			w = 0.2;
			y = 0.054;
			onLBSelChanged = "MenuAction = 303";
		};
		/* Labels */
		class CA_Faction_Label: CA_Label {
			idc = 12027;
			text = $STR_WF_Faction;
			x = 0.2;
			y = 0.663641;
			sizeEx = 0.025;
		};
		class CA_Time_Label: CA_Label {
			idc = 12028;
			text = $STR_WF_Time;
			x = 0.2;
			y = 0.716359;
			sizeEx = 0.025;
		};
		class CA_Skill_Label: CA_Label {
			idc = 12029;
			text = $STR_WF_Skill;
			x = 0.2;
			y = 0.742718;
			sizeEx = 0.025;
		};
		class CA_TransportCapacity_Label: CA_Label {
			idc = 12030;
			text = $STR_WF_Transport_Cability;
			x = 0.2;
			y = 0.769077;
			sizeEx = 0.025;
		};
		class CA_MaxSpeed_Label: CA_Label {
			idc = 12031;
			text = $STR_WF_MaxSpeed;
			x = 0.2;
			y = 0.795436;
			sizeEx = 0.025;
		};
		class CA_Armor_Label: CA_Label {
			idc = 12032;
			text = $STR_WF_Armor;
			x = 0.2;
			y = 0.821795;
			sizeEx = 0.025;
		};
		/* Values */
		class CA_Faction_Value: CA_Label {
			idc = 12033;
			text = "";
			x = 0.3;
			y = 0.663641;
			w = 0.19;
			sizeEx = 0.025;
			style = 1;
		};
		class CA_Price_Value: CA_Faction_Value {
			idc = 12034;
			text = "";
			y = 0.69;
		};
		class CA_Time_Value: CA_Faction_Value {
			idc = 12035;
			text = "";
			y = 0.716359;
		};
		class CA_Skill_Value: CA_Faction_Value {
			idc = 12036;
			text = "";
			y = 0.742718;
		};
		class CA_TransportCapacity_Value: CA_Faction_Value {
			idc = 12037;
			text = "";
			y = 0.769077;
		};
		class CA_MaxSpeed_Value: CA_Faction_Value {
			idc = 12038;
			text = "";
			y = 0.795436;
		};
		class CA_Armor_Value: CA_Faction_Value {
			idc = 12039;
			text = "";
			y = 0.821795;
		};
		/* Controls */
		class CA_Unit_Label: CA_Label {
			idc = 12040;
			text = $STR_WF_Unit_Information;
			y = 0.6225;
			colorText[] = subcolor1;
		};
	};
};

//--- Command Menu.
class WF_CommandMenu {
	movingEnable = 1;
	idd = 13000;
	onLoad = "ExecVM ""Client\GUI\GUI_CommandMenu.sqf""";
	
	class controlsBackground {
		class Mainback : RscPicture {
			x = 0.015;
			y = 0.17;
			w = 0.627451;
			h = 0.836601;
			moving = 1;
			text = "\ca\ui\data\ui_mainmenu_background_ca.paa";
		};
	};
	class controls {
		class Button_A: RscShortcutButtonMain
		{
			idc = 13001;
			x = 0.02;
			y = 0.255;
			text = $STR_WF_Commandteam;
			action = "MenuAction = 1";
		};
		class Button_B: Button_A
		{
			idc = 13002;
			y = 0.355;
			text = $STR_WF_SpecialMenu;
			action = "MenuAction = 2";
		};		
		class Button_C: Button_A
		{
			idc = 13003;
			y = 0.455;
			text = $STR_WF_Upgrade_Menu;
			action = "MenuAction = 3";
		};
		class Button_D: Button_A
		{
			idc = 13004;
			y = 0.555;
			text = $STR_WF_Commander_Menu;
			action = "MenuAction = 4";
		};
		class Button_E: Button_A
		{
			idc = 13005;
			y = 0.655;
			text = $STR_WF_SupportMenu;
			action = "MenuAction = 5";
		};
		class Label: RscText {
			idc = 13006;
			text = $STR_WF_CommandMenu;
			x = 0.04;
			y = 0.205;
		};
		class CA_Diff_B_Back : RscShortcutButton {
			idc = 13007;
			shortcuts[] = {0x00050000 + 1};
			default = 0;
			x = 0.14;
			y = 0.7625;
			text = $STR_DISP_CLOSE;
			action = "closeDialog 0;";
		};
	};
};

//--- Team Orders.
class RscOrderMenu {
	movingEnable = 1;
	idd = 14000;
	onLoad = "_this ExecVM 'Client\GUI\GUI_TeamOrders.sqf'";
	
	class controlsBackground {
		class Mainback : RscPicture {
			x = 0.04;
			y = 0.01;
			w = 1.25;
			h = 1.67;
			moving = 1;
			text = "\ca\ui\data\igui_background_buy_units_ca.paa";
		};
	};
	
	class controls {
		class CA_Diff_B_Back : RscIGUIShortcutButton {
			idc = 14001;
			x = 0.17 + 0.2 * 3;
			y = 0.897;
			w = 0.185;
			h = 0.052;
			text = $STR_DISP_CLOSE;
			action = "closeDialog 0";
		};
		class WF_MiniMap : RscMapControl {
			IDC = 14002;
			ShowCountourInterval = 1;
			x = 0.5;
			y = 0.165;
			w = 0.454;
			h = 0.452;

			onMouseMoving = "mouseX = (_this Select 1);mouseY = (_this Select 2)";
			onMouseButtonDown = "mouseButtonDown = _this Select 1";
			onMouseButtonUp = "mouseButtonUp = _this Select 1";
		};
		class CA_Label: RscText {
			idc = 14003;
			text = $STR_WF_Commandteam;
			x = 0.047634;
			y = 0.01;
			colorText[] = subcolor1;
			SizeEx = 0.03;
		};
		class CA_Property_Label: CA_Label {
			idc = 14004;
			text = $STR_WF_Property;
			x = 0.05;
			y = 0.62;
		};
		class CA_TakeTowns: RscIGUIShortcutButton {
			idc = 14005;
			x = 0.52;
			y = 0.66;
			w = 0.4;
			text = $STR_WF_TakeTowns;
			action = "MenuAction = 101";
		};
		class CA_Move: RscIGUIShortcutButton {
			idc = 14006;
			x = 0.52;
			y = 0.70;
			w = 0.4;
			text = $STR_WF_Move;
			action = "MenuAction = 102";
		};
		class CA_Patrol: RscIGUIShortcutButton {
			idc = 14007;
			x = 0.52;
			y = 0.74;
			w = 0.4;
			text = $STR_WF_Patrol;
			action = "MenuAction = 103";
		};
		class CA_Defend: RscIGUIShortcutButton {
			idc = 14008;
			x = 0.52;
			y = 0.78;
			w = 0.4;
			text = $STR_WF_Defense;
			action = "MenuAction = 104";
		};
		class CA_Sell: RscIGUIShortcutButton {
			idc = 14029;
			x = 0.52;
			y = 0.82;
			w = 0.4;
			text = $STR_WF_SellStructure;
			action = "MenuAction = 105";
		};
		class CA_BuyType_Label: CA_Label {
			idc = 14009;
			text = $STR_WF_BuyType;
			x = 0.05;
			y = 0.4;
			w = 0.17;
		};
		class CA_BuyType_Combo: RscCombo {
			idc = 14010;
			x = 0.243;
			w = 0.25;
			y = 0.4;
		};
		class CA_Respawn : CA_Diff_B_Back {
			idc = 14011;
			x = 0.17 + 0.2 * 2;
			text = $STR_WF_Respawn;
			action = "MenuAction = 201";
		};
		class CA_TeamList : RscListBox {
			idc = 14012;
			x = 0.043;
			y = 0.663;
			w = 0.45;
			h = 0.232;
			rowHeight = 0.0219091;
			sizeEx = 0.03;
			style = 0x20;//--- MultiSelect LB.
			
			onLBSelChanged = "MenuAction = 1";
			onLBDblClick = "MenuAction = 2";
		};	
		class CA_Mission_Type: CA_Label {
			idc = 14013;
			text = "";
			x = 0.5;
			y = 0.128;
		};
		class CA_AutoAIOn : CA_Diff_B_Back {
			idc = 14014;
			x = 0.04;
			w = 0.235;
			text = $STR_WF_AutoAI;
			action = "MenuAction = 301";
		};
		class CA_AutoAIOff : CA_Diff_B_Back {
			idc = 14015;
			x = 0.09 + 0.2* 1;
			w = 0.235;
			text = $STR_WF_AutoAIOff;
			action = "MenuAction = 301";
		};		
		class CA_SetBuy : RscIGUIShortcutButton {
			idc = 14016;
			x = 0.06;
			y = 0.44;
			w = 0.42;
			text = $STR_WF_SetBuyType;
			action = "MenuAction = 302";
		};
		class CA_Behavior_Combo: RscCombo {
			idc = 14017;
			x = 0.243;
			w = 0.25;
			y = 0.18;
		};
		class CA_Combat_Combo: RscCombo {
			idc = 14018;
			x = 0.243;
			w = 0.25;
			y = 0.22;
		};
		class CA_Formation_Combo: RscCombo {
			idc = 14019;
			x = 0.243;
			w = 0.25;
			y = 0.26;
		};
		class CA_Speed_Combo: RscCombo {
			idc = 14020;
			x = 0.243;
			w = 0.25;
			y = 0.30;
		};
		class CA_Behavior_Label: CA_Label {
			idc = 14021;
			text = $STR_WF_Behavior;
			x = 0.05;
			y = 0.18;
			w = 0.17;
		};
		class CA_Combat_Label: CA_Label {
			idc = 14022;
			text = $STR_WF_CombatMode;
			x = 0.05;
			y = 0.22;
			w = 0.17;
		};
		class CA_Formation_Label: CA_Label {
			idc = 14031;
			text = $STR_WF_Formation;
			x = 0.05;
			y = 0.26;
			w = 0.17;
		};
		class CA_Speed_Label: CA_Label {
			idc = 14023;
			text = $STR_WF_Speed;
			x = 0.05;
			y = 0.30;
			w = 0.17;
		};
		class CA_SetToTeam : RscIGUIShortcutButton {
			idc = 14024;
			x = 0.06;
			y = 0.34;
			w = 0.42;
			text = $STR_WF_SetTeamProperties;
			action = "MenuAction = 303";
		};
		class CA_Respawn_Combo: RscCombo {
			idc = 14025;
			x = 0.243;
			w = 0.25;
			y = 0.5;
			
			onLBSelChanged = "MenuAction = 305";
		};
		class CA_Respawn_Label: CA_Label {
			idc = 14026;
			text = $STR_WF_Respawn;
			x = 0.05;
			y = 0.5;
			w = 0.17;
		};
		class CA_SetRespawn : RscIGUIShortcutButton {
			idc = 14027;
			x = 0.06;
			y = 0.54;
			w = 0.42;
			text = $STR_WF_SetRespawn;
			action = "MenuAction = 304";
		};
		class CA_Funds_Label: CA_Label {
			idc = 14028;
			text = '';
			x = 0.25;
			y = 0.62;
		};
		class CA_Tab_Label: CA_Label {
			idc = 14030;
			text = $STR_WF_TeamsSetting;
			x = 0.135;
			y = 0.125;
		};
		class CA_SetTask : RscIGUIShortcutButton {
			idc = 14032;
			x = 0.06;
			y = 0.26;
			w = 0.42;
			text = $STR_WF_TaskTO_Set;
			action = "MenuAction = 306";
		};
		//--- HQ Team units details.
		class CA_UnitsDetailList : RscListBoxA {
			idc = 14041;
			x = 0.043;
			y = 0.167676;
			w = 0.45;
			h = 0.4;
			columns[] = {0.01, 0.19};
			drawSideArrows = 0;
			idcRight = -1;
			idcLeft = -1;
			rowHeight = 0.05;
			sizeEx = 0.023;
			
			onLBSelChanged = "MenuAction = 401";
			onLBDblClick = "MenuAction = 3";
		};	
		class CA_FUnflip : RscIGUIShortcutButton {
			idc = 14042;
			x = 0.043;
			y = 0.572;
			w = 0.22;
			text = $STR_WF_Unflip;
			action = "MenuAction = 402";
		};	
		class CA_FDisband : RscIGUIShortcutButton {
			idc = 14043;
			x = 0.273;
			y = 0.572;
			w = 0.22;
			text = $STR_WF_Disband;
			action = "MenuAction = 403";
		};		
		class WF_Con1: RscClickableText {
			idc = 14500;
			text = "\CA\warfare2\Images\con_barracks.paa";
			x = 0.10;
			y = 0.05;
			w = 0.072;
			h = 0.072;
			action = "MenuAction = 601";
		};
		class WF_Con2: RscClickableText {
			idc = 14501;
			text = "Client\Images\con_task.paa";
			x = 0.17;
			y = 0.05;
			w = 0.072;
			h = 0.072;
			action = "MenuAction = 602";
		};
		class WF_Con3: RscClickableText {
			idc = 14502;
			text = "\CA\warfare2\Images\con_hq.paa";
			x = 0.24;
			y = 0.05;
			w = 0.072;
			h = 0.072;
			action = "MenuAction = 603";
		};
		//--- Separators.
		class LineTRH1 : RscText {
			idc = 14900;
			x = 0.04;
			y = 0.163;
			w = 0.4565;
			h = 0.002;
			text = "";
			colorBackground[] = {0.543, 0.5742, 0.4102, 1.0};
		};
		class LineTRH2 : LineTRH1 {
			idc = 14901;
			x = 0.04;
			y = 0.485;
			w = 0.4565;
			h = 0.002;
		};
		class LineTRH3 : LineTRH1 {
			idc = 14902;
			x = 0.04;
			y = 0.385;
			w = 0.4565;
			h = 0.002;
		};
		class LineTRH4 : LineTRH1 {
			idc = 14903;
			x = 0.04;
			y = 0.617;
			w = 0.4565;
			h = 0.002;
		};
	};
};

//--- Respawn Menu.
class RscRespawnMenu {
	movingEnable = 1;
	idd = 15000;
	onLoad = "_this ExecVM ""Client\GUI\GUI_Respawn.sqf""";
	
	class controlsBackground {
		class Mainback : RscPicture {
			x = 0.185;
			y = 0.17;
			w = 1.2549;
			h = 0.836601;
			moving = 1;
			text = "\ca\ui\data\ui_difficulty_background_ca.paa";
		};
	};
	
	class controls {
		class WF_MiniMap : RscMapControl {
			IDC = 15001;
			ShowCountourInterval = 1;
			x = 0.191;
			y = 0.254;
			w = 0.7133;
			h = 0.509;

			onMouseMoving = "mouseX = (_this Select 1);mouseY = (_this Select 2)";
			onMouseButtonDown = "mouseButtonDown = _this Select 1";
			onMouseButtonUp = "mouseButtonUp = _this Select 1";
		};
		class CA_Label: RscText {
			idc = 15002;
			text = $STR_WF_RespawnMenu;
			x = 0.2;
			w = 0.7;
			y = 0.205;
		};
		class CA_Status: RscText {
			idc = 15003;
			text = "";
			x = 0.2;
			w = 0.7;
			y = 0.775;
			sizeEx = 0.03221;
			shadow = 2;
		};
		class CA_Gear_Button: RscButton {
			idc = 15004;
			x = 0.85;
			w = 0.05;
			y = 0.205;
			text = "";
			shadow = 2;
			sizeEx = 0.03;
			
			tooltip = $STR_WF_Tooltips_RespawnDefault;
			onButtonClick = "WFBE_RespawnDefaultGear = if (WFBE_RespawnDefaultGear) then {false} else {true};";
		};
		class CA_PreEnv_Button: CA_Gear_Button {
			idc = 15005;
			x = 0.79;
			
			colorBackground[] = {0, 0.537, 1, 0.5};
			colorBackgroundActive[] = {0, 0.537, 1, 0.5};
			colorFocused[] = {0, 0.537, 1, 1};
			
			tooltip = $STR_WF_Tooltips_Preload;
			onButtonClick = "WFBE_EnablePreload = if (WFBE_EnablePreload) then {false} else {true};";
		};
	};
};

// ACE gear menu
class RscAceGear
{
	movingEnable=1;
	idd=16001;
	onLoad="ExecVM ""Client\GUI\GUI_GearAce.sqf""";
	class Filters
	{
		class All
		{
			name="All";
			mask=-1;
			image="\ca\ui\data\igui_gear_filter_1_ca.paa";
		};
		class Primary
		{
			name="Primary";
			mask=769;
			image="\ca\ui\data\igui_gear_filter_2_ca.paa";
		};
		class Secondary
		{
			name="Secondary";
			mask=516;
			image="\ca\ui\data\igui_gear_filter_3_ca.paa";
		};
		class HandGun
		{
			name="HandGun";
			mask=18;
			image="\ca\ui\data\igui_gear_filter_4_ca.paa";
		};
		class Items
		{
			name="Items";
			mask=135168;
			image="\ca\ui\data\igui_gear_filter_5_ca.paa";
		};
	};
	class ControlsBackground
	{
		class Mainback:RscPicture
		{
			idc=1005;
			x="(SafeZoneX + 0.01)";
			y="(SafeZoneY + 0.01)";
			w=1.1;
			h=1.14;
			moving=1;
			text="\x\ace\addons\sys_ruck\data\ui\ui_gear_background.paa";
		};
	};
	class controls
	{
		class Gear_Title:CA_IGUI_Title
		{
			idc=1001;
			x="(SafeZoneX + 0.02)";
			y="(SafeZoneY + 0.02)";
			text=$STR_WF_Purchase_Gear;
		};
		class ConClear : RscClickableText {
			style = 48 + 0x800;
			color[] = {1, 1, 1, 1};
			colorActive[] = subcolor1;
			idc = 3800;
			x="(SafeZoneX + 0.852)";
			y="(SafeZoneY + 0.02)";
			w = 0.032;
			h = 0.032;
			tooltip = $STR_WF_Tooltips_GearClear;
			text = "Client\Images\i_clear.paa";
			action = "WF_Logic setVariable ['WF_Gear_Action','clear']";
		};
		class ConReload : ConClear {
			idc = 3801;
			x="(SafeZoneX + 0.88)";
			tooltip = $STR_WF_Tooltips_GearReload;
			text = "Client\Images\i_reload.paa";
			action = "WF_Logic setVariable ['WF_Gear_Action','reload']";
		};
		class ConBackpack : ConClear {
			idc = 3802;
			x="(SafeZoneX + 0.824)";
			tooltip = $STR_WF_Tooltips_Backpack;
			text = "Client\Images\i_backpack.paa";
			action = "WF_Logic setVariable ['WF_Gear_Action','backpack']";
		};
		class CA_Filter_Icon:RscPicture
		{
			idc=148;
			style="0x30+ 0x800";
			x="(SafeZoneX + 0.025)";
			y="(SafeZoneY + 0.09)- 0.001";
			w=0.458;
			h=0.075;
			text="\ca\ui\data\igui_gear_filter_1_ca.paa";
		};
		class CA_Filter_Left_Icon:RscClickableText
		{
			idc=1301;
			style="0x30+ 0x800";
			x="(SafeZoneX + 0.025)+ 0.01";
			y="(SafeZoneY + 0.09)";
			w=0.036;
			h=0.075;
			text="\ca\ui\data\arrow_left_ca.paa";
			action="WF_Logic setVariable [ 'lbMainAction', 'filterMinus' ]";
		};
		class CA_Filter_Right_Icon:RscClickableText
		{
			idc=1302;
			style="0x30+ 0x800";
			x="(SafeZoneX + 0.025)+ 0.413";
			y="(SafeZoneY + 0.09)";
			w=0.036;
			h=0.075;
			text="\ca\ui\data\arrow_right_ca.paa";
			action="WF_Logic setVariable [ 'lbMainAction', 'filterPlus' ]";
		};
		class CA_Filter_Icon1:RscButton
		{
			idc=149;
			colorText[]={1,1,1,0};
			colorDisabled[]={1,1,1,0};
			colorBackground[]={1,1,1,0};
			colorBackgroundDisabled[]={1,1,1,0};
			colorBackgroundActive[]={1,1,1,0};
			colorShadow[]={1,1,1,0};
			colorFocused[]={1,1,1,0};
			x="(SafeZoneX + 0.025)+ 0.059";
			y="(SafeZoneY + 0.02)";
			w=0.341;
			h=0.075;
			text="";
		};
		class Unit_Title:RscText
		{
			idc=101;
			style="0x02";
			x="(SafeZoneX + 0.66)";
			y="(SafeZoneY + 0.09)";
			w=0.4;
		};
		class ACE_Unit_Arrow_Left:RscClickableText
		{
			idc=90110;
			style="0x30+ 0x800";
			colorBackground[]={0,0,0,1};
			x="(SafeZoneX + 0.66)- 0.030";
			y="(SafeZoneY + 0.09)";
			w=0.03;
			h=0.037;
			text="\ca\ui\data\arrow_left_ca.paa";
			action="WF_Logic setVariable [ 'lbMainAction', 'unitMinus' ]";
		};
		class ACE_Unit_Arrow_Right:RscClickableText
		{
			idc=90111;
			style="0x30+ 0x800";
			colorBackground[]={0,0,0,1};
			x="(SafeZoneX + 0.66)+ 0.4";
			y="(SafeZoneY + 0.09)";
			w=0.03;
			h=0.037;
			text="\ca\ui\data\arrow_right_ca.paa";
			action="WF_Logic setVariable [ 'lbMainAction', 'unitPlus' ]";
		};
		class Available_items_Text:RscText
		{
			idc=1100;
			x="(SafeZoneX + 0.025)+ 0.0033014";
			y="(SafeZoneY + 0.18)";
			w=0.389709;
			h=0.04;
			text=$STR_GEAR_ITEMS;
		};
		class CA_ItemName:Available_items_Text
		{
			idc=1101;
			x="(SafeZoneX + 0.025)+ 0.0016704";
			y="(SafeZoneY + 0.59)";
			h=0.04;
			text=$STR_GEAR_UNIT;
		};
		class CA_Item_Picture:RscPicture
		{
			idc=1104;
			style="0x30+ 0x800";
			x="(SafeZoneX + 0.465)";
			y="(SafeZoneY + 0.64)";
			w=0.156863;
			h=0.104575;
			text="";
		};
		class CA_CustomDescription:RscStructuredText
		{
			idc=1106;
			x="(SafeZoneX + 0.02)";
			y="(SafeZoneY + 0.64)";
			w=0.458;
			h=0.152;
			colorText[]={0.95,0.95,0.95,1};
			class Attributes
			{
				font="Zeppelin32";
				color="#F2F2F2";
				align="left";
				shadow=1;
			};
		};
		class ACE_Ruck_Items:RscText
		{
			idc=90000;
			x="(SafeZoneX + 0.025)+ 0.0033014";
			y="(SafeZoneY + 0.80)";
			w=0.389709;
			h=0.04;
			text=$STR_ACE_RUCK_ITEMS;
		};
		class MainList : RscListBoxA {
			idc = 3700;
			columns[] = {0.01, 0.25};
			drawSideArrows = 0;
			idcRight = -1;
			idcLeft = -1;
			x="(SafeZoneX + 0.025)";
			y="(SafeZoneY + 0.22)";
			w=0.42;
			h=0.36;
			
			onLBSelChanged = "WF_Logic setVariable ['lbChange',true]";
			onLBDblClick = "WF_Logic setVariable ['lbMainAction','addMainItem']";
		};
		class SecondaryList : RscListBoxA {
			idc = 3701;
			columns[] = {0.01, 0.25};
			drawSideArrows = 0;
			idcRight = -1;
			idcLeft = -1;
			x="(SafeZoneX + 0.025)";
			y="(SafeZoneY + 0.84)";
			w=0.42;
			h=0.25;
			onLBDblClick = "WF_Logic setVariable ['lbMainAction','addMagazine']";
		};
		class ACE_Item_Weight:RscText
		{
			idc=90005;
			x="(SafeZoneX + 0.485)";
			y="(SafeZoneY + 0.80)";
			w=0.2;
			h=0.04;
			text="";
		};
		class ACE_Item_Volume:RscText
		{
			idc=90007;
			x="(SafeZoneX + 0.485)";
			y="(SafeZoneY + 0.84)";
			w=0.2;
			h=0.04;
			text="";
		};
		class ACE_Total_Weight:RscText
		{
			idc=90009;
			x="(SafeZoneX + 0.40)";
			y="(SafeZoneY + 0.02)";
			w=0.3;
			h=0.04;
			text="";
		};
		class ACE_Total_Volume:RscText
		{
			idc=90011;
			x="(SafeZoneX + 0.025)+ 0.15";
			y="(SafeZoneY + 0.80)";
			w=0.35;
			h=0.04;
			text="";
		};
		class ACE_ButtonWOBPrimary:RscIGUIShortcutButton
		{
			idc=90100;
			w=0.15;
			x="(SafeZoneX + 0.51)";
			y="(SafeZoneY + 0.20)";
			text=$STR_ACE_ON_BACK;
			onButtonClick="WF_Logic setVariable ['WF_Gear_Action','primary_onback']";
		};
		class ACE_ButtonWOBSecondary:ACE_ButtonWOBPrimary
		{
			idc=90101;
			y="(SafeZoneY + 0.35)";
			text=$STR_ACE_ON_BACK;
			onButtonClick="WF_Logic setVariable ['WF_Gear_Action','secondary_onback']";
		};
		class G_GearItems:RscControlsGroup
		{
			idc=160;
			x="(SafeZoneX + 0.13 + 0.502)";
			y="(SafeZoneY + 0.05 + 0.09 )";
			w=0.463;
			h=0.776;
			class Controls
			{
				class CA_Gear_slot_primary:RscClickableText
				{
					idc=107;
					x=0;
					y=0;
					w=0.286;
					h=0.15;
					style="0x30+ 0x800";
					soundDoubleClick[]={"",0.1,1};
					color[]={1,1,1,1};
					colorBackground[]={0.6,0.8392,0.4706,1};
					colorBackgroundSelected[]={0.6,0.8392,0.4706,1};
					colorFocused[]={0,0,0,0};
					colorActive[]={1,1,1,1};
					text="";
					action="WF_Logic setVariable ['InventoryClick',107]";
				};
				class CA_Gear_slot_secondary:CA_Gear_slot_primary
				{
					idc=108;
					y="(0.244 - 0.09)";
					action="WF_Logic setVariable ['InventoryClick',108]";
				};
				class ACE_Gear_slot_WOB:CA_Gear_slot_primary
				{
					idc=90020;
					y="(0.398 - 0.09)";
					color[]={1,1,1,0.5};
					colorFocused[]={1,1,1,1};
					action="WF_Logic setVariable ['InventoryClick',90020]";
				};
				class CA_Gear_slot_item1:CA_Gear_slot_primary
				{
					idc=109;
					x="(0.79 - 0.502)";
					y=0;
					w=0.055;
					h=0.074;
					action="WF_Logic setVariable ['InventoryClick',109]";
				};
				class CA_Gear_slot_item2:CA_Gear_slot_item1
				{
					idc=110;
					x="(0.847 - 0.502)";
					y=0;
					action="WF_Logic setVariable ['InventoryClick',110]";
				};
				class CA_Gear_slot_item3:CA_Gear_slot_item1
				{
					idc=111;
					x="(0.904366 - 0.502)";
					y=0;
					action="WF_Logic setVariable ['InventoryClick',111]";
				};
				class CA_Gear_slot_item4:CA_Gear_slot_item1
				{
					idc=112;
					x="(0.79 - 0.502)";
					y="(0.167 - 0.09)";
					action="WF_Logic setVariable ['InventoryClick',112]";
				};
				class CA_Gear_slot_item5:CA_Gear_slot_item1
				{
					idc=113;
					x="(0.847 - 0.502)";
					y="(0.167 - 0.09)";
					action="WF_Logic setVariable ['InventoryClick',113]";
				};
				class CA_Gear_slot_item6:CA_Gear_slot_item1
				{
					idc=114;
					x="(0.904366 - 0.502)";
					y="(0.167 - 0.09)";
					action="WF_Logic setVariable ['InventoryClick',114]";
				};
				class CA_Gear_slot_item7:CA_Gear_slot_item1
				{
					idc=115;
					x="(0.79 - 0.502)";
					y="(0.244 - 0.09)";
					action="WF_Logic setVariable ['InventoryClick',115]";
				};
				class CA_Gear_slot_item8:CA_Gear_slot_item7
				{
					idc=116;
					x="(0.847 - 0.502)";
					y="(0.244 - 0.09)";
					action="WF_Logic setVariable ['InventoryClick',116]";
				};
				class CA_Gear_slot_item9:CA_Gear_slot_item7
				{
					idc=117;
					x="(0.904366 - 0.502)";
					y="(0.244 - 0.09)";
					action="WF_Logic setVariable ['InventoryClick',117]";
				};
				class CA_Gear_slot_item10:CA_Gear_slot_item7
				{
					idc=118;
					x="(0.79 - 0.502)";
					y="(0.321 - 0.09)";
					action="WF_Logic setVariable ['InventoryClick',118]";
				};
				class CA_Gear_slot_item11:CA_Gear_slot_item7
				{
					idc=119;
					x="(0.847 - 0.502)";
					y="(0.321 - 0.09)";
					action="WF_Logic setVariable ['InventoryClick',119]";
				};
				class CA_Gear_slot_item12:CA_Gear_slot_item7
				{
					idc=120;
					x="(0.904366 - 0.502)";
					y="(0.321 - 0.09)";
					action="WF_Logic setVariable ['InventoryClick',120]";
				};
				class CA_Gear_slot_handgun:CA_Gear_slot_primary
				{
					idc=121;
					x=0;
					y="(0.551 - 0.09)";
					w=0.113;
					h=0.15;
					action="WF_Logic setVariable ['InventoryClick',121]";
				};
				class CA_Gear_slot_handgun_item1:CA_Gear_slot_item1
				{
					idc=122;
					x="(0.617 - 0.502)";
					y="(0.551 - 0.09)";
					w=0.055;
					h=0.074;
					action="WF_Logic setVariable ['InventoryClick',122]";
				};
				class CA_Gear_slot_handgun_item2:CA_Gear_slot_handgun_item1
				{
					idc=123;
					x="(0.674 - 0.502)";
					y="(0.551 - 0.09)";
					action="WF_Logic setVariable ['InventoryClick',123]";
				};
				class CA_Gear_slot_handgun_item3:CA_Gear_slot_handgun_item1
				{
					idc=124;
					x="(0.733 - 0.502)";
					y="(0.551 - 0.09)";
					action="WF_Logic setVariable ['InventoryClick',124]";
				};
				class CA_Gear_slot_handgun_item4:CA_Gear_slot_handgun_item1
				{
					idc=125;
					x="(0.79 - 0.502)";
					y="(0.551 - 0.09)";
					action="WF_Logic setVariable ['InventoryClick',125]";
				};
				class CA_Gear_slot_handgun_item5:CA_Gear_slot_handgun_item1
				{
					idc=126;
					x="(0.617 - 0.502)";
					y="(0.628 - 0.09)";
					action="WF_Logic setVariable ['InventoryClick',126]";
				};
				class CA_Gear_slot_handgun_item6:CA_Gear_slot_handgun_item5
				{
					idc=127;
					x="(0.674 - 0.502)";
					y="(0.628 - 0.09)";
					action="WF_Logic setVariable ['InventoryClick',127]";
				};
				class CA_Gear_slot_handgun_item7:CA_Gear_slot_handgun_item5
				{
					idc=128;
					x="(0.733 - 0.502)";
					y="(0.628 - 0.09)";
					action="WF_Logic setVariable ['InventoryClick',128]";
				};
				class CA_Gear_slot_handgun_item8:CA_Gear_slot_handgun_item5
				{
					idc=129;
					x="(0.79 - 0.502)";
					y="(0.628 - 0.09)";
					action="WF_Logic setVariable ['InventoryClick',129]";
				};
				class CA_Gear_slot_special1:CA_Gear_slot_item1
				{
					idc=130;
					x="(0.847 - 0.502)";
					y="(0.551 - 0.09)";
					w=0.113;
					h=0.15;
					action="WF_Logic setVariable ['InventoryClick',130]";
				};
				class CA_Gear_slot_special2:CA_Gear_slot_special1
				{
					idc=131;
					x="(0.847 - 0.502)";
					y="(0.705 - 0.09)";
					action="WF_Logic setVariable ['InventoryClick',131]";
				};
				class CA_Gear_slot_inventory1:CA_Gear_slot_special1
				{
					idc=134;
					x=0;
					y="(0.705 - 0.09)";
					w=0.055;
					h=0.074;
					action="WF_Logic setVariable ['InventoryClick',134]";
				};
				class CA_Gear_slot_inventory2:CA_Gear_slot_inventory1
				{
					idc=135;
					x="(0.56 - 0.502)";
					y="(0.705 - 0.09)";
					action="WF_Logic setVariable ['InventoryClick',135]";
				};
				class CA_Gear_slot_inventory3:CA_Gear_slot_inventory1
				{
					idc=136;
					x="(0.617 - 0.502)";
					y="(0.705 - 0.09)";
					action="WF_Logic setVariable ['InventoryClick',136]";
				};
				class CA_Gear_slot_inventory4:CA_Gear_slot_inventory1
				{
					idc=137;
					x="(0.674 - 0.502)";
					y="(0.705 - 0.09)";
					action="WF_Logic setVariable ['InventoryClick',137]";
				};
				class CA_Gear_slot_inventory5:CA_Gear_slot_inventory1
				{
					idc=138;
					x="(0.733 - 0.502)";
					y="(0.705 - 0.09)";
					action="WF_Logic setVariable ['InventoryClick',138]";
				};
				class CA_Gear_slot_inventory6:CA_Gear_slot_inventory1
				{
					idc=139;
					x="(0.79 - 0.502)";
					y="(0.705 - 0.09)";
					action="WF_Logic setVariable ['InventoryClick',139]";
				};
				class CA_Gear_slot_inventory7:CA_Gear_slot_inventory1
				{
					idc=140;
					x=0;
					y="(0.782 - 0.09)";
					action="WF_Logic setVariable ['InventoryClick',140]";
				};
				class CA_Gear_slot_inventory8:CA_Gear_slot_inventory7
				{
					idc=141;
					x="(0.56 - 0.502)";
					y="(0.782 - 0.09)";
					action="WF_Logic setVariable ['InventoryClick',141]";
				};
				class CA_Gear_slot_inventory9:CA_Gear_slot_inventory7
				{
					idc=142;
					x="(0.617 - 0.502)";
					y="(0.782 - 0.09)";
					action="WF_Logic setVariable ['InventoryClick',142]";
				};
				class CA_Gear_slot_inventory10:CA_Gear_slot_inventory7
				{
					idc=143;
					x="(0.674 - 0.502)";
					y="(0.782 - 0.09)";
					action="WF_Logic setVariable ['InventoryClick',143]";
				};
				class CA_Gear_slot_inventory11:CA_Gear_slot_inventory7
				{
					idc=144;
					x="(0.733 - 0.502)";
					y="(0.782 - 0.09)";
					action="WF_Logic setVariable ['InventoryClick',144]";
				};
				class CA_Gear_slot_inventory12:CA_Gear_slot_inventory7
				{
					idc=145;
					x="(0.79 - 0.502)";
					y="(0.782 - 0.09)";
					action="WF_Logic setVariable ['InventoryClick',145]";
				};
				class CA_Gear_slot_inventory13:CA_Gear_slot_inventory7
				{
					idc=1122;
					x=0.1;
					y=0.1;
				};
				class ACE_IFAK_1P:RscPicture
				{
					idc=90104;
					style="0x30+ 0x800";
					x="(0.79 - 0.502)";
					y="(0.398 - 0.09)+ 0.05";
					w=0.043;
					h=0.043;
					text="";
				};
				class ACE_IFAK_2P:RscPicture
				{
					idc=90105;
					style="0x30+ 0x800";
					x="(0.79 - 0.502)+ 0.001+ 0.043";
					y="(0.398 - 0.09)+ 0.05";
					w=0.043;
					h=0.043;
					text="";
				};
				class ACE_IFAK_3P:RscPicture
				{
					idc=90106;
					style="0x30+ 0x800";
					x="(0.79 - 0.502)+ (0.001+ 0.043) * 2";
					y="(0.398 - 0.09)+ 0.05";
					w=0.043;
					h=0.043;
					text="";
				};
				class ACE_IFAK_1C:RscText
				{
					idc=90107;
					style="0x02";
					x="(0.79 - 0.502)";
					y="(0.398 - 0.09)+ 0.05* 2";
					w=0.043;
					h="0.043* 0.7";
					text="";
				};
				class ACE_IFAK_2C:RscText
				{
					idc=90108;
					style="0x02";
					x="(0.79 - 0.502)+ 0.001+ 0.043";
					y="(0.398 - 0.09)+ 0.05* 2";
					w=0.043;
					h="0.043* 0.7";
					text="";
				};
				class ACE_IFAK_3C:RscText
				{
					idc=90109;
					style="0x02";
					x="(0.79 - 0.502)+ (0.001+ 0.043) * 2";
					y="(0.398 - 0.09)+ 0.05* 2";
					w=0.043;
					h="0.043* 0.7";
					text="";
				};
			};
		};
		class Break_7:RscLineBreak
		{
		};
		class ButtonClose:RscIGUIShortcutButton
		{
			idc=2;
			shortcuts[]={"0x00050000+1"};
			x="(SafeZoneX + 0.0392216 )";
			y="(SafeZoneY + 1.1 )";
			text=$STR_DISP_CLOSE;
		};
		class ButtonBuy:RscIGUIShortcutButton
		{
			idc=148;
			shortcuts[]={"0x00050000+3"};
			x="(SafeZoneX + 0.333336 )";
			y="(SafeZoneY + 1.1 )";
			text=$STR_WF_Purchase;
			onButtonClick="WF_Logic setVariable ['lbMainAction','buy']";
		};
		class ItemCost:RscText
		{
			idc=152;
			x="(SafeZoneX + 0.77 )";
			y="(SafeZoneY + 1.1 )";
			width=0.3;
			text="";
		};
		class PlayerFunds:ItemCost
		{
			idc=150;
			x="(SafeZoneX + 0.52 )";
		};
		class PlayerRespawnCost:ItemCost
		{
			idc=151;
			y="(SafeZoneY + 1.04 )";
			width=0.3;
			text="";
		};
	};
};

//--- Gear Menu.
class RscGear {
	movingEnable = 1;
	idd = 16000;
	onLoad = gearmenu;
	
	class controlsBackground {
		class Mainback : RscPicture {
			x = 0.04;
			y = 0.01;
			w = 1.2549;
			h = 1.6732;
			moving = 1;
			text = "\ca\ui\data\igui_background_gear_ca.paa";
		};
	};
	
	class controls {
		//--- ArmA 2 WF Gear Menu Modified.
		class FilterButtonSidearm : RscClickableText {
			idc = 3400 + 4;
			style = 48 + 0x800;
			x = 0.325;
			y = 0.047;
			w = 0.086;
			h = 0.086;
			color[] = {1, 1, 1, 1};
			colorActive[] = subcolor1;
			text = "\CA\warfare2\Images\GearIconSidearm.paa";
			action = "WF_Logic setVariable ['filler','sidearm']";
		};
		
		class FilterButtonMisc : FilterButtonSidearm {
			idc = 3400 + 5;
			x = 0.375;
			text = "\CA\warfare2\Images\GearIconMisc.paa";
			action = "WF_Logic setVariable ['filler','misc']";
		};
		
		class FilterButtonSecondary : FilterButtonSidearm {
			idc = 3400 + 3;
			x = 0.266;
			text = "\CA\warfare2\Images\GearIconSecondary.paa";
			action = "WF_Logic setVariable ['filler','secondary']";
		};
		
		class FilterButtonPrimary : FilterButtonSidearm {
			idc = 3400 + 2;
			x = 0.193;
			text = "\CA\warfare2\Images\GearIconPrimary.paa";
			action = "WF_Logic setVariable ['filler','primary']";
		};
		
		class FilterButtonTemplate : FilterButtonSidearm {
			idc = 3400;
			x = 0.075;
			text = "\CA\warfare2\Images\GearIconTemplate.paa";
			action = "WF_Logic setVariable ['filler','template']";
		};
		
		class FilterButtonAll : FilterButtonTemplate {
			idc = 3400 + 1;
			x = 0.125;
			text = "\CA\warfare2\Images\GearIconAll.paa";
			action = "WF_Logic setVariable ['filler','all']";
		};
		class ConClear : FilterButtonTemplate {
			idc = 3800;
			x = 0.902;
			y = 0.014;
			w = 0.032;
			h = 0.032;
			tooltip = $STR_WF_Tooltips_GearClear;
			text = "Client\Images\i_clear.paa";
			action = "WF_Logic setVariable ['WF_Gear_Action','clear']";
		};
		class ConReload : ConClear {
			idc = 3801;
			x = 0.93;
			tooltip = $STR_WF_Tooltips_GearReload;
			text = "Client\Images\i_reload.paa";
			action = "WF_Logic setVariable ['WF_Gear_Action','reload']";
		};
		class ConBackpack : ConClear {
			idc = 3802;
			x = 0.874;
			tooltip = $STR_WF_Tooltips_Backpack;
			text = "Client\Images\i_backpack.paa";
			action = "WF_Logic setVariable ['WF_Gear_Action','backpack']";
		};
		class MainList : RscListBoxA {
			idc = 3700;
			columns[] = {0.01, 0.25};
			drawSideArrows = 0;
			idcRight = -1;
			idcLeft = -1;
			x = 0.043;
			y = 0.167676;
			w = 0.45;
			h = 0.444;
			
			onLBSelChanged = "WF_Logic setVariable ['lbChange',true]";
			onLBDblClick = "WF_Logic setVariable ['lbMainAction','addWeapon']";
		};
		class SecondaryList : RscListBoxA {
			idc = 3701;
			columns[] = {0.01, 0.25};
			drawSideArrows = 0;
			idcRight = -1;
			idcLeft = -1;
			x = 0.043;
			y = 0.66;
			w = 0.45;
			h = 0.24;
			
			onLBDblClick = "WF_Logic setVariable ['lbMainAction','addMagazine']";
		};	
		class PrimaryWeapon : RscClickableText {
			idc = 3500;
			x = 0.502;
			y = 0.244;
			w = 0.286;
			h = 0.15;
			style = 48 + 0x800;
			soundDoubleClick[] = {"", 0.1, 1};
			colorBackground[] = {0.6, 0.83, 0.47, 1};
			colorBackgroundSelected[] = {0.6, 0.83, 0.47, 1};
			colorFocused[] = {0, 0, 0, 0};
			color[] = {0.85, 0.85, 0.85, 1};
			colorText[] = {0.85, 0.85, 0.85, 1};
			colorActive[] = {1, 1, 1, 1};
			text = "\Ca\UI\Data\ui_gear_gun_gs.paa";
			action = "primClicked = true";
		};
		
		class SecondaryWeapon : PrimaryWeapon {
			idc = 3500 + 1;
			y = 0.398;
			text = "\Ca\UI\Data\ui_gear_sec_gs.paa";
			action = "secoClicked = true";
		};
		
		class Sidearm : PrimaryWeapon {
			idc = 3500 + 2;
			x = 0.56;
			y = 0.551;
			w = 0.113;
			h = 0.15;
			text = "\Ca\UI\Data\ui_gear_hgun_gs.paa";
			action = "sideClicked = true";
		};
		
		class InventorySlot0 : PrimaryWeapon {
			idc = 3500 + 3;
			x = 0.79;
			y = 0.244;
			w = 0.055;
			h = 0.074;
			text = "\Ca\UI\Data\ui_gear_mag_gs.paa";
			action = "WF_Logic setVariable ['InventoryClick',3503]";
		};
		
		class InventorySlot1 : InventorySlot0 {
			idc = 3500 + 4;
			x = 0.847;
			y = 0.244;
			action = "WF_Logic setVariable ['InventoryClick',3504]";
		};
		
		class InventorySlot2 : InventorySlot0 {
			idc = 3500 + 5;
			x = 0.904366;
			y = 0.244;
			action = "WF_Logic setVariable ['InventoryClick',3505]";
		};
		
		class InventorySlot3 : InventorySlot0 {
			idc = 3500 + 6;
			x = 0.79;
			y = 0.321;
			action = "WF_Logic setVariable ['InventoryClick',3506]";
		};
		
		class InventorySlot4 : InventorySlot0 {
			idc = 3500 + 7;
			x = 0.847;
			y = 0.321;
			action = "WF_Logic setVariable ['InventoryClick',3507]";
		};
		
		class InventorySlot5 : InventorySlot0 {
			idc = 3500 + 8;
			x = 0.904366;
			y = 0.321;
			action = "WF_Logic setVariable ['InventoryClick',3508]";
		};
		
		class InventorySlot6 : InventorySlot0 {
			idc = 3500 + 9;
			x = 0.79;
			y = 0.398;
			action = "WF_Logic setVariable ['InventoryClick',3509]";
		};
		
		class InventorySlot7 : InventorySlot0 {
			idc = 3500 + 10;
			x = 0.847;
			y = 0.398;
			action = "WF_Logic setVariable ['InventoryClick',3510]";
		};
		
		class InventorySlot8 : InventorySlot0 {
			idc = 3500 + 11;
			x = 0.904366;
			y = 0.398;
			action = "WF_Logic setVariable ['InventoryClick',3511]";
		};
		
		class InventorySlot9 : InventorySlot0 {
			idc = 3500 + 12;
			x = 0.79;
			y = 0.474;
			action = "WF_Logic setVariable ['InventoryClick',3512]";
		};
		
		class InventorySlot10 : InventorySlot0 {
			idc = 3500 + 13;
			x = 0.847;
			y = 0.474;
			action = "WF_Logic setVariable ['InventoryClick',3513]";
		};
		
		class InventorySlot11 : InventorySlot0 {
			idc = 3500 + 14;
			x = 0.904366;
			y = 0.474;
			action = "WF_Logic setVariable ['InventoryClick',3514]";
		};
		
		class SidearmInventorySlot0 : InventorySlot0 {
			idc = 3500 + 15;
			x = 0.674;
			y = 0.551;
			w = 0.055;
			h = 0.074;
			text = "\Ca\UI\Data\ui_gear_hgunmag_gs.paa";
			action = "WF_Logic setVariable ['InventoryClick',3515]";
		};
		
		class SidearmInventorySlot1 : SidearmInventorySlot0 {
			idc = 3500 + 16;
			x = 0.733;
			y = 0.551;
			action = "WF_Logic setVariable ['InventoryClick',3516]";
		};
		
		class SidearmInventorySlot2 : SidearmInventorySlot0 {
			idc = 3500 + 17;
			x = 0.79;
			action = "WF_Logic setVariable ['InventoryClick',3517]";
		};
		
		class SidearmInventorySlot3 : SidearmInventorySlot0 {
			idc = 3500 + 18;
			x = 0.847;
			action = "WF_Logic setVariable ['InventoryClick',3518]";
		};
		
		class SidearmInventorySlot4 : SidearmInventorySlot0 {
			idc = 3500 + 19;
			x = 0.674;
			y = 0.628;
			action = "WF_Logic setVariable ['InventoryClick',3519]";
		};
		
		class SidearmInventorySlot5 : SidearmInventorySlot0 {
			idc = 3500 + 20;
			x = 0.733;
			y = 0.628;
			action = "WF_Logic setVariable ['InventoryClick',3520]";
		};
		
		class SidearmInventorySlot6 : SidearmInventorySlot0 {
			idc = 3500 + 21;
			x = 0.79;
			y = 0.628;
			action = "WF_Logic setVariable ['InventoryClick',3521]";
		};
		
		class SidearmInventorySlot7 : SidearmInventorySlot0 {
			idc = 3500 + 22;
			x = 0.847;
			y = 0.628;
			action = "WF_Logic setVariable ['InventoryClick',3522]";
		};
		
		class MiscInventorySlot0 : InventorySlot0 {
			idc = 3500 + 23;
			x = 0.56;
			y = 0.705;
			w = 0.055;
			h = 0.074;
			colorActive[] = {0.85, 0.85, 0.85, 1};
			text = "\Ca\UI\Data\ui_gear_eq_gs.paa";
			action = "WF_Logic setVariable ['InventoryClick',3523]";
		};
		
		class MiscInventorySlot1 : MiscInventorySlot0 {
			idc = 3500 + 24;
			x = 0.617;
			y = 0.705;
			action = "WF_Logic setVariable ['InventoryClick',3524]";
		};
		
		class MiscInventorySlot2 : MiscInventorySlot0 {
			idc = 3500 + 25;
			x = 0.674;
			y = 0.705;
			action = "WF_Logic setVariable ['InventoryClick',3525]";
		};
		
		class MiscInventorySlot3 : MiscInventorySlot0 {
			idc = 3500 + 26;
			x = 0.733;
			y = 0.705;
			action = "WF_Logic setVariable ['InventoryClick',3526]";
		};
		
		class MiscInventorySlot4 : MiscInventorySlot0 {
			idc = 3500 + 27;
			x = 0.79;
			y = 0.705;
			action = "WF_Logic setVariable ['InventoryClick',3527]";
		};
		
		class MiscInventorySlot5 : MiscInventorySlot0 {
			idc = 3500 + 28;
			x = 0.847;
			y = 0.705;
			action = "WF_Logic setVariable ['InventoryClick',3528]";
		};
		
		class MiscInventorySlot6 : MiscInventorySlot0 {
			idc = 3500 + 29;
			x = 0.56;
			y = 0.782;
			action = "WF_Logic setVariable ['InventoryClick',3529]";
		};
		
		class MiscInventorySlot7 : MiscInventorySlot0 {
			idc = 3500 + 30;
			x = 0.617;
			y = 0.782;
			action = "WF_Logic setVariable ['InventoryClick',3530]";
		};
		
		class MiscInventorySlot8 : MiscInventorySlot0 {
			idc = 3500 + 31;
			x = 0.674;
			y = 0.782;
			action = "WF_Logic setVariable ['InventoryClick',3531]";
		};
		
		class MiscInventorySlot9 : MiscInventorySlot0 {
			idc = 3500 + 32;
			x = 0.733;
			y = 0.782;
			action = "WF_Logic setVariable ['InventoryClick',3532]";
		};
		
		class MiscInventorySlot10 : MiscInventorySlot0 {
			idc = 3500 + 33;
			x = 0.79;
			y = 0.782;
			action = "WF_Logic setVariable ['InventoryClick',3533]";
		};
		
		class MiscInventorySlot11 : MiscInventorySlot0 {
			idc = 3500 + 34;
			x = 0.847;
			y = 0.782;
			action = "WF_Logic setVariable ['InventoryClick',3534]";
		};
		
		class SpecialInventorySlot0 : InventorySlot0 {
			idc = 3500 + 35;
			x = 0.502;
			y = 0.09;
			w = 0.113;
			h = 0.15;
			colorActive[] = {0.85, 0.85, 0.85, 1};
			text = "\Ca\UI\Data\ui_gear_eq_gs.paa";
			action = "WF_Logic setVariable ['InventoryClick',3535]";
		};
		
		class SpecialInventorySlot1 : SpecialInventorySlot0 {
			idc = 3500 + 36;
			x = 0.847;
			y = 0.09;
			action = "WF_Logic setVariable ['InventoryClick',3536]";
		};
		
		class CA_Money_Value : RscText {
			idc = 3850;
			x = 0.727942;
			y = 0.86;
			SizeEx = 0.03;
			text = "";
			colorText[] = subcolor1;
			shadow = 2;
		};
		
		class CA_Cost : CA_Money_Value {
			idc = 3851;
			x = 0.504086;
			y = 0.86;
			text = '';
		};
		
		class CA_GearLabel : CA_Money_Value {
			idc = 3852;
			style = 2;
			x = 0.502419;
			y = 0.0492156;
			w = 0.456;
			SizeEx = 0.03;
			text = $STR_WF_Gear_MenuEquip;
		};
		
		class Gear_Title : CA_Money_Value {
			idc = 3853;
			x = 0.047634;
			y = 0.01;
			text = $STR_WF_Gear_Label;
		};
		
		class CA_SwapUnit : RscCombo {
			idc = 3854;
			x = 0.141;
			y = 0.129;
			w = 0.351;
			
			onLBSelChanged = "WF_Logic setVariable ['WF_GEAR_Swap',true]";
		};	
		
		class Unit_Title : CA_Money_Value {
			idc = 3855;
			x = 0.037634;
			y = 0.129;
			text = $STR_WF_Unit;
		};
		
		class BuyButton : RscIGUIShortcutButton {
			idc = 3900;
			x = 0.0392 + 0.245 * 2;
			y = 0.897;
			w = 0.185;
			h = 0.052;
			text = $STR_WF_Purchase;
			action = "buyLoadout = true";
		};
		
		class CloseButton : BuyButton {
			idc = 3901;
			x = 0.0392 + 0.245 * 3;
			text = $STR_DISP_CLOSE;
			action = "closeDialog 0";
		};	
		
		class SaveButton : BuyButton {
			idc = 3902;
			x = 0.0392  + 0.245;
			text = $STR_WF_Save;
			action = "saveLoadout = true";
		};
		
		class DeleteButton : BuyButton {
			idc = 3903;
			x = 0.0392;
			text = $STR_WF_Delete;
			action = "deleteLoadout = true";
		};
	};
};

//--- Special Menu.
class RscArtilleryMenu {
	movingEnable = 1;
	idd = 17000;
	onLoad = "_this ExecVM 'Client\GUI\GUI_ArtilleryMenu.sqf'";
	
	class controlsBackground {
		class Mainback : RscPicture {
			x = 0.04;
			y = 0.01;
			w = 1.25;
			h = 1.67;
			moving = 1;
			text = "\ca\ui\data\igui_background_buy_units_ca.paa";
		};
		class background1: RscText {
			x = 0.04;
			y = 0.579;
			w = 0.4565;
			h = 0.043;
			colorBackground[] = {0, 0, 0, 0.5};
	};
	};
	
	class controls {
		class CA_Diff_B_Back : RscIGUIShortcutButton {
			idc = 17001;
			shortcuts[] = {0x00050000 + 1};
			default = 0;
			x = 0.0392 + 0.245 * 3;
			y = 0.897;
			w = 0.185;
			h = 0.052;
			text = $STR_DISP_CLOSE;
			action = "closeDialog 0";
		};
		class WF_MiniMap : RscMapControl {
			IDC = 17002;
			ShowCountourInterval = 1;
			x = 0.5;
			y = 0.165;
			w = 0.454;
			h = 0.452;

			onMouseMoving = "mouseX = (_this Select 1);mouseY = (_this Select 2)";
			onMouseButtonDown = "mouseButtonDown = _this Select 1";
			onMouseButtonUp = "mouseButtonUp = _this Select 1";
		};
		class CA_Label: RscText {
			idc = 17003;
			text = $STR_WF_SpecialMenu;
			x = 0.047634;
			y = 0.01;
			colorText[] = subcolor1;
			SizeEx = 0.03;
		};
		class CA_Artillery_Label: CA_Label {
			idc = 17004;
			text = $STR_WF_Artillery;
			x = 0.043;
			y = 0.165;
			w = 0.2;
		};
		class CA_Artillery_Slider : RscXSliderH {
			idc = 17005;
			x = 0.044;
			y = 0.2;
			w = 0.34;
		};
		class CA_SetFMission_Button: RscIGUIShortcutButton {
			idc = 17006;
			x = 0.044;
			y = 0.24;
			w = 0.28;
			text = $STR_WF_FireMission_Set;
			action = "MenuAction = 1";
		};
		class CA_FireMission_Button: RscIGUIShortcutButton {
			idc = 17007;
			x = 0.044;
			y = 0.28;
			w = 0.28;
			text = $STR_WF_FireMission;
			action = "MenuAction = 2";
		};
		class CA_Artillery_Combo: RscCombo {
			idc = 17008;
			x = 0.393;
			w = 0.1;
			y = 0.2;
			h = 0.029412;
			
			onLBSelChanged = "MenuAction = 200";
		};
		class CA_Special_Label: CA_Label {
			idc = 17009;
			text = $STR_WF_Special;
			x = 0.043;
			y = 0.335;
			w = 0.2;
		};
		class CA_ArtilleryTimeout: RscStructuredText {
			idc = 17016;
			size = 0.0262;
			x = 0.33;
			y = 0.24;
			h = 0.16;
			w = 0.15;
		};
		class SupportList : RscListBox {
			idc = 17019;
			x = 0.043;
			y = 0.37;
			w = 0.45;
			h = 0.205;
			rowHeight = 0.01;
			sizeEx = 0.024;
		};
		class CA_Button_Use: RscIGUIShortcutButton {
			idc = 17020;
			x = 0.295;
			y = 0.578;
			w = 0.2;
			text = $STR_WF_Use;
			action = "MenuAction = 20";
		};
		class CA_SpecialTimeout: CA_Label {
			idc = 17021;
			size = 0.0262;
			x = 0.043;
			y = 0.58;
			w = 0.25;
		};
		class CA_InformationText: RscStructuredText {
			idc = 17022;
			size = 0.0262;
			x = 0.043;
			y = 0.904;
			w = 0.6;
		};
		class Ca_ArtilleryToggle: RscClickableText {
			idc = 17023;
			text = "Client\Images\tog_arty.paa";
			x = 0.43;
			y = 0.24;
			w = 0.064;
			h = 0.064;
			action = "MenuAction = 40";
			tooltip = $STR_WF_Tooltips_ArtilleryToggle;
		};
		class CA_ArtilleryList : RscListBoxA {
			idc = 17024;
			x = 0.613;
			y = 0.66;
			w = 0.34;
			h = 0.235;
			columns[] = {0.02, 0.55};
			drawSideArrows = 0;
			idcRight = -1;
			idcLeft = -1;
			rowHeight = 0.05;
			sizeEx = 0.023;
			
			onLBSelChanged = "MenuAction = 60";
		};	
		class CA_ArtilleryTable_Label: CA_Label {
			idc = 17025;
			text = "";
			x = 0.61;
			y = 0.621;
			w = 0.34;
		};
		//--- Separators.
		class LineTRH1 : RscText {
			x = 0.04;
			y = 0.163;
			w = 0.4565;
			h = 0.002;
			text = "";
			colorBackground[] = {0.543, 0.5742, 0.4102, 1.0};
		};
		class LineTRH2 : LineTRH1 {
			x = 0.04;
			y = 0.33;
			w = 0.4565;
			h = 0.002;
		};
		class LineTRH3 : LineTRH1 {
			x = 0.04;
			y = 0.617;
			w = 0.4565;
			h = 0.002;
		};
		class LineTRH4 : LineTRH1 {
			x = 0.610;
			y = 0.66;
			w = 0.002;
			h = 0.236;
	};
	};
};

//--- Upgrade Menu.
class RscUpgradeMenu {
	movingEnable = 1;
	idd = 18000;
	onLoad = "_this ExecVM ""Client\GUI\GUI_Upgrade.sqf""";
	
	class controlsBackground {
		class Mainback : RscPicture {
			x = 0.185;
			y = 0.17;
			w = 1.2549;
			h = 0.836601;
			moving = 1;
			text = "\ca\ui\data\ui_difficulty_background_ca.paa";
		};
	};
	
	class controls {
		class CA_Label: RscText {
			idc = 18801;
			text = $STR_WF_Upgrade_Menu;
			x = 0.2;
			w = 0.4;
			y = 0.205;
		};
		class CA_Label_TimeLeft: RscText {
			idc = 18802;
			text = "";
			x = 0.5;
			w = 0.4;
			y = 0.205;
			sizeEx = 0.034;
		};
		//--- Tree.
		class LineTRH1 : RscText {
			x = 0.81;
			y = 0.3;
			w = 0.002;
			h = 0.4;
			text = "";
			colorBackground[] = {1, 1, 1, 1};
		};
		class LineTRH2 : LineTRH1 {
			x = 0.81;
			y = 0.37;
			w = 0.03;
			h = 0.002;
		};
		class LineTRH3 : LineTRH1 {
			x = 0.84;
			y = 0.37;
			w = 0.002;
			h = 0.05;
		};
		class LineTRH4 : LineTRH1 {
			x = 0.73;
			y = 0.38;
			w = 0.08;
			h = 0.002;
		};
		class LineTRH5 : LineTRH1 {
			x = 0.78;
			y = 0.38;
			w = 0.002;
			h = 0.05;
		};
		class LineTRH6 : LineTRH1 {
			x = 0.73;
			y = 0.38;
			w = 0.002;
			h = 0.05;
		};
		class LineTRH7 : LineTRH1 {
			x = 0.45;
			y = 0.3;
			w = 0.002;
			h = 0.3;
		};
		class LineTRH8 : LineTRH1 {
			x = 0.45;
			y = 0.37;
			w = 0.03;
			h = 0.002;
		};
		class LineTRH9 : LineTRH1 {
			x = 0.48;
			y = 0.37;
			w = 0.002;
			h = 0.05;
		};
		class LineTRH10 : LineTRH1 {
			x = 0.42;
			y = 0.38;
			w = 0.03;
			h = 0.002;
		};
		class LineTRH11 : LineTRH1 {
			x = 0.42;
			y = 0.38;
			w = 0.002;
			h = 0.05;
		};
		class LineTRH12 : LineTRH1 {
			x = 0.81;
			y = 0.46;
			w = 0.03;
			h = 0.002;
		};
		class LineTRH13 : LineTRH1 {
			x = 0.84;
			y = 0.46;
			w = 0.002;
			h = 0.05;
		};
		class LineTRH14 : LineTRH1 {
			x = 0.27;
			y = 0.3;
			w = 0.002;
			h = 0.3;
		};
		class LineTRH15 : LineTRH1 {
			x = 0.27;
			y = 0.37;
			w = 0.03;
			h = 0.002;
		};
		class LineTRH16 : LineTRH1 {
			x = 0.3;
			y = 0.37;
			w = 0.002;
			h = 0.05;
		};
		class LineTRH17 : LineTRH1 {
			x = 0.63;
			y = 0.3;
			w = 0.002;
			h = 0.3;
		};
		class LineTRH18 : LineTRH1 {
			x = 0.63;
			y = 0.37;
			w = 0.03;
			h = 0.002;
		};
		class LineTRH19 : LineTRH1 {
			x = 0.66;
			y = 0.37;
			w = 0.002;
			h = 0.05;
		};
		class LineTRH20 : LineTRH1 {
			x = 0.24;
			y = 0.38;
			w = 0.002;
			h = 0.03;
		};
		class LineTRH21 : LineTRH1 {
			x = 0.24;
			y = 0.38;
			w = 0.03;
			h = 0.002;
		};
		class LineTRH22 : LineTRH1 {
			x = 0.24;
			y = 0.47;
			w = 0.002;
			h = 0.03;
		};
		class LineTRH23 : LineTRH1 {
			x = 0.24;
			y = 0.47;
			w = 0.03;
			h = 0.002;
		};
		class LineTRH24 : LineTRH1 {
			x = 0.78;
			y = 0.47;
			w = 0.002;
			h = 0.03;
		};
		class LineTRH25 : LineTRH1 {
			x = 0.78;
			y = 0.47;
			w = 0.03;
			h = 0.002;
		};
		class LineTRH26 : LineTRH1 {
			x = 0.73;
			y = 0.47;
			w = 0.002;
			h = 0.03;
		};
		class LineTRH27 : LineTRH1 {
			x = 0.73;
			y = 0.47;
			w = 0.06;
			h = 0.002;
		};
		//--- Shells Line.
		class LineTRH28 : LineTRH1 {
			x = 0.63;
			y = 0.46;
			w = 0.03;
			h = 0.002;
		};
		class LineTRH29 : LineTRH1 {
			x = 0.66;
			y = 0.46;
			w = 0.002;
			h = 0.05;
		};
		//--- Normal GUI Ctrls.
		class WF_Con1: RscClickableText {
			idc = 18001;
			text = "Client\Images\wf_b.paa";
			x = 0.24;
			y = 0.26;
			w = 0.064;
			h = 0.064;
			action = "MenuAction = 1";
			
			onMouseMoving = "mouseX = (_this Select 1);mouseY = (_this Select 2)"; 
			onMouseEnter = "displayUpgrade = 'infantry'";
			onMouseExit = "displayUpgrade = ''";
		};
		class WF_Con2: RscClickableText {
			idc = 18002;
			text = "Client\Images\wf_lvf.paa";
			x = 0.42;
			y = 0.26;
			w = 0.064;
			h = 0.064;
			action = "MenuAction = 1";
			
			onMouseMoving = "mouseX = (_this Select 1);mouseY = (_this Select 2)"; 
			onMouseEnter = "displayUpgrade = 'light'";
			onMouseExit = "displayUpgrade = ''";
		};
		class WF_Con3: RscClickableText {
			idc = 18003;
			text = "Client\Images\wf_hvf.paa";
			x = 0.6;
			y = 0.26;
			w = 0.064;
			h = 0.064;
			action = "MenuAction = 1";
			
			onMouseMoving = "mouseX = (_this Select 1);mouseY = (_this Select 2)"; 
			onMouseEnter = "displayUpgrade = 'heavy'";
			onMouseExit = "displayUpgrade = ''";
		};
		class WF_Con4: RscClickableText {
			idc = 18004;
			text = "Client\Images\wf_air.paa";
			x = 0.78;
			y = 0.26;
			w = 0.064;
			h = 0.064;
			action = "MenuAction = 1";
			
			onMouseMoving = "mouseX = (_this Select 1);mouseY = (_this Select 2)"; 
			onMouseEnter = "displayUpgrade = 'air'";
			onMouseExit = "displayUpgrade = ''";
		};
		class WF_Con5: RscClickableText {
			idc = 18005;
			text = "Client\Images\wf_par.paa";
			x = 0.75;
			y = 0.39;
			w = 0.064;
			h = 0.064;
			action = "MenuAction = 1";
			
			onMouseMoving = "mouseX = (_this Select 1);mouseY = (_this Select 2)"; 
			onMouseEnter = "displayUpgrade = 'parachutist'";
			onMouseExit = "displayUpgrade = ''";
		};
		class WF_Con6: RscClickableText {
			idc = 18006;
			text = "Client\Images\wf_uav.paa";
			x = 0.70;
			y = 0.48;
			w = 0.064;
			h = 0.064;
			action = "MenuAction = 1";
			
			onMouseMoving = "mouseX = (_this Select 1);mouseY = (_this Select 2)"; 
			onMouseEnter = "displayUpgrade = 'uav'";
			onMouseExit = "displayUpgrade = ''";
		};
		class WF_Con7: RscClickableText {
			idc = 18007;
			text = "Client\Images\wf_sup.paa";
			x = 0.45;
			y = 0.38;
			w = 0.064;
			h = 0.064;
			action = "MenuAction = 1";
			
			onMouseMoving = "mouseX = (_this Select 1);mouseY = (_this Select 2)"; 
			onMouseEnter = "displayUpgrade = 'supply'";
			onMouseExit = "displayUpgrade = ''";
		};
		class WF_Con8: RscClickableText {
			idc = 18008;
			text = "Client\Images\wf_fia.paa";
			x = 0.39;
			y = 0.39;
			w = 0.064;
			h = 0.064;
			action = "MenuAction = 1";
			
			onMouseMoving = "mouseX = (_this Select 1);mouseY = (_this Select 2)"; 
			onMouseEnter = "displayUpgrade = 'ambuSpawn'";
			onMouseExit = "displayUpgrade = ''";
		};
		class WF_Con9: RscClickableText {
			idc = 18009;
			text = "Client\Images\wf_lif.paa";
			x = 0.81;
			y = 0.38;
			w = 0.064;
			h = 0.064;
			action = "MenuAction = 1";
			
			onMouseMoving = "mouseX = (_this Select 1);mouseY = (_this Select 2)"; 
			onMouseEnter = "displayUpgrade = 'airlift'";
			onMouseExit = "displayUpgrade = ''";
		};
		class WF_Con10: RscClickableText {
			idc = 18010;
			text = "Client\Images\wf_fla.paa";
			x = 0.81;
			y = 0.47;
			w = 0.064;
			h = 0.064;
			action = "MenuAction = 1";
			
			onMouseMoving = "mouseX = (_this Select 1);mouseY = (_this Select 2)"; 
			onMouseEnter = "displayUpgrade = 'flares'";
			onMouseExit = "displayUpgrade = ''";
		};
		class WF_Con11: RscClickableText {
			idc = 18011;
			text = "Client\Images\wf_art.paa";
			x = 0.63;
			y = 0.38;
			w = 0.064;
			h = 0.064;
			action = "MenuAction = 1";
			
			onMouseMoving = "mouseX = (_this Select 1);mouseY = (_this Select 2)"; 
			onMouseEnter = "displayUpgrade = 'artillery'";
			onMouseExit = "displayUpgrade = ''";
		};
		class WF_Con12: RscClickableText {
			idc = 18012;
			text = "Client\Images\wf_mib.paa";
			x = 0.78;
			y = 0.69;
			w = 0.064;
			h = 0.064;
			action = "MenuAction = 1";
			
			onMouseMoving = "mouseX = (_this Select 1);mouseY = (_this Select 2)"; 
			onMouseEnter = "displayUpgrade = 'icbm'";
			onMouseExit = "displayUpgrade = ''";
		};
		class WF_Con13: RscClickableText {
			idc = 18013;
			text = "Client\Images\wf_fas.paa";
			x = 0.27;
			y = 0.38;
			w = 0.064;
			h = 0.064;
			action = "MenuAction = 1";
			
			onMouseMoving = "mouseX = (_this Select 1);mouseY = (_this Select 2)"; 
			onMouseEnter = "displayUpgrade = 'fasttravel'";
			onMouseExit = "displayUpgrade = ''";
		};
		class WF_Con14: RscClickableText {
			idc = 18014;
			text = "Client\Images\wf_gea.paa";
			x = 0.21;
			y = 0.39;
			w = 0.064;
			h = 0.064;
			action = "MenuAction = 1";
			
			onMouseMoving = "mouseX = (_this Select 1);mouseY = (_this Select 2)"; 
			onMouseEnter = "displayUpgrade = 'gear'";
			onMouseExit = "displayUpgrade = ''";
		};
		class WF_Con15: RscClickableText {
			idc = 18015;
			text = "Client\Images\wf_amm.paa";
			x = 0.21;
			y = 0.48;
			w = 0.064;
			h = 0.064;
			action = "MenuAction = 1";
			
			onMouseMoving = "mouseX = (_this Select 1);mouseY = (_this Select 2)"; 
			onMouseEnter = "displayUpgrade = 'ammo'";
			onMouseExit = "displayUpgrade = ''";
		};
		class WF_Con16: RscClickableText {
			idc = 18016;
			text = "Client\Images\wf_eas.paa";
			x = 0.75;
			y = 0.48;
			w = 0.064;
			h = 0.064;
			action = "MenuAction = 1";
			
			onMouseMoving = "mouseX = (_this Select 1);mouseY = (_this Select 2)"; 
			onMouseEnter = "displayUpgrade = 'easa'";
			onMouseExit = "displayUpgrade = ''";
		};
		class WF_Con17: RscClickableText {
			idc = 18017;
			text = "Client\Images\wf_pas.paa";
			x = 0.70;
			y = 0.39;
			w = 0.064;
			h = 0.064;
			action = "MenuAction = 1";
			
			onMouseMoving = "mouseX = (_this Select 1);mouseY = (_this Select 2)"; 
			onMouseEnter = "displayUpgrade = 'paradrop'";
			onMouseExit = "displayUpgrade = ''";
		};
		class WF_Con18: RscClickableText {
			idc = 18018;
			text = "Client\Images\wf_shl.paa";
			x = 0.63;
			y = 0.47;
			w = 0.064;
			h = 0.064;
			action = "MenuAction = 1";
			
			onMouseMoving = "mouseX = (_this Select 1);mouseY = (_this Select 2)"; 
			onMouseEnter = "displayUpgrade = 'shells'";
			onMouseExit = "displayUpgrade = ''";
		};
		class CA_Diff_B_Back : RscShortcutButton {
			idc = 18901;
			shortcuts[] = {0x00050000 + 1};
			default = 0;
			x = 0.706;
			y = 0.7625;
			text = $STR_DISP_CLOSE;
			action = "closeDialog 0";
		};
		class TooltipHelper : RscText {
			style = 128;
			idc = 18998;
			x = 0.0;
			y = 0.0;
			w = 0.0;
			h = 0.0;
			colorBackground[] = {0.1882, 0.2588, 0.149, 0.76};
		};
		class TooltipHelperText : RscStructuredText {
			idc = 18999;
			x = 0.0;
			y = 0.0;
			w = 0.0;
			h = 0.0;
			size = 0.035;
			
			class Attributes {
				font = "Zeppelin32";
				color = "#B6F862";
				align = "left";
				shadow = true;
			};
		};
	};
};

//--- Support Menu.
class RscSupportMenu {
	movingEnable = 1;
	idd = 20000;
	onLoad = "ExecVM ""Client\GUI\GUI_SupportMenu.sqf""";
	
	class controlsBackground {
		class Mainback : RscPicture {
			x = 0.015;
			y = 0.17;
			w = 0.627451;
			h = 0.836601;
			moving = 1;
			text = "\ca\ui\data\ui_mainmenu_background_ca.paa";
		};
	};
	class controls {
		class Label: RscText {
			idc = 20001;
			text = $STR_WF_SupportMenu;
			x = 0.04;
			y = 0.205;
		};
		class CA_UnitList : RscListBox {
			idc = 20002;
			x = 0.04;
			y = 0.26;
			w = 0.28;
			h = 0.20;
			rowHeight = 0.0439091;
		};
		class CA_Rearm_Button : RscIGUIShortcutButton {
			idc = 20003;
			x = 0.04;
			y = 0.47;
			w = 0.18;
			text = $STR_WF_Rearm;
			action = "MenuAction = 1";
		};
		class CA_Repair_Button : RscIGUIShortcutButton {
			idc = 20004;
			x = 0.04;
			y = 0.51;
			w = 0.18;
			text = $STR_WF_Repair;
			action = "MenuAction = 2";
		};
		class CA_Refuel_Button : RscIGUIShortcutButton {
			idc = 20005;
			x = 0.04;
			y = 0.55;
			w = 0.18;
			text = $STR_WF_Refuel;
			action = "MenuAction = 3";
		};
		class CA_RespST_Button : RscIGUIShortcutButton {
			idc = 20007;
			x = 0.04;
			y = 0.63;
			w = 0.28;
			text = $STR_WF_RespawnST;
			action = "MenuAction = 4";
		};
		class CA_Diff_B_Back : RscShortcutButton {
			idc = 20006;
			shortcuts[] = {0x00050000 + 1};
			default = 0;
			x = 0.14;
			y = 0.7625;
			text = $STR_DISP_CLOSE;
			action = "closeDialog 0";
		};
		class CA_Heal_Button : RscIGUIShortcutButton {
			idc = 20008;
			x = 0.04;
			y = 0.59;
			w = 0.18;
			text = $STR_WF_Heal;
			action = "MenuAction = 5";
		};
		class CA_Parameters_Button : RscIGUIShortcutButton {
			idc = 20009;
			x = 0.04;
			y = 0.71;
			w = 0.28;
			text = $STR_WF_Parameters;
			action = "MenuAction = 6";
		};
		class CA_EASA_Button : RscIGUIShortcutButton {
			idc = 20010;
			x = 0.04;
			y = 0.67;
			w = 0.28;
			text = "EASA";
			action = "MenuAction = 7";
		};
		class CA_LabelRearm: RscText {
			idc = 20011;
			text = "";
			x = 0.23;
			y = 0.47;
			w = 0.12;
			sizeEx = 0.03;
		};
		class CA_LabelRepair: CA_LabelRearm {
			idc = 20012;
			text = "";
			y = 0.51;
		};
		class CA_LabelRefuel: CA_LabelRearm {
			idc = 20013;
			text = "";
			y = 0.55;
		};
		class CA_LabelHeal: CA_LabelRearm {
			idc = 20014;
			text = "";
			y = 0.59;
		};
	};
};

//--- Units Camera.
class RscUnitCamera {
	movingEnable = 1;
	idd = 21000;
	onLoad = "_this ExecVM ""Client\GUI\GUI_UnitsCamera.sqf""";
	
	class controlsBackground {
		class Mainback : RscPicture {
			x = 0.015;
			y = 0.17;
			w = 0.627451;
			h = 0.836601;
			moving = 1;
			text = "\ca\ui\data\ui_mainmenu_background_ca.paa";
		};
	};
	class controls {
		class Label: RscText {
			idc = 21001;
			text = $STR_WF_UnitCam;
			x = 0.04;
			y = 0.205;
		};
		class CA_Camera_UnitList : RscListBox {
			idc = 21002;
			x = 0.04;
			y = 0.26;
			w = 0.28;
			h = 0.099;
			rowHeight = 0.01;
			sizeEx = 0.024;
			
			onLBSelChanged = "MenuAction = 101";
		};
		class CA_Commanding_Label: RscText {
			idc = 21003;
			text = "Commanding:";
			x = 0.04;
			y = 0.36;
			sizeEx = 0.03;
		};
		class CA_Camera_AIList : RscListBox {
			idc = 21004;
			x = 0.04;
			y = 0.4;
			w = 0.28;
			h = 0.12;
			rowHeight = 0.01;
			sizeEx = 0.024;
			
			onLBSelChanged = "MenuAction = 102";
		};
		class CA_Camera_Mode: RscText {
			idc = 21005;
			text = "Camera Mode:";
			x = 0.04;
			y = 0.52;
			sizeEx = 0.03;
		};
		class CA_Camera_Combo : RscCombo {
			idc = 21006;
			x = 0.04;
			y = 0.56;
			w = 0.28;
			
			onLBSelChanged = "MenuAction = 103";
		};
		class CA_MiniMap : RscMapControl {
			IDC = 21007;
			ShowCountourInterval = 1;
			x = 0.02;
			y = 0.605;
			w = 0.314;
			h = 0.158;

			onMouseMoving = "mouseX = (_this Select 1);mouseY = (_this Select 2)";
			onMouseButtonDown = "mouseButtonDown = _this Select 1";
			onMouseButtonUp = "mouseButtonUp = _this Select 1";
		};		
		class CA_Diff_B_Back : RscShortcutButton {
			idc = 21008;
			shortcuts[] = {0x00050000 + 1};
			default = 0;
			x = 0.14;
			y = 0.7625;
			text = $STR_DISP_CLOSE;
			action = "closeDialog 0";
		};
	};
};

//--- Ingame Parameters.
class RscDisplayIngameParameters {
	movingEnable = 1;
	idd = 22000;
	onLoad = "_this ExecVM ""Client\GUI\GUI_Parameters.sqf""";
	
	class controlsBackground {
		class MainWizardBack2 : RscPicture {
			idc = 22001;
			x = 0.084;
			y = 0.17;
			w = 1.2549;
			h = 0.836601;
			text = "\ca\ui\data\ui_wizard_units_background_ca.paa";
		};
	};
	
	class controls {
		class CA_Title : RscText {
			idc = 22002;
			x = 0.17051;
			y = 0.2;
			SizeEx = 0.04821;
			text = $STR_WF_Parameters;
		};
		
		class LB_ParamsTitles : RscListBoxA {
			idc = 22003;
			columns[] = {0.01, 0.42};
			rowHeight = 0.036;
			drawSideArrows = 0;
			idcRight = -1;
			idcLeft = -1;
			x = 0.1;
			y = 0.27103;
			w = 0.85;
			h = 0.472;
		};
		
		class ButtonOK : RscShortcutButton {
			idc = 22004;
			shortcuts[] = {0x00050000 + 0, 28, 57, 156};
			x = 0.772;
			y = 0.7625;
			default = 1;
			text = $STR_DISP_OK;
			action = "closeDialog 0";
		};
		
		class CA_Time: RscText {
			idc = 22005;
			text = "";
			x = 0.13;
			y = 0.7695;
			w = 0.5;
			colorText[] = subcolor1;
			SizeEx = 0.03;
		};
	};
};

//--- EASA.
class RscDisplayEASA {
	movingEnable = 1;
	idd = 23000;
	onLoad = "_this ExecVM ""Client\GUI\GUI_EASA.sqf""";
	
	class controlsBackground {
		class MainWizardBack2 : RscPicture {
			idc = 23001;
			x = 0.084;
			y = 0.17;
			w = 1.2549;
			h = 0.836601;
			text = "\ca\ui\data\ui_wizard_units_background_ca.paa";
		};
	};
	
	class controls {
		class CA_Title : RscText {
			idc = 23002;
			x = 0.17051;
			y = 0.2;
			w = 0.6;
			SizeEx = 0.04821;
			text = $STR_WF_EASA;
		};
		
		class LB_EASA : RscListBoxA {
			idc = 23003;
			columns[] = {0.01, 0.16};
			rowHeight = 0.036;
			drawSideArrows = 0;
			idcRight = -1;
			idcLeft = -1;
			x = 0.1;
			y = 0.27103;
			w = 0.85;
			h = 0.472;
			
			onLBDblClick = "MenuAction = 101";
		};
		
		class CA_Purchase : RscShortcutButton {
			idc = 22004;
			x = 0.58;
			y = 0.7625;
			text = $STR_WF_Purchase;
			action = "MenuAction = 101";
		};
		
		class ButtonOK : RscShortcutButton {
			idc = 22005;
			shortcuts[] = {0x00050000 + 0, 28, 57, 156};
			x = 0.772;
			y = 0.7625;
			default = 1;
			text = $STR_DISP_CLOSE;
			action = "closeDialog 0";
		};
	};
};

//--- Commander Menu.
class RscCommanderMenu {
	movingEnable = 1;
	idd = 23000;
	onLoad = "_this ExecVM 'Client\GUI\GUI_CommanderMenu.sqf'";
	
	class controlsBackground {
		class Mainback : RscPicture {
			x = 0.04;
			y = 0.01;
			w = 1.25;
			h = 1.67;
			moving = 1;
			text = "\ca\ui\data\igui_background_buy_units_ca.paa";
		};
		class background1: RscText {
			x = 0.04;
			y = 0.579;
			w = 0.4565;
			h = 0.043;
			colorBackground[] = {0, 0, 0, 0.5};
		};
	};
	
	class controls {
		class CA_Diff_B_Back : RscIGUIShortcutButton {
			idc = 23001;
			shortcuts[] = {0x00050000 + 1};
			default = 0;
			x = 0.0392 + 0.245 * 3;
			y = 0.897;
			w = 0.185;
			h = 0.052;
			text = $STR_DISP_CLOSE;
			action = "closeDialog 0";
		};
		class WF_MiniMap : RscMapControl {
			IDC = 23002;
			ShowCountourInterval = 1;
			x = 0.5;
			y = 0.165;
			w = 0.454;
			h = 0.452;

			onMouseMoving = "mouseX = (_this Select 1);mouseY = (_this Select 2)";
			onMouseButtonDown = "mouseButtonDown = _this Select 1";
			onMouseButtonUp = "mouseButtonUp = _this Select 1";
		};
		class CA_Label: RscText {
			idc = 23003;
			text = $STR_WF_Commander_Menu;
			x = 0.047634;
			y = 0.01;
			colorText[] = subcolor1;
			SizeEx = 0.03;
		};
		//--- Workers
		class CA_LabelPartWorkers: CA_Label {
			idc = 23008;
			text = $STR_WF_Workers;
			x = 0.044;
			y = 0.17;
			w = 0.25;
		};
		class CA_HireWorker_Button: RscIGUIShortcutButton {
			idc = 23004;
			x = 0.044;
			y = 0.21;
			w = 0.28;
			text = $STR_WF_HireWorker;
			action = "MenuAction = 1";
		};
		class CA_LabelWorkers: CA_Label {
			idc = 23005;
			text = "";
			x = 0.33;
			y = 0.21;
			w = 0.15;
		};
		class CA_DisbandWorker_Button: CA_HireWorker_Button {
			idc = 23006;
			y = 0.25;
			text = $STR_WF_Disband;
			action = "MenuAction = 2";
		};
		class CA_Workers_Combo : RscCombo {
			idc = 23007;
			x = 0.33;
			y = 0.255;
			w = 0.15;
			
			onLBSelChanged = "MenuAction = 100";
		};
		//--- Income
		class CA_LabelPartIncome: CA_LabelPartWorkers {
			idc = 23009;
			text = $STR_WF_Income_Sys;
			y = 0.295;
		};
		class CA_Slider_Income : RscXSliderH {
			idc = 23010;
			x = 0.044;
			y = 0.335;
			w = 0.36;
		};
		class CA_LabelIncomePercent: CA_Label {
			idc = 23011;
			text = "";
			x = 0.41;
			y = 0.335;
			w = 0.15;
		};
		class CA_IncomeSet_Button: RscIGUIShortcutButton {
			idc = 23012;
			x = 0.044;
			y = 0.375;
			w = 0.44;
			text = $STR_WF_SetIncome;
			action = "MenuAction = 3";
		};
		class CA_LabelIncomeCommander: CA_Label {
			idc = 23013;
			text = "";
			x = 0.044;
			y = 0.415;
			w = 0.4;
		};
		class CA_LabelPlayerCommander: CA_LabelIncomeCommander {
			idc = 23014;
			text = "";
			y = 0.45;
		};
		//--- Separators.
		class LineTRH1 : RscText {
			x = 0.04;
			y = 0.295;
			w = 0.4565;
			h = 0.002;
			text = "";
			colorBackground[] = {0.543, 0.5742, 0.4102, 1.0};
		};
	};
};
