// Fill out your copyright notice in the Description page of Project Settings.


#include "MovablePlatform.h"

// Sets default values


AMovablePlatform::AMovablePlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}


// Called when the game starts or when spawned
void AMovablePlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}

// Called every frame
void AMovablePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovablePlatform::RotatePlatform(float DeltaTime)
{
	AddActorLocalRotation(RotationVelocity * DeltaTime);
}

void AMovablePlatform::MovePlatform(float DeltaTime)
{
	if (ShouldPlatformReturn())
	{
		StartLocation += LocationVelocity.GetSafeNormal() * MaxDistance; //set start location to max distance
		SetActorLocation(StartLocation); //set actor location to start location
		LocationVelocity *= -1; //reverse velocity
	}
	else
	{
		//get actor location
		FVector ActorLocation = GetActorLocation();
		//modify actor location
		ActorLocation += LocationVelocity * DeltaTime;
		//set actor location
		SetActorLocation(ActorLocation);
	}
}

bool AMovablePlatform::ShouldPlatformReturn() const
{
	//check if distance is greater than max distance
	return GetDistanceMoved() > MaxDistance;
}

float AMovablePlatform::GetDistanceMoved() const
{
	return FVector::Dist(StartLocation, GetActorLocation());
}
