
#include "Action.h"
	class PlayRecord : public Action
	{
	private:
		ActionType RecordStatus;
		int order;
	public:



		PlayRecord(ApplicationManager* pApp);

		virtual void ReadActionParameters();

		virtual void Execute();
	};






