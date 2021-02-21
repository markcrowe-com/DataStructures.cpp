#pragma once
/*
 * Copyright (c) 2021 Mark Crowe <https://github.com/markcrowe-com>. All rights reserved.
 */
#include <queue>
#include <list>
#include <iostream>
using namespace std;
namespace DataStructuresGFG
{
	// Program to shortest path from a given source vertex ‘s’ to
	// a given destination vertex ‘t’. Expected time complexity
	// is O(vertexCount+E).

	// This class represents a directed graph using adjacency
	// list representation
	class Graph
	{
		int vertexCount; // No. of vertices
		list<int>* adj; // adjacency lists
	public:
		Graph(int vertexCount); // Constructor
		void addEdge(int v, int w, int weight); // adds an edge

		// finds shortest path from source vertex ‘s’ to
		// destination vertex ‘d’.
		int findShortestPath(int s, int d);

		// print shortest path from a source vertex ‘s’ to
		// destination vertex ‘d’.
		int printShortestPath(int parent[], int s, int d);
	};

	Graph::Graph(int vertexCount)
	{
		this->vertexCount = vertexCount;
		adj = new list<int>[2 * vertexCount];
	}

	void Graph::addEdge(int v, int w, int weight)
	{
		// split all edges of weight 2 into two
		// edges of weight 1 each. The intermediate
		// vertex number is maximum vertex number + 1,
		// that is vertexCount.
		if(weight == 2)
		{
			adj[v].push_back(v + vertexCount);
			adj[v + vertexCount].push_back(w);
		}
		else // Weight is 1
			adj[v].push_back(w); // Add w to v’s list.
	}

	// To print the shortest path stored in parent[]
	int Graph::printShortestPath(int parent[], int s, int d)
	{
		static int level = 0;

		// If we reached root of shortest path tree
		if(parent[s] == -1)
		{
			cout << "Shortest Path between " << s << " and "
				<< d << " is " << s << " ";
			return level;
		}

		printShortestPath(parent, parent[s], d);

		level++;
		if(s < vertexCount)
			cout << s << " ";

		return level;
	}

	// This function mainly does BFS and prints the
	// shortest path from src to dest. It is assumed
	// that weight of every edge is 1
	int Graph::findShortestPath(int src, int dest)
	{
		// Mark all the vertices as not visited
		bool* visited = new bool[2 * vertexCount];
		int* parent = new int[2 * vertexCount];

		// Initialize parent[] and visited[]
		for(int i = 0; i < 2 * vertexCount; i++)
		{
			visited[i] = false;
			parent[i] = -1;
		}

		// Create a queue for BFS
		list<int> queue;

		// Mark the current node as visited and enqueue it
		visited[src] = true;
		queue.push_back(src);

		// 'i' will be used to get all adjacent vertices of a vertex
		list<int>::iterator i;

		while(!queue.empty())
		{
			// Dequeue a vertex from queue and print it
			int s = queue.front();

			if(s == dest)
				return printShortestPath(parent, s, dest);

			queue.pop_front();

			// Get all adjacent vertices of the dequeued vertex s
			// If a adjacent has not been visited, then mark it
			// visited and enqueue it
			for(i = adj[s].begin(); i != adj[s].end(); ++i)
			{
				if(!visited[*i])
				{
					visited[*i] = true;
					queue.push_back(*i);
					parent[*i] = s;
				}
			}
		}
	}

	// Driver program to test methods of graph class
	int main()
	{
		// Create a graph given in the above diagram
		int vertexCount = 4;
		Graph graph(vertexCount);
		graph.addEdge(0, 1, 2);
		graph.addEdge(0, 2, 2);

		graph.addEdge(1, 2, 1);
		graph.addEdge(1, 3, 1);

		graph.addEdge(2, 0, 1);
		graph.addEdge(2, 3, 2);

		graph.addEdge(3, 3, 2);

		int src = 0, dest = 3;
		cout << "\nShortest Distance between " << src
			<< " and " << dest << " is "
			<< graph.findShortestPath(src, dest);

		return 0;
	}
}