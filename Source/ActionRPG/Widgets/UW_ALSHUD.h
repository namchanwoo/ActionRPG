#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UW_ALSHUD.generated.h"


UCLASS()
class ACTIONRPG_API UUW_ALSHUD : public UUserWidget
{
	GENERATED_BODY()
	
public:
	// UFUNCTION(BlueprintPure)
	// ESlateVisibility Get_HUD_Visibility();
	//
	// UFUNCTION(BlueprintPure)
	// FSlateColor Get_ShowHUD_Color();
	//
	// UFUNCTION(BlueprintPure)
	// FSlateColor Get_Slomo_Color();
	//
	// UFUNCTION(BlueprintPure)
	// FSlateColor Get_Debug_View_Color();
	//
	// UFUNCTION(BlueprintPure)
	// FSlateColor Get_ShowTraces_Color();
	//
	// UFUNCTION(BlueprintPure)
	// FSlateColor Get_ShowDebugShapes_Color();
	//
	// UFUNCTION(BlueprintPure)
	// FSlateColor Get_ShowLayerColors_Color();
	//
	// UFUNCTION(BlueprintPure)
	// FSlateColor Get_ShowCharacterInfo_Color();
	//
	// UFUNCTION(BlueprintPure)
	// FText Get_DebugCharacterName();
	//
	// UFUNCTION(BlueprintPure)
	// FText Get_CharacterStates();
	//
	// UFUNCTION(BlueprintPure)
	// FText Get_AnimCurveNames();
	//
	// UFUNCTION(BlueprintPure)
	// FText Get_Anim_Curve_Values();
	//
	// /**캐릭터정보의 가시성 활성화 여부룰 가져옵니다 */
	// UFUNCTION(BlueprintPure)
	// ESlateVisibility Get_CharacterInfo_Visibility();


#pragma region                           Properties Members
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Properties")
	ACharacter* DebugFocusCharacter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Properties")
	bool bDebugView;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Properties")
	bool bShowHUD;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Properties")
	bool bSlomo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Properties")
	bool bShowTraces;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Properties")
	bool bShowDebugShapes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Properties")
	bool bShowLayerColors;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Properties")
	bool bShowCharacterInfo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Properties")
	FLinearColor EnabledColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Properties")
	FLinearColor DisabledColor;

#pragma endregion                        Properties Members
};
