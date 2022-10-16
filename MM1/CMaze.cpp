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
	m_Search->init(MAZE_START, MAZE_GOAL);
}

CMaze::~CMaze()
{
	delete m_pField;
	delete m_Search;
}

void CMaze::Draw(CDC* pDC, floatPoint point, double scale, double rotateDeg)
{
	m_pField->m_MapOrigin = point;
	//CClientDC dc(hwnd);

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
#if 0
	// 辺を描画
	for (auto ylist : m_Search->vlist)
	{ // y走査
		for (auto v : ylist)
		{ // x走査

			do { // ノードの右線を描画
				int color = 0;

				// switchにするとbreakでdo{}を脱出できなくなるのでifにした
				if (v.GetWall_East() == WallStatus::E_KS_WallExists)
				{ // 壁あり
					break;
				}
				else if (v.GetWall_East() == WallStatus::E_KS_WallNothing)
				{ // 壁無し
					color = RGB(0, 240, 0);
				}
				else if (v.GetWall_East() == WallStatus::E_KS_Unknown)
				{ // 不明(未探索)
					color = RGB(0, 0, 0);
				}
				else if (v.GetWall_East() == WallStatus::E_KS_OutSide)
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

			do { // ノードの下線を描画
				int color = 0;

				// switchにするとbreakでdo{}を脱出できなくなるのでifにした
				if (v.GetWall_South() == WallStatus::E_KS_WallExists)
				{ // 壁あり
					break;
				}
				else if (v.GetWall_South() == WallStatus::E_KS_WallNothing)
				{ // 壁無し
					color = RGB(0, 240, 0);
				}
				else if (v.GetWall_South() == WallStatus::E_KS_Unknown)
				{ // 不明(未探索)
					color = RGB(0, 0, 0);
				}
				else if (v.GetWall_South() == WallStatus::E_KS_OutSide)
				{ // 迷路外
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

			do { // ノードの左上斜め線を描画
				int color = 0;

				// switchにするとbreakでdo{}を脱出できなくなるのでifにした
				if (v.GetWall_WestNorth() == WallStatus::E_KS_WallExists)
				{ // 壁あり
					break;
				}
				else if (v.GetWall_WestNorth() == WallStatus::E_KS_WallNothing)
				{ // 壁無し
					color = RGB(0, 240, 0);
				}
				else if (v.GetWall_WestNorth() == WallStatus::E_KS_Unknown)
				{ // 不明(未探索)
					color = RGB(0, 0, 0);
				}
				else if (v.GetWall_WestNorth() == WallStatus::E_KS_OutSide)
				{ // 迷路外
					break;
				}
				CPen pen(PS_SOLID, 1, color);
				CPen* pOldPen = pDC->SelectObject(&pen);

				floatPoint from = v;
				floatPoint to = *(v.GetVertex_WestNorth());
				from = (from * scale).rotate(rotateDeg) + m_pField->m_MapOrigin;
				to = (to * scale).rotate(rotateDeg) + m_pField->m_MapOrigin;

				pDC->MoveTo(from);
				pDC->LineTo(to);

				// ペンをもとに戻す
				pDC->SelectObject(pOldPen);
			} while (0);

			do { // ノードの右上斜め線を描画
				int color = 0;

				// switchにするとbreakでdo{}を脱出できなくなるのでifにした
				if (v.GetWall_NorthEast() == WallStatus::E_KS_WallExists)
				{ // 壁あり
					break;
				}
				else if (v.GetWall_NorthEast() == WallStatus::E_KS_WallNothing)
				{ // 壁無し
					color = RGB(0, 240, 0);
				}
				else if (v.GetWall_NorthEast() == WallStatus::E_KS_Unknown)
				{ // 不明(未探索)
					color = RGB(0, 0, 0);
				}
				else if (v.GetWall_NorthEast() == WallStatus::E_KS_OutSide)
				{ // 迷路外
					break;
				}
				CPen pen(PS_SOLID, 1, color);
				CPen* pOldPen = pDC->SelectObject(&pen);

				floatPoint from = v;
				floatPoint to = *(v.GetVertex_NorthEast());
				from = (from * scale).rotate(rotateDeg) + m_pField->m_MapOrigin;
				to = (to * scale).rotate(rotateDeg) + m_pField->m_MapOrigin;

				pDC->MoveTo(from);
				pDC->LineTo(to);

				// ペンをもとに戻す
				pDC->SelectObject(pOldPen);
			} while (0);

		}
	}
#endif

#if 1
	// 頂点を描画
	for (auto ylist : m_Search->vlist)
	{ // y走査
		for (auto v : ylist)
		{ // x走査

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
				color = RGB(200, 0, 0);
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
				color = RGB(0, 255, 0);
				// 最短経路
				break;
			case E_Status_UnExplored:
				break;
			case E_Status_Looked:
				break;
			case E_Status_Exploring:
				break;
			case E_Status_Searched:
				break;
			default:
				break;
			}

			if (m_Search->GoalVertexIndex == v.mazeCoordinate)
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
		}
	}
	/* 壁描画 */
	DrawWall(pDC, point, scale, rotateDeg);

#endif

}

void CMaze::DrawWall(CDC* pDC, floatPoint point, double scale, double rotateDeg)
{
	CPoint pointList[4] = {0};
	int pointCount = 4; /* 四角なので4固定 */

	int color = RGB(50, 50, 50);

	CPen pen(PS_SOLID, 0, color);
	CPen* pOldPen = pDC->SelectObject(&pen);

	// 塗りつぶし色
	CBrush defaultBrush(color);
	// 新しいブラシ(brush)を設定し、設定されていた元のブラシをpOldBrushに保存します。
	CBrush* pOldBrush = pDC->SelectObject(&defaultBrush);

	int kx = 0;
	int ky = 0;
	int d = 0;
	bool IsDraw = true;
	for (auto hWall_x : m_pField->m_MazeWall.hWallList)
	{
		//if (ky == 16) { break; }
		kx = 0;
		for (wall_t wall : hWall_x)
		{
			if (ky == 0 || ky == MAZE_SIZE)
			{
				color = RGB(240, 240, 240);
				IsDraw = true;
			}
			else
			{
				auto& v = m_Search->vAnswer[(ky - 1) * 2][kx * 2];
				// switchにするとbreakでdo{}を脱出できなくなるのでifにした
				if (v.GetWall_South() == WallStatus::E_KS_WallExists)
				{ // 壁あり
					color = RGB(240, 240, 240);
					IsDraw = true;
				}
				else if (v.GetWall_South() == WallStatus::E_KS_WallNothing)
				{ // 壁なし
					IsDraw = false;
				}
				else if (v.GetWall_South() == WallStatus::E_KS_Unknown)
				{ // 不明(未探索)
					IsDraw = false;
				}
				else if (v.GetWall_South() == WallStatus::E_KS_OutSide)
				{ // 迷路外
					IsDraw = false;
				}
			}
			kx++;
			if (IsDraw)
			{
				CBrush brush(color);
				pOldBrush = pDC->SelectObject(&brush);
				floatRect polyRect = wall.rect.scale(scale);
				polyRect = polyRect.rotate(rotateDeg);
				polyRect += m_pField->m_MapOrigin;
				pointList[0] = polyRect.lefttop;
				pointList[1] = polyRect.righttop;
				pointList[2] = polyRect.rightbottom;
				pointList[3] = polyRect.leftbottom;
				pDC->Polygon(pointList, pointCount);
				// ペンをもとに戻す
				pDC->SelectObject(pOldPen);
				pDC->SelectObject(pOldBrush);
			}
		}
		ky++;
	}

	kx = 0;
	ky = 0;
	for (auto vWall_x : m_pField->m_MazeWall.vWallList)
	{
		//if (ky == 16) { break; }
		kx = 0;
		for (wall_t wall : vWall_x)
		{
			//color = RGB(50, 50, 50);
			if (kx == 0 || kx == MAZE_SIZE)
			{
				color = RGB(240, 240, 240);
				IsDraw = true;
			}
			else
			{
				auto& v = m_Search->vAnswer[ky * 2][(kx - 1) * 2];
				// switchにするとbreakでdo{}を脱出できなくなるのでifにした
				if (v.GetWall_East() == WallStatus::E_KS_WallExists)
				{ // 壁あり
					color = RGB(240, 240, 240);
					IsDraw = true;
				}
				else if (v.GetWall_East() == WallStatus::E_KS_WallNothing)
				{ // 壁無し
					IsDraw = false;
				}
				else if (v.GetWall_East() == WallStatus::E_KS_Unknown)
				{ // 不明(未探索)
					IsDraw = false;
				}
				else if (v.GetWall_East() == WallStatus::E_KS_OutSide)
				{ // 迷路外
					IsDraw = false;
				}
			}
			kx++;
			if (IsDraw)
			{
				CBrush brush(color);
				pOldBrush = pDC->SelectObject(&brush);
				floatRect polyRect = wall.rect.scale(scale);
				polyRect = polyRect.rotate(rotateDeg);
				polyRect += m_pField->m_MapOrigin;
				pointList[0] = polyRect.lefttop;
				pointList[1] = polyRect.righttop;
				pointList[2] = polyRect.rightbottom;
				pointList[3] = polyRect.leftbottom;
				pDC->Polygon(pointList, pointCount);
				// ペンをもとに戻す
				pDC->SelectObject(pOldPen);
				pDC->SelectObject(pOldBrush);
			}
		}
		ky++;
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
