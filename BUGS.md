# BUGS — inconsistencies, issues and bugs found

Audit date: 2026-11-27. Code checked: branch `claude-edits` at commit `26b12e1`.

The audit itself changed no game code or assets. Fixes made since then are marked in the Status column and under each bug. The descriptions show the problem as it was found.

## How to read this

| Label | Meaning |
|---|---|
| **Confirmed** | I read the code or data that causes it. It was **not** reproduced by playing the game. |
| **Likely** | The cause is confirmed, but what you would see in game is my expectation. |
| **Assumption** | It looks wrong, but it may be something you intended. Please decide. |

I could not run the game or build the full ROM here, so there may be bugs that only show up while playing.

## Summary

| ID | Severity | Confidence | Short description | Status |
|---|---|---|---|---|
| BUG-01 | High | Likely | Wild battles can start in Pallet Town before you own a Pokémon | Fixed, awaiting test |
| BUG-02 | High | Confirmed | Magneton's level-up list is out of order | Fixed, tested |
| BUG-03 | High | Confirmed | Cinnabar Battle House is a copy of the Cerulean one and has no trainers | Deferred by you |
| BUG-04 | High | Confirmed | Only Mewtwo can learn the Route 15 elemental punches | Fixed, tested |
| BUG-05 | Medium | Confirmed | Confusion and disobedience self-hits use the wrong damage rules | Fixed, tested |
| BUG-06 | Medium | Confirmed | Victory music never plays after knocking out a wild Pokémon | Fixed, tested |
| BUG-07 | Medium | Confirmed | NPC hints mention things that are not in the game yet | Open |
| BUG-08 | Medium | Confirmed | Seafoam Resort cannot be reached and its exits are wrong | Open |
| BUG-09 | Medium | Likely | Two doors lead to the wrong place (Route 5, Cinnabar Island) | Open |
| BUG-10 | Medium | Confirmed | Build fails on case-sensitive computers (Seafoam folder name) | Open |
| BUG-11 | Low | Confirmed | `poryscript` is not marked as runnable | Open |
| BUG-12 | Low | Confirmed | Using a TM can read past the end of the item effect table | Fixed, tested |
| BUG-13 | Low | Confirmed | Ariados and Donphan have one more move than the relearner can hold | Open |
| BUG-14 | Low | Confirmed | Mr. Nuzlocke rewards can be missed after beating the game | Open |
| BUG-15 | Low | Confirmed | Early National Dex means two vanilla events behave differently | Open |
| BUG-16 | Low | Confirmed | Rare Candy man and elemental tutors have small script faults | Open |
| BUG-17 | Low | Confirmed | Ice Body and Snow Cloak holders are not protected from hail by the ability itself | Open |
| BUG-18 | Low | Confirmed | Typos and small code tidiness issues | Open |
| BUG-19 | Low | Confirmed | In double battles the enemy can try to switch in a Pokémon already out (from the original game) | Fixed, awaiting test |

---

## High

### BUG-01: Wild battles can start in Pallet Town before you own a Pokémon
**Status (2026-11-27):** Fixed, awaiting your test. The added Pallet Town grass encounters were removed, so the wild tables match the original game. The grass tiles remain as decoration.

- **Where:** Pallet Town tall grass (6 tiles, map position x 22–24, y 3–4); table `sPalletTown_FireRed` in `src/data/wild_encounters.json`.
- **Confirmed:** The grass is walkable and in the open next to the houses, it has an encounter table, and the encounter code (`src/wild_encounter.c`) does not check whether you have a Pokémon.
- **Likely:** Walking in it before choosing a starter starts a battle with an empty party, which the game is not designed for.
- **Also:** 4 of the 12 slots (the common ones, 60% of encounters) are a **level 31 Murkrow**. The rest are level 5 Kabuto, Unown, Krabby, Bulbasaur, Ivysaur, Venusaur and Heracross. This looks like test data, or an intentional challenge (**Assumption** either way).
- **Possible fix:** Decide whether the grass belongs there. If it does, block it until you have a starter and set the levels you want.

### BUG-02: Magneton's level-up list is out of order
**Status (2026-11-27):** Fixed, and you reported it tested. The Flash Cannon line now sits next to the other level 57 move. No move or level changed.

- **Where:** `sMagnetonLevelUpLearnset` in `src/data/pokemon/level_up_learnsets.h`.
- **Cause:** The list starts `1 Metal Sound`, `57 Flash Cannon`, then `1 Tackle`… The game stops reading at the first move above the Pokémon's level.
- **Effect:** Any Magneton created below level 57 knows only **Metal Sound**. This includes the wild ones in the Power Plant (levels 31–34).
- **Possible fix:** Move the level 57 line to its correct place. (Learnset edits are on hold until you say so.)

