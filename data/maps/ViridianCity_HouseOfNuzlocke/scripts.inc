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


MrNuzlocke::
# 48 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	lock
# 49 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	faceplayer
# 50 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	goto_if_set SYS_FLAGS + 0x2C, MrNuzlocke_1
# 52 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	goto_if_set FLAG_0x0B1, MrNuzlocke_2
# 57 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	goto_if_set SYS_FLAGS + 0x27, MrNuzlocke_7
MrNuzlocke_6:
# 64 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	goto_if_set FLAG_0x0B0, MrNuzlocke_4
# 69 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	msgbox MrNuzlocke_Text_5, MSGBOX_YESNO
# 70 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	switch VAR_RESULT
# 71 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	case YES, MrNuzlocke_14
# 78 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	case NO, MrNuzlocke_15
# 86 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	release
	end

MrNuzlocke_1:
# 51 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	msgbox MrNuzlocke_Text_0
	return

MrNuzlocke_2:
# 53 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	msgbox MrNuzlocke_Text_1
# 54 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	release
	end

MrNuzlocke_3:
# 58 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	msgbox MrNuzlocke_Text_2
# 59 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	giveitem ITEM_FOCUS_BAND, 1
# 60 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	msgbox MrNuzlocke_Text_3
# 61 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	setflag FLAG_0x0B1
# 62 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	release
	end

MrNuzlocke_4:
# 65 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	msgbox MrNuzlocke_Text_4
# 66 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	release
	end

MrNuzlocke_7:
# 57 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	goto_if_unset FLAG_0x0B1, MrNuzlocke_3
	goto MrNuzlocke_6

MrNuzlocke_14:
# 72 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	msgbox MrNuzlocke_Text_6
# 73 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	giveitem ITEM_TM10, 1
# 74 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	msgbox MrNuzlocke_Text_7
# 75 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	setflag FLAG_0x0B0
# 76 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	release
	end

MrNuzlocke_15:
# 79 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	msgbox MrNuzlocke_Text_8
# 80 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	giveitem ITEM_TM10, 1
# 81 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	setflag FLAG_0x0B0
# 82 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	msgbox MrNuzlocke_Text_9
# 83 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	release
	end


testguy::
# 92 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	lock
# 93 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	faceplayer
# 94 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	msgbox testguy_Text_0
# 95 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	release
	end


TheRules::
# 100 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	lock
# 101 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	msgbox TheRules_Text_0
# 102 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	release
	end


HardCoreNuzlocke::
# 107 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	lock
# 108 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	msgbox HardCoreNuzlocke_Text_0
# 109 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	release
	end


NewNuzlocker::
# 114 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	lock
# 115 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	faceplayer
# 116 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	msgbox NewNuzlocker_Text_0
# 117 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	release
	end


NewNuzlocker2::
# 122 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	lock
# 123 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	faceplayer
# 124 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	msgbox NewNuzlocker2_Text_0
# 125 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	release
	end


NuzlockePikachu::
# 130 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	lock
# 131 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	faceplayer
# 132 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
# 133 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	delay 40
# 134 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	msgbox NuzlockePikachu_Text_0
# 135 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	msgbox NuzlockePikachu_Text_1
# 136 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	release
	end


NuzlockeDoduo::
# 141 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	lock
# 142 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	faceplayer
# 143 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	playmoncry SPECIES_DODUO, CRY_MODE_NORMAL
# 144 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	delay 40
# 145 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	msgbox NuzlockeDoduo_Text_0
# 146 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	msgbox NuzlockeDoduo_Text_1
# 147 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	playmoncry SPECIES_DODUO, CRY_MODE_NORMAL
# 148 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	delay 40
# 149 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	release
	end


NuzlockeSign::
# 154 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	lock
# 155 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	faceplayer
# 156 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	msgbox NuzlockeSign_Text_0
# 157 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	release
	end


ViridianCity_GiveRareCandy_Text_0:
# 7 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "Come back for more?$"

ViridianCity_GiveRareCandy_Text_1:
# 10 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "You still have candies left...$"

