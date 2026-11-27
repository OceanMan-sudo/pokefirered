@ TEMPORARY test tool. Remove before version 1 (see TODO.md).
@ Open it in the field by holding B and pressing SELECT.

EventScript_DebugMenu::
	lockall
EventScript_DebugMain::
	closemessage
	dynmultichoice 0, 0, FALSE, 7, 0, DYN_MULTICHOICE_CB_NONE, DebugMenu_Text_Warp, DebugMenu_Text_Pokemon, DebugMenu_Text_Items, DebugMenu_Text_Progress, DebugMenu_Text_Heal, DebugMenu_Text_Exit
	goto_if_eq VAR_RESULT, 0, EventScript_DebugWarp
	goto_if_eq VAR_RESULT, 1, EventScript_DebugMon
	goto_if_eq VAR_RESULT, 2, EventScript_DebugItems
	goto_if_eq VAR_RESULT, 3, EventScript_DebugProgress
	goto_if_eq VAR_RESULT, 4, EventScript_DebugHeal
	goto EventScript_DebugExit

EventScript_DebugExit::
	closemessage
	releaseall
	end

EventScript_DebugHeal::
	special HealPlayerParty
	playfanfare MUS_HEAL
	waitfanfare
	msgbox DebugMenu_Text_Healed
	goto EventScript_DebugMain

EventScript_DebugWarp::
	checkflag FLAG_SYS_SAFARI_MODE
	goto_if TRUE, EventScript_DebugNoWarpSafari
	getpartysize
	goto_if_eq VAR_RESULT, 0, EventScript_DebugNoWarpParty
EventScript_DebugWarpKind::
	closemessage
	dynmultichoice 0, 0, FALSE, 7, 0, DYN_MULTICHOICE_CB_NONE, DebugMenu_Text_Towns, DebugMenu_Text_Gyms, DebugMenu_Text_TestSpots, DebugMenu_Text_Back
	goto_if_eq VAR_RESULT, 0, EventScript_DebugWarpTowns
	goto_if_eq VAR_RESULT, 1, EventScript_DebugWarpGyms
	goto_if_eq VAR_RESULT, 2, EventScript_DebugWarpSpots
	goto EventScript_DebugMain

EventScript_DebugWarpTowns::
	dynmultichoice 0, 0, FALSE, 7, 0, DYN_MULTICHOICE_CB_NONE, DebugMenu_Text_PalletTown, DebugMenu_Text_ViridianCity, DebugMenu_Text_PewterCity, DebugMenu_Text_CeruleanCity, DebugMenu_Text_VermilionCity, DebugMenu_Text_LavenderTown, DebugMenu_Text_CeladonCity, DebugMenu_Text_FuchsiaCity, DebugMenu_Text_SaffronCity, DebugMenu_Text_CinnabarIsland, DebugMenu_Text_IndigoPlateau, DebugMenu_Text_OneIsland, DebugMenu_Text_Back
	goto_if_eq VAR_RESULT, 0, EventScript_DebugWarpTowns0
	goto_if_eq VAR_RESULT, 1, EventScript_DebugWarpTowns1
	goto_if_eq VAR_RESULT, 2, EventScript_DebugWarpTowns2
	goto_if_eq VAR_RESULT, 3, EventScript_DebugWarpTowns3
	goto_if_eq VAR_RESULT, 4, EventScript_DebugWarpTowns4
	goto_if_eq VAR_RESULT, 5, EventScript_DebugWarpTowns5
	goto_if_eq VAR_RESULT, 6, EventScript_DebugWarpTowns6
	goto_if_eq VAR_RESULT, 7, EventScript_DebugWarpTowns7
	goto_if_eq VAR_RESULT, 8, EventScript_DebugWarpTowns8
	goto_if_eq VAR_RESULT, 9, EventScript_DebugWarpTowns9
	goto_if_eq VAR_RESULT, 10, EventScript_DebugWarpTowns10
	goto_if_eq VAR_RESULT, 11, EventScript_DebugWarpTowns11
	goto EventScript_DebugWarpKind

EventScript_DebugWarpTowns0::
	call EventScript_DebugBeforeWarp
	warp MAP_PALLET_TOWN, 6, 8
	waitstate
	releaseall
	end

