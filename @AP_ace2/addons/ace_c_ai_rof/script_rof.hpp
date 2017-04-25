//gls
#define ACE_AI_ROF_GL_SEMI_PLAYER \
		minRangeProbab = 0;\
		midRangeProbab = 0;\
		maxRangeProbab = 0;
#define ACE_AI_ROF_GL_SEMI_AI \
		minRange = 50;\
		minRangeProbab = 0.5;\
		midRange = 150;\
		midRangeProbab = 0.9;\
		maxRange = 400;\
		maxRangeProbab = 0.05;\
		cameraDir = "";\
		memoryPointCamera = "";\
		showtoplayer = 0;

// assault rifles, carbines
#define ACE_AI_ROF_RIFLE_SMALL_SEMI_SCOPE_ \
		aiRateOfFire = 2;\
		aiRateOfFireDistance = 800;\
		minRange = 0;\
		minRangeProbab = 0.7;\
		midRange = 200;\
		midRangeProbab = 0.6;\
		maxRange = 650;\
		maxRangeProbab = 0.1;
#define ACE_AI_ROF_RIFLE_SMALL_SEMI_ \
		aiRateOfFire = 1;\
		aiRateOfFireDistance = 550;\
		minRange = 0;\
		minRangeProbab = 0.7;\
		midRange = 200;\
		midRangeProbab = 0.5;\
		maxRange = 500;\
		maxRangeProbab = 0.1;
#define ACE_AI_ROF_RIFLE_SMALL_BURST_ \
		aiRateOfFire = 1;\
		aiRateOfFireDistance = 200;\
		minRange = 0;\
		minRangeProbab = 0.8;\
		midRange = 150;\
		midRangeProbab = 0.7;\
		maxRange = 250;\
		maxRangeProbab = 0.1;
#define ACE_AI_ROF_RIFLE_SMALL_AUTO_ \
		aiRateOfFire = 0.1;\
		aiRateOfFireDistance = 50;\
		minRange = 0;\
		minRangeProbab = 0.9;\
		midRange = 60;\
		midRangeProbab = 0.7;\
		maxRange = 120;\
		maxRangeProbab = 0.1;
#define ACE_AI_ROF_RIFLE_SMALL_BURST_FAR_ \
		aiRateOfFire = 2;\
		aiRateOfFireDistance = 600;\
		minRange = 500;\
		minRangeProbab = 0.05;\
		midRange = 600;\
		midRangeProbab = 0.1;\
		maxRange = 700;\
		maxRangeProbab = 0.1;

// CQB rifles (short barrels, small calibre)
#define ACE_AI_ROF_RIFLE_CQB_SEMI_SCOPE_ \
		aiRateOfFire = 1;\
		aiRateOfFireDistance = 600;\
		minRange = 0;\
		minRangeProbab = 0.7;\
		midRange = 200;\
		midRangeProbab = 0.6;\
		maxRange = 500;\
		maxRangeProbab = 0.1;
#define ACE_AI_ROF_RIFLE_CQB_SEMI_ \
		aiRateOfFire = 1;\
		aiRateOfFireDistance = 400;\
		minRange = 0;\
		minRangeProbab = 0.7;\
		midRange = 150;\
		midRangeProbab = 0.5;\
		maxRange = 400;\
		maxRangeProbab = 0.1;
#define ACE_AI_ROF_RIFLE_CQB_BURST_ \
		aiRateOfFire = 1;\
		aiRateOfFireDistance = 200;\
		minRange = 0;\
		minRangeProbab = 0.8;\
		midRange = 100;\
		midRangeProbab = 0.7;\
		maxRange = 200;\
		maxRangeProbab = 0.1;
#define ACE_AI_ROF_RIFLE_CQB_AUTO_ \
		aiRateOfFire = 0.1;\
		aiRateOfFireDistance = 50;\
		minRange = 0;\
		minRangeProbab = 0.9;\
		midRange = 60;\
		midRangeProbab = 0.7;\
		maxRange = 120;\
		maxRangeProbab = 0.1;
