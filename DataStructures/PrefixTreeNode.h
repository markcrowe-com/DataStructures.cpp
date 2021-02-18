/*
 * Copyright (c) 2020 Mark Crowe <https://github.com/markcrowe-com>. All rights reserved.
 */
#pragma once
namespace DataStructures
{
	using namespace std;
	/// <summary>
	///	Avl Tree Node
	/// </summary>
	/// <typeparam name="T"></typeparam>
	template<class T> __interface PrefixTreeNode
	{
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
	};
}