EventScript_DebugWarpTowns1::
	call EventScript_DebugBeforeWarp
	warp MAP_VIRIDIAN_CITY, 26, 27
	waitstate
	releaseall
	end

EventScript_DebugWarpTowns2::
	call EventScript_DebugBeforeWarp
	warp MAP_PEWTER_CITY, 17, 26
	waitstate
	releaseall
	end

EventScript_DebugWarpTowns3::
	call EventScript_DebugBeforeWarp
	warp MAP_CERULEAN_CITY, 22, 20
	waitstate
	releaseall
	end

EventScript_DebugWarpTowns4::
	call EventScript_DebugBeforeWarp
	warp MAP_VERMILION_CITY, 15, 7
	waitstate
	releaseall
	end

EventScript_DebugWarpTowns5::
	call EventScript_DebugBeforeWarp
	warp MAP_LAVENDER_TOWN, 6, 6
	waitstate
	releaseall
	end

EventScript_DebugWarpTowns6::
	call EventScript_DebugBeforeWarp
	warp MAP_CELADON_CITY, 48, 12
	waitstate
	releaseall
	end

EventScript_DebugWarpTowns7::
	call EventScript_DebugBeforeWarp
	warp MAP_FUCHSIA_CITY, 25, 32
	waitstate
	releaseall
	end

EventScript_DebugWarpTowns8::
	call EventScript_DebugBeforeWarp
	warp MAP_SAFFRON_CITY, 24, 39
	waitstate
	releaseall
	end

EventScript_DebugWarpTowns9::
	call EventScript_DebugBeforeWarp
	warp MAP_CINNABAR_ISLAND, 14, 12
	waitstate
	releaseall
	end

EventScript_DebugWarpTowns10::
	call EventScript_DebugBeforeWarp
	warp MAP_INDIGO_PLATEAU_EXTERIOR, 11, 7
	waitstate
	releaseall
	end

EventScript_DebugWarpTowns11::
	call EventScript_DebugBeforeWarp
	warp MAP_ONE_ISLAND, 14, 6
	waitstate
	releaseall
	end

EventScript_DebugWarpGyms::
	dynmultichoice 0, 0, FALSE, 7, 0, DYN_MULTICHOICE_CB_NONE, DebugMenu_Text_PewterGym, DebugMenu_Text_CeruleanGym, DebugMenu_Text_VermilionGym, DebugMenu_Text_CeladonGym, DebugMenu_Text_FuchsiaGym, DebugMenu_Text_SaffronGym, DebugMenu_Text_CinnabarGym, DebugMenu_Text_ViridianGym, DebugMenu_Text_PokemonLeague, DebugMenu_Text_Back
	goto_if_eq VAR_RESULT, 0, EventScript_DebugWarpGyms0
	goto_if_eq VAR_RESULT, 1, EventScript_DebugWarpGyms1
	goto_if_eq VAR_RESULT, 2, EventScript_DebugWarpGyms2
	goto_if_eq VAR_RESULT, 3, EventScript_DebugWarpGyms3
	goto_if_eq VAR_RESULT, 4, EventScript_DebugWarpGyms4
	goto_if_eq VAR_RESULT, 5, EventScript_DebugWarpGyms5
	goto_if_eq VAR_RESULT, 6, EventScript_DebugWarpGyms6
	goto_if_eq VAR_RESULT, 7, EventScript_DebugWarpGyms7
	goto_if_eq VAR_RESULT, 8, EventScript_DebugWarpGyms8
	goto EventScript_DebugWarpKind

EventScript_DebugWarpGyms0::
	call EventScript_DebugBeforeWarp
	warp MAP_PEWTER_CITY_GYM, 1
	waitstate
	releaseall
	end

EventScript_DebugWarpGyms1::
	call EventScript_DebugBeforeWarp
	warp MAP_CERULEAN_CITY_GYM, 1
	waitstate
	releaseall
	end

EventScript_DebugWarpGyms2::
	call EventScript_DebugBeforeWarp
	warp MAP_VERMILION_CITY_GYM, 1
	waitstate
	releaseall
	end

EventScript_DebugWarpGyms3::
	call EventScript_DebugBeforeWarp
	warp MAP_CELADON_CITY_GYM, 1
	waitstate
	releaseall
	end

EventScript_DebugWarpGyms4::
	call EventScript_DebugBeforeWarp
	warp MAP_FUCHSIA_CITY_GYM, 1
	waitstate
	releaseall
	end

