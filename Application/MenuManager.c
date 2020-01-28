#include "MenuManager.h"

bool EditorMode = false;

void Menu_Show(buttons* control)
{
//	static uint8_t modeCounter;
	static nixieActions action;
	
	if(EditorMode == false)
		action = Nixie_ShowTime(DYNAMIC_ANIMATION_NONE);
	
	if(*control == BUTTON_MODE_SAVE_CHANGES)
		EditorMode = true;
	
	if(EditorMode == true)
		action = Nixie_EditTime(control);
	
	if(action == NIXIE_ACTION_END_OF_TIME_EDIT)
		EditorMode = false;
}

