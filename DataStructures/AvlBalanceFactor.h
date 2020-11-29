/*
 * Copyright (c) 2020 Mark Crowe <https://github.com/markcrowe-com>. All rights reserved.
 */
#pragma once
#include <string>
namespace DataStructures
{
	using namespace std;
	class AvlBalanceFactor
	{
	public:
		#pragma region Fields
		#pragma endregion
		static const int Balanced = 0;
		static const int LeftUnbalanced = 1;
		static const int RightUnbalanced = -1;
		#pragma region Methods
		#pragma endregion
		static string ToString(const int& height)
		{
			if(height > Balanced)
				return "Left Unbalanced";
			else if(height < Balanced)
				return "Right Unbalanced";
			else //if (height == Balanced)
				return "Balanced";
		}
	};
}