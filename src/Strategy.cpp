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
				case 2:
					windowsHelper->selected(20, 12, "������ϵ��");  // ����ѡ����ȡ���ұ���ɫ
					windowsHelper->toSelect(20, 10, "�ҵ���ϵ��");  // ����ѡ�������ñ���ɫ
					--key;
					break;
				case 3:
					windowsHelper->selected(20, 14, "�����ҵ���ϵ��");
					windowsHelper->toSelect(20, 12, "������ϵ��");
					--key;
					break;
				case 4:
					windowsHelper->selected(20, 16, "�˳�ϵͳ");
					windowsHelper->toSelect(20, 14, "�����ҵ���ϵ��");
					--key;
					break;
				}
			}
			break;
		// DOWN�·����
		case 80:
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					windowsHelper->selected(20, 10, "�ҵ���ϵ��");
					windowsHelper->toSelect(20, 12, "������ϵ��");
					++key;
					break;
				case 2:
					windowsHelper->selected(20, 12, "������ϵ��");
					windowsHelper->toSelect(20, 14, "�����ҵ���ϵ��");
					++key;
					break;
				case 3:
					windowsHelper->selected(20, 14, "�����ҵ���ϵ��");
					windowsHelper->toSelect(20, 16, "�˳�ϵͳ");
					++key;
					break;
				default:
					break;
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

