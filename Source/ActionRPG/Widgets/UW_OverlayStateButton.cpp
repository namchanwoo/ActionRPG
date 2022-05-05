#include "UW_OverlayStateButton.h"


#include "Components/Image.h"
#include "Components/TextBlock.h"

void UUW_OverlayStateButton::SetVisualParameters(bool Selected)
{
	if (Selected)
	{
		Image_Background->SetColorAndOpacity(BackgroundSelectedColor);
		Text_OverlayState->SetColorAndOpacity(TextSelectedColor);
	}
	else
	{
		Image_Background->SetColorAndOpacity(BackgroundUnSelectedColor);
		Text_OverlayState->SetColorAndOpacity(TextUnSelectedColor);
	}
}
