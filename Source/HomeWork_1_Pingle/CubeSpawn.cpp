// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeSpawn.h"

// Sets default values
ACubeSpawn::ACubeSpawn()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Base Mesh");
}

// Called when the game starts or when spawned
void ACubeSpawn::BeginPlay()
{
	Super::BeginPlay();
	UWorld* World = GetWorld();
	AddVectorParams();
	for (int32 i = MINCOUNT; i < SphereCount; ++i) 
	{
		const FTransform GeometryTransform = InitializerOfVector();
		ACubeSpawn* SpawnObj = World->SpawnActor<ACubeSpawn>(BaseObj, GeometryTransform);
	}
}

// Called every frame
void ACubeSpawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACubeSpawn::AddVectorParams()
{
	int32 i = MINCOUNT;
	float VectorX = 1300.0f;
	float VectorY = 1050.0f;
	while (i <= MAXCOUNT)
	{
		VectorX -= 120;
		VectorY -= 120;
		SpawnArrayX.Add(VectorX);
		SpawnArrayY.Add(VectorY);
		++i;
	}
}


int32 ACubeSpawn::RandomGeneratorX()
{
	int32 RandomIndex = FMath::FRandRange(MINCOUNT, MAXCOUNT);
	float VectorX = SpawnArrayX[RandomIndex];
	SpawnArrayX[RandomIndex] = 0.0f;
	SpawnArrayX.Sort();
	
	return VectorX;
}

int32 ACubeSpawn::RandomGeneratorY()
{
	int32 RandomIndex = FMath::FRandRange(MINCOUNT, MAXCOUNT);
	float VectorY = SpawnArrayX[RandomIndex];
	SpawnArrayY[RandomIndex] = 0.0f;
	SpawnArrayY.Sort();
	//MINCOUNT += 1;
	return VectorY;
}

const FTransform ACubeSpawn::InitializerOfVector() 
{
	FTransform Geometry = FTransform(FRotator::ZeroRotator, FVector(RandomGeneratorX(), RandomGeneratorY(), 240.0f));
	MINCOUNT += 1;
	return Geometry;
}



