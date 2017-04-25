/* ace_sys_ruck (.pbo) (c) 2009 by tcp */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#include "script_dialog_defines.hpp"

// Front-end code to allow sys_ruck to update it's info when normal gear functions invoked.
scopeName "main";
disableSerialization;
PARAMS_2(_data,_event);
DEFAULT_PARAM(2,_trynum,0);
private ["_display", "_control", "_unit", "_lastIDC", "_itm", "_txt", "_typ", "_isWep", "_timeWait", "_loaded"];
private ["_ACE_fnc_WOBButton", "_ACE_fnc_PackButton", "_ACE_fnc_UnpackButton", "_ACE_fnc_SwitchWOBText", "_ACE_fnc_Show_Buttons", "_ACE_fnc_keyActions", "_ACE_fnc_displayLoad", "_ACE_fnc_Forget_IDC", "_fnc_weaponsLBSetFocus", "_ACE_fnc_RuckLBSetFocus", "_fnc_lbSelectedItem", "_fnc_isWeapon", "_fnc_WOBSelectedItem", "_ACE_fnc_GearClick", "_ACE_fnc_Remember_IDC", "_ACE_fnc_WOBClick", "_fnc_displayItemInfo", "_ACE_fnc_UpdateDisplay", "_ACE_fnc_Recall_IDC", "_ACE_fnc_hasMagInRuck"];
private ["_onLoad"];

/*-------------------------------------------*/
if (typeName (_data select 0) == "DISPLAY") then {
	_display = _data select 0;
};

if (typeName (_data select 0) == "CONTROL") then {
	_control = _data select 0;
	_display = ctrlParent _control;
};

GVAR(diag_to_close) = ([str _display, "#"] call CBA_fnc_split) select 1;

_unit = _display call FUNC(uiGetCallingUnit); //diag_log _unit;
GVAR(lastUnit) = _unit;

//delay events if dialog not loaded yet
if ( _event != "onLoad" && {isNil "ACE_gearopen"} ) then {
	TRACE_1("Delay",_event);
	if ( _trynum < 3 ) then {
		[[_data,_event, _trynum + 1], {_this call ace_sys_ruck_fnc_handleGear}] call cba_common_fnc_directCall;
	} else {
		TRACE_1("Delay failed",_event);
	};
	breakOut "main";
};
//TRACE_1("Allow event",_event);

if (isPlayer _unit && {(_unit call CBA_fnc_getUnitAnim) select 0 == "stand"}) then {
	// Have we been in Binocular-Fuckup Mode?
	_binocularState = animationState _unit;
	_usedBino = (_binocularState in ["awoppercmstpsoptwbindnon_rfl","awoppercmstpsoptwbindnon_pst","awoppercmstpsoptwbindnon_lnr","awoppercmstpsoptwbindnon_non"]);
	
	_weaponType = (currentWeapon _unit) call ace_sys_weapons_fnc_getType;
	TRACE_1("",_weaponType);
	_anim = "AmovPercMstpSrasWrflDnon_diary";
	if (_weaponType == 4) then {
		_anim = "aidlpknlmstpsraswlnrdnon_player_0s"; // launcher
	};
	if (_weaponType == 0) exitWith {}; /* then {
		_anim = "aidlpknlmstpsnonwnondnon_player_idlesteady01"; // no weapon
	};*/
	if (_weaponType == 2) then {
		_anim = "AmovPknlMstpSrasWpstDnon"; //"amovpknlmstpsraswpstdnon_gear"; // pistol
	};
	// If you have a fucking bino Arma remembers the previous weapon you had by different animation names...
	if (_weaponType == 4096) exitWith {}; /*then {
		switch (_binocularState) do {
			case "awoppercmstpsoptwbindnon_rfl": { _anim = "awoppknlmstpsoptwbindnon_rfl" };
			case "awoppercmstpsoptwbindnon_pst": { _anim = "awoppknlmstpsoptwbindnon_pst" };
			case "awoppercmstpsoptwbindnon_lnr": { _anim = "awoppknlmstpsoptwbindnon_lnr" };
			case "awoppercmstpsoptwbindnon_non": { _anim = "exit" };
		};
	};
	if (_anim == "exit") exitWith {}; */
	_unit playMove _anim;
};

