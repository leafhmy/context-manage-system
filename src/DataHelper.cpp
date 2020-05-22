#include "DataHelper.h"

void DataWriter::__save(Json::Value value)
{
	ofstream fileContacts(contactsFile, ios::binary | ios::trunc | ios::out);
	fileContacts << value;
	fileContacts.close();
}

void DataWriter::__save(string group)
{
	ifstream readFileGroups(groupsFile, ios::binary | ios::trunc | ios::in);
	Json::Value groups;
	readFileGroups >> groups;
	groups["groups"].append(group);
	readFileGroups.close();

	ofstream writeFileGroups(groupsFile, ios::binary | ios::trunc | ios::out);
	writeFileGroups << groups;
	writeFileGroups.close();
}

void DataWriter::__addContact(map<string, string> contactInfo, string group)
{
	ifstream fileContacts(contactsFile, ios::binary | ios::trunc | ios::in);
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

void DataWriter::__addGroup(string group)
{
	ifstream fileContacts(contactsFile, ios::binary | ios::trunc | ios::in);
	Json::Value contacts;
	fileContacts >> contacts;

	Json::Value newGroup = Json::arrayValue;
	contacts[GBToUTF8(group.c_str())] = newGroup;
	fileContacts.close();
	__save(group);
}

void DataWriter::__editeInfo(string group, string identifiy, string attribute, string newInfo)
{
	ifstream fileContacts(contactsFile, ios::binary | ios::trunc | ios::in);
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
	fstream fileContacts(contactsFile, ios::binary | ios::trunc | ios::in);
	Json::Value contacts;
	fileContacts >> contacts;

	Json::Value backupGroup = Json::arrayValue;
	backupGroup = contacts[GBToUTF8(name.c_str())];
	contacts.removeMember(GBToUTF8(name.c_str()));
	contacts[GBToUTF8(newName.c_str())] = backupGroup;

	fileContacts.close();
	__save(contacts);

	ifstream readFileGroups(groupsFile, ios::binary | ios::trunc | ios::in);
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

	for (int i = 0; i < groups.size(); i++)
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

map<string, string> DataReader::__getContact(string group, string name)
{
	vector<map<string, string>> contactsInGroup = __getContactsInGroup(group);
	for (auto contacts : contactsInGroup)
	{
		if (contacts["name"] == name)
			return contacts;
	}
}

