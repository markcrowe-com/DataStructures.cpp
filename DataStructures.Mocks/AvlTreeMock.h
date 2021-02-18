/*
 * Copyright (c) 2020 Mark Crowe <https://github.com/markcrowe-com>. All rights reserved.
 */
#pragma once
#include <string>
#include "../DataStructures/AvlTree.h"
#include "../DataStructures/AvlTreeNode.h"
#include "AvlTreeNodeMock.h"
namespace DataStructures
{
	template <class T>class AvlTreeMock : public AvlTree<T>
	{
	public:
		AvlTreeMock();
		~AvlTreeMock();
	public:
		void Clear();
		bool Contains(T candidate) const;
		void Insert(T value);
		bool IsEmpty() const;
		AvlTreeNode<T>* Nodes() const;
		bool Remove(T value);
		string ToString() const;
	};

	//
	//	constructor/desturtor
	//
	template<class T> AvlTreeMock<T>::AvlTreeMock()
	{
		cerr << "AvlTreeMock<T>::AvlTreeMock()" << endl;
	}
	template<class T> AvlTreeMock<T>::~AvlTreeMock()
	{
		cerr << "AvlTreeMock<T>::~AvlTreeMock()" << endl;
	}
	#pragma region Public Methods
	#pragma endregion
	template<class T> void AvlTreeMock<T>::Clear()
	{
		cerr << "AvlTreeMock<T>::Clear()" << endl;
	}
	template<class T> bool AvlTreeMock<T>::Contains(T candidate) const
	{
		cerr << "AvlTreeMock<T>::Contains(" << candidate << ")" << endl;
		return true;
	}
	template<class T> void AvlTreeMock<T>::Insert(T value)
	{
		cerr << "AvlTreeMock<T>::Insert(" << value << ")" << endl;
	}
	template<class T> bool AvlTreeMock<T>::IsEmpty() const
	{
		cerr << "AvlTreeMock<T>::IsEmpty()" << endl;
		return true;
	}
	template<class T> AvlTreeNode<T>* AvlTreeMock<T>::Nodes() const
	{
		cerr << "AvlTreeMock<T>::Nodes()" << endl;
		return new AvlTreeNodeMock<T>();
	}
	template<class T> bool AvlTreeMock<T>::Remove(T value)
	{
		cerr << "AvlTreeMock<T>::Remove(" << value << ")" << endl;
		return true;
	}
	template<class T> string AvlTreeMock<T>::ToString() const
	{
		cerr << "AvlTreeMock<T>::ToString()" << endl;
		return "        2\n\n       / \\\n      /   \\\n     /     \\\n    1       3\n   / \\     / \\\n  0   7   9   1\n /   / \\     / \\\n2   1   0   8   8\n       /\n      7\n";
	}
}