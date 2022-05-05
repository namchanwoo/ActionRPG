#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ALS_Camera_Interface.generated.h"


UINTERFACE(Blueprintable, meta=(CannotImplementInterfaceInBlueprint),MinimalAPI)
class UALS_Camera_Interface : public UInterface
{
	GENERATED_BODY()
};


class ACTIONRPG_API IALS_Camera_Interface
{
	GENERATED_BODY()

public:
	/**카메라의 프로퍼티를 가져옵니다*/
	virtual void I_GetCameraParameters(float& OutTP_Fov, float& OutFP_Fov, bool& OutRightShoulder) =0;

	/**1인칭 카메라 타겟을(백터)를 가져옵니다*/
	UFUNCTION(BlueprintCallable,Category="IALS_Camera_Interface")
	virtual FVector I_GetFP_CameraTarget() =0;

	/**3안칭 중심을(트렌스폼)을 가져옵니다*/
	UFUNCTION(BlueprintCallable,Category="IALS_Camera_Interface")
	virtual FTransform I_Get3P_PivotTarget() =0;

	/**3인칭 트레이스파라미터를 가져옵니다*/
	UFUNCTION(BlueprintCallable,Category="IALS_Camera_Interface")
	virtual void I_Get3P_TraceParams(FVector& OutTraceOrigin, float& OutTraceRadius, TEnumAsByte<ETraceTypeQuery>& OutTraceChannel) =0;
};
