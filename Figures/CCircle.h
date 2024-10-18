#ifndef CCIRC_H
#define CCIRC_H
#include "CFigure.h"
class CCircle : public CFigure
{
private:
	Point Center;
	Point P;
    
public:
	CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo);
	CCircle();
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