/*
    Author: Aaron Clark - EpochMod.com
    Contributors: Andrew Gregory

    Description:
    Main Client side configs for the Epoch gamemode

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_config/Configs/CfgEpochClient.hpp
*/
/*[[[cog from arma_config_tools import *; json_to_arma()]]]*/
class CfgEpochClient
{
    epochVersion = "1.3.2";
    ArmAVersion = 176;
	debug = "true";  // true = enable extra rpt debug lines, false to disable
	ForceGender = "";	// Force Players to spawn as "Male" or "Female"
	RemoveLaserfromUAV = "true";	// remove LaserDesignator from assembled UAV's

	UseOldRevive = "false";		// Revive / Heal Player has been changed to use "HandleDamage" Eventhandler. If scripts are breaking it for you, set it to true (not recommended!)
	UnconsciousChance = 30;			// Change in percent to get unconscious by a hit with an Axe / Sledge / Sword
	UnconsciousTime[] = {60,180};	// Min / Max time for unconscious after you got a hit from a non lethal weapon / Axe / Sledge / Sword

	antagonistRngChance = 100; // increase number to reduce chances and reduce to increase. Default 100
	NuisanceMulti = 0.5;		// Multi for Nuisance increase on shooting - higher Nuisance effect at least antagonist spawn change. (0-1, default 0.5)

	outOfBoundsRadiation = 10; // how much rads per tick (10sec), when outside play area.
	radioactiveLocations[] = {"NameCityCapital", "NameCity", "Airport"}; // used for random radioactive locations and to suppress animal spawns within cities.
	radiatedObjMaxFalloutDist = 125; // max distance radiated object can affect player (number in meters)
	geigerCounterEnergyUsage = 10; // default loss of 10 energy every 10sec of use
	radiationEffectsThreshold = 10; // default level for screen effects to indicate a player's rad dosage (0-100)
	
	baseRadiationLoss = -1; //default radiation loss every 1 minute, calculated from total immunity. No immunity no reduction.
	baseRadiationLossImmunityPenalty = -1; //immunity is reduced as a penalty for radiation loss effect
	
    baseHungerLoss = 2; // increase number to speed up rate of Hunger loss
    baseThirstLoss = 2; // increase number to speed up rate of Thirst loss
	accelerateHTALoss = "false"; // use server's time acceleration to increase the rate of Hunger, Thirst and Alcohol loss

    buildingNearbyMilitary = 0; //1 to allow building nearby
    buildingNearbyMilitaryRange = 300; //Define radius of blocked area
    buildingNearbyMilitaryClasses[] = {"Cargo_Tower_base_F","Cargo_HQ_base_F","Cargo_Patrol_base_F","Cargo_House_base_F"};
    restrictedLocations[] = {"NameCityCapital"};
    restrictedLocationsRange = 300;
    buildingRequireJammer = 1;		//1 = require jammer to build
	buildingJammerRange = 125; 		// Unused by Epoch, but leave it to prevent issues with custom scripts (should be set to the max possible JammerRange from cfgJammers)
    jammerPerGroup = 1;				// allowed number of jammers per group.
    jammerGLOnly = 1;               // allow only group leader to place Jammer
    minJammerDistance = 650;		// min distance to next Jammer
    maxBuildingHeight = 100;		// Max Height, building is allowed.
    splitCountLimits = 0;			//1 = distinguish buildingCountLimit from storageCountLimit (ex.: buildingCountLimit=100, storageCountLimit=100 >> you can build 100 baseparts AND additional 100 storage objects like safes, lockboxes...)
	MaxBuildingTilt = 180;			// Max degrees players can tilt building elements
	EnablePhysicsOnBuild = "true";	// Building parts need Snap (hold) points to not fall on the ground while building
	
