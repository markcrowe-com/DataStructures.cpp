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
	struct PathManager
	{
	public:
		PathManager(VertexType fromVertex, VertexType toVertex)
		{
			this->fromVertex = fromVertex;
			this->toVertex = toVertex;
			this->distance = 0;
		}
		// < means greater distance
		//bool operator<(PathManager otherItem);
		//bool operator==(PathManager otherItem);
		//bool operator<=(PathManager otherItem);
		//
		//	Fields
		//
		VertexType fromVertex;
		VertexType toVertex;
		int distance;
	};

	template<class VertexType>void ShortestPath(GraphType<VertexType> graph, VertexType startVertex)
	{
		int minDistance;
		priority_queue<PathManager> priorityQueue;// = (10);
		queue<VertexType> vertexQ;
		int count = 0;

		graph.ClearMarks();

		PathManager<VertexType> pathManager = new PathManager<VertexType>(startVertex, startVertex);

		priorityQueue.push(pathManager);//.Enqueue

		cout << “Last Vertex Destination Distance” << endl;
		cout << “------------------------------------------ - ” << endl;

		do
		{
			pathManager = priorityQueue.pop(); //.Dequeue(pathManager);
			if(!graph.IsMarked(pathManager.toVertex))
			{
				graph.MarkVertex(pathManager.toVertex);

				cout << pathManager.fromVertex;
				cout << " ";
				cout << pathManager.toVertex;
				cout << " " << pathManager.distance << endl;

				pathManager.fromVertex = pathManager.toVertex;
				minDistance = pathManager.distance;
				graph.GetToVertices(pathManager.fromVertex, vertexQ);

				while(!vertexQ.IsEmpty()) {
					VertexType vertex;
					vertexQ.Dequeue(vertex);
					if(!graph.IsMarked(vertex))
					{
						pathManager.toVertex = vertex;
						pathManager.distance = minDistance +
							graph.WeightIs(pathManager.fromVertex, vertex);
						priorityQueue.push(pathManager);// Enqueue(pathManager);
					}
				}
			}
		} while(!priorityQueue.empty());// .IsEmpty());
	}
}