EventScript_DebugWarpGyms5::
	call EventScript_DebugBeforeWarp
	warp MAP_SAFFRON_CITY_GYM, 1
	waitstate
	releaseall
	end

EventScript_DebugWarpGyms6::
	call EventScript_DebugBeforeWarp
	warp MAP_CINNABAR_ISLAND_GYM, 1
	waitstate
	releaseall
	end

EventScript_DebugWarpGyms7::
	call EventScript_DebugBeforeWarp
	warp MAP_VIRIDIAN_CITY_GYM, 1
	waitstate
	releaseall
	end

EventScript_DebugWarpGyms8::
	call EventScript_DebugBeforeWarp
	warp MAP_INDIGO_PLATEAU_POKEMON_CENTER_1F, 0
	waitstate
	releaseall
	end

EventScript_DebugWarpSpots::
	dynmultichoice 0, 0, FALSE, 7, 0, DYN_MULTICHOICE_CB_NONE, DebugMenu_Text_MtMoonEntrance, DebugMenu_Text_Route11, DebugMenu_Text_PowerPlant, DebugMenu_Text_PunchTutors, DebugMenu_Text_CyclingRoadGate, DebugMenu_Text_Back
	goto_if_eq VAR_RESULT, 0, EventScript_DebugWarpSpots0
	goto_if_eq VAR_RESULT, 1, EventScript_DebugWarpSpots1
	goto_if_eq VAR_RESULT, 2, EventScript_DebugWarpSpots2
	goto_if_eq VAR_RESULT, 3, EventScript_DebugWarpSpots3
	goto_if_eq VAR_RESULT, 4, EventScript_DebugWarpSpots4
	goto EventScript_DebugWarpKind

EventScript_DebugWarpSpots0::
	call EventScript_DebugBeforeWarp
	warp MAP_ROUTE4, 12, 6
	waitstate
	releaseall
	end

EventScript_DebugWarpSpots1::
	call EventScript_DebugBeforeWarp
	warp MAP_ROUTE11, 8, 10
	waitstate
	releaseall
	end

EventScript_DebugWarpSpots2::
	call EventScript_DebugBeforeWarp
	warp MAP_POWER_PLANT, 0
	waitstate
	releaseall
	end

EventScript_DebugWarpSpots3::
	call EventScript_DebugBeforeWarp
	warp MAP_ROUTE15_HOUSEOF_ELEMENTS, 0
	waitstate
	releaseall
	end

EventScript_DebugWarpSpots4::
	checkitem ITEM_BICYCLE
	call_if_eq VAR_RESULT, FALSE, EventScript_DebugAddBicycle
	call EventScript_DebugBeforeWarp
	warp MAP_ROUTE16, 28, 13
	waitstate
	releaseall
	end

@ Leaving Cycling Road by warping must not leave the player stuck on the bike
EventScript_DebugBeforeWarp::
	clearflag FLAG_SYS_ON_CYCLING_ROAD
	setvar VAR_MAP_SCENE_ROUTE16, 0
	return

EventScript_DebugAddBicycle::
	additem ITEM_BICYCLE
	return

EventScript_DebugNoWarpSafari::
	msgbox DebugMenu_Text_NoWarpSafari
	goto EventScript_DebugMain

EventScript_DebugNoWarpParty::
	msgbox DebugMenu_Text_NoWarpParty
	goto EventScript_DebugMain

EventScript_DebugMon::
	setvar VAR_0x8004, DEBUG_PICK_SPECIES
	special DebugMenu_PickNumber
	waitstate
	goto_if_eq VAR_RESULT, 0, EventScript_DebugMain
	copyvar VAR_0x8005, VAR_RESULT
	setvar VAR_0x8004, DEBUG_PICK_LEVEL
	special DebugMenu_PickNumber
	waitstate
	goto_if_eq VAR_RESULT, 0, EventScript_DebugMon
	copyvar VAR_0x8006, VAR_RESULT
	specialvar VAR_RESULT, DebugMenu_GiveMon
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, EventScript_DebugMonToPc
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, EventScript_DebugMonNoRoom
	msgbox DebugMenu_Text_MonToParty
	goto EventScript_DebugMain

EventScript_DebugMonToPc::
	msgbox DebugMenu_Text_MonToPc
	goto EventScript_DebugMain

