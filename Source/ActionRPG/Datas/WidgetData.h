#pragma once

#include "CoreMinimal.h"
#include "ALS_Data.h"
#include "UObject/NoExportTypes.h"
#include "WidgetData.generated.h"


/**오버레이 스테이트 버튼 파람*/
USTRUCT(BlueprintType)
struct FOverlayStateButtonParams
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	class UUW_OverlayStateButton* Widget;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	EALSOverlayState State;
};
