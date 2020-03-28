#include <iostream>
#include <ctime>
#include "Graph.h"

const unsigned int ANTS_COUNT = 1;
const double PC = 0.5;

void LowLevel()
{
	std::cout << "\nLowLevel\n";
	Graph* graph;
	{
		std::cout << "\nyuzgcp130.13.col\n";
		graph = new Graph();
		graph->ReadInformation("yuzgcp130.13.col", ANTS_COUNT, PC);
		graph->ExecuteGraph();
		delete graph;
	}
	{
		std::cout << "\nyuzGCP660.33.col\n";
		graph = new Graph();
		graph->ReadInformation("yuzGCP660.33.col", ANTS_COUNT, PC);
		graph->ExecuteGraph();
		delete graph;
	}
	{
		std::cout << "\nyuzGCP990.33.col\n";
		graph = new Graph();
		graph->ReadInformation("yuzGCP990.33.col", ANTS_COUNT, PC);
		graph->ExecuteGraph();
		delete graph;
	}
}

void MiddleLevel()
{
	std::cout << "\nMiddleLevel\n";
	Graph* graph;
	{
		std::cout << "\nyuzGCPrnd83.10.col\n";
		graph = new Graph();
		graph->ReadInformation("yuzGCPrnd83.10.col", ANTS_COUNT, PC);
		graph->ExecuteGraph();
		delete graph;
	}
	{
		std::cout << "\nyuzGCPrnd127.14.col\n";
		graph = new Graph();
		graph->ReadInformation("yuzGCPrnd127.14.col", ANTS_COUNT, PC);
		graph->ExecuteGraph();
		delete graph;

	}
	{
		std::cout << "\nyuzGCPrnd157.10.col\n";
		graph = new Graph();
		graph->ReadInformation("yuzGCPrnd157.10.col", ANTS_COUNT, PC);
		graph->ExecuteGraph();
		delete graph;
	}

}

void HighLevel()
{
	std::cout << "\nDifficultLevel\n";
	Graph* graph;
	{
		std::cout << "\nyuzGCPrnd83.9.col\n";
		graph = new Graph();
		graph->ReadInformation("yuzGCPrnd83.9.col", ANTS_COUNT, PC);
		graph->ExecuteGraph();
		delete graph;
	}
	{
		std::cout << "\nyuzGCPrnd127.13.col\n";
		graph = new Graph();
		graph->ReadInformation("yuzGCPrnd127.13.col", ANTS_COUNT, PC);
		graph->ExecuteGraph();
		delete graph;
	}
	{
		std::cout << "\nyuzGCPrnd157.9.col\n";
		graph = new Graph();
		graph->ReadInformation("yuzGCPrnd157.9.col", ANTS_COUNT, PC);
		graph->ExecuteGraph();
		delete graph;
	}
}

int main() 
{
	srand((unsigned long)time(nullptr));

	LowLevel();
	MiddleLevel();
	HighLevel();
	
	return 0;
}