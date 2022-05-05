#include "ALS_PlayerCameraManager.h"

#include "Global.h"
#include "ALS_PlayerCameraBehavior.h"
#include "GlobalFunctions/CLog.h"
#include "Interfaces/ALS_Camera_Interface.h"
#include "Interfaces/ALS_Controller_Interface.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"


AALS_PlayerCameraManager::AALS_PlayerCameraManager()
{
	CameraBehavior = CreateDefaultSubobject<USkeletalMeshComponent>("CameraBehavior");
	CameraBehavior->SetHiddenInGame(true);

	DebugViewOffset = FVector(350.0f, 0.0f, 50.0f);
	DebugViewRotation = FRotator(-5.0f, 180.0f, 0.0f);
}

void AALS_PlayerCameraManager::OnPossess(APawn* NewPawn)
{
	//플레이어 컨트롤러가 새 캐릭터를 소유할 때 "제어된 폰"을 설정하십시오. (플레이어 컨트롤러에서 호출)
	ControlledPawn = NewPawn;

	UALS_PlayerCameraBehavior* PlayerCameraBehavior = Cast<UALS_PlayerCameraBehavior>(CameraBehavior->GetAnimInstance());
	CHECK(PlayerCameraBehavior!=nullptr);
	PlayerCameraBehavior->PlayerController = GetOwningPlayerController();
	PlayerCameraBehavior->ControlledPawn = ControlledPawn;
}

