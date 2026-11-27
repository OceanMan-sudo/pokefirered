#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_ai_script_commands.h"
#include "battle_controllers.h"
#include "random.h"
#include "util.h"
#include "constants/abilities.h"
#include "constants/battle_ai.h"
#include "constants/battle_move_effects.h"
#include "constants/item_effects.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"

static bool8 HasSuperEffectiveMoveAgainstOpponents(bool8 noRng);
static bool8 FindMonWithFlagsAndSuperEffective(u8 flags, u8 moduloPercent);
static bool8 ShouldUseItem(void);
static void ModulateByTypeEffectiveness(u8 atkType, u8 defType1, u8 defType2, u8 *var);

// Party slot of the Pokemon this trainer is saving for last (the last one in
// the team), or PARTY_SIZE if they aren't saving one.
static u8 GetSavedAceId(void)
{
    s32 i;

    if (!OpponentAiSavesAce())
        return PARTY_SIZE;
    for (i = PARTY_SIZE - 1; i >= 0; --i)
    {
        u16 species = GetMonData(&gEnemyParty[i], MON_DATA_SPECIES_OR_EGG);

        if (species != SPECIES_NONE && species != SPECIES_EGG)
            return i;
    }
    return PARTY_SIZE;
}

static bool8 ShouldSwitchIfPerishSong(void)
{
    if (gStatuses3[gActiveBattler] & STATUS3_PERISH_SONG
     && gDisableStructs[gActiveBattler].perishSongTimer == 0)
    {
        *(gBattleStruct->AI_monToSwitchIntoId + (GetBattlerPosition(gActiveBattler) >> 1)) = PARTY_SIZE;
        BtlController_EmitTwoReturnValues(1, B_ACTION_SWITCH, 0);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static bool8 ShouldSwitchIfWonderGuard(void)
{
    u8 opposingBattler;
    u8 moveFlags;
    u8 aceId = GetSavedAceId();
    s32 i, j;
    u16 move;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        return FALSE;
    if (gBattleMons[GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)].ability == ABILITY_WONDER_GUARD)
    {
        // Check if Pokemon has a super effective move.
        for (opposingBattler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT), i = 0; i < MAX_MON_MOVES; ++i)
        {
            move = gBattleMons[gActiveBattler].moves[i];
            if (move == MOVE_NONE)
                continue;
            moveFlags = AI_TypeCalc(move, gBattleMons[opposingBattler].species, gBattleMons[opposingBattler].ability);
            if (moveFlags & MOVE_RESULT_SUPER_EFFECTIVE)
                return FALSE;
        }
        // Find a Pokemon in the party that has a super effective move.
        for (i = 0; i < PARTY_SIZE; ++i)
        {
            if (GetMonData(&gEnemyParty[i], MON_DATA_HP) == 0
             || GetMonData(&gEnemyParty[i], MON_DATA_SPECIES_OR_EGG) == SPECIES_NONE
             || GetMonData(&gEnemyParty[i], MON_DATA_SPECIES_OR_EGG) == SPECIES_EGG
             || i == gBattlerPartyIndexes[gActiveBattler]
             || i == aceId)
                continue;
            GetMonData(&gEnemyParty[i], MON_DATA_SPECIES); // Unused return value.
            GetMonData(&gEnemyParty[i], MON_DATA_ABILITY_NUM); // Unused return value.        
            for (opposingBattler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT), j = 0; j < MAX_MON_MOVES; ++j)
            {
                move = GetMonData(&gEnemyParty[i], MON_DATA_MOVE1 + j);
                if (move == MOVE_NONE)
                    continue;
                moveFlags = AI_TypeCalc(move, gBattleMons[opposingBattler].species, gBattleMons[opposingBattler].ability);
                if (moveFlags & MOVE_RESULT_SUPER_EFFECTIVE && Random() % 3 < 2)
                {
                    // We found a mon.
                    *(gBattleStruct->AI_monToSwitchIntoId + (GetBattlerPosition(gActiveBattler) >> 1)) = i;
                    BtlController_EmitTwoReturnValues(1, B_ACTION_SWITCH, 0);
                    return TRUE;
                }
            }
        }
    }
    return FALSE; // There is not a single Pokemon in the party that has a super effective move against a mon with Wonder Guard.
}

