#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "AvlTreeNodeComponentB.h"
namespace DataStructures
{
	using namespace std;
	template<class T>class AvlTreeComponentB : public AvlTree<T>
	{
	public:
		AvlTreeComponentB();
		~AvlTreeComponentB();
	public:
		void Clear();
		bool Contains(T candidate) const;
		void Insert(T value);
		bool IsEmpty() const;
		AvlTreeNode<T>* Nodes() const;
		bool Remove(T value);
		string ToString() const;
	private:
		AvlTreeNodeComponentB<T>* root;
	private:
		void DeleteItem(T item);
		void InsertItem(T item);
	};

	//
//	constructor/desturtor
//
	template<class T> AvlTreeComponentB<T>::AvlTreeComponentB()
	{
		root = NULL;
	}
	template<class T> AvlTreeComponentB<T>::~AvlTreeComponentB() { }
	#pragma region Public Methods
	#pragma endregion
	template<class T> void AvlTreeComponentB<T>::Clear()
	{
		root = NULL;
	}
	template<class T> bool AvlTreeComponentB<T>::Contains(T candidate) const
	{
		return ContainsValue<T>(root, candidate);
	}

	template<class T> bool AvlTreeComponentB<T>::IsEmpty() const
	{
		return root == NULL;
	}
	template<class T> void AvlTreeComponentB<T>::Insert(T value)
	{
		InsertItem(value);
		//root = InsertValue<T>(root, value);
	}
	template<class T> AvlTreeNode<T>* AvlTreeComponentB<T>::Nodes() const
	{
		return root; // should be a deep copy of Nodes
	}
	template<class T> bool AvlTreeComponentB<T>::Remove(T value)
	{
		bool present = Contains(value);
		if(present)
			DeleteItem(value);
		return present;
	}
	template<class T> string AvlTreeComponentB<T>::ToString() const
	{
		return ToInOrderString<T>(root);
	}


	template<class T>void InsertNode(AvlTreeNodeComponentB<T>*& tree, T item, bool& taller);

	/// 03 - AVL Part 2 File : Slide 17-19
	template <class T>
	void AvlTreeComponentB<T>::DeleteItem(T item)
		// Calls recursive function Delete to delete item from tree.
	{
		bool shorter;
		Delete(root, item, shorter);
	}
	template <class T>
	void Delete(AvlTreeNodeComponentB<T>*& tree, T item, bool& shorter)
		// Deletes item from tree.
		// Post:	item is not in tree.
	{
		if(tree != NULL)
		{
			if(item < tree->Value)
			{
				Delete(tree->leftTree, item, shorter);
				// Look in left subtree.
				if(shorter)
					switch(tree->bf)
					{
						case LH: tree->bf = EH; break;
						case EH: tree->bf = RH; shorter = false;
							break;
						case RH: DelRightBalance(tree, shorter);
					}
			}
			else if(item > tree->Value)
			{
				Delete(tree->rightTree, item, shorter);
				// Look in right subtree.
				if(shorter)
					switch(tree->bf)
					{
						case LH: DelLeftBalance(tree, shorter);
							break;
						case EH: tree->bf = LH; shorter = false; 							break;
						case RH: tree->bf = EH; break;
					}
			}
			else
				DeleteNode(tree, shorter);
			// Node found; call DeleteNode.
		}
		else
		{
			cerr << "\nNOTE: " << item << " not in the tree so cannot be deleted.";
		}
	}
	/// 03 - AVL Part 2 File : Slide 17-19

	/// 04 - LeftBalance File
	template <class T>
	void LeftBalance(AvlTreeNodeComponentB<T>*& tree, bool& taller)
	{
		AvlTreeNodeComponentB<T>* ls = tree->leftTree;
		AvlTreeNodeComponentB<T>* rs;

		switch(ls->bf)
		{
			case LH:	tree->bf = ls->bf = EH;
				RotateRight(tree);
				taller = false;
				break;
			case EH:	cerr << "Tree already balanced " << endl;
				break;
			case RH:	rs = ls->rightTree;
				switch(rs->bf)
				{
					case LH:	tree->bf = RH;
						ls->bf = EH;		break;
					case EH:	tree->bf = ls->bf = EH;	break;
					case RH:	tree->bf = EH;
						ls->bf = LH;		break;
				}
				rs->bf = EH;
				RotateLeft(tree->leftTree);
				RotateRight(tree);
				taller = false;
		}
	}
	/// 04 - LeftBalance File


