// Copyright 2017 Bent Nürnberg. All Rights Reserved.

#include "BTD_UtilityCalculation.h"

UBTD_UtilityCalculation::UBTD_UtilityCalculation(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	NodeName = "Utility Calculation";

	bAllowAbortNone = false;
	bAllowAbortLowerPri = false;
	bAllowAbortChildNodes = false;
}

float UBTD_UtilityCalculation::WrappedCalculateUtilityValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	const UBTD_UtilityCalculation* Node = bCreateNodeInstance ? (const UBTD_UtilityCalculation*)GetNodeInstance(OwnerComp, NodeMemory) : this;
	return Node ? Node->CalculateUtilityValue(OwnerComp, NodeMemory) : 0.0f;
}

float UBTD_UtilityCalculation::CalculateUtilityValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	return 0.0f;
}