#define ACE_AI_ROF_RIFLE_CQB_BURST_FAR_ \
		aiRateOfFire = 3;\
		aiRateOfFireDistance = 600;\
		minRange = 300;\
		minRangeProbab = 0.05;\
		midRange = 400;\
		midRangeProbab = 0.1;\
		maxRange = 600;\
		maxRangeProbab = 0.1;

// battle rifles, 7.62 assault rifles
#define ACE_AI_ROF_RIFLE_MEDIUM_SEMI_SCOPE_ \
		aiRateOfFire = 3;\
		aiRateOfFireDistance = 700;\
		minRange = 0;\
		minRangeProbab = 0.7;\
		midRange = 300;\
		midRangeProbab = 0.6;\
		maxRange = 700;\
		maxRangeProbab = 0.1;
#define ACE_AI_ROF_RIFLE_MEDIUM_SEMI_ \
		aiRateOfFire = 2;\
		aiRateOfFireDistance = 400;\
		minRange = 0;\
		minRangeProbab = 0.7;\
		midRange = 200;\
		midRangeProbab = 0.5;\
		maxRange = 500;\
		maxRangeProbab = 0.1;
#define ACE_AI_ROF_RIFLE_MEDIUM_BURST_ \
		aiRateOfFire = 2;\
		aiRateOfFireDistance = 200;\
		minRange = 0;\
		minRangeProbab = 0.8;\
		midRange = 50;\
		midRangeProbab = 0.7;\
		maxRange = 100;\
		maxRangeProbab = 0.1;
#define ACE_AI_ROF_RIFLE_MEDIUM_AUTO_ \
		aiRateOfFire = 0.1;\
		aiRateOfFireDistance = 50;\
		minRange = 0;\
		minRangeProbab = 0.9;\
		midRange = 20;\
		midRangeProbab = 0.7;\
		maxRange = 80;\
		maxRangeProbab = 0.1;

// with suppressors, burst and auto on shorter ranges
#define ACE_AI_ROF_RIFLE_SD_BURST_ \
		aiRateOfFire = 1;\
		aiRateOfFireDistance = 200;\
		minRange = 0;\
		minRangeProbab = 0.8;\
		midRange = 40;\
		midRangeProbab = 0.7;\
		maxRange = 80;\
		maxRangeProbab = 0.1;
#define ACE_AI_ROF_RIFLE_SD_AUTO_ \
		aiRateOfFire = 0.1;\
		aiRateOfFireDistance = 50;\
		minRange = 0;\
		minRangeProbab = 0.9;\
		midRange = 10;\
		midRangeProbab = 0.7;\
		maxRange = 30;\
		maxRangeProbab = 0.1;

// bolt action rifles (excl. sniper)
#define ACE_AI_ROF_RIFLE_MEDIUM_BOLT_SEMI_SCOPE_ \
		aiRateOfFire = 4;\
		aiRateOfFireDistance = 700;\
		minRange = 0;\
		minRangeProbab = 0.4;\
		midRange = 400;\
		midRangeProbab = 0.8;\
		maxRange = 700;\
		maxRangeProbab = 0.1;
#define ACE_AI_ROF_RIFLE_MEDIUM_BOLT_SEMI_ \
		aiRateOfFire = 3;\
		aiRateOfFireDistance = 400;\
		minRange = 0;\
		minRangeProbab = 0.4;\
		midRange = 300;\
		midRangeProbab = 0.8;\
		maxRange = 500;\
		maxRangeProbab = 0.1;

// special ak class, trigger happy
#define ACE_AI_ROF_RIFLE_AKM_SEMI_ \
		aiRateOfFire = 1;\
		aiRateOfFireDistance = 500;\
		minRange = 0;\
		minRangeProbab = 0.7;\
		midRange = 300;\
		midRangeProbab = 0.2;\
		maxRange = 400;\
		maxRangeProbab = 0.1;
