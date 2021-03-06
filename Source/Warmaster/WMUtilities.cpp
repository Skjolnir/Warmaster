// Copyright Bent Nürnberg

#include "WMUtilities.h"
#include "Runtime/Core/Public/Misc/FileHelper.h"
#include "Runtime/Core/Public/Misc/Paths.h"

void UWMUtilities::FileSaveStringArray(const TArray<FString> &Lines, FString FileName)
{
    FFileHelper::SaveStringArrayToFile(Lines, *(FPaths::ProjectDir() + FileName));
}


