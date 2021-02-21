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
		PathManager()
		{
			this->fromVertex = NULL;
			this->toVertex = NULL;
			this->distance = 0;
		}
		PathManager(VertexType fromVertex, VertexType toVertex)
		{
			this->fromVertex = fromVertex;
			this->toVertex = toVertex;
			this->distance = 0;
		}
		friend bool operator==(const PathManager<VertexType>& lhs, const PathManager<VertexType>& rhs)
		{
			return lhs.distance == rhs.distance;
		}
		friend bool operator<(const PathManager<VertexType>& lhs, const PathManager<VertexType>& rhs)
		{
			return lhs.distance > rhs.distance;//Note lhs > rhs, not lhs < rhs
		}
		friend ostream& operator<<(ostream& os, const PathManager<VertexType>& pathManager)
		{
			os << pathManager.fromVertex << "\t" << pathManager.toVertex << "\t" << pathManager.distance;
			return os;
		}
		VertexType fromVertex;
		VertexType toVertex;
		int distance;
	};

	/// <summary>
	/// Print the Shortest Paths. Inspired from C++ Plus Data Structures [2007] by Nell B.Dale -isbn-9780763741587
	/// </summary>
	/// <typeparam name="V">The vertex type</typeparam>
	/// <param name="graph">The graph to search.</param>
	/// <param name="startVertex">The vertex to start searching at.</param>
	template<class V>void CoutShortestPaths(GraphType<V>* graph, V startVertex)
	{
		graph->ClearMarks();

		priority_queue<PathManager<V>> priorityQueue;
		priorityQueue.push(PathManager<V>(startVertex, startVertex));

		do
		{
			PathManager<V> pathManager = priorityQueue.top();
			priorityQueue.pop();
			if(!graph->IsMarked(pathManager.toVertex))
			{
				graph->MarkVertex(pathManager.toVertex);
				cout << pathManager << endl;

				pathManager.fromVertex = pathManager.toVertex;
				int minDistance = pathManager.distance;

				queue<V> queue;
				graph->GetToVertices(pathManager.fromVertex, queue);
				while(!queue.empty())
				{
					V vertex = queue.front();
					queue.pop();
					if(!graph->IsMarked(vertex))
					{
						pathManager.toVertex = vertex;
						pathManager.distance = minDistance + graph->WeightIs(pathManager.fromVertex, vertex);
						priorityQueue.push(pathManager);
					}
				}
			}
		} while(!priorityQueue.empty());
	}
}