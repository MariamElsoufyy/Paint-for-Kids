//WAHDAN

#include "AddHexAction.h"

#include "..\Figures\CHexagon.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddHexAction::AddHexAction(ApplicationManager* pApp):Action(pApp)
{}

void AddHexAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at Center");

	//Read center and store in point P1
	pIn->GetPointClicked(Center.x, Center.y);


	HexGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddHexAction::Execute()
{
	record = pManager->getRecordStatus();
	if (record != PlayRecording)
		ReadActionParameters();


	//Create a hexagon with the parameters read from the user
	CHexagon* H = new CHexagon(Center, HexGfxInfo);

	//Add the Hexagon to the list of figures
	pManager->AddFigure(H);
}

//WAHDAN