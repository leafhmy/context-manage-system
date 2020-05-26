#include "DataHelper.h"

void DataWriter::__save(Json::Value value)
{
	ofstream fileContacts(contactsFile, ios::binary | ios::trunc | ios::out);
	fileContacts << value;
	fileContacts.close();
}



void DataWriter::__save(string group)
{
	// 用于添加分组
	ifstream readFileGroups(groupsFile, ios::binary | ios::in);
	Json::Value groups;
	readFileGroups >> groups;
	
	//groups["groups"].append(GBToUTF8(group.c_str()));
	groups["groups"].append(GBToUTF8(group.c_str()));
	readFileGroups.close();

	ofstream writeFileGroups(groupsFile, ios::binary | ios::trunc | ios::out);
	writeFileGroups << groups;
	writeFileGroups.close();
}

void DataWriter::__addContact(map<string, string> contactInfo, string group)
{
	//ifstream fileContacts(contactsFile, ios::binary | ios::in);
	//Json::Value contacts;
	//fileContacts >> contacts;

	ifstream fileContacts(contactsFile, ios::binary | ios::in);
	Json::Value contacts;
	fileContacts >> contacts;

	Json::Value info;
	info["address"] = GBToUTF8(contactInfo["address"].c_str());
	info["group"] = GBToUTF8(group.c_str());
	info["home_phone"] = contactInfo["home_phone"].c_str();
	info["id"] = contactInfo["id"].c_str();
	info["mail"] = contactInfo["mail"].c_str();
	info["mobile_phone"] = contactInfo["mobile_phone"].c_str();
	info["name"] = GBToUTF8(contactInfo["name"].c_str());
	info["sex"] = GBToUTF8(contactInfo["sex"].c_str());
	info["work_phone"] = contactInfo["work_phone"].c_str();

	contacts[GBToUTF8(group.c_str())].append(info);
	fileContacts.close();
	__save(contacts);
}


void DataWriter::__removeContact(string group, string id)
{
	ifstream fileContacts(contactsFile, ios::binary | ios::in);
	Json::Value contacts;
	fileContacts >> contacts;

	int index = 0;
	for (auto contact : contacts[GBToUTF8(group.c_str())])
	{
		if (UTF8ToGB(contact["id"].asCString()).c_str() == id)
		{
			break;
		}
		index++;
	}

	Json::Value deleted;
	contacts[GBToUTF8(group.c_str())].removeIndex(index, &deleted);
	
	fileContacts.close();
	__save(contacts);
}

void DataWriter::__moveContact(string moveId, string inGroup, string destinGroup)
{
	map<string, string> contact;
	DataReader reader;
	contact = reader.getContact(inGroup, moveId);
	__addContact(contact, destinGroup);
	__removeContact(inGroup, moveId);
}


void DataWriter::__changeContactsInfo(string id, string inGroup, string toChange, string changeInfo)
{
	map<string, string> contact;
	DataReader reader;
	contact = reader.getContact(inGroup, id);
	contact[toChange] = changeInfo;
	// 如果改变分组信息，需要添加到目标分组
	if (toChange == "group")
		__addContact(contact, changeInfo);
	else
		__addContact(contact, inGroup);
	__removeContact(inGroup, id);

}

void DataWriter::__addGroup(string group)
{
	ifstream fileContacts(contactsFile, ios::binary | ios::in);
	Json::Value contacts;
	fileContacts >> contacts;

	Json::Value newGroup = Json::arrayValue;
	contacts[GBToUTF8(group.c_str())] = newGroup;
	fileContacts.close();

	__save(group);
	__save(contacts);
}


void DataWriter::__removeGroup(string groupName)
{
	ifstream readFileGroups(groupsFile, ios::binary | ios::in);
	Json::Value groups;
	readFileGroups >> groups;

	ifstream fileContacts(contactsFile, ios::binary | ios::in);
	Json::Value contacts;
	fileContacts >> contacts;
	
	int index = 0;
	for (auto group : groups["groups"])
	{
		if (UTF8ToGB(group.asCString()).c_str() == groupName)
		{
			//newGroup.append(GBToUTF8(group.asCString()));
			break;
		}
		index++;
	}
	Json::Value deleted;
	groups["groups"].removeIndex(index, &deleted);

	ofstream writeFileGroups(groupsFile, ios::binary | ios::trunc | ios::out);
	writeFileGroups << groups;
	writeFileGroups.close();

	// 删除联系人文件下的该组
	contacts.removeMember(GBToUTF8(groupName.c_str()));

	readFileGroups.close();
	writeFileGroups.close();
	fileContacts.close();
	__save(contacts);

}

