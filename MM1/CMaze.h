#pragma once
#include <vector>
#include "CField.h"
#include "AdachiHo.h"

typedef struct stLine
{
	floatPoint from;
	floatPoint to;
}stLine_t;

class CMaze
{
	CMaze() = delete;
public:
	CMaze(int mazeSize);
	~CMaze();

	void Draw(CWnd* hwnd, floatPoint point, double scale, double rotateDeg);
	int to_1d(int x, int y)
	{
		return y + (x * m_mazeCells);
	}

	int m_mazeCells = 0;
	floatSize m_mazeSize;
	std::vector<floatRect> m_wallList;
	CField *m_pField;
	std::vector<stLine_t> m_HorizontalLineList;
	std::vector<stLine_t> m_VerticalLineList;
	GraphSearch* m_Search = nullptr;

private:
	void DrawWall(CWnd* hwnd, floatPoint point, double scale, double rotateDeg);
};

