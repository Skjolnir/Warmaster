// Copyright Bent Nürnberg

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WarmasterEnums.h"
#include "WMScoreSystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTeamWinsDelegate, ETeam, Team);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class WARMASTER_API UWMScoreSystem : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWMScoreSystem();

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
        FTeamWinsDelegate TeamWins;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
