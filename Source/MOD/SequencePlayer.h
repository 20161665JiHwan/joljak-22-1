#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SequencePlayer.generated.h"

UCLASS()
class MANSIONOFDARKNESS_API ASequencePlayer : public ACharacter
{
	GENERATED_BODY()

public:
	ASequencePlayer();
	virtual void Destroyed() override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* Mesh1P;

public:
	UPROPERTY(BlueprintReadWrite, Category = Flash)
		bool startWithFlash = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Flash)
		TSubclassOf<class AActor> flashBP;
	UPROPERTY(BlueprintReadOnly, Category = Flash)
		AActor* flash;

	UFUNCTION(BlueprintCallable)
		USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }

	// Ä«¸Þ¶ó
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* CameraComponent;
public:
	FORCEINLINE class UCameraComponent* GetCameraComponent() const { return CameraComponent; }

};
