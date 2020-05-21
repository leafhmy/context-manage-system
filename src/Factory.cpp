#include "Factory.h"

shared_ptr<Interface> InterfaceFactory::getInstance_shared(e_Interface e_face)
{
	switch (e_face)
	{
	case e_MainInterface:
	{
		face = shared_ptr<Interface>(new MainInterface());
	}
	default:
		break;
	}

	return face;
}



shared_ptr<WindowsHelper> WindowsFactory::getInstance()
{
	helper = shared_ptr<WindowsHelper>(new WindowsHelper());
	return helper;
}



shared_ptr<InterfaceFactory> Factory::getInterfaceFactory()
{
	return  shared_ptr<InterfaceFactory>(new InterfaceFactory());
}

shared_ptr<WindowsFactory> Factory::getWindowsFactory()
{
	return shared_ptr<WindowsFactory>(new WindowsFactory());
}