#include "MenuManager.h"

bool EditorMode = false;
uint8_t MenuCounter = 0;
dynamicAnimations LampAnimation = (dynamicAnimations)0;
	
void Menu_Show(buttonCommands* command)
{
	nixieActions action;
	
	if(EditorMode == false)
	{
		switch(MenuCounter)
		{
			case 0:
				action = DataDisplay_ShowTime(LampAnimation);
			break;
			
			case 1:
				action = DataDisplay_ShowDate(LampAnimation);
			break;
			
			default:
			break;
		}
	
		switch(*command)
		{
			case COMMAND_EDITOR_MODE:
				EditorMode = true;
			break;
			
			case COMMAND_INCREASING:
				MenuCounter++;
			break;

			case COMMAND_DECREASING:
				LampAnimation++;
			break;
			
			default:
			break;
		}
	
		if(MenuCounter > 1)
			MenuCounter = 0;
		
		if(LampAnimation > (dynamicAnimations)1)
			LampAnimation = (dynamicAnimations)0;
	}
	
	if(EditorMode == true)
	{
		switch(MenuCounter)
		{
			case 0:
				action = DataDisplay_EditTime(*command);
			break;
			
			case 1:
				action = DataDisplay_EditDate(*command);
			break;
			
			default:
			break;
		}
	}
	
	if(action == NIXIE_ACTION_END_OF_TIME_EDIT | action == NIXIE_ACTION_END_OF_DATE_EDIT)
		EditorMode = false;
}

