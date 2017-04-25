#define COMPONENT a2_compat
#include "\x\acex_usnavy\addons\main\script_mod.hpp"
#include "\x\acex_usnavy\addons\main\script_macros.hpp"

#define SCOPE scope = 1

// BC_PRELOAD(CACharacters_E)
#define BC_PRELOAD(A) class ACE_COMPAT_##A { list[]= {QUOTE(A)}; }

// class M119; BC_REMAP(ACE_M119,M119);
#define BC_REMAP(A,B) class A: B { ACE_NOARMORY; ACE_BWC; };
#define BC_REMAP_B(A,B) class B; class A: B { ACE_NOARMORY; ACE_BWC; };

// class M119; BC_REMAP_VEH(ACE_M119,M119);
#define BC_REMAP_VEH(A,B) class A: B { SCOPE; ACE_NOARMORY; ACE_BWC; };
#define BC_REMAP_VEH_B(A,B) class B; class A: B { SCOPE; ACE_NOARMORY; ACE_BWC; };
