// Copyright 2017 Bent Nürnberg. All Rights Reserved.

#include "BTC_UtilitySelector.h"
#include "BTD_UtilityCalculation.h"

UBTC_UtilitySelector::UBTC_UtilitySelector(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	NodeName = "Utility Selector";

	bUseNodeActivationNotify = true;

	OnNextChild.BindUObject(this, &UBTC_UtilitySelector::GetNextChildHandler);
}

void UBTC_UtilitySelector::InitializeMemory(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTMemoryInit::Type InitType) const
{
	FUtilityMemory* UtilityMemory = reinterpret_cast<FUtilityMemory*>(NodeMemory);
	if (InitType == EBTMemoryInit::Initialize)
	{
		new (&UtilityMemory->TaskSequence) FUtilityTaskSequence();
	}
}

uint16 UBTC_UtilitySelector::GetInstanceMemorySize() const
{
	return sizeof(FUtilityMemory);
}

void UBTC_UtilitySelector::NotifyNodeActivation(FBehaviorTreeSearchData& SearchData) const
{
	FUtilityMemory* NodeMemory = GetNodeMemory<FUtilityMemory>(SearchData);

	struct FUtilityValueWithIndex
	{
		int Index;
		float Value;

		inline bool operator < (FUtilityValueWithIndex const& Other) const
		{
			return Value > Other.Value;
		}
	};

	auto const Count = GetChildrenNum();
	TArray<FUtilityValueWithIndex> UtilityValuesWithIndex;
	UtilityValuesWithIndex.SetNumUninitialized(Count);

	for (int i = 0; i < Count; ++i)
	{
		auto const& Child = Children[i];
		for (auto Decorator : Child.Decorators)
		{
			auto UtilityCalculation = Cast<UBTD_UtilityCalculation>(Decorator);
			
			auto UtilityValue = UtilityCalculation ?
				UtilityCalculation->WrappedCalculateUtilityValue(SearchData.OwnerComp, UtilityCalculation->GetNodeMemory<uint8>(SearchData))
				: 0.0f;
			
			UtilityValuesWithIndex[i].Index = i;
			UtilityValuesWithIndex[i].Value = UtilityValue;
		}
	}

	UtilityValuesWithIndex.Sort();

	NodeMemory->TaskSequence.SetNumUninitialized(Count);

	for (int i = 0; i < Count; ++i)
	{
		NodeMemory->TaskSequence[i] = UtilityValuesWithIndex[i].Index;
	}
}

int32 UBTC_UtilitySelector::GetNextChildHandler(FBehaviorTreeSearchData& SearchData, int32 PrevChild, EBTNodeResult::Type LastResult) const
{
	FUtilityMemory* NodeMemory = GetNodeMemory<FUtilityMemory>(SearchData);

	// success = quit
	int NextChildIdx = BTSpecialChild::ReturnToParent;

	if (PrevChild == BTSpecialChild::NotInitialized)
	{
		// newly activated = start from first
		NextChildIdx = NodeMemory->TaskSequence[0];
	}
	else if (LastResult == EBTNodeResult::Failed)
	{
		int SequenceIdx = NodeMemory->TaskSequence.IndexOfByKey(PrevChild) + 1;
        if (SequenceIdx < NodeMemory->TaskSequence.Num())
        {
            // failed = choose next child
            NextChildIdx = NodeMemory->TaskSequence[SequenceIdx];
        }
	}

	return NextChildIdx;
}

#if WITH_EDITOR

FName UBTC_UtilitySelector::GetNodeIconName() const
{
	return FName("BTEditor.Graph.BTNode.Composite.Selector.Icon");
}

#endif
