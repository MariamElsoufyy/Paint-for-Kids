#include "StartRecord.h"

StartRecord::StartRecord(ApplicationManager* pApp) :Action(pApp)
{ 
}

void StartRecord::ReadActionParameters()
{
	RAction = pManager->gettobeRecordedAction();
	deletefactor = pManager->GetDeleteFactor();
	
}

void StartRecord::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();

		
	if (deletefactor == "true")
	{
		pManager->DeleteRecord();
		
		pOut->PrintMessage("Started Recording");
		Sleep(1000);
	}
	pManager->RecordthisAction(RAction);
}
