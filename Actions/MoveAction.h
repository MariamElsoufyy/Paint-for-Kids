#pragma once
#include"../ApplicationManager.h"
#include"Action.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CTriangle.h"
class MoveAction : public Action
{
private:
	Point P;
	Point last;
public:
	MoveAction(ApplicationManager* pApp);
	
	virtual void ReadActionParameters();
	virtual void Execute();
};