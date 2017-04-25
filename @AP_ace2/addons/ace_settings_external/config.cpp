#include "script_component.hpp"
class CfgPatches {
	class ADDON {
		units[] = {};
		weapons[] = {};
		requiredVersion = REQUIRED_VERSION;
		requiredAddons[] = {
			"CAData",
			"CACharacters", "CACharacters2",
			"CACharacters_E",
			QUOTE(MAIN_ADDON), "ace_sys_ruck", "ace_c_weapon", "ace_c_vehicle",
			"ace_m_tracer",
			"ace_c_men_gear"
		};
		version = VERSION;
	};
};

// Protection

// Cfg
class CfgMods;
class CfgExperience;
class CfgAISkill;
class CfgDifficulties;
class CfgInventory;
class CfgTextureToMaterial;
class CfgMaterials;
class CfgVehicleActions;
// class CfgWeaponCursors;
//class CfgAmmo;
class CfgRecoils;
//class CfgMagazines;
// class CfgWeapons;
class CfgCloudlets;
class CfgOpticsEffect;
class CfgDestructPos;
class CfgDamageAround;
class CfgLights;
class CfgCloth;
class CfgVehicleClasses;
class CfgFactionClasses;
// class CfgVehicles;
class CfgNonAIVehicles;
class CfgSimulationCosts;
class CfgMarkedTargets;
class CfgFSMs;
class CfgSkeletonParameters;
class CfgVoice;
class CfgVoiceTypes;
class CfgCoreData;
class CfgVehicleIcons;
class CfgCloudletShapes;
class CfgSaveThumbnails;
class CfgSurfaceCharacters;
class CfgSurfaces;
class CfgDefaultSettings;
// class CfgPatches; // ;-)
class CfgFontFamilies;
class CfgFonts;
class CfgEditCamera;
class CfgWrapperUI;
//class CfgInGameUI;
//class CfgDiary;
class CfgActions;
class CfgMissions;
class CfgDefaultKeysMapping;
class CfgDetectors;
class CfgFaceWounds;
class CfgGlasses;
class CfgFaces;
class CfgMimics;
class CfgEnvSounds;
class CfgHQIdentities;
class CfgHeads;
class CfgMusic;
class CfgSounds;
class CfgWhistleSound;
class CfgTitles;
class CfgIntro;
class CfgCredits;
class CfgCutScenes;
class CfgCameraEffects;
class CfgMarkers;
class CfgMarkerColors;
class CfgMarkerBrushes;
class CfgLocationTypes;
class CfgWorlds;
class CfgWorldList;
class CfgGroups;
class CfgAddons;
class CfgEditorObjects;
class CfgMPGameTypes;
class CfgLiveStats;
class CfgAchievements;
class CfgVoiceMask;
class CfgRumble;
class CfgCameraShake;
class CfgMovesButterfly;
class CfgMovesBasic;
class CfgMovesMaleSdr;
class CfgGesturesMale;
class CfgMovesWomen;
class CfgMovesSportWomen;
class CfgMovesOldWomen;
class CfgDestroy;
class CfgSFX;
class CfgCivilianConversations;
class CfgCivilianScreams;
class CfgCivilianRemarks;
class CfgCivilianActions;
class CfgObjectCompositions;
class CfgCivilianConversations_EP1;
class CfgCivilianScreams_EP1;
class CfgCivilianRemarks_EP1;
class CfgCivilianActions_EP1;
// class CfgIdentities;
class CfgRadio;
class CfgMovesAnimal;
class CfgMovesBird;
class CfgTasks;
class CfgMovesAnimalsBase;
class CfgMovesCock;
class CfgMovesHen;
class CfgMovesCow;
class CfgMovesDog;
class CfgMovesGoat;
class CfgMovesRabbit;
class CfgMovesSheep;
class CfgMovesWildBoar;
class CfgLanguages;
class CfgTalkTopics;
class CfgTalkSentences;
class CfgArmory;
class CfgSecOps;
class CfgTalkSentences_E;

