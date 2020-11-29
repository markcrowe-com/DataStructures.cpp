/*
 * Copyright (c) 2020 Mark Crowe <https://github.com/markcrowe-com>. All rights reserved.
 */
#pragma once
#include <string>
#include "AvlTreeNodeMethods.h"
#include "../DataStructures/AvlTree.h"
namespace DataStructures
{
	template <class T>class AvlTreeComponent : public AvlTree<T>
	{
	public:
		AvlTreeComponent();
		~AvlTreeComponent();
	public:
		void Clear();
		bool Contains(T candidate) const;
		void Insert(T value);
		bool IsEmpty() const;
		AvlTreeNode<T>* Nodes() const;
		bool Remove(T value);
		string ToString() const;
	private:
		AvlTreeNode<T>* root;
	};

	//
	//	constructor/desturtor
	//
	template<class T> AvlTreeComponent<T>::AvlTreeComponent()
	{
		root = NULL;
	}
	template<class T> AvlTreeComponent<T>::~AvlTreeComponent() { }
	#pragma region Public Methods
	#pragma endregion
	template<class T> void AvlTreeComponent<T>::Clear()
	{
		root = NULL;
	}
	template<class T> bool AvlTreeComponent<T>::Contains(T candidate) const
	{
		return ContainsValue<T>(root, candidate);
	}
	template<class T> void AvlTreeComponent<T>::Insert(T value)
	{
		root = InsertValue<T>(root, value);
	}
	template<class T> bool AvlTreeComponent<T>::IsEmpty() const
	{
		return root == NULL;
	}
	template<class T> AvlTreeNode<T>* AvlTreeComponent<T>::Nodes() const
	{
		return root; // should be a deep copy of Nodes
	}
	template<class T> bool AvlTreeComponent<T>::Remove(T value)
	{
		bool present = Contains(value);
		if(present)
			root = DeleteNodeByValue<T>(root, value);
		return present;
	}
	template<class T> string AvlTreeComponent<T>::ToString() const
	{
		return ToInOrderString<T>(root);
	}
}