ViridianCity_GiveRareCandy_Text_2:
# 15 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "Use them responsibly!$"

ViridianCity_GiveRareCandy_Text_3:
# 21 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "Grinding is such a pain,\nNuzlocke run or not.\pWho has time to catch a new\nPOKéMON, and train it and\lget it up to speed?\pChildren, that's who!\pAnd we aren't kids\nanymore!\pWe have jobs and responsibilites!\pI don't want to spend what\nlittle time I have training\la MEOWTH to use PAY DAY!\pSo how about I get rid of all\nthe grinding in your playthrough?\pWant to take these Rare Candies?\pI guess it sort of is cheating\nbut who cares?\pPlay the game your own\nway.\pWhat do you say?\pWould you like to take the Rare\nCandies?$"

ViridianCity_GiveRareCandy_Text_4:
# 25 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "Use them responsibly!\pWhile grinding is a pain,\nso is removing any sort of\lchallenge.\pCome see me again if\nyou end up running out.$"

ViridianCity_GiveRareCandy_Text_5:
# 30 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "Suit yourself.$"

NuzlockeMeowth_Text_0:
# 39 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "I say you ain't trying if\nyou ain't cheating!\pI-I mean -$"

NuzlockeMeowth_Text_1:
# 42 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "NYAH!\p...Nevermind what I said earlier.$"

MrNuzlocke_Text_0:
# 51 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "MR. NUZLOCKE: You've become strong!\n"
	.string "But, mark my words, I don't plan on\l"
	.string "retiring ever! Run along now, child!$"

MrNuzlocke_Text_1:
# 53 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "MR. NUZLOCKE: Go forth! And let the\n"
	.string "spirit of Nuzlocke guide you to the\l"
	.string "top!$"

MrNuzlocke_Text_2:
# 58 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "MR. NUZLOCKE: Incredible! All the\n"
	.string "badges of the region are yours.\l"
	.string "You've proven your strength,\l"
	.string "resilience, and mastery! As a token\l"
	.string "of the Illustrious House of\l"
	.string "Nuzlocke, take this Focus Band. It\l"
	.string "might just save a run when all\l"
	.string "hope seems lost.$"

MrNuzlocke_Text_3:
# 60 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "Go forth, adventurer! And let the\n"
	.string "spirit of Nuzlocke guide you to the\l"
	.string "top!$"

MrNuzlocke_Text_4:
# 65 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "MR. NUZLOCKE: The Illustrious House\n"
	.string "of Nuzlocke will always stand as a\l"
	.string "bastion for any brave soul who\l"
	.string "dares the dare the challenge.\l"
	.string "Return to me when you've collected\l"
	.string "all the badges of this region.\l"
	.string "There may be something even\l"
	.string "grander waiting for you at the end\l"
	.string "of your journey!$"

MrNuzlocke_Text_5:
# 69 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "MR. NUZLOCKE: Ah, a new face!\n"
	.string "Welcome to the world of Nuzlocke!\l"
	.string "There's a certain magic in it you\l"
	.string "see... Each encounter, each battle,\l"
	.string "each victory, every fainted\l"
	.string "POKéMON - it all has weight,\l"
	.string "consequence! It's not just a\l"
	.string "challenge, it's a journey of\l"
	.string "bonding, loss, and triumph. Why, in\l"
	.string "a Nuzlocke, every POKéMON you\l"
	.string "catch is a friend you cherish -\l"
	.string "until fate decides to take them\l"
	.string "away... But that's the beauty in it!\l"
	.string "The uncertainty, the\l"
	.string "bittersweetness. It makes every\l"
	.string "victory all the more special! So,\l"
	.string "are you ready to embrace the\l"
	.string "adventure with no regrets?$"

MrNuzlocke_Text_6:
# 72 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "Excellent! I knew you'd understand.\n"
	.string "The thrill of a true Nuzlocke\l"
	.string "adventurer runs deep in you! To\l"
	.string "honor your commitment to the\l"
	.string "journey, take this - a token of the\l"
	.string "House of Nuzlocke.$"

