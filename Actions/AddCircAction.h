//WAHDAN

#ifndef ADD_Circ_ACTION_H
#define ADD_Circ_ACTION_H

#include "Action.h"

//Add Circle Action class
class AddCircAction : public Action
{
private:
	Point Center, P;
	GfxInfo CircGfxInfo;
	ActionType record;
public:
	AddCircAction(ApplicationManager* pApp);

	//Reads Circle parameters
	virtual void ReadActionParameters();

	//Add Circle to the ApplicationManager
	virtual void Execute();
};
#endif

//WAHDAN