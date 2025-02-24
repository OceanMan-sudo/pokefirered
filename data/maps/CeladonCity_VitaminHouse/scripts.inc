CeladonCity_VitaminHouse_MapScripts::
	.byte 0


VitaminHouseMan::
# 4 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	lock
# 5 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	faceplayer
# 6 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	msgbox VitaminHouseMan_Text_0
# 7 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	release
	end


EffortValuesTrainer::
# 12 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	lock
# 13 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	faceplayer
# 14 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	msgbox EffortValuesTrainer_Text_0
# 15 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	release
	end


EffortValuesTrainer2::
# 20 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	lock
# 21 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	faceplayer
# 22 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	msgbox EffortValuesTrainer2_Text_0
# 23 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	release
	end


CasualPlayer::
# 28 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	lock
# 29 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	faceplayer
# 30 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	msgbox CasualPlayer_Text_0
# 31 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	release
	end


SeriousPlayer::
# 36 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	lock
# 37 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	faceplayer
# 38 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	msgbox SeriousPlayer_Text_0
# 39 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	release
	end


Pidgeot::
# 44 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	lock
# 45 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	faceplayer
# 46 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	playmoncry SPECIES_PIDGEOT, CRY_MODE_NORMAL
# 47 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	msgbox Pidgeot_Text_0
# 48 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	delay 40
# 49 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	release
	return


MachoBrace::
# 54 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	goto_if_unset FLAG_0x0B2, MachoBrace_1
# 65 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	lock
# 66 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	faceplayer
# 67 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	msgbox MachoBrace_Text_2
# 68 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	release
	end

MachoBrace_1:
# 55 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	lock
# 56 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	faceplayer
# 57 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	msgbox MachoBrace_Text_0
# 58 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	giveitem ITEM_MACHO_BRACE
# 59 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	setflag FLAG_0x0B2
# 60 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	msgbox MachoBrace_Text_1
# 61 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	release
	end


BerryEnjoyer::
# 74 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	lock
# 75 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	faceplayer
# 76 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	msgbox BerryEnjoyer_Text_0
# 77 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	release
	end


VitaminSuperNerd::
# 82 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	lock
# 83 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	faceplayer
# 84 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	msgbox VitaminSuperNerd_Text_0
# 85 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	release
	end


VitaminFella::
# 90 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	lock
# 91 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	faceplayer
# 92 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	msgbox VitaminFella_Text_0
# 93 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	release
	end


CeladonBerrySeller::
# 98 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	lock
# 99 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	faceplayer
# 100 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	msgbox CeladonBerrySeller_Text_0
# 101 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	waitmessage
# 102 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	pokemart CeladonBerryStore
# 103 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	msgbox CeladonBerrySeller_Text_1
# 104 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	release
	end


CeladonVitaminSeller::
# 109 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	lock
# 110 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	faceplayer
# 111 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	msgbox CeladonBerrySeller_Text_0
# 112 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	waitmessage
# 113 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	pokemart CeladonVitaminStore
# 114 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	msgbox CeladonBerrySeller_Text_1
# 115 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	release
	end


# 119 "data/maps/CeladonCity_VitaminHouse/scripts.pory"

# 120 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
.align 2
# 121 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
CeladonBerryStore::
# 122 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
    .2byte ITEM_MOOMOO_MILK
# 123 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
    .2byte ITEM_LAVA_COOKIE
# 124 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
    .2byte ITEM_BERRY_JUICE
# 125 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
    .2byte ITEM_NONE
# 126 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
    release
# 127 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
    end
# 128 "data/maps/CeladonCity_VitaminHouse/scripts.pory"

# 129 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
    .align 2
# 130 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
CeladonVitaminStore::
# 131 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
    .2byte ITEM_HP_UP
# 132 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
    .2byte ITEM_PROTEIN
# 133 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
    .2byte ITEM_IRON
# 134 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
    .2byte ITEM_CARBOS
# 135 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
    .2byte ITEM_CALCIUM
# 136 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
    .2byte ITEM_ZINC
# 137 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
    .2byte ITEM_PP_UP
