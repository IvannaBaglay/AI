#pragma once
#include <vector>

class PointOfGraph {
public:
	explicit PointOfGraph(uint32_t ID, uint32_t color);
	~PointOfGraph();

	void AddNeighbor(PointOfGraph* point) { m_NeighborsVector.push_back(point); }
	void UpdateConflictsCount();

	uint32_t GetID() const { return m_ID; }
	uint32_t GetColor() const { return m_Color; }
	uint32_t GetConflictsCount() const { return m_ConflictsCount; }
	const std::vector<PointOfGraph*>& GetNeighborsVector() const { return m_NeighborsVector; }

	void SetColor(uint32_t color) { this->m_Color = color; }
private:
	const uint32_t m_ID;
	uint32_t m_Color;
	uint32_t m_ConflictsCount;

	std::vector<PointOfGraph*> m_NeighborsVector;
};

