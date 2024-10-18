#include "CLearAll.h"

#include "..\ApplicationManager.h"
#include "..\Figures\CRectangle.h"
CLearAll::CLearAll(ApplicationManager* pApp) :Action(pApp)
{
}

void CLearAll::ReadActionParameters()
{

}

void CLearAll::Execute()
{

	Output* pOut = pManager->GetOutput();



	pOut->ClearDrawArea();
	pOut->ClearStatusBar();
	pManager->appClearAll();
	pOut->PrintMessage("All Cleared");
	Sleep(2000);
	pOut->ClearStatusBar();
}