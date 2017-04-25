#ifndef ACE_NOHUD 
class CfgInGameUI {
	class Menu {
		hideTime = 20; // 60;
	};
	class CommandBar {
		dimm = 0;
		left = "(((safezoneX + (safezoneW - (1 * (safezoneW / safezoneH))) / 2) + 4.9 * ((1 * (safezoneW / safezoneH)) / 32)))";
		top = "((safezoneY + safezoneH - ((1 / 1.2 * (safezoneW / safezoneH)) / 20)))";
		width = "(22 * ((1 * (safezoneW / safezoneH)) / 32))";
		height = "(1 * ((1 / 1.2 * (safezoneW / safezoneH)) / 20))";
		class prevPage {
			x = 0;
			y = 0;
			w = "1 * ((1 * (safezoneW / safezoneH)) / 32)";
			h = "1 * ((1 / 1.2 * (safezoneW / safezoneH)) / 20)";
			color[] = {1,1,1,0.3};
		};
		class nextPage {
			x = 0;
			y = 0;
			w = "1 * ((1 * (safezoneW / safezoneH)) / 32)";
			h = "1 * ((1 / 1.2 * (safezoneW / safezoneH)) / 20)";
			color[] = {1,1,1,0.3};
		};
		class UnitInfo {
			class GroupIcon {
				x = "0.016/2";
				y = 0.012;
				w = "0.05733/2";
				h = "0.07623/2";
			};
			class HcGroupText {
				x = 0.045;
				y = 0.083;
				font = "Zeppelin32";
				SizeEx = "((1 / 1.2 * (safezoneW / safezoneH)) / 20) * 0.7/2";
			};
			class UnitBackground {
				x = 0;
				y = 0;
				w = "2 * ((1 * (safezoneW / safezoneH)) / 32)";
				h = "1 * ((1 / 1.2 * (safezoneW / safezoneH)) / 20)";
				color[] = {1.0,1.0,1.0,0};
				textureNormal = "x\ace\addons\c_ui\ui_minimalhud\cmdbar_background_ca.paa";
				textureSelected = "x\ace\addons\c_ui\ui_minimalhud\cmdbar_selected_ca.paa";
				texturePlayer = "x\ace\addons\c_ui\ui_minimalhud\cmdbar_player_ca.paa";
				textureFocus = "x\ace\addons\c_ui\ui_minimalhud\cmdbar_background_ca.paa";
			};
			class UnitFocus {
				x = 0;
				y = 0;
				w = 0;
				h = 0;
				color[] = {1.0,1.0,1.0,0};
				texture = "#(argb,8,8,3)color(0,0,0,0)";
			};
			class UnitIcon {
				x = "1 * ((1 * (safezoneW / safezoneH)) / 32)";
				y = "0 * ((1 / 1.2 * (safezoneW / safezoneH)) / 20)";
				w = "1 * ((1 * (safezoneW / safezoneH)) / 32)";
				h = "1 * ((1 / 1.2 * (safezoneW / safezoneH)) / 20)";
			};
			class Semaphore {
				x = "0.05 * ((1 * (safezoneW / safezoneH)) / 32)";
				y = "0.05 * ((1 / 1.2 * (safezoneW / safezoneH)) / 20)";
				w = "0.45 * ((1 * (safezoneW / safezoneH)) / 32)";
				h = "0.45 * ((1 / 1.2 * (safezoneW / safezoneH)) / 20)";
				color[] = {0.8,0,0,1};
				texture = "x\ace\addons\c_ui\ui_minimalhud\cmdbar_donotfire_ca.paa";
			};
			class CommandBackground {
				x = 0;
				y = 0;
				w = 0;
				h = 0;
				color[] = {1.0,1.0,1.0,0};
			};
			
			/* class Holdfire */
			/* class OrderBackground */
			/* class OrderText */
			/* class VehicleBackground */
			/* class VehicleText */
			