static bool8 FindMonThatAbsorbsOpponentsMove(void)
{
    u8 battlerIn1, battlerIn2;
    u8 aceId = GetSavedAceId();
    u8 absorbingTypeAbility;
    s32 i;

    if ((HasSuperEffectiveMoveAgainstOpponents(TRUE) && Random() % 3) 
    || (gLastLandedMoves[gActiveBattler] == MOVE_NONE))
        return FALSE;
    if (gLastLandedMoves[gActiveBattler] == 0xFFFF
     || gBattleMoves[gLastLandedMoves[gActiveBattler]].power == 0)
        return FALSE;
    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        battlerIn1 = gActiveBattler;
        if (gAbsentBattlerFlags & gBitTable[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)))])
            battlerIn2 = gActiveBattler;
        else
            battlerIn2 = GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)));
    }
    else
    {
        battlerIn1 = gActiveBattler;
        battlerIn2 = gActiveBattler;
    }
    if (gBattleMoves[gLastLandedMoves[gActiveBattler]].type == TYPE_FIRE)
        absorbingTypeAbility = ABILITY_FLASH_FIRE;
    else if (gBattleMoves[gLastLandedMoves[gActiveBattler]].type == TYPE_WATER)
        absorbingTypeAbility = ABILITY_WATER_ABSORB;
    else if (gBattleMoves[gLastLandedMoves[gActiveBattler]].type == TYPE_ELECTRIC)
        absorbingTypeAbility = ABILITY_VOLT_ABSORB;
    else
        return FALSE;
    if (gBattleMons[gActiveBattler].ability == absorbingTypeAbility)
        return FALSE;
    for (i = 0; i < PARTY_SIZE; ++i)
    {
        u16 species;
        u8 monAbility;

        if ((GetMonData(&gEnemyParty[i], MON_DATA_HP) == 0)
         || (GetMonData(&gEnemyParty[i], MON_DATA_SPECIES_OR_EGG) == SPECIES_NONE)
         || (GetMonData(&gEnemyParty[i], MON_DATA_SPECIES_OR_EGG) == SPECIES_EGG)
         || (i == gBattlerPartyIndexes[battlerIn1])
         || (i == gBattlerPartyIndexes[battlerIn2])
         || (i == *(gBattleStruct->monToSwitchIntoId + battlerIn1))
         || (i == *(gBattleStruct->monToSwitchIntoId + battlerIn2))
         || (i == aceId))
            continue;
        species = GetMonData(&gEnemyParty[i], MON_DATA_SPECIES);
        if (GetMonData(&gEnemyParty[i], MON_DATA_ABILITY_NUM) != ABILITY_NONE)
            monAbility = gSpeciesInfo[species].abilities[1];
        else
            monAbility = gSpeciesInfo[species].abilities[0];
        if (absorbingTypeAbility == monAbility && Random() & 1)
        {
            // we found a mon
            *(gBattleStruct->AI_monToSwitchIntoId + (GetBattlerPosition(gActiveBattler) >> 1)) = i;
            BtlController_EmitTwoReturnValues(1, B_ACTION_SWITCH, 0);
            return TRUE;
        }
    }
    return FALSE;
}

static bool8 ShouldSwitchIfNaturalCure(void)
{
    if (!(gBattleMons[gActiveBattler].status1 & STATUS1_SLEEP)
     || (gBattleMons[gActiveBattler].ability != ABILITY_NATURAL_CURE)
     || (gBattleMons[gActiveBattler].hp < gBattleMons[gActiveBattler].maxHP / 2))
        return FALSE;
    if ((gLastLandedMoves[gActiveBattler] == MOVE_NONE || gLastLandedMoves[gActiveBattler] == 0xFFFF) && Random() & 1)
    {
        *(gBattleStruct->AI_monToSwitchIntoId + (GetBattlerPosition(gActiveBattler) >> 1)) = PARTY_SIZE;
        BtlController_EmitTwoReturnValues(1, B_ACTION_SWITCH, 0);
        return TRUE;
    }
    else if (gBattleMoves[gLastLandedMoves[gActiveBattler]].power == 0 && Random() & 1)
    {
        *(gBattleStruct->AI_monToSwitchIntoId + (GetBattlerPosition(gActiveBattler) >> 1)) = PARTY_SIZE;
        BtlController_EmitTwoReturnValues(1, B_ACTION_SWITCH, 0);
        return TRUE;
    }
    if (FindMonWithFlagsAndSuperEffective(MOVE_RESULT_DOESNT_AFFECT_FOE, 1)
     || FindMonWithFlagsAndSuperEffective(MOVE_RESULT_NOT_VERY_EFFECTIVE, 1))
        return TRUE;
    if (Random() & 1)
    {
        *(gBattleStruct->AI_monToSwitchIntoId + (GetBattlerPosition(gActiveBattler) >> 1)) = PARTY_SIZE;
        BtlController_EmitTwoReturnValues(1, B_ACTION_SWITCH, 0);
        return TRUE;
    }
    return FALSE;
}

