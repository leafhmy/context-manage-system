#include "Interface.h"

Interface::Interface()
{
	fac = new Factory();
	windowsFactory = fac->getWindowsFactory();
	windowsHelper = windowsFactory->getInstance();
}

Interface::~Interface()
{
	delete fac;
}

//////////////////////////////////////////////////////////////////////

void MainInterface::showTitle()
{
	windowsHelper->print(17, 5, "��ӭ����ͨ��¼����ϵͳ");
	windowsHelper->print(5, 7, "ͨ�����·����ѡ����Ҫ���еĲ�����");
}


void MainInterface::showSelection()
{
	windowsHelper->print(20, 10, "�ҵ���ϵ��");
	windowsHelper->print(20, 12, "������ϵ��");
	windowsHelper->print(20, 14, "�����ҵ���ϵ��");
	windowsHelper->print(20, 16, "�˳�ϵͳ");
}

/////////////////////////////////////////////////////

void MyContactsInterface::showTitle()
{
	windowsHelper->print(17, 5, "�ҵ���ϵ��");
	windowsHelper->print(12, 7, "�ҵķ��飺");
}

void MyContactsInterface::showSelection()
{

}

//////////////////////////////////////////////////////

void LookGroupInterface::showTitle()
{

}

void LookGroupInterface::showSelection()
{
	windowsHelper->print(3, 25, "����");
}

//////////////////////////////////////////////////