// Other
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class MissileManualEffects;
class MissileEffects;
class ImpactEffectsBig;
class ImpactEffectsSmall;
class ImpactEffectsBlood;
class ImpactEffectsWater;
class ExplosionEffects;
class ExhaustsEffect;
class ExhaustsEffectBig;
class LDustEffects;
class RDustEffects;
class LWaterEffects;
class RWaterEffects;
class LEngEffects;
class REngEffects;
class FDustEffects;
class HeliDust;
class HeliWater;
class DamageSmokeHeli;
class DamageSmokePlane;
class ScudEffect;
class WeaponFireGun;
class WeaponFireMGun;
class WeaponCloudsGun;
class WeaponCloudsMGun;
class AirplaneHUD;
class PreloadVehicles;
class cfgFormations;
class UserActionsConflictGroups;
class UserActionGroups;
class cfgGroupIcons;
class PreloadTextures;
class DefaultAnalogCurveDefs;
class DefaultMouseCurveDefs;
class ButtonDeadZonesDefault;
class ControllerTypes;
class ControllerSchemes;
class DefaultTextAttributes;
class DefaultSounds;
class DisplayMultiplayerServerAdvanced;
class DisplayMultiplayerServerAdvancedSelect;
class DisplayMultiplayerServerSettings;
class RadioChannels;
//class RadioProtocolBase;
class RadioProtocolDefault;
class PreloadConfig;
class DefaultEventhandlers;
class MaskFace;
class MaskFaceWoman;
class EyeMask;
class EyeMaskWoman;
class LipMask;
class NoEffect;
class Missile1;
class Missile2;
class Missile3;
class Missile4;
class Missile5;
class GrenadeCrater;
class MortarCrater;
class ATMissileCrater;
class AAMissileCrater;
class ATRocketCrater;
class HERocketCrater;
class HEShellCrater;
class ArtyShellCrater;
class ExploAmmoCrater;
class ImpactMetal;
class ImpactGlass;
class ImpactGlassThin;
class ImpactWood;
class ImpactPlaster;
class ImpactRubber;
class ImpactBlood;
class ImpactConcrete;
class ImpactLeaves;
class BombCrater;
class ExplosionEffectsWater;
class CannonFire;
class heavyCaliber;
class SencondaryExplosion;
class GrenadeExplosion;
class MortarExplosion;
class WPExplosion;
class ATMissileExplosion;
class AAMissileExplosion;
class ATRocketExplosion;
class HERocketExplosion;
class HEShellExplosion;
class ArtyShellExplosion;
class BombExplosion;
class HelicopterExplosionEffects;
class HelicopterExplosionEffects2;
class VehicleExplosionEffects;
class RocketExplosion;
class ExploAmmoExplosion;
class SmallFire;
class SmokeShellWhite;
class cfgFunctions;
class CounterMeasureFlare;
class CounterMeasureChaff;
class ImpactLeavesGreen;
// class RadioProtocol_EP1_EN;
// class RadioProtocol_EP1_TK;
// class RadioProtocol_WMN_EP1_TK;
class IGUIBack;
class CA_Mainback;
class CA_Mainback_2;
class CA_Mainback_3;
class CA_Back;
class CA_Title_Back;
class CA_Back1;
class CA_Back2;
class CA_Back3;
class CA_Black_Back;
class CA_Title;
class CA_IGUI_Title;
class CA_Logo;
class CA_Logo_Small;
class CA_GameSpy_logo;
class ArmA2_HintBackgroundTop;
class ArmA2_HintBackgroundBottom;
class CA_RscButton;
class CA_RscButton_dialog;
class CA_Ok;
class CA_Ok_image;
class CA_Ok_image2;
class CA_Ok_text;
class CA_Table_back;
class CA_UpTitle;
class CA_BoxLeft;
class BB_left;
class BB_right;
class BB_down;
class BB_up;
class BB_Back;
class Back_UserTitle;
class Table_back_black;
class Table_back_white;
class MapArea;
class RespawnMap;
class RespawnTimer;
class NoCrater;
class NoExplosion;
// class RadioProtocol_BAF;
class WFGUIText;
class WFGUILargeText;
class WFGUIButton;
class WFGUIImage;
class WFGUIImageAspectRatio;
class WFGUIListBox;
class WFGUIListNBox;
class WFGUIComboBox;
class WFGUIActiveText;
class WFGUIActiveImage;
class WFGUIActiveImageAspectRatio;
class WFGUIStructuredText;
class WFGUISlider;
class WFGUIShortcutButton;
class WFGUIGearShortcutButton;
class WFBuyMenuBase;
class WFFactoryMenu;
class WFGearMenu;
class WFCityMenu;
class WFTeamMenu;
class WFDiplomacyMenu;
class WFGUIMap;
class WFViewMission;
class WFCommanderViewMission;
class WFFactoryMenuOA;
class WFGearMenuOA;
class WFCityMenuOA;
class WFTeamMenuOA;
class WFDiplomacyMenuOA;
class NoDust;
class ARTY_ShellExplosionSmall;
class ARTY_ShellExplosionMedium;
class ARTY_ShellExplosionLarge;
class ARTY_SmokeExplosionMedium;

