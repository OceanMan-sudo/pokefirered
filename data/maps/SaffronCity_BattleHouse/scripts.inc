SaffronCity_BattleHouse_MapScripts::
	.byte 0


SaffronCityBattleHouseClerk::
# 4 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	lock
# 5 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	faceplayer
# 6 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	msgbox SaffronCityBattleHouseClerk_Text_0
# 7 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	release
	end


SaffronMay::
# 11 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	lock
# 12 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	faceplayer
# 13 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	trainerbattle_single TRAINER_PLAYER_MAY, MayIntro, MayDefeated
# 14 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	msgbox MayPostBattle, MSGBOX_AUTOCLOSE
# 15 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	waitmessage
# 16 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	release
	end


SaffronBrendan::
# 22 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	lock
# 23 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	faceplayer
# 24 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	trainerbattle_single TRAINER_PLAYER_BRENDAN, BrendanIntro, BrendanDefeated
# 25 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	msgbox BrendanPostBattle, MSGBOX_AUTOCLOSE
# 26 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	waitmessage
# 27 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	release
	end


CoolTrainerDuke::
# 32 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	lock
# 33 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	faceplayer
# 34 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	trainerbattle_single TRAINER_COOLTRAINER_DUKE, DukeIntro, DukeDefeated
# 35 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	msgbox DukePostBattle, MSGBOX_AUTOCLOSE
# 36 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	waitmessage
# 37 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	release
	end


SaffronCityBattleHouseClerk_Text_0:
# 6 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	.string "Welcome to the SAFFRON CITY BATTLE\n"
	.string "HOUSE! Defeat all three trainers\l"
	.string "and win a fabulous prize! Fair\l"
	.string "warning; the trainers in here are\l"
	.string "tough!$"

MayIntro::
# 41 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	.string "You're saying I look familiar? Odd.\n"
	.string "This is my first time in the KANTO\l"
	.string "region!$"

MayDefeated::
# 45 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	.string "Wow, you're tough!$"

MayPostBattle::
# 49 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	.string "You should visit the HOENN region\n"
	.string "sometime. There are tons of tough\l"
	.string "trainers and rare POKeMON to catch!$"

BrendanIntro::
# 53 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	.string "My neighbor and I are on vacation\n"
	.string "from the HOENN region. Let's see\l"
	.string "what you got!$"

BrendanDefeated::
# 57 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	.string "Wow, you're no joke!$"

BrendanPostBattle::
# 61 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	.string "I wish I could stick around KANTO a\n"
	.string "bit longer, but I'll need to return\l"
	.string "to LITTLEROOT TOWN soon.$"

DukeIntro::
# 65 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	.string "Let's see if you've got what it takes!$"

DukeDefeated::
# 69 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	.string "It turns out you do have what it\n"
	.string "takes.$"

DukePostBattle::
# 73 "data/maps/SaffronCity_BattleHouse/scripts.pory"
	.string "This BATTLE HOUSE gives out the\n"
	.string "CHOICE BAND as a reward. Talk\l"
	.string "about a strong item to have!$"
