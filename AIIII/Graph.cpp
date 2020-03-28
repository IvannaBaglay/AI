#include "Graph.h"

void Graph::ReadInformation(const char * filename, uint32_t antsCount, double PC)
{
	try 
	{
		if (antsCount <= 0)
		{
			throw "Error in ReadInformation constructor. Illegal ants count.";
		}

		std::string tmpString = filename;

		int lastPoint = tmpString.rfind('.');
		int preLastPoint = tmpString.rfind('.', lastPoint - 1);

		if (lastPoint == std::string::npos || preLastPoint == std::string::npos)
		{
			throw "Error in ReadInformation constructor. Wrong filename.\n";
		}

		tmpString.assign(tmpString.begin() + lastPoint + 1, tmpString.end());
		if (tmpString != "col")
		{
			throw "Error in ReadInformation constructor. Wrong file resolution.\n";
		}

		tmpString = filename;
		tmpString.assign(tmpString.begin() + preLastPoint + 1, tmpString.begin() + lastPoint);
		unsigned int chromatic_number = stoi(tmpString);

		std::ifstream fin(filename);

		if (!fin.is_open())
		{
			throw "Error in ReadInformation constructor. File can't be open.\n";
		}

		unsigned int pointsCount, EdgesCount;
		unsigned int tmpNum1, tmpNum2;

		while (!fin.eof()) 
		{
			fin >> tmpString;

			if (tmpString[0] == 'c')
			{
				getline(fin, tmpString);
			}

			else if (tmpString[0] == 'p') 
			{
				fin >> tmpString >> tmpString;
				tmpNum1 = stoi(tmpString);
				fin >> tmpString;
				tmpNum2 = stoi(tmpString);

				pointsCount = tmpNum1;
				EdgesCount = tmpNum2;

				for (unsigned int i = 0; i < antsCount; i++)
				{
					m_RootsVector.push_back(Root(PC, pointsCount, EdgesCount, chromatic_number));
				}
			}

			else 
			{
				fin >> tmpString;
				tmpNum1 = stoi(tmpString);
				fin >> tmpString;
				tmpNum2 = stoi(tmpString);

				if (tmpNum1 == tmpNum2)
				{
					break;
				}

				for (Root& root : m_RootsVector)
				{
					root.CreateRib(tmpNum1, tmpNum2);
				}
			}
		}

		fin.clear();
		fin.close();
	}
	catch (const char * str) 
	{
		std::cerr << str;
		exit(-1);
	}
}

Graph::~Graph() {  }

void Graph::ExecuteGraph()
{
	for (Root& root : m_RootsVector)
	{
		if (root.ExecuteRoot()) 
		{
			break;
		}
	}
}