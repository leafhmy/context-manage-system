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
	int ch;  // ��¼����ֵ
	int key = 1;  // ��¼ѡ�����ʼѡ���һ��
	bool flag = false;
	windowsHelper->toSelect(20, 10, "�ҵ���ϵ��");
	while ((ch = _getch()))  // ��������
	{
		switch (ch)  // ��������
		{
			// UP�Ϸ����
		case 72:
			if (key > 1)//����ʱѡ����Ϊ��һ��ʱ��UP�Ϸ������Ч
			{
				switch (key)
				{
				case(2):
				{
					windowsHelper->selected(20, 12, "������ϵ��");  // ����ѡ����ȡ���ұ���ɫ
					windowsHelper->toSelect(20, 10, "�ҵ���ϵ��");  // ����ѡ�������ñ���ɫ

					--key;
					break;
				}
				case(3):
				{
					windowsHelper->selected(20, 14, "�����ҵ���ϵ��");
					windowsHelper->toSelect(20, 12, "������ϵ��");

					--key;
					break;
				}
				case(4):
				{
					windowsHelper->selected(20, 16, "�˳�ϵͳ");
					windowsHelper->toSelect(20, 14, "�����ҵ���ϵ��");

					--key;
					break;
				}
				}
			}
			break;
			// DOWN�·����
		case 80:
			if (key < 4)
			{
				switch (key)
				{
				case(1):
				{
					windowsHelper->selected(20, 10, "�ҵ���ϵ��");
					windowsHelper->toSelect(20, 12, "������ϵ��");

					++key;
					break;
				}
				case(2):
				{
					windowsHelper->selected(20, 12, "������ϵ��");
					windowsHelper->toSelect(20, 14, "�����ҵ���ϵ��");

					++key;
					break;
				}

				case(3):
				{
					windowsHelper->selected(20, 14, "�����ҵ���ϵ��");
					windowsHelper->toSelect(20, 16, "�˳�ϵͳ");

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

		case 13://Enter�س���
			flag = true;
			break;
		default://��Ч����
			break;
		}
		if (flag) break;//����Enter�س���ȷ�ϣ��˳��������ѭ��
	}
	return key;
}

int GetMyContactsInterfaceSelection::Select()
{
	int ch;
	int key = 1;
	bool flag = false;
	// windowsHelper->print(3, 25, "����");
	windowsHelper->toSelect(3, 25, "����");
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
	// windowsHelper->setWindowsAttribute(50, 40, "test");
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
	windowsHelper->print(2, 2, "��������ϵ����Ϣ��");
	string contactInfo;
	// �û����������Ϣ
	// ���Ȳ��ܳ���50
	while (true)
	{
		getline(cin, contactInfo); cin.clear();
		if (contactInfo.length() > 50 || contactInfo.length() == 0)
		{
			windowsHelper->print(2, 2, "�����������������,");
			system("pause");
			windowsHelper->clearLine(2, 2, 50, "��������ϵ����Ϣ��");
		}
		else
			break;
	}

	// ������Ϣ
	shared_ptr<DataReader> reader = fac->getDataReader_shared();
	// ��ȡ������ϵ��
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
	// �ı����̨���
	if(foundContacts.size()!=0)
		windowsHelper->setWindowsAttribute(80, 30, "ͨ��¼����ϵͳ");

	//windowsHelper->print(2, 2, "��������ϵ����Ϣ��");
	windowsHelper->setCursorPosition(2, 2);
	cout << "���ҵ� " << foundContacts.size() << " ����¼";
	vector<string> attrubute({ "����","���", "����","�Ա�", "��ַ","�ֻ���","��ͥ�绰","�����绰" ,"����" });
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
	// �ҵ���ϵ��
	case 1:
		oper = operFac->getInstance_shared(e_MyContacts);
		oper->doOperation();
		break;
	// ������ϵ��
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
	// ������ҳ��
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