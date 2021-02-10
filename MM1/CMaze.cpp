#include "pch.h"
#include "CMaze.h"

CMaze::CMaze(int mazeSize)
{
	m_mazeCells = mazeSize;
	m_mazeSize.width = (CELL_LENGTH * mazeSize) + WALL_WIDTH; /* 単位はmm 区画90mm, 壁厚さ6mm */
	m_mazeSize.height = (CELL_LENGTH * mazeSize) + WALL_WIDTH; /* 単位はmm 区画90mm, 壁厚さ6mm 正方形なのでxとy同じ */
	floatPoint center(200, 200);
	m_pField = new CField(m_mazeCells, m_mazeSize, center);

	//m_HorizontalLineList

	/* 横線描画 */
	stLine_t HLine;
	HLine.from = floatPoint((m_pField->m_RelativeMap.lefttop.x + (WALL_WIDTH / 2.0)), m_pField->m_RelativeMap.lefttop.y + (WALL_WIDTH / 2.0));
	HLine.to = floatPoint((m_pField->m_RelativeMap.rightbottom.x - (WALL_WIDTH / 2.0)), m_pField->m_RelativeMap.lefttop.y + (WALL_WIDTH / 2.0));

	for (int i = 0; i < m_mazeCells + 1; i++)
	{
		m_HorizontalLineList.push_back(HLine);
		HLine.from.y += CELL_LENGTH;
		HLine.to.y += CELL_LENGTH;
	}

	/* 縦線描画 */
	stLine_t VLine;
	VLine.from = floatPoint((m_pField->m_RelativeMap.lefttop.x + (WALL_WIDTH / 2.0)), m_pField->m_RelativeMap.lefttop.y + (WALL_WIDTH / 2.0));
	VLine.to = floatPoint((m_pField->m_RelativeMap.lefttop.x + (WALL_WIDTH / 2.0)), m_pField->m_RelativeMap.rightbottom.y - (WALL_WIDTH / 2.0));

	for (int i = 0; i < m_mazeCells + 1; i++)
	{
		m_VerticalLineList.push_back(VLine);
		VLine.from.x += CELL_LENGTH;
		VLine.to.x += CELL_LENGTH;
	}
}

CMaze::~CMaze()
{
	delete m_pField;
}

void CMaze::Draw(CWnd* hwnd, floatPoint point, double scale, double rotateDeg)
{
	m_pField->m_MapOrigin = point;
	CClientDC dc(hwnd);

	/* テスト　迷路中心まで線を描く */
	dc.MoveTo(CPoint(0, 0));
	dc.LineTo(m_pField->m_MapOrigin);

	/* 横線描画 */
	for (int i = 0; i < m_mazeCells + 1; i++)
	{
		dc.MoveTo((m_HorizontalLineList[i].from * scale).rotate(rotateDeg) + m_pField->m_MapOrigin);
		dc.LineTo((m_HorizontalLineList[i].to * scale).rotate(rotateDeg) + m_pField->m_MapOrigin);
	}

	/* 縦線描画 */
	for (int i = 0; i < m_mazeCells + 1; i++)
	{
		dc.MoveTo((m_VerticalLineList[i].from * scale).rotate(rotateDeg) + m_pField->m_MapOrigin);
		dc.LineTo((m_VerticalLineList[i].to * scale).rotate(rotateDeg) + m_pField->m_MapOrigin);
	}

/* 壁描画 */
	DrawWall(hwnd, point, scale, rotateDeg);
}

void CMaze::DrawWall(CWnd* hwnd, floatPoint point, double scale, double rotateDeg)
{
	CClientDC dc(hwnd);
	CPoint pointList[4] = {0};
	int pointCount = 4; /* 四角なので4固定 */

	for (auto hWall_x : m_pField->m_MazeWall.hWallList)
	{
		for (wall_t wall : hWall_x)
		{
			floatRect polyRect = wall.rect.scale(scale);
			polyRect = polyRect.rotate(rotateDeg);
			polyRect += m_pField->m_MapOrigin;
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
			floatRect polyRect = wall.rect.scale(scale);
			polyRect = polyRect.rotate(rotateDeg);
			polyRect += m_pField->m_MapOrigin;
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
			floatRect polyRect = pillar.rect.scale(scale);
			polyRect = polyRect.rotate(rotateDeg);
			polyRect += m_pField->m_MapOrigin;
			pointList[0] = polyRect.lefttop;
			pointList[1] = polyRect.righttop;
			pointList[2] = polyRect.rightbottom;
			pointList[3] = polyRect.leftbottom;
			dc.Polygon(pointList, pointCount);
		}
	}

}
