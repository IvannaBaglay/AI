#include "Graph.h"

void Graph::ReadInformation(const char * filename, uint32_t ants_count, double PC)
{
	try 
	{
		if (ants_count <= 0)
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

		unsigned int points_count, ribs_count;
		unsigned int tmp_num1, tmp_num2;

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
				tmp_num1 = stoi(tmpString);
				fin >> tmpString;
				tmp_num2 = stoi(tmpString);

				points_count = tmp_num1;
				ribs_count = tmp_num2;

				for (unsigned int i = 0; i < ants_count; i++)
				{
					m_RootsVector.push_back(Root(PC, points_count, ribs_count, chromatic_number));
				}
			}

			else 
			{
				fin >> tmpString;
				tmp_num1 = stoi(tmpString);
				fin >> tmpString;
				tmp_num2 = stoi(tmpString);

				if (tmp_num1 == tmp_num2)
				{
					break;
				}

				for (Root& root : m_RootsVector)
				{
					root.CreateRib(tmp_num1, tmp_num2);
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