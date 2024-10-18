#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"



#include "..\GUI\input.h"
#include "..\GUI\Output.h"
class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	
	
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	CRectangle();
	virtual void Draw(Output* pOut) const;


	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& InFile, Output* pOut);

	virtual bool checkPoint(int x, int y) const;
	virtual void Move(Point PP);
	void PrintFigData(Output* pOut) const;

	virtual void Select(Output* pOut);
	virtual void unSelect(Output* pOut);

	virtual string GetType() const;

};

#endif