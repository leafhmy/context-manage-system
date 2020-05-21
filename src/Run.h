#pragma once
#ifndef RUN_H
#define RUN_H
using namespace std;
#include "WindowsHelper.h"
#include "Interface.h"
#include "Factory.h"
#include <conio.h>

class Run
{
public:

	Run();

	~Run();

	void start();

private:
	Factory* fac;
	shared_ptr<WindowsFactory> windowsFac;
	shared_ptr<WindowsHelper> windowsHelper;
	shared_ptr<InterfaceFactory> interfaceFactory;

	int mainInterfaceSelection();
};


#endif // !RUN_H
