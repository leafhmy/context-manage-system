#include "Factory.h"


shared_ptr<WindowsHelper> WindowsFactory::getInstance()
{
	helper = shared_ptr<WindowsHelper>(new WindowsHelper());
	return helper;
}



///////////////////////////////////////////////////////////////////////////////////



shared_ptr<Interface> InterfaceFactory::getInstance_shared(e_Interface e_face)
{
	switch (e_face)
	{
	case e_MainInterface:
		face = shared_ptr<MainInterface>(new MainInterface());
		break;
	case e_MyContactsInterface:
		face = shared_ptr<MyContactsInterface>(new MyContactsInterface());
		break;
	case e_LookGroupInterface:
		face = shared_ptr<LookGroupInterface>(new LookGroupInterface());
		break;
	case e_FindContactsInterface:
		face = shared_ptr<FindContactsInterface>(new FindContactsInterface());
		break;
	case e_ManageContactsInterface:
		face = shared_ptr<ManageContactsInterface>(new ManageContactsInterface());
		break;
	case e_ExitSystemInterface:
		face = shared_ptr<ExitSystemInterface>(new ExitSystemInterface());
		break;
	default:
		break;
	}

	return face;
}



/////////////////////////////////////////////////////////////////////////////////



shared_ptr<GetSelection> GetSelectionFactory::getInstance_shared(e_GetSelection selec)
{
	switch (selec)
	{
	case e_GetMyContactsInterfaceSelection:
		getSelection = shared_ptr<GetMyContactsInterfaceSelection>(new GetMyContactsInterfaceSelection());
		break;
	case e_GetMainInterfaceSelection:
		getSelection = shared_ptr<GetMainInterfaceSelection>(new GetMainInterfaceSelection());
		break;
	case e_GetFindContactsInterfaceSelection:
		getSelection = shared_ptr<GetFindContactsInterfaceSelection>(new GetFindContactsInterfaceSelection());
		break;
	case e_GetManageContactsInterfaceSelection:
		getSelection = shared_ptr<GetManageContactsInterfaceSelection>(new GetManageContactsInterfaceSelection());
		break;
	default:
		break;
	}

	return getSelection;
}



//////////////////////////////////////////////////////////////////////////////////



shared_ptr<Operation> OperationFactory::getInstance_shared(e_Operation e_oper)
{
	switch (e_oper)
	{
	case e_MyContacts:
		oper = shared_ptr<MyContacts>(new MyContacts());
		break;
	case e_FindContacts:
		oper = shared_ptr<FindContacts>(new FindContacts());
		break;
	case e_ManageContacts:
		oper = shared_ptr<ManageContacts>(new ManageContacts());
		break;
	case e_AddContacts:
		oper = shared_ptr<AddContacts>(new AddContacts());
		break;
	case e_RemoveContacts:
		oper = shared_ptr<RemoveContacts>(new RemoveContacts());
		break;
	case e_MoveContacts:
		oper = shared_ptr<MoveContacts>(new MoveContacts());
		break;
	case e_EditContactsInfo:
		oper = shared_ptr<EditContactsInfo>(new EditContactsInfo());
		break;
	case e_AddGroup:
		oper = shared_ptr<AddGroup>(new AddGroup());
		break;
	case e_RemoveGroup:
		oper = shared_ptr<RemoveGroup>(new RemoveGroup());
		break;
	case e_GoBack:
		oper = shared_ptr<GoBack>(new GoBack());
		break;
	case e_ExitSystem:
		oper = shared_ptr<ExitSystem>(new ExitSystem());
		break;
	default:
		break;
	}

	return oper;
}



////////////////////////////////////////////////////////////////////



shared_ptr<Context> ContextFactory::getInstance_shared(e_Context e_ctx)
{
	switch (e_ctx)
	{
	case e_MainInterfaceReaction:
		ctx = shared_ptr<MainInterfaceReaction>(new MainInterfaceReaction());
		break;
	case e_MyContactsInterfaceReaction:
		ctx = shared_ptr<MyContactsInterfaceReaction>(new MyContactsInterfaceReaction());
		break;
	case e_FindContactsInterfaceReaction:
		ctx = shared_ptr<FindContactsInterfaceReaction>(new FindContactsInterfaceReaction());
		break;
	case e_ManageContactsInterfaceReaction:
		ctx = shared_ptr<ManageContactsInterfaceReaction>(new ManageContactsInterfaceReaction());
		break;
	default:
		break;
	}

	return ctx;
}



///////////////////////////////////////////////////////////////////


shared_ptr<InterfaceFactory> Factory::getInterfaceFactory()
{
	return  shared_ptr<InterfaceFactory>(new InterfaceFactory());
}

shared_ptr<WindowsFactory> Factory::getWindowsFactory()
{
	return shared_ptr<WindowsFactory>(new WindowsFactory());
}

shared_ptr<GetSelectionFactory> Factory::getSelectionFactory()
{
	return shared_ptr<GetSelectionFactory>(new GetSelectionFactory());
}

shared_ptr<ContextFactory> Factory::getContextFactory()
{
	return shared_ptr<ContextFactory>(new ContextFactory());
}

shared_ptr<OperationFactory> Factory::getOperationFactory()
{
	return shared_ptr<OperationFactory>(new OperationFactory());
}

shared_ptr<DataReader> Factory::getDataReader_shared()
{
	return shared_ptr<DataReader>(new DataReader());
}

shared_ptr<DataWriter> Factory::getDataWriter_shared()
{
	return shared_ptr<DataWriter>(new DataWriter());
}