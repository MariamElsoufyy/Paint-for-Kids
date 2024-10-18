//WAHDAN

#include "AddCircAction.h"

#include "..\Figures\CCircle.h"

#include"..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCircAction::AddCircAction(ApplicationManager* pApp):Action(pApp)
{}

void AddCircAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at Center");

	//Read center and store in point Center
	pIn->GetPointClicked(Center.x, Center.y);

	pOut->PrintMessage("New Circle: Click at Point");

	//Read Point and store in point
	pIn->GetPointClicked(P.x, P.y);

	CircGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}
//Execute the action
void AddCircAction::Execute()
{
	record = pManager->getRecordStatus();
	if (record != PlayRecording)
	ReadActionParameters();

	//Create a Circle with the parameters read from the user
	CCircle* C = new CCircle(Center, P, CircGfxInfo);

	//Add the Circle to the list of figures
	pManager->AddFigure(C);
}

//WAHDAN