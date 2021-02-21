/*
 * Copyright (c) 2020 Mark Crowe <https://github.com/markcrowe-com>. All rights reserved.
 */
 //
 // DataStructures.ConsoleApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
 //
#include <iostream>
#include <string>
#include "../DataStructures.CommandLineInterface/AvlTreeCommandApp.h"
#include "../DataStructures.CommandLineInterface/PrefixTreeCommandApp.h"
#include "../DataStructures.Implementation/AvlTreeComponent.h"
#include "../DataStructures.Implementation/AvlTreeComponentB.h"
#include "../DataStructures.Mocks/PrefixTreeMock.h"
#include "../DataStructures.Implementation/GraphType.Methods.h"

using namespace DataStructures;
using namespace std;

struct Airport
{
public:
	Airport() {}
	Airport(string name)
	{
		this->name = name;
	}
	//
	//	Properties
	//
	string Name()
	{
		return this->name;
	}
	void Name(string name)
	{
		this->name = name;
	}
	friend ostream& operator<<(ostream& os, const Airport& airport)
	{
		os << airport.name;
		return os;
	}
	friend bool operator==(const Airport& lhs, const Airport& rhs)
	{
		return lhs.name == rhs.name;
	}
	//
	//	Methods
	//
	string toString()
	{
		return this->name;
	}
	//
	//	Fields
	//
private:
	string name;
};

int main()
{
	//AvlTreeCommandApp avlTreeCommandApp;
	//avlTreeCommandApp.TestAvlTree = new AvlTreeComponentB<string>();
	//avlTreeCommandApp.Run();

	GraphType<Airport> graph;

	Airport v0("0");
	Airport v1("1");
	Airport v2("2");
	Airport v3("3");
	Airport v4("4");

	graph.AddVertex(v0);
	graph.AddVertex(v1);
	graph.AddVertex(v2);
	graph.AddVertex(v3);
	graph.AddVertex(v4);


	graph.AddEdge(v0, v1, 5);
	graph.AddEdge(v0, v2, 3);
	graph.AddEdge(v0, v4, 2);

	graph.AddEdge(v1, v2, 2);
	graph.AddEdge(v1, v3, 6);

	graph.AddEdge(v2, v1, 1);
	graph.AddEdge(v2, v3, 2);

	graph.AddEdge(v4, v1, 6);
	graph.AddEdge(v4, v2, 10);
	graph.AddEdge(v4, v3, 3);

	ShortestPathLecturerVersion<Airport>(graph, v0);
	//TODO: Fix Error: Graph is destroyed by destructer after function call!
	ShortestPathLecturerVersion<Airport>(graph, v0);
	//TODO: Fix Error: Graph is destroyed by destructer after function call!
	ShortestPath<Airport>(graph, v0);

	/*PrefixTreeCommandApp prefixTreeCommandApp;
	prefixTreeCommandApp.TestPrefixTree = new PrefixTreeMock<string>();
	prefixTreeCommandApp.Run();*/

	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