void AALS_PlayerCameraManager::CustomCameraBehavior(FVector& OutLocation, FRotator& OutRotation, float& OutFov)
{
	//1단계: 카메라 인터페이스를 통해 CharacterBP에서 카메라 매개변수 가져오기
	IALS_Camera_Interface* Cast_ALS_Camera_Interface = Cast<IALS_Camera_Interface>(ControlledPawn);
	CHECK(Cast_ALS_Camera_Interface!=nullptr);

	FTransform L_PivotTarget = Cast_ALS_Camera_Interface->I_Get3P_PivotTarget();
	FVector L_FPTarget = Cast_ALS_Camera_Interface->I_GetFP_CameraTarget();

	float L_TP_Fov;
	float L_FP_Fov;
	bool L_RightShoulder;
	Cast_ALS_Camera_Interface->I_GetCameraParameters(L_TP_Fov, L_FP_Fov, L_RightShoulder);


	//2단계: 대상 카메라 회전을 계산합니다. 제어 회전을 사용하고 부드러운 카메라 회전을 위해 보간합니다.
	{
		const float L_DeltaSeconds = UGameplayStatics::GetWorldDeltaSeconds(this);
		FRotator L_InterpControlRotation = UKismetMathLibrary::RInterpTo(GetCameraRotation(), GetOwningPlayerController()->GetControlRotation(),
		                                                                 L_DeltaSeconds, GetCameraBehaviorParam(FName(TEXT("RotationLagSpeed"))));

		TargetCameraRotation = UKismetMathLibrary::RLerp(L_InterpControlRotation, DebugViewRotation,
		                                                 GetCameraBehaviorParam(FName(TEXT("Override_Debug"))), true);
	}


	//3단계: 평활화된 피벗 목표(주황색 구)를 계산합니다. 3P 피벗 타겟(녹색 구)을 얻고 최대 제어를 위해 축 독립 지연을 사용하여 보간합니다.
	{
		FVector L_LagSpeeds = FVector(GetCameraBehaviorParam(FName("PivotLagSpeed_X")),
		                              GetCameraBehaviorParam(FName("PivotLagSpeed_Y")),
		                              GetCameraBehaviorParam(FName("PivotLagSpeed_Z")));

		const FVector L_SmoothedPivotLocation = CalculateAxisIndependentLag(SmoothedPivotTarget.GetLocation(), L_PivotTarget.GetLocation(),
		                                                                    TargetCameraRotation, L_LagSpeeds);
		SmoothedPivotTarget = FTransform(L_PivotTarget.GetRotation(), L_SmoothedPivotLocation);
	}


	//4단계: 피벗 위치 계산(BlueSphere). Smoothed Pivot Target을 가져오고 추가 카메라 제어를 위해 로컬 오프셋을 적용합니다.
	{
		PivotLocation = SmoothedPivotTarget.GetLocation() +
			UKismetMathLibrary::GetForwardVector(SmoothedPivotTarget.GetRotation().Rotator()) * GetCameraBehaviorParam(FName("PivotOffset_X")) +
			UKismetMathLibrary::GetRightVector(SmoothedPivotTarget.GetRotation().Rotator()) * GetCameraBehaviorParam(FName("PivotOffset_Y")) +
			UKismetMathLibrary::GetUpVector(SmoothedPivotTarget.GetRotation().Rotator()) * GetCameraBehaviorParam(FName("PivotOffset_Z"));
	}


	//5단계: 대상 카메라 위치를 계산합니다. 피벗 위치를 가져오고 카메라 상대 오프셋을 적용합니다.
	{
		FVector L_LerpVectorA = PivotLocation +
			UKismetMathLibrary::GetForwardVector(TargetCameraRotation) * GetCameraBehaviorParam(FName("CameraOffset_X")) +
			UKismetMathLibrary::GetRightVector(TargetCameraRotation) * GetCameraBehaviorParam(FName("CameraOffset_Y")) +
			UKismetMathLibrary::GetUpVector(TargetCameraRotation) * GetCameraBehaviorParam(FName("CameraOffset_Z"));

		FVector L_LerpVectorB = L_PivotTarget.GetLocation() + DebugViewOffset;
		TargetCameraLocation = UKismetMathLibrary::VLerp(L_LerpVectorA, L_LerpVectorB, GetCameraBehaviorParam(TEXT("Override_Debug")));
	}


	//6단계: 보정 오프셋을 적용하기 위해 카메라와 캐릭터 사이의 개체를 추적합니다. 추적 원점은 카메라 인터페이스를 통해 캐릭터 BP 내에서 설정됩니다.
	//일반 스프링 암과 같은 기능을 하지만 피벗에 관계없이 다른 추적 원점을 허용할 수 있습니다.
	{
		FVector TraceOrigin;
		float TraceRadius;
		TEnumAsByte<ETraceTypeQuery> TraceChannel;
		Cast_ALS_Camera_Interface->I_Get3P_TraceParams(TraceOrigin, TraceRadius, TraceChannel);
		TArray<AActor*> ActorToIgnores;
		FHitResult SphereTraceHitResult;
		UKismetSystemLibrary::SphereTraceSingle(this, TraceOrigin, TargetCameraLocation, TraceRadius, TraceChannel, false, ActorToIgnores,
		                                        GetDebugTraceType(EDrawDebugTrace::ForOneFrame), SphereTraceHitResult, true);

		if (SphereTraceHitResult.bBlockingHit && !SphereTraceHitResult.bStartPenetrating)
		{
			FVector TraceDir = SphereTraceHitResult.Location - SphereTraceHitResult.TraceEnd;
			TargetCameraLocation = TraceDir + TargetCameraLocation;
		}
	}

	//7단계: 디버그 모양을 그립니다.
	{
		IALS_Controller_Interface* Cast_ALS_Controller_Interface = Cast<IALS_Controller_Interface>(GetOwningPlayerController());
		CHECK(Cast_ALS_Controller_Interface!=nullptr);
		FALS_DebugInfo DebugInfo = Cast_ALS_Controller_Interface->I_GetDebugInfo();

		if (DebugInfo.bShowDebugShapes)
		{
			UKismetSystemLibrary::DrawDebugSphere(this, L_PivotTarget.GetLocation(), 16.0f, 8,
			                                      FLinearColor::Green, 0.0f, 0.5f);
			UKismetSystemLibrary::DrawDebugSphere(this, SmoothedPivotTarget.GetLocation(), 16.0f, 8,
			                                      COLOR_ORANGE, 0.0f, 0.5f);
			UKismetSystemLibrary::DrawDebugSphere(this, PivotLocation, 16.0f, 8,
			                                      COLOR_SKY, 0.0f, 0.5f);
			UKismetSystemLibrary::DrawDebugLine(this, SmoothedPivotTarget.GetLocation(), L_PivotTarget.GetLocation(),
			                                    COLOR_ORANGE, 0.0f, 1.0f);
			UKismetSystemLibrary::DrawDebugLine(this, PivotLocation, SmoothedPivotTarget.GetLocation(),
			                                    COLOR_SKY, 0.0f, 1.0f);
		}
	}

	//8단계: Lerp 1인칭 대상 카메라 매개변수를 재정의하고 반환합니다.
	FTransform L_TargetTransform = FTransform(TargetCameraRotation, TargetCameraLocation);
	FTransform L_FP_TargetTransform = FTransform(TargetCameraRotation, L_FPTarget);

	FTransform L_CameraTransform = UKismetMathLibrary::TLerp(L_TargetTransform, L_FP_TargetTransform,
	                                                       GetCameraBehaviorParam(TEXT("Weight_FirstPerson")));

	FTransform L_DebugTransform = FTransform(DebugViewRotation, TargetCameraLocation);
	FTransform L_LerpTransform = UKismetMathLibrary::TLerp(L_CameraTransform, L_DebugTransform, GetCameraBehaviorParam(TEXT("Override_Debug")));

	OutLocation = L_LerpTransform.GetLocation();
	OutRotation = L_LerpTransform.GetRotation().Rotator();
	OutFov = UKismetMathLibrary::Lerp(L_TP_Fov, L_FP_Fov, GetCameraBehaviorParam(TEXT("Weight_FirstPerson")));
}

