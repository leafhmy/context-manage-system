#include "Run.h"

Run::Run()
{
	windowsHelper->setColor(3);
	fac = new Factory();
	windowsFac =  fac->getWindowsFactory();
	windowsHelper = windowsFac->getInstance();
	windowsHelper->setWindowsAttribute(50, 30, "ͨ��¼����ϵͳ");
	interfaceFactory = fac->getInterfaceFactory();

}

Run::~Run()
{
	delete fac;
}



void Run::start()
{
	shared_ptr<Interface> mainInterface = interfaceFactory->getInstance_shared(e_MainInterface);
	mainInterface->show();
	int key = 1;
	key = mainInterfaceSelection();

	
}

int Run::mainInterfaceSelection()
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


