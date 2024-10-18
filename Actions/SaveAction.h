#include "Action.h"
#include <fstream>
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include<string>
#include "..\Figures\CRectangle.h"
#include "..\ApplicationManager.h"
class SaveAction : public Action
{
	string filename;
public:
	SaveAction(ApplicationManager* pApp);
	virtual void Execute();
	virtual void ReadActionParameters();

	
};