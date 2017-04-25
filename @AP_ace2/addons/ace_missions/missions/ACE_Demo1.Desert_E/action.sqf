ace_test_debug_disabled = if (isNil "ace_test_debug_disabled") then {
	hint "Disabled";
	true;
} else {
	hint "Enabled";
	nil;
};
