/*
 * Copyright (c) 2020 Mark Crowe <https://github.com/markcrowe-com>. All rights reserved.
 */
#pragma once
#include <iostream>
#include "TrieTreeEntry.h"
#include "TrieTreeNodeComponentD.h"
#include <stack>
namespace DataStructures
{
	using namespace std;
	typedef char Key[MAXLENGTH];
	class TrieType
	{
	public:
		TrieType();
		~TrieType();
		TrieType(TrieType& originalTree);
		void operator=(TrieType& originalTree);
		void MakeEmpty();
		void InsertTrie(Key newkey, EntryType* newentry);
		EntryType* TrieSearch(Key target);
		bool DeleteTrie(Key delkey);
		void PrintTrie(ostream& outfile) const;
	private:
		Trienode* root;
	};
	TrieType::TrieType()
	{
		root = NULL;
	}
	EntryType* TrieType::TrieSearch(Key target)
	{
		Trienode* current = root;
		for(int i = 0; i < MAXLENGTH && current; i++)
		{
			if(target[i] == '\0')
				break;
			else
				current = current->branch[target[i] - 'a'];
		}
		if(!current)
			return NULL;
		else if(!current->ref)
			return NULL;

		return current->ref;
	}
	bool TrieType::DeleteTrie(Key target)
	{
		Trienode* iterator = root;
		stack<Trienode*> s;
		for(int i = 0; i < MAXLENGTH && iterator; i++)
		{
			if(target[i] == '\0')
				break;
			else
			{
				iterator = iterator->branch[target[i] - 'a'];
				s.push(iterator);
			}
		}
		if(!iterator) {
			return false;
		}
		else {
			iterator->ref = NULL;
			RemoveEmptyTries(iterator);
		}
		return true;
	}
	void RemoveEmptyTries(Trienode* iterator)
	{
	}
	void TrieType::InsertTrie(Key newkey, EntryType* newentry)
	{
		if(!root)
			root = new Trienode();
		Trienode* current = root;
		for(int i = 0; i < MAXLENGTH; i++)
		{
			if(newkey[i] == '\0')
				break;
			else
			{
				if(!current->branch[newkey[i] - 'a'])
					current->branch[newkey[i] - 'a'] = new Trienode();
				current = current->branch[newkey[i] - 'a'];
			}
		}
		if(current->ref != NULL)
			cout << "\nTried to insert a duplicate key." << endl;
		else
			current->ref = newentry;
	}
}