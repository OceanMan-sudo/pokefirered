# 1 "data/maps/Route15/scripts.pory"
Route15_MapScripts::
# 2 "data/maps/Route15/scripts.pory"
	.byte 0
# 3 "data/maps/Route15/scripts.pory"

# 4 "data/maps/Route15/scripts.pory"
Route15_EventScript_RouteSign::
# 5 "data/maps/Route15/scripts.pory"
	msgbox Route15_Text_RouteSign, MSGBOX_SIGN
# 6 "data/maps/Route15/scripts.pory"
	end

ElementHouse::
# 9 "data/maps/Route15/scripts.pory"
	lock
# 10 "data/maps/Route15/scripts.pory"
	faceplayer
# 11 "data/maps/Route15/scripts.pory"
	msgbox ElementHouse_Text_0
# 12 "data/maps/Route15/scripts.pory"
	release
	end


BattleGirlElements::
# 17 "data/maps/Route15/scripts.pory"
	lock
# 18 "data/maps/Route15/scripts.pory"
	faceplayer
# 19 "data/maps/Route15/scripts.pory"
	msgbox BattleGirlElements_Text_0
# 20 "data/maps/Route15/scripts.pory"
	release
	end


ElementHouse_Text_0:
# 11 "data/maps/Route15/scripts.pory"
	.string "The House of Elements$"

BattleGirlElements_Text_0:
# 19 "data/maps/Route15/scripts.pory"
	.string "The blackbelts in this house are\n"
	.string "practitioners of the elemental\l"
	.string "punches. They taught my MANKEY the\l"
	.string "move THUNDERPUNCH!$"
