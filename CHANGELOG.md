# CHANGELOG — known modifications

Compared with the original decompilation at commit `539ed3616` (29 August 2024). Changes made by the original project after that date are not counted.

- **Your work** is on `master`: 163 commits, including 2 from RavePossum.
- **Claude-assisted work** is on `claude-edits`: 57 commits (some are temporary test setups and their removal).

Tables were generated from the game files, so they show the **net difference** from the original. **Confirmed** means present in the code. **Tested** is used only where you reported that something worked in game.

## Still to test
Claude-assisted changes you have not yet reported as working.

- **Pallet Town clean-up:** the two people and nine doors are gone, and the house and lab doors still work.
- **New game:** only a Potion in the PC, and no wild battles in the Pallet Town grass.
- **Quick escape:** answering No, a much slower lead Pokémon, no box when it should not appear, the Smoke Ball and the Pokémon Tower ghost.
- **Walled bosses switching** (testing in progress).
- **Dragon Rage against Fairy types:** checked in a simulator only.
- **Fairy move special cases:** Drain Kiss against Liquid Ooze, Fae Voice against Soundproof, and opponents using the spread moves.
- **Multi-hit moves:** the new odds and accuracy.
- **Reworked animations:** Bulldoze, Wild Charge and the Shell Smash shell break.
- **Four support moves:** Quiver Dance, Shell Smash, Aurora Veil and Tailwind.
- **Five-turn weather abilities:** Drizzle, Drought, Sand Stream and Snow Warning.
- **Ability fixes:** Solar Power's HP cost, hail immunity for Ice Body and Snow Cloak, the second-ability setting for trainers, and Seel's type.
- **Eleven more abilities:** these can be tried once Pokémon have been given them.
- **Sturdy and Magma Armor:** the new full-HP survival and the Water immunity.
- **Brock's Geodude** having Sturdy, caught Slugma showing Magma Armor, and the debug menu's Ability option.
- **Other AI fixes:** healing when hurt, Soundproof, immunities and the new weather abilities. The Physical/Special and Facade decisions were not checked one by one.
- **Double battle switching fix (BUG-19):** too rare to check reliably in game.

