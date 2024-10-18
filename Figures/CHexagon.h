#ifndef CHEX_H
#define CHEX_H
#include "CFigure.h"
class CHexagon : public CFigure
{
private:
	Point Center;
	double r;
public:
	CHexagon(Point P, GfxInfo FigureGfxInfo);
	CHexagon();
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

