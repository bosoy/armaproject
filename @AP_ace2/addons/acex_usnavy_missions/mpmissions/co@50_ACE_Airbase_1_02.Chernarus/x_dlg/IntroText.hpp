//class RscTitles
//{

	class vehicle_hud
	{
		idd=64431;
		movingEnable = true;
		fadein       =  0;
		fadeout      =  0;
		duration     =  4;
		name="vehicle_hud";
		controls[]={"vehicle_hud_name","vehicle_hud_speed","vehicle_hud_fuel","vehicle_hud_damage"};
		onLoad="DVEC_HUD = _this select 0";

		class vehicle_hud_name
		{
			type = 0;
			idc = 64432;
			style = 0;
			//x = 0.789;
			x = 0.87;
			y = 0.725;
			w = 0.2;
			h = 0.2;
			font = "Zeppelin32";
			sizeEx = 0.019;
			colorText[] = {1.0, 1.0, 1.0, 0.9};
			colorBackground[]={0,0,0,0.0};
			text = "abc";
		};

		class vehicle_hud_speed
		{
			type = 0;
			idc = 64433;
			style = 0;
			x = 0.87;
			y = 0.755;
			w = 0.2;
			h = 0.2;
			font = "Zeppelin32";
			sizeEx = 0.019;
			colorText[] = {1.0, 1.0, 1.0, 0.9};
			colorBackground[]={0,0,0,0.0};
			text = "abc";
		};

		class vehicle_hud_fuel
		{
			type = 0;
			idc = 64434;
			style = 0;
			x = 0.87;
			y = 0.785;
			w = 0.2;
			h = 0.2;
			font = "Zeppelin32";
			sizeEx = 0.019;
			colorText[] = {1.0, 1.0, 1.0, 0.9};
			colorBackground[]={0,0,0,0.0};
			text = "abc";
		};

		class vehicle_hud_damage
		{
			type = 0;
			idc = 64435;
			style = 0;
			x = 0.87;
			y = 0.815;
			w = 0.2;
			h = 0.2;
			font = "Zeppelin32";
			sizeEx = 0.019;
			colorText[] = {1.0, 1.0, 1.0, 0.9};
			colorBackground[]={0,0,0,0.0};
			text = "abc";
		};
	};
//};