int GetManageContactsInterfaceSelection::Select()
{
	int ch;  // ��¼����ֵ
	int key = 1;  // ��¼ѡ�����ʼѡ���һ��
	bool flag = false;
	windowsHelper->toSelect(2, 6, "�����ϵ��");
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
				case 2:
					windowsHelper->selected(2, 8, "ɾ����ϵ��");  // ����ѡ����ȡ���ұ���ɫ
					windowsHelper->toSelect(2, 6, "�����ϵ��");  // ����ѡ�������ñ���ɫ
					--key;
					break;
				case 3:
					windowsHelper->selected(2, 10, "�ƶ���ϵ��");
					windowsHelper->toSelect(2, 8, "ɾ����ϵ��");
					--key;
					break;
				case 4:
					windowsHelper->selected(2, 12, "�༭��Ϣ");
					windowsHelper->toSelect(2, 10, "�ƶ���ϵ��");
					--key;
					break;
				case 5:
					windowsHelper->selected(2, 14, "��ӷ���");
					windowsHelper->toSelect(2, 12, "�༭��Ϣ");
					--key;
					break;
				case 6:
					windowsHelper->selected(2, 16, "ɾ������");
					windowsHelper->toSelect(2, 14, "��ӷ���");
					--key;
					break;
				case 7:
					windowsHelper->selected(2, 18, "����");
					windowsHelper->toSelect(2, 16, "ɾ������");
					--key;
					break;
				}
			}
			break;
		// DOWN�·����
		case 80:
			if (key < 7)
			{
				switch (key)
				{
				case 1:
					windowsHelper->selected(2, 6, "�����ϵ��");
					windowsHelper->toSelect(2, 8, "ɾ����ϵ��");
					++key;
					break;
				case 2:
					windowsHelper->selected(2, 8, "ɾ����ϵ��");
					windowsHelper->toSelect(2, 10, "�ƶ���ϵ��");
					++key;
					break;
				case 3:
					windowsHelper->selected(2, 10, "�ƶ���ϵ��");
					windowsHelper->toSelect(2, 12, "�༭��Ϣ");
					++key;
					break;
				case 4:
					windowsHelper->selected(2, 12, "�༭��Ϣ");
					windowsHelper->toSelect(2, 14, "��ӷ���");
					++key;
					break;
				case 5:
					windowsHelper->selected(2, 14, "��ӷ���");
					windowsHelper->toSelect(2, 16, "ɾ������");
					++key;
					break;
				case 6:
					windowsHelper->selected(2, 16, "ɾ������");
					windowsHelper->toSelect(2, 18, "����");
					++key;
					break;
				default:
					break;
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

int GetFindContactsInterfaceSelection::Select()
{
	// windowsHelper->print(2, 4, "����");
	int ch;
	int key = 1;
	bool flag = false;
	windowsHelper->toSelect(2, 4, "����");
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
	operFac = fac->getOperationFactory();
}

Operation::~Operation()
{
	delete fac;
}

void Operation::printAllContacts()
{
	windowsHelper->setColor(3);
	shared_ptr<DataReader> reader = fac->getDataReader_shared();
	// ��ȡ������ϵ��
	vector<map<string, string>> allContacts = reader->getAllContacts();

	// windowsHelper->print(35, 2, "������ϵ��");
	// windowsHelper->print(2, 6, "�����ϵ��");
	// windowsHelper->print(2, 8, "�ƶ���ϵ��");
	// windowsHelper->print(2, 10, "�༭��Ϣ");
	// windowsHelper->print(2, 12, "��ӷ���");
	// windowsHelper->print(2, 14, "ɾ������");

	vector<string> attrubute({ "����","���", "����","�Ա�", "�ֻ���","��ͥ�绰","�����绰" ,"����", "��ַ" });
	for (unsigned i = 0, x = 8, y = 6; i < attrubute.size(); i++)
	{
		windowsHelper->print(x, y, attrubute[i]);
		if (attrubute[i] == "���" || attrubute[i] == "�Ա�")
			x += 4;
		else if (attrubute[i] == "����")
			x += 10;
		else
			x += 8;	
	}

	int xPos = 8, yPos = 8;
	for (auto contact : allContacts)
	{
		windowsHelper->print(xPos, yPos, contact["group"]); xPos += 8;
		windowsHelper->print(xPos, yPos, contact["id"]); xPos += 4;
		windowsHelper->print(xPos, yPos, contact["name"]); xPos += 8;
		windowsHelper->print(xPos, yPos, contact["sex"]); xPos += 4;
		windowsHelper->print(xPos, yPos, contact["mobile_phone"]); xPos += 8;
		windowsHelper->print(xPos, yPos, contact["home_phone"]); xPos += 8;
		windowsHelper->print(xPos, yPos, contact["work_phone"]); xPos += 8;
		windowsHelper->print(xPos, yPos, contact["mail"]); xPos += 10;
		windowsHelper->print(xPos, yPos, contact["address"]); xPos = 8;
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
	// ��ӡ���з���
	vector<string> allGroups = reader->getGroups();
	int yPos1 = 10;
	int xPos1 = 17;
	for (auto groupName : allGroups)
	{
		windowsHelper->print(xPos1, yPos1, groupName);
		yPos1 += 2;
	}

	windowsHelper->setCursorPosition(3, 30);
	windowsHelper->print(3, 25, "�����������Բ鿴��");
	string groupName = "Ĭ�Ϸ���";

	bool success = true;
	while (true)
	{
		getline(cin, groupName); cin.clear();
		if (find(allGroups.begin(), allGroups.end(), groupName) == allGroups.end())
		{
			int ch;
			windowsHelper->print(3, 25, "������󣡰�������������룬��Esc������");
			ch = _getch();
			if (ch != 27)
				windowsHelper->clearLine(3, 25, 50, "�����������Բ鿴��");
			else
			{
				success = false;
				shared_ptr<Operation> goBack = operFac->getInstance_shared(e_GoBack);
				goBack->doOperation();
				break;
			}
		}
		else
			break;
	}
	if (success)
	{
		system("cls");
		// ��ӡ�����µ�������ϵ�˵������͵绰���루�ֻ��ţ���ͥ�绰�ţ��칫�绰���룩
		vector<map<string, string>> contactsInGroup = reader->getContactsInGroup(groupName);
		int size = contactsInGroup.size();
		windowsHelper->print(17, 5, groupName); cout << " ����" << size << "����";
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
			xPos = 8;
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
}

void FindContacts::doOperation()
{
	windowsHelper->setColor(3);
	system("cls");
	string contactInfo;
	bool success = true;
	// �û����������Ϣ
	while (true)
	{
		windowsHelper->clearLine(2, 2, 50, "��������ϵ����Ϣ��");
		getline(cin, contactInfo); cin.clear();
		if (contactInfo.length() > 30 || contactInfo.length() == 0)
		{
			int ch;
			windowsHelper->clearLine(2, 2, 50, "������󣡰�������������룬��Esc������");
			ch = _getch();
			if (ch != 27)
				continue;
			else
			{
				success = false;
				shared_ptr<Operation> goBack = operFac->getInstance_shared(e_GoBack);
				goBack->doOperation();
				break;
			}
		}
		else
			break;
	}

	if (success)
	{
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
		windowsHelper->setWindowsCols(85);
		windowsHelper->setCursorPosition(2, 2);
		cout << "���ҵ� " << foundContacts.size() << " ����¼";
		vector<string> attrubute({ "����","���", "����","�Ա�", "�ֻ���","��ͥ�绰","�����绰" ,"����", "��ַ" });
		for (unsigned i = 0, x = 8, y = 6; i < attrubute.size(); i++)
		{
			windowsHelper->print(x, y, attrubute[i]);
			if (attrubute[i] == "���" || attrubute[i] == "�Ա�")
				x += 4;
			else if (attrubute[i] == "����")
				x += 10;
			else
				x += 8;
		}

		int xPos = 8, yPos = 8;
		for (auto contact : foundContacts)
		{
			windowsHelper->print(xPos, yPos, contact["group"]); xPos += 8;
			windowsHelper->print(xPos, yPos, contact["id"]); xPos += 4;
			windowsHelper->print(xPos, yPos, contact["name"]); xPos += 8;
			windowsHelper->print(xPos, yPos, contact["sex"]); xPos += 4;
			windowsHelper->print(xPos, yPos, contact["mobile_phone"]); xPos += 8;
			windowsHelper->print(xPos, yPos, contact["home_phone"]); xPos += 8;
			windowsHelper->print(xPos, yPos, contact["work_phone"]); xPos += 8;
			windowsHelper->print(xPos, yPos, contact["mail"]); xPos += 10;
			windowsHelper->print(xPos, yPos, contact["address"]); xPos = 8;
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
		// �ָ�����̨��С
		windowsHelper->setWindowsCols(50);
		findCtxFaceReact->reactToSelection(key);
	}
}

void ManageContacts::doOperation()
{
	windowsHelper->setColor(3);
	system("cls");
	windowsHelper->setWindowsCols(85);
	upDateMngCtxInterface();
}

void AddContacts::doOperation()
{
	shared_ptr<DataReader> reader = fac->getDataReader_shared();
	// ��ȡ������Ϣ
	vector<string> allGroups = reader->getGroups();
	// ��ȡ������ϵ��
	vector<map<string, string>> allContacts = reader->getAllContacts();
	string group, id, name, sex, address, mobile_phone, home_phone, work_phone, mail;

	// ��������
	while (true)
	{
		windowsHelper->clearLine(2, 4, 85, "������Ŀ����飺");
		getline(cin, group); cin.clear();
		bool ok = true;
		vector<string>::iterator found = find(allGroups.begin(), allGroups.end(), group);
		if (group.length() == 0)
		{
			group = "Ĭ�Ϸ���";
			break;
		}
		if (found == allGroups.end())
		{
			ok = false;
			windowsHelper->clearLine(2, 4, 85, "�����ڸ÷��飡���������룬");
			system("pause");
		}
		if (ok)
			break;
	}
	// ������
	while (true)
	{
		windowsHelper->clearLine(2, 4, 85, "��������λ���ֱ�ţ�");
		getline(cin, id); cin.clear();
		regex pat("^([0-9]{4})$");
		smatch s;
		bool found = regex_search(id, s, pat);
		bool ok = true;
		if (!found)
		{
			ok = false;
			windowsHelper->clearLine(2, 4, 85, "��ʽ�������������룬");
			system("pause");
		}
		// ����
		else
		{
			for (auto contact : allContacts)
			{
				if (contact["id"] == id)
				{
					ok = false;
					windowsHelper->clearLine(2, 4, 85, "��Ŵ��ڣ����������룬");
					system("pause");
					windowsHelper->clearLine(2, 4, 85, "��������λ���ֱ�ţ�");
					break;
				}
			}
		}
		if (ok)
			break;
	}
	// ��������
	while (true)
	{
		windowsHelper->clearLine(2, 4, 85, "������������");
		bool ok = true;
		getline(cin, name); cin.clear();
		regex pat("^([^\\s].{0,15})$");
		smatch s;
		bool found = regex_search(name, s, pat);
		if (!found)
		{
			ok = false;
			windowsHelper->clearLine(2, 4, 85, "��ʽ�������������룬");
			system("pause");
		}
		if (ok)
			break;
	}
	// �����Ա�
	while (true)
	{
		windowsHelper->clearLine(2, 4, 85, "�������Ա�");
		bool ok = true;
		getline(cin, sex); cin.clear();
		if (sex != "��" && sex != "Ů")
		{
			ok = false;
			windowsHelper->clearLine(2, 4, 85, "��ʽ�������������룬");
			system("pause");
		}
		if (ok)
			break;
	}
	// �����ַ
	while (true)
	{
		windowsHelper->clearLine(2, 4, 85, "�������ַ��");
		bool ok = true;
		getline(cin, address); cin.clear();
		if (address.length() == 0)
			break;
		regex pat("^([^\\s].{0,29})$");
		smatch s;
		bool found = regex_search(id, s, pat);
		if (!found)
		{
			ok = false;
			windowsHelper->clearLine(2, 4, 85, "��ʽ�������������룬");
			system("pause");
		}
		if (ok)
			break;
	}
	bool EnteredPhone = false;
	// �����ֻ���
	while (true)
	{
		windowsHelper->clearLine(2, 4, 85, "�������ֻ��ţ�");
		bool ok = true;
		getline(cin, mobile_phone); cin.clear();
		if (mobile_phone.length() == 0)
			break;
		regex pat("^(1[3-9]\\d{9})$");
		smatch s;
		bool found = regex_search(mobile_phone, s, pat);
		if (!found)
		{
			ok = false;
			windowsHelper->clearLine(2, 4, 85, "��ʽ�������������룬");
			system("pause");
		}
		if (ok)
		{
			EnteredPhone = true;
			break;
		}
	}
	// �����ͥ�绰
	while (true)
	{
		windowsHelper->clearLine(2, 4, 85, "�������ͥ�绰��");
		bool ok = true;
		getline(cin, home_phone); cin.clear();
		if (home_phone.length() == 0)
			break;
		regex pat("^([^\\s][\\d\\s-]{0,15})$");
		smatch s;
		bool found = regex_search(home_phone, s, pat);
		if (!found)
		{
			ok = false;
			windowsHelper->clearLine(2, 4, 85, "��ʽ�������������룬");
			system("pause");
		}
		if (ok)
		{
			EnteredPhone = true;
			break;
		}
	}
	// ���빤���绰
	while (true)
	{
		windowsHelper->clearLine(2, 4, 85, "�����빤���绰��");
		bool ok = true;
		getline(cin, work_phone); cin.clear();
		if (work_phone.length() == 0)
		{
			if (EnteredPhone == false)
			{
				windowsHelper->clearLine(2, 4, 85, "��������һ���绰��");
				system("pause");
				continue;
			}
			else
				break;
		}
		regex pat("^([^\\s][\\d\\s-]{0,15})$");
		smatch s;
		bool found = regex_search(work_phone, s, pat);
		if (!found)
		{
			ok = false;
			windowsHelper->clearLine(2, 4, 85, "��ʽ�������������룬");
			system("pause");
		}
		if (ok)
			break;
	}
	// ��������
	while (true)
	{
		windowsHelper->clearLine(2, 4, 85, "���������䣺");
		bool ok = true;
		getline(cin, mail); cin.clear();
		if (mail.length() == 0)
			break;
		regex pat("^[a-zA-Z0-9_-]+@[a-zA-Z0-9_-]+(\\.[a-zA-Z0-9_-]+)+$");
		smatch s;
		bool found = regex_search(mail, s, pat);
		if (!found || mail.length() > 20)
		{
			ok = false;
			windowsHelper->clearLine(2, 4, 85, "��ʽ�������������룬");
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
	windowsHelper->clearLine(2, 4, 85, "��ӳɹ���");
	system("pause");
	upDateMngCtxInterface();
}

void RemoveContacts::doOperation()
{
	shared_ptr<DataReader> reader = fac->getDataReader_shared();
	// ��ȡ������ϵ��
	vector<map<string, string>> allContacts = reader->getAllContacts();

	string removeId;
	string inGroup;
	bool success = true;
	while (true)
	{
		windowsHelper->clearLine(2, 4, 85, "��������ϵ�˱�ţ�");
		getline(cin, removeId); cin.clear();
		bool exist = false;
		// ȷ�ϱ���Ƿ����
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
			int ch;
			windowsHelper->clearLine(2, 4, 85, "���������Ų����ڣ���������������룬��Esc������");
			ch = _getch();
			if (ch != 27)
				continue;
			else
			{
				success = false;
				shared_ptr<Operation> mngContacts = operFac->getInstance_shared(e_ManageContacts);
				mngContacts->doOperation();
				break;
			}

		}
	}
	if (success)
	{
		shared_ptr<DataWriter> writer = fac->getDataWriter_shared();
		writer->removeContact(inGroup, removeId);
		windowsHelper->clearLine(2, 4, 85, "ɾ���ɹ���");
		system("pause");

		upDateMngCtxInterface();
	}

}

void MoveContacts::doOperation()
{
	shared_ptr<DataReader> reader = fac->getDataReader_shared();
	// ��ȡ������ϵ��
	vector<map<string, string>> allContacts = reader->getAllContacts();
	// ��ȡ������Ϣ
	vector<string> allGroups = reader->getGroups();

	string moveId;
	string inGroup;
	string destinGroup;
	bool success = true;
	// ��ȡ��ϵ�˱�ź����ڷ���
	while (true)
	{
		windowsHelper->clearLine(2, 4, 85, "��������ϵ�˱��:");
		getline(cin, moveId); cin.clear();
		bool exist = false;
		// ȷ�ϱ���Ƿ����
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
			int ch;
			windowsHelper->clearLine(2, 4, 85, "���������Ų����ڣ���������������룬��Esc������");
			ch = _getch();
			if (ch != 27)
				continue;
			else
			{
				success = false;
				shared_ptr<Operation> mngContacts = operFac->getInstance_shared(e_ManageContacts);
				mngContacts->doOperation();
				break;
			}
		}
	}
	// ��ȡĿ�����
	while (success)
	{
		windowsHelper->clearLine(2, 4, 85, "������Ҫ�ƶ����ķ��飺");
		getline(cin, destinGroup); cin.clear();
		if (destinGroup == inGroup)
		{
			int ch;
			windowsHelper->clearLine(2, 4, 85, "��ϵ���Ѿ��ڸ��飡��������������룬��Esc������");
			ch = _getch();
			if (ch != 27)
				continue;
			else
			{
				success = false;
				shared_ptr<Operation> mngContacts = operFac->getInstance_shared(e_ManageContacts);
				mngContacts->doOperation();
				break;
			}
		}
		bool exist = false;
		// ȷ��Ŀ������Ƿ����
		if (find(allGroups.begin(), allGroups.end(), destinGroup) != allGroups.end())
		{
			exist = true;
			break;
		}
		if (exist)
			break;
		else
		{
			int ch;
			windowsHelper->clearLine(2, 4, 85, "��������÷��鲻���ڣ���������������룬��Esc������");
			ch = _getch();
			if (ch != 27)
				continue;
			else
			{
				success = false;
				shared_ptr<Operation> mngContacts = operFac->getInstance_shared(e_ManageContacts);
				mngContacts->doOperation();
				break;
			}
		}
	}

	if (success)
	{
		shared_ptr<DataWriter> writer = fac->getDataWriter_shared();
		writer->moveContact(moveId, inGroup, destinGroup);
		windowsHelper->clearLine(2, 4, 85, "�ƶ��ɹ���");
		system("pause");

		upDateMngCtxInterface();
	}
}

void EditContactsInfo::doOperation()
{
	shared_ptr<DataReader> reader = fac->getDataReader_shared();
	// ��ȡ������ϵ��
	vector<map<string, string>> allContacts = reader->getAllContacts();
	// ��ȡ������Ϣ
	vector<string> allGroups = reader->getGroups();
	vector<string> attrubutes({ "����","���", "����","�Ա�", "��ַ","�ֻ���","��ͥ�绰","�����绰" ,"����" });
	map<string, string> attrToKey;
	attrToKey["����"] = "group";
	attrToKey["���"] = "id";
	attrToKey["����"] = "name";
	attrToKey["�Ա�"] = "sex";
	attrToKey["��ַ"] = "address";
	attrToKey["�ֻ���"] = "mobile_phone";
	attrToKey["��ͥ�绰"] = "home_phone";
	attrToKey["�����绰"] = "work_phone";
	attrToKey["����"] = "mail";
	string id;
	string inGroup;
	string toChange;
	string changeInfo;

	// ��ȡ��ϵ�˱�ź����ڷ���
	while (true)
	{
		windowsHelper->clearLine(2, 4, 85, "��������ϵ�˱��:");
		getline(cin, id); cin.clear();
		bool exist = false;
		// ȷ�ϱ���Ƿ����
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
			windowsHelper->clearLine(2, 4, 85, "���������Ų����ڣ����������룬");
			system("pause");
		}
	}
	// ��ȡ��Ҫ�޸ĵ�����
	while (true)
	{
		windowsHelper->clearLine(2, 4, 85, "��������Ҫ�޸ĵ�����:");
		getline(cin, toChange); cin.clear();
		bool exist = false;
		// ȷ�������Ƿ����
		for (auto attrubute : attrubutes)
		{
			if (attrubute == toChange)
			{
				exist = true;
				break;
			}
		}
		if (toChange == "����" && allGroups.size() == 1)
		{
			windowsHelper->clearLine(2, 4, 85, "��ǰֻ��һ�����飡:");
			system("pause");
			continue;
		}
		if (exist)
			break;
		else
		{
			windowsHelper->clearLine(2, 4, 85, "����������������룬");
			system("pause");
		}
	}
	// ����޸���Ϣ
	// TODO �����ظ�
	while (true)
	{
		if (toChange == "����")
		{
			while (true)
			{
				windowsHelper->clearLine(2, 4, 85, "������Ŀ����飺");
				getline(cin, changeInfo); cin.clear();
				bool ok = true;
				vector<string>::iterator found = find(allGroups.begin(), allGroups.end(), changeInfo);
				if (found == allGroups.end())
				{
					ok = false;
					windowsHelper->clearLine(2, 4, 85, "�����ڸ÷��飡���������룬");
					system("pause");
					continue;
				}
				if (changeInfo == inGroup)
				{
					ok = false;
					windowsHelper->clearLine(2, 4, 85, "��ϵ���Ѿ��ڸ��飡���������룬");
					system("pause");
					continue;
				}
				if (ok)
					break;
			}
			break;
		}
		else if (toChange == "���")
		{
			while (true)
			{
				windowsHelper->clearLine(2, 4, 85, "��������λ���ֱ�ţ�");
				getline(cin, changeInfo); cin.clear();
				regex pat("^([0-9]{4})$");
				smatch s;
				bool found = regex_search(changeInfo, s, pat);
				bool ok = true;
				if (!found)
				{
					ok = false;
					windowsHelper->clearLine(2, 4, 85, "��ʽ�������������룬");
					system("pause");
				}
				// ����
				else
				{
					for (auto contact : allContacts)
					{
						if (contact["id"] == changeInfo)
						{
							ok = false;
							windowsHelper->clearLine(2, 4, 85, "��Ŵ��ڣ����������룬");
							system("pause");
							windowsHelper->clearLine(2, 4, 85, "��������λ���ֱ�ţ�");
							break;
						}
					}
				}
				if (ok)
					break;
			}
			break;
		}
		else if (toChange == "����")
		{
			while (true)
			{
				windowsHelper->clearLine(2, 4, 85, "������������");
				bool ok = true;
				getline(cin, changeInfo); cin.clear();
				regex pat("^([^\\s].{0,15})$");
				smatch s;
				bool found = regex_search(changeInfo, s, pat);
				if (!found)
				{
					ok = false;
					windowsHelper->clearLine(2, 4, 85, "��ʽ�������������룬");
					system("pause");
				}
				if (ok)
					break;
			}
			break;
		}
		else if (toChange == "�Ա�")
		{
			while (true)
			{
				windowsHelper->clearLine(2, 4, 85, "�������Ա�");
				bool ok = true;
				getline(cin, changeInfo); cin.clear();
				if (changeInfo != "��" && changeInfo != "Ů")
				{
					ok = false;
					windowsHelper->clearLine(2, 4, 85, "��ʽ�������������룬");
					system("pause");
				}
				if (ok)
					break;
			}
			break;
		}
		else if (toChange == "��ַ")
		{
			while (true)
			{
				windowsHelper->clearLine(2, 4, 85, "�������ַ��");
				bool ok = true;
				getline(cin, changeInfo); cin.clear();
				regex pat("^([^\\s].{0,29})$");
				smatch s;
				bool found = regex_search(changeInfo, s, pat);
				if (!found)
				{
					ok = false;
					windowsHelper->clearLine(2, 4, 85, "��ʽ�������������룬");
					system("pause");
				}
				if (ok)
					break;
			}
			break;
		}
		else if (toChange == "�ֻ���")
		{
			while (true)
			{
				windowsHelper->clearLine(2, 4, 85, "�������ֻ��ţ�");
				bool ok = true;
				getline(cin, changeInfo); cin.clear();
				regex pat("^(1[3-9]\\d{9})$");
				smatch s;
				bool found = regex_search(changeInfo, s, pat);
				if (!found)
				{
					ok = false;
					windowsHelper->clearLine(2, 4, 85, "��ʽ�������������룬");
					system("pause");
				}
				if (ok)
					break;
			}
			break;
		}
		else if (toChange == "��ͥ�绰")
		{
			while (true)
			{
				windowsHelper->clearLine(2, 4, 85, "�������ͥ�绰��");
				bool ok = true;
				getline(cin, changeInfo); cin.clear();
				regex pat("^([^\\s][\\d\\s-]{0,15})$");
				smatch s;
				bool found = regex_search(changeInfo, s, pat);
				if (!found)
				{
					ok = false;
					windowsHelper->clearLine(2, 4, 85, "��ʽ�������������룬");
					system("pause");
				}
				if (ok)
					break;
			}
			break;
		}
		else if (toChange == "�����绰")
		{
			while (true)
			{
				windowsHelper->clearLine(2, 4, 85, "�����빤���绰��");
				bool ok = true;
				getline(cin, changeInfo); cin.clear();
				regex pat("^([^\\s][\\d\\s-]{0,15})$");
				smatch s;
				bool found = regex_search(changeInfo, s, pat);
				if (!found)
				{
					ok = false;
					windowsHelper->clearLine(2, 4, 85, "��ʽ�������������룬");
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
				windowsHelper->clearLine(2, 4, 85, "���������䣺");
				bool ok = true;
				getline(cin, changeInfo); cin.clear();
				regex pat("^[a-zA-Z0-9_-]+@[a-zA-Z0-9_-]+(\\.[a-zA-Z0-9_-]+)+$");
				smatch s;
				bool found = regex_search(changeInfo, s, pat);
				if (!found || changeInfo.length() > 20)
				{
					ok = false;
					windowsHelper->clearLine(2, 4, 85, "��ʽ�������������룬");
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
	windowsHelper->clearLine(2, 4, 85, "�޸ĳɹ���");
	system("pause");

	upDateMngCtxInterface();

}

void AddGroup::doOperation()
{
	shared_ptr<DataReader> reader = fac->getDataReader_shared();
	// ��ȡ������Ϣ
	vector<string> allGroups = reader->getGroups();
	string group;
	bool success = true;
	while (true)
	{
		windowsHelper->clearLine(2, 4, 85, "������������");
		getline(cin, group); cin.clear();
		vector<string>::iterator found = find(allGroups.begin(), allGroups.end(), group);
		regex pat("^([^\\s].{0,15})$");
		smatch s;
		bool found2 = regex_search(group, s, pat);
		if (!found2)
		{
			int ch;
			windowsHelper->clearLine(2, 4, 85, "��ʽ���󣡰�������������룬��Esc������");
			ch = _getch();
			if (ch != 27)
				continue;
			else
			{
				success = false;
				shared_ptr<Operation> mngContacts = operFac->getInstance_shared(e_ManageContacts);
				mngContacts->doOperation();
				break;
			}
		}
		if (found != allGroups.end() && success)
		{
			windowsHelper->clearLine(2, 4, 85, "�������ڣ���������������룬��Esc������");
			int ch;
			ch = _getch();
			if (ch != 27)
				continue;
			else
			{
				success = false;
				shared_ptr<Operation> mngContacts = operFac->getInstance_shared(e_ManageContacts);
				mngContacts->doOperation();
				break;
			}
		}
		if (success)
			break;
	}
	if (success)
	{
		shared_ptr<DataWriter> writer = fac->getDataWriter_shared();
		writer->addGroup(group);
		windowsHelper->clearLine(2, 4, 85, "��ӳɹ�������ӽ����Ѱɣ�");
		system("pause");
		upDateMngCtxInterface();
	}
}

void RemoveGroup::doOperation()
{
	shared_ptr<DataReader> reader = fac->getDataReader_shared();
	// ��ȡ������Ϣ
	vector<string> allGroups = reader->getGroups();

	string group;
	bool success = true;
	while (true)
	{
		windowsHelper->clearLine(2, 4, 85, "���˲�����ɾ�������µ�������ϵ�ˣ�������Ҫɾ��������");
		getline(cin, group); cin.clear();
		if (group == "Ĭ�Ϸ���")
		{
			int ch;
			windowsHelper->clearLine(2, 4, 85, "Ĭ�Ϸ��鲻��ɾ������������������룬��Esc������");
			ch = _getch();
			if (ch != 27)
				continue;
			else
			{
				success = false;
				shared_ptr<Operation> mngContacts = operFac->getInstance_shared(e_ManageContacts);
				mngContacts->doOperation();
				break;
			}
		}
		vector<string>::iterator found = find(allGroups.begin(), allGroups.end(), group);
		if (found == allGroups.end())
		{
			int ch;
			windowsHelper->clearLine(2, 4, 85, "���������ڣ���������������룬��Esc������");
			ch = _getch();
			if (ch != 27)
				continue;
			else
			{
				success = false;
				shared_ptr<Operation> mngContacts = operFac->getInstance_shared(e_ManageContacts);
				mngContacts->doOperation();
				break;
			}
		}
		else
			break;
	}

	if (success)
	{
		shared_ptr<DataWriter> writer = fac->getDataWriter_shared();
		writer->removeGroup(group);
		windowsHelper->clearLine(2, 4, 85, "ɾ���ɹ���");
		system("pause");
		upDateMngCtxInterface();
	}

}

void GoBack::doOperation()
{
	windowsHelper->setColor(3);
	system("cls");
	windowsHelper->setWindowsCols(50);
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
	// ������ϵ��
	case 3:
		oper = operFac->getInstance_shared(e_ManageContacts);
		oper->doOperation();
		break;
	// �˳�ϵͳ
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
	// ������ҳ��
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
		// ������ҳ��
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
	// �����ϵ��
	case 1:
		oper = operFac->getInstance_shared(e_AddContacts);
		oper->doOperation();
		break;
	// ɾ����ϵ��
	case 2:
		oper = operFac->getInstance_shared(e_RemoveContacts);
		oper->doOperation();
		break;
	// �ƶ���ϵ��
	case 3:
		oper = operFac->getInstance_shared(e_MoveContacts);
		oper->doOperation();
		break;
	// �༭��Ϣ
	case 4:
		oper = operFac->getInstance_shared(e_EditContactsInfo);
		oper->doOperation();
		break;
	// ��ӷ���
	case 5:
		oper = operFac->getInstance_shared(e_AddGroup);
		oper->doOperation();
		break;
	// ɾ������
	case 6:
		oper = operFac->getInstance_shared(e_RemoveGroup);
		oper->doOperation();
		break;
	// ����
	case 7:
		oper = operFac->getInstance_shared(e_GoBack);
		oper->doOperation();
		break;
	default:
		break;
	}
}
