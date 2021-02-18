/*
 * Copyright (c) 2020 Mark Crowe <https://github.com/markcrowe-com>. All rights reserved.
 */
#pragma once
#include <string>
#include "AvlTreeNode.h"
#include "BinarySearchTree.h"
namespace DataStructures
{
	using namespace std;
	/// <summary>
	/// AVL Tree
	/// </summary>
	/// <typeparam name="T"></typeparam>
	template<class T> __interface AvlTree : public BinarySearchTree<T>
	{
		void Clear();
		bool Contains(T candidate) const;
		void Insert(T value);
		bool IsEmpty() const;
		AvlTreeNode<T>* Nodes() const;
		bool Remove(T value);
		string ToString() const;
	};
}