Step-by-step checks are in [TODO.md](TODO.md#waiting-to-be-tested).

## Timeline

| When | Main work (from commit messages) |
|---|---|
| May–Aug 2024 | RavePossum's dynamic multichoice (merged September 2024) |
| 5–10 Sep 2024 | Evolution methods, Pallet Town expansion, Poryscript, Physical/Special split and icons, EXP on catching, Rare Candy man, new Pallet homes |
| 11–17 Sep 2024 | National Dex checks changed and Dex enabled from the start, Viridian expansion, House of Nuzlocke, Pewter berry house and shop, first new moves, Nugget Bridge double battles, B-to-Run |
| 22 Sep 2024 | Vermilion changes, fossil revival |
| 22–25 Feb 2025 | Berry houses, rain, Milotic evolution, Pokémon Tower basement, Celadon shops, Route 2 trainer, Saffron and Cerulean battle houses, Fuchsia item ball |
| 3–5 Mar 2025 | More new moves, Pokémon type changes |
| 9–15 Jul 2025 | Learnsets, new abilities, move relearner, Cinnabar expansion, elemental punch tutors, Route 5 revamp |
| 16–29 Jul 2025 | Seafoam Resort, wild encounters, Boomburst, Night Slash, Snow Cloak, Johto learnsets |
| 28 May 2026 | Encounters, collision fixes, gym leader updates (Koga, Erika, Surge "UNTESTED") |
| 26 Nov 2026 | Trainer, learnset and TM edits ("cant remember") |
| 26–27 Nov 2026 | Claude-assisted changes (below) |

## Your changes (`master`)

### Battle and mechanics
- Physical/Special split, with category icon.
- Eight new abilities: Solar Power, Super Luck, Technician, Ice Body, Iron Fist, Reckless, Snow Warning (including permanent hail), Snow Cloak.
- Damage formula edits: type items, Thick Fat, weather and Flash Fire (see [DESIGN.md](DESIGN.md#battle-mechanics)).
- Removed Sky Attack's high critical-hit rate.
- EXP when catching; display fix for the Pokédex page after a catch.
- B moves the cursor to RUN in wild battles.
- Victory music condition changed (was faulty; fixed on `claude-edits`, BUG-06).
- EV limit per stat 255 → 252; vitamin limit 100 → 252.
- TMs made reusable.

### Progression
- National Dex enabled on receiving the Pokédex; former National Dex gates now check game clear.
- National Dex evolution block removed from the evolution scene.
- No trade evolutions; many level changes; six items now usable for evolution.
- New game PC now contains Potion, 99 Rare Candy, 99 Master Ball, TM03, Dragon Scale, 99 Nugget and 99 Max Repel (testing items; removed on `claude-edits`).

### Content
- 25 of the 46 new moves, and changes to 62 original moves.
- All of the species, learnset and TM compatibility changes below.
- 18 new maps, expanded towns, new characters, shops and gifts (see [DESIGN.md](DESIGN.md#world)).
- Trainer changes and new trainers.
- Wild encounters in 67 FireRed areas, plus tables for Pewter City, Pokémon Tower B1F and Seafoam Resort. LeafGreen tables unchanged.
- Test characters in Pallet Town: Giovanni (grants the Fuchsia gym flags) and a chef (gives Leftovers and marks the game cleared). Pallet Town also has doors to the other towns (test shortcuts). The characters and doors are removed on `claude-edits`.

### Code, tools and project files
- Poryscript added (`tools/poryscript/`, Makefile rule, 32 `.pory` map scripts).
- Dynamic multichoice script commands (RavePossum).
- Move tutor compatibility widened to fit new tutors.
- New map section "Seafoam Resort"; new flag `FLAG_0x900`; flags `0x0AF`–`0x0B8` put to use.
- Hoenn leader and Elite Four trainer pictures commented out; trainer numbers 83–88 reused.
- Screenshots and save states committed to the repository root.

## Claude-assisted changes (`claude-edits`)

### Trainer AI
| Change | In-game status |
|---|---|
| Trainer AI in three levels by trainer class; 364 trainer entries moved up, none down | Tested |
| Opponents send out the best matchup (Levels 2 and 3) or go in team order (Level 1) | Tested |
| Level 3 trainers save the last Pokémon in their team for last | Tested |
| Trainer AI uses the Physical/Special split; Facade and sandstorm/hail stalling mistakes corrected | Battles tested with nothing odd; these decisions not checked one by one |
| Faster bosses use healing moves when hurt; Sp. Atk-lowering logic checks Sp. Atk | Not yet tested |
| Trainer AI accounts for Soundproof against Boomburst and Hyper Voice, immunities against Overheat-type moves, and new weather abilities | Not yet tested |
| Level 3 trainers switch out when nothing they have can affect your Pokémon and a teammate can | Not yet tested |
| Double battle enemy switching slip fixed (BUG-19) | Not yet tested |
| Trainer AI no longer uses Dragon Rage on Pokémon immune to it | Not yet tested |
| Trainer AI recognises Snow Warning's hail | Not yet tested |
| Level 3 trainers also favor Sunny Day with Chlorophyll when slower, and Hail when it opens up Aurora Veil | Not yet tested |

### Battle
| Change | In-game status |
|---|---|
| Evolution after catching | Tested |
| Sandstorm and hail defence boosts; Solar Power respects Cloud Nine and Air Lock; only Blizzard never misses in hail | Tested |
| Drizzle, Drought, Sand Stream and Snow Warning set five turns of weather instead of lasting the whole battle | Not yet tested |
| Solar Power costs 1/8 of max HP at the end of each turn in sun | Not yet tested |
| Ice Body and Snow Cloak holders take no hail damage (BUG-17) | Not yet tested |
| Trainer Pokémon can be given their second ability. Brock's Geodude uses it for Sturdy | Not yet tested |
| Seel is a pure Water type again | Not yet tested |
| Eleven abilities added: Adaptability, Skill Link, Sniper, Tinted Lens, Sand Rush, Download, Sap Sipper, Moxie, Sheer Force, Multiscale and Regenerator. No Pokémon has them yet. Trainer AI updated to allow for them | Not yet tested |
| Sturdy also leaves its Pokémon with 1 HP after a hit that would knock it out from full HP. Trainer AI updated to match | Not yet tested |
| Magma Armor also takes in Water moves and heals from them, like Water Absorb. Trainer AI updated to match, and now allows for Water Absorb when choosing its next Pokémon | Not yet tested |
| Slugma and Magcargo no longer have Water Absorb; Magma Armor is their only ability. A species with one ability now always shows it, including Pokémon caught when it had two | Not yet tested |
| Quick escape: hold B as a wild Pokémon slides in to be asked about escaping | Partly tested (escaping, Run Away, Arena Trap) |

### Fairy type
| Change | In-game status |
|---|---|
| Fairy type with the Generation 6 matchups; Steel no longer resists Ghost or Dark | Tested |
| 18 Pokémon become Fairy; Charm, Sweet Kiss and Moonlight are Fairy moves | Tested |
| Fairy label and TM disc color; Fairy added to the Pokédex type order and the trade board; Hidden Power cannot be Fairy | Partly tested (trade board and Hidden Power not checked) |
| Clefable: Defense and Sp. Def set to Generation 6 (90→73, 95→90) | Tested |

### Moves and animations
| Change | In-game status |
|---|---|
| Soundproof blocks Boomburst; Draco Meteor and Leaf Storm non-contact; Psycho Power loses priority | Tested |
| New move: Aura Sphere with animation | Tested |
| New moves: Moonblast and Play Rough with animations | Tested |
| New moves: Fairy Wind, Drain Kiss, Dazzle Gleam and Fae Voice with animations; new drain effect that heals three quarters; Fae Voice blocked by Soundproof | Tested |
| Fire, Ice and Thunder Punch back to 75 power; Superpower back to its original form | Tested |
| Sky Attack: special, 140 power, 90 accuracy, 5 PP, lowers the user's Sp. Atk by two stages; no longer boosted by Reckless | Tested |
| Rock Slide flinch chance 30%→20%; Double Slap is Fairy | Tested |
| Multi-hit moves use modern odds for 2, 3, 4 and 5 hits (35/35/15/15%); Pin Missile accuracy 95, Bone Rush and Rock Blast 90; Bullet Seed 25 power | Not yet tested (odds checked outside the game) |
| New moves: Close Combat, Brave Bird, Wild Charge, Icicle Crash, Iron Head, Bug Buzz, Power Gem, Energy Ball, Bulldoze and Snarl with animations; new effects for Close Combat and Bulldoze; Bug Buzz and Snarl blocked by Soundproof | Tested, except the reworked Bulldoze and Wild Charge animations |
| New moves: Quiver Dance, Shell Smash, Aurora Veil and Tailwind with animations and trainer AI; four new effects; Brick Break removes Aurora Veil | Not yet tested |
| Animations fixed or redrawn: Earth Power, X-Scissor, Poison Jab, Seed Bomb, Aqua Jet, Roost, Psycho Power, Dragon Pulse, Dark Pulse, Flash Cannon, Focus Blast, Shadow Claw, Shadow Sneak | Tested (Psycho Power and Shadow Claw after a second pass) |

### Items, TMs and field moves
| Change | In-game status |
|---|---|
| TMs unique, unsellable, unholdable, no quantity; owned TMs hidden from shops | Tested |
| Pickup: TM10 replaced by Leftovers | Tested |
| HM field moves without teaching; HMs forgettable | Tested |
| Release protection for the last Surf user | Tested |
| Rock Tunnel dark again | Tested |
| Prompt to use another Repel; prices 350/500/700 → 10/20/30 | Tested |
| Pewter City aide gives a starter type booster from Mom instead of the Running Shoes | Tested |

### Rules, options and screens
| Change | In-game status |
|---|---|
| IV/EV view with SELECT on the summary screen | Tested |
| Running from the start and on every map and tile | Tested |
| Cycling theme removed | Tested |
| Enemy trainers never use items | Tested |
| Level cap by badge count: no EXP or Rare Candies at the cap, EVs still earned, Day Care stops at the cap, lifts after the Champion | Tested |
| New games start in Set battle style (was Shift) | Tested |
| Your Bag cannot be used in trainer battles unless switched on | Tested |
| Auto run, off by default | Tested |
| Options menu: second page with Level Cap, Items vs Trainers and Auto Run | Tested |

### Bug fixes
| Change | In-game status |
|---|---|
| Magneton level-up list put in order (BUG-02) | Tested |
| Route 15 punch tutor compatibility: 89 Fire, 104 Ice, 109 Thunder (BUG-04) | Tested |
| Self-hit damage uses its own move; Technician no longer boosts it (BUG-05) | Tested |
| Victory music plays after knocking out a wild Pokémon (BUG-06) | Tested |
| Upper limit restored on items usable on Pokémon (BUG-12) | Tested |
| Removed the added Pallet Town grass encounters (BUG-01) | Not yet tested |

### Test tools and clean-up
| Change | In-game status |
|---|---|
| Temporary Pallet Town test characters (Aura Sphere giver, two move tutors) | Removed 27 November 2026 |
| Temporary debug menu for testing (warp, Pokémon, items, progress, heal) | Tested |
| Debug menu: Teach Move option | Tested |
| Debug menu: Ability option, to give a party Pokémon any ability | Not yet tested |
| Pallet Town clean-up: removed the Giovanni and chef who set story flags, and the nine warp doors | Not yet tested |
| New game PC back to the original single Potion | Not yet tested |
| Removed the unused `Tester` script from Route 2 | Not needed (nothing used it) |

The Claude-assisted changes did not touch TM compatibility or trainer teams. The only species data edits are the 18 Fairy retypes, Clefable's two stats and Seel's type. The only wild encounter edit is the Pallet Town grass. The only level-up learnset edit is the Magneton reorder, and the only tutor compatibility edit is the three punches, both approved by you.

## Data changes in detail

### Pokémon types
38 Pokémon.

| Pokémon | Original | Now |
|---|---|---|
| Ekans | Poison | Poison/Dark |
| Arbok | Poison | Poison/Dark |
| Sandslash | Ground | Ground/Steel |
| Clefairy | Normal | Fairy |
| Clefable | Normal | Fairy |
| Jigglypuff | Normal | Normal/Fairy |
| Wigglytuff | Normal | Normal/Fairy |
| Parasect | Bug/Grass | Bug/Ghost |
| Venomoth | Bug/Poison | Bug/Psychic |
| Meowth | Normal | Normal/Dark |
| Persian | Normal | Normal/Dark |
| Farfetch'd | Normal/Flying | Fighting/Flying |
| Doduo | Normal/Flying | Ground/Flying |
| Dodrio | Normal/Flying | Ground/Flying |
| Drowzee | Psychic | Psychic/Dark |
| Hypno | Psychic | Psychic/Dark |
| Kingler | Water | Water/Steel |
| Marowak | Ground | Ground/Ghost |
| Mr. Mime | Psychic | Psychic/Fairy |
| Aerodactyl | Rock/Flying | Rock/Dragon |
| Noctowl | Normal/Flying | Ghost/Flying |
| Cleffa | Normal | Fairy |
| Igglybuff | Normal | Normal/Fairy |
| Togepi | Normal | Fairy |
| Togetic | Normal/Flying | Fairy/Flying |
| Marill | Water | Water/Fairy |
| Azumarill | Water | Water/Fairy |
| Sunflora | Grass | Grass/Fire |
| Snubbull | Normal | Fairy |
| Granbull | Normal | Fairy |
| Octillery | Water | Water/Fire |
| Sceptile | Grass | Grass/Dragon |
| Ralts | Psychic | Psychic/Fairy |
| Kirlia | Psychic | Psychic/Fairy |
| Gardevoir | Psychic | Psychic/Fairy |
| Azurill | Normal | Normal/Fairy |
| Mawile | Steel | Steel/Fairy |
| Tropius | Grass/Flying | Grass/Dragon |

### Pokémon abilities
95 Pokémon.

| Pokémon | Original | Now |
|---|---|---|
| Bulbasaur | Overgrow | Overgrow/Chlorophyll |
| Ivysaur | Overgrow | Overgrow/Chlorophyll |
| Venusaur | Overgrow | Overgrow/Chlorophyll |
| Charmander | Blaze | Blaze/Solar Power |
| Charmeleon | Blaze | Blaze/Solar Power |
| Charizard | Blaze | Blaze/Solar Power |
| Squirtle | Torrent | Torrent/Rain Dish |
| Wartortle | Torrent | Torrent/Rain Dish |
| Blastoise | Torrent | Torrent/Rain Dish |
| Spearow | Keen Eye | Keen Eye/Super Luck |
| Fearow | Keen Eye | Keen Eye/Super Luck |
| Nidoran♀ | Poison Point | Poison Point/Hustle |
| Nidorina | Poison Point | Poison Point/Hustle |
| Nidoqueen | Poison Point | Poison Point/Rough Skin |
| Nidoran♂ | Poison Point | Poison Point/Hustle |
| Nidorino | Poison Point | Poison Point/Hustle |
| Nidoking | Poison Point | Poison Point/Rough Skin |
| Vulpix | Flash Fire | Flash Fire/Drought |
| Ninetales | Flash Fire | Flash Fire/Drought |
| Oddish | Chlorophyll | Chlorophyll/Run Away |
| Gloom | Chlorophyll | Chlorophyll/Effect Spore |
| Vileplume | Chlorophyll | Chlorophyll/Effect Spore |
| Meowth | Pickup | Pickup/Technician |
| Persian | Limber | Limber/Technician |
| Poliwrath | Water Absorb/Damp | Water Absorb/Swift Swim |
| Rapidash | Run Away/Flash Fire | Speed Boost/Flash Fire |
| Farfetch'd | Keen Eye/Inner Focus | Guts/Super Luck |
| Dodrio | Run Away/Early Bird | Guts/Early Bird |
| Seel | Thick Fat | Thick Fat/Ice Body |
| Dewgong | Thick Fat | Thick Fat/Ice Body |
| Drowzee | Insomnia | Insomnia/Inner Focus |
| Hypno | Insomnia | Insomnia/Inner Focus |
| Hitmonlee | Limber | Limber/Reckless |
| Hitmonchan | Keen Eye | Iron Fist/Inner Focus |
| Lickitung | Own Tempo/Oblivious | Own Tempo/Thick Fat |
| Rhyhorn | Lightning Rod/Rock Head | Reckless/Rock Head |
| Rhydon | Lightning Rod/Rock Head | Reckless/Rock Head |
| Kangaskhan | Early Bird | Iron Fist/Inner Focus |
| Staryu | Illuminate/Natural Cure | Rain Dish/Natural Cure |
| Starmie | Illuminate/Natural Cure | Rain Dish/Natural Cure |
| Mr. Mime | Soundproof | Soundproof/Technician |
| Scyther | Swarm | Swarm/Technician |
| Jynx | Oblivious | Oblivious/Snow Warning |
| Electabuzz | Static | Static/Vital Spirit |
| Magmar | Flame Body | Flame Body/Vital Spirit |
| Aerodactyl | Rock Head/Pressure | Rock Head/Levitate |
| Articuno | Pressure | Snow Cloak |
| Zapdos | Pressure | Static |
| Moltres | Pressure | Flame Body |
| Mewtwo | Pressure | Intimidate |
| Chikorita | Overgrow | Overgrow/Marvel Scale |
| Bayleef | Overgrow | Overgrow/Marvel Scale |
| Meganium | Overgrow | Overgrow/Marvel Scale |
| Cyndaquil | Blaze | Blaze/Flash Fire |
| Quilava | Blaze | Blaze/Flash Fire |
| Typhlosion | Blaze | Blaze/Flash Fire |
| Totodile | Torrent | Torrent/Intimidate |
| Croconaw | Torrent | Torrent/Intimidate |
| Feraligatr | Torrent | Torrent/Intimidate |
| Sentret | Run Away/Keen Eye | Pickup/Keen Eye |
| Furret | Run Away/Keen Eye | Pickup/Technician |
| Noctowl | Insomnia/Keen Eye | Insomnia/Compound Eyes |
| Ledyba | Swarm/Early Bird | Swarm |
| Ledian | Swarm/Early Bird | Iron Fist |
| Spinarak | Swarm/Insomnia | Swarm/Super Luck |
| Ariados | Swarm/Insomnia | Swarm/Super Luck |
| Chinchou | Volt Absorb/Illuminate | Volt Absorb/Water Absorb |
| Lanturn | Volt Absorb/Illuminate | Volt Absorb/Water Absorb |
| Natu | Synchronize/Early Bird | Synchronize/Trace |
| Xatu | Synchronize/Early Bird | Synchronize/Trace |
| Politoed | Water Absorb/Damp | Water Absorb/Drizzle |
| Aipom | Run Away/Pickup | Technician/Pickup |
| Sunkern | Chlorophyll | Chlorophyll/Solar Power |
| Sunflora | Chlorophyll | Chlorophyll/Solar Power |
| Murkrow | Insomnia | Super Luck |
| Gligar | Hyper Cutter/Sand Veil | Sand Stream/Sand Veil |
| Scizor | Swarm | Swarm/Technician |
| Sneasel | Inner Focus/Keen Eye | Inner Focus/Snow Cloak |
| Slugma | Magma Armor/Flame Body | Magma Armor |
| Magcargo | Magma Armor/Flame Body | Magma Armor |
| Swinub | Oblivious | Thick Fat/Snow Cloak |
| Piloswine | Oblivious | Thick Fat/Snow Cloak |
| Remoraid | Hustle | Hustle/Super Luck |
| Octillery | Suction Cups | Suction Cups/Super Luck |
| Delibird | Vital Spirit/Hustle | Vital Spirit/Snow Warning |
| Houndoom | Early Bird/Flash Fire | Solar Power/Flash Fire |
| Smeargle | Own Tempo | Own Tempo/Technician |
| Tyrogue | Guts | Guts/Vital Spirit |
| Hitmontop | Intimidate | Intimidate/Technician |
| Smoochum | Oblivious | Oblivious/Cute Charm |
| Elekid | Static | Static/Vital Spirit |
| Magby | Flame Body | Flame Body/Vital Spirit |
| Raikou | Pressure | Volt Absorb |
| Entei | Pressure | Flash Fire |
| Suicune | Pressure | Water Absorb |

### Pokémon base stats
41 Pokémon.

| Pokémon | Base stat changes |
|---|---|
| Butterfree | SpA 80→90 |
| Beedrill | Atk 80→90 |
| Pidgey | Atk 45→35, SpA 35→45 |
| Pidgeotto | Atk 60→50, SpA 50→60 |
| Pidgeot | Atk 80→70, SpA 70→90, Spe 91→101 |
| Pikachu | Def 30→40, SpD 40→50 |
| Raichu | Spe 100→110 |
| Nidoqueen | Atk 82→92 |
| Nidoking | Atk 92→102 |
| Clefable | SpA 85→95 |
| Wigglytuff | SpA 75→85 |
| Vileplume | SpA 100→110 |
| Poliwrath | Atk 85→95 |
| Alakazam | SpD 85→95 |
| Victreebel | SpD 60→70 |
| Golem | Atk 110→120 |
| Rapidash | Spe 105→115 |
| Farfetch'd | HP 52→60, Atk 65→95, Def 55→65, Spe 60→85 |
| Dewgong | SpA 70→80 |
| Onix | Atk 45→70 |
| Marowak | SpA 50→80 |
| Rhydon | SpD 45→55 |
| Tangela | HP 65→80, SpA 100→110, SpD 40→50 |
| Electabuzz | Def 57→80, SpD 85→90 |
| Magmar | Def 57→80, SpD 85→90 |
| Lapras | Atk 85→75, Def 80→90, SpA 85→90, SpD 95→105 |
| Noctowl | SpA 76→86, Spe 70→60 |
| Ledian | Atk 35→80, SpA 55→30, SpD 110→100, Spe 85→80 |
| Togetic | Def 85→95, SpD 105→115, Spe 40→80 |
| Ampharos | Def 75→85 |
| Bellossom | Def 85→95 |
| Azumarill | SpA 50→60 |
| Jumpluff | SpD 85→95 |
| Aipom | Spe 85→100 |
| Sunflora | Spe 30→55 |
| Yanma | Def 45→65, SpA 75→100 |
| Murkrow | HP 60→80, Atk 85→95, SpA 85→75 |
| Misdreavus | SpA 85→95, SpD 85→95, Spe 85→95 |
| Steelix | HP 75→95 |
| Sneasel | HP 55→65, Atk 95→105 |
| Piloswine | HP 100→110, Atk 100→110 |

### Other Pokémon data
| Pokémon | Field | Original | Now |
|---|---|---|---|
| Nidoqueen | Egg groups | Undiscovered | Monster/Field |
| Horsea | Rare held item | None | Dragon Scale |
| Seadra | Rare held item | None | Dragon Scale |
| Goldeen | Rare held item | None | Mystic Water |
| Lapras | Rare held item | None | Mystic Water |
| Sentret | Common held item | None | Oran Berry |
| Sunkern | Growth rate | Medium Slow | Medium Fast |
| Sunflora | Growth rate | Medium Slow | Medium Fast |

### TM/HM compatibility
23 Pokémon gained moves. None lost any.

| Pokémon | Added TM/HM |
|---|---|
| Charizard | TM22 Solar Beam |
| Spearow | HM01 Cut |
| Fearow | HM01 Cut |
| Pikachu | HM02 Fly, HM03 Surf |
| Raichu | HM03 Surf |
| Vulpix | TM22 Solar Beam |
| Ninetales | TM22 Solar Beam |
| Parasect | TM30 Shadow Ball |
| Venomoth | TM04 Calm Mind, TM16 Light Screen, TM33 Reflect |
| Arcanine | TM22 Solar Beam |
| Magmar | TM22 Solar Beam, TM36 Sludge Bomb |
| Lapras | TM04 Calm Mind |
| Flareon | TM22 Solar Beam |
| Moltres | TM22 Solar Beam |
| Mewtwo | HM01 Cut, HM02 Fly, HM03 Surf |
| Typhlosion | TM22 Solar Beam |
| Sunflora | TM35 Flamethrower, TM38 Fire Blast, TM50 Overheat |
| Steelix | HM07 Waterfall |
| Magcargo | TM22 Solar Beam |
| Octillery | TM50 Overheat |
| Blaziken | TM22 Solar Beam |
| Torkoal | TM22 Solar Beam |
| Camerupt | TM22 Solar Beam |

### Level-up learnsets
230 Pokémon have changed level-up lists. Not listed move by move; use `git diff 539ed3616 -- src/data/pokemon/level_up_learnsets.h`.

Bulbasaur, Ivysaur, Venusaur, Charmander, Charmeleon, Charizard, Squirtle, Wartortle, Blastoise, Metapod, Butterfree, Kakuna, Beedrill, Pidgey, Pidgeotto, Pidgeot, Rattata, Raticate, Spearow, Fearow, Ekans, Arbok, Pikachu, Raichu, Sandshrew, Sandslash, Nidoran♀, Nidorina, Nidoqueen, Nidoran♂, Nidorino, Nidoking, Clefable, Vulpix, Ninetales, Jigglypuff, Wigglytuff, Zubat, Golbat, Oddish, Gloom, Vileplume, Paras, Parasect, Venonat, Venomoth, Diglett, Dugtrio, Meowth, Persian, Psyduck, Golduck, Mankey, Primeape, Growlithe, Arcanine, Poliwag, Poliwhirl, Poliwrath, Kadabra, Alakazam, Machop, Machoke, Machamp, Bellsprout, Weepinbell, Victreebel, Tentacool, Tentacruel, Geodude, Graveler, Golem, Ponyta, Rapidash, Slowpoke, Slowbro, Magneton, Farfetch'd, Doduo, Dodrio, Seel, Dewgong, Grimer, Muk, Shellder, Cloyster, Haunter, Gengar, Onix, Drowzee, Hypno, Krabby, Kingler, Voltorb, Electrode, Exeggcute, Exeggutor, Cubone, Marowak, Hitmonlee, Hitmonchan, Lickitung, Koffing, Weezing, Rhyhorn, Rhydon, Chansey, Tangela, Kangaskhan, Horsea, Seadra, Goldeen, Seaking, Staryu, Starmie, Scyther, Jynx, Electabuzz, Magmar, Pinsir, Tauros, Magikarp, Gyarados, Lapras, Eevee, Vaporeon, Jolteon, Flareon, Porygon, Omanyte, Omastar, Kabuto, Kabutops, Aerodactyl, Snorlax, Articuno, Zapdos, Moltres, Dratini, Dragonair, Dragonite, Mewtwo, Chikorita, Bayleef, Meganium, Cyndaquil, Quilava, Typhlosion, Totodile, Croconaw, Feraligatr, Sentret, Furret, Hoothoot, Noctowl, Ledyba, Ledian, Spinarak, Ariados, Crobat, Chinchou, Lanturn, Pichu, Togetic, Natu, Xatu, Mareep, Flaaffy, Ampharos, Bellossom, Marill, Azumarill, Sudowoodo, Politoed, Hoppip, Skiploom, Jumpluff, Aipom, Sunkern, Sunflora, Yanma, Wooper, Quagsire, Espeon, Umbreon, Murkrow, Slowking, Misdreavus, Girafarig, Pineco, Forretress, Dunsparce, Gligar, Steelix, Snubbull, Granbull, Qwilfish, Scizor, Shuckle, Heracross, Sneasel, Teddiursa, Ursaring, Slugma, Magcargo, Swinub, Piloswine, Corsola, Remoraid, Octillery, Mantine, Skarmory, Houndour, Houndoom, Kingdra, Phanpy, Donphan, Porygon2, Stantler, Tyrogue, Hitmontop, Smoochum, Elekid, Magby, Miltank, Blissey, Raikou, Entei, Suicune, Tyranitar

### Changes to original moves
64 moves (category additions not counted).

| Move | Change (original → now) |
|---|---|
| Double Slap | type Normal→Fairy |
| Comet Punch | power 18→15; type Normal→Fighting |
| Razor Wind | type Normal→Flying; accuracy 100→95; PP 10→15; effect Razor Wind→High Critical; effect chance 0→20; target both→selected |
| Cut | power 50→60; type Normal→Bug; accuracy 95→100; PP 30→25 |
| Fly | power 70→100; accuracy 95→100 |
| Mega Kick | accuracy 75→90; PP 5→10 |
| Rolling Kick | accuracy 85→100; PP 15→25 |
| Thrash | power 90→120 |
| Poison Sting | power 15→25 |
| Twineedle | power 25→40 |
| Pin Missile | power 14→25; accuracy 85→95 |
| Hydro Pump | PP 5→10 |
| Ice Beam | PP 10→15 |
| Blizzard | accuracy 70→75 |
| Strength | power 80→75; type Normal→Rock |
| Absorb | power 20→35; PP 20→35 |
| Mega Drain | power 40→60; PP 10→25 |
| Growth | effect Special Attack Up→Special Attack Up 2 |
| Petal Dance | power 70→120 |
| Thunder | accuracy 70→75 |
| Rock Throw | accuracy 90→95 |
| Psychic | PP 10→15 |
| Night Shade | power 1→40; PP 15→30; effect Level Damage→Hit |
| Recover | PP 20→5 |
| Egg Bomb | type Normal→Grass; accuracy 75→100; PP 10→15 |
| Fire Blast | PP 5→10 |
| Spike Cannon | type Normal→Steel |
| Kinesis | flags edited (Magic Coat flag removed) |
| Soft-Boiled | PP 10→5 |
| Hi Jump Kick | power 85→130; PP 20→10 |
| Glare | accuracy 75→85 |
| Dream Eater | type Psychic→Dark; accuracy 100→120 |
| Poison Gas | accuracy 55→90 |
| Leech Life | power 20→40 |
| Sky Attack | effect Sky Attack→Overheat; effect chance 30→100; now special (originally physical) |
| Transform | priority 0→1 |
| Bubble | power 20→30 |
| Crabhammer | power 90→100; accuracy 85→95 |
| Rest | PP 10→5 |
| Rock Slide | power 75→90; PP 10→15; effect chance 30→20 |
| Triple Kick | PP 10→20 |
| Curse | type Mystery→Ghost |
| Sweet Kiss | type Normal→Fairy |
| Octazooka | accuracy 85→100 |
| Bone Rush | accuracy 80→90 |
| Outrage | power 90→120 |
| Giga Drain | power 60→75; PP 5→15 |
| Charm | type Normal→Fairy |
| False Swipe | power 40→60 |
| Steel Wing | power 70→75; accuracy 90→100 |
| Iron Tail | accuracy 75→85; effect chance 30→10 |
| Metal Claw | accuracy 95→100 |
| Moonlight | type Normal→Fairy |
| Extreme Speed | priority 1→2 |
| Future Sight | power 80→120; accuracy 90→100 |
| Nature Power | accuracy 0→95 |
| Snatch | now copyable by Mirror Move |
| Blaze Kick | power 85→95; accuracy 90→100 |
| Meteor Mash | accuracy 85→90 |
| Sky Uppercut | accuracy 90→95 |
| Bullet Seed | power 10→25 |
| Icicle Spear | power 10→30 |
| Leaf Blade | power 70→90 |
| Rock Blast | accuracy 80→90 |

### New moves
See [DESIGN.md](DESIGN.md#46-new-moves).

### Trainers
22 trainers added or changed. Numbers after each Pokémon are levels.

| Trainer | Change | Original team | Current team |
|---|---|---|---|
| HIKER_JONES | new trainer | — | Poliwag 15<br>Remoraid 15<br>Koffing 15 |
| BLACK_BELT_ROGAN | new trainer | — | Shroomish 15 (holds Black Belt)<br>Mankey 15 (holds Black Belt)<br>Slakoth 15 (holds Black Belt) |
| YOUNGSTER_JAMIE | new trainer | — | Whismur 15<br>Whismur 16 |
| COOLTRAINER_SYLVIA | new trainer | — | Glalie 34 [Ice Beam, Protect, Body Slam, Rollout]<br>Mawile 34 [Torment, Secret Power, Faint Attack, Brick Break]<br>Seviper 34 [Swagger, Giga Drain, Iron Tail, Glare] |
| PICNICKER_SALLY | new trainer | — | Sentret 5<br>Hoothoot 5 |
| YOUNGSTER_TIMMY | now a double battle | (same team) | Sandshrew 14<br>Ekans 14 |
| BUG_CATCHER_CALE | team changed, now a double battle | Caterpie 10<br>Weedle 10<br>Metapod 10<br>Kakuna 10 | Metapod 10<br>Kakuna 10<br>Pineco 10<br>Yanma 10 |
| LASS_RELI | team changed, now a double battle | Nidoran♂ 16<br>Nidoran♀ 16 | Nidorino 16<br>Nidorina 16 |
| LASS_ALI | team changed, now a double battle | Pidgey 12<br>Oddish 12<br>Bellsprout 12 | Oddish 14<br>Bellsprout 14 |
| CAMPER_ETHAN | team changed, now a double battle | Mankey 18 | Mankey 17<br>Mankey 17 |
| BOSS_GIOVANNI | team changed | Onix 25<br>Rhyhorn 24<br>Kangaskhan 29 | Persian 30<br>Rhyhorn 28<br>Kangaskhan 30 |
| TEAM_ROCKET_GRUNT_6 | team changed, renamed | Ekans 15<br>Zubat 15 | Gligar 16<br>Delibird 16 |
| COOLTRAINER_DUKE | new trainer | — | Camerupt 34 [Amnesia, Magnitude, Rest, Ember]<br>Sableye 34 [Fake Out, Aerial Ace, Torment, Faint Attack]<br>Zangoose 34 [Crush Claw, Pursuit, Mud-Slap, Swift] |
| LEADER_BROCK | team changed | Geodude 12 [Tackle, Defense Curl]<br>Onix 14 [Tackle, Bind, Rock Tomb] | Geodude 13 (Sturdy) [Tackle, Defense Curl, Rock Tomb]<br>Zubat 12 [Supersonic, Astonish, Leech Life]<br>Onix 14 [Dragon Breath, Bind, Rock Tomb, Torment] |
| LEADER_MISTY | team changed | Staryu 18 [Tackle, Harden, Recover, Water Pulse]<br>Starmie 21 [Swift, Recover, Rapid Spin, Water Pulse] | Psyduck 20 [Screech, Fury Swipes, Hypnosis, Water Pulse]<br>Corsola 21 [Tackle, Harden, Recover, Water Pulse]<br>Starmie 23 [Swift, Recover, Rapid Spin, Water Pulse] |
| LEADER_LT_SURGE | team changed | Voltorb 21 [Sonic Boom, Tackle, Screech, Shock Wave]<br>Pikachu 18 [Quick Attack, Thunder Wave, Double Team, Shock Wave]<br>Raichu 24 [Quick Attack, Thunder Wave, Double Team, Shock Wave] | Lanturn 23 [Bubble Beam, Charge, Confuse Ray, Shock Wave]<br>Voltorb 21 [Sonic Boom, Tackle, Screech, Shock Wave]<br>Elekid 22 [Low Kick, Light Screen, Thunder Wave, Shock Wave]<br>Raichu 26 [Quick Attack, Thunder Wave, Double Team, Shock Wave] |
| LEADER_ERIKA | team changed | Victreebel 29 [Stun Spore, Acid, Poison Powder, Giga Drain]<br>Tangela 24 [Poison Powder, Constrict, Ingrain, Giga Drain]<br>Vileplume 29 [Sleep Powder, Acid, Stun Spore, Giga Drain] | Victreebel 33 [Stun Spore, Acid, Knock Off, Giga Drain]<br>Sunflora 32 [Synthesis, Earth Power, Sunny Day, Giga Drain]<br>Tangela 32 [Sleep Powder, Growth, Confusion, Giga Drain]<br>Vileplume 34 [Sleep Powder, Drain Punch, Solar Beam, Giga Drain] |
| LEADER_KOGA | team changed | Koffing 37 [Self-Destruct, Sludge, Smokescreen, Toxic]<br>Muk 39 [Minimize, Sludge, Acid Armor, Toxic]<br>Koffing 37 [Self-Destruct, Sludge, Smokescreen, Toxic]<br>Weezing 43 [Tackle, Sludge, Smokescreen, Toxic] | Crobat 39 [Poison Fang, Confuse Ray, Aerial Ace, Toxic]<br>Ariados 38 [Night Slash, Twineedle, Pain Split, Toxic]<br>Muk 41 [Protect, Sludge Bomb, Acid Armor, Toxic]<br>Venomoth 38 [Signal Beam, Psychic, Double Team, Toxic]<br>Weezing 43 [Double Team, Sludge Bomb, Flamethrower, Toxic] |
| LEADER_BLAINE | team changed | Growlithe 42 [Bite, Roar, Take Down, Fire Blast]<br>Ponyta 40 [Stomp, Bounce, Fire Spin, Fire Blast]<br>Rapidash 42 [Stomp, Bounce, Fire Spin, Fire Blast]<br>Arcanine 47 [Bite, Roar, Take Down, Fire Blast] | Magcargo 43 [Fire Blast, Yawn, Ancient Power, Amnesia]<br>Rapidash 44 [Fire Spin, Bounce, Quick Attack, Fire Blast]<br>Magmar 45 [Cross Chop, Thunder Punch, Sludge Bomb, Fire Blast]<br>Octillery 44 [Bullet Seed, Ice Beam, Octazooka, Fire Blast]<br>Arcanine 46 [Morning Sun, Extreme Speed, Outrage, Fire Blast] |
| LEADER_SABRINA | team changed | Kadabra 38 [Psybeam, Reflect, Future Sight, Calm Mind]<br>Mr. Mime 37 [Barrier, Psybeam, Baton Pass, Calm Mind]<br>Venomoth 38 [Psybeam, Gust, Leech Life, Supersonic]<br>Alakazam 43 [Psychic, Recover, Future Sight, Calm Mind] | Mr. Mime 39 [Psybeam, Reflect, Magical Leaf, Calm Mind]<br>Espeon 41 [Psybeam, Signal Beam, Shadow Ball, Calm Mind]<br>Haunter 37 [Destiny Bond, Perish Song, Mean Look, Shadow Punch]<br>Girafarig 37 [Psybeam, Wish, Nasty Plot, Take Down]<br>Alakazam 44 [Psychic, Recover, Safeguard, Calm Mind] |
| PLAYER_BRENDAN | team changed, AI changed | Dummy 5 | Swellow 35<br>Spinda 35<br>Swampert 37 |
| PLAYER_MAY | team changed, AI changed | Dummy 5 | Beautifly 35<br>Skitty 35<br>Blaziken 37 |
