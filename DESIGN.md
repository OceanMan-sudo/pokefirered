# DESIGN — current game design and mechanics

This describes the game as it stands on `claude-edits` (audit of 27 November 2026). For before-and-after details see [CHANGELOG.md](CHANGELOG.md). For problems see [BUGS.md](BUGS.md).

**How to read this:** Everything here was read from the code and data (**confirmed in code**) unless marked **Assumption**. **Tested** means you reported that it worked in game. Anything not marked Tested has no recorded in-game confirmation, except the items ticked under "Waiting to be tested" in [TODO.md](TODO.md), which you reported working on 27 November 2026.

## Test tools (temporary)

A **debug menu** is in the normal game for testing and will be removed before version 1. In the overworld, **hold B and press SELECT**. B goes back or closes it.

| Menu | What it does |
|---|---|
| Warp | Towns, gym entrances, the Pokémon League and a few test spots. Needs a Pokémon in the party; not available in the Safari Zone |
| Pokémon | Pick any of the 386 by National Dex number and a level from 1 to 100 |
| Teach Move | Pick a party Pokémon and any move by number. If it already knows four moves, you choose which to replace. Learnsets are not changed |
| Items | Repels, Poké Balls, evolution items, all TMs and HMs, Bicycle, money, or any item by number |
| Progress | All badges; badges plus HM01–HM07; Fly map; Pokédex with National Dex; mark the Champion as beaten |
| Heal | Heals the party |

In the number picker, up and down change by 1, left and right by 10, A confirms. Story events still happen after warping.

## Rules and settings

The settings and level cap below are **Tested**.

The Options menu has a second page. Press **Down** past FRAME to reach it, and **Up** to go back. **A** or **B** saves and closes from either page.

| Setting | Where | New game | What it does |
|---|---|---|---|
| Battle style | Page 1 | **Set** | Set gives no free switch when the opponent sends out its next Pokémon |
| Level cap | Page 2 | **On** | Shows the current cap beside ON |
| Items vs trainers | Page 2 | **Off** | Off: your Bag cannot be used in trainer battles (this includes the first rival battle). Wild battles and held items work normally |
| Auto run | Page 2 | **Off** | On: you run without holding B, and holding B walks |

A save made before these settings existed starts with the cap on, trainer battle items off and auto run off, and keeps the battle style it had.

### Level cap
| Badges | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
|---|---|---|---|---|---|---|---|---|---|
| Cap | 14 | 23 | 26 | 34 | 43 | 44 | 46 | 50 | 63 |

- The cap counts badges, whatever order you got them in. The whole League uses 63.
- It lifts after you first beat the Champion.
- A Pokémon at or above the cap can still battle. It gains no EXP, and Rare Candies have no effect on it.
- It still earns EVs, and its stats update after the battle.
- The Day Care stops at the cap in force when you pick the Pokémon up.
- To change the numbers, edit `src/data/level_caps.h`.

## Battle mechanics

### Physical/Special split
Each move is Physical, Special or Status on its own, whatever its type. An icon in the battle move menu shows which. Counter and Mirror Coat follow the category.

### Fairy type
Fairy follows Generation 6.

| Fairy | Types |
|---|---|
| Fairy attacks do 2x to | Fighting, Dragon, Dark |
| Fairy attacks do ½x to | Fire, Poison, Steel |
| Fairy Pokémon take 2x from | Poison, Steel |
| Fairy Pokémon take ½x from | Fighting, Bug, Dark |
| Fairy Pokémon are immune to | Dragon |

Steel no longer resists Ghost or Dark.

| Typing | Pokémon |
|---|---|
| Fairy | Cleffa, Clefairy, Clefable, Togepi, Snubbull, Granbull |
| Normal/Fairy | Azurill, Igglybuff, Jigglypuff, Wigglytuff |
| Psychic/Fairy | Mr. Mime, Ralts, Kirlia, Gardevoir |
| Water/Fairy | Marill, Azumarill |
| Fairy/Flying | Togetic |
| Steel/Fairy | Mawile |

