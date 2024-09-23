VermilionCity_FossilHouse_MapScripts::
	.byte 0


ReviveFossilNPC::
# 4 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	lock
# 5 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	faceplayer
	checkitem ITEM_HELIX_FOSSIL
# 0 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne ReviveFossilNPC_2
ReviveFossilNPC_1:
	checkitem ITEM_DOME_FOSSIL
# 0 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne ReviveFossilNPC_5
ReviveFossilNPC_4:
	checkitem ITEM_ROOT_FOSSIL
# 0 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne ReviveFossilNPC_13
ReviveFossilNPC_12:
	checkitem ITEM_CLAW_FOSSIL
# 0 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne ReviveFossilNPC_21
ReviveFossilNPC_20:
	checkitem ITEM_OLD_AMBER
# 0 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne ReviveFossilNPC_29
# 121 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_14
ReviveFossilNPC_28:
# 123 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	release
	end

ReviveFossilNPC_2:
# 7 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_0
# 8 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	givemon SPECIES_OMANYTE, 20
# 9 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ReviveFossilNPC_7
# 17 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq ReviveFossilNPC_8
# 26 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_3
	goto ReviveFossilNPC_1

ReviveFossilNPC_5:
# 30 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_4
# 31 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	givemon SPECIES_KABUTO, 20
# 32 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ReviveFossilNPC_15
# 40 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq ReviveFossilNPC_16
# 49 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_3
	goto ReviveFossilNPC_4

ReviveFossilNPC_7:
# 10 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 11 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_1
# 12 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	call NicknamePartyMon
# 13 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	removeitem ITEM_HELIX_FOSSIL
# 14 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_2
# 15 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	release
	end

ReviveFossilNPC_8:
# 18 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 19 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_1
# 20 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	call NameReceivedBoxMon
# 21 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	removeitem ITEM_HELIX_FOSSIL
# 22 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_2
# 23 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	release
	end

ReviveFossilNPC_13:
# 53 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_7
# 54 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	givemon SPECIES_LILEEP, 20
# 55 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ReviveFossilNPC_23
# 63 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq ReviveFossilNPC_24
# 72 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_3
	goto ReviveFossilNPC_12

ReviveFossilNPC_15:
# 33 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 34 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_5
# 35 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	call NicknamePartyMon
# 36 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	removeitem ITEM_DOME_FOSSIL
# 37 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_6
# 38 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	release
	end

ReviveFossilNPC_16:
# 41 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 42 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_5
# 43 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	call NameReceivedBoxMon
# 44 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	removeitem ITEM_DOME_FOSSIL
# 45 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_6
# 46 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	release
	end

ReviveFossilNPC_21:
# 76 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_10
# 77 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	givemon SPECIES_ANORITH, 20
# 78 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ReviveFossilNPC_32
# 86 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq ReviveFossilNPC_33
# 95 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_3
	goto ReviveFossilNPC_20

ReviveFossilNPC_23:
# 56 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 57 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_8
# 58 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	call NicknamePartyMon
# 59 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	removeitem ITEM_ROOT_FOSSIL
# 60 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_9
# 61 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	release
	end

ReviveFossilNPC_24:
# 64 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 65 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_8
# 66 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	call NameReceivedBoxMon
# 67 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	removeitem ITEM_ROOT_FOSSIL
# 68 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_9
# 69 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	release
	end

ReviveFossilNPC_29:
# 99 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_12
# 100 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	givemon SPECIES_AERODACTYL, 20
# 101 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ReviveFossilNPC_37
# 109 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq ReviveFossilNPC_38
# 118 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_3
	goto ReviveFossilNPC_28

ReviveFossilNPC_32:
# 79 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 80 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_11
# 81 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	call NicknamePartyMon
# 82 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	removeitem ITEM_CLAW_FOSSIL
# 83 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_9
# 84 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	release
	end

ReviveFossilNPC_33:
# 87 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 88 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_11
# 89 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	call NameReceivedBoxMon
# 90 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	removeitem ITEM_CLAW_FOSSIL
# 91 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_9
# 92 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	release
	end

ReviveFossilNPC_37:
# 102 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 103 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_13
# 104 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	call NicknamePartyMon
# 105 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	removeitem ITEM_OLD_AMBER
# 106 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_9
# 107 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	release
	end

ReviveFossilNPC_38:
# 110 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 111 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_13
# 112 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	call NameReceivedBoxMon
# 113 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	removeitem ITEM_OLD_AMBER
# 114 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_9
# 115 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	release
	end


NicknamePartyMon::
# 129 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
# 130 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NicknamePartyMon_1
	return

NicknamePartyMon_1:
# 131 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	call EventScript_GetGiftMonPartySlot
# 132 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	call EventScript_ChangePokemonNickname
	return


NameReceivedBoxMon::
# 137 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
# 138 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NameReceivedBoxMon_2
NameReceivedBoxMon_1:
# 141 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox NameReceivedBoxMon_Text_0
	return

