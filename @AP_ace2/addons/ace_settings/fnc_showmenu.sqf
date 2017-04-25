#include "script_component.hpp"

#define DISP(A) (_display displayCtrl A)

private "_display";

disableSerialization;

PARAMS_1(_menu);
_display = uiNamespace getVariable "ACE_SETTINGS_DIALOG";
switch (_menu) do {
	case "options": {
		DISP(1000) ctrlShow true; // Options
		DISP(1002) ctrlShow false; // Keys
		DISP(1003) ctrlShow false; // SP Options
		
		//if (!isMultiPlayer) then {
		//	if (ctrlShown DISP(8000)) then {
		//		DISP(8000) ctrlShow false;
		//		DISP(8000) ctrlCommit 0;
		//		DISP(8001) ctrlSetPosition [-0.06,0.05940156];
		//		DISP(8001) ctrlCommit 0;
		//	} else {
		//		DISP(8000) ctrlShow true;
		//		DISP(8000) ctrlCommit 0;
		//		DISP(8001) ctrlSetPosition [-0.06,0.109875];
		//		DISP(8001) ctrlCommit 0;
		//	};
		//};
	};
	case "keys": {
		DISP(1002) ctrlShow true;
		DISP(1000) ctrlShow false;
		DISP(1003) ctrlShow false;
	
		//if (ctrlShown DISP(8000)) then {
		//	DISP(8000) ctrlShow false;
		//	DISP(8000) ctrlCommit 0;
		//	DISP(8001) ctrlSetPosition [-0.06,0.05940156];
		//	DISP(8001) ctrlCommit 0;				
		//};			
	};
	case "options_sp": {
		DISP(1003) ctrlShow true;
		DISP(1000) ctrlShow false;
		DISP(1002) ctrlShow false;
	};
};
