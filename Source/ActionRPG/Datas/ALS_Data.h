#pragma once

#include "CoreMinimal.h"
#include "Curves/CurveVector.h"
#include "Engine/DataTable.h"
#include "ALS_Data.generated.h"

/**움직임의 상태*/
UENUM(BlueprintType)
enum class EALSMovementState : uint8
{
	//아무것도 아닌
	None UMETA(DisplayName = "None"),
	//땅에 있는
	Grounded UMETA(DisplayName = "Grounded"),
	//공중에 있는
	InAir UMETA(DisplayName = "In Air"),
	//멘틀링
	Mantling UMETA(DisplayName = "Mantling"),
	//레그돌
	RagDoll UMETA(DisplayName = "Ragdoll")
};

/**움직임의 액션*/
UENUM(BlueprintType)
enum class EALSMovementAction : uint8
{
	//아무것도 아닌
	None UMETA(DisplayName = "None"),
	//낮은 멘틀링
	LowMantle UMETA(DisplayName = "LowMantle"),
	//높은 멘틀링
	HighMantle UMETA(DisplayName = "HighMantle"),
	//구르기
	Rolling UMETA(DisplayName = "Rolling"),
	//일어서기
	GettingUp UMETA(DisplayName = "GettingUp")
};

/**회전 모드*/
UENUM(BlueprintType)
enum class EALSRotationMode : uint8
{
	//속도방향
	VelocityDirection UMETA(DisplayName = "VelocityDirection"),

	//보는 방향
	LookingDirection UMETA(DisplayName = "LookingDirection"),

	//조준 중
	Aiming UMETA(DisplayName = "Aiming")
};

/**보조 유형*/
UENUM(BlueprintType)
enum class EALSGait : uint8
{
	//걷는 중
	Walking UMETA(DisplayName = "Walking"),

	//달리는 중
	Running UMETA(DisplayName = "Running"),

	//질주 중
	Sprinting UMETA(DisplayName = "Sprinting")
};

/**자세 유형*/
UENUM(BlueprintType)
enum class EALSStance : uint8
{
	//서다
	Standing UMETA(DisplayName = "Standing"),

	//웅크리기
	Crouching UMETA(DisplayName = "Crouching")
};


/**멘틀 유형*/
UENUM(BlueprintType)
enum class EMantleType : uint8
{
	//높은 맨틀
	HighMantle UMETA(DisplayName = "HighMantle"),
	//낮은 맨틀
	LowMantle UMETA(DisplayName = "LowMantle"),
	//떨어지는 캐치
	FallingCatch UMETA(DisplayName = "FallingCatch"),
};


/**뷰 모드*/
UENUM(BlueprintType)
enum class EALSViewMode : uint8
{
	//3인칭
	ThirdPerson UMETA(DisplayName = "ThirdPerson"),

	//1인칭
	FirstPerson UMETA(DisplayName = "FirstPerson")
};


/**오버레이 상태*/
UENUM(BlueprintType)
enum class EALSOverlayState : uint8
{
	//3인칭
	Default UMETA(DisplayName = "Default"),
	Masculine UMETA(DisplayName = "Masculine"),
	Feminine UMETA(DisplayName = "Feminine"),
	Injured UMETA(DisplayName = "Injured"),
	HandsTied UMETA(DisplayName = "HandsTied"),
	Rifle UMETA(DisplayName = "Rifle"),
	Pistol1H UMETA(DisplayName = "Pistol 1H"),
	Pistol2H UMETA(DisplayName = "Pistol 2H"),
	Bow UMETA(DisplayName = "Bow"),
	Torch UMETA(DisplayName = "Torch"),
	Binoculars UMETA(DisplayName = "Binoculars"),
	Box UMETA(DisplayName = "Box"),
	Barrel UMETA(DisplayName = "Barrel"),
	Max UMETA(DisplayName = "Max")
	
};

/**땅과의 접지 상태 유형*/
UENUM(BlueprintType)
enum class EGroundedEntryState : uint8
{
	None UMETA(DisplayName = "None"),
	Roll UMETA(DisplayName = "Roll")
};

/**움직임의 방향*/
UENUM(BlueprintType)
enum class EMovementDirection : uint8
{
	Forward UMETA(DisplayName = "Forward"),
	Right UMETA(DisplayName = "Right"),
	Left UMETA(DisplayName = "Left"),
	Backward UMETA(DisplayName = "Backward")
};

