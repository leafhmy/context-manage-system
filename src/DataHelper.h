#pragma once
#ifndef DATAHELPER_H
#define DATAHELPER_H
#include "json/json.h"
#include <map>
#include <vector>
#include <fstream>
#include <windows.h>
#include <memory>
#include "Factory.h"

using namespace std;

class DataHelper
{
public:
	DataHelper() {}

	virtual ~DataHelper() {}

protected:
	const string contactsFile = "./data/contacts.json";
	const string groupsFile = "./data/groups.json";

	inline string UTF8ToGB(const char* str)
	{
		string result;
		WCHAR* strSrc;
		LPSTR szRes;

		int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
		strSrc = new WCHAR[i + 1];
		MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

		i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
		szRes = new CHAR[i + 1];
		WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

		result = szRes;
		delete[]strSrc;
		delete[]szRes;

		return result;
	}

	inline string GBToUTF8(const char* gb2312)
	{
		int len = MultiByteToWideChar(CP_ACP, 0, gb2312, -1, NULL, 0);
		wchar_t* wstr = new wchar_t[len + 1];
		memset(wstr, 0, len + 1);
		MultiByteToWideChar(CP_ACP, 0, gb2312, -1, wstr, len);
		len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
		char* str = new char[len + 1];
		memset(str, 0, len + 1);
		WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);
		if (wstr) delete[] wstr;
		return str;
	}

};


class DataWriter : private DataHelper
{
public:
	void addContact(map<string, string> contactInfo, string group)
	{
		__addContact(contactInfo, group);
	}

	void removeContact(string group, string id)
	{
		__removeContact(group, id);
	}

	void moveContact(string moveId, string inGroup, string destinGroup)
	{
		__moveContact(moveId, inGroup, destinGroup);
	}

	void changeContactsInfo(string id, string inGroup, string toChange, string changeInfo)
	{
		__changeContactsInfo(id, inGroup, toChange, changeInfo);
	}

	void addGroup(string group)
	{
		__addGroup(group);
	}

	void removeGroup(string group)
	{
		__removeGroup(group);
	}

	void editeInfo(string group, string identifiy, string attribute, string newInfo)
	{
		__editeInfo(group, identifiy, attribute, newInfo);
	}

	void renameGroup(string name, string newName)
	{
		__renameGroup(name, newName);
	}

private:
	void __addContact(map<string, string> contactInfo, string group);

	void __removeContact(string group, string id);

	void __moveContact(string removeId, string inGroup, string destinGroup);

	void __changeContactsInfo(string id, string inGroup, string toChange, string changeInfo);

	void __addGroup(string group);

	void __removeGroup(string group);

	void __editeInfo(string group, string identifiy,string attribute, string newInfo);

	void __renameGroup(string name, string newName);

	void __save(Json::Value value);

	void __save(string group);

};


//////////////////////////////////////////////////////////////////////

class DataReader : private DataHelper
{
public:
	vector<map<string, string>> getAllContacts()
	{
		return __getAllContacts();
	}

	vector<string> getGroups()
	{
		return __getGroups();
	}
	
	vector<map<string, string>> getContactsInGroup(string group)
	{
		return __getContactsInGroup(group);
	}

	map<string, string> getContact(string group, string id)
	{
		return __getContact(group, id);
	}

private:
	vector<map<string, string>> __getAllContacts();

	vector<string> __getGroups();

	vector<map<string, string>> __getContactsInGroup(string group);

	map<string, string> __getContact(string group, string id);

};




#endif // !DATAHELPER_H