#define ACE_AI_ROF_RIFLE_AKM_BURST_ \
		aiRateOfFire = 1;\
		aiRateOfFireDistance = 200;\
		minRange = 0;\
		minRangeProbab = 0.8;\
		midRange = 200;\
		midRangeProbab = 0.7;\
		maxRange = 250;\
		maxRangeProbab = 0.1;
#define ACE_AI_ROF_RIFLE_AKM_AUTO_ \
		aiRateOfFire = 0.1;\
		aiRateOfFireDistance = 50;\
		minRange = 0;\
		minRangeProbab = 0.9;\
		midRange = 100;\
		midRangeProbab = 0.7;\
		maxRange = 150;\
		maxRangeProbab = 0.1;
#define ACE_AI_ROF_RIFLE_AKM_BURST_FAR_ \
		aiRateOfFire = 2;\
		aiRateOfFireDistance = 600;\
		minRange = 400;\
		minRangeProbab = 0.05;\
		midRange = 500;\
		midRangeProbab = 0.1;\
		maxRange = 600;\
		maxRangeProbab = 0.1;

// sniper rifles (hi mag. scopes, medium-high calibre)
#define ACE_AI_ROF_RIFLE_SNIPER_SEMI_ \
		aiRateOfFire = 6;\
		aiRateOfFireDistance = 1100;\
		minRange = 0;\
		minRangeProbab = 0.4;\
		midRange = 500;\
		midRangeProbab = 0.8;\
		maxRange = 1100;\
		maxRangeProbab = 0.1;
#define ACE_AI_ROF_RIFLE_SNIPER_SEMI_338_ \
		aiRateOfFire = 8;\
		aiRateOfFireDistance = 1200;\
		minRange = 1;\
		minRangeProbab = 0.4;\
		midRange = 500;\
		midRangeProbab = 0.8;\
		maxRange = 1200;\
		maxRangeProbab = 0.1;
#define ACE_AI_ROF_RIFLE_SNIPER_SEMI_50CAL_ \
		aiRateOfFire = 10;\
		aiRateOfFireDistance = 1500;\
		minRange = 1;\
		minRangeProbab = 0.4;\
		midRange = 500;\
		midRangeProbab = 0.8;\
		maxRange = 1800;\
		maxRangeProbab = 0.1;

// light-medium machineguns
#define ACE_AI_ROF_MG_AUTO_ \
		aiRateOfFire = 0.1;\
		aiRateOfFireDistance = 50;\
		minRange = 0;\
		minRangeProbab = 0.9;\
		midRange = 20;\
		midRangeProbab = 0.7;\
		maxRange = 30+ random 20;\
		maxRangeProbab = 0.1;
#define ACE_AI_ROF_MG_CLOSE_ \
		burst = 6+round random 4;\
		aiRateOfFire = 1;\
		aiRateOfFireDistance = 200;\
		minRange = 30;\
		minRangeProbab = 0.8;\
		midRange = 50+ random 50;\
		midRangeProbab = 0.7;\
		maxRange = 100+ random 50;\
		maxRangeProbab = 0.1;
#define ACE_AI_ROF_MG_SHORT_ \
		burst = 4+round random 6;\
		aiRateOfFire = 2;\
		aiRateOfFireDistance = 400;\
		minRange = 50;\
		minRangeProbab = 0.8;\
		midRange = 100+ random 50;\
		midRangeProbab = 0.7;\
		maxRange = 300+ random 50;\
		maxRangeProbab = 0.1;
#define ACE_AI_ROF_MG_MEDIUM_ \
		burst = 4+round random 4;\
		aiRateOfFire = 2;\
		aiRateOfFireDistance = 600;\
		minRange = 100;\
		minRangeProbab = 0.8;\
		midRange = 300+ random 50;\
		midRangeProbab = 0.7;\
		maxRange = 400+ random 50;\
		maxRangeProbab = 0.1;
