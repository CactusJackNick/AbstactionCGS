// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectivesHud.h"
#include "Components/TextBlock.h"

void UObjectivesHud::UpdateObjectiveText(uint32 ObjectivesCompleted, uint32 TotalObjectives)
{
	if (ObjectivesText)
	{
		ObjectivesText->SetText(FText::Format(FTextFormat::FromString("{0} / {1}"), ObjectivesCompleted, TotalObjectives));
	}
}