static bool8 HasSuperEffectiveMoveAgainstOpponents(bool8 noRng)
{
    u8 opposingBattler;
    s32 i;
    u8 moveFlags;
    u16 move;

    opposingBattler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
    if (!(gAbsentBattlerFlags & gBitTable[opposingBattler]))
    {
        for (i = 0; i < MAX_MON_MOVES; ++i)
        {
            move = gBattleMons[gActiveBattler].moves[i];
            if (move == MOVE_NONE)
                continue;

            moveFlags = AI_TypeCalc(move, gBattleMons[opposingBattler].species, gBattleMons[opposingBattler].ability);
            if (moveFlags & MOVE_RESULT_SUPER_EFFECTIVE)
            {
                if (noRng || (Random() % 10))
                    return TRUE;
            }
        }
    }
    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
        return FALSE;
    opposingBattler = GetBattlerAtPosition(BATTLE_PARTNER(B_POSITION_PLAYER_LEFT));
    if (!(gAbsentBattlerFlags & gBitTable[opposingBattler]))
    {
        for (i = 0; i < MAX_MON_MOVES; ++i)
        {
            move = gBattleMons[gActiveBattler].moves[i];
            if (move == MOVE_NONE)
                continue;
            moveFlags = AI_TypeCalc(move, gBattleMons[opposingBattler].species, gBattleMons[opposingBattler].ability);
            if (moveFlags & MOVE_RESULT_SUPER_EFFECTIVE)
            {
                if (noRng)
                    return TRUE;
                if (Random() % 10 != 0)
                    return TRUE;
            }
        }
    }
    return FALSE;
}

static bool8 AreStatsRaised(void)
{
    u8 buffedStatsValue = 0;
    s32 i;

    for (i = 0; i < NUM_BATTLE_STATS; ++i)
    {
        if (gBattleMons[gActiveBattler].statStages[i] > 6)
            buffedStatsValue += gBattleMons[gActiveBattler].statStages[i] - 6;
    }
    return (buffedStatsValue > 3);
}

