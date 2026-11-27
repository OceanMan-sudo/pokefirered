#ifndef GUARD_LEVEL_CAP_H
#define GUARD_LEVEL_CAP_H

// The numbers themselves are in src/data/level_caps.h

u8 GetStoryLevelCap(void);
u8 GetLevelCap(void);
u32 LimitExpToLevelCap(u16 species, u32 currentExp, u32 expGain);
void RecalculateCappedMonStats(void);

#endif // GUARD_LEVEL_CAP_H
