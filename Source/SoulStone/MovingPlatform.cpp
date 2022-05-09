// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	startpos = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector currentpos = GetActorLocation();
	currentpos += velocity * DeltaTime;
	float distanceMoved = FVector::Distance(startpos,currentpos);

	if (distanceMoved > moveDistance)
	{
		startpos = currentpos;
		velocity = -velocity;
	}

	SetActorLocation(currentpos);
}

