/*
 * Copyright (c) 2020 Mark Crowe <https://github.com/markcrowe-com>. All rights reserved.
 */
#pragma once
#include "../DataStructures/BinaryTreeNode.h"
namespace DataStructures
{
	template<class T> struct BinaryTreeNodeMock : public BinaryTreeNode<T>
	{
	public:
		BinaryTreeNodeMock();
		BinaryTreeNodeMock(T value);
		#pragma region Methods : get const
		#pragma endregion
		BinaryTreeNode<T>* getLeftTree() const;
		BinaryTreeNode<T>* getRightTree() const;
		T getValue() const;
		#pragma region Methods : set
		#pragma endregion
		void setValue(T value);
		#pragma region Methods
		#pragma endregion
		bool IsComplete() const;
		bool IsLeaf() const;
		bool IsNotComplete() const;
		#pragma region Properties
		#pragma endregion
		__declspec(property(get = getLeftTree, put = setLeftTree)) BinaryTreeNode<T>* LeftTree;
		__declspec(property(get = getRightTree, put = setRightTree)) BinaryTreeNode<T>* RightTree;
		#pragma region Fields
		#pragma endregion
	private:
		BinaryTreeNode<T>* leftTree;
		BinaryTreeNode<T>* rightTree;
		T value;
	};

	template<class T> BinaryTreeNodeMock<T>::BinaryTreeNodeMock()
	{
		cerr << "BinaryTreeNodeMock<T>::BinaryTreeNodeMock()" << endl;
	}
	template<class T> BinaryTreeNodeMock<T>::BinaryTreeNodeMock(T value)
	{
		cerr << "BinaryTreeNodeMock<T>::BinaryTreeNodeMock(T value)" << endl;
	}
	#pragma region Methods : get const
	#pragma endregion
	template<class T> BinaryTreeNode<T>* BinaryTreeNodeMock<T>::getLeftTree() const
	{
		cerr << "BinaryTreeNode<T>::getLeftTree()" << endl;
		return NULL;
	}
	template<class T> BinaryTreeNode<T>* BinaryTreeNodeMock<T>::getRightTree() const
	{
		cerr << "BinaryTreeNode<T>::getRightTree()" << endl;
		return NULL;
	}
	template<class T> T BinaryTreeNodeMock<T>::getValue() const
	{
		cerr << "BinaryTreeNode<T>::getValue()" << endl;
		return NULL;
	}
	#pragma region Methods : set
	#pragma endregion
	template<class T> void BinaryTreeNodeMock<T>::setValue(T value)
	{
		cerr << "BinaryTreeNodeMock<T>::setValue(T value)" << endl;
	}
	#pragma region Methods
	#pragma endregion
	template<class T> bool BinaryTreeNodeMock<T>::IsComplete() const
	{
		cerr << "BinaryTreeNodeMock<T>::IsComplete()" << endl;
		return false;
	}
	template<class T> bool BinaryTreeNodeMock<T>::IsLeaf() const
	{
		cerr << "BinaryTreeNodeMock<T>::IsLeaf()" << endl;
		return true;
	}
	template<class T> bool BinaryTreeNodeMock<T>::IsNotComplete() const
	{
		cerr << "BinaryTreeNodeMock<T>::IsNotComplete()" << endl;
		return true;
	}
}