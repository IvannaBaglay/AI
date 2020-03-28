#pragma once
#include "PointOfGraph.h"

class Ant {
public:
	explicit Ant();
	explicit Ant(PointOfGraph* position);
	~Ant();

	PointOfGraph* FindMaxConflictsPoint();
	PointOfGraph* FindRandomPoint();

	PointOfGraph* GetPosition() const { return m_Position; }

	void SetPosition(PointOfGraph* point) { m_Position = point; }
private:
	PointOfGraph* m_Position;
};