/*-------------------------------------------*/
_ACE_fnc_WOBButton = {
	private ["_weapon", "_putInHands"];
	call _ACE_fnc_SwitchWOBText;
	if (ctrlEnabled (_display displayCtrl ACE_BUTTON_WOB_IDC)) then {
		switch _lastIDC do {
			case CA_GEAR_SLOT_PRIMARY_IDC: {
				_weapon = primaryWeapon _unit;
				_putInHands = false;
			};

			case CA_GEAR_SLOT_SECONDARY_IDC: {
				_weapon = secondaryWeapon _unit;
				_putInHands = false;
			};

			/*Switch for WOB in hands
			case ACE_GEAR_SLOT_WOB_IDC: {
				_weapon = _unit getVariable ["ACE_weapononback",""];
				_putInHands = true;
			};*/

			default {
				_weapon = "";
				_putInHands = false;
			};
		};
		// Check if button action is "in hands"
		if ((ctrlText (_display displayCtrl ACE_BUTTON_WOB_IDC)) == (localize "STR_ACE_IN_HANDS")) then {
				_weapon = _unit getVariable ["ACE_weapononback",""];
				_putInHands = true;
		};
		TRACE_2("WOB", _weapon, _lastIDC);
		if (isNil "ace_weapononback_inprogress") then {ace_weapononback_inprogress = false};
		if (_weapon != "" && {!ace_weapononback_inprogress}) then {
				if (_putInHands) then {
					[_unit, _weapon] call FUNC(uiPutWeaponInHands);
				} else {
					[_unit, _weapon] call FUNC(uiPutWeaponOnBack);
				};
				[_unit, _display] call FUNC(uiUpdateWOBDisplay);
		};
		call _ACE_fnc_postRef;
	};
};

