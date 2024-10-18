#pragma once
#include "Action.h"

class CLearAll :public Action
{
private:
	ActionType record;
public:

	

	CLearAll(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};
