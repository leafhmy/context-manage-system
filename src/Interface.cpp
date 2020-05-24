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

void FindContactsInterface::showTitle()
{
	
}

void FindContactsInterface::showSelection()
{
	windowsHelper->print(2, 4, "����");
}


///////////////////////////////////////////////////

void ManageContactsInterface::showTitle()
{
	windowsHelper->print(35, 2, "������ϵ��");
}

void ManageContactsInterface::showSelection()
{
	windowsHelper->print(2, 6, "�����ϵ��");
	windowsHelper->print(2, 8, "ɾ����ϵ��");
	windowsHelper->print(2, 10, "�ƶ���ϵ��");
	windowsHelper->print(2, 12, "�༭��Ϣ");
	windowsHelper->print(2, 14, "��ӷ���");
	windowsHelper->print(2, 16, "ɾ������");
	windowsHelper->print(2, 18, "����");
}

//////////////////////////////////////////////

void ExitSystemInterface::showTitle()
{
	windowsHelper->print(17, 5, "�����˳�");
}

void ExitSystemInterface::showSelection()
{

}