_ACE_fnc_PackButton = {
	private ["_itm", "_class", "_source", "_packable", "_retval", "_confNonPackable", "_confDisposable", "_confDispCompact", "_lastWep", "_numammo","_ammoidx"];
	_itm = "";
	_class = "";
	_source = "";
	_numammo = -1;
	_ammoidx = -1;
	_packable = false;
	TRACE_1("Pack 1", _lastIDC);
	if (_lastIDC == -1) then {
		TRACE_2("Pack 1", _lastIDC, _itm);
		if (_isWep) then {
			_class = "weapon";
			_source = "other";
		} else {
			_class = "magazine";
			_source = "other";
		};
	} else {
		_retval = [_unit, _lastIDC] call FUNC(uiGetSelectedInventoryType);
		TRACE_1("Pack 1", _retval);
		_itm = _retval select 0;
		_class = _retval select 1;
		_numammo = _retval select 2;
		_ammoidx = _retval select 3;
		_source = "self";
	};
	TRACE_3("Pack 2", _unit, _class, _source);
	if (_itm != "" && {_class != ""}) then {
		_packable = true;

		if (call _ACE_fnc_notAct || {!(_unit call FUNC(HasRuck))}) then {_packable = false};

		if ( _class == "weapon" ) then {
			_confNonPackable = __CONF_WEAPONS >> _itm >> "ACE_NoPack";
			if (getNumber _confNonPackable == 1) then {
				TRACE_1("Non-packable weapon", _itm);
				_packable = false;
			} else {
				_confDisposable = __CONF_WEAPONS >> _itm >> "ace_disposable";
				//_confDispCompact = __CONF_WEAPONS >> _itm >> "ace_disposable_compact";
				//if (getNumber _confDisposable == 1 && {getNumber _confDispCompact == 0}) then {
				if (getNumber _confDisposable == 1) then {
					TRACE_1("Disposable weapon", _itm);
					_packable = false;
				};
			};
		} else {
			_confNonPackable = __CONF_MAGAZINES >> _itm >> "ACE_NoPack";
			if (getNumber _confNonPackable == 1) then {
				TRACE_1("Non-packable magazine", _itm);
				_packable = false;
			} else {
				_confDisposable = __CONF_MAGAZINES >> _itm >> "ace_disposable";
				if (getNumber _confDisposable == 1) then {
					TRACE_1("Disposable magazine", _itm);
					_packable = false;
				};
			};
		};

		if (_source == "other") then {
			TRACE_1("Direct crate to ruck packing disabled for now", _source);
			_packable = false;
		};

		_lastWep = (_class == "weapon");
		if !([_unit, _itm, _lastWep] call FUNC(FitsInRucksack)) then {
			TRACE_1("Too big",_itm);
			_packable = false;
		};

		if (_class == "weapon") then {
			if !(_unit hasWeapon _itm) then {_packable = false;};
		} else {
			if !(_itm in (magazines _unit)) then {_packable = false;};
		};

		if (_packable) then {
			TRACE_2("Packing...", _unit, _itm);
			if (_class == "weapon") then {
				[_unit, _itm] call FUNC(AddWepToRuck);
				_unit removeWeapon _itm;
			} else {
				[_unit, _itm, 1, _numammo] call FUNC(AddMagToRuck);
				private ["_curweapon", "_curmuz", "_remar"];
				// TODO: If the following ticket https://dev-heaven.net/issues/54743 will get resolved replace the code below with such a command
				_t256mags = [];
				_t16mags = [];
				{
					_flag = (_ammoidx == _forEachIndex);
					if (getNumber(configFile>>"CfgMagazines">>_x>>"type") == 16) then {
						_t16mags set [count _t16mags, [_x, 0, _flag, -1]];
					} else {
						_t256mags set [count _t256mags, [_x, 0, _flag, -1]];
					};
				} forEach (magazines _unit);
				_flagedfound = false;
				for "_o" from CA_GEAR_SLOT_ITEM1_IDC to CA_GEAR_SLOT_ITEM12_IDC do {
					_acount = gearIDCAmmoCount _o;
					TRACE_1("gearIDCAmmoCount1",_acount);
					if (_acount == 0) exitWith {};
					_curmag = _t256mags select (_o - CA_GEAR_SLOT_ITEM1_IDC);
					_curmag set [1, _acount];
					_flagedfound = _curmag select 2;
					if (_lastIDC < CA_GEAR_SLOT_ITEM12_IDC && _flagedfound) then {
						_curmag set [3, _o - 1];
					} else {
						_curmag set [3, _o];
					};
				};
				_flagedfound = false;
				for "_o" from CA_GEAR_SLOT_HANDGUN_ITEM1_IDC to CA_GEAR_SLOT_HANDGUN_ITEM8_IDC do {
					_acount = gearIDCAmmoCount _o;
					TRACE_1("gearIDCAmmoCount2",_acount);
					if (_acount == 0) exitWith {};
					_curmag = _t16mags select (_o - CA_GEAR_SLOT_HANDGUN_ITEM1_IDC);
					_curmag set [1, _acount];
					_flagedfound = _curmag select 2;
					if (_lastIDC < CA_GEAR_SLOT_HANDGUN_ITEM8_IDC && _flagedfound) then {
						_curmag set [3, _o - 1];
					} else {
						_curmag set [3, _o];
					};
				};
				_curweapon = currentWeapon _unit;
				_curmuz = currentMuzzle _unit;
				_remar = [];
				{
					if !((_x select 0) in _remar) then {
						_unit removeMagazines (_x select 0);
						_remar set [count _remar, _x select 0];
					};
				} forEach (_t256mags + _t16mags);
				_mrem = false;
				{
					if (_x select 2) exitWith {
						_t256mags set [_forEachIndex, -1];
						_mrem = true;
					};
				} forEach _t256mags;
				if (!_mrem) then {
					{
						if (_x select 2) exitWith {
							_t16mags set [_forEachIndex, -1];
						};
					} forEach _t16mags;
					_t16mags = _t16mags - [-1];
				} else {
					_t256mags = _t256mags - [-1];
				};
				{
					if (_x select 1 == 0) then {
						_x set [1, getNumber(configFile>>"CfgMagazines">>(_x select 0)>>"count")];
					};
				} forEach (_t256mags + _t16mags);
				{
					//_unit addMagazine _x;
					if !([_unit, [_x select 0, _x select 1]] call FUNC(addMagazineAR)) then {
						(_x select 3) setIDCAmmoCount (_x select 1);
					};
				} forEach (_t256mags + _t16mags);
				if (_curweapon != "") then {
					//shitty workaround, otherwise the player ends up with no magazine loaded
					_unit removeWeapon _curweapon;
					_unit addWeapon _curweapon;
					_unit selectWeapon _curmuz;
				};
				// TODO If the following ticket https... END
				//_unit removeMagazine _itm;
			};
			call _ACE_fnc_postRef;
		};
	};
};

_ACE_fnc_hasMagInRuck = {
	private ["_mags","_result"];
	PARAMS_2(_unit,_magi);
	_result = false;
	__DEF_GETV(_mags,_unit,"ACE_RuckMagContents",[]);
	{
		if (_x select 1 > 0 && {_x select 0 == _magi}) exitWith {
			_result = true;
		};
	} foreach _mags;

	_result
};

