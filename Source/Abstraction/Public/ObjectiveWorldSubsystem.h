// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Subsystems/WorldSubsystem.h"
#include "Blueprint/UserWidget.h"
#include "ObjectiveComponent.h"
#include "ObjectiveWorldSubsystem.generated.h"

class UObjectiveComponent;
class UObjectivesHud;
class UUserWidget;

UCLASS()
class ABSTRACTION_API UObjectiveWorldSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintCallable)
	FString GetCurrentObjectiveDescription();
	
	UFUNCTION(BlueprintCallable)
	void AddObjective(UObjectiveComponent* ObjectiveComponent);

	UFUNCTION(BlueprintCallable)
	void RemoveObjective(UObjectiveComponent* ObjectiveComponent);

	UFUNCTION(BlueprintCallable)
	void OnMapStart();

	void CreateObjectiveWidgets();

protected:
	virtual void Deinitialize() override;

	void DisplayObjectiveWidget();
	void RemoveObjectiveWidget();
	
	void DisplayObjectivesCompleteWidget();
	void RemoveObjectivesCompleteWidget();

	uint32 GetCompletedObjectiveCount();

	void OnObjectiveStateChanged(UObjectiveComponent* ObjectiveComponent, EObjectiveState ObjectiveState);
private:
	//UUserWidget* ObjectiveWidget = nullptr;
	UObjectivesHud* ObjectiveWidget = nullptr;
	UUserWidget* ObjectivesCompleteWidget = nullptr;

	//add remove them
	//sign up for callbakc onchanged
	TArray<UObjectiveComponent*> Objectives;
};
