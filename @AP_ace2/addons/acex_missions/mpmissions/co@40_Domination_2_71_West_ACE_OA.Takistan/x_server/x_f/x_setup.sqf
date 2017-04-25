#include "x_macros.sqf"
#define __OWN_SIDE_WEST__
#define __ACE__
#define __OA__
#define __DEFAULT__
#define __D_VER_NAME__ "DominationOA! One Team - A.C.E. West"
#define __D_NUM_PLAYERS__ 40
#define __D_RESPAWN_DELAY__ 20
#define __UI_Path(lfile) QUOTE(\ca\ui\data\lfile)
#ifdef __TOH__
#define __GLOGO __UI_Path(helisim_logo_ca.paa)
#else
#define __GLOGO __UI_Path(logo_arma2ep1_ca.paa)
#endif

#ifdef __CO__
#undef __GLOGO
#endif
