// Copyright Bent Nürnberg

#pragma once

//#include "CoreMinimal.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EAiState : uint8
{
    AS_Undefined    UMETA(DisplayName = "Undefined"),
    AS_Attack       UMETA(DisplayName = "Attack"),
    AS_Flee         UMETA(DisplayName = "Flee"),
    AS_Defend       UMETA(DisplayName = "Defend"),
    AS_Roam         UMETA(DisplayName = "Roam")
};

UENUM(BlueprintType)
enum class ETeam : uint8
{
    T_NormalBlue    UMETA(DisplayName="Normal / Blue"),
    T_ExtendedRed   UMETA(DisplayName="Extended / Red")
};

UENUM(BlueprintType)
enum class ETargetingType : uint8
{
    TT_Distance    UMETA(DisplayName = "Distance"),
    TT_Utility     UMETA(DisplayName = "Utility"),
    TT_Health      UMETA(DisplayName = "Health"),
    TT_DPS         UMETA(DisplayName = "DPS")
};
