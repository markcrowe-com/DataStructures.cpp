#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

typedef enum { LH, EH, RH } balance;

template <class ItemType>struct  TreeNode
{
	ItemType info;
	ItemType root;
	balance bf;
	TreeNode* left;
	TreeNode* right;
};

template <class ItemType>class TreeType
{
public:
	void DeleteItem(ItemType item);
	void InsertItem(ItemType item);
	string ToString();
private:
	TreeNode<ItemType>* root;
};


template<class ItemType>void Insert(TreeNode<ItemType>*& tree, ItemType item, bool& taller);
template<class T>string ToInOrderString(TreeNode<T>* tree);

template<class ItemType>string TreeType<ItemType>::ToString()
// Calls recursive function Delete to delete item from tree.
{
	return ToInOrderString<ItemType>(root);
}


/// 03 - AVL Part 2 File : Slide 17-19
template <class ItemType>
void TreeType<ItemType>::DeleteItem(ItemType item)
// Calls recursive function Delete to delete item from tree.
{
	bool shorter;
	Delete(root, item, shorter);
}
template <class ItemType>
void Delete(TreeNode<ItemType>*& tree, ItemType item, bool& shorter)
// Deletes item from tree.
// Post:	item is not in tree.
{
	if(tree != NULL)
	{
		if(item < tree->info)
		{
			Delete(tree->left, item, shorter);
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
		else if(item > tree->info)
		{
			Delete(tree->right, item, shorter);
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
		cout << "\nNOTE: " << item << " not in the tree so cannot be 					deleted.";
	}
}
/// 03 - AVL Part 2 File : Slide 17-19

/// 04 - LeftBalance File
template <class ItemType>
void LeftBalance(TreeNode<ItemType>*& tree, bool& taller)
{
	TreeNode<ItemType>* ls = tree->left;
	TreeNode<ItemType>* rs;

	switch(ls->bf)
	{
		case LH:	tree->bf = ls->bf = EH;
			RotateRight(tree);
			taller = false;
			break;
		case EH:	cerr << "Tree already balanced " << endl;
			break;
		case RH:	rs = ls->right;
			switch(rs->bf)
			{
				case LH:	tree->bf = RH;
					ls->bf = EH;		break;
				case EH:	tree->bf = ls->bf = EH;	break;
				case RH:	tree->bf = EH;
					ls->bf = LH;		break;
			}
			rs->bf = EH;
			RotateLeft(tree->left);
			RotateRight(tree);
			taller = false;
	}
}
/// 04 - LeftBalance File


/// 02 - Lecture 2 - AVL Trees (Part 1) File: Slide 29-36
template<class ItemType>void TreeType<ItemType> ::InsertItem(ItemType item)
// Calls recursive function Insert to insert item into tree.
{
	bool taller = false;
	Insert(root, item, taller);
}
template <class ItemType>
void Insert(TreeNode<ItemType>*& tree, ItemType item, bool& taller)
// Inserts item into tree.				  // Post:	item is in tree; search property is maintained.
{
	if(tree == NULL)
	{	// Insertion place found.
		tree = new TreeNode<ItemType>;
		tree->left = NULL;
		tree->right = NULL;
		tree->info = item;
		tree->bf = EH;
		taller = true;
	}
	else if(item == tree->info)
		cerr << "Duplicate key is not allowed in AVL tree." << endl;
	else if(item < tree->info)
	{
		Insert(tree->left, item, taller);  		// Insert into left subtree
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
		Insert(tree->right, item, taller);   		// Insert into right subtree
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
template <class ItemType>
void RightBalance(TreeNode<ItemType>*& tree, bool& taller)
{
	TreeNode<ItemType>* rs = tree->right;
	TreeNode<ItemType>* ls;

	switch(rs->bf)
	{
		case RH:	tree->bf = rs->bf = EH;
			RotateLeft(tree);
			taller = false;
			break;

		case EH:	cerr << "Tree already balanced " << endl;
			break;


		case LH:	ls = rs->left;
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
			RotateRight(tree->right);
			RotateLeft(tree);
			taller = false;
	}
}
/// 02 - Lecture 2 - AVL Trees (Part 1) File: Slide 29-36

/// 02 - Lecture 2 - AVL Trees (Part 1) File: Slide 15/16
template<class ItemType>void RotateLeft(TreeNode<ItemType>*& tree)
{
	TreeNode<ItemType>* rs;
	if(tree == NULL)
		cerr << "It is impossible to rotate an empty tree in RotateLeft"
		<< endl;
	else if(tree->right == NULL)
		cerr << "It is impossible to make an empty subtree the root in RotateLeft" << endl;
	else
	{
		rs = tree->right;
		tree->right = rs->left;
		rs->left = tree;
		tree = rs;
	}
}
/// 02 - Lecture 2 - AVL Trees (Part 1) File: Slide 15/16

/// 02 - Lecture 2 - AVL Trees (Part 1) File: Slide 21/22
template<class ItemType>void RotateRight(TreeNode<ItemType>*& tree)
{
	TreeNode<ItemType>* ls;
	if(tree == NULL)
		cerr << "It is impossible to rotate an empty tree in RotateRight"
		<< endl;
	else if(tree->left == NULL)
		cerr << "It is impossible to make an empty subtree the root in RotateRight" << endl;
	else
	{
		ls = tree->left;
		tree->left = ls->right;
		ls->right = tree;
		tree = ls;
	}
}
/// 02 - Lecture 2 - AVL Trees (Part 1) File: Slide 21/22

/// 06 - Delete Source Code File : Slide 4-7
template <class ItemType>
void DeleteNode(TreeNode <ItemType>*& tree, bool& shorter)
// Delete the node pointed to by tree.
// Post: The user's data in the node pointed to by tree is no longer in the tree. // If tree is a leaf node or has only one non-NULL child pointer, the node
// pointed to by tree is deleted; otherwise, the user's data is replaced by its
// logical predecessor and the predecessor's node is deleted.
{
	ItemType data;	TreeNode <ItemType>* tempPtr;
	tempPtr = tree;
	if(tree->left == NULL)
	{
		tree = tree->right;
		delete tempPtr;
		shorter = true;
	}
	else if(tree->right == NULL)
	{
		tree = tree->left;
		delete tempPtr;
		shorter = true;
	}
	else
	{
		GetPredecessor(tree, data);
		tree->info = data;
		Delete(tree->left, data, shorter);
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
template <class ItemType>
void GetPredecessor(TreeNode<ItemType>* tree, ItemType& data)
// Sets data to the info member of the right-most node in tree.
{
	tree = tree->left;
	while(tree->right != NULL)
		tree = tree->right;
	data = tree->info;
}
template <class ItemType>
void DelRightBalance(TreeNode<ItemType>*& tree, bool& shorter)
{
	TreeNode<ItemType>* rs = tree->right;
	TreeNode<ItemType>* ls;
	switch(rs->bf)
	{
		case RH:	tree->bf = rs->bf = EH;
			RotateLeft(tree);
			shorter = true; break;
		case EH:	tree->bf = RH;
			rs->bf = LH;
			RotateLeft(tree);
			shorter = false; break;
		case LH:	ls = rs->left;
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
			RotateRight(tree->right);
			RotateLeft(tree);
			shorter = true;
	}
}
template <class ItemType>
void DelLeftBalance(TreeNode<ItemType>*& tree, bool& shorter)
{
	TreeNode<ItemType>* ls = tree->left;
	TreeNode<ItemType>* rs;
	switch(ls->bf)
	{
		case LH:	tree->bf = ls->bf = EH;
			RotateRight(tree);
			shorter = true; break;
		case EH:	tree->bf = LH;
			ls->bf = RH;
			RotateRight(tree);
			shorter = false; break;
		case RH:	rs = ls->right;
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
			RotateLeft(tree->left);
			RotateRight(tree);
			shorter = true;
	}
}
/// 06 - Delete Source Code File : Slide 4-7

/// ToString

template<class T>string TtoString(T const& t)
{
	ostringstream myObjectStream;
	myObjectStream << t;
	return myObjectStream.str();
}
static string BalanceFactorToString(balance height)
{
	if(height == LH)
		return "Left Unbalanced";
	else if(height == RH)
		return "Right Unbalanced";
	else //if (height == Balanced)
		return "Balanced";
}

template<class T>string ToString(TreeNode<T>* tree)
{
	string lhs = tree->left == NULL ? "NULL" : TtoString(tree->left->info);
	string rhs = tree->right == NULL ? "NULL" : TtoString(tree->right->info);
	string balanceFactor = BalanceFactorToString(tree->bf);

	return "\n\t " + TtoString(tree->info) + ":\tLeft: " + lhs + " \tRight: " + rhs + " \tBalance Factor: " + balanceFactor;
}
template<class T>string ToInOrderString(TreeNode<T>* tree)
{
	if(tree == NULL)
		return "";
	else
	{
		string text = ToInOrderString(tree->left);
		text += ToString(tree);
		text += ToInOrderString(tree->right);
		return text;
	}
}
template<class T>string ToPreOrderString(TreeNode<T>* tree)
{
	if(tree != NULL)
	{
		string text = TtoString(tree->info) + " ";
		text += ToPreOrderString(tree->left);
		text += ToPreOrderString(tree->right);
		return text;
	}
	else
		return "";
}

