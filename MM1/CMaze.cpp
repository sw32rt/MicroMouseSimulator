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

	m_Search = new AdachiHo();
	int Start = to_1d(0, 31);
	int Goal = to_1d(26, 3);
	m_Search->init(Start, Goal);
}

CMaze::~CMaze()
{
	delete m_pField;
}

void CMaze::Draw(CDC* pDC, floatPoint point, double scale, double rotateDeg)
{
	m_pField->m_MapOrigin = point;
	//CClientDC dc(hwnd);

	/* 迷路中心まで線を描く */
	pDC->MoveTo(CPoint(0, 0));
	pDC->LineTo(m_pField->m_MapOrigin);
#if 0
	/* 横線描画 */
	for (int i = 0; i < m_mazeCells + 1; i++)
	{
		pDC->MoveTo((m_HorizontalLineList[i].from * scale).rotate(rotateDeg) + m_pField->m_MapOrigin);
		pDC->LineTo((m_HorizontalLineList[i].to * scale).rotate(rotateDeg) + m_pField->m_MapOrigin);
	}

	/* 縦線描画 */
	for (int i = 0; i < m_mazeCells + 1; i++)
	{
		pDC->MoveTo((m_VerticalLineList[i].from * scale).rotate(rotateDeg) + m_pField->m_MapOrigin);
		pDC->LineTo((m_VerticalLineList[i].to * scale).rotate(rotateDeg) + m_pField->m_MapOrigin);
	}
#endif

	// ペンを作成します。
	// ペンのスタイル : 実線
	// ペンの太さ    : 1
	// ペンの色     : 黒
	CPen pen;

	// 新しいペン(pen)を設定し、設定されていた元のペンをpOldPenに保存します。
	CPen* pOldPen;
	// 辺を描画
	for (auto v : m_Search->vlist)
	{
		do { // ノードの右側の線を描画
			int color = 0;

			// switchにするとbreakでdo{}を脱出できなくなるのでifにした
			if (v.Wall_East == WallStatus::E_KS_Exists)
			{ // 存在する
				color = RGB(255, 100, 0);
			}
			else if (v.Wall_East == WallStatus::E_KS_NotExist)
			{ // 存在しない
				color = RGB(240, 240, 240);
			}
			else if (v.Wall_East == WallStatus::E_KS_Unknown)
			{ // 不明(未探索)
				color = RGB(0, 0, 0);
			}
			else if (v.Wall_East == WallStatus::E_KS_OutSide)
			{ // 迷路外
				//color = RGB(255, 0, 0);
				break;
			}
			CPen pen(PS_SOLID, 1, color);
			CPen* pOldPen = pDC->SelectObject(&pen);
			floatPoint from = v;
			floatPoint to = *(v.GetVertex_East());
			from = (from * scale).rotate(rotateDeg) + m_pField->m_MapOrigin;
			to = (to * scale).rotate(rotateDeg) + m_pField->m_MapOrigin;

			pDC->MoveTo(from);
			pDC->LineTo(to);

			// ペンをもとに戻す
			pDC->SelectObject(pOldPen);
		} while (0);

		do { // ノードの下側の線を描画
			int color = 0;

			// switchにするとbreakでdo{}を脱出できなくなるのでifにした
			if (v.Wall_South == WallStatus::E_KS_Exists)
			{ // 存在する
				color = RGB(255, 100, 0);
			}
			else if (v.Wall_South == WallStatus::E_KS_NotExist)
			{ // 存在しない
				//break; // 線を書かない
				color = RGB(240, 240, 240);
			}
			else if (v.Wall_South == WallStatus::E_KS_Unknown)
			{ // 不明(未探索)
				color = RGB(0, 0, 0);
			}
			else if (v.Wall_South == WallStatus::E_KS_OutSide)
			{ // 迷路外
				//color = RGB(255, 0, 0);
				break;
			}
			CPen pen(PS_SOLID, 1, color);
			CPen* pOldPen = pDC->SelectObject(&pen);

			floatPoint from = v;
			floatPoint to = *(v.GetVertex_South());
			from = (from * scale).rotate(rotateDeg) + m_pField->m_MapOrigin;
			to = (to * scale).rotate(rotateDeg) + m_pField->m_MapOrigin;

			pDC->MoveTo(from);
			pDC->LineTo(to);

			// ペンをもとに戻す
			pDC->SelectObject(pOldPen);
		} while (0);
	}

	int index = 0;
	// 頂点を描画
	for (auto v : m_Search->vlist)
	{
		int color = 0;

		switch (v.SStatus)
		{
		case E_Status_UnExplored:
			// 未探索
			color = RGB(255, 255, 255);
			break;
		case E_Status_Looked:
			// 認知
			color = RGB(0, 255, 255);
			break;
		case E_Status_Exploring:
			// 探索中
			color = RGB(200, 200, 0);
			break;
		case E_Status_Searched:
			// 探索済み
			color = RGB(100, 100, 100);
			break;
		case E_Status_ShortestPath:
			// 最短経路
			color = RGB(0, 255, 0);
			break;
		default:
			break;
		}

		switch (v.SupposeSearchStatus)
		{
		case E_Status_ShortestPath:
			// 最短経路
			color = RGB(0, 255, 0);
			break;
		case E_Status_UnExplored:
		case E_Status_Looked:
		case E_Status_Exploring:
		case E_Status_Searched:
		default:
			break;
		}


		if (m_Search->GoalVertexIndex == index)
		{ // ゴール
			color = RGB(200, 100, 0);
		}

		// 塗りつぶし色
		CBrush brush(color);
		// 新しいブラシ(brush)を設定し、設定されていた元のブラシをpOldBrushに保存します。
		CBrush* pOldBrush = pDC->SelectObject(&brush);

		floatPoint fpoint = v;
		fpoint = (fpoint * scale).rotate(rotateDeg) + m_pField->m_MapOrigin;

		CSize size(10, 10);
		CPoint point(fpoint.x - (size.cx / 2), fpoint.y - (size.cy / 2));
		CRect rect(point, size);
		pDC->Ellipse(rect);

		pDC->SelectObject(pOldBrush);

		//// 情報text
		//CFont font;
		//CFont* pOldfont;
		//font.CreateFontW(10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, L"consolas");
		//pOldfont = pDC->SelectObject(&font);
		//CString str;
		//point.Offset(10, -5);
		//str.Format(L"%d", index);
		//pDC->TextOutW(point.x, point.y, str);
		//str.Format(L"%2d", m_Search->routelist[index]);
		//point.Offset(0, 10);
		//pDC->TextOutW(point.x, point.y, str);
		//pDC->SelectObject(pOldfont);
		index++;
	}

	/* 壁描画 */
	DrawWall(pDC, point, scale, rotateDeg);


}

void CMaze::DrawWall(CDC* pDC, floatPoint point, double scale, double rotateDeg)
{
	//CClientDC dc(hwnd);
	CPoint pointList[4] = {0};
	int pointCount = 4; /* 四角なので4固定 */

	int color = RGB(50, 50, 50);

	CPen pen(PS_SOLID, 0, color);
	CPen* pOldPen = pDC->SelectObject(&pen);

	// 塗りつぶし色
	CBrush brush(color);
	// 新しいブラシ(brush)を設定し、設定されていた元のブラシをpOldBrushに保存します。
	CBrush* pOldBrush = pDC->SelectObject(&brush);

	int d = 0;
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
			pDC->Polygon(pointList, pointCount);
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
			pDC->Polygon(pointList, pointCount);
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
			pDC->Polygon(pointList, pointCount);
		}
	}

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);


}
