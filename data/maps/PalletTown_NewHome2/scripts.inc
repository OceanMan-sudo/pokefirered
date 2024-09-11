PalletTown_NewHome2_MapScripts::
	.byte 0


AgathaPallet::
# 3 "data/maps/PalletTown_NewHome2/scripts.pory"
	lock
# 4 "data/maps/PalletTown_NewHome2/scripts.pory"
	faceplayer
# 5 "data/maps/PalletTown_NewHome2/scripts.pory"
	goto_if_set SYS_FLAGS + 0x2C, AgathaPallet_2
# 7 "data/maps/PalletTown_NewHome2/scripts.pory"
	goto_if_set SYS_FLAGS + 0x27, AgathaPallet_3
# 9 "data/maps/PalletTown_NewHome2/scripts.pory"
	goto_if_set SYS_FLAGS + 0x29, AgathaPallet_4
# 12 "data/maps/PalletTown_NewHome2/scripts.pory"
	msgbox AgathaPallet_Text_3
AgathaPallet_1:
# 14 "data/maps/PalletTown_NewHome2/scripts.pory"
	release
	end

AgathaPallet_2:
# 6 "data/maps/PalletTown_NewHome2/scripts.pory"
	msgbox AgathaPallet_Text_0
	goto AgathaPallet_1

AgathaPallet_3:
# 8 "data/maps/PalletTown_NewHome2/scripts.pory"
	msgbox AgathaPallet_Text_1
	goto AgathaPallet_1

AgathaPallet_4:
# 10 "data/maps/PalletTown_NewHome2/scripts.pory"
	msgbox AgathaPallet_Text_2
	goto AgathaPallet_1


AgathaPallet_Text_0:
# 6 "data/maps/PalletTown_NewHome2/scripts.pory"
	.string "AGATHA: You've become strong!\pBut, mark my words,\nI don't plan on retiring ever!\pRun along now, child!$"

AgathaPallet_Text_1:
# 8 "data/maps/PalletTown_NewHome2/scripts.pory"
	.string "AGATHA: You've become strong!\pThe time has come to test your\nstrength.\pShow me what the old duff\nsees in you.\pRun along now, child!$"

AgathaPallet_Text_2:
# 10 "data/maps/PalletTown_NewHome2/scripts.pory"
	.string "AGATHA: That old duff OAK entrusted\nyou with the POKéDEX did he?\pHmph!\pYou must focus on battling.\pPOKéMON are made for battling, not\nstudying!\pRun along now, child.$"

AgathaPallet_Text_3:
# 12 "data/maps/PalletTown_NewHome2/scripts.pory"
	.string "AGATHA: Run along now child.$"
