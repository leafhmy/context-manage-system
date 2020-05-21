#pragma once
#ifndef STRATEGY_H
#define STRATEGY_H
#include "Factory.h"

class Operation
{
public:
	Operation();

	virtual ~Operation();

	virtual void doOperation() = 0;
};

class MyContacts :public Operation
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


};

class MainInterfaceReaction :public Context
{
public:
	void reactToSelection(int key)override;

};



#endif // !STRATEGY-H
