// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/HitInterface.h"
#include "Enemy.generated.h"

class UAnimMontage;
class UNiagaraSystem;

UCLASS()
class SLASH_UDEMYRPG_API AEnemy : public ACharacter, public IHitInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void GetHit_Implementation(const FVector& ImpactPoint) override;

	void DirectionalHitReact(const FVector& ImpactPoint);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//
	//Play Montage Functions
	//
	void PlayHitReactMontage(const FName& SelectionName);

	//
	//VFX
	//
	UPROPERTY(EditAnywhere, Category = VisualEffects)
	UParticleSystem* HitParticles;

	UPROPERTY(EditAnywhere, Category = VisualEffects)
	UNiagaraSystem* NiagaraHitParticles;

private:
	//
	//Animation Montages
	//
	UPROPERTY(EditDefaultsOnly, Category = Montages)
	UAnimMontage* HitReactMontage;

	//
	//SFX
	//
	UPROPERTY(EditAnywhere, Category = Sounds)
	USoundBase* HitSound;

public:	

};
