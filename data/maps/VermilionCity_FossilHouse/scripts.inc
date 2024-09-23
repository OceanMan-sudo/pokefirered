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
# 101 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_12
ReviveFossilNPC_28:
# 103 "data/maps/VermilionCity_FossilHouse/scripts.pory"
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
# 15 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq ReviveFossilNPC_8
# 22 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_3
	goto ReviveFossilNPC_1

ReviveFossilNPC_5:
# 26 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_4
# 27 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	givemon SPECIES_KABUTO, 20
# 28 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ReviveFossilNPC_15
# 34 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq ReviveFossilNPC_16
# 41 "data/maps/VermilionCity_FossilHouse/scripts.pory"
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
	goto ReviveFossilNPC_1

ReviveFossilNPC_8:
# 16 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 17 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_1
# 18 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	call NameReceivedBoxMon
# 19 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	removeitem ITEM_HELIX_FOSSIL
# 20 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_2
	goto ReviveFossilNPC_1

ReviveFossilNPC_13:
# 45 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_6
# 46 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	givemon SPECIES_LILEEP, 20
# 47 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ReviveFossilNPC_23
# 53 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq ReviveFossilNPC_24
# 60 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_3
	goto ReviveFossilNPC_12

ReviveFossilNPC_15:
# 29 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 30 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_5
# 31 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	call NicknamePartyMon
# 32 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	removeitem ITEM_DOME_FOSSIL
# 33 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_2
	goto ReviveFossilNPC_4

ReviveFossilNPC_16:
# 35 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 36 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_5
# 37 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	call NameReceivedBoxMon
# 38 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	removeitem ITEM_DOME_FOSSIL
# 39 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_2
	goto ReviveFossilNPC_4

ReviveFossilNPC_21:
# 64 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_8
# 65 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	givemon SPECIES_ANORITH, 20
# 66 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ReviveFossilNPC_32
# 72 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq ReviveFossilNPC_33
# 79 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_3
	goto ReviveFossilNPC_20

ReviveFossilNPC_23:
# 48 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 49 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_7
# 50 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	call NicknamePartyMon
# 51 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	removeitem ITEM_ROOT_FOSSIL
# 52 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_2
	goto ReviveFossilNPC_12

ReviveFossilNPC_24:
# 54 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 55 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_7
# 56 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	call NameReceivedBoxMon
# 57 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	removeitem ITEM_ROOT_FOSSIL
# 58 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_2
	goto ReviveFossilNPC_12

ReviveFossilNPC_29:
# 83 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_10
# 84 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	givemon SPECIES_AERODACTYL, 20
# 85 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq ReviveFossilNPC_37
# 91 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq ReviveFossilNPC_38
# 98 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_3
	goto ReviveFossilNPC_28

ReviveFossilNPC_32:
# 67 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 68 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_9
# 69 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	call NicknamePartyMon
# 70 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	removeitem ITEM_CLAW_FOSSIL
# 71 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_2
	goto ReviveFossilNPC_20

ReviveFossilNPC_33:
# 73 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 74 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_9
# 75 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	call NameReceivedBoxMon
# 76 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	removeitem ITEM_CLAW_FOSSIL
# 77 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_2
	goto ReviveFossilNPC_20

ReviveFossilNPC_37:
# 86 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 87 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_11
# 88 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	call NicknamePartyMon
# 89 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	removeitem ITEM_OLD_AMBER
# 90 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_2
	goto ReviveFossilNPC_28

ReviveFossilNPC_38:
# 92 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 93 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_11
# 94 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	call NameReceivedBoxMon
# 95 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	removeitem ITEM_OLD_AMBER
# 96 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox ReviveFossilNPC_Text_2
	goto ReviveFossilNPC_28


NicknamePartyMon::
# 109 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
# 110 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NicknamePartyMon_1
	return

NicknamePartyMon_1:
# 111 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	call EventScript_GetGiftMonPartySlot
# 112 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	call EventScript_ChangePokemonNickname
	return


NameReceivedBoxMon::
# 117 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
# 118 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NameReceivedBoxMon_2
NameReceivedBoxMon_1:
# 121 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	msgbox NameReceivedBoxMon_Text_0
	return

NameReceivedBoxMon_2:
# 119 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	call EventScript_NameReceivedBoxMon
	goto NameReceivedBoxMon_1


ReviveFossilNPC_Text_0:
# 7 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "Ah! You have a Helix Fossil!\p"
	.string "Let me revive it for you.$"

ReviveFossilNPC_Text_1:
# 11 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "Recieved OMANYTE!$"

ReviveFossilNPC_Text_2:
# 14 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "Come back if you find any more\n"
	.string "fossils!$"

ReviveFossilNPC_Text_3:
# 22 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "You don't have room.$"

ReviveFossilNPC_Text_4:
# 26 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "Ah! You have a Dome Fossil!\p"
	.string "Let me revive it for you.$"

ReviveFossilNPC_Text_5:
# 30 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "Recieved KABUTO!$"

ReviveFossilNPC_Text_6:
# 45 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "Ah! You have a Root Fossil!\p"
	.string "Let me revive it for you.$"

ReviveFossilNPC_Text_7:
# 49 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "Recieved LILEEP!$"

ReviveFossilNPC_Text_8:
# 64 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "Ah! You have a Claw Fossil!\p"
	.string "Let me revive it for you.$"

ReviveFossilNPC_Text_9:
# 68 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "Recieved ANORITH!$"

ReviveFossilNPC_Text_10:
# 83 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "Ah! You have an Old Amber!\p"
	.string "Let me revive it for you.$"

ReviveFossilNPC_Text_11:
# 87 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "Recieved AERODACTYL!$"

ReviveFossilNPC_Text_12:
# 101 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "Do you have a fossil? If you do, I\n"
	.string "can revive it for you!$"

NicknamePartyMon_Text_0:
# 109 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "Give it a nickname?$"

NameReceivedBoxMon_Text_0:
# 121 "data/maps/VermilionCity_FossilHouse/scripts.pory"
	.string "POKéMON was sent to BILL's PC!$"
