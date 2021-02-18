#pragma once
#include <queue>
using namespace std;

namespace DataStructures
{
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

		void MakeEmpty();
		void ClearMarks();

		bool IsEmpty() const;
		bool IsFull() const;
		bool IsMarked(VertexType) const;
		int WeightIs(VertexType, VertexType);

		void AddVertex(VertexType);
		void AddEdge(VertexType, VertexType, int);
		void MarkVertex(VertexType);

		void GetToVertices(VertexType, queue<VertexType>&);
	private:
		int numVertices;
		int maxVertices;
		VertexType* vertices;
		int edges[50][50];
		bool* marks;
	};
	template<class VertexType>GraphType<VertexType>::GraphType()
	{
		numVertices = 0;
		maxVertices = 50;
		vertices = new VertexType[50];
		marks = new bool[50];
	}
	template<class VertexType>GraphType<VertexType>::GraphType(int maxV)
	{
		numVertices = 0;
		maxVertices = maxV;
		vertices = new VertexType[maxV];
		marks = new bool[maxV];
	}
	template<class VertexType>GraphType<VertexType>::~GraphType()
	{
		delete[] vertices;
		delete[] marks;
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
		int row;
		int column;
		row = IndexIs(vertices, fromVertex);
		column = IndexIs(vertices, toVertex);
		edges[row][column] = weight;
	}
	template<class VertexType>int GraphType<VertexType>::WeightIs(VertexType fromVertex, VertexType toVertex)
	{
		int row;
		int column;
		row = IndexIs(vertices, fromVertex);
		column = IndexIs(vertices, toVertex);
		return edges[row][column];
	}
	template<class VertexType>int IndexIs(VertexType* vertices, VertexType vertex)
	{
		int index = 0;
		while(!(vertex == vertices[index]))
			index++;
		return index;
	}
	template<class VertexType>int IndexIs(VertexType* vertices, VertexType vertex)
	{
		int index = 0;
		while(!(vertex == vertices[index]))
			index++;
		return index;
	}
	template<class VertexType>void GraphType<VertexType>::GetToVertices(VertexType vertex, queue<VertexType>& adjvertexQ)
	{
		int fromIndex = IndexIs(vertices, vertex);
		for(int toIndex = 0; toIndex < numVertices; toIndex++)
			if(edges[fromIndex][toIndex] != NULL_EDGE)
				adjvertexQ.Enqueue(vertices[toIndex]);
	}
}