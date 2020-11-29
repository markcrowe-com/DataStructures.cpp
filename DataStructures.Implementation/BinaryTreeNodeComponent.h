/*
 * Copyright (c) 2020 Mark Crowe <https://github.com/markcrowe-com>. All rights reserved.
 */
#pragma once
#include "../DataStructures/BinaryTreeNode.h"
namespace DataStructures
{
	template<class T> struct BinaryTreeNodeComponent : public BinaryTreeNode<T>
	{
	public:
		BinaryTreeNodeComponent();
		BinaryTreeNodeComponent(T value);
		#pragma region Methods : get const
		#pragma endregion
		BinaryTreeNode<T>* getLeftTree() const;
		BinaryTreeNode<T>* getRightTree() const;
		T getValue() const;
		#pragma region Methods : set
		#pragma endregion
		void setLeftTree(BinaryTreeNode<T>* value);
		void setRightTree(BinaryTreeNode<T>* value);
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

	template<class T> BinaryTreeNodeComponent<T>::BinaryTreeNodeComponent()
	{
		this->leftTree = this->rightTree = NULL;
	}
	template<class T> BinaryTreeNodeComponent<T>::BinaryTreeNodeComponent(T value)
	{
		this->leftTree = this->rightTree = NULL;
		this->value = value;
	}
	#pragma region Methods : get const
	#pragma endregion
	template<class T> BinaryTreeNode<T>* BinaryTreeNodeComponent<T>::getLeftTree() const
	{
		return this->leftTree;
	}
	template<class T> BinaryTreeNode<T>* BinaryTreeNodeComponent<T>::getRightTree() const
	{
		return this->rightTree;
	}
	template<class T> T BinaryTreeNodeComponent<T>::getValue() const
	{
		return this->value;
	}
	#pragma region Methods : set
	#pragma endregion
	template<class T> void BinaryTreeNodeComponent<T>::setLeftTree(BinaryTreeNode<T>* value)
	{
		this->leftTree = value;
	}
	template<class T> void BinaryTreeNodeComponent<T>::setRightTree(BinaryTreeNode<T>* value)
	{
		this->rightTree = value;
	}
	template<class T> void BinaryTreeNodeComponent<T>::setValue(T value)
	{
		this->value = value;
	}
	#pragma region Methods
	#pragma endregion
	template<class T> bool BinaryTreeNodeComponent<T>::IsComplete() const
	{
		return this->leftTree != NULL && this->rightTree != NULL;
	}
	template<class T> bool BinaryTreeNodeComponent<T>::IsLeaf() const
	{
		return this->leftTree == NULL && this->rightTree == NULL;
	}
	template<class T> bool BinaryTreeNodeComponent<T>::IsNotComplete() const
	{
		return this->leftTree == NULL || this->rightTree == NULL;
	}
}