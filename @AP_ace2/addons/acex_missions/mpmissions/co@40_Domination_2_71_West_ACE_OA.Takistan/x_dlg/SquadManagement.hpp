// by Xeno
#include "x_setup.sqf"

class XD_RscControlsGroup {
	class VScrollbar {
		color[] = {1,1,1,1};
		width = 0.021;
		autoScrollSpeed = -1;
		autoScrollDelay = 5;
		autoScrollRewind = 0;
		shadow = 0;
	};
	class HScrollbar {
		color[] = {1,1,1,1};
		height = 0.028;
		shadow = 0;
	};
	class ScrollBar {
		color[] = {1,1,1,0.6};
		colorActive[] = {1,1,1,1};
		colorDisabled[] = {1,1,1,0.3};
		shadow = 0;
		thumb = "\ca\ui\data\ui_scrollbar_thumb_ca.paa";
		arrowFull = "\ca\ui\data\ui_arrow_top_active_ca.paa";
		arrowEmpty = "\ca\ui\data\ui_arrow_top_ca.paa";
		border = "\ca\ui\data\ui_border_scroll_ca.paa";
	};
	class Controls {};
	type = 15;
	idc = -1;
	x = 0;
	y = 0;
	w = 1;
	h = 1;
	shadow = 0;
	style = 16;
};

class XD_SquadManagementDialog {
	idd = -1;
	movingEnable = 1;
	onLoad = "uiNamespace setVariable ['X_SQUADMANAGEMENT_DIALOG', _this select 0];d_squadmanagement_dialog_open = true;call d_fnc_squadmanagementfill";
	onUnLoad = "uiNamespace setVariable ['X_SQUADMANAGEMENT_DIALOG', nil];d_SQMGMT_grps = nil;d_squadmanagement_dialog_open = false";
	class controlsBackground {
		class XD_BackGround : RscBG {
			x = "SafeZoneXAbs";
			y = "SafeZoneY";
			w = "safeZoneWAbs";
			h = "SafeZoneH";
			colorBackground[] = {0.106, 0.133, 0.102, 0.9};
		};
	};
	class controls {
		class XD_MainCaption : XC_RscText {
			x = "SafeZoneX + 0.02";
			y = "SafeZoneY + 0.01";
			w = 0.25;
			h = 0.1;
			sizeEx = 0.035;
			colorBackground[] = {1, 1, 1, 0};
			colorText[] = {0.643, 0.5742, 0.4102, 1};
			text = "SQUAD MANAGEMENT";
		};
		class Dom2 : XD_MainCaption {
			x = "SafeZoneX + 0.05";
			y = "SafeZoneY + SafeZoneH - 0.1";
			XCMainCapt;
			text = __DOM_NVER_STR__;
		};
		class GroupsControlsGroup : XD_RscControlsGroup {
			x = "SafeZoneX + 0.02";
			y = "SafeZoneY + 0.1";
			w = "SafeZoneW - 0.05";
			h = "SafeZoneH - 0.2";
			__EXEC(bgidc = 1000)
			__EXEC(lbidc = 2000)
			__EXEC(buidc = 3000)
			__EXEC(txtidc = 4000)
			__EXEC(butnum = 5000)
			class Controls {
				class BackGround0 : XD_RscPicture {
					idc = __EVAL(bgidc);
					__EXEC(xposbg = 0.005)
					x = __EVAL(xposbg);
					__EXEC(yposbg = 0.005)
					y = __EVAL(yposbg);
					w = 0.5;
					h = 0.39;
					colorBackground[] = {0,0,0,0};
					text = __UI_Path(ui_background_controls_ca.paa);
				};
				class GroupListBox0 : SXRscListBox {
					idc = __EVAL(lbidc);
					__EXEC(xposlb = 0.025)
					x = __EVAL(xposlb);
					__EXEC(yposlb = 0.06)
					y = __EVAL(yposlb);
					w = 0.35;
					h = 0.265;
					__EXEC(_numlbstr = str lbidc)
					onLBSelChanged = __EVAL("[" + _numlbstr + ",_this] call d_fnc_squadmgmtlbchanged");
				};
				class LeaveJoinButton0 : XD_ButtonBase {
					idc = __EVAL(buidc);
					__EXEC(xposbu = 0.172)
					x = __EVAL(xposbu);
					__EXEC(yposbu = 0.3145)
					y = __EVAL(yposbu);
					text = "Join";
					__EXEC(_numbstr = str butnum)
					action = __EVAL(_numbstr + " call d_fnc_squadmgmtbuttonclicked");
				};
				class GroupText0 : SXRscText {
					idc = __EVAL(txtidc);
					__EXEC(xpostxt = 0.025)
					x = __EVAL(xpostxt);
					__EXEC(ypostxt = 0.017)
					y = __EVAL(ypostxt);
					w = 0.3;
					h = 0.03;
					sizeEx = 0.023;
					shadow = 0;
					text = "Groupname";
				};
				
