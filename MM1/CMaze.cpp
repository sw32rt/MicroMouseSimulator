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

void CMaze::Draw(CHwndRenderTarget* pRenderTarget, floatPoint point, double scale, double rotateDeg)
{
	m_pField->m_MapOrigin = point;
	CD2DSolidColorBrush blackBrush(pRenderTarget, D2D1::ColorF(D2D1::ColorF::Black, 1.0f));

#if 0
	/* 横線描画 */
	for (int i = 0; i < m_mazeCells + 1; i++)
	{
		pRenderTarget->MoveTo((m_HorizontalLineList[i].from * scale).rotate(rotateDeg) + m_pField->m_MapOrigin);
		pRenderTarget->LineTo((m_HorizontalLineList[i].to * scale).rotate(rotateDeg) + m_pField->m_MapOrigin);
	}

	/* 縦線描画 */
	for (int i = 0; i < m_mazeCells + 1; i++)
	{
		pRenderTarget->MoveTo((m_VerticalLineList[i].from * scale).rotate(rotateDeg) + m_pField->m_MapOrigin);
		pRenderTarget->LineTo((m_VerticalLineList[i].to * scale).rotate(rotateDeg) + m_pField->m_MapOrigin);
	}
#endif

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
				CPen* pOldPen = pRenderTarget->SelectObject(&pen);
				floatPoint from = v;
				floatPoint to = *(v.GetVertex_East());
				from = (from * scale).rotate(rotateDeg) + m_pField->m_MapOrigin;
				to = (to * scale).rotate(rotateDeg) + m_pField->m_MapOrigin;

				pRenderTarget->MoveTo(from);
				pRenderTarget->LineTo(to);

				// ペンをもとに戻す
				pRenderTarget->SelectObject(pOldPen);
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
				CPen* pOldPen = pRenderTarget->SelectObject(&pen);

				floatPoint from = v;
				floatPoint to = *(v.GetVertex_South());
				from = (from * scale).rotate(rotateDeg) + m_pField->m_MapOrigin;
				to = (to * scale).rotate(rotateDeg) + m_pField->m_MapOrigin;

				pRenderTarget->MoveTo(from);
				pRenderTarget->LineTo(to);

				// ペンをもとに戻す
				pRenderTarget->SelectObject(pOldPen);
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
				CPen* pOldPen = pRenderTarget->SelectObject(&pen);

				floatPoint from = v;
				floatPoint to = *(v.GetVertex_WestNorth());
				from = (from * scale).rotate(rotateDeg) + m_pField->m_MapOrigin;
				to = (to * scale).rotate(rotateDeg) + m_pField->m_MapOrigin;

				pRenderTarget->MoveTo(from);
				pRenderTarget->LineTo(to);

				// ペンをもとに戻す
				pRenderTarget->SelectObject(pOldPen);
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
				CPen* pOldPen = pRenderTarget->SelectObject(&pen);

				floatPoint from = v;
				floatPoint to = *(v.GetVertex_NorthEast());
				from = (from * scale).rotate(rotateDeg) + m_pField->m_MapOrigin;
				to = (to * scale).rotate(rotateDeg) + m_pField->m_MapOrigin;

				pRenderTarget->MoveTo(from);
				pRenderTarget->LineTo(to);

				// ペンをもとに戻す
				pRenderTarget->SelectObject(pOldPen);
			} while (0);

		}
	}
#endif
	/* 現在見つかった最短経路の線を描画 */
	if (m_Search->CurrentShortestRoutelist.empty() == false) // Current -> Goal
	{ // ルート見つかった
		Coordinate from = m_Search->StartVertexIndex;
		Coordinate to = m_Search->StartVertexIndex;
		CD2DSolidColorBrush brush(pRenderTarget, COLORREF(RGB(136, 238, 170)));

		while (1)
		{
			to = m_Search->CurrentShortestRoutelist[from];
			CPoint fromPoint(m_Search->vlist[from.y][from.x]);
			fromPoint += m_pField->m_MapOrigin;
			CPoint toPoint(m_Search->vlist[to.y][to.x]);
			toPoint += m_pField->m_MapOrigin;
			pRenderTarget->DrawLine(fromPoint, toPoint, &brush, 2.0F);
			if (to == m_Search->GoalVertexIndex)
			{
				break;
			}
			from = to;
		}
	}

#if 1

	bool IsDraw = false;
	int color = 0;
	// 頂点を描画
	for (auto ylist : m_Search->vlist)
	{ // y走査
		for (auto v : ylist)
		{ // x走査


			switch (v.SStatus)
			{
			case E_Status_UnExplored:
				// 未探索
				color = RGB(255, 255, 255);
				IsDraw = false;
				break;
			case E_Status_Looked:
				// 認知
				color = RGB(0, 255, 255);
				IsDraw = false;
				break;
			case E_Status_Exploring:
				// 探索中
				color = RGB(200, 0, 0);
				IsDraw = false;
				break;
			case E_Status_Searched:
				// 探索済み
				color = RGB(100, 100, 100);
				IsDraw = false;
				break;
			case E_Status_ShortestPath:
				// 最短経路
				color = RGB(156, 196, 88);
				IsDraw = true;
				break;
			default:
				IsDraw = false;
				break;
			}

			switch (v.SupposeSearchStatus)
			{
			case E_Status_ShortestPath:
				color = RGB(218, 165, 32);
				IsDraw = true;
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
				IsDraw = true;
			}

			if (IsDraw)
			{
				// 塗りつぶし色
				CD2DSolidColorBrush brush(pRenderTarget, COLORREF(color));

				floatPoint fpoint = v;
				fpoint = fpoint + m_pField->m_MapOrigin;

				CSize size(10, 10);
				CPoint point(fpoint.x - (size.cx / 2), fpoint.y - (size.cy / 2));
				CRect rect(point, size);
				CD2DEllipse ellipse(rect);
				//pRenderTarget->FillEllipse(ellipse, &brush);
				pRenderTarget->FillRectangle(rect, &brush);
				//pRenderTarget->DrawEllipse(ellipse, &blackBrush);
				//pRenderTarget->DrawRectangle(rect, &blackBrush);
			}


			//// 情報text
			//CFont font;
			//CFont* pOldfont;
			//font.CreateFontW(10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, L"consolas");
			//pOldfont = pRenderTarget->SelectObject(&font);
			//CString str;
			//point.Offset(10, -5);
			//str.Format(L"%d", index);
			//pRenderTarget->TextOutW(point.x, point.y, str);
			//str.Format(L"%2d", m_Search->routelist[index]);
			//point.Offset(0, 10);
			//pRenderTarget->TextOutW(point.x, point.y, str);
			//pRenderTarget->SelectObject(pOldfont);
		}
	}
	/* 壁描画 */
	DrawWall(pRenderTarget, point, scale, rotateDeg);

