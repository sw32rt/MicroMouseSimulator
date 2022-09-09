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
	int CurrentVertexIndex = 0;
	int StartVertexIndex = 0;
	int GoalVertexIndex = 0;
	int ShortestPathDistance = 0;
	virtual void init(int StartVertexIndex, int GoalVertexIndex) = 0;
	virtual bool SearchNext(void) = 0;
	int GetShortestPathDistance(void) { return ShortestPathDistance;  };

private:
	virtual int GetNextSearchVertex(int CurrentVertex) = 0;

};