NameReceivedBoxMon_2:
# 139 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	call EventScript_NameReceivedBoxMon
	goto NameReceivedBoxMon_1


FossilNerdVermilion::
# 145 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	lock
# 146 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	faceplayer
# 147 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox FossilNerdVermilion_Text_0
# 148 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	release
	end


FossilWorker::
# 153 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	lock
# 154 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	faceplayer
# 155 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox FossilWorker_Text_0
# 156 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	release
	end


FossilerWorker2::
# 161 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	lock
# 162 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	faceplayer
# 163 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox FossilerWorker2_Text_0
# 164 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	release
	end


ReviveFossilNPC_Text_0:
# 7 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "I used to research POKéMON on\n"
	.string "CINNABAR ISLAND but I've relocated\l"
	.string "here to VERMILION CITY. Ah! I see\l"
	.string "you have a HELIX FOSSIL! Let me\l"
	.string "revive it for you.$"

ReviveFossilNPC_Text_1:
# 11 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "Recieved OMANYTE!$"

ReviveFossilNPC_Text_2:
# 14 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "You made an excellent choice\n"
	.string "selecting the path of Helix... Come\l"
	.string "back if you find any more fossils!$"

ReviveFossilNPC_Text_3:
# 26 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "You don't have room.$"

ReviveFossilNPC_Text_4:
# 30 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "I used to research POKéMON on\n"
	.string "CINNABAR ISLAND but I've relocated\l"
	.string "here to VERMILION CITY. Ah! I see\l"
	.string "you have a DOME FOSSIL! Let me\l"
	.string "revive it for you.$"

ReviveFossilNPC_Text_5:
# 34 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "Recieved KABUTO!$"

ReviveFossilNPC_Text_6:
# 37 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "The DOME FOSSIL... An interesting\n"
	.string "choice. Come back if you find any\l"
	.string "more fossils!$"

ReviveFossilNPC_Text_7:
# 53 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "I used to research POKéMON on\n"
	.string "CINNABAR ISLAND but I've relocated\l"
	.string "here to VERMILION CITY. Ah! I see\l"
	.string "you have a ROOT FOSSIL! Let me\l"
	.string "revive it for you.$"

ReviveFossilNPC_Text_8:
# 57 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "Recieved LILEEP!$"

ReviveFossilNPC_Text_9:
# 60 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "Come back if you find any more\n"
	.string "fossils!$"

ReviveFossilNPC_Text_10:
# 76 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "I used to research POKéMON on\n"
	.string "CINNABAR ISLAND but I've relocated\l"
	.string "here to VERMILION CITY. Ah! I see\l"
	.string "you have a a CLAW FOSSIL! Let me\l"
	.string "revive it for you.$"

ReviveFossilNPC_Text_11:
# 80 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "Recieved ANORITH!$"

ReviveFossilNPC_Text_12:
# 99 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "I used to research POKéMON on\n"
	.string "CINNABAR ISLAND but I've relocated\l"
	.string "here to VERMILION CITY. Ah! I see\l"
	.string "you have an OLD AMBER! Let me\l"
	.string "revive it for you.$"

ReviveFossilNPC_Text_13:
# 103 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "Recieved AERODACTYL!$"

ReviveFossilNPC_Text_14:
# 121 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "I enjoyed living on CINNABAR ISLAND,\n"
	.string "but it's just so far! I'm happy I\l"
	.string "moved my research to VERMILION\l"
	.string "CITY.$"

NicknamePartyMon_Text_0:
# 129 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "Give it a nickname?$"

NameReceivedBoxMon_Text_0:
# 141 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "POKéMON was sent to BILL's PC!$"

FossilNerdVermilion_Text_0:
# 147 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "I'm glad we moved our research to\n"
	.string "VERMILION CITY. Although I must\l"
	.string "admit, it did take quite a bit of\l"
	.string "work figuring out how to get it all\l"
	.string "working in an entirely new city. Do\l"
	.string "you know how much effort it takes\l"
	.string "to restore a FOSSIL? A lot, as it\l"
	.string "turns out. I'd say it took up our\l"
	.string "whole Sunday!$"

FossilWorker_Text_0:
# 155 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "While you can still restore your\n"
	.string "FOSSIL POKéMON on CINNABAR\l"
	.string "ISLAND, we here in VERMILION CITY\l"
	.string "are able to bring the POKéMON back\l"
	.string "at a much higher level! Now you\l"
	.string "can enjoy POKéMON like KABUTO or\l"
	.string "OMANYTE without needing to play\l"
	.string "catchup! What's more is that we've\l"
	.string "discovered ways to evolve these\l"
	.string "POKéMON at earlier levels. We hope\l"
	.string "you enjoy the results of our\l"
	.string "research!$"

FossilerWorker2_Text_0:
# 163 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "We believe there are ways to acquire\n"
	.string "other fossils around the region.\l"
	.string "Perhaps you can even find the ROOT\l"
	.string "FOSSIL and CLAW FOSSIL somewhere?$"