#define ACE_AI_ROF_MG_FAR_ \
		burst = 2+round random 4;\
		aiRateOfFire = 3;\
		aiRateOfFireDistance = 800;\
		minRange = 300;\
		minRangeProbab = 0.8;\
		midRange = 500+ random 50;\
		midRangeProbab = 0.7;\
		maxRange = 600+ random 50;\
		maxRangeProbab = 0.1;
#define ACE_AI_ROF_MG_LONG_ \
		burst = 8+round random 6;\
		aiRateOfFire = 4;\
		aiRateOfFireDistance = 1000;\
		minRange = 400;\
		minRangeProbab = 0.8;\
		midRange = 700+ random 50;\
		midRangeProbab = 0.2;\
		maxRange = 800;\
		maxRangeProbab = 0.1;

// handguns
#define ACE_AI_ROF_PISTOL_SEMI_ \
		aiRateOfFire = 0.6;\
		aiRateOfFireDistance = 50;\
		minRange = 0;\
		minRangeProbab = 0.5;\
		midRange = 20;\
		midRangeProbab = 0.3;\
		maxRange = 80;\
		maxRangeProbab = 0.01;
#define ACE_AI_ROF_PISTOL_AUTO_ \
		aiRateOfFire = 0.4;\
		aiRateOfFireDistance = 50;\
		minRange = 0;\
		minRangeProbab = 0.6;\
		midRange = 10;\
		midRangeProbab = 0.4;\
		maxRange = 20;\
		maxRangeProbab = 0.05;

// submachineguns
#define ACE_AI_ROF_SMG_SEMI_ \
		aiRateOfFire = 1;\
		aiRateOfFireDistance = 200;\
		minRange = 0;\
		minRangeProbab = 0.7;\
		midRange = 75;\
		midRangeProbab = 0.5;\
		maxRange = 150;\
		maxRangeProbab = 0.05;
#define ACE_AI_ROF_SMG_BURST_ \
		aiRateOfFire = 1;\
		aiRateOfFireDistance = 100;\
		minRange = 0;\
		minRangeProbab = 0.8;\
		midRange = 50;\
		midRangeProbab = 0.7;\
		maxRange = 100;\
		maxRangeProbab = 0.1;
#define ACE_AI_ROF_SMG_AUTO_ \
		aiRateOfFire = 0.1;\
		aiRateOfFireDistance = 50;\
		minRange = 0;\
		minRangeProbab = 0.9;\
		midRange = 10;\
		midRangeProbab = 0.7;\
		maxRange = 40;\
		maxRangeProbab = 0.1;

//shotguns
#define ACE_AI_ROF_SHOTGUN_SEMI \
		minRange = 0;\
		minRangeProbab = 0.7;\
		midRange = 60;\
		midRangeProbab = 0.2;\
		maxRange = 120;\
		maxRangeProbab = 0.05;
#define ACE_AI_ROF_SHOTGUN_AUTO \
		minRange = 0;\
		minRangeProbab = 0.8;\
		midRange = 40;\
		midRangeProbab = 0.5;\
		maxRange = 60;\
		maxRangeProbab = 0.1;


#define ACE_SMALL_BURSTS \
	class ACE_Burst: Single { \
		ACE_AI_ROF_RIFLE_SMALL_BURST_ \
		displayName = $STR_DN_MODE_BURST; \
		burst = 3; \
		soundBurst = 0; \
	}; \
	class ACE_Burst_AI: ACE_Burst { \
		burst = 3 + round random 5; \
		showtoplayer = 0; \
	}; \
	class ACE_Burst_AI2: ACE_Burst_AI { \
		burst = 3 + round random 5; \
	}

