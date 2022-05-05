#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Interfaces/ALS_Controller_Interface.h"
#include "ALS_PlayerController.generated.h"


UCLASS()
class ACTIONRPG_API AALS_PlayerController : public APlayerController,
                                            public IALS_Controller_Interface
{

private:
	GENERATED_BODY()

#pragma region                                IALS_Controller_Interface
public:
	virtual FALS_DebugInfo I_GetDebugInfo() override;
#pragma endregion                             IALS_Controller_Interface


#pragma region               Debug Members
private:
	/**포커스 된 디버그 캐릭터*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug Members", meta=(AllowPrivateAccess="true"))
	ACharacter* DebugFocusCharacter;

	/**사용 가능한 디버그 캐릭터들*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug Members", meta=(AllowPrivateAccess="true"))
	TArray<ACharacter*> AvailableDebugCharacters;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug Members", meta=(AllowPrivateAccess="true"))
	bool bShowHUD;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug Members", meta=(AllowPrivateAccess="true"))
	bool bDebugView;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug Members", meta=(AllowPrivateAccess="true"))
	bool bShowTraces;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug Members", meta=(AllowPrivateAccess="true"))
	bool bShowDebugShapes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug Members", meta=(AllowPrivateAccess="true"))
	bool bShowLayerColors;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug Members", meta=(AllowPrivateAccess="true"))
	bool bShowCharacterInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug Members", meta=(AllowPrivateAccess="true"))
	bool bSlomo;

#pragma endregion            Debug Members


#pragma region               Default Members
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Default Members", meta=(AllowPrivateAccess="true"))
	class UUW_ALSHUD* ALS_HUD;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Default Members", meta=(AllowPrivateAccess="true"))
	class UUW_OverlayStateSwitcher* OverlaySwitcher;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Default Members", meta=(AllowPrivateAccess="true"))
	bool bOverlayMenuOpen;
#pragma endregion            Default Members
};
