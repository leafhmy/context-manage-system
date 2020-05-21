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
	// windowsHelper->print(17, 5, "�ҵ���ϵ��");
	// windowsHelper->print(12, 7, "�ҵķ��飺");
	// ��ӡ���з���
	vector<string> allGroups = reader->getGroups();
	int pos = 10;
	for (auto groupName : allGroups)
	{
		windowsHelper->setCursorPosition(17, pos);
		cout << groupName;
	}

	windowsHelper->setCursorPosition(3, 30);
	windowsHelper->print(3, 25, "�����������Բ鿴��");
	string groupName = "Ĭ�Ϸ���";
	// TODO �����������ֵ��ַ�����bug
	// ��Ϊ�����ַ���
	while (true)
	{
		//cin >> groupName; 
		getline(cin, groupName); cin.clear();
		if (find(allGroups.begin(), allGroups.end(), groupName) == allGroups.end())
		{
			windowsHelper->print(3, 25, "�����������������,");
			system("pause");
			windowsHelper->clearLine(3, 25, 50, "�����������Բ鿴��");
		}
		else
			break;
	}
	system("cls");
	windowsHelper->print(17, 5, groupName);
	// TODO ��ӡ�����µ�������ϵ�˵������͵绰���루�ֻ��ţ���ͥ�绰�ţ��칫�绰���룩
	vector<map<string, string>> contactsInGroup = reader->getContactsInGroup(groupName);
	windowsHelper->print(8, 8, "����");
	windowsHelper->print(16, 8, "�ֻ���");
	windowsHelper->print(24, 8, "��ͥ�绰��");
	windowsHelper->print(32, 8, "�칫�绰��");

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
	// �ҵ���ϵ��
	case 1:
		oper = operFac->getInstance_shared(e_MyContacts);
		oper->doOperation();
		break;
	default:
		break;
	}
}