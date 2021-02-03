#include "pch.h"
#include "CScreen.h"

CScreen::CScreen(CWnd* hwnd)
	: m_hWnd(hwnd)
{
	InitMaze();
}

CScreen::~CScreen()
{
}

void CScreen::Update(void)
{
	/* ˆê’èŽžŠÔ‚²‚Æ‚ÉŒÄ‚Î‚ê‚é */
	CClientDC dc(m_hWnd);

	CPoint pointLertTop(100, 100);
	CSize rectSize(100, 100);
	CRect rect(pointLertTop, rectSize);

	dc.MoveTo(rect.TopLeft());
	dc.LineTo(rect.TopLeft() + CPoint(rect.Width(), 0));
	dc.LineTo(rect.BottomRight());
	dc.LineTo(rect.BottomRight() + CPoint(-rect.Width(), 0));
	dc.LineTo(rect.TopLeft());
}

void CScreen::InitMaze(void)
{

}
