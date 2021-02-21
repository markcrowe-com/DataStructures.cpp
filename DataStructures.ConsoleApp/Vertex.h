/*
 * Copyright (c) 2020 Mark Crowe <https://github.com/markcrowe-com>. All rights reserved.
 */
#include <iostream>
#include <string>
using namespace std;
struct Vertex
{
public:
	Vertex() {}
	Vertex(string name)
	{
		this->name = name;
	}
	string Name()
	{
		return this->name;
	}
	void Name(string name)
	{
		this->name = name;
	}
	friend ostream& operator<<(ostream& os, const Vertex& airport)
	{
		os << airport.name;
		return os;
	}
	friend bool operator==(const Vertex& lhs, const Vertex& rhs)
	{
		return lhs.name == rhs.name;
	}
private:
	string name;
};