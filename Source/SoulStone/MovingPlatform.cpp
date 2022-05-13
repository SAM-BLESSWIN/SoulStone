// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Display, TEXT("constructed moving platform"));
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	startpos = GetActorLocation();
	UE_LOG(LogTemp, Display, TEXT("Move Distance %f"), moveDistance);

}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);

	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float deltatime)
{
	FVector currentpos = GetActorLocation();

	if (ShouldPlatformReturn())
	{
		FVector moveDirection = movevelocity.GetSafeNormal();
		startpos = startpos + moveDirection * moveDistance;
		movevelocity = -movevelocity;
	}

	currentpos += movevelocity * deltatime;
	SetActorLocation(currentpos);
}

inline bool AMovingPlatform::ShouldPlatformReturn() const
{
	return FVector::Distance(startpos, GetActorLocation()) > moveDistance;
}

void AMovingPlatform::RotatePlatform(float deltatime)
{
	FRotator currentrot = GetActorRotation();
	currentrot += rotatevelocity * deltatime;
	SetActorRotation(currentrot);
}