- Charm, Sweet Kiss and Moonlight are Fairy moves.
- Damaging Fairy moves: [Fairy Wind, Drain Kiss, Dazzle Gleam, Fae Voice, Moonblast and Play Rough](#42-new-moves). No Pokémon learns them naturally yet.
- Hidden Power cannot be Fairy.
- No held item boosts Fairy moves.

### Damage rules that differ from the original
- Type-boosting held items (Charcoal and so on) boost both Attack and Sp. Atk.
- Thick Fat halves the move's power.
- Weather and Flash Fire apply to physical moves as well as special ones.
- Light Ball doubles Pikachu's Sp. Atk only.

### Weather
| Weather | Effects added or changed |
|---|---|
| Sandstorm | Rock types get 1.5× Sp. Def |
| Hail | Ice types get 1.5× Defense. Blizzard never misses |
| Rain | Routes 12 and 13 are now rainy |

### New abilities
| Ability | What it does here | Pokémon with it |
|---|---|---|
| Solar Power | 1.5× special damage in sun, no HP loss | Charmander, Charmeleon, Charizard, Sunkern, Sunflora, Houndoom |
| Super Luck | Higher critical-hit chance (+1 stage) | Spearow, Fearow, Farfetch'd, Spinarak, Ariados, Murkrow, Remoraid, Octillery |
| Technician | 1.5× for moves with 60 power or less | Meowth, Persian, Mr. Mime, Scyther, Furret, Aipom, Scizor, Smeargle, Hitmontop |
| Ice Body | Heals 1/16 HP each turn in hail | Seel, Dewgong |
| Iron Fist | 1.2× for punching moves (the list also includes Poison Jab) | Hitmonchan, Kangaskhan, Ledian |
| Reckless | 1.2× for recoil and jump-kick moves | Hitmonlee, Rhyhorn, Rhydon |
| Snow Warning | Starts permanent hail on entering | Jynx, Delibird |
| Snow Cloak | Attacks against it are 20% less accurate in hail | Articuno, Sneasel, Swinub, Piloswine |

95 Pokémon have had their abilities changed. See the table in [CHANGELOG.md](CHANGELOG.md#pokémon-abilities).

### Battle conveniences
- You gain EXP when you catch a Pokémon, and level-up evolutions happen after a catch (**Tested**).
- In wild battles, pressing **B** on the action menu jumps the cursor to **RUN**.
- Enemy trainers never use items, including gym leaders and the League.
- By default you cannot use your Bag in trainer battles either (see [Rules and settings](#rules-and-settings)).
- **Quick escape** (below).

### Quick escape
Hold **B** as a wild Pokémon slides in. "Wild ___ appeared!" shows with **Try to escape?** and a Yes/No box that starts on **Yes**. Pressing B again, or choosing No, starts the battle normally.

Choosing Yes makes the usual escape check with your first Pokémon, before it comes out:

| Result | What happens |
|---|---|
| Escape works | The battle ends. A Smoke Ball or Run Away always works |
| Too slow | "Can't escape!", your Pokémon comes out and you lose your first turn |
| Trapped by an ability (such as Arena Trap) | The ability is named, your Pokémon comes out and you take your turn normally |

It works in wild battles, including legendary and ghost battles. It does not appear in trainer battles, the Safari Zone or the catching tutorials. In ghost battles the question follows the ghost's own message.

## Training and progression

### EVs and IVs
- A single stat can hold up to **252** EVs (total limit unchanged at 510).
- Vitamins now work up to 252 in a stat (originally 100).
- On the summary screen's skills page, **SELECT** cycles between stats, IVs and EVs (**Tested**).

### Level-up moves
230 Pokémon have changed level-up lists (Generations 1 and 2). Learnset work is paused until you restart it.

### TMs
- TMs are reusable.
- You own at most one of each. Receiving a duplicate still "succeeds", so gifts and item balls behave normally.
- TMs cannot be sold or held, and the TM Case shows no quantity.
- TMs you own are not listed in marts or at the Game Corner.
- The Pickup ability gives Leftovers where it used to give TM10.

### HMs and field moves
- An HM move works outside battle if you have its badge and either a Pokémon that **knows** it, or the **HM item** and a Pokémon that **can learn** it (**Tested**).
- The party menu lists an HM move only when you can use it where you are (five field moves at most).
- Other field moves (such as Dig) still have to be learned.
- HM moves can be forgotten like any other move.
- You cannot release your last Pokémon able to use Surf, once you have the Soul Badge and HM03 (**Tested**).
- Rock Tunnel is dark until Flash is used (**Tested**).

### National Dex and game-clear checks
- The National Dex is enabled when you first receive the Pokédex, so Pokémon from later regions can evolve and be recorded from the start.
- Places that used to require the National Dex (Indigo Plateau, the One Island Celio quest) now check that you have beaten the game.

### Running
Hold **B** to run, from the start of the game. No Running Shoes are needed, and running is allowed on every map and floor tile, indoors included. With **Auto run** switched on, you run by default and hold **B** to walk.

### Cycling
There is no cycling theme. The area's music keeps playing on the bike, including on Cycling Road.

### Repels
When a Repel wears off, the game offers to use another: the kind used last, otherwise any other you carry (Repel first, then Super, then Max). Shop prices are 10, 20 and 30.

## Evolution

No Pokémon needs to be traded. Former trade-item evolutions work by using the item on the Pokémon.

| Pokémon | Original | Now |
|---|---|---|
| Poliwag | Poliwhirl: level 25 | Poliwhirl: level 18 |
| Poliwhirl | Politoed: trade holding Kings Rock | Politoed: use Kings Rock |
| Kadabra | Alakazam: trade | Alakazam: level 38 |
| Machop | Machoke: level 28 | Machoke: level 18 |
| Machoke | Machamp: trade | Machamp: level 38 |
| Geodude | Graveler: level 25 | Graveler: level 18 |
| Graveler | Golem: trade | Golem: level 38 |
| Ponyta | Rapidash: level 40 | Rapidash: level 28 |
| Slowpoke | Slowbro: level 37; Slowking: trade holding Kings Rock | Slowbro: level 32; Slowking: use Kings Rock |
| Seel | Dewgong: level 34 | Dewgong: level 30 |
| Gastly | Haunter: level 25 | Haunter: level 24 |
| Haunter | Gengar: trade | Gengar: level 40 |
| Onix | Steelix: trade holding Metal Coat | Steelix: use Metal Coat |
| Koffing | Weezing: level 35 | Weezing: level 30 |
| Rhyhorn | Rhydon: level 42 | Rhydon: level 34 |
| Horsea | Seadra: level 32 | Seadra: level 22 |
| Seadra | Kingdra: trade holding Dragon Scale | Kingdra: use Dragon Scale |
| Goldeen | Seaking: level 33 | Seaking: level 25 |
| Scyther | Scizor: trade holding Metal Coat | Scizor: use Metal Coat |
| Eevee | Espeon: friendship day; Umbreon: friendship night | Espeon: use Sun Stone; Umbreon: use Moon Stone |
| Porygon | Porygon2: trade holding Up Grade | Porygon2: use Up Grade |
| Omanyte | Omastar: level 40 | Omastar: level 28 |
| Kabuto | Kabutops: level 40 | Kabutops: level 28 |
| Dragonair | Dragonite: level 55 | Dragonite: level 50 |
| Slugma | Magcargo: level 38 | Magcargo: level 33 |
| Swinub | Piloswine: level 33 | Piloswine: level 30 |
| Smoochum | Jynx: level 30 | Jynx: level 25 |
| Elekid | Electabuzz: level 30 | Electabuzz: level 25 |
| Magby | Magmar: level 30 | Magmar: level 25 |
| Pupitar | Tyranitar: level 55 | Tyranitar: level 50 |
| Feebas | Milotic: beauty 170 | Milotic: level 20 |
| Clamperl | Huntail: trade holding Deep Sea Tooth; Gorebyss: trade holding Deep Sea Scale | Huntail: use Deep Sea Tooth; Gorebyss: use Deep Sea Scale |

Friendship evolution still applies to Golbat, Chansey, Pichu, Cleffa, Igglybuff, Togepi and Azurill.

## Moves

### 42 new moves
† added with Claude.

| Move | Type | Category | Power | Acc | PP | Effect code |
|---|---|---|---|---|---|---|
| Dragon Pulse | Dragon | Special | 90 | 100 | 15 | Hit |
| Focus Blast | Fighting | Special | 110 | 80 | 10 | Special Defense Down Hit (10%) |
| Shadow Claw | Ghost | Physical | 70 | 100 | 20 | High Critical |
| Dark Pulse | Dark | Special | 80 | 100 | 15 | Flinch Hit (20%) |
| Roost | Flying | Status | — | — | 5 | Restore Hp |
| Bullet Punch | Steel | Physical | 40 | 100 | 30 | Quick Attack, priority 1 |
| Flare Blitz | Fire | Physical | 120 | 100 | 10 | Recoil |
| Poison Jab | Poison | Physical | 80 | 100 | 15 | Poison Hit (20%) |
| Earth Power | Ground | Special | 80 | 100 | 15 | Special Defense Down Hit (10%) |
| Giga Impact | Normal | Physical | 150 | 90 | 5 | Recharge |
| Ice Shard | Ice | Physical | 40 | 100 | 30 | Quick Attack, priority 1 |
| Shadow Sneak | Ghost | Physical | 40 | 100 | 30 | Quick Attack, priority 1 |
| Psycho Power | Psychic | Physical | 90 | 100 | 30 | Defense Down Hit (10%) |
| Flash Cannon | Steel | Special | 80 | 100 | 15 | Special Defense Down Hit (10%) |
| Draco Meteor | Dragon | Special | 140 | 90 | 5 | Overheat |
| Leaf Storm | Grass | Special | 140 | 90 | 5 | Overheat |
| Ominous Wind | Ghost | Special | 60 | 100 | 5 | All Stats Up Hit (10%) |
| Scorch Sand | Ground | Special | 70 | 100 | 15 | Burn Hit (30%) |
| Nasty Plot | Dark | Status | — | 100 | 20 | Special Attack Up 2 |
| X-Scissor | Bug | Physical | 80 | 100 | 15 | Hit |
| Seed Bomb | Grass | Physical | 80 | 100 | 15 | Hit |
| Drain Punch | Fighting | Physical | 75 | 100 | 15 | Absorb |
| Aqua Jet | Water | Physical | 40 | 100 | 30 | Quick Attack, priority 1 |
| Boomburst | Normal | Special | 140 | 100 | 15 | Hit |
| Night Slash | Dark | Physical | 70 | 100 | 20 | High Critical |
| Aura Sphere † | Fighting | Special | 80 | never misses | 20 | Always Hit |
| Moonblast † | Fairy | Special | 95 | 100 | 15 | Special Attack Down Hit (20%) |
| Play Rough † | Fairy | Physical | 90 | 90 | 10 | Attack Down Hit (10%) |
| Fairy Wind † | Fairy | Special | 40 | 100 | 30 | Hit |
| Drain Kiss † | Fairy | Special | 50 | 100 | 10 | Draining Kiss (new) |
| Dazzle Gleam † | Fairy | Special | 80 | 100 | 10 | Hit, both opponents |
| Fae Voice † | Fairy | Special | 40 | never misses | 15 | Always Hit, both opponents |
| Close Combat † | Fighting | Physical | 120 | 100 | 5 | Close Combat (new) |
| Brave Bird † | Flying | Physical | 120 | 100 | 15 | Double Edge (recoil 1/3) |
| Wild Charge † | Electric | Physical | 90 | 100 | 15 | Recoil (1/4) |
| Icicle Crash † | Ice | Physical | 85 | 90 | 10 | Flinch Hit (30%) |
| Iron Head † | Steel | Physical | 80 | 100 | 15 | Flinch Hit (20%) |
| Bug Buzz † | Bug | Special | 90 | 100 | 10 | Special Defense Down Hit (10%) |
| Power Gem † | Rock | Special | 80 | 100 | 20 | Hit |
| Energy Ball † | Grass | Special | 90 | 100 | 10 | Special Defense Down Hit (10%) |
| Bulldoze † | Ground | Physical | 60 | 100 | 20 | Bulldoze (new), everyone but the user |
| Snarl † | Dark | Special | 55 | 95 | 15 | Special Attack Down Hit (100%), both opponents |

"Effect code" is the name of the battle effect the move uses.

Who can learn them: new moves mainly come from level-up lists. **Scorch Sand, Aura Sphere, the six Fairy moves and the ten moves from Close Combat down are on no level-up list**, and Shadow Sneak is on one. (Moves 381 to 396 can be taught with the debug menu.) No new TMs or egg moves use them.

Names in other games: Drain Kiss is Draining Kiss, Dazzle Gleam is Dazzling Gleam, and Fae Voice is Disarming Voice.

- **Drain Kiss** gives the user back three quarters of the damage dealt (other draining moves give half). It makes contact, and Liquid Ooze turns the healing into damage. Trainer AI judges it like other draining moves.
- **Fae Voice** is a sound move, so Soundproof blocks it.
- **Dazzle Gleam and Fae Voice** hit both opponents. When both are out, each takes half damage, as with Surf (Generation 6 uses three quarters).

The six Fairy moves, with their animations, are **Tested**.

The ten moves from Close Combat to Snarl are **Tested**, apart from the reworked Bulldoze and Wild Charge animations.

- **Close Combat** lowers the user's Defense and Sp. Def by one stage after hitting.
- **Brave Bird and Wild Charge** damage the user (a third and a quarter of the damage dealt). Rock Head prevents this, and Reckless boosts both moves.
- **Bulldoze** lowers Speed and, like Earthquake, hits every other Pokémon, including your partner in a double battle, at full damage. It does not affect Flying types or Pokémon with Levitate.
- **Snarl** hits both opponents. When both are out, each takes half damage.
- **Bug Buzz and Snarl** are sound moves, so Soundproof blocks them.

64 original moves were also changed. See [CHANGELOG.md](CHANGELOG.md#changes-to-original-moves).

### Multi-hit moves
Multi-hit moves follow modern games:

- Moves that hit 2 to 5 times check accuracy **once**. If that succeeds, every hit lands unless the target faints first.
- Odds: 2 hits 35%, 3 hits 35%, 4 hits 15%, 5 hits 15%.
- Triple Kick checks accuracy before each kick and stops at the first miss.
- A multi-hit move that breaks a Substitute carries on into the Pokémon behind it.

### Sky Attack and Double Slap
- **Sky Attack** is a special Flying move that hits in one turn: 140 power, 90 accuracy, 5 PP. It lowers the user's Sp. Atk by two stages, like Overheat.
- **Double Slap** is a Fairy move. It is still physical and looks the same.

Animations for thirteen of the new moves were fixed or redrawn with Claude (**Tested**).

### Move tutors and relearner
- **Move relearner**, free: Fuchsia City House 3 and the new Cerulean City house.
- **Route 15 House of Elements:** Ice Punch, Fire Punch and Thunder Punch tutors. Compatibility follows newer official games (89 Pokémon for Fire Punch, 104 for Ice Punch, 109 for Thunder Punch).

## Items and shops

No new items were created. These sources were added or changed:

| Where | Sells |
|---|---|
| Celadon Dept. Store 4F | Original stock plus Sun Stone and Moon Stone |
| Celadon Dept. Store 4F, "evolution seller" | Metal Coat, King's Rock, Dragon Scale, Up-Grade, Deep Sea Tooth, Deep Sea Scale |
| Celadon Dept. Store 5F | Magnet, Charcoal, Miracle Seed, Mystic Water, Focus Band, Smoke Ball (vitamins removed here) |
| Celadon Vitamin House | HP Up, Protein, Iron, Carbos, Calcium, Zinc, PP Up, PP Max |
| Celadon Vitamin House, second seller | MooMoo Milk, Lava Cookie, Berry Juice |
| Celadon Poké Ball shop | Poké, Great, Ultra, Luxury, Nest, Net, Dive, Timer and Repeat Balls |
| Pewter Berry House | Cheri, Chesto, Pecha, Rawst, Aspear, Leppa, Oran, Persim Berries |
| Vermilion Berry House | Figy, Wiki, Mago, Aguav, Iapapa, Oran Berries |
| Celadon Berry House | Sitrus, Lum, Enigma, Leppa Berries |

### Gifts
| Gift | Where |
|---|---|
| Cheri Berry | A boy in Pallet Town |
| Miracle Seed, Mystic Water or Charcoal, matching your starter (a gift from Mom, replacing the Running Shoes) | Oak's aide in Pewter City |
| Old Rod | A fisherman in Viridian City |
| Good Rod | Vermilion City house (replaces the original Old Rod there) |
| 99 Rare Candies, refilled when you run out | Viridian City, House of Nuzlocke |
| TM10 Hidden Power, later a Focus Band after all 8 badges | Mr. Nuzlocke, same house |
| Macho Brace | Celadon Vitamin House |
| Nest Ball | Item ball in Fuchsia City |
| Enigma Berry | A woman on Cinnabar Island |
| Shell Bell | Cerulean Battle House prize |
| Bright Powder | Saffron Battle House prize |
| Choice Band | Cinnabar Battle House (faulty, see BUG-03) |

### Fossils
The Vermilion Fossil House revives Helix, Dome and Old Amber (and Root and Claw, which cannot currently be obtained) instantly, at level 20.

Other Pokémon changes worth knowing: wild Horsea and Seadra can hold a Dragon Scale, Goldeen and Lapras a Mystic Water, Sentret an Oran Berry. Nidoqueen can now breed.

## World

### Expanded maps
- **Pallet Town:** twice as wide (24 → 48), with a patch of tall grass (no wild Pokémon), a pond and new houses.
- **Viridian City:** wider (48 → 60).
- **Cinnabar Island:** taller (20 → 26).
- Layout edits in Pewter, Cerulean, Vermilion, Celadon, Saffron, Route 5, Route 15, Route 20 and Pokémon Tower 1F.
- Some Cut trees removed (four in Fuchsia, one on Route 15).
- Oak's Aide removed from Vermilion City.
- Routes 12 and 13 now have rain.

### 18 new maps
| Map | Contents | State |
|---|---|---|
| Pallet new home 1 (1F, 2F) | Residents | In use |
| Pallet new home 2 | Residents | In use |
| Viridian House of Nuzlocke | Rare Candies, Mr. Nuzlocke, rules signs | In use |
| Pewter Berry House | Berry shop | In use |
| Cerulean "Always Been Here" house | Move relearner | In use |
| Cerulean Battle House | 3 trainers, Shell Bell | In use |
| Vermilion Berry House | Berry shop | In use |
| Vermilion Fossil House | Fossil revival | In use |
| `NewMap1` (Vermilion) | Surge fan, truck rumour | Reachable; placeholder name |
| Pokémon Tower B1F | Wild Pokémon only | Reachable from 1F; no people or items (**Assumption:** unfinished) |
| Celadon Vitamin House | Two shops, Macho Brace, EV talk | In use |
| Celadon Berry House | Berry shop | In use |
| Celadon Poké Ball shop | Ball shop | In use |
| Saffron Battle House | 4 trainers, Bright Powder | In use |
| Cinnabar Battle House | Clerk only | Unfinished |
| Route 15 House of Elements | Punch tutors | In use |
| Seafoam Resort | 7 characters with no dialogue, surfing encounters | Unreachable, unfinished |

## Trainers

### Battle AI
**Tested.** How clever a trainer is depends on the trainer class. The list is in `src/data/trainer_ai_levels.h`; change a level there and rebuild.

| Level | Who | Choosing moves | Sending out the next Pokémon |
|---|---|---|---|
| 1 Simple | Bug Catcher, Youngster, Lass, Camper, Picnicker, Twins, Tuber, Young Couple, Sis and Bro, Fisherman, Aroma Lady, Lady, Beauty, Painter, Pokémon Breeder, and any class not listed | Avoids moves that would do nothing, otherwise random | Team order |
| 2 Knockout | Hiker, Super Nerd, Sailor, Biker, Cue Ball, Black Belt, Crush Girl, Crush Kin, Bird Keeper, Burglar, Channeler, Engineer, Gamer, Gentleman, Juggler, PokéManiac, Psychic, Rocker, Ruin Maniac, Scientist, Tamer, Team Rocket, Swimmers | Takes a knockout when it can and otherwise leans on its strongest attack. May still use status moves | Best matchup |
| 3 Boss | Gym leaders, Elite Four, Champion, rival, Giovanni, Cooltrainer, Pokémon Ranger, Cool Couple | The above, plus weighing each move for the situation | Best matchup, with the last Pokémon in the team saved for last |

- A trainer whose own settings in `trainers.h` are higher than the class keeps the higher level (two Team Rocket trainers are Level 3).
- **Best matchup** weighs the most damage the Pokémon can do to yours against how strongly your Pokémon's types hit it. Moves without a set power (such as Seismic Toss) are not counted.
- A saved Pokémon comes out only when it is the last one able to fight. Your Roar or Whirlwind can still drag it out.
- When bosses decide about stat moves, screens, Counter and Mirror Coat, they go by each move's Physical or Special category and the target species' higher attacking stat.
- Bosses now judge Facade, and stalling with Fly or Dig in sandstorm or hail, correctly (both were mistakes in the original).
- Bosses faster than you now use healing moves such as Recover when hurt (in the original they practically never did).
- No trainer uses Boomburst or Hyper Voice into Soundproof once your ability has shown itself; until then the AI guesses between the species' abilities, as it always has. Draco Meteor, Leaf Storm and Overheat are checked against immunities like other attacks.
- Bosses are keener on Sunny Day with Solar Power, and on Hail with Ice Body or Snow Cloak.
- The Sp. Atk-lowering logic now checks Sp. Atk. No move currently in the game only lowers Sp. Atk, so this changes nothing yet.
- **Bosses switch when they can't get anywhere** (not yet tested in game). The rule is described just below.
- Otherwise switching out mid-battle works as before. Enemy trainers never use items. The AI does not look at the move you are about to choose.
- Special battles whose teams are not in `trainers.h` (such as Trainer Tower) use the full logic and do not save a Pokémon.

#### When a boss switches because it is walled
Level 3, single battles only. All of these must be true at the start of its turn:

1. No attack it can use would take 20% of your Pokémon's maximum HP, or knock it out.
2. It has no useful status move that would work on you: sleep, Yawn, poison, paralysis, burn, confusion, Leech Seed, Perish Song or a Ghost-type's Curse.
3. It is not trapped.
4. It did not switch for this reason on its previous turn.
5. A teammate (not the saved last Pokémon, not asleep or frozen) can do that 20% or knock you out, and your Pokémon's types are not super effective against it.

It then sends out the best of those teammates, every time. Boosting, healing, screens and Protect do not keep it in.

- The estimate uses real stats, types and abilities, so for this one decision a boss knows your ability. It covers fixed-damage moves, absorbing abilities, Soundproof, Disable, Encore, Taunt, Choice Band and running out of PP.
- Moves whose strength cannot be known beforehand (such as Hidden Power, Counter, Low Kick, Metronome and one-hit knockouts) keep the active Pokémon in, but do not count for a teammate. Return and Frustration are worked out from friendship.
- The 20% is `AI_WALLED_DAMAGE_PERCENT` in `include/constants/battle_ai.h`.
- Choosing a replacement after a knockout still uses the simpler estimate above.

### Gym leaders and Elite Four
| Boss | Team (species, level) | Status |
|---|---|---|
| Brock | Geodude 13, Zubat 12, Onix 14 | Changed |
| Misty | Psyduck 20, Corsola 21, Starmie 23 | Changed |
| Lt. Surge | Lanturn 23, Voltorb 21, Elekid 22, Raichu 26 | Changed |
| Erika | Victreebel 33, Sunflora 32, Tangela 32, Vileplume 34 | Changed |
| Koga | Crobat 39, Ariados 38, Muk 41, Venomoth 38, Weezing 43 | Changed |
| Sabrina | Mr. Mime 39, Espeon 41, Haunter 37, Girafarig 37, Alakazam 44 | Changed |
| Blaine | Magcargo 43, Rapidash 44, Magmar 45, Octillery 44, Arcanine 46 | Changed |
| Giovanni | Rhyhorn 45, Dugtrio 42, Nidoqueen 44, Nidoking 45, Rhyhorn 50 | Original |
| Lorelei | Dewgong 52, Cloyster 51, Slowbro 52, Jynx 54, Lapras 54 | Original |
| Bruno | Onix 51, Hitmonchan 53, Hitmonlee 53, Onix 54, Machamp 56 | Original |
| Agatha | Gengar 54, Golbat 54, Haunter 53, Arbok 56, Gengar 58 | Original |
| Lance | Gyarados 56, Dragonair 54, Dragonair 54, Aerodactyl 58, Dragonite 60 | Original |

The rival and Champion teams are unchanged. Full movesets for changed trainers are in [CHANGELOG.md](CHANGELOG.md#trainers). Koga, Erika and Lt. Surge were committed with the note "UNTESTED".

### Other additions
- **Cerulean Battle House** (levels 15–16): Youngster Jamie, Black Belt Rogan, Hiker Jones.
- **Saffron Battle House** (levels 34–37): Brendan, May, Cooltrainer Duke, Cooltrainer Sylvia.
- **Route 2:** Picnicker Sally (level 5).
- **Route 24 (Nugget Bridge):** five of the battles are now double battles.
- **Rocket Hideout:** Giovanni leads with Persian.

## Where to find Pokémon (changed and new areas)

The original game has 113 wild species across FireRed's tables; this hack has 214. Areas not listed keep their original Pokémon. Seafoam Resort is listed but cannot be reached.

| Location | Pokémon (level range) |
|---|---|
| Viridian Forest | **Grass/floor:** Caterpie 4–5, Weedle 4, Pineco 5, Spinarak 3, Ledyba 3, Metapod 5, Kakuna 4–5, Pikachu 3–5, Pidgeotto 8 |
| Mt Moon 1F | **Grass/floor:** Zubat 7–8, Geodude 7–9, Teddiursa 9, Phanpy 9, Paras 7–8, Cleffa 7, Clefairy 8 |
| Mt Moon B1F | **Grass/floor:** Paras 5–10, Parasect 10 |
| Mt Moon B2F | **Grass/floor:** Zubat 8–11, Geodude 9–10, Teddiursa 9, Phanpy 9, Paras 10–12, Clefairy 10–12, Cleffa 11 |
| Digletts Cave B1F | **Grass/floor:** Diglett 17–22, Phanpy 15–17, Swinub 16, Dugtrio 29–31 |
| Victory Road 1F | **Grass/floor:** Rhyhorn 37, Graveler 38, Onix 40–46, Golbat 38–44, Golem 49, Ursaring 44–46, Tyrogue 44, Steelix 46 |
| Victory Road 2F | **Grass/floor:** Donphan 37, Graveler 38, Marowak 40, Machoke 43–46, Golbat 38–44, Golem 49, Larvitar 33, Pupitar 49 |
| Victory Road 3F | **Grass/floor:** Donphan 37, Graveler 38, Gligar 40–44, Ursaring 43, Onix 46–48, Golem 50, Bagon 33, Shelgon 49, Steelix 55 |
| Pokemon Mansion 1F | **Grass/floor:** Slugma 28–30, Grimer 28–32, Koffing 30–34, Magmar 35, Magcargo 36, Weezing 32, Muk 32 |
| Pokemon Mansion 2F | **Grass/floor:** Slugma 28–30, Grimer 28–32, Koffing 30–34, Magmar 35, Magcargo 36, Weezing 32, Muk 32 |
| Pokemon Mansion 3F | **Grass/floor:** Slugma 28–30, Grimer 28–32, Koffing 30–34, Magmar 35, Magcargo 36, Weezing 32, Muk 32, Castform 30 |
| Pokemon Mansion B1F | **Grass/floor:** Slugma 30, Grimer 28–32, Koffing 30–34, Magmar 35, Magcargo 36–42, Weezing 32, Muk 32 |
| Rock Tunnel 1F | **Grass/floor:** Zubat 15–16, Geodude 16, Rhyhorn 16–17, Machop 16–17, Skarmory 17–18, Onix 13–15 |
| Rock Tunnel B1F | **Grass/floor:** Zubat 15–16, Geodude 17, Sneasel 16–17, Machop 16–17, Onix 13–22, Skarmory 16–19<br>**Rock Smash:** Geodude 5–30, Graveler 25–40 |
| Seafoam Islands 1F | **Grass/floor:** Seel 27–28, Swinub 29–31, Zubat 22–26, Golbat 26–30, Piloswine 30–33 |
| Seafoam Islands B1F | **Grass/floor:** Seel 27–28, Swinub 29–31, Zubat 22–26, Golbat 26–30, Piloswine 30–33 |
| Seafoam Islands B2F | **Grass/floor:** Seel 30, Swinub 29–32, Sneasel 28–32, Jynx 26–34 |
| Seafoam Islands B3F | **Grass/floor:** Piloswine 30, Sneasel 24–32, Delibird 32, Jynx 26–34<br>**Surf:** Shellder 25–35, Seel 25–30, Dewgong 30–40<br>**Fishing:** Magikarp 5–15, Horsea 5–30, Krabby 5–15, Gyarados 15–35, Psyduck 15–25 |
| Seafoam Islands B4F | **Grass/floor:** Delibird 24–32, Sneasel 32, Jynx 26–34<br>**Surf:** Shellder 25–35, Seel 25–30, Dewgong 30–40<br>**Fishing:** Magikarp 5–15, Horsea 5–30, Krabby 5–15, Gyarados 15–35, Psyduck 15–25 |
| Pokemon Tower 3F | **Grass/floor:** Gastly 15–16, Vulpix 13–19, Noctowl 18, Cubone 15–17, Haunter 20 |
| Pokemon Tower 4F | **Grass/floor:** Gastly 15–17, Misdreavus 13–17, Noctowl 14, Cubone 15–18, Haunter 20, Ninetales 26 |
| Pokemon Tower 5F | **Grass/floor:** Gastly 16–19, Misdreavus 13–17, Noctowl 18, Haunter 20, Cubone 15–17 |
| Pokemon Tower 6F | **Grass/floor:** Gastly 16–18, Misdreavus 14–19, Haunter 21–23, Cubone 17–19 |
| Pokemon Tower 7F | **Grass/floor:** Gastly 16–18, Misdreavus 15–19, Haunter 23–25, Cubone 17–19 |
| Power Plant | **Grass/floor:** Voltorb 22–25, Magnemite 22–25, Muk 29, Pikachu 24, Magneton 31–34, Electabuzz 30–35 |
| Mt Ember Exterior | **Grass/floor:** Numel 30–33, Meditite 30–34, Medicham 39, Trapinch 33, Vibrava 36, Camerupt 42<br>**Rock Smash:** Geodude 5–30, Graveler 25–40 |
| Mt Ember Summit Path 1F | **Grass/floor:** Makuhita 31–33, Slugma 29–35, Aron 31–33, Torkoal 35–37, Machoke 37–39 |
| Mt Ember Summit Path 2F | **Grass/floor:** Makuhita 31–33, Slugma 29–35, Aron 31–33, Torkoal 35–37, Machoke 37–39<br>**Rock Smash:** Geodude 5–30, Graveler 25–40 |
| Mt Ember Summit Path 3F | **Grass/floor:** Makuhita 31–33, Slugma 29–35, Aron 31–33, Torkoal 35–37, Machoke 37–39 |
| Mt Ember Ruby Path 1F | **Grass/floor:** Makuhita 31–33, Slugma 29–35, Aron 31–33, Torkoal 35–37, Machoke 37–39<br>**Rock Smash:** Geodude 25–40, Graveler 30–50 |
| Mt Ember Ruby Path B1F | **Grass/floor:** Makuhita 31–33, Slugma 29–35, Aron 31–33, Torkoal 35–37, Machoke 37–39<br>**Rock Smash:** Geodude 25–40, Graveler 30–50 |
| Mt Ember Ruby Path B2F | **Grass/floor:** Makuhita 31–33, Slugma 29–35, Aron 31–33, Torkoal 35–37, Machoke 37–39<br>**Rock Smash:** Geodude 25–40, Graveler 30–50 |
| Mt Ember Ruby Path B3F | **Grass/floor:** Makuhita 31–33, Slugma 29–35, Aron 31–33, Torkoal 35–37, Machoke 37–39<br>**Rock Smash:** Slugma 15–35, Magcargo 25–45 |
| Mt Ember Ruby Path B1F Stairs | **Grass/floor:** Makuhita 31–33, Slugma 29–35, Aron 31–33, Torkoal 35–37, Machoke 37–39<br>**Rock Smash:** Geodude 25–40, Graveler 30–50 |
| Mt Ember Ruby Path B2F Stairs | **Grass/floor:** Makuhita 31–33, Slugma 29–35, Aron 31–33, Torkoal 35–37, Machoke 37–39<br>**Rock Smash:** Geodude 25–40, Graveler 30–50 |
| Three Island Berry Forest | **Grass/floor:** Wurmple 30–32, Silcoon 36, Cascoon 36, Slakoth 34, Vigoroth 38–39, Illumise 37, Volbeat 37, Hypno 44<br>**Surf:** Psyduck 5–40, Golduck 35–40<br>**Fishing:** Magikarp 5–15, Goldeen 5–25, Poliwag 5–15, Seaking 20–30, Gyarados 15–25, Psyduck 15–35 |
| One Island Kindle Road | **Grass/floor:** Taillow 30–32, Numel 33–34, Swellow 27–40, Meditite 31–33, Spoink 32–33, Camerupt 40<br>**Surf:** Tentacool 5–40, Tentacruel 35–40<br>**Rock Smash:** Geodude 5–30, Graveler 25–40<br>**Fishing:** Magikarp 5–15, Horsea 5–25, Gyarados 15–25, Seadra 25–35, Psyduck 25–35 |
| One Island Treasure Beach | **Grass/floor:** Lotad 32, Skitty 33, Lombre 35, Corphish 35–36, Wingull 31–33, Pelipper 40<br>**Surf:** Tentacool 5–40, Tentacruel 35–40<br>**Fishing:** Magikarp 5–15, Horsea 5–25, Gyarados 15–25, Seadra 25–35, Psyduck 25–35 |
| Two Island Cape Brink | **Grass/floor:** Taillow 31–33, Poochyena 30–32, Zigzagoon 31–33, Swellow 38, Mightyena 40, Linoone 37–40, Persian 37–40<br>**Surf:** Psyduck 5–40, Golduck 35–40<br>**Fishing:** Magikarp 5–15, Poliwag 5–25, Goldeen 5–15, Poliwhirl 20–30, Gyarados 15–25, Psyduck 15–35 |
| Three Island Bond Bridge | **Grass/floor:** Electrike 29–32, Gulpin 31, Swalot 39, Minun 36, Plusle 36, Ralts 31–34, Kirlia 37–40, Manectric 40<br>**Surf:** Tentacool 5–40, Tentacruel 35–40<br>**Fishing:** Magikarp 5–15, Horsea 5–25, Gyarados 15–25, Seadra 25–35, Psyduck 25–35 |
| Three Island Port | **Grass/floor:** Spinda 10–30, Dunsparce 5–35 |
| Route 1 | **Grass/floor:** Pidgey 2–3, Rattata 3–4, Pichu 2, Sentret 3–5, Eevee 3 |
| Route 2 | **Grass/floor:** Pidgey 3–4, Rattata 3–4, Vulpix 3, Hoothoot 4, Hoppip 5, Mankey 4–5 |
| Route 3 | **Grass/floor:** Spearow 6–8, Pidgey 6, Teddiursa 7, Mankey 7, Nidoran♂ 6–7, Phanpy 7, Jigglypuff 3–7, Nidoran♀ 6 |
| Route 4 | **Grass/floor:** Sandshrew 10, Ekans 10, Spearow 10–13, Smoochum 10–12, Magby 10–12, Elekid 10–12, Corsola 12<br>**Surf:** Tentacool 5–40<br>**Fishing:** Magikarp 5–15, Horsea 5–35, Krabby 5–15, Gyarados 15–25, Psyduck 25–35 |
| Route 5 | **Grass/floor:** Meowth 10–12, Pidgey 13, Farfetch'd 13–16, Psyduck 15, Lickitung 16 |
| Route 6 | **Grass/floor:** Meowth 13, Natu 13, Ekans 13–15, Sandshrew 12–15, Psyduck 14–16, Golduck 16<br>**Surf:** Psyduck 20–40<br>**Fishing:** Magikarp 5–15, Poliwag 5–25, Goldeen 5–15, Poliwhirl 20–30, Gyarados 15–25, Psyduck 15–35 |
| Route 7 | **Grass/floor:** Aipom 17–19, Teddiursa 17, Oddish 19, Bellsprout 18, Weepinbell 22, Gloom 22, Skiploom 17–19, Scyther 20, Sudowoodo 20 |
| Route 8 | **Grass/floor:** Ponyta 16–18, Teddiursa 18, Pidgeotto 20, Aipom 17–20, Murkrow 15–19, Smeargle 18 |
| Route 9 | **Grass/floor:** Spearow 16, Rattata 16, Venonat 15–16, Tangela 13–14, Slowpoke 15–18 |
| Route 10 | **Grass/floor:** Wooper 13–17, Voltorb 14–16, Venonat 11–15, Yanma 13–17<br>**Surf:** Tentacool 5–40<br>**Fishing:** Magikarp 5–15, Horsea 5–35, Krabby 5–15, Gyarados 15–25, Psyduck 25–35 |
| Route 11 | **Grass/floor:** Farfetch'd 14, Natu 15, Growlithe 12–13, Drowzee 11–13, Magnemite 12–17, Heracross 15, Magneton 22<br>**Surf:** Tentacool 5–40<br>**Fishing:** Magikarp 5–15, Horsea 5–35, Krabby 5–15, Gyarados 15–25, Psyduck 25–35 |
| Route 12 | **Grass/floor:** Poliwag 24, Krabby 24, Marill 22–26, Tauros 23, Miltank 25, Poliwhirl 26–27, Growlithe 23–28, Politoed 33<br>**Surf:** Tentacool 5–40<br>**Fishing:** Magikarp 5–15, Horsea 5–35, Krabby 5–15, Gyarados 15–25, Psyduck 25–35 |
| Route 13 | **Grass/floor:** Ledian 24–29, Stantler 24–28, Girafarig 22–27, Tauros 26, Miltank 26, Shuckle 25–26, Chansey 30<br>**Surf:** Tentacool 5–40<br>**Fishing:** Magikarp 5–15, Horsea 5–35, Krabby 5–15, Gyarados 15–25, Psyduck 25–35 |
| Route 14 | **Grass/floor:** Pidgeotto 24, Furret 24, Ledian 22, Ditto 23, Nidorino 26–27, Nidorina 26–27, Girafarig 26–29 |
| Route 15 | **Grass/floor:** Gloom 24, Weepinbell 24, Gligar 22–26, Pidgeotto 25–27, Ditto 25, Mr. Mime 28–30 |
| Route 16 | **Grass/floor:** Meowth 20, Doduo 18–20, Ponyta 18–23, Snubbull 20, Persian 24, Granbull 22, Pinsir 22–25 |
| Route 17 | **Grass/floor:** Ponyta 20, Doduo 24–26, Koffing 22–25, Raticate 25–27, Fearow 28–29, Rapidash 30 |
| Route 18 | **Grass/floor:** Koffing 20–22, Doduo 24–26, Raticate 25–29, Fearow 25, Ariados 26–28, Dodrio 27–29, Weezing 29 |
| Route 21 North | **Grass/floor:** Tangela 22–28, Pidgeotto 25, Poliwhirl 22–28, Kangaskhan 29, Dunsparce 25–28<br>**Surf:** Tentacool 5–40<br>**Fishing:** Magikarp 5–15, Horsea 5–25, Krabby 5–15, Gyarados 15–25, Seadra 25–35, Psyduck 25–35 |
| Route 22 | **Grass/floor:** Nidoran♀ 3, Nidoran♂ 3, Mankey 4, Hoppip 2, Spearow 2–5, Jigglypuff 5<br>**Surf:** Psyduck 20–40<br>**Fishing:** Magikarp 5–15, Poliwag 5–25, Goldeen 5–15, Poliwhirl 20–30, Gyarados 15–25, Psyduck 15–35 |
| Route 23 | **Grass/floor:** Primeape 38, Fearow 40, Arbok 41–44, Sandslash 41–44, Donphan 38–44, Larvitar 32, Tyrogue 33<br>**Surf:** Psyduck 20–40<br>**Fishing:** Magikarp 5–15, Poliwag 5–25, Goldeen 5–15, Poliwhirl 20–30, Gyarados 15–25, Psyduck 15–35 |
| Route 24 | **Grass/floor:** Snubbull 9, Mareep 11, Bellsprout 11–14, Oddish 12–13, Abra 10, Houndour 10–14<br>**Surf:** Tentacool 5–40<br>**Fishing:** Magikarp 5–15, Horsea 5–35, Krabby 5–15, Gyarados 15–25, Psyduck 25–35 |
| Route 25 | **Grass/floor:** Snubbull 12, Houndour 13, Bellsprout 11–13, Oddish 13–14, Abra 11, Mareep 9, Flaaffy 13<br>**Surf:** Psyduck 20–40<br>**Fishing:** Magikarp 5–15, Poliwag 5–25, Goldeen 5–15, Poliwhirl 20–30, Gyarados 15–25, Psyduck 15–35 |
| Cerulean City | **Grass/floor:** Marill 15–16, Houndour 16, Psyduck 15–17, Snubbull 17, Corsola 18–19<br>**Surf:** Tentacool 5–40<br>**Fishing:** Magikarp 5–15, Horsea 5–35, Krabby 5–15, Gyarados 15–25, Psyduck 25–35 |
| Celadon City | **Grass/floor:** Shroomish 19–21, Seedot 19–21, Exeggcute 21–22, Roselia 22–24, Chimecho 19<br>**Surf:** Psyduck 5–40, Koffing 30–40<br>**Fishing:** Magikarp 5–35, Grimer 30–40 |
| Pokemon Tower B1F | **Grass/floor:** Misdreavus 15–18, Gastly 15–17, Duskull 16, Shuppet 16, Haunter 20, Cubone 15–17, Gengar 33 |
| Seafoam Resort | **Surf:** Wooper 23–24, Quagsire 28–31, Mantine 21–55 |
| Pewter City | **Grass/floor:** Rattata 3–4, Hoothoot 4, Sunkern 3–5, Vulpix 4–6, Poliwag 3–5 |

### Not obtainable (from Pokémon #1–251)
I checked wild tables, gifts, set encounters, evolution, and breeding and in-game trades:

- **Staryu, Starmie, Chinchou, Lanturn, Remoraid, Octillery**
- **Mantine** (only in the unreachable Seafoam Resort)
- **All Johto starters** and their evolutions (9 Pokémon)
- **Mew and Celebi** (event Pokémon)

Also limited:
- **Lugia, Ho-Oh and Deoxys** need event tickets, and I found nothing in the game that gives them.
- **Bulbasaur, Charmander and Squirtle** come only as the starter choice.
- **Raikou, Entei and Suicune** roam after the Sevii Islands quest, as in the original (one per save).
- **Generation 3** Pokémon were not checked for completeness.
