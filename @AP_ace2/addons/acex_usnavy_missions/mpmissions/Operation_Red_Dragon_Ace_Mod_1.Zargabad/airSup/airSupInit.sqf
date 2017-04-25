_man = _this select 0;
/// Change classnames for different aircraft ////////////////
switch (side _man) do {
	case WEST:{
		airSupFXD = "F35B";
		airSupFXDCAS = "A10";
		airSupROT = "AH1Z";
		airSupTRN = "MH60S";
		airSupPIL = "USMC_Soldier_Pilot";
	};
	case EAST:{
		airSupFXD = "SU34";
		airSupFXDCAS = "SU39";
		airSupROT = "Mi24_V";
		airSupTRN = "Mi17_medevac_RU";
		airSupPIL = "RU_Soldier_Pilot";
	};
};
// Change to the number of times each support can be called //
ASnumJDA = 99;
ASnumLGB = 99;
ASnumCAP = 99;
ASnumCAT = 99;
ASnumCBM = 99;
ASnumCAS = 99;
ASnumHEL = 99;
ASnumTRN = 99;
///////////////////////////////////////////////////////////////
as0 = _man addAction [localize "STR_MENUASM","airSup\addMenu.sqf",[], 5, false, false, "", "_target == player"];
// Variable deffinition in first run only /////////////////////
if (ASfirstrun) then {
	if("jadam" in _this)then{jadam = true}else{jadam = false};
	if("lgb" in _this)then{lgb = true}else{lgb = false};
	if("cbuap" in _this)then{cbuap = true}else{cbuap = false};
	if("cbuat" in _this)then{cbuat = true}else{cbuat = false};
	if("cbumine" in _this)then{cbumine = true}else{cbumine = false};
	if("cas" in _this)then{cas = true}else{cas = false};
	if("helo" in _this)then{helo = true}else{helo = false};
	if("trans" in _this)then{trans = true}else{trans = false};
	IPheloAS = false;
	IPfixedAS = false;
	sad = false;
	ASclick = false;
	airSupPlane = "";
	ASLGB = 0;
	ASJDA = 0;
	ASCAP = 0;
	ASCAT = 0;
	ASCBM = 0;
	ASCAS = 0;
	ASHEL = 0;
	ASTRN = 0;
	kill1 = false;
	kill2 = false;
	kill3 = false;
	kill4 = false;
	kill5 = false;
	kill6 = false;
	kill7 = false;
	kill8 = false;
	ASfirstrun = false;
};
if(true)exitwith{};