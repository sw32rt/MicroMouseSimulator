#pragma once
#include "GraphSearch.h"
#include <vector>
#include <deque>

// [‚³—Dæ’Tõ
class AdachiHo : public GraphSearch
{
public:
	using GraphSearch::GraphSearch;
	~AdachiHo();
	void init(int StartVertexIndex, int GoalVertexIndex);
	int GetNextSearchStep(int CurrentVertex);
	bool SearchNext(void);
	std::deque<int> NextSearchVertexStack;
	
private:
	int GetNextSearchVertex(int CurrentVertex);
};


