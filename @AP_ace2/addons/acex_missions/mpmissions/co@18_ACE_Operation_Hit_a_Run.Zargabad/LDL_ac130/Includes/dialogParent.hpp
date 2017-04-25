class LDL_DialogParent
{
	idd = 1000;
	movingEnable = true;
	controlsBackground[] = {};
	controls[] = 
	{
		/*Bottom*/Target10,Target9,Target8,Target7,Target6,Target5,Target4,Target3,Target2,Target1,TargetText,indicatorVerBar,indicatorVerFrame,indicatorVerText,indicatorHorText,indicatorHorBar,indicatorHorFrame,West,South,East,North,Range,Cross,Center2,Center,mouseHandler,Info4,Info3,Info2,Info1,Warning,
		/*Middle*/Display,
		/*Top*/Info5
	};

        class Display: LDL_RscPicture
  	{
   		idc = 1000;
   		font = "Bitstream";
  		text = "LDL_ac130\Pictures\TVMonitor.paa";
  		x = SafeZoneX;
  		y = SafeZoneY;
  		w = SafeZoneW;
  		h = SafeZoneH;
  	};
	
	class mouseHandler
	{
		type = 15;
		idc = -1;
		style = 0;	
		
		class Scrollbar 
		{
			color[] = {1, 1, 1, 1};
			height = 0.028;
		};
		
		class VScrollbar 
		{
			color[] = {1, 1, 1, 1};
			width = 0.021;
			autoScrollRewind = true;
			autoScrollDelay = -2;
			autoScrollSpeed = -2;		
		};
	
		class HScrollbar 
		{
			color[] = {1, 1, 1, 1};
			height = 0.028;
		};
				
		//onMouseHolding = "";
		//onMouseEnter = "";	
		onMouseMoving = "[""MouseMoving"",_this] call LDL_MouseEvents";
		onMouseButtonDown = "[""MouseButtonDown"",_this] call LDL_MouseEvents";
		onMouseButtonUp = "[""MouseButtonUp"",_this] call LDL_MouseEvents";
		onMouseZChanged = "[""MouseZChanged"",_this] call LDL_MouseEvents";
		x = SafeZoneX; y = SafeZoneY;
		w = SafeZoneW; h = SafeZoneH;			
		colorBackground[] = {0.0, 0.0, 0.0, 0.0};
	};
	
	class Info1
	{
		//Links unten
	      	idc = 1001; 
	      	type = CT_STRUCTURED_TEXT;
	    	style = ST_DOWN;
              	colorBackground[] = {1, 1, 1, 0}; 
	     	x = SafeZoneX + SafeZoneW/8; 
	     	y = SafeZoneY + SafeZoneH - SafeZoneH/3;
	      	w = SafeZoneW/4;  
	      	h = SafeZoneH/4;
              	size = 0.04; 
              	text = ""; 
              	class Attributes 
              	{ 
                  font = "TahomaB"; 
                  color = "#FFFFF"; 
                  align = "left"; 
                  valign = "bottom"; 
                  shadow = false; 
                  shadowColor = "#000000"; 
                  size = "0.75"; 
              	}; 
        }; 

  	class Info2: LDL_RscText
	{
		//Rechts unten
		idc = 1002;
		style = ST_RIGHT;
		colorBackground[] = {1, 1, 1, 0}; 
		x = SafeZoneX + SafeZoneW - SafeZoneW/4 - SafeZoneW/8;
		y = SafeZoneY + SafeZoneH - SafeZoneH/3;
	      	w = SafeZoneW/4;  
	      	h = 0.04;
		text = "";
		sizeEx = 0.04; 
        }; 
      
	class Info3
	{
		//Links oben 
	      idc = 1003; 
	      type = CT_STRUCTURED_TEXT;
	      style = ST_MULTI;
              colorBackground[] = {1, 1, 1, 0}; 
	      x = SafeZoneX + SafeZoneW/8; 
	      y = SafeZoneY + SafeZoneH/8;
	      w = SafeZoneW/4;  
	      h = SafeZoneH/3;
              size = 0.04; 
              text = ""; 
              class Attributes 
              { 
                font = "TahomaB"; 
                color = "#FFFFF"; 
                align = "left"; 
                valign = "top"; 
                shadow = false; 
                shadowColor = "#000000"; 
                size = "1"; 
              }; 
        };
      
        class Info4: Info3
	{
		//Rechts oben 
	      idc = 1004;  
	      x = SafeZoneX + SafeZoneW - SafeZoneW/4 - SafeZoneW/8; 
              class Attributes 
              { 
                font = "TahomaB"; 
                color = "#FFFFF"; 
                align = "right"; 
                valign = "top"; 
                shadow = false; 
                shadowColor = "#000000"; 
                size = "1"; 
              }; 
        };
      
        class Info5: Info3
	{ 
		//Unten
	      idc = -1; 
	      x = SafeZoneX;
	      y = SafeZoneY + SafeZoneH - SafeZoneH/32;
	      w = SafeZoneW;  
	      h = SafeZoneH/32;
	      colorBackground[]={0, 0, 0, 0.5};
              text = "F1: Help | F2: Toggle View | F3: Infantry Strobe | F4: Vehicle Detection | F5: Normal Mode | F6: FLIR | F7: NVG | F8: Toggle Mode | F9: Show Waypoints | F10: Disable Sound | L MOUSE: Fire | R MOUSE: Change Position | MOUSE WHEEL: Zoom | 1 2 3 or ^: Change Weapons | M: Map | Shift: Fix Camera | Arrow Keys: Move Plane |";
              class Attributes 
              { 
                font = "TahomaB"; 
                color = "#FFFFF"; 
                align = "center"; 
                valign = "top"; 
                shadow = false; 
                shadowColor = "#000000"; 
                size = "0.5"; 
              }; 
        };
      
        class Center: LDL_RscPicture
  	{
   		idc = 1005;
   		colorText[]={1, 1, 1, 0.5};
 		text = "\CA\ui\data\map_player_ca.paa";
		w = SafeZoneW/32;
		h = SafeZoneH/32;
		x = -1;
		y = -1; 
  	};

	class Center2: Center
  	{
   		idc = 1006;
   		colorText[]={1, 1, 1, 0};
 		text = "\CA\ui\data\marker_goal_ca.paa";
  	};
  
        class Cross: LDL_RscPicture
  	{
   		idc = 1007;
  		text = "LDL_ac130\Pictures\Vis25mm.paa";
		w = SafeZoneW/4;
		h = SafeZoneH/4;
		x = SafeZoneX + SafeZoneW/2 - SafeZoneW/8;
		y = SafeZoneY + SafeZoneH/2 - SafeZoneH/8;
  	};
  

        class Range: LDL_RscText
	{
		idc = 1008;
		style = ST_CENTER;
		w = SafeZoneW/6;
		h = SafeZoneH/6;
		x = SafeZoneX + SafeZoneW/2 - SafeZoneW/12;
		y = SafeZoneY + SafeZoneH/2 + SafeZoneH/12;
		sizeEx=0.02;
		text = "Range: ";
        };

    	class North: LDL_RscText
	{
		idc = 1009;
		style = ST_RIGHT;
		w = SafeZoneW/50;
		h = SafeZoneW/50;
		x = SafeZoneX + SafeZoneW/100;
		y = SafeZoneY + SafeZoneH/100;
		sizeEx=0.03;
		text = "N";
        };
      
        class East: North
	{
		idc = 1010;
		text = "E";
        };
      
        class South: North
	{
		idc = 1011;
		text = "S";
        };

        class West: North
	{
		idc = 1012;
		text = "W";
        };
      
        class indicatorHorFrame : LDL_RscText
	{
		style = ST_LINE;
		w = SafeZoneW/8;
		h = 0;
		x = SafeZoneX + SafeZoneW/2 - SafeZoneW/16;
		y = SafeZoneY + SafeZoneH - SafeZoneH/4 + SafeZoneH/64;
   		colorBackground[] = {1,1,1,1};
	};
      
        class indicatorHorBar: indicatorHorFrame
	{
		idc = 1013;
		w = 0;
		h = SafeZoneH/64;
		x = SafeZoneX + SafeZoneW/2 - SafeZoneW/16;
		y = SafeZoneY + SafeZoneH/2 + SafeZoneH/4 + SafeZoneH/64;
		colorBackground[] = {0,0,0,1};
	};

        class indicatorHorText: LDL_RscText
	{
		idc = 1014;
		style = ST_CENTER;
		w = SafeZoneH/32;
		h = SafeZoneH/32;
		x = SafeZoneX + SafeZoneW/2;
		y = SafeZoneY + SafeZoneH/2 + SafeZoneH/4 + SafeZoneH/32;
		colorText[] = {1,1,1,1};
		colorBackground[] = {1,1,1,0};
	};

        class indicatorVerFrame : indicatorHorFrame
	{
		w = 0;
		h = SafeZoneH/8;
		x = SafeZoneX + SafeZoneW - SafeZoneW/4;
		y = SafeZoneY + SafeZoneH/2 - SafeZoneH/16;
	};
      
        class indicatorVerBar: indicatorHorBar
	{
		idc = 1015;
		w = SafeZoneW/64;
		h = 0;
		x = SafeZoneX + SafeZoneW - SafeZoneW/4;
		y = SafeZoneY + SafeZoneH/2;
	};

        class indicatorVerText: LDL_RscText
	{
		idc = 1016;
		style = ST_CENTER;
		w = SafeZoneH/32;
		h = SafeZoneH/32;
		x = SafeZoneX + SafeZoneW - SafeZoneW/4;
		y = SafeZoneY + SafeZoneH/2;
		colorText[] = {1,1,1,1};
		colorBackground[] = {1,1,1,0};
	};

        class Warning: Info3
	{ 
	      idc = 1017; 
	      x = SafeZoneX + SafeZoneW/2 - SafeZoneH/4;
	      y = SafeZoneY + SafeZoneH/2 - SafeZoneH/4;
	      w = SafeZoneW/4;  
	      h = SafeZoneH/32;
	      colorBackground[]={0, 0, 0, 0};
              text = "";
              class Attributes 
              { 
                font = "TahomaB"; 
                color = "#FFFFF"; 
                align = "left"; 
                valign = "top"; 
                shadow = false; 
                shadowColor = "#000000"; 
                size = "0.5"; 
              }; 
        };
	
  	//Targets

      	class Target : LDL_RscText
      	{
		idc = 2000;
		style = ST_FRAME;
   		colorBackground[] = {1,0,0,1};
   	 	colorText[] = {1,0,0,1};
       		x = -2;
       		y = -2;
       		w = 0.04;
       		h = 0.05;
      	};
      
        class TargetText : LDL_RscText
      	{
		idc = 2001;
		x = -2;
       		y = -2;
       		w = 0.1;
       		h = 0.05;
		text = "Target";
		sizeEx = 0.02;
		style=ST_CENTER;
		colorText[] = {1, 0, 0, 1};
      	};
       
     	class Target1 : Target
     	{
		idc = 2001+1;
      	};
       
      	class Target2 : Target
      	{
		idc = 2001+2;
      	};
       
      	class Target3 : Target
      	{
		idc = 2001+3;
      	};
      
      	class Target4 : Target
     	{
		idc = 2001+4;
      	};
       
      	class Target5 : Target
      	{
		idc = 2001+5;
      	};
       
      	class Target6 : Target
      	{
		idc = 2001+6;
      	};
      
      	class Target7 : Target
      	{
		idc = 2001+7;
      	};
       
      	class Target8 : Target
      	{
		idc = 2001+8;
      	};
       
      	class Target9 : Target
      	{
		idc = 2001+9;
      	};
      
      	class Target10 : Target
      	{
		idc = 2001+10;
      	};
    
};