	class CfgJammers {
		class PlotPole_EPOCH 					// Jammer Classname
		{
			buildingJammerRange = 		75;		// jammer range in meters
			buildingCountLimit = 		200;	// Max Building Elements per Base
			storageCountLimit = 		100;	// Max Storage Elements per Base
			buildingCountPerMember = 	5;		// Additional Building elements per Member
			storageCountPerMember = 	5;		// Additional Storage elements per Member
			maxdoors = 					10;		// Max Doors per Base
			maxgates = 					5;		// Max Gates per Base
			maxCams = 					2;		// Max Cams per Base
		};
		class PlotPole_M_EPOCH : PlotPole_EPOCH	// inherits from "PlotPole_EPOCH" (not defined values will be taken from PlotPole_EPOCH)
		{
			buildingJammerRange = 		100;	// jammer range in meters
			buildingCountLimit = 		215;	// Max Building Elements per Base
			storageCountLimit = 		115;	// Max Storage Elements per Base
		};
		class PlotPole_L_EPOCH : PlotPole_M_EPOCH
		{
			buildingJammerRange = 		125;	// jammer range in meters
			buildingCountLimit = 		230;	// Max Building Elements per Base
			storageCountLimit = 		130;	// Max Storage Elements per Base
		};
		class PlotPole_XL_EPOCH : PlotPole_L_EPOCH
		{
			buildingJammerRange = 		150;	// jammer range in meters
			buildingCountLimit = 		245;	// Max Building Elements per Base
			storageCountLimit = 		145;	// Max Storage Elements per Base
		};
		class PlotPole_XXL_EPOCH : PlotPole_XL_EPOCH
		{
			buildingJammerRange = 		175;	// jammer range in meters
			buildingCountLimit = 		260;	// Max Building Elements per Base
			storageCountLimit = 		160;	// Max Storage Elements per Base
		};
	};
	StorageClasses[] = {"Buildable_Storage","Buildable_Storage_SIM","Buildable_Storage_Ghost","Constructions_lockedstatic_F","Secure_Storage_Temp"};
	BuildingClasses[] = {"Constructions_static_F","Constructions_foundation_F","Const_Ghost_EPOCH"};
	DoorClasses[] = {"WoodLargeWallDoorL_EPOCH","WoodWall4_EPOCH","CinderWallDoorwHatch_EPOCH","WoodStairs3_EPOCH","JailWallDoor_EPOCH"};
	GateClasses[] = {"CinderWallGarage_EPOCH","WoodWallGarage_EPOCH","MetalWallGarage_EPOCH"};

	AtmBlockedAtPlot = "true";		// Block ATM's in Plotpole-Range
    disableRemoteSensors = "true";  // disableRemoteSensors true/false
	
	ActionFireOnLighter = "true";				// Lighter is needed to inflame fires
	ActionBurnBarrelOffExtinguisher = "true";	// FireExtinguisher is needed to put off Burn Barrels
	ActionHookRope = "true";					// Rope is needed to hook vehicles (get back on release)
	
	DefuseBombChance = 0.6;						// Chance for successfully defuse a bomb -> If fail, the bomb will explode
	DisableDoorInteractForACE = "true";			// If true, Door-Interactions from ACE-Mod will be blocked (no effect, if ACE is not running)

    epochMessageBackgroundCol[] = {0,0,0,0.2};  //Epoch_message background color (format: {R,G,B,A})
    epochMessageTextCol[] = {1,1,1,0.95};       //Epoch_message text color (format: {R,G,B,A})
                                                //to use different colored messages in scripts, just call it this way: ["the message", 6, [[0,0,0,0.2],[1,1,1,0.95]]] call Epoch_message;

    EPOCH_news[] = {"Word is that Sappers have a new boss.","Dogs will often lure them monsters away.","My dog was blown up. I miss him.."};
    deathMorphClass[] = {"Epoch_Sapper_F","Epoch_SapperG_F","Epoch_SapperB_F","I_UAV_01_F","Epoch_Cloak_F"}; //Random selection of these classes when player morphs after death. Currently available: Epoch_Cloak_F, Epoch_SapperB_F, Epoch_Sapper_F, I_UAV_01_F
    niteLight[] = {1,1.88,22}; // 0 = disabled or 1 = enabled, Set ambient lighting at night: {Brightness of light,Height of light}. Default (Low Ambient): {1.88,22} | Twilight: {7.2,88} | Distant: {12.8,142}
    ryanZombiesEnabled = "true";

	antagonistChances[] = {
		// {"type", chance}
		"Epoch_Cloak_F",0.06,
		"GreatWhite_F",0,
		"Epoch_Sapper_F",0.12,
		"Epoch_SapperG_F",0.06,
		"Epoch_SapperB_F",0.03,
		"I_UAV_01_F",0.12,
		"PHANTOM",0.03,
		"B_Heli_Transport_01_F",0,
		"EPOCH_RyanZombie_1",0.12,
		"I_Soldier_EPOCH",0
	};

