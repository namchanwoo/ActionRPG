#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UW_OverlayStateButton.generated.h"


UCLASS()
class ACTIONRPG_API UUW_OverlayStateButton : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable,Category="OverlayStateButton Event")
	void SetVisualParameters(bool Selected);

#pragma region                           Designer Members
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Designer", meta = (BindWidget))
	class UCanvasPanel* CanvasPanel_Main;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Designer", meta = (BindWidget))
	class UCanvasPanel* CanvasPanel_Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Designer", meta = (BindWidget))
	class UImage* Image_Background;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Designer", meta = (BindWidget))
	class UTextBlock* Text_OverlayState;

#pragma endregion                        Designer Members


#pragma region                           Properties Members
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Properties")
	FLinearColor BackgroundSelectedColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Properties")
	FLinearColor BackgroundUnSelectedColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Properties")
	FLinearColor TextSelectedColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Properties")
	FLinearColor TextUnSelectedColor;
	
#pragma endregion                        Properties Members
};
