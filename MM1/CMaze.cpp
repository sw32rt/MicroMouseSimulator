#include "pch.h"
#include "CMaze.h"

CMaze::CMaze(int mazeSize)
{
	m_mazeCells = mazeSize;
	m_mazeSize.width = (CELL_LENGTH * mazeSize) + WALL_WIDTH; /* 単位はmm 区画90mm, 壁厚さ6mm */
	m_mazeSize.height = (CELL_LENGTH * mazeSize) + WALL_WIDTH; /* 単位はmm 区画90mm, 壁厚さ6mm 正方形なのでxとy同じ */
	floatPoint center(200, 200);
	m_pField = new CField(m_mazeCells, m_mazeSize, center);

}

CMaze::~CMaze()
{
	delete m_pField;
}

void CMaze::Draw(CWnd* hwnd, floatPoint point, double scale)
{
	m_pField->m_MapOrigin = point;
	CClientDC dc(hwnd);

	/* テスト　迷路中心まで線を描く */
	dc.MoveTo(CPoint(0, 0));
	dc.LineTo(m_pField->m_MapOrigin);

	/* 横線描画 */
	floatPoint HPoint_from = floatPoint((m_pField->m_RelativeMap.lefttop.x + (WALL_WIDTH / 2.0)), m_pField->m_RelativeMap.lefttop.y + (WALL_WIDTH / 2.0)) * scale;
	floatPoint HPoint_to = floatPoint((m_pField->m_RelativeMap.rightbottom.x - (WALL_WIDTH / 2.0)), m_pField->m_RelativeMap.lefttop.y + (WALL_WIDTH / 2.0)) * scale;
	HPoint_from += m_pField->m_MapOrigin;
	HPoint_to += m_pField->m_MapOrigin;

	for (int i = 0; i < m_mazeCells + 1; i++)
	{
		dc.MoveTo(HPoint_from);
		dc.LineTo(HPoint_to);
		HPoint_from.y += ((CELL_LENGTH) * scale);
		HPoint_to.y = HPoint_from.y;
	}

	/* 縦線描画 */
	floatPoint VPoint_from = floatPoint((m_pField->m_RelativeMap.lefttop.x + (WALL_WIDTH / 2.0)), m_pField->m_RelativeMap.lefttop.y + (WALL_WIDTH / 2.0)) * scale;
	floatPoint VPoint_to = floatPoint((m_pField->m_RelativeMap.lefttop.x + (WALL_WIDTH / 2.0)), m_pField->m_RelativeMap.rightbottom.y - (WALL_WIDTH / 2.0)) * scale;
	VPoint_from += m_pField->m_MapOrigin;
	VPoint_to += m_pField->m_MapOrigin;

	for (int i = 0; i < m_mazeCells + 1; i++)
	{
		dc.MoveTo(VPoint_from);
		dc.LineTo(VPoint_to);
		VPoint_from.x += ((CELL_LENGTH) * scale);
		VPoint_to.x = VPoint_from.x;
	}

/* 壁描画 */
	DrawWall(hwnd, point, scale);
}

void CMaze::DrawWall(CWnd* hwnd, floatPoint point, double scale)
{
	CClientDC dc(hwnd);
	CPoint pointList[4] = {0};
	int pointCount = 4; /* 四角なので4固定 */

	for (auto hWall_x : m_pField->m_MazeWall.hWallList)
	{
		for (wall_t wall : hWall_x)
		{
			floatRect polyRect = wall.rect.scale(scale) + m_pField->m_MapOrigin;
			pointList[0] = polyRect.lefttop;
			pointList[1] = polyRect.righttop;
			pointList[2] = polyRect.rightbottom;
			pointList[3] = polyRect.leftbottom;
			dc.Polygon(pointList, pointCount);
		}
	}

	for (auto vWall_x : m_pField->m_MazeWall.vWallList)
	{
		for (wall_t wall : vWall_x)
		{
			floatRect polyRect = wall.rect.scale(scale) + m_pField->m_MapOrigin;
			pointList[0] = polyRect.lefttop;
			pointList[1] = polyRect.righttop;
			pointList[2] = polyRect.rightbottom;
			pointList[3] = polyRect.leftbottom;
			dc.Polygon(pointList, pointCount);
		}
	}

	for (auto pillar_x : m_pField->m_MazeWall.pillarList)
	{
		for (pillar_t pillar : pillar_x)
		{
			floatRect polyRect = pillar.rect.scale(scale) + m_pField->m_MapOrigin;
			pointList[0] = polyRect.lefttop;
			pointList[1] = polyRect.righttop;
			pointList[2] = polyRect.rightbottom;
			pointList[3] = polyRect.leftbottom;
			dc.Polygon(pointList, pointCount);
		}
	}

}
