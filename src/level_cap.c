#include "global.h"
#include "event_data.h"
#include "level_cap.h"
#include "pokemon.h"
#include "constants/flags.h"
#include "data/level_caps.h"

// The cap for the current point in the story, whether or not it is switched on.
// MAX_LEVEL means there is no cap.
u8 GetStoryLevelCap(void)
{
    u8 i;
    u8 badges = 0;

    if (FlagGet(FLAG_SYS_GAME_CLEAR))
        return MAX_LEVEL;

    for (i = 0; i < NUM_BADGES; i++)
    {
        if (FlagGet(FLAG_BADGE01_GET + i))
            badges++;
    }
    return sLevelCaps[badges];
}

// The cap that applies right now, including the switch in the Options menu
u8 GetLevelCap(void)
{
    if (gSaveBlock2Ptr->optionsLevelCapOff)
        return MAX_LEVEL;
    return GetStoryLevelCap();
}

// How much of an EXP gain a Pokémon may keep. It stops exactly at the cap level.
// A Pokémon already past the cap keeps its level but gains nothing.
u32 LimitExpToLevelCap(u16 species, u32 currentExp, u32 expGain)
{
    u8 cap = GetLevelCap();
    u32 capExp;

    if (cap >= MAX_LEVEL)
        return expGain;

    capExp = gExperienceTables[gSpeciesInfo[species].growthRate][cap];
    if (currentExp >= capExp)
        return 0;
    if (expGain > capExp - currentExp)
        return capExp - currentExp;
    return expGain;
}

// Capped Pokémon still earn EVs but cannot level up, which is when stats are
// normally recalculated. This applies their EVs after a battle.
void RecalculateCappedMonStats(void)
{
    u8 i;
    u8 level;
    u8 cap = GetLevelCap();

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) == SPECIES_NONE
         || GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
            continue;

        level = GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);
        if (level >= cap && level < MAX_LEVEL)
            CalculateMonStats(&gPlayerParty[i]);
    }
}
