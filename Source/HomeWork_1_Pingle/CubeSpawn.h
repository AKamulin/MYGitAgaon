// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "CubeSpawn.generated.h"

USTRUCT(BlueprintType)
struct FGeometryData
{
	GENERATED_USTRUCT_BODY()
	
};


UCLASS()
class HOMEWORK_1_PINGLE_API ACubeSpawn : public AActor
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	ACubeSpawn();
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ACubeSpawn> BaseObj;
	UPROPERTY(EditAnywhere, Category = "OPTIONS")
	int32 MINCOUNT = 0;
	int32 MAXCOUNT = 100;
	UPROPERTY(EditAnywhere, Category = "OPTIONS" )
	int32 SphereCount = 1;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	
	TArray<float> SpawnArrayX;
	TArray<float> SpawnArrayY;
	void AddVectorParams();
	int32 RandomGeneratorX();
	int32 RandomGeneratorY();
	const FTransform InitializerOfVector() ;
};