# 138 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
    .2byte ITEM_PP_MAX
# 139 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
    .2byte ITEM_NONE
# 140 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
    release
# 141 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
    end

VitaminHouseMan_Text_0:
# 6 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	.string "This place is your one-stop shop for\n"
	.string "anything related to POKéMON\l"
	.string "nutrition and Effort Values. It's\l"
	.string "very convenient!$"

EffortValuesTrainer_Text_0:
# 14 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	.string "The Effort Values of a POKéMON\n"
	.string "determine a how high their stats\l"
	.string "will be. For instance, a POKéMON\l"
	.string "that has maxed out it's Attack EVs\l"
	.string "will have a much more powerful\l"
	.string "physical attack when compared to a\l"
	.string "POKéMON that focused on another\l"
	.string "stat. Taking the time to think about\l"
	.string "how you'd like to invest in your\l"
	.string "POKéMON's Effort Values will help\l"
	.string "your team outshine others.$"

EffortValuesTrainer2_Text_0:
# 22 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	.string "Training isn’t just about leveling up.\n"
	.string "How you battle shapes your\l"
	.string "POKéMON's true potential! Defeating\l"
	.string "certain POKéMON makes your own\l"
	.string "grow stronger in different ways. A\l"
	.string "well-trained team isn’t just strong,\l"
	.string "it’s specialized.$"

CasualPlayer_Text_0:
# 30 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	.string "I don't pay attention to things like\n"
	.string "Effort Values and Individual\l"
	.string "Values. I just like to train my\l"
	.string "POKéMON in a way that's fun for\l"
	.string "both of us!$"

SeriousPlayer_Text_0:
# 38 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	.string "I make sure all of my POKéMON are\n"
	.string "raised right by using VITAMINS. My\l"
	.string "friend on the other hand takes a\l"
	.string "much more casual approach.$"

Pidgeot_Text_0:
# 47 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	.string "PIDG-PIDGO!$"

MachoBrace_Text_0:
# 57 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	.string "Training a POKéMON to reach its full\n"
	.string "potential takes time. Every battle\l"
	.string "shapes how it grows, but the\l"
	.string "process can be slow. A MACHO BRACE\l"
	.string "will help speed things up, doubling\l"
	.string "the effort your POKéMON puts into\l"
	.string "getting stronger. Here, you can\l"
	.string "have my spare one!$"

MachoBrace_Text_1:
# 60 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	.string "That should help speed up the\n"
	.string "process. Keep in mind that it'll\l"
	.string "slow down your POKéMON when\l"
	.string "wearing it in battle.$"

MachoBrace_Text_2:
# 67 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	.string "I've heard they're trying to import\n"
	.string "this special type of POWER ITEM\l"
	.string "from other regions so they can sell\l"
	.string "it here in this shop. It sounds like\l"
	.string "its taking a lot of effort to import\l"
	.string "those items at the moment...$"

BerryEnjoyer_Text_0:
# 76 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	.string "I don't know much about Effort\n"
	.string "Values. All I know is that feeding\l"
	.string "my POKéMON the drinks they sell\l"
	.string "here makes them happier and that's\l"
	.string "enough for me!$"

VitaminSuperNerd_Text_0:
# 84 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	.string "Effort Values are really important,\n"
	.string "but if you're not playing\l"
	.string "competitively or running a Nuzlocke\l"
	.string "then I wouldn't worry about it too\l"
	.string "much.$"

VitaminFella_Text_0:
# 92 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	.string "There's no limit to the amount of\n"
	.string "VITAMINS you can give your\l"
	.string "POKéMON. If you wanted to max out\l"
	.string "their HP stat using only VITAMINS,\l"
	.string "you're free to do so, though I feel\l"
	.string "like that takes the fun out it.$"

CeladonBerrySeller_Text_0:
# 100 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	.string "Welcome to CELADON NUTRITION. What\n"
	.string "can I get for you?$"

CeladonBerrySeller_Text_1:
# 103 "data/maps/CeladonCity_VitaminHouse/scripts.pory"
	.string "Come back anytime!$"
