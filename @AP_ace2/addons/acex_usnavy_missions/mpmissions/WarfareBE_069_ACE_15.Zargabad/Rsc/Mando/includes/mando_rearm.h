class MandoMissileRearmDlg
{
   idd = 1;
   movingEnable = 1;
   onLoad = "[""onLoad"", _this] call mando_missile_rearm";
   onUnload = "[""onUnLoad"", _this] call mando_missile_rearm";
   onMouseButtonDown  = "[""onMouseClick"", _this] call mando_missile_rearm";
   onMouseZChanged  = "[""onMouseZChanged"", _this] call mando_missile_rearm";

   controlsBackground[] = {MMA_CFG_SOURCE_CURRENT, MMA_CFG_BACK_SHADOW, MMA_CFG_BACK, MMA_CFG_WEAPONS_FRAME, MMA_CFG_CURRENT_FRAME,MMA_CFG_PRECONF_FRAME,MMA_CFG_SOURCE_FRAME,MMA_CFG_SOURCE_BACK,MMA_CFG_SOURCE_LEVEL};

   class MMA_CFG_SOURCE_CURRENT
   {
      idc = 11;
      type = 0;
      colorText[] = {0.5, 1, 0.5, 1};
      font = "Bitstream";
      colorBackground[] = {0, 0, 0, 1};
      text = "";
      style = 48;
      sizeEx = 0.015;
      x = 0.5 - (0.17*3/4)/2;
      y = 0.5 - (0.17/2);
      w = 0.17*3/4 ;
      h = 0.17;
   };

   class MMA_CFG_BACK
   {
        type = 0;
        style = 128;
        idc = -1;
        x = 0.2 - 0.08 - 0.2;
        y = 0.68 - 0.07+0.05;
        w = 0.76 + 0.2;
        h = 0.33 + 0.13 ;
        text = "";
        colorBackground[] = {0.3, 0.3, 0.5, 1};
        colorText[] = {1, 1, 1, 1};
        font = "Bitstream";
        sizeEx = 0.02;
   };

   class MMA_CFG_BACK_SHADOW
   {
        type = 0;
        style = 128;
        idc = -1;
        x = 0.2 - 0.08+0.007 - 0.2;
        y = 0.68 - 0.07+0.05+0.01;
        w = 0.76 + 0.2;
        h = 0.33 + 0.13 ;
        text = "";
        colorBackground[] = {0.2, 0.2, 0.3, 1};
        colorText[] = {1, 1, 1, 1};
        font = "Bitstream";
        sizeEx = 0.02;
   };

   class MMA_CFG_WEAPONS_FRAME
   {
      idc = 23;
      type = 0;
      style = 128;
      colorText[] = {1, 1, 1, 1};
      colorBackground[] = {0.3, 0.3, 0.5, 1};
      text = "";
      font = "Bitstream";
      sizeEx = 0.02;

      x = 0.2-0.11-0.01- 0.12;
      y = 0.67-2.5;
      w = 0.46+0.14;
      h = 0.33+0.01;
   };

   class MMA_CFG_CURRENT_FRAME
   {
      idc = -1;
      type = 0;
      style = 64;
      colorText[] = {1, 1, 1, 1};
      colorBackground[] = {0, 0, 0, 0};
      text = "Current weapons and magazines";
      font = "Zeppelin32";
      sizeEx = 0.03;

      x = 0.2-0.11-0.01+0.49- 0.12-0.23 - 0.08 - 0.2;
      y = 0.67-0.005+0.05;
      w = 0.23+0.01+0.23;
      h = 0.33+0.015-0.05;
   };

   class MMA_CFG_PRECONF_FRAME
   {
      idc = -1;
      type = 0;
      style = 64;
      colorText[] = {1, 1, 1, 1};
      colorBackground[] = {0, 0, 0, 0};
      text = "Configurations";
      font = "Zeppelin32";
      sizeEx = 0.03;

      x = 0.2-0.11-0.01+0.49+0.13 - 0.08 - 0.2;
      y = 0.67-0.005+0.05;
      w = 0.23+0.01 + 0.2;
      h = 0.33+0.015-0.05;
   };

   class MMA_CFG_SOURCE_FRAME
   {
      idc = -1;
      type = 0;
      style = 64;
      colorText[] = {1, 1, 1, 1};
      colorBackground[] = {0, 0, 0, 0};
      text = "Rearming and weapons source level";
      font = "Zeppelin32";
      sizeEx = 0.03;

      x = 0.2-0.11-0.01+0.49- 0.12-0.23 - 0.08 - 0.2;
      y = 0.67-0.005+0.05 + 0.33+0.015-0.05 + 0.01;
      w = 0.23+0.01+0.23 + 0.23+0.01+0.01;
      h = 0.08;
   };

   class MMA_CFG_SOURCE_BACK
   {
        type = 0;
        style = 2;
        idc = 10;
        x = 0.15 - 0.2;
        y = 1.05;
        w = 0.5 + 0.2;
        h = 0.04;
        text = "";
        colorBackground[] = {0.2, 0.2, 0.3, 0.95};
        colorText[] = {1, 1, 1, 1};
        font = "Zeppelin32";
        sizeEx = 0.03;
   };

   class MMA_CFG_SOURCE_LEVEL
   {
        type = 0;
        style = 0;
        idc = 9;
        x = 0.15 - 0.2;
        y = 1.055;
        w = 0.3 + 0.2;
        h = 0.03;
        text = "";
        colorBackground[] = {0.6, 0.6, 0.8, 0.7};
        colorText[] = {1, 1, 1, 1};
        font = "Bitstream";
        sizeEx = 0.02;
   };


   controls[]= {MMA_CFG_PANLEFT,MMA_CFG_PANRIGHT,MMA_CFG_TITLE, MMA_CFG_WEAPONS,MMA_CFG_MAGAZINES,MMA_CFG_VIRTUAL, MMA_CFG_CURRENTW,MMA_CFG_CURRENTM,MMA_CFG_PRECONF,MMA_CFG_PRECONF_WEAPONS, MMA_CFG_CLEARW,MMA_CFG_CLEARM,MMA_CFG_ADD,MMA_CFG_REARM};

   class MMA_CFG_PANLEFT
   {
      type = 1;
      style = 2+256;
      idc = 12;

      x = safeZoneX+safeZoneW-0.05*2*3/4-0.02;
      y = safeZoneY+safeZoneH-0.06;
      w = 0.05*3/4;
      h = 0.05;

      onMouseHolding  = "[""CALL_PAN_LEFT"", _this] call mando_missile_rearm";

      sizeEx = 0.03;
      text = "<<";
      action = "[""CALL_PAN_LEFT"", []] call mando_missile_rearm";
      SetFocus = "false";

	access = ReadAndWrite;
        colorText[] = {1, 1, 1, 1};
        font = "Bitstream";
	soundEnter[] = {"\ca\ui\data\sound\mouse2",0.09,1};
        soundPush[] = {"\ca\ui\data\sound\new1",0.09,1};
        soundClick[] = {"\ca\ui\data\sound\mouse3",0.07,1};
        soundEscape[] = {"\ca\ui\data\sound\mouse1",0.09,1};
        default = false;

        colorDisabled[] = {0.3, 0.3, 0.3, 1};
        colorBackground[] = {0.6, 0.6, 0.8, 0.95};
        colorBackgroundActive[] = {0.6, 0.6, 0.8, 0.95};
        colorBackgroundDisabled[] = {0.5, 0.5, 0.5, 1.0};
        colorFocused[] = {0.6, 0.6, 0.8, 0.95};
        colorShadow[] = {0,0,0,0.2};
        colorBorder[] = {0,0,0,1};

        offsetX = 0.000;
        offsetY = 0.000;
        offsetPressedX = 0.000;
        offsetPressedY = 0.000;
        borderSize = 0.0;
   };

   class MMA_CFG_PANRIGHT
   {
      type = 1;
      style = 2+256;
      idc = 13;

      x = safeZoneX+safeZoneW-0.05*3/4-0.01;
      y = safeZoneY+safeZoneH-0.06;
      w = 0.05*3/4;
      h = 0.05;

      onMouseHolding  = "[""CALL_PAN_RIGHT"", _this] call mando_missile_rearm";

      sizeEx = 0.03;
      text = ">>";
      action = "[""CALL_PAN_RIGHT"", []] call mando_missile_rearm";
      SetFocus = "false";

	access = ReadAndWrite;
        colorText[] = {1, 1, 1, 1};
        font = "Bitstream";
	soundEnter[] = {"\ca\ui\data\sound\mouse2",0.09,1};
        soundPush[] = {"\ca\ui\data\sound\new1",0.09,1};
        soundClick[] = {"\ca\ui\data\sound\mouse3",0.07,1};
        soundEscape[] = {"\ca\ui\data\sound\mouse1",0.09,1};
        default = false;

        colorDisabled[] = {0.3, 0.3, 0.3, 1};
        colorBackground[] = {0.6, 0.6, 0.8, 0.95};
        colorBackgroundActive[] = {0.6, 0.6, 0.8, 0.95};
        colorBackgroundDisabled[] = {0.5, 0.5, 0.5, 1.0};
        colorFocused[] = {0.6, 0.6, 0.8, 0.95};
        colorShadow[] = {0,0,0,0.2};
        colorBorder[] = {0,0,0,1};

        offsetX = 0.000;
        offsetY = 0.000;
        offsetPressedX = 0.000;
        offsetPressedY = 0.000;
        borderSize = 0.0;
   };


   class MMA_CFG_TITLE
   {
        type = 0;
        moving = 1;
        LBDragging   = "[""onDrag"", _this] call mando_missile_rearm";
        style = "0x02 + 0x100";
        font = "Zeppelin32";
        sizeEx = 0.05;
        colorText[] = {0.95,0.95,0.95,1};
        idc = -1;
        x = 0.2+0.14-0.02 - 0.12 - 0.08 - 0.1;
        y = 0.68 - 0.06 - 0.005 + 0.05;
        w = 0.82 + 0.04 -0.1;
        h = 0.05 ;
        text = "MMA Rearming System";
        colorBackground[] = {0.3, 0.3, 0.5, 0};
   };

   class MMA_CFG_REARM
   {
      type = 1;
      style = 2+256;

      idc = 8;
      x = 0.67;
      y = 1.05;
      w = 0.17;
      h = 0.04;

      sizeEx = 0.03;
      text = "Rearm vehicle";
      action = "[""CALL_REARM"", []] call mando_missile_rearm";
      SetFocus = "false";

	access = ReadAndWrite;
        colorText[] = {1, 1, 1, 1};
        font = "Bitstream";
	soundEnter[] = {"\ca\ui\data\sound\mouse2",0.09,1};
        soundPush[] = {"\ca\ui\data\sound\new1",0.09,1};
        soundClick[] = {"\ca\ui\data\sound\mouse3",0.07,1};
        soundEscape[] = {"\ca\ui\data\sound\mouse1",0.09,1};
        default = false;

        colorDisabled[] = {0.3, 0.3, 0.3, 1};
        colorBackground[] = {0.6, 0.6, 0.8, 0.95};
        colorBackgroundActive[] = {0.6, 0.6, 0.8, 0.95};
        colorBackgroundDisabled[] = {0.5, 0.5, 0.5, 1.0};
        colorFocused[] = {0.6, 0.6, 0.8, 0.95};
        colorShadow[] = {0,0,0,0.2};
        colorBorder[] = {0,0,0,1};

        offsetX = 0.005;
        offsetY = 0.005;
        offsetPressedX = 0.005;
        offsetPressedY = 0.005;
        borderSize = 0.0;
   };


   class MMA_CFG_ADD
   {
      type = 1;
      style = 2;

      idc = 20;
      x = 0.44;
      y = 0.7-2.5;
      w = 0.1;
      h = 0.03;

      sizeEx = 0.03;
      text = "Add W/M";
      action = "[""CALL_CFG_ADD"", []] call mando_missile_rearm";
      SetFocus = "false";

	access = ReadAndWrite;
        colorText[] = {1, 1, 1, 1};
        font = "Bitstream";
	soundEnter[] = {"\ca\ui\data\sound\mouse2",0.09,1};
        soundPush[] = {"\ca\ui\data\sound\new1",0.09,1};
        soundClick[] = {"\ca\ui\data\sound\mouse3",0.07,1};
        soundEscape[] = {"\ca\ui\data\sound\mouse1",0.09,1};
        default = false;

        colorDisabled[] = {0.3, 0.3, 0.3, 1};
        colorBackground[] = {0.2, 0.3, 0.5, 1.0};
        colorBackgroundActive[] = {0.2,0.3,0.5,1.0};
        colorBackgroundDisabled[] = {0.5, 0.5, 0.5, 1.0};
        colorFocused[] = {0.2,0.3,0.5,0.2};
        colorShadow[] = {0,0,0,0.1};
        colorBorder[] = {0,0,0,1};

        offsetX = 0.000;
        offsetY = 0.002;
        offsetPressedX = 0.000;
        offsetPressedY = 0.002;
        borderSize = 0.0;
   };

   class MMA_CFG_CLEARW
   {
      type = 1;
      style = 2;

      idc = 21;
      x = 0.44;
      y = 0.74-2.5;
      w = 0.1;
      h = 0.03;

      sizeEx = 0.03;
      text = "Remove W.";
      action = "[""CALL_CFG_CLEAR"", []] call mando_missile_rearm";
      SetFocus = "false";

	access = ReadAndWrite;
        colorText[] = {1, 1, 1, 1};
        font = "Bitstream";
	soundEnter[] = {"\ca\ui\data\sound\mouse2",0.09,1};
        soundPush[] = {"\ca\ui\data\sound\new1",0.09,1};
        soundClick[] = {"\ca\ui\data\sound\mouse3",0.07,1};
        soundEscape[] = {"\ca\ui\data\sound\mouse1",0.09,1};
        default = false;

        colorDisabled[] = {0.3, 0.3, 0.3, 1};
        colorBackground[] = {0.2, 0.3, 0.5, 1.0};
        colorBackgroundActive[] = {0.2,0.3,0.5,1.0};
        colorBackgroundDisabled[] = {0.5, 0.5, 0.5, 1.0};
        colorFocused[] = {0.2,0.3,0.5,0.2};
        colorShadow[] = {0,0,0,0.1};
        colorBorder[] = {0,0,0,1};

        offsetX = 0.000;
        offsetY = 0.002;
        offsetPressedX = 0.000;
        offsetPressedY = 0.002;
        borderSize = 0.0;
   };

   class MMA_CFG_CLEARM
   {
      type = 1;
      style = 2;

      idc = 22;
      x = 0.44;
      y = 0.78-2.5;
      w = 0.1;
      h = 0.03;

      sizeEx = 0.03;
      text = "Remove M.";
      action = "[""CALL_CFG_CLEARM"", []] call mando_missile_rearm";
      SetFocus = "false";

	access = ReadAndWrite;
        colorText[] = {1, 1, 1, 1};
        font = "Bitstream";
	soundEnter[] = {"\ca\ui\data\sound\mouse2",0.09,1};
        soundPush[] = {"\ca\ui\data\sound\new1",0.09,1};
        soundClick[] = {"\ca\ui\data\sound\mouse3",0.07,1};
        soundEscape[] = {"\ca\ui\data\sound\mouse1",0.09,1};
        default = false;

        colorDisabled[] = {0.3, 0.3, 0.3, 1};
        colorBackground[] = {0.2, 0.3, 0.5, 1.0};
        colorBackgroundActive[] = {0.2,0.3,0.5,1.0};
        colorBackgroundDisabled[] = {0.5, 0.5, 0.5, 1.0};
        colorFocused[] = {0.2,0.3,0.5,0.2};
        colorShadow[] = {0,0,0,0.1};
        colorBorder[] = {0,0,0,1};

        offsetX = 0.000;
        offsetY = 0.002;
        offsetPressedX = 0.000;
        offsetPressedY = 0.002;
        borderSize = 0.0;
   };

   class MMA_CFG_WEAPONS
   {
      access = 0;
      type = 5;
      style = 0;

      idc = 1;
      x = 0.2-0.11 -  0.12;
      y = 0.7-2.5;
      w = 0.22;
      h = 0.3;

      onLBSelChanged = "[""CALL_CFG_CHANGE"", _this] call mando_missile_rearm";
      wholeHeight = 0.4;
      colorSelect[] = {1.0, 1.0, 1.0, 1};
      colorText[] = {0.75, 0.75, 0.75, 1};
      colorBackground[] = {0, 0, 0, 1};
      colorSelectBackground[] = {0.2, 0.2, 0.5, 0.6};
      colorSelect2[] = {0.95,0.95,0.95,1};
      colorSelectBackground2[] = {0.1,0.1,0.2,0.5};
      font = "Zeppelin32";
      sizeEx = 0.025;
      soundSelect[] = {"", 0.1, 1};

      maxHistoryDelay = 1;
      autoScrollSpeed = -1;
      autoScrollDelay = 5;
      autoScrollRewind = 0;
      rowHeight = 0.03;

      class ScrollBar
      {
         color[] = {1,1,1,0.6};
         colorActive[] = {1,1,1,1};
         colorDisabled[] = {1,1,1,0.3};
         thumb = "\ca\ui\data\ui_scrollbar_thumb_ca.paa";
         arrowFull = "\ca\ui\data\ui_arrow_top_active_ca.paa";
         arrowEmpty = "\ca\ui\data\ui_arrow_top_ca.paa";
         border = "\ca\ui\data\ui_border_scroll_ca.paa";
      };
   };

   class MMA_CFG_MAGAZINES
   {
      access = 0;
      type = 5;
      style = 0;

      idc = 2;
      x = 0.44-0.11-  0.12;
      y = 0.7-2.5;
      w = 0.22;
      h = 0.3;


      wholeHeight = 0.4;
      colorSelect[] = {1.0, 1.0, 1.0, 1};
      colorText[] = {0.75, 0.75, 0.75, 1};
      colorBackground[] = {0.0, 0.0, 0.0, 1};
      colorSelectBackground[] = {0.2, 0.2, 0.5, 0.6};
      colorSelect2[] = {0.95,0.95,0.95,1};
      colorSelectBackground2[] = {0.1,0.1,0.2,0.5};

      font = "Bitstream";
      sizeEx = 0.025;
      soundSelect[] = {"", 0.1, 1};

      maxHistoryDelay = 1;
      autoScrollSpeed = -1;
      autoScrollDelay = 5;
      autoScrollRewind = 0;
      rowHeight = 0.03;

      class ScrollBar
      {
         color[] = {1,1,1,0.6};
         colorActive[] = {1,1,1,1};
         colorDisabled[] = {1,1,1,0.3};
         thumb = "\ca\ui\data\ui_scrollbar_thumb_ca.paa";
         arrowFull = "\ca\ui\data\ui_arrow_top_active_ca.paa";
         arrowEmpty = "\ca\ui\data\ui_arrow_top_ca.paa";
         border = "\ca\ui\data\ui_border_scroll_ca.paa";
      };
   };

   class MMA_CFG_VIRTUAL
   {
      access = 0;
      type = 5;
      style = 0;

      idc = 6;
      x = 0.44-0.11-0.10 - 0.08 - 0.2;
      y = 0.7+0.05;
      w = 0.22;
      h = 0.3-0.05;


      wholeHeight = 0.4;
      colorSelect[] = {0.6, 0.6, 0.8, 1};
      colorText[] = {0.6, 0.6, 0.8, 1};
      colorBackground[] = {0.0, 0.0, 0.0, 1};
      colorSelectBackground[] = {0.2, 0.2, 0.5, 0};
      colorSelect2[] = {0.6, 0.6, 0.8, 1};
      colorSelectBackground2[] = {0.1,0.1,0.2,0};

      font = "Bitstream";
      sizeEx = 0.025;
      soundSelect[] = {"", 0.1, 1};

      maxHistoryDelay = 1;
      autoScrollSpeed = -1;
      autoScrollDelay = 5;
      autoScrollRewind = 0;
      rowHeight = 0.03;

      class ScrollBar
      {
         color[] = {1,1,1,0.6};
         colorActive[] = {1,1,1,1};
         colorDisabled[] = {1,1,1,0.3};
         thumb = "\ca\ui\data\ui_scrollbar_thumb_ca.paa";
         arrowFull = "\ca\ui\data\ui_arrow_top_active_ca.paa";
         arrowEmpty = "\ca\ui\data\ui_arrow_top_ca.paa";
         border = "\ca\ui\data\ui_border_scroll_ca.paa";
      };
   };


   class MMA_CFG_CURRENTW
   {
      access = 0;
      type = 5;
      style = 0;

      idc = 3;
      x = 0.58-  0.12 - 0.08 -0.2;
      y = 0.7+0.05;
      w = 0.22;
      h = 0.14;

      wholeHeight = 0.4;
      colorSelect[] = {0.6, 0.6, 0.8, 1};
      colorText[] = {0.6, 0.6, 0.8, 1};
      colorBackground[] = {0.0, 0.0, 0.0, 1};
      colorSelectBackground[] = {0.2, 0.2, 0.5, 0};
      colorSelect2[] = {0.6, 0.6, 0.8, 1};
      colorSelectBackground2[] = {0.1,0.1,0.2,0};

      font = "Bitstream";
      sizeEx = 0.025;
      soundSelect[] = {"", 0.1, 1};

      maxHistoryDelay = 1;
      autoScrollSpeed = -1;
      autoScrollDelay = 5;
      autoScrollRewind = 0;
      rowHeight = 0.03;

      class ScrollBar
      {
         color[] = {1,1,1,0.6};
         colorActive[] = {1,1,1,1};
         colorDisabled[] = {1,1,1,0.3};
         thumb = "\ca\ui\data\ui_scrollbar_thumb_ca.paa";
         arrowFull = "\ca\ui\data\ui_arrow_top_active_ca.paa";
         arrowEmpty = "\ca\ui\data\ui_arrow_top_ca.paa";
         border = "\ca\ui\data\ui_border_scroll_ca.paa";
      };
   };

   class MMA_CFG_CURRENTM
   {
      access = 0;
      type = 5;
      style = 0;

      idc = 4;
      x = 0.58-  0.12 - 0.08 - 0.2;
      y = 0.85+0.05;
      w = 0.22;
      h = 0.148-0.05;

      wholeHeight = 0.4;
      colorSelect[] = {0.6, 0.6, 0.8, 1};
      colorText[] = {0.6, 0.6, 0.8, 1};
      colorBackground[] = {0.0, 0.0, 0.0, 1};
      colorSelectBackground[] = {0.2, 0.2, 0.5, 0};
      colorSelect2[] = {0.6, 0.6, 0.8, 1};
      colorSelectBackground2[] = {0.1,0.1,0.2,0};

      font = "Bitstream";
      sizeEx = 0.025;
      soundSelect[] = {"", 0.1, 1};

      maxHistoryDelay = 1;
      autoScrollSpeed = -1;
      autoScrollDelay = 5;
      autoScrollRewind = 0;
      rowHeight = 0.03;

      class ScrollBar
      {
         color[] = {1,1,1,0.6};
         colorActive[] = {1,1,1,1};
         colorDisabled[] = {1,1,1,0.3};
         thumb = "\ca\ui\data\ui_scrollbar_thumb_ca.paa";
         arrowFull = "\ca\ui\data\ui_arrow_top_active_ca.paa";
         arrowEmpty = "\ca\ui\data\ui_arrow_top_ca.paa";
         border = "\ca\ui\data\ui_border_scroll_ca.paa";
      };
   };

   class MMA_CFG_PRECONF
   {
      access = 0;
      type = 5;
      style = 0;

      idc = 5;
      x = 0.2-0.11-0.01+0.49+0.14 - 0.08 - 0.2;
      y = 0.7+0.05;
      w = 0.19;
      h = 0.3-0.05;

      onLBSelChanged = "[""CALL_PRECFG_CHANGE"", _this] call mando_missile_rearm";
      wholeHeight = 0.4;
      colorSelect[] = {1.0, 1.0, 1.0, 1};
      colorText[] = {0.75, 0.75, 0.75, 1};
      colorBackground[] = {0.0, 0.0, 0.0, 1};
      colorSelectBackground[] = {0.2, 0.2, 0.5, 0.6};
      colorSelect2[] = {0.95,0.95,0.95,1};
      colorSelectBackground2[] = {0.1,0.1,0.2,0.5};

      font = "Bitstream";
      sizeEx = 0.025;
      soundSelect[] = {"", 0.1, 1};

      maxHistoryDelay = 1;
      autoScrollSpeed = -1;
      autoScrollDelay = 5;
      autoScrollRewind = 0;
      rowHeight = 0.03;

      class ScrollBar
      {
         color[] = {1,1,1,0.6};
         colorActive[] = {1,1,1,1};
         colorDisabled[] = {1,1,1,0.3};
         thumb = "\ca\ui\data\ui_scrollbar_thumb_ca.paa";
         arrowFull = "\ca\ui\data\ui_arrow_top_active_ca.paa";
         arrowEmpty = "\ca\ui\data\ui_arrow_top_ca.paa";
         border = "\ca\ui\data\ui_border_scroll_ca.paa";
      };
   };

   class MMA_CFG_PRECONF_WEAPONS
   {
      access = 0;
      type = 5;
      style = 0;

      idc = 7;
      x = 0.2-0.11-0.01+0.49+0.14 - 0.08;
      y = 0.7+0.05;
      w = 0.22;
      h = 0.3-0.05;

      onLBSelChanged = "[""CALL_PRECFG_CHANGE"", _this] call mando_missile_rearm";
      wholeHeight = 0.4;
      colorSelect[] = {0.6, 0.6, 0.8, 1};
      colorText[] = {0.6, 0.6, 0.8, 1};
      colorBackground[] = {0.0, 0.0, 0.0, 1};
      colorSelectBackground[] = {0.2, 0.2, 0.5, 0};
      colorSelect2[] = {0.6, 0.6, 0.8, 1};
      colorSelectBackground2[] = {0.1,0.1,0.2,0};

      font = "Bitstream";
      sizeEx = 0.025;
      soundSelect[] = {"", 0.1, 1};

      maxHistoryDelay = 1;
      autoScrollSpeed = -1;
      autoScrollDelay = 5;
      autoScrollRewind = 0;
      rowHeight = 0.03;

      class ScrollBar
      {
         color[] = {1,1,1,0.6};
         colorActive[] = {1,1,1,1};
         colorDisabled[] = {1,1,1,0.3};
         thumb = "\ca\ui\data\ui_scrollbar_thumb_ca.paa";
         arrowFull = "\ca\ui\data\ui_arrow_top_active_ca.paa";
         arrowEmpty = "\ca\ui\data\ui_arrow_top_ca.paa";
         border = "\ca\ui\data\ui_border_scroll_ca.paa";
      };
   };

};
