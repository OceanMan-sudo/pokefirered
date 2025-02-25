SaffronCity_BattleHouse_MapScripts::
	.byte 0


SaffronCityBattleHouseClerk::
# 4 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	lock
# 5 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	faceplayer
# 6 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	goto_if_set FLAG_0x0B3, SaffronCityBattleHouseClerk_1
# 10 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	checktrainerflag TRAINER_COOLTRAINER_DUKE
	goto_if 1, SaffronCityBattleHouseClerk_4
SaffronCityBattleHouseClerk_3:
# 18 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	msgbox SaffronCityBattleHouseClerk_Text_3
# 19 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	release
	end

SaffronCityBattleHouseClerk_1:
# 7 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	msgbox SaffronCityBattleHouseClerk_Text_0
# 8 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	release
	end

SaffronCityBattleHouseClerk_2:
# 11 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	msgbox SaffronCityBattleHouseClerk_Text_1
# 12 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	giveitem ITEM_CHOICE_BAND, 1
# 13 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	msgbox SaffronCityBattleHouseClerk_Text_2
# 14 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	setflag FLAG_0x0B3
# 15 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	release
	end

SaffronCityBattleHouseClerk_4:
# 10 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	checktrainerflag TRAINER_COOLTRAINER_SYLVIA
	goto_if 1, SaffronCityBattleHouseClerk_6
	goto SaffronCityBattleHouseClerk_3

SaffronCityBattleHouseClerk_6:
# 10 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	checktrainerflag TRAINER_PLAYER_BRENDAN
	goto_if 1, SaffronCityBattleHouseClerk_8
	goto SaffronCityBattleHouseClerk_3

SaffronCityBattleHouseClerk_8:
# 10 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	checktrainerflag TRAINER_PLAYER_MAY
	goto_if 1, SaffronCityBattleHouseClerk_2
	goto SaffronCityBattleHouseClerk_3


SaffronMay::
# 24 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	lock
# 25 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	faceplayer
# 26 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	trainerbattle_single TRAINER_PLAYER_MAY, MayIntro, MayDefeated
# 27 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	msgbox MayPostBattle, MSGBOX_AUTOCLOSE
# 28 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	waitmessage
# 29 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	release
	end


SaffronBrendan::
# 35 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	lock
# 36 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	faceplayer
# 37 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	trainerbattle_single TRAINER_PLAYER_BRENDAN, BrendanIntro, BrendanDefeated
# 38 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	msgbox BrendanPostBattle, MSGBOX_AUTOCLOSE
# 39 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	waitmessage
# 40 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	release
	end


CoolTrainerDuke::
# 45 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	lock
# 46 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	faceplayer
# 47 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	trainerbattle_single TRAINER_COOLTRAINER_DUKE, DukeIntro, DukeDefeated
# 48 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	msgbox DukePostBattle, MSGBOX_AUTOCLOSE
# 49 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	waitmessage
# 50 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	release
	end


CoolTrainerSylvia::
# 55 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	lock
# 56 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	faceplayer
# 57 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	trainerbattle_single TRAINER_COOLTRAINER_SYLVIA, SylviaIntro, SylviaDefeated
# 58 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	msgbox SylviaPostBattle, MSGBOX_AUTOCLOSE
# 59 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	waitmessage
# 60 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	release
	end


SaffronCityBattleHouseClerk_Text_0:
# 7 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	.string "Congratulations on completing the\n"
	.string "SAFFRON CITY BATTLE HOUSE. We\l"
	.string "hope you enjoy your prize!$"

SaffronCityBattleHouseClerk_Text_1:
# 11 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	.string "Congratulations on defeating each of\n"
	.string "the trainers in the SAFFRON CITY\l"
	.string "BATTLE HOUSE! Please accept the\l"
	.string "CHOICE BAND as a reward for\l"
	.string "completing this challenge!$"

SaffronCityBattleHouseClerk_Text_2:
# 13 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	.string "We do hope you enjoy your prize!$"

SaffronCityBattleHouseClerk_Text_3:
# 18 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	.string "Welcome to the SAFFRON CITY BATTLE\n"
	.string "HOUSE! Defeat all three trainers\l"
	.string "and win a fabulous prize! Fair\l"
	.string "warning; the trainers in here are\l"
	.string "tough!$"

MayIntro::
# 64 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	.string "You're saying I look familiar? Odd.\n"
	.string "This is my first time in the KANTO\l"
	.string "region!$"

MayDefeated::
# 68 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	.string "Wow, you're tough!$"

MayPostBattle::
# 72 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	.string "You should visit the HOENN region\n"
	.string "sometime. There are tons of tough\l"
	.string "trainers and rare POKeMON to catch!$"

BrendanIntro::
# 76 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	.string "My neighbor and I are on vacation\n"
	.string "from the HOENN region. Let's see\l"
	.string "what you got!$"

BrendanDefeated::
# 80 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	.string "Wow, you're no joke!$"

BrendanPostBattle::
# 84 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	.string "I wish I could stick around KANTO a\n"
	.string "bit longer, but I'll need to return\l"
	.string "to LITTLEROOT TOWN soon.$"

DukeIntro::
# 88 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	.string "This music is just so catchy!$"

DukeDefeated::
# 92 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	.string "This tune is gonna be stuck in my\n"
	.string "head all day!$"

DukePostBattle::
# 96 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	.string "You never really get to see this\n"
	.string "room in regular playthroughs do you?$"

SylviaIntro::
# 100 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	.string "Am I crazy or are those two HOENN\n"
	.string "trainers super familiar?$"

SylviaDefeated::
# 104 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	.string "Seriously, that's BRENDAN and MAY\n"
	.string "from HOENN!$"

SylviaPostBattle::
# 108 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	.string "I wonder what those two are doing\n"
	.string "here in SAFFRON CITY?$"
