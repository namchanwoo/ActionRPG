#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Datas/ALS_Data.h"
#include "ALS_Character_Interface.generated.h"

// This class does not need to be modified.
UINTERFACE(Blueprintable, MinimalAPI, meta=(CannotImplementInterfaceInBlueprint))
class UALS_Character_Interface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ACTIONRPG_API IALS_Character_Interface
{
	GENERATED_BODY()
public:
#pragma region                Character Information Methods
public:
	/**캐릭터와 동기화 해야 할 필수적인 변수들을 가져 옵니다*/
	virtual void I_GetEssentialValues(FVector& OutVelocity, FVector& OutAcceleration, FVector& OutMovementInput,
	                                  bool& OutIsMoving, bool& OutHasMovementInput, float& OutSpeed, float& OutMovementInputAmount,
	                                  FRotator& OutAimingRotation, float& OutAimYawRate) =0;

	UFUNCTION(BlueprintCallable, Category="IALS_Character_Interface")
	virtual void I_GetCurrentStates(TEnumAsByte<EMovementMode>& OutPawnMovementMode, EALSMovementState& OutMovementState,
	                                EALSMovementState& OutPrevMovementState, EALSMovementAction& OutMovementAction,
	                                EALSRotationMode& OutRotationMode, EALSGait& OutActualGait, EALSStance& OutActualStance,
	                                EALSViewMode& OutViewMode, EALSOverlayState& OutOverlayState) =0;

#pragma endregion             Character Information Methods


#pragma region                Character States Methods
public:
	virtual void I_SetMovementState(EALSMovementState NewMovementState) =0;

	virtual void I_SetMovementAction(EALSMovementAction NewMovementAction) =0;

	virtual void I_SetRotationMode(EALSRotationMode NewRotationMode) =0;

	virtual void I_SetGait(EALSGait NewGait) =0;

	virtual void I_SetViewMode(EALSViewMode NewViewMode) =0;

	UFUNCTION(BlueprintCallable, Category="IALS_Character_Interface")
	virtual void I_SetOverlayState(EALSOverlayState NewOverlayState) =0;

#pragma endregion             Character States Methods
};
