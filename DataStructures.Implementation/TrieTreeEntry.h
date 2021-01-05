#pragma once
/*
 * Copyright (c) 2020 Mark Crowe <https://github.com/markcrowe-com>. All rights reserved.
 */
#pragma once
#include <iostream>
namespace DataStructures
{
	using namespace std;
	const int MAXLENGTH = 10;
	class EntryType
	{
	public:
		EntryType();
		EntryType(char* key);
		EntryType(EntryType& entry);
	private:
		char entryKey[MAXLENGTH];
	};
	EntryType::EntryType()
	{
	}
	EntryType::EntryType(char* key)
	{
	}
	EntryType::EntryType(EntryType& entry)
	{
		//entryKey = entry.entryKey;
	}
	struct Person
	{
		string firstname;
		string surname;
		int age;
	};
}