HoJoFlashPos = [];

disableSerialization;

_XD_display = uiNamespace getVariable "FlashLightDialog";
{
	HoJoFlashPos = HoJoFlashPos + [ctrlPosition (_XD_display displayCtrl _x)];
} foreach [174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191];

closeDialog 0;
