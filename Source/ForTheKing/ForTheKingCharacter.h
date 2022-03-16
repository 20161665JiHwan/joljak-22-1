#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterStatus.h"
#include "ForTheKingCharacter.generated.h"

UCLASS(config = Game)
class AForTheKingCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AForTheKingCharacter();
	
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

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void TurnAtRate(float Rate);

	void Interaction();

	// 스탯
private:
	UPROPERTY(EditAnywhere, Category = Player, meta = (AllowPrivateAccess = "true"))
		struct FCharacterStatus status;
	UPROPERTY(EditAnywhere, Category = Player, meta = (AllowPrivateAccess = "true"))
		int CurHealth;
	UPROPERTY(EditAnywhere, Category = Player, meta = (AllowPrivateAccess = "true"))
		int MaxHealth;
	UPROPERTY(EditAnywhere, Category = Player, meta = (AllowPrivateAccess = "true"))
		int CurExp;
	UPROPERTY(EditAnywhere, Category = Player, meta = (AllowPrivateAccess = "true"))
		int MaxExp;
	UPROPERTY(EditAnywhere, Category = Player, meta = (AllowPrivateAccess = "true"))
		int SkillPoint;

	// 상호작용
private:
	UPROPERTY(VisibleAnywhere)
		class USphereComponent* collision;

	bool canInteract = false;

public:
};
