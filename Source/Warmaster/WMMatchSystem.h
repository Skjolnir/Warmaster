// Copyright Bent Nürnberg

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WMMatchSystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FStartMatchDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEndMatchDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSetupNextTest);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class WARMASTER_API UWMMatchSystem : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWMMatchSystem();

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FStartMatchDelegate StartMatch;

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FEndMatchDelegate EndMatch;

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FSetupNextTest SetupNextTest;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
