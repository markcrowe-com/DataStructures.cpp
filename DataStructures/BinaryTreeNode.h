/*
 * Copyright (c) 2020 Mark Crowe <https://github.com/markcrowe-com>. All rights reserved.
 */
#pragma once
namespace DataStructures
{
	using namespace std;
	/// <summary>
	///	Binary Tree Node
	/// </summary>
	/// <typeparam name="T"></typeparam>
	template<class T> __interface BinaryTreeNode
	{
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
		__declspec(property(get = getLeftTree)) BinaryTreeNode<T>* LeftTree;
		__declspec(property(get = getRightTree)) BinaryTreeNode<T>* RightTree;
		__declspec(property(get = getValue, put = setValue)) T Value;
	};
}