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
	TrieType::~TrieType()
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
		if(root == NULL)
			return false;

		Trienode* iterator = root;

		stack<Trienode*>* targetPathStack = new stack<Trienode*>();
		targetPathStack->push(iterator);

		for(int i = 0; i < MAXLENGTH && iterator; i++)
		{
			if(target[i] == '\0')
				break;
			else
			{
				iterator = iterator->branch[target[i] - 'a'];
				targetPathStack->push(iterator);
			}
		}
		if(iterator == NULL) {
			return false;
		}
		else {
			iterator->ref = NULL;
			deleteEmptyNodes(targetPathStack);
			return true;
		}
	}
	void TrieType::PrintTrie(ostream& outfile) const
	{
		cout << "Demo Print";
	}
	void deleteEmptyNodes(stack<Trienode*>* targetPathStack)
	{
		while(!targetPathStack->empty())
		{
			Trienode* node = targetPathStack->top();
			targetPathStack->pop();
			if(node->IsEmpty())
			{
				delete node;
			}
			else
			{
				break;
			}
		}
	}
	void TrieType::MakeEmpty()
	{
		root = NULL;
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