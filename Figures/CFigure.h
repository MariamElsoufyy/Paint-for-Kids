#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <string>
#include <fstream>
#include<cstdlib>
#include <Windows.h>
//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	string Type;
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	CFigure();
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(Output* pOut) const = 0;		//Draw the figure

	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	void UnFill();
	virtual bool checkPoint(int x, int y) const=0;

	virtual void PrintFigData(Output* pOut) const = 0;
	virtual void Move(Point PP) = 0;
	virtual void Select(Output* pOut)=0;
	virtual void unSelect(Output* pOut) = 0;
	virtual string GetType() const = 0;
	virtual void Save(ofstream& OutFile) = 0;
	virtual void Load(ifstream& InFile, Output* pOut) = 0;
};
#endif