/*
 * Copyright (c) 2020 Mark Crowe <https://github.com/markcrowe-com>. All rights reserved.
 */
#pragma once
#include <sstream>
#include <string>
#include "../DataStructures/AvlBalanceFactor.h"
#include "../DataStructures/AvlTreeNode.h"
#include "AvlTreeNodeComponent.h"
namespace DataStructures
{
	using namespace std;

	template<class T>AvlTreeNode<T>* BalanceTreeAfterDeletion(AvlTreeNode<T>*&);
	template<class T>AvlTreeNode<T>* BalanceTreeAfterInsert(AvlTreeNode<T>*&, T&);
	template<class T> int CalculateHeight(AvlTreeNode<T>*);
	template<class T>bool ContainsValue(AvlTreeNode<T>*, T);
	template<class T>AvlTreeNode<T>* DeleteNodeByValue(AvlTreeNode<T>*, T);
	template<class T>AvlTreeNode<T>* GetLeftmostNode(AvlTreeNode<T>*);
	template<class T>AvlTreeNode<T>* InsertValue(AvlTreeNode<T>*, T);
	template<class T>AvlTreeNode<T>* RotateRight(AvlTreeNode<T>*);
	template<class T>AvlTreeNode<T>* RotateLeft(AvlTreeNode<T>*);
	template<class T>string ToInOrderString(AvlTreeNode<T>* tree);
	template<class T>string ToPreOrderString(AvlTreeNode<T>* tree);
	template<class T>string ToString(AvlTreeNode<T>* tree);
	template<class T>string TtoString(T const& t);

