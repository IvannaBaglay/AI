#include "Root.h"

double Root::ThrowDice() 
{
	return rand() % 100 / 100. + 0.01;
}

void Root::UpdateConflictsCountInRoot() 
{
	for (PointOfGraph& point : m_PointsVector)
	{
		point.UpdateConflictsCount();
	}
}

unsigned int Root::CalcAllConflictsInRoot() 
{
	unsigned int sumConflicts = 0;

	for (PointOfGraph& point : m_PointsVector)
	{
		sumConflicts += point.GetConflictsCount();
	}

	return sumConflicts;
}

unsigned int Root::CalcMaxConflictsCountInRoot()
{
	unsigned int conflictsCount = 0;

	for (PointOfGraph& point : m_PointsVector)
	{
		if (conflictsCount < point.GetConflictsCount())
		{
			conflictsCount = point.GetConflictsCount();
		}
	}

	return conflictsCount;
}

void Root::RecolorPoint(PointOfGraph * point) 
{
	unsigned int defaultColor = point->GetColor();
	unsigned int bestColor = 0;
	unsigned int minConflicts = UINT16_MAX;

	for (unsigned int i = 0; i < m_ChromaticNumber; i++) 
	{
		if (i == defaultColor)
		{
			continue;
		}
		point->SetColor(i);
		point->UpdateConflictsCount();

		if (point->GetConflictsCount() < minConflicts) 
		{
			bestColor = i;
			minConflicts = point->GetConflictsCount();
		}
	}
	point->SetColor(bestColor);
}

Root::Root(double PC, uint32_t points_count, uint32_t ribs_count, uint32_t chromatic_number) 
	: m_PC(PC)
	, m_PN(0.9)
	, m_PointsCount(points_count)
	, m_RibsCount(ribs_count)
	, m_ChromaticNumber(chromatic_number) 
{
	uint32_t color;

	for (unsigned int i = 0; i < points_count; i++)
	{
		color = rand() % chromatic_number;
		m_PointsVector.push_back(PointOfGraph(i + 1, color));
	}

	m_Ant = Ant(&m_PointsVector[0]);
}

Root::Root(const Root& root)
	: m_PC(root.GetPC())
	, m_PointsCount(root.GetPointsCount())
	, m_RibsCount(root.GetRibsCount())
	, m_ChromaticNumber(root.GetChromaticNumber()) 
{
	m_PointsVector = std::vector<PointOfGraph>(root.GetPointsVector());
	m_Ant = Ant(&m_PointsVector[0]);
}

Root::~Root() {  }

void Root::CreateRib(uint32_t id_point1, uint32_t id_point2) 
{
	m_PointsVector[id_point1 - 1].AddNeighbor(&m_PointsVector[id_point2 - 1]);
	m_PointsVector[id_point2 - 1].AddNeighbor(&m_PointsVector[id_point1 - 1]);
}

bool Root::ExecuteRoot()
{
	unsigned long iter = 0;
	double dice;

	while (true)
	{
		UpdateConflictsCountInRoot();

		const double confsoverall = CalcAllConflictsInRoot() / 2.;

		if (confsoverall == 0) 
		{
			for (PointOfGraph point : m_PointsVector)
			{
				std::cout << point.GetColor() << ",";
			}
			return true;
		}

		const double maxconf = CalcMaxConflictsCountInRoot();
		const double avgy = 4.8 * confsoverall / (m_PointsCount * m_PointsCount);
		const double avgx = 1.0 * maxconf;

		//m_PN = exp(-3.2 * ((5 * iter + 1) * avgy / (avgx)));
		m_PN = 0.9;
		//std::cout << "PN = " << m_PN << "\t" << "conflicts count = " << confsoverall << "\n";
		if (m_PN < 0.01)
		{
			break;
		}
		dice = ThrowDice();
		if (m_PN >= dice) 
		{
			PointOfGraph * maxConflictPoint = m_Ant.FindMaxConflictsPoint();
			m_Ant.SetPosition(maxConflictPoint);
			RecolorPoint(maxConflictPoint);
		}
		else 
		{
			PointOfGraph * newPoint = m_Ant.FindRandomPoint();
			m_Ant.SetPosition(newPoint);
			dice = ThrowDice();
			if (m_PC >= dice)
			{
				RecolorPoint(newPoint);
			}
		}
		iter++;
	}
	return false;
}