#include "PlayRecord.h"

PlayRecord::PlayRecord(ApplicationManager* pApp) :Action(pApp)
{
}

void PlayRecord::ReadActionParameters()
{
	RecordStatus= pManager->getRecordStatus();
	 order=pManager->getRecordOrder();
}

void PlayRecord::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	if (RecordStatus == StartRecording &&order!=0)
	{
		pOut->PrintMessage("stop recording First");
		return;
	}
	else if ((RecordStatus == StartRecording || RecordStatus ==none) && order == 0)
	{
		pOut->PrintMessage("Nothing to play");
		Sleep(500);
		return;
	}
	else if(RecordStatus == StopRecording && order == 0)
	{
		
		pOut->PrintMessage("No Record started");
		Sleep(500);
		return;
		

	}
	else if (RecordStatus == PlayRecording && order != 0)
	{
		pManager->appClearAll();
		pOut->ClearDrawArea();
		pOut->PrintMessage("Playing record");
		Sleep(500);
		Action* nextaction;
		for ( int i = 1;  i < order;  i++)
		{
			nextaction= pManager->GetRecordedAction(i);
			if (nextaction != NULL)
				pManager->ExecuteRecordedAction(nextaction);
			Sleep(1000);
		}
		
	}

}
