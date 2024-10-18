#pragma once
#include "Action.h"
class ChangeFillColorAction :public Action
{


	private:

		CFigure* selected;
		ActionType acttype;
		ActionType record;
		color clr;
	public:
		ChangeFillColorAction(ApplicationManager* pApp);

		//Reads rectangle parameters
		virtual void ReadActionParameters();

		//Add rectangle to the ApplicationManager
		virtual void Execute();
	};



