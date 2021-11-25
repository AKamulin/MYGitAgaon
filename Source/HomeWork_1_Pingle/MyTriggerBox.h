// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Components/BoxComponent.h"
#include "MyTriggerBox.generated.h"


/**
 * 
 */
UCLASS()
class HOMEWORK_1_PINGLE_API AMyTriggerBox : public ATriggerBox
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;
	AMyTriggerBox();
	void MyFunc();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UBoxComponent* Box;
	
};
