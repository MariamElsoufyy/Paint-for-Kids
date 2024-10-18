#include "SaveAction.h"
#include <fstream>
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include<string>
#include"..\ApplicationManager.h"

SaveAction::SaveAction(ApplicationManager* pApp) :Action(pApp)
{
}

void SaveAction::ReadActionParameters()
{
	int x, y;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Saving the file , Please enter the name of the file");
	filename = pIn->GetSrting(pOut); 
	pOut->PrintMessage("file name is "+ filename);
	Sleep(1000);
}
void SaveAction::Execute()
{
	color draw, fill;
	int c;
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	ofstream OutFile(filename, ios::out);
	pManager->GetCrntData(draw, fill, c);
	if (draw == RED)
		OutFile << "RED" << " ";
	if (draw == ORANGE)
		OutFile << "ORANGE" << " ";
	if (draw == YELLOW)
		OutFile << "YELLOW" << " ";
	if (draw == GREEN)
		OutFile << "GREEN" << " ";
	if (draw == BLUE)
		OutFile << "BLUE" << " ";
	if (draw == BLACK)
		OutFile << "BLACK" << " ";


		if (fill == RED)
			OutFile << "RED";
		else if  (fill == ORANGE)
			OutFile << "ORANGE";
		else if (fill == YELLOW)
			OutFile << "YELLOW";
		else if (fill == GREEN)
			OutFile << "GREEN";
		else if (fill == BLUE)
			OutFile << "BLUE";
		else if (fill == BLACK)
			OutFile << "BLACK";
	    else
		OutFile << "NO_FILL";

	OutFile << endl;
	OutFile << c << endl;
	

	pManager->SaveAll(OutFile);
	OutFile.close();
	pOut->PrintMessage("File Saved");
	Sleep(1000);
	pOut->ClearStatusBar();
}