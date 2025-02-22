VermillionCity_BerryHouse_MapScripts::
	.byte 0


VermillionBerrySister::
# 4 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	lock
# 5 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	faceplayer
# 6 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	msgbox VermillionBerrySister_Text_0
# 7 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	waitmessage
# 8 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	pokemart VermillionBerryHouse_Mart
# 9 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	msgbox VermillionBerrySister_Text_1
# 10 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	release
	end


# 14 "data/maps/VermillionCity_BerryHouse/scripts.pory"

# 15 "data/maps/VermillionCity_BerryHouse/scripts.pory"
.align 2
# 16 "data/maps/VermillionCity_BerryHouse/scripts.pory"
VermillionBerryHouse_Mart::
# 17 "data/maps/VermillionCity_BerryHouse/scripts.pory"
    .2byte ITEM_FIGY_BERRY
# 18 "data/maps/VermillionCity_BerryHouse/scripts.pory"
    .2byte ITEM_WIKI_BERRY
# 19 "data/maps/VermillionCity_BerryHouse/scripts.pory"
    .2byte ITEM_MAGO_BERRY
# 20 "data/maps/VermillionCity_BerryHouse/scripts.pory"
    .2byte ITEM_AGUAV_BERRY
# 21 "data/maps/VermillionCity_BerryHouse/scripts.pory"
    .2byte ITEM_IAPAPA_BERRY
# 22 "data/maps/VermillionCity_BerryHouse/scripts.pory"
    .2byte ITEM_ORAN_BERRY
# 23 "data/maps/VermillionCity_BerryHouse/scripts.pory"
    .2byte ITEM_NONE
# 24 "data/maps/VermillionCity_BerryHouse/scripts.pory"
    release
# 25 "data/maps/VermillionCity_BerryHouse/scripts.pory"
    end

VermillionBerrySister_Text_0:
# 6 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	.string "Welcome to the Vermillion City Berry\n"
	.string "House! How can I assist you?$"

VermillionBerrySister_Text_1:
# 9 "data/maps/VermillionCity_BerryHouse/scripts.pory"
	.string "Please come again!$"
