// TEMPORARY test tool. Remove before version 1 (see TODO.md).
// The menu itself is in data/scripts/debug_menu.inc. Open it by holding B and pressing SELECT.
#include "global.h"
#include "gflib.h"
#include "data.h"
#include "event_data.h"
#include "field_fadetransition.h"
#include "item.h"
#include "menu.h"
#include "new_menu_helpers.h"
#include "overworld.h"
#include "party_menu.h"
#include "pokemon_summary_screen.h"
#include "script.h"
#include "script_pokemon_util.h"
#include "task.h"
#include "constants/debug_menu.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/songs.h"

#define tMode     data[0]
#define tValue    data[1]
#define tWindowId data[2]

static const u8 sText_Species[] = _("POKéDEX No.");
static const u8 sText_Level[] = _("LEVEL");
static const u8 sText_Item[] = _("ITEM No.");
static const u8 sText_Quantity[] = _("HOW MANY?");
static const u8 sText_Move[] = _("MOVE No.");
static const u8 sText_Help[] = _("UP/DOWN 1  LEFT/RIGHT 10");

static const struct WindowTemplate sPickerWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 20,
    .height = 6,
    .paletteNum = 15,
    .baseBlock = 0x038
};

static void Task_DebugPickNumber(u8 taskId);

static s32 GetPickerMax(u8 mode)
{
    switch (mode)
    {
    case DEBUG_PICK_SPECIES:
        return NATIONAL_DEX_COUNT;
    case DEBUG_PICK_LEVEL:
        return MAX_LEVEL;
    case DEBUG_PICK_ITEM:
        return ITEMS_COUNT - 1;
    case DEBUG_PICK_MOVE:
        return MOVES_COUNT - 1;
    default:
        return 99;
    }
}

// Moves the value, wrapping around at either end. Unused item numbers are skipped.
static s32 StepPickerValue(u8 mode, s32 value, s32 step)
{
    s32 max = GetPickerMax(mode);
    s32 direction = (step > 0) ? 1 : -1;
    s32 next = value + step;

    if (next > max)
        next = (value == max) ? 1 : max;
    else if (next < 1)
        next = (value == 1) ? max : 1;

    if (mode == DEBUG_PICK_ITEM)
    {
        while (ItemId_GetId(next) == ITEM_NONE)
        {
            next += direction;
            if (next > max)
                next = 1;
            else if (next < 1)
                next = max;
        }
    }
    return next;
}

