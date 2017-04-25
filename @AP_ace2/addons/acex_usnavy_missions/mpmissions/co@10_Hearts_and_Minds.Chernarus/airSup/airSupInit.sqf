_man = _this select 0;
/// Change classnames for different aircraft ////////////////
switch (side _man) do {
/* For CO
	case WEST:{
		airSupFXD = "F35B";
		airSupFXDCAS = "A10";
		airSupROT = "AH64D_EP1";
		airSupTRN = "MH60S";
		airSupPIL = "US_Soldier_Pilot_EP1";
		airSupBomb = "Bo_Mk82";
	};
	case EAST:{
		airSupFXD = "SU34";
		airSupFXDCAS = "SU39";
		airSupROT = "Mi24_V";
		airSupTRN = "Mi17_medevac_RU";
		airSupPIL = "RU_Soldier_Pilot";
		airSupBomb = "Bo_Mk82";
	};
*/
	case WEST:{
		airSupFXD = "A10_US_EP1";
		airSupFXDCAS = "A10_US_EP1";
		airSupROT = "AH64D_EP1";
		airSupTRN = "UH60M_EP1";
		airSupPIL = "US_Soldier_Pilot_EP1";
		airSupBomb = "Bo_GBU12_LGB";
	};
	case EAST:{
		airSupFXD = "L39_TK_EP1";
		airSupFXDCAS = "Su25_TK_EP1";
		airSupROT = "Mi24_D_TK_EP1";
		airSupTRN = "Mi17_TK_EP1";
		airSupPIL = "TK_Soldier_Pilot_EP1";
		airSupBomb = "Bo_GBU12_LGB";
	};
};
// Change to the number of times each support can be called /////
ASnumJDA = 0;
ASnumLGB = 0;
ASnumCAP = 0;
ASnumCAT = 0;
ASnumCBM = 0;
ASnumCAS = 0;
ASnumHEL = 2;
ASnumTRN = 0;
// Is menu on a player or an object ?  uncomment only one ///////
airSup_stg = "_target == player"; // player
// airSup_stg = ""; // object
// Keeps the main action menu on the character through respawn //
[_man] execVM "airSup\MPrespwn.sqf";
// Variable deffinition in first run only ///////////////////////
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