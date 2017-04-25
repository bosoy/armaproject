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

	#ifdef CBA
		#undef CBA
	#endif
	#ifdef ACE
		#undef ACE
	#endif
	#ifdef ACEX
		#undef ACEX
	#endif

	// For serverconfig
	class CBA {
		#ifdef Versioning
			#undef Versioning
		#endif
		#ifdef Registry
			#undef Registry
		#endif
		#ifdef dependencies
			#undef dependencies
		#endif
		#ifdef VERSIONING_LEVEL
			class Versioning {
				class ACE {
					class dependencies;
					level = VERSIONING_LEVEL;
				};
				class ACEX {
					class dependencies;
					level = VERSIONING_LEVEL;
				};
			};
		#endif
		#ifndef VERSIONING_LEVEL
			class Versioning;
			class Registry;
		#endif
	};
};
