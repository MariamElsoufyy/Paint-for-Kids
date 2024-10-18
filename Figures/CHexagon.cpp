#include "CHexagon.h"

CHexagon::CHexagon(Point P, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	
	Center = P;
	Type = "HEX";
}
CHexagon::CHexagon()
{

}
void CHexagon::Draw(Output* pOut) const
{
	pOut->Drawhexagon(Center, FigGfxInfo, Selected);
}

bool CHexagon::checkPoint(int x, int y) const
{
	Point P1;
	P1.x = Center.x - (sqrt(3) / 2) * 100;
	P1.y = Center.y - 0.5 * 100;
	const double radius = pow((pow(Center.x - P1.x, 2) + pow(Center.y - P1.y, 2)), 0.5);
	const double Dis = pow((pow(Center.x - x, 2) + pow(Center.y - y, 2)), 0.5);
	if (Dis <= radius)
		return true;
	else
		return false;
}


void CHexagon::Save(ofstream& OutFile)
{
	OutFile << Type << " " << ID << " " << Center.x << " " << Center.y << " ";
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
void CHexagon::Load(ifstream& InFile, Output* pOut)
{
	this->SetSelected(0);
	string DrwClr, Fillclr;
	int center1, center2, borderwidth;
	InFile >> ID >> center1 >> center2 >> borderwidth;
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
	FigGfxInfo.BorderWdth = borderwidth;

	Draw(pOut);
}
void CHexagon::PrintFigData(Output* pOut) const
{
	string Drwclr, fillclr, IDD, Side, cx, cy;
	IDD = to_string(ID);
	Side = to_string(70);
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
		
	}else 
			fillclr = "NO_FILL";
	pOut->PrintMessage(Type + " " + IDD + " Center :" + cx + " " + cy + " Side :" + Side + " Draw Color " + Drwclr + " Fill Color " + fillclr);
	Sleep(4000);
	pOut->ClearStatusBar();
}
void CHexagon::Move(Point PP)
{

		Center = PP;
	

}
string CHexagon::GetType() const
{
	return Type;
}
void CHexagon::Select(Output* pOut)
{
	Selected=1;
	Draw(pOut);
}
void CHexagon::unSelect(Output* pOut)
{
	Selected = 0;
	Draw(pOut);
}
;


