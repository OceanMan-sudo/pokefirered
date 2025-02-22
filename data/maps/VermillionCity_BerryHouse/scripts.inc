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
	playmoncry SPECIES_NIDORAN_F, CRY_MODE_NORMAL
# 15 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	msgbox VermillionBerryHouse_Nidoran_Text_0
# 16 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	delay 40
# 17 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	release
	end


VermillionBerryHouse_Sailor::
# 22 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	lock
# 23 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	faceplayer
# 24 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	msgbox VermillionBerryHouse_Sailor_Text_0
# 25 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	release
	end


VermillionBerrySister::
# 30 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	lock
# 31 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	faceplayer
# 32 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	msgbox VermillionBerrySister_Text_0
# 33 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	waitmessage
# 34 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	pokemart VermillionBerryHouse_Mart
# 35 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	msgbox VermillionBerrySister_Text_1
# 36 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	release
	end


# 40 "data/maps/VermillionCity_BerryHouse/scripts.pory"

# 41 "data/maps/VermillionCity_BerryHouse/scripts.pory"
.align 2
# 42 "data/maps/VermillionCity_BerryHouse/scripts.pory"
VermillionBerryHouse_Mart::
# 43 "data/maps/VermillionCity_BerryHouse/scripts.pory"
    .2byte ITEM_FIGY_BERRY
# 44 "data/maps/VermillionCity_BerryHouse/scripts.pory"
    .2byte ITEM_WIKI_BERRY
# 45 "data/maps/VermillionCity_BerryHouse/scripts.pory"
    .2byte ITEM_MAGO_BERRY
# 46 "data/maps/VermillionCity_BerryHouse/scripts.pory"
    .2byte ITEM_AGUAV_BERRY
# 47 "data/maps/VermillionCity_BerryHouse/scripts.pory"
    .2byte ITEM_IAPAPA_BERRY
# 48 "data/maps/VermillionCity_BerryHouse/scripts.pory"
    .2byte ITEM_ORAN_BERRY
# 49 "data/maps/VermillionCity_BerryHouse/scripts.pory"
    .2byte ITEM_NONE
# 50 "data/maps/VermillionCity_BerryHouse/scripts.pory"
    release
# 51 "data/maps/VermillionCity_BerryHouse/scripts.pory"
    end

VermillionBerryHouse_LittleGirl_Text_0:
# 6 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	.string "I gave my POKéMON an IAPAPA BERRY\n"
	.string "to hold but it ended up getting\l"
	.string "confused after eating the berry!$"

VermillionBerryHouse_Nidoran_Text_0:
# 15 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	.string "Nido!$"

VermillionBerryHouse_Sailor_Text_0:
# 24 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	.string "Have you been onboard the S.S.\n"
	.string "ANNE? There are lots of tough\l"
	.string "trainers on the ship, so I make\l"
	.string "sure to stock up on berries just in\l"
	.string "case.$"

VermillionBerrySister_Text_0:
# 32 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	.string "Welcome to the VERMILION CITY BERRY\n"
	.string "HOUSE! How can I assist you?$"

VermillionBerrySister_Text_1:
# 35 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	.string "Please come again!$"
