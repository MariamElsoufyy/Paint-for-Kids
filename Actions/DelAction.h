#pragma once
#include "Action.h"
class DelAction :public Action
{

	CFigure* Selected;
public:
	DelAction(ApplicationManager* pApp);



	virtual void ReadActionParameters();


	virtual void Execute();
};

