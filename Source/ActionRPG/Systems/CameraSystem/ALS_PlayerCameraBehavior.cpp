#include "ALS_PlayerCameraBehavior.h"

#include "GlobalFunctions/CLog.h"
#include "Interfaces/ALS_Camera_Interface.h"
#include "Interfaces/ALS_Character_Interface.h"
#include "Interfaces/ALS_Controller_Interface.h"


void UALS_PlayerCameraBehavior::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	UpdateCharacterInfo();
}

void UALS_PlayerCameraBehavior::UpdateCharacterInfo()
{
	if (IsValid(ControlledPawn))
	{
		//스테이크 상태 가져오기
		IALS_Character_Interface* Cast_Character_Interface = Cast<IALS_Character_Interface>(ControlledPawn);
		CHECK(Cast_Character_Interface!=nullptr);
		TEnumAsByte<EMovementMode> OutMovementMode;
		EALSMovementState OutPrevMovementState;
		EALSOverlayState OutOverlayState;
		Cast_Character_Interface->I_GetCurrentStates(OutMovementMode, MovementState, OutPrevMovementState,
		                                          MovementAction, RotationMode, Gait, Stance, ViewMode, OutOverlayState);

		//카메라 파라미터 가져오기
		IALS_Camera_Interface* CastCamera_Interface = Cast<IALS_Camera_Interface>(ControlledPawn);
		CHECK(CastCamera_Interface!=nullptr);
		float OutTPFov;
		float OutFPFov;
		CastCamera_Interface->I_GetCameraParameters(OutTPFov, OutFPFov, bRightShoulder);
	}

	if (IsValid(PlayerController))
	{
		IALS_Controller_Interface* CastController_Interface = Cast<IALS_Controller_Interface>(PlayerController);
		CHECK(CastController_Interface!=nullptr);
		const FALS_DebugInfo DebugInfo = CastController_Interface->I_GetDebugInfo();
		bDebugView = DebugInfo.bDebugView;
	}
}
