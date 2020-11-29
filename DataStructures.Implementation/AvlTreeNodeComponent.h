/*
 * Copyright (c) 2020 Mark Crowe <https://github.com/markcrowe-com>. All rights reserved.
 */
#pragma once
#include "../DataStructures/AvlTreeNode.h"
namespace DataStructures
{
	template<class T> struct AvlTreeNodeComponent : public AvlTreeNode<T>
	{
	public:
		AvlTreeNodeComponent();
		AvlTreeNodeComponent(int, T);
		AvlTreeNodeComponent(T);
		#pragma region Methods : get const
		#pragma endregion
		int getHeight() const;
		AvlTreeNode<T>* getLeftTree() const;
		AvlTreeNode<T>* getRightTree() const;
		T getValue() const;
		#pragma region Methods : set
		#pragma endregion
		void setHeight(int value);
		void setLeftTree(AvlTreeNode<T>*);
		void setRightTree(AvlTreeNode<T>*);
		void setValue(T);
		#pragma region Methods
		#pragma endregion
		int CalculateHeightDifference() const;
		bool IsComplete() const;
		bool IsLeaf() const;
		bool IsNotComplete() const;
		void UpdateHeight();
		#pragma region Properties
		#pragma endregion
		__declspec(property(get = getHeight, put = setHeight)) int Height;
		__declspec(property(get = getLeftTree, put = setLeftTree)) AvlTreeNode<T>* LeftTree;
		__declspec(property(get = getRightTree, put = setRightTree)) AvlTreeNode<T>* RightTree;
		__declspec(property(get = getValue, put = setValue)) T Value;
		#pragma region Fields
		#pragma endregion
	private:
		int height;
		AvlTreeNode<T>* leftTree;
		AvlTreeNode<T>* rightTree;
		T value;
	};

	template<class T> AvlTreeNodeComponent<T>::AvlTreeNodeComponent()
	{
		this->height = 1;
		this->leftTree = this->rightTree = NULL;
	}
	template<class T> AvlTreeNodeComponent<T>::AvlTreeNodeComponent(T value)
	{
		this->height = 1;
		this->leftTree = this->rightTree = NULL;
		this->value = value;
	}
	template<class T> AvlTreeNodeComponent<T>::AvlTreeNodeComponent(int height, T value)
	{
		this->height = height;
		this->leftTree = this->rightTree = NULL;
		this->value = value;
	}
	#pragma region Methods : get const
	#pragma endregion
	template<class T> int AvlTreeNodeComponent<T>::getHeight() const
	{
		return this->height;
	}
	template<class T> AvlTreeNode<T>* AvlTreeNodeComponent<T>::getLeftTree() const
	{
		return this->leftTree;
	}
	template<class T> AvlTreeNode<T>* AvlTreeNodeComponent<T>::getRightTree() const
	{
		return this->rightTree;
	}
	template<class T> T AvlTreeNodeComponent<T>::getValue() const
	{
		return this->value;
	}
	#pragma region Methods : set
	#pragma endregion
	template<class T> void AvlTreeNodeComponent<T>::setHeight(int value)
	{
		this->height = value;
	}
	template<class T> void AvlTreeNodeComponent<T>::setLeftTree(AvlTreeNode<T>* value)
	{
		this->leftTree = value;
	}
	template<class T> void AvlTreeNodeComponent<T>::setRightTree(AvlTreeNode<T>* value)
	{
		this->rightTree = value;
	}
	template<class T> void AvlTreeNodeComponent<T>::setValue(T value)
	{
		this->value = value;
	}
	#pragma region Methods
	#pragma endregion
	template<class T> int AvlTreeNodeComponent<T>::CalculateHeightDifference() const
	{
		int heightDifference = calculateHeight(this->leftTree) - calculateHeight(this->rightTree);
		return heightDifference;
	}
	template<class T> bool AvlTreeNodeComponent<T>::IsComplete() const
	{
		return this->leftTree != NULL && this->rightTree != NULL;
	}
	template<class T> bool AvlTreeNodeComponent<T>::IsLeaf() const
	{
		return this->leftTree == NULL && this->rightTree == NULL;
	}
	template<class T> bool AvlTreeNodeComponent<T>::IsNotComplete() const
	{
		return this->leftTree == NULL || this->rightTree == NULL;
	}
	int getLargest(int lhs, int rhs)
	{
		return (lhs > rhs) ? lhs : rhs;
	}
	template<class T>int calculateHeight(AvlTreeNode<T>* avlTreeNode)
	{
		return avlTreeNode == NULL ? 0 : avlTreeNode->getHeight();
	}
	template<class T> void AvlTreeNodeComponent<T>::UpdateHeight()
	{
		int leftTreeHeight = calculateHeight(this->leftTree);
		int rightTreeHeight = calculateHeight(this->rightTree);
		this->height = 1 + getLargest(leftTreeHeight, rightTreeHeight);
	}
}