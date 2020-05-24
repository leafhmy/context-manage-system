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
	windowsHelper->print(17, 5, "欢迎进入通信录管理系统");
	windowsHelper->print(5, 7, "通过上下方向键选择您要进行的操作：");
}


void MainInterface::showSelection()
{
	windowsHelper->print(20, 10, "我的联系人");
	windowsHelper->print(20, 12, "查找联系人");
	windowsHelper->print(20, 14, "管理我的联系人");
	windowsHelper->print(20, 16, "退出系统");
}

/////////////////////////////////////////////////////

void MyContactsInterface::showTitle()
{
	windowsHelper->print(17, 5, "我的联系人");
	windowsHelper->print(12, 7, "我的分组：");
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
	windowsHelper->print(3, 25, "返回");
}

//////////////////////////////////////////////////

void FindContactsInterface::showTitle()
{
	
}

void FindContactsInterface::showSelection()
{
	windowsHelper->print(2, 4, "返回");
}


///////////////////////////////////////////////////

void ManageContactsInterface::showTitle()
{
	windowsHelper->print(35, 2, "所有联系人");
}

void ManageContactsInterface::showSelection()
{
	windowsHelper->print(2, 6, "添加联系人");
	windowsHelper->print(2, 8, "删除联系人");
	windowsHelper->print(2, 10, "移动联系人");
	windowsHelper->print(2, 12, "编辑信息");
	windowsHelper->print(2, 14, "添加分组");
	windowsHelper->print(2, 16, "删除分组");
	windowsHelper->print(2, 18, "返回");
}

//////////////////////////////////////////////

void ExitSystemInterface::showTitle()
{
	windowsHelper->print(17, 5, "您已退出");
}

void ExitSystemInterface::showSelection()
{

}