#include "LoadAction.h"
#include "SaveAction.h"
#include <fstream>
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include<string>
#include"..\ApplicationManager.h"


LoadAction::LoadAction(ApplicationManager* pApp) :Action(pApp)
{
}

void LoadAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("laoding a file , Please enter the name of the file");
	filename = pIn->GetSrting(pOut);
	
	
}
void LoadAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	ifstream inFile(filename, ios::in);

	if (!inFile.is_open())
	{
		pOut->PrintMessage("Couldn't find the File");
		Sleep(1000);
		pOut->ClearStatusBar();
		return;
	}
	else
	{
		string drwclr, fillclr, type;

		if (drwclr == "RED")
			pOut->SetCrntDrawColor(RED);
		else if (drwclr == "ORANGE")
			pOut->SetCrntDrawColor(ORANGE);
		else if (drwclr == "YELLOW")
			pOut->SetCrntDrawColor(YELLOW);
		else if (drwclr == "GREEN")
			pOut->SetCrntDrawColor(GREEN);
		else if (drwclr == "BLUE")
			pOut->SetCrntDrawColor(BLUE);
		else if (drwclr == "BLACK")
			pOut->SetCrntDrawColor(BLACK);
		else
		{
			pOut->SetCrntDrawColor(BLACK);
		}


		if (fillclr == "RED")
			pOut->SetCrntFillColor(RED);
		else if (fillclr == "ORANGE")
			pOut->SetCrntFillColor(ORANGE);
		else if (fillclr == "YELLOW")
			pOut->SetCrntFillColor(YELLOW);
		else if (fillclr == "GREEN")
			pOut->SetCrntFillColor(GREEN);
		else if (fillclr == "BLUE")
			pOut->SetCrntFillColor(BLUE);
		else if (fillclr == "BLACK")
			pOut->SetCrntFillColor(BLACK);
		
		int n;
		inFile >> drwclr >> fillclr >> n;
		CFigure* Fig;
		for (int i = 0; i < n; i++)
		{
			inFile >> type;
			if (type == "RECT")
			{
				Fig = new CRectangle;
				Fig->Load(inFile, pOut);
				pManager->AddFigure(Fig);
				Fig = NULL;
			}
			else if (type == "TRIANG")
			{
				Fig = new CTriangle;
				Fig->Load(inFile, pOut);
				pManager->AddFigure(Fig);
				Fig = NULL;
			}
			else if (type == "CIRCLE")
			{
				Fig = new CCircle;
				Fig->Load(inFile, pOut);
				pManager->AddFigure(Fig);
				Fig = NULL;
			}
			else if (type == "HEX")
			{
				Fig = new CHexagon;
				Fig->Load(inFile, pOut);
				pManager->AddFigure(Fig);
				Fig = NULL;
			}
			else if (type == "SQUARE")
			{
				Fig = new CSquare;
				Fig->Load(inFile, pOut);
				pManager->AddFigure(Fig);
				Fig = NULL;
			}
			else
			{
				pOut->PrintMessage("Error! couldn't Load Figure Number "+ n);
				Sleep(1000);
			}
		}

		inFile.close();
		pOut->PrintMessage("File Loaded");
		Sleep(1000);
		pOut->ClearStatusBar();
	}
}