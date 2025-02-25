CeruleanCity_BattleHouse_MapScripts::
	.byte 0


CeruleanCityBattleHouseClerk::
# 4 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	lock
# 5 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	faceplayer
# 6 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	goto_if_set FLAG_0x0B3, CeruleanCityBattleHouseClerk_1
# 10 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	checktrainerflag TRAINER_COOLTRAINER_DUKE
	goto_if 1, CeruleanCityBattleHouseClerk_4
CeruleanCityBattleHouseClerk_3:
# 18 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	msgbox CeruleanCityBattleHouseClerk_Text_3
# 19 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	release
	end

CeruleanCityBattleHouseClerk_1:
# 7 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	msgbox CeruleanCityBattleHouseClerk_Text_0
# 8 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	release
	end

CeruleanCityBattleHouseClerk_2:
# 11 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	msgbox CeruleanCityBattleHouseClerk_Text_1
# 12 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	giveitem ITEM_SHELL_BELL, 1
# 13 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	msgbox CeruleanCityBattleHouseClerk_Text_2
# 14 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	setflag FLAG_0x0B4
# 15 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	release
	end

CeruleanCityBattleHouseClerk_4:
# 10 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	checktrainerflag TRAINER_COOLTRAINER_SYLVIA
	goto_if 1, CeruleanCityBattleHouseClerk_6
	goto CeruleanCityBattleHouseClerk_3

CeruleanCityBattleHouseClerk_6:
# 10 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	checktrainerflag TRAINER_PLAYER_BRENDAN
	goto_if 1, CeruleanCityBattleHouseClerk_8
	goto CeruleanCityBattleHouseClerk_3

CeruleanCityBattleHouseClerk_8:
# 10 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	checktrainerflag TRAINER_PLAYER_MAY
	goto_if 1, CeruleanCityBattleHouseClerk_2
	goto CeruleanCityBattleHouseClerk_3


NonTrainer::
# 25 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	lock
# 26 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	faceplayer
# 27 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	msgbox NonTrainer_Text_0
# 28 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	release
	end


NonTrainer2::
# 33 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	lock
# 34 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	faceplayer
# 35 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	msgbox NonTrainer2_Text_0
# 36 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	release
	end


YoungsterJamie::
# 41 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	lock
# 42 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	faceplayer
# 43 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	trainerbattle_single TRAINER_YOUNGSTER_JAMIE, JamieIntro, JamieDefeated
# 44 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	msgbox JamiePostBattle, MSGBOX_AUTOCLOSE
# 45 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	waitmessage
# 46 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	release
	end


JoeRogan::
# 63 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	lock
# 64 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	faceplayer
# 65 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_ROGAN, RoganIntro, RoganDefeated
# 66 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	msgbox RoganPostBattle, MSGBOX_AUTOCLOSE
# 67 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	waitmessage
# 68 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	release
	end


CeruleanCityBattleHouseClerk_Text_0:
# 7 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	.string "Congratulations on completing the\n"
	.string "CERULEAN CITY BATTLE HOUSE. We\l"
	.string "hope you enjoy your prize!$"

CeruleanCityBattleHouseClerk_Text_1:
# 11 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	.string "Congratulations on defeating each of\n"
	.string "the trainers in the CERULEAN CITY\l"
	.string "BATTLE HOUSE! Please accept this\l"
	.string "SHELL BELL as a reward for\l"
	.string "completing our challenge!$"

CeruleanCityBattleHouseClerk_Text_2:
# 13 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	.string "We do hope you enjoy your prize!$"

CeruleanCityBattleHouseClerk_Text_3:
# 18 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	.string "Welcome to the CERULEAN CITY BATTLE\n"
	.string "HOUSE! Defeat all three trainers\l"
	.string "and win a fabulous prize! Fair\l"
	.string "warning; the trainers in here are\l"
	.string "tough!$"

NonTrainer_Text_0:
# 27 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	.string "Oh, I'm not a trainer. I just like\n"
	.string "hanging out at these new BATTLE\l"
	.string "HOUSE facilities.$"

NonTrainer2_Text_0:
# 35 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	.string "There are new BATTLE HOUSE\n"
	.string "facilities spread across KANTO that\l"
	.string "offer really powerful items as\l"
	.string "prizes. The prize at this facility\l"
	.string "is the SHELL BELL which heals a\l"
	.string "POKéMON by a little bit any time it\l"
	.string "inflicts damage on an opponent.\l"
	.string "Pretty convenient!$"

JamieIntro::
# 50 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	.string "Want a battle? Sure, let me pull\n"
	.string "that up for you!$"

JamieDefeated::
# 54 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	.string "Wait, let me pull that up!$"

JamiePostBattle::
# 58 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	.string "To be honest, I stopped listening to\n"
	.string "the podcast too...$"

RoganIntro::
# 72 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	.string "You ever seen a PRIMEAPE out in the\n"
	.string "wild? They will literally rip your\l"
	.string "face off!$"

RoganDefeated::
# 76 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	.string "Jamie pull that up!$"

RoganPostBattle::
# 80 "data/maps/CeruleanCity_BattleHouse/scripts.pory"
	.string "You killed, bro. You killed!$"