void DataWriter::__editeInfo(string group, string identifiy, string attribute, string newInfo)
{
	ifstream fileContacts(contactsFile, ios::binary | ios::in);
	Json::Value contacts;
	fileContacts >> contacts;

	for (auto contact : contacts[GBToUTF8(group.c_str())])
	{
		if ((contact[GBToUTF8(identifiy.c_str())] == contact["name"]) || (contact[GBToUTF8(identifiy.c_str())] == contact["id"]))
		{
			contact[GBToUTF8(attribute.c_str())] = GBToUTF8(newInfo.c_str());
			break;
		}
	}
	
	fileContacts.close();
	__save(contacts);
}

void DataWriter::__renameGroup(string name, string newName)
{
	fstream fileContacts(contactsFile, ios::binary | ios::in);
	Json::Value contacts;
	fileContacts >> contacts;

	Json::Value backupGroup = Json::arrayValue;
	backupGroup = contacts[GBToUTF8(name.c_str())];
	contacts.removeMember(GBToUTF8(name.c_str()));
	contacts[GBToUTF8(newName.c_str())] = backupGroup;

	fileContacts.close();
	__save(contacts);

	ifstream readFileGroups(groupsFile, ios::binary | ios::in);
	Json::Value groups;
	readFileGroups >> groups;
	groups["groups"][GBToUTF8(name.c_str())] = GBToUTF8(newName.c_str());

	readFileGroups.close();
}



//////////////////////////////////////////////////////////////////////


vector<map<string, string>> DataReader::__getAllContacts()
{
	// <attribute, value>
	vector<map<string, string>> allContacts;
	ifstream fileContacts(contactsFile, ios::binary | ios::in);
	Json::Value contacts;
	fileContacts >> contacts;
	fileContacts.close();

	ifstream readFileGroups(groupsFile, ios::binary | ios::in);
	Json::Value groups;
	readFileGroups >> groups;
	readFileGroups.close();

	for (unsigned i = 0; i < groups["groups"].size(); i++)
	{
		Json::Value contactsInGroup = contacts[(groups["groups"][i].asCString())];
		for (auto contact : contactsInGroup)
		{
			map<string, string> contactInfo;
			contactInfo["address"] = UTF8ToGB(contact["address"].asCString());
			contactInfo["group"] = UTF8ToGB(contact["group"].asCString());
			contactInfo["home_phone"] = contact["home_phone"].asCString();
			contactInfo["id"] = contact["id"].asCString();
			contactInfo["mail"] = contact["mail"].asCString();
			contactInfo["mobile_phone"] = contact["mobile_phone"].asCString();
			contactInfo["name"] = UTF8ToGB(contact["name"].asCString());
			contactInfo["sex"] = UTF8ToGB(contact["sex"].asCString());
			contactInfo["work_phone"] = contact["work_phone"].asCString();

			allContacts.push_back(contactInfo);
		}
	}

	return allContacts;
}

vector<string> DataReader::__getGroups()
{
	vector<string> allGroups;
	ifstream readFileGroups(groupsFile, ios::binary | ios::in);
	Json::Value groups;
	readFileGroups >> groups;
	readFileGroups.close();

	for (auto group : groups["groups"])
	{
		allGroups.push_back(UTF8ToGB(group.asCString()));
	}

	return allGroups;
}

vector<map<string, string>> DataReader::__getContactsInGroup(string group)
{
	vector<map<string, string>> contactsInGroup;
	ifstream fileContacts(contactsFile, ios::binary | ios::in);
	Json::Value contacts;
	fileContacts >> contacts;
	fileContacts.close();

	contacts = contacts[GBToUTF8(group.c_str())];
	for (auto contact : contacts)
	{
		map<string, string> contactInfo;
		contactInfo["address"] = UTF8ToGB(contact["address"].asCString());
		contactInfo["group"] = UTF8ToGB(contact["group"].asCString());
		contactInfo["home_phone"] = contact["home_phone"].asCString();
		contactInfo["id"] = contact["id"].asCString();
		contactInfo["mail"] = contact["mail"].asCString();
		contactInfo["mobile_phone"] = contact["mobile_phone"].asCString();
		contactInfo["name"] = UTF8ToGB(contact["name"].asCString());
		contactInfo["sex"] = UTF8ToGB(contact["sex"].asCString());
		contactInfo["work_phone"] = contact["work_phone"].asCString();

		contactsInGroup.push_back(contactInfo);
	}

	return contactsInGroup;
}

map<string, string> DataReader::__getContact(string group, string id)
{
	vector<map<string, string>> contactsInGroup = __getContactsInGroup(group);
	for (auto contacts : contactsInGroup)
	{
		if (contacts["id"] == id)
			return contacts;
	}
}

