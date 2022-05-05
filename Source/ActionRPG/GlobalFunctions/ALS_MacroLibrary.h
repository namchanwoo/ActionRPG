#pragma once

#include "CoreMinimal.h"
#include "Datas/ALS_Data.h"
#include "GlobalFunctions/DoOnce.h"
#include "Kismet/KismetMathLibrary.h"


DECLARE_DELEGATE(FNoParmTest1) //임시
DECLARE_DELEGATE(FNoParmTest2) //임시

/**매크로 라이브러리_ A와 B의 비교 값을 반환합니다*/
#define ML_IsDifferent(A,B) A!=B

/**매크로 라이브러리_이전 값과 현재 값을 갱신합니다*/
#define ML_SetPreviousAndNewValue(NewValue,NewTarget,PreviousTarget) \
	PreviousTarget=NewTarget; \
	NewTarget = NewValue;


class ACTIONRPG_API ALS_MacroLibrary
{
public:

	static FString GetOverlayStateAsString(EALSOverlayState EnumValue);
	
	static FString GetMovementModeAsString(EMovementMode EnumValue);
	static FString GetMovementStateAsString(EALSMovementState EnumValue);
	static FString GetMovementActionAsString(EALSMovementAction EnumValue);
	static FString GetRotationModeAsString(EALSRotationMode EnumValue);
	static FString GetGaitAsString(EALSGait EnumValue);
	static FString GetStanceAsString(EALSStance EnumValue);
	static FString GetViewModeAsString(EALSViewMode EnumValue);


	
	/**배열의 갯수를 bool의 결과로 반환합니다*/
	template <typename T>
	static bool ML_MultiTraceHit(TArray<T> Array);

	/**컴포넌트의 월드 트렌스폼을 로컬트렌스폼으로 변경하여 반환합니다*/
	static FALS_ComponentAndTransform ML_ComponentWorldToLocal(FALS_ComponentAndTransform WorldSpaceComponent);

	/**컴포넌트의 로컬 트렌스폼을 월드 트렌스폼으로 변경하여 반환합니다*/
	static FALS_ComponentAndTransform ML_ComponentLocalToWorld(FALS_ComponentAndTransform WorldSpaceComponent);

	/**A와 B의 트렌스폼을 뺀 결과를 반환합니다*/
	static FTransform ML_Transform_Sub_Transform(FTransform A, FTransform B);

	/**A와 B의 트렌스폼을 더한 결과를 반환합니다*/
	static FTransform ML_Transform_Add_Transform(FTransform A, FTransform B);


	/**배열에서 다음 아이템을 찾습니다*/
	template <typename T>
	static T ML_GetNextArrayItem(TArray<T> Array, T CurrentArrayItem)
	{
		int32 FindIndex = Array.Find(CurrentArrayItem);
		int32 SelectInt = UKismetMathLibrary::SelectInt(0, FindIndex + 1, FindIndex == Array.Max());
		return Array[SelectInt];
	}


	/**배열에서 이전 아이템을 찾습니다*/
	template <typename T>
	static T ML_GetPreviousArrayItem(TArray<T> Array, T CurrentArrayItem)
	{
		const int32 FindIndex = Array.Find(CurrentArrayItem);
		int32 SelectInt = UKismetMathLibrary::SelectInt(0, FindIndex - 1, FindIndex <= 0);
		return Array[SelectInt];
	}


	// static bool ML_DoWhile(bool Condition, FDoOnce& Do_True, FDoOnce& Do_False, FNoParmTest1 ChangedToTrue, FNoParmTest2 ChangedToFalse);

	template <class TClass>
	static bool ML_DoWhile(UObject* InContext, bool Condition, FDoOnce& Do_True, FDoOnce& Do_False,
	                       void (TClass::*CheckToTrue)(void), void (TClass::*CheckToFalse)(void))
	{
		TClass* CastContext = Cast<TClass>(InContext);
		CHECK(CastContext != nullptr, false);

		if (Condition)
		{
			//한번만 실행만
			if (Do_True.Execute())
			{
				Do_False.Reset();
				(CastContext->*CheckToTrue)();
			}
			return true;
		}
		else
		{
			if (Do_False.Execute())
			{
				Do_True.Reset();
				(CastContext->*CheckToFalse)();
			}
			return false;
		}
	}
};