	antagonistSpawnIndex[] = {
		// {"type", limit}
		{"Epoch_Cloak_F",1},
		{"GreatWhite_F",2},
		{"Epoch_Sapper_F",2},
		{"Epoch_SapperG_F",1},
		{"Epoch_SapperB_F",1},
		{"I_UAV_01_F",2},
		{"PHANTOM",1},
		{"B_Heli_Transport_01_F",1},
		{"EPOCH_RyanZombie_1",12},
		{"I_Soldier_EPOCH",1}
	};
	customVarsDefaults[] = {
		// EPOCH_player + varName, default value, {max,min,high-warn,high-critical,low-warn,low-critical}
		{"Temp",98.6,{106.7,95,102,105,96,95}},
		{"Hunger",1500,{5000,0,5001,5001,1250,0}},
		{"Thirst",750,{2500,0,2501,2501,625,0}},
		{"AliveTime",0,{-2,0}}, // local
		{"Energy",0,{2500,0}},
		{"Wet",0,{100,0,35,55,-1,-1}},
		{"Soiled",0,{100,0,35,55,-1,-1}},
		{"Immunity",0,{100,0}},
		{"Toxicity",0,{100,0,35,55,-1,-1}},
		{"Stamina",100,{"EPOCH_playerStaminaMax",0}},
		{"Crypto",0,{250000,0}},
		{"HitPoints",{0,0,0,0},{1,0,0.5,1,-1,-1}}, // limits here only used for HUD.
		{"BloodP",100,{190,0,120,140,70,50}},
		{"SpawnArray",{},{}},
		{"NotUsed",0,{50000,-50000}}, // TODO remove or replace
		{"Alcohol",0,{100,0,35,55,-1,-1}},
		{"Radiation",0,{100,0,35,55,-1,-1}},  // local
		{"Nuisance",0,{100,0}},
		{"MissionArray",{},{}}
	};
	// Vars and the value that gets set if godmode is enabled
	gmVars[] = {
		{"Temp",98.6},
		{"Hunger",2500},
		{"Thirst",1500},
		{"Energy",2500},
		{"Toxicity",0},
		{"Stamina",100},
		{"BloodP",100},
		{"Alcohol",0},
		{"Radiation",0}
	};
    hudConfigs[] = {
		{{"BloodP","","",{"getPlayerDamage",">=",0.7}},"topRight","x\addons\a3_epoch_code\Data\UI\bleeding_ca.paa",{"forceUpdate"}},
		{{"Oxygen","getPlayerOxygenRemaining","",{},{1,0,2,2,1,0.55}},"topRight","x\addons\a3_epoch_code\Data\UI\oxygen_ca.paa"},
		{"Hunger","topRight","x\addons\a3_epoch_code\Data\UI\hunger_ca.paa",{"forceBloodRise"}},
		{"Thirst","topRight","x\addons\a3_epoch_code\Data\UI\thirst_ca.paa",{"forceBloodRise"}},
		{"Temp","topRight",{"x\addons\a3_epoch_code\Data\UI\hot_ca.paa","x\addons\a3_epoch_code\Data\UI\cold_ca.paa"},{{"forceFatigue","forceBloodRise"},{"forceFatigue","forceBloodDrop"}}},
		{"Toxicity","topRight","x\addons\a3_epoch_code\Data\UI\hazzard_ca.paa",{"forceBloodRise"}},
		{"Alcohol","topRight","x\addons\a3_epoch_code\Data\UI\drunk_ca.paa"},
		{"Soiled","topRight","x\addons\a3_epoch_code\Data\UI\soiled_ca.paa"},
		{"Radiation","topRight","x\addons\a3_epoch_code\Data\UI\rads_ca.paa",{"forceBloodRise"}},
		{{"HitPoints","getPlayerHitPointDamage","HitLegs"},"topRight","x\addons\a3_epoch_code\Data\UI\broken_ca.paa"}
	};
	defineCommunityStats[]  = {
		// EPOCH_total + varName, starting value, {min,max or custom values}
		{"Karma",1500,{-50000,50000,{-5000,-15000,-30000},{5000,15000,30000}}}, // min, max, {Work In Progress levels}
		{"Murders",0,{}},
		{"Deaths",0,{}},
		{"Suicides",0,{0,99999,500}}, // min, max, "Suicide King" status
		{"Revives",0,{0,99999,500}}, // min, max, "Medic" status
		{"TraderMissions",0,{}},
		{"AIKills",0,{}},
		{"AntagonistKills",0,{}},
		{"ZombieKills",0,{}},
		{"WalkDist",0,{}},
		{"MaxAliveTime",0,{}},
		{"NPCTrades",0,{}},
		{"PlayTime",0,{}},
		{"LootedObjs",0,{}},
		{"CraftedItems",0,{}},
		{"ConnectCount",0,{}},
		{"BuildingsSet",0,{}},
		{"AIDeaths",0,{}},
		{"PublicStats",1,{}}	// DO not change this! Players can disable it within the E-Pad by themself!
	};
	PlayerStatsDialogEntries[] = {
/*
		{
			{"CommunityVariable","DisplayName","ExtraCalculation"}
		},
*/
		{
			{"ConnectCount","Times connected"},
			{"PlayTime","Playtime (hours)","%1/3600 toFixed 2"},
			{"MaxAliveTime","Max Alivetime (hours)","%1/3600 toFixed 2"},
			{"WalkDist","Distance Walked (Km)","%1/1000 toFixed 2"}
		},
		{
			{"LootedObjs","Objects Looted"},
			{"NPCTrades","Trades at Trader"},
			{"BuildingsSet","Placed Buildings"},
			{"CraftedItems","Crafted Items"}
		},
		{
			{"Karma","Karma","round %1"},
			{"Revives","Player Revived"},
			{"TraderMissions","Tradermissions"}
		},
		{
			{"Murders","Player Kills"},
			{"AIKills","AI Kills"},
			{"AntagonistKills","Antagonist Kills"},
			{"ZombieKills","Zombie Kills"}
		},
		{
			{"Deaths","Deaths by Player"},
			{"AIDeaths","Deaths by AI"},
			{"Suicides","Suicides"}
		},
		{
			{"","K/D PvP","(Epoch_totalMurders/(Epoch_totalDeaths max 1)) toFixed 1"},
			{"","K/D PvE","(Epoch_totalAIKills/(Epoch_totalAIDeaths max 1)) toFixed 1"}
		}
	};
	TopStatsDialogEntries[] = {
/*
		{"CommunityVariable","DisplayName","ExtraCalculation"},
*/
		{"PlayTime","Playtime (hours)","%1/3600 toFixed 2"},
		{"MaxAliveTime","Max Alivetime (hours)","%1/3600 toFixed 2"},
		{"WalkDist","Distance Walked (Km)","%1/1000 toFixed 2"},
		{"LootedObjs","Objects Looted"},
		{"NPCTrades","Trades at Trader"},
		{"BuildingsSet","Placed Buildings"},
		{"CraftedItems","Crafted Items"},
		{"Karma","Karma","round %1"},
		{"Murders","Player Kills"},
		{"AIKills","AI Kills"},
		{"Deaths","Deaths by Player"},
		{"AIDeaths","Deaths by AI"}
	};	
    group_upgrade_lvl[] = {4,"1000",6,"1500",8,"2000",10,"2500",12,"3000",14,"3500",16,"4000",32,"8000",64,"16000"}; // controls max group limit and cost
    // Event handler code
    displayAddEventHandler[] = {"keyDown","keyUp"};
    keyDown = "(_this call EPOCH_KeyDown)";
    keyUp = "(_this call EPOCH_KeyUp)";
    addEventHandler[] = {"Respawn","Put","Take","InventoryClosed","InventoryOpened","FiredMan","Killed","HandleRating","HandleScore","HandleDamage","GetInMan","GetOutMan","Hit","SeatSwitchedMan","FiredNear","WeaponAssembled"};
    Respawn = "(_this select 0) call EPOCH_clientRespawn";
    Put = "(_this select 1) call EPOCH_interact;_this call EPOCH_PutHandler;_this call Epoch_custom_EH_Put";
    Take = "(_this select 1) call EPOCH_interact;_this call EPOCH_UnisexCheck;_this call Epoch_custom_EH_Take";
    FiredMan = "_this call EPOCH_fnc_playerFired;_this call Epoch_custom_EH_FiredMan";
    InventoryClosed = "_this call EPOCH_InventoryClosed;_this call EPOCH_custom_EH_InventoryClosed";
    InventoryOpened = "_this call EPOCH_InventoryOpened||_this call EPOCH_custom_EH_InventoryOpened"; // the || here allows either function to block opening of inventory by returning true.
    Killed = "_this call EPOCH_fnc_playerDeath;_this call Epoch_custom_EH_Killed";
    HandleRating = "0";
	HandleScore = "";
    HandleDamage = "_this call EPOCH_HandleDamage;_this call EPOCH_custom_EH_HandleDamage";
    HandleHeal = "";
    Dammaged = "";
    Hit = "_this call EPOCH_custom_EH_Hit";
    HitPart = "";
    GetInMan = "_this call EPOCH_getInMan;_this call Epoch_custom_EH_GetInMan";
    GetOutMan = "_this call EPOCH_getOutMan;_this call Epoch_custom_EH_GetOutMan";
	SeatSwitchedMan = "_this call EPOCH_custom_EH_SeatSwitchedMan";
	FiredNear = "_this call EPOCH_custom_EH_FiredNear";
	WeaponAssembled = "clearItemCargoGlobal (_this select 1);if (['CfgEpochClient','RemoveLaserfromUAV',true] call EPOCH_fnc_returnConfigEntryV2) then {(_this select 1) removeWeaponTurret ['Laserdesignator_mounted',[0]]}; if ((_this select 1) isKindOf 'UAV_01_base_F' || (_this select 1) isKindOf 'UAV_06_base_F') then {['UAV assembled - Connect it with DynaMenu (Space)',5] call Epoch_Message}";
    // suppress these units from spawning near Jammer or Traders
    nonJammerAI[] = {"B_Heli_Transport_01_F","PHANTOM","EPOCH_Sapper_F","Epoch_SapperG_F","Epoch_SapperB_F","I_UAV_01_F","EPOCH_RyanZombie_1"};
    nonTraderAI[] = {"B_Heli_Transport_01_F","PHANTOM","EPOCH_Sapper_F","Epoch_SapperG_F","Epoch_SapperB_F","I_UAV_01_F","Epoch_Cloak_F","GreatWhite_F","EPOCH_RyanZombie_1"};
    nonTraderAIRange = 50;
    fishLoots[] = {"ItemTuna","ItemSeaBass","ItemSeaBass","ItemSeaBass","ItemTrout","ItemTrout","ItemTrout","ItemTrout","ItemTrout","ItemTrout"}; // Fishing loots
    animalAiTables[] = {"Sheep_random_EPOCH","Sheep_random_EPOCH","Goat_random_EPOCH","Goat_random_EPOCH","Goat_random_EPOCH",{"Cock_random_EPOCH","Hen_random_EPOCH"},{"Cock_random_EPOCH","Hen_random_EPOCH"},"Rabbit_EPOCH","Rabbit_EPOCH","Rabbit_EPOCH","Snake_random_EPOCH","Snake2_random_EPOCH",{"Fin_random_EPOCH","Alsatian_Random_EPOCH"}}; // Animal spawn table
    playerDeathScreen = "TapOut";
    playerKilledScreen = "TapOut2";
    playerDisableRevenge = 0;
    playerRevengeMinAliveTime = 900;
    playerLocationMarkerGPSOnly = 1; // Map marker toggle in map dyna menu with assigned GPS only
    playerDeathMarkerGPSOnly = 1; // Map marker toggle in map dyna menu on death with assigned GPS only
    mapOnZoomSetMarkerSize = 1; // When in map markers will change to larger size as player zooms in
    bankTransferTime[] = {0.0006,1.2,0.06};
	
