#include "Ant.h"

Ant::Ant() 
	: m_Position(nullptr)
{
}

Ant::Ant(PointOfGraph * position)
	: m_Position(position)
{
}

Ant::~Ant() {}

PointOfGraph* Ant::FindMaxConflictsPoint() 
{
	unsigned int maxConflicts = 0;
	PointOfGraph * maxConflictPoint = nullptr;
	std::vector<PointOfGraph *> neighbors = m_Position->GetNeighborsVector();

	for (PointOfGraph* point : neighbors)
	{
		if (maxConflicts <= point->GetConflictsCount())
		{
			maxConflicts = point->GetConflictsCount();
			maxConflictPoint = point;
		}
	}

	return maxConflictPoint;
}

PointOfGraph* Ant::FindRandomPoint() 
{
	std::vector<PointOfGraph *> neighbors = m_Position->GetNeighborsVector();
	return neighbors[rand() % neighbors.size()];
}
