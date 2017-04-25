/* ace_sys_interaction (.pbo) | (c) 2009 by rocko */

#include "script_component.hpp"

PARAMS_3(_receiver,_sender,_action);

LOG("Creating answer menu");

private["_text"];
switch (toLower _action) do {
	case "gear": {
		_text = format[localize "STR_DN_ACE_AYAYAYAY",name _sender];
	};
	case "search": {
		_text = format[localize "STR_DN_ACE_ILOVETHESMELLOFPUSSYINTHEMORNING",name _sender];
	};
	case "carry": {
		_text = format[localize "STR_DN_ACE_CZECHGIRLSANDMONEY",name _sender];
	};
	case "morphine": {
		_text = format[localize "STR_DN_ACE_TSCHUESSEN",name _sender];
	};
	case "epinephrine": {
		_text = format[localize "STR_DN_ACE_ISUCKATSTRINTABLENAMES",name _sender];
	};	
};

if (local _receiver) then {
	// Set busy state
	_receiver setVariable ["ace_sys_interaction_busy",true, true];
	GVAR(rec_has_answered) = nil;

	_text spawn ace_fnc_visual;

	#define ACE_TEXT_RED(Text) ("<t color='#FF0000'>" + ##Text + "</t>")
	#define ACE_TEXT_GREEN(Text) ("<t color='#00FF00'>" + ##Text + "</t>")

	GVAR(yes) = _receiver addAction [ACE_TEXT_GREEN(localize "STR_DN_ACE_CONFIRMYES"),QPATHTO_F(fnc_yesno),[_sender,_action,1],9999];
	GVAR(no) = _receiver addAction [ACE_TEXT_RED(localize "STR_DN_ACE_DENYFUCKNOOES"),QPATHTO_F(fnc_yesno),[_sender,_action,0],10000];

	[_sender,_receiver] spawn {
		PARAMS_2(_sender,_receiver);
		private["_t"];
		_t = time;
		LOG("Params passed");
		LOG(_sender);
		LOG(_receiver);

		while { time < (_t +10) && {alive _receiver} && {isNil QGVAR(rec_has_answered)} } do {
			sleep 1;
			LOG("Waiting for an answer");
		};

		if (isNil QGVAR(rec_has_answered)) then {
			LOG(GVAR(rec_has_answered));
			LOG("No answer received - Declining");
			[QGVAR(confirmation), [_sender, _receiver, 0, _action]] call ACE_fnc_receiverOnlyEvent;
			_receiver removeAction GVAR(yes);
			_receiver removeAction GVAR(no);
			// Unset busy state
			_receiver setVariable ["ace_sys_interaction_busy",false, true];
		};
	};
};

false
