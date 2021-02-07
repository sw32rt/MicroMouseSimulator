#include "pch.h"
#include "CMaze.h"

CMaze::CMaze(int mazeSize)
{
	m_mazeCells = mazeSize;
	m_mazeSize.width = (90.0 * mazeSize) + 6.0; /* ’PˆÊ‚Ímm ‹æ‰æ90mm, •ÇŒú‚³6mm */
	m_mazeSize.height = (90.0 * mazeSize) + 6.0; /* ’PˆÊ‚Ímm ‹æ‰æ90mm, •ÇŒú‚³6mm ³•ûŒ`‚È‚Ì‚Åx‚Æy“¯‚¶ */
	floatPoint center(200,200);
	m_pField = new CField(m_mazeSize, center);

}

CMaze::~CMaze()
{
}

void CMaze::Draw(CWnd* hwnd, floatPoint point, double scale)
{
	m_pField->m_MapOrigin = point;
	CClientDC dc(hwnd);
	
	/* ƒeƒXƒg@–À˜H’†S‚Ü‚Åü‚ð•`‚­ */
	dc.MoveTo(CPoint(0, 0));
	dc.LineTo(m_pField->m_MapOrigin);

	floatRect scaledRect = m_pField->m_RelativeMap.scale(scale);

	/* ‰¡ü•`‰æ */
	floatPoint HPoint_from;
	floatPoint HPoint_to;
	HPoint_from.x = m_pField->m_RelativeMap.lefttop.x * scale;
	HPoint_to.x = m_pField->m_RelativeMap.rightbottom.x * scale;
	HPoint_to.y = HPoint_from.y = (m_pField->m_RelativeMap.lefttop.y + 3) * scale;
	HPoint_to += m_pField->m_MapOrigin;
	HPoint_from += m_pField->m_MapOrigin;

	for (int i = 0; i < m_mazeCells + 1; i++)
	{
		HPoint_from.y = ((m_pField->m_RelativeMap.lefttop.y + (i * 90.0)) * scale) + m_pField->m_MapOrigin.y;
		HPoint_to.y = HPoint_from.y;
		dc.MoveTo(HPoint_from);
		dc.LineTo(HPoint_to);
	}

	/* cü•`‰æ */
	floatPoint VPoint_from;
	floatPoint VPoint_to;
	VPoint_from.y = m_pField->m_RelativeMap.lefttop.y * scale;
	VPoint_to.y = m_pField->m_RelativeMap.rightbottom.y * scale;
	VPoint_to.x = VPoint_from.x = (m_pField->m_RelativeMap.lefttop.x + 3) * scale;
	VPoint_to += m_pField->m_MapOrigin;
	VPoint_from += m_pField->m_MapOrigin;

	for (int i = 0; i < m_mazeCells + 1; i++)
	{
		VPoint_from.x = ((m_pField->m_RelativeMap.lefttop.x + (i * 90.0)) * scale) + m_pField->m_MapOrigin.x;
		VPoint_to.x = VPoint_from.x;
		dc.MoveTo(VPoint_from);
		dc.LineTo(VPoint_to);
	}
}
