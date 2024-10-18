#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_RECT,		//Recangle item in menu
	ITM_SQUARE, // SQAURE ICON IN MENU
	ITM_CIRCLE,  	// CIRCLE ICON IN MENU
	ITM_TRI, // trinagle icon in the menu
	ITM_HEXAGON,  // HEXAGON ICON IN MENU
	ITM_ChangeFillingColour,		//change filling colour item in menu
	ITM_ChangeDrawingColour, //change drawing colour item in menu
	ITM_Black,		//Black item in menu
	ITM_Red,		//Red item in menu
	ITM_Blue,		//Blue item in menu
	ITM_Green,		//Green item in menu
	ITM_Yellow,		//Blue item in menu
	ITM_Orange,		//Blue item in menu
	ITM_SELECT,
	ITM_MoveFigure,		//move figure item in menu
	ITM_DeleteFigure,		//delete figure item in menu
	ITM_Undo,		//undo item in menu
	ITM_Redo,		//redo item in menu
	ITM_Reset,		//reset item in menu
	ITM_StartRecording,		//start recording item in menu
	ITM_StopRecording,		//stop recording item in menu
	ITM_PlayRecording,		//play recording item in menu
	ITM_Save,		//save item in menu
	ITM_Load,		//load item in men
	TO_PLAY, //switch to play mode
	ITM_EXIT,		//Exit item

	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_PickbyFigure,		// PickbyFigure item in menu
	ITM_PickbyColour,		//PickbyColour item in menu
	ITM_PickbyFigure_colour,		//PickbyFigure_colour item in menu
	TO_DRAW,		//switch to draw mode 
	ITM_EXITT,
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,	    //Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed

}UI;	//create a global object UI

#endif