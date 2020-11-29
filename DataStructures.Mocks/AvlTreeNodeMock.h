#pragma once
#include <iostream>
#include "../DataStructures/AvlTreeNode.h"

namespace DataStructures
{
	template<class T> struct AvlTreeNodeMock : public AvlTreeNode<T>
	{
	public:
		AvlTreeNodeMock();
		AvlTreeNodeMock(int, T);
		AvlTreeNodeMock(T);
		#pragma region Methods : get const
		#pragma endregion
		int getHeight() const;
		AvlTreeNode<T>* getLeftTree() const;
		AvlTreeNode<T>* getRightTree() const;
		T getValue() const;
		#pragma region Methods : set
		#pragma endregion
		void setHeight(int value);
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
		__declspec(property(get = getLeftTree)) AvlTreeNode<T>* LeftTree;
		__declspec(property(get = getRightTree)) AvlTreeNode<T>* RightTree;
		__declspec(property(get = getValue, put = setValue)) T Value;
		#pragma region Fields
		#pragma endregion
	};

	template<class T> AvlTreeNodeMock<T>::AvlTreeNodeMock()
	{
		cerr << "AvlTreeNodeMock<T>::AvlTreeNodeMock()" << endl;
	}
	template<class T> AvlTreeNodeMock<T>::AvlTreeNodeMock(T value)
	{
		cerr << "AvlTreeNodeMock<T>::AvlTreeNodeMock(T value)" << endl;
	}
	template<class T> AvlTreeNodeMock<T>::AvlTreeNodeMock(int height, T value)
	{
		cerr << "AvlTreeNodeMock<T>::AvlTreeNodeMock(int height, T value)" << endl;
	}
	#pragma region Methods : get const
	#pragma endregion
	template<class T> int AvlTreeNodeMock<T>::getHeight() const
	{
		cerr << "AvlTreeNodeMock<T>::getHeight()" << endl;
		return 1;
	}
	template<class T> AvlTreeNode<T>* AvlTreeNodeMock<T>::getLeftTree() const
	{
		cerr << "AvlTreeNodeMock<T>::getLeftTree()" << endl;
		return NULL;
	}
	template<class T> AvlTreeNode<T>* AvlTreeNodeMock<T>::getRightTree() const
	{
		cerr << "AvlTreeNodeMock<T>::getRightTree()" << endl;
		return NULL;
	}
	template<class T> T AvlTreeNodeMock<T>::getValue() const
	{
		cerr << "AvlTreeNodeMock<T>::getValue()" << endl;
		return NULL;
	}
	#pragma region Methods : set
	#pragma endregion
	template<class T> void AvlTreeNodeMock<T>::setHeight(int value)
	{
		cerr << "AvlTreeNodeMock<T>::setHeight(int value)" << endl;

	}
	template<class T> void AvlTreeNodeMock<T>::setValue(T value)
	{
		cerr << "AvlTreeNodeMock<T>::setValue(T value)" << endl;
	}
	#pragma region Methods
	#pragma endregion
	template<class T> int AvlTreeNodeMock<T>::CalculateHeightDifference() const
	{
		cerr << "AvlTreeNodeMock<T>::CalculateHeightDifference()" << endl;
		return 0;
	}
	template<class T> bool AvlTreeNodeMock<T>::IsComplete() const
	{
		cerr << "AvlTreeNodeMock<T>::IsComplete()" << endl;
		return false;
	}
	template<class T> bool AvlTreeNodeMock<T>::IsLeaf() const
	{
		cerr << "AvlTreeNodeMock<T>::IsLeaf()" << endl;
		return true;
	}
	template<class T> bool AvlTreeNodeMock<T>::IsNotComplete() const
	{
		cerr << "AvlTreeNodeMock<T>::IsNotComplete()" << endl;
		return true;
	}
	template<class T> void AvlTreeNodeMock<T>::UpdateHeight()
	{
		cerr << "AvlTreeNodeMock<T>::UpdateHeight()" << endl;
	}
}