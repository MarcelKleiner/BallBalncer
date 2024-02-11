#include "../Taskhandler/Taskhandler.h"

#ifndef SRC_APPMAIN_APPLICATIONMAIN_H_
#define SRC_APPMAIN_APPLICATIONMAIN_H_

class ApplicationMain
{
	public:
		ApplicationMain();

		void StartUp();
		void Main();


		Taskhandler taskhandler = Taskhandler();
	private:



};

#endif /* SRC_APPMAIN_APPLICATIONMAIN_H_ */
