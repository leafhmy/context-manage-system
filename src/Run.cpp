#include "Run.h"

Run::Run()
{
	windowsHelper->setColor(3);
	fac = new Factory();
	windowsFac =  fac->getWindowsFactory();
	windowsHelper = windowsFac->getInstance();
	windowsHelper->setWindowsAttribute(50, "通信录管理系统");
	interfaceFactory = fac->getInterfaceFactory();

}

Run::~Run()
{
	delete fac;
}

void Run::start()
{
	shared_ptr<Interface> mainInterface = interfaceFactory->getInstance_shared(e_MainInterface);
	mainInterface->show();
	shared_ptr<GetSelectionFactory> getSelecFac = fac->getSelectionFactory();
	shared_ptr<GetSelection> getSelec = getSelecFac->getInstance_shared(e_GetMainInterfaceSelection);
	int key = getSelec->Select();
	shared_ptr<ContextFactory> ctxFac = fac->getContextFactory();
	shared_ptr<Context> mainInterfaceReaction = ctxFac->getInstance_shared(e_MainInterfaceReaction);
	mainInterfaceReaction->reactToSelection(key);
	
}



