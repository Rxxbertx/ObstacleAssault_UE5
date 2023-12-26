// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovablePlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovablePlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovablePlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	//METHODS
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//move platform
	void MovePlatform(float DeltaTime);
	//rotate platform
	void RotatePlatform(float DeltaTime);

	bool ShouldPlatformReturn() const;

	float GetDistanceMoved() const;

	//VARS
	UPROPERTY(EditAnywhere)
	int32 MaxDistance = 100;

	UPROPERTY(EditAnywhere, Category="Moving Platform")
	FVector LocationVelocity = FVector(100, 0, 0);

	UPROPERTY(EditAnywhere, Category="Moving Platform")
	FRotator RotationVelocity = FRotator(0, 0, 0);
	
	FVector StartLocation;
};
