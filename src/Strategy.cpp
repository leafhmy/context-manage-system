#include "Strategy.h"

Operation::Operation()
{
	Factory* fac = new Factory();
	faceFac = fac->getInterfaceFactory();
	winFac = fac->getWindowsFactory();
	windowsHelper = winFac->getInstance();
}

Operation::~Operation()
{
	delete fac;
}

void MyContacts::doOperation()
{
	windowsHelper->setColor(3);
	system("cls");
	shared_ptr<Interface> myCtxInterface = faceFac->getInstance_shared(e_MyContactsInterface);
	myCtxInterface->show();

	shared_ptr<DataReader> reader = fac->getDataReader_shared();
	// windowsHelper->print(17, 5, "我的联系人");
	// windowsHelper->print(12, 7, "我的分组：");
	// 打印所有分组
	vector<string> allGroups = reader->getGroups();
	int pos = 10;
	for (auto groupName : allGroups)
	{
		windowsHelper->setCursorPosition(17, pos);
		cout << groupName;
	}

	windowsHelper->setCursorPosition(3, 30);
	windowsHelper->print(3, 25, "请输入组名以查看：");
	string groupName = "默认分组";
	// TODO 处理键入非数字的字符出现bug
	// 改为输入字符串
	while (true)
	{
		//cin >> groupName; 
		getline(cin, groupName); cin.clear();
		if (find(allGroups.begin(), allGroups.end(), groupName) == allGroups.end())
		{
			windowsHelper->print(3, 25, "输入错误！请重新输入,");
			system("pause");
			windowsHelper->clearLine(3, 25, 50, "请输入组名以查看：");
		}
		else
			break;
	}
	system("cls");
	windowsHelper->print(17, 5, groupName);
	// TODO 打印改组下的所有联系人的姓名和电话号码（手机号，家庭电话号，办公电话号码）
	vector<map<string, string>> contactsInGroup = reader->getContactsInGroup(groupName);
	windowsHelper->print(8, 8, "姓名");
	windowsHelper->print(16, 8, "手机号");
	windowsHelper->print(24, 8, "家庭电话号");
	windowsHelper->print(32, 8, "办公电话号");

	int xPos = 8, yPos = 10;
	for (auto contactInfo : contactsInGroup)
	{
		windowsHelper->print(xPos, yPos, contactInfo["name"]);
		xPos += 8;
		windowsHelper->print(xPos, yPos, contactInfo["mobile_phone"]);
		xPos += 8;
		windowsHelper->print(xPos, yPos, contactInfo["home_phone"]);
		xPos += 8;
		windowsHelper->print(xPos, yPos, contactInfo["work_phone"]);
		xPos = 6;
		yPos += 2;
	}

	shared_ptr<InterfaceFactory> interfaceFac = fac->getInterfaceFactory();
	shared_ptr<Interface> groupInterface = interfaceFac->getInstance_shared(e_LookGroupInterface);
	groupInterface->show();

}


////////////////////////////////////////////////////////////



Context::Context()
{
	fac = new Factory();
	operFac = fac->getOperationFactory();
}

Context::~Context()
{
	delete fac;
}

void MainInterfaceReaction::reactToSelection(int key)
{
	switch (key)
	{
	// 我的联系人
	case 1:
		oper = operFac->getInstance_shared(e_MyContacts);
		oper->doOperation();
		break;
	default:
		break;
	}
}