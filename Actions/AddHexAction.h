//WAHDAN

#ifndef ADD_HEX_ACTION_H
#define ADD_HEX_ACTION_H

#include "Action.h"

//Add Hexagon Action class
class AddHexAction : public Action
{
private:
	Point Center; //Hexagon Center
	GfxInfo HexGfxInfo;
	ActionType record;
public:
	AddHexAction(ApplicationManager* pApp);

	//Reads Hexagon parameters
	virtual void ReadActionParameters();

	//Add Hexagon to the ApplicationManager
	virtual void Execute();
};
#endif

//WAHDAN