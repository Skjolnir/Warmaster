// Copyright Bent Nürnberg

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WMDamageSystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAttackTargetDelegate, AActor*, Actor, AActor*, Target);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class WARMASTER_API UWMDamageSystem : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWMDamageSystem();

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FAttackTargetDelegate AttackTarget;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
