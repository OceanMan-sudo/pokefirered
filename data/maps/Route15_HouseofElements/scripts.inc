Route15_HouseofElements_MapScripts::
	.byte 0


IcePunchMan::
# 3 "data/maps/Route15_HouseofElements/scripts.pory"
	lock
# 4 "data/maps/Route15_HouseofElements/scripts.pory"
	faceplayer
# 6 "data/maps/Route15_HouseofElements/scripts.pory"
	msgbox IcePunchMan_Text_0, MSGBOX_YESNO
# 7 "data/maps/Route15_HouseofElements/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq IcePunchMan_2
IcePunchMan_1:
# 11 "data/maps/Route15_HouseofElements/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq IcePunchMan_5
IcePunchMan_4:
# 15 "data/maps/Route15_HouseofElements/scripts.pory"
	msgbox IcePunchMan_Text_1
# 16 "data/maps/Route15_HouseofElements/scripts.pory"
	setvar VAR_0x8005, MOVETUTOR_ICE_PUNCH
# 17 "data/maps/Route15_HouseofElements/scripts.pory"
	call EventScript_ChooseMoveTutorMon
# 18 "data/maps/Route15_HouseofElements/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq IcePunchMan_8
IcePunchMan_7:
# 22 "data/maps/Route15_HouseofElements/scripts.pory"
	goto EventScript_IcePunchTaught
	end

IcePunchMan_2:
# 8 "data/maps/Route15_HouseofElements/scripts.pory"
	goto EventScript_IcePunchDeclined
	goto IcePunchMan_1

IcePunchMan_5:
# 12 "data/maps/Route15_HouseofElements/scripts.pory"
	goto EventScript_IcePunchDeclined
	goto IcePunchMan_4

IcePunchMan_8:
# 19 "data/maps/Route15_HouseofElements/scripts.pory"
	goto EventScript_IcePunchDeclined
	goto IcePunchMan_7


EventScript_IcePunchDeclined::
# 27 "data/maps/Route15_HouseofElements/scripts.pory"
	msgbox EventScript_IcePunchDeclined_Text_0
# 28 "data/maps/Route15_HouseofElements/scripts.pory"
	release
	end


EventScript_IcePunchTaught::
# 33 "data/maps/Route15_HouseofElements/scripts.pory"
	msgbox EventScript_IcePunchTaught_Text_0
# 34 "data/maps/Route15_HouseofElements/scripts.pory"
	release
	end


IcePunchMan_Text_0:
# 6 "data/maps/Route15_HouseofElements/scripts.pory"
	.string "The elements speak to me! They tell\n"
	.string "me ice is the most formidable. To\l"
	.string "prove the superiority of ice, allow\l"
	.string "me to teach one of your POKéMON\l"
	.string "ICE PUNCH!$"

IcePunchMan_Text_1:
# 15 "data/maps/Route15_HouseofElements/scripts.pory"
	.string "Excellent choice! Which POKéMON\n"
	.string "shall I teach?$"

EventScript_IcePunchDeclined_Text_0:
# 27 "data/maps/Route15_HouseofElements/scripts.pory"
	.string "Very well! Return here when you wish\n"
	.string "to embrace the elements!$"

EventScript_IcePunchTaught_Text_0:
# 33 "data/maps/Route15_HouseofElements/scripts.pory"
	.string "Use this move well. It was passed\n"
	.string "down to me from the masters of the\l"
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}LIN KUEI TEMPLE.$"
