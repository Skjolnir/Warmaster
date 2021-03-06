// Copyright 2017 Bent Nürnberg. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTD_UtilityCalculation.generated.h"

/**
* 
*/
UCLASS(Abstract)
class WARMASTERBTUTILITY_API UBTD_UtilityCalculation : public UBTDecorator
{
	GENERATED_BODY()
	
public:
	UBTD_UtilityCalculation(const FObjectInitializer& ObjectInitializer);

	float WrappedCalculateUtilityValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const;

protected:
	virtual float CalculateUtilityValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const;
};