	// Player (Building) Energy
	energyPowerSources[]	= {				// Add PowerCapacity and PowerType in CfgBaseBuilding, if you add something here!
		"Land_spp_Tower_F",
		"Land_wpp_Turbine_V2_F",
		"Land_wpp_Turbine_V1_F",
		"SolarGen_EPOCH",
		"Land_Wreck_Satellite_EPOCH"
	};
	energyRange				= 75;			// Range to check for energy sources
	energyRegenMax			= 5;			// Max energy increase value (every 10 seconds) 
	energyCostNV			= 3;			// Energy loss value by using nightvision (every 10 seconds)
	energyRegenInVeh 		= 5;			// Energy increase value in Vehicles with Engine On (every 10 seconds)

	// Favorite Bar
	Fav_enableFavoriteBar = "true";			// If disabled, players will not be able to use favorite bar
	Fav_DropIfOverflow = "false";			// If enabled and inventory full, equipped weapon will be dropped on ground in favor for the new selected weapon, otherwise action will fail with message and weapon will not be equipped
	Fav_FastWeaponSwitching = "false";		// If enabled, same slot weapons from favorites bar are equipped instantly, otherwise reload action is played (recommended for immersion)
	Fav_BannedItems[] = {"FAK"};				// Items that users are not allowed to pin