/**엉덩이의 방향*/
UENUM(BlueprintType)
enum class EHipsDirection : uint8
{
	F UMETA(DisplayName = "F"),
	B UMETA(DisplayName = "B"),
	RF UMETA(DisplayName = "RF"),
	RB UMETA(DisplayName = "RB"),
	LF UMETA(DisplayName = "LF"),
	LB UMETA(DisplayName = "LB")
};


/**움직임의 상태*/
UENUM(BlueprintType)
enum class EALSMoveGround : uint8
{
	WhileTrue,
	WhileFalse,
	ChangedToTrue,
	ChangedToFalse	
};


/**속도 혼합 구조체*/
USTRUCT(BlueprintType)
struct FVelocityBlend
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float F;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float B;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float L;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float R;
};


/**기울기 양의 구조체*/
USTRUCT(BlueprintType)
struct FLeanAmount
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float LR;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float FB;

	FLeanAmount(): LR(0), FB(0)
	{
	}

	FLeanAmount(float InLR, float InFB)
	{
		LR = InLR;
		FB = InFB;
	}
};


/**기울기 양의 구조체*/
USTRUCT(BlueprintType)
struct FTurnInPlaceAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UAnimSequenceBase* Animation;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float AnimatedAngle;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FName SlotName;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float PlayRate;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	bool bScaleTurnAngle;

public:
	FTurnInPlaceAsset(): Animation(nullptr), AnimatedAngle(0)
	{
		PlayRate = 1.0f;
		bScaleTurnAngle = true;
	}

	FTurnInPlaceAsset(float InAnimatedAngle, FName InSlotName, float InPlayRate, bool InScaleTurnAngle): Animation(nullptr)
	{
		AnimatedAngle = InAnimatedAngle;
		SlotName = InSlotName;
		PlayRate = InPlayRate;
		bScaleTurnAngle = InScaleTurnAngle;
	}
};


/**기울기 양의 구조체*/
USTRUCT(BlueprintType)
struct FDynamicMontageParams
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UAnimSequenceBase* Animation;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float BlendInTime;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float BlendOutTime;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float PlayRate;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float StartTime;
};


/**기울기 양의 구조체*/
USTRUCT(BlueprintType)
struct FALS_DebugInfo
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	ACharacter* DebugFocusCharacter;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	bool bDebugView;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	bool bShowHUD;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	bool bShowTraces;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	bool bShowDebugShapes;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	bool bShowLayerColors;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	bool bSlomo;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	bool bShowCharacterInfo;
};




/**움직임 관련 기본 셋팅 값 */
USTRUCT(BlueprintType)
struct FMovementSettings
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float WalkSpeed;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float RunSpeed;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float SprintSpeed;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UCurveVector* MovementCurve;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UCurveFloat* RotationRateCurve;
};


/**움직임관련 설정 - 자세 구조체*/
USTRUCT(BlueprintType)
struct FMovementSettings_Stance
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FMovementSettings Standing;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FMovementSettings Crouching;
};


/**움직임관련 설정 - 상태 구조체*/
USTRUCT(BlueprintType)
struct FMovementSettings_State : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FMovementSettings_Stance VelocityDirection;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FMovementSettings_Stance LookingDirection;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FMovementSettings_Stance Aiming;
};


/**멘틀 에셋*/
USTRUCT(BlueprintType)
struct FMantle_Asset
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UAnimMontage* AnimMontage;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UCurveVector* Position_CorrectionCurve;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FVector StartingOffset;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float LowHeight;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float LowPlayRate;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float LowStartPosition;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float HighHeight;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float HighPlayRate;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float HighStartPosition;
};


/**멘틀 파라미터*/
USTRUCT(BlueprintType)
struct FMantle_Params
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UAnimMontage* AnimMontage;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UCurveVector* Position_CorrectionCurve;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float StartingPosition;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float PlayRate;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FVector StartingOffset;
};

/**멘틀 트레이스 셋팅 구조체*/
USTRUCT(BlueprintType)
struct FMantle_TraceSettings
{
	GENERATED_BODY()
public:
	/**최대 선반 높이*/
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float MaxLedgeHeight;

	/**최소 선반 높이*/
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float MinLedgeHeight;

	/**도달 거리*/
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float ReachDistance;

	/**순방향 추적 반경*/
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float ForwardTraceRadius;

	/**하향 궤적 반경*/
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float DownwardTraceRadius;
};

/**컴포넌트 그리고 트렌스폼*/
USTRUCT(BlueprintType)
struct FALS_ComponentAndTransform
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FTransform Transform;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UPrimitiveComponent* Component;
};