_ACE_fnc_UnpackButton = {
	TRACE_2("Unpack",_itm, _isWep);
	if (!(call _ACE_fnc_notAct) && {(_unit call FUNC(HasRuck))} && {!isNil "_itm"} && {!isNil "_isWep"}) then {
		if (_itm != "") then {
			if (_isWep) then {
				if ([_unit, _itm] call FUNC(HasFreeWepSlot)) then {
					if !(_unit hasWeapon _itm) then {
						[_unit, _itm] call FUNC(RemoveWepFromRuck);
						_unit addWeapon _itm;
						call _ACE_fnc_postRef;
					} else {
						TRACE_1("Cannot unpack weapon, not unique", _itm);
					};
				} else {
					TRACE_1("Cannot unpack weapon, no space", _itm);
				};
			} else {
				if ([_unit,_itm] call FUNC(HasFreeMagSlot)) then {
					if ([_unit, _itm] call _ACE_fnc_hasMagInRuck) then {
						private ["_addar"];
						_addar = [_unit, _itm] call FUNC(RemoveMagFromRuck);
						{
							//_unit addMagazine [_itm, _x];
							[_unit, [_itm, _x]] call FUNC(addMagazineAR);
						} forEach _addar;
						call _ACE_fnc_postRef;
					} else {
						TRACE_1("Cannot unpack magazine, not in count", _itm);
					};
				} else {
					TRACE_1("Cannot unpack magazine, no space", _itm);
				};
			};
		};
	};
};

_ACE_fnc_SwitchWOBText = {
	private ["_ctrlWOB", "_hasWOB_Var", "_typeWOB", "_typeW"];
	_ctrlWOB = _display displayCtrl ACE_BUTTON_WOB_IDC;
	_ctrlWOBBox = _display displayctrl ACE_GEAR_SLOT_WOB_IDC;
	_ctrlWOBBox ctrlSetFade 0; //WOB uses different highlighting
	_ctrlWOBBox ctrlCommit 0;
	_ctrlWOBBox ctrlSetTextColor [1,1,1,0.5];
	switch (_lastIDC) do {
		_hasWOB_Var = _unit getVariable ["ACE_weapononback",""];
		_typeWOB = getNumber(__CONF_WEAPONS >> _hasWOB_Var >> "type");
		TRACE_1("", _hasWOB_Var);
		case ACE_GEAR_SLOT_WOB_IDC: {
			if (_hasWOB_Var != "") then {
				TRACE_1("Enable WOB Button and Swap Actions","");
				_ctrlWOB ctrlEnable true;
				_ctrlWOB ctrlSetText (localize "STR_ACE_IN_HANDS");
				_ctrlWOBBox ctrlSetTextColor [1,1,1,1];
			} else {
				if (ctrlEnabled _ctrlWOB) then {
					_ctrlWOB ctrlEnable false;
				};
			};
		};

		case CA_GEAR_SLOT_PRIMARY_IDC: {
			_ctrlWOB ctrlSetText (localize "STR_ACE_ON_BACK");
			_typeW = getNumber(__CONF_WEAPONS >> (primaryWeapon _unit) >> "type");
			if (primaryWeapon _unit != "" && {((_hasWOB_Var != "" && {_typeW == _typeWOB}) || {_hasWOB_Var == ""} || {[_unit, _hasWOB_Var] call FUNC(HasFreeWepSlot)})}) then {
				if !(ctrlEnabled _ctrlWOB) then {
					_ctrlWOB ctrlEnable true;
				};
			} else {
				if (ctrlEnabled _ctrlWOB) then {
					_ctrlWOB ctrlEnable false;
				};
			};
		};

		case CA_GEAR_SLOT_SECONDARY_IDC: {
			_ctrlWOB ctrlSetText (localize "STR_ACE_ON_BACK");
			_typeW = getNumber(__CONF_WEAPONS >> (secondaryWeapon _unit) >> "type");
			if (secondaryWeapon _unit != "" && {((_hasWOB_Var != "" && {_typeW == _typeWOB}) || {_hasWOB_Var == ""} || {[_unit, _hasWOB_Var] call FUNC(HasFreeWepSlot)})} && {!(secondaryWeapon _unit in ["ACE_ParachutePack","ACE_ParachuteRoundPack"])}) then {
				if !(ctrlEnabled _ctrlWOB) then {
					_ctrlWOB ctrlEnable true;
				};
			} else {
				if (ctrlEnabled _ctrlWOB) then {
					_ctrlWOB ctrlEnable false;
				};
			};
		};

		case CA_GEAR_SLOT_HANDGUN_IDC: {
			if (ctrlEnabled _ctrlWOB) then {
				_ctrlWOB ctrlEnable false;
			};
		};

		default {
			//TRACE_1("Unknown IDC", _lastIDC);
			if (ctrlEnabled _ctrlWOB) then {
				_ctrlWOB ctrlEnable false;
			};
		};
	};
};

