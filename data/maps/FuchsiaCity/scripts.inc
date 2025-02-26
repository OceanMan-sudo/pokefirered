# 1 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_MapScripts::
# 2 "data/maps/FuchsiaCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_OnTransition
# 3 "data/maps/FuchsiaCity/scripts.pory"
	.byte 0
# 4 "data/maps/FuchsiaCity/scripts.pory"

# 5 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_OnTransition::
# 6 "data/maps/FuchsiaCity/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_FUCHSIA_CITY
# 7 "data/maps/FuchsiaCity/scripts.pory"
	call_if_set FLAG_GOT_DOME_FOSSIL, FuchsiaCity_EventScript_SetOmanyteGfx
# 8 "data/maps/FuchsiaCity/scripts.pory"
	call_if_unset FLAG_GOT_DOME_FOSSIL, FuchsiaCity_EventScript_SetKabutoGfx
# 9 "data/maps/FuchsiaCity/scripts.pory"
	end
# 10 "data/maps/FuchsiaCity/scripts.pory"

# 11 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_SetOmanyteGfx::
# 12 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OMANYTE
# 13 "data/maps/FuchsiaCity/scripts.pory"
	return
# 14 "data/maps/FuchsiaCity/scripts.pory"

# 15 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_SetKabutoGfx::
# 16 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_KABUTO
# 17 "data/maps/FuchsiaCity/scripts.pory"
	return
# 18 "data/maps/FuchsiaCity/scripts.pory"

# 19 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_LittleBoy::
# 20 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_DidYouTrySafariGame, MSGBOX_NPC
# 21 "data/maps/FuchsiaCity/scripts.pory"
	end
# 22 "data/maps/FuchsiaCity/scripts.pory"

# 23 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_OldMan::
# 24 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_SafariZoneZooInFront, MSGBOX_NPC
# 25 "data/maps/FuchsiaCity/scripts.pory"
	end
# 26 "data/maps/FuchsiaCity/scripts.pory"

# 27 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_Erik::
# 28 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_WheresSara, MSGBOX_NPC
# 29 "data/maps/FuchsiaCity/scripts.pory"
	end
# 30 "data/maps/FuchsiaCity/scripts.pory"

# 31 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_Youngster::
# 32 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_ItemBallInThere, MSGBOX_NPC
# 33 "data/maps/FuchsiaCity/scripts.pory"
	end
# 34 "data/maps/FuchsiaCity/scripts.pory"

# 35 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_Lass::
# 36 "data/maps/FuchsiaCity/scripts.pory"
	lock
# 37 "data/maps/FuchsiaCity/scripts.pory"
	faceplayer
# 38 "data/maps/FuchsiaCity/scripts.pory"
	famechecker FAMECHECKER_KOGA, 3
# 39 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_MyFatherIsGymLeader
# 40 "data/maps/FuchsiaCity/scripts.pory"
	release
# 41 "data/maps/FuchsiaCity/scripts.pory"
	end
# 42 "data/maps/FuchsiaCity/scripts.pory"

# 43 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_CitySign::
# 44 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_CitySign, MSGBOX_SIGN
# 45 "data/maps/FuchsiaCity/scripts.pory"
	end
# 46 "data/maps/FuchsiaCity/scripts.pory"

# 47 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_SafariZoneSign::
# 48 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_SafariZoneSign, MSGBOX_SIGN
# 49 "data/maps/FuchsiaCity/scripts.pory"
	end
# 50 "data/maps/FuchsiaCity/scripts.pory"

# 51 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_SafariGameSign::
# 52 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_SafariGameSign, MSGBOX_SIGN
# 53 "data/maps/FuchsiaCity/scripts.pory"
	end
# 54 "data/maps/FuchsiaCity/scripts.pory"

# 55 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_WardensHomeSign::
# 56 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_WardensHomeSign, MSGBOX_SIGN
# 57 "data/maps/FuchsiaCity/scripts.pory"
	end
# 58 "data/maps/FuchsiaCity/scripts.pory"

# 59 "data/maps/FuchsiaCity/scripts.pory"
@ Unused
# 60 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_SafariZoneOfficeSign::
# 61 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_SafariZoneOfficeSign, MSGBOX_SIGN
# 62 "data/maps/FuchsiaCity/scripts.pory"
	end
# 63 "data/maps/FuchsiaCity/scripts.pory"

# 64 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_GymSign::
# 65 "data/maps/FuchsiaCity/scripts.pory"
	lockall
# 66 "data/maps/FuchsiaCity/scripts.pory"
	famechecker FAMECHECKER_KOGA, 0
# 67 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_GymSign
# 68 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
# 69 "data/maps/FuchsiaCity/scripts.pory"
	end
# 70 "data/maps/FuchsiaCity/scripts.pory"

# 71 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_ChanseySign::
# 72 "data/maps/FuchsiaCity/scripts.pory"
	lockall
# 73 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_CHANSEY
# 74 "data/maps/FuchsiaCity/scripts.pory"
	special SetSeenMon
# 75 "data/maps/FuchsiaCity/scripts.pory"
	showmonpic SPECIES_CHANSEY, 10, 3
# 76 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_ChanseySign
# 77 "data/maps/FuchsiaCity/scripts.pory"
	hidemonpic
# 78 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
# 79 "data/maps/FuchsiaCity/scripts.pory"
	end
# 80 "data/maps/FuchsiaCity/scripts.pory"

# 81 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_VoltorbSign::
# 82 "data/maps/FuchsiaCity/scripts.pory"
	lockall
