#pragma once
#ifndef INTERFACE_H
#define INTERFACE_H
#include "Factory.h"

class Factory;
class WindowsFactory;
class WindowsHelper;

class Interface
{
public:
	Interface();

	virtual ~Interface();

	virtual void showTitle() = 0;

	virtual void showSelection() = 0;

	virtual void show()
	{
		showTitle();
		showSelection();
	}

protected:
	Factory* fac;
	shared_ptr<WindowsFactory> windowsFactory;
	shared_ptr<WindowsHelper> windowsHelper;

};

class MainInterface :public Interface
{
public:
	void showTitle()override;

	void showSelection()override;

};

class MyContactsInterface :public Interface
{
public:
	void showTitle()override;

	void showSelection()override;
};

class LookGroupInterface :public Interface
{
public:
	void showTitle()override;

	void showSelection()override;
};

class FindContactsInterface :public Interface
{
public:
	void showTitle()override;

	void showSelection()override;
};

class ManageContactsInterface :public Interface
{
public:
	void showTitle()override;

	void showSelection()override;
};


#endif // !INTERFACE_H
