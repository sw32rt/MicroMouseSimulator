#pragma once
#include "CField.h"
#include "CMaze.h"
#include <vector>

#define MAZE_SIZE 32

class CMM1Dlg;

class CScreen
{
public:
	CScreen(CMM1Dlg* hwnd);
	~CScreen();

	void Update(void);
	void InitMaze(void);

	floatPoint m_DisplayOffset = floatPoint(450, 470);
	double m_DisplayScale = 0.3;
	double m_DisplayRotate = 0.0;
	CMaze m_maze;
	std::vector<stLine_t> m_MeasureLines;

private:
	CMM1Dlg* m_hWnd;


};

