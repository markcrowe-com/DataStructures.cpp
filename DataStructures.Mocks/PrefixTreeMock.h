/*
 * Copyright (c) 2020 Mark Crowe <https://github.com/markcrowe-com>. All rights reserved.
 */
#pragma once
#include "../DataStructures/PrefixTree.h"
namespace DataStructures
{
	template<class T> struct PrefixTreeMock : public PrefixTree<T>
	{
	public:
		PrefixTreeMock();
		#pragma region Methods
		#pragma endregion
		void Clear();
		bool Contains(T candidate) const;
		void Insert(T value);
		bool IsEmpty() const;
		bool Remove(T value);
		string ToString() const;
	};
	template<class T> PrefixTreeMock<T>::PrefixTreeMock()
	{
		cerr << "PrefixTreeMock<T>::PrefixTreeMock()" << endl;
	}
	#pragma region Methods
	#pragma endregion
	template<class T> void PrefixTreeMock<T>::Clear()
	{
		cerr << "PrefixTreeMock<T>::Clear()" << endl;
	}
	template<class T> bool PrefixTreeMock<T>::Contains(T candidate) const
	{
		cerr << "PrefixTreeMock<T>::Contains(T)" << endl;
		return true;
	}
	template<class T> void PrefixTreeMock<T>::Insert(T value)
	{
		cerr << "PrefixTreeMock<T>::Insert(T)" << endl;
	}
	template<class T> bool PrefixTreeMock<T>::IsEmpty() const
	{
		cerr << "PrefixTreeMock<T>::IsEmpty()" << endl;
		return true;
	}
	template<class T> bool PrefixTreeMock<T>::Remove(T value)
	{
		cerr << "PrefixTreeMock<T>::Remove(T)" << endl;
		return true;
	}
	template<class T> string PrefixTreeMock<T>::ToString() const
	{
		cerr << "PrefixTreeMock<T>::ToString()" << endl;
		return "PrefixTreeMock<T>::ToString()";
	}
}
