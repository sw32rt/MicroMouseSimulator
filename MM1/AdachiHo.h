#pragma once
#include "GraphSearch.h"
#include <vector>
#include <deque>

// ê[Ç≥óDêÊíTçı
class AdachiHo : public GraphSearch
{
public:
	using GraphSearch::GraphSearch;
	~AdachiHo();
	void init(Coordinate StartVertexIndex, Coordinate GoalVertexIndex);
	Coordinate GetNextSearchStep(Coordinate CurrentVertex);
	bool SearchNext(void);
	std::deque<Coordinate> NextSearchVertexStack;
	
private:
	Coordinate GetNextSearchVertex(Coordinate CurrentVertex);
};


