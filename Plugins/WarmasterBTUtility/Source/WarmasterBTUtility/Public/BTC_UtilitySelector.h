// Copyright 2017 Bent Nürnberg. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTCompositeNode.h"
#include "BTC_UtilitySelector.generated.h"

typedef TArray<uint8, TFixedAllocator<16>> FUtilityTaskSequence;

struct FUtilityMemory : public FBTCompositeMemory
{
	FUtilityTaskSequence TaskSequence;
};

class UBTD_UtilityCalculation;

/**
* Utility Selector composite node.
* Utility Selector Nodes execute their children based on calculated utility values, and will stop executing its children when one of their children succeeds.
* If a Utility Selector's child succeeds, the Utility Selector succeeds. If all the Utility Selector's children fail, the Utility Selector fails.
*/
UCLASS()
class WARMASTERBTUTILITY_API UBTC_UtilitySelector : public UBTCompositeNode
{
	GENERATED_UCLASS_BODY()

protected:
	virtual void NotifyNodeActivation(FBehaviorTreeSearchData& SearchData) const override;

public:
	int32 GetNextChildHandler(struct FBehaviorTreeSearchData& SearchData, int32 PrevChild, EBTNodeResult::Type LastResult) const;

	virtual void InitializeMemory(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTMemoryInit::Type InitType) const override;
	virtual uint16 GetInstanceMemorySize() const override;

#if WITH_EDITOR
	virtual FName GetNodeIconName() const override;
#endif
};
