//////////////////////////////
//    Dynamic-AI-Creator    //
//    Version 3.0 - 2010    //
//--------------------------//
//    DAC__Init_Zone        //
//--------------------------//
//    Script by Silola      //
//    silola@freenet.de     //
//////////////////////////////

waituntil {((time > 2) && ((direction DAC_StartDummy) > 90))};
sleep (random 1);
if(DAC_Basic_Value > 0) then {exit};
if((count (_this select 5)) >= 6) then {DAC_Init_Camps = DAC_Init_Camps + ((_this select 5) select 0)};
_this execVM "\DAC_Source\Scripts\DAC_Create_Zone.sqf";