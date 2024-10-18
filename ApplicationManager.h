#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H
#include "Actions\Action.h"
#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Actions\Action.h"
class Action;
//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure

	//Pointers to Input and Output classes
	Input* pIn;
	Output* pOut;

	int recordOrder;
	ActionType record;
	Action* recordArray[20];
	Action* actiontoberecorded;
	Point Selectedpoint;
	string DeleteFactor;
	ActionType store;




public:



	ApplicationManager();
	~ApplicationManager();
	void DeleteSelectedFigure();



	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType); //Creates an action and executes it

	string GetDeleteFactor();

	void ExecuteRecordedAction(Action* act);




	int GetIndex(CFigure* Fig);

	// -- save and load functions
	void SaveAll(ofstream& OutFile);

	void DeleteRecord();

	void RecordthisAction(Action* Act);

	int getRecordOrder();

	Action* GetRecordedAction(int i);

	ActionType getRecordStatus();

	Action* gettobeRecordedAction();




	void appClearAll();

	void RecClearAll();

	void GetCrntData(color& draw, color& fill, int& c);





	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);//Adds a new figure to the FigList
	CFigure* GetSelectedFig();
	void UnSelect();
	void Select(CFigure* Fig);
	void SetLastSelectedPoint(int& x, int& y);
	Point GetLastSelectedPoint();
	CFigure* GetFigure(int x, int y); //Search for a figure given a point inside the figure


	// -- Interface Management Functions
	Input* GetInput() const; //Return pointer to the input
	Output* GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;
    int GetID() const;

};

#endif