EventScript_DebugMonNoRoom::
	msgbox DebugMenu_Text_MonNoRoom
	goto EventScript_DebugMain

EventScript_DebugItems::
	closemessage
	dynmultichoice 0, 0, FALSE, 8, 0, DYN_MULTICHOICE_CB_NONE, DebugMenu_Text_Repels, DebugMenu_Text_PokeBalls, DebugMenu_Text_EvolutionItems, DebugMenu_Text_AllTmsAndHms, DebugMenu_Text_Bicycle, DebugMenu_Text_Money, DebugMenu_Text_ChooseAnyItem, DebugMenu_Text_Back
	goto_if_eq VAR_RESULT, 0, EventScript_DebugRepels
	goto_if_eq VAR_RESULT, 1, EventScript_DebugBalls
	goto_if_eq VAR_RESULT, 2, EventScript_DebugEvoItems
	goto_if_eq VAR_RESULT, 3, EventScript_DebugAllTms
	goto_if_eq VAR_RESULT, 4, EventScript_DebugBicycle
	goto_if_eq VAR_RESULT, 5, EventScript_DebugMoney
	goto_if_eq VAR_RESULT, 6, EventScript_DebugAnyItem
	goto EventScript_DebugMain

EventScript_DebugRepels::
	additem ITEM_REPEL, 20
	additem ITEM_SUPER_REPEL, 20
	additem ITEM_MAX_REPEL, 20
	goto EventScript_DebugItemsDone

EventScript_DebugBalls::
	additem ITEM_POKE_BALL, 20
	additem ITEM_GREAT_BALL, 20
	additem ITEM_ULTRA_BALL, 20
	additem ITEM_MASTER_BALL, 5
	goto EventScript_DebugItemsDone

EventScript_DebugEvoItems::
	additem ITEM_SUN_STONE, 3
	additem ITEM_MOON_STONE, 3
	additem ITEM_FIRE_STONE, 3
	additem ITEM_THUNDER_STONE, 3
	additem ITEM_WATER_STONE, 3
	additem ITEM_LEAF_STONE, 3
	additem ITEM_KINGS_ROCK, 3
	additem ITEM_METAL_COAT, 3
	additem ITEM_DRAGON_SCALE, 3
	additem ITEM_UP_GRADE, 3
	additem ITEM_DEEP_SEA_TOOTH, 3
	additem ITEM_DEEP_SEA_SCALE, 3
	goto EventScript_DebugItemsDone

EventScript_DebugAllTms::
	setvar VAR_0x8005, ITEM_TM01
	setvar VAR_0x8006, ITEM_HM08
	special DebugMenu_GiveItemRange
	goto EventScript_DebugItemsDone

EventScript_DebugBicycle::
	checkitem ITEM_BICYCLE
	call_if_eq VAR_RESULT, FALSE, EventScript_DebugAddBicycle
	goto EventScript_DebugItemsDone

EventScript_DebugMoney::
	addmoney 999999
	goto EventScript_DebugItemsDone

EventScript_DebugItemsDone::
	msgbox DebugMenu_Text_ItemsDone
	goto EventScript_DebugItems

EventScript_DebugAnyItem::
	setvar VAR_0x8004, DEBUG_PICK_ITEM
	special DebugMenu_PickNumber
	waitstate
	goto_if_eq VAR_RESULT, 0, EventScript_DebugItems
	copyvar VAR_0x8005, VAR_RESULT
	setvar VAR_0x8006, 1
	specialvar VAR_RESULT, DebugMenu_IsSingleItem
	goto_if_eq VAR_RESULT, TRUE, EventScript_DebugGiveChosenItem
	setvar VAR_0x8004, DEBUG_PICK_QUANTITY
	special DebugMenu_PickNumber
	waitstate
	goto_if_eq VAR_RESULT, 0, EventScript_DebugAnyItem
	copyvar VAR_0x8006, VAR_RESULT
EventScript_DebugGiveChosenItem::
	specialvar VAR_RESULT, DebugMenu_GiveItem
	goto_if_eq VAR_RESULT, FALSE, EventScript_DebugItemFailed
	msgbox DebugMenu_Text_GotItem
	goto EventScript_DebugItems

EventScript_DebugItemFailed::
	msgbox DebugMenu_Text_ItemFailed
	goto EventScript_DebugItems

