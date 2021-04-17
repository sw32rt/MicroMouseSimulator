#pragma once
#include "GraphSearch.h"
#include <vector>
#include <deque>

// [‚³—Dæ’Tõ
class AdachiHo : public GraphSearch
{
public:
	using GraphSearch::GraphSearch;
	void init(int StartVertexIndex, int GoalVertexIndex);
	bool SearchNext(void);
	std::deque<int> NextSearchVertexStack;
	
private:
	int GetNextSearchVertex(int CurrentVertex);
	int to_1d(int x, int y)
	{
		return y + (x * m_MapSize);
	};

};


