#pragma once

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

#include "GlobalFunctions/CLog.h"
#include "GlobalFunctions/CHelpers.h"
#include "GlobalFunctions/ALS_MacroLibrary.h"
// #include "GlobalFunctions/StatsLibrary.h"
// #include "GlobalFunctions/MacroLibrary.h"
// #include "GlobalFunctions/CombatLibrary.h"
// #include "GlobalFunctions/InventoryEquipmentLibrary.h"


#include "GlobalFunctions/Gate.h"
#include "GlobalFunctions/DoOnce.h"

// #define ECC_Interactable ECC_GameTraceChannel1
#define ECO_Interactable ObjectTypeQuery7
#define ECC_Interactable ECC_GameTraceChannel1
#define ECC_Climbable ECC_GameTraceChannel2


// #define TAG_ENEMY FName(TEXT("Enemy"))
// #define TAG_ENEMYAI FName(TEXT("EnemyAI"))
// #define TAG_MASTERAI FName(TEXT("MasterAI"))
// #define TAG_PLAYERCHARACTER FName(TEXT("PlayerCharacter"))
// #define TAG_PAWNCAPSULE FName(TEXT("Pawn Capsule"))
// #define TAG_LOCKONSPHERE FName(TEXT("LockOnSphere"))
// #define TAG_AICOMPONENT FName(TEXT("AI Component"))
// #define TAG_IGNORE FName(TEXT("Ignore"))

//스텟매니저 컴포넌트 관련된 변수 네임
// #define NOT_FIND_STAT_VALUE 0.0f


#define COLOR_MAGENTA FLinearColor(0.25f,0.0f,0.25f,1.0f)
#define COLOR_PURPLE FLinearColor(1.0f,0.0f,1.0f,1.0f)
#define COLOR_YELLOW FLinearColor(1.0f,0.5f,0.0f,1.0f)
#define COLOR_BROWN FLinearColor(0.25f,0.125f,0.0f,1.0f)
#define COLOR_SKY FLinearColor(0.0f,0.5f,1.0f,1.0f)
#define COLOR_ORANGE FLinearColor(0.9f, 0.4f, 0.0f, 1.0f)
#define COLOR_PINK FLinearColor(0.9f, 0.3f, 1.0f, 1.0f)


//물리(서피스) 타입
#define Brick SurfaceType1
#define Dirt SurfaceType2
#define Wood SurfaceType3
#define Blood SurfaceType4
#define Water SurfaceType5



