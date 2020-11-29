#pragma once
#include <iomanip>
#include <iostream>
#include <string>
#include "../DataStructures/AvlTree.h"
#include "TreeInorderPrinter.h"
namespace DataStructures
{
	using namespace std;
	class AvlTreeCommandApp
	{
	public:
		AvlTreeCommandApp();
		#pragma region Methods
		#pragma endregion
		AvlTree<string>* getTestAvlTree() const;
		#pragma region Methods : set
		#pragma endregion
		void setTestAvlTree(AvlTree<string>*);
		#pragma region Methods
		#pragma endregion
		void Run();
		#pragma region Properties
		#pragma endregion
		__declspec(property(get = getTestAvlTree, put = setTestAvlTree)) AvlTree<string>* TestAvlTree;
	private:
		void ClearAvlTree();
		void DisplayBanner();
		int DisplayMenu();
		void DisplayTree();
		void ExitProgram();
		void InitializeAvlTree();
		void InsertValue();
		void HandleInvalidCode();
		void RemoveValue();
		void SearchAvlTree();
		#pragma region Fields
		#pragma endregion
		DataStructures::AvlTree<string>* avlTree;
		int choice;
		bool leaveMenu;
		#pragma region Constants
		#pragma endregion
		static const int DisplayTreeCode = 1;
		static const int InsertValueCode = 2;
		static const int SearchAvlTreeCode = 3;
		static const int RemoveValueCode = 4;
		static const int ClearTreeCode = 5;
		static const int InitializeTreeCode = 6;
		static const int ExitProgramCode = 7;
	};
	AvlTreeCommandApp::AvlTreeCommandApp()
	{
		avlTree = NULL;
		choice = 0;
		leaveMenu = false;
	}
	#pragma region Methods : get const
	#pragma endregion
	AvlTree<string>* AvlTreeCommandApp::getTestAvlTree() const
	{
		return this->avlTree;
	}
	#pragma region Methods : set
	#pragma endregion
	void AvlTreeCommandApp::setTestAvlTree(AvlTree<string>* value)
	{
		this->avlTree = value;
	}
	#pragma region Methods
	#pragma endregion
	void AvlTreeCommandApp::Run()
	{
		leaveMenu = false;
		system("Color 80");
		InitializeAvlTree();

		string userInput;
		do
		{
			choice = DisplayMenu();
			switch(choice)
			{
				case ClearTreeCode:		ClearAvlTree();		break;
				case DisplayTreeCode:	DisplayTree();		break;
				case ExitProgramCode:	ExitProgram();		break;
				case InitializeTreeCode:InitializeAvlTree(); break;
				case InsertValueCode:	InsertValue();		break;
				case RemoveValueCode:	RemoveValue();		break;
				case SearchAvlTreeCode:	SearchAvlTree();	break;
				default:	HandleInvalidCode();			break;
			}
			system("pause");
		} while(!leaveMenu);
	}
	void AvlTreeCommandApp::ClearAvlTree()
	{
		avlTree->Clear();
		cout << endl << "The AVL Tree has been cleared." << endl;
	}
	void AvlTreeCommandApp::DisplayBanner()
	{
		cout << "******************************************\n";
		cout << "                 AVL Tree \n";
		cout << "******************************************\n\n";
	}
	int AvlTreeCommandApp::DisplayMenu()
	{
		int option;
		system("cls");
		DisplayBanner();
		string menu = " " + to_string(DisplayTreeCode) + " -> Display the AVL Tree.\n"
			+ " " + to_string(InsertValueCode) + " -> Insert into AVL Tree.\n"
			+ " " + to_string(SearchAvlTreeCode) + " -> Search the AVL Tree.\n"
			+ " " + to_string(RemoveValueCode) + " -> Delete from the AVL Tree.\n"
			+ " " + to_string(ClearTreeCode) + " -> Clear the AVL Tree.\n"
			+ " " + to_string(InitializeTreeCode) + " -> Initialize the AVL Tree with default values.\n"
			+ " " + to_string(ExitProgramCode) + " -> Exit.\n\n"
			+ "******************************************\n"
			+ " \n  Enter your choice and press return: \n\n"
			+ "******************************************\n";

		cout << menu;
		cin >> option;
		return option;
	}
	void AvlTreeCommandApp::DisplayTree()
	{
		system("cls");
		DisplayBanner();

		if(avlTree->IsEmpty())
		{
			cout << "The AVL Tree is empty." << endl << endl;
		}
		else
		{
			TreeInorderPrinter<string>* printer = new TreeInorderPrinter<string>(avlTree);
			cout << printer->PrintString() << endl << endl;
			cout << avlTree->ToString() << endl << endl;
		}
	}
	void AvlTreeCommandApp::ExitProgram()
	{
		cout << "End of Program.\n";
		cin.get();
		leaveMenu = true;
	}
	void AvlTreeCommandApp::HandleInvalidCode()
	{
		cout << "Not a Valid Choice. \n Please enter again! ";
	}
	void AvlTreeCommandApp::InitializeAvlTree()
	{
		avlTree->Clear();
		cout << "Initialize AVL Tree:";
		string namesValues[] = { "Tom" , "Una", "Mary", "Zaki", "Tim", "Amy" };	// { "Mark", "Ann", "Tom", "Sarah", "Simon" };
		for(string value : namesValues)
		{
			avlTree->Insert(value);
			cout << " " << value;
		}
		cout << "." << endl << endl;
	}
	void AvlTreeCommandApp::InsertValue()
	{
		string userInput;
		do
		{
			cout << "\nPlease enter the name you would like to add: (Enter 0 to cancel)\n";
			cin >> userInput;
			if(userInput != "0")
			{
				cout << "Now adding " << userInput << endl;
				avlTree->Insert(userInput);
			}
		} while(userInput != "0");
	}
	void AvlTreeCommandApp::RemoveValue()
	{
		string userInput;

		cout << endl << "Please enter the name you would like to Delete:" << endl;
		cin >> userInput;

		if(avlTree->Remove(userInput))
			cout << "Removed " << userInput << " from the AVL Tree." << endl;
		else
			cout << "The AVL Tree does not contain " << userInput << "." << endl;
	}
	void AvlTreeCommandApp::SearchAvlTree()
	{
		string userInput;
		do
		{
			cout << endl << "Please enter the name you would like to Search: (Enter 0 to cancel)" << endl;
			cin >> userInput;
			if(userInput != "0")
			{
				if(avlTree->Contains(userInput))
					cout << "The AVL Tree contains " << userInput << "." << endl;
				else
					cout << "The AVL Tree does not contain " << userInput << "." << endl;
			}
		} while(userInput != "0");
	}
}