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

class Operation;
class MyContacts;
class FindContacts;

class Context;
class MainInterfaceReaction;
class MyContactsInterfaceReaction;

class DataHelper;
class DataWriter;
class DataReader;

class GetSelection;
class GetMyContactsInterfaceSelection;
class GetMainInterfaceSelection;

class Operation;
class MyContacts;

class Context;
class MainInterfaceReaction;
class MyContactsInterfaceReaction;

enum e_Interface
{
	e_MainInterface,
	e_MyContactsInterface,
	e_LookGroupInterface,
	e_FindContactsInterface,
};

enum e_GetSelection
{
	e_GetMyContactsInterfaceSelection,
	e_GetMainInterfaceSelection,
};

enum e_Operation
{
	e_MyContacts,
	e_FindContacts,
};

enum e_Context
{
	e_MainInterfaceReaction,
	e_MyContactsInterfaceReaction,
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
