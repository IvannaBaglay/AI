#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Root.h"

class Graph 
{
public:
	explicit Graph() = default;
	~Graph();
	void ExecuteGraph();
	void ReadInformation(const char* filename, uint32_t ants_count, double PC);
	const std::vector<Root>& GetRootsVector() const { return m_RootsVector; }
private:
	std::vector<Root> m_RootsVector;
};