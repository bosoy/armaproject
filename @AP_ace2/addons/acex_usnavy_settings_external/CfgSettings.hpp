#ifdef CfgSettings
	#undef CfgSettings
#endif
#ifdef ACE
	#undef ACE
#endif

class CfgSettings {
	class PREFIX {
		#include "\userconfig\ace\ace_clientside_config.hpp"
		#include "\userconfig\ace\ace_serverconfig.hpp"
	};
};