			class CommandText {
				//x = "1.55 * ((1 * (safezoneW / safezoneH)) / 32)";
				x = "1.35 * ((1 * (safezoneW / safezoneH)) / 32)";
				y = "0.05 * ((1 / 1.2 * (safezoneW / safezoneH)) / 20)";
				w = "0.5 * ((1 * (safezoneW / safezoneH)) / 32)";
				h = "0.2 * ((1 / 1.2 * (safezoneW / safezoneH)) / 20)";
				color[] = {1.0,1.0,1.0,1};
				font = "Zeppelin32";
				SizeEx = "((1 / 1.2 * (safezoneW / safezoneH)) / 20) * 0.5";
			};
			class VehicleNumberBackground {
				x = "0.5 * ((1 * (safezoneW / safezoneH)) / 32)";
				y = "0.05 * ((1 / 1.2 * (safezoneW / safezoneH)) / 20)";
				w = "0.45 * ((1 * (safezoneW / safezoneH)) / 32)";
				h = "0.45 * ((1 / 1.2 * (safezoneW / safezoneH)) / 20)";
				color[] = {0.023529,0,0.0313725,1};
				texture = "#(argb,8,8,3)color(0,0,0,0.2)";
			};
			class VehicleNumberText {
				x = "0.75 * ((1 * (safezoneW / safezoneH)) / 32)";
				y = "0.05 * ((1 / 1.2 * (safezoneW / safezoneH)) / 20)";
				w = "0.45 * ((1 * (safezoneW / safezoneH)) / 32)";
				h = "0.45 * ((1 / 1.2 * (safezoneW / safezoneH)) / 20)";
				colorText[] = {0.023529,0,0.0313725,1};
				font = "Zeppelin32";
				SizeEx = "((1 / 1.2 * (safezoneW / safezoneH)) / 20) * 0.5";
			};
			class UnitNumberBackground {
				x = "0.05 * ((1 * (safezoneW / safezoneH)) / 32)";
				y = "0.05 * ((1 / 1.2 * (safezoneW / safezoneH)) / 20)";
				w = "0.45 * ((1 * (safezoneW / safezoneH)) / 32)";
				h = "0.45 * ((1 / 1.2 * (safezoneW / safezoneH)) / 20)";
				color[] = {0.023529,0,0.0313725,1};
				texture = "#(argb,8,8,3)color(0,0,0,0.2)";
			};
			class UnitNumberText {
				x = "0.30 * ((1 * (safezoneW / safezoneH)) / 32)";
				y = "0.05 * ((1 / 1.2 * (safezoneW / safezoneH)) / 20)";
				w = "0.45 * ((1 * (safezoneW / safezoneH)) / 32)";
				h = "0.45 * ((1 / 1.2 * (safezoneW / safezoneH)) / 20)";
				colorText[] = {0.023529,0,0.0313725,1};
				font = "Zeppelin32";
				SizeEx = "((1 / 1.2 * (safezoneW / safezoneH)) / 20) * 0.5";
			};
			class UnitSpecialRole {
				x = "1.5 * ((1 * (safezoneW / safezoneH)) / 32)";
				y = "1.5 * ((1 / 1.2 * (safezoneW / safezoneH)) / 20)";
				w = "0.4 * ((1 * (safezoneW / safezoneH)) / 32)";
				h = "0.4 * ((1 / 1.2 * (safezoneW / safezoneH)) / 20)";
				color[] = {0.95,0.95,0.95,1};
			};
			class UnitRole {
				x = "0.1 * ((1 * (safezoneW / safezoneH)) / 32)";
				y = "0.5 * ((1 / 1.2 * (safezoneW / safezoneH)) / 20)";
				w = "0.4 * ((1 * (safezoneW / safezoneH)) / 32)";
				h = "0.4 * ((1 / 1.2 * (safezoneW / safezoneH)) / 20)";
				color[] = {0.023529,0,0.0313725,1};
			};
			class CombatMode {
				x = "0.5 * ((1 * (safezoneW / safezoneH)) / 32)";
				y = "0.5 * ((1 / 1.2 * (safezoneW / safezoneH)) / 20)";
				w = "0.4 * ((1 * (safezoneW / safezoneH)) / 32)";
				h = "0.4 * ((1 / 1.2 * (safezoneW / safezoneH)) / 20)";
			};
		};
		imageNoWeapons = "\ca\ui\data\cmdbar_unarmed_ca.paa";
	};
};
#else
class CfgInGameUI {
	class Menu {
		hideTime = 5; // 60;
	};
	class CommandBar {
		elementSpacing = 0;
		width = 0;
		height = 0;
		class prevPage {
			w = 0;
			h = 0;
		};
		class nextPage {
			w = 0;
			h = 0;
		};
		class UnitInfo {
			w = 0;
			h = 0;
			class GroupIcon {
				w = 0;
				h = 0;
			};
			class HcGroupText {
				w = 0;
				h = 0;
				SizeEx = 0;
			};
			class UnitBackground {
				w = 0;
				h = 0;
			};
			class UnitFocus {
				w = 0;
				h = 0;
			};
			class UnitIcon {
				w = 0;
				h = 0;
			};
			class Semaphore {
				w = 0;
				h = 0;
			};
			class CommandBackground {
				w = 0;
				h = 0;
			};
			class HoldFire {
				w = 0;
				h = 0;
			};
			class OrderBackground {
				w = 0;
				h = 0;
			};
			class OrderText {
				w = 0;
				h = 0;
				SizeEx = 0;
			};
			class VehicleBackground {
				w = 0;
				h = 0;
			};
			class VehicleText {
				w = 0;
				h = 0;
				SizeEx = 0;
			};
			class UnitSpecialRole {
				w = 0;
				h = 0;
			};
			class UnitRole {
				w = 0;
				h = 0;
			};
			class UnitNumberBackground {
				w = 0;
				h = 0;
			};
			class UnitNumberText {
				w = 0;
				h = 0;
				SizeEx = 0;
			};
			class CommandText {
				w = 0;
				h = 0;
				SizeEx = 0;
			};
			class VehicleNumberText {
				w = 0;
				h = 0;
				SizeEx = 0;
			};
			class VehicleNumberBackground {
				w = 0;
				h = 0;
			};
			class CombatMode {
				w = 0;
				h = 0;
			};
		};
	};
	class Cursor {
		/*meColor[] = {0,0,0,0.2};
		selectColor[] = {0.4,0.6745,0.2784,1};
		leaderColor[] = {0.863,0.584,0,1};
		missionFade = 0.3;
		missionColor1[] = {0.863,0.584,0,1};
		missionColor2[] = {0.863,0.584,0,1};
		customMarkColor[] = {0.4,0.6745,0.2784,1};
		unitUnconsciousColor[] = {0.196,0.592,0.706,1};
		iconTakeBackpack = "#(argb,8,8,3)color(1,1,0,1)";
		iconAssemble = "#(argb,8,8,3)color(1,1,0,1)";
		iconDisassemble = "#(argb,8,8,3)color(1,1,0,1)";
		color[] = {0.4,0.6745,0.2784,1};
		colorBackground[] = {0,0,0,0};
		colorLocked[] = {1,0,0,1};
		assaultColor[] = {0.706,0.0745,0.0196,1};
		boardColor[] = {0.863,0.584,0,1};
		iconMoveColor[] = {0.863,0.584,0,1};
		iconJoinColor[] = {0.863,0.584,0,1};
		iconHealAtColor[] = {0.863,0.584,0,1};
		iconRepairAtColor[] = {0.863,0.584,0,1};
		iconRearmAtColor[] = {0.863,0.584,0,1};
		iconRefuelAtColor[] = {0.863,0.584,0,1};
		iconSupportColor[] = {0.863,0.584,0,1};
		iconInFormationColor[] = {0.863,0.584,0,1};
		class Sign {
			height = 2.7;
			widthSector = 2.6;
			widthGroup = 2.5;
			widthUnit = 2.4;
		};
		enemyActiveColor[] = {0.706,0.0745,0.0196,1};
		throwCursorMinScale = 1;
		throwCursorMaxScale = 2;
		throwCursorFadeSpeed = 4;
		font = "EtelkaNarrowMediumPro";
		size = 0.034;
		activeWidth = 0.0392157;
		activeHeight = 0.0522876;
		activeMinimum = 1.1;
		activeMaximum = 1.1;
		aim = "\ca\ui\data\cursor_aim_ca.paa";
		weapon = "\ca\ui\data\cursor_w_airMG_gs.paa";*/
		
