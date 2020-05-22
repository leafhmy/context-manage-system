#pragma once
#ifndef STRATEGY_H
#define STRATEGY_H
#include "Factory.h"
#include <regex>
#include <sstream>
#include <algorithm>
#include <conio.h>

class Interface;
class InterfaceFactory;
class OperationFactory;
class WindowsFactory;
class Factory;



class GetSelection
{
public:
	GetSelection();

	virtual ~GetSelection();

	virtual int Select() = 0;

protected:
	Factory* fac;
	shared_ptr<WindowsFactory> winFac;
	shared_ptr<WindowsHelper> windowsHelper;
};

class GetMyContactsInterfaceSelection :public GetSelection
{
public:
	int Select()override;
};

class GetMainInterfaceSelection :public GetSelection
{
	int Select()override;
};

////////////////////////////////////////

class Operation
{
public:
	Operation();

	virtual ~Operation();

	virtual void doOperation() = 0;

protected:
	Factory* fac;
	shared_ptr<InterfaceFactory> faceFac;
	shared_ptr<Interface> face;
	shared_ptr<WindowsFactory> winFac;
	shared_ptr<WindowsHelper> windowsHelper;
};

class MyContacts :public Operation
{
public:
	void doOperation()override;

};

class FindContacts :public Operation
{
public:
	void doOperation()override;

};


/////////////////////////////////////////////////////



class Context
{
public:
	Context();

	virtual ~Context();

	virtual void reactToSelection(int key) = 0;

protected:
	Factory* fac;
	shared_ptr<OperationFactory> operFac;
	shared_ptr<Operation> oper;

};

 
class MainInterfaceReaction :public Context
{
public:
	void reactToSelection(int key)override;

};

class MyContactsInterfaceReaction :public Context 
{
public:
	void reactToSelection(int key)override;
};



#endif // !STRATEGY-H