_ACE_fnc_Show_Buttons = {
	private ["_packbtn", "_unpkbtn", "_wobbtn", "_packable", "_unpackable", "_rCont", "_retval", "_lastItm", "_lastWep", "_drkbtn"];
	if !(isClass (configFile >> "CfgPatches" >> "ace_sys_stamina")) then { ACE_SYS_STAMINA = false; };
	_packbtn = _display displayCtrl ACE_BUTTON_PACK_IDC;
	_unpkbtn = _display displayCtrl ACE_BUTTON_UNPACK_IDC;
	_wobbtn = _display displayCtrl ACE_BUTTON_WOB_IDC;
	_drkbtn = _display displayCtrl ACE_BUTTON_DRUCK_IDC;
	_packable = false;
	_unpackable = false;
	if (ACE_SYS_STAMINA && {!(call _ACE_fnc_notAct)}) then {
		if (_unit call FUNC(HasRuck)) then {
			if (call _ACE_fnc_RuckDrpb) then {_drkbtn ctrlShow true} else {_drkbtn ctrlShow false};
			if (!isNil "_itm") then {
				_rCont = _display displayCtrl ACE_RUCK_CONTENTS_IDC;
				if (!isNil {lbCurSel _rCont}) then {
					if ((lbCurSel _rCont) > -1) then {
						if (_isWep) then {
							_unpackable = [_unit, _itm] call FUNC(HasFreeWepSlot);
						} else {
							_unpackable = [_unit, _itm] call FUNC(HasFreeMagSlot);
						};
						TRACE_1("upacks",lbCurSel _rCont);
					};
				};
				_unpkbtn ctrlEnable _unpackable;
			};
			if (!isNil "_lastIDC") then {
				if (_lastIDC != -1) then {
					_retval = [_unit, _lastIDC] call FUNC(uiGetSelectedInventoryType);
					_lastItm = _retval select 0;
					_lastWep = ((_retval select 1) == "weapon");
					_packable = [_unit, _lastItm, _lastWep] call FUNC(FitsInRucksack);
					TRACE_4("packs",_lastIDC,_lastItm,_lastWep,_packable);
				};
				_packbtn ctrlEnable _packable;
			};
		} else {
			_packbtn ctrlEnable false;
			_unpkbtn ctrlEnable false;
			_drkbtn ctrlShow false;
		};
	} else {
		_packbtn ctrlEnable false;
		_unpkbtn ctrlEnable false;
		_wobbtn ctrlEnable false;
		_drkbtn ctrlShow false;
	};
};

/*-------------------------------------------*/
 _ACE_fnc_keyActions = {
	private ["_keyLeft", "_keyRight", "_keyTop", "_keyBottom", "_key", "_lbIDC", "_kcontrol"];

	_keyLeft = [203, 327700, 327686];
	_keyRight = [205, 327696, 327687];
	_keyTop = [200, 327697, 327684];
	_keyBottom = [208, 327701, 327685];
	_key = _data select 1;

	if ( ! isNil QGVAR(ruckLBfoc) ) then {
		if ((_keyLeft find _key) >= 0 ) then {

			_kcontrol = _display displayctrl ACE_RUCK_B_ADD_IDC;
			//ctrlActivate _kcontrol; //doesn't work, don't know why
			[[_kcontrol], "Ruck_onAddClick"] call FUNC(handleGear);
			_output = true;
		};

		if ( (_keyRight find _key) >= 0 ) then {
			_kcontrol = _display displayctrl ACE_RUCK_B_REMOVE_IDC;
			//ctrlActivate _kcontrol; //doesn't work, don't know why
			[[_kcontrol], "Ruck_onRemClick"] call FUNC(handleGear);
			_output = true;
		};
	} else {
		if ( ! isNil QGVAR(caLBfoc) ) then {
			//handle key behavior in order to stay inside main listbox when using arrow keys
			if ((_keyLeft find _key) >= 0 ) then {
				_kcontrol = _display displayctrl CA_B_ADD_IDC;
				ctrlActivate _kcontrol;
				_output = true;
			};

			if ( (_keyRight find _key) >= 0 ) then {
				_kcontrol = _display displayctrl CA_B_REMOVE_IDC;
				ctrlActivate _kcontrol;
				_output = true;
			};
		};
	};
	//TODO: Make entire dialog more TAB and arrow key navigation friendly, show what is selected at all times
 };

