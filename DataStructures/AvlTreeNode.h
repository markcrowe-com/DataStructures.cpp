/*
 * Copyright (c) 2020 Mark Crowe <https://github.com/markcrowe-com>. All rights reserved.
 */
#pragma once
#include "BinaryTreeNode.h"
namespace DataStructures
{
	using namespace std;
	/// <summary>
	///	Avl Tree Node
	/// </summary>
	/// <typeparam name="T"></typeparam>
	template<class T> __interface AvlTreeNode : public BinaryTreeNode<T>
	{
		#pragma region Methods : get const
		#pragma endregion
		int getHeight() const;
		AvlTreeNode<T>* getLeftTree() const;
		AvlTreeNode<T>* getRightTree() const;
		T getValue() const;
		#pragma region Methods : set
		#pragma endregion
		void setHeight(int value);
		void setLeftTree(AvlTreeNode<T>* value);
		void setRightTree(AvlTreeNode<T>* value);
		void setValue(T value);
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
	};
}