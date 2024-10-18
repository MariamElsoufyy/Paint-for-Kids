#include "MoveAction.h"
MoveAction::MoveAction(ApplicationManager* pApp):Action(pApp)
{

}
void MoveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Choose a New Position");
	pIn->GetPointClicked(P.x, P.y);
	pOut->ClearStatusBar();
}

void MoveAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	CFigure* SelectedFig = pManager->GetSelectedFig();
	if (SelectedFig == NULL)
	{
		pOut->PrintMessage("Cannot Move, Please select a Figure");
	}
	else
	{
		string type = SelectedFig->GetType();
		if (type == "RECT")
		{
			CRectangle WillBeDeleted = dynamic_cast<CRectangle&>(*SelectedFig) ;

			WillBeDeleted.SetSelected(0);
			WillBeDeleted.ChngDrawClr(LIGHTGOLDENRODYELLOW);
			WillBeDeleted.ChngFillClr(LIGHTGOLDENRODYELLOW);
			WillBeDeleted.Draw(pOut);
		}
		else if (type == "TRIANG")
		{
			CTriangle WillBeDeleted = dynamic_cast<CTriangle&>(*SelectedFig);
			WillBeDeleted.SetSelected(0);
			WillBeDeleted.ChngDrawClr(LIGHTGOLDENRODYELLOW);
			WillBeDeleted.ChngFillClr(LIGHTGOLDENRODYELLOW);
			WillBeDeleted.Draw(pOut);
		}
		else if (type == "CIRCLE")
		{
			CCircle WillBeDeleted = dynamic_cast<CCircle&>(*SelectedFig);
			WillBeDeleted.SetSelected(0);
			WillBeDeleted.ChngDrawClr(LIGHTGOLDENRODYELLOW);
			WillBeDeleted.ChngFillClr(LIGHTGOLDENRODYELLOW);
			WillBeDeleted.Draw(pOut);
		}
		else if (type == "HEX")
		{
			CHexagon WillBeDeleted = dynamic_cast<CHexagon&>(*SelectedFig);
			WillBeDeleted.SetSelected(0);
			WillBeDeleted.ChngDrawClr(LIGHTGOLDENRODYELLOW);
			WillBeDeleted.ChngFillClr(LIGHTGOLDENRODYELLOW);
			WillBeDeleted.Draw(pOut);
		}
		else if (type == "SQUARE")
		{
			CSquare WillBeDeleted = dynamic_cast<CSquare&>(*SelectedFig);
			WillBeDeleted.SetSelected(0);
			WillBeDeleted.ChngDrawClr(LIGHTGOLDENRODYELLOW);
			WillBeDeleted.ChngFillClr(LIGHTGOLDENRODYELLOW);
			WillBeDeleted.Draw(pOut);
		}
		
		SelectedFig->Move(P);
		
		SelectedFig->SetSelected(0);
		SelectedFig->Draw(pOut);
		CFigure* BackFigure = NULL;
		last = pManager->GetLastSelectedPoint();
		
		do
		{
			BackFigure = pManager->GetFigure(last.x, last.y);
			if (BackFigure != NULL)
				BackFigure->Draw(pOut);

		} while (BackFigure != NULL);
	}
	pManager->UnSelect();
};