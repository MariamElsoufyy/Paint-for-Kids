
#include "Action.h"
	class StopRecord : public Action
	{
	private:
		ActionType RecordStatus;
	
	public:



		StopRecord(ApplicationManager* pApp);

		virtual void ReadActionParameters();

		virtual void Execute();
	};



