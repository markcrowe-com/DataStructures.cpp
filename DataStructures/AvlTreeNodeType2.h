#pragma once
namespace DataStructuresRefactor
{
	using namespace std;
	enum class BalanceFactor { LeftHigher, EqualHeight, RightHigher };
	/// <summary>
	///	Avl Tree Node
	/// </summary>
	/// <typeparam name="T"></typeparam>
	template<class T> __interface AvlTreeNode
	{
		#pragma region Methods : get const
		#pragma endregion
		BalanceFactor getBalanceFactor() const;
		AvlTreeNode<T>* getLeftTree() const;
		AvlTreeNode<T>* getRightTree() const;
		T getValue() const;
		#pragma region Methods : set
		#pragma endregion
		void setBalanceFactor(BalanceFactor value);
		void setLeftTree(AvlTreeNode<T>* value);
		void setRightTree(AvlTreeNode<T>* value);
		void setValue(T value);
		#pragma region Properties
		#pragma endregion
		__declspec(property(get = getBalanceFactor, put = setBalanceFactor))  BalanceFactor BalanceFactor;
		__declspec(property(get = getLeftTree, put = setLeftTree)) AvlTreeNode<T>* LeftTree;
		__declspec(property(get = getRightTree, put = setRightTree)) AvlTreeNode<T>* RightTree;
		__declspec(property(get = getValue, put = setValue)) T Value;
	};
}