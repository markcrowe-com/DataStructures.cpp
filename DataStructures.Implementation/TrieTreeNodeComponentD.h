/*
 * Copyright (c) 2020 Mark Crowe <https://github.com/markcrowe-com>. All rights reserved.
 */
#pragma once
#include "TrieTreeEntry.h"
namespace DataStructures
{
	const int LETTERS = 26;
	struct Trienode
	{
		Trienode();
		bool IsEmpty() const;
		bool IsLeaf() const;
		Trienode* branch[LETTERS];
		EntryType* ref;
	};
	Trienode::Trienode()
	{
		int ch;
		for(ch = 0; ch < LETTERS; ch++)
			branch[ch] = NULL;
		ref = NULL;
	}
	bool Trienode::IsLeaf() const
	{
		for(int index = 0; index < LETTERS; index++)
		{
			if(branch[index] != NULL)
				return false;
		}
		return true;
	}
	bool Trienode::IsEmpty() const
	{
		return ref == NULL && IsLeaf();
	}
}