static bool8 FindMonWithFlagsAndSuperEffective(u8 flags, u8 moduloPercent)
{
    u8 battlerIn1, battlerIn2;
    u8 aceId = GetSavedAceId();
    s32 i, j;
    u16 move;
    u8 moveFlags;

    if (gLastLandedMoves[gActiveBattler] == 0)
        return FALSE;
    if ((gLastLandedMoves[gActiveBattler] == 0xFFFF)
     || (gLastHitBy[gActiveBattler] == 0xFF)
     || (gBattleMoves[gLastLandedMoves[gActiveBattler]].power == 0))
        return FALSE;
    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        battlerIn1 = gActiveBattler;
        if (gAbsentBattlerFlags & gBitTable[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)))])
            battlerIn2 = gActiveBattler;
        else
            battlerIn2 = GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)));
    }
    else
    {
        battlerIn1 = gActiveBattler;
        battlerIn2 = gActiveBattler;
    }
    for (i = 0; i < PARTY_SIZE; ++i)
    {
        u16 species;
        u8 monAbility;

        if ((GetMonData(&gEnemyParty[i], MON_DATA_HP) == 0)
         || (GetMonData(&gEnemyParty[i], MON_DATA_SPECIES_OR_EGG) == SPECIES_NONE)
         || (GetMonData(&gEnemyParty[i], MON_DATA_SPECIES_OR_EGG) == SPECIES_EGG)
         || (i == gBattlerPartyIndexes[battlerIn1])
         || (i == gBattlerPartyIndexes[battlerIn2])
         || (i == *(gBattleStruct->monToSwitchIntoId + battlerIn1))
         || (i == *(gBattleStruct->monToSwitchIntoId + battlerIn2))
         || (i == aceId))
            continue;
        species = GetMonData(&gEnemyParty[i], MON_DATA_SPECIES);
        if (GetMonData(&gEnemyParty[i], MON_DATA_ABILITY_NUM) != ABILITY_NONE)
            monAbility = gSpeciesInfo[species].abilities[1];
        else
            monAbility = gSpeciesInfo[species].abilities[0];
        moveFlags = AI_TypeCalc(gLastLandedMoves[gActiveBattler], species, monAbility);
        if (moveFlags & flags)
        {
            battlerIn1 = gLastHitBy[gActiveBattler];
            for (j = 0; j < MAX_MON_MOVES; ++j)
            {
                move = GetMonData(&gEnemyParty[i], MON_DATA_MOVE1 + j);
                if (move == MOVE_NONE)
                    continue;
                moveFlags = AI_TypeCalc(move, gBattleMons[battlerIn1].species, gBattleMons[battlerIn1].ability);
                if (moveFlags & MOVE_RESULT_SUPER_EFFECTIVE && Random() % moduloPercent == 0)
                {
                    *(gBattleStruct->AI_monToSwitchIntoId + (GetBattlerPosition(gActiveBattler) >> 1)) = i;
                    BtlController_EmitTwoReturnValues(1, B_ACTION_SWITCH, 0);
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

static bool8 ShouldSwitch(void)
{
    u8 battlerIn1, battlerIn2;
    u8 aceId = GetSavedAceId();
    s32 i;
    s32 availableToSwitch;

    if ((gBattleMons[gActiveBattler].status2 & (STATUS2_WRAPPED | STATUS2_ESCAPE_PREVENTION))
     || (gStatuses3[gActiveBattler] & STATUS3_ROOTED)
     || AbilityBattleEffects(ABILITYEFFECT_CHECK_OTHER_SIDE, gActiveBattler, ABILITY_SHADOW_TAG, 0, 0)
     || AbilityBattleEffects(ABILITYEFFECT_CHECK_OTHER_SIDE, gActiveBattler, ABILITY_ARENA_TRAP, 0, 0))
        return FALSE; // misses the flying or levitate check
    if (AbilityBattleEffects(ABILITYEFFECT_FIELD_SPORT, 0, ABILITY_MAGNET_PULL, 0, 0))
        if ((gBattleMons[gActiveBattler].type1 == TYPE_STEEL) || (gBattleMons[gActiveBattler].type2 == TYPE_STEEL))
            return FALSE;
    availableToSwitch = 0;
    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        battlerIn1 = gActiveBattler;
        if (gAbsentBattlerFlags & gBitTable[GetBattlerAtPosition(GetBattlerPosition(gActiveBattler) ^ BIT_FLANK)])
            battlerIn2 = gActiveBattler;
        else
            battlerIn2 = GetBattlerAtPosition(GetBattlerPosition(gActiveBattler) ^ BIT_FLANK);
    }
    else
    {
        battlerIn2 = gActiveBattler;
        battlerIn1 = gActiveBattler;
    }
    for (i = 0; i < PARTY_SIZE; ++i)
    {
        if ((GetMonData(&gEnemyParty[i], MON_DATA_HP) == 0)
         || (GetMonData(&gEnemyParty[i], MON_DATA_SPECIES_OR_EGG) == SPECIES_NONE)
         || (GetMonData(&gEnemyParty[i], MON_DATA_SPECIES_OR_EGG) == SPECIES_EGG)
         || (i == gBattlerPartyIndexes[battlerIn1])
         || (i == gBattlerPartyIndexes[battlerIn2])
         || (i == *(gBattleStruct->monToSwitchIntoId + battlerIn1))
         || (i == *(gBattleStruct->monToSwitchIntoId + battlerIn2))
         || (i == aceId))
            continue;
        ++availableToSwitch;
    }
    if (!availableToSwitch)
        return FALSE;
    if (ShouldSwitchIfPerishSong()
     || ShouldSwitchIfWonderGuard()
     || FindMonThatAbsorbsOpponentsMove()
     || ShouldSwitchIfNaturalCure())
        return TRUE;
    if (HasSuperEffectiveMoveAgainstOpponents(FALSE)
     || AreStatsRaised())
        return FALSE;
    if (FindMonWithFlagsAndSuperEffective(MOVE_RESULT_DOESNT_AFFECT_FOE, 2)
     || FindMonWithFlagsAndSuperEffective(MOVE_RESULT_NOT_VERY_EFFECTIVE, 3))
        return TRUE;
    return FALSE;
}

void AI_TrySwitchOrUseItem(void)
{
    u8 battlerIn1, battlerIn2;

    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
    {
        if (ShouldSwitch())
        {
            if (*(gBattleStruct->AI_monToSwitchIntoId + (GetBattlerPosition(gActiveBattler) >> 1)) == 6)
            {
                s32 monToSwitchId = GetMostSuitableMonToSwitchInto();
                if (monToSwitchId == 6)
                {
                    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
                    {
                        battlerIn1 = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
                        battlerIn2 = battlerIn1;
                    }
                    else
                    {
                        battlerIn1 = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
                        battlerIn2 = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
                    }
                    for (monToSwitchId = 0; monToSwitchId < PARTY_SIZE; ++monToSwitchId)
                    {
                        if ((!GetMonData(&gEnemyParty[monToSwitchId], MON_DATA_HP) == 0)
                         && (monToSwitchId != gBattlerPartyIndexes[battlerIn1])
                         && (monToSwitchId != gBattlerPartyIndexes[battlerIn2])
                         && (monToSwitchId != *(gBattleStruct->monToSwitchIntoId + battlerIn1))
                         && (monToSwitchId != *(gBattleStruct->monToSwitchIntoId + battlerIn2)))
                            break;
                    }
                }
                *(gBattleStruct->AI_monToSwitchIntoId + (GetBattlerPosition(gActiveBattler) >> 1)) = monToSwitchId;
            }
            *(gBattleStruct->monToSwitchIntoId + gActiveBattler) = *(gBattleStruct->AI_monToSwitchIntoId + (GetBattlerPosition(gActiveBattler) >> 1));
            return;
        }
        else if (ShouldUseItem())
        {
            return;
        }
    }
    BtlController_EmitTwoReturnValues(1, B_ACTION_USE_MOVE, (gActiveBattler ^ BIT_SIDE) << 8);
}

static void ModulateByTypeEffectiveness(u8 atkType, u8 defType1, u8 defType2, u8 *var)
{
    s32 i = 0;

    while (TYPE_EFFECT_ATK_TYPE(i) != TYPE_ENDTABLE)
    {
        if (TYPE_EFFECT_ATK_TYPE(i) == TYPE_FORESIGHT)
        {
            i += 3;
            continue;
        }
        else if (TYPE_EFFECT_ATK_TYPE(i) == atkType)
        {
            // Check type1.
            if (TYPE_EFFECT_DEF_TYPE(i) == defType1)
                *var = (*var * TYPE_EFFECT_MULTIPLIER(i)) / 10;
            // Check type2.
            if (TYPE_EFFECT_DEF_TYPE(i) == defType2 && defType1 != defType2)
                *var = (*var * TYPE_EFFECT_MULTIPLIER(i)) / 10;
        }
        i += 3;
    }
}

static bool8 CanSwitchIn(u8 partyId, u8 battlerIn1, u8 battlerIn2)
{
    u16 species = GetMonData(&gEnemyParty[partyId], MON_DATA_SPECIES_OR_EGG);

    return species != SPECIES_NONE
        && species != SPECIES_EGG
        && GetMonData(&gEnemyParty[partyId], MON_DATA_HP) != 0
        && partyId != gBattlerPartyIndexes[battlerIn1]
        && partyId != gBattlerPartyIndexes[battlerIn2]
        && partyId != *(gBattleStruct->monToSwitchIntoId + battlerIn1)
        && partyId != *(gBattleStruct->monToSwitchIntoId + battlerIn2);
}

// Fills in the battle data a party Pokemon would have just after being sent out.
static void GetPartyMonAsBattler(u8 partyId, struct BattlePokemon *dst)
{
    struct Pokemon *mon = &gEnemyParty[partyId];
    s32 i;

    CpuFill32(0, dst, sizeof(*dst));
    dst->species = GetMonData(mon, MON_DATA_SPECIES);
    dst->attack = GetMonData(mon, MON_DATA_ATK);
    dst->defense = GetMonData(mon, MON_DATA_DEF);
    dst->speed = GetMonData(mon, MON_DATA_SPEED);
    dst->spAttack = GetMonData(mon, MON_DATA_SPATK);
    dst->spDefense = GetMonData(mon, MON_DATA_SPDEF);
    dst->hp = GetMonData(mon, MON_DATA_HP);
    dst->maxHP = GetMonData(mon, MON_DATA_MAX_HP);
    dst->level = GetMonData(mon, MON_DATA_LEVEL);
    dst->item = GetMonData(mon, MON_DATA_HELD_ITEM);
    dst->status1 = GetMonData(mon, MON_DATA_STATUS);
    dst->ability = gSpeciesInfo[dst->species].abilities[GetMonData(mon, MON_DATA_ABILITY_NUM)];
    dst->type1 = gSpeciesInfo[dst->species].types[0];
    dst->type2 = gSpeciesInfo[dst->species].types[1];
    for (i = 0; i < NUM_BATTLE_STATS; ++i)
        dst->statStages[i] = DEFAULT_STAT_STAGE;
    for (i = 0; i < MAX_MON_MOVES; ++i)
    {
        dst->moves[i] = GetMonData(mon, MON_DATA_MOVE1 + i);
        dst->pp[i] = GetMonData(mon, MON_DATA_PP1 + i);
    }
}

// The most damage any of the attacker's moves would do to the defending battler.
static u32 GetBestMoveDamage(struct BattlePokemon *attacker, u8 defender)
{
    u32 bestDamage = 0;
    u32 damage;
    u16 sideStatus = gSideStatuses[GET_BATTLER_SIDE(defender)];
    u8 savedCritMultiplier = gCritMultiplier;
    u16 move;
    u8 moveType;
    u8 effectiveness;
    s32 i;

    gCritMultiplier = 1;
    for (i = 0; i < MAX_MON_MOVES; ++i)
    {
        move = attacker->moves[i];
        // Skip empty slots, used up moves, status moves, moves without a set
        // power, and moves that knock out the user.
        if (move == MOVE_NONE || attacker->pp[i] == 0 || gBattleMoves[move].power <= 1
         || gBattleMoves[move].effect == EFFECT_EXPLOSION)
            continue;

        moveType = gBattleMoves[move].type;
        effectiveness = 10;
        ModulateByTypeEffectiveness(moveType, gBattleMons[defender].type1, gBattleMons[defender].type2, &effectiveness);
        if (gBattleMons[defender].ability == ABILITY_LEVITATE && moveType == TYPE_GROUND)
            effectiveness = 0;
        if (gBattleMons[defender].ability == ABILITY_WONDER_GUARD && effectiveness <= 10)
            effectiveness = 0;
        if (effectiveness == 0)
            continue;

        damage = CalculateBaseDamage(attacker, &gBattleMons[defender], move, sideStatus, 0, 0, gActiveBattler, defender);
        if (moveType == attacker->type1 || moveType == attacker->type2)
            damage = damage * 15 / 10;
        damage = damage * effectiveness / 10;
        if (bestDamage < damage)
            bestDamage = damage;
    }
    gCritMultiplier = savedCritMultiplier;
    return bestDamage;
}

// Higher is better: how hard this Pokemon can hit the opponent, divided by how
// badly the opponent's types hit it.
static u32 ScoreSwitchInCandidate(u8 partyId, u8 opposingBattler)
{
    struct BattlePokemon candidate;
    u32 damage;
    u8 threat = 0;
    u8 effectiveness;
    u8 atkType;
    s32 i;

    GetPartyMonAsBattler(partyId, &candidate);

    damage = GetBestMoveDamage(&candidate, opposingBattler);
    // Anything past a knockout is no better than a knockout.
    if (damage > gBattleMons[opposingBattler].hp)
        damage = gBattleMons[opposingBattler].hp;

    for (i = 0; i < 2; ++i)
    {
        atkType = (i == 0) ? gBattleMons[opposingBattler].type1 : gBattleMons[opposingBattler].type2;
        effectiveness = 10;
        ModulateByTypeEffectiveness(atkType, candidate.type1, candidate.type2, &effectiveness);
        if (candidate.ability == ABILITY_LEVITATE && atkType == TYPE_GROUND)
            effectiveness = 0;
        if (threat < effectiveness)
            threat = effectiveness;
    }
    if (threat < 2) // immune
        threat = 2;

    return (damage + 1) * 40 / threat;
}

// Picks the Pokemon the opposing trainer sends out next. Returns PARTY_SIZE if
// there is none to send.
u8 GetMostSuitableMonToSwitchInto(void)
{
    u8 opposingBattler;
    u8 bestMonId;
    u8 aceId;
    u8 battlerIn1, battlerIn2;
    u32 score, bestScore;
    bool8 pickByMatchup;
    s32 i;

    if (*(gBattleStruct->monToSwitchIntoId + gActiveBattler) != PARTY_SIZE)
        return *(gBattleStruct->monToSwitchIntoId + gActiveBattler);
    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        battlerIn1 = gActiveBattler;
        if (gAbsentBattlerFlags & gBitTable[GetBattlerAtPosition(GetBattlerPosition(gActiveBattler) ^ BIT_FLANK)])
            battlerIn2 = gActiveBattler;
        else
            battlerIn2 = GetBattlerAtPosition(GetBattlerPosition(gActiveBattler) ^ BIT_FLANK);
        // UB: It considers the opponent only player's side even though it can battle alongside player.
        opposingBattler = Random() & BIT_FLANK;
        if (gAbsentBattlerFlags & gBitTable[opposingBattler])
            opposingBattler ^= BIT_FLANK;
    }
    else
    {
        opposingBattler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        battlerIn1 = gActiveBattler;
        battlerIn2 = gActiveBattler;
    }

    aceId = GetSavedAceId();
    // Simple trainers go in team order, as does anyone with nothing to match
    // up against because the opposing Pokemon has fainted.
    pickByMatchup = (GetOpponentAiLevel() != AI_LEVEL_SIMPLE && gBattleMons[opposingBattler].hp != 0);
    bestMonId = PARTY_SIZE;
    bestScore = 0;
    for (i = 0; i < PARTY_SIZE; ++i)
    {
        if (i == aceId || !CanSwitchIn(i, battlerIn1, battlerIn2))
            continue;
        if (!pickByMatchup)
            return i;
        score = ScoreSwitchInCandidate(i, opposingBattler);
        if (bestMonId == PARTY_SIZE || bestScore < score)
        {
            bestScore = score;
            bestMonId = i;
        }
    }
    // The saved Pokemon comes out once it is the only one left to send.
    if (bestMonId == PARTY_SIZE && aceId != PARTY_SIZE && CanSwitchIn(aceId, battlerIn1, battlerIn2))
        bestMonId = aceId;
    return bestMonId;
}

static u8 GetAI_ItemType(u8 itemId, const u8 *itemEffect) // NOTE: should take u16 as item Id argument
{
    if (itemId == ITEM_FULL_RESTORE)
        return AI_ITEM_FULL_RESTORE;
    else if (itemEffect[4] & ITEM4_HEAL_HP)
        return AI_ITEM_HEAL_HP;
    else if (itemEffect[3] & ITEM3_STATUS_ALL)
        return AI_ITEM_CURE_CONDITION;
    else if (itemEffect[0] & (ITEM0_DIRE_HIT | ITEM0_X_ATTACK) || itemEffect[1] != 0 || itemEffect[2] != 0)
        return AI_ITEM_X_STAT;
    else if (itemEffect[3] & ITEM3_GUARD_SPEC)
        return AI_ITEM_GUARD_SPECS;
    else
        return AI_ITEM_NOT_RECOGNIZABLE;
}

static bool8 ShouldUseItem(void)
{
    s32 i;
    u8 validMons = 0;
    bool8 shouldUse = FALSE;

    for (i = 0; i < PARTY_SIZE; ++i)
        if (GetMonData(&gEnemyParty[i], MON_DATA_HP) != 0
         && GetMonData(&gEnemyParty[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_NONE
         && GetMonData(&gEnemyParty[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG)
            ++validMons;
    for (i = 0; i < MAX_TRAINER_ITEMS; ++i)
    {
        u16 item;
        const u8 *itemEffects;
        u8 paramOffset;
        u8 battlerSide;

        if (i && validMons > (gBattleResources->battleHistory->itemsNo - i) + 1)
            continue;
        item = gBattleResources->battleHistory->trainerItems[i];
        if (item == ITEM_NONE || gItemEffectTable[item - ITEM_POTION] == NULL)
            continue;
        if (item == ITEM_ENIGMA_BERRY)
            itemEffects = gSaveBlock1Ptr->enigmaBerry.itemEffect;
        else
            itemEffects = gItemEffectTable[item - ITEM_POTION];
        *(gBattleStruct->AI_itemType + gActiveBattler / 2) = GetAI_ItemType(item, itemEffects);
        switch (*(gBattleStruct->AI_itemType + gActiveBattler / 2))
        {
        case AI_ITEM_FULL_RESTORE:
            if (gBattleMons[gActiveBattler].hp >= gBattleMons[gActiveBattler].maxHP / 4)
                break;
            if (gBattleMons[gActiveBattler].hp == 0)
                break;
            shouldUse = TRUE;
            break;
        case AI_ITEM_HEAL_HP:
            paramOffset = GetItemEffectParamOffset(item, 4, 4);
            if (paramOffset == 0 || gBattleMons[gActiveBattler].hp == 0)
                break;
            if (gBattleMons[gActiveBattler].hp < gBattleMons[gActiveBattler].maxHP / 4 || gBattleMons[gActiveBattler].maxHP - gBattleMons[gActiveBattler].hp > itemEffects[paramOffset])
                shouldUse = TRUE;
            break;
        case AI_ITEM_CURE_CONDITION:
            *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) = 0;
            if (itemEffects[3] & ITEM3_SLEEP && gBattleMons[gActiveBattler].status1 & STATUS1_SLEEP)
            {
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x20;
                shouldUse = TRUE;
            }
            if (itemEffects[3] & ITEM3_POISON && (gBattleMons[gActiveBattler].status1 & STATUS1_POISON || gBattleMons[gActiveBattler].status1 & STATUS1_TOXIC_POISON))
            {
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x10;
                shouldUse = TRUE;
            }
            if (itemEffects[3] & ITEM3_BURN && gBattleMons[gActiveBattler].status1 & STATUS1_BURN)
            {
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x8;
                shouldUse = TRUE;
            }
            if (itemEffects[3] & ITEM3_FREEZE && gBattleMons[gActiveBattler].status1 & STATUS1_FREEZE)
            {
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x4;
                shouldUse = TRUE;
            }
            if (itemEffects[3] & ITEM3_PARALYSIS && gBattleMons[gActiveBattler].status1 & STATUS1_PARALYSIS)
            {
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x2;
                shouldUse = TRUE;
            }
            if (itemEffects[3] & ITEM3_CONFUSION && gBattleMons[gActiveBattler].status2 & STATUS2_CONFUSION)
            {
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x1;
                shouldUse = TRUE;
            }
            break;
        case AI_ITEM_X_STAT:
            *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) = 0;
            if (!gDisableStructs[gActiveBattler].isFirstTurn)
                break;
            if (itemEffects[0] & ITEM0_X_ATTACK)
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x1;
            if (itemEffects[1] & ITEM1_X_DEFEND)
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x2;
            if (itemEffects[1] & ITEM1_X_SPEED)
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x4;
            if (itemEffects[2] & ITEM2_X_SPATK)
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x8;
            if (itemEffects[2] & ITEM2_X_ACCURACY)
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x20;
            if (itemEffects[0] & ITEM0_DIRE_HIT)
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x80;
            shouldUse = TRUE;
            break;
        case AI_ITEM_GUARD_SPECS:
            battlerSide = GetBattlerSide(gActiveBattler);
            if (gDisableStructs[gActiveBattler].isFirstTurn && gSideTimers[battlerSide].mistTimer == 0)
                shouldUse = TRUE;
            break;
        case AI_ITEM_NOT_RECOGNIZABLE:
            return FALSE;
        }
        if (shouldUse)
        {
            BtlController_EmitTwoReturnValues(1, B_ACTION_USE_ITEM, 0);
            *(gBattleStruct->chosenItem + (gActiveBattler / 2) * 2) = item;
            gBattleResources->battleHistory->trainerItems[i] = 0;
            return shouldUse;
        }
    }
    return FALSE;
}
