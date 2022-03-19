#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MODCharacter.generated.h"

UCLASS(config = Game)
class AMODCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMODCharacter();
	
	// 카메라
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;

public:
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	// 조작
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

	UPROPERTY(EditAnywhere, Category = "Character Movement: Walking")
		float SprintRate;

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void TurnAtRate(float Rate);
	
	void Sprint();
	void StopSprinting();

	void Interaction();

	// 상호작용
private:
	UPROPERTY(VisibleAnywhere)
	TArray<class UInteractionTriggerComponent*> interactions;

public:
	void AddInteraction(UInteractionTriggerComponent* trigger);
	void RemoveInteraction(UInteractionTriggerComponent* trigger);
};