/*-------------------------------------------*/
_ACE_fnc_displayLoad = {
	private "_rcontrol";
	call _ACE_fnc_Forget_IDC;
};

_fnc_weaponsLBSetFocus = {
	private "_rCtrl";
	_rCtrl = _display displayctrl ACE_RUCK_CONTENTS_IDC;
	//_rCtrl lnbSetCurSelRow -1;
	_unit setVariable [QGVAR(lbIDC), AVAILABLE_ITEMS_IDC, false];
};

_ACE_fnc_RuckLBSetFocus = {
	private ["_rCtrl"];
	_unit setVariable [QGVAR(lbIDC), ACE_RUCK_CONTENTS_IDC, false];
};

_fnc_lbSelectedItem = {
	private ["_lbIDC", "_contCtrl", "_contIdx"];
	_lbIDC = _unit getVariable [QGVAR(lbIDC), AVAILABLE_ITEMS_IDC];
	_contCtrl = _display displayctrl _lbIDC;
	_contIdx = lbCurSel _contCtrl;
	_itm = _contCtrl lnbData [_contIdx, 1];
	_txt = _contCtrl lnbText [_contIdx, 1];
	_pic = "\" + (_contCtrl lnbPicture [_contIdx, 1]); //slash to make comparable
	if (_lbIDC == ACE_RUCK_CONTENTS_IDC) then {
		_txt = _contCtrl lnbText [_contIdx, 0];
		_typ = _contCtrl lnbData [_contIdx, 0];
	};
	call _fnc_isWeapon;
	TRACE_5("sel",_itm,_txt,_lbIDC,_contIdx,_isWep);
};

_fnc_WOBSelectedItem = {
	private ["_lbIDC", "_contCtrl", "_WOB"];
	_lbIDC = _unit getVariable [QGVAR(lbIDC), AVAILABLE_ITEMS_IDC];
	_contCtrl = _display displayctrl _lbIDC;
	//_contCtrl lnbSetCurSelRow -1;
	_WOB = _unit getVariable ["ACE_weapononback",""];
	_itm = _WOB;
	_isWep = true;
};

_fnc_isWeapon = {
	private ["_isClsWep", "_isClsMag", "_isNamWep", "_isNamMag", "_isPicWep", "_isPicMag"];
	//isClass
	_isClsWep = isClass(__CONF_WEAPONS >> _itm);
	_isClsMag = isClass(__CONF_MAGAZINES >> _itm);
	if !(_isClsWep && _isClsMag) then {_isWep = _isClsWep;};
	//displayName
	if (isNil "_isWep" && {!isNil "_txt"}) then {
		if (typeName _txt == "STRING" && {_txt != ""}) then {
			_isNamWep = (_txt == getText(__CONF_WEAPONS >> _itm >> "displayName"));
			_isNamMag = (_txt == getText(__CONF_MAGAZINES >> _itm >> "displayName"));
			if !(_isNamWep && {_isNamMag}) then {_isWep = _isNamWep;};
		};
	};
	//ruckData
	if (isNil "_isWep" && !isNil "_typ") then {
		if (typeName _typ == "STRING") then {
			if (_typ == "magazine") then {
				_isWep = false;
			} else {
				if (_typ == "weapon") then {_isWep = true;};
			};
			TRACE_2("rckD",_typ,_isWep);
		};
	};
	//scope
	if (isNil "_isWep") then {
			if ( getNumber(__CONF_WEAPONS >> _itm >> "scope") == 0 ) then {_isWep = false;};
			if ( getNumber(__CONF_MAGAZINES >> _itm >> "scope") == 0 ) then {_isWep = true;};
			TRACE_1("scp",_isWep);
	};
	//IDC
	call _ACE_fnc_Recall_IDC;
	if (isNil "_isWep" && {!isNil "_lastIDC"}) then {
		_isWep =  !(_lastIDC >= 109);
		TRACE_3("fbIDC",_itm,_lastIDC,_isWep);
	};
	//picture
	if (isNil "_isWep" && {!isNil "_pic"}) then {
		if (typeName _pic == "STRING" && {_pic != ""}) then {
			_isPicWep = (_pic == getText(__CONF_WEAPONS >> _itm >> "picture"));
			_isPicMag = (_pic == getText(__CONF_MAGAZINES >> _itm >> "picture"));
			if !(_isPicWep && {_isPicMag}) then {_isWep = _isPicWep;};
		};
	};
	//fallback
	if (isNil "_isWep") then {TRACE_1("fbFin",_itm); _isWep = false;};
};

