#pragma once
/*
 * Copyright (c) 2021 Mark Crowe <https://github.com/markcrowe-com>. All rights reserved.
 */
#include <queue>
#include "GraphType.h"
namespace DataStructures
{
	using namespace std;
	template<class VertexType>
	struct ItemType
	{
		// < means greater distance
		//bool operator<(ItemType otherItem);
		//bool operator==(ItemType otherItem);
		//bool operator<=(ItemType otherItem);
		//
		//	Fields
		//
		VertexType fromVertex;
		VertexType toVertex;
		int distance;
	};

	template<class VertexType>void ShortestPath(GraphType<VertexType> graph, VertexType startVertex)
	{
		ItemType item;
		int minDistance;
		priority_queue<ItemType> priorityQueue;// = (10);
		queue<VertexType> vertexQ;
		int count = 0;

		graph.ClearMarks();
		item.fromVertex = startVertex;
		item.toVertex = startVertex;
		item.distance = 0;
		priorityQueue.push(item);//.Enqueue
		cout << “Last Vertex Destination Distance” << endl;
		cout << “------------------------------------------ - ” << endl;

		do
		{
			item = priorityQueue.pop(); //.Dequeue(item);
			if(!graph.IsMarked(item.toVertex))
			{
				graph.MarkVertex(item.toVertex);
				cout << item.fromVertex;
				cout << " ";
				cout << item.toVertex;
				cout << " " << item.distance << endl;
				item.fromVertex = item.toVertex;
				minDistance = item.distance;
				graph.GetToVertices(item.fromVertex, vertexQ);

				while(!vertexQ.IsEmpty()) {
					VertexType vertex;
					vertexQ.Dequeue(vertex);
					if(!graph.IsMarked(vertex))
					{
						item.toVertex = vertex;
						item.distance = minDistance +
							graph.WeightIs(item.fromVertex, vertex);
						priorityQueue.push(item);// Enqueue(item);
					}
				}
			}
		} while(!priorityQueue.empty());// .IsEmpty());
	}
}