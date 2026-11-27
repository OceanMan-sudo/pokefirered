# TODO — roadmap and outstanding tasks

Last updated: 27 November 2026 (discovery audit). Nothing here has been started as part of the audit.

## Your roadmap outline

Saved as you wrote it ("a very rough outline that we can work on later after the audit").

**New Features:**
- ~~Reusable TMs~~
- Infinite rare candies
- Infinite repels
- ~~Remove need for HMs~~
- Updated evolution methods
- Increase Pokémon availability
- Trainer Roster updates
- Level caps
- Auto-Run, run in doors
- Allow trainers to run from battles immediately
- Remove cycling music
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

## Where each item stands

| Item | Status found in the code | Notes |
|---|---|---|
| Reusable TMs | **Done** | Also unique and unsellable |
| Infinite rare candies | **Partly** | An NPC gives 99 and refills when you run out. Starting PC also has 99 |
| Infinite repels | **Not started** | Only 99 Max Repels in the starting PC |
| Remove need for HMs | **Done** | HM item plus a compatible Pokémon (tested) |
| Updated evolution methods | **Mostly done** | No trade evolutions. 7 friendship evolutions remain |
| Increase Pokémon availability | **In progress** | See "Not obtainable" in [DESIGN.md](DESIGN.md#not-obtainable-from-pokémon-1251) |
| Trainer roster updates | **In progress** | 7 gym leaders updated. Giovanni, Elite Four, Champion and rivals unchanged |
| Level caps | **Not found** | |
| Auto-run, run indoors | **Partly** | Still hold B. Indoor running enabled in a few places |
| Allow trainers to run from battles immediately | **Unclear** | B jumps to RUN in wild battles. No other change found. Please explain what you mean |
| Remove cycling music | **Not found** | |
| Hard mode | **Not found** | |
| Physical/Special split | **Done, one bug** | BUG-05 |
| New items, moves, areas | **In progress** | 26 moves, 18 maps, no new items |
| Fairy type | **Not found** | |
| Day/Night cycle | **Not found** | |
| New Pokémon | **Not found** | |
| Battle Frontier | **Not found** | Only the original Trainer Tower |
| Legend encounter areas | **Not found** | |
| Battle Island and secret boss | **Not found** | |

## Suggested order of work

These are suggestions for us to discuss, not decisions.

### 1. Fix what can break a playthrough
- [ ] BUG-01 Pallet Town grass before the starter
- [ ] BUG-02 Magneton level-up order (needs your go-ahead, since learnsets are on hold)
- [ ] BUG-03 Cinnabar Battle House reward
- [ ] BUG-05 Self-hit damage
- [ ] BUG-06 Victory music
- [ ] BUG-12 Item effect table limit

### 2. Finish half-built content
- [ ] Cinnabar Battle House: add trainers, fix text and prize
- [ ] Route 15 tutors: decide which Pokémon can learn the punches (BUG-04)
- [ ] Seafoam Resort: add an entrance, fix exits, write the 7 characters (BUG-08)
- [ ] Pokémon Tower B1F: decide what else goes there
- [ ] `NewMap1`: give it a proper name
- [ ] Placeholder doors on Route 5 and Cinnabar (BUG-09)
- [ ] Remoraid, electric fishing, Root and Claw Fossils: add them or change the NPC lines (BUG-07)
- [ ] Decide how to obtain the remaining missing Pokémon
- [ ] Scorch Sand and Aura Sphere: add to learnsets (when learnset work starts)

### 3. Test in game
No in-game confirmation is recorded for these:
- [ ] Koga, Erika and Lt. Surge teams (committed as "UNTESTED"), plus the later edits to Sabrina, Blaine and others
- [ ] Sandstorm, hail, Solar Power and Blizzard changes
- [ ] TM changes: duplicates, shops, Game Corner, selling and holding
- [ ] Pickup giving Leftovers
- [ ] Boomburst, Draco Meteor, Leaf Storm and Psycho Power fixes
- [ ] The eight new abilities
- [ ] A full playthrough to the Hall of Fame and the Sevii Islands quest

### 4. Clean up before sharing the game
Test or debug content found. **Nothing has been removed.** "Likely" ones need your confirmation.

| Item | Where | Added by |
|---|---|---|
| Aura Sphere giver and two move tutors | Pallet Town (40,16), (38,16), (42,16); `data/scripts/item_ball_scripts.inc` | Claude (temporary) |
| Giovanni who grants the Fuchsia gym flags | Pallet Town (5,16), `EightBadges` | You |
| Chef who marks the game cleared and gives Leftovers | Pallet Town (2,16), `ClearGame` | You |
| Doors from Pallet Town to other towns (likely) | Pallet Town, row 4, x 37–45 | You |
| Starting PC items (likely) | `src/player_pc.c` | You |
| Level 31 Murkrow and rare species in Pallet grass (possibly) | `wild_encounters.json` | You |
| Unplaced `Tester` script | `data/maps/Route2/scripts.pory` | You |
| Unused original Fishing Guru script | `data/maps/VermilionCity_House1/scripts.pory` | You |
| Screenshots and save states | Repository root | You |

### 5. Housekeeping
- [ ] Rename the `SeaFoamResort` folders to `SeafoamResort` (BUG-10)
- [ ] Mark `poryscript` as runnable (BUG-11)
- [ ] Typos and tidy-ups (BUG-16, BUG-18)
- [ ] Decide when to merge `claude-edits` into `master`

## Questions for the scope discussion
1. Is this hack mainly a quality-of-life remake, a harder challenge, or a bigger adventure with new areas?
2. What does "Allow trainers to run from battles immediately" mean to you?
3. Which Pokémon should be obtainable: the first 251, or some Generation 3 as well?
4. Should infinite candies and repels be key items, NPCs or menu options?
5. Should level caps apply always, or only in Hard mode?
6. Fairy type affects types, moves, the type chart and graphics. Is it a priority?
7. Are Pallet Town's grass and test shortcuts meant to stay?
