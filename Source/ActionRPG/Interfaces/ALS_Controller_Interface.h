
#pragma once

#include "CoreMinimal.h"
#include "Datas/ALS_Data.h"
#include "UObject/Interface.h"
#include "ALS_Controller_Interface.generated.h"


UINTERFACE(Blueprintable, MinimalAPI, meta=(CannotImplementInterfaceInBlueprint))
class UALS_Controller_Interface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ACTIONRPG_API IALS_Controller_Interface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="IALS_Controller_Interface")
	virtual FALS_DebugInfo I_GetDebugInfo()=0;
};
