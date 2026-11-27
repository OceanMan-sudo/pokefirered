# TODO — roadmap and outstanding tasks

Last updated: 27 November 2026, after the scope discussion. Items are not started unless marked done.

## Version 1 goal

A quality-of-life upgrade and a new difficulty curve with fresh teams, across a freshened-up Kanto, with rules that suit Nuzlocke play. Bigger new adventures are a stretch goal.

## Decisions

| Topic | Decision |
|---|---|
| Code base | Stay on the current code. Do not switch to the pokeemerald-expansion toolkit (artwork or ideas may still be borrowed, with credit) |
| Audience | Only you |
| Game version | FireRed first. A redone LeafGreen maybe later |
| Pokémon | Focus on the original 386. Evolutionary relatives, and maybe more legends, later |
| Fairy type | Follow Generation 6, including the type chart |
| Learnsets | Modernize a bit without upsetting balance or making Pokémon feel alike. **On hold until you start it** |
| Trainers | Every trainer gets updated. AI updated a little, not brutally hard |
| Level cap | Hard cap: no EXP and no Rare Candies at the cap. Lifts after the first Champion clear |
| Default rules | No difficulty mode. Set battle style, no items in battle and level cap on by default, each switchable in the menu |
| Enemy trainers | Never use items |
| Rare Candies | Keep the house that gives them |
| Repels | Infinite repels dropped. Prompt to use another when one runs out. Prices 10, 20, 30 |
| Running | Run from the start (no shoes needed), allowed everywhere, auto-run switchable |
| Pewter City aide | Gives a starter type booster as a gift from Mom, in place of the Running Shoes |
| Wild battles | Holding B as the wild Pokémon slides in prompts you to escape. The usual escape checks apply |
| All 386 obtainable | Not required for version 1; some can wait |
| Unfinished areas | Seafoam Resort, Pokémon Tower B1F, `NewMap1` and Cinnabar Battle House are part of version 1, tackled later |
| New areas | Both after the story and woven into it. Ideas later |

## Open questions

- [ ] Level caps: confirm the numbers (see the level curve), and decide how the cap works during the League

## Order of work

Serious bugs, then easy features, then Fairy type and teams. Day/night and new Pokémon come later. Difficulty ratings are estimates, and every change needs your in-game test.

