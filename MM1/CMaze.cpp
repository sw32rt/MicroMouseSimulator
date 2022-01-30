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

	/* ���H���S�܂Ő���`�� */
	pDC->MoveTo(CPoint(0, 0));
	pDC->LineTo(m_pField->m_MapOrigin);
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
	// �ӂ�`��
	for (auto v : m_Search->vlist)
	{
		do { // �m�[�h�̉E���̐���`��
			int color = 0;

			// switch�ɂ����break��do{}��E�o�ł��Ȃ��Ȃ�̂�if�ɂ���
			if (v.Wall_East == WallStatus::E_KS_Exists)
			{ // ���݂���
				color = RGB(255, 100, 0);
			}
			else if (v.Wall_East == WallStatus::E_KS_NotExist)
			{ // ���݂��Ȃ�
				color = RGB(240, 240, 240);
			}
			else if (v.Wall_East == WallStatus::E_KS_Unknown)
			{ // �s��(���T��)
				color = RGB(0, 0, 0);
			}
			else if (v.Wall_East == WallStatus::E_KS_OutSide)
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

		do { // �m�[�h�̉����̐���`��
			int color = 0;

			// switch�ɂ����break��do{}��E�o�ł��Ȃ��Ȃ�̂�if�ɂ���
			if (v.Wall_South == WallStatus::E_KS_Exists)
			{ // ���݂���
				color = RGB(255, 100, 0);
			}
			else if (v.Wall_South == WallStatus::E_KS_NotExist)
			{ // ���݂��Ȃ�
				//break; // ���������Ȃ�
				color = RGB(240, 240, 240);
			}
			else if (v.Wall_South == WallStatus::E_KS_Unknown)
			{ // �s��(���T��)
				color = RGB(0, 0, 0);
			}
			else if (v.Wall_South == WallStatus::E_KS_OutSide)
			{ // ���H�O
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

			// �y�������Ƃɖ߂�
			pDC->SelectObject(pOldPen);
		} while (0);
	}

	int index = 0;
	// ���_��`��
	for (auto v : m_Search->vlist)
	{
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
			color = RGB(200, 200, 0);
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
			// �ŒZ�o�H
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
		index++;
	}

	/* �Ǖ`�� */
	DrawWall(pDC, point, scale, rotateDeg);


}

void CMaze::DrawWall(CDC* pDC, floatPoint point, double scale, double rotateDeg)
{
	//CClientDC dc(hwnd);
	CPoint pointList[4] = {0};
	int pointCount = 4; /* �l�p�Ȃ̂�4�Œ� */

	int color = RGB(50, 50, 50);

	CPen pen(PS_SOLID, 0, color);
	CPen* pOldPen = pDC->SelectObject(&pen);

	// �h��Ԃ��F
	CBrush brush(color);
	// �V�����u���V(brush)��ݒ肵�A�ݒ肳��Ă������̃u���V��pOldBrush�ɕۑ����܂��B
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