	EnableTempVehTrade = "false";			// Enable selling of temp Vehicles (not handled by Epoch). Temp Vehicles will not be stored in Traders, but can be sold
	BulletCalculateOnCraft = "true";		// Enable Bullet Calculation on Crafting - Example: If you craft a large EnergyPack with 3 half full EnergyPacks, you will only get a half filled large EnergyPack back

	// Vehicle Settings
	DisallowSellOnDamage = "false";										// Prevent from selling Vehicles with one or more fully damaged wheel or engine
	MaxVehTradeDist = 30;												// Max distance where Players can sell Vehicles to Traders
	UseAdvancedVehicleRepair = "true";									// Switch On / Off Advanced Vehicle Repair (Does not effect SuppressedCraftingItems !)
	EnableRemoveParts = "true";											// Enable removing Tires / Engines from Vehicles
	SuppressedCraftingItems[] = {										// These Items can not be crafted (but can be used in recipe)
			"VehicleRepairLg",			// Supressed for Advanced Vehicle Repair (no longer needed)
			"KitMetalQuarterFloor",		// Item is Upgradeable, but you can remove it here to make it also Craftable
			"KitMetalHalfFloor",		// Item is Upgradeable, but you can remove it here to make it also Craftable
			"KitMetalFloor",			// Item is Upgradeable, but you can remove it here to make it also Craftable
			"KitMetalTower",			// Item is Upgradeable, but you can remove it here to make it also Craftable
			"KitCinderQuarterFloor",	// Item is Upgradeable, but you can remove it here to make it also Craftable
			"KitCinderHalfFloor",		// Item is Upgradeable, but you can remove it here to make it also Craftable
			"KitCinderFloor",			// Item is Upgradeable, but you can remove it here to make it also Craftable
			"KitCinderTower"			// Item is Upgradeable, but you can remove it here to make it also Craftable
	};
	VehicleRepairs[] = {												// {Hitpoint, dmg to repair, dmg to replace, mat to repair, mat to replace}
		{"HitHull",0.33,0.66,"ItemScraps","ItemCorrugated"},
		{"HitBody",0.33,1,"ItemScraps","ItemCorrugated"},
		{"HitEngine",0.33,0.91,"EngineParts","EngineBlock"},
		{"glass",0.33,1,"ItemGlass","ItemGlass"},
		{"HitFuel",0.1,0.66,"ItemDuctTape","FuelTank"},
		{"HitHRotor",0.33,1,"ItemCorrugated","ItemRotor"},
		{"HitVRotor",0.33,1,"ItemCorrugated","ItemRotor"},
		{"HitWinch",0.33,0.91,"ItemCables","ItemCables"},
		{"HitAvionics",0.33,0.91,"CircuitParts","CircuitParts"},
		// Wheels - Do not change the order (front to back wheels) here!
		{"HitLFWheel",0.33,1,"VehicleRepair","SpareTire"},
		{"HitRFWheel",0.33,1,"VehicleRepair","SpareTire"},
		{"HitLF2Wheel",0.33,1,"VehicleRepair","SpareTire"},
		{"HitRF2Wheel",0.33,1,"VehicleRepair","SpareTire"},
		{"HitLMWheel",0.33,1,"VehicleRepair","SpareTire"},
		{"HitRMWheel",0.33,1,"VehicleRepair","SpareTire"},
		{"HitLBWheel",0.33,1,"VehicleRepair","SpareTire"},
		{"HitRBWheel",0.33,1,"VehicleRepair","SpareTire"},
		// Mountainbike wheels
		{"HitFWheel",0.33,0.91,"",""},
		{"HitBWheel",0.33,0.91,"",""}
	};

/*	// Lower difficult VehicleRepairs example	
	VehicleRepairs[] = {												// {Hitpoint, dmg to repair, dmg to replace, mat to repair, mat to replace}
		{"HitHull",0.33,0.66,"ItemScraps","ItemCorrugated"},
		{"HitBody",0.33,1,"ItemScraps","ItemCorrugated"},
		{"HitEngine",0.33,0.91,"VehicleRepair","VehicleRepair"},
		{"glass",0.33,1,"ItemGlass","ItemGlass"},
		{"HitFuel",0.1,0.66,"ItemDuctTape","ItemDuctTape"},
		{"HitHRotor",0.33,1,"ItemCorrugated","ItemCorrugated"},
		{"HitVRotor",0.33,1,"ItemCorrugated","ItemCorrugated"},
		{"HitWinch",0.33,0.91,"ItemCables","ItemCables"},
		{"HitAvionics",0.33,0.91,"CircuitParts","CircuitParts"},
		// Wheels - Do not change the order (front to back wheels) here!
		{"HitLFWheel",0.33,1,"VehicleRepair","VehicleRepair"},
		{"HitRFWheel",0.33,1,"VehicleRepair","VehicleRepair"},
		{"HitLF2Wheel",0.33,1,"VehicleRepair","VehicleRepair"},
		{"HitRF2Wheel",0.33,1,"VehicleRepair","VehicleRepair"},
		{"HitLMWheel",0.33,1,"VehicleRepair","VehicleRepair"},
		{"HitRMWheel",0.33,1,"VehicleRepair","VehicleRepair"},
		{"HitLBWheel",0.33,1,"VehicleRepair","VehicleRepair"},
		{"HitRBWheel",0.33,1,"VehicleRepair","VehicleRepair"},
		// Mountainbike wheels
		{"HitFWheel",0.33,0.91,"",""},
		{"HitBWheel",0.33,0.91,"",""}
	};
*/

