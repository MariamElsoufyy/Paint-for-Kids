#include "Output.h"

#include<cmath>
Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 47;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;


	string drawMenuItemImages[DRAW_ITM_COUNT];

	drawMenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	drawMenuItemImages[ITM_CIRCLE] = "images\\MenuItems\\Menu_Circ.jpg";
	drawMenuItemImages[ITM_TRI] = "images\\MenuItems\\menu_tri.jpg";
	drawMenuItemImages[ITM_SQUARE] = "images\\MenuItems\\menu_sqr.jpg";
	drawMenuItemImages[ITM_HEXAGON] = "images\\MenuItems\\menu_hex.jpg";
	drawMenuItemImages[ITM_ChangeFillingColour] = "images\\MenuItems\\FillingColour.jpg";
	drawMenuItemImages[ITM_ChangeDrawingColour] = "images\\MenuItems\\DrawingColour.jpg";
	drawMenuItemImages[ITM_MoveFigure] = "images\\MenuItems\\MoveFigure.jpg";
	drawMenuItemImages[ITM_DeleteFigure] = "images\\MenuItems\\DeleteFigure.jpg";
	drawMenuItemImages[ITM_Undo] = "images\\MenuItems\\Undo.jpg";
	drawMenuItemImages[ITM_Redo] = "images\\MenuItems\\Redo.jpg";
	drawMenuItemImages[ITM_Reset] = "images\\MenuItems\\Reset.jpg";
	drawMenuItemImages[ITM_StartRecording] = "images\\MenuItems\\StartRecording.jpg";
	drawMenuItemImages[ITM_StopRecording] = "images\\MenuItems\\StopRecording.jpg";
	drawMenuItemImages[ITM_PlayRecording] = "images\\MenuItems\\PlayRecording.jpg";
	drawMenuItemImages[ITM_Save] = "images\\MenuItems\\Save.jpg";
	drawMenuItemImages[ITM_Load] = "images\\MenuItems\\Load.jpg";
	drawMenuItemImages[TO_PLAY] = "images\\MenuItems\\SwitchtoPlayMode.jpg";
	drawMenuItemImages[ITM_Black] = "images\\MenuItems\\Black.jpg";
	drawMenuItemImages[ITM_Red] = "images\\MenuItems\\Red.jpg";
	drawMenuItemImages[ITM_Blue] = "images\\MenuItems\\Blue.jpg";
	drawMenuItemImages[ITM_Green] = "images\\MenuItems\\Green.jpg";
	drawMenuItemImages[ITM_Yellow] = "images\\MenuItems\\Yellow.jpg";
	drawMenuItemImages[ITM_Orange] = "images\\MenuItems\\Orange.jpg";
	drawMenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";
	drawMenuItemImages[ITM_SELECT] = "images\\MenuItems\\select.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(drawMenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{

	UI.InterfaceMode = MODE_PLAY;
	string playMenuItemImages[PLAY_ITM_COUNT];
	playMenuItemImages[ITM_PickbyFigure] = "images\\MenuItems\\PickbyFigure.jpg";
	playMenuItemImages[ITM_PickbyColour] = "images\\MenuItems\\PickbyColour.jpg";
	playMenuItemImages[ITM_PickbyFigure_colour] = "images\\MenuItems\\PickbyFigure_colour.jpg";
	playMenuItemImages[TO_DRAW] = "images\\MenuItems\\SwitchtoDrawMode.jpg";
	playMenuItemImages[ITM_EXITT] = "images\\MenuItems\\Menu_Exit.jpg";


	//Clear tool bar by drawing a filled white rectangle

	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);


	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(playMenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

void Output::SetCrntDrawColor(color clr) const
{
	UI.DrawColor = clr;
}

void Output::SetCrntFillColor(color clr) const
{
	
	UI.FillColor = clr;
}


//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

 //drawing a rectangle

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);


}


// drawing a square

void Output::Drawsquare(Point P, GfxInfo sqrGfxInfo, bool selected) const
{
	Point P1;
	Point P2;
	int side = 70;
	P1.x = P.x - side;
	P1.y = P.y - side;
	P2.x = P.x + side;
	P2.y = P.y + side;
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = sqrGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (sqrGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(sqrGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);


}

//drawing a triangle

void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}

//drawing a circle 

void Output::Drawcircle(Point P1, Point P2, GfxInfo circGfxInfo, bool selected) const
{
	color DrawingClr;
	const double radius = pow((pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2)), 0.5);
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = circGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (circGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(circGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawCircle(P1.x, P1.y, radius, style);

}

//drawing a hexagon

void Output::Drawhexagon(Point P, GfxInfo hexGfxInfo, bool selected) const
{
	int side = 100;
	Point P1, P2, P3, P4, P5, P6;

	// top left point
	P1.x = P.x - (sqrt(3) / 2) * side;
	P1.y = P.y - 0.5 * side;

	// bottom left point
	P2.x = P.x - (sqrt(3) / 2) * side;
	P2.y = P1.y + side;


	// bottom point
	P3.x = P.x;
	P3.y = P.y + side;

	//  bottom right point 
	P4.x = P.x + (sqrt(3) / 2) * side;
	P4.y = P.y + 0.5 * side;

	// top right point 
	P5.x = P.x + (sqrt(3) / 2) * side;
	P5.y = P.y - 0.5 * side;

	// top  point 
	P6.x = P.x;
	P6.y = P.y - side;


	color DrawingClr;
	const int arrx[6] = { P1.x,P2.x,P3.x,P4.x,P5.x, P6.x };
	const int arry[6] = { P1.y,P2.y,P3.y,P4.y,P5.y, P6.y };
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = hexGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (hexGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(hexGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawPolygon(arrx, arry, 6, style);

}





//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}
