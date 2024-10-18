#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	
	Corner1 = P1;
	Corner2 = P2;
	Type = "RECT";

	
}

CRectangle::CRectangle()
{
	

}

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

void CRectangle::Save(ofstream& OutFile)
{
	OutFile << Type << " " << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " ";
	OutFile << FigGfxInfo.BorderWdth << " ";
	
		if (FigGfxInfo.DrawClr == RED)
				OutFile << "RED" << " ";
		if (FigGfxInfo.DrawClr == ORANGE)
				OutFile << "ORANGE" << " ";
		if (FigGfxInfo.DrawClr == YELLOW)
				OutFile << "YELLOW" << " ";
		if (FigGfxInfo.DrawClr == GREEN)
				OutFile << "GREEN" << " ";
		if (FigGfxInfo.DrawClr == BLUE)
				OutFile << "BLUE" << " ";
		if (FigGfxInfo.DrawClr == BLACK)
				OutFile << "BLACK" << " ";

		if (FigGfxInfo.isFilled == true)
		{
			if (FigGfxInfo.FillClr == RED)
				OutFile << "RED";
			if (FigGfxInfo.FillClr == ORANGE)
				OutFile << "ORANGE";
			if (FigGfxInfo.FillClr == YELLOW)
				OutFile << "YELLOW";
			if (FigGfxInfo.FillClr == GREEN)
				OutFile << "GREEN";
			if (FigGfxInfo.FillClr == BLUE)
				OutFile << "BLUE";
			if (FigGfxInfo.FillClr == BLACK)
				OutFile << "BLACK";
		}

		if (FigGfxInfo.isFilled == false)
			OutFile << "NO_FILL";
		OutFile << endl;




}
void CRectangle::Load(ifstream& InFile, Output* pOut)
{
	this->SetSelected(0);
	string DrwClr, Fillclr;
	int p1x, p1y, p2x, p2y, borderwidth;
	InFile >> ID >> p1x >> p1y >> p2x >> p2y>> borderwidth;
	InFile>> DrwClr>>Fillclr;
	if (DrwClr == "RED")
		FigGfxInfo.DrawClr = RED;
	else if (DrwClr == "ORANGE")
		FigGfxInfo.DrawClr = ORANGE;
	else if (DrwClr == "YELLOW")
		FigGfxInfo.DrawClr = YELLOW;
	else if (DrwClr == "GREEN")
		FigGfxInfo.DrawClr = GREEN;
	else if (DrwClr == "BLUE")
		FigGfxInfo.DrawClr = BLUE;
	else if (DrwClr == "BLACK")
		FigGfxInfo.DrawClr = BLACK;
	else
	{
		pOut->PrintMessage("Error!!!!""Draw Colour isn't Available for figure With ID " + ID);
		Sleep(2000);
		pOut->ClearStatusBar();
		return;
	}


	if (Fillclr == "RED")
		FigGfxInfo.FillClr = RED;
	else if (Fillclr == "ORANGE")
		FigGfxInfo.FillClr = ORANGE;
	else if (Fillclr == "YELLOW")
		FigGfxInfo.FillClr = YELLOW;
	else if (Fillclr == "GREEN")
		FigGfxInfo.FillClr = GREEN;
	else if (Fillclr == "BLUE")
		FigGfxInfo.FillClr = BLUE;
	else if (Fillclr == "BLACK")
		FigGfxInfo.FillClr = BLACK;
	else if (Fillclr == "NO_FILL")
		FigGfxInfo.isFilled = false;
	else
	{
		pOut->PrintMessage("Error!!!! Fill Colour isn't Available With ID" + ID);
		Sleep(2000);
		pOut->ClearStatusBar();
		return;
	}

	
	Corner1.x = p1x;
	Corner1.y = p1y;
	Corner2.x = p2x;
	Corner2.y = p2y;
	FigGfxInfo.BorderWdth = borderwidth;
	Draw(pOut);


}
void CRectangle::PrintFigData(Output* pOut) const
{
	string Drwclr, fillclr, IDD, Width , Height ,c1x,c1y,c2x,c2y;
	IDD = ID;
	Width =(abs(Corner1.x - Corner2.x));
	Height = abs(Corner1.y - Corner1.y);
	
	c1x = Corner1.x;
	c1y = Corner1.y;
	c2x = Corner2.x;
	c2y = Corner2.y;

	if (FigGfxInfo.DrawClr == RED)
		Drwclr = "RED";
	if (FigGfxInfo.DrawClr == ORANGE)
		Drwclr = "ORANGE";
	if (FigGfxInfo.DrawClr == YELLOW)
		Drwclr = "YELLOW";
	if (FigGfxInfo.DrawClr == GREEN)
		Drwclr = "GREEN";
	if (FigGfxInfo.DrawClr == BLUE)
		Drwclr = "BLUE";
	if (FigGfxInfo.DrawClr == BLACK)
		Drwclr = "BLACK";

	if (FigGfxInfo.isFilled == true)
	{
		if (FigGfxInfo.FillClr == RED)
			fillclr = "RED";
		if (FigGfxInfo.FillClr == ORANGE)
			fillclr =  "ORANGE";
		if (FigGfxInfo.FillClr == YELLOW)
			fillclr = "YELLOW";
		if (FigGfxInfo.FillClr == GREEN)
			fillclr = "GREEN";
		if (FigGfxInfo.FillClr == BLUE)
			fillclr = "BLUE";
		if (FigGfxInfo.FillClr == BLACK)
			fillclr = "BLACK";
		
	}else
			fillclr = "NO_FILL";
	pOut->PrintMessage(Type + " " + IDD + " Corner 1 :" + c1x + " " + c1y + " Corner 2 :" + c2x + " " + c2y + " Width :" + Width + " Height : " + Height + " Draw Color " + Drwclr + " Fill Color " + fillclr);
		Sleep(3000);
		pOut->ClearStatusBar();
}
void CRectangle::Select(Output* pOut)
{
	Selected = 1;
	Draw(pOut);
}
void CRectangle::unSelect(Output* pOut)
{
	Selected = 0;
	Draw(pOut);
}
//omar//
bool CRectangle::checkPoint(int x, int y) const
{
	if ((x >= Corner1.x && x <= Corner2.x) || (x <= Corner1.x && x >= Corner2.x) && (y >= Corner1.y && y <= Corner2.y) || (y <= Corner1.y && y >= Corner2.y))
	{
		return true;
	}
	else
		return false;
}
void CRectangle::Move(Point PP)
{
	int length, width;

	length = abs(Corner1.x - Corner2.x);
	width = abs(Corner1.y - Corner2.y);

	Corner1.x = PP.x - length;
	Corner1.y = PP.y - width;
	Corner2.x = PP.x + length;
	Corner1.y = PP.y + width;
}
string CRectangle::GetType() const
{
	return Type;
}
;
//omar//;

