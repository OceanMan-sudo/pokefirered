# 1 "data/maps/VermilionCity_House1/scripts.pory"

# 2 "data/maps/VermilionCity_House1/scripts.pory"
VermilionCity_House1_MapScripts::
# 3 "data/maps/VermilionCity_House1/scripts.pory"
	.byte 0
# 4 "data/maps/VermilionCity_House1/scripts.pory"

# 5 "data/maps/VermilionCity_House1/scripts.pory"
VermilionCity_House1_EventScript_FishingGuru::
# 6 "data/maps/VermilionCity_House1/scripts.pory"
	lock
# 7 "data/maps/VermilionCity_House1/scripts.pory"
	faceplayer
# 8 "data/maps/VermilionCity_House1/scripts.pory"
	goto_if_set FLAG_GOT_OLD_ROD, VermilionCity_House1_EventScript_AlreadyGotOldRod
# 9 "data/maps/VermilionCity_House1/scripts.pory"
	msgbox VermilionCity_House1_Text_ImFishingGuruDoYouLikeToFish, MSGBOX_YESNO
# 10 "data/maps/VermilionCity_House1/scripts.pory"
	goto_if_eq VAR_RESULT, YES, VermilionCity_House1_EventScript_GiveOldRod
# 11 "data/maps/VermilionCity_House1/scripts.pory"
	msgbox VermilionCity_House1_Text_OhThatsSoDisappointing
# 12 "data/maps/VermilionCity_House1/scripts.pory"
	release
# 13 "data/maps/VermilionCity_House1/scripts.pory"
	end
# 14 "data/maps/VermilionCity_House1/scripts.pory"

# 15 "data/maps/VermilionCity_House1/scripts.pory"
VermilionCity_House1_EventScript_AlreadyGotOldRod::
# 16 "data/maps/VermilionCity_House1/scripts.pory"
	msgbox VermilionCity_House1_Text_HowAreTheFishBiting
# 17 "data/maps/VermilionCity_House1/scripts.pory"
	release
# 18 "data/maps/VermilionCity_House1/scripts.pory"
	end
# 19 "data/maps/VermilionCity_House1/scripts.pory"

# 20 "data/maps/VermilionCity_House1/scripts.pory"
VermilionCity_House1_EventScript_GiveOldRod::
# 21 "data/maps/VermilionCity_House1/scripts.pory"
	checkitemspace ITEM_OLD_ROD
# 22 "data/maps/VermilionCity_House1/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_House1_EventScript_NoRoomForOldRod
# 23 "data/maps/VermilionCity_House1/scripts.pory"
	additem ITEM_OLD_ROD
# 24 "data/maps/VermilionCity_House1/scripts.pory"
	msgbox VermilionCity_House1_Text_TakeThisAndFish
# 25 "data/maps/VermilionCity_House1/scripts.pory"
	msgreceiveditem VermilionCity_House1_Text_ReceivedOldRodFromFishingGuru, ITEM_OLD_ROD
# 26 "data/maps/VermilionCity_House1/scripts.pory"
	setflag FLAG_GOT_OLD_ROD
# 27 "data/maps/VermilionCity_House1/scripts.pory"
	msgbox VermilionCity_House1_Text_FishingIsAWayOfLife
# 28 "data/maps/VermilionCity_House1/scripts.pory"
	release
# 29 "data/maps/VermilionCity_House1/scripts.pory"
	end
# 30 "data/maps/VermilionCity_House1/scripts.pory"

# 31 "data/maps/VermilionCity_House1/scripts.pory"
VermilionCity_House1_EventScript_NoRoomForOldRod::
# 32 "data/maps/VermilionCity_House1/scripts.pory"
	msgbox VermilionCity_House1_Text_NoRoomForNiceGift
# 33 "data/maps/VermilionCity_House1/scripts.pory"
	release
# 34 "data/maps/VermilionCity_House1/scripts.pory"
	end

