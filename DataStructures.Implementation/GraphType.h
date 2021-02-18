#pragma once
/*
 * Copyright (c) 2021 Mark Crowe <https://github.com/markcrowe-com>. All rights reserved.
 */
#include <queue>
using namespace std;
namespace DataStructures
{
	int NULL_EDGE = 0;
	using namespace std;
	/// <summary>
	/// </summary>
	/// <typeparam name="T">Assumption: VertexType is a type for which the // "=", "==", and "<<" operators are defined</typeparam>
	template<class VertexType>class GraphType
	{
	public:
		GraphType();// constructor, default of 50 vertices.
		GraphType(int maxV);// parameterized constructor, maxV <= 50.
		~GraphType();
		#pragma region Methods : get status
		#pragma endregion
		bool IsEmpty() const;
		bool IsFull() const;
		bool IsMarked(VertexType) const;
		#pragma region Methods : get
		#pragma endregion
		int WeightIs(VertexType, VertexType) const;
		#pragma region Methods
		#pragma endregion
		void AddEdge(VertexType, VertexType, int);
		void AddVertex(VertexType);
		void Clear();
		void ClearMarks();
		void GetToVertices(VertexType, queue<VertexType>&);
		void MarkVertex(VertexType);
	private:
		int IndexOf(VertexType vertex);
	private:
		int edges[50][50];
		bool* marks;
		int maxVertices;
		int numVertices;
		VertexType* vertices;
	};
	template<class VertexType>GraphType<VertexType>::GraphType()
	{
		this->marks = new bool[50];
		this->maxVertices = 50;
		this->numVertices = 0;
		this->vertices = new VertexType[50];
	}
	template<class VertexType>GraphType<VertexType>::GraphType(int maxV)
	{
		this->marks = new bool[maxV];
		this->maxVertices = maxV;
		this->numVertices = 0;
		this->vertices = new VertexType[maxV];
	}
	template<class VertexType>GraphType<VertexType>::~GraphType()
	{
		delete[] marks;
		delete[] vertices;
	}
	template<class VertexType>void GraphType<VertexType>::AddVertex(VertexType vertex)
	{
		vertices[numVertices] = vertex;
		for(int index = 0; index < numVertices; index++)
		{
			edges[numVertices][index] = NULL_EDGE;
			edges[index][numVertices] = NULL_EDGE;
		}
		numVertices++;
	}
	template<class VertexType>void GraphType<VertexType>::AddEdge(VertexType fromVertex, VertexType toVertex, int weight)
	{
		int row = IndexOf(fromVertex);
		int column = IndexOf(toVertex);
		edges[row][column] = weight;
	}
	template<class VertexType>int GraphType<VertexType>::WeightIs(VertexType sourceVertex, VertexType targetVertex) const
	{
		int row = IndexOf(sourceVertex);
		int column = IndexOf(targetVertex);
		return edges[row][column];
	}
	template<class VertexType>int IndexOf(VertexType vertex)
	{
		for(int index = 0; index < this.numVertices; index++)
		{
			if(vertex == vertices[index])
				return index;
		}
		return -1;
	}
	template<class VertexType>void GraphType<VertexType>::GetToVertices(VertexType vertex, queue<VertexType>& adjvertexQ)
	{
		int fromIndex = IndexOf(vertex);
		for(int toIndex = 0; toIndex < numVertices; toIndex++)
		{
			if(edges[fromIndex][toIndex] != NULL_EDGE)
				adjvertexQ.Enqueue(vertices[toIndex]);
		}
	}
}