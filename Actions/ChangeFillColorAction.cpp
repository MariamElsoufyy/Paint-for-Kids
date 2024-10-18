#include "ChangeFillColorAction.h"
ChangeFillColorAction::ChangeFillColorAction(ApplicationManager* pApp) :Action(pApp)
{
}

void ChangeFillColorAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	selected = pManager->GetSelectedFig();
	pOut->PrintMessage("Please Select a fill colour");
	acttype = pIn->GetUserAction();


}

void ChangeFillColorAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	record = pManager->getRecordStatus();
	if (record != PlayRecording)
		ReadActionParameters();
	if (selected == NULL)
	{
		pOut->PrintMessage("Cannot Change Colour , Please Select a Figure First");
		return;

	}
	if (record != PlayRecording)
		pOut->PrintMessage("Changing Fill Colour ");
	
	if (acttype == Red)
	{
		clr=RED;
	
		
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
		pOut->PrintMessage("Cannot Change Colour , Please Select a fill colour First");
		return;
	}
	selected->ChngFillClr(clr);
	pOut->SetCrntFillColor(clr);
	selected->Draw(pOut);
	selected->SetSelected(0);
	pManager->UnSelect();


}
