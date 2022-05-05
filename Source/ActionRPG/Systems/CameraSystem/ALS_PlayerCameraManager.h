
#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "Kismet/KismetSystemLibrary.h"
#include "ALS_PlayerCameraManager.generated.h"


UCLASS()
class ACTIONRPG_API AALS_PlayerCameraManager : public APlayerCameraManager
{
	GENERATED_BODY()

public:
	AALS_PlayerCameraManager();

	UFUNCTION(BlueprintCallable,Category="PlayerCameraManager Event")
	void OnPossess(APawn* NewPawn);

	/**커스텀 카메라비헤이비어*/
	UFUNCTION(BlueprintCallable , Category="PlayerCameraManager Event")
	void CustomCameraBehavior(FVector& OutLocation,FRotator& OutRotation,float& OutFov);

	/**축 독립 지연 계산*/
	UFUNCTION(BlueprintPure,Category="PlayerCameraManager Event")
	FVector CalculateAxisIndependentLag(FVector InCurrentLocation,FVector InTargetLocation,FRotator InCameraRotation,FVector InLagSpeeds);

	/**현재 카메라 애님 인스턴스의 커브 값을 가져옵니다*/
	UFUNCTION(BlueprintPure,Category="PlayerCameraManager Event")
	float GetCameraBehaviorParam(FName CurveName);

	/**디버그 트레이스 타입을 가져옵니다*/
	UFUNCTION(BlueprintPure,Category="PlayerCameraManager Event")
	TEnumAsByte<EDrawDebugTrace::Type> GetDebugTraceType(TEnumAsByte<EDrawDebugTrace::Type> InShowTraceType);

#pragma region               Default Members
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Default Members")
	USkeletalMeshComponent* CameraBehavior;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Default Members")
	APawn* ControlledPawn;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Default Members")
	FVector DebugViewOffset;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Default Members")
	FRotator DebugViewRotation;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Default Members")
	FVector RootLocation;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Default Members")
	FTransform SmoothedPivotTarget;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Default Members")
	FVector PivotLocation;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Default Members")
	FVector TargetCameraLocation;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Default Members")
	FRotator TargetCameraRotation;
	
#pragma endregion            Default Members
};
