ViridianCity_HouseOfNuzlocke_MapScripts::
	.byte 0


ViridianCity_GiveRareCandy::
# 4 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	goto_if_set FLAG_0x0AF, ViridianCity_GiveRareCandy_2
# 19 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	lock
# 20 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	faceplayer
# 21 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	msgbox ViridianCity_GiveRareCandy_Text_3, MSGBOX_YESNO
# 22 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	switch VAR_RESULT
# 23 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	case YES, ViridianCity_GiveRareCandy_5
# 29 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	case NO, ViridianCity_GiveRareCandy_6
	return

ViridianCity_GiveRareCandy_2:
# 5 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	lock
# 6 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	faceplayer
# 7 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	msgbox ViridianCity_GiveRareCandy_Text_0
# 8 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	checkitem ITEM_RARE_CANDY, 1
# 9 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq ViridianCity_GiveRareCandy_7
# 14 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	giveitem ITEM_RARE_CANDY, 99
# 15 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	msgbox ViridianCity_GiveRareCandy_Text_2
# 16 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	release
	end

ViridianCity_GiveRareCandy_5:
# 24 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	giveitem ITEM_RARE_CANDY, 99
# 25 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	msgbox ViridianCity_GiveRareCandy_Text_4
# 26 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	setflag FLAG_0x0AF
# 27 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	release
	end

ViridianCity_GiveRareCandy_6:
# 30 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	msgbox ViridianCity_GiveRareCandy_Text_5
# 31 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	release
	end

ViridianCity_GiveRareCandy_7:
# 10 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	msgbox ViridianCity_GiveRareCandy_Text_1, MSGBOX_NPC
# 11 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	release
	end


NuzlockeMeowth::
# 37 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	lock
# 38 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	faceplayer
# 39 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	msgbox NuzlockeMeowth_Text_0
# 40 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	playmoncry SPECIES_MEOWTH, CRY_MODE_NORMAL
# 41 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	delay 40
# 42 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	msgbox NuzlockeMeowth_Text_1
# 43 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	release
	end


ViridianCity_GiveRareCandy_Text_0:
# 7 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "Come back for more?$"

ViridianCity_GiveRareCandy_Text_1:
# 10 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "You still have candies left$"

ViridianCity_GiveRareCandy_Text_2:
# 15 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "Use them responsibly!$"

ViridianCity_GiveRareCandy_Text_3:
# 21 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "Grinding is such a pain,\nNuzlocke run or not.\pWho has time to catch a new\nPOKéMON, and train it and\lget it up to speed?\pChildren, that's who!\pAnd we aren't kids\nanymore!\pWe have jobs and responsibilites!\pI don't want to spend what\nlittle time I have training\la MEOWTH to use PAY DAY!\pSo how about I get rid of all\nthe grinding in your playthrough?\pWant to take these Rare Candies?\pI guess it sort of is cheating\nbut who cares?\pPlay the game your own\nway.\pWhat do you say?\pWould you like to take the Rare\nCandies?$"

ViridianCity_GiveRareCandy_Text_4:
# 25 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "Use them responsibly!\pWhile grinding is a pain\nso is removing any sort of\lchallenge.\pCome see me again if\nyou end up running out.$"

ViridianCity_GiveRareCandy_Text_5:
# 30 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "Suit yourself.$"

NuzlockeMeowth_Text_0:
# 39 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "I say you ain't trying if\nyou ain't cheating!\pI-I mean -$"

NuzlockeMeowth_Text_1:
# 42 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "NYAH!\p...Nevermind what I said earlier.$"
