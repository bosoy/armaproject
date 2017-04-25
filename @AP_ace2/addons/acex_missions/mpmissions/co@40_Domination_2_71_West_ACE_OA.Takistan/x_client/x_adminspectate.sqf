// by Xeno
#define THIS_FILE "x_adminspectate.sqf"
#include "x_setup.sqf"

xr_phd_invulnerable = true;
player setVariable ["ace_w_allow_dam", false];
if (__TTVer) then {
	if (GVAR(side_player) == east) then {
		KEGs_ShownSides = [east, west];
	} else {
		KEGs_ShownSides = [west, east];
	};
} else {
	KEGs_ShownSides = [GVAR(side_player)];
};
KEGs_can_exit_spectator = true;
KEGs_playable_only = true;
KEGs_no_butterfly_mode = true;
if (!isNil QGVAR(a_d_cur_unit) && {!isNull GVAR(a_d_cur_unit)} ) then {
	KEGs_target = GVAR(a_d_cur_unit);
};

[player, objNull, "x"] execVM "spect\specta.sqf";
