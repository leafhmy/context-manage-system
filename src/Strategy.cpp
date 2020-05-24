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

int GetManageContactsInterfaceSelection::Select()
{
	int ch;  // 记录键入值
	int key = 1;  // 记录选中项，初始选择第一个
	bool flag = false;
	windowsHelper->toSelect(2, 6, "添加联系人");
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
					windowsHelper->selected(2, 8, "删除联系人");  // 将已选中项取消我背景色
					windowsHelper->toSelect(2, 6, "添加联系人");  // 给待选中项设置背景色

					--key;
					break;
				}
				case(3):
				{
					windowsHelper->selected(2, 10, "移动联系人");
					windowsHelper->toSelect(2, 8, "删除联系人");

					--key;
					break;
				}
				case(4):
				{
					windowsHelper->selected(2, 12, "编辑信息");
					windowsHelper->toSelect(2, 10, "移动联系人");

					--key;
					break;
				}
				case(5):
				{
					windowsHelper->selected(2, 14, "添加分组");
					windowsHelper->toSelect(2, 12, "编辑信息");

					--key;
					break;
				}
				case(6):
				{
					windowsHelper->selected(2, 16, "删除分组");
					windowsHelper->toSelect(2, 14, "添加分组");

					--key;
					break;
				}
				case(7):
				{
					windowsHelper->selected(2, 18, "返回");
					windowsHelper->toSelect(2, 16, "删除分组");

					--key;
					break;
				}
				}
			}
			break;
			// DOWN下方向键
		case 80:
			if (key < 7)
			{
				switch (key)
				{
				case(1):
				{
					windowsHelper->selected(2, 6, "添加联系人");
					windowsHelper->toSelect(2, 8, "删除联系人");

					++key;
					break;
				}
				case(2):
				{
					windowsHelper->selected(2, 8, "删除联系人");
					windowsHelper->toSelect(2, 10, "移动联系人");

					++key;
					break;
				}

				case(3):
				{
					windowsHelper->selected(2, 10, "移动联系人");
					windowsHelper->toSelect(2, 12, "编辑信息");

					++key;
					break;
				}
				case(4):
				{
					windowsHelper->selected(2, 12, "编辑信息");
					windowsHelper->toSelect(2, 14, "添加分组");

					++key;
					break;
				}
				case(5):
				{
					windowsHelper->selected(2, 14, "添加分组");
					windowsHelper->toSelect(2, 16, "删除分组");

					++key;
					break;
				}
				case(6):
				{
					windowsHelper->selected(2, 16, "删除分组");
					windowsHelper->toSelect(2, 18, "返回");

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

int GetFindContactsInterfaceSelection::Select()
{
	// windowsHelper->print(2, 4, "返回");
	int ch;
	int key = 1;
	bool flag = false;
	windowsHelper->toSelect(2, 4, "返回");
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

void Operation::printAllContacts()
{
	windowsHelper->setColor(3);
	shared_ptr<DataReader> reader = fac->getDataReader_shared();
	// 获取所有联系人
	vector<map<string, string>> allContacts = reader->getAllContacts();

	// windowsHelper->print(35, 2, "所有联系人");
	// windowsHelper->print(2, 6, "添加联系人");
	// windowsHelper->print(2, 8, "移动联系人");
	// windowsHelper->print(2, 10, "编辑信息");
	// windowsHelper->print(2, 12, "添加分组");
	// windowsHelper->print(2, 14, "删除分组");

	vector<string> attrubute({ "分组","编号", "姓名","性别", "地址","手机号","家庭电话","工作电话" ,"邮箱" });
	for (int i = 0, x = 8, y = 6; i < attrubute.size(); x += 8, i++)
	{
		windowsHelper->print(x, y, attrubute[i]);
	}

	int xPos = 8, yPos = 8;
	for (auto contact : allContacts)
	{
		windowsHelper->print(xPos, yPos, contact["group"]); xPos += 8;
		windowsHelper->print(xPos, yPos, contact["id"]); xPos += 8;
		windowsHelper->print(xPos, yPos, contact["name"]); xPos += 8;
		windowsHelper->print(xPos, yPos, contact["sex"]); xPos += 8;
		windowsHelper->print(xPos, yPos, contact["address"]); xPos += 8;
		windowsHelper->print(xPos, yPos, contact["mobile_phone"]); xPos += 8;
		windowsHelper->print(xPos, yPos, contact["home_phone"]); xPos += 8;
		windowsHelper->print(xPos, yPos, contact["work_phone"]); xPos += 8;
		windowsHelper->print(xPos, yPos, contact["mail"]); xPos = 8;
		yPos += 2;
	}
}


void Operation::upDateMngCtxInterface()
{
	system("cls");
	shared_ptr<InterfaceFactory> faceFac = fac->getInterfaceFactory();
	shared_ptr<Interface> mngCtxFace = faceFac->getInstance_shared(e_ManageContactsInterface);
	mngCtxFace->show();

	printAllContacts();

	shared_ptr<GetSelectionFactory> getSelecFac = fac->getSelectionFactory();
	shared_ptr<GetSelection> getMngSelect = getSelecFac->getInstance_shared(e_GetManageContactsInterfaceSelection);
	int key = getMngSelect->Select();
	shared_ptr<ContextFactory> ctxFac = fac->getContextFactory();
	shared_ptr<Context> mngReact = ctxFac->getInstance_shared(e_ManageContactsInterfaceReaction);
	windowsHelper->setColor(3);
	mngReact->reactToSelection(key);
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
	int yPos1 = 10;
	int xPos1 = 17;
	for (auto groupName : allGroups)
	{
		windowsHelper->print(xPos1, yPos1, groupName);
		yPos1 += 2;
	}

	windowsHelper->setCursorPosition(3, 30);
	windowsHelper->print(3, 25, "请输入组名以查看：");
	string groupName = "默认分组";

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
	// 打印该组下的所有联系人的姓名和电话号码（手机号，家庭电话号，办公电话号码）
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
	windowsHelper->setWindowsAttribute(80, 30, "通信录管理系统");

	//windowsHelper->print(2, 2, "请输入联系人信息：");
	windowsHelper->setCursorPosition(2, 2);
	cout << "共找到 " << foundContacts.size() << " 条记录";
	vector<string> attrubute({ "分组","编号", "姓名","性别", "地址","手机号","家庭电话","工作电话" ,"邮箱" });
	for (int i = 0, x = 2, y = 6; i < attrubute.size(); x += 8, i++)
	{
		windowsHelper->print(x, y, attrubute[i]);
	}
	int xPos = 2, yPos = 8;
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
		windowsHelper->print(xPos, yPos, contact["mail"]); xPos = 2;
		yPos += 2;
	}
	
	shared_ptr<InterfaceFactory> interfaceFac = fac->getInterfaceFactory();
	shared_ptr<Interface> groupInterface = interfaceFac->getInstance_shared(e_FindContactsInterface);
	groupInterface->show();
	shared_ptr<GetSelectionFactory> getSelecFac = fac->getSelectionFactory();
	shared_ptr<GetSelection> findCtxFaceSelection = getSelecFac->getInstance_shared(e_GetFindContactsInterfaceSelection);
	int key = findCtxFaceSelection->Select();
	shared_ptr<ContextFactory> ctxFac = fac->getContextFactory();
	shared_ptr<Context> findCtxFaceReact = ctxFac->getInstance_shared(e_FindContactsInterfaceReaction);
	windowsHelper->setColor(3);
	system("cls");
	// 恢复控制台大小
	windowsHelper->setWindowsAttribute(50, 30, "通信录管理系统");
	findCtxFaceReact->reactToSelection(key);

}


void ManageContacts::doOperation()
{
	windowsHelper->setColor(3);
	system("cls");
	windowsHelper->setWindowsAttribute(85, 30, "通信录管理系统");
	shared_ptr<Interface> mngCtxInterface = faceFac->getInstance_shared(e_ManageContactsInterface);
	mngCtxInterface->show();

	shared_ptr<DataReader> reader = fac->getDataReader_shared();
	// 获取所有联系人
	vector<map<string, string>> allContacts = reader->getAllContacts();

	// windowsHelper->print(35, 2, "所有联系人");
	// windowsHelper->print(2, 6, "添加联系人");
	// windowsHelper->print(2, 8, "移动联系人");
	// windowsHelper->print(2, 10, "编辑信息");
	// windowsHelper->print(2, 12, "添加分组");
	// windowsHelper->print(2, 14, "删除分组");

	vector<string> attrubute({ "分组","编号", "姓名","性别", "地址","手机号","家庭电话","工作电话" ,"邮箱" });
	for (int i = 0, x = 8, y = 6; i < attrubute.size(); x += 8, i++)
	{
		windowsHelper->print(x, y, attrubute[i]);
	}

	int xPos = 8, yPos = 8;
	for (auto contact : allContacts)
	{
		windowsHelper->print(xPos, yPos, contact["group"]); xPos += 8;
		windowsHelper->print(xPos, yPos, contact["id"]); xPos += 8;
		windowsHelper->print(xPos, yPos, contact["name"]); xPos += 8;
		windowsHelper->print(xPos, yPos, contact["sex"]); xPos += 8;
		windowsHelper->print(xPos, yPos, contact["address"]); xPos += 8;
		windowsHelper->print(xPos, yPos, contact["mobile_phone"]); xPos += 8;
		windowsHelper->print(xPos, yPos, contact["home_phone"]); xPos += 8;
		windowsHelper->print(xPos, yPos, contact["work_phone"]); xPos += 8;
		windowsHelper->print(xPos, yPos, contact["mail"]); xPos = 8;
		yPos += 2;
	}

	shared_ptr<GetSelectionFactory> getMngCtxFaceFac = fac->getSelectionFactory();
	shared_ptr<GetSelection>getMngCtxFaceSelect = getMngCtxFaceFac->getInstance_shared(e_GetManageContactsInterfaceSelection);
	int key = getMngCtxFaceSelect->Select();
	shared_ptr<ContextFactory> ctxFac = fac->getContextFactory();
	shared_ptr<Context> mngContactsReac = ctxFac->getInstance_shared(e_ManageContactsInterfaceReaction);

	windowsHelper->setColor(3);
	mngContactsReac->reactToSelection(key);

}


void AddContacts::doOperation()
{
	shared_ptr<DataReader> reader = fac->getDataReader_shared();
	// 获取分组信息
	vector<string> allGroups = reader->getGroups();
	// 获取所有联系人
	vector<map<string, string>> allContacts = reader->getAllContacts();
	// windowsHelper->print(35, 2, "所有联系人");
	// windowsHelper->print(2, 6, "添加联系人");
	// windowsHelper->print(2, 8, "移动联系人");
	// windowsHelper->print(2, 10, "编辑信息");
	// windowsHelper->print(2, 12, "添加分组");
	// windowsHelper->print(2, 14, "删除分组");
	// vector<string> attrubute({ "分组","编号", "姓名","性别", "地址","手机号","家庭电话","工作电话" ,"邮箱" });
	
	string group, id, name, sex, address, mobile_phone, home_phone, work_phone, mail;

	// 输入组名
	while (true)
	{
		windowsHelper->clearLine(2, 4, 85, "请输入目标分组：");
		getline(cin, group); cin.clear();
		bool ok = true;
		vector<string>::iterator found = find(allGroups.begin(), allGroups.end(), group);
		if (found == allGroups.end())
		{
			ok = false;
			windowsHelper->clearLine(2, 4, 85, "不存在该分组！请重新输入，");
			system("pause");
		}
		if (ok)
			break;
	}
	// 输入编号
	while (true)
	{
		windowsHelper->clearLine(2, 4, 85, "请输入四位数字编号：");
		getline(cin, id); cin.clear();
		regex pat("^([0-9]{4})$");
		smatch s;
		bool found = regex_search(id, s, pat);
		bool ok = true;
		if (!found)
		{
			ok = false;
			windowsHelper->clearLine(2, 4, 85, "格式错误！请重新输入，");
			system("pause");
		}
		// 查重
		else
		{
			for (auto contact : allContacts)
			{
				if (contact["id"] == id)
				{
					ok = false;
					windowsHelper->clearLine(2, 4, 85, "编号存在！请重新输入，");
					system("pause");
					windowsHelper->clearLine(2, 4, 85, "请输入四位数字编号：");
					break;
				}
			}
		}
		if (ok)
			break;
	}
	// 输入姓名
	while (true)
	{
		windowsHelper->clearLine(2, 4, 85, "请输入姓名：");
		bool ok = true;
		getline(cin, name); cin.clear();
		regex pat("^([^\\s].{0,19})$");
		smatch s;
		bool found = regex_search(name, s, pat);
		if (!found)
		{
			ok = false;
			windowsHelper->clearLine(2, 4, 85, "格式错误！请重新输入，");
			system("pause");
		}
		if (ok)
			break;
	}
	// 输入性别
	while (true)
	{
		windowsHelper->clearLine(2, 4, 85, "请输入性别：");
		bool ok = true;
		getline(cin, sex); cin.clear();
		if (sex != "男" && sex != "女")
		{
			ok = false;
			windowsHelper->clearLine(2, 4, 85, "格式错误！请重新输入，");
			system("pause");
		}
		if (ok)
			break;
	}
	// 输入地址
	while (true)
	{
		windowsHelper->clearLine(2, 4, 85, "请输入地址：");
		bool ok = true;
		getline(cin, address); cin.clear();
		regex pat("^([^\\s].{0,19})$");
		smatch s;
		bool found = regex_search(id, s, pat);
		if (!found)
		{
			ok = false;
			windowsHelper->clearLine(2, 4, 85, "格式错误！请重新输入，");
			system("pause");
		}
		if (ok)
			break;
	}
	// 输入手机号
	while (true)
	{
		windowsHelper->clearLine(2, 4, 85, "请输入手机号：");
		bool ok = true;
		getline(cin, mobile_phone); cin.clear();
		regex pat("^(1[3-9]\\d{9})$");
		smatch s;
		bool found = regex_search(mobile_phone, s, pat);
		if (!found)
		{
			ok = false;
			windowsHelper->clearLine(2, 4, 85, "格式错误！请重新输入，");
			system("pause");
		}
		if (ok)
			break;
	}
	// 输入家庭电话
	while (true)
	{
		windowsHelper->clearLine(2, 4, 85, "请输入家庭电话：");
		bool ok = true;
		getline(cin, home_phone); cin.clear();
		regex pat("(^(\\d{2,4}[-_－—]?)?\\d{3,8}([-_－—]?\\d{3,8})?([-_－—]?\\d{1,7})?$)|(^0?1[35]\\d{9}$)");
		smatch s;
		bool found = regex_search(home_phone, s, pat);
		if (!found)
		{
			ok = false;
			windowsHelper->clearLine(2, 4, 85, "格式错误！请重新输入，");
			system("pause");
		}
		if (ok)
			break;
	}
	// 输入工作电话
	while (true)
	{
		windowsHelper->clearLine(2, 4, 85, "请输入工作电话：");
		bool ok = true;
		getline(cin, work_phone); cin.clear();
		regex pat("(^(\\d{2,4}[-_－—]?)?\\d{3,8}([-_－—]?\\d{3,8})?([-_－—]?\\d{1,7})?$)|(^0?1[35]\\d{9}$)");
		smatch s;
		bool found = regex_search(work_phone, s, pat);
		if (!found)
		{
			ok = false;
			windowsHelper->clearLine(2, 4, 85, "格式错误！请重新输入，");
			system("pause");
		}
		if (ok)
			break;
	}
	// 输入邮箱
	while (true)
	{
		windowsHelper->clearLine(2, 4, 85, "请输入邮箱：");
		bool ok = true;
		getline(cin, mail); cin.clear();
		regex pat("^([\\w!#$%&'*+/=?^_`{|}~-]+(?:\.[\\w!#$%&'*+/=?^_`{|}~-]+)*@(?:[\\w](?:[\\w-]*[\\w])?\.)+[\\w](?:[\\w-]*[\\w])?)$");
		smatch s;
		bool found = regex_search(mail, s, pat);
		if (!found)
		{
			ok = false;
			windowsHelper->clearLine(2, 4, 85, "格式错误！请重新输入，");
			system("pause");
		}
		if (ok)
			break;
	}

	map<string, string> newContact;
	newContact["address"] = address;
	newContact["home_phone"] = home_phone;
	newContact["id"] = id;
	newContact["group"] = group;
	newContact["name"] = name;
	newContact["sex"] = sex;
	newContact["mobile_phone"] = mobile_phone;
	newContact["work_phone"] = work_phone;
	newContact["mail"] = mail;

	shared_ptr<DataWriter>writer = fac->getDataWriter_shared();
	writer->addContact(newContact, group);

	upDateMngCtxInterface();
}


void RemoveContacts::doOperation()
{
	shared_ptr<DataReader> reader = fac->getDataReader_shared();
	// 获取所有联系人
	vector<map<string, string>> allContacts = reader->getAllContacts();

	string removeId;
	string inGroup;
	while (true)
	{
		windowsHelper->clearLine(2, 4, 85, "请输入联系人编号:");
		getline(cin, removeId); cin.clear();
		bool exist = false;
		// 确认编号是否存在
		for (auto contact : allContacts)
		{
			if (contact["id"] == removeId)
			{
				exist = true;
				inGroup = contact["group"];
				break;
			}
		}
		if (exist)
			break;
		else
		{
			windowsHelper->clearLine(2, 4, 85, "输入错误或编号不存在，请重新输入，");
			system("pause");
		}
	}

	shared_ptr<DataWriter> writer = fac->getDataWriter_shared();
	writer->removeContact(inGroup, removeId);
	windowsHelper->clearLine(2, 4, 85, "删除成功！");
	system("pause");

	upDateMngCtxInterface();

}


void MoveContacts::doOperation()
{
	shared_ptr<DataReader> reader = fac->getDataReader_shared();
	// 获取所有联系人
	vector<map<string, string>> allContacts = reader->getAllContacts();
	// 获取分组信息
	vector<string> allGroups = reader->getGroups();

	string moveId;
	string inGroup;
	string destinGroup;
	// 获取联系人编号和所在分组
	while (true)
	{
		windowsHelper->clearLine(2, 4, 85, "请输入联系人编号:");
		getline(cin, moveId); cin.clear();
		bool exist = false;
		// 确认编号是否存在
		for (auto contact : allContacts)
		{
			if (contact["id"] == moveId)
			{
				exist = true;
				inGroup = contact["group"];
				break;
			}
		}
		if (exist)
			break;
		else
		{
			windowsHelper->clearLine(2, 4, 85, "输入错误或编号不存在，请重新输入，");
			system("pause");
		}
	}
	// 获取目标分组
	while (true)
	{
		windowsHelper->clearLine(2, 4, 85, "请输入要移动到的分组：");
		getline(cin, destinGroup); cin.clear();
		if (destinGroup == inGroup)
		{
			windowsHelper->clearLine(2, 4, 85, "联系人已经在该组！请重新输入，");
			system("pause");
			continue;
		}
		bool exist = false;
		// 确认目标分组是否存在
		for (auto group : allGroups)
		{
			if (group == destinGroup)
			{
				exist = true;
				break;
			}
		}
		if (exist)
			break;
		else
		{
			windowsHelper->clearLine(2, 4, 85, "输入错误或该分组不存在，请重新输入，");
			system("pause");
		}
	}


	shared_ptr<DataWriter> writer = fac->getDataWriter_shared();
	writer->moveContact(moveId, inGroup, destinGroup);
	windowsHelper->clearLine(2, 4, 85, "移动成功！");
	system("pause");

	upDateMngCtxInterface();
}


void EditContactsInfo::doOperation()
{
	shared_ptr<DataReader> reader = fac->getDataReader_shared();
	// 获取所有联系人
	vector<map<string, string>> allContacts = reader->getAllContacts();
	// 获取分组信息
	vector<string> allGroups = reader->getGroups();
	vector<string> attrubutes({ "分组","编号", "姓名","性别", "地址","手机号","家庭电话","工作电话" ,"邮箱" });
	map<string, string> attrToKey;
	attrToKey["分组"] = "group";
	attrToKey["编号"] = "id";
	attrToKey["姓名"] = "name";
	attrToKey["性别"] = "sex";
	attrToKey["地址"] = "address";
	attrToKey["手机号"] = "mobile_phone";
	attrToKey["家庭电话"] = "home_phone";
	attrToKey["工作电话"] = "work_phone";
	attrToKey["邮箱"] = "mail";
	string id;
	string inGroup;
	string toChange;
	string changeInfo;

	// 获取联系人编号和所在分组
	while (true)
	{
		windowsHelper->clearLine(2, 4, 85, "请输入联系人编号:");
		getline(cin, id); cin.clear();
		bool exist = false;
		// 确认编号是否存在
		for (auto contact : allContacts)
		{
			if (contact["id"] == id)
			{
				exist = true;
				inGroup = contact["group"];
				break;
			}
		}
		if (exist)
			break;
		else
		{
			windowsHelper->clearLine(2, 4, 85, "输入错误或编号不存在，请重新输入，");
			system("pause");
		}
	}
	// 获取需要修改的属性
	while (true)
	{
		windowsHelper->clearLine(2, 4, 85, "请输入您要修改的属性:");
		getline(cin, toChange); cin.clear();
		bool exist = false;
		// 确认属性是否存在
		for (auto attrubute : attrubutes)
		{
			if (attrubute == toChange)
			{
				exist = true;
				break;
			}
		}
		if (toChange == "分组" && allGroups.size() == 1)
		{
			windowsHelper->clearLine(2, 4, 85, "当前只有一个分组！:");
			system("pause");
			continue;
		}
		if (exist)
			break;
		else
		{
			windowsHelper->clearLine(2, 4, 85, "输入错误，请重新输入，");
			system("pause");
		}
	}
	// 获得修改信息
	// TODO 代码重复
	while (true)
	{
		if (toChange == "分组")
		{
			while (true)
			{
				windowsHelper->clearLine(2, 4, 85, "请输入目标分组：");
				getline(cin, changeInfo); cin.clear();
				bool ok = true;
				vector<string>::iterator found = find(allGroups.begin(), allGroups.end(), changeInfo);
				if (found == allGroups.end())
				{
					ok = false;
					windowsHelper->clearLine(2, 4, 85, "不存在该分组！请重新输入，");
					system("pause");
				}
				if (changeInfo == inGroup)
				{
					ok = false;
					windowsHelper->clearLine(2, 4, 85, "联系人已经在该组！请重新输入，");
					system("pause");
				}
				if (ok)
					break;
			}
			break;
		}
		else if (toChange == "编号")
		{
			while (true)
			{
				windowsHelper->clearLine(2, 4, 85, "请输入四位数字编号：");
				getline(cin, changeInfo); cin.clear();
				regex pat("^([0-9]{4})$");
				smatch s;
				bool found = regex_search(changeInfo, s, pat);
				bool ok = true;
				if (!found)
				{
					ok = false;
					windowsHelper->clearLine(2, 4, 85, "格式错误！请重新输入，");
					system("pause");
				}
				// 查重
				else
				{
					for (auto contact : allContacts)
					{
						if (contact["id"] == changeInfo)
						{
							ok = false;
							windowsHelper->clearLine(2, 4, 85, "编号存在！请重新输入，");
							system("pause");
							windowsHelper->clearLine(2, 4, 85, "请输入四位数字编号：");
							break;
						}
					}
				}
				if (ok)
					break;
			}
			break;
		}
		else if (toChange == "姓名")
		{
			while (true)
			{
				windowsHelper->clearLine(2, 4, 85, "请输入姓名：");
				bool ok = true;
				getline(cin, changeInfo); cin.clear();
				regex pat("^([^\\s].{0,19})$");
				smatch s;
				bool found = regex_search(changeInfo, s, pat);
				if (!found)
				{
					ok = false;
					windowsHelper->clearLine(2, 4, 85, "格式错误！请重新输入，");
					system("pause");
				}
				if (ok)
					break;
			}
			break;
		}
		else if (toChange == "性别")
		{
			while (true)
			{
				windowsHelper->clearLine(2, 4, 85, "请输入性别：");
				bool ok = true;
				getline(cin, changeInfo); cin.clear();
				if (changeInfo != "男" && changeInfo != "女")
				{
					ok = false;
					windowsHelper->clearLine(2, 4, 85, "格式错误！请重新输入，");
					system("pause");
				}
				if (ok)
					break;
			}
			break;
		}
		else if (toChange == "地址")
		{
			while (true)
			{
				windowsHelper->clearLine(2, 4, 85, "请输入地址：");
				bool ok = true;
				getline(cin, changeInfo); cin.clear();
				regex pat("^([^\\s].{0,19})$");
				smatch s;
				bool found = regex_search(changeInfo, s, pat);
				if (!found)
				{
					ok = false;
					windowsHelper->clearLine(2, 4, 85, "格式错误！请重新输入，");
					system("pause");
				}
				if (ok)
					break;
			}
			break;
		}
		else if (toChange == "手机号")
		{
			while (true)
			{
				windowsHelper->clearLine(2, 4, 85, "请输入手机号：");
				bool ok = true;
				getline(cin, changeInfo); cin.clear();
				regex pat("^(1[3-9]\\d{9})$");
				smatch s;
				bool found = regex_search(changeInfo, s, pat);
				if (!found)
				{
					ok = false;
					windowsHelper->clearLine(2, 4, 85, "格式错误！请重新输入，");
					system("pause");
				}
				if (ok)
					break;
			}
			break;
		}
		else if (toChange == "家庭电话")
		{
			while (true)
			{
				windowsHelper->clearLine(2, 4, 85, "请输入家庭电话：");
				bool ok = true;
				getline(cin, changeInfo); cin.clear();
				regex pat("(^(\\d{2,4}[-_－—]?)?\\d{3,8}([-_－—]?\\d{3,8})?([-_－—]?\\d{1,7})?$)|(^0?1[35]\\d{9}$)");
				smatch s;
				bool found = regex_search(changeInfo, s, pat);
				if (!found)
				{
					ok = false;
					windowsHelper->clearLine(2, 4, 85, "格式错误！请重新输入，");
					system("pause");
				}
				if (ok)
					break;
			}
			break;
		}
		else if (toChange == "工作电话")
		{
			while (true)
			{
				windowsHelper->clearLine(2, 4, 85, "请输入工作电话：");
				bool ok = true;
				getline(cin, changeInfo); cin.clear();
				regex pat("(^(\\d{2,4}[-_－—]?)?\\d{3,8}([-_－—]?\\d{3,8})?([-_－—]?\\d{1,7})?$)|(^0?1[35]\\d{9}$)");
				smatch s;
				bool found = regex_search(changeInfo, s, pat);
				if (!found)
				{
					ok = false;
					windowsHelper->clearLine(2, 4, 85, "格式错误！请重新输入，");
					system("pause");
				}
				if (ok)
					break;
			}
			break;
		}
		else
		{
			while (true)
			{
				windowsHelper->clearLine(2, 4, 85, "请输入邮箱：");
				bool ok = true;
				getline(cin, changeInfo); cin.clear();
				regex pat("^([\\w!#$%&'*+/=?^_`{|}~-]+(?:\.[\\w!#$%&'*+/=?^_`{|}~-]+)*@(?:[\\w](?:[\\w-]*[\\w])?\.)+[\\w](?:[\\w-]*[\\w])?)$");
				smatch s;
				bool found = regex_search(changeInfo, s, pat);
				if (!found)
				{
					ok = false;
					windowsHelper->clearLine(2, 4, 85, "格式错误！请重新输入，");
					system("pause");
				}
				if (ok)
					break;
			}
			break;
		}
	}

	shared_ptr<DataWriter> writer = fac->getDataWriter_shared();
	
	writer->changeContactsInfo(id, inGroup, attrToKey[toChange], changeInfo);
	windowsHelper->clearLine(2, 4, 85, "修改成功！");
	system("pause");

	upDateMngCtxInterface();

}


void AddGroup::doOperation()
{
	shared_ptr<DataReader> reader = fac->getDataReader_shared();
	// 获取分组信息
	vector<string> allGroups = reader->getGroups();

	string group;
	while (true)
	{
		windowsHelper->clearLine(2, 4, 85, "请输入组名：");
		getline(cin, group); cin.clear();
		bool ok = true;
		vector<string>::iterator found = find(allGroups.begin(), allGroups.end(), group);
		if (found != allGroups.end())
		{
			ok = false;
			windowsHelper->clearLine(2, 4, 85, "组名存在！请重新输入，");
			system("pause");
		}
		if (ok)
			break;
	}

	shared_ptr<DataWriter> writer = fac->getDataWriter_shared();
	writer->addGroup(group);
	upDateMngCtxInterface();
}


void RemoveGroup::doOperation()
{
	shared_ptr<DataReader> reader = fac->getDataReader_shared();
	// 获取分组信息
	vector<string> allGroups = reader->getGroups();

	string group;
	while (true)
	{
		windowsHelper->clearLine(2, 4, 85, "请输入要删除组名：");
		getline(cin, group); cin.clear();
		bool ok = true;
		vector<string>::iterator found = find(allGroups.begin(), allGroups.end(), group);
		if (found == allGroups.end())
		{
			ok = false;
			windowsHelper->clearLine(2, 4, 85, "组名不存在！请重新输入，");
			system("pause");
		}
		if (ok)
			break;
	}

	shared_ptr<DataWriter> writer = fac->getDataWriter_shared();
	writer->removeGroup(group);
	upDateMngCtxInterface();
}


void GoBack::doOperation()
{
	windowsHelper->setColor(3);
	system("cls");
	windowsHelper->setWindowsAttribute(50, 30, "通信录管理系统");
	shared_ptr<InterfaceFactory> faceFac = fac->getInterfaceFactory();
	shared_ptr<Interface> mainFace = faceFac->getInstance_shared(e_MainInterface);
	mainFace->show();
	shared_ptr<GetSelectionFactory> getSelecFac = fac->getSelectionFactory();
	shared_ptr<GetSelection> mainFaceSelec = getSelecFac->getInstance_shared(e_GetMainInterfaceSelection);
	int key = mainFaceSelec->Select();
	shared_ptr<ContextFactory> ctxFac = fac->getContextFactory();
	shared_ptr<Context> mainFaceReact = ctxFac->getInstance_shared(e_MainInterfaceReaction);
	mainFaceReact->reactToSelection(key);
}


void ExitSystem::doOperation()
{
	windowsHelper->setColor(3);
	system("cls");
	shared_ptr<Interface> exitFace = faceFac->getInstance_shared(e_ExitSystemInterface);
	exitFace->show();
	windowsHelper->setCursorPosition(15, 7);
	system("pause");
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
	// 管理联系人
	case 3:
		oper = operFac->getInstance_shared(e_ManageContacts);
		oper->doOperation();
		break;
	// 退出系统
	case 4:
		oper = operFac->getInstance_shared(e_ExitSystem);
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
		oper = operFac->getInstance_shared(e_GoBack);
		oper->doOperation();
		break;
	default:
		break;
	}
}

void FindContactsInterfaceReaction::reactToSelection(int key)
{
	switch (key)
	{
		// 返回主页面
	case 1:
		oper = operFac->getInstance_shared(e_GoBack);
		oper->doOperation();
		break;
	default:
		break;
	}
}


void ManageContactsInterfaceReaction::reactToSelection(int key)
{
	switch (key)
	{
	// 添加联系人
	case 1:
		oper = operFac->getInstance_shared(e_AddContacts);
		oper->doOperation();
		break;
	// 删除联系人
	case 2:
		oper = operFac->getInstance_shared(e_RemoveContacts);
		oper->doOperation();
		break;
	// 移动联系人
	case 3:
		oper = operFac->getInstance_shared(e_MoveContacts);
		oper->doOperation();
		break;
	// 编辑信息
	case 4:
		oper = operFac->getInstance_shared(e_EditContactsInfo);
		oper->doOperation();
		break;
	// 添加分组
	case 5:
		oper = operFac->getInstance_shared(e_AddGroup);
		oper->doOperation();
		break;
	// 删除分组
	case 6:
		oper = operFac->getInstance_shared(e_RemoveGroup);
		oper->doOperation();
		break;
	// 返回
	case 7:
		oper = operFac->getInstance_shared(e_GoBack);
		oper->doOperation();
		break;
	default:
		break;
	}
}
