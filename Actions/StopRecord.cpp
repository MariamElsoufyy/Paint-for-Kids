#include "StopRecord.h"

StopRecord::StopRecord(ApplicationManager* pApp) :Action(pApp)
{
}

void StopRecord::ReadActionParameters()
{
	RecordStatus = pManager->getRecordStatus();
}

void StopRecord::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	if (RecordStatus != StartRecording)
	{
		pOut->PrintMessage("start recording First");
		Sleep(500);
		return;
	}
	else if (RecordStatus == StartRecording )
	{
		pOut->PrintMessage("Stopped Recording");
		Sleep(500);
		return;
	}
	
	}
