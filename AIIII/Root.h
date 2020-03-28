#pragma once
#include"Ant.h"
#include <iostream>

class Root {
public:
	explicit Root(double PC, uint32_t points_count, uint32_t ribs_count, uint32_t chromatic_number);
	explicit Root(const Root& root);
	~Root();

	void CreateRib(uint32_t id_point1, uint32_t id_point2);
	bool ExecuteRoot();

	double GetPN() const { return m_PN; }
	double GetPC() const { return m_PC; }
	uint32_t GetPointsCount() const { return m_PointsCount; }
	uint32_t GetRibsCount() const { return m_EdgesCount; }
	uint32_t GetChromaticNumber() const { return m_ChromaticNumber; }
	const std::vector<PointOfGraph>& GetPointsVector() const { return m_PointsVector; }
	Ant GetAnt() const { return m_Ant; }

private:
	double ThrowDice();
	void UpdateConflictsCountInRoot();
	uint32_t CalcAllConflictsInRoot();
	uint32_t CalcMaxConflictsCountInRoot();
	void RecolorPoint(PointOfGraph* point);

	double m_PN;
	const double m_PC;
	const uint32_t m_PointsCount;
	const uint32_t m_EdgesCount;
	const uint32_t m_ChromaticNumber;
	std::vector<PointOfGraph> m_PointsVector;
	Ant m_Ant;
};

