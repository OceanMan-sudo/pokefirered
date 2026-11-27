// LEVEL CAPS: change the numbers here.
//
// Each line is the highest level your Pokémon can reach while you have that many
// badges. Use whole numbers from 1 to 100. The cap always goes away after you
// beat the Champion.

static const u8 sLevelCaps[NUM_BADGES + 1] =
{
    14, // 0 badges (next: Brock)
    23, // 1 badge  (next: Misty)
    26, // 2 badges (next: Lt. Surge)
    34, // 3 badges (next: Erika)
    43, // 4 badges (next: Koga)
    44, // 5 badges (next: Sabrina)
    46, // 6 badges (next: Blaine)
    50, // 7 badges (next: Giovanni)
    63, // 8 badges (the whole Pokémon League)
};
