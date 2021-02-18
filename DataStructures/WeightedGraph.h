#pragma once
#include <queue>
namespace DataStructures
{
	using namespace std;
	/// <summary>
	/// Weighted Graph
	/// </summary>
	/// <typeparam name="T"></typeparam>
	template<class T> __interface WeightedGraph
	{
		void Clear();
		void ClearMarks();
	};
}