#include "SelecttAction.h"
SelecttAction::SelecttAction(ApplicationManager* pApp) :Action(pApp)
{
	Check = 0;
	Selectedfigure = NULL;
}

void SelecttAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select figure");

	
	pIn->GetPointClicked(px, py);
	pOut->ClearStatusBar();

}





void SelecttAction::Execute()
{   
	PreviousSelection = NULL;
	ReadActionParameters();

	if (Selectedfigure != NULL) 
	{
		PreviousSelection = Selectedfigure;

	}

	Selectedfigure = pManager->GetFigure(px, py);
	Output* pOut = pManager->GetOutput();


	if (Selectedfigure != NULL && PreviousSelection != NULL)
	{
		Check = Selectedfigure->IsSelected();

		if (Check == true)
		{
			Selectedfigure->unSelect(pOut);
			Selectedfigure = NULL;
			PreviousSelection = NULL;
		}
		else if (Check == false)
		{
			PreviousSelection = NULL;
			Selectedfigure->Select(pOut);
			pManager->Select(Selectedfigure);
			Selectedfigure->PrintFigData(pOut);


		}
	}
	else if (Selectedfigure == NULL && PreviousSelection == NULL)
	{

		pOut->PrintMessage("Error !!! select a figure");
		pManager->UnSelect();

	}
	else if (Selectedfigure != NULL && PreviousSelection == NULL)
	{

		Selectedfigure->Select(pOut);
		pManager->Select(Selectedfigure);
		Selectedfigure->PrintFigData(pOut);

	}

	pManager->SetLastSelectedPoint(px, py);

};
