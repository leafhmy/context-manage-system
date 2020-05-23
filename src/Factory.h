#pragma once
#ifndef FACTORY_H
#define FACTORY_H
using namespace std;
#include <memory>
#include "Interface.h"
#include "WindowsHelper.h"
#include "Strategy.h"
#include "DataHelper.h"

class WindowsHelper;

class Interface;
class MainInterface;
class MyContactsInterface;
class LookGroupInterface;
class FindContactsInterface;
class ManageContactsInterface;

class Operation;
class MyContacts;
class FindContacts;
class ManageContacts;
class EditContactsInfo;

class Context;
class MainInterfaceReaction;
class MyContactsInterfaceReaction;

class DataHelper;
class DataWriter;
class DataReader;

class GetSelection;
class GetMyContactsInterfaceSelection;
class GetMainInterfaceSelection;
class GetFindContactsInterfaceSelection;
class GetManageContactsInterfaceSelection;

class Operation;
class MyContacts;
class AddContacts;
class RemoveContacts;
class MoveContacts;

class Context;
class MainInterfaceReaction;
class MyContactsInterfaceReaction;
class FindContactsInterfaceReaction;
class ManageContactsInterfaceReaction;

enum e_Interface
{
	e_MainInterface,
	e_MyContactsInterface,
	e_LookGroupInterface,
	e_FindContactsInterface,
	e_ManageContactsInterface,
};

enum e_GetSelection
{
	e_GetMyContactsInterfaceSelection,
	e_GetMainInterfaceSelection,
	e_GetFindContactsInterfaceSelection,
	e_GetManageContactsInterfaceSelection,
};

enum e_Operation
{
	e_MyContacts,
	e_FindContacts,
	e_ManageContacts,
	e_AddContacts,
	e_RemoveContacts,
	e_MoveContacts,
	e_EditContactsInfo,
};

enum e_Context
{
	e_MainInterfaceReaction,
	e_MyContactsInterfaceReaction,
	e_FindContactsInterfaceReaction,
	e_ManageContactsInterfaceReaction,
};



class WindowsFactory
{
public:
	shared_ptr<WindowsHelper> getInstance();

private:
	shared_ptr<WindowsHelper> helper;
};



class InterfaceFactory
{
public:
	shared_ptr<Interface> getInstance_shared(e_Interface e_face);

private:
	shared_ptr<Interface> face;

};


class GetSelectionFactory
{
public:
	shared_ptr<GetSelection> getInstance_shared(e_GetSelection selec);

private:
	shared_ptr<GetSelection> getSelection;
};


class OperationFactory
{
public:
	shared_ptr<Operation> getInstance_shared(e_Operation e_oper);

private:
	shared_ptr<Operation> oper;

};



class ContextFactory
{
public:
	shared_ptr<Context> getInstance_shared(e_Context e_ctx);

private:
	shared_ptr<Context> ctx;

};



class Factory
{
public:
	shared_ptr<InterfaceFactory> getInterfaceFactory();

	shared_ptr<WindowsFactory> getWindowsFactory();

	shared_ptr<GetSelectionFactory> getSelectionFactory();

	shared_ptr<ContextFactory> getContextFactory();

	shared_ptr<OperationFactory> getOperationFactory();

	shared_ptr<DataReader> getDataReader_shared();

	shared_ptr<DataWriter> getDataWriter_shared();

};



#endif // !FACTORY_H