FVector AALS_PlayerCameraManager::CalculateAxisIndependentLag(FVector InCurrentLocation, FVector InTargetLocation, FRotator InCameraRotation,
                                                              FVector InLagSpeeds)
{
	const FRotator L_CameraRotationYaw = FRotator(0.0f, InCameraRotation.Yaw, 0.0f);

	const float DeltaSeconds = UGameplayStatics::GetWorldDeltaSeconds(this);
	FVector UnRotate_CurrentLocation = UKismetMathLibrary::LessLess_VectorRotator(InCurrentLocation, L_CameraRotationYaw);
	FVector UnRotate_TargetLocation = UKismetMathLibrary::LessLess_VectorRotator(InTargetLocation, L_CameraRotationYaw);

	FVector UnRotateVector = FVector(
		UKismetMathLibrary::FInterpTo(UnRotate_CurrentLocation.X, UnRotate_TargetLocation.X, DeltaSeconds, InLagSpeeds.X),
		UKismetMathLibrary::FInterpTo(UnRotate_CurrentLocation.Y, UnRotate_TargetLocation.Y, DeltaSeconds, InLagSpeeds.Y),
		UKismetMathLibrary::FInterpTo(UnRotate_CurrentLocation.Z, UnRotate_TargetLocation.Z, DeltaSeconds, InLagSpeeds.Z));

	return UKismetMathLibrary::GreaterGreater_VectorRotator(UnRotateVector, L_CameraRotationYaw);
}

float AALS_PlayerCameraManager::GetCameraBehaviorParam(FName CurveName)
{
	//플레이어 카메라 비헤이비어 AnimBP에서 애님 커브 값을 가져와 커스텀 카메라 비헤이비어 계산에서 매개변수로 사용할 수 있습니다.
	if (IsValid(CameraBehavior->GetAnimInstance()))
		return CameraBehavior->GetAnimInstance()->GetCurveValue(CurveName);
	
	return 0;
}

TEnumAsByte<EDrawDebugTrace::Type> AALS_PlayerCameraManager::GetDebugTraceType(TEnumAsByte<EDrawDebugTrace::Type> InShowTraceType)
{
	APlayerController* WorldPlayerController = UGameplayStatics::GetPlayerController(this, 0);
	IALS_Controller_Interface* ALS_Controller_Interface = Cast<IALS_Controller_Interface>(WorldPlayerController);

	FALS_DebugInfo DebugInfo = ALS_Controller_Interface->I_GetDebugInfo();

	if (DebugInfo.bShowTraces)
		return InShowTraceType;

	return EDrawDebugTrace::None;
}
