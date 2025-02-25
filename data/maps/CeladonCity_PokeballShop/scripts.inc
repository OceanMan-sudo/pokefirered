CeladonCity_PokeballShop_MapScripts::
	.byte 0


PokeballGuy::
# 4 "data/maps/CeladonCity_PokeballShop/scripts.pory"
	lock
# 5 "data/maps/CeladonCity_PokeballShop/scripts.pory"
	faceplayer
# 6 "data/maps/CeladonCity_PokeballShop/scripts.pory"
	msgbox PokeballGuy_Text_0
# 7 "data/maps/CeladonCity_PokeballShop/scripts.pory"
	waitmessage
# 8 "data/maps/CeladonCity_PokeballShop/scripts.pory"
	pokemart PokeballShop
# 9 "data/maps/CeladonCity_PokeballShop/scripts.pory"
	msgbox PokeballGuy_Text_1
# 10 "data/maps/CeladonCity_PokeballShop/scripts.pory"
	release
	end


DiveBallGuy::
# 15 "data/maps/CeladonCity_PokeballShop/scripts.pory"
	lock
# 16 "data/maps/CeladonCity_PokeballShop/scripts.pory"
	faceplayer
# 17 "data/maps/CeladonCity_PokeballShop/scripts.pory"
	msgbox DiveBallGuy_Text_0
# 18 "data/maps/CeladonCity_PokeballShop/scripts.pory"
	release
	end


NetBallGuy::
# 23 "data/maps/CeladonCity_PokeballShop/scripts.pory"
	lock
# 24 "data/maps/CeladonCity_PokeballShop/scripts.pory"
	faceplayer
# 25 "data/maps/CeladonCity_PokeballShop/scripts.pory"
	msgbox NetBallGuy_Text_0
# 26 "data/maps/CeladonCity_PokeballShop/scripts.pory"
	release
	end


ClefairyPokeball::
# 31 "data/maps/CeladonCity_PokeballShop/scripts.pory"
	lock
# 32 "data/maps/CeladonCity_PokeballShop/scripts.pory"
	faceplayer
# 33 "data/maps/CeladonCity_PokeballShop/scripts.pory"
	playmoncry SPECIES_CLEFAIRY, CRY_MODE_NORMAL
# 34 "data/maps/CeladonCity_PokeballShop/scripts.pory"
	delay 40
# 35 "data/maps/CeladonCity_PokeballShop/scripts.pory"
	msgbox ClefairyPokeball_Text_0
# 36 "data/maps/CeladonCity_PokeballShop/scripts.pory"
	release
	end


# 40 "data/maps/CeladonCity_PokeballShop/scripts.pory"

# 41 "data/maps/CeladonCity_PokeballShop/scripts.pory"
    .align 2
# 42 "data/maps/CeladonCity_PokeballShop/scripts.pory"
PokeballShop::
# 43 "data/maps/CeladonCity_PokeballShop/scripts.pory"
    .2byte ITEM_POKE_BALL
# 44 "data/maps/CeladonCity_PokeballShop/scripts.pory"
    .2byte ITEM_GREAT_BALL
# 45 "data/maps/CeladonCity_PokeballShop/scripts.pory"
    .2byte ITEM_ULTRA_BALL
# 46 "data/maps/CeladonCity_PokeballShop/scripts.pory"
    .2byte ITEM_LUXURY_BALL
# 47 "data/maps/CeladonCity_PokeballShop/scripts.pory"
    .2byte ITEM_NEST_BALL
# 48 "data/maps/CeladonCity_PokeballShop/scripts.pory"
    .2byte ITEM_NET_BALL
# 49 "data/maps/CeladonCity_PokeballShop/scripts.pory"
    .2byte ITEM_DIVE_BALL
# 50 "data/maps/CeladonCity_PokeballShop/scripts.pory"
    .2byte ITEM_TIMER_BALL
# 51 "data/maps/CeladonCity_PokeballShop/scripts.pory"
    .2byte ITEM_REPEAT_BALL
# 52 "data/maps/CeladonCity_PokeballShop/scripts.pory"
    .2byte ITEM_NONE
# 53 "data/maps/CeladonCity_PokeballShop/scripts.pory"
    release
# 54 "data/maps/CeladonCity_PokeballShop/scripts.pory"
    end

PokeballGuy_Text_0:
# 6 "data/maps/CeladonCity_PokeballShop/scripts.pory"
	.string "Welcome to the POKéBALL SHOP. What\n"
	.string "can I get for you?$"

PokeballGuy_Text_1:
# 9 "data/maps/CeladonCity_PokeballShop/scripts.pory"
	.string "Happy catching!$"

DiveBallGuy_Text_0:
# 17 "data/maps/CeladonCity_PokeballShop/scripts.pory"
	.string "They sell all sorts of POKéBALLs\n"
	.string "here. They even sell the DIVE\l"
	.string "BALL, even though there are no\l"
	.string "diving spots in KANTO. I guess some\l"
	.string "people just like the aesthetic?$"

NetBallGuy_Text_0:
# 25 "data/maps/CeladonCity_PokeballShop/scripts.pory"
	.string "The NET BALL is great for catching\n"
	.string "BUG TYPE POKéMON!$"

ClefairyPokeball_Text_0:
# 35 "data/maps/CeladonCity_PokeballShop/scripts.pory"
	.string "CLEFF!$"
