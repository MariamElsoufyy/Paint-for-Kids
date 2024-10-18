#include "Action.h"
#include <fstream>
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include<string>
#include "..\Figures\CRectangle.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CTriangle.h"
#include "..\ApplicationManager.h"
class LoadAction : public Action
{
	string filename;
public:
	LoadAction(ApplicationManager* pApp);
	void ReadActionParameters();
    void Execute();
};

