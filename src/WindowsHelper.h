#define _CRT_SECURE_NO_WARNINGS
#pragma once
#ifndef WINDOWSHELPER_H
#define WINDOWSHELPER_H
#include <iostream>
#include <windows.h>
#include <string>
#include <cstdio>

class WindowsHelper
{
public:

	inline void setWindowsAttribute(const int cols, const std::string title)
	{
		__setWindowsAttribute(cols, title);
	}

	inline void setWindowsCols(const int cols)
	{
		__setWindowsCols(cols);
	}

	inline void setCursorPosition(const int x, const int y)
	{
		__setCursorPosition(x, y);
	}

	inline void print(const int x, const int y, const std::string contant)
	{
		__print(x, y, contant);
	}

	inline void setColor(const int colorID)
	{
		__setColor(colorID);
	}

	inline void setBackColor()
	{
		__setBackColor();
	}

	inline void selected(const int x, const int y, const std::string contant)
	{
		__selected(x, y, contant);
	}

	inline void toSelect(const int x, const int y, const std::string contant)
	{
		__toSelect(x, y, contant);
	}

	// ������������Ͻ�
	inline void hideCursor()
	{
		__setCursorPosition(0, 0);
	}

	inline void clearLine(const int x, const int y, const int w)
	{
		__clearLine(x, y, w);
	}

	inline void clearLine(const int x, const int y, const int w, const int h)
	{
		__clearLine(x, y, w, h);
	}

	inline void  clearLine(const int x, const int y, const int w, const std::string contant)
	{
		__clearLine(x, y, w, contant);
	}

private:

	inline void __setWindowsAttribute(const int cols, const std::string title)
	{
		// ���ô��ڱ���
		system(("title " + title).c_str());
		char cmd[30];
		sprintf_s(cmd, "mode con cols=%d", cols * 2);
		system(cmd);
	}

	inline void __setWindowsCols(int const cols)
	{
		char cmd[30];
		sprintf_s(cmd, "mode con cols=%d", cols * 2);
		system(cmd);
	}


	// ���ù��λ��
	inline void __setCursorPosition(const int x, const int y)
	{
		COORD position;
		position.X = x * 2;
		position.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	}

	// �ڶ�Ӧλ�ô�ӡ�ַ���
	inline void __print(const int x, const int y, const std::string contant)
	{
		__setCursorPosition(x, y);
		std::cout << contant;
	}

	inline void __clearLine(const int x, const int y, const int w)
	{
		__setCursorPosition(x, y);
		for (int i = 0; i < w; i++)
			cout << " ";
		__setCursorPosition(x, y);
	}

	inline void __clearLine(const int x, const int y, const int w, const int h)
	{
		__setCursorPosition(x, y);
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; i < w; j++)
			{
				cout << " ";
			}
			cout << endl;
		}
		__setCursorPosition(x, y);
	}

	inline void __clearLine(const int x, const int y, const int w, const std::string contant)
	{
		__setCursorPosition(x, y);
		for (int i = 0; i < w; i++)
			cout << " ";
		__setCursorPosition(x, y);
		cout << contant;
	}

	// �����ı���ɫ
	inline void __setColor(const int colorID)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
	}

	// �����ı�����ɫ
	inline void __setBackColor()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
			FOREGROUND_BLUE |
			BACKGROUND_BLUE |
			BACKGROUND_GREEN |
			BACKGROUND_RED);
	}

	// Ŀǰѡ���ѡ�����ȡ������ɫ
	inline void __selected(const int x, const int y, const std::string contant)
	{
		__setCursorPosition(x, y);//����ѡ����ȡ������ɫ
		__setColor(3);
		std::cout << contant;
		hideCursor();
	}

	// ����ѡ�������ñ���ɫ
	inline void __toSelect(const int x, const int y, const std::string contant)
	{
		__setCursorPosition(x, y);
		__setBackColor();
		std::cout << contant;
		hideCursor();
	}

};



#endif // !WINDOWSHELPER_H
