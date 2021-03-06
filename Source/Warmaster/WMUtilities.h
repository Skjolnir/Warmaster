// Copyright Bent Nürnberg

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "WMUtilities.generated.h"

/**
 * 
 */
UCLASS()
class WARMASTER_API UWMUtilities : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

    UFUNCTION(BlueprintCallable, Category = "Save")
    static void FileSaveStringArray(const TArray<FString> &Lines, FString FileName);
};