VermillionCity_GoodRod::
# 38 "data/maps/VermilionCity_House1/scripts.pory"
	goto_if_set FLAG_GOT_GOOD_ROD, VermillionCity_GoodRod_2
# 44 "data/maps/VermilionCity_House1/scripts.pory"
	lock
# 45 "data/maps/VermilionCity_House1/scripts.pory"
	faceplayer
# 46 "data/maps/VermilionCity_House1/scripts.pory"
	msgbox VermillionCity_GoodRod_Text_1, MSGBOX_YESNO
# 47 "data/maps/VermilionCity_House1/scripts.pory"
	switch VAR_RESULT
# 48 "data/maps/VermilionCity_House1/scripts.pory"
	case YES, VermillionCity_GoodRod_5
# 55 "data/maps/VermilionCity_House1/scripts.pory"
	case NO, VermillionCity_GoodRod_6
	return

VermillionCity_GoodRod_2:
# 39 "data/maps/VermilionCity_House1/scripts.pory"
	lock
# 40 "data/maps/VermilionCity_House1/scripts.pory"
	faceplayer
# 41 "data/maps/VermilionCity_House1/scripts.pory"
	msgbox VermillionCity_GoodRod_Text_0
# 42 "data/maps/VermilionCity_House1/scripts.pory"
	release
	end

VermillionCity_GoodRod_5:
# 49 "data/maps/VermilionCity_House1/scripts.pory"
	msgbox VermillionCity_GoodRod_Text_2
# 50 "data/maps/VermilionCity_House1/scripts.pory"
	giveitem ITEM_GOOD_ROD, 1
# 51 "data/maps/VermilionCity_House1/scripts.pory"
	msgbox VermillionCity_GoodRod_Text_3
# 52 "data/maps/VermilionCity_House1/scripts.pory"
	setflag FLAG_GOT_GOOD_ROD
# 53 "data/maps/VermilionCity_House1/scripts.pory"
	release
	end

VermillionCity_GoodRod_6:
# 56 "data/maps/VermilionCity_House1/scripts.pory"
	msgbox VermillionCity_GoodRod_Text_4
# 57 "data/maps/VermilionCity_House1/scripts.pory"
	release
	end


VermillionCity_GoodRod_Text_0:
# 41 "data/maps/VermilionCity_House1/scripts.pory"
	.string "The GOOD ROD will net you rarer\n"
	.string "POKéMON than the OLD ROD would. If\l"
	.string "you fish here in VERMILLION, you\l"
	.string "might even find ELECTRIC POKéMON\l"
	.string "in the waters!$"

VermillionCity_GoodRod_Text_1:
# 46 "data/maps/VermilionCity_House1/scripts.pory"
	.string "Ah, the thrill of fishing! There's\n"
	.string "nothing quite like it. The calm of\l"
	.string "the water, the tug of a bite, and\l"
	.string "the excitement of reeling in a big\l"
	.string "catch! It’s not just about the fish;\l"
	.string "it’s about the peace and joy of\l"
	.string "being out here. Wouldn't you agree,\l"
	.string "kid?$"

VermillionCity_GoodRod_Text_2:
# 49 "data/maps/VermilionCity_House1/scripts.pory"
	.string "I knew you’d understand! Here, take\n"
	.string "this GOOD ROD.$"

VermillionCity_GoodRod_Text_3:
# 51 "data/maps/VermilionCity_House1/scripts.pory"
	.string "It’ll help you reel in even more\n"
	.string "POKéMON! With it, you can fish in\l"
	.string "the waters and discover all sorts\l"
	.string "of amazing catches. Happy fishing!$"

VermillionCity_GoodRod_Text_4:
# 56 "data/maps/VermilionCity_House1/scripts.pory"
	.string "Oh? You don't know what you're\nmissing!\pThere's nothing more relaxing than\nfishing for POKéMON.$"