MrNuzlocke_Text_7:
# 74 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "Remember, it's not the strength of\n"
	.string "the move that matters most - it's\l"
	.string "the bond with the POKéMON who\l"
	.string "wields it! Now, go forth! Your\l"
	.string "Nuzlocke adventure awaits!$"

MrNuzlocke_Text_8:
# 79 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "Oh, I see... Perhaps the Nuzlocke\n"
	.string "journey isn't for everyone. But\l"
	.string "that's alright! Take this anyways.$"

MrNuzlocke_Text_9:
# 82 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "TM10 contains Hidden Power. It's a\n"
	.string "fitting move, don't you\n"
	.string "think? Just like in life, its true\l"
	.string "nature is a mystery until you dig a\l"
	.string "little deeper. Even if you are not\l"
	.string "on a\n"
	.string "Nuzlocke journey, know that the\l"
	.string "illustrious House of Nuzlocke will\l"
	.string "always welcome any adventurer!$"

testguy_Text_0:
# 94 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "I once beat a Gym Leader with\n"
	.string "nothing but an ELECTRODE, the move\l"
	.string "Explosion, and a ballpoint pen.$"

TheRules_Text_0:
# 101 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "There are two and only two rules for\n"
	.string "a standard Nuzlocke run. The First\l"
	.string "Rule: You can only obtain the first\l"
	.string "POKéMON encountered in each area\l"
	.string "and nothing else. The Second Rule:\l"
	.string "If a POKéMON faints, you cannot use\l"
	.string "it again for the rest of the run.\l"
	.string "Some trainers release these POKéMON\l"
	.string "but those trainers are absolute\l"
	.string "degenerates. Please put them in the\l"
	.string "box until you beat the game. And,\l"
	.string "of course, the Third Rule: You must\l"
	.string "nickname every POKéMON!$"

HardCoreNuzlocke_Text_0:
# 108 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "A variant of the standard Nuzlocke is\n"
	.string "the Hardcore Nuzlocke playthrough.\l"
	.string "Under these rules, the battle style\l"
	.string "must be SET and not SHIFT, you\l"
	.string "cannot use items in battle aside\l"
	.string "from held items, and you cannot\l"
	.string "level your POKéMON past the\l"
	.string "highest level of the next Gym\l"
	.string "Leader or Champion. For instance,\l"
	.string "BROCK's ONIX is Level 14. Your\l"
	.string "POKéMON cannot exceed that level\l"
	.string "until you have defeated BROCK.\l"
	.string "These are the rules of the\l"
	.string "Hardcore Nuzlocke.$"

NewNuzlocker_Text_0:
# 116 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "My favorite part about Nuzlocke\n"
	.string "playthroughs is using POKéMON that\l"
	.string "don't usually get noticed. I never\l"
	.string "thought I'd be using a DODUO during\l"
	.string "my run through KANTO but it has\l"
	.string "quickly grown into my ace POKéMON!$"

NewNuzlocker2_Text_0:
# 124 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "At first, I was hesitant to try a\n"
	.string "Nuzlocke run. But now I can't\l"
	.string "imagine playing POKéMON any other\l"
	.string "way!$"

NuzlockePikachu_Text_0:
# 134 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "PIKA!$"

NuzlockePikachu_Text_1:
# 135 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "It's MR. NUZLOCKE's own PIKACHU. It\n"
	.string "seems to be MR. NUZLOCKE's starter\l"
	.string "POKéMON.$"

NuzlockeDoduo_Text_0:
# 145 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "DO-DO!$"

NuzlockeDoduo_Text_1:
# 146 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "This DODUO has seen things you\n"
	.string "people wouldn't believe... Attack\l"
	.string "ships on fire off the shoulder of\l"
	.string "CINNABAR. This DODUO has watched\l"
	.string "Hyper Beams glitter in the dark\l"
	.string "near Saffron City's gates. All those\l"
	.string "precious moments will be lost in\l"
	.string "time like tears in the rain.$"

NuzlockeSign_Text_0:
# 156 "data/maps/ViridianCity_HouseOfNuzlocke/scripts.pory"
	.string "Remember, this is all happening for a\n"
	.string "reason!$"
