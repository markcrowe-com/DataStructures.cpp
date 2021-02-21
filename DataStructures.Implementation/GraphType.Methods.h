#pragma once
/*
 * Copyright (c) 2021 Mark Crowe <https://github.com/markcrowe-com>. All rights reserved.
 */
#include <queue>
#include "GraphType.h"
#include "../DataStructures.Implementation/AvlTreeNodeMethods.h"
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

		void PrintLine()
		{
			cout << TtoString(fromVertex);
			cout << " ";
			cout << TtoString(toVertex);
			cout << " " << distance << endl;
		}
		// < means greater distance
		//bool operator<(PathManager otherItem);

		friend bool operator==(const PathManager<VertexType>& lhs, const PathManager<VertexType>& rhs)
		{
			return lhs.fromVertex == rhs.fromVertex &&
				lhs.toVertex == rhs.toVertex &&
				lhs.distance == rhs.distance;
		}
		friend bool operator<(const PathManager<VertexType>& lhs, const PathManager<VertexType>& rhs)
		{
			return
				lhs.distance < rhs.distance;
		}
		friend bool operator<=(const PathManager<VertexType>& lhs, const PathManager<VertexType>& rhs)
		{
			return
				lhs.distance <= rhs.distance;
		}
		//bool operator<=(PathManager otherItem);

		friend ostream& operator<<(ostream& os, const PathManager<VertexType>& pathManager)
		{
			os << pathManager.fromVertex << " " << pathManager.toVertex << " " << distance << endl;
			return os;
		}

		//
		//	Fields
		//
		VertexType fromVertex;
		VertexType toVertex;
		int distance;
	};

	template<class VertexType>void ShortestPath(GraphType<VertexType> graph, VertexType startVertex)
	{
		graph.ClearMarks();

		PathManager<VertexType> pathManager(startVertex, startVertex);

		priority_queue<PathManager<VertexType>> priorityQueue;// (10);// = (10);

		priorityQueue.push(pathManager);//.Enqueue

		cout << "Last Vertex Destination Distance" << endl;
		cout << "-------------------------------------------" << endl;

		int minDistance;

		do
		{
			pathManager = priorityQueue.top();
			priorityQueue.pop(); //.Dequeue(pathManager);
			if(!graph.IsMarked(pathManager.toVertex))
			{
				graph.MarkVertex(pathManager.toVertex);

				pathManager.PrintLine();

				pathManager.fromVertex = pathManager.toVertex;
				minDistance = pathManager.distance;

				queue<VertexType> queue;
				graph.GetToVertices(pathManager.fromVertex, queue);

				while(!queue.empty()) {
					VertexType vertex = queue.front();
					queue.pop();
					if(!graph.IsMarked(vertex))
					{
						pathManager.toVertex = vertex;
						pathManager.distance = minDistance + graph.WeightIs(pathManager.fromVertex, vertex);
						priorityQueue.push(pathManager);// Enqueue(pathManager);
					}
				}
			}
		} while(!priorityQueue.empty());// .IsEmpty());
	}
}