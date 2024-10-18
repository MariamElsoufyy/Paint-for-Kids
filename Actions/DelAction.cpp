#include "DelAction.h"
#include"..\ApplicationManager.h"
DelAction::DelAction(ApplicationManager* pApp):Action(pApp)
{
}

void DelAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Deleting a Figure");
	Selected = pManager->GetSelectedFig();


	pOut->ClearStatusBar();
}

void DelAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();

	if (Selected == NULL)
	{
		pOut->PrintMessage("Cannot Delete , Please Select A figure First");
		return;
	}
	else
	{
		Selected->ChngDrawClr(LIGHTGOLDENRODYELLOW);
		Selected->ChngFillClr(LIGHTGOLDENRODYELLOW);
		Selected->unSelect(pOut);
		pManager->DeleteSelectedFigure();





	}
}
