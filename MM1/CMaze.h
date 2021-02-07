#pragma once
#include <vector>
#include "CField.h"

class CMaze
{
	CMaze() = delete;
public:
	CMaze(int mazeSize);
	~CMaze();

	void Draw(CWnd* hwnd, floatPoint point, double scale);

	int m_mazeCells = 0;
	floatSize m_mazeSize;
	std::vector<floatRect> m_wallList;
	CField *m_pField;

};

