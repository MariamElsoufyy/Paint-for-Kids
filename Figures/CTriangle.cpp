
#include "CTriangle.h"
#include "../Actions/Action.h"


CTriangle::CTriangle(Point P1, Point P2,Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	Type = "TRIANG";
}
CTriangle::CTriangle()
{

}
void CTriangle::Draw(Output* pOut) const
{
		
	pOut->DrawTri(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}
void CTriangle::Save(ofstream& OutFile)
{

	OutFile << Type << " " << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << Corner3.x << " " << Corner3.y << " ";
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
void CTriangle::Load(ifstream& InFile, Output* pOut)
{
	this->SetSelected(0);
	string DrwClr, Fillclr;
	int p1x, p1y, p2x, p2y,p3x,p3y, borderwidth;
	InFile >> ID >> p1x >> p1y >> p2x >> p2y >> p3x>>p3y>> borderwidth;
	InFile >> DrwClr >> Fillclr;
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
		Sleep(1000);
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
		Sleep(1000);
		pOut->ClearStatusBar();
		return;
	}


	
	Corner1.x = p1x;
	Corner1.y = p1y;
	Corner2.x = p2x;
	Corner2.y = p2y;
	Corner3.x = p3x;
	Corner3.y = p3y;
	FigGfxInfo.BorderWdth = borderwidth;
	Draw(pOut);
}
bool CTriangle::checkPoint(int x, int y) const
{
	// coordinate of the vertices


	// Formula to calculate centroid
	int CenterX = (Corner1.x + Corner2.x + Corner3.x) / 3;

	int CenterY = (Corner1.y + Corner2.y + Corner3.y) / 3;

	//IF CONDITION//

	
	/// logic was too complicated 
	

	return 0;
}
void CTriangle::Move(Point PP)
{
}
void CTriangle::PrintFigData(Output* pOut) const
{
	string Drwclr, fillclr, IDD, side1, side2, side3 ,c1x, c1y, c2x, c2y,c3x,c3y;
	IDD = ID;
	side1 = to_string(pow((pow(Corner1.x - Corner2.x, 2) + pow(Corner1.y - Corner2.y, 2)), 0.5));
	side2 = to_string(pow((pow(Corner2.x - Corner3.x, 2) + pow(Corner2.y - Corner3.y, 2)), 0.5));
	side3= to_string(pow((pow(Corner1.x - Corner3.x, 2) + pow(Corner1.y - Corner3.y, 2)), 0.5));
	c1x = to_string(Corner1.x);
	c1y = to_string(Corner1.y);
	c2x = to_string(Corner2.x);
	c2y = to_string(Corner2.y);
	c3x = to_string(Corner3.x);
	c3y = to_string(Corner3.y);
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
			fillclr = "ORANGE";
		if (FigGfxInfo.FillClr == YELLOW)
			fillclr = "YELLOW";
		if (FigGfxInfo.FillClr == GREEN)
			fillclr = "GREEN";
		if (FigGfxInfo.FillClr == BLUE)
			fillclr = "BLUE";
		if (FigGfxInfo.FillClr == BLACK)
			fillclr = "BLACK";
		
	}
	else
		fillclr = "NO_FILL";
	pOut->PrintMessage(Type + " " + IDD + " Corner 1 :" + c1x + " " + c1y + " Corner 2 :" + c2x + " " + c2y + " Corner 3 :" + c3x + " " + c3y + " Side 1 :" + side1 + " Side 2 : " + side2 + " Side 3 :" + side3 + " Draw Color " + Drwclr + " Fill Color " + fillclr);
	Sleep(1000);
	pOut->ClearStatusBar();
}
void CTriangle::Select(Output* pOut)
{
	Selected = 1;
	Draw(pOut);
}
void CTriangle::unSelect(Output* pOut)
{
	Selected = 0;
	Draw(pOut);
}
string CTriangle::GetType() const
{
	return Type;
}
;


