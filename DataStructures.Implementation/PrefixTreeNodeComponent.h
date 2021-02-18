#pragma once
/*
 * Copyright (c) 2020 Mark Crowe <https://github.com/markcrowe-com>. All rights reserved.
 */
#pragma once
#include "../DataStructures/PrefixTreeNode.h"
namespace DataStructures
{
	template<class T> struct PrefixTreeNodeComponent : public PrefixTreeNode<T>
	{
	public:
		PrefixTreeNodeComponent();
		PrefixTreeNodeComponent(T value);
		#pragma region Methods
		#pragma endregion
		void AddValue(T);
		void RemoveValue(T);
		#pragma region Methods const
		#pragma endregion
		PrefixTreeNode<T>* getBranches() const;
		int getBranchCount() const;
		T* getValues() const;
		bool IsEmpty() const;
		bool IsLeaf() const;
		#pragma region Properties
		#pragma endregion
		__declspec(property(get = getBranches)) PrefixTreeNode<T>* Branches;
		__declspec(property(get = getBranchCount)) int BranchCount;
		__declspec(property(get = getValues)) T* Values;
		#pragma region Fields
		#pragma endregion
	private:
		PrefixTreeNode<T>* branches;
		BranchSize;
		T* values;
	};

	template<class T> PrefixTreeNodeComponent<T>::PrefixTreeNodeComponent()
	{
		this->leftTree = this->rightTree = NULL;
	}
	template<class T> PrefixTreeNodeComponent<T>::PrefixTreeNodeComponent(T value)
	{
		this->leftTree = this->rightTree = NULL;
		this->value = value;
	}
	#pragma region Methods
	#pragma endregion
	template<class T> void PrefixTreeNodeComponent<T>::AddValue(T value)
	{
		return this->leftTree;
	}
	template<class T> void PrefixTreeNodeComponent<T>::RemoveValue(T value)
	{
		return this->rightTree;
	}
	#pragma region Methods : set
	#pragma endregion
	template<class T> T PrefixTreeNodeComponent<T>::getValue() const
	{
		return this->value;
	}
	template<class T> void PrefixTreeNodeComponent<T>::setLeftTree(BinaryTreeNode<T>* value)
	{
		this->leftTree = value;
	}
	template<class T> void PrefixTreeNodeComponent<T>::setRightTree(BinaryTreeNode<T>* value)
	{
		this->rightTree = value;
	}
	template<class T> void PrefixTreeNodeComponent<T>::setValue(T value)
	{
		this->value = value;
	}
	#pragma region Methods
	#pragma endregion
	template<class T> bool PrefixTreeNodeComponent<T>::IsComplete() const
	{
		return this->leftTree != NULL && this->rightTree != NULL;
	}
	template<class T> bool PrefixTreeNodeComponent<T>::IsLeaf() const
	{
		return this->leftTree == NULL && this->rightTree == NULL;
	}
	template<class T> bool PrefixTreeNodeComponent<T>::IsNotComplete() const
	{
		return this->leftTree == NULL || this->rightTree == NULL;
	}
}