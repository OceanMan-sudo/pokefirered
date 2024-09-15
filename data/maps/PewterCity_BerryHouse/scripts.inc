PewterCity_BerryHouse_MapScripts::
	.byte 0


StockingUp::
# 3 "data/maps/PewterCity_BerryHouse/scripts.pory"
	lock
# 4 "data/maps/PewterCity_BerryHouse/scripts.pory"
	faceplayer
# 5 "data/maps/PewterCity_BerryHouse/scripts.pory"
	msgbox StockingUp_Text_0
# 6 "data/maps/PewterCity_BerryHouse/scripts.pory"
	release
	end


PewterKantoBerries::
# 11 "data/maps/PewterCity_BerryHouse/scripts.pory"
	lock
# 12 "data/maps/PewterCity_BerryHouse/scripts.pory"
	faceplayer
# 13 "data/maps/PewterCity_BerryHouse/scripts.pory"
	msgbox PewterKantoBerries_Text_0
# 14 "data/maps/PewterCity_BerryHouse/scripts.pory"
	release
	end


PewterBerrySister::
# 19 "data/maps/PewterCity_BerryHouse/scripts.pory"
	lock
# 20 "data/maps/PewterCity_BerryHouse/scripts.pory"
	faceplayer
# 21 "data/maps/PewterCity_BerryHouse/scripts.pory"
	msgbox PewterBerrySister_Text_0
# 22 "data/maps/PewterCity_BerryHouse/scripts.pory"
	waitmessage
# 23 "data/maps/PewterCity_BerryHouse/scripts.pory"
	pokemart PewterBerryHouse_Mart
# 24 "data/maps/PewterCity_BerryHouse/scripts.pory"
	msgbox PewterBerrySister_Text_1
# 25 "data/maps/PewterCity_BerryHouse/scripts.pory"
	release
	end


# 29 "data/maps/PewterCity_BerryHouse/scripts.pory"

# 30 "data/maps/PewterCity_BerryHouse/scripts.pory"
.align 2
# 31 "data/maps/PewterCity_BerryHouse/scripts.pory"
PewterBerryHouse_Mart::
# 32 "data/maps/PewterCity_BerryHouse/scripts.pory"
    .2byte ITEM_CHERI_BERRY
# 33 "data/maps/PewterCity_BerryHouse/scripts.pory"
    .2byte ITEM_CHESTO_BERRY
# 34 "data/maps/PewterCity_BerryHouse/scripts.pory"
    .2byte ITEM_PECHA_BERRY
# 35 "data/maps/PewterCity_BerryHouse/scripts.pory"
    .2byte ITEM_RAWST_BERRY
# 36 "data/maps/PewterCity_BerryHouse/scripts.pory"
    .2byte ITEM_ASPEAR_BERRY
# 37 "data/maps/PewterCity_BerryHouse/scripts.pory"
    .2byte ITEM_LEPPA_BERRY
# 38 "data/maps/PewterCity_BerryHouse/scripts.pory"
    .2byte ITEM_ORAN_BERRY
# 39 "data/maps/PewterCity_BerryHouse/scripts.pory"
    .2byte ITEM_PERSIM_BERRY
# 40 "data/maps/PewterCity_BerryHouse/scripts.pory"
    .2byte ITEM_NONE
# 41 "data/maps/PewterCity_BerryHouse/scripts.pory"
    release
# 42 "data/maps/PewterCity_BerryHouse/scripts.pory"
    end

StockingUp_Text_0:
# 5 "data/maps/PewterCity_BerryHouse/scripts.pory"
	.string "I'm stocking up on PECHA and PERSIM\n"
	.string "BERRIES before my hike through MT.\l"
	.string "MOON. I don't want to poisoned or\l"
	.string "confused by the wild ZUBAT!$"

PewterKantoBerries_Text_0:
# 13 "data/maps/PewterCity_BerryHouse/scripts.pory"
	.string "Berries don't grow as well in KANTO\n"
	.string "as they do in other regions.\l"
	.string "Luckily the Berry Sisters have\l"
	.string "opened up shop in a few areas to\l"
	.string "sell all sorts of berries.$"

PewterBerrySister_Text_0:
# 21 "data/maps/PewterCity_BerryHouse/scripts.pory"
	.string "Welcome to the Pewter City Berry\n"
	.string "House! How can I assist you?$"

PewterBerrySister_Text_1:
# 24 "data/maps/PewterCity_BerryHouse/scripts.pory"
	.string "Please come again!$"
