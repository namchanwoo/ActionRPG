#include "ALS_MacroLibrary.h"
#include "Kismet/KismetMathLibrary.h"

FString ALS_MacroLibrary::GetOverlayStateAsString(EALSOverlayState EnumValue)
{
	const UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EALSOverlayState"), true);
	if (!enumPtr)
		return FString(TEXT("Invalid NoEnum"));

	FString L_Name = enumPtr->GetNameStringByIndex(static_cast<int32>(EnumValue));
	return L_Name;
}

FString ALS_MacroLibrary::GetMovementModeAsString(EMovementMode EnumValue)
{
	const UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EMovementMode"), true);
	if (!enumPtr)
		return FString(TEXT("Invalid NoEnum"));

	FString L_Name = enumPtr->GetNameStringByIndex(static_cast<int32>(EnumValue));
	return L_Name;
}

FString ALS_MacroLibrary::GetMovementStateAsString(EALSMovementState EnumValue)
{
	const UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EALSMovementState"), true);
	if (!enumPtr)
		return FString(TEXT("Invalid NoEnum"));

	FString L_Name = enumPtr->GetNameStringByIndex(static_cast<int32>(EnumValue));
	return L_Name;
}

FString ALS_MacroLibrary::GetMovementActionAsString(EALSMovementAction EnumValue)
{
	const UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EALSMovementAction"), true);
	if (!enumPtr)
		return FString(TEXT("Invalid NoEnum"));

	FString L_Name = enumPtr->GetNameStringByIndex(static_cast<int32>(EnumValue));
	return L_Name;
}

FString ALS_MacroLibrary::GetRotationModeAsString(EALSRotationMode EnumValue)
{
	const UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EALSRotationMode"), true);
	if (!enumPtr)
		return FString(TEXT("Invalid NoEnum"));

	FString L_Name = enumPtr->GetNameStringByIndex(static_cast<int32>(EnumValue));
	return L_Name;
}

FString ALS_MacroLibrary::GetGaitAsString(EALSGait EnumValue)
{
	const UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EALSGait"), true);
	if (!enumPtr)
		return FString(TEXT("Invalid NoEnum"));

	FString L_Name = enumPtr->GetNameStringByIndex(static_cast<int32>(EnumValue));
	return L_Name;
}

FString ALS_MacroLibrary::GetStanceAsString(EALSStance EnumValue)
{
	const UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EALSStance"), true);
	if (!enumPtr)
		return FString(TEXT("Invalid NoEnum"));

	FString L_Name = enumPtr->GetNameStringByIndex(static_cast<int32>(EnumValue));
	return L_Name;
}

FString ALS_MacroLibrary::GetViewModeAsString(EALSViewMode EnumValue)
{
	const UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EALSViewMode"), true);
	if (!enumPtr)
		return FString(TEXT("Invalid NoEnum"));

	FString L_Name = enumPtr->GetNameStringByIndex(static_cast<int32>(EnumValue));
	return L_Name;
}


template <typename T>
bool ALS_MacroLibrary::ML_MultiTraceHit(TArray<T> Array)
{
	return Array.Num();
}



// template <class TClass>
// static bool ML_DoWhile(bool Condition, FDoOnce& Do_True, FDoOnce& Do_False,
//                        void (TClass::*TrueFunction)(void), void (TClass::*FalseFunction)(void))
// {
// 	if (Condition)
// 	{
// 		//한번만 실행만
// 		if (Do_True.Execute())
// 		{
// 			Do_False.Reset();
// 			TrueFunction();
// 		}
// 		return true;
// 	}
// 	else
// 	{
// 		if (Do_False.Execute())
// 		{
// 			Do_True.Reset();
// 			FalseFunction();
// 		}
// 		return false;
// 	}
// }


FALS_ComponentAndTransform ALS_MacroLibrary::ML_ComponentWorldToLocal(FALS_ComponentAndTransform WorldSpaceComponent)
{
	FALS_ComponentAndTransform OutComponentAndTransform;

	FTransform ComponentWorld = WorldSpaceComponent.Component->GetComponentToWorld();

	OutComponentAndTransform.Transform = WorldSpaceComponent.Transform * UKismetMathLibrary::InvertTransform(ComponentWorld);
	OutComponentAndTransform.Component = WorldSpaceComponent.Component;
	return OutComponentAndTransform;
}

FALS_ComponentAndTransform ALS_MacroLibrary::ML_ComponentLocalToWorld(FALS_ComponentAndTransform WorldSpaceComponent)
{
	FALS_ComponentAndTransform OutComponentAndTransform;

	OutComponentAndTransform.Transform = WorldSpaceComponent.Transform * WorldSpaceComponent.Component->GetComponentToWorld();
	OutComponentAndTransform.Component = WorldSpaceComponent.Component;
	return OutComponentAndTransform;
}

FTransform ALS_MacroLibrary::ML_Transform_Sub_Transform(FTransform A, FTransform B)
{
	FVector OutLocation = A.GetLocation() - B.GetLocation();
	FVector OutScale = A.GetScale3D() - B.GetScale3D();

	float OutRoll = A.GetRotation().X - B.GetRotation().X;
	float OutPitch = A.GetRotation().Y - B.GetRotation().Y;
	float OutYaw = A.GetRotation().Z - B.GetRotation().Z;
	FRotator OutRotation = FRotator(OutPitch, OutYaw, OutRoll);

	return FTransform(OutRotation, OutLocation, OutScale);
}

FTransform ALS_MacroLibrary::ML_Transform_Add_Transform(FTransform A, FTransform B)
{
	FVector OutLocation = A.GetLocation() + B.GetLocation();
	FVector OutScale = A.GetScale3D() + B.GetScale3D();

	float OutRoll = A.GetRotation().X + B.GetRotation().X;
	float OutPitch = A.GetRotation().Y + B.GetRotation().Y;
	float OutYaw = A.GetRotation().Z + B.GetRotation().Z;
	FRotator OutRotation = FRotator(OutPitch, OutYaw, OutRoll);

	return FTransform(OutRotation, OutLocation, OutScale);
}


// bool ALS_MacroLibrary::ML_DoWhile(bool Condition, FDoOnce& Do_True, FDoOnce& Do_False, FNoParmTest1 ChangedToTrue, FNoParmTest2 ChangedToFalse)
// {
// 		if (Condition)
// 		{
// 			//한번만 실행만
// 			if (Do_True.Execute())
// 			{
// 				Do_False.Reset();
// 				ChangedToTrue.Execute();
// 			}
// 			return true;
// 		}
// 		else
// 		{
// 			if (Do_False.Execute())
// 			{
// 				Do_True.Reset();
// 				ChangedToFalse.Execute();
// 			}
// 			return false;
// 		}
// }


//
// template <typename T>
// bool ALS_MacroLibrary::ML_DoWhile(bool Condition, FDoOnce& Do_True, FDoOnce& Do_False, void(T::* ChangedToTrueFunction)(),
// 	void(T::* ChangedToFalseFunction)())
// {
// 	//불이 트루라면
// 	if (Condition)
// 	{
// 		//한번만 실행만
// 		if (Do_True.Execute())
// 		{
// 			Do_False.Reset();
// 			ChangedToTrueFunction();
// 		}
// 		return true;
// 	}
// 	else
// 	{
// 		if (Do_False.Execute())
// 		{
// 			Do_True.Reset();
// 			ChangedToFalseFunction();
// 		}
// 		return false;
// 	}
// }
