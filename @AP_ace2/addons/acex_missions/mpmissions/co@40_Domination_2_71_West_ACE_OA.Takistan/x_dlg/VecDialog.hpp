class XD_VecDialog {
	idd = -1;
	movingEnable = 1;
	onLoad = "uiNamespace setVariable ['X_VEC_DIALOG', _this select 0];d_vec_dialog_open = true;d_do_ma_update_n = true";
	onUnLoad = "uiNamespace setVariable ['X_VEC_DIALOG', nil];d_vec_dialog_open = false;d_do_ma_update_n = false";
	objects[] = {};
	class controlsBackground {
		class XD_BackGround : XD_RscPicture {
			x = 0.1;
			y = 0;
			w = 1.0349;
			h = 1.03;
			colorBackground[] = {0,0,0,0};
			text = __UI_Path(ui_background_controls_ca.paa);
		};
	};
	class controls {
		class XD_CloseButton: XD_ButtonBase {
			idc = -1;
			text = "$STR_DOM_MISSIONSTRING_1218"; 
			action = "closeDialog 0";
			default = true;
			x = 0.6;
			y = 0.91;
		};
		class Dom2 : XC_RscText {
			x = 0.14;
			y = 0.91;
			w = 0.25;
			h = 0.1;
			sizeEx = 0.035;
			colorBackground[] = {1, 1, 1, 0};
			XCMainCapt;
			text = __DOM_NVER_STR__;
		};
		class XD_VecDialogCaption : XC_RscText {
			x = 0.18;
			y = 0.01;
			w = 0.25;
			h = 0.1;
			sizeEx = 0.04;
			colorBackground[] = {1, 1, 1, 0};
			colorText[] = {0.643, 0.5742, 0.4102, 1};
			text = "$STR_DOM_MISSIONSTRING_1322";
		};
		class XD_VecPicture : XD_RscPicture {
			idc = 44444;
			x=0.43; y=0.145; w=0.1; h=0.1;
			text="";
			sizeEx = 256;
		};
		class XD_VecDialogCaption2 : XC_RscText {
			idc = 44445;
			x = 0.55;
			y = 0.15;
			w = 0.25;
			h = 0.1;
			sizeEx = 0.032;
			colorBackground[] = {1, 1, 1, 0};
			colorText[] = {0.643, 0.5742, 0.4102, 1};
			text = "Chopper 1";
		};
		class XD_AmmoBoxCaption : XC_RscText {
			idc = 44454;
			x = 0.24;
			y = 0.25;
			w = 0.25;
			h = 0.1;
			colorBackground[] = {1, 1, 1, 0};
			XCTextBlack;
			text = "$STR_DOM_MISSIONSTRING_1323";
		};
		class XD_BoxPicture : XD_RscPicture {
			idc = 44446;
			x=0.23; y=0.3; w=0.17; h=0.17;
			text="";
			sizeEx = 256;
		};
		class XD_BoxPicture2 : XD_RscPicture {
			idc = 44447;
			x=0.25; y=0.325; w=0.12; h=0.12;
			text="";
			sizeEx = 256;
		};
		class XD_DropAmmoButton: XD_ButtonBase {
			idc = 44448;
			text = "$STR_DOM_MISSIONSTRING_1324"; 
			action = "closeDialog 0;[vehicle player, player] call d_fnc_x_dropammoboxd";
			x = 0.20;
			y = 0.47;
		};
		class XD_LoadAmmoButton: XD_ButtonBase {
			idc = 44452;
			text = "$STR_DOM_MISSIONSTRING_1325"; 
			action = "closeDialog 0;[vehicle player, player] call d_fnc_x_loaddropped";
			x = 0.20;
			y = 0.53;
		};
		class XD_CreateVecCaption : XC_RscText {
			idc = 44450;
			x = 0.50;
			y = 0.25;
			w = 0.25;
			h = 0.1;
			colorBackground[] = {1, 1, 1, 0};
			XCTextBlack;
			text = "$STR_DOM_MISSIONSTRING_1326";
		};
		class XD_CreateListbox : SXRscListBox {
			idc = 44449;
			x = 0.50;
			y = 0.35;
			w = 0.275;
			h = 0.20;
			sizeEx = 0.023;
			rowHeight = 0.06;
			style = ST_LEFT;
			borderSize = 1;
		};
		class XD_CreateVecButton: XD_ButtonBase {
			idc = 44451;
			text = "$STR_DOM_MISSIONSTRING_1326"; 
			action = "call d_fnc_x_create_vec";
			x = 0.52;
			y = 0.59;
		};
		class XD_TeleportButton: XD_ButtonBase {
			idc = 44453;
			text = "$STR_DOM_MISSIONSTRING_1250"; 
			action = "closeDialog 0;call d_fnc_x_teleport";
			x = 0.20;
			y = 0.59;
		};
		class XD_SATViewButton: XD_ButtonBase {
			idc = 44459;
			text = "$STR_DOM_MISSIONSTRING_1327"; 
			action = "closeDialog 0;call d_fnc_SatellitenBildd";
			x = 0.20;
			y = 0.65;
		};
		class XD_DeployMHQ: XD_ButtonBase {
			idc = 44462;
			text = "$STR_DOM_MISSIONSTRING_1328"; 
			action = "closeDialog 0;call d_fnc_x_deploymhq";
			x = 0.37;
			y = 0.75;
		};
	};
};
