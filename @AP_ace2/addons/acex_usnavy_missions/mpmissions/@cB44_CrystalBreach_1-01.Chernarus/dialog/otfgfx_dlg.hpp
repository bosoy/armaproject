/*
File:			otfgfx_dlg.hpp
Version:		1.00
Author:			Deadfast
Description:	Dialog for On-the-fly GFX Changer. Do not forget to #include this in your description.ext!
*/

class dfs_otfgfx_optionsDlg
{
	idd = 46212;

	class controls
	{
		class dfs_otfgfx_bg
		{
			idc = -1;
			type = 0;
			style = 48;
			x = 0.25;
			y = 0.2;
			w = 1.0;
			h = 0.7;
			colorText[] = {1, 1, 1, 1};
			colorBackground[] = {0,0,0,0};
			text = "\ca\ui\data\ui_mainmenu_background_ca.paa";
			font = "Zeppelin32";
			sizeEx = 0.032;
		};
		class dfs_otfgfx_header
		{
			access = ReadAndWrite;
			type = 13;
			idc = -1;
			style = 0x00;

			x = 0.29;
			y = 0.22;
			w = 0.7;
			h = 0.05;
			size = 0.043;
			lineSpacing = 1;

			colorBackground[] = {0,0,0,0};
			colorText[] = {0.6, 0.8392, 0.4706, 0};

			text = "Settings";

			class Attributes
			{
				font  = "Zeppelin33";
				color = "#ffcc00";
				align = "left";
				shadow = true;
			};
		};
		class dfs_otfgfx_vdinfo
		{
			access = ReadAndWrite;
			type = 13;
			idc = -1;
			style = 0x00;

			x = 0.3;
			y = 0.3;
			w = 0.2;
			h = 0.05;
			sizeEx = 0.032;
			size = 0.032;
			lineSpacing = 1;

			colorBackground[] = {0,0,0,0};
			colorText[] = {0.6, 0.8392, 0.4706, 0};

			text = "View distance:";
			font  = "Zeppelin32";
			class Attributes
			{
				font  = "Zeppelin33";
				color = "#ffffff";
				align = "left";
				shadow = false;
			};
		};
		class dfs_otfgfx_vdcur : dfs_otfgfx_vdinfo
		{
			idc = 11;
			x = 0.48;
			text = "1000 m";

			class Attributes
			{
				font  = "Zeppelin32";
				color = "#ffffff";
				align = "left";
				shadow = false;
			};
		};
		class dfs_otfgfx_vdSlider
		{
			idc = 12;
			type = 43;
			style = 0x400  + 0x10;
			x = 0.3;
			y = 0.36;
			h = 0.03;
			w = 0.42;
			color[] = {1, 1, 1, 0.4};
			colorActive[] = {1, 1, 1, 1};
			colorDisabled[] = {1, 1, 1, 0.2};
			arrowEmpty = "\ca\ui\data\ui_arrow_left_ca.paa";
			arrowFull = "\ca\ui\data\ui_arrow_left_active_ca.paa";
			border = "\ca\ui\data\ui_border_frame_ca.paa";
			thumb = "\ca\ui\data\ui_slider_bar_ca.paa";

			onSliderPosChanged = "_this call DFS_otfgfx_sliderChange";
		};

		class dfs_otfgfx_tdinfo: dfs_otfgfx_vdinfo
		{
			y = 0.45;
			text = "Terrain detail:";
		};
		class dfs_otfgfx_tdcur : dfs_otfgfx_tdinfo
		{
			idc = 21;
			x = 0.48;
			text = "1/5";

			class Attributes
			{
				font  = "Zeppelin32";
				color = "#ffffff";
				align = "left";
				shadow = false;
			};
		};
		class dfs_otfgfx_tdSlider : dfs_otfgfx_vdSlider
		{
			idc = 22;
			y = 0.51;
			onSliderPosChanged = "_this call DFS_otfgfx_sliderChange";
		};
		class dfs_otfgfx_commit
		{
			idc = -1;
			type = 16;
			style = 0;

			text = "  Commit!";
			action = "[sliderPosition 12, sliderPosition 22] spawn DFS_otfgfx_commit;";

			x = 0.4;
			y = 0.57;
			w = 0.23;
			h = 0.104575;
			size = 0.03921;
			sizeEx = 0.03921;

			color[] = {0.543, 0.5742, 0.4102, 1.0};
			color2[] = {0.95, 0.95, 0.95, 1};
			colorBackground[] = {1, 1, 1, 1};
			colorbackground2[] = {1, 1, 1, 0.4};
			colorDisabled[] = {1, 1, 1, 0.25};
			periodFocus = 1.2;
			periodOver = 0.8;

			class HitZone
			{
				left = 0.004;
				top = 0.029;
				right = 0.004;
				bottom = 0.029;
			};

			class ShortcutPos
			{
				left = 0.0145;
				top = 0.026;
				w = 0.0392157;
				h = 0.0522876;
			};

			class TextPos
			{
				left = 0.05;
				top = 0.034;
				right = 0.005;
				bottom = 0.005;
			};


			textureNoShortcut = "";
			animTextureNormal = "\ca\ui\data\ui_button_normal_ca.paa";
			animTextureDisabled = "\ca\ui\data\ui_button_disabled_ca.paa";
			animTextureOver = "\ca\ui\data\ui_button_over_ca.paa";
			animTextureFocused = "\ca\ui\data\ui_button_focus_ca.paa";
			animTexturePressed = "\ca\ui\data\ui_button_down_ca.paa";
			animTextureDefault = "\ca\ui\data\ui_button_default_ca.paa";
			period = 0.4;
			font = "Zeppelin32";


			soundEnter[] = {"\ca\ui\data\sound\mouse2", 0.09, 1};
			soundPush[] = {"\ca\ui\data\sound\new1", 0.09, 1};
			soundClick[] = {"\ca\ui\data\sound\mouse3", 0.07, 1};
			soundEscape[] = {"\ca\ui\data\sound\mouse1", 0.09, 1};

			class Attributes
			{
				font = "Zeppelin32";
				color = "#E5E5E5";
				align = "left";
				shadow = "true";
			};

			class AttributesImage
			{
				font = "Zeppelin32";
				color = "#E5E5E5";
				align = "left";
				shadow = "true";
			};
		};
		class dfs_otfgfx_close : dfs_otfgfx_commit
		{
			x = 0.42;
			y = 0.69;
			w = 0.183825;
			h = 0.104575;
			text = " Close";
			action = "closeDialog 0;";
		};
	};
};