    // include configs
    #include "CfgEpochClient\Altis.hpp"
    #include "CfgEpochClient\australia.hpp"
    #include "CfgEpochClient\Bornholm.hpp"
    #include "CfgEpochClient\Chernarus_Summer.hpp"
    #include "CfgEpochClient\Chernarus.hpp"
	#include "CfgEpochClient\ChernarusRedux.hpp"
    #include "CfgEpochClient\Enoch.hpp"
    #include "CfgEpochClient\Esseker.hpp"
    #include "CfgEpochClient\ProvingGrounds_PMC.hpp"
    #include "CfgEpochClient\Sara_dbe1.hpp"
    #include "CfgEpochClient\Sara.hpp"
    #include "CfgEpochClient\SaraLite.hpp"
    #include "CfgEpochClient\Stratis.hpp"
    #include "CfgEpochClient\takistan.hpp"
    #include "CfgEpochClient\utes.hpp"
    #include "CfgEpochClient\vr.hpp"
    #include "CfgEpochClient\Zargabad.hpp"
    #include "CfgEpochClient\Tanoa.hpp"
    #include "CfgEpochClient\Malden.hpp"
    #include "CfgEpochClient\WorldInteractions.hpp"
};
class CfgEpochSoldier
{
    unitTypes[] = {"I_Soldier_EPOCH", "I_Soldier2_EPOCH", "I_Soldier3_EPOCH"};//Selects from randomly
    minAISkill = 0.2; //Minumum AI Skill. Skills are chosen randomly between this minimum overall AI skill value and the following max AI skill values, for each of the next skills:
    maxAimingAccuracy = 0.7;
    maxAimingShake = 0.9;
    maxAimingSpeed = 0.6;
    maxEndurance = 0.4;
    maxSpotDistance = 0.4;
    maxSpotTime = 0.3;
    maxCourage = 0.3;
    maxReloadSpeed = 0.5;
    maxCommanding = 0.4;
    maxGeneral = 0.4;
	minspawndist = 120;
	maxspawndist = 200;
};
class CfgEpochSapper
{
    detonateDistMax = 8; //Random distance between 3m and this number at which sapper detonates. Min value = 4
    groanTrig = 16; //Percentage chance of a groan. Min value = 4
    sRange = 300; //Distance from target over which sapper will dispose. Range within which sapper code will be aware of targets. Distance up to which sapper will attempt to find a spot to hide in. Min Value = 150.
    smellDist = 24; //Distance up to which sapper can smell. Used to decide if sapper can see target when deciding to charge and influences target selection. Is influenced by wind direction. Min Value = 8.
    reflexSpeed = 0.25; //Sapper brain will pause for this time when checking for new stimulus during each thought process. Lower number equals a more reactive sapper. (Guide Min 0.25 - Max 2.5).
    nestChance = 2; //Every time a sapper spawns apply this percentage chance that sapper will create a nest.
    hideLevel = 72; //(Emotion) Sapper fear increases by several factors, higher number of armed player(s) in area / being shot at. Set fear level (out of 100) at which he will go into a 'hide / evade mode'.. temporarily.
    chargeLevel = 52; //(Emotion) Sapper anger increases by smelling / sensing players, being shot at / hit, too many players on his turf. Set level (Out of 100) at which he is triggered to charge on the current target.
};
class CfgEpochUAV
{
    UAVMinDist = 48; //Minimum distance to choose next position when roaming. Min Value = 8.
    UAVMaxDist = 180; //Maximum distance to choose next position when roaming. Min Value = 42 / Max Value = 400.
    UAVHeight = 100; //Set height when roaming, slight randomness is applied to this value. UAV will choose own height when locked onto target. Min Value = 42 / Max Value = 280. UAV can still spot targets from height !
};
class CfgEpochUAVSupport
{
	unitTypes[] = {"I_Soldier_EPOCH"}; //Selects from randomly (e.g. {"I_Soldier_EPOCH","Epoch_Sapper_F","Epoch_SapperB_F","Epoch_SapperG_F"};)
	minUnitNum = 2; //Maximum number of units spawned when UAV spots target.
	maxUnitNum = 4; //Maximum number of units spawned when UAV spots target.
};
class CfgEpochCloak
{
    cRange = 300; //Distance, from target, at which Cloak will dispose. Cloak is also aware of players within this range. (Min: 60 / Max: 600)
    cAggression = 75; //Percentage chance of attack, currently a psychological attack (Cultist spooky voice). (Min: 1 / Max: 100)
    attackFrequency = 120; //One attack only per this period. (Min: 120)
    attackDistance = 38; // Distance, from target, up to which Cloak will attack. Lower for less vocals. (Min: 16)
    targetChangeFrequency = 42; //Cloak will only attempt to change target once per this period. Make Higher to stick to first target player. (Min: 42)
    teleportChance = 66; //Chance for cloak to teleport. (Min: 1)
    hoverFrequency = 1280; //Cloak has new hover attack. When player is above cloak, and at a distance, cloak will float to player and teleport attack. Only perform one of these moves per this period. (Min: 240)
};
class CfgEpochRyanZombie
{
    zeds[] = {"EPOCH_RyanZombie_1","EPOCH_RyanZombie_2","EPOCH_RyanZombie_3","EPOCH_RyanZombie_4","EPOCH_RyanZombie_5"};
    attackDist = 1.6; //Attack Distance.
    range = 45; //Range at which to dispose old zombies and spawn new ones within.
    disposeRange = 800; // distance before zombie is disposed
    smell[] = {38,0.42}; //Distance in metres up to which the zombie can smell a target. | Skill (0 - 1). 0 - Disable
    sight[] = {28,0.72}; //Zombie sight distance | Skill (0 - 1).
    hearing[] = {108,0.68}; //Zombie hearing distance / Skill. Max FiredNear EH Limit ?
    memory[] = {480,0.8}; //Memory time. / Weighting. WIP - Not Used
    reflexSpeed = 0.25; //Zombie brain will pause for this time when checking for new stimulus during each thought process. Lower number equals a more reactive zombie. (Guide Min 0.25 - Max 2.5).
    moans[] = {"ryanzombiesmoan1","ryanzombiesmoan2","ryanzombiesmoan3","ryanzombiesmoan4"};
    screams[] = {"ryanzombiesscream1","ryanzombiesscream2","ryanzombiesscream3","ryanzombiesscream4","ryanzombiesscream5","ryanzombiesscream6","ryanzombiesscream7","ryanzombiesscream8","ryanzombiesscream9"};
};
/*[[[end]]]*/
