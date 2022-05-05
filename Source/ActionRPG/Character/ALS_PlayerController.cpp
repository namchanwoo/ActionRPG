#include "Character/ALS_PlayerController.h"


FALS_DebugInfo AALS_PlayerController::I_GetDebugInfo()
{
	FALS_DebugInfo OutDebugInfo;
	OutDebugInfo.DebugFocusCharacter = DebugFocusCharacter;
	OutDebugInfo.bDebugView = bDebugView;
	OutDebugInfo.bShowHUD = bShowHUD;
	OutDebugInfo.bShowTraces = bShowTraces;
	OutDebugInfo.bShowDebugShapes = bShowDebugShapes;
	OutDebugInfo.bShowLayerColors = bShowLayerColors;
	OutDebugInfo.bSlomo = bSlomo;
	OutDebugInfo.bShowCharacterInfo = bShowCharacterInfo && !bOverlayMenuOpen;
	return OutDebugInfo;
}
