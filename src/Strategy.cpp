#include "Strategy.h"

///////////////////////////////////////////////

GetSelection::GetSelection()
{
	fac = new Factory();
	winFac = fac->getWindowsFactory();
	windowsHelper = winFac->getInstance();
}

GetSelection::~GetSelection()
{
	delete fac;
}

int GetMainInterfaceSelection::Select()
{
	int ch;  // 记录键入值
	int key = 1;  // 记录选中项，初始选择第一个
	bool flag = false;
	windowsHelper->toSelect(20, 10, "我的联系人");
	while ((ch = _getch()))  // 检测输入键
	{
		switch (ch)  // 检测输入键
		{
			// UP上方向键
		case 72:
			if (key > 1)//当此时选中项为第一项时，UP上方向键无效
			{
				switch (key)
				{
				case(2):
				{
					windowsHelper->selected(20, 12, "查找联系人");  // 将已选中项取消我背景色
					windowsHelper->toSelect(20, 10, "我的联系人");  // 给待选中项设置背景色

					--key;
					break;
				}
				case(3):
				{
					windowsHelper->selected(20, 14, "管理我的联系人");
					windowsHelper->toSelect(20, 12, "查找联系人");

					--key;
					break;
				}
				case(4):
				{
					windowsHelper->selected(20, 16, "退出系统");
					windowsHelper->toSelect(20, 14, "管理我的联系人");

					--key;
					break;
				}
				}
			}
			break;
			// DOWN下方向键
		case 80:
			if (key < 4)
			{
				switch (key)
				{
				case(1):
				{
					windowsHelper->selected(20, 10, "我的联系人");
					windowsHelper->toSelect(20, 12, "查找联系人");

					++key;
					break;
				}
				case(2):
				{
					windowsHelper->selected(20, 12, "查找联系人");
					windowsHelper->toSelect(20, 14, "管理我的联系人");

					++key;
					break;
				}

				case(3):
				{
					windowsHelper->selected(20, 14, "管理我的联系人");
					windowsHelper->toSelect(20, 16, "退出系统");

					++key;
					break;
				}
				default:
				{
					break;
				}
				}
			}
			break;

		case 13://Enter回车键
			flag = true;
			break;
		default://无效按键
			break;
		}
		if (flag) break;//输入Enter回车键确认，退出检查输入循环
	}
	return key;
}

int GetMyContactsInterfaceSelection::Select()
{
	int ch;
	int key = 1;
	bool flag = false;
	// windowsHelper->print(3, 25, "返回");
	windowsHelper->toSelect(3, 25, "返回");
	while ((ch = _getch()))
	{
		switch (ch)
		{
		case 13:
			flag = true;
			break;
		default:
			break;
		}
		if (flag) break;
	}
	return key;
}


//////////////////////////////////////////////

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
	// windowsHelper->setWindowsAttribute(50, 40, "test");
	windowsHelper->print(17, 5, groupName);
	// TODO 打印该组下的所有联系人的姓名和电话号码（手机号，家庭电话号，办公电话号码）
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
	shared_ptr<GetSelectionFactory> getSelecFac = fac->getSelectionFactory();
	shared_ptr<GetSelection> myCtxFaceSelection = getSelecFac->getInstance_shared(e_GetMyContactsInterfaceSelection);
	int key = myCtxFaceSelection->Select();
	shared_ptr<ContextFactory> ctxFac = fac->getContextFactory();
	shared_ptr<Context> myCtxFaceReact = ctxFac->getInstance_shared(e_MyContactsInterfaceReaction);
	windowsHelper->setColor(3);
	system("cls");
	myCtxFaceReact->reactToSelection(key);
}


void FindContacts::doOperation()
{
	windowsHelper->setColor(3);
	system("cls");
	windowsHelper->print(2, 2, "请输入联系人信息：");
	string contactInfo;
	// 用户输入查找信息
	// 长度不能超过50
	while (true)
	{
		getline(cin, contactInfo); cin.clear();
		if (contactInfo.length() > 50 || contactInfo.length() == 0)
		{
			windowsHelper->print(2, 2, "输入错误！请重新输入,");
			system("pause");
			windowsHelper->clearLine(2, 2, 50, "请输入联系人信息：");
		}
		else
			break;
	}

	// 查找信息
	shared_ptr<DataReader> reader = fac->getDataReader_shared();
	// 获取所有联系人
	vector<map<string, string>> allContacts = reader->getAllContacts();
	vector<map<string, string>> foundContacts;

	for (auto contact : allContacts)
	{
		for (auto info : contact)
		{
			string value = info.second;
			if (value.find(contactInfo) != value.npos)
			{
				foundContacts.push_back(contact);
				break;
			}
		}
	}

	system("cls");
	// 改变控制台宽度
	if(foundContacts.size()!=0)
		windowsHelper->setWindowsAttribute(80, 30, "通信录管理系统");

	//windowsHelper->print(2, 2, "请输入联系人信息：");
	windowsHelper->setCursorPosition(2, 2);
	cout << "共找到 " << foundContacts.size() << " 条记录";
	vector<string> attrubute({ "分组","编号", "姓名","性别", "地址","手机号","家庭电话","工作电话" ,"邮箱" });
	for (int i = 0, x = 2, y = 4; i < foundContacts[0].size(); x += 8, i++)
	{
		windowsHelper->print(x, y, attrubute[i]);
	}
	int xPos = 2, yPos = 6;
	for (auto contact : foundContacts)
	{
		windowsHelper->print(xPos, yPos, contact["group"]); xPos += 8;
		windowsHelper->print(xPos, yPos, contact["id"]); xPos += 8;
		windowsHelper->print(xPos, yPos, contact["name"]); xPos += 8;
		windowsHelper->print(xPos, yPos, contact["sex"]); xPos += 8;
		windowsHelper->print(xPos, yPos, contact["address"]); xPos += 8;
		windowsHelper->print(xPos, yPos, contact["mobile_phone"]); xPos += 8;
		windowsHelper->print(xPos, yPos, contact["home_phone"]); xPos += 8;
		windowsHelper->print(xPos, yPos, contact["work_phone"]); xPos += 8;
		windowsHelper->print(xPos, yPos, contact["mail"]); xPos += 5;
		yPos += 2;
	}


	//shared_ptr<Interface> findCtxInterface = faceFac->getInstance_shared(e_FindContactsInterface);
	//findCtxInterface->show();







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
	// 查找联系人
	case 2:
		oper = operFac->getInstance_shared(e_FindContacts);
		oper->doOperation();
		break;
	default:
		break;
	}
}

void MyContactsInterfaceReaction::reactToSelection(int key)
{
	switch (key)
	{
	// 返回主页面
	case 1: 
	{
		shared_ptr<InterfaceFactory> faceFac = fac->getInterfaceFactory();
		shared_ptr<Interface> mainFace = faceFac->getInstance_shared(e_MainInterface);
		mainFace->show();
		shared_ptr<GetSelectionFactory> getSelecFac = fac->getSelectionFactory();
		shared_ptr<GetSelection> mainFaceSelec = getSelecFac->getInstance_shared(e_GetMainInterfaceSelection);
		int key = mainFaceSelec->Select();
		shared_ptr<ContextFactory> ctxFac = fac->getContextFactory();
		shared_ptr<Context> mainFaceReact = ctxFac->getInstance_shared(e_MainInterfaceReaction);
		mainFaceReact->reactToSelection(key);
		break;
	}
	default:
		break;
	}
}