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
	
	// ī�޶�
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;

public:
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	// ����
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void TurnAtRate(float Rate);

	void Interaction();

	// ��ȣ�ۿ�
private:
	UPROPERTY(VisibleAnywhere)
		class USphereComponent* collision;

	bool canInteraction = false;

public:
	void SetCanInteraction(bool canInter);
};
