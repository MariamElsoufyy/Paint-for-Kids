#pragma once
#include "Action.h"
class ChangeDrawColorAction :public Action
{

	
private:
		 
		CFigure* selected;
		ActionType acttype;
		ActionType record;
		color clr;
public:
	ChangeDrawColorAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
	};