EventScript_DebugProgress::
	closemessage
	dynmultichoice 0, 0, FALSE, 7, 0, DYN_MULTICHOICE_CB_NONE, DebugMenu_Text_AllBadges, DebugMenu_Text_BadgesAndHms, DebugMenu_Text_UnlockFlyMap, DebugMenu_Text_Pokedex, DebugMenu_Text_BeatTheChampion, DebugMenu_Text_Back
	goto_if_eq VAR_RESULT, 0, EventScript_DebugBadges
	goto_if_eq VAR_RESULT, 1, EventScript_DebugHms
	goto_if_eq VAR_RESULT, 2, EventScript_DebugFly
	goto_if_eq VAR_RESULT, 3, EventScript_DebugDex
	goto_if_eq VAR_RESULT, 4, EventScript_DebugChampion
	goto EventScript_DebugMain

EventScript_DebugBadges::
	call EventScript_DebugSetBadges
	goto EventScript_DebugProgressDone

EventScript_DebugSetBadges::
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET
	setflag FLAG_BADGE06_GET
	setflag FLAG_BADGE07_GET
	setflag FLAG_BADGE08_GET
	return

EventScript_DebugHms::
	call EventScript_DebugSetBadges
	setvar VAR_0x8005, ITEM_HM01
	setvar VAR_0x8006, ITEM_HM07
	special DebugMenu_GiveItemRange
	goto EventScript_DebugProgressDone

EventScript_DebugFly::
	setflag FLAG_WORLD_MAP_PALLET_TOWN
	setflag FLAG_WORLD_MAP_VIRIDIAN_CITY
	setflag FLAG_WORLD_MAP_PEWTER_CITY
	setflag FLAG_WORLD_MAP_CERULEAN_CITY
	setflag FLAG_WORLD_MAP_LAVENDER_TOWN
	setflag FLAG_WORLD_MAP_VERMILION_CITY
	setflag FLAG_WORLD_MAP_CELADON_CITY
	setflag FLAG_WORLD_MAP_FUCHSIA_CITY
	setflag FLAG_WORLD_MAP_CINNABAR_ISLAND
	setflag FLAG_WORLD_MAP_INDIGO_PLATEAU_EXTERIOR
	setflag FLAG_WORLD_MAP_SAFFRON_CITY
	setflag FLAG_WORLD_MAP_ONE_ISLAND
	setflag FLAG_WORLD_MAP_TWO_ISLAND
	setflag FLAG_WORLD_MAP_THREE_ISLAND
	setflag FLAG_WORLD_MAP_FOUR_ISLAND
	setflag FLAG_WORLD_MAP_FIVE_ISLAND
	setflag FLAG_WORLD_MAP_SEVEN_ISLAND
	setflag FLAG_WORLD_MAP_SIX_ISLAND
	setflag FLAG_WORLD_MAP_ROUTE4_POKEMON_CENTER_1F
	setflag FLAG_WORLD_MAP_ROUTE10_POKEMON_CENTER_1F
	goto EventScript_DebugProgressDone

EventScript_DebugDex::
	setflag FLAG_SYS_POKEDEX_GET
	special EnableNationalPokedex
	goto EventScript_DebugProgressDone

EventScript_DebugChampion::
	msgbox DebugMenu_Text_ConfirmChampion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_DebugProgress
	setflag FLAG_SYS_GAME_CLEAR
	goto EventScript_DebugProgressDone

EventScript_DebugProgressDone::
	msgbox DebugMenu_Text_ProgressDone
	goto EventScript_DebugProgress

DebugMenu_Text_Warp::
    .string "WARP$"

DebugMenu_Text_Pokemon::
    .string "POKéMON$"

DebugMenu_Text_Items::
    .string "ITEMS$"

DebugMenu_Text_Progress::
    .string "PROGRESS$"

DebugMenu_Text_Heal::
    .string "HEAL$"

DebugMenu_Text_Exit::
    .string "EXIT$"

DebugMenu_Text_Healed::
    .string "Your party is fully healed.$"

DebugMenu_Text_Towns::
    .string "TOWNS$"

DebugMenu_Text_Gyms::
    .string "GYMS$"

DebugMenu_Text_TestSpots::
    .string "TEST SPOTS$"

DebugMenu_Text_Back::
    .string "BACK$"

