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
public:
	int Select()override;
};

class GetFindContactsInterfaceSelection :public GetSelection
{
public:
	int Select()override;
};

class GetManageContactsInterfaceSelection :public GetSelection
{
public:
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

protected:
	void printAllContacts();
	void upDateMngCtxInterface();
	string GBToUTF8(const char* gb2312)
	{
		int len = MultiByteToWideChar(CP_ACP, 0, gb2312, -1, NULL, 0);
		wchar_t* wstr = new wchar_t[len + 1];
		memset(wstr, 0, len + 1);
		MultiByteToWideChar(CP_ACP, 0, gb2312, -1, wstr, len);
		len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
		char* str = new char[len + 1];
		memset(str, 0, len + 1);
		WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);
		if (wstr) delete[] wstr;
		return str;
	}
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

class ManageContacts :public Operation
{
public:
	void doOperation()override;
};

class AddContacts :public Operation
{
public:
	void doOperation()override;
};

class RemoveContacts :public Operation
{
public:
	void doOperation()override;
};

class MoveContacts :public Operation
{
public:
	void doOperation()override;
};

class EditContactsInfo :public Operation
{
public:
	void doOperation()override;
};

class AddGroup : public Operation
{
public:
	void doOperation()override;
};

class RemoveGroup :public Operation
{
public:
	void doOperation()override;
};

class GoBack :public Operation
{
public:
	void doOperation()override;
};

class ExitSystem :public Operation
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

class FindContactsInterfaceReaction :public Context
{
public:
	void reactToSelection(int key)override;
};

class ManageContactsInterfaceReaction :public Context
{
public:
	void reactToSelection(int key)override;
};




#endif // !STRATEGY_H
