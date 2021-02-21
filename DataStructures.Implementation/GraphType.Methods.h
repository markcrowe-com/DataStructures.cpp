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
		PathManager() {
			//this->fromVertex = NULL;
			//this->toVertex = NULL;
			this->distance = 0;
		}
		PathManager(VertexType fromVertex, VertexType toVertex)
		{
			this->fromVertex = fromVertex;
			this->toVertex = toVertex;
			this->distance = 0;
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
			os << pathManager.fromVertex << " " << pathManager.toVertex << " " << pathManager.distance;
			return os;
		}

		//
		//	Fields
		//
		VertexType fromVertex;
		VertexType toVertex;
		int distance;
	};

	template<class VertexType>void ShortestPath(GraphType<VertexType>* graph, VertexType startVertex)
	{
		graph->ClearMarks();

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
			if(!graph->IsMarked(pathManager.toVertex))
			{
				graph->MarkVertex(pathManager.toVertex);

				cout << pathManager << endl;

				pathManager.fromVertex = pathManager.toVertex;
				minDistance = pathManager.distance;

				queue<VertexType> queue;
				graph->GetToVertices(pathManager.fromVertex, queue);

				while(!queue.empty()) {
					VertexType vertex = queue.front();
					queue.pop();
					if(!graph->IsMarked(vertex))
					{
						pathManager.toVertex = vertex;
						pathManager.distance = minDistance + graph->WeightIs(pathManager.fromVertex, vertex);
						priorityQueue.push(pathManager);// Enqueue(pathManager);
					}
				}
			}
		} while(!priorityQueue.empty());// .IsEmpty());
	}

	template<class VertexType>void ShortestPathLecturerVersion(GraphType<VertexType> graph, VertexType startVertex)
	{
		PathManager<VertexType> item;
		int minDistance;

		priority_queue<PathManager<VertexType>> pq;// (10); 	// Assume at most 10 vertices

		VertexType vertex;
		int count = 0;

		graph.ClearMarks();
		item.fromVertex = startVertex;
		item.toVertex = startVertex;
		item.distance = 0;
		pq.push(item);
		cout << "Last Vertex Destination Distance" << endl;
		cout << "------------------------------------------ - " << endl;

		do
		{
			item = pq.top();
			pq.pop();
			if(!graph.IsMarked(item.toVertex))
			{
				graph.MarkVertex(item.toVertex);
				cout << item.fromVertex << " " << item.toVertex << " " << item.distance << endl;
				item.fromVertex = item.toVertex;
				minDistance = item.distance;
				queue<VertexType> vertexQ;
				graph.GetToVertices(item.fromVertex, vertexQ);

				while(!vertexQ.empty()) {
					vertex = vertexQ.front();
					vertexQ.pop();
					if(!graph.IsMarked(vertex))
					{
						item.toVertex = vertex;
						item.distance = minDistance + graph.WeightIs(item.fromVertex, vertex);
						pq.push(item);
					}
				}
			}
		} while(!pq.empty());
	}
}