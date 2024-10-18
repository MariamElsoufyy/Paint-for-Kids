#include "ChangeDrawColorAction.h"

ChangeDrawColorAction::ChangeDrawColorAction(ApplicationManager* pApp) :Action(pApp)
{  
}

void ChangeDrawColorAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	selected = pManager->GetSelectedFig();
	pOut->PrintMessage("Please Select a draw colour");
	acttype=pIn->GetUserAction();

	
}

void ChangeDrawColorAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (selected == NULL)
	{
		pOut->PrintMessage("Cannot Change Colour , Please Select a Figure First");
		return;

	}

	pOut->PrintMessage("Changing Draw Colour ");
	if (record != PlayRecording)
		pOut->PrintMessage("Changing Fill Colour ");

	if (acttype == Red)
	{
		clr = RED;


	}
	else if (acttype == Orange)
	{
		clr = ORANGE;
	}
	else if (acttype == Yellow)
	{
		clr = YELLOW;
	}
	else if (acttype == Green)
	{
		clr = GREEN;
	}
	else if (acttype == Blue)
	{
		clr = BLUE;
	}
	else if (acttype == Black)
	{
		clr = BLACK;
	}
	
	else
	{
		pOut->PrintMessage("Cannot Change Colour , Please Select a  Draw colour First");
		return;
	}

	selected->ChngDrawClr(clr);
	pOut->SetCrntDrawColor(clr);

	selected->SetSelected(0);
	selected->Draw(pOut);

	pManager->UnSelect();

}
