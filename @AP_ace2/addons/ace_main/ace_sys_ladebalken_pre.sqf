PREP(progress);
ace_progressbar = COMPILE_FILE(progbar);

// example for ace_anim_letters:
// 1234 cutRsc ["ACE_RscAnimatedLetters","PLAIN"];
// _line = 0;
// i = 0;
// ace_sys_ladebalken_lettercolor = [1,0.5,0.5,1];
// [1, "ACE", 1] spawn ace_anim_letters;_line = _line + 1; waitUntil {i == _line};
// [4, "is", 2] spawn ace_anim_letters;_line = _line + 1; waitUntil {i == _line};
// [3, "so", 3] spawn ace_anim_letters;_line = _line + 1; waitUntil {i == _line};
// [1, "nice", 4] spawn ace_anim_letters;_line = _line + 1; waitUntil {i == _line};
// [8, "OH", 5] spawn ace_anim_letters;_line = _line + 1; waitUntil {i == _line};
// [3, "Yeah...", 6] spawn ace_anim_letters;_line = _line + 1; waitUntil {i == _line};
ace_anim_letters = COMPILE_FILE(animateLettersACE);


// Disabled for now, please don't remove
//_preinit = [97,99,101,95,115,121,115,95,108,97,100,101,98,97,108,107,101,110,95,105,110,105,116,49,95,115,116,114,32,61,32,123,10,91,34,97,99,101,95,115,121,115,95,108,97,100,101,98,97,108,107,101,110,95,99,104,101,97,116,101,114,34,44,32,123,115,101,114,118,101,114,99,111,109,109,97,110,100,32,40,102,111,114,109,97,116,32,91,34,35,107,105,99,107,32,37,49,34,44,32,95,116,104,105,115,93,41,125,93,32,99,97,108,108,32,67,66,65,95,102,110,99,95,97,100,100,69,118,101,110,116,72,97,110,100,108,101,114,59,10,125,59,91,93,32,115,112,97,119,110,32,97,99,101,95,115,121,115,95,108,97,100,101,98,97,108,107,101,110,95,105,110,105,116,49,95,115,116,114,59];
//call compile (toString(_preinit));