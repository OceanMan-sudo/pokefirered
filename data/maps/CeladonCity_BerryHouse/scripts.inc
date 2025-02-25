CeladonCity_BerryHouse_MapScripts::
	.byte 0


CeladonBerrySister::
# 4 "data/maps/CeladonCity_BerryHouse/scripts.pory"
	lock
# 5 "data/maps/CeladonCity_BerryHouse/scripts.pory"
	faceplayer
# 6 "data/maps/CeladonCity_BerryHouse/scripts.pory"
	msgbox CeladonBerrySister_Text_0
# 7 "data/maps/CeladonCity_BerryHouse/scripts.pory"
	waitmessage
# 8 "data/maps/CeladonCity_BerryHouse/scripts.pory"
	pokemart CeladonBerryHouse_Mart
# 9 "data/maps/CeladonCity_BerryHouse/scripts.pory"
	msgbox CeladonBerrySister_Text_1
# 10 "data/maps/CeladonCity_BerryHouse/scripts.pory"
	release
	end


BerryCustomer::
# 15 "data/maps/CeladonCity_BerryHouse/scripts.pory"
	lock
# 16 "data/maps/CeladonCity_BerryHouse/scripts.pory"
	faceplayer
# 17 "data/maps/CeladonCity_BerryHouse/scripts.pory"
	msgbox BerryCustomer_Text_0
# 18 "data/maps/CeladonCity_BerryHouse/scripts.pory"
	release
	end


EnigmaFan::
# 23 "data/maps/CeladonCity_BerryHouse/scripts.pory"
	lock
# 24 "data/maps/CeladonCity_BerryHouse/scripts.pory"
	faceplayer
# 25 "data/maps/CeladonCity_BerryHouse/scripts.pory"
	msgbox EnigmaFan_Text_0
# 26 "data/maps/CeladonCity_BerryHouse/scripts.pory"
	release
	end


ErikaFan::
# 31 "data/maps/CeladonCity_BerryHouse/scripts.pory"
	lock
# 32 "data/maps/CeladonCity_BerryHouse/scripts.pory"
	faceplayer
# 33 "data/maps/CeladonCity_BerryHouse/scripts.pory"
	msgbox ErikaFan_Text_0
# 34 "data/maps/CeladonCity_BerryHouse/scripts.pory"
	release
	end


# 38 "data/maps/CeladonCity_BerryHouse/scripts.pory"

# 39 "data/maps/CeladonCity_BerryHouse/scripts.pory"
.align 2
# 40 "data/maps/CeladonCity_BerryHouse/scripts.pory"
CeladonBerryHouse_Mart::
# 41 "data/maps/CeladonCity_BerryHouse/scripts.pory"
    .2byte ITEM_SITRUS_BERRY
# 42 "data/maps/CeladonCity_BerryHouse/scripts.pory"
    .2byte ITEM_LUM_BERRY
# 43 "data/maps/CeladonCity_BerryHouse/scripts.pory"
    .2byte ITEM_ENIGMA_BERRY
# 44 "data/maps/CeladonCity_BerryHouse/scripts.pory"
    .2byte ITEM_LEPPA_BERRY
# 45 "data/maps/CeladonCity_BerryHouse/scripts.pory"
    .2byte ITEM_NONE
# 46 "data/maps/CeladonCity_BerryHouse/scripts.pory"
    release
# 47 "data/maps/CeladonCity_BerryHouse/scripts.pory"
    end

CeladonBerrySister_Text_0:
# 6 "data/maps/CeladonCity_BerryHouse/scripts.pory"
	.string "Welcome to the CELADON CITY BERRY\n"
	.string "HOUSE! How can I assist you?$"

CeladonBerrySister_Text_1:
# 9 "data/maps/CeladonCity_BerryHouse/scripts.pory"
	.string "Please come again!$"

BerryCustomer_Text_0:
# 17 "data/maps/CeladonCity_BerryHouse/scripts.pory"
	.string "The prices are higher when compared\n"
	.string "to other regions but that's because\l"
	.string "KANTO doesn't naturally grow these\l"
	.string "types of BERRIES. We just didn't\l"
	.string "have that sort of agricultural\l"
	.string "know-how back in 1996 I guess.$"

EnigmaFan_Text_0:
# 25 "data/maps/CeladonCity_BerryHouse/scripts.pory"
	.string "They sell ENIGMA BERRIES here! Do\n"
	.string "you know how hard it is to get a\l"
	.string "hold of an ENIGMA BERRY elsewhere?\l"
	.string "It's very, very hard!$"

ErikaFan_Text_0:
# 33 "data/maps/CeladonCity_BerryHouse/scripts.pory"
	.string "The GYM LEADER ERIKA does a lot to\n"
	.string "promote the new BERRY HOUSES\l"
	.string "located across KANTO. You can\l"
	.string "count on her POKéMON holding some\l"
	.string "of the BERRIES they sell at this\l"
	.string "store.$"
