/* 
	3 levels of civilians, villagers, citizen and large citizen (keep them).
	keep the same _n name
*/


Private ['_civType','_n','_u'];
_civType = ('WFBE_CIVILIANFACTIONS' Call GetNamespace) select ('WFBE_CIVILIANFACTION' Call GetNamespace);

if (_civType == 'Chernarus Civilians') then {
	_n		= ["Villagers1"];
	_u		= ["Villager1"];
	_u = _u + ["Woodlander1"];
	_u = _u + ["Worker1"];
	[Format["WFBE_CIV%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["Villagers2"];
	_u		= ["Villager4"];
	_u = _u + ["Woodlander2"];
	_u = _u + ["Farmwife1"];
	[Format["WFBE_CIV%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;
	
	_n = _n + ["Villagers3"];
	_u		= ["Villager2"];
	_u = _u + ["WorkWoman3"];
	[Format["WFBE_CIV%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;	
	
	_n = _n + ["Villagers4"];
	_u		= ["Villager2"];
	_u = _u + ["WorkWoman3"];
	_u = _u + ["Worker3"];
	[Format["WFBE_CIV%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;
	
	_n = _n + ["Citizen1"];
	_u		= ["Citizen2"];
	_u = _u + ["Profiteer3"];
	[Format["WFBE_CIV%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;
	
	_n = _n + ["Citizen2"];
	_u		= ["Rocker2"];
	_u = _u + ["Citizen4"];
	[Format["WFBE_CIV%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;
	
	_n = _n + ["Citizen3"];
	_u		= ["WorkWoman5"];
	_u = _u + ["Citizen3"];
	[Format["WFBE_CIV%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;
	
	_n = _n + ["Citizen4"];
	_u		= ["Damsel2"];
	_u = _u + ["Madam5"];
	[Format["WFBE_CIV%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;	
	
	_n = _n + ["LargeCitizen1"];
	_u		= ["SchoolTeacher"];
	_u = _u + ["Functionary1"];
	[Format["WFBE_CIV%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;
	
	_n = _n + ["LargeCitizen2"];
	_u		= ["Assistant"];
	_u = _u + ["Secretary3"];
	[Format["WFBE_CIV%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;
	
	_n = _n + ["LargeCitizen3"];
	_u		= ["Worker3"];
	_u = _u + ["Hooker1"];
	[Format["WFBE_CIV%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;	
	
	_n = _n + ["LargeCitizen4"];
	_u		= ["Citizen3"];
	_u = _u + ["Villager2"];
	[Format["WFBE_CIV%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;
};

if (_civType == 'Takistan Civilians') then {
	_n 		= ["Villagers1"];
	_u		= ["TK_CIV_Takistani02_EP1"];
	_u = _u + ["TK_CIV_Takistani03_EP1"];
	_u = _u + ["TK_CIV_Takistani06_EP1"];
	[Format["WFBE_CIV%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["Villagers2"];
	_u		= ["TK_CIV_Worker01_EP1"];
	_u = _u + ["TK_CIV_Woman02_EP1"];
	_u = _u + ["TK_CIV_Takistani06_EP1"];
	[Format["WFBE_CIV%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;
	
	_n = _n + ["Villagers3"];
	_u		= ["TK_CIV_Takistani05_EP1"];
	_u = _u + ["TK_CIV_Takistani01_EP1"];
	[Format["WFBE_CIV%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;	
	
	_n = _n + ["Villagers4"];
	_u		= ["TK_CIV_Woman01_EP1"];
	_u = _u + ["TK_CIV_Takistani04_EP1"];
	[Format["WFBE_CIV%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;
	
	_n = _n + ["Citizen1"];
	_u		= ["TK_CIV_Worker02_EP1"];
	_u = _u + ["CIV_EuroMan01_EP1"];
	[Format["WFBE_CIV%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;
	
	_n = _n + ["Citizen2"];
	_u		= ["CIV_EuroMan01_EP1"];
	_u = _u + ["CIV_EuroMan02_EP1"];
	[Format["WFBE_CIV%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;
	
	_n = _n + ["Citizen3"];
	_u		= ["TK_CIV_Takistani06_EP1"];
	_u = _u + ["TK_CIV_Takistani03_EP1"];
	[Format["WFBE_CIV%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;
	
	_n = _n + ["Citizen4"];
	_u		= ["TK_CIV_Takistani04_EP1"];
	_u = _u + ["TK_CIV_Takistani05_EP1"];
	[Format["WFBE_CIV%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;	
	
	_n = _n + ["LargeCitizen1"];
	_u		= ["TK_CIV_Woman03_EP1"];
	_u = _u + ["TK_CIV_Woman03_EP1"];
	[Format["WFBE_CIV%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;
	
	_n = _n + ["LargeCitizen2"];
	_u		= ["TK_CIV_Takistani01_EP1"];
	_u = _u + ["TK_CIV_Takistani05_EP1"];
	[Format["WFBE_CIV%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;
	
	_n = _n + ["LargeCitizen3"];
	_u		= ["TK_CIV_Takistani02_EP1"];
	_u = _u + ["TK_CIV_Woman01_EP1"];
	[Format["WFBE_CIV%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;	
	
	_n = _n + ["LargeCitizen4"];
	_u		= ["TK_CIV_Takistani03_EP1"];
	_u = _u + ["TK_CIV_Takistani02_EP1"];
	[Format["WFBE_CIV%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;
};

diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Config_Civilians: Intialization - [Done]",diag_frameno,diag_tickTime];