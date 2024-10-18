//WAHDAN

#include "AddSqrAction.h"
#include "..\Figures\CSquare.h"

#include"..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddSqrAction::AddSqrAction(ApplicationManager* pApp) :Action(pApp)
{}
void AddSqrAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at the Center");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	SqrGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SqrGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}
//Execute the action
void AddSqrAction::Execute()
{
	record = pManager->getRecordStatus();
	if (record != PlayRecording)
		ReadActionParameters();
	//Create a Square with the parameters read from the user
	CSquare* S = new CSquare(P1, SqrGfxInfo);

	//Add the Square to the list of figures
	pManager->AddFigure(S);
}

//WAHDAN