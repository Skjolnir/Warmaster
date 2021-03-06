// Copyright Bent Nürnberg

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WMUnitSystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSpawnActorsDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDespawnActorsDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSpawnActorDelegate, AActor*, Actor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FActorSpawnedDelegate, AActor*, Actor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDespawnActorDelegate, AActor*, Actor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FActorDespawnedDelegate, AActor*, Actor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FRespawnActorDelegate, AActor*, Actor, float, SpawnDelay);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FKillActorDelegate, AActor*, Actor, AActor*, Killer);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FActorKilledDelegate, AActor*, Actor, AActor*, Killer);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class WARMASTER_API UWMUnitSystem : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWMUnitSystem();

    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Unit System")
    FSpawnActorsDelegate SpawnActors;

    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Unit System")
    FDespawnActorsDelegate DespawnActors;

    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Unit System")
    FSpawnActorDelegate SpawnActor;

    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Unit System")
    FActorSpawnedDelegate ActorSpawned;

    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Unit System")
    FDespawnActorDelegate DespawnActor;

    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Unit System")
    FActorDespawnedDelegate ActorDespawned;

    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Unit System")
    FRespawnActorDelegate RespawnActor;

    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Unit System")
    FKillActorDelegate KillActor;

    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Unit System")
    FActorKilledDelegate ActorKilled;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
