#include "pch.h"
#include "CScreen.h"
#include "MM1Dlg.h"

CScreen::CScreen(CMM1Dlg* hwnd)
	: m_hWnd(hwnd)
	, m_maze(8)
{
	InitMaze();
}

CScreen::~CScreen()
{
}

void CScreen::Update(void)
{
	m_maze.Draw(m_hWnd, m_DisplayOffset, m_DisplayScale, m_DisplayRotate);
}

void CScreen::InitMaze(void)
{

}
