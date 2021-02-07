#include "pch.h"
#include "CScreen.h"
#include "MM1Dlg.h"

CScreen::CScreen(CMM1Dlg* hwnd)
	: m_hWnd(hwnd)
	, m_maze(9)
{
	InitMaze();
}

CScreen::~CScreen()
{
}

void CScreen::Update(void)
{
	m_maze.Draw(m_hWnd, m_DisplayOffset, m_DisplayScale);
}

void CScreen::InitMaze(void)
{

}
