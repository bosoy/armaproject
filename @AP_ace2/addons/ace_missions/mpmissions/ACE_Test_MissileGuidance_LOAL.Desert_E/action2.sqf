ace_test_debug2_enabled = if !(isNil "ace_test_debug2_enabled") then {
	hint "Disabled";
	nil;
} else {
	hint "Enabled";
	true;
};
