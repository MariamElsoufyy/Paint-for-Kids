//WAHDAN

#ifndef ADD_Tri_ACTION_H
#define ADD_Tri_ACTION_H

#include "Action.h"

//Add Triangle Action class
class AddTriAction : public Action
{
private:
	Point P1, P2, P3; //Triangle Corners
	GfxInfo TriGfxInfo;
	ActionType record;
public:
	AddTriAction(ApplicationManager* pApp);

	//Reads Triangle parameters
	virtual void ReadActionParameters();

	//Add Triangle to the ApplicationManager
	virtual void Execute();
};
#endif

//WAHDAN