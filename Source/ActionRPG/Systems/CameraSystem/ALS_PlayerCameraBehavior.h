#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Datas/ALS_Data.h"
#include "ALS_PlayerCameraBehavior.generated.h"

UCLASS()
class ACTIONRPG_API UALS_PlayerCameraBehavior : public UAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	void UpdateCharacterInfo();

#pragma region               References Members
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="References")
	APlayerController* PlayerController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="References")
	APawn* ControlledPawn;
#pragma endregion            References Members


#pragma region               Character Info Members
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Info")
	EALSMovementState MovementState;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Info")
	EALSMovementAction MovementAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Info")
	EALSRotationMode RotationMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Info")
	EALSGait Gait;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Info")
	EALSStance Stance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Info")
	EALSViewMode ViewMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Info")
	bool bRightShoulder;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Info")
	bool bDebugView;
#pragma endregion            Character Info Members
	
};


