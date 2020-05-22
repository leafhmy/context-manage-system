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

	void setWindowsAttribute(const int cols, const int lines, std::string title)
	{
		__setWindowsAttribute(cols, lines, title);
	}

	void setCursorPosition(const int x, const int y)
	{
		__setCursorPosition(x, y);
	}

	void print(const int x, const int y, std::string contant)
	{
		__print(x, y, contant);
	}

	void setColor(int colorID)
	{
		__setColor(colorID);
	}

	void setBackColor()
	{
		__setBackColor();
	}

	void selected(const int x, const int y, std::string contant)
	{
		__selected(x, y, contant);
	}

	void toSelect(const int x, const int y, std::string contant)
	{
		__toSelect(x, y, contant);
	}

	// ������������Ͻ�
	void hideCursor()
	{
		__setCursorPosition(0, 0);
	}

	void clearLine(const int x, const int y, const int w)
	{
		__clearLine(x, y, w);
	}

	void clearLine(const int x, const int y, const int w, const int h)
	{
		__clearLine(x, y, w, h);
	}

	void  clearLine(const int x, const int y, const int w, std::string contant)
	{
		__clearLine(x, y, w, contant);
	}

private:
	// ���ô��ڴ�С������
	void __setWindowsAttribute(const int cols, const int lines, std::string title)
	{
		// ���ô��ڱ���
		system(("title " + title).c_str());
		char cmd[30];
		sprintf_s(cmd, "mode con cols=%d lines=%d", cols * 2, lines);
		system(cmd);
	}

	// ���ù��λ��
	void __setCursorPosition(const int x, const int y)
	{
		COORD position;
		position.X = x * 2;
		position.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	}

	// �ڶ�Ӧλ�ô�ӡ�ַ���
	void __print(const int x, const int y, std::string contant)
	{
		__setCursorPosition(x, y);
		std::cout << contant;
	}

	void __clearLine(const int x, const int y, const int w)
	{
		__setCursorPosition(x, y);
		for (int i = 0; i < w; i++)
			cout << " ";
		__setCursorPosition(x, y);
	}

	void __clearLine(const int x, const int y, const int w, const int h)
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

	void __clearLine(const int x, const int y, const int w, std::string contant)
	{
		__setCursorPosition(x, y);
		for (int i = 0; i < w; i++)
			cout << " ";
		__setCursorPosition(x, y);
		cout << contant;
	}

	// �����ı���ɫ
	void __setColor(int colorID)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
	}

	// �����ı�����ɫ
	void __setBackColor()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
			FOREGROUND_BLUE |
			BACKGROUND_BLUE |
			BACKGROUND_GREEN |
			BACKGROUND_RED);
	}

	// Ŀǰѡ���ѡ�����ȡ������ɫ
	void __selected(const int x, const int y, std::string contant)
	{
		__setCursorPosition(x, y);//����ѡ����ȡ������ɫ
		__setColor(3);
		std::cout << contant;
		hideCursor();
	}

	// ����ѡ�������ñ���ɫ
	void __toSelect(const int x, const int y, std::string contant)
	{
		__setCursorPosition(x, y);
		__setBackColor();
		std::cout << contant;
		hideCursor();
	}

};



#endif // !WINDOWSHELPER_H
