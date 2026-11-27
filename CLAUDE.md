# CLAUDE.md — technical project documentation

A Pokémon FireRed ROM hack built on the [pret/pokefirered](https://github.com/pret/pokefirered) decompilation. An in-game character calls it "Super POKéMON FireRed II Turbo HD Remix".

Related files: [DESIGN.md](DESIGN.md) (how the game plays) · [TODO.md](TODO.md) (roadmap) · [CHANGELOG.md](CHANGELOG.md) (what changed) · [BUGS.md](BUGS.md) (known problems)

## Working agreements

These are the owner's standing instructions.

1. **Confirm before changing anything.** Describe the plan and wait for approval on anything new or open to interpretation. A direct, specific request counts as approval.
2. **Do not edit learnsets** until the owner starts that work.
3. Work on the `claude-edits` branch. Leave `master` untouched.
4. The owner is new to the terminal. Give copy-and-paste commands and plain explanations.
5. **Remind the owner to remove the debug menu** before version 1 is finished. Steps are in [TODO.md](TODO.md) under "Removing the debug menu".

## Repository and history

| Item | Value |
|---|---|
| GitHub repository | `OceanMan-sudo/pokefirered` |
| Original project | `pret/pokefirered` |
| Point where the hack split from the original | commit `539ed3616` (29 August 2024) |
| `master` | the owner's work, last commit `ba9438229` (26 November 2026) |
| `claude-edits` | `master` plus the Claude-assisted changes |
| Third-party code merged in | RavePossum's dynamic multichoice (`sbird_multichoice` branch) |

To compare against the original game:

```bash
git remote add upstream https://github.com/pret/pokefirered   # once
git fetch upstream
git diff 539ed3616 -- src include data          # everything this hack changed
git diff master claude-edits                    # only the Claude-assisted changes
```

Compare against the split commit, not the newest upstream: the original project has moved on since, and those changes are not part of this hack.

## Building the game

The owner builds on Windows using WSL (Debian), with the project on the Windows drive. Full first-time setup is in [INSTALL.md](INSTALL.md). In short you need `build-essential`, `binutils-arm-none-eabi`, `git`, `libpng-dev`, and [agbcc](https://github.com/pret/agbcc) installed into `tools/agbcc`.

```bash
cd /mnt/c/Users/<you>/Documents/pokefirered
git pull
make
```

- Output: `pokefirered.gba` in the project folder (FireRed, revision 0, English).
- `make -j$(nproc)` builds faster.
- `make leafgreen` builds LeafGreen, but this hack's wild encounter changes are mostly FireRed only, and LeafGreen has not been checked.
- `make compare` checks for an exact copy of the original ROM, so it is expected to fail.
- `make clean` removes build output, **including the `.inc` files generated from `.pory` files**. The next `make` recreates them.

### What `make` does

1. Builds the helper programs in `tools/`.
2. Turns `.pory` scripts into `.inc` files with Poryscript.
3. Turns JSON (maps, items, wild encounters, map sections) into C and assembly.
4. Converts graphics and music into GBA formats.
5. Compiles C with `agbcc` (an old compiler: variables are declared at the top of a block, and warnings stop the build).
6. Links everything (`ld_script.ld`) and fixes the ROM header.

### Testing a change

Build, open `pokefirered.gba` in an emulator, and check the feature. If you saved inside a map that changed, leave and re-enter it. Saves from much older builds may not load correctly.

## Where things live

| To change… | Edit |
|---|---|
| Pokémon stats, types, abilities, held items | `src/data/pokemon/species_info.h` |
| Level-up moves | `src/data/pokemon/level_up_learnsets.h` |
| TM/HM compatibility | `src/data/pokemon/tmhm_learnsets.h` |
| Move tutor compatibility | `src/data/pokemon/tutor_learnsets.h` |
| Evolutions | `src/data/pokemon/evolution.h` |
| Move data (power, type, category…) | `src/data/battle_moves.h` |
| Move names / descriptions | `src/data/text/move_names.h`, `src/move_descriptions.c` |
| Move numbers | `include/constants/moves.h` |
| Move animations | `data/battle_anim_scripts.s`, `src/battle_anim_*.c` |
| Ability numbers / names / descriptions | `include/constants/abilities.h`, `src/data/text/abilities.h` |
| Ability and damage rules | `src/pokemon.c` (`CalculateBaseDamage`), `src/battle_util.c`, `src/battle_script_commands.c` |
| Trainers | `src/data/trainers.h`, `src/data/trainer_parties.h`, `include/constants/opponents.h` |
| Wild encounters | `src/data/wild_encounters.json` |
| Items | `src/data/items.json`, `src/data/pokemon/item_effects.h` |
| Maps (people, doors, signs) | `data/maps/<MapName>/map.json` (Porymap edits this) |
| Map tiles | `data/layouts/<MapName>/` |
| Map scripts and text | `data/maps/<MapName>/scripts.pory` if it exists, otherwise `scripts.inc` and `text.inc` |
| Shared scripts | `data/scripts/` |
| Story flags | `include/constants/flags.h` |
| Starting PC items | `src/player_pc.c` |
| Level caps | `src/data/level_caps.h` |

## Custom systems

| System | Main files |
|---|---|
| Physical/Special split | `category` field in `battle_moves.h`; `IS_MOVE_PHYSICAL` / `IS_MOVE_SPECIAL` in `include/battle.h`; icon in `src/battle_controller_player.c` and `graphics/battle_interface/split_icons_battle.png` |
| Fairy type | `TYPE_FAIRY` in `include/constants/pokemon.h`; chart and names in `src/battle_main.c` (the chart size is also in `include/battle_main.h`); label position in `src/list_menu.c`, artwork in `graphics/interface/menu_info.png`; TM disc color in `src/tm_case.c` and `graphics/tm_case/disc_types_2.pal`; Hidden Power in `src/battle_script_commands.c`; trade board in `src/data/union_room.h`; Pokédex order in `src/data/pokemon/pokedex_orders.h` |
| New abilities (78–85) | `src/pokemon.c`, `src/battle_util.c`, `src/battle_script_commands.c` |
| Permanent hail (Snow Warning) | `B_WEATHER_HAIL_PERMANENT` in `include/constants/battle.h` |
| EXP when catching, then evolving | `data/battle_scripts_2.s`, `src/battle_main.c` |
| Reusable, unique TMs | `src/party_menu.c`, `src/item.c`, `src/shop.c`, `src/tm_case.c`, `src/script_menu.c` |
| HM field moves without teaching | `GetPartyMonForFieldMove` in `src/party_menu.c`; used by `src/scrcmd.c` and `src/field_player_avatar.c` |
| Release protection (Surf) | `src/pokemon_storage_system_data.c`, `src/pokemon_storage_system_tasks.c` |
| IV/EV viewer | `src/pokemon_summary_screen.c` |
| Move relearner | `data/scripts/move_relearner_pc.inc` |
| Repel reuse prompt | `data/scripts/repel.inc`, `GetRepelToReuse` in `src/item_use.c`, `VAR_LAST_REPEL_USED` |
| Trainer AI levels | Classes in `src/data/trainer_ai_levels.h`; `GetOpponentAiLevel` and AI commands `0x5E`, `0x5F` in `src/battle_ai_script_commands.c`; replacement choice, saved ace and walled switching (`ShouldSwitchIfWalled`) in `src/battle_ai_switch_items.c`; scripts in `data/battle_ai_scripts.s` |
| Enemy trainers use no items | `BattleAI_HandleItemUseBeforeAISetup` in `src/battle_ai_script_commands.c` (the `items` fields in `trainers.h` are ignored) |
| Running everywhere and auto run | `PlayerNotOnBikeMoving` in `src/field_player_avatar.c` |
| Level cap | Numbers in `src/data/level_caps.h`; logic in `src/level_cap.c`; enforced in `Cmd_getexp` (`src/battle_script_commands.c`), `src/pokemon.c` and `src/party_menu.c` (Rare Candy), and `src/daycare.c` |
| No Bag in trainer battles | `B_ACTION_USE_ITEM` case in `src/battle_main.c` |
| Quick escape (hold B in a wild battle intro) | `BattleIntro...QuickEscape...` functions in `src/battle_main.c`; `quickEscapeFailed` in `include/battle.h`; text in `src/battle_message.c`; `BattleScript_QuickEscapeUsingItem` in `data/battle_scripts_1.s` |
| Rule switches | `optionsLevelCapOff`, `optionsTrainerItemsOn`, `optionsAutoRun` in `SaveBlock2` (0 is the default for each); defaults in `SetDefaultRules` (`src/new_game.c`); second page in `src/option_menu.c` |
| Dynamic multichoice menus | `src/script_menu.c`, `src/scrcmd.c` (script commands `0xd5`, `0xd6`) |
| Debug menu (temporary) | `data/scripts/debug_menu.inc`, `src/debug_menu.c`, `include/constants/debug_menu.h`; opened from `src/field_control_avatar.c`; switch `DEBUG_MENU` in `include/config.h` |

## Rules that prevent common breakage

- **Poryscript:** if a map has `scripts.pory`, edit only that. Its `scripts.inc` is generated and will be overwritten. All 32 pairs matched at the time of the audit.
- **Porymap:** after saving, check `git diff` for unexpected changes to maps you did not open.
- **Level-up lists must be in level order.** The game stops at the first move above the Pokémon's level (see BUG-02).
- **At most 20 level-up moves** per Pokémon for the relearner (`MAX_LEVEL_UP_MOVES`).
- **Wild encounters:** tables ending in `_FireRed` or `_LeafGreen` apply to that version only. Tables with other names (the three new ones) apply to both. Slot counts are fixed: 12 land, 5 surf, 5 Rock Smash, 10 fishing.
- **`.pal` files** need Windows (CRLF) line endings. `.gitattributes` handles this.
- **File names are case-sensitive** on some computers even though Windows ignores it (see BUG-10).
- **Flags and variables** are part of the save file. Adding flags beyond the current end changes the save layout.
- **Windows and WSL line endings:** many files can show as "modified" without real changes. Check with `git diff --ignore-cr-at-eol --stat` before committing.
- **Debug content** is still in the game. See the cleanup list in [TODO.md](TODO.md).

## Other documentation in the repository

`README.md`, `INSTALL.md`, and `docs/bugs_and_glitches.md` come from the original project. The last one lists bugs in the **original** game; this hack's problems are in [BUGS.md](BUGS.md).

## How this documentation was produced

An audit on 27 November 2026 compared `claude-edits` at `26b12e1` with the split commit by reading code, data and history. The game was not run and the full ROM was not built during the audit. Statements about in-game behaviour are marked as tested only where the owner reported testing them.
