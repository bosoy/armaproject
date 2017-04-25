class Params
{
	// paramsArray [0]
	class Hour {
		title = "Time";
		values[] = {12,14,16,18,20,22,0,2,4,6,8,10};
		texts[] = {"0000","0200","0400","0600","0800","1000","1200","1400","1600","1800","2000","2200"};
		default = 16;
		code = "MissionTime = %1";
	};
	// paramsArray [1]
	class moonState {
		title = "Moon State";
		values[] = {1,2,3};
		texts[] =  {"Full Moon","Half Moon","New Moon"};
		default = 1;
		code = "MissionMoon = %1";
	};
	// paramsArray [2]
	class trackingMarkers {
		title = "Tracking Markers";
		values[] = {1,2};
		texts[] =  {"Group Tracking On","Group Tracking off"};
		default = 2;
		code = "GroupTracking = %1";
	};
};
