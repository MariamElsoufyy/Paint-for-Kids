#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\SaveAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\AddCircAction.h"
#include "Actions\AddSqrAction.h"
#include "Actions\LoadAction.h"
#include "Actions\AddHexAction.h"
#include "Actions\ClearAll.h"
#include "Actions\SelecttAction.h"
#include "Actions\ChangeDrawColorAction.h"
#include "Actions\ChangeFillColorAction.h"
#include "Actions\MoveAction.h"
#include "Actions\DelAction.h"
#include "Actions\StartRecord.h"
#include "Actions\PlayRecord.h"
#include "Actions\StopRecord.h"
#include "Actions\Action.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	DeleteFactor = "true";
	FigCount = 0;
	recordOrder = 0;
	SelectedFig = NULL;
	actiontoberecorded = NULL;
	store = none;
	record = none;
	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
	for (int i = 1; i < 20; i++)
	{
		recordArray[i]=NULL;

	}

}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	Action* pRecord = NULL;
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;
	case DRAW_TRI:
		pAct = new AddTriAction(this);
		break;
	case DRAW_CIRCLE:
		pAct = new AddCircAction(this);
		break;
	case DRAW_SQUARE:
		pAct = new AddSqrAction(this);
		break;
	case DRAW_HEXAGON:
		pAct = new AddHexAction(this);
		break;
	case Save:
		pAct = new SaveAction(this);
		break;
	case Load:
		pAct = new LoadAction(this);
		break;
	case Selectt:
		pAct = new SelecttAction(this);
		break;
	case Reset:
		pAct = new CLearAll(this);
		record = none;
		DeleteFactor = "true";
		store = none;
		break;
	case MoveFigure:
		pAct = new MoveAction(this);
		break;
	case ChangeDrawingColour:
		pAct = new ChangeDrawColorAction(this);
		break;
	case ChangeFillingColour:
		pAct = new ChangeFillColorAction(this);
		break;
	case DeleteFigure:
		pAct = new DelAction(this);
		break;
	case DRAWING_AREA:
		UnSelect();
		break;
	case StartRecording:
		record = StartRecording;
		break;
	case StopRecording:
		store = record;
		record = StopRecording;
		break;
	case PlayRecording:
		if (record == StartRecording || record == none)
			store = record;
		else if (record = StopRecording)
		{
			store = PlayRecording;
			record = none;
		}
		pAct = new PlayRecord(this);
		break;
	case SwitchtoDrawMode:
		
		pOut->CreateDrawToolBar();
		break;

	case SwitchtoPlayMode:
		
		pOut->CreatePlayToolBar();
		break;
	case EXIT:
		///create ExitAction here

		break;

	case STATUS:	//a click on the status bar ==> no action
		return;


	}
	if (record == StartRecording)
	{
		pRecord = new StartRecord(this);

	}
	else if (record == StopRecording)
	{
		pRecord = new StopRecord(this);
	}
	if (ActType != StartRecording && ActType != StopRecording && ActType != PlayRecording && ActType != Save && ActType != Load && ActType != EXIT)
	{
		actiontoberecorded = pAct;
	}


	//Execute the created action & Record it
	if (pAct != NULL)
	{
		pAct->Execute();//Execute

		pAct = NULL;
	}
	if (pRecord != NULL)
	{

		pRecord->Execute();//Execute
		if (record == StartRecording)
		{
			DeleteFactor = "false";

		}
		else if (record == StopRecording)
		{
			DeleteFactor = "true";

		}

		delete pRecord;
		pRecord = NULL;
	}
}

//==================================================================================//
//						Record  Function								//
//==================================================================================//

string ApplicationManager::GetDeleteFactor()
{
	return DeleteFactor;

}
//wahdan
void ApplicationManager::ExecuteRecordedAction(Action* act)
{
	act->Execute();
}
//wahdan
int ApplicationManager::GetIndex(CFigure* Fig)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (Fig == (FigList[i]))
			return i;

	}

}

void ApplicationManager::DeleteRecord()
{

	for (int j = 0; j < 20; j++)
	{
		recordArray[j] = NULL;
	}
}
void ApplicationManager::RecordthisAction(Action* Act)
{
	if (recordOrder <= 20)
	{
		recordArray[recordOrder] = Act;
		recordOrder++;
	}
	else
	{
		for (int j = 0; j < 20; j++)
		{
			recordArray[j] = NULL;
		}
		recordOrder = 0;
		recordArray[recordOrder] = Act;
		recordOrder++;
	}

}

//omar

int ApplicationManager::getRecordOrder()
{
	return recordOrder;

}
//omar
Action* ApplicationManager::GetRecordedAction(int i)
{
	return recordArray[i];

}
ActionType ApplicationManager::getRecordStatus()
{
	return store;

}
Action* ApplicationManager::gettobeRecordedAction()
{
	return actiontoberecorded;

}
void ApplicationManager::RecClearAll()
{
	for (int i = 1; i < 20; i++)
	{ if (recordArray[i]!=NULL)
		delete recordArray[i];

	}


}
//==================================================================================//
//						Save  Function								//
//==================================================================================//

void ApplicationManager::SaveAll(ofstream& OutFile)
{

	for (int i = 0; i < MaxFigCount; i++)
	{
		if (FigList[i] != NULL)
		{
			FigList[i]->Save(OutFile);
		}
	}
}
//==================================================================================//
//						Reset Function							//
//==================================================================================//


void ApplicationManager::appClearAll()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;

}

void ApplicationManager::GetCrntData(color& draw,color&fill,int& c)
{
	c = FigCount;
	draw = pOut->getCrntDrawColor();
	fill = pOut->getCrntFillColor();
	

}



CFigure* ApplicationManager::GetSelectedFig()
{
	return SelectedFig;
}
CFigure* ApplicationManager::GetFigure(int x, int y)
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.


	SelectedFig = NULL;
	for (int i = 0; i < MaxFigCount; i++)
	{
		if (FigList[i] != NULL)
		{
			bool ch = FigList[i]->checkPoint(x, y);
			if (ch == true)
			{
				SelectedFig = FigList[i];
			}
		}
	}
	return SelectedFig;
}
void ApplicationManager::UnSelect()
{
	if (SelectedFig != NULL)
	{
		SelectedFig->unSelect(pOut);
	}
	SelectedFig = NULL;
}

void ApplicationManager::Select(CFigure* Fig)
{
	SelectedFig = Fig;
}



void ApplicationManager::SetLastSelectedPoint(int& x, int& y)
{
	Selectedpoint.x = x;
	Selectedpoint.y = y;
}
Point ApplicationManager::GetLastSelectedPoint()
{
	return Selectedpoint;
}
void ApplicationManager::DeleteSelectedFigure()
{
	int i;
	CFigure* selected = GetSelectedFig();


	if (SelectedFig != NULL)
	{
		i = GetIndex(selected);
		delete selected;

		for (int j = i; j < FigCount; j++)
		{
			FigList[j] = FigList[j + 1];
		}

		FigCount--;
	}
	SelectedFig = NULL;
}

//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}

int ApplicationManager::GetID() const
{

	for (int i = MaxFigCount - 1; i >= 0; i--)
	{
		if (FigList[i] != NULL)
			return i;

	}


}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
