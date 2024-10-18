#pragma once

#include "Action.h"
class SelecttAction :public Action
{
private:
	int px, py;
	CFigure* Selectedfigure;
	CFigure* PreviousSelection;
	bool Check;

public:

	SelecttAction(ApplicationManager* pApp);


	virtual void ReadActionParameters();


	virtual void Execute();



};
///omar///
