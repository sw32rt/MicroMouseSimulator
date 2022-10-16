#include "pch.h"
#include "CMaze.h"

CMaze::CMaze(int mazeSize)
{
	m_mazeCells = mazeSize;
	m_mazeSize.width = (CELL_LENGTH * mazeSize) + WALL_WIDTH; /* �P�ʂ�mm ���90mm, �ǌ���6mm */
	m_mazeSize.height = (CELL_LENGTH * mazeSize) + WALL_WIDTH; /* �P�ʂ�mm ���90mm, �ǌ���6mm �����`�Ȃ̂�x��y���� */
	floatPoint center(200, 200);
	m_pField = new CField(m_mazeCells, m_mazeSize, center);

	//m_HorizontalLineList

	/* �����`�� */
	stLine_t HLine;
	HLine.from = floatPoint((m_pField->m_RelativeMap.lefttop.x + (WALL_WIDTH / 2.0)), m_pField->m_RelativeMap.lefttop.y + (WALL_WIDTH / 2.0));
	HLine.to = floatPoint((m_pField->m_RelativeMap.rightbottom.x - (WALL_WIDTH / 2.0)), m_pField->m_RelativeMap.lefttop.y + (WALL_WIDTH / 2.0));

	for (int i = 0; i < m_mazeCells + 1; i++)
	{
		m_HorizontalLineList.push_back(HLine);
		HLine.from.y += CELL_LENGTH;
		HLine.to.y += CELL_LENGTH;
	}

	/* �c���`�� */
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
	/* �����`�� */
	for (int i = 0; i < m_mazeCells + 1; i++)
	{
		pDC->MoveTo((m_HorizontalLineList[i].from * scale).rotate(rotateDeg) + m_pField->m_MapOrigin);
		pDC->LineTo((m_HorizontalLineList[i].to * scale).rotate(rotateDeg) + m_pField->m_MapOrigin);
	}

	/* �c���`�� */
	for (int i = 0; i < m_mazeCells + 1; i++)
	{
		pDC->MoveTo((m_VerticalLineList[i].from * scale).rotate(rotateDeg) + m_pField->m_MapOrigin);
		pDC->LineTo((m_VerticalLineList[i].to * scale).rotate(rotateDeg) + m_pField->m_MapOrigin);
	}
#endif

	// �y�����쐬���܂��B
	// �y���̃X�^�C�� : ����
	// �y���̑���    : 1
	// �y���̐F     : ��
	CPen pen;

	// �V�����y��(pen)��ݒ肵�A�ݒ肳��Ă������̃y����pOldPen�ɕۑ����܂��B
	CPen* pOldPen;
#if 0
	// �ӂ�`��
	for (auto ylist : m_Search->vlist)
	{ // y����
		for (auto v : ylist)
		{ // x����

			do { // �m�[�h�̉E����`��
				int color = 0;

				// switch�ɂ����break��do{}��E�o�ł��Ȃ��Ȃ�̂�if�ɂ���
				if (v.GetWall_East() == WallStatus::E_KS_WallExists)
				{ // �ǂ���
					break;
				}
				else if (v.GetWall_East() == WallStatus::E_KS_WallNothing)
				{ // �ǖ���
					color = RGB(0, 240, 0);
				}
				else if (v.GetWall_East() == WallStatus::E_KS_Unknown)
				{ // �s��(���T��)
					color = RGB(0, 0, 0);
				}
				else if (v.GetWall_East() == WallStatus::E_KS_OutSide)
				{ // ���H�O
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

				// �y�������Ƃɖ߂�
				pDC->SelectObject(pOldPen);
			} while (0);

			do { // �m�[�h�̉�����`��
				int color = 0;

				// switch�ɂ����break��do{}��E�o�ł��Ȃ��Ȃ�̂�if�ɂ���
				if (v.GetWall_South() == WallStatus::E_KS_WallExists)
				{ // �ǂ���
					break;
				}
				else if (v.GetWall_South() == WallStatus::E_KS_WallNothing)
				{ // �ǖ���
					color = RGB(0, 240, 0);
				}
				else if (v.GetWall_South() == WallStatus::E_KS_Unknown)
				{ // �s��(���T��)
					color = RGB(0, 0, 0);
				}
				else if (v.GetWall_South() == WallStatus::E_KS_OutSide)
				{ // ���H�O
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

				// �y�������Ƃɖ߂�
				pDC->SelectObject(pOldPen);
			} while (0);

			do { // �m�[�h�̍���΂ߐ���`��
				int color = 0;

				// switch�ɂ����break��do{}��E�o�ł��Ȃ��Ȃ�̂�if�ɂ���
				if (v.GetWall_WestNorth() == WallStatus::E_KS_WallExists)
				{ // �ǂ���
					break;
				}
				else if (v.GetWall_WestNorth() == WallStatus::E_KS_WallNothing)
				{ // �ǖ���
					color = RGB(0, 240, 0);
				}
				else if (v.GetWall_WestNorth() == WallStatus::E_KS_Unknown)
				{ // �s��(���T��)
					color = RGB(0, 0, 0);
				}
				else if (v.GetWall_WestNorth() == WallStatus::E_KS_OutSide)
				{ // ���H�O
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

				// �y�������Ƃɖ߂�
				pDC->SelectObject(pOldPen);
			} while (0);

			do { // �m�[�h�̉E��΂ߐ���`��
				int color = 0;

				// switch�ɂ����break��do{}��E�o�ł��Ȃ��Ȃ�̂�if�ɂ���
				if (v.GetWall_NorthEast() == WallStatus::E_KS_WallExists)
				{ // �ǂ���
					break;
				}
				else if (v.GetWall_NorthEast() == WallStatus::E_KS_WallNothing)
				{ // �ǖ���
					color = RGB(0, 240, 0);
				}
				else if (v.GetWall_NorthEast() == WallStatus::E_KS_Unknown)
				{ // �s��(���T��)
					color = RGB(0, 0, 0);
				}
				else if (v.GetWall_NorthEast() == WallStatus::E_KS_OutSide)
				{ // ���H�O
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

				// �y�������Ƃɖ߂�
				pDC->SelectObject(pOldPen);
			} while (0);

		}
	}
#endif

#if 1
	// ���_��`��
	for (auto ylist : m_Search->vlist)
	{ // y����
		for (auto v : ylist)
		{ // x����

			int color = 0;

			switch (v.SStatus)
			{
			case E_Status_UnExplored:
				// ���T��
				color = RGB(255, 255, 255);
				break;
			case E_Status_Looked:
				// �F�m
				color = RGB(0, 255, 255);
				break;
			case E_Status_Exploring:
				// �T����
				color = RGB(200, 0, 0);
				break;
			case E_Status_Searched:
				// �T���ς�
				color = RGB(100, 100, 100);
				break;
			case E_Status_ShortestPath:
				// �ŒZ�o�H
				color = RGB(0, 255, 0);
				break;
			default:
				break;
			}

			switch (v.SupposeSearchStatus)
			{
			case E_Status_ShortestPath:
				color = RGB(0, 255, 0);
				// �ŒZ�o�H
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
			{ // �S�[��
				color = RGB(200, 100, 0);
			}

			// �h��Ԃ��F
			CBrush brush(color);
			// �V�����u���V(brush)��ݒ肵�A�ݒ肳��Ă������̃u���V��pOldBrush�ɕۑ����܂��B
			CBrush* pOldBrush = pDC->SelectObject(&brush);

			floatPoint fpoint = v;
			fpoint = (fpoint * scale).rotate(rotateDeg) + m_pField->m_MapOrigin;

			CSize size(10, 10);
			CPoint point(fpoint.x - (size.cx / 2), fpoint.y - (size.cy / 2));
			CRect rect(point, size);
			pDC->Ellipse(rect);

			pDC->SelectObject(pOldBrush);

			//// ���text
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
	/* �Ǖ`�� */
	DrawWall(pDC, point, scale, rotateDeg);

#endif

}

void CMaze::DrawWall(CDC* pDC, floatPoint point, double scale, double rotateDeg)
{
	CPoint pointList[4] = {0};
	int pointCount = 4; /* �l�p�Ȃ̂�4�Œ� */

	int color = RGB(50, 50, 50);

	CPen pen(PS_SOLID, 0, color);
	CPen* pOldPen = pDC->SelectObject(&pen);

	// �h��Ԃ��F
	CBrush defaultBrush(color);
	// �V�����u���V(brush)��ݒ肵�A�ݒ肳��Ă������̃u���V��pOldBrush�ɕۑ����܂��B
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
				// switch�ɂ����break��do{}��E�o�ł��Ȃ��Ȃ�̂�if�ɂ���
				if (v.GetWall_South() == WallStatus::E_KS_WallExists)
				{ // �ǂ���
					color = RGB(240, 240, 240);
					IsDraw = true;
				}
				else if (v.GetWall_South() == WallStatus::E_KS_WallNothing)
				{ // �ǂȂ�
					IsDraw = false;
				}
				else if (v.GetWall_South() == WallStatus::E_KS_Unknown)
				{ // �s��(���T��)
					IsDraw = false;
				}
				else if (v.GetWall_South() == WallStatus::E_KS_OutSide)
				{ // ���H�O
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
				// �y�������Ƃɖ߂�
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
				// switch�ɂ����break��do{}��E�o�ł��Ȃ��Ȃ�̂�if�ɂ���
				if (v.GetWall_East() == WallStatus::E_KS_WallExists)
				{ // �ǂ���
					color = RGB(240, 240, 240);
					IsDraw = true;
				}
				else if (v.GetWall_East() == WallStatus::E_KS_WallNothing)
				{ // �ǖ���
					IsDraw = false;
				}
				else if (v.GetWall_East() == WallStatus::E_KS_Unknown)
				{ // �s��(���T��)
					IsDraw = false;
				}
				else if (v.GetWall_East() == WallStatus::E_KS_OutSide)
				{ // ���H�O
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
				// �y�������Ƃɖ߂�
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