#define ACE_MEDIUM_BURSTS \
	class ACE_Burst: Single { \
		ACE_AI_ROF_RIFLE_MEDIUM_BURST_ \
		displayName = $STR_DN_MODE_BURST; \
		burst = 3; \
		soundBurst = 0; \
	}; \
	class ACE_Burst_AI: ACE_Burst { \
		burst = 2 + round random 4; \
		showtoplayer = 0; \
	}; \
	class ACE_Burst_AI2: ACE_Burst_AI { \
		burst = 2 + round random 4; \
	}

#define ACE_SD_BURSTS \
	class ACE_Burst: Single { \
		ACE_AI_ROF_RIFLE_SD_BURST_ \
		displayName = $STR_DN_MODE_BURST; \
		burst = 3; \
		soundBurst = 0; \
	}; \
	class ACE_Burst_AI: ACE_Burst { \
		burst = 2 + round random 3; \
		showtoplayer = 0; \
	}; \
	class ACE_Burst_AI2: ACE_Burst_AI { \
		burst = 2 + round random 3; \
	}


#define ACE_SCARL_MODES \
	class ACE_Burst: SCAR_L_Single { \
		ACE_AI_ROF_RIFLE_SMALL_BURST_ \
		displayName = $STR_DN_MODE_BURST; \
		burst = 3; \
		soundBurst = 0; \
	}; \
	class ACE_Burst_AI: ACE_Burst { \
		burst = 3 + round random 5; \
		showtoplayer = 0; \
	}; \
	class ACE_Burst_AI2: ACE_Burst_AI { \
		burst = 3 + round random 5; \
	}; \
	modes[] = {"SCAR_L_Single", "SCAR_L_FullAuto", "ACE_Burst_AI", "ACE_Burst_AI2"}

#define ACE_SCARH_MODES \
	class ACE_Burst: SCAR_H_Single { \
		ACE_AI_ROF_RIFLE_MEDIUM_BURST_ \
		displayName = $STR_DN_MODE_BURST; \
		burst = 3; \
		soundBurst = 0; \
	}; \
	class ACE_Burst_AI: ACE_Burst { \
		burst = 2 + round random 4; \
		showtoplayer = 0; \
	}; \
	class ACE_Burst_AI2: ACE_Burst_AI { \
		burst = 2 + round random 4; \
	}; \
	modes[] = {"SCAR_H_Single", "SCAR_H_FullAuto", "ACE_Burst_AI", "ACE_Burst_AI2"}

#define ACE_SCARLSD_MODES \
	class ACE_Burst: SCAR_L_SD_Single { \
		ACE_AI_ROF_RIFLE_SD_BURST_ \
		displayName = $STR_DN_MODE_BURST; \
		burst = 3; \
		soundBurst = 0; \
	}; \
	class ACE_Burst_AI: ACE_Burst { \
		burst = 2 + round random 3; \
		showtoplayer = 0; \
	}; \
	class ACE_Burst_AI2: ACE_Burst_AI { \
		burst = 2 + round random 3; \
	}; \
	modes[] = {"SCAR_L_SD_Single", "SCAR_L_SD_FullAuto", "ACE_Burst_AI", "ACE_Burst_AI2"}

#define ACE_SCARHSD_MODES \
	class ACE_Burst: SCAR_H_SD_Single { \
		ACE_AI_ROF_RIFLE_SD_BURST_ \
		displayName = $STR_DN_MODE_BURST; \
		burst = 3; \
		soundBurst = 0; \
	}; \
	class ACE_Burst_AI: ACE_Burst { \
		burst = 2 + round random 3; \
		showtoplayer = 0; \
	}; \
	class ACE_Burst_AI2: ACE_Burst_AI { \
		burst = 2 + round random 3; \
	}; \
	modes[] = {"SCAR_H_SD_Single", "SCAR_H_SD_FullAuto", "ACE_Burst_AI", "ACE_Burst_AI2"}