	/// 02 - Lecture 2 - AVL Trees (Part 1) File: Slide 29-36
	template<class T>void AvlTreeComponentB<T> ::InsertItem(T item)
		// Calls recursive function Insert to insert item into tree.
	{
		bool taller = false;
		InsertNode(root, item, taller);
	}
	template <class T>
	void InsertNode(AvlTreeNodeComponentB<T>*& tree, T item, bool& taller)
		// Inserts item into tree.				  // Post:	item is in tree; search property is maintained.
	{
		if(tree == NULL)
		{	// Insertion place found.
			tree = new AvlTreeNodeComponentB<T>(item);
			taller = true;
		}
		else if(item == tree->Value)
			cerr << "Duplicate key is not allowed in AVL tree." << endl;
		else if(item < tree->Value)
		{
			InsertNode(tree->leftTree, item, taller);  		// Insert into left subtree
			if(taller)
				switch(tree->bf)
				{
					case LH: LeftBalance(tree, taller); break;
					case EH: tree->bf = LH; break;
					case RH: tree->bf = EH;
						taller = false; break;
				}
		}
		else {
			InsertNode(tree->rightTree, item, taller);   		// Insert into right subtree
			if(taller)
				switch(tree->bf)
				{
					case RH: RightBalance(tree, taller); break;
					case EH: tree->bf = RH; break;
					case LH: tree->bf = EH;
						taller = false; break;
				}
		}
	}
	template <class T>
	void RightBalance(AvlTreeNodeComponentB<T>*& tree, bool& taller)
	{
		AvlTreeNodeComponentB<T>* rs = tree->rightTree;
		AvlTreeNodeComponentB<T>* ls;

		switch(rs->bf)
		{
			case RH:	tree->bf = rs->bf = EH;
				RotateLeft(tree);
				taller = false;
				break;

			case EH:	cerr << "Tree already balanced " << endl;
				break;


			case LH:	ls = rs->leftTree;
				switch(ls->bf)
				{
					case RH:	tree->bf = LH;
						rs->bf = EH;
						break;
					case EH:	tree->bf = rs->bf = EH;
						break;
					case LH:	tree->bf = EH;
						rs->bf = RH;
						break;
				}
				ls->bf = EH;
				RotateRight(tree->rightTree);
				RotateLeft(tree);
				taller = false;
		}
	}
	/// 02 - Lecture 2 - AVL Trees (Part 1) File: Slide 29-36

	/// 02 - Lecture 2 - AVL Trees (Part 1) File: Slide 15/16
	template<class T>void RotateLeft(AvlTreeNodeComponentB<T>*& tree)
	{
		AvlTreeNodeComponentB<T>* rs;
		if(tree == NULL)
			cerr << "It is impossible to rotate an empty tree in RotateLeft"
			<< endl;
		else if(tree->RightTree == NULL)
			cerr << "It is impossible to make an empty subtree the root in RotateLeft" << endl;
		else
		{
			rs = tree->rightTree;
			tree->rightTree = rs->leftTree;
			rs->leftTree = tree;
			tree = rs;
		}
	}
	/// 02 - Lecture 2 - AVL Trees (Part 1) File: Slide 15/16

