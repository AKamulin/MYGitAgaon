// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTriggerBox.h"

AMyTriggerBox::AMyTriggerBox()
{
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("MAIN BOX"));
}

void AMyTriggerBox::BeginPlay()
{
	Super::BeginPlay();
}

void AMyTriggerBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMyTriggerBox::MyFunc()
{
	Box->GetScaledBoxExtent
}