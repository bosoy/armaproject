#define COMPONENT veh_su34
#define COMPONENT_COM veh_su_common
#define COMPONENT_COM_C DOUBLES(c,COMPONENT_COM)
#define COMPONENT_COM_T DOUBLES(t,COMPONENT_COM)
#define PATHTO_COM_C(var1) PATHTOF2_SYS(PREFIX,COMPONENT_COM_C,var1)
#define PATHTO_COM_T(var1) PATHTOF2_SYS(PREFIX,COMPONENT_COM_T,var1)
#define MODULAR
#include "\x\acex_ru\addons\main\script_mod.hpp"
#include "\x\acex_ru\addons\main\script_macros.hpp"
