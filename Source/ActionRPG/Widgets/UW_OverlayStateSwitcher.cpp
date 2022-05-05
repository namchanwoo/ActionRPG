#include "UW_OverlayStateSwitcher.h"

#include "UW_OverlayStateButton.h"
#include "Components/TextBlock.h"
#include "GlobalFunctions/ALS_MacroLibrary.h"
#include "GlobalFunctions/CLog.h"
#include "Interfaces/ALS_Character_Interface.h"
#include "Kismet/KismetTextLibrary.h"


// void UUW_OverlayStateSwitcher::SelectOverlayState()
// {
// 	IALS_Character_Interface* ALS_Character_Interface = Cast<IALS_Character_Interface>(GetOwningPlayer()->GetPawn());
// 	CHECK(ALS_Character_Interface!=nullptr);
// 	ALS_Character_Interface->I_SetOverlayState(NewOverlayState);
// }

void UUW_OverlayStateSwitcher::SelectOverlayState()
{
	IALS_Character_Interface* Cast_ALS_Character_Interface = Cast<IALS_Character_Interface>(GetOwningPlayer()->GetPawn());
	CHECK(Cast_ALS_Character_Interface!=nullptr);
	Cast_ALS_Character_Interface->I_SetOverlayState(NewOverlayState);
}

void UUW_OverlayStateSwitcher::CreateButtons()
{
	TArray<EALSOverlayState> ArrayOverlayStates;
	for (int32 i = 0; i < static_cast<int32>(EALSOverlayState::Max); i++)
	{
		EALSOverlayState AddOverlayState = static_cast<EALSOverlayState>(i);
		if (AddOverlayState == EALSOverlayState::Max)
			break;
		ArrayOverlayStates.Add(AddOverlayState);
	}


	for (const auto OverlayState : ArrayOverlayStates)
	{
		UUW_OverlayStateButton* L_Button = CreateWidget<UUW_OverlayStateButton>(GetOwningPlayer(), BP_OverlayStateButtonClass);
		FString OverlayStateString = ALS_MacroLibrary::GetOverlayStateAsString(OverlayState);
		L_Button->Text_OverlayState->SetText(UKismetTextLibrary::Conv_StringToText(OverlayStateString));
		VerticalBox_List->AddChildToVerticalBox(L_Button);

		FOverlayStateButtonParams AddParam;
		AddParam.Widget = L_Button;
		AddParam.State = OverlayState;
		OverlayStateButtons.Add(AddParam);
	}
}

void UUW_OverlayStateSwitcher::UpdateButtonFocus()
{
	for (const auto OverlayStateButton : OverlayStateButtons)
		if (IsValid(OverlayStateButton.Widget))
			OverlayStateButton.Widget->SetVisualParameters(OverlayStateButton.State == NewOverlayState);
}

void UUW_OverlayStateSwitcher::CycleState(bool IsUp)
{
	TArray<EALSOverlayState> TempEnum;
	TempEnum.Empty();

	for (int32 i = 0; i < static_cast<int32>(EALSOverlayState::Max); i++)
		TempEnum.Add(static_cast<EALSOverlayState>(i));

	if (IsUp)
		NewOverlayState = ALS_MacroLibrary::ML_GetPreviousArrayItem(TempEnum, NewOverlayState);
	else
		NewOverlayState = ALS_MacroLibrary::ML_GetNextArrayItem(TempEnum, NewOverlayState);

	UpdateButtonFocus();
}
