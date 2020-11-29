#pragma once
/*
 * Copyright (c) 2020 Mark Crowe <https://github.com/markcrowe-com>. All rights reserved.
 */
#include <string>
#include "../DataStructures/BinarySearchTree.h"
namespace DataStructures
{
	using namespace std;
	template<class T> class TreeInorderPrinter
	{
	public:
		TreeInorderPrinter()
		{
		}
		TreeInorderPrinter(BinarySearchTree<T>* tree)
		{
			this->tree = tree;
		}
	public:
		string PrintString()
		{
			if(tree->Nodes() == NULL)
				return "";

			string text = PrintString(tree->Nodes(), "", "", "");
			return text.substr(0, text.length() - 1);//.deleteCharAt(text.length() - 1);
			//return text;
		}
		string PrintString(BinaryTreeNode<T>* tree)
		{
			if(tree == NULL)
				return "";

			string text = PrintString(tree, "", "", "");
			return text.substr(0, text.length() - 1);//.deleteCharAt(text.length() - 1);
		}
	private:
		string PrintString(BinaryTreeNode<T>* node, string nodePrefix, string leftPrefix, string rightPrefix)
		{
			string valueString = TtoString(node->Value);

			size_t length = valueString.length();
			if(length % 2 == 0)
			{
				length--;
			}
			length >>= 1;

			string nodeString = "";
			BinaryTreeNode<T>* right = node->RightTree;
			if(right != NULL)
			{
				rightPrefix += Blank(length);
				nodeString += PrintString(right,
					rightPrefix + rightAppend,
					rightPrefix + lineAppend,
					rightPrefix + blankAppend);
			}

			nodeString += nodePrefix + valueString + "\n";
			BinaryTreeNode<T>* left = node->LeftTree;
			if(left != NULL)
			{
				leftPrefix += Blank(length);
				nodeString += PrintString(left,
					leftPrefix + leftAppend,
					leftPrefix + blankAppend,
					leftPrefix + lineAppend);
			}
			return nodeString;
		}
	public:
		static string Blank(size_t length)
		{
			string builder = "";
			while(length-- > 0)
			{
				builder += " ";
			}
			return builder;
		}
	private:
		int length = 2;
		string rightAppend = "*--";
		string  leftAppend = "*--";
		string blankAppend = "   ";
		string  lineAppend = ".  ";
	public:
		BinarySearchTree<T>* tree;
	};
}