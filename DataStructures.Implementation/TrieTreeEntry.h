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
		for(int index = 0; index < MAXLENGTH; index++)
		{
			this->entryKey[index] = '\0';
		}
	}
	EntryType::EntryType(char* key)
	{
		for(int index = 0; index < MAXLENGTH; index++)
		{
			this->entryKey[index] = key[index];
		}
	}
	EntryType::EntryType(EntryType& entry)
	{
		for(int index = 0; index < MAXLENGTH; index++)
		{
			this->entryKey[index] = entry.entryKey[index];
		}
	}
	struct Person
	{
		string firstname;
		string surname;
		int age;
	};
}