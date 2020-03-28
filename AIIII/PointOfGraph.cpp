#include "PointOfGraph.h"

void PointOfGraph::UpdateConflictsCount()
{
	m_ConflictsCount = 0;
	for (PointOfGraph* point : m_NeighborsVector)
	{
		if (m_Color == point->GetColor())
		{
			m_ConflictsCount++;
		}
	}
}

PointOfGraph::PointOfGraph(uint32_t ID, uint32_t color) : m_ID(ID)
{
	this->m_Color = color;
	this->m_ConflictsCount = INT16_MAX;
	m_NeighborsVector = std::vector<PointOfGraph *>();
}

PointOfGraph::~PointOfGraph() {  }