### Phase 1: fix serious bugs
Details are in [BUGS.md](BUGS.md).
- [x] BUG-01 Wild battles in Pallet Town before you have a Pokémon (grass battles removed)
- [x] BUG-02 Magneton's level-up order
- [ ] BUG-03 Cinnabar Battle House free Choice Band (**deferred:** to be changed later)
- [x] BUG-04 Route 15 punch compatibility (newer games' lists)
- [x] BUG-05 Confusion and disobedience self-hit damage
- [x] BUG-06 Victory music
- [x] BUG-12 TM use reads past the item effect table

Checked items are fixed in the code. Test them using the list under [Waiting to be tested](#waiting-to-be-tested).

### Phase 2: easy features
- [x] Running from the start, with no shoes needed
- [x] Running allowed indoors and everywhere else it was blocked
- [x] Enemy trainers never use items
- [x] Prompt to use another Repel when one runs out
- [x] Repel prices set to 10, 20 and 30
- [x] Remove the cycling music
- [x] Pewter City aide gives Mom's starter gift

Checked items are in the code. Test them using the list under [Waiting to be tested](#waiting-to-be-tested).

### Phase 3: rules and battle features
Build the rules and their menu switches together.

| Done | Feature | Difficulty |
|---|---|---|
| ☐ | Hard level cap, blocks EXP and Rare Candies, lifts after Champion | Easy to medium |
| ☐ | Set battle style by default | Easy |
| ☐ | No items in trainer battles by default (your side; enemy trainers already never use items) | Easy |
| ☐ | Menu switches for Set, items and level cap | Medium |
| ☐ | Auto-run switch | Easy to medium |
| ☐ | Hold B as a wild Pokémon slides in to get an escape prompt (usual escape checks) | Medium |
| ☐ | AI update: better existing logic for more trainers, plus small tweaks | Easy to medium |

### Phase 4: Fairy type (medium)
- [ ] Add the type and include it everywhere types are listed
- [ ] Generation 6 type chart (includes Steel no longer resisting Ghost and Dark)
- [ ] Retype the 18 Pokémon that become Fairy
- [ ] Retype Charm, Sweet Kiss and Moonlight
- [ ] Stop Hidden Power from rolling Fairy
- [ ] Type label, colours and TM disc colour
- [ ] New Fairy moves and animations (Moonblast, Play Rough, Dazzling Gleam and others you choose)

### Phase 5: groundwork for the Kanto pass
Do these before changing teams area by area, so work is not redone.
- [ ] Agree the level curve (below)
- [ ] Learnsets (**on hold until you say**). Teams without hand-picked moves use level-up moves
- [ ] Add Scorch Sand, Aura Sphere and the new Fairy moves to learnsets as part of that work
- [ ] Decide whether the 7 remaining friendship evolutions should change
- [ ] Plan where each missing Pokémon will come from (list at the end)

#### Level curve

| Milestone | Highest enemy level now | New level cap |
|---|---|---|
| Brock | 14 | to decide |
| Misty | 23 | to decide |
| Lt. Surge | 26 | to decide |
| Erika | 34 | to decide |
| Koga | 43 | to decide |
| Sabrina | 44 | to decide |
| Blaine | 46 | to decide |
| Giovanni | 50 | to decide |
| Lorelei, Bruno, Agatha, Lance | 54, 56, 58, 60 | to decide |
| Champion (first time) | 63 | to decide, then the cap lifts |

Koga, Sabrina and Blaine can be fought in more than one order in the original game, so decide whether the caps should force an order.

### Phase 6: Kanto pass, town by town and route by route

For each area:
1. **Clean-up and updates:** you walk through it and list what to change (map, doors, people, signs, text, items, test content).
2. **Encounters:** wild Pokémon, rates and levels, including places for missing Pokémon.
3. **Teams and levels:** every trainer's team, moves and levels, fitted to the level curve.
4. **Test** in game, then change ☐ to ✅.

"Teams changed 1/8" means 1 of 8 trainers differs from the original. Levels are what the code has now. Wild levels cover grass and cave floors only; surfing, fishing and Rock Smash need checking too. Rival and Champion fights are noted but not counted. The order is a suggested play order.

#### Part 1: to Brock

| Area | Now | Clean-up | Encounters | Teams |
|---|---|---|---|---|
| Pallet Town | Rival fight; wild tables same as the original; 3 new maps | ☐ | ☐ | ☐ |
| Route 1 | Wild tables changed 1/1, Lv 2–5 | ☐ | ☐ | — |
| Viridian City | Wild tables changed 0/1; 1 new map; Nuzlocke house; Old Rod hint (BUG-07) | ☐ | ☐ | — |
| Route 22 | Rival fight; wild tables changed 1/1, Lv 2–5 | ☐ | ☐ | ☐ |
| Route 2 | Teams changed 1/1, Lv 5; wild tables changed 1/1, Lv 3–5 | ☐ | ☐ | ☐ |
| Viridian Forest | Teams changed 0/5, Lv 6–9; wild tables changed 1/1, Lv 3–8 | ☐ | ☐ | ☐ |
| Pewter City | Teams changed 1/2, Lv 10–14; wild tables changed 1/1, Lv 3–6; 1 new map | ☐ | ☐ | ☐ |

#### Part 2: to Misty

| Area | Now | Clean-up | Encounters | Teams |
|---|---|---|---|---|
| Route 3 | Teams changed 0/8, Lv 9–14; wild tables changed 1/1, Lv 3–8 | ☐ | ☐ | ☐ |
| Mt. Moon | Teams changed 0/12, Lv 10–14; wild tables changed 3/3, Lv 5–12 | ☐ | ☐ | ☐ |
| Route 4 | Teams changed 0/1, Lv 31; wild tables changed 1/1, Lv 10–13 | ☐ | ☐ | ☐ |
| Cerulean City | Teams changed 4/7, Lv 15–23; rival fight; wild tables changed 1/1, Lv 15–19; 2 new maps | ☐ | ☐ | ☐ |

#### Part 3: to Lt. Surge

| Area | Now | Clean-up | Encounters | Teams |
|---|---|---|---|---|
| Route 24 | Teams changed 6/7, Lv 10–17; wild tables changed 1/1, Lv 9–14 | ☐ | ☐ | ☐ |
| Route 25 | Teams changed 0/9, Lv 13–17; wild tables changed 1/1, Lv 9–14 | ☐ | ☐ | ☐ |
| Route 5 | Wild tables changed 1/1, Lv 10–16; Wrong door (BUG-09) | ☐ | ☐ | — |
| Route 6 | Teams changed 0/6, Lv 16–20; wild tables changed 1/1, Lv 12–16 | ☐ | ☐ | ☐ |
| Underground Paths | No trainers or wild Pokémon | ☐ | — | — |
| Vermilion City | Teams changed 1/4, Lv 21–26; wild tables changed 0/1; 2 new maps; Rod and fossil hints (BUG-07) | ☐ | ☐ | ☐ |
| S.S. Anne | Teams changed 0/16, Lv 17–23; rival fight; wild tables changed 0/1 | ☐ | ☐ | ☐ |

#### Part 4: to Erika

| Area | Now | Clean-up | Encounters | Teams |
|---|---|---|---|---|
| Route 11 | Teams changed 0/10, Lv 17–21; wild tables changed 1/1, Lv 11–22 | ☐ | ☐ | ☐ |
| Diglett's Cave | Wild tables changed 1/1, Lv 15–31 | ☐ | ☐ | — |
| Route 9 | Teams changed 0/9, Lv 18–23; wild tables changed 1/1, Lv 13–18 | ☐ | ☐ | ☐ |
| Route 10 | Teams changed 0/6, Lv 19–29; wild tables changed 1/1, Lv 11–17 | ☐ | ☐ | ☐ |
| Rock Tunnel | Teams changed 0/15, Lv 19–25; wild tables changed 2/2, Lv 13–22 | ☐ | ☐ | ☐ |
| Lavender Town | No trainers or wild Pokémon | ☐ | — | — |
| Route 8 | Teams changed 0/12, Lv 19–26; wild tables changed 1/1, Lv 15–20 | ☐ | ☐ | ☐ |
| Route 7 | Wild tables changed 1/1, Lv 17–22 | ☐ | ☐ | — |
| Celadon City | Teams changed 1/9, Lv 20–34; wild tables changed 1/1, Lv 19–24; 3 new maps | ☐ | ☐ | ☐ |
| Rocket Hideout | Teams changed 1/12, Lv 17–30 | ☐ | — | ☐ |

#### Part 5: Koga, Sabrina and Blaine

| Area | Now | Clean-up | Encounters | Teams |
|---|---|---|---|---|
| Pokémon Tower | Teams changed 0/16, Lv 22–26; rival fight; wild tables changed 6/6, Lv 13–33; 1 new map; New basement unfinished | ☐ | ☐ | ☐ |
| Route 12 | Teams changed 0/8, Lv 21–29; wild tables changed 1/1, Lv 22–33 | ☐ | ☐ | ☐ |
| Route 13 | Teams changed 0/10, Lv 24–30; wild tables changed 1/1, Lv 22–30 | ☐ | ☐ | ☐ |
| Route 14 | Teams changed 0/11, Lv 26–33; wild tables changed 1/1, Lv 22–29 | ☐ | ☐ | ☐ |
| Route 15 | Teams changed 0/11, Lv 25–33; wild tables changed 1/1, Lv 22–30; 1 new map | ☐ | ☐ | ☐ |
| Route 16 | Teams changed 0/7, Lv 28–33; wild tables changed 1/1, Lv 18–25 | ☐ | ☐ | ☐ |
| Route 17 | Teams changed 0/10, Lv 25–33; wild tables changed 1/1, Lv 20–30 | ☐ | ☐ | ☐ |
| Route 18 | Teams changed 0/3, Lv 26–34; wild tables changed 1/1, Lv 20–29 | ☐ | ☐ | ☐ |
| Fuchsia City | Teams changed 1/7, Lv 31–43; wild tables changed 0/1 | ☐ | ☐ | ☐ |
| Safari Zone | Wild tables changed 0/4, Lv 22–33 | ☐ | ☐ | — |
| Saffron City | Teams changed 5/17, Lv 31–44; 1 new map | ☐ | — | ☐ |
| Silph Co. | Teams changed 0/31, Lv 25–41; rival fight | ☐ | — | ☐ |
| Power Plant | Wild tables changed 1/1, Lv 22–35 | ☐ | ☐ | — |
| Route 19 | Teams changed 0/11, Lv 27–30; wild tables changed 0/1 | ☐ | ☐ | ☐ |
| Route 20 | Teams changed 0/10, Lv 28–35; wild tables changed 0/1 | ☐ | ☐ | ☐ |
| Seafoam Islands | Wild tables changed 5/5, Lv 22–34 | ☐ | ☐ | — |
| Cinnabar Island | Teams changed 1/8, Lv 34–46; wild tables changed 0/1; 1 new map; Battle House and a door (BUG-03, 09) | ☐ | ☐ | ☐ |
| Pokémon Mansion | Teams changed 0/7, Lv 29–38; wild tables changed 4/4, Lv 28–42 | ☐ | ☐ | ☐ |
| Route 21 | Teams changed 0/9, Lv 27–37; wild tables changed 1/2, Lv 17–29 | ☐ | ☐ | ☐ |

#### Part 6: Sevii Islands 1–3 and Giovanni

| Area | Now | Clean-up | Encounters | Teams |
|---|---|---|---|---|
| One Island | Teams changed 0/13, Lv 33–39; wild tables changed 2/3, Lv 27–40 | ☐ | ☐ | ☐ |
| Mt. Ember | Teams changed 0/5, Lv 35–40; wild tables changed 10/10, Lv 29–42 | ☐ | ☐ | ☐ |
| Two Island | Wild tables changed 1/1, Lv 30–40 | ☐ | ☐ | — |
| Three Island | Teams changed 0/10, Lv 34–39; wild tables changed 3/3, Lv 5–44 | ☐ | ☐ | ☐ |
| Viridian Gym | Teams changed 0/9, Lv 37–50; Giovanni’s team is unchanged | ☐ | — | ☐ |

#### Part 7: the League

| Area | Now | Clean-up | Encounters | Teams |
|---|---|---|---|---|
| Route 23 | Wild tables changed 1/1, Lv 32–44 | ☐ | ☐ | — |
| Victory Road | Teams changed 0/12, Lv 40–48; wild tables changed 3/3, Lv 33–55 | ☐ | ☐ | ☐ |
| Indigo Plateau and League | Teams changed 0/8, Lv 51–72; Champion fight; Highest levels include rematch teams | ☐ | — | ☐ |

#### Part 8: after the Champion

| Area | Now | Clean-up | Encounters | Teams |
|---|---|---|---|---|
| Cerulean Cave | Wild tables changed 0/3, Lv 46–67 | ☐ | ☐ | — |
| Four Island | Teams changed 0/1, Lv 38; wild tables changed 0/5, Lv 23–53 | ☐ | ☐ | ☐ |
| Five Island | Teams changed 0/23, Lv 46–55; wild tables changed 0/19, Lv 6–52 | ☐ | ☐ | ☐ |
| Six Island | Teams changed 0/29, Lv 45–50; wild tables changed 0/14, Lv 3–52 | ☐ | ☐ | ☐ |
| Seven Island | Teams changed 0/18, Lv 47–52; wild tables changed 0/11, Lv 10–54 | ☐ | ☐ | ☐ |
| Trainer Tower | No trainers or wild Pokémon | ☐ | — | — |
| Navel Rock and Birth Island | No trainers or wild Pokémon | ☐ | — | — |

#### Unfinished new areas

| Area | Now | Clean-up | Encounters | Teams |
|---|---|---|---|---|
| Seafoam Resort | Wild tables changed 1/1; 1 new map; No entrance, wrong exits (BUG-08) | ☐ | ☐ | — |
| `NewMap1` | 1 new map; Needs a name and purpose | ☐ | — | — |

There are 455 placed trainers in these tables (22 changed), not counting rival and Champion fights. Rematch versions are extra. This replaces my earlier estimate of "about 740", which counted unused trainer slots.

### Phase 7: finish version 1
- [ ] Finish the unfinished areas: Seafoam Resort (BUG-08), Pokémon Tower B1F, `NewMap1`, Cinnabar Battle House (BUG-03)
- [ ] Full playthrough to the Hall of Fame and the Sevii Islands quest
- [ ] **Remove the debug menu** (you asked to be reminded; steps under "Removing the debug menu")
- [ ] Remove test content (table below)
- [ ] Remaining bugs and typos in [BUGS.md](BUGS.md) (BUG-10, 11, 13, 14, 15, 16, 17, 18)
- [ ] Rename the `SeaFoamResort` folders to `SeafoamResort` and mark `poryscript` as runnable
- [ ] Decide when to merge `claude-edits` into `master`

## Later and stretch goals

| Goal | Notes |
|---|---|
| New areas, legend areas | Easy for buildings, medium for routes and towns. Waiting on your ideas |
| Battle Island and secret boss | Waiting on your ideas |
| Evolutionary relatives | About 30 extra Pokédex entries should fit without changing the save layout, with one adjustment (read from code, untested). Enough for the 29 Generation 4 relatives plus Sylveon. Toolkit artwork could be adapted, with credit |
| Day/night | Medium to hard. An in-game clock is simpler than real-world time |
| Battle Frontier | Hard. Would have to be ported from Emerald |
| Your own new Pokémon | Needs original art and sounds |
| More legends | After the 386 |
| LeafGreen | After FireRed |

## Already done

- Reusable, unique TMs
- HM field moves without teaching them
- Physical/Special split
- 26 new moves and 8 new abilities
- Evolution changes with no trade evolutions (7 friendship evolutions remain)
- House that gives Rare Candies

## Waiting to be tested
Ticked items: you reported on 27 November 2026 that they work.
- [x] Koga, Erika and Lt. Surge teams (committed as "UNTESTED"), plus the later edits to Sabrina, Blaine and others
- [x] Sandstorm, hail, Solar Power and Blizzard changes
- [x] TM changes: duplicates, shops, Game Corner, selling and holding
- [x] Pickup giving Leftovers
- [x] Boomburst, Draco Meteor, Leaf Storm and Psycho Power fixes
- [x] The eight new abilities
- [x] Phase 1 fixes: Magneton's moves, punch tutors, confusion damage, victory music, TMs and evolution items
- [x] Running without shoes, indoors and on Cycling Road
- [x] Music while biking, including Cycling Road
- [x] A gym leader battle with no enemy items
- [x] Repel prompt (yes, no, and with no Repels left) and shop prices
- [x] Mom's gift in Pewter City, for each starter if possible
- [x] Debug menu: every option (hold B, press SELECT)
- [ ] Pallet Town after the clean-up: the two people and nine doors are gone, and the house and lab doors still work
- [ ] A new game: only a Potion in the PC, and no wild battles in the Pallet Town grass

## Test content to remove
Removed on 27 November 2026: the Pallet Town Giovanni and chef, the nine warp doors, the added starting PC items, the Pallet Town grass battles and the unused Route 2 `Tester` script. The items below are still in the game. "Likely" ones need your confirmation. Keep any you still use for testing until Phase 7.

| Item | Where | Added by |
|---|---|---|
| Unused original Fishing Guru script | `data/maps/VermilionCity_House1/scripts.pory` | You |
| Screenshots and save states | Repository root | You |
| **Debug menu** (hold B, press SELECT) | See below | Claude, at your request |

### Removing the debug menu

Before version 1 is finished. To only switch it off, set `DEBUG_MENU` to `FALSE` in `include/config.h` (the button combination stops working). To remove it completely:

1. Delete `src/debug_menu.c`, `data/scripts/debug_menu.inc` and `include/constants/debug_menu.h`.
2. Remove the `#if DEBUG_MENU` block in `src/field_control_avatar.c` and the `DEBUG_MENU` lines in `include/config.h`.
3. Remove the two `.include` / `#include` lines in `data/event_scripts.s`.
4. Remove the five `DebugMenu_` lines in `data/specials.inc`.
5. Remove `EventScript_DebugMenu` from `include/event_scripts.h`.
6. Remove the two `debug_menu.o` lines in `ld_script.ld`.

## Pokémon without a source

A code check found no way to get these 88 Pokémon (wild, gifts, set encounters, evolution, breeding and trades were considered; not tested in game).

- **Generations 1 and 2:** Staryu, Starmie, Mew, Chikorita, Bayleef, Meganium, Cyndaquil, Quilava, Typhlosion, Totodile, Croconaw, Feraligatr, Chinchou, Lanturn, Remoraid, Octillery, Mantine, Lugia, Ho-Oh, Celebi
- **Generation 3:** Treecko, Grovyle, Sceptile, Torchic, Combusken, Blaziken, Mudkip, Marshtomp, Swampert, Nincada, Ninjask, Shedinja, Surskit, Masquerain, Wailmer, Wailord, Kecleon, Baltoy, Claydol, Nosepass, Sableye, Barboach, Whiscash, Luvdisc, Feebas, Milotic, Carvanha, Sharpedo, Spheal, Sealeo, Walrein, Cacnea, Cacturne, Snorunt, Glalie, Lunatone, Solrock, Mawile, Swablu, Altaria, Tropius, Whismur, Loudred, Exploud, Clamperl, Huntail, Gorebyss, Absol, Seviper, Zangoose, Relicanth, Lileep, Cradily, Anorith, Armaldo, Beldum, Metang, Metagross, Regirock, Regice, Registeel, Kyogre, Groudon, Rayquaza, Latias, Latios, Jirachi, Deoxys

Also note:
- Mantine appears only in the unreachable Seafoam Resort. Lugia, Ho-Oh and Deoxys need event tickets nothing gives. The Root and Claw Fossils have no source.
- Only one of Raikou, Entei and Suicune appears per save, and some others are one-time choices (starters, fossils), so a single save needs another source for the rest.
- Some of today's sources may be removed during clean-up. With the Pallet Town grass battles gone, the Bulbasaur line comes only from the starter choice.

## Your original roadmap outline

Kept as you first wrote it. The decisions above replace it where they differ.

**New Features:**
- ~~Reusable TMs~~
- Infinite rare candies
- ~~Infinite repels~~ (dropped)
- ~~Remove need for HMs~~
- Updated evolution methods
- Increase Pokémon availability
- Trainer Roster updates
- Level caps
- Auto-Run, run in doors
- Allow trainers to run from battles immediately
- ~~Remove cycling music~~
- Hard mode (no items in trainer battles, level cap)
- Physical/Special split
- New items, moves, and potentially new areas
- Fairy Type

**Stretch Goals:**
- Day/Night cycle
- New Pokémon
- Battle Frontier
- New areas for legend encounters
- Battle Island w/Secret Boss
