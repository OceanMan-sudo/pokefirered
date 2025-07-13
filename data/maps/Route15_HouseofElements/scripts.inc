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


FirePunchMan::
# 39 "data/maps/Route15_HouseofElements/scripts.pory"
	lock
# 40 "data/maps/Route15_HouseofElements/scripts.pory"
	faceplayer
# 42 "data/maps/Route15_HouseofElements/scripts.pory"
	msgbox FirePunchMan_Text_0, MSGBOX_YESNO
# 43 "data/maps/Route15_HouseofElements/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq FirePunchMan_2
FirePunchMan_1:
# 47 "data/maps/Route15_HouseofElements/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq FirePunchMan_5
FirePunchMan_4:
# 51 "data/maps/Route15_HouseofElements/scripts.pory"
	msgbox IcePunchMan_Text_1
# 52 "data/maps/Route15_HouseofElements/scripts.pory"
	setvar VAR_0x8005, MOVETUTOR_FIRE_PUNCH
# 53 "data/maps/Route15_HouseofElements/scripts.pory"
	call EventScript_ChooseMoveTutorMon
# 54 "data/maps/Route15_HouseofElements/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq FirePunchMan_8
FirePunchMan_7:
# 58 "data/maps/Route15_HouseofElements/scripts.pory"
	goto EventScript_FirePunchTaught
	end

FirePunchMan_2:
# 44 "data/maps/Route15_HouseofElements/scripts.pory"
	goto EventScript_IcePunchDeclined
	goto FirePunchMan_1

FirePunchMan_5:
# 48 "data/maps/Route15_HouseofElements/scripts.pory"
	goto EventScript_IcePunchDeclined
	goto FirePunchMan_4

FirePunchMan_8:
# 55 "data/maps/Route15_HouseofElements/scripts.pory"
	goto EventScript_IcePunchDeclined
	goto FirePunchMan_7


EventScript_FirePunchTaught::
# 63 "data/maps/Route15_HouseofElements/scripts.pory"
	msgbox EventScript_FirePunchTaught_Text_0
# 64 "data/maps/Route15_HouseofElements/scripts.pory"
	release
	end


ThunderPunchMan::
# 69 "data/maps/Route15_HouseofElements/scripts.pory"
	lock
# 70 "data/maps/Route15_HouseofElements/scripts.pory"
	faceplayer
# 72 "data/maps/Route15_HouseofElements/scripts.pory"
	msgbox ThunderPunchMan_Text_0, MSGBOX_YESNO
# 73 "data/maps/Route15_HouseofElements/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ThunderPunchMan_2
ThunderPunchMan_1:
# 77 "data/maps/Route15_HouseofElements/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ThunderPunchMan_5
ThunderPunchMan_4:
# 81 "data/maps/Route15_HouseofElements/scripts.pory"
	msgbox IcePunchMan_Text_1
# 82 "data/maps/Route15_HouseofElements/scripts.pory"
	setvar VAR_0x8005, MOVETUTOR_THUNDER_PUNCH
# 83 "data/maps/Route15_HouseofElements/scripts.pory"
	call EventScript_ChooseMoveTutorMon
# 84 "data/maps/Route15_HouseofElements/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq ThunderPunchMan_8
ThunderPunchMan_7:
# 88 "data/maps/Route15_HouseofElements/scripts.pory"
	goto EventScript_ThunderPunchTaught
	end

ThunderPunchMan_2:
# 74 "data/maps/Route15_HouseofElements/scripts.pory"
	goto EventScript_IcePunchDeclined
	goto ThunderPunchMan_1

ThunderPunchMan_5:
# 78 "data/maps/Route15_HouseofElements/scripts.pory"
	goto EventScript_IcePunchDeclined
	goto ThunderPunchMan_4

ThunderPunchMan_8:
# 85 "data/maps/Route15_HouseofElements/scripts.pory"
	goto EventScript_IcePunchDeclined
	goto ThunderPunchMan_7


EventScript_ThunderPunchTaught::
# 93 "data/maps/Route15_HouseofElements/scripts.pory"
	msgbox EventScript_ThunderPunchTaught_Text_0
# 94 "data/maps/Route15_HouseofElements/scripts.pory"
	release
	end


ElementalLady::
# 99 "data/maps/Route15_HouseofElements/scripts.pory"
	lock
# 100 "data/maps/Route15_HouseofElements/scripts.pory"
	faceplayer
# 101 "data/maps/Route15_HouseofElements/scripts.pory"
	msgbox ElementalLady_Text_0
# 102 "data/maps/Route15_HouseofElements/scripts.pory"
	release
	end


ElementalKid::
# 107 "data/maps/Route15_HouseofElements/scripts.pory"
	lock
# 108 "data/maps/Route15_HouseofElements/scripts.pory"
	faceplayer
# 109 "data/maps/Route15_HouseofElements/scripts.pory"
	msgbox ElementalKid_Text_0
# 110 "data/maps/Route15_HouseofElements/scripts.pory"
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
	.string "Excellent! Which POKéMON shall I\n"
	.string "teach?$"

EventScript_IcePunchDeclined_Text_0:
# 27 "data/maps/Route15_HouseofElements/scripts.pory"
	.string "Very well! Return here when you wish\n"
	.string "to embrace the elements!$"

EventScript_IcePunchTaught_Text_0:
# 33 "data/maps/Route15_HouseofElements/scripts.pory"
	.string "Use this move well. It was passed\n"
	.string "down to me from the masters of the\l"
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}LIN KUEI TEMPLE.$"

FirePunchMan_Text_0:
# 42 "data/maps/Route15_HouseofElements/scripts.pory"
	.string "The elements speak to me! They tell\n"
	.string "me fire is the most formidable. To\l"
	.string "prove the superiority of fire, allow\l"
	.string "me to teach one of your POKéMON\l"
	.string "FIRE PUNCH!$"

EventScript_FirePunchTaught_Text_0:
# 63 "data/maps/Route15_HouseofElements/scripts.pory"
	.string "Use this move well. It was passed\n"
	.string "down to me from the masters of the\l"
	.string "{COLOR RED}{SHADOW LIGHT_RED}SHIRAI RYU FIRE GARDEN.$"

ThunderPunchMan_Text_0:
# 72 "data/maps/Route15_HouseofElements/scripts.pory"
	.string "The elements speak to me! They tell\n"
	.string "me electricity is the most\l"
	.string "formidable. To prove the\l"
	.string "superiority of electricity, allow me\l"
	.string "to teach one of your POKéMON\l"
	.string "THUNDERPUNCH!$"

EventScript_ThunderPunchTaught_Text_0:
# 93 "data/maps/Route15_HouseofElements/scripts.pory"
	.string "Use this move well. It was passed\n"
	.string "down to me from the masters of the\l"
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}SKY TEMPLE.$"

ElementalLady_Text_0:
# 101 "data/maps/Route15_HouseofElements/scripts.pory"
	.string "They meditate for hours, then scream\n"
	.string "‘FIRE PUNCH! or ICE PUNCH!’ and\l"
	.string "sock the wall. I don’t get it\l"
	.string "either...$"

ElementalKid_Text_0:
# 109 "data/maps/Route15_HouseofElements/scripts.pory"
	.string "The blackbelts here say they learned\n"
	.string "from locations like the LIN KUEI\l"
	.string "TEMPLE or the SHIRAI RYU FIRE\l"
	.string "GARDENS. Those aren't any places\l"
	.string "I've heard of.$"
