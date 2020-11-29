/*
 * Copyright (c) 2020 Mark Crowe <https://github.com/markcrowe-com>. All rights reserved.
 */
#pragma once
#include <string>
#include "BinaryTreeNode.h"
namespace DataStructures
{
	using namespace std;
	template<class T> __interface BinarySearchTree
	{
		void Clear();
		bool Contains(T candidate) const;
		void Insert(T value);
		bool IsEmpty() const;
		BinaryTreeNode<T>* Nodes() const;
		bool Remove(T value);
		string ToString() const;
	};
}