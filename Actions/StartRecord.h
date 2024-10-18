#pragma once
#include "Action.h"
class StartRecord: public Action
{
	private:
		Action* RAction;
		string deletefactor;
		int count;
	public:



		StartRecord(ApplicationManager* pApp);

		virtual void ReadActionParameters();

		virtual void Execute();
	};