static void PrintPicker(u8 taskId)
{
    u8 text[32];
    u8 *end;
    u8 windowId = gTasks[taskId].tWindowId;
    u8 mode = gTasks[taskId].tMode;
    u16 value = gTasks[taskId].tValue;
    const u8 *title;

    switch (mode)
    {
    case DEBUG_PICK_SPECIES:
        title = sText_Species;
        break;
    case DEBUG_PICK_LEVEL:
        title = sText_Level;
        break;
    case DEBUG_PICK_ITEM:
        title = sText_Item;
        break;
    case DEBUG_PICK_MOVE:
        title = sText_Move;
        break;
    default:
        title = sText_Quantity;
        break;
    }

    end = ConvertIntToDecimalStringN(text, value, STR_CONV_MODE_LEADING_ZEROS, 3);
    *end++ = CHAR_SPACE;
    *end = EOS;
    if (mode == DEBUG_PICK_SPECIES)
        StringCopy(end, gSpeciesNames[NationalPokedexNumToSpecies(value)]);
    else if (mode == DEBUG_PICK_ITEM)
        CopyItemName(value, end);
    else if (mode == DEBUG_PICK_MOVE)
        StringCopy(end, gMoveNames[value]);

    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    AddTextPrinterParameterized(windowId, FONT_NORMAL, title, 2, 1, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, text, 2, 17, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(windowId, FONT_SMALL, sText_Help, 2, 34, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

// Special: VAR_0x8004 says what to pick. VAR_RESULT gets the number, or 0 if cancelled.
// Use "waitstate" after it.
void DebugMenu_PickNumber(void)
{
    u8 taskId = CreateTask(Task_DebugPickNumber, 80);
    u8 windowId = AddWindow(&sPickerWindowTemplate);

    gTasks[taskId].tMode = gSpecialVar_0x8004;
    gTasks[taskId].tWindowId = windowId;
    if (gSpecialVar_0x8004 == DEBUG_PICK_LEVEL)
        gTasks[taskId].tValue = 5;
    else
        gTasks[taskId].tValue = 1;

    PutWindowTilemap(windowId);
    SetStdWindowBorderStyle(windowId, FALSE);
    PrintPicker(taskId);
}

static void Task_DebugPickNumber(u8 taskId)
{
    s32 step = 0;

    if (JOY_NEW(A_BUTTON))
    {
        gSpecialVar_Result = gTasks[taskId].tValue;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        gSpecialVar_Result = 0;
    }
    else
    {
        if (JOY_REPT(DPAD_UP))
            step = 1;
        else if (JOY_REPT(DPAD_DOWN))
            step = -1;
        else if (JOY_REPT(DPAD_RIGHT))
            step = 10;
        else if (JOY_REPT(DPAD_LEFT))
            step = -10;

        if (step != 0)
        {
            PlaySE(SE_SELECT);
            gTasks[taskId].tValue = StepPickerValue(gTasks[taskId].tMode, gTasks[taskId].tValue, step);
            PrintPicker(taskId);
        }
        return;
    }

    PlaySE(SE_SELECT);
    ClearWindowTilemap(gTasks[taskId].tWindowId);
    ClearStdWindowAndFrameToTransparent(gTasks[taskId].tWindowId, TRUE);
    RemoveWindow(gTasks[taskId].tWindowId);
    DestroyTask(taskId);
    ScriptContext_Enable();
}

// VAR_0x8005: National Pokedex number, VAR_0x8006: level.
// Returns MON_GIVEN_TO_PARTY, MON_GIVEN_TO_PC or MON_CANT_GIVE.
u16 DebugMenu_GiveMon(void)
{
    u16 species = NationalPokedexNumToSpecies(gSpecialVar_0x8005);
    u8 result = ScriptGiveMon(species, gSpecialVar_0x8006, ITEM_NONE, 0, 0, 0);

    if (result != MON_CANT_GIVE)
        FlagSet(FLAG_SYS_POKEMON_GET);
    StringCopy(gStringVar1, gSpeciesNames[species]);
    return result;
}

// TMs, HMs and Key Items are only ever held once
u16 DebugMenu_IsSingleItem(void)
{
    u8 pocket = ItemId_GetPocket(gSpecialVar_0x8005);

    return pocket == POCKET_TM_CASE || pocket == POCKET_KEY_ITEMS;
}

// VAR_0x8005: item, VAR_0x8006: quantity. Returns TRUE if it went into the bag.
u16 DebugMenu_GiveItem(void)
{
    CopyItemName(gSpecialVar_0x8005, gStringVar1);
    if (DebugMenu_IsSingleItem() && CheckBagHasItem(gSpecialVar_0x8005, 1))
        return FALSE;
    return AddBagItem(gSpecialVar_0x8005, gSpecialVar_0x8006);
}

// Gives one of every item from VAR_0x8005 to VAR_0x8006 that the bag lacks
void DebugMenu_GiveItemRange(void)
{
    u16 item;

    for (item = gSpecialVar_0x8005; item <= gSpecialVar_0x8006; item++)
    {
        if (!CheckBagHasItem(item, 1))
            AddBagItem(item, 1);
    }
}

// VAR_0x8007: party slot, VAR_0x8006: move number.
// Teaches the move straight away if there is an empty slot.
u16 DebugMenu_TeachMove(void)
{
    struct Pokemon *mon = &gPlayerParty[gSpecialVar_0x8007];
    u16 move = gSpecialVar_0x8006;
    u8 i;

    GetMonNickname(mon, gStringVar1);
    StringCopy(gStringVar2, gMoveNames[move]);

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (GetMonData(mon, MON_DATA_MOVE1 + i) == move)
            return DEBUG_TEACH_KNOWN;
    }
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (GetMonData(mon, MON_DATA_MOVE1 + i) == MOVE_NONE)
        {
            RemoveMonPPBonus(mon, i);
            SetMonMoveSlot(mon, move, i);
            return DEBUG_TEACH_DONE;
        }
    }
    return DEBUG_TEACH_FULL;
}

// VAR_0x8007: party slot, VAR_0x8006: new move.
// Opens the summary screen. VAR_0x8005 gets the slot chosen, or MAX_MON_MOVES if cancelled.
// Like the move deleter: "fadescreen FADE_TO_BLACK" before it, "fadescreen FADE_FROM_BLACK" after.
void DebugMenu_SelectMoveToReplace(void)
{
    ShowSelectMovePokemonSummaryScreen(gPlayerParty, gSpecialVar_0x8007, gPlayerPartyCount - 1, CB2_ReturnToField, gSpecialVar_0x8006);
    gFieldCallback = FieldCB_ContinueScriptHandleMusic;
}

// VAR_0x8007: party slot, VAR_0x8006: new move, VAR_0x8005: move slot to overwrite.
void DebugMenu_ReplaceMove(void)
{
    struct Pokemon *mon = &gPlayerParty[gSpecialVar_0x8007];

    RemoveMonPPBonus(mon, gSpecialVar_0x8005);
    SetMonMoveSlot(mon, gSpecialVar_0x8006, gSpecialVar_0x8005);
    // The summary screen reuses the text buffers, so fill them again for the message
    GetMonNickname(mon, gStringVar1);
    StringCopy(gStringVar2, gMoveNames[gSpecialVar_0x8006]);
}
