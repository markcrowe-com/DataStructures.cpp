#pragma once
#include "TrieTreeEntry.h"
/*
 * Copyright (c) 2020 Mark Crowe <https://github.com/markcrowe-com>. All rights reserved.
 */
#pragma once
namespace DataStructures
{
	const int LETTERS = 26;
	struct Trienode
	{
		Trienode* branch[LETTERS];
		EntryType* ref;
	};
}