_ACE_fnc_GearClick = {
	call _ACE_fnc_Remember_IDC;
};

_ACE_fnc_WOBClick = {
	call _ACE_fnc_Remember_IDC;
};

_fnc_displayItemInfo = {
	[_itm,_isWep,_display] call FUNC(uiUpdateItemDisplay);
};

_ACE_fnc_UpdateDisplay = {
	private "_rcontrol";
	call _ACE_fnc_SwitchWOBText;
	if ( isNil QGVAR(hg_up_disp_inpro) ) then {
		GVAR(hg_up_disp_inpro) = true;
		if ( isNil QGVAR(load) ) then {
			// some updates need to be delayed after the click event since BI gear actions are delayed, the weapons/magazine changes are not ready immediately.
			[_unit,_display] spawn FUNC(uiUpdateTotalsDelayed);
		} else {
			// No spawn needed onLoad
			[_unit,_display,false] call FUNC(uiUpdateTotalsDelayed);
		};
		[_unit,_display] call FUNC(uiUpdateTotals);
		[_unit, _display] call FUNC(uiUpdateWOBDisplay);
		call _ACE_fnc_Show_Buttons;
		call _ACE_fnc_postRef;
		GVAR(hg_up_disp_inpro) = nil;
	};
};

_ACE_fnc_Forget_IDC = {
	TRACE_1("Forget",_unit getVariable QGVAR(LastGearSlot));
	_unit setVariable[QGVAR(LastGearSlot), [-1, -1], false];
};

_ACE_fnc_Remember_IDC = {
	_lastIDC = [_unit,_display,_control,_itm,_isWep,true] call FUNC(uiHighlightSlots);
	TRACE_1("Remember",_lastIDC);
};

_ACE_fnc_Recall_IDC = {
	_lastIDC = [_unit,_display,_control,_itm,_isWep] call FUNC(uiHighlightSlots);
	TRACE_1("Recall",_lastIDC);
};

_ACE_fnc_highPack = {
	private "_pctrl";
	_pctrl = _display displayCtrl _lastIDC;
	_pctrl ctrlSetFade 0.3;
	_pctrl ctrlCommit 0;
	TRACE_1("_ACE_fnc_highPack",_pctrl,_lastIDC);
};

_ACE_fnc_postRef = {
	[_data, "forceRef"] call FUNC(handleGear);
};

_ACE_fnc_notAct = {
	((vehicle _unit != _unit) || {(time < 1)})
};

_ACE_fnc_RuckDrpb = {
	(!surfaceIsWater (getpos _unit))
};

_ACE_fnc_forceRef = {
	private ["_fctrl", "_bctrl"];
	_fctrl = _display displayCtrl CA_FILTER_ARROW_RIGHT_IDC;
	_bctrl = _display displayCtrl CA_FILTER_ARROW_LEFT_IDC;
	ctrlActivate _fctrl;
	ctrlActivate _bctrl;
	TRACE_3("Ref", _display,_fctrl,_bctrl);
};

