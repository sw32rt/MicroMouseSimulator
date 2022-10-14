#pragma once
#include "Graph.h"
#include <vector>
#include <deque>

// •—Dæ’Tõ
class GraphSearch : public Graph
{
public:
	using Graph::Graph;
	virtual ~GraphSearch();
	Coordinate CurrentVertexIndex = { 0, 0 };
	Coordinate StartVertexIndex = { 0, 0 };
	Coordinate GoalVertexIndex = { 0, 0 };
	int ShortestPathDistance = 0;
	virtual void init(Coordinate StartVertexIndex, Coordinate GoalVertexIndex) = 0;
	virtual bool SearchNext(void) = 0;
	int GetShortestPathDistance(void) { return ShortestPathDistance;  };

private:
	virtual Coordinate GetNextSearchVertex(Coordinate CurrentVertex) = 0;

};


