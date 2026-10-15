// Fill out your copyright notice in the Description page of Project Settings.


#include "SocialCharacter.h"

// Sets default values
ASocialCharacter::ASocialCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASocialCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASocialCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASocialCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// 1. The Local Math Function
// The player's computer runs this to calculate the angle and force of their push
void ASocialCharacter::CalculateInteractionMath()
{
    // Get the exact 3D vector direction the player's character is currently facing
    FVector ForwardDirection = GetActorForwardVector();

    // 3D Vector Math: Multiply that direction by 500 to simulate physical pushing force
    CalculatedPushForce = ForwardDirection * 500.0f;

    // Send this calculated math packet over the network to the server
    Server_ApplyInteraction(CalculatedPushForce);
}

// 2. The Server RPC (Remote Procedure Call)
// This code ONLY runs on the multiplayer server to prevent cheating
void ASocialCharacter::Server_ApplyInteraction_Implementation(FVector PushedForce)
{
    // If the server receives the math successfully, it prints a green message to the screen.
    // In a full game, this is where you would apply the PushedForce to a shared physical object like a door.
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Server Authenticated Push Math: %s"), *PushedForce.ToString()));
    }
}