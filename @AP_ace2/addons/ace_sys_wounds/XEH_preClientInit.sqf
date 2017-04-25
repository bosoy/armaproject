#include "script_component.hpp"

ADDON = false;
LOG(MSG_INIT);

GVAR(drag) = false;
GVAR(carry) = false;
GVAR(dropAction) = -3333;
GVAR(carryAction) = -3333;
GVAR(loadAction) = -3333;

PREP(examansw);
PREP(bandage);
PREP(epi);
PREP(morphine);
PREP(CATremove);
PREP(cpr);
PREP(drag);

PREP(pullvec);

PREP(stretcher);
PREP(drop_stretcher);

PREP(blackoutp);

PREP(dragkeydown);
PREP(mapunckeydown);

PREP(effect);

ADDON = true;