#include "\x\cba\addons\main\script_eventhandlers.hpp"

// Rsc
class RscText;
class RscTextSmall;
class RscTitle;
class RscProgress;
class RscProgressNotFreeze;
class RscPicture;
class RscHTML;
class RscButton;
class RscShortcutButton;
class RscButtonSmall;
class RscEdit;
class RscCombo;
class RscListBox;
class RscListNBox;
class RscXListBox;
class RscTree;
class RscSlider;
class RscSliderH;
class RscXSliderH;
class RscActiveText;
class RscStructuredText;
class RscControlsGroup;
class RscBackgroundStripeTop;
class RscBackgroundStripeBottom;
class RscDisplayBackgroundStripes;
class RscCinemaBorder;
class RscToolbox;
class RscXKeyShadow;
class RscXKey;
class RscMapControl;
class RscObject;
class RscStandardDisplay;
class RscLineBreak;
//class RscCompass;
class RscWatch;
class RscMiniMap;
class RscMiniMapSmall;
class RscButtonImages;
class RscObjectives;
class RscMsgBox;
class RscMsgBox3;
class RscMap;
class RscDisplayChannel;
class RscDisplayChat;
class RscDisplayVoiceChat;
class RscDisplayMissionEditor;
class RscDisplayEditObject;
class RscDisplayMissionLoad;
class RscDisplayMissionSave;
class RscDisplayScriptingHelp;
class RscDisplayCapture;
class RscDisplayInterruptEditorPreview;
class RscDisplayInterruptEditor3D;
class RscDisplayAddonActions;
class RscDisplayNewMod;
class RscDisplayInsertMarker;
class RscDisplayDebug;
class RscChatListDefault;
class RscChatListMission;
class RscChatListBriefing;
class RscChatListMap;
class RscTitlesText;
class RscIGText;
class RscIGProgress;
class RscDisplayHintC;
class RscDisplayHintCEx;
class RscInGameUI;
class RscTitles;
class RscDisplayLoading;
class RscDisplayLoadMission;
class RscDisplayNotFreeze;
class RscDisplayNotFreezeBig;
class RscDisplayStart;
class RscDisplayEditDiaryRecord;
class RscDisplayDiary;
class RscDisplayMainMap;
class RscDisplayMain;
class RscDisplaySingleplayer;
class RscDisplaySingleMission;
class RscDisplayCampaignLoad;
class RscDisplayRevert;
class RscDisplaySelectDifficulty;
class RscDisplayDifficultySelect;
class RscDisplayGetReady;
class RscDisplayGear;
class RscDisplayGearWeapon;
class RscDisplayArtillery;
class RscDisplayEmpty;
class RscDisplayMission;
class RscDisplayIntro;
class RscDisplayOutro;
class RscDisplayAward;
class RscDisplayCampaign;
class RscDisplayMissionEnd;
class RscDisplayTeamSwitch;
class RscDisplayInterrupt;
class RscDisplayInterruptRevert;
class RscDisplaySelectSave;
class RscDisplayMPInterrupt;
class RscDisplayDebriefing;
class RscDisplayMissionFail;
class RscDisplayLogin;
class RscDisplayNewUser;
class RscDisplayModLauncher;
class RscDisplayOptions;
class RscDisplayOptionsInGame;
class RscDisplayOptionsVideo;
class RscDisplayOptionsAudio;
class RscDisplayMicSensitivityOptions;
class RscDisplayGameOptions;
class RscDisplayDifficulty;
class RscListBoxKeys;
class RscDisplayConfigure;
class RscDisplayConfigureAction;
class RscDisplayConfigureControllers;
class RscDisplayCustomizeController;
class RscDisplayCredits;
class RscDisplaySelectIsland;
class RscDisplayCustomArcade;
class RscDisplayArcadeMap;
class RscDisplayArcadeUnit;
class RscDisplayArcadeModules;
class RscDisplayArcadeGroup;
class RscDisplayArcadeWaypoint;
class RscDisplayArcadeMarker;
class RscDisplayArcadeSensor;
class RscDisplayArcadeEffects;
class RscDisplayTemplateSave;
class RscDisplayTemplateLoad;
class RscDisplayIntel;
class RscDisplayXWizardTemplate;
class RscDisplayXWizardIntel;
class RscDisplayXWizardIntelName;
class RscDisplayXWizardIntelIsland;
class RscDisplayXWizardIntelWeather;
class RscDisplayXWizardIntelTime;
class RscDisplayXWizardUnit;
class RscDisplayXWizardUnitSelect;
class RscDisplayXWizardUnitSelectCustom;
class RscDisplayXWizardMap;
class RscDisplayXWizardMapInsertUnit;
class RscDisplayXWizardMapInsertWaypoint;
class RscDisplayXWizardParams;
class RscDisplayXWizardParameter;
class RscDisplayESRBOnline;
class RscDisplayMultiplayer;
class RscDisplayHostSettings;
class RscDisplayRemoteMissions;
class RscDisplayRemoteMissionVoted;
class RscDisplayServer;
class RscDisplayClient;
class RscDisplayMultiplayerSetup;
class RscDisplayMultiplayerSetupParams;
class RscDisplayMultiplayerSetupParameter;
class RscDisplayPassword;
class RscDisplayPort;
class RscDisplayIPAddress;
class RscDisplayFilter;
class RscDisplayMPPlayers;
class RscDisplayClientWait;
class RscDisplayServerGetReady;
class RscDisplayClientGetReady;
class RscMPSetupMessage;
class RscDisplayDedicatedServerSettings;
class RscDisplayDedicatedServer;
class RscPendingInvitation;
class RscPendingInvitationInGame;
class RscXTitle;
class RscXBackgroundAll;
class RscXNotepad;
class RscXNotepadSett;
class RscDisplayEditProfile;
class RscDisplayProfileFace;
class RscDisplayProfileVoice;
class RscDisplayProfileController;
class RscDisplayProfileControllerWheel;
class RscDisplayProfileControllerJoystick;
class RscDisplayProfileAudio;
class RscDisplayProfileVideo;
class RscDisplayEditProfileInGame;
class RscDisplayVoiceMask;
class RscXMPNotepad;
class RscDisplayLive;
class RscDisplayMPType;
class RscDisplayOptiMatchFilter;
class RscDisplayQuickMatch;
class RscDisplayPlayers;
class RscDisplayStatistics;
class RscDisplayStatisticsCurrent;
class RscDisplayInteruptReceiving;
class RscDisplayCampaignSelect;
class RscDisplayMovieInterrupt;
class RscGroupRootMenu;
class RscMainMenu;
class RscSubmenu;
class RscMoveHigh;
class RscMoveDir;
class RscReply;
class RscCallSupport;
class RscStatus;
class RscWatchDir;
class RscWatchMoreDir;
class RscMoveDist;
class RscFormations;
class RscCombatMode;
class RscTeam;
class RscSelectTeam;
class RscRadio;
class RscMenuBasicLevel;
class RscSplashText;
class RscLine;
class RscTextMainMenu;
class RscPictureKeepAspect;
class RscGearButtonTest;
class RscIGUIShortcutButton;
class RscGearShortcutButton;
class RscShortcutButtonMainMenu;
class RscShortcutButtonMain;
class RscShortcutButtonDiaryMap;
class RscShortcutButtonWizard;
class RscButton_small;
class RscButtonTextOnly;
class RscProgressBackground;
class RscLoadingText;
class RscIGUIListBox;
class RscIGUIListNBox;
class RscFrame;
class RscBackground;
class RscTextWIP;
class RscIGUIText;
class RscOpticsText;
class RscOpticsValue;
class RscIGUIValue;
class RscDisplayBuyGear;
class RscDisplayBuyUnits;
class RscArmorySelectIsland;
class RscCameraControl;
class RscFunctionsViewer;
class RscConfigEditor_Main;
class RscDisplayWFVoting;
class RscDisplayWFCity;
class RscDisplaySelectProfile;
class RscAnimatedLetters;
class RscHCGroupRootMenu;
class RscHCMainMenu;
class RscHCMoveHigh;
class RscHCWatchDir;
class RscHCCombatMode;
class RscHCSpeedMode;
class RscHCFormations;
class RscHCTeam;
class RscHCSelectTeam;
class RscHCReply;
class RscHCWPRootMenu;
class RscHCWPType;
class RscHCWPCombatMode;
class RscHCWPFormations;
class RscHCWPSpeedMode;
class RscHCWPWait;
class RscDisplayDSinterface;
class RscLibrary_Main;
class RscLibrary_Challenge;
class RscLibrary_Load;



