// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SocialCharacter.generated.h"

UCLASS()
class SOCIALSANDBOX_API ASocialCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASocialCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    // 1. The 3D Vector Math Variable
    // This stores the direction and force the player is applying to an object
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EA Prototype | Math")
    FVector CalculatedPushForce;

    // 2. The Local Function
    // This is where the client uses dot products to calculate their pushing angle
    UFUNCTION(BlueprintCallable, Category = "EA Prototype | Math")
    void CalculateInteractionMath();

    // 3. The Server RPC (Remote Procedure Call)
    // The "Server" tag means the player asks the server to execute this, preventing cheating.
    // The "Reliable" tag ensures the data packet is never dropped over the network.
    UFUNCTION(Server, Reliable)
    void Server_ApplyInteraction(FVector PushedForce);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
