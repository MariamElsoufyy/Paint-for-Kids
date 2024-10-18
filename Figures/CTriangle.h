#ifndef CTRI_H
#define CTRI_H
#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo);
	CTriangle();
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
