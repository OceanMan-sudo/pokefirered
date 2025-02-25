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


Tester::
# 33 "data/maps/Route2/scripts.pory"
	checktrainerflag TRAINER_PICNICKER_SALLY
	goto_if 1, Tester_1
# 43 "data/maps/Route2/scripts.pory"
	lock
# 44 "data/maps/Route2/scripts.pory"
	faceplayer
# 45 "data/maps/Route2/scripts.pory"
	msgbox Tester_Text_1
# 46 "data/maps/Route2/scripts.pory"
	release
	end

Tester_1:
# 35 "data/maps/Route2/scripts.pory"
	lock
# 36 "data/maps/Route2/scripts.pory"
	faceplayer
# 37 "data/maps/Route2/scripts.pory"
	msgbox Tester_Text_0
# 38 "data/maps/Route2/scripts.pory"
	release
	end


Tester_Text_0:
# 37 "data/maps/Route2/scripts.pory"
	.string "Got em$"

Tester_Text_1:
# 45 "data/maps/Route2/scripts.pory"
	.string "Kick her butt$"

PicnickerSallyIntro::
# 20 "data/maps/Route2/scripts.pory"
	.string "I'll be your first opponent!$"

PicnickerSallyDefeated::
# 24 "data/maps/Route2/scripts.pory"
	.string "One trainer down, many more to go!$"

PicnickerSallyPostBattle::
# 28 "data/maps/Route2/scripts.pory"
	.string "I'd stock up on ANTIDOTEs \nbefore heading into VIRIDIAN\lFOREST if I were you.$"
