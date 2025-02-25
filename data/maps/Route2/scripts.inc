# 1 "data/maps/Route2/scripts.pory"
 Route2_MapScripts::
# 2 "data/maps/Route2/scripts.pory"
	.byte 0
# 3 "data/maps/Route2/scripts.pory"

# 4 "data/maps/Route2/scripts.pory"
Route2_EventScript_RouteSign::
# 5 "data/maps/Route2/scripts.pory"
	msgbox Route2_Text_RouteSign, MSGBOX_SIGN
# 6 "data/maps/Route2/scripts.pory"
	end
# 7 "data/maps/Route2/scripts.pory"

# 8 "data/maps/Route2/scripts.pory"
Route2_EventScript_DiglettsCaveSign::
# 9 "data/maps/Route2/scripts.pory"
	msgbox Route2_Text_DiglettsCave, MSGBOX_SIGN
# 10 "data/maps/Route2/scripts.pory"
	end

PicnickerSally::
# 14 "data/maps/Route2/scripts.pory"
	trainerbattle_single TRAINER_PICNICKER_SALLY, PicnickerSallyIntro, PicnickerSallyDefeated
# 15 "data/maps/Route2/scripts.pory"
	msgbox PicnickerSallyPostBattle, MSGBOX_AUTOCLOSE
# 16 "data/maps/Route2/scripts.pory"
	waitmessage
	end


PicnickerSallyIntro::
# 20 "data/maps/Route2/scripts.pory"
	.string "Good luck$"

PicnickerSallyDefeated::
# 24 "data/maps/Route2/scripts.pory"
	.string "Nice job$"

PicnickerSallyPostBattle::
# 28 "data/maps/Route2/scripts.pory"
	.string "Got me!$"
