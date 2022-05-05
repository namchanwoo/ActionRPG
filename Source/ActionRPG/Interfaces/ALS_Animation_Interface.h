#pragma once

#include "CoreMinimal.h"
#include "Datas/ALS_Data.h"
#include "UObject/Interface.h"
#include "ALS_Animation_Interface.generated.h"


UINTERFACE(MinimalAPI)
class UALS_Animation_Interface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ACTIONRPG_API IALS_Animation_Interface
{
	GENERATED_BODY()

public:
	virtual void I_Jumped() =0;

	virtual void I_SetGroundedEntryState(EGroundedEntryState InGroundedEntryState) =0;

	virtual void I_SetOverlayOverrideState(int32 InOverlayOverrideState) =0;
};
