EventScript_RepelWoreOff::
	lockall
	specialvar VAR_RESULT, GetRepelToReuse
	goto_if_eq VAR_RESULT, ITEM_NONE, EventScript_RepelWoreOffNoMore
	msgbox Text_RepelWoreOffUseAnother, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_RepelWoreOffEnd
	special UseRepelAgain
	playse SE_REPEL
	msgbox Text_UsedAnotherRepel
EventScript_RepelWoreOffEnd::
	releaseall
	end

EventScript_RepelWoreOffNoMore::
	msgbox Text_RepelWoreOff
	releaseall
	end

Text_RepelWoreOff::
	.string "REPEL's effect wore off…$"

Text_RepelWoreOffUseAnother::
    .string "REPEL's effect wore off…\p"
    .string "Use another\n"
    .string "{STR_VAR_1}?$"

Text_UsedAnotherRepel::
    .string "{PLAYER} used the\n"
    .string "{STR_VAR_1}.$"
