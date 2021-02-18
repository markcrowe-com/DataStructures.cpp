#pragma once
#include <iostream>
#include "../DataStructures/AvlTreeNode.h"
#include "../DataStructures/AvlBalanceFactor.h"
namespace DataStructures
{
	using namespace std;
	enum class balance { LH, EH, RH };
	template<class T> struct AvlTreeNodeComponentB : public AvlTreeNode<T>
	{
		AvlTreeNodeComponentB();
		AvlTreeNodeComponentB(T);
	public:
		#pragma region Methods : get const
		#pragma endregion
		int getHeight() const;
		AvlTreeNode<T>* getLeftTree() const;
		AvlTreeNode<T>* getRightTree() const;
		T getValue() const;
		#pragma region Methods : set
		#pragma endregion
		void setHeight(int);
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
		//__declspec(property(get = getBalanceFactor, put = setBalanceFactor)) balance BalanceFactor;

		#pragma region Fields
		#pragma endregion
		balance bf;//balanceFactor
		#pragma region Methods : get const
		#pragma endregion
		balance getBalanceFactor() const;
		void setBalanceFactor(balance value);
		AvlTreeNodeComponentB<T>* leftTree;
		AvlTreeNodeComponentB<T>* rightTree;
	private:
		T value;
	};
	template<class T> AvlTreeNodeComponentB<T>::AvlTreeNodeComponentB()
	{
		this->bf = balance::EH;
		this->leftTree = this->rightTree = NULL;
	}
	template<class T> AvlTreeNodeComponentB<T>::AvlTreeNodeComponentB(T value)
	{
		this->bf = balance::EH;
		this->leftTree = this->rightTree = NULL;
		this->value = value;
	}
	#pragma region Methods : get const
	#pragma endregion
	template<class T> int AvlTreeNodeComponentB<T>::getHeight() const
	{
		cerr << "AvlTreeNodeComponentB<T>::getHeight()" << endl;
		return 1;
	}
	template<class T> AvlTreeNode<T>* AvlTreeNodeComponentB<T>::getLeftTree() const
	{
		return this->leftTree;
	}
	template<class T> AvlTreeNode<T>* AvlTreeNodeComponentB<T>::getRightTree() const
	{
		return this->rightTree;
	}
	template<class T> T AvlTreeNodeComponentB<T>::getValue() const
	{
		return this->value;
	}
	#pragma region Methods : set
	#pragma endregion
	template<class T> void AvlTreeNodeComponentB<T>::setHeight(int value)
	{
		cerr << "AvlTreeNodeComponentB<T>::setHeight(int value)" << endl;
	}
	template<class T> void AvlTreeNodeComponentB<T>::setLeftTree(AvlTreeNode<T>* value)
	{
		//this->leftTree = value;
	}
	template<class T> void AvlTreeNodeComponentB<T>::setRightTree(AvlTreeNode<T>* value)
	{
		//this->rightTree = value;
	}
	template<class T> void AvlTreeNodeComponentB<T>::setValue(T value)
	{
		this->value = value;
	}
	#pragma region Methods
	#pragma endregion
	template<class T> int AvlTreeNodeComponentB<T>::CalculateHeightDifference() const
	{
		if(bf == balance::EH)
			return AvlBalanceFactor::Balanced;
		else if(bf == balance::LH)
			return AvlBalanceFactor::LeftUnbalanced;
		else
			return AvlBalanceFactor::RightUnbalanced;
	}
	template<class T> bool AvlTreeNodeComponentB<T>::IsComplete() const
	{
		return this->leftTree != NULL && this->rightTree != NULL;
	}
	template<class T> bool AvlTreeNodeComponentB<T>::IsLeaf() const
	{
		return this->leftTree == NULL && this->rightTree == NULL;
	}
	template<class T> bool AvlTreeNodeComponentB<T>::IsNotComplete() const
	{
		return this->leftTree == NULL || this->rightTree == NULL;
	}
	template<class T> void AvlTreeNodeComponentB<T>::UpdateHeight()
	{
		cerr << "AvlTreeNodeComponentB<T>::UpdateHeight()" << endl;
	}
	#pragma region Methods : get const
	#pragma endregion
	template<class T> balance AvlTreeNodeComponentB<T>::getBalanceFactor() const
	{
		return this->bf;
	}
	#pragma region Methods : set
	#pragma endregion
	template<class T> void AvlTreeNodeComponentB<T>::setBalanceFactor(balance value)
	{
		this->bf = value;
	}
}