		outArrow = "#(argb,8,8,3)color(0,0,0,0)"; //"\ca\ui\data\icon_offarrow_ca.paa";
		
		/*select_target = "\ca\ui\data\cursor_w_target_gs.paa";
		lock_target = "\ca\ui\data\cursor_w_laserlock_gs.paa";
		gunner_lock = "\ca\ui\data\gunner_lock.paa";*/
		
		select = "#(argb,8,8,3)color(0,0,0,0)"; // "\ca\ui\data\icon_unit_ca.paa";
		
		/*selectOver = "\ca\ui\data\cursor_select_unit_ca.paa";
		me = "\ca\ui\data\cursor_circle_ca.paa";*/
		leader = "#(argb,8,8,3)color(0,0,0,0)"; // "\ca\ui\data\icon_unit_teamleader_ca.paa";
		
		/*mission = "\ca\ui\data\icon_task_ca.paa";
		unitUnconscious = "\ca\ui\data\icon_unit_agony_ca.paa";
		assault = "\ca\ui\data\icon_attack_ca.paa";
		board = "\ca\ui\data\icon_task_board_ca.paa";
		customMark = "\ca\ui\data\icon_custom_task_ca.paa";
		iconBoardIn = "\ca\ui\data\icon_board_into_ca.paa";
		iconBoardOut = "\ca\ui\data\icon_board_out_ca.paa";
		iconMove = "\ca\ui\data\icon_mission_move_ca.paa";
		iconJoin = "\ca\ui\data\icon_mission_join_ca.paa";
		iconHealAt = "#(argb,8,8,3)color(0,0,0,0)";
		iconRepairAt = "\ca\ui\data\icon_mission_repair_ca.paa";
		iconRearmAt = "\ca\ui\data\icon_mission_rearm_ca.paa";
		iconRefuelAt = "\ca\ui\data\icon_mission_refuel_ca.paa";
		iconComplex = "ca\ui\data\Cursor_hand_CA.paa";
		iconSupport = "#(argb,8,8,3)color(0,0,0,0)";
		iconInFormation = "#(argb,8,8,3)color(0,0,0,0)";
		iconCursorSupport = "\ca\ui\data\cursor_support_ca.paa";
		iconRepairVehicle = "\ca\ui\data\icon_mission_repair_ca.paa";
		tactical = "\ca\ui\data\cursor_tactical_ca.paa";
		move = "\ca\ui\data\cursor_basic_ca.paa";
		selected = "\ca\ui\data\cursor_selected_ca.paa";
		attack = "\ca\ui\data\cursor_attack_ca.paa";
		getIn = "\ca\ui\data\cursor_getin_ca.paa";
		watch = "\ca\ui\data\cursor_igui_scroll_ca.paa";
		dimmMe = 0.2;
		dimmMeStartTime = 5;
		dimmMeEndTime = 10;
		dimmCmdStartTime = 5;
		dimmCmdEndTime = 10;
		blinkingPeriod = 2;
		dimm = 0.15;
		shadow = 2;
		infoTextShadow = 2;*/
	};
};
#endif