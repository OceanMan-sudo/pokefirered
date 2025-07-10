Common_EventScript_MoveRelearner::
    goto_if_questlog EventScript_ReleaseEnd
    special QuestLog_CutRecording
    lock
    faceplayer
    msgbox gText_WantMeToTeachMove, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, EventScript_EndTutorMove
    goto EventScript_ChooseMonToTutor
    end

EventScript_ChooseMonToTutor::
    msgbox gText_TutorWhichMon
    special SelectMoveTutorMon
    waitstate
    goto_if_ge VAR_0x8004, PARTY_SIZE, EventScript_EndTutorMove
    special IsSelectedMonEgg
    goto_if_eq VAR_RESULT, TRUE, EventScript_CantTutorEgg
    goto_if_eq VAR_0x8005, 0, EventScript_NoMoveToTutorMon
    goto EventScript_ChooseMoveToTeach
    end

EventScript_ChooseMoveToTeach::
    msgbox gText_TeachWhichMove
    special DisplayMoveTutorMenu
    waitstate
    goto_if_eq VAR_0x8004, 0, EventScript_ChooseMonToTutor
    goto EventScript_EndTutorMove
    end

EventScript_NoMoveToTutorMon::
    msgbox gText_NoMoveICanTeachThatMon
    goto EventScript_ChooseMonToTutor
    end

EventScript_CantTutorEgg::
    msgbox gText_CantTeachAnEgg
    goto EventScript_ChooseMonToTutor
    end

EventScript_EndTutorMove::
    msgbox gText_ComeBackAgain
    release
    end
    