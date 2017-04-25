disableuserinput true;
createDialog "FlashLightDialog";
disableuserinput false;

disableSerialization;

if (isNil "HoJoFlashPos") then {
	HoJoFlashPos = [];
	HOMJ_FlashColor = ["White", [1,1,1]];
	hint "FLASHLIGHT INSTRUCTIONS:\n\nClick the '?' button to repeat this message.\n\nSend a signal by clicking on the signal's words. Change your signal's color by clicking on the color's text.\n\nYou may relocate the dialog on your screen. If you close the dialog with your 'Esc' key, it will not leave an overlay on-screen.\n\nOpen the dialog with your action menu!";
};

HOMJ_FlashColor execVM "Flashlight\ChangeColor.sqf"; // "change" color of dialogs and such to the already-existing color selection

if (count HoJoFlashPos > 0) then {
	_y = 0;
	_XD_display = uiNamespace getVariable "FlashLightDialog";
	{
		(_XD_display displayCtrl _x) ctrlSetPosition (HoJoFlashPos select _y);
		(_XD_display displayCtrl _x) ctrlCommit 0;
		_y = _y + 1;
	} foreach [174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191]; // move dialogs to position
};

if (isNil "H_OverlayPos") then {
	H_OverlayPos = [];
	//idc 175 = codes pic
	//idc's 176-182 = signal names, hail ... SOS
	_XD_display = uiNamespace getVariable "FlashLightDialog";
	{
		H_OverlayPos = H_OverlayPos + [ctrlPosition (_XD_display displayCtrl _x)];
	} foreach [175,176,177,178,179,180,181,182];
};

//Now hide the overlay by moving it way off-screen:
_y = 0;
_XD_display = uiNamespace getVariable "FlashlightCodes";
{
	//(_XD_display displayCtrl _x) ctrlSetPosition [2,2];
	(_XD_display displayCtrl _x) ctrlSetPosition [-2000,-2000];
	(_XD_display displayCtrl _x) ctrlCommit 0;
	_y = _y + 1;
} foreach [1001,1002,1003,1004,1005,1006,1007,1008];

//Display overlay again, by moving it back on-screen:

waitUntil {!dialog || !alive player};

if (!alive player) then {waitUntil {alive player}};

if (isNil "HOMJ_FlashOverlay") then {CutRsc ["FlashlightCodes" , "PLAIN", 0]};

_y = 0;
_XD_display = uiNamespace getVariable "FlashlightCodes";
{
//	player sidechat format ["%1",HoJo_tmp];
	(_XD_display displayCtrl _x) ctrlSetPosition (H_OverlayPos select _y);
	(_XD_display displayCtrl _x) ctrlCommit 0;
	_y = _y + 1;
} foreach [1001,1002,1003,1004,1005,1006,1007,1008];