# 83 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_VOLTORB
# 84 "data/maps/FuchsiaCity/scripts.pory"
	special SetSeenMon
# 85 "data/maps/FuchsiaCity/scripts.pory"
	showmonpic SPECIES_VOLTORB, 10, 3
# 86 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_VoltorbSign
# 87 "data/maps/FuchsiaCity/scripts.pory"
	hidemonpic
# 88 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
# 89 "data/maps/FuchsiaCity/scripts.pory"
	end
# 90 "data/maps/FuchsiaCity/scripts.pory"

# 91 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_KangaskhanSign::
# 92 "data/maps/FuchsiaCity/scripts.pory"
	lockall
# 93 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_KANGASKHAN
# 94 "data/maps/FuchsiaCity/scripts.pory"
	special SetSeenMon
# 95 "data/maps/FuchsiaCity/scripts.pory"
	showmonpic SPECIES_KANGASKHAN, 10, 3
# 96 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_KangaskhanSign
# 97 "data/maps/FuchsiaCity/scripts.pory"
	hidemonpic
# 98 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
# 99 "data/maps/FuchsiaCity/scripts.pory"
	end
# 100 "data/maps/FuchsiaCity/scripts.pory"

# 101 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_SlowpokeSign::
# 102 "data/maps/FuchsiaCity/scripts.pory"
	lockall
# 103 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_SLOWPOKE
# 104 "data/maps/FuchsiaCity/scripts.pory"
	special SetSeenMon
# 105 "data/maps/FuchsiaCity/scripts.pory"
	showmonpic SPECIES_SLOWPOKE, 10, 3
# 106 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_SlowpokeSign
# 107 "data/maps/FuchsiaCity/scripts.pory"
	hidemonpic
# 108 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
# 109 "data/maps/FuchsiaCity/scripts.pory"
	end
# 110 "data/maps/FuchsiaCity/scripts.pory"

# 111 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_LaprasSign::
# 112 "data/maps/FuchsiaCity/scripts.pory"
	lockall
# 113 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_LAPRAS
# 114 "data/maps/FuchsiaCity/scripts.pory"
	special SetSeenMon
# 115 "data/maps/FuchsiaCity/scripts.pory"
	showmonpic SPECIES_LAPRAS, 10, 3
# 116 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_LaprasSign
# 117 "data/maps/FuchsiaCity/scripts.pory"
	hidemonpic
# 118 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
# 119 "data/maps/FuchsiaCity/scripts.pory"
	end
# 120 "data/maps/FuchsiaCity/scripts.pory"

# 121 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_FossilMonSign::
# 122 "data/maps/FuchsiaCity/scripts.pory"
	lockall
# 123 "data/maps/FuchsiaCity/scripts.pory"
	goto_if_set FLAG_GOT_DOME_FOSSIL, FuchsiaCity_EventScript_OmanyteSign
# 124 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_KABUTO
# 125 "data/maps/FuchsiaCity/scripts.pory"
	special SetSeenMon
# 126 "data/maps/FuchsiaCity/scripts.pory"
	showmonpic SPECIES_KABUTO, 10, 3
# 127 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_KabutoSign
# 128 "data/maps/FuchsiaCity/scripts.pory"
	hidemonpic
# 129 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
# 130 "data/maps/FuchsiaCity/scripts.pory"
	end
# 131 "data/maps/FuchsiaCity/scripts.pory"

# 132 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_OmanyteSign::
# 133 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_OMANYTE
# 134 "data/maps/FuchsiaCity/scripts.pory"
	special SetSeenMon
# 135 "data/maps/FuchsiaCity/scripts.pory"
	showmonpic SPECIES_OMANYTE, 10, 3
# 136 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_OmanyteSign
# 137 "data/maps/FuchsiaCity/scripts.pory"
	hidemonpic
# 138 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
# 139 "data/maps/FuchsiaCity/scripts.pory"
	end

LedgeGuy::
# 142 "data/maps/FuchsiaCity/scripts.pory"
	lock
# 143 "data/maps/FuchsiaCity/scripts.pory"
	faceplayer
# 144 "data/maps/FuchsiaCity/scripts.pory"
	msgbox LedgeGuy_Text_0
# 145 "data/maps/FuchsiaCity/scripts.pory"
	release
	end


DomeHater::
# 149 "data/maps/FuchsiaCity/scripts.pory"
	lock
# 150 "data/maps/FuchsiaCity/scripts.pory"
	faceplayer
# 151 "data/maps/FuchsiaCity/scripts.pory"
	msgbox DomeHater_Text_0
# 152 "data/maps/FuchsiaCity/scripts.pory"
	release
	end


FirstItem::
# 157 "data/maps/FuchsiaCity/scripts.pory"
	lock
# 158 "data/maps/FuchsiaCity/scripts.pory"
	giveitem ITEM_NEST_BALL, 1
# 159 "data/maps/FuchsiaCity/scripts.pory"
	removeobject 15
# 160 "data/maps/FuchsiaCity/scripts.pory"
	setflag FLAG_0x0B5
# 161 "data/maps/FuchsiaCity/scripts.pory"
	release
	end


LedgeGuy_Text_0:
# 144 "data/maps/FuchsiaCity/scripts.pory"
	.string "Don't you just hate that ledge\n"
	.string "there? We could get rid of it\l"
	.string "but...honestly it's just way funnier\l"
	.string "leaving it there.$"

DomeHater_Text_0:
# 151 "data/maps/FuchsiaCity/scripts.pory"
	.string "There's something about this FOSSIL\n"
	.string "POKéMON that just doesn't sit right\l"
	.string "with me...$"
