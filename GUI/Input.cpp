#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check which Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_SQUARE: return DRAW_SQUARE;
			case ITM_CIRCLE: return DRAW_CIRCLE;
			case ITM_TRI: return DRAW_TRI;
			case ITM_HEXAGON: return DRAW_HEXAGON;
			case ITM_MoveFigure: return MoveFigure;
			case ITM_DeleteFigure: return DeleteFigure;
			case ITM_Undo: return Undo;
			case ITM_ChangeFillingColour: return ChangeFillingColour;
			case ITM_ChangeDrawingColour:return ChangeDrawingColour;
			case ITM_Redo: return Redo;
			case ITM_Red: return Red;
			case ITM_Black: return Black;
			case ITM_Blue: return Blue;
			case ITM_Green: return Green;
			case ITM_Yellow: return Yellow;
			case ITM_Orange: return Orange;
			case ITM_SELECT: return Selectt;
			case ITM_Reset: return Reset;
			case ITM_StartRecording: return StartRecording;
			case ITM_StopRecording: return StopRecording;
			case ITM_PlayRecording: return PlayRecording;
			case ITM_Save: return Save;
			case ITM_Load: return Load;
			case TO_PLAY: return SwitchtoPlayMode;
			case ITM_EXIT: return EXIT;
			











			default: return EMPTY;	//A click on empty place in desgin toolbar
			}







		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{

		if (y >= 0 && y < UI.ToolBarHeight)
		{

			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder)
			{


			case ITM_PickbyFigure: return PickbyFigure;
			case ITM_PickbyColour: return PickbyColour;
			case ITM_PickbyFigure_colour: return PickbyFigure_colour;
			case TO_DRAW: return SwitchtoDrawMode;
			case ITM_EXITT: return EXIT;





			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}
		//[3] User clicks on the status bar
		return STATUS;
	}

}


/////////////////////////////////

Input::~Input()
{
}
