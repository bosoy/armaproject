class CfgIdentities {
	#ifndef ACE_IDENTITY
		#define ACE_IDENTITY John Doe
	#endif
	
	class ACE_Original_Identity {
		name = QUOTE(ACE_IDENTITY);
		#ifdef ACE_CUSTOMFACE
			face = QUOTE(ACE_CUSTOMFACE);
		#else
			face = "Default";
		#endif
		pitch=0.8213051;
		glasses = "None";
		//#ifdef ACE_NOVOICE
		//	speaker = "Male01EN";
		//#else
			speaker = "Male01";
		//#endif
		class ACE {
			class ACE_GOGGLES {
				resource = "Default";
				protection = -1; // 0 = none, but goggle; 1 = eyes, goggle; 2 = facemask only, 3 = eyes,gasmask, 4 - visor, -1 = no eye wear / mask on player
			};
		};
	};
	class ACE_Glasses_None: ACE_Original_Identity {
		glasses = "None";
		class ACE: ACE {
			class ACE_GOGGLES: ACE_GOGGLES {
				protection = 0;
			};
		};
	};
	class ACE_GlassesSpectacles: ACE_Glasses_None {
		glasses = "Spectacles";
	};
	class ACE_GlassesRoundGlasses: ACE_Glasses_None {
		glasses = "RoundGlasses";
	};
	class ACE_GlassesBlackSun: ACE_Glasses_None {
		glasses = "BlackSun";
		class ACE: ACE {
			class ACE_GOGGLES: ACE_GOGGLES {
				resource = "ACE_GlassesSunglasses";
			};
		};
	};
	class ACE_GlassesBlueSun: ACE_Glasses_None {
		glasses = "BlueSun";
		class ACE: ACE {
			class ACE_GOGGLES: ACE_GOGGLES {
				resource = "ACE_GlassesSunglasses";
			};
		};
	};
	class ACE_GlassesRedSun: ACE_Glasses_None {
		glasses = "RedSun";
		class ACE: ACE {
			class ACE_GOGGLES: ACE_GOGGLES {
				resource = "ACE_GlassesSunglasses";
			};
		};
	};
	class ACE_GlassesGreenSun: ACE_Glasses_None {
		glasses = "GreenSun";
		class ACE: ACE {
			class ACE_GOGGLES: ACE_GOGGLES {
				resource = "ACE_GlassesSunglasses";
			};
		};
	};
	class ACE_GlassesSunglasses: ACE_Glasses_None {
		glasses = "Sunglasses";
		class ACE: ACE {
			class ACE_GOGGLES: ACE_GOGGLES {
				resource = "ACE_GlassesSunglasses";
			};
		};
	};
	class ACE_GlassesLHD_glasses: ACE_Original_Identity {
		glasses = "Delta_glasses";
		class ACE: ACE {
			class ACE_GOGGLES: ACE_GOGGLES {
				resource = "ACE_GlassesLHD_glasses";
				protection = 1;
			};
		};
	};
	class ACE_GlassesTactical: ACE_GlassesLHD_glasses {
		glasses = "Tactical";
		class ACE: ACE {
			class ACE_GOGGLES: ACE_GOGGLES {
				resource = "ACE_GlassesTactical";
			};
		};
	};
	class ACE_GlassesGasMask_US: ACE_Original_Identity {
		glasses = "ACE_GasMask_US";
		class ACE: ACE {
			class ACE_GOGGLES: ACE_GOGGLES {
				resource = "ACE_Gasmask_US";
				protection = 3;
			};
		};
	};
	class ACE_GlassesGasMask_RU: ACE_GlassesGasMask_US {
		glasses = "ACE_GasMask_RU";
	};
	class ACE_GlassesGasMask2_US: ACE_GlassesGasMask_US {
		glasses = "ACE_GasMask2_US";
	};
	class ACE_GlassesGasMask_S10: ACE_GlassesGasMask2_US {
		glasses = "ACE_GasMask_S10";
	};
	class ACE_GlassesBalaklava: ACE_Original_Identity {
		glasses = "ACE_Balaklava";
		class ACE: ACE {
			class ACE_GOGGLES: ACE_GOGGLES {
				protection = 2;
			};
		};
	};
	class ACE_GlassesBalaklavaGray: ACE_GlassesBalaklava {
		glasses = "ACE_BalaklavaGray";
	};
	class ACE_GlassesBalaklavaOlive: ACE_GlassesBalaklava {
		glasses = "ACE_BalaklavaOlive";
	};
	class ACE_GlassesBalaklava_Skull: ACE_Original_Identity {
		glasses = "ACE_Balaklava_Skull";
		class ACE: ACE {
			class ACE_GOGGLES: ACE_GOGGLES {
				protection = 2;
			};
		};
	};
	class ACE_GlassesBalaklava_Pink: ACE_Original_Identity {
		glasses = "ACE_Balaklava_Pink";
		class ACE: ACE {
			class ACE_GOGGLES: ACE_GOGGLES {
				protection = 2;
			};
		};
	};	
	class ACE_GlassesHaha: ACE_Original_Identity {
		glasses = "ACE_Haha";
	};
	
	class ACE_Visor: ACE_Original_Identity {
		glasses = "ACE_Visor";
		class ACE: ACE {
			class ACE_GOGGLES: ACE_GOGGLES {
				resource = "ACE_Visor";
				protection = 4;
			};		
		};
	};

	class ACE_GlassesMFS: ACE_Original_Identity {
		//glasses = "ACE_MFS";
		glasses = "ACE_MFSVisor";
		class ACE: ACE {
			class ACE_GOGGLES: ACE_GOGGLES {
				resource = "ACE_GlassesMFS";
				protection = 1;
			};		
		};
	};
	class ACE_GlassesMFSVisor: ACE_GlassesMFS {
		glasses = "ACE_MFSVisor";
		class ACE: ACE {
			class ACE_GOGGLES: ACE_GOGGLES {
				resource = "ACE_GlassesMFS";
				protection = 1;
			};		
		};	
	};
	class ACE_GlassesMFS_R: ACE_GlassesMFS {
		//glasses = "ACE_MFS_R";
		glasses = "ACE_MFS_RVisor";
		class ACE: ACE {
			class ACE_GOGGLES: ACE_GOGGLES {
				resource = "ACE_GlassesMFS";
				protection = 1;
			};		
		};	
	};
	class ACE_GlassesMFS_RVisor: ACE_GlassesMFS_R{
		glasses = "ACE_MFS_RVisor";
		class ACE: ACE {
			class ACE_GOGGLES: ACE_GOGGLES {
				resource = "ACE_GlassesMFS";
				protection = 1;
			};		
		};	
	};
};
