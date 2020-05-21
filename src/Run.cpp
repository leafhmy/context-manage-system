#include "Run.h"

Run::Run()
{
	windowsHelper->setColor(3);
	fac = new Factory();
	windowsFac =  fac->getWindowsFactory();
	windowsHelper = windowsFac->getInstance();
	windowsHelper->setWindowsAttribute(50, 30, "通信录管理系统");
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


