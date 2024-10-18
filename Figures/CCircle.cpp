#include "CCircle.h"
#include<String>
#include <fstream>
CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	
	Center = P1;
	P = P2;
	Type = "CIRCLE";

}
CCircle::CCircle()
{
}
void CCircle::Draw(Output* pOut) const
{
	
	pOut->Drawcircle(Center, P, FigGfxInfo, Selected);
}
void CCircle::Save(ofstream& OutFile)
{
	OutFile << Type << " " << ID << " " << Center.x << " " << Center.y << " "<<P.x <<" " << P.y<<" ";
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
void CCircle::Load(ifstream& InFile, Output* pOut)
{
	this->SetSelected(0);
	string DrwClr, Fillclr;
	int center1, center2, px, py, borderwidth;
		InFile >> ID >> center1 >> center2 >> px >> py>>borderwidth;
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
			FigGfxInfo.DrawClr = BLACK;
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
			FigGfxInfo.isFilled = false;
		}

		
		Center.x = center1;
		Center.y = center2;
		P.x = px;
		P.y = py;

		
		FigGfxInfo.BorderWdth = borderwidth;
		Draw(pOut);

}
//omar//
bool CCircle::checkPoint(int x, int y) const
{
	const double radius = pow((pow(Center.x - P.x, 2) + pow(Center.y - P.y, 2)), 0.5);
	const double Dis = pow((pow(Center.x - x, 2) + pow(Center.y - y, 2)), 0.5);
	if (Dis <= radius)
		return true;
	else
		return false;
}
//omar//;
void CCircle::PrintFigData(Output* pOut) const
{
	string Drwclr, fillclr, IDD, Radius, cx, cy;
	IDD = ID;
	Radius = to_string(pow((pow(Center.x - P.x, 2) + pow(Center.y - P.y, 2)), 0.5));
	cx = to_string(Center.x);
	cy = to_string(Center.y);


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
	pOut->PrintMessage(Type + " " + IDD + " Center :" + cx + " " + cy + " Radius :" + Radius + " Draw Color " + Drwclr + " Fill Color " + fillclr);
	Sleep(3000);
	pOut->ClearStatusBar();
}

void CCircle::Select(Output* pOut)
{
	Selected = 1;
	Draw(pOut);
}

	void CCircle::Move(Point PP)
	{
		const double radius = pow((pow(Center.x - P.x, 2) + pow(Center.y - P.y, 2)), 0.5);
		Center = PP;
		P = PP;
		P.y = PP.y+ radius;

		
	}

	void CCircle::unSelect(Output* pOut)
	{
		Selected = 0;
		Draw(pOut);
	}
	string CCircle::GetType() const
	{
		return Type;
	}
;
