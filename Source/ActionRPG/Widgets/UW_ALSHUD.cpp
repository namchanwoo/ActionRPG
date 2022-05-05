#include "UW_ALSHUD.h"

//
// ESlateVisibility UUW_ALSHUD::Get_HUD_Visibility()
// {
// 	if (bShowHUD)
// 		return ESlateVisibility::Visible;
//
// 	return ESlateVisibility::Collapsed;
// }
//
// FSlateColor UUW_ALSHUD::Get_ShowHUD_Color()
// {
// 	if (bShowHUD)
// 	{
// 		return FSlateColor(EnabledColor);
// 	}
// 	else
// 	{
// 		return FSlateColor(DisabledColor);
// 	}
// }
//
// FSlateColor UUW_ALSHUD::Get_Slomo_Color()
// {
// 	if (bSlomo)
// 	{
// 		return FSlateColor(EnabledColor);
// 	}
// 	else
// 	{
// 		return FSlateColor(DisabledColor);
// 	}
// }
//
// FSlateColor UUW_ALSHUD::Get_Debug_View_Color()
// {
// 	if (bDebugView)
// 	{
// 		return FSlateColor(EnabledColor);
// 	}
// 	else
// 	{
// 		return FSlateColor(DisabledColor);
// 	}
// }
//
// FSlateColor UUW_ALSHUD::Get_ShowTraces_Color()
// {
// 	if (bShowTraces)
// 	{
// 		return FSlateColor(EnabledColor);
// 	}
// 	else
// 	{
// 		return FSlateColor(DisabledColor);
// 	}
// }
//
// FSlateColor UUW_ALSHUD::Get_ShowDebugShapes_Color()
// {
// 	if (bShowDebugShapes)
// 	{
// 		return FSlateColor(EnabledColor);
// 	}
// 	else
// 	{
// 		return FSlateColor(DisabledColor);
// 	}
// }
//
// FSlateColor UUW_ALSHUD::Get_ShowLayerColors_Color()
// {
// 	if (bShowLayerColors)
// 	{
// 		return FSlateColor(EnabledColor);
// 	}
// 	else
// 	{
// 		return FSlateColor(DisabledColor);
// 	}
// }
//
// FSlateColor UUW_ALSHUD::Get_ShowCharacterInfo_Color()
// {
// 	if (bShowCharacterInfo)
// 	{
// 		return FSlateColor(EnabledColor);
// 	}
// 	else
// 	{
// 		return FSlateColor(DisabledColor);
// 	}
// }
//
// FText UUW_ALSHUD::Get_DebugCharacterName()
// {
// 	if (IsValid(DebugFocusCharacter))
// 	{
// 		return FText::FromString(UKismetSystemLibrary::GetObjectName(DebugFocusCharacter));
// 	}
//
// 	return FText::FromString(FString(TEXT("No Valid Character Selected")));
// }
//
// FText UUW_ALSHUD::Get_CharacterStates()
// {
// 	if (bShowCharacterInfo)
// 	{
// 		if (IsValid(DebugFocusCharacter))
// 		{
// 			IALS_Character_Interface* ALS_Character_Interface = Cast<IALS_Character_Interface>(DebugFocusCharacter);
// 			CHECK(ALS_Character_Interface!=nullptr, {});
//
// 			TEnumAsByte<EMovementMode> OutPawnMovementMode;
// 			EALSMovementState OutMovementState;
// 			EALSMovementState OutPrevMovementState;
// 			EALSMovementAction OutMovementAction;
// 			EALSRotationMode OutRotationMode;
// 			EALSGait OutActualGait;
// 			EALSStance OutActualStance;
// 			EALSViewMode OutViewMode;
// 			EALSOverlayState OutOverlayState;
// 			ALS_Character_Interface->I_GetCurrentStates(OutPawnMovementMode, OutMovementState, OutPrevMovementState, OutMovementAction, OutRotationMode,
// 			                                          OutActualGait, OutActualStance, OutViewMode, OutOverlayState);
//
// 			FString MovementModeString = ALS_MacroLibrary::GetMovementModeAsString(OutPawnMovementMode);
// 			FString MovementStateString = ALS_MacroLibrary::GetMovementStateAsString(OutMovementState);
// 			FString MovementActionString = ALS_MacroLibrary::GetMovementActionAsString(OutMovementAction);
// 			FString RotationModeString = ALS_MacroLibrary::GetRotationModeAsString(OutRotationMode);
// 			FString ActualGaitString = ALS_MacroLibrary::GetGaitAsString(OutActualGait);
// 			FString StanceString = ALS_MacroLibrary::GetStanceAsString(OutActualStance);
// 			FString ViewModeString = ALS_MacroLibrary::GetViewModeAsString(OutViewMode);
// 			FString OverlayStateString = ALS_MacroLibrary::GetOverlayStateAsString(OutOverlayState);
//
// 			FString DebugString;
// 			DebugString.Append(MovementModeString);
// 			DebugString.Append(TEXT(""));
// 			DebugString.Append(TEXT(""));
//
// 			DebugString.Append(MovementStateString);
// 			DebugString.Append(TEXT(""));
// 			DebugString.Append(TEXT(""));
//
// 			DebugString.Append(MovementActionString);
// 			DebugString.Append(TEXT(""));
// 			DebugString.Append(TEXT(""));
//
// 			DebugString.Append(RotationModeString);
// 			DebugString.Append(TEXT(""));
// 			DebugString.Append(TEXT(""));
//
// 			DebugString.Append(ActualGaitString);
// 			DebugString.Append(TEXT(""));
// 			DebugString.Append(TEXT(""));
//
// 			DebugString.Append(StanceString);
// 			DebugString.Append(TEXT(""));
// 			DebugString.Append(TEXT(""));
//
// 			DebugString.Append(ViewModeString);
// 			DebugString.Append(TEXT(""));
// 			DebugString.Append(TEXT(""));
//
// 			DebugString.Append(OverlayStateString);
// 			DebugString.Append(TEXT(""));
// 			DebugString.Append(TEXT(""));
//
// 			return FText::FromString(DebugString);
// 		}
// 	}
//
//
// 	return {};
// }
//
// FText UUW_ALSHUD::Get_AnimCurveNames()
// {
// 	if (IsValid(DebugFocusCharacter))
// 	{
// 		if (IsValid(DebugFocusCharacter->GetMesh()->GetAnimInstance()))
// 		{
// 			const UAnimInstance* MeshAnimInstance = DebugFocusCharacter->GetMesh()->GetAnimInstance();
// 			TArray<FName> CurveNames;
// 			MeshAnimInstance->GetActiveCurveNames(EAnimCurveType::AttributeCurve, CurveNames);
//
// 			FString AnimCurveString;
//
// 			for (auto CurveName : CurveNames)
// 			{
// 				AnimCurveString.Append(CurveName.ToString());
// 				AnimCurveString.Append(TEXT(" "));
// 				AnimCurveString.Append(TEXT(" "));
// 			}
//
// 			return FText::FromString(AnimCurveString);
// 		}
// 		else
// 			return FText::FromString(TEXT("No Anim Instance"));
// 	}
//
// 	return {};
// }
//
// FText UUW_ALSHUD::Get_Anim_Curve_Values()
// {
// 	if (IsValid(DebugFocusCharacter))
// 	{
// 		if (IsValid(DebugFocusCharacter->GetMesh()->GetAnimInstance()))
// 		{
// 			const UAnimInstance* MeshAnimInstance = DebugFocusCharacter->GetMesh()->GetAnimInstance();
// 			TArray<FName> CurveNames;
// 			MeshAnimInstance->GetActiveCurveNames(EAnimCurveType::AttributeCurve, CurveNames);
//
// 			FString AnimCurveValueString;
//
// 			for (auto CurveName : CurveNames)
// 			{
// 				AnimCurveValueString.Append(UKismetStringLibrary::Conv_FloatToString(MeshAnimInstance->GetCurveValue(CurveName)));
// 				AnimCurveValueString.Append(TEXT(" "));
// 				AnimCurveValueString.Append(TEXT(" "));
// 			}
//
// 			return FText::FromString(AnimCurveValueString);
// 		}
// 	}
// 	return {};
// }
//
// ESlateVisibility UUW_ALSHUD::Get_CharacterInfo_Visibility()
// {
// 	if (IsValid(DebugFocusCharacter))
// 	{
// 		if (bShowCharacterInfo)
// 			return ESlateVisibility::Visible;
// 	}
// 	return ESlateVisibility::Hidden;
// }
