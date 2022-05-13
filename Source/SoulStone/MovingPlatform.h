// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class SOULSTONE_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnyWhere, Category = "Movement")
	FVector movevelocity = FVector(500, 0, 0);

	UPROPERTY(EditAnyWhere, Category = "Movement")
	float moveDistance = 100;

	UPROPERTY(EditAnyWhere, Category = "Rotation")
	FRotator rotatevelocity = FRotator(0, 0, 0);

private:
	FVector startpos;

private:
	void MovePlatform(float deltatime);
	void RotatePlatform(float deltatime);
	inline bool ShouldPlatformReturn() const;
};
