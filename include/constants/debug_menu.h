#ifndef GUARD_CONSTANTS_DEBUG_MENU_H
#define GUARD_CONSTANTS_DEBUG_MENU_H

// TEMPORARY test tool. Remove before version 1 (see TODO.md).

// What the number picker is choosing (set in VAR_0x8004)
#define DEBUG_PICK_SPECIES  0 // National Pokedex number
#define DEBUG_PICK_LEVEL    1
#define DEBUG_PICK_ITEM     2
#define DEBUG_PICK_QUANTITY 3
#define DEBUG_PICK_MOVE     4 // Move number

// Results of DebugMenu_TeachMove
#define DEBUG_TEACH_DONE    0 // Learned into an empty slot
#define DEBUG_TEACH_KNOWN   1 // The Pokemon already knows it
#define DEBUG_TEACH_FULL    2 // A move has to be replaced

#endif // GUARD_CONSTANTS_DEBUG_MENU_H