/*-------------------------------------------*/
_output = false;
_onLoad = false;
switch _event do {
	case "onLoad": {
		_onLoad = true;
		if (! isNil "EMP_RF_RUN") then { if (EMP_RF_RUN) then {EMP_RF_STP = true} }; //pause laser designate
		GVAR(load) = true;
		GVAR(CargoCountTime) = 0;
		
		//temporary bwc, adds warnings to RPT
		private ["_umagsruck", "_oneentry", "_nammoar", "_nammoc", "_ez", "_ufoundwrong"];
		_umagsruck = _unit getVariable ["ACE_RuckMagContents", []];
		TRACE_2("",_umagsruck,_unit);
		_ufoundwrong = false;
		{
			_oneentry = _x;
			TRACE_1("before",_oneentry);
			if (count _oneentry < 3) then {
				_ufoundwrong = true;
				WARNING("ACE_RuckMagContents ammocount for magazine missing: " + str(_oneentry)); 
				_nammoar = [];
				_nammoc = getNumber(configFile/"CfgMagazines"/(_oneentry select 0)/"count");
				for "_ez" from 1 to (_oneentry select 1) do {
					_nammoar set [count _nammoar, _nammoc];
				};
				_oneentry set [count _oneentry, _nammoar];
				TRACE_1("after",_oneentry);
			} else {
				// just in case
				if (_oneentry select 1 > count (_oneentry select 2)) then {
					_nammoar = _oneentry select 2;
					_nammoc = getNumber(configFile/"CfgMagazines"/(_oneentry select 0)/"count");
					for "_ez" from (count _nammoar) to (_oneentry select 1) - 1 do {
						_nammoar set [count _nammoar, _nammoc];
					};
				};
			};
		} forEach _umagsruck;
		if (_ufoundwrong) then {
			WARNING("Please update mission or addon to make use of the ACE_fnc_PackMagazine API function !!!");
		};
		
		call _fnc_weaponsLBSetFocus;
		call _ACE_fnc_displayLoad;
		call _fnc_lbSelectedItem;
		call _ACE_fnc_Recall_IDC;
		call _fnc_displayItemInfo;
	};

	case "forceRef": {
		call _ACE_fnc_forceRef;
	};

	case "onKeyDown": {
		call _ACE_fnc_keyActions;
	};

	case "Ruck_onFocus": {
		GVAR(ruckLBfoc) = true;
		call _ACE_fnc_Forget_IDC;
		call _ACE_fnc_RuckLBSetFocus;
	};

	case "Ruck_onKillFocus": {
		GVAR(ruckLBfoc) = nil;
	};

	case "onFocus": {
		GVAR(caLBfoc) = true;
		call _ACE_fnc_Forget_IDC;
	};

	case "onKillFocus": {
		GVAR(caLBfoc) = nil;
	};

	case "onLBSelChanged": {
		call _fnc_weaponsLBSetFocus;
		call _fnc_lbSelectedItem;
		call _ACE_fnc_Recall_IDC;
		call _fnc_displayItemInfo;
	};

	case "Ruck_onLBSelChanged": {
		call _fnc_lbSelectedItem;
		call _ACE_fnc_Recall_IDC;
		call _fnc_displayItemInfo;
	};

	case "ACE_WOBButton": {
		call _ACE_fnc_Recall_IDC;
		call _ACE_fnc_WOBButton;
	};

	case "ACE_PackButton": {
		call _ACE_fnc_Recall_IDC;
		call _ACE_fnc_PackButton;
		// TODO call _ACE_fnc_highPack if there is no item in the slot abymore
		//call _ACE_fnc_highPack;
	};

	case "ACE_UnpackButton": {
		call _fnc_lbSelectedItem;
		call _ACE_fnc_UnpackButton;
	};

	/*
	case "Ruck_onAddClick": {
		//TODO: Pack ruck by type, check and pack from inventory
	};
	*/

	case "Ruck_onRemClick": {
		call _fnc_lbSelectedItem;
		call _ACE_fnc_UnpackButton;
	};

	case "Ruck_onDblClick": {
		call _fnc_lbSelectedItem;
		call _ACE_fnc_UnpackButton;
	};

	case "ACE_GearClick": {
		call _ACE_fnc_GearClick;
	};

	case "ACE_WOBClick": {
		call _fnc_WOBSelectedItem;
		call _fnc_displayItemInfo;
		call _ACE_fnc_WOBClick;
	};

	case "ACE_DRuckButton": {
		if (_unit call FUNC(HasRuck)) then { [_unit] call FUNC(DropRuck); };
	};

	case "ACE_RLockButton": {
		[_unit] call FUNC(RuckLock);
	};

	case "ACE_RLockCnxButton": {
		[_unit] call FUNC(RuckCancel);
	};
};

call _ACE_fnc_UpdateDisplay;

if (_onLoad) then {
	GVAR(load) = nil;
	ACE_gearopen = true;
};

_output