### BUG-03: Cinnabar Battle House is a copy of the Cerulean one
**Status (2026-11-27):** Deferred. You plan to change this room later.

- **Where:** `data/maps/CinnabarIsland_BattleHouse/scripts.pory`.
- **Confirmed:** The house has a clerk but no trainers. The clerk checks the three **Cerulean** trainers (Jamie, Rogan, Jones). The prize message says "CERULEAN CITY" and "SHELL BELL" but gives a **Choice Band**.
- **Effect:** A player who cleared the Cerulean house can collect a free Choice Band.
- **Note:** This looks like an unfinished room (**Assumption**).

### BUG-04: Only Mewtwo can learn the Route 15 elemental punches
**Status (2026-11-27):** Fixed, and you reported it tested. Compatibility now follows newer official games: 89 Pokémon can learn Fire Punch, 104 Ice Punch and 109 Thunder Punch (taken from the pokeemerald-expansion reference data, including Deoxys's Normal Forme list).

- **Where:** `src/data/pokemon/tutor_learnsets.h`; tutors in `data/maps/Route15_HouseofElements/`.
- **Confirmed:** Ice Punch, Fire Punch and Thunder Punch tutor flags are set for Mewtwo only.
- **Effect:** The three tutors refuse almost every Pokémon.
- **Likely cause:** The compatibility list was never filled in (**Assumption**).

## Medium

### BUG-05: Confusion and disobedience self-hits use the wrong rules
**Status (2026-11-27):** Fixed, and you reported it tested. `CalculateBaseDamage` now uses the move passed to it, and Technician is skipped for self-hits.

- **Where:** `CalculateBaseDamage` in `src/pokemon.c`.
- **Cause:** It decides physical or special from the move you **chose** (`gCurrentMove`), not from the move passed in. Self-hits pass in a stand-in physical move.
- **Effects:**
  - If the chosen move is **special**, the self-hit uses Sp. Atk and Sp. Def.
  - If the chosen move is a **status** move, the self-hit does only about 2 damage.
  - Technician always boosts the self-hit (its power is 40). Iron Fist or Reckless boost it if the chosen move is on their list.
- **Possible fix:** Use the passed-in move for the category check, and skip these abilities for self-hits.

### BUG-06: Victory music never plays after knocking out a wild Pokémon
**Status (2026-11-27):** Fixed, and you reported it tested. The music now plays only when the wild Pokémon has fainted, so catching does not trigger it.

- **Where:** `Cmd_getexp` in `src/battle_script_commands.c`.
- **Cause:** The music only starts if the enemy has no Poké Ball recorded. Every newly created Pokémon is recorded with a Poké Ball, so the condition is never true.
- **Assumption:** The check was meant to tell catching apart from knocking out.

### BUG-07: NPC hints mention things that are not in the game yet
- **Viridian City (Old Rod giver):** says the Old Rod usually nets **Goldeen or Remoraid**. In every FireRed encounter table the Old Rod only catches **Magikarp**, and Remoraid is not obtainable anywhere.
- **Vermilion City (Good Rod giver):** says you might find **Electric Pokémon** in Vermilion waters. The Vermilion tables contain none.
- **Vermilion Fossil House:** a worker suggests finding the **Root Fossil** and **Claw Fossil** "somewhere". I found no way to get either one, so Lileep and Anorith cannot be obtained.
- **Assumption:** These may be changes you planned but have not made. If you remember making them in Porymap, check they were saved.

### BUG-08: Seafoam Resort cannot be reached
- **Where:** `data/maps/SeaFoamResort/map.json`.
- **Confirmed:** No door anywhere leads into it. Its exit at (14, 34) leads back to itself, and its exit at (14, 7) leads to the rival's house door in Pallet Town. All 7 people and Pokémon in it have no script.
- **Effect:** Mantine, which only appears there, cannot be obtained.
- **Assumption:** Unfinished area.

### BUG-09: Two doors lead to the wrong place
- **Route 5**, door at (23, 11): drops you elsewhere on Route 5 (by the Underground Path entrance), one way.
- **Cinnabar Island**, door at (8, 16): leads into the Gym, the same as the real Gym door.
- **Assumption:** Placeholders. I did not check visually whether the Cinnabar one is on a visible door.

### BUG-10: Build fails on case-sensitive computers
- **Where:** `data/maps/SeaFoamResort/` and `data/layouts/SeaFoamResort/` are stored with a capital **F**, but the game files ask for `SeafoamResort`.
- **Effect:** Works on your Windows drive, which ignores capitals. A normal Linux or Mac case-sensitive copy would not find the files.

## Low

### BUG-11: `poryscript` is not marked as runnable
`tools/poryscript/poryscript` is stored without "executable" permission. On a native Linux copy, rebuilding scripts fails with `Permission denied`. Your Windows drive under WSL is not affected.

### BUG-12: Using a TM can read past the item effect table
**Status (2026-11-27):** Fixed, and you reported it tested. The limit is now `ITEM_UP_GRADE`, the last item in the effect table, and `GetItemEffectType` ignores items with no effect.

`IS_POKEMON_ITEM` in `include/constants/items.h` lost its upper limit (so the new evolution items would work). TM item numbers are far beyond the end of `gItemEffectTable`, and `GetItemEffectType` does not check. It works in practice today, but what it reads is undefined and could change as the game changes. A fix is to restore a limit that includes the highest evolution item.

### BUG-13: Ariados and Donphan have 21 level-up moves
The limit used by the move relearner is 20 (`MAX_LEVEL_UP_MOVES`). The 21st move (Ariados: Megahorn at 51; Donphan: Fissure at 68) can be learned by leveling but not relearned. Eevee also lists Tackle twice at level 1.

### BUG-14: Mr. Nuzlocke rewards can be missed
After the game is cleared he only says "Good work dude". A player who had not collected the Hidden Power TM or Focus Band by then cannot get them. The TM and Focus Band are also marked as given even if the bag was too full.

### BUG-15: Early National Dex changes two vanilla events
The National Dex is switched on when you first receive the Pokédex. As a result:
- Professor Oak's post-game National Dex scene never starts.
- The Three Island Dunsparce Tunnel is already dug out, and the Nugget can be collected, on your first visit.

I found no progression blocker: the Celio quest and the roaming legendary Pokémon now depend on beating the game, as you set up. (**Confirmed** in scripts, not played through.)

### BUG-16: Small script faults
- Rare Candy man: "Come back for more?" is missing a comma before its message-box setting, so the setting is ignored (no visible problem expected, **Assumption**).
- Mr. Nuzlocke: the after-game-clear line ends without `release`, unlike his other lines. Nearby characters may stay frozen until you leave the room (**Assumption**).
- Route 15 tutors: can be used over and over, do not check whether the Pokémon already knows the move, and share one "decline" message.
- Vermilion Good Rod giver: marks the rod as received even if it could not be given.
- Fossil scientist: if there is no room for the revived Pokémon, he says so and can then continue into his "no fossil" line.

### BUG-17: Hail protection for Ice Body and Snow Cloak
In the main games these abilities protect from hail damage on their own. Here only Ice types are protected. Every current holder is an Ice type, so you will only notice if the ability is copied or swapped.

### BUG-18: Typos and tidiness
- Text: "Recieved" (fossil scientist), "a a CLAW FOSSIL", "SUNKIRN" (Pewter Pokémon Center), "responsibilites" (Rare Candy man), a double space in Growth's description.
- `include/constants/flags.h` defines `FLAG_GOT_POTION_ON_ROUTE_1` twice (same value, harmless).
- The Deep Sea Scale and Deep Sea Tooth effect entries have swapped names in `src/data/pokemon/item_effects.h` (both do the same thing).
- A comment on the Snow Cloak accuracy line says "sand veil".
- The "PP" label window was removed from the battle move menu, but the code still writes to it. No visible problem is known (**Assumption**).
- Indentation in `CalculateBaseDamage` is uneven, which makes it easy to misread.
- Repository root contains screenshots and save states (`pokefirered-0.png` to `-3.png`, `pokefirered.ss1`, `.ss2`).

### BUG-19: Enemy switching slip in double battles
**Status (2026-11-27):** Fixed. The search now keeps the attacking Pokémon in its own variable. The same random test situations no longer produce a bad pick. It is too rare to check reliably in game.

- **Where:** `FindMonWithFlagsAndSuperEffective` in `src/battle_ai_switch_items.c`.
- **Confirmed:** Part way through its search it reuses the variable that remembers which Pokémon is already out, so in a double battle it can pick that one as the "replacement". This comes from the original game. Found while testing the AI changes; it showed up 2 times in 200,000 random test situations.

## Things to keep an eye on (not bugs)

- **Old save files:** A new flag (`FLAG_0x900`) made the saved flag list longer. Saves made before that change are probably not compatible (**Assumption**).
- **Battle AI:** Opponents still do not make special decisions around the new abilities or moves.
- **Removed Emerald trainer pictures:** Several Hoenn leader and Elite Four graphics were commented out to make room. Nothing found that still uses them (**Assumption** that this is safe).
- **Automatic checks on GitHub:** `.github/workflows` came from the original project and checks for an exact copy of the original ROM, so it is expected to fail on a ROM hack (**Assumption**; I did not look at the results).
