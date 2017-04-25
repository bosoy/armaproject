#define THIS_FILE "fn_infoText.sqf"
#include "x_setup.sqf"
/*
	File: infoText.sqf
	Author: Karel Moricky

	Description:
	Info with some ffect.

	Parameter(s):
	_this: Array containing lines of text (String)
*/

123100 cutrsc [QGVAR(rscInfoText),"plain"];

//--- Separate lines
_text = _this;
_textArrayUnicode = [];
{_textArrayUnicode set [count _textArrayUnicode, toarray _x]} foreach _text;

//--- Separate letters
_textArrayLines = [];
for "_ee" from 0 to (count _textArrayUnicode - 1) do {
	_textArrayTemp = [];
	{_textArrayTemp set [count _textArrayTemp, tostring [_x]]} foreach (_textArrayUnicode select _ee);
	_textArrayLines set [_ee,_textArrayTemp];
};

//--- Merge arrays
_textArray = [];
_emptyArray = [];
_nArrayTemp = [];
_n = 0;
{
	_line = _x;
	_textArray = _textArray + _line + ["\n"];
	{
		//_emptyArray = _emptyArray + [_line call bis_fnc_selectrandom]; //--- Shuffled text
		//_emptyArray = _emptyArray + [str floor random 2]; //--- Binary Solo
		//_emptyArray = _emptyArray + [""]; //--- Rolling text
		_emptyArray set [count _emptyArray, " "]; //--- Space
		_nArrayTemp set [count _nArrayTemp, _n];
		__INC(_n);
	} foreach _x;
	__INC(_n);
	_emptyArray set [count _emptyArray, "\n"];
} foreach _textArrayLines;
_finalArray = _emptyArray;
_text = composetext _finalArray;


//--- Random order
_nArray = [];
while {count _nArrayTemp > 0} do {
	_element = _nArrayTemp select (floor random (count _nArrayTemp));
	_nArray set [count _nArray, _element];
	_nArrayTemp = _nArrayTemp - [_element];
};

//--- Visualization
disableserialization;
_display = __uiGetVar(GVAR(BIS_InfoText));
_textControl = _display displayctrl 3101;

_text = composetext _finalArray;
_textControl ctrlsettext str _text;
_textControl ctrlcommit 0.01;
sleep 1;

{
	_finalArray set [_x,_textArray select _x];
	_text = composetext _finalArray;
	_textControl ctrlsettext str _text;
	_textControl ctrlcommit 0.01;
	playsound "counter";
	if (random 1 > 0.9) then {sleep 0.1};
	sleep 0.01;
} foreach _nArray;

sleep 2;

//--- Fade away
{
	_finalArray set [_x," "];
	_text = composetext _finalArray;
	_textControl ctrlsettext str _text;
	_textControl ctrlcommit 0.01;
	playsound "counter";
	//if (random 1 > 0.9) then {sleep 0.2};
	sleep 0.01;
} foreach _nArray;

123100 cuttext ["","plain"];