/*
	Town mode initialization.
		the town that have to be removed need to be stored on the desired variable over WF_Logic. If those ain't set, the full town setting will be used. 
		Custom templates can be added bellow.
*/
private ['_index','_i','_paramName','_value'];
Private ['_i','_index','_paramName','_value'];

_index = 0;
for [{_i = 0},{_i < (count (missionConfigFile/"Params"))},{_i = _i + 1}]  do {
	_paramName = (configName ((missionConfigFile >> "Params") select _i));
	if (_paramName == "townsAmount") exitWith {_index =_i};
};

_value = if (isMultiplayer) then {paramsArray select _index} else {getNumber (missionConfigFile >> "Params" >> "townsAmount" >> "default")};

/*
	Chernarus Template (WF_Logic init field):
		this setVariable ["Towns_RemovedXSmall",["Zelenogorsk","Dolina","StarySobor","Myshkino","Chernogorsk","Dubrovka","Pogorevka","Bor","Staroye","Pulkovo","Khelm","Kamyshovo","Pavlovo","Nadezhdino","Mogilevka","Vyshnoye","Berezino","Krasnostav","Gorka","Elektrozavodsk","Msta","Komarovo","Petrovka","Shakhovka","Prigorodki","Olsha","Orlovets","Nizhnoye","Solnichniy","Tulga","Kozlovka","Polana","Kamenka","Gvozdno","NovySobor","Pusta","Guglovo"]];
		this setVariable ["Towns_RemovedSmall",["Zelenogorsk","Dolina","StarySobor","Lopatino","Myshkino","Chernogorsk","Pogorevka","Bor","Kabanino","Staroye","Pulkovo","Kamyshovo","Vybor","Pavlovo","Nadezhdino","Grishino","Mogilevka","Vyshnoye","Elektrozavodsk","Msta","Komarovo","Petrovka","Shakhovka","Prigorodki","Nizhnoye","Solnichniy","Tulga","Kozlovka","Pustoshka","Kamenka","NovySobor","Pusta","Guglovo"]];
		this setVariable ["Towns_RemovedMedium",["Dolina","Dubrovka","Bor","Staroye","Elektrozavodsk","Berezino","Krasnostav","Pulkovo","Khelm","Kamyshovo","Vyshnoye","Gorka","Msta","Petrovka","Shakhovka","Prigorodki","Olsha","Orlovets","Nizhnoye","Solnichniy","Tulga","Polana","Gvozdno","NovySobor","Pusta","Guglovo","Sosnovka"]];
		this setVariable ["Towns_RemovedLarge",["Bor","Pulkovo","Khelm","Msta","Shakhovka","Prigorodki","Olsha","Orlovets","Nizhnoye","Tulga","Kozlovka","Pustoshka","Kamenka","NovySobor","Sosnovka"]];
*/

TownTemplate = [];
switch (_value) do {
	case 0: {TownTemplate = WF_Logic getVariable "Towns_RemovedXSmall"};
	case 1: {TownTemplate = WF_Logic getVariable "Towns_RemovedSmall"};
	case 2: {TownTemplate = WF_Logic getVariable "Towns_RemovedMedium"};
	case 3: {TownTemplate = WF_Logic getVariable "Towns_RemovedLarge"};
	//--- case 4 = full. useless.
	/* Add your templates here !
		Custom templates can be added here, just set a new variable with the towns to remove in WF_Logic and add your template name/value in the parameter class 
			- WF_Logic:   this setVariable ["myRemovedTowns",["Chernogorsk","Pavlovo","Zelenogorsk"]];
			- parameter (Add it at the end!!!): 
				class townsAmount {
					title = "$STR_WF_Gameplay_TownsAmount";
					values[] = {0,1,2,3,4,5};
					texts[] = {"Extra Small","Small","Medium","Large","Full","MyOwnTemplate"};
					default = 3;
				};
			- Init_TownMode.sqf (Here!): case 5: {TownTemplate = WF_Logic getVariable "myRemovedTowns"}
			
			As a result, Chernogorsk, Pavlovo and Zelenogorsk will be removed.
	*/
};

if (isNil "TownTemplate") then {TownTemplate = []};//--- The field is not defined, we use the default island setting.
totalTowns = (WF_Logic getVariable "totalTowns") - (count TownTemplate);

townModeSet = true;

diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_TownMode: Towns mode initialization (world: %3) - [Done]",diag_frameno,diag_tickTime,worldName];