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
	
protected:
	virtual void BeginPlay() override;

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
	void LookUpAtRate(float Rate);

	// ����
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

	// ��ȣ�ۿ�
private:
	UPROPERTY(VisibleAnywhere)
		class USphereComponent* collision;
public:
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
