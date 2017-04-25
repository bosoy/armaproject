_panc = _this select 0;

switch (_this select 1) do
{
	case "hide" : {_panc animate ["panc1_hide",1];};
	case "unhide" : {_panc animate ["panc1_hide",0];};
};

switch (_this select 2) do
{
	case "hide" : {_panc animate ["panc2_hide",1];};
	case "unhide" : {_panc animate ["panc2_hide",0];};
};

switch (_this select 3) do
{
	case "hide" : {_panc animate ["panc3_hide",1];};
	case "unhide" : {_panc animate ["panc3_hide",0];};
};