#endif

}

void CMaze::DrawWall(CHwndRenderTarget* pRenderTarget, floatPoint point, double scale, double rotateDeg)
{
	CPoint pointList[4] = {0};
	int pointCount = 4; /* 四角なので4固定 */

	CD2DSolidColorBrush blackBrush(pRenderTarget, D2D1::ColorF(D2D1::ColorF::Black, 1.0f));
	CD2DSolidColorBrush grayBrush(pRenderTarget, COLORREF(RGB(180, 180, 180)));
	CD2DSolidColorBrush redBrush(pRenderTarget, COLORREF(RGB(240, 140, 124)));
	CD2DSolidColorBrush whiteBrush(pRenderTarget, COLORREF(RGB(240, 240, 240)));

	int kx = 0;
	int ky = 0;
	int d = 0;
	bool IsDraw = true;
	for (auto hWall_x : m_pField->m_MazeWall.hWallList)
	{
		kx = 0;
		for (wall_t wall : hWall_x)
		{
			if (ky == 0 || ky == MAZE_SIZE)
			{ /* ワク */
				CRect rect(wall.rect);
				rect.OffsetRect(m_pField->m_MapOrigin);
				pRenderTarget->FillRectangle(rect, &blackBrush);
				IsDraw = true;
			}
			else
			{
				auto& vAns = m_Search->vAnswer[(ky - 1) * 2][kx * 2];
				auto& v = m_Search->vlist[(ky - 1) * 2][kx * 2];
				// switchにするとbreakでdo{}を脱出できなくなるのでifにした
				if (v.GetWall_South() == WallStatus::E_KS_WallExists)
				{ // 壁あり
					CRect rect(wall.rect);
					rect.OffsetRect(m_pField->m_MapOrigin);
					pRenderTarget->FillRectangle(rect, &blackBrush);
					IsDraw = true;
				}
				else if (v.GetWall_South() == WallStatus::E_KS_WallNothing)
				{ // 壁なし
					IsDraw = false;
				}
				else if ((v.GetWall_South() == WallStatus::E_KS_Unknown)
					   &&(vAns.GetWall_South() == WallStatus::E_KS_WallExists))
				{ // 不明(未探索)
					CRect rect(wall.rect);
					rect.OffsetRect(m_pField->m_MapOrigin);
					pRenderTarget->DrawRectangle(rect, &grayBrush);
					IsDraw = true;
				}
				else if (v.GetWall_South() == WallStatus::E_KS_OutSide)
				{ // 迷路外
					IsDraw = false;
				}
			}
			kx++;
		}
		ky++;
	}

	kx = 0;
	ky = 0;
	for (auto vWall_x : m_pField->m_MazeWall.vWallList)
	{
		kx = 0;
		for (wall_t wall : vWall_x)
		{
			if (kx == 0 || kx == MAZE_SIZE)
			{ /* ワク */
				CRect rect(wall.rect);
				rect.OffsetRect(m_pField->m_MapOrigin);
				pRenderTarget->FillRectangle(rect, &blackBrush);
			}
			else
			{
				auto& vAns = m_Search->vAnswer[ky * 2][(kx - 1) * 2];
				auto& v = m_Search->vlist[ky * 2][(kx - 1) * 2];
				// switchにするとbreakでdo{}を脱出できなくなるのでifにした
				if (v.GetWall_East() == WallStatus::E_KS_WallExists)
				{ // 壁あり
					CRect rect(wall.rect);
					rect.OffsetRect(m_pField->m_MapOrigin);
					pRenderTarget->FillRectangle(rect, &blackBrush);
				}
				else if (v.GetWall_East() == WallStatus::E_KS_WallNothing)
				{ // 壁無し
				}
				else if ((v.GetWall_East() == WallStatus::E_KS_Unknown)
					&& (vAns.GetWall_East() == WallStatus::E_KS_WallExists))
				{ // 不明(未探索)
					CRect rect(wall.rect);
					rect.OffsetRect(m_pField->m_MapOrigin);
					pRenderTarget->DrawRectangle(rect, &grayBrush);
				}
				else if (v.GetWall_East() == WallStatus::E_KS_OutSide)
				{ // 迷路外
				}
			}
			kx++;
		}
		ky++;
	}

	for (auto pillar_x : m_pField->m_MazeWall.pillarList)
	{
		for (pillar_t pillar : pillar_x)
		{
			CRect rect(pillar.rect);
			rect.OffsetRect(m_pField->m_MapOrigin);
			pRenderTarget->DrawRectangle(rect, &blackBrush);
		}
	}
}
