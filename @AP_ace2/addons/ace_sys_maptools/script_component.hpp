#define IS_ACE 1
#ifdef IS_ACE
    #define ITEMNAME ACE_Map_Tools
    #include "ace_script_component.hpp"
#else
    #define ITEMNAME NOU_Map_Tools
    #include "standalone_script_component.hpp"
#endif