DebugMenu_Text_PalletTown::
    .string "PALLET TOWN$"

DebugMenu_Text_ViridianCity::
    .string "VIRIDIAN CITY$"

DebugMenu_Text_PewterCity::
    .string "PEWTER CITY$"

DebugMenu_Text_CeruleanCity::
    .string "CERULEAN CITY$"

DebugMenu_Text_VermilionCity::
    .string "VERMILION CITY$"

DebugMenu_Text_LavenderTown::
    .string "LAVENDER TOWN$"

DebugMenu_Text_CeladonCity::
    .string "CELADON CITY$"

DebugMenu_Text_FuchsiaCity::
    .string "FUCHSIA CITY$"

DebugMenu_Text_SaffronCity::
    .string "SAFFRON CITY$"

DebugMenu_Text_CinnabarIsland::
    .string "CINNABAR ISLAND$"

DebugMenu_Text_IndigoPlateau::
    .string "INDIGO PLATEAU$"

DebugMenu_Text_OneIsland::
    .string "ONE ISLAND$"

DebugMenu_Text_PewterGym::
    .string "PEWTER GYM$"

DebugMenu_Text_CeruleanGym::
    .string "CERULEAN GYM$"

DebugMenu_Text_VermilionGym::
    .string "VERMILION GYM$"

DebugMenu_Text_CeladonGym::
    .string "CELADON GYM$"

DebugMenu_Text_FuchsiaGym::
    .string "FUCHSIA GYM$"

DebugMenu_Text_SaffronGym::
    .string "SAFFRON GYM$"

DebugMenu_Text_CinnabarGym::
    .string "CINNABAR GYM$"

DebugMenu_Text_ViridianGym::
    .string "VIRIDIAN GYM$"

DebugMenu_Text_PokemonLeague::
    .string "POKéMON LEAGUE$"

DebugMenu_Text_MtMoonEntrance::
    .string "MT. MOON ENTRANCE$"

DebugMenu_Text_Route11::
    .string "ROUTE 11$"

DebugMenu_Text_PowerPlant::
    .string "POWER PLANT$"

DebugMenu_Text_PunchTutors::
    .string "PUNCH TUTORS$"

DebugMenu_Text_CyclingRoadGate::
    .string "CYCLING ROAD GATE$"

DebugMenu_Text_NoWarpSafari::
    .string "Leave the SAFARI ZONE first.$"

DebugMenu_Text_NoWarpParty::
    .string "Get a POKéMON first, using\nthe POKéMON menu.$"

DebugMenu_Text_MonToParty::
    .string "{STR_VAR_1} joined your party.$"

DebugMenu_Text_MonToPc::
    .string "{STR_VAR_1} was sent\nto the PC.$"

DebugMenu_Text_MonNoRoom::
    .string "There is no room left.$"

DebugMenu_Text_Repels::
    .string "REPELS$"

DebugMenu_Text_PokeBalls::
    .string "POKé BALLS$"

DebugMenu_Text_EvolutionItems::
    .string "EVOLUTION ITEMS$"

DebugMenu_Text_AllTmsAndHms::
    .string "ALL TMs AND HMs$"

DebugMenu_Text_Bicycle::
    .string "BICYCLE$"

DebugMenu_Text_Money::
    .string "MONEY$"

DebugMenu_Text_ChooseAnyItem::
    .string "CHOOSE ANY ITEM$"

DebugMenu_Text_ItemsDone::
    .string "Done! Check your BAG.$"

DebugMenu_Text_GotItem::
    .string "Added {STR_VAR_1}\nto your BAG.$"

DebugMenu_Text_ItemFailed::
    .string "Could not add {STR_VAR_1}.\nYou may already have it.$"

DebugMenu_Text_AllBadges::
    .string "ALL BADGES$"

DebugMenu_Text_BadgesAndHms::
    .string "BADGES AND HMs$"

DebugMenu_Text_UnlockFlyMap::
    .string "UNLOCK FLY MAP$"

DebugMenu_Text_Pokedex::
    .string "POKéDEX$"

DebugMenu_Text_BeatTheChampion::
    .string "BEAT THE CHAMPION$"

DebugMenu_Text_ConfirmChampion::
    .string "Mark the game as beaten?\pThis changes the story and\ncannot be undone here.$"

DebugMenu_Text_ProgressDone::
    .string "Done!$"
