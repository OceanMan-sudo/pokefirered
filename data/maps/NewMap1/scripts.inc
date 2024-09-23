NewMap1_MapScripts::
	.byte 0


VermilionCity_SurgeHype::
# 3 "data/maps/NewMap1/scripts.pory"
	lock
# 4 "data/maps/NewMap1/scripts.pory"
	faceplayer
# 5 "data/maps/NewMap1/scripts.pory"
	msgbox VermilionCity_SurgeHype_Text_0
# 6 "data/maps/NewMap1/scripts.pory"
	release
	end


VermilionCity_HiddenTruck::
# 11 "data/maps/NewMap1/scripts.pory"
	lock
# 12 "data/maps/NewMap1/scripts.pory"
	faceplayer
# 13 "data/maps/NewMap1/scripts.pory"
	msgbox VermilionCity_HiddenTruck_Text_0
# 14 "data/maps/NewMap1/scripts.pory"
	release
	end


VermilionSpearow::
# 19 "data/maps/NewMap1/scripts.pory"
	lock
# 20 "data/maps/NewMap1/scripts.pory"
	faceplayer
# 21 "data/maps/NewMap1/scripts.pory"
	playmoncry SPECIES_SPEAROW, CRY_MODE_NORMAL
# 22 "data/maps/NewMap1/scripts.pory"
	delay 40
# 23 "data/maps/NewMap1/scripts.pory"
	msgbox VermilionSpearow_Text_0
# 24 "data/maps/NewMap1/scripts.pory"
	release
	end


VermilionCity_SurgeHype_Text_0:
# 5 "data/maps/NewMap1/scripts.pory"
	.string "You're planning on taking on LT.\n"
	.string "SURGE? Good luck! His LANTURN is\l"
	.string "really tough!$"

VermilionCity_HiddenTruck_Text_0:
# 13 "data/maps/NewMap1/scripts.pory"
	.string "I heard there's a truck hidden near\n"
	.string "the dock. It's almost impossible to\l"
	.string "access though...$"

VermilionSpearow_Text_0:
# 23 "data/maps/NewMap1/scripts.pory"
	.string "SPARR!$"
