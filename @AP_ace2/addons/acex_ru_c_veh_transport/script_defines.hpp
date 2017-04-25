// Can be included in other modfolders c_veh_transport when needed

// Parts
#define DEFAULT_TRANSPORT_WEAPONS ACE_M_WEP(ACE_JerryCan_Dummy_15,1)
#define DEFAULT_TRANSPORT_MAGAZINES ACE_M_MAG(ACE_Rope_TOW_M_5,1); ACE_M_MAG(SmokeShell,2); ACE_M_MAG(SmokeShellGreen,2)

#define TRANSPORT_MAX transportMaxMagazines = 9999; transportMaxWeapons = 9999; transportMaxBackpacks = 9999

#define MEDIC_TRANSPORT_WEAPONS ACE_M_WEP(ACE_Stretcher,2)
#define MEDIC_TRANSPORT_MAGAZINES ACE_M_MAG(ACE_Bandage,100); ACE_M_MAG(ACE_LargeBandage,50); ACE_M_MAG(ACE_Morphine,100); ACE_M_MAG(ACE_Epinephrine,100); ACE_M_MAG(ACE_Medkit,20); ACE_M_MAG(ACE_Bodybag,2)

// TODO: Default Side transport weaps+mags
#define WEST_TRANSPORT_WEAPONS
#define WEST_TRANSPORT_MAGAZINES ACE_M_MAG(HandGrenade_West,2)

#define EAST_TRANSPORT_WEAPONS
#define EAST_TRANSPORT_MAGAZINES ACE_M_MAG(HandGrenade_East,2)

#define ALL_DEFAULTS TRANSPORT_MAX


// TODO: Tanks/Air need special consideration

// Sets
#define ALL_DEFAULT		ALL_DEFAULTS; \
		class TransportWeapons { \
			DEFAULT_TRANSPORT_WEAPONS; \
		}; \
		class TransportMagazines { \
			DEFAULT_TRANSPORT_MAGAZINES; \
		}

#define MEDIC_DEFAULT		ALL_DEFAULTS; \
		class TransportWeapons { \
			DEFAULT_TRANSPORT_WEAPONS; \
			MEDIC_TRANSPORT_WEAPONS; \
		}; \
		class TransportMagazines { \
			DEFAULT_TRANSPORT_MAGAZINES; \
			MEDIC_TRANSPORT_MAGAZINES; \
		}

#define MEDIC_B_DEFAULT		ALL_DEFAULTS; \
		class TransportWeapons { \
			MEDIC_TRANSPORT_WEAPONS; \
		}; \
		class TransportMagazines { \
			MEDIC_TRANSPORT_MAGAZINES; \
		}


#define WEST_DEFAULT		ALL_DEFAULTS; \
		class TransportWeapons { \
			DEFAULT_TRANSPORT_WEAPONS; \
		}; \
		class TransportMagazines { \
			DEFAULT_TRANSPORT_MAGAZINES; \
		}

#define EAST_DEFAULT		TRANSPORT_MAX; \
		class TransportWeapons { \
			DEFAULT_TRANSPORT_WEAPONS; \
		}; \
		class TransportMagazines { \
			DEFAULT_TRANSPORT_MAGAZINES; \
		}


// Custom

#define WEST_TOW 		ALL_DEFAULTS; \
		class TransportWeapons { \
			DEFAULT_TRANSPORT_WEAPONS; \
		}; \
		class TransportMagazines { \
			DEFAULT_TRANSPORT_MAGAZINES; \
			ACE_M_MAG(ACE_TOW_CSWDM,5); \
		}
		
#define WEST_STINGER		ALL_DEFAULTS; \
		class TransportWeapons { \
			DEFAULT_TRANSPORT_WEAPONS; \
		}; \
		class TransportMagazines { \
			DEFAULT_TRANSPORT_MAGAZINES; \
			ACE_M_MAG(ACE_Stinger_CSWDM,4); \
		}

#define EAST_STRELA 		ALL_DEFAULTS; \
		class TransportWeapons { \
			DEFAULT_TRANSPORT_WEAPONS; \
		}; \
		class TransportMagazines { \
			DEFAULT_TRANSPORT_MAGAZINES; \
			ACE_M_MAG(ACE_9M31_CSWDM,4); \
		}