#include "CfgSettings.hpp"
#include "CfgIdentities.hpp"

#ifdef CfgWeapons
	#undef CfgWeapons
#endif

#ifdef CfgVehicles
	#undef CfgVehicles
#endif

#include "ui_compass.hpp"

// No Cross
class CfgWeapons {
	class Default;
	class PistolCore;
	class RifleCore;
	class MGunCore;
	class LauncherCore;
	class GrenadeCore;

	#ifdef ACE_NOCROSS
		#include "no_crosshair.hpp"
	#endif
	#ifdef ACE_MINCROSS
		#include "minimal_crosshair.hpp"
	#endif
	#ifndef ACE_NOCROSS
		class Rifle;
	#endif
	#ifdef ACE_RETICLES
		#include "cfgWeapons_reticles.hpp"
	#endif
};

#ifdef ACE_NOCROSS
	#include "no_crosshair_texture.hpp"
#endif
#ifdef ACE_MINCROSS
	#include "minimal_crosshair_texture.hpp"
#endif
// class CfgWeaponCursors;

#ifdef ACE_MINIMALHUD
	#include "minimalhud.hpp"
#endif

#ifndef ACE_MINIMALHUD
	class CfgInGameUI;
#endif

// Ruckless
#ifndef ACE_DISABLE_RUCKLESS
	#include "CfgVehicles.hpp"
#endif

#ifdef ACE_DISABLE_RUCKLESS
	class CfgVehicles;
#endif

// No radio
#ifdef ACE_NOVOICE
	#include "CfgVoice.hpp"
#endif

// Alternative tracers
class cfgAmmo {
	#ifdef ACE_BALLTRACERS
		#include "CfgAmmo.hpp"
	#endif
};
// Scripted grenade throwing
class cfgMagazines {
	#ifdef ACE_GRENADETHROW
		#include "CfgMagazines.hpp"
	#endif
};

// Disable statistics during mission (OFP alike)
class CfgDiary {
	#ifdef ACE_NODIARYSTATISTICS
		#include "CfgDiary.hpp"
	#endif
};
