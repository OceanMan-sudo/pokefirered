VermillionCity_BerryHouse_MapScripts::
	.byte 0


VermillionBerryHouse_LittleGirl::
# 4 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	lock
# 5 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	faceplayer
# 6 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	msgbox VermillionBerryHouse_LittleGirl_Text_0
# 7 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	release
	end


VermillionBerryHouse_Nidoran::
# 12 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	lock
# 13 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	faceplayer
# 14 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	msgbox VermillionBerryHouse_Nidoran_Text_0
# 15 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	playmoncry SPECIES_NIDORAN_F, CRY_MODE_NORMAL
# 16 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	delay 40
# 17 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	release
	end


VermillionBerrySister::
# 22 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	lock
# 23 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	faceplayer
# 24 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	msgbox VermillionBerrySister_Text_0
# 25 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	waitmessage
# 26 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	pokemart VermillionBerryHouse_Mart
# 27 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	msgbox VermillionBerrySister_Text_1
# 28 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	release
	end


# 32 "data/maps/VermillionCity_BerryHouse/scripts.pory"

# 33 "data/maps/VermillionCity_BerryHouse/scripts.pory"
.align 2
# 34 "data/maps/VermillionCity_BerryHouse/scripts.pory"
VermillionBerryHouse_Mart::
# 35 "data/maps/VermillionCity_BerryHouse/scripts.pory"
    .2byte ITEM_FIGY_BERRY
# 36 "data/maps/VermillionCity_BerryHouse/scripts.pory"
    .2byte ITEM_WIKI_BERRY
# 37 "data/maps/VermillionCity_BerryHouse/scripts.pory"
    .2byte ITEM_MAGO_BERRY
# 38 "data/maps/VermillionCity_BerryHouse/scripts.pory"
    .2byte ITEM_AGUAV_BERRY
# 39 "data/maps/VermillionCity_BerryHouse/scripts.pory"
    .2byte ITEM_IAPAPA_BERRY
# 40 "data/maps/VermillionCity_BerryHouse/scripts.pory"
    .2byte ITEM_ORAN_BERRY
# 41 "data/maps/VermillionCity_BerryHouse/scripts.pory"
    .2byte ITEM_NONE
# 42 "data/maps/VermillionCity_BerryHouse/scripts.pory"
    release
# 43 "data/maps/VermillionCity_BerryHouse/scripts.pory"
    end

VermillionBerryHouse_LittleGirl_Text_0:
# 6 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	.string "I gave my POKéMON an IAPAPA BERRY\n"
	.string "to hold but it ended up getting\l"
	.string "confused after eating the berry!$"

VermillionBerryHouse_Nidoran_Text_0:
# 14 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	.string "Nido!$"

VermillionBerrySister_Text_0:
# 24 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	.string "Welcome to the VERMILION CITY BERRY\n"
	.string "HOUSE! How can I assist you?$"

VermillionBerrySister_Text_1:
# 27 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	.string "Please come again!$"