	template<class T>AvlTreeNode<T>* BalanceTreeAfterDeletion(AvlTreeNode<T>*& tree)
	{
		tree->UpdateHeight();
		int balanceFactor = tree->CalculateHeightDifference();

		if(balanceFactor > AvlBalanceFactor::LeftUnbalanced)
		{
			int leftBalanceFactor = tree->LeftTree->CalculateHeightDifference();
			if(leftBalanceFactor >= AvlBalanceFactor::Balanced)
				return RotateRight(tree);
			else if(leftBalanceFactor < AvlBalanceFactor::Balanced)
			{
				tree->LeftTree = RotateLeft(tree->LeftTree);
				return RotateRight(tree);
			}
		}
		else if(balanceFactor < AvlBalanceFactor::RightUnbalanced)
		{
			int rightBalanceFactor = tree->RightTree->CalculateHeightDifference();
			if(rightBalanceFactor <= AvlBalanceFactor::Balanced)
				return RotateLeft(tree);
			else if(rightBalanceFactor > AvlBalanceFactor::Balanced)
			{
				tree->RightTree = RotateRight(tree->RightTree);
				return RotateLeft(tree);
			}
		}
		return tree;
	}
	template<class T>AvlTreeNode<T>* BalanceTreeAfterInsert(AvlTreeNode<T>*& tree, T& value)
	{
		tree->UpdateHeight();
		int balanceFactor = tree->CalculateHeightDifference();

		if(balanceFactor > AvlBalanceFactor::LeftUnbalanced)
		{
			if(value < tree->LeftTree->Value)
				return RotateRight(tree);
			else if(value > tree->LeftTree->Value)
			{
				tree->LeftTree = RotateLeft(tree->LeftTree);
				return RotateRight(tree);
			}
			else return tree;
		}
		else if(balanceFactor < AvlBalanceFactor::RightUnbalanced)
		{
			if(value > tree->RightTree->Value)
				return RotateLeft(tree);
			else if(value < tree->RightTree->Value)
			{
				tree->RightTree = RotateRight(tree->RightTree);
				return RotateLeft(tree);
			}
			else return tree;
		}
		else return tree;
	}
	template<class T> int CalculateHeight(AvlTreeNode<T>* avlTreeNode)
	{
		return avlTreeNode == NULL ? 0 : avlTreeNode->Height;
	}
	template<class T>bool ContainsValue(AvlTreeNode<T>* tree, T value)
	{
		if(tree == NULL)
			return false;
		else if(value < tree->Value)
			return ContainsValue(tree->LeftTree, value);
		else if(value > tree->Value)
			return ContainsValue(tree->RightTree, value);
		else
			return value == tree->Value;
	}
	template<class T>AvlTreeNode<T>* DeleteNodeByValue(AvlTreeNode<T>* tree, T value)
	{
		if(tree == NULL)
			return tree;
		else
		{
			if(value < tree->Value)
				tree->LeftTree = DeleteNodeByValue(tree->LeftTree, value);
			else if(value > tree->Value)
				tree->RightTree = DeleteNodeByValue(tree->RightTree, value);
			else //if (value == root->Value)
			{
				if((tree->IsNotComplete()))
				{
					AvlTreeNode<T>* nodeToDelete = tree->LeftTree ? tree->LeftTree : tree->RightTree;

					if(nodeToDelete == NULL) // both branches are empty
					{
						nodeToDelete = tree;
						tree = NULL;
						//return root;
					}
					else
					{
						//*tree = *nodeToDelete; // Copy the contents of the non-empty child
						tree->Value = nodeToDelete->Value; // Copy the contents of the non-empty child
						tree->LeftTree = NULL;
						tree->RightTree = NULL;
					}
					delete nodeToDelete;
				}
				else
				{
					AvlTreeNode<T>* leftmostNode = GetLeftmostNode(tree->RightTree);
					tree->Value = leftmostNode->Value;
					tree->RightTree = DeleteNodeByValue(tree->RightTree, leftmostNode->Value);
				}
			}

			// If the tree had only one node then return
			if(tree == NULL)
				return tree;

			return BalanceTreeAfterDeletion(tree);
		}
	}
	template<class T>AvlTreeNode<T>* GetLeftmostNode(AvlTreeNode<T>* tree)
	{
		AvlTreeNode<T>* iterator = tree;
		for(; iterator->LeftTree != NULL; iterator = iterator->LeftTree)
		{
		}
		return iterator;
	}
	template<class T>AvlTreeNode<T>* InsertValue(AvlTreeNode<T>* tree, T value)
	{
		if(tree == NULL)
			return new AvlTreeNodeComponent<T>(value);
		else
		{
			if(value < tree->Value)
				tree->LeftTree = InsertValue(tree->LeftTree, value);
			else if(value > tree->Value)
				tree->RightTree = InsertValue(tree->RightTree, value);
			else // Equal keys are not allowed in BST
				return tree;

			return BalanceTreeAfterInsert(tree, value);
		}
	}
	template<class T>AvlTreeNode<T>* RotateRight(AvlTreeNode<T>* root)
	{
		AvlTreeNode<T>* newRoot = root->LeftTree;
		AvlTreeNode<T>* rootNewLeft = newRoot->RightTree;

		newRoot->RightTree = root;
		root->LeftTree = rootNewLeft;

		root->UpdateHeight();
		newRoot->UpdateHeight();

		return newRoot;
	}
	template<class T>AvlTreeNode<T>* RotateLeft(AvlTreeNode<T>* root)
	{
		AvlTreeNode<T>* newRoot = root->RightTree;
		AvlTreeNode<T>* rootNewRight = newRoot->LeftTree;

		newRoot->LeftTree = root;
		root->RightTree = rootNewRight;

		root->UpdateHeight();
		newRoot->UpdateHeight();

		return newRoot;
	}
	template<class T>string ToInOrderString(AvlTreeNode<T>* tree)
	{
		if(tree == NULL)
			return "";
		else
		{
			string text = ToInOrderString(tree->LeftTree);
			text += ToString(tree);
			text += ToInOrderString(tree->RightTree);
			return text;
		}
	}
	template<class T>string ToPreOrderString(AvlTreeNode<T>* tree)
	{
		if(tree != NULL)
		{
			string text = TtoString(tree->Value) + " ";
			text += ToPreOrderString(tree->LeftTree);
			text += ToPreOrderString(tree->RightTree);
			return text;
		}
		else
			return "";
	}
	template<class T>string ToString(AvlTreeNode<T>* tree)
	{
		string lhs = tree->LeftTree == NULL ? "NULL" : TtoString(tree->LeftTree->Value);
		string rhs = tree->RightTree == NULL ? "NULL" : TtoString(tree->RightTree->Value);
		string balanceFactor = AvlBalanceFactor::ToString(tree->CalculateHeightDifference());

		return "\n\t " + TtoString(tree->Value) + ":\tLeft: " + lhs + " \tRight: " + rhs + " \tBalance Factor: " + balanceFactor;
	}
	template<class T>string TtoString(T const& t)
	{
		ostringstream myObjectStream;
		myObjectStream << t;
		return myObjectStream.str();
	}
}