				#define NewControl(tname,xplus,yplus) \
				class BackGround##tname : BackGround0 { \
					__EXEC(bgidc = bgidc + 1) \
					idc = __EVAL(bgidc); \
					__EXEC(xposbg = xposbg + xplus) \
					x = __EVAL(xposbg); \
					__EXEC(yposbg = yposbg + yplus) \
					y = __EVAL(yposbg); \
				}; \
				class GroupListBox##tname : GroupListBox0 { \
					__EXEC(lbidc = lbidc + 1) \
					idc = __EVAL(lbidc); \
					__EXEC(xposlb = xposlb + xplus) \
					x = __EVAL(xposlb); \
					__EXEC(yposlb = yposlb + yplus) \
					y = __EVAL(yposlb); \
					__EXEC(_numlbstr = str lbidc) \
					onLBSelChanged = __EVAL("[" + _numlbstr + ",_this] call d_fnc_squadmgmtlbchanged"); \
				}; \
				class LeaveJoinButton##tname : LeaveJoinButton0 { \
					__EXEC(buidc = buidc + 1) \
					idc = __EVAL(buidc); \
					__EXEC(xposbu = xposbu + xplus) \
					x = __EVAL(xposbu); \
					__EXEC(yposbu = yposbu + yplus) \
					y = __EVAL(yposbu); \
					__EXEC(butnum = butnum + 1) \
					__EXEC(_numbstr = str butnum) \
					action = __EVAL(_numbstr + " call d_fnc_squadmgmtbuttonclicked"); \
				}; \
				class GroupText##tname : GroupText0 { \
					__EXEC(txtidc = txtidc + 1) \
					idc = __EVAL(txtidc); \
					__EXEC(xpostxt = xpostxt + xplus) \
					x = __EVAL(xpostxt); \
					__EXEC(ypostxt = ypostxt + yplus) \
					y = __EVAL(ypostxt); \
				};
				
				NewControl(1,0.47,0);
				NewControl(2,0.47,0);
				NewControl(3,0.47,0);
				
				__EXEC(xposbg = 0.005)
				__EXEC(xposlb = 0.025)
				__EXEC(xposbu = 0.172)
				__EXEC(xpostxt = 0.025)
				NewControl(4,0,0.45);
				NewControl(5,0.47,0);
				NewControl(6,0.47,0);
				NewControl(7,0.47,0);
				
				__EXEC(xposbg = 0.005)
				__EXEC(xposlb = 0.025)
				__EXEC(xposbu = 0.172)
				__EXEC(xpostxt = 0.025)
				NewControl(8,0,0.45);
				NewControl(9,0.47,0);
				NewControl(10,0.47,0);
				NewControl(11,0.47,0);
				
				__EXEC(xposbg = 0.005)
				__EXEC(xposlb = 0.025)
				__EXEC(xposbu = 0.172)
				__EXEC(xpostxt = 0.025)
				NewControl(12,0,0.45);
				NewControl(13,0.47,0);
				NewControl(14,0.47,0);
				NewControl(15,0.47,0);
				
				__EXEC(xposbg = 0.005)
				__EXEC(xposlb = 0.025)
				__EXEC(xposbu = 0.172)
				__EXEC(xpostxt = 0.025)
				NewControl(16,0,0.45);
				NewControl(17,0.47,0);
				NewControl(18,0.47,0);
				NewControl(19,0.47,0);
				
				__EXEC(xposbg = 0.005)
				__EXEC(xposlb = 0.025)
				__EXEC(xposbu = 0.172)
				__EXEC(xpostxt = 0.025)
				NewControl(20,0,0.45);
				NewControl(21,0.47,0);
				NewControl(22,0.47,0);
				NewControl(23,0.47,0);
				
				__EXEC(xposbg = 0.005)
				__EXEC(xposlb = 0.025)
				__EXEC(xposbu = 0.172)
				__EXEC(xpostxt = 0.025)
				NewControl(24,0,0.45);
				NewControl(25,0.47,0);
				NewControl(26,0.47,0);
				NewControl(27,0.47,0);
			};
		};
		class XD_CloseButton: XD_ButtonBase {
			text = "Close"; 
			action = "closeDialog 0";
			default = true;
			x = "SafeZoneX + SafeZoneW - 0.3";
			y = "SafeZoneY + SafeZoneH - 0.1";
		};
	};
};