	/// 02 - Lecture 2 - AVL Trees (Part 1) File: Slide 21/22
	template<class T>void RotateRight(AvlTreeNodeComponentB<T>*& tree)
	{
		AvlTreeNodeComponentB<T>* ls;
		if(tree == NULL)
			cerr << "It is impossible to rotate an empty tree in RotateRight"
			<< endl;
		else if(tree->LeftTree == NULL)
			cerr << "It is impossible to make an empty subtree the root in RotateRight" << endl;
		else
		{
			ls = tree->leftTree;
			tree->leftTree = ls->rightTree;
			ls->rightTree = tree;
			tree = ls;
		}
	}
	/// 02 - Lecture 2 - AVL Trees (Part 1) File: Slide 21/22

	/// 06 - Delete Source Code File : Slide 4-7
	template <class T>
	void DeleteNode(AvlTreeNodeComponentB <T>*& tree, bool& shorter)
		// Delete the node pointed to by tree.
		// Post: The user's data in the node pointed to by tree is no longer in the tree. // If tree is a leaf node or has only one non-NULL child pointer, the node
		// pointed to by tree is deleted; otherwise, the user's data is replaced by its
		// logical predecessor and the predecessor's node is deleted.
	{
		T data;	AvlTreeNodeComponentB <T>* tempPtr;
		tempPtr = tree;
		if(tree->LeftTree == NULL)
		{
			tree = tree->rightTree;
			delete tempPtr;
			shorter = true;
		}
		else if(tree->RightTree == NULL)
		{
			tree = tree->leftTree;
			delete tempPtr;
			shorter = true;
		}
		else
		{
			GetPredecessor(tree, data);
			tree->Value = data;
			Delete(tree->leftTree, data, shorter);
			// Delete the predecessor node
			if(shorter)
				switch(tree->bf)
				{
					case LH: tree->bf = EH; break;
					case EH: tree->bf = RH; shorter = false;
						break;
					case RH: DelRightBalance(tree, shorter);
				}
		}
	}
	template <class T>
	void GetPredecessor(AvlTreeNodeComponentB<T>* tree, T& data)
		// Sets data to the info member of the right-most node in tree.
	{
		tree = tree->leftTree;
		while(tree->RightTree != NULL)
			tree = tree->rightTree;
		data = tree->Value;
	}
	template <class T>
	void DelRightBalance(AvlTreeNodeComponentB<T>*& tree, bool& shorter)
	{
		AvlTreeNodeComponentB<T>* rs = tree->rightTree;
		AvlTreeNodeComponentB<T>* ls;
		switch(rs->bf)
		{
			case RH:	tree->bf = rs->bf = EH;
				RotateLeft(tree);
				shorter = true; break;
			case EH:	tree->bf = RH;
				rs->bf = LH;
				RotateLeft(tree);
				shorter = false; break;
			case LH:	ls = rs->leftTree;
				switch(ls->bf)
				{
					case RH:	tree->bf = LH;
						rs->bf = EH; break;
					case EH:	tree->bf = rs->bf = EH;
						break;
					case LH:	tree->bf = EH;
						rs->bf = RH; break;
				} // END SWITCH

				ls->bf = EH;
				RotateRight(tree->rightTree);
				RotateLeft(tree);
				shorter = true;
		}
	}
	template <class T>
	void DelLeftBalance(AvlTreeNodeComponentB<T>*& tree, bool& shorter)
	{
		AvlTreeNodeComponentB<T>* ls = tree->leftTree;
		AvlTreeNodeComponentB<T>* rs;
		switch(ls->bf)
		{
			case LH:	tree->bf = ls->bf = EH;
				RotateRight(tree);
				shorter = true; break;
			case EH:	tree->bf = LH;
				ls->bf = RH;
				RotateRight(tree);
				shorter = false; break;
			case RH:	rs = ls->rightTree;
				switch(rs->bf)
				{
					case LH:	tree->bf = RH;
						ls->bf = EH; break;
					case EH:	tree->bf = ls->bf = EH;
						break;
					case RH:	tree->bf = EH;
						ls->bf = LH; break;
				} // END SWITCH
				rs->bf = EH;
				RotateLeft(tree->leftTree);
				RotateRight(tree);
				shorter = true;
		}
	}
	/// 06 - Delete Source Code File : Slide 4-7

	/// ToString
}