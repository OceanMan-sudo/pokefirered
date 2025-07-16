CinnabarIsland_BattleHouse_MapScripts::
	.byte 0


CinnabarIslandBattleHouseClerk::
# 4 "data/maps/CinnabarIsland_BattleHouse/scripts.pory"
	lock
# 5 "data/maps/CinnabarIsland_BattleHouse/scripts.pory"
	faceplayer
# 6 "data/maps/CinnabarIsland_BattleHouse/scripts.pory"
	goto_if_set FLAG_0x0B8, CinnabarIslandBattleHouseClerk_1
# 10 "data/maps/CinnabarIsland_BattleHouse/scripts.pory"
	checktrainerflag TRAINER_BLACK_BELT_ROGAN
	goto_if 1, CinnabarIslandBattleHouseClerk_4
CinnabarIslandBattleHouseClerk_3:
# 18 "data/maps/CinnabarIsland_BattleHouse/scripts.pory"
	msgbox CinnabarIslandBattleHouseClerk_Text_3
# 19 "data/maps/CinnabarIsland_BattleHouse/scripts.pory"
	release
	end

CinnabarIslandBattleHouseClerk_1:
# 7 "data/maps/CinnabarIsland_BattleHouse/scripts.pory"
	msgbox CinnabarIslandBattleHouseClerk_Text_0
# 8 "data/maps/CinnabarIsland_BattleHouse/scripts.pory"
	release
	end

CinnabarIslandBattleHouseClerk_2:
# 11 "data/maps/CinnabarIsland_BattleHouse/scripts.pory"
	msgbox CinnabarIslandBattleHouseClerk_Text_1
# 12 "data/maps/CinnabarIsland_BattleHouse/scripts.pory"
	giveitem ITEM_CHOICE_BAND, 1
# 13 "data/maps/CinnabarIsland_BattleHouse/scripts.pory"
	msgbox CinnabarIslandBattleHouseClerk_Text_2
# 14 "data/maps/CinnabarIsland_BattleHouse/scripts.pory"
	setflag FLAG_0x0B8
# 15 "data/maps/CinnabarIsland_BattleHouse/scripts.pory"
	release
	end

CinnabarIslandBattleHouseClerk_4:
# 10 "data/maps/CinnabarIsland_BattleHouse/scripts.pory"
	checktrainerflag TRAINER_HIKER_JONES
	goto_if 1, CinnabarIslandBattleHouseClerk_6
	goto CinnabarIslandBattleHouseClerk_3

CinnabarIslandBattleHouseClerk_6:
# 10 "data/maps/CinnabarIsland_BattleHouse/scripts.pory"
	checktrainerflag TRAINER_YOUNGSTER_JAMIE
	goto_if 1, CinnabarIslandBattleHouseClerk_2
	goto CinnabarIslandBattleHouseClerk_3


CinnabarIslandBattleHouseClerk_Text_0:
# 7 "data/maps/CinnabarIsland_BattleHouse/scripts.pory"
	.string "Congratulations on completing the\n"
	.string "CERULEAN CITY BATTLE HOUSE. We\l"
	.string "hope you enjoy your prize!$"

CinnabarIslandBattleHouseClerk_Text_1:
# 11 "data/maps/CinnabarIsland_BattleHouse/scripts.pory"
	.string "Congratulations on defeating each of\n"
	.string "the trainers in the CERULEAN CITY\l"
	.string "BATTLE HOUSE! Please accept this\l"
	.string "SHELL BELL as a reward for\l"
	.string "completing our challenge!$"

CinnabarIslandBattleHouseClerk_Text_2:
# 13 "data/maps/CinnabarIsland_BattleHouse/scripts.pory"
	.string "We do hope you enjoy your prize!$"

CinnabarIslandBattleHouseClerk_Text_3:
# 18 "data/maps/CinnabarIsland_BattleHouse/scripts.pory"
	.string "Welcome to the CINNABAR ISLAND\n"
	.string "BATTLE HOUSE! Defeat all three\l"
	.string "trainers and win a fabulous prize!\l"
	.string "Fair warning; the trainers in here\l"
	.string "are tough cookies!$"
