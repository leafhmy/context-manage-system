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

class Operation;
class MyContacts;

class Context;
class MainInterfaceReaction;

enum e_Interface
{
	e_MainInterface,
};

enum e_Operation
{
	e_MyContacts,
};

enum e_Context
{
	e_MainInterfaceReaction,
};

enum e_DataHelper
{

};



class InterfaceFactory
{
public:
	shared_ptr<Interface> getInstance_shared(e_Interface e_face);

private:
	shared_ptr<Interface> face;

};



class WindowsFactory
{
public:
	shared_ptr<WindowsHelper> getInstance();

private:
	shared_ptr<WindowsHelper> helper;
};



class Factory
{
public:
	shared_ptr<InterfaceFactory> getInterfaceFactory();

	shared_ptr<WindowsFactory> getWindowsFactory();

};



#endif // !FACTORY_H
