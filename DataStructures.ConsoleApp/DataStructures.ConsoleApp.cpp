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
#include "Vertex.h"
using namespace DataStructures;
using namespace std;

void airportGraphExample();
void graphExample();
Vertex AddNewVertex(GraphType<Vertex>* graph, string name);

using namespace std;

int main()
{
	airportGraphExample();
	graphExample();

	//AvlTreeCommandApp avlTreeCommandApp;
	//avlTreeCommandApp.TestAvlTree = new AvlTreeComponentB<string>();
	//avlTreeCommandApp.Run();

	/*PrefixTreeCommandApp prefixTreeCommandApp;
	prefixTreeCommandApp.TestPrefixTree = new PrefixTreeMock<string>();
	prefixTreeCommandApp.Run();*/

	return 0;
}
void airportGraphExample()
{
	GraphType<Vertex> graph;
	Vertex atlanta = AddNewVertex(&graph, "Atlanta");
	Vertex austin = AddNewVertex(&graph, "Austin");
	Vertex chicago = AddNewVertex(&graph, "Chicago");
	Vertex dallas = AddNewVertex(&graph, "Dallas");
	Vertex denver = AddNewVertex(&graph, "Denver");
	Vertex houston = AddNewVertex(&graph, "Houston");
	Vertex washington = AddNewVertex(&graph, "Washington");

	graph.AddEdge(atlanta, washington, 600);
	graph.AddEdge(atlanta, houston, 800);

	graph.AddEdge(austin, dallas, 200);
	graph.AddEdge(austin, houston, 160);

	graph.AddEdge(chicago, denver, 1000);

	graph.AddEdge(dallas, austin, 200);
	graph.AddEdge(dallas, denver, 780);
	graph.AddEdge(dallas, chicago, 900);

	graph.AddEdge(denver, atlanta, 1400);
	graph.AddEdge(denver, chicago, 1000);

	graph.AddEdge(houston, atlanta, 800);

	graph.AddEdge(washington, atlanta, 600);
	graph.AddEdge(washington, dallas, 1300);

	ShortestPath<Vertex>(&graph, washington);
	//TODO: Fix Error: Graph is destroyed by destructer after function call!
	//ShortestPathLecturerVersion<Vertex>(graph, washington);
}
void graphExample()
{
	GraphType<Vertex> graph;
	Vertex v0 = AddNewVertex(&graph, "0");
	Vertex v1 = AddNewVertex(&graph, "1");
	Vertex v2 = AddNewVertex(&graph, "2");
	Vertex v3 = AddNewVertex(&graph, "3");
	Vertex v4 = AddNewVertex(&graph, "4");

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

	ShortestPath<Vertex>(&graph, v0);
	//TODO: Fix Error: Graph is destroyed by destructer after function call!
	//ShortestPathLecturerVersion<Vertex>(graph, v0);
}
Vertex AddNewVertex(GraphType<Vertex>* graph, string name)
{
	Vertex vertex(name);
	graph->AddVertex(vertex);
	return vertex;
}
