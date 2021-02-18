#pragma once
#include <iomanip>
#include <iostream>
#include <string>
#include "../DataStructures/PrefixTree.h"
namespace DataStructures
{
	using namespace std;
	class PrefixTreeCommandApp
	{
	public:
		PrefixTreeCommandApp();
		#pragma region Methods
		#pragma endregion
		PrefixTree<string>* getTestPrefixTree() const;
		#pragma region Methods : set
		#pragma endregion
		void setTestPrefixTree(PrefixTree<string>*);
		#pragma region Methods
		#pragma endregion
		void Run();
		#pragma region Properties
		#pragma endregion
		__declspec(property(get = getTestPrefixTree, put = setTestPrefixTree)) PrefixTree<string>* TestPrefixTree;
	private:
		void ClearTree();
		void DisplayBanner();
		int DisplayMenu();
		void DisplayTree();
		void ExitProgram();
		void InitializeTree();
		void InsertValue();
		void HandleInvalidCode();
		void RemoveValue();
		void SearchTree();
		#pragma region Fields
		#pragma endregion
		PrefixTree<string>* prefixTree;
		int choice;
		bool leaveMenu;
		#pragma region Constants
		#pragma endregion
		static const int DisplayTreeCode = 1;
		static const int InsertValueCode = 2;
		static const int SearchTreeCode = 3;
		static const int RemoveValueCode = 4;
		static const int ClearTreeCode = 5;
		static const int InitializeTreeCode = 6;
		static const int ExitProgramCode = 7;
	};
	PrefixTreeCommandApp::PrefixTreeCommandApp()
	{
		prefixTree = NULL;
		choice = 0;
		leaveMenu = false;
	}
	#pragma region Methods : get const
	#pragma endregion
	PrefixTree<string>* PrefixTreeCommandApp::getTestPrefixTree() const
	{
		return this->prefixTree;
	}
	#pragma region Methods : set
	#pragma endregion
	void PrefixTreeCommandApp::setTestPrefixTree(PrefixTree<string>* value)
	{
		this->prefixTree = value;
	}
	#pragma region Methods
	#pragma endregion
	void PrefixTreeCommandApp::Run()
	{
		leaveMenu = false;
		system("Color 80");
		InitializeTree();

		string userInput;
		do
		{
			choice = DisplayMenu();
			switch(choice)
			{
				case ClearTreeCode:		ClearTree();	  break;
				case DisplayTreeCode:	DisplayTree();    break;
				case ExitProgramCode:	ExitProgram();    break;
				case InitializeTreeCode:InitializeTree(); break;
				case InsertValueCode:	InsertValue();	  break;
				case RemoveValueCode:	RemoveValue();	  break;
				case SearchTreeCode:	SearchTree();	  break;
				default:	HandleInvalidCode();		  break;
			}
			system("pause");
		} while(!leaveMenu);
	}
	void PrefixTreeCommandApp::ClearTree()
	{
		prefixTree->Clear();
		cout << endl << "The Prefix Tree has been cleared." << endl;
	}
	void PrefixTreeCommandApp::DisplayBanner()
	{
		cout << "******************************************\n";
		cout << "               Prefix Tree \n";
		cout << "******************************************\n\n";
	}
	int PrefixTreeCommandApp::DisplayMenu()
	{
		int option;
		system("cls");
		DisplayBanner();
		string menu = " " + to_string(DisplayTreeCode) + " -> Display the Prefix Tree.\n"
			+ " " + to_string(InsertValueCode) + " -> Insert into Prefix Tree.\n"
			+ " " + to_string(SearchTreeCode) + " -> Search the Prefix Tree.\n"
			+ " " + to_string(RemoveValueCode) + " -> Delete from the Prefix Tree.\n"
			+ " " + to_string(ClearTreeCode) + " -> Clear the Prefix Tree.\n"
			+ " " + to_string(InitializeTreeCode) + " -> Initialize the Prefix Tree with default values.\n"
			+ " " + to_string(ExitProgramCode) + " -> Exit.\n\n"
			+ "******************************************\n"
			+ " \n  Enter your choice and press return: \n\n"
			+ "******************************************\n";

		cout << menu;
		cin >> option;
		return option;
	}
	void PrefixTreeCommandApp::DisplayTree()
	{
		system("cls");
		DisplayBanner();

		if(prefixTree->IsEmpty())
		{
			cout << "The Prefix Tree is empty." << endl << endl;
		}
		else
		{
			cout << prefixTree->ToString() << endl << endl;
		}
	}
	void PrefixTreeCommandApp::ExitProgram()
	{
		cout << "End of Program.\n";
		cin.get();
		leaveMenu = true;
	}
	void PrefixTreeCommandApp::HandleInvalidCode()
	{
		cout << "Not a Valid Choice. \n Please enter again! ";
	}
	void PrefixTreeCommandApp::InitializeTree()
	{
		prefixTree->Clear();
		cout << "Initialize Prefix Tree:";
		string namesValues[] = { "Tom" , "Una", "Mary", "Zaki", "Tim", "Amy" };	// { "Mark", "Ann", "Tom", "Sarah", "Simon" };
		for(string value : namesValues)
		{
			prefixTree->Insert(value);
			cout << " " << value << endl;
		}
		cout << "." << endl << endl;
	}
	void PrefixTreeCommandApp::InsertValue()
	{
		string userInput;
		do
		{
			cout << "\nPlease enter the name you would like to add: (Enter 0 to cancel)\n";
			cin >> userInput;
			if(userInput != "0")
			{
				cout << "Now adding " << userInput << endl;
				prefixTree->Insert(userInput);
			}
		} while(userInput != "0");
	}
	void PrefixTreeCommandApp::RemoveValue()
	{
		string userInput;

		cout << endl << "Please enter the name you would like to Delete:" << endl;
		cin >> userInput;

		if(prefixTree->Remove(userInput))
			cout << "Removed " << userInput << " from the Prefix Tree." << endl;
		else
			cout << "The Prefix Tree does not contain " << userInput << "." << endl;
	}
	void PrefixTreeCommandApp::SearchTree()
	{
		string userInput;
		do
		{
			cout << endl << "Please enter the name you would like to Search: (Enter 0 to cancel)" << endl;
			cin >> userInput;
			if(userInput != "0")
			{
				if(prefixTree->Contains(userInput))
					cout << "The Prefix Tree contains " << userInput << "." << endl;
				else
					cout << "The Prefix Tree does not contain " << userInput << "." << endl;
			}
		} while(userInput != "0");
	}
}