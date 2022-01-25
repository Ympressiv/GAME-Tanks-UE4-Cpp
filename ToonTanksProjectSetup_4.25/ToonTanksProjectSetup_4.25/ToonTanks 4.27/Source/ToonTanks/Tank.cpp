// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"

ATank::ATank()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm -> SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera -> SetupAttachment(SpringArm);

}

// Move Forward on WASD
void ATank::Move(float MoveForward_Value)
{
	DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
	DeltaLocation = FVector(0.0f, 0.0f, 0.0f);
	/* Zastepujemy X z DeltaLocation na wartosc wciskanego inputa i mnozymy przez DeltaTime
	bo sam input zalezy od FPS, wiec wyniesie sporo, lub ma³o jak spadn¹, a DeltaTime,
	jest zawsze ma³e, wiêc ograniczy nam t¹ szalon¹ wartoœæ. Dziêki temu dalej mno¿ymy razy speed, 
	by sobie przyspieszyæ postaæ*/
	DeltaLocation.X = MoveForward_Value * DeltaTime * Speed;
	AddActorLocalOffset(DeltaLocation);
}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::Move);
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
}
