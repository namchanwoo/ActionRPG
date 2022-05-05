#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/VerticalBox.h"
#include "Datas/ALS_Data.h"
#include "Datas/WidgetData.h"
#include "UW_OverlayStateSwitcher.generated.h"


UCLASS()
class ACTIONRPG_API UUW_OverlayStateSwitcher : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="OverlayStateSwitcher")
	void SelectOverlayState();
	
	UFUNCTION(BlueprintCallable, Category="OverlayStateSwitcher")
	void CreateButtons();
	
	UFUNCTION(BlueprintCallable,Category="OverlayStateSwitcher")
	void UpdateButtonFocus();

	UFUNCTION(BlueprintCallable,Category="OverlayStateSwitcher")
	void CycleState(bool IsUp);

	
#pragma region               Designer Members
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Designer", meta = (BindWidget))
	class UCanvasPanel* CanvasPanel_Main;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Designer", meta = (BindWidget))
	class UCanvasPanel* CanvasPanel_MovablePanel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Designer", meta = (BindWidget))
	UVerticalBox* VerticalBox_List;
#pragma endregion            Designer Members


#pragma region                Properties Members
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Properties")
	TArray<FOverlayStateButtonParams> OverlayStateButtons;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Properties")
	EALSOverlayState NewOverlayState;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Initialize | SpawnClass")
	TSubclassOf<UUW_OverlayStateButton> BP_OverlayStateButtonClass;